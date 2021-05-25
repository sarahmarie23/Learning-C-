#include <iostream>
using namespace std;

int main() {
  int dollars_entered;
  int cents_entered;
  int sum;
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;

  cout<<"Please enter the amount of money to convert:\n"<<endl;
  cout<<"# of dollars: ";
  cin>>dollars_entered;
  cout<<"# of cents: ";
  cin>>cents_entered;
  cout<<""<<endl;
  
  sum = (dollars_entered * 100) + cents_entered;
  quarters = sum/25;
  sum = sum - (quarters * 25);
  dimes = sum/10;
  sum = sum - (dimes * 10);
  nickels = sum/5;
  sum = sum - (nickels * 5);
  pennies = sum;

  cout<<"The coins are "<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels, and "<<pennies<<" pennies"<<endl;

  return 0;
}
