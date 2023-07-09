#include <iostream>
#include <string>
using namespace std;


//declare a class called car with private members
class Car {
private:
    string make; // ex: Toyota
    int year;     // ex: 2023
    string model; // ex: land cruiser
    
//we usually declare functions as public 
public:

//  function gets user input and assigns the input to make
    void setMake() {
        cout << "Please enter the Car make value: ";
        //for string variable use getline 
        getline(cin, make);
    }
//  function gets user input and assigns the input to year
    void setYear() {
        cout << "Please enter the Car year value: ";
        cin >> year;
         // ignore the newline character in the input 
        cin.ignore();
    }
//  function gets user input and assigns the input to model
    void setModel() {
        cout << "Please enter the Car model value: ";
         //for string variable use getline
        getline(cin, model);
    }
// function retrieves and displays make
    string getMake() const {
        return make;
    }
// function retrieves and displays make
    int getYear() const {
        return year;
    }
// function retrieves and displays make
    string getModel() const {
        return model;
    }
//print() uses the above three functions to retrieve and display
// make, year and model
    void print() const {
        cout << "Make of car: " << getMake() << "\n";
        cout << "Year of car: " << getYear() << "\n";
        cout << "Model of car: " << getModel() << "\n";
    }
};

int main() {
    //assign the carInfo class
    Car carInfo;
    //Calling the functions setMake(), setYear(), setModel() and print() 
    
    carInfo.setMake();
    carInfo.setYear();
    carInfo.setModel();
    carInfo.print();

    return 0;
}
