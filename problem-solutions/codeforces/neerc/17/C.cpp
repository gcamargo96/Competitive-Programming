#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int t, n, m;
vi adj[N], rev[N];
set<ii> keep;
bool vis[N];

void init(){
	keep.clear();
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < N; i++){
		adj[i].clear();
		rev[i].clear();
	}
}

void dfs1(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(!vis[v]){
			keep.insert(ii(u,v));
			dfs1(v);
		}
	}
}

void dfs2(int u){
	vis[u] = 1;

	for(int v : rev[u]){
		if(!vis[v]){
			keep.insert(ii(v,u));
			dfs2(v);
		}
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d%d", &n, &m);

		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			rev[v].pb(u);
		}

		dfs1(1);
		memset(vis, 0, sizeof vis);
		dfs2(1);

		int cnt = m - 2*n;
		for(int u = 1; u <= n; u++){
			for(int v : adj[u]){
				if(!keep.count(ii(u,v)) and cnt > 0){
					printf("%d %d\n", u, v);
					cnt--;
				}
			}
		}
	}

	return 0;
}