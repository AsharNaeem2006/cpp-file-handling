#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    float gpa;

public:
    Student() {}

    Student(int i, string n, int a, float g) {
        id = i;
        name = n;
        age = a;
        gpa = g;
    }

    void input() {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGPA: " << gpa << endl;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    float getGpa() {
        return gpa;
    }
};

void addStudent() {
    Student s;
    s.input();

    ofstream file("students.txt", ios::app);

    file << s.getId() << " "
         << s.getName() << " "
         << s.getAge() << " "
         << s.getGpa() << endl;

    file.close();

    cout << "\nStudent saved successfully!\n";
}

void viewStudents() {
    ifstream file("students.txt");

    int id, age;
    string name;
    float gpa;

    cout << "\n===== Student Records =====\n";

    while (file >> id >> name >> age >> gpa) {
        Student s(id, name, age, gpa);
        s.display();
        cout << "----------------------\n";
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");

    int searchId;
    bool found = false;

    cout << "Enter Student ID to search: ";
    cin >> searchId;

    int id, age;
    string name;
    float gpa;

    while (file >> id >> name >> age >> gpa) {
        if (id == searchId) {
            Student s(id, name, age, gpa);

            cout << "\nStudent Found:\n";
            s.display();

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found!\n";
    }

    file.close();
}

void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int deleteId;
    bool found = false;

    cout << "Enter Student ID to delete: ";
    cin >> deleteId;

    int id, age;
    string name;
    float gpa;

    while (file >> id >> name >> age >> gpa) {
        if (id == deleteId) {
            found = true;
            continue;
        }

        temp << id << " "
             << name << " "
             << age << " "
             << gpa << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "\nStudent deleted successfully!\n";
    } else {
        cout << "\nStudent not found!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;

        case 2:
            viewStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}