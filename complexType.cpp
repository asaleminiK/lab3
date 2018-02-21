#include "complexType.h"
#include <cmath>

ostream& operator<<(ostream& os, const complexType& num){
  os << num.real << " + " << num.imaginary << "i";
  return os;
}

complexType operator+(const complexType& num1, const complexType& num2){
  complexType a(num1.real + num2.real, num1.imaginary + num2.imaginary);
  return a;
}


complexType::complexType(double r, double i): real(r), imaginary(i){
  value = sqrt(r*r+i*i);
}

complexType::complexType(string& r, string& i){
  if(i[0] == 'i')
    imaginary = 1;
  else if (i.size() == 2 && i[0] == '-')
    imaginary = -1;
  else{
    try{
      imaginary = std::stod(i.substr(0,i.size()-1));
    }
    catch(std::invalid_argument&){
      cout << "INVALID ARGUMENT ON IMAGINARY VALUE: "
           << i<< ". DEFAULTING TO ZERO."<< endl;
      imaginary = 0;}
  }
  try{
    real = std::stod(r);}
  catch(std::invalid_argument&){
    cout<< "INVALID ARGUMENT ON REAL VALUE : "
        << r << ". DEFAULTING TO ZERO"<< endl;
    real = 0;
  }
  value = sqrt(real*real+imaginary*imaginary);
}

bool complexType::operator>(complexType &a) {
    return value > a.value;
}

bool complexType::operator==(const complexType& a) const{
    return ((real == a.real) && (imaginary == a.imaginary));
}

void complexType::swap(complexType& First, complexType& Second){
  std::swap(First.real, Second.real);
  std::swap(First.imaginary, Second.imaginary);
  std::swap(First.value, Second.value);
}