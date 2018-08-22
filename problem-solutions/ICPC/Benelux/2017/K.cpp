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

const int N = 1002;
vi adj[N];
char g[N][N];
bool vis[N];
vi ans;
int n;

void dfs(int u){
	vis[u] = 1;
	ans.pb(u);

	for(int v : adj[u]){
		if(!vis[v]) dfs(v);
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %c", &g[i][j]);
			if(g[i][j] == '1'){
				adj[i].pb(j);
			}
		}
	}

	dfs(0);

	if(ans.size() == n){
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else{
		printf("impossible\n");
	}

	return 0;
}