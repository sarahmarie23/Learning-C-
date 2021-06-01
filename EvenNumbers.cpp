#include <iostream>
using namespace std;

int main() {
  int user_input;
  int counter = 2;

  cout<<"Please enter a positive integer: ";
  cin>>user_input;

  while (user_input > 0){
    cout<<counter<<endl;
    counter+=2;
    user_input--;
  }

  return 0;
}
