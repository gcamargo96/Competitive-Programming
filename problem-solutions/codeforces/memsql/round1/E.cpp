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
int indeg[N], outdeg[N];
bool vis[N], visc[N];
int to[N], has[N];
ll fat[N];
vector<int> adj[N];

void init(){
	for(int i = 0; i < N; i++){
		to[i] = i;
	}

	fat[0] = 1;
	for(ll i = 1; i < N; i++){
		fat[i] = (fat[i-1]*i)%M;
	}
}

/*pair<ll,ll> dfs(int u){
	if(vis[u]) return mp(0,0);
	vis[u] = 1;
	if(to[u] == u){
		return mp(1, has[u]);
	}
	pair<ll,ll> aux = dfs(to[u]);
	return mp(aux.fi+1, aux.se+has[u]);
}*/

pair<ll,ll> dfs(int u){
	if(vis[u]) return mp(0LL,0LL);
	vis[u] = 1;
	pair<ll,ll> ret = mp(0LL,0LL);
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		pair<ll,ll> aux = dfs(v);
		ret.fi += aux.fi, ret.se += aux.se;
	}
	ret.fi += 1, ret.se += has[u];
	return ret;
}

ll fastpow(ll b, ll e){
	if(e == 0) return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0){
		return (x*x)%M;
	}
	else{
		return ((b*x)%M * x)%M;
	}
}

int main(void){
	init();
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &u, &v);
		has[u] = 1;
		if(u == v) continue;
		// adj[u].pb(v);
		// to[u] = v;
		to[v] = u;
		adj[v].pb(u);
		// outdeg[u]++;
		// indeg[v]++;
		outdeg[v]++;
		indeg[u]++;
	}

	ll ans = 1;
	for(int u = 1; u <= 2*n; u++){
		if(!vis[u] and indeg[u] == 0 and outdeg[u] > 0){
			// printf("comecou em %d\n", u);
			pair<ll,ll> aux = dfs(u);
			// printf("pair = %lld %lld\n", aux.fi, aux.se);
			ll num = fat[aux.fi];
			ll den = (fat[aux.se] * fat[aux.fi - aux.se])%M;
			ll ncr = (num * fastpow(den, M-2))%M;
			ans = (ans * ncr)%M;
		}
	}

	for(int u = 1; u <= 2*n; u++){
		if(!vis[u] and outdeg[u] > 0){
			// printf("comecou em %d\n", u);
			pair<ll,ll> aux = dfs(u);
			// printf("pair = %lld %lld\n", aux.fi, aux.se);
			// ans = (ans * aux.fi)%M;
			// printf("aux.fi = %lld\n", aux.fi);
			ans = (ans*2LL)%M;
		}
	}

	printf("%lld\n", ans);

	return 0;
}