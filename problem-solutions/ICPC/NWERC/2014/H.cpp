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

const int N = 10005;
int n, cnt = 3;
vi adj[N];
int ans[N][2];
int vis[N];
int dp[N];

void solve(int u, int f){
	vis[u] = 1;
	ans[u][0] = f;
	ans[u][1] = cnt++;

	bool flag = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(vis[v]) continue;

		if(adj[v].size() == 1){
			ans[v][0] = ans[u][0];
			ans[v][1] = ans[u][1];
		}
		else if(!vis[v]){
			solve(v, flag == 0 ? ans[u][1] : ans[u][0]);
			flag = 1;
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

	ans[1][0] = 1, ans[1][1] = 2;
	vis[1] = 1;
	bool flag = 0;
	for(int i = 0; i < adj[1].size(); i++){
		int v = adj[1][i];
		if(vis[v]) continue;

		if(adj[v].size() == 1){
			ans[v][0] = ans[1][0];
			ans[v][1] = ans[1][1];
		}
		else{
			solve(v, flag == 0 ? 2 : 1);
			flag = 1;
		}
	}

	for(int u = 1; u <= n; u++){
		printf("%d %d\n", ans[u][0], ans[u][1]);
	}

	return 0;
}