#include <iostream>
using namespace std;
struct Product
{
    int productID;
    string productName;
    double price;
    int quantity;
    double calculateTotalPrice()
    {
        return price*quantity;
    }
};
int main()
{
    Product p;
    cout<<"Enter product ID: ";
    cin>>p.productID;
    cout<<"Enter product name: ";
    cin>>p.productName;
    cout<<"Enter price: ";
    cin>>p.price;
    cout<<"Enter quantity: ";
    cin>>p.quantity;
    cout<<"Product Details:"<<endl;
    cout<<"Product ID: "<<p.productID<<endl;
    cout<<"Product Name: "<<p.productName<<endl;
    cout<<"Price: "<<p.price<<endl;
    cout<<"Quantity: "<<p.quantity<<endl;
    cout<<"Total Price: "<<p.calculateTotalPrice()<<endl;
    return 0;
}
