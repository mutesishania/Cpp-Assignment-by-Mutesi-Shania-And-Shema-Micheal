#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Course {
private:
    int code;
    string name;
    int credit;
    float marks;

public:
    void input() {
        cout << "enter the code of the course: ";
        cin >> code;
        cout << "enter the name of the course: ";
        cin.ignore(); // flush newline
        getline(cin, name);
        cout << "enter the credit of the course: ";
        cin >> credit;
        cout << "enter the marks of the course: ";
        cin >> marks;
    }
 //Function to check if student has passed or failed course
    bool haspassed() const {
        return marks >= 50;
    }

    int getCredit() const {
        return haspassed() ? credit : 0;
    }
};

class Student {
private:
    string firstName;
    string lastName;
    int rollNumber;
    vector<Course> courses;

public:
    void enterInfo() {
        int numCourses;
        cout << "Please Enter the first name of the student: ";
        cin >> firstName;
        cout << "Please Enter the last name of the student: ";
        cin >> lastName;
        cout << "Please Enter the roll number of the student: ";
        cin >> rollNumber;
        cout << "Please Enter the number of courses: ";
        cin >> numCourses;

        for (int i = 0; i < numCourses; i++) {
            Course c;
            cout<<"enter details for course No"<<i+1<<endl;
            c.input();
            courses.push_back(c);
        }
    }

    int getrollNumber() const {
        return rollNumber;
    }
 //function to count how many courses passed
    int CountPassed() const {
        int count = 0;
        for (const Course& c : courses) {
            if (c.haspassed()) {
                count++;
            }
        }
        return count;
    }
//function to count how many courses failed
    int CountFailed() const {
        int count = 0;
        for (const Course& c : courses) {
            if (!c.haspassed()) {
                count++;
            }
        }
        return count;
    }
//function to return how many credits accumulated
    int TotalCredits() const {
        int total = 0;
        for (const Course& c : courses) {
            total += c.getCredit();
        }
        return total;
    }
//function to display student information
    void display() const {
        cout << "\n------ Student Info ------\n";
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Roll number: " << rollNumber << endl;
        cout << "Number of courses: " << courses.size() << endl;
    }
};

int main() {
    vector<Student> students;
    while (true){
    int choice;

    cout << "\n-------------------- Student Management System ----------------\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Find how many courses passed\n";
    cout << "4. Find how many courses failed\n";
    cout << "5. Find how many credits accumulated\n";
    cout <<"6. Exit\n";
    cout << "Please enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        Student s;
        s.enterInfo();
        students.push_back(s);
    }
    else if (choice == 2) {
        for (const Student& s : students) {
            s.display();
        }
    }
    else if (choice == 3) {
        int rollno;
        bool found = false;
        cout << "Please enter roll number of student: ";
        cin >> rollno;
        for (const Student& s : students) {
            if (s.getrollNumber() == rollno) {
                found = true;
                cout << "Number of courses passed: " << s.CountPassed() << endl;
            }
        }
        if(!found){
            cout<<"student with roll number "<<rollno <<" not found.";
        }
    }
    else if (choice == 4) {
        int rollno;
        bool found = false;
        cout << "Please enter roll number of student: ";
        cin >> rollno;
        for (const Student& s : students) {
            if (s.getrollNumber() == rollno) {
                found = true;
                cout << "Number of courses failed: " << s.CountFailed() << endl;
            }
        }
        if(!found){
            cout<<"student with roll number "<<rollno <<" not found.";
        }
    }
    else if (choice == 5) {
        int rollno;
        bool found = false;
        cout << "Please enter roll number of student: ";
        cin >> rollno;
        for (const Student& s : students) {
            if (s.getrollNumber() == rollno) {
                found = true;
                cout << "Total credits accumulated: " << s.TotalCredits() << endl;
            }
        }
        if(!found){
            cout<<"student with roll number "<<rollno <<" not found.";
        }
    }
    else if(choice == 6){
        break;
    }
    else {
        cout << "Invalid choice" << endl;
    }
}

    return 0;
}
