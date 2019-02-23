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

const int N = 105;
vi adj[N*N], rev[N*N];
int n, m;
char g[N][N];
int cnt[N][N];
bool vis[N*N];
int cntT = 0, cntE = 0;
vi nodes;

void init(){
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < N; i++){
		adj[i].clear();
		rev[i].clear();
	}
}

// id x = 2*x
// id not x = 2*x + 1
int id (int x, bool n) {
	return 2*x + n;
}

// na == 0, var: a
// na == 1, var: not a
void add_or (int a, bool na, int b, bool nb) {
	g[id(a, !na)].pb(id(b, nb));
	g[id(b, !nb)].pb(id(a, na));
}

// na == 0, var: a
// na == 1, var: not a
void add_implies (int a, bool na, int b, bool nb) {
	add_or (a, !na, b, nb);
}

void add_tower(int x, int y){
	t = cnt[x][y]*4;
	for(int i = 0; i < 4; i++){
		for(int j = i+1; j < 4; j++){
			add_implies(t+i, 0, t+j, 1);
		}
	}

	for(int i = x-1; i >= 1; i--){
		if(g[i][y] == '#') break;
		if(g[i][y] == 'n'){
			add_implies(4*cnt[x][y], 1, 4*cntT+cnt[i][y], 0);
		}
		if(g[i][y] == 'T'){
			add_implies(4*cnt[x][y], 0, 4*cnt[x][y], 1);
			break;
		}
	}

	for(int i = x+1; i <= n; i++){
		if(g[i][y] == '#') break;
		if(g[i][y] == 'n'){
			add_implies(4*cnt[x][y]+1, 1, 4*cntT+cnt[i][y], 0);
		}
		if(g[i][y] == 'T'){
			add_implies(4*cnt[x][y]+1, 0, 4*cnt[x][y]+1, 1);
			break;
		}
	}

	for(int j = y-1; j >= 1; j--){
		if(g[x][j] == '#') break;
		if(g[x][j] == 'n'){
			add_implies(4*cnt[x][y]+2, 1, 4*cntT+cnt[x][j], 0);
		}
		if(g[x][j] == 'T'){
			add_implies(4*cnt[x][y]+2, 0, 4*cnt[x][y]+2, 1);
			break;
		}
	}

	for(int j = y+1; j <= m; j++){
		if(g[x][j] == '#') break;
		if(g[x][j] == 'n'){
			add_implies(4*cnt[x][y]+3, 1, 4*cntT+cnt[x][j], 0);
		}
		if(g[x][j] == 'T'){
			add_implies(4*cnt[x][y]+3, 0, 4*cnt[x][y]+3, 1);
			break;
		}
	}
}

void add_enemy(int x, int y){
	e += 4*cntT + cnt[x][y];
	add_implies(e, 1, e, 0);
}

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	nodes.pb(u);
}

void dfs_rev(int u){
	vis[u] = 1;

	for(int v : rev[u]){
		if(!vis[v]){
			dfs_rev(v);
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);
			
			if(g[i][j] == 'T'){
				cnt[i][j] = cntT++;
			}
			if(g[i][j] == 'n'){
				cnt[i][j] = cntE++;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == 'T'){
				add_tower(cnt[i][j]);
			}
			if(g[i][j] == 'n'){
				add_enemy(cnt[i][j]);
			}
		}
	}

	


	return 0;
}