#include <iostream>
#include <cmath>
#include <sstream>

class Figure {
public:
    virtual double get_square() const = 0;
    virtual ~Figure(){}
};

class Rectangle: Figure {
private:
    double a;
    double b;
public:
    static Rectangle* make(std::string s) {
        std::stringstream ss(s);
        std::string word;
        ss >> word;
        double x = stod(word);
        ss >> word;
        double y = stod(word);
        return new Rectangle(x,y);
    }
    Rectangle(double x, double y): a(x), b(y) {}
    virtual double get_square() const {return a*b;}
};
class Square: Figure {
private:
    double a;
public:
    static Square* make(std::string s) {
        double x = stod(s);
        return new Square(x);
    }
    Square(double x): a(x) {}
    virtual double get_square() const {return a*a;}
};
class Circle: Figure {
private:
    double r;
public:
    static Circle* make(std::string s) {
        double x = stod(s);
        return new Circle(x);
    }
    Circle(double x): r(x) {}
    virtual double get_square() const {return r*r*M_PI;}
};
