#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int *p1,*p2;
    int temp;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<"Before swapping:"<<endl;
    cout<<"a= "<<a<<endl;
    cout<<"b = "<<b<<endl;
    p1=&a;
    p2=&b;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
    cout<<"After swapping:"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    return 0;
}
