#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int let_app(const string& word, char let) {
    int count = 0;
    for (char ch : word) {
        if (ch == let) {
            count++;
        }
    }
    return count;
}

bool compare(const string& word1, const string& word2, char let) {
    double frac1 = ((double)(let_app(word1, let))) / ((double)word1.length());
    double frac2 = ((double)(let_app(word2, let))) / ((double)word2.length());
    return frac1 > frac2;
}

int max_password_length(int N, vector<string>& words, char let) {
    sort(words.begin(), words.end(), [&](const string& a, const string& b) {
        return compare(a, b, let);
    });
    int result = 0;
    int let_in_words = 0;
    for (int i = 0; i < N; i++) {
        int let_in_curr = let_app(words[i], let);
        double frac = ((double)let_in_curr) / ((double)words[i].length());
        if (frac > 0.5) {
            let_in_words += let_in_curr;
            result += words[i].length();
        } else {
            int aux_let_in_words = let_in_words + let_in_curr;
            int aux_result = result + words[i].length();
            double aux_frac
                    = ((double) aux_let_in_words) / ((double) aux_result);
            if (aux_frac > 0.5) {
                result = aux_result;
                let_in_words = aux_let_in_words;
            }
        }
    }
    cout << endl;
    return result;
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");
    int N;
    fin >> N;

    vector<string> words(N);
    vector<int> freq(26, 0);
    for (int i = 0; i < N; ++i) {
        fin >> words[i];
        for (char let : words[i]) {
            freq[let - 'a']++;
        }
    }
    int max = -1e9;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) {
            continue;
        }
        int current = max_password_length(N, words, static_cast<char>(i + 'a'));
        if (current >= max) {
            max = current;
        }
    }
    fout << max << endl;
    return 0;
}
