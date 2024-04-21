#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double min_of_three(double a, double b, double c) {
    return min(a, min(b, c));
}

double best_of_three(double a, double b, double c) {
    double sum1 = a + b + c - min_of_three(a, b, c);
    double sum2 = a + b + c - min(b, c) / 2;
    double sum3 = a + b + c - min(a, b) / 2;
    return min(sum1 , (min(sum2, sum3)));
}

double best_sum(vector<int>& products, int N) {
    vector<double> dp(N + 1, 0);

    dp[0] = products[0];
    dp[1] = (double)min(products[0], products[1]) / 2
            + max(products[0], products[1]);
    dp[2] = best_of_three(products[0], products[1], products[2]);

    for (int i = 3; i < N; i++) {
        double sum1 = dp[i - 1] + (double)products[i];
        double sum2 = dp[i - 2] + products[i - 1] + products[i]
                    - (double)min(products[i - 1], products[i]) / 2;
        double sum3 = dp[i - 3] + products[i] + products[i - 1]
                    + products[i - 2] - min_of_three(products[i],
                        products[i - 1], products[i - 2]);
        dp[i] = min_of_three(sum1, sum2, sum3);
        cout << dp[i] << " ";
    }

    return dp[N - 1];
}

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");
    int N, K;
    fin >> N >> K;
    vector<int> products(N);
    for (int i = 0; i < N; i++) {
        fin >> products[i];
    }
    double best = best_sum(products, N);
    fout << fixed << setprecision(1);
    fout << best;
    return 0;
}
