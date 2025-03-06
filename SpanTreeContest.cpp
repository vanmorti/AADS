#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define int ll

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
struct Point {
    int x, y;
};
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

signed main(){
    int n;
    cin >> n;
    vector<Point> p(n);
    for (Point &a : p) {
        cin >> a.x >> a.y;
    }
    vector<
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

