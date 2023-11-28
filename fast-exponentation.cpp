#include <iostream>
using namespace std;

int pow(int base, int power);
int pow(int base, int power, int mod);

int main() {
    cout << pow(2, 30) << endl;
    cout << pow(2, 30, 1'000'000'007) << endl;

    return 0;
}

int pow(int base, int power) {
    if (power == 1) return base;
    if (power == 0) return 1; 
    if (base == 0) return 0;
    int ans = power % 2 ? 1 : base, rest = pow(base, power / 2);
    return ans * rest * rest;
}

int pow(int base, int power, int mod) {
    if (power == 1) return base;
    if (power == 0) return 1; 
    if (base == 0) return 0;
    int ans = power % 2 ? 1 : base, rest = pow(base, power / 2) % mod;
    return ans * rest * rest % mod;
}