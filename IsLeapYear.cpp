#include <iostream>
using namespace std;

int main() {
  int year;

  cout<<"Please enter a year: ";
  cin>>year;

  //divisible by 4 but not by 100 unless it is also divisible by 400.
  if((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0)){
    cout<<year<<" was a leap year";
  } else {
    cout<<year<<" was not a leap year";
  }

  return 0;
}
