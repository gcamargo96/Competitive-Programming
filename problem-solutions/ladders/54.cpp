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

#define MOD 1000000007
const int N = 100002;
int n, m;
vi adj[N], rev[N];
int w[N];
bool vis[N];
ll cnt, menor, cnt_menor;
vi p;

void dfs(int u){
	vis[u] = 1;
	
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}

	p.pb(u);
}

void dfs_rev(int u){
	vis[u] = 1;
	//cout << "visrev " << u << endl;

	if(w[u] < menor){
		menor = w[u];
		cnt_menor = 1;
	}
	else if(w[u] == menor){
		cnt_menor++;
	}
	
	For(i,0,rev[u].size()){
		int v = rev[u][i];
		if(!vis[v]){
			dfs_rev(v);
		}
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}

	scanf("%d", &m);

	int u, v;
	For(i,0,m){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		rev[v].pb(u);
	}

	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs(i);
	}

	ll money = 0, ways = 1;
	memset(vis, 0, sizeof vis);
	for(int i = n-1; i >= 0; i--){
		if(!vis[p[i]]){
			menor = INF;
			dfs_rev(p[i]);
			money += menor;
			ways = (ways*cnt_menor)%MOD;

			//cout << "menor = " << menor << " / quantidade = " << cnt_menor << endl;
		}
	}

	printf("%lld %lld\n", money, ways);

	return 0;
}

