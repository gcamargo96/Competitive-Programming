#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n;
vector<int> adj[N];
bool vis[N], color[N];
ll cnt0 = 0, cnt1 = 0;

void dfs(int u, bool cor){
	vis[u] = 1;
	color[u] = cor;
	if(cor == 0) cnt0++;
	else cnt1++;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v, !cor);
		}
	}
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0);

	ll ans = 0;
	for(int u = 1; u <= n; u++){
		if(color[u] == 0){
			ans += cnt1 - ll(adj[u].size());
		}
		else{
			ans += cnt0 - ll(adj[u].size());
		}
		//ans += ll(cnt[!color[u]]) - ll(adj[u].size());
	}

	ans /= 2;

	printf("%lld\n", ans);

	return 0;
}