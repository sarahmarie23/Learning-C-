#include <iostream>
using namespace std;

int main() {
  //program that writes the first n fibonacci numbers
  int userInput;
  cout<<"Please enter a positive integer greater than 1: ";
  cin>>userInput;

  int a = 0;
  int b = 1;
  int sum;
  int count = 1;

  cout<<1<<endl;

  while (count < userInput){
      sum = a + b;
      cout<<sum<<endl;
      a = b;
      b = sum;
      count++;
  }
}
