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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000005;
ii v[N];
int n;
vi adj[N], rev[N], topsort;
int vis[N], scc[N], size_scc[N], acum[N];
int cur_scc = 0;
int pos[N];

bool cmp_se(ii a, ii b){
	return a.se < b.se;
}

bool cmp_origin(ii a, ii b){
	return pos[a.fi] < pos[b.fi];
}

void dfs(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}

	topsort.pb(u);
}

int dfs_rev(int u){
	vis[u] = 1;
	scc[u] = cur_scc;

	// printf("scc[%d] = %d\n", u, scc[u]);

	int cnt = 1;
	for(int v : rev[u]){
		if(!vis[v]){
			cnt += dfs_rev(v);
		}
	}

	return cnt;
}

int main(void){
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &v[i].fi, &v[i].se);
		pos[v[i].fi] = i;
	}

	sort(v, v+n);

	for(int i = 0; i < n; i++){
		int origin = pos[v[i].fi];
		v[i].fi = i;
		pos[i] = origin;

		if(i > 0){
			adj[i].pb(i-1);
			rev[i-1].pb(i);
		}
	}

	sort(v, v+n, cmp_se);

	for(int i = 1; i < n; i++){
		adj[v[i].fi].pb(v[i-1].fi);
		rev[v[i-1].fi].pb(v[i].fi);
	}

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}

	reverse(topsort.begin(), topsort.end());
	memset(vis, 0, sizeof vis);

	for(int i = 0; i < n; i++){
		int u = topsort[i];
		if(!vis[u]){
			size_scc[cur_scc] = dfs_rev(u);
			cur_scc++;
			// printf("\n");
		}
	}

	acum[cur_scc-1] = size_scc[cur_scc-1];
	for(int i = cur_scc-2; i >= 0; i--){
		acum[i] = acum[i+1] + size_scc[i];
	}

	// for(int i = 0; i < cur_scc; i++){
	// 	printf("%d ", acum[i]);
	// }
	// printf("\n");

	sort(v, v+n, cmp_origin);

	for(int i = 0; i < n; i++){
		int u = v[i].fi;
		int comp = scc[u];
		// printf("u = %d, scc = %d\n", u, comp);
		printf("%d\n", acum[comp]-1);
	}

	return 0;
}