#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

/*
 * ===========================================
 *  STUDENT MANAGEMENT RECORD SYSTEM (CSV)
 *  Features:
 *   âœ… Add, Update, Delete, Navigate
 *   âœ… Save records in students.csv file
 *   âœ… Proper CSV format with header
 *   âœ… Works with Excel / Google Sheets
 * ===========================================
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButtonAdd->setEnabled(true);
    ui->pushButtonUpdate->setEnabled(false);
    ui->pushButtonDelete->setEnabled(false);

    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &MainWindow::onNextClicked);
    connect(ui->pushButtonUpdate, &QPushButton::clicked, this, &MainWindow::onUpdateClicked);
    connect(ui->pushButtonDelete, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);

    currentIndex = -1;

    // ---------- Load existing CSV file ----------
    QFile file("students.csv");
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString header = in.readLine(); // Skip header line
        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if(fields.size() == 6) {
                Student s = {fields[0], fields[1], fields[2], fields[3], fields[4], fields[5]};
                students.append(s);
            }
        }
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ------------------------------
// Helper Function: Clear fields
// ------------------------------
void MainWindow::clearFields() {
    ui->lineEditName->clear();
    ui->lineEditRoll->clear();
    ui->lineEditFather->clear();
    ui->lineEditCaste->clear();
    ui->lineEditDistrict->clear();
    ui->lineEditGPA->clear();
}

// ------------------------------
// Helper Function: Validate inputs
// ------------------------------
bool MainWindow::validateFields() {
    if (ui->lineEditName->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "Name field is required!");
        return false;
    }
    if (ui->lineEditRoll->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "Roll Number is required!");
        return false;
    }
    if (ui->lineEditFather->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "Father's Name is required!");
        return false;
    }
    if (ui->lineEditCaste->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "Caste field is required!");
        return false;
    }
    if (ui->lineEditDistrict->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "District field is required!");
        return false;
    }
    if (ui->lineEditGPA->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Field", "GPA field is required!");
        return false;
    }
    return true;
}

// ------------------------------
// SAVE ALL STUDENTS TO CSV FILE
// ------------------------------
void saveAllToCSV(const QVector<Student>& students) {
    QFile file("students.csv");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);

        // Header Line
        out << "Name,Roll,Father,Caste,District,GPA\n";

        // Write each record
        for (const Student &s : students) {
            out << s.name << "," << s.roll << "," << s.father << ","
                << s.caste << "," << s.district << "," << s.gpa << "\n";
        }
        file.close();
    }
}

// ------------------------------
// ADD BUTTON FUNCTION
// ------------------------------
void MainWindow::onAddClicked() {
    if (!validateFields()) return;

    Student s;
    s.name = ui->lineEditName->text();
    s.roll = ui->lineEditRoll->text();
    s.father = ui->lineEditFather->text();
    s.caste = ui->lineEditCaste->text();
    s.district = ui->lineEditDistrict->text();
    s.gpa = ui->lineEditGPA->text();

    students.append(s);

    // Save all records (including new) to CSV
    saveAllToCSV(students);

    QMessageBox::information(this, "Success", "Student added successfully (saved to CSV)!");

    clearFields();
    ui->pushButtonAdd->setEnabled(true);
    ui->pushButtonUpdate->setEnabled(false);
    ui->pushButtonDelete->setEnabled(false);
}

// ------------------------------
// NEXT BUTTON FUNCTION
// ------------------------------
void MainWindow::onNextClicked() {
    if (students.isEmpty()) {
        QMessageBox::information(this, "Info", "No student records available!");
        return;
    }

    currentIndex = (currentIndex + 1) % students.size();

    Student s = students[currentIndex];
    ui->lineEditName->setText(s.name);
    ui->lineEditRoll->setText(s.roll);
    ui->lineEditFather->setText(s.father);
    ui->lineEditCaste->setText(s.caste);
    ui->lineEditDistrict->setText(s.district);
    ui->lineEditGPA->setText(s.gpa);

    ui->pushButtonAdd->setEnabled(false);
    ui->pushButtonUpdate->setEnabled(true);
    ui->pushButtonDelete->setEnabled(true);
}

// ------------------------------
// UPDATE BUTTON FUNCTION
// ------------------------------
void MainWindow::onUpdateClicked() {
    if (currentIndex < 0 || currentIndex >= students.size()) return;
    if (!validateFields()) return;

    Student &s = students[currentIndex];
    s.name = ui->lineEditName->text();
    s.roll = ui->lineEditRoll->text();
    s.father = ui->lineEditFather->text();
    s.caste = ui->lineEditCaste->text();
    s.district = ui->lineEditDistrict->text();
    s.gpa = ui->lineEditGPA->text();

    saveAllToCSV(students);

    QMessageBox::information(this, "Updated", "Student record updated successfully (CSV updated)!");

    clearFields();
    ui->pushButtonAdd->setEnabled(true);
    ui->pushButtonUpdate->setEnabled(false);
    ui->pushButtonDelete->setEnabled(false);
}

// ------------------------------
// DELETE BUTTON FUNCTION
// ------------------------------
void MainWindow::onDeleteClicked() {
    if (currentIndex < 0 || currentIndex >= students.size()) return;

    students.removeAt(currentIndex);

    if (currentIndex >= students.size())
        currentIndex = students.size() - 1;

    saveAllToCSV(students);

    if (students.isEmpty()) {
        clearFields();
        ui->pushButtonAdd->setEnabled(true);
        ui->pushButtonUpdate->setEnabled(false);
        ui->pushButtonDelete->setEnabled(false);
    } else {
        onNextClicked();
    }

    QMessageBox::information(this, "Deleted", "Student record deleted successfully from CSV!");
}
