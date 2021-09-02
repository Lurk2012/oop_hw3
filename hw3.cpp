////////////////////////  HW3   /////////////////////////
#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
//////////////////////// part 1 /////////////////////////
class Figure {
  protected :
    double A;
    double B;
  virtual double area() = 0; 
  public : 
    Figure(double A = 0, double B = 0) : A(A), B(B) {}
    double getA () const {return A;}
    double getB () const {return B;}
};

class Circle : public Figure {
  protected :
    double int_A;
  public :  
    Circle (double int_A) : Figure(int_A) {}     
    double area ()       {return A*A*3.14;}
};

class Parallelogram : public Figure {
  virtual double area() = 0;
  public :
    Parallelogram(double A = 0, double B = 0) : Figure(A, B) {}
};

class Rectangle : public Parallelogram {
  private :
    double int_A;
    double int_B;    
  public :       
    Rectangle (double int_A, double int_B) : Parallelogram(int_A, int_B) {} 
    double area ()       {return A * B;}
};

class Square : public Parallelogram {
  private :       
    double int_A;  
  public :  
    Square (double int_A) : Parallelogram(int_A) {}
    double area ()       {return A*A;}
};

class Rhombus : public Parallelogram {
  private :
    double int_A;
    double int_B;
  public :         
    Rhombus (double int_A, double int_B) : Parallelogram(int_A, int_B) {}
    double area ()       {return A * B;}
};
//////////////////////// part 2 /////////////////////////
class Car {
  protected :
    std::string company;
    std::string model;
  public :
    Car (std::string company = "Null", std::string model = "Null") : company(company), model(model)
    {std::cout << "Car" << "\n";};
    std::string getcompany () const {return company;}
    std::string getmodel   () const {return model;}
};

class PassengerCar: public Car {
  public :  
    PassengerCar (std::string company = "Null", std::string model = "Null") : Car(company, model)
    {std::cout << "PassengerCar" << "\n";}
};

class Bus: public Car {
  public :  
    Bus (std::string company = "Null", std::string model = "Null") : Car(company, model)
    {std::cout << "Bus" << "\n";}
};

class Minivan: public PassengerCar, public Bus {
  public :
    Minivan (std::string company = "Null", std::string model = "Null") : PassengerCar (company, model)//, Bus (company, model)
    {std::cout << "Minivan" << "\n";}
};
//////////////////////// part 3 /////////////////////////
class Fraction {
  protected :
    int num;
    int den;
  public :
    Fraction (int num = 0, int den = 1) : num(num), den(den) 
    {if (den == 0) std::cout << "\nerror ";}
    
    void printFraction () {std::cout << num << "/" << den << " ";}
    
    friend Fraction operator+ (const Fraction &f1, const Fraction &f2);
    friend Fraction operator- (const Fraction &f1, const Fraction &f2);
    friend Fraction operator* (const Fraction &f1, const Fraction &f2);
    friend Fraction operator/ (const Fraction &f1, const Fraction &f2);

    Fraction operator- () const {return Fraction(-num, den);}
    
    friend bool operator== (const Fraction &f1, const Fraction &f2);
    friend bool operator!= (const Fraction &f1, const Fraction &f2);
    friend bool operator<  (const Fraction &f1, const Fraction &f2);
    friend bool operator>  (const Fraction &f1, const Fraction &f2);
    friend bool operator<= (const Fraction &f1, const Fraction &f2);
    friend bool operator>= (const Fraction &f1, const Fraction &f2);
};
  
  Fraction operator+(const Fraction &f1, const Fraction &f2) {return Fraction(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);}
  Fraction operator-(const Fraction &f1, const Fraction &f2) {return Fraction(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);}
  Fraction operator*(const Fraction &f1, const Fraction &f2) {return Fraction(f1.num*f2.num, f1.den*f2.den);}
  Fraction operator/(const Fraction &f1, const Fraction &f2) {return Fraction(f1.num*f2.den, f1.den*f2.num);}
  
  bool operator== (const Fraction &f1, const Fraction &f2)   {return (f1.num)*(f2.den) == (f2.num)*(f1.den);}
  bool operator!= (const Fraction &f1, const Fraction &f2)   {return (f1.num)*(f2.den) != (f2.num)*(f1.den);}
  bool operator<  (const Fraction &f1, const Fraction &f2)   {return (f1.num)*(f2.den) < (f2.num)*(f1.den);}
  bool operator>  (const Fraction &f1, const Fraction &f2)   {return (f1.num)*(f2.den) > (f2.num)*(f1.den);}
  bool operator<= (const Fraction &f1, const Fraction &f2)   {return (&f2 > &f1);}
  bool operator>= (const Fraction &f1, const Fraction &f2)   {return (&f2 < &f1);}
//////////////////////// part 4 /////////////////////////

///////////////////////// main //////////////////////////
int main (int argc, const char** argv) {

  std::cout << "\nPart 1\n";
  
  Circle circle(4);
  Rectangle rectangle(5, 6);
  Square square(5);
  Rhombus rhombus(7, 8);
  
  std::cout << "Area of circle with radius " << circle.getA() << " = " << circle.area() <<"\n";
  std::cout << "Area of rectangle with sides " << rectangle.getA() << " and " << rectangle.getB() << " = " << rectangle.area() <<"\n";
  std::cout << "Area of square with side " << square.getA() << " = " << square.area() <<"\n";
  std::cout << "Area of rhombus with side " << rhombus.getA() << " and " << "height " << rhombus.getB() << " = " << rhombus.area() <<"\n";
  
  std::cout << "\nPart 2\n";
  
  std::cout << "\nCar construct order: " << "\n";
  Car car("Company_1", "Model_1");
  
  std::cout << "\nPassengerCar construct order: " << "\n";
  PassengerCar pcar("Company_2", "Model_2");
  
  std::cout << "\nBus construct order: " << "\n";
  Bus bus("Company_3", "Model_3");
  
  std::cout << "\nMinivan construct order: " << "\n";
  Minivan minivan("Company_4", "Model_4");
  
  std::cout << "\nPart 3\n";
  Fraction f0(5,0);
  std::cout << "Fraction 0 = "; f0.printFraction(); std::cout << "\n";
  Fraction f1(3,5);
  Fraction f2(8,9);
  std::cout << "Fraction 1 = "; f1.printFraction(); std::cout << "\n";
  std::cout << "Fraction 2 = "; f2.printFraction(); std::cout << "\n";
  
  Fraction f3 = f1 + f2;
  std::cout << "\nFraction 1 + Fraction 2 = "; f3.printFraction(); std::cout << "\n";
  Fraction f4 = f1 - f2;
  std::cout << "Fraction 1 - Fraction 2 = "; f4.printFraction(); std::cout << "\n";
  Fraction f5 = f1 * f2;
  std::cout << "Fraction 1 * Fraction 2 = "; f5.printFraction(); std::cout << "\n";
  Fraction f6 = f1 / f2;
  std::cout << "Fraction 1 / Fraction 2 = "; f6.printFraction(); std::cout << "\n";
  Fraction f7(11,13);
  std::cout << "\nFraction7 = "; f7.printFraction(); std::cout << "\n";
  std::cout << "-Fraction7 = "; (-f7).printFraction(); std::cout << "\n";

  std::cout << "\nFraction 1 = "; f1.printFraction(); std::cout << "\n";
  std::cout << "Fraction 2 = ";   f2.printFraction(); std::cout << "\n";  
  
  std::cout << "Fraction 1 = Fraction 2 ? : "   << (f1 == f2) << "\n";
  std::cout << "Fraction 1 =/= Fraction 2 ? : " << (f1 != f2) << "\n";
  std::cout << "Fraction 1 < Fraction 2 ? : "   << (f1 < f2)  << "\n";
  std::cout << "Fraction 1 > Fraction 2 ? : "   << (f1 > f2)  << "\n";
  std::cout << "Fraction 1 <= Fraction 2 ? : "  << (f1 <= f2) << "\n";
  std::cout << "Fraction 1 >= Fraction 2 ? : "  << (f1 >= f2) << "\n";
  
return 0;
}
