#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define int ll

/*
Алгоритм Краскала — это жадный алгоритм для нахождения минимального остовного дерева взвешенного графа. 
Основная идея заключается в последовательном добавлении рёбер в остовное дерево, начиная с самого легкого ребра, 
пока не будут соединены все вершины графа.
Основные шаги алгоритма:
1. Инициализация:
Сортируем рёбра графа по весу от наименьшего к наибольшему.
Создаём систему непересекающихся множеств, где каждая вершина находится в своем собственном множестве.
2. Перебор всех рёбер по возрастанию их веса:
Выбираем ребро с наименьшим весом среди оставшихся.
Проверяем, образуют ли концы выбранного ребра цикл. Для этого проверяем, находятся ли они в одном множестве (функция unite(a, b) вернёт false).
Если они уже находятся в одном множестве, пропускаем ребро. Если они находятся в разных множествах (функция unite вернуля true), 
добавляем ребро в остовное дерево (в момент, когда мы использовали unite, множества с данными вершинами уже объединились).
*/
struct Dsu {
    vector<int> l;
    vector<int> r;
    void set(int n) {
        l.resize(n);
        r.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            l[i] = i;
        }
    }
    int leader(int v) {
        if (l[v] == v) {
            return v;
        }
        return l[v] = leader(l[v]);
    }
    bool unite(int a, int b) {
        a = leader(a); b = leader(b);
        if (a == b) {
            return false;
        }
        if (r[a] > r[b]) {
            swap(a, b);
        }
        r[b] = max(r[b], r[a] + 1);
        l[a] = b;
        return true;
    }
};

struct Edge {
    int f, t, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

signed main(){
    int n, m;
    cin >> n >> m;
    Dsu d; 
    d.set(n);
    vector<Edge> edges(m);
    for (Edge &e : edges) {
        cin >> e.f >> e.t >> e.w;
        e.f--; e.t--;
    }
    sort(edges.begin(), edges.end(), cmp);
    int ans = 0;
    for (Edge &e : edges) {
        if (d.unite(e.f, e.t)) {
            ans += e.w;
        }
    }
    cout << ans << '\n';
    return 0;
}

