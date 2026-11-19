#include <iostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node(string page){
    data = page;
    next = nullptr;
    }
};
class Stack
{
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
    while (top != nullptr){
    Node* temp = top;
    top = top->next;
    delete temp;
    }
    }
    bool isEmpty()
    {
    return top == nullptr;
    }
    int size(){
    return count;
    }
    void push(string page) {
    Node* newNode = new Node(page);
    newNode->next = top;
    top = newNode;
    count++;
    }
    void pop() {
    if (isEmpty())
    return;
    Node* temp = top;
    top = top->next;
    delete temp;
    count--;
    }
    string peek()
    {
    if (isEmpty())
    return "";
    return top->data;
    }
    void display()
    {
    if (isEmpty())
    {
    cout << "History is empty" << endl;
    return;
    }
    Node* current = top;
    cout << "History (current to oldest): ";
    while (current != nullptr)
    {
    cout << current->data << " ";
    current = current->next;
    }
    cout << endl;
    }
};
int main(){
    Stack history;
    int choice;
    string page;
    do{
    cout << "\n1. Visit page";
    cout << "\n2. Back";
    cout << "\n3. Current page";
    cout << "\n4. History";
    cout << "\n0. Exit";
    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice){
    case 1:
    cout << "Enter page name: ";
    cin >> page;
    history.push(page);
    cout << "Visited: " << page << endl;
    break;
    case 2:
    if (history.size() <= 1) {
    cout << "Cannot go back" << endl;
    }
    else {
    history.pop();
    cout << "Current page: "
    << history.peek() << endl;
    }
    break;
    case 3:
    if (history.isEmpty())
    cout << "No page open" << endl;
    else
    cout << "Current page: "
    << history.peek() << endl;
    break;
    case 4:
    history.display();
    break;
    case 0:
    cout << "Exiting browser" << endl;
    break;
    default:
    cout << "Invalid choice" << endl;
    }
    } while (choice != 0);
    return 0;
}
