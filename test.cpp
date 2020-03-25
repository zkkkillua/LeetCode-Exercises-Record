#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Obj
{
public:
    void set(int a) {this->a = a;}
    void print() {cout << a << endl;}
private:
    int a;
};

int main()
{
    // Obj obj;
    // obj.set(5);
    // obj.print();

    int num = 3;
    if (num >= 0)
        if (num == 0)
            cout << "first" << endl;
        else
            cout << "second" << endl;
    cout << "third" << endl;

    return 0;
}
