#include "Header.h"

Rational::Rational(int numarator, int numitor)
{
    this->numarator = numarator;
    this->numitor = numitor;
}

Rational::Rational(const Rational& z)
{
    numarator = z.numarator;
    numitor = z.numitor;
}

Rational::~Rational() {}

int Rational::cmmdc(int a, int b)
{
    while (a != b)
        if (a > b) a = a - b;
        else b = b - a;
    return a;
}
 void Rational::simplifica()
{
    int c = cmmdc(numarator, numitor);
    numarator = numarator / c;
    numitor = numitor / c;
}

 Rational Rational::operator-()
 {
     Rational r;
     r.numarator = -numarator;
     r.numitor = numitor;
     return r;
 }

 Rational Rational::operator!()
 {
     Rational r;
     r.numarator = numitor;
     r.numitor = numarator;
     return r;
 }

Rational Rational::operator+(const Rational r)
{
    Rational r1(this->numarator * r.numitor + r.numarator * this->numitor, this->numitor * r.numitor);
    r1.simplifica();
    return r1;
}

Rational Rational::operator-(const Rational r)
{
    Rational r1(this->numarator * r.numitor - r.numarator * this->numitor, this->numitor * r.numitor);
    r1.simplifica();
    return r1;
}

Rational Rational::operator*(const Rational r)
{
    Rational r1(this->numarator * r.numarator, this->numitor * r.numitor);
    r1.simplifica();
    return r1;
}

Rational Rational::operator/(const Rational r)
{
    Rational r1(this->numarator * r.numitor, this->numitor * r.numarator);
    r1.simplifica();
    return r1;
}

Rational operator+(const Rational& r1, const Rational& r2)
{
    Rational r(r1.numarator * r2.numitor + r2.numarator * r1.numitor, r1.numitor * r2.numitor);
    r.simplifica();
    return r;
}
Rational operator-(const Rational& r1, const Rational& r2)
{
    Rational r(r1.numarator * r2.numitor - r2.numarator * r1.numitor, r1.numitor * r2.numitor);
    r.simplifica();
    return r;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    Rational r(r1.numarator * r2.numarator, r1.numitor * r2.numitor);
    r.simplifica();
    return r;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    Rational r(r1.numarator * r2.numitor, r1.numitor * r2.numarator);
    r.simplifica();
    return r;
}

Rational& Rational::operator=(const Rational& r)
{
    numarator = r.numarator;
    numitor = r.numitor;
    return*this;
}

ostream& operator<<(ostream& out, Rational& r) {
    if (r.numarator == 0)
    {
        out << 0 << endl;
    }
    else if (r.numitor == 0)
    {
        out << "Nu exista" << endl;
    }
    else
    {
        out << r.numarator << "/" << r.numitor;
    }

    return out;
};

istream& operator>>(istream& in, Rational& r) {
    cout << "\tintroduceti numaratorul: ";
    in >> r.numarator;
    do {
        cout << "\tintroduceti numitorul: ";
        in >> r.numitor;
    } while (r.numitor == 0);
    r.simplifica();
    return in;
};

int main()
{
    Rational r(1, 2), r1(4, 6), r2 = r1, r3(0, 2), r4(3, 0);
    cout << "r=" << r << endl;
    cout << "r1=" << r1 << endl;
    cout << "r3=" << r3 << endl;
    cout << "r4=" << r4 << endl;

    cout << "r+r1= " << r + r1 << endl;

    cout << "r1-r= " << r1 - r << endl;

    Rational p = r * r1;
    cout << "r*r1= " << p << endl;

    Rational i = r1 / r;
    cout << "r1/r= " << i << endl;

    cout << "Opusul lui r: " << -r << endl;

    cout << "Inversul lui r: " << !r << endl;

    Rational r5;
    cout << "Citim r5: ";
    cin >> r5;
    cout << "r5=" << r5;
    return 0;
}