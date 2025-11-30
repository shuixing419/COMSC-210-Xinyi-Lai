// Class Array declaration
class Array {
    int values[100]; // initialize to 0
    int dummy;

public:
    Array(); 
    int capacity() const; 
    int operator[](int) const; // getter version of square bracket operator
    int& operator[](int); // setter version of square bracket operator
};

// Class Array member function implementations
Array::Array() {
    // initialize all elements to 0
    for (int i = 0; i < 100; i++) {
        values[i] = 0;
    }
    // initialize dummy to any value
    dummy = -1;
}

int Array::capacity() const {
    // return the size of the array
    return 100;
}

int Array::operator[](int index) const {
    // getter version of square bracket operator
    // check if index is within range
    if (index >= 0 && index < 100) {
        // return the value at the index
        return values[index];
    }
    else {
        // return dummy value if out of range
        return 0;
    }
}

int& Array::operator[](int index) {
    // setter version of square bracket operator
    // check if index is within range
    if (index >= 0 && index < 100) {
        // return a reference to the value at the index
        return values[index];
    }
    else {
        // return a reference to dummy value if out of range
        return dummy;
    }
}
