#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>

using namespace std;
class complexType{
 public:
    complexType(double = 0, double = 0);
    complexType(string&, string&);
    friend ostream& operator<< (ostream& os, const complexType& num);
  friend complexType operator+(const complexType& num1, const complexType& num2);
    bool operator>(complexType&);
    bool operator==(const complexType&) const;
    void swap(complexType&, complexType&);
 private:
  double real;
  double imaginary;
    double value;
};

#endif
