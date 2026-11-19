#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int value){
    data = value;
    next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack(){
    top = nullptr;
    }
    ~Stack()
    {
    while (!isEmpty())
    {
    pop();
    }
    }

    bool isEmpty()
    {
    return top == nullptr;
    }
    void push(int value)
    {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    }

    int pop(){
    if (isEmpty())
    return -1;
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
    }
};

int main(){
    int number;
    cout << "Enter number: ";
    cin >> number;
    if ( number < 0) {
    cout << "Please enter a non-negative number"
    << endl;
    return 0;
    }
    Stack s ;
    if ( number == 0){
    s.push(0);
    }
    else{
    while ( number > 0)
    {
    int remainder = number % 2;
    s.push(remainder);
    number = number / 2;
    }
    }
    cout << "Binary: ";
    while (! s.isEmpty())
    {
    cout << s.pop();
    }
    cout << endl;
    return 0;
}
