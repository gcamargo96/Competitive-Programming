#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 300005;
ll n;
vi adj[N];
int f, b;

bool dfs(int u, int p, int from){
	bool ret = 0;
	for(int v : adj[u]){
		if(v == p)
			continue;

		ret |= dfs(v, u, from);
	}

	if(from == f and u == b)
		ret = 1;
	if(from == b and u == f)
		ret = 1;

	return ret;
}

int dfscnt(int u, int p){
	int cnt = 1;
	for(int v : adj[u]){
		if(v == p)
			continue;
		cnt += dfscnt(v, u);
	}
	return cnt;
}

int main(void){
	scanf("%lld%d%d", &n, &f, &b);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll ftree = 1, btree = 1;
	for(int v : adj[f]){
		bool foundb = dfs(v, f, f);
		if(!foundb){
			ftree += dfscnt(v, f);
		}
	}

	for(int v : adj[b]){
		bool foundf = dfs(v, b, b);
		if(!foundf){
			btree += dfscnt(v, b);
		}
	}

	// printf("ftree = %lld, btree = %lld\n", ftree, btree);

	ll ans = n*(n-1LL) - ftree*btree;
	printf("%lld\n", ans);

	return 0;
}