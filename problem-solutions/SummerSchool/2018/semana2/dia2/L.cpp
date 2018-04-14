#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002;
const ll INF = 1000000000000000000LL;
vi adj[N];
ll d[N], s[N], ans = INF;
ll n;

void dfs(int u, int p){
	s[u] = 1;
	ll qnt = 0;
	for(int v : adj[u]){
		if(v == p)
			continue;

		dfs(v, u);
		s[u] += s[v];

		d[u] += d[v] + (qnt+1) * s[v];
		qnt += (s[v]-1)*2LL;
		qnt += 2;
	}
}

void dfs2(int u, int p, ll nd){
	ll S = n-s[u], S2 = (n-s[u])*(n-s[u]), D = nd;
	for(int v : adj[u]){
		if(v == p)
			continue;

		S += s[v];
		S2 += s[v]*s[v];
		D += d[v];
	}

	// printf("u = %d, ans = %lld\n", u, D + S + (S*S - S2));
	ans = min(ans, D + S + (S*S - S2));

	for(int v : adj[u]){
		if(v == p)
			continue;

		S -= s[v];
		S2 -= s[v]*s[v];
		D -= d[v];
		dfs2(v, u, D + S + (S*S - S2));
		S += s[v];
		S2 += s[v]*s[v];
		D += d[v];
	}
}

int main(void){
	scanf("%lld", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0);
	dfs2(1, 0, 0);

	printf("%lld\n", ans);

	return 0;
}