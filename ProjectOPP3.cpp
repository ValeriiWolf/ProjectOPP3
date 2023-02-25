#include <iostream>
using namespace std;

class Figure {
public:
    virtual void area()=0;
};

class Parallelogram:public Figure {
public:
    Parallelogram() {} 
    Parallelogram(int a,int h) : width(a), height(h){}
    virtual void area() override { cout << "Parallelogram_area = " << width * height << endl; } 
private:
    int height;
    int width;
};

class Circle:public Figure {
public:
    Circle(int r) : Rad(r) {}
    virtual void area()override { cout << "Circle_area = "<< Rad* Rad*Pi << endl; }
private:
    int Rad;
    double const Pi = 3.14;
};

class Rectangle :public Parallelogram {
public:
    Rectangle(int a, int b) : width(a), height(b){}
    virtual void area()override { cout << "Rectangle_area = " << width * height << endl; }
private:
    int width;
    int height;
};

class Square :public Parallelogram {
public:
    Square(int a) : width(a){ }
    virtual void area()override { cout << "Square_area = " << width * width << endl; }
protected:
    int width;
private:
    
};

class Rhombus :public Parallelogram {
public:
    Rhombus(int a, int h) :width(a), height(h) {}
    virtual void area()override { cout << "Rhombus_area = " << width * height << endl; }
private:
    int height;
    int width;
};

class Car {
public:
    Car() {}
    Car(string st1, string st2) :company(st1), model(st2){}
    virtual void Print() { cout << "Model_Car " << model << " Company_Car " << company << endl; }
    void SetModel(string a) { model = a; }
    void SetCompany(string b) { company = b; }
    string getModel() { return model; }
    string getCompany() { return company; }
private:
    string company;
    string model;

};

class PassengerCar : virtual public Car {
public: 
    PassengerCar(string st1, string st2) : Car(st1, st2) { SetCompany(st1), SetModel(st2); }
    virtual void Print()override { cout << "Model_PassengerCar " << getModel() << " Company_PassengerCar " << getCompany() << endl; }
private:
};
class Bus :virtual public Car {
public:
    Bus(string st1, string st2) : Car(st1, st2) { SetCompany(st1), SetModel(st2); }
    virtual void Print()override { cout << "Model_Bus " << getModel() << " Company_Bus " << getCompany() << endl; }
private:
};

class Minivan : public PassengerCar, Bus {
public:
    Minivan(string st1, string st2) : PassengerCar(st1, st2),Bus(st1, st2) { SetCompany(st1), SetModel(st2); }
    virtual void Print()override { cout << "Model_Minivan " << getModel() << " Company_Minivan " << getCompany() << endl; }
};

class Fraction {
public:
    Fraction(int a, int b) :numerator(a), denominator(b) { if (b == 0) { std::cout << "denominator cannot be 0"; } else { denominator = b; } }
    void setnumerator(int a) { numerator = a; }
    int getnumerator() const { return numerator; }
    void setdenominator(int b) { if (b == 0) { std::cout << "denominator cannot be 0"; } else { denominator = b; } }
    int getdenominator() const { return denominator; }
    void Print() { cout << numerator << '/' << denominator << endl; }
    Fraction operator+( Fraction r_op) {
        int newnumerator = numerator * r_op.denominator + r_op.numerator * denominator;
        int newdenominator = denominator * r_op.denominator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator-(Fraction r_op) {
        int newnumerator = numerator * r_op.denominator - r_op.numerator * denominator;
        int newdenominator = denominator * r_op.denominator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator*(Fraction r_op) {
        int newnumerator = numerator *  r_op.numerator;
        int newdenominator = denominator * r_op.denominator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator/(Fraction r_op) {
        int newnumerator = numerator * r_op.denominator;
        int newdenominator = denominator * r_op.numerator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator-()const {
        return Fraction(-numerator, denominator);
    }
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
private:
    int numerator;
    int denominator;
};
bool operator == (const Fraction& v1, const Fraction& v2)
{
    if (v1.getnumerator() * v2.getdenominator() == v2.getnumerator() * v1.getdenominator())
        return true;
    return false;
}
const bool operator != (const Fraction& v1, const Fraction& v2)
{
    return !(v1 == v2);
}
bool operator > (const Fraction& v1, const Fraction& v2)
{
    if (v1.getnumerator() * v2.getdenominator() > v2.getnumerator() * v1.getdenominator())
        return true;
    return false;
}
const bool operator <= (const Fraction& v1, const Fraction& v2)
{
    return !(v1 > v2);
}
bool operator < (const Fraction& v1, const Fraction& v2)
{
    if (v1.getnumerator() * v2.getdenominator() < v2.getnumerator() * v1.getdenominator())
        return true;
    return false;
}
const bool operator >= (const Fraction& v1, const Fraction& v2)
{
    return !(v1 < v2);
}

class Card {
public:
    enum Suit { Diamonds, Hearts, Clubs, Spades };
    enum Value { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10 };
private:
    bool Position=0;
    Suit S_Suit = Diamonds;
    Value V_Value = two;
public:
    Card(Suit a , Value b, bool c) :S_Suit(a), V_Value(b),Position(c){}
    void Print() { cout<<"Suit "<< S_Suit <<"Value "<<V_Value<<"Position "<<Position << endl; }
    void Flip() { Position=!Position; }
    int GetValue() { /*cout << "Value " << V_Value << endl;*/ return V_Value; }
    
};


int main()
{
    Parallelogram P(4,2);
    P.area();
    Circle C(2);
    C.area();
    Rectangle R(6,4);
    R.area();
    Square S(4);
    S.area();
    Rhombus Romb(5,9);
    Romb.area();
    Car CA("Tapochki","Svist");
    PassengerCar PaC("Toyota", "M");
    Bus BU("Mersedes","Busic");
    Minivan MI("Nissan","Sanny");
    CA.Print();
    PaC.Print();
    BU.Print();
    MI.Print();
    Fraction f1(4,5);
    Fraction f2(3,4);
    Fraction f3 = f1 + f2;
    f1.Print();
    f2.Print();
    f3.Print();
    f3 = f1 - f2;
    f3.Print();
    f3 = f1 * f2;
    f3.Print();
    f3 = f1 / f2;
    f3.Print();
    if (f1 == f2) cout << "f1 = f2" << endl;
    else cout << "f1 /= f2" << endl;
    if (f1 != f2) cout << "f1 /= f2" << endl;
    else cout << "f1 = f2" << endl;
    if (f1 > f2) cout << "f1 > f2" << endl;
    else cout << "f1 <= f2" << endl;
    if (f1 < f2) cout << "f1 < f2" << endl;
    else cout << "f1 >= f2" << endl;
    if (f1 >= f2) cout << "f1 >= f2" << endl;
    else cout << "f1 < f2" << endl;
    if (f1 <= f2) cout << "f1 <= f2" << endl;
    else cout << "f1 > f2" << endl;

    Card Card1(Card::Suit::Clubs, Card::Value::ace, true);
    Card1.Print();
    Card1.GetValue();
    Card1.Flip();
    Card1.Print();
    return 0;
}