#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Reutilizamos el k-way merge como núcleo de mezcla
vector<int> k_way_merge(const vector<vector<int>>& lists) {
    using Node = tuple<int,int,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int i = 0; i < (int)lists.size(); ++i)
        if (!lists[i].empty()) pq.emplace(lists[i][0], i, 0);

    vector<int> out;
    while (!pq.empty()) {
        auto [val, li, pi] = pq.top(); pq.pop();
        out.push_back(val);
        int next = pi + 1;
        if (next < (int)lists[li].size())
            pq.emplace(lists[li][next], li, next);
    }
    return out;
}

int main() {
    // Corridas desbalanceadas (simulan distribución tipo Fibonacci)
    // En polifase real, la cantidad de elementos por corrida y su distribución
    // entre cintas están planeadas para minimizar E/S. Aquí solo ilustramos
    // la idea con tamaños distintos.
    vector<vector<int>> runs = {
        {1, 9},          // corrida pequeña
        {2, 4, 6, 8},    // corrida mediana
        {3, 5, 7, 10,12} // corrida grande
    };

    cout << "Polyphase simulated runs:\n";
    for (auto& r : runs) {
        for (int x : r) cout << x << " ";
        cout << "\n";
    }

    // Mezcla "polifase" simulada: un único k-way merge
    vector<int> merged = k_way_merge(runs);

    cout << "Merged (polyphase sim): ";
    for (int x : merged) cout << x << " ";
    cout << "\n";
    return 0;
}