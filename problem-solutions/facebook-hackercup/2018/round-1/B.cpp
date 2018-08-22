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

const int N = 2002;
int t, n, k;
int l[N], r[N];
int label[N];
vi pre, pos;
vi adj[N];

void init(){
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	memset(label, 0, sizeof label);
	pre.clear();
	pos.clear();

	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
}

void preorder(int u){
	pre.pb(u);
	if(l[u] != 0) preorder(l[u]);
	if(r[u] != 0) preorder(r[u]);
}

void postorder(int u){
	if(l[u] != 0) postorder(l[u]);
	if(r[u] != 0) postorder(r[u]);
	pos.pb(u);
}

void dfs(int u, int cor){
	label[u] = cor;

	for(int v : adj[u]){
		if(label[v] == 0){
			dfs(v, cor);
		}
	}
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d", &n, &k);

		for(int i = 1; i <= n; i++){
			scanf("%d%d", &l[i], &r[i]);
		}

		preorder(1);
		postorder(1);

		for(int i = 0; i < n; i++){
			int u = pre[i];
			int v = pos[i];
			adj[u].pb(v);
			adj[v].pb(u);
		}

		int cor = 0;
		for(int u = 1; u <= n; u++){
			if(label[u] == 0){
				if(cor < k) cor++;
				dfs(u, cor);
			}
		}

		printf("Case #%d: ", caso);
		if(cor == k){
			for(int u = 1; u < n; u++){
				printf("%d ", label[u]);
			}
			printf("%d\n", label[n]);
		}
		else{
			printf("Impossible\n");
		}
	}

	return 0;
}