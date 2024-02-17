#include <iostream>
using namespace std;

long int fibonacchi(int i) {
    int value = 0;
    if(i < 1) return 0;
    if(i == 1) return 1;
    return fibonacchi(i-1) + fibonacchi(i - 2);
}

long int main() {
    int i = 0;

    while(i < 7) {
        cout << "Fibonacchi number " << i + 1 << ": " << fibonacchi(i) << endl;
        i++;
    }

    return 0;
}