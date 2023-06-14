#include <iostream>
#include <vector>

using namespace std;

// Recursive function for Fibonacci using non-dynamic programming
int fib_non_dp(int n, int& calls) {
    calls++; // Increment the number of calls
    if (n <= 1) {
        return n;
    }
    return fib_non_dp(n - 1, calls) + fib_non_dp(n - 2, calls);
}

// Recursive function for Fibonacci using dynamic programming
int fib_dp(int n, vector<int>& f, int& calls) {
    calls++; // Increment the number of calls
    if (f[n] != -1) {
        return f[n];
    }
    f[n] = fib_dp(n - 1, f, calls) + fib_dp(n - 2, f, calls);
    return f[n];
}

int main() {
    vector<int> terms = {8, 16, 32, 64, 128};
    cout << "Term\tFibonacci Value\t # of Calls(NonDP)\t # of Calls(DP)" << endl;
    for (int term : terms) {
        int calls_non_dp = 0;
        int calls_dp = 0;
        int fib_non_dp_value = fib_non_dp(term, calls_non_dp);
        vector<int> f(term + 1, -1);
        f[0] = 0;
        f[1] = 1;
        int fib_dp_value = fib_dp(term, f, calls_dp);
        cout << term << "\t\t\t" << fib_non_dp_value << "\t\t\t\t" << calls_non_dp << "\t\t\t\t\t" << calls_dp << endl;
    }
    return 0;
}

