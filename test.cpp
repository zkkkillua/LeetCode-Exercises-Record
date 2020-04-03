#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Obj
{
public:
    void set(int a) {this->a = a;}
    void print() {cout << a << endl;}
private:
    int a;
};

int func(const vector<int>& vec)
{
    int ans = vec[2];
    return ans;
}

int main()
{
    // Obj obj;
    // obj.set(5);
    // obj.print();

    int a = 5;
    cout << -pow(2, a) << endl;

    return 0;
}
