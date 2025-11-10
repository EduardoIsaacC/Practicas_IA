#include <iostream>
using namespace std;

// Devuelve el valor máximo (para saber número de dígitos)
int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx) mx = a[i];
    return mx;
}

// Ordena por un dígito (usando Counting Sort)
void countSort(int a[], int n, int exp) {
    int output[n];   // arreglo de salida
    int count[10] = {0}; // conteo de dígitos

    // Contar ocurrencias de dígitos
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    // Sumar conteos para obtener posiciones reales
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construir arreglo de salida estable
    for (int i = n - 1; i >= 0; i--) {
        int index = (a[i] / exp) % 10;
        output[count[index] - 1] = a[i];
        count[index]--;
    }

    // Copiar resultado al arreglo original
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// Función principal RadixSort
void radixSort(int a[], int n) {
    int m = getMax(a, n); // máximo valor para conocer dígitos
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    //ORDENAMIENTO RADIX
    radixSort(a, n);

    cout << "Sorted:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
