#include <iostream>
using namespace std;

int main() {
  int num1, num2, num3, num4;
  int mod1, mod2, mod3, mod4;
  int sum;

  cout<<"Please enter 4 positive integers, separated by a space: ";
  cin>>num1>>num2>>num3>>num4;
  cout<<""<<endl;

  mod1 = num1 % 2;
  mod2 = num2 % 2;
  mod3 = num3 % 2;
  mod4 = num4 % 2;

  sum = mod1 + mod2 + mod3 + mod4;

  if(sum < 2){
    cout<<"More evens";
  } else if(sum >= 3) {
    cout<<"More odds";
  } else {
    cout<<"Same number of evens and odds";
  }

  return 0;
}
