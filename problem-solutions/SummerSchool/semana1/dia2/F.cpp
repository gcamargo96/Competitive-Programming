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

const int N = 100002;
int temp = 0;
int n;
int p[N], vis[N], ini[N], fim[N];
ll bit[N], res[N];
vi adj[N];
ii ranks[N];

void dfs(int u){
	vis[u] = 1;
	ini[u] = temp++;

	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}

	fim[u] = temp-1;
}

void update(int id, ll x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

ll query(int id){
	ll sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

int main(void){
	scanf("%d", &n);

	int m, r, t;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &m, &r, &t);
		if(m == -1) m = 0;
		p[i] = t;
		adj[m].pb(i);
		ranks[i].fi = r;
		ranks[i].se = i;
	}

	dfs(0);
	sort(ranks+1, ranks+n+1);

	int i = 1;
	while(i <= n){
		int j;
		vi aux;
		for(j = i; j <= n and ranks[j].fi == ranks[i].fi; j++){
			int id = ranks[j].se;
			/*printf("id: %d -> %d a %d\n", id, ini[id], fim[id]);
				
			for(int k = 1; k <= n; k++){
				printf("%lld ", query(k) - query(k-1));
			}
			printf("\n");
			*/
			res[id] = query(fim[id]) - query(ini[id]);
			aux.pb(id);
		}
		For(j,0,aux.size()){
			update(ini[aux[j]], p[aux[j]]);
		}
		i = j;
	}

	for(int i = 1; i <= n; i++){
		printf("%lld\n", res[i]);
	}

	return 0;
}

