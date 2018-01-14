#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1000002;
int pai[N], peso[N], vis[N];
int n, sum, root;
vi adj[N], res;

int dfs(int u){
	int ret = peso[u];
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		ret += dfs(v);
	}

	//printf("no %d -> %d\n", u, ret);
	if(ret == sum/3){
		res.pb(u);
		return 0;
	}
	else{
		return ret;
	}
}

int main(void){
	scanf("%d", &n);

	int u;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &pai[i], &peso[i]);

		adj[pai[i]].pb(i);
		sum += peso[i];
		if(pai[i] == 0) root = i;
	}

	if(sum%3 != 0){
		printf("-1\n");
		return 0;
	}

	dfs(root);

	if(res.size() >= 3){
		printf("%d %d\n", res[0], res[1]);
	}
	else{
		printf("-1\n");
	}

	return 0;
}

