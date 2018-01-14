#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int N = 100007, inf = 0x3f3f3f3f;

int col[N], vis[N];
vector<int> vec, edges[N];
int memo[N];

void topo(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	int v, i;
	for(i = 0; i < edges[u].size(); ++i) {
		v = edges[u][i];
		topo(v);
	}

	vec.pb(u);
}

int solve(int u) {
	if(memo[u] == -1) {
		int ans = 0;
		for(int i = 0; i < edges[u].size(); ++i) {
			ans = max(ans, (col[edges[u][i]] == 0? col[u] : 0) + solve(edges[u][i]));
		}
		if(col[u] and edges[u].size() == 0) ans++;
		memo[u] = ans;
	}
	return memo[u];
}

int main() {
	memset(memo, -1, sizeof memo);
	int n, m, u, v;
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 0; i < n; ++i) cin >> col[i];

	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		edges[u].pb(v);
	}

	for(int i = 0; i < n; ++i) {
		topo(i);
	}

	reverse(vec.begin(), vec.end());

	int ans = 0;
	for(int i = 0; i < vec.size(); ++i) {
		ans = max(ans, solve(vec[i]));
	}

	cout << ans << endl;

}