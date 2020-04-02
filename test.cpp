#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

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

    vector<int> vec = {2, 3, 4, 5};
    cout << func(vec) << endl;

    return 0;
}
