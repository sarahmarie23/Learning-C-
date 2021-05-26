#include <iostream>
using namespace std;

int main() {
  double weight_entered;
  double height_entered;
  double BMI_calculated;

  cout<<"Please enter weight in pounds: ";
  cin>>weight_entered;
  cout<<"Please enter height in inches: ";
  cin>>height_entered;

  BMI_calculated = (weight_entered * 0.453592)/(height_entered * 0.0254 * height_entered * 0.0254);
  
  cout<<"\nBMI is: ";
  printf("%.2f", BMI_calculated);

  return 0;
}
