#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 300005;
vi adj[N], flav[N];
int n, m, res;
int cor[N];
bool vis[N];
set<int> used;

void dfs(int u){
	vis[u] = 1;

	For(i,0,flav[u].size()){
		int v = flav[u][i];
		if(cor[v] != 0){
			used.insert(cor[v]);
		}
	}
	int cur = 1;
	For(i,0,flav[u].size()){
		int c = 1, v = flav[u][i];
		if(cor[v] != 0) continue;

		while(used.count(cur)){
			cur++;
		}
		cor[v] = cur;
		used.insert(cur);
		cur++;
	}

	used.clear();
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int qnt, x;
	For(i,1,n+1){
		scanf("%d", &qnt);
		For(j,0,qnt){
			scanf("%d", &x);
			flav[i].pb(x);
		}
	}

	int u, v;
	For(i,0,n-1){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);

	for(int i = 1; i <= m; i++){
		if(cor[i] == 0){
			cor[i] = 1;
		}
		res = max(res, cor[i]);
	}

	printf("%d\n", res);
	for(int i = 1; i <= m; i++){
		printf("%d ", cor[i]);
	}
	printf("\n");

	return 0;
}

