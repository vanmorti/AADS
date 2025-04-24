#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int& elem : a) {
        cin >> elem;
    }
    
    const int BLOCK_SIZE = 512; // 300
    const int BLOCK_COUNT = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
    
    vector<int> b(BLOCK_COUNT);
    for (int i = 0; i < n; ++i) {
        int bi = i / BLOCK_SIZE;
        b[bi] += a[i];
    }
    
    for (int i = 0; i < q; ++i) {
        int type;
        // 1 -> insert(i, x)
        // 2 -> sum[l, r)
        cin >> type;
        if (type == 1) {
            int i, val;
            cin >> i >> val;
            int block_number = i / BLOCK_SIZE;
            a[i] = val;
            b[block_number] = 0;
            for (int j = block_number * BLOCK_SIZE; j < min(n, (block_number + 1) * BLOCK_SIZE); ++j) {
                b[block_number] += a[j];
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            int res = 0;
            while (l < r && l % BLOCK_SIZE > 0) {
                res += a[l++];
            }
            while (l < r && r % BLOCK_SIZE > 0) {
                res += a[--r];
            }
            int start = l / BLOCK_SIZE;
            int finish = r / BLOCK_SIZE;
            for (int j = start; j < finish; ++j) {
                res += b[j];
            }
            cout << res << '\n';
        }
    }
}
