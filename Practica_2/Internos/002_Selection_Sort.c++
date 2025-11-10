#include <iostream>
using namespace std;

int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    // ORDENAMIENTO POR SELECCIÓN
    // Busca el elemento más pequeño y lo coloca al inicio
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // índice del mínimo actual
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        // Intercambia el menor con el elemento actual
        swap(a[i], a[min_idx]);
    }

    cout << "Sorted:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}