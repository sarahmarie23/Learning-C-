#include <iostream>
using namespace std;

int main() {
  double weight_entered;
  double height_entered;
  double BMI_calculated;

  cout<<"Please enter weight in kilograms: ";
  cin>>weight_entered;
  cout<<"Please enter height in meters: ";
  cin>>height_entered;

  BMI_calculated = weight_entered/(height_entered * height_entered);

  cout<<"BMI is: ";
  printf("%.2f", BMI_calculated);

  return 0;
}
