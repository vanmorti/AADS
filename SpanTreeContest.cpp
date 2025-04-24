#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char x;
				cin >> x;
				cnt[i] += (x == '1');
			}
		}
		string ans = "SQUARE";
		for (int& elem : cnt) {
			if (elem == 1) {
				ans = "TRIANGLE";
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}