#include <iostream>   // Includes the input/output library for cout
#include <string>     // Includes the string data type
#include <utility>    // Includes std::move()

// Base class
class Person {
protected:
    std::string name;  // Protected data member to store person's name

public:
    // Constructor of Person class
    // explicit prevents unwanted automatic type conversion
    // std::move() transfers the string instead of copying it
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Member function to display the person's name
    // const means this function does not modify the object
    void displayName() const {
        std::cout << "Name: " << name << '\n';  // Print the name
    }
};

// Derived class Student inherits publicly from Person
class Student : public Person {
private:
    int rollNumber;  // Private data member to store student's roll number

public:
    // Constructor of Student class
    Student(std::string studentName, int roll)
        // Call the constructor of the base class Person
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Member function to display student's information
    void displayStudent() const {

        displayName();  // Call the inherited function from Person class

        // Display the student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function - execution starts here
int main() {

    // Create a Student object named student
    // "Amit" is passed as the name and 101 as the roll number
    Student student("Amit", 101);

    // Call displayStudent() to display student's details
    student.displayStudent();

    return 0;  // End the program successfully
}
