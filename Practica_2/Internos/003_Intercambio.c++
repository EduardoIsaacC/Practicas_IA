#include <iostream>
using namespace std;

int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    // ORDENAMIENTO POR INTERCAMBIO (BURBUJA)
    // Compara pares adyacentes e intercambia si están fuera de orden
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // bandera para optimizar
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // si no hubo cambios, ya está ordenado
    }

    cout << "Sorted:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}