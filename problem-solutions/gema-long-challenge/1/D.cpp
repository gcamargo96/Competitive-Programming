#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 100005;
int n, q, tempo = 1;
int bit[N], seg[4*N], lazy[4*N], h[N], tin[N], tout[N];
vi adj[N];
int a, b;

void update_bit(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query_bit(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

void prop(int r, int i, int j){
	seg[r] += lazy[r];
	if(i != j){
		lazy[2*r] += lazy[r];
		lazy[2*r+1] += lazy[r];
	}
	lazy[r] = 0;
}

void update_seg(int r, int x, int i, int j){
	if(seg[r] == INF) return;
	prop(r, i, j);
	
	if(i > b or j < a) return;
	

	if(i == j){
		// printf("estou em %d %d, seg[r] = %d\n", i, j, seg[r]);

		seg[r] += x;
		if(seg[r] <= 0){
			update_bit(i, 1);
			seg[r] = INF;
		}
		return;
	}

	if(a <= i and j <= b){
		seg[r] += x;
	
		if(seg[r] > 0){
			lazy[2*r] += x;
			lazy[2*r+1] += x;
			return;
		}
	}

	int mid = (i+j)/2;
	update_seg(2*r, x, i, mid);
	update_seg(2*r+1, x, mid+1, j);
	seg[r] = min(seg[2*r], seg[2*r+1]);
}

int query_seg(int r, int i, int j){
	prop(r, i, j);
	if(i > b or j < a) return INF;
	// printf("estou em %d %d, seg[r] = %d\n", i, j, seg[r]);
	if(a <= i and j <= b) return seg[r];

	int mid = (i+j)/2;
	int L = query_seg(2*r, i, mid);
	int R = query_seg(2*r+1, mid+1, j);
	return min(L, R);
}

void dfs(int u){
	tin[u] = tempo++;

	for(int v : adj[u]){
		dfs(v);
	}

	tout[u] = tempo-1;
}

int main(void){
	scanf("%d", &n);

	int p;
	for(int u = 1; u <= n; u++){
		scanf("%d%d", &h[u], &p);
		adj[p].pb(u);
	}

	dfs(0);

	a = b = 1;
	update_seg(1, INF, 1, n+1);

	for(int i = 1; i <= n; i++){
		a = b = tin[i];
		update_seg(1, h[i], 1, n+1);
	}

	for(int i = 1; i <= n; i++){
		a = b = tin[i];
		query_seg(1, 1, n+1);	
	}

	scanf("%d", &q);

	int tipo, u, x;
	while(q--){
		scanf("%d", &tipo);

		if(tipo == 1){
			scanf("%d%d", &u, &x);
			a = tin[u]+1, b = tout[u];

			update_seg(1, -x, 1, n+1);
		}
		else{
			scanf("%d", &u);
			int ans = (tout[u] - tin[u]) - (query_bit(tout[u]) - query_bit(tin[u]));
			printf("%d\n", ans);
		}

		// for(int i = 0; i <= n+1; i++){
		// 	printf("%d ", query_bit(i) - query_bit(i-1));
		// }
		// printf("\n");
	}

	return 0;
}