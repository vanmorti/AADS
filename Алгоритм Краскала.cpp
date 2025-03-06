#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define int ll

/*
Алгоритм Краскала — это жадный алгоритм для нахождения минимального остовного дерева взвешенного графа. 
Основная идея заключается в последовательном добавлении рёбер в остовное дерево, начиная с самого легкого.
Основные шаги алгоритма:
*/
struct Dsu{    
    vector<int> l; // лидеры
	vector<int> r; // ранги деревьев
	void init(int n) {
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
    int from, to, weight;
};

signed main(){
    int n, m;
    cin >> n >> m;
/*
1. Подготовка:
Создаём систему непересекающихся множеств, где каждая вершина находится в своем собственном множестве.
Сортируем рёбра графа по весу от наименьшего к наибольшему.
*/
    Dsu d; 
    d.init(n);
    vector<Edge> edges(m);
    for (Edge &e : edges) {
        cin >> e.from >> e.to >> e.weight;
        e.from--; e.to--;
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
/*
2. Перебор всех рёбер по возрастанию их веса:
Выбираем ребро с наименьшим весом среди оставшихся.
Проверяем, образуют ли концы выбранного ребра цикл. Для этого проверяем, находятся ли они в одном множестве (функция unite(a, b) вернёт false).
Если они уже находятся в одном множестве, пропускаем ребро. Если они находятся в разных множествах (функция unite вернуля true), 
добавляем ребро в остовное дерево (в момент, когда мы использовали unite, множества с данными вершинами уже объединились).    
*/
    int ans = 0;
    for (Edge &e : edges) {
        if (d.unite(e.from, e.to)) {
            ans += e.weight;
        }
    }
    cout << ans << '\n';
    return 0;
}
