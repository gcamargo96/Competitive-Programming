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

const int N = 1005;
int n, m, k;
int s, d;
vi adj[N];
vector<ii> peso[N];
vi bordas;
bool vis[N];

bool dfs(int u, int l, int r){
	if(u == d) return 1;
	
	vis[u] = 1;

	bool ret = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		int bl = peso[u][i].fi, br = peso[u][i].se;
		
		if(!vis[v] and l >= bl and r <= br){
			ret |= dfs(v, l, r);
		}
	}

	return ret;
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &s, &d);

	int u, v, l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d%d", &u, &v, &l, &r);
		adj[u].pb(v);
		peso[u].pb(ii(l,r));
		bordas.pb(l);
		bordas.pb(r);
	}

	sort(bordas.begin(), bordas.end());
	bordas.resize(unique(bordas.begin(), bordas.end()) - bordas.begin());

	// for(int i = 0; i < bordas.size(); i++){
	// 	printf("%d ", bordas[i]);
	// }
	// printf("\n");

	int last = 0, ans = 0;
	for(int i = 0; i < bordas.size(); i++){
		memset(vis, 0, sizeof vis);
		l = last+1, r = min(k, bordas[i]-1);
		// printf("%d %d\n", l, r);
		if(r >= l and dfs(s, l, r)){
			ans += r-l+1;
		}

		memset(vis, 0, sizeof vis);
		if(bordas[i] <= k and dfs(s, bordas[i], bordas[i])){
			ans++;
		}
		last = bordas[i];
	}

	printf("%d\n", ans);

	return 0;
}