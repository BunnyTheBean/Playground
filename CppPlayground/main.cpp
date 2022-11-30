#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;

class Test {
    public:
        Test() {
            cout << "Test()" << endl;
        }

        ~Test() {
            cout << "~Test()" << endl;
        }
};

int main() {
    Test* test = new Test();
    delete test;
}