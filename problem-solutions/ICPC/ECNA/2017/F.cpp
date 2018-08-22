#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10005;
int n;
vi adj[N];
int pai[N], sub[N];
ll ans1[N], ans2[N];

void dfs(int u, int p){
	pai[u] = p;
	sub[u] = 1;

	vi subtrees;
	for(int v : adj[u]){
		if(v == p) continue;

		dfs(v, u);
		sub[u] += sub[v];
		subtrees.pb(sub[v]);
	}
	if(n+1 - sub[u] > 0)
		subtrees.pb(n+1 - sub[u]);

	int nsubs = subtrees.size();
	sort(subtrees.begin(), subtrees.end());
	
	vector<ll> acc(nsubs+2, 0);
	for(int i = nsubs-1; i >= 0; i--){
		acc[i] = acc[i+1] + subtrees[i];
	}

	ans1[u] = 0;
	for(int i = 0; i < nsubs-1; i++){
		ans1[u] += ll(subtrees[i]) * acc[i+1];
	}

	ans2[u] = 0;
	for(int i = 0; i < nsubs-2; i++){
		ans2[u] += ll(subtrees[i]) * acc[i+1];
	}
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(0, -1);

	int id;
	ll crit = -1;
	for(int u = 0; u <= n; u++){
		if(ans1[u] > crit){
			crit = ans1[u];
			id = u;
		}
	}

	printf("%lld %lld\n", ans1[id], ans2[id]);

	return 0;
}