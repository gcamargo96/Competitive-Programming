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

const int N = 102;
int n, m;
vi adj[N], let[N];
int dp[N][N][30];

int solve(int u, int v, int c){
	int& DP = dp[u][v][c];
	if(DP != -1){
		return DP;
	}

	int ret = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int x = adj[u][i];
		int nc = let[u][i];

		if(nc < c){
			continue;
		}
		if(solve(v, x, nc) == 0){
			ret = 1;
		}
	}

	return DP = ret;
}

int main(void){
	fastcin;
	cin >> n >> m;

	int u, v;
	char c;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> c;
		adj[u].pb(v);
		let[u].pb(c-'a');
	}

	memset(dp, -1, sizeof dp);
	for(int u = 1; u <= n; u++){
		for(int v = 1; v <= n; v++){
			cout << (solve(u,v,0) ? 'A' : 'B');
		}
		cout << endl;
	}

	return 0;
}