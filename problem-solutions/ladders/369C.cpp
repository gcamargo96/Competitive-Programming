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
vi adj[N], tipo[N];
vi ans;
bool vis[N];
int n;

int dfs(int u, int e){
	vis[u] = 1;

	int ret = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		int t = tipo[u][i];

		if(!vis[v])
			ret += dfs(v, t);
	}

	if(e == 2 and ret == 0)
		ans.pb(u);

	return ret + (e == 2);
}

int main(void){
	scanf("%d", &n);

	int u, v, t;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d%d", &u, &v, &t);
		adj[u].pb(v);
		adj[v].pb(u);
		tipo[u].pb(t);
		tipo[v].pb(t);
	}

	dfs(1, 1);

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}