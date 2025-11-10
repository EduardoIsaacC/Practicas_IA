#include <iostream>
#include <vector>
using namespace std;

// Fusión ordenada de dos sublistas (estilo merge de MergeSort)
vector<int> merge_two(const vector<int>& L, const vector<int>& R) {
    vector<int> out;
    out.reserve(L.size() + R.size());
    size_t i = 0, j = 0;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) out.push_back(L[i++]);
        else              out.push_back(R[j++]);
    }
    // Copiar remanentes
    while (i < L.size()) out.push_back(L[i++]);
    while (j < R.size()) out.push_back(R[j++]);
    return out;
}

// Straight Merging: mezcla por "ancho" fijo que se duplica en cada pasada
void straight_merge_sort(vector<int>& a) {
    int n = (int)a.size();
    // width = tamaño de corrida actual (1, 2, 4, 8, ...)
    for (int width = 1; width < n; width *= 2) {
        // Recorremos de 2*width en 2*width (pares de corridas)
        for (int i = 0; i < n; i += 2 * width) {
            // Sublista izquierda: [i, i+width)
            vector<int> L(a.begin() + i, a.begin() + min(i + width, n));
            // Sublista derecha: [i+width, i+2*width)
            vector<int> R(a.begin() + min(i + width, n), a.begin() + min(i + 2 * width, n));
            // Fusionar y reescribir en 'a'
            vector<int> M = merge_two(L, R);
            for (size_t k = 0; k < M.size(); ++k)
                a[i + (int)k] = M[k];
        }
    }
}

int main() {
    // Lista de prueba
    vector<int> a = {9, 8, 7, 6, 5, 4, 3, 3, 2, 1};

    // Imprimir arreglo original
    cout << "Unsorted: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    // Ordenar con Straight Merging
    straight_merge_sort(a);

    // Imprimir resultado
    cout << "Sorted:   ";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}