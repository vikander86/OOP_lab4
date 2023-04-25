# OOP_lab4

Inheritance

## Exercise 1

Setup new project with a main.cpp

## Exercise 2

Copied previous headers created in Lab3. Created a new vehicle class and a bike class.
Implemented inheritence to car and bike so they both inherit from the vehicle class.
Defined new print functions for vehicle, car and bike

## Exercise 3

From main.cpp.

Made vehicle objects using derived classes Car and Bike:

Vehicle *car = new Car();
Vehicle *bike = new Bike();

Called their print functions.

### Problemsolving

Using inheritance causes an issue if we're using static function binding. If I call the car->print() function, it will call the vehicles print function. By making it dynamic(using virtual), we can tell the compiler to check the rest of the code, to see if there's a different print() function we can use instead - in this case we're telling the compiler to go to the print member function of our Car class instead.

## Exercise 4

Created a boat class which inherits from the Vehicle class.
Created a Amphicar class inheriting from both Car and Boat classes
Created a amphicar in main

Vehicle \*amphicar = new Amphicar();

### Problemsolving

When creating the amphicar we're creating an object that inherits from two different classes(car and boat), that in turn, inherits from the same class(vehicle) which causes an ambiguous base meaning that we're creating two vehicles in the process.

To solve this we can use virtual inheritance by setting Boat and Car to inherit virtually, causing the compiler to only choose the vehicle class once.

## Exercise 5

Created a vehicle.txt with the provided information.

Created a function to return a unique ptr to an object of a Vehicle type.

Created a vector to store unique pointers to Vehicle type objects

Read from file and instantiated Vehicle objects which was then added to the vector.

Then iterated through the vector and called the print() function of each Vehicle object.

### Problemsolving

I started by reading the from the file and adding the strings read from the file to a normal vector. Then I printed out the strings to great success. So now i had a way of reading the file.

I then used if statements to create a vehicle object based on the string read from the file. The code looked clunky and I figured I should refactor the code for better readability.

By creating a function in a different header, I could improve the readability and overall structure of the code.

A problem that occured was when creating unique pointers and trying to add them to the vector. I used the following line:

    vehicleList.push_back(vehicle)

This caused a compile error, telling me I'm trying to copy a unique pointer. Which I found out cannot be done, as std::unique_ptr holds unique ownership of that particular object. What I could do instead is move the pointer instead, as in, move the ownership of the pointer to the newly created vector object.

    vehicleList.push_back(std::move(vehicle))

Which worked wonders.

