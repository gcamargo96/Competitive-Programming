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

const int N = 100005;
vi adj[N];
int n, k;
int vis[N], courses[N];
vi toposort;

bool dfs(int u){
	vis[u] = 1;

	bool ret = 0;
	for(int v : adj[u]){
		if(vis[v] == 0){
			ret |= dfs(v);
		}
		else if(vis[v] == 1){
			return 1;
		}
	}

	vis[u] = 2;
	toposort.pb(u);
	return ret;
}

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < k; i++){
		scanf("%d", &courses[i]);
	}

	for(int u = 1; u <= n; u++){
		int t, v; 
		scanf("%d", &t);

		for(int i = 0; i < t; i++){
			scanf("%d", &v);
			adj[u].pb(v);
		}
	}

	bool cycle = 0;
	for(int i = 0; i < k; i++){
		int u = courses[i];

		if(!vis[u]){
			cycle |= dfs(u);
		}
	}

	if(cycle){
		printf("-1\n");
	}
	else{
		printf("%d\n", (int) toposort.size());

		for(int i = 0; i < toposort.size(); i++){
			printf("%d ", toposort[i]);
		}
		printf("\n");
	}

	return 0;
}