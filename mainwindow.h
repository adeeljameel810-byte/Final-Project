#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>

struct Student {
    QString name;
    QString roll;
    QString father;
    QString caste;
    QString district;
    QString gpa;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();
    void onNextClicked();
    void onUpdateClicked();
    void onDeleteClicked();

private:
    Ui::MainWindow *ui;
    QVector<Student> students;
    int currentIndex;

    void clearFields();
    bool validateFields();
};

#endif // MAINWINDOW_H
