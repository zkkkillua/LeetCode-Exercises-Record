#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    string s = "string";
    char c = s[2];
    string ss = "r";

    cout << typeid(c).name() << ' ' << sizeof(c) << endl;
    cout << typeid(ss).name() << ' ' << sizeof(ss) << endl;
    cout << typeid(s).name() << ' ' << sizeof(s) << endl;

    return 0;
}