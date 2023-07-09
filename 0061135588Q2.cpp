#include <iostream>
#include <string>
using namespace std;

// engine class has one private member:
class Engine {
private:
    int cylinders;  // ex: 6
//engine class has two public members to set and get the private variable
public:
    void setCylinders(int numCylinders) {
        cylinders = numCylinders;
    }

    int getCylinders() const {
        return cylinders;
    }
};
//doors class has one private member:
class Doors {
private:
    int numberOfDoors;   //ex: 2
//doors class has two public members to set and get the private variable
public:
    void setNumberOfDoors(int numDoors) {
        numberOfDoors = numDoors;
    }

    int getNumberOfDoors() const {
        return numberOfDoors;
    }
};

class Car {
// Declaring the private variables of the class. 
private:
    string make;
    int year;
    string model;
    Engine cEngine;
    Doors cDoors;

public:
    
     // This function prompts the user to enter a value for the make of the car
     
    void setMake() {
        cout << "Please enter the Car make value:";
          //for string variable use getline 
        getline(cin, make);
    }

   
     /*The function setYear() prompts the user to enter the year of the car and stores the value in the
     variable year*/
    
    void setYear() {
        cout << "Please enter the Car year value: ";
        cin >> year;
        cin.ignore(); 
    }

   
    // This function sets the model of the car
    
    void setModel() {
        cout << "Please enter the Car model value: ";
          //for string variable use getline 
        getline(cin, model);
    }

  /*
    This function prompts the user to enter the number of cylinders for the engine and then sets the
    number of cylinders for the engine
   */
    void setEngineCylinders() {
        int numCylinders;
        cout << "Please enter the Engine cylinders value:";
        cin >> numCylinders;
        cEngine.setCylinders(numCylinders);
    }

   
    //This function is used to set the number of doors for the car
    
    void setNumberOfDoors() {
        int numDoors;
        cout << "Please enter the Doors number value: ";
        cin >> numDoors;
        cDoors.setNumberOfDoors(numDoors);
    }

    
     //This function returns the value of the private variable make

    string getMake() const {
        return make;
    }

    
     // It returns the year of the date.
    
     
    int getYear() const {
        return year;
    }

 
   //It returns the model of the car.
 
    string getModel() const {
        return model;
    }

  
   // The function getEngineCylinders() returns the number of cylinders in the engine
  
   
    int getEngineCylinders() const {
        return cEngine.getCylinders();
    }

  // The function returns the number of doors in the car
  
    int getNumberOfDoors() const {
        return cDoors.getNumberOfDoors();
    }

   
    // This function prints the make, year, model, number of cylinders, and number of doors of the car
    
    void print() const {
        cout << "Make of car: " << getMake() << "\n";
        cout << "Year of car: " << getYear() << "\n";
        cout << "Model of car: " << getModel() << "\n";
        cout << "Number of cylinders: " << getEngineCylinders() << "\n";
        cout << "Number of doors: " << getNumberOfDoors() << "\n";
    }
};

/*
 * The main function creates an object of the Car class, calls the set functions to set the values of
 * the private data members, and then calls the print function to print the values of the private data
 * members.
 */
int main() {
    Car carInfo;

    carInfo.setMake();
    carInfo.setYear();
    carInfo.setModel();
    carInfo.setEngineCylinders();
    carInfo.setNumberOfDoors();
    carInfo.print();

    return 0;
}


/* Question1: Because cars have engines and doors, we need to build a composition between the Car class and the Engine and Doors classes.
The contained objects (the engine and doors) share the lifetime of the containing object (the car object). 
Destroying the vehicle object destroys its contents.
We can make Engine and Doors private Car class members to implement this relationship.
 The Car class can then provide member functions to access and modify Engine and Door private members as needed.
*/ 
