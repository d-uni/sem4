#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
namespace numbers {
    class complex {
        double ree, imm;
    public:
        complex(double r = 0, double i = 0) : ree(r), imm(i) {}
        explicit complex(const std::string &str) {
            unsigned int p = str.find(',');
            std::string s1 = "", s2 = "";
            unsigned int i;
            for(i = 1;i < p; i++) {
                s1 = s1 + str[i];
            }
            for(i = p + 1; i < str.length(); i++) {
                s2 = s2 + str[i];
            }
            double a = std::stod(s1.c_str());
            double b = std::stod(s2.c_str());
            ree = a;
            imm = b;
        }
        double re() const {
            return ree;
        }
        double im()  const {
            return imm;
        }
        double abs2()  const {
            return ree * ree + imm * imm;
        }
        double abs() const {
            return sqrt(abs2());
        }
        std::string to_string() const {
            char p1[1000];
            char p2[1000];
            sprintf(p1, "%.10g", ree);
            sprintf(p2, "%.10g", imm);
            std::string a = "(";
            a = a + std::string(p1) + "," + std::string(p2) + ")";
            return a;
        }
        friend complex operator + (const complex &x, const complex &y);
        friend complex operator - (const complex &x, const complex &y);
        friend complex operator * (const complex &x, const complex &y);
        friend complex operator / (const complex &x, const complex &y);
        complex &operator += (const complex &x) {
            ree = ree + x.ree;
            imm = imm + x.imm;
            return *this;
        };
        complex &operator -= (const complex &x) {
            ree = ree - x.ree;
            imm = imm - x.imm;
            return *this;
        }
        complex &operator *= (const complex &x) {
            double p = ree;
            ree = ree * x.ree - imm * x.imm;
            imm = p * x.imm + imm * x.ree;
            return *this;
        }
        complex &operator /= (const complex &x) {
            double p = ree;
            ree = (ree * x.ree + imm * x.imm ) / (x.ree * x.ree + x.imm * x.imm);
            imm = (x.ree * imm - p * x.imm) / (x.ree * x.ree + x.imm * x.imm);
            return *this;
        }
        complex operator ~() const {
            complex out(ree, -imm);
            return out;
        }
        complex operator -() const {
            complex out(-ree, -imm);
            return out;
        }
    };
    complex operator + (const complex &x, const complex &y) {
        complex out(x.ree, x.imm);
        out += y;
        return out;
    }
    complex operator - (const complex &x, const complex &y) {
        complex out(x.ree, x.imm);
        out -= y;
        return out;
    }
    complex operator * (const complex &x, const complex &y) {
        complex out(x.ree, x.imm);
        out *= y;
        return out;
    }
    complex operator / (const complex &x, const complex &y) {
        complex out(x.ree, x.imm);
        out /= y;
        return out;
    }
}
