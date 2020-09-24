#ifndef Long_hpp
#define Long_hpp

#include <iostream> //для ввода/вывода
#include <math.h> //для использования математических операции в  Long.cpp
using namespace std; //все функции из пространства имен std в глобальные
const unsigned int MAX = pow(2,32);

class Long {
private:
    //атрибуты класса
    unsigned int high;
    unsigned int low;
    
public:
    //методы класса
    Long();
    void PrintINT();
    void Print();
    Long EqualInt(int high, int low);
    Long Eq(Long b);
    Long Increment();
    Long Decrement();
    Long Add(Long a);
    Long Subtract(Long a);
    Long Multiply(Long a);
    Long Divide(Long a);
    Long Mod(Long a);
    bool EqualLong(Long b);
    Long More(Long a);
    Long Less(Long a);
};


#endif /* Long_hpp */


