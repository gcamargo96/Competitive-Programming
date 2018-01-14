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

const int N = 200002;
int n;
int a[N], ans[N];
vector<int> adj[N];
set<tuple<int,int,int> > vis;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve(int u, int pu, bool flag, int g){
	tuple<int,int,int> tp = make_tuple(u, flag, g);
	if(vis.count(tp)) return;
	vis.insert(tp);

	if(!flag) ans[u] = max(ans[u], g);
	ans[u] = max(ans[u], gcd(a[u], g));

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(v != pu){
			solve(v, u, flag, gcd(g, a[u]));
			if(!flag) solve(v, u, 1, g);
		}
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	solve(1, -1, 0, 0);

	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}