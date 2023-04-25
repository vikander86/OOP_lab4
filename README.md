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
