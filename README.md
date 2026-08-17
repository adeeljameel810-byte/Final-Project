🌟 STUDENT MANAGEMENT SYSTEM — Qt C++ Project . This is my final year project
A modern, lightweight, and user-friendly Student Record Management System built using Qt (C++ GUI).
This application allows users to Add, Update, Delete, and Navigate student records stored in a text/CSV file.

🧭 Project Overview
┌────────────────────────────────────────────┐
│  A simple Desktop tool to manage student   │
│  records efficiently with clean user       │
│  interaction and smooth navigation.        │
└────────────────────────────────────────────┘

The system provides:
✔ A clean form for student details.
✔ Text/CSV file storage.
✔ Navigation through records.
✔ Editing & deleting functionality.
✔ Buttons that enable/disable intelligently.

🧩 Features
╔══════════════════════════════════════════╗
║              MAIN FEATURES               ║
╚══════════════════════════════════════════╝

📝 Student Fields
Each student entry includes:
• Name
• Roll Number
• Father’s Name
• Cast
• District
• GPA

🖲 Button Actions
┌───────────┬────────────────────────────────────────┐
│ Add       │ Insert a new student record             │
├───────────┼────────────────────────────────────────┤
│ Update    │ Modify current record (by Roll No.)     │
├───────────┼────────────────────────────────────────┤
│ Delete    │ Remove the current displayed record     │
├───────────┼────────────────────────────────────────┤
│ Next      │ Navigate to the next saved student      │
└───────────┴────────────────────────────────────────┘


🔄 Application Workflow
╔══════════════════════════════════════════╗
║             APPLICATION FLOW              ║
╚══════════════════════════════════════════╝

▶ At Startup
[ Add: ENABLED ]  
[ Update: DISABLED ]  
[ Delete: DISABLED ]  
[ Next: ENABLED ]

➕ Adding a Record
• User fills the form
• Clicks ADD
• Record is saved to file
• Success message is shown

⏭ Navigating Records
• Load next record using NEXT
• ADD becomes disabled
• UPDATE and DELETE become enabled

✏ Updating
• User edits fields
• UPDATE overwrites record matching Roll Number

🗑 Deleting
• DELETE removes the current record permanently


🗂 File Format
Stored as .txt or .csv:
Name,Roll,Father,Caste,District,GPA
Ali,01,Ahmed,Abbasi,Hyderabad,3.5
Sara,02,Khan,Pathan,Karachi,3.8

Readable in:

.Excel
.Notepad
.Google Sheets
.Any text editor



🛠 Tech Stack
• C++
• Qt Framework (Widgets GUI)
• QFile & QTextStream for file handling
• Qt Designer for UI layout


📦 How to Run
git clone https://github.com/adeeljameel810-byte/Final-Project



Open the project in Qt Creator
Build the project
Run the application



🖼 GUI Layout (Illustration)
┌─────────────────────────────────────────────┐
│ Name:      [__________________________]     │
│ Roll No:   [__________________________]     │
│ Father:    [__________________________]     │
│ Caste:     [__________________________]     │
│ District:  [__________________________]     │
│ GPA:       [__________________________]     │
├─────────────────────────────────────────────┤
│ [ Add ]   [ Update ]   [ Delete ]   [ Next ]│
└─────────────────────────────────────────────┘



👨‍💻 Author
Jameel Ahmed Khuhro
Final Project – Student Record Management System (Qt C++)

📜 License
This project is distributed under the MIT License.


