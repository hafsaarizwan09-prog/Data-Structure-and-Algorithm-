#include <iostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node(string word){
    data = word;
    next = nullptr;
    }
};

class Stack{
private:
    Node* top;
    int count;

public:
    Stack()
    {
    top = nullptr;
        count = 0;
    }

    ~Stack()
    {
    while ( top != nullptr)
    {
    Node* temp = top;
    top = top->next;
    delete temp;
    }
    }

    bool isEmpty()
    {
    return top == nullptr;
    }

    void push(string word)
    {
    Node* newNode = new Node(word);
    newNode->next = top;
    top = newNode;
    count++;
    }

    void pop(){
    if (isEmpty())
    return;
    Node* temp = top;
    top = top->next;
    delete temp;
    count--;
    }
    int size() {
    return count;
    }
    string peek()
    {
    if (isEmpty())
    return "";
    return top->data;
    }
    void undo() {
    if (isEmpty())
    {
    cout << "Nothing to undo" << endl;
    return;
    }
    cout << "Undone: " << peek() << endl;
    pop();
    cout << "Word count: " << size() << endl;
    if (isEmpty())
    cout << "No words left" << endl;
    else
    cout << "Last word: " << peek() << endl;
    }
};
int main(){
    Stack editor;
    int choice;
    string word;
    do {
    cout << "\n1. Type word";
    cout << "\n2. Undo";
    cout << "\n3. Word count";
    cout << "\n4. Last word";
    cout << "\n0. Exit";
    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice){
    case 1:
    cout << "Enter word: ";
    cin >> word;
    editor.push(word);
    cout << "Typed: " << word << endl;
    break;
    case 2:
    editor.undo();
    break;
    case 3:
    cout << "Word count: "
    << editor.size() << endl;
    break;
    case 4:
    if (editor.isEmpty())
    cout << "Editor is empty" << endl;
    else
    cout << "Last word: "
    << editor.peek() << endl;
    break;
    case 0:
    cout << "Exiting editor" << endl;
    break;
    default:
    cout << "Invalid choice" << endl;
    }
    } while (choice != 0);
    return 0;
}
