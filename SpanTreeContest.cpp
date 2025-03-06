#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n); // Список смежности для хранения рёбер
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;

        g[from].push_back({weight, to});
        g[to].push_back({weight, from});
    }
    vector<bool> in(n); // Массив для отслеживания вершин в минимальном остове
    set<pair<int, int>> q; // Множество для хранения рёбер в порядке возрастания веса
    // Начинаем с первой вершины
    in[0] = true;
    for (auto edge : g[0]) { // Добавляем все рёбра, исходящие из первой вершины
        q.insert(edge);
    }
    int ans = 0;
    while (!q.empty()) {
        auto [w, v] = *q.begin(); // Получаем ребро с минимальным весом
        q.erase(q.begin());
        // Проверяем, находится ли вторая вершина ребра вне MST
        if (!in[v]) {
            ans += w;
            in[v] = true; // Добавляем вторую вершину ребра в MST
            // Добавляем все рёбра, исходящие из новой вершины в MST
            for (auto [weight, to] : g[v]) {
                if (!in[to]) {
                    q.insert({weight, to});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
