#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 36;
    int original = n;
    int highPrime = -1;

    while (n % 2 == 0) {
        highPrime = 2;
        n /= 2;
    }

    for (int i = 3; (long long)i * i <= n; i += 2) {
        while (n % i == 0) {
            highPrime = i;
            n /= i;
        }
    }

    if (n > 1)
        highPrime = n;

    cout << "Highest Prime Factor of " << original << ": " << highPrime << endl;

    return 0;
}
