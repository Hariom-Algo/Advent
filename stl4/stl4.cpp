#include <iostream>
#include <algorithm>
#include "stl4.h"
using namespace std;

int gen[5] = { 0, 0, 0, 0, 0 }; int goal; int gens; int best; int i = 0; int fit;

int dif(int in) {
    return abs(gen[in] - goal);
}

void nextgen() {
    int fit[5] = { dif(1), dif(2), dif(3), dif(4), dif(5) };
    best = *max_element(fit, fit + 6);
    int gen[5] = { best - 2, best - 1, best, best + 1, best + 2 };
}

int main() {
    cout << "Goal: "; cin >> goal; cout << "Gens: "; cin >> gens;
    while (i < gens) {
        nextgen(); cout << "Generation " << i + 1 << ": " << best << "\n";
        i = i + 1;
    }
}