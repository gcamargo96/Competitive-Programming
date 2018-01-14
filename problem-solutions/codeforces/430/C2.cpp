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
bool vis[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int u, int gcd1, int gcd2){
	vis[u] = 1;
	ans[u] = (u == 1 ? a[u] : max(gcd1, gcd(gcd2, a[u])));
	// printf("u = %d / noZero = %d / withZero = %d\n", u, noZero, withZero);
	// printf("u = %d / gcd1 = %d / gcd2 = %d\n", u, gcd1, gcd2);

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			int newgcd1 = gcd(gcd1, a[u]); // no changes
			int A = (u == 1 ? 0 : gcd(gcd1, a[v])); // don't pick u
			int B = gcd(gcd2, a[u]); // pick u
			int newgcd2 = (gcd(a[v], gcd1) > gcd(a[v],B) ? A : B);

			// printf("%d para %d -> newgcd1 = %d / A = %d / B = %d\n", u, v, newgcd1, A, B);
			dfs(v, newgcd1, newgcd2);
			// dfs(v, noZero, withZero, changeToZero);
			// dfs(v, noZero, )
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

	dfs(1, 0, 0);

	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}