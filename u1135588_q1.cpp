#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    string name;
    string ID;
    string course;
    int age;
};

void saveStudentsToFile(const Student students[], int size, const string &filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "Failed to open the file." << endl;
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        file << "Student name: " << students[i].name << endl;
        file << "Student ID: " << students[i].ID << endl;
        file << "Student course: " << students[i].course << endl;
        file << "Student age: " << students[i].age << endl;
        file << endl;
    }

    file.close();
}

void displayStudentsFromFile(const string &filename)
{
    ifstream file(filename);
    string line;

    if (!file)
    {
        cout << "Failed to open the file." << endl;
        return;
    }

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

int main()
{
    const int numStudents = 4;
    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i)
    {
        cout << "Please enter student name: ";
        getline(cin, students[i].name);

        cout << "Please enter student ID: ";
        getline(cin, students[i].ID);

        cout << "Please enter student course: ";
        getline(cin, students[i].course);

        cout << "Please enter student age: ";
        cin >> students[i].age;
        cin.ignore(); // Ignore the newline character after reading age

        cout << endl;
    }

    string filename = "studentUSQ.txt";
    saveStudentsToFile(students, numStudents, filename);

    cout << "And " << filename << ":" << endl;
    displayStudentsFromFile(filename);

    return 0;
}
