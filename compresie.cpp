#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

int error(int j, int N) {
    return (j >= N) ? -1 : 1;
}

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int N, M;
    fin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; i++) {
        fin >> array1[i];
    }
    fin >> M;
    vector<int> array2(M);
    int max_length = max(M, N);
    vector<int> array(max_length);
    for (int i = 0; i < max_length; i++) {
        array[i] = 0;
    }
    int j = 0, k = 0;
    for (int i = 0; i < M; i++) {
        fin >> array2[i];
        if (error(j, N) == -1) {
            k = -1;
            break;
        }
        if (array1[j] > array2[i] + array[k]) {
            array[k] += array2[i];
            continue;
        }
        if (array1[j] == array2[i] + array[k]) {
            array[k] = array2[i] + array[k];
            k++;
            j++;
            continue;
        }
        if (array1[j] < array2[i] + array[k]) {
           while (array1[j] < array2[i] + array[k] && j < N - 1) {
                array1[j + 1] += array1[j];
                j++;
           }
           if (error(j, N) == -1) {
                k = -1;
                break;
            }
            if (array1[j] > array2[i] + array[k]) {
                array[k] += array2[i];
                continue;
            }
            if (array1[j] == array2[i] + array[k]) {
                array[k] = array2[i] + array[k];
                k++;
                j++;
                continue;
            }
        }
    }
    fout << k;
    return 0;
}
