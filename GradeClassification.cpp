#include <iostream>
using namespace std;

int main() {
  int grade1, grade2;
  
  cout<<"Please enter two grades, separated by a space: ";
  cin>>grade1>>grade2;
  
  if(grade1 < 60 && grade2 < 60){
    cout<<"Student failed :(";
  } else if(grade1 >= 95 && grade2 >= 95){
    cout<<"Student graduated with honors :)";
  } else {
    cout<<"Student graduated";
  }
  
  return 0;
}
