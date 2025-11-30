#include <iostream>
#include <string>
#include "StackTemplate.h"

using namespace std;

void testStackPrimitive()
{
  cout << "Programmer: Jie Zhou\n";
  cout << "Programmer's ID: 2047477\n";

  cout << "Stack test:(double)" << endl;
  cout << "-------------------------------" << endl;

  // Testing stack::size
  Stack<double> stackDouble;
  cout << "Testing stack::size" << endl;
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << stackDouble.size() << endl;
  cout << (stackDouble.size() == 0 ? "Pass!" : "Fail!") << endl << endl;

  // Testing stack::peek & stack::push
  cout << "Tesing stack::peek & stack::push" << endl;
  stackDouble.push(1.1);
  cout << "EXPECTED: 1.1" << endl;
  cout << "ACTUAL: " << stackDouble.peek() << endl;
  cout << (stackDouble.peek() == 1.1 ? "Pass!" : "Fail!") << endl << endl;

  // Testing Stack::pop
  cout << "Testing stack::pop" << endl;
  cout << "Before pop: " << stackDouble.peek() << endl;
  stackDouble.pop();
  cout << "After pop: ";
  stackDouble.push(2.2);
  cout << (stackDouble.empty() ? "Stack is empty" : std::to_string(stackDouble.peek())) << endl;
  cout << (!stackDouble.empty() ? "Pass!" : "Fail!") << endl << endl;
  stackDouble.push(3.3);
  stackDouble.push(4.4);
  stackDouble.push(5.5);
  stackDouble.push(6.6);


  // Testing copy constructor
  cout << "Testing copy constructor" << endl;
  Stack<double> copyStackDouble(stackDouble);
  cout << "Pass !" << endl << endl;

  // Testing assignment operator
  cout << "Tesing assignment operator" << endl;
  Stack<double> assignedStackDouble;
  assignedStackDouble = copyStackDouble;
  cout << "Pass !" << endl << endl;

  // Testnig Stack::size
  cout << "Testnig Stack::size" << endl;
  cout << "After pushing 5 now element, size is: " << copyStackDouble.size() << endl;
  cout << (copyStackDouble.size() == 5 ? "Pass!" : "Fail!") << endl << endl;

  // Testing stack::clear & empty
  cout << "Testing stack::clear & empty" << endl;
  copyStackDouble.clear();
  cout << (copyStackDouble.empty() ? "Pass!" : "Fail!") << endl << endl;

  // Constant object test
  const Stack<double> constStackDouble = assignedStackDouble;
  cout << "Constant object test:size:" << endl;
  cout << "size is: " << constStackDouble.size() << endl;
  cout << (constStackDouble.size() == 0 ? "It's empty!" : "It's not empty!") << endl << endl;
}

void testStackString()
{


  cout << "Stack test:(string)" << endl;
  cout << "-------------------------------" << endl;

  // Testing stack::size
  Stack<string> stackString;
  cout << "Testing stack::size" << endl;
  cout << "EXPECTED: 0" << endl;
  cout << "ACTUAL: " << stackString.size() << endl;
  cout << (stackString.size() == 0 ? "Pass!" : "Fail!") << endl << endl;

  // Testing stack::peek & stack::push
  cout << "Tesing stack::peek & stack::push" << endl;
  stackString.push("ONE");
  cout << "EXPECTED: ONE" << endl;
  cout << "ACTUAL: " << stackString.peek() << endl;
  cout << (stackString.peek() == "ONE" ? "Pass!" : "Fail!") << endl << endl;

  // Testing Stack::pop
  cout << "Testing Stack::pop" << endl;
  cout << "Before pop: " << stackString.peek() << endl;
  stackString.pop();
  stackString.push("TWO");
  cout << "After pop: ";
  cout << (stackString.empty() ? "Stack is empty" : stackString.peek()) << endl;
  cout << (!stackString.empty() ? "Pass!" : "Fail!") << endl << endl;

  stackString.push("THREE");
  stackString.push("FOUR");
  stackString.push("FIVE");
  stackString.push("SIX");

  // Testing copy constructor
  cout << "Testing copy constructor" << endl;
  Stack<string> copyStackString(stackString);
  cout << "Pass!" << endl << endl;

  // Testing assignment operator
  cout << "Tesing assignment operator" << endl;
  Stack<string> assignedStackString;
  assignedStackString = copyStackString;
  cout << "Pass!" << endl << endl;

  // Testnig Stack::size()
  cout << "Testnig Stack::size()" << endl;
  cout << "After pushing 5 new elements, size is: " << copyStackString.size() << endl;
  cout << (copyStackString.size() == 5 ? "Pass!" : "Fail!") << endl << endl;


  // Testing stack::clear & empty
  cout << "Testing stack::clear & empty" << endl;
  copyStackString.clear();
  cout << (copyStackString.empty() ? "Pass!" : "Fail!") << endl << endl;

  // Constant object test
  const Stack<string> constStackString = assignedStackString;
  cout << "Constant object test:size:" << endl;
  cout << "size is: " << constStackString.size() << endl;
  cout << (constStackString.size() == 0 ? "It's empty!" : "It's not empty!") << endl << endl;
}

int main() {
  testStackPrimitive();
  testStackString();

  cout << "Program ended with exit code: 0" << endl;
  return 0;
}

