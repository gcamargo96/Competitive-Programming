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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;
int n;
vector<int> adj[N];
bool cyc, full, has[N], vis[N];
ll tam = 0;

ll mul(ll a, ll b){
	return (a*b)%M;
}

void dfs(int u, int p){
	vis[u] = 1;
	// printf("no = %d / has = %d\n", u, int(has[u]));
	full &= has[u];
	tam++;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(v != p and vis[v]){
			// printf("u = %d / v = %d / p = %d\n", u, v, p);
			cyc = 1;
		}
		if(v != p and !vis[v]){
			dfs(v, u);
		}
	}
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &u, &v);
		has[u] = 1;
		if(u == v) continue;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll ans = 1;
	for(int u = 1; u <= 2*n; u++){
		if(!vis[u] and has[u]){
			// printf("u = %d\n", u);
			cyc = 0;
			full = 1;
			tam = 0;
			dfs(u, u);

			if(!full and !cyc){
				// printf("1 - %lld\n", tam);
				ans = mul(ans, tam);
			}
			else if(cyc){
				// printf("2 - %lld\n", tam);
				ans = mul(ans, 2);
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}