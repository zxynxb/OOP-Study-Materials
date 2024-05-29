#include <iostream>
using namespace std;

int main() {
    int n, i;
    for (n = 10; n <= 11; n++){
        cout << "Table of " << n << endl;
        for (i = 1; i <= 10; i++){
            cout << n << " x " << i << " = " << n*i << endl;
        }
        cout << endl;
    }
    return 0;
}
