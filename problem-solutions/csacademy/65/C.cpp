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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
vi adj[N];
int dist[N], pai[N];
int n;
int x, y;
vi ans;

void dfs(int u, int p, int d){
	dist[u] = d;

	for(int v : adj[u]){
		if(v == p)
			continue;

		dfs(v, u, d+1);
		pai[v] = u;
	}
}

void dfs_subtree(int u, int p){
	ans.pb(u);
	for(int v : adj[u]){
		if(v == p)
			continue;

		dfs_subtree(v, u);
		ans.pb(u);
	}
}

void get_path(int u, int p){
	ans.pb(u);
	// printf("u = %d\n", u);

	if(u == x)
		return;

	for(int v : adj[u]){
		if(v == p)
			continue;

		if(v != pai[u]){
			dfs_subtree(v, u);
			ans.pb(u);
		}
	}

	get_path(pai[u], u);
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0, 0);

	int maxdist = -1;
	for(int u = 1; u <= n; u++){
		if(dist[u] > maxdist){
			maxdist = dist[u];
			x = u;
		}
	}

	// printf("x = %d\n", x);

	dfs(x, 0, 0);

	maxdist = -1;
	for(int u = 1; u <= n; u++){
		if(dist[u] > maxdist){
			maxdist = dist[u];
			y = u;
		}
	}

	// printf("y = %d\n", y);

	get_path(y, 0);

	printf("%d\n", int(ans.size())-1);
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}