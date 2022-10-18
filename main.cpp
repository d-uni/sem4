class C {
    int *p;
public:
    C(){}
    C(int x, int y){}
    C(const C &x, int y) {}
    C(double x) {}
    C(const C *x) {}
    int & operator [] ( int i) { return p[i]; }
    operator int() { return 1; }
    friend int operator + (int a, const C &b);
    friend int operator ~ (const C &b);
    friend C operator ++ (C &b);
    friend int operator * (const C &a, C *b);
    int operator ~ () {return 1; }
    ~C(){};

};
int operator + (int a, const C &b) {
    return 1;
}
int operator ~ (const C &b) {
    return 1;
}
C operator ++ (C &b) {
    return 1;
}
int operator * (const C &a, C *b) {
    return 1;
}
