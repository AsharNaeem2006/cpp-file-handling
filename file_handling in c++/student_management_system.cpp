#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Student{
    private:
    string name;
    int age;
    string id;
    int marks;
    public:
    void add_new_student();
    void display_all_students();
    void search_student();
    void update_student_record();
    void delete_student_record();
};
void Student::add_new_student()
{
    fstream fout;
    fout.open("Student.txt",ios::app|ios::out);
    cout << "Enter your name :";
    cin.ignore();
    getline(cin,name);
    cout << "Enter your age : ";
    cin >>age ;
    cin.ignore();
    cout  <<"Enter your id :";
    getline(cin,id);
    cout << "Enter your marks : ";
    cin  >>marks;
    fout << name<<'|'<<age<<'|'<<id<<'|'<<marks<<endl;
    cout << "Student Record Successfully added in file \n";
    fout.close();
}
void Student::display_all_students()
{
    fstream fin;
    fin.open("Student.txt",ios::in);
    if(!fin.is_open()||fin.peek()==ifstream::traits_type::eof())
    {
        cout << "File is empty\n";
        return;
    }
    while(getline(fin,name,'|')&&fin>>age&&fin.ignore()&&getline(fin,id,'|')&&fin>>marks)
    {
        fin.ignore();
        cout << name <<'|'<<age<<'|'<<id<<'|'<<marks<<endl;
    }
    fin.close();
}
void Student::search_student()
{
    fstream fin;
    fin.open("Student.txt",ios::in);
    if(!fin.is_open() || fin.peek()==fstream::traits_type::eof())
    {
        cout << "File is empty\n";
        return;
    }
    string search_name;     
    cout << "Enter name : ";
    cin.ignore();
    getline(cin,search_name);
    bool found=false;
    while(getline(fin,name,'|')&&fin>>age&&fin.ignore()&&getline(fin,id,'|')&&fin>>marks)
    {
        fin.ignore();
       if(search_name==name)
       {
            found=true;
            break;
       }
    }
    if(found)
    {
        cout << "Student found\n";
    }
    else{
        cout << "Not found \n";
    }
    fin.close();
    
}
void Student::update_student_record()
{
    fstream fin("Student.txt", ios::in);
    fstream fout("temp.txt", ios::out);

    if (!fin.is_open() || fin.peek() == EOF)
    {
        cout << "File is empty\n";
        return;
    }

    string search_name;
    cout << "Enter name to update record: ";
    cin.ignore();
    getline(cin, search_name);

    bool found = false;

    while (getline(fin, name, '|') &&
           fin >> age &&
           fin.ignore() &&
           getline(fin, id, '|') &&
           fin >> marks)
    {
        fin.ignore(); 

        if (search_name == name)
        {
            found = true;

            cout << "Enter new name: ";
            getline(cin, name);

            cout << "Enter new age: ";
            cin >> age;

            cin.ignore();
            cout << "Enter new id: ";
            getline(cin, id);

            cout << "Enter new marks: ";
            cin >> marks;
        }

        fout << name << '|' << age << '|' << id << '|' << marks << endl;
    }

    fin.close();
    fout.close();

    remove("Student.txt");
    rename("temp.txt", "Student.txt");

    if (found)
        cout << "Student record updated successfully\n";
    else
        cout << "Student not found\n";
}
void Student::delete_student_record()
{
    fstream fin;
    fin.open("Student.txt",ios::in);
    if(!fin.is_open()||fin.peek()==fstream::traits_type::eof())
    {
        cout << "File is empty\n";
    }
    fstream fout;
    fout.open("temp.txt",ios::out);
    string del_name;
    cout << "Enter name to delete the record :";
    cin.ignore();
    getline(cin,del_name);
    bool found=false;
    while(getline(fin,name,'|')&&fin>>age&&fin.ignore()&&getline(fin,id,'|')&&fin>>marks)
    {
        fin.ignore();
        if(del_name==name)
        {
            found=true;
            continue;
        }
        fout << name<<'|'<<age<<'|'<<id<<'|'<<marks<<endl;
    }
    if(found)
    {
        cout << "Student record is successfully deleted\n";
    }
    else{
        cout << "Student with this name is not found \n";
    }
    fin.close();
    fout.close();
    remove("Student.txt");
    rename("temp.txt","Student.txt");
    
}
int main()
{
    Student S1;
    int choice;
    do{
        cout << "\n......Student management system.........\n";
        cout << "1.Add New Student\n";
        cout << "2.Display All Students \n";
        cout << "3.Search Student\n";
        cout << "4.Update Student Record\n";
        cout << "5.Delete Student Record\n";
        cout << "6.Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            S1.add_new_student();
            break;
            case 2:
            S1.display_all_students();
            break;
            case 3:
            S1.search_student();
            break;
            case 4:
            S1.update_student_record();
            break;
            case 5:
            S1.delete_student_record();
            break;
            case 6:
            cout << "Exiting...\n";
            break;
            default:
            cout << "Invalid choice...\n";
            break;
        }
    }while(choice!=6);
    return 0;
}
