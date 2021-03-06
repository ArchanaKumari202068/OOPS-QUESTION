// Write a program to show that the effect of default 
//arguments can alternatively achieved by overloading
#include <iostream>
using namespace std;
//class named Maths is created
class Maths{
  private:
  
  public:
  //Members functions
  double power(double m,int n);
  double power(double m);
};
//Function definition for power
double Maths::power(double m, int n){
    int result = 1;
    for(int i = 0;i<n;i++){
        result *= m;
    }
    return result;
}
// Overloading Power Function 
double Maths::power(double m){
    int n = 2;
    return power(m,n);
}

int main()
{
  // Object is created
    Maths m1;
    int base,exponent;
    cout<<"power function with only base value\n";
    cout<<"Enter base value: ";
    cin>>base;
    cout<<"Value: "<<m1.power(base);
    cout<<"\npower function with both base and exponent value\n";
    cout<<"Enter base value: ";
    cin>>base;
    cout<<"Enter exponent value: ";
    cin>>exponent;
    cout<<"Value: "<<m1.power(base,exponent);

    return 0;
}

