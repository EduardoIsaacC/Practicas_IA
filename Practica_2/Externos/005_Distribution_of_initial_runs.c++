#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <queue>
#include <tuple>
using namespace std;

// Mezcla k corridas ordenadas
vector<int> k_merge(const vector<vector<int>>& lists) {
    using Node = tuple<int,int,int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int i = 0; i < (int)lists.size(); ++i)
        if (!lists[i].empty()) pq.emplace(lists[i][0], i, 0);

    vector<int> out;
    while (!pq.empty()) {
        auto [val, li, pi] = pq.top(); pq.pop();
        out.push_back(val);
        int nxt = pi + 1;
        if (nxt < (int)lists[li].size())
            pq.emplace(lists[li][nxt], li, nxt);
    }
    return out;
}

// Distribuye en corridas iniciales (bloques), ordena cada bloque y mezcla
vector<int> distribution_of_initial_runs(const vector<int>& a, int tapes = 3) {
    int n = (int)a.size();
    int chunk = max(1, (n + tapes - 1) / tapes); // tamaño aproximado por "cinta"

    vector<vector<int>> runs;
    for (int i = 0; i < n; i += chunk) {
        vector<int> block(a.begin() + i, a.begin() + min(i + chunk, n));
        sort(block.begin(), block.end());        // ordena corrida inicial
        runs.push_back(block);                   // guarda corrida
    }

    // Mezcla balanceada de todas las corridas
    return k_merge(runs);
}

int main() {
    // Arreglo grande (simulado)
    vector<int> a = {12, 3, 17, 8, 2, 20, 1, 9, 15, 7, 14, 11, 6, 4, 10, 5, 13, 16, 18, 19};

    cout << "Unsorted: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    // Distribuye en corridas iniciales y mezcla
    vector<int> sorted = distribution_of_initial_runs(a, /*tapes*/ 3);

    cout << "Sorted:   ";
    for (int x : sorted) cout << x << " ";
    cout << "\n";
    return 0;
}