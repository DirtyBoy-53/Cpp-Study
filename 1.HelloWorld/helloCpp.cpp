#include <iostream>

class Base {

    private:

 virtual void f() { std::cout << "Base::f" << std::endl; }

};

class Derive : public Base{

};

typedef void(*Fun)(void);

int main() {

    Derive d;

    // Fun  pFun = (Fun)((int*)*(int*)(&d)+0);
    int *p1 = (int*)(&d);
    int *p2 = static_cast<int*>(*p1);
    Fun pFun = (Fun)(*p2);

    pFun();

    return 0;
}