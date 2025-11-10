#include <iostream>
using namespace std;

int main() {
    // Arreglo desordenado
    int a[] = {9, 8, 7, 6, 5, 4, 3, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]); // tamaño del arreglo

    // Mostrar lista original
    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    // ORDENAMIENTO POR INSERCIÓN
    // Toma cada elemento y lo coloca en su posición correcta
    for (int i = 1; i < n; i++) {
        int key = a[i];   // elemento actual a insertar
        int j = i - 1;    // índice anterior

        // Desplaza a la derecha todos los mayores a 'key'
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        // Inserta el elemento en su lugar
        a[j + 1] = key;
    }

    // Mostrar lista ordenada
    cout << "Sorted:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
