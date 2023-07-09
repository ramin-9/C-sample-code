#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// usually functions are public. for each phone, person and address we declare two set and get functions.
class Person
{
public:
    /*
     * The function setName() takes a string as an argument and sets the name of the object to the value
     * of the string. data type is void because it doesn't return anything.
     */
    void setName(string name)
    {
        personName = name;
    }
    // get functions should be constant because it is read only.
    string getName() const
    {
        return personName;
    }

    /*
     * The function setPhone() takes a string as an argument and sets the phone number to the value of
     * the string
     */
    void setPhone(string phone)
    {
        personPhone = phone;
    }
    string getPhone() const
    {
        return personPhone;
    }

    /**
     * The function setAddress() takes a string as an argument and sets the address of the object to
     * the value of the string
     */
    void setAddress(string address)
    {
        personAddress = address;
    }
    string getAddress() const
    {
        return personAddress;
    }

    void print() const
    {
        cout << "Name: " << personName << endl;
        cout << "Phone: " << personPhone << endl;
        cout << "Address: " << personAddress << endl;
    }

    // Declaring the private variables of the class.
private:
    string personName;
    string personPhone;
    string personAddress;
};
// Implement class staff which inherits from person, with two additional private members. it can use the puplic members of the person class.
class Staff : public Person
{
public:
    void setSchool(string school)
    {
        staffSchool = school;
    }
    string getSchool() const
    {
        return staffSchool;
    }

    void setSalary(int salary)
    {
        staffSalary = salary;
    }
    int getSalary() const
    {
        return staffSalary;
    }

    /**
     * The function `print()` is a member function of the class `Staff` that prints the name, age, school,
     * and salary of a staff member
     */
    void print() const
    {
        Person::print();
        cout << "School: " << staffSchool << endl;
        cout << "Salary: $" << staffSalary << endl;
    }

    // Declaring the private variables of the class.
private:
    string staffSchool;
    int staffSalary;
};
// Implement class student which inherits from person, with two additional private members. it can use the puplic members of the person class.
class Student : public Person
{
public:
    /**
     * The setProgram function sets the studentProgram variable to the value of the program variable
     */
    void setProgram(string program)
    {
        studentProgram = program;
    }
    string getProgram() const
    {
        return studentProgram;
    }

    /**
     * The setGPA function takes a float as an argument and sets the studentGpa variable to that value
     */
    void setGPA(float gpa)
    {
        studentGpa = gpa;
    }
    float getGPA() const
    {
        return studentGpa;
    }

    /**
     * The function print() is a member function of the class Student. It is a const function, which means
     * that it does not modify the object on which it is called. It is a public function, which means that
     * it can be called by any function. It has no parameters. It returns no value. It is a void function,
     * which means that it does not return a value
     */
    void print() const
    {
        Person::print();
        cout << "Program: " << studentProgram << endl;
        cout << "GPA: " << studentGpa << endl;
    }

    // Declaring the private variables of the class.
private:
    string studentProgram;
    float studentGpa;
};

int main()
{
    // Declaring the variables outFile and option.
    ofstream outFile;
    string option;

    // Asking the user to enter either staff or student to add a new staff or student.
    while (true)
    {
        cout << "Enter \"staff\" to add a new staff , \"student\" to add a new student, or other key to exit: ";
        cin >> option;

        /* The below code is creating a new staff member and then writing the staff member's information
        to a file. */
        if (option == "staff")
        {
            Staff staff;
            string name, phone, address, school;
            int salary;

            cout << "Please enter staff name: ";
            cin.ignore();
            getline(cin, name);
            staff.setName(name);

            cout << "Please enter staff phone number: ";
            getline(cin, phone);
            staff.setPhone(phone);

            cout << "Please enter staff address: ";
            getline(cin, address);
            staff.setAddress(address);

            cout << "Please enter staff school: ";
            getline(cin, school);
            staff.setSchool(school);

            cout << "Please enter staff salary: ";
            cin >> salary;
            staff.setSalary(salary);

            staff.print();

            outFile.open("staffRegister.txt", ios::app);
            outFile << "Name: " << staff.getName() << endl;
            outFile << "Phone: " << staff.getPhone() << endl;
            outFile << "Address: " << staff.getAddress() << endl;
            outFile << "School: " << staff.getSchool() << endl;
            outFile << "Salary: $" << staff.getSalary() << endl;
            outFile.close();
        }
        /* The below code is creating a student object and then setting the name, phone, address,
        program, and gpa of the student. Then it prints the student information and then writes the
        student information to a file. */
        else if (option == "student")
        {
            Student student;
            string name, phone, address, program;
            float gpa;

            cout << "Please enter student name: ";
            cin.ignore();
            getline(cin, name);
            student.setName(name);

            cout << "Please enter student phone number: ";
            getline(cin, phone);
            student.setPhone(phone);

            cout << "Please enter student address: ";
            getline(cin, address);
            student.setAddress(address);

            cout << "Please enter student program: ";
            getline(cin, program);
            student.setProgram(program);

            cout << "Please enter student GPA: ";
            cin >> gpa;
            student.setGPA(gpa);

            student.print();

            outFile.open("studentRegister.txt", ios::app);
            outFile << "Name: " << student.getName() << endl;
            outFile << "Phone: " << student.getPhone() << endl;
            outFile << "Address: " << student.getAddress() << endl;
            outFile << "Program: " << student.getProgram() << endl;
            outFile << "GPA:" << student.getGPA() << endl;
            outFile.close();
        }
        return 0;
    }
}
