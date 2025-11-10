#include <iostream>
#include <vector>
using namespace std;

// Fusión de dos corridas
vector<int> merge_runs(const vector<int>& A, const vector<int>& B) {
    vector<int> out;
    out.reserve(A.size() + B.size());
    size_t i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] <= B[j]) out.push_back(A[i++]);
        else              out.push_back(B[j++]);
    }
    while (i < A.size()) out.push_back(A[i++]);
    while (j < B.size()) out.push_back(B[j++]);
    return out;
}

// Divide el arreglo en corridas naturales (subsecuencias no-decrecientes)
vector<vector<int>> detect_runs(const vector<int>& a) {
    vector<vector<int>> runs;
    if (a.empty()) return runs;

    vector<int> run;
    run.push_back(a[0]);
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] >= a[i - 1]) {
            // Sigue no-decreciente: extender corrida actual
            run.push_back(a[i]);
        } else {
            // Cerramos corrida y abrimos otra
            runs.push_back(run);
            run.clear();
            run.push_back(a[i]);
        }
    }
    runs.push_back(run);
    return runs;
}

void natural_merge_sort(vector<int>& a) {
    if (a.size() < 2) return;

    while (true) {
        // 1) Detectar corridas naturales
        vector<vector<int>> runs = detect_runs(a);
        if (runs.size() == 1) {
            // Ya quedó una sola corrida => ordenado
            a = runs[0];
            return;
        }

        // 2) Mezclar corridas de dos en dos
        vector<int> merged_all;
        merged_all.reserve(a.size());
        for (size_t i = 0; i < runs.size(); i += 2) {
            if (i + 1 < runs.size()) {
                vector<int> m = merge_runs(runs[i], runs[i + 1]);
                merged_all.insert(merged_all.end(), m.begin(), m.end());
            } else {
                merged_all.insert(merged_all.end(), runs[i].begin(), runs[i].end());
            }
        }
        // 3) Reemplazar 'a' por el resultado y repetir
        a.swap(merged_all);
    }
}

int main() {
    vector<int> a = {5, 7, 9, 1, 2, 8, 8, 10, 3, 4};  // Contiene corridas naturales
    cout << "Unsorted: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    natural_merge_sort(a);

    cout << "Sorted:   ";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}
