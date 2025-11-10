#include <iostream>
using namespace std;

// Función para mantener la propiedad de heap
void heapify(int a[], int n, int i) {
    int largest = i;      // raíz
    int l = 2 * i + 1;    // hijo izquierdo
    int r = 2 * i + 2;    // hijo derecho

    // Si el hijo izquierdo es mayor que la raíz
    if (l < n && a[l] > a[largest])
        largest = l;

    // Si el hijo derecho es mayor que el mayor actual
    if (r < n && a[r] > a[largest])
        largest = r;

    // Si el mayor no es la raíz
    if (largest != i) {
        swap(a[i], a[largest]);
        // Llamada recursiva sobre el subárbol afectado
        heapify(a, n, largest);
    }
}

// Función principal del heap sort
void heapSort(int a[], int n) {
    // Construir heap (reordenar arreglo)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);      // Mover raíz actual al final
        heapify(a, i, 0);      // Llamar heapify en el heap reducido
    }
}

int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    // ORDENAMIENTO POR ÁRBOL
    heapSort(a, n);

    cout << "Sorted:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}