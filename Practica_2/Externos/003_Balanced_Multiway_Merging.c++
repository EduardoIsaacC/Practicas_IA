#include <iostream>
#include <vector>
#include <queue>    // priority_queue
#include <tuple>    // tuple para (valor, idxLista, idxPos)
using namespace std;

// Mezcla k listas ordenadas usando un min-heap (priority_queue con greater)
vector<int> balanced_multiway_merge(const vector<vector<int>>& lists) {
    // Nodo del heap: (valor, índice_lista, índice_elemento)
    using Node = tuple<int,int,int>;

    // Min-heap por valor (std::greater)
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Posiciones actuales por lista
    vector<int> pos(lists.size(), 0);

    // Insertar primer elemento de cada lista
    for (int i = 0; i < (int)lists.size(); ++i) {
        if (!lists[i].empty()) {
            pq.emplace(lists[i][0], i, 0);
        }
    }

    vector<int> result;
    // Extraer siempre el mínimo y avanzar en su lista
    while (!pq.empty()) {
        auto [val, li, pi] = pq.top(); pq.pop();
        result.push_back(val);
        int next = pi + 1;
        if (next < (int)lists[li].size()) {
            pq.emplace(lists[li][next], li, next);
        }
    }
    return result;
}

int main() {
    // Tres corridas ya ordenadas (simulan archivos)
    vector<vector<int>> runs = {
        {1, 5, 9},
        {2, 6, 10, 11},
        {3, 4, 7, 8}
    };

    // Mostrar corridas de entrada
    cout << "Runs:\n";
    for (auto& r : runs) {
        for (int x : r) cout << x << " ";
        cout << "\n";
    }

    // Mezcla múltiple balanceada
    vector<int> merged = balanced_multiway_merge(runs);

    // Resultado final
    cout << "Merged: ";
    for (int x : merged) cout << x << " ";
    cout << "\n";
    return 0;
}