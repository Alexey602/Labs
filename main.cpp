#include <iostream>

using namespace std;

class Complex
{
private:
    int a; // действительная часть
    int b; // мнимая часть 
public:
    int get_a(){
        return a;
    }
    int get_b(){
        return b;
    }
    void set_a(int value_a){
        a = value_a;
    }
    void set_b(int value_b){
        b = value_b;
    }

    Complex() {};

    Complex (int v1, int v2)
    {
      a = v1;
      b = v2;
    }

    Complex operator+(Complex& c){
        Complex result;
        result.set_a(a + c.get_a());
        result.set_b(b + c.get_b());
        return result;
    }

    Complex operator-(Complex& c){
        Complex result;
        result.set_a(a - c.get_a());
        result.set_b(b - c.get_b());
        return result;
    }

    Complex operator*(Complex& c){
        Complex result;
        result.set_a(a * c.get_a() - b * c.get_b());
        result.set_b(a * c.get_b() + c.get_a() * b);
        return result;
    }

    Complex operator/(Complex& c){
        Complex result;
        result.set_a(a * c.get_a() + b * c.get_b());
        result.set_b(c.get_a() * b - a * c.get_b());
        return result;
    }

    bool operator==(Complex& c){
        return this -> a == c.a && this -> b == c.b;
    }

    bool operator%(Complex& c){
        if(a<0){
            a=a*(-1);
        }
        if(c.a<0){
            c.a=c.a*(-1);
        }
        if(b<0){
            b=b*(-1);
        }
        if(c.b<0){
            c.b=c.b*(-1);
        }
        return this -> a == c.a && this -> b == c.b;
    }

};



int main(){
    Complex value1(1, 5);
    Complex value2(-1, 5);
    cout << "Value1 = (" << value1.get_a() << ", " << value1.get_b()  << ") " << "Value2 = (" << value2.get_a() << ", " << value2.get_b() << ")" <<endl; 
    Complex add = value1+value2;
    cout << "Add = (" << add.get_a() << ", " << add.get_b() << ")" <<endl;
    Complex sub = value1-value2;
    cout << "Sub = (" << sub.get_a() << ", " << sub.get_b() << ")" <<endl;
    Complex mul = value1*value2;
    cout << "Mul = (" << mul.get_a() << ", " << mul.get_b() << ")" <<endl;
    Complex div = value1/value2;
    cout << "Div = (" << div.get_a() << ", " << div.get_b() << ")" <<endl;
    bool equ = value1==value2;
    cout << "Equ = " << equ << endl;
    cout << "Conj = (" << value1.get_a() << ", " << -value1.get_b() << ")" << endl;
    bool mod = value1%value2;
    cout << "Mod = " << mod << endl;

}