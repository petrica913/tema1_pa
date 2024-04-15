#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Server {
    int power;
    int threshold;
};

bool intersect(Server a, Server b) {
    if (a.power >= b.threshold)
        return false;
    return true;
}

double calculate_supply(Server a, Server b) {
    double supply_choice;
    if (a.threshold > b.threshold) {
        supply_choice = (a.power - a.threshold - b.power - b.threshold) * (-1);
    } else {
        supply_choice = (a.power - a.threshold - b.power - b.threshold);
    }
    return supply_choice / 2;
}

class Curbe {
 public:
    int x1, x2, y1, y2;
 public:
    Curbe(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
 public:
    int get_slope() {
        return (y2 - y1) / (x2 - x1);
    }
};


bool doIntersect(Curbe c1, Curbe c2) {
    if (c1.x2 < c2.x2)
        return false;
    return true;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int N;
    fin >> N;

    vector<Server> servers(N);
    Server a , b;
    a.threshold = 1e9;
    b.threshold = 1e9;
    int maxim = -1e9, minim = 1e9;
    int y1_min = 1e9, y2_min = 1e9;
    double supply_choice = 0;
    Curbe c1(0, 0, 0, 0), c2(0, 0, 0, 0);

    for (int i = 0; i < N; ++i) {
        fin >> servers[i].power;
    }

    for (int i = 0; i < N; ++i) {
        fin >> servers[i].threshold;
        Curbe curbe((servers[i].threshold - servers[i].power)
        , 0, servers[i].threshold, servers[i].power);
        if (curbe.get_slope() == 1 && curbe.x1 >= maxim && curbe.y2 <= y1_min) {
            maxim = curbe.x1;
            a = servers[i];
            c1 = curbe;
        }
        Curbe curbe2(servers[i].threshold, servers[i].power
        , (servers[i].threshold + servers[i].power), 0);
        if (curbe2.get_slope() == -1 && curbe2.x2 <= minim
            && curbe2.y1 <= y2_min) {
                minim = curbe2.x2;
                b = servers[i];
                c2 = curbe2;
        }
    }

    supply_choice = (c1.x1 + c2.x2);
    supply_choice /= 2;
    double min_value = 1e9;
    for (int i = 0; i < N; i++) {
        double value = servers[i].power
            - abs(supply_choice - servers[i].threshold);
        if (value < min_value)
            min_value = value;
    }
    fout << fixed << setprecision(1);
    fout << min_value;

    fin.close();
    fout.close();

    return 0;
}
