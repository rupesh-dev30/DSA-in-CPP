#include <bits/stdc++.h>
using namespace std;

/*
    When properties & member functions of base class are passed on the derived class.
*/

class Animal {
private:
  bool speak;

public:
  string color;

  void eat() {
    cout << "eats \n";
  }

  void breathe() {
    cout << "breathes \n";
  }
};

class Fish : public Animal {
public:
  int fins;

  void swim() {
    cout << "swims \n";
  }
};

int main() {
  // code here
  Fish f1;

  f1.fins = 3;
  f1.color = "grey";
  f1.swim();
  f1.eat();
  f1.breathe();
  cout << f1.color << endl;

  /*
  f1.legs = false;    // Not accessible beacuse of private
  cout << f1.legs << endl;
  */

  return 0;
}

/*
    Mode of Inheritance

      ______________________________________________________________________________
      |                  |                                                         |
      |  Base Class      |              Types of Inheritance                       |
      |  member access   |_________________________________________________________|
      |  specifier       |    Public       |    Protected       |     Private      |
      |__________________|_________________|____________________|__________________|
      |                  |                 |                    |                  |
      |   Public         |    Public       |     Protected      |      Private     |
      |__________________|_________________|____________________|__________________|
      |                  |                 |                    |                  |
      |   Protected      |    Protected    |     Protected      |     Private      |
      |__________________|_________________|____________________|__________________|
      |                  |                 |                    |                  |
      |   Private        |  Not Accessible |   Not Accessible   |  Not Accessible  |
      |__________________|_________________|____________________|__________________|


*/