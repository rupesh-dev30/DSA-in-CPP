#include <bits/stdc++.h>
using namespace std;

// Function Overloading
class Print {
public:
  void show(int x) {
    cout << "Integer: " << x << endl;
  }

  void show(string str) {
    cout << "String: " << str << endl;
  }
};

// Operator Overloading
class Complex {
  int real;
  int img;

public:
  Complex(int r, int i) {
    real = r;
    img = i;
  }
  void showNum() {
    cout << real << " + " << img << "i \n";
  }

  // operator overloading
  Complex operator + (Complex &c2) {
    int resReal = this->real + c2.real;
    int resImg = this->img + c2.img;

    Complex c3(resReal, resImg);
    // cout << "result = ";
    // c3.showNum();
    return c3;
  }
};

int main() {
  // code here
  Print obj1;
  obj1.show(10);
  obj1.show("Hello");

  Complex c1(1, 2);
  Complex c2(3, 4);

  c1.showNum();
  c2.showNum();

  Complex c3 = c1 + c2;
  c3.showNum();

  return 0;
}

/*
    Operator Overloading

        returnType operator opSymbol() {....}
*/