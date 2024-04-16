#include<iostream>
#include<fstream>
using namespace std;

#define MOD 1000000007

long long int power(long long int base, long long int exp) {
    long long int result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result % MOD;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");
    int k;
    fin >> k;
    long long int x;
    char c, old_c = 'o';
    long long int result = 1;
    for (int i = 0; i < k; i++) {
        fin >> x >> c;
        if (old_c == 'o' && c == 'V') {
            result = ((result % MOD) * (3 * power(2, x - 1)) % MOD) % MOD;
            old_c = 'V';
            continue;
        }
        if (old_c == 'o' && c == 'H') {
            result = ((result % MOD) * (2 * power(3, x)) % MOD) % MOD;
            old_c = 'H';
            continue;
        }
        if (old_c == 'H' && c == 'V') {
            result = ((result % MOD) * power(2, x - 1) % MOD) % MOD;
            old_c = 'V';
            continue;
        }
        if (old_c == 'V' && c == 'V') {
            result = ((result % MOD) * power(2, x) % MOD) % MOD;
            old_c = 'V';
            continue;
        }
        if (old_c == 'V' && c == 'H') {
            result = ((result % MOD) * (2 * power(3, x - 1)) % MOD) % MOD;
            old_c = 'H';
            continue;
        }
        if (old_c == 'H' && c == 'H') {
            result = ((result % MOD) * power(3, x) % MOD) % MOD;
            old_c = 'H';
            continue;
        }
    }
    fout << (result % MOD);
}
