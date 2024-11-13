// box.cpp
// d13m11y2024
// Horton and van Weert (2023), Chapter 12, p. 427ff
// Making a Box class, etc.
// NOTE: To compile, use 'g++', not 'gcc', e.g.:
// 'g++ box.cpp -o box'
// 'gcc' results in too many errors with inconsistencies.
//

#include <iostream>
//#include<stdio.h>
// #include<cstdio>

using namespace std;

// Class definition:
class Box
{
public:
  // Prototype, etc., declaration:
  Box() = default;    // User-defined (or defaulted) default constructor
  Box(double length, double width, double height);    // Three parameter delegated constructor

  explicit Box(double side);    // single argument/parameter constructor
  // Recall, the single argument constructor requires 'explicit' keyword to
  // avoid implicit conversion
  // NOTE: Although, the order does not matter, the single argument constructo
  // was declared after the three parameter one for convention purposes.
  // This is because, in its definition, the three parameter constructor act
  // as the delegated constructor which will be called by the
  // single parameter one. (See p. 439)

  double volume();    // Member function

private:
  double m_length;    // Will be initialized later...
  double m_width;   // in the member intializer list
  double m_height;
};    // Don't forget the semi-colon (;) that goes here!

// Delegated constructor definition:
Box::Box(double length, double width, double height)
  :m_length{length}, m_width{width}, m_height{height}
{
  //std::cout << "Box constructor (3-parameter) called." <<std::endl;
  printf("Box constructor (3-parameter) called.\n");
}

// Single argument constructor definition:
Box::Box(double side):Box{side, side, side}
{
  //std::cout << "Box constructor (1-parameter) called" << std::endl;
  printf("Box constructor (1-parameter) called.\n");
}

// Member function definition:
double Box::volume()
{
  return m_length * m_width * m_height;
}

// Class implementation:
int main()
{
  Box myBox; // Class instantiation (create an instance of the class object)

  // Testing if the following assignment line works:
  myBox = Box{1.0,2.0,4.0};    // Initialize object
  // Findings: I need some sort of set() member function in orer to be
  // able to make this kind of initialization.
  double boxVolume{1.0};

  // Alternatively, write this:
  //Box myBox {1.0, 2.0, 4.0};
  Box myCube{1.0};
  
  boxVolume = myBox.volume();

  //std::cout << "Volume of my box is = " << myBox.volume() << std::endl;
  cout << "Volume of my box is = " << myBox.volume() << endl;
  //printf("Volume of my box is = %s\n", myBox.volume());    // Print

  //printf("Volume of my box is = %d\n", boxVolume);    // Print

  printf("Volume of my cube is = %d cubic-units\n", myCube.volume());

  return 0;
}
