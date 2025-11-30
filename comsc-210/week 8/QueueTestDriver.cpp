#include <iostream>
#include <string>
#include "Queue.h"
#include <cassert>
using namespace std;

void testQueuePrimitive()
{
    cout << "Programmer: Jie Zhou\n";
    cout << "Programmer's ID: 2047477\n";

    cout << "Queue test: double" << endl;
    cout << "-------------------------------" << endl;

    Queue<double> queueDouble;

    cout << "Testing queue::size" << endl;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << queueDouble.size() << endl;
    cout << (queueDouble.size() == 0 ? "Pass!" : "Fail!") << endl << endl;

    cout << "Testing queue::push & queue::front" << endl;
    queueDouble.push(1.1);
    queueDouble.push(2.2);
    cout << "EXPECTED: 1.1" << endl;
    cout << "ACTUAL: " << queueDouble.front() << endl;
    cout << (queueDouble.front() == 1.1 ? "Pass!" : "Fail!") << endl << endl;

    cout << "Testing queue::pop" << endl;
    cout << "Before pop: " << queueDouble.front() << endl;
    queueDouble.pop();
    cout << "After popping: " << queueDouble.front() << endl;
    queueDouble.push(2.2);
    cout << (queueDouble.front() == 2.2 ? "Pass!" : "Fail!") << endl << endl;

    cout << "Testing queue::back" << endl;
    cout << "EXPECTED: 2.2" << endl;
    cout << "ACTUAL: " << queueDouble.back() << endl;
    cout << (queueDouble.back() == 2.2 ? "Pass!" : "Fail!") << endl << endl;

    cout << "Testing copy constructor" << endl;
    Queue<double> copyQueueDouble(queueDouble);
    cout << "Pass!" << endl << endl;

    cout << "Testing assignment operator" << endl;
    Queue<double> assignedQueueDouble;
    assignedQueueDouble = copyQueueDouble;
    cout << "Pass!" << endl << endl;

    cout << "Testing queue::clear & empty" << endl;
    copyQueueDouble.clear();
    cout << (copyQueueDouble.empty() ? "Pass!" : "Fail!") << endl << endl;

    cout << "Constant object test:" << endl;
    const Queue<double> constQueueDouble(queueDouble);
    cout << "size: " << constQueueDouble.size() << endl;
    cout << (!constQueueDouble.empty() ? "Its NOT empty!" : "") << endl << endl;
}

void testQueueString()
{
    cout << "Queue test: string" << endl;
    cout << "-------------------------------" << endl;

    Queue<string> queueString;

    // Testing queue::size
    cout << "Testing Queue::size" << endl;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << queueString.size() << endl;
    cout << (queueString.size() == 0 ? "Pass!" : "Fail!") << endl << endl;

    // Testing queue::push & queue::front
    cout << "Testing Queue::push & Queue::front" << endl;
    queueString.push("1.1");
    queueString.push("2.2");
    cout << "EXPECTED: 1.1" << endl;
    cout << "ACTUAL: " << queueString.front() << endl;
    cout << (queueString.front() == "1.1" ? "Pass!" : "Fail!") << endl << endl;

    // Testing queue::pop
    cout << "Testing Queue::pop" << endl;
    cout << "Before pop: " << queueString.front() << endl;
    queueString.pop();
    queueString.push("2.2");
    cout << "After pop: " << queueString.front() << endl;
    cout << (queueString.front() == "2.2" ? "Pass!" : "Fail!") << endl << endl;

    // Testing queue::back
    cout << "Testing Queue::back" << endl;
    cout << "EXPECTED: 2.2" << endl;
    cout << "ACTUAL: " << queueString.back() << endl;
    cout << (queueString.back() == "2.2" ? "Pass!" : "Fail!") << endl << endl;

    // Testing copy constructor
    cout << "Testing copy constructor" << endl;
    Queue<string> copyQueueString(queueString);
    cout << "Pass!" << endl << endl;

    // Testing assignment operator
    cout << "Testing assignment operator" << endl;
    Queue<string> assignedQueueString;
    assignedQueueString = copyQueueString;
    cout << "Pass!" << endl << endl;

    // Testing queue::clear & empty
    cout << "Testing Queue::clear & empty" << endl;
    copyQueueString.clear();
    cout << (copyQueueString.empty() ? "Pass!" : "Fail!") << endl << endl;

    // Constant object test
    cout << "Constant object test:" << endl;
    const Queue<string> constQueueString(queueString);
    cout << "size: " << constQueueString.size() << endl;
    cout << (!constQueueString.empty() ? "Its NOT empty!" : "") << endl << endl;
}


int main() {
    testQueuePrimitive();
    testQueueString();

    cout << "Program ended with exit code: 0" << endl;
    return 0;
}
