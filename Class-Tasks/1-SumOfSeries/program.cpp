#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double sum = 0, result;
    int n;
    cout << "calculating the sum of the series 1 + 1/2^2 + 1/3^3 + .... + 1/n^n" << endl;
    cout << "enter the value for nth term: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        result = 1 / pow(i, i);
        cout << "1/" << i << "^" << i << " = " << result << endl;
        sum += result;
    }
    cout << "the sum of ";
    for (int i = 1; i <= n; i++) {
        cout << "1/" << i << "^" << i << " + ";
    }
    cout << "is " << sum << endl;
}
