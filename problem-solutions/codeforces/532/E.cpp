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

const int N = 100005;
int n, m;
vi adj[N];
int vis[N];
int u[N], v[N], c[N], Rank[N];
vi topsort, inverted;

void init(){
	memset(vis, 0, sizeof vis);
	for(int i = 0; i <= n; i++){
		adj[i].clear();
	}
}

bool dfs(int u){
	vis[u] = 1;

	bool ret = 0;
	for(int v : adj[u]){
		if(vis[v] == 1){
			// printf("ciclo em %d\n", v);
			return 1;
		}
		else if(vis[v] == 0){
			ret |= dfs(v);
		}
	}

	vis[u] = 2;
	return ret;
}

bool check(int x){
	init();

	for(int i = 0; i < m; i++){
		if(c[i] > x){
			adj[u[i]].pb(v[i]);
		}
	}

	bool cicle = 0;
	for(int u = 0; u < n; u++){
		if(vis[u] == 0){
			cicle |= dfs(u);
		}
	}

	return !cicle;
}

void toposort(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(vis[v] == 0){
			toposort(v);
		}
	}

	topsort.pb(u);
}

void build_ans(int x){
	init();

	for(int i = 0; i < m; i++){
		if(c[i] > x){
			adj[u[i]].pb(v[i]);
		}
	}

	for(int u = 0; u < n; u++){
		if(vis[u] == 0){
			toposort(u);
		}
	}
	reverse(topsort.begin(), topsort.end());

	// printf("toposort = ");
	for(int i = 0; i < topsort.size(); i++){
		// printf("%d ", topsort[i]);
		Rank[topsort[i]] = i+1;
	}
	// printf("\n");

	for(int i = 0; i < m; i++){
		// printf("Rank = %d %d\n", Rank[u[i]], Rank[v[i]]);
		if(c[i] <= x and Rank[u[i]] > Rank[v[i]]){
			inverted.pb(i+1);
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u[i], &v[i], &c[i]);
		u[i]--, v[i]--;
	}

	int l = 0, r = 1000000005, contr = 1000000005;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid)){
			contr = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}

	build_ans(contr);

	printf("%d %d\n", contr, int(inverted.size()));

	for(int i = 0; i < inverted.size(); i++){
		printf("%d ", inverted[i]);
	}
	printf("\n");

	return 0;
}