#include <iostream>
using namespace std;
int main()
{
    char* ptr=new char;
    *ptr ='A';
    cout<<"Stored character: "<<*ptr<<endl;
    delete ptr;
    ptr=nullptr;
    return 0;
}
