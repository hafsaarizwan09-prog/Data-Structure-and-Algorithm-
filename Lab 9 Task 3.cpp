
#include <iostream>
using namespace std;

const int MAX = 5;

int stk[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
    }
    else {
        top++;
        stk[top] = x;
        cout << x << " pushed." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
    }
    else {
        cout << "Popped: " << stk[top] << endl;
        top--;
    }
}
int search(int x) {
    for (int i = top; i >= 0; i--) {
        if (stk[i] == x) {
            return top - i + 1;
        }
    }

    return -1;
}

int main() {
    int value;

    cout << "Enter 5 integers:" << endl;

    for (int i = 0; i < MAX; i++) {
        cin >> value;
        push(value);
    }

    cout << "\nTrying to push sixth element:" << endl;
    push(60);

    cout << "\nEnter a value to search (present): ";
    cin >> value;

    int result = search(value);

    if (result != -1)
        cout << "Found at " << result << " step(s) from top." << endl;
    else
        cout << "Value not found." << endl;

    cout << "\nEnter an absent value to search: ";
    cin >> value;

    result = search(value);

    if (result != -1)
        cout << "Value found at " << result << " step(s) from top." << endl;
    else
        cout << "Value not found. Search returned -1." << endl;

    cout << "\nRemoving all elements:" << endl;

    while (!isEmpty()) {
        pop();
    }

    cout << "\nTrying to pop again:" << endl;
    pop();

    return 0;
}
