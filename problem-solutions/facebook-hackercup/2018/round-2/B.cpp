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

const int N = 200005, M = 1000005;
int seg[4*N], p[N], h[N], in[N], out[N], pos[N];
int c[M];

int a, b;
int t, n, m;
int A, B;
int tempo = 0;

vi adj[N];
vi v;

void init(){
	tempo = 0;

	memset(seg, 0, sizeof seg);
	memset(p, 0, sizeof p);
	memset(h, 0, sizeof h);
	memset(in, 0, sizeof in);
	memset(out, 0, sizeof out);
	memset(pos, 0, sizeof pos);
	memset(c, 0, sizeof c);

	v.clear();
	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
}

int query(int r, int i, int j){
	if(b < i || a > j) return 0;
	if(a <= i && j <= b) return seg[r];
	
	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return max(L,R);
}

void update(int r, int x, int i, int j){
	if(b < i || a > j) return;
	if(a <= i && j <= b){
		seg[r] = x;
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

void build(int r, int i, int j){
	if(i == j){
		seg[r] = v[i];
		return;
	}
	int mid = (i+j)/2;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

void dfs(int u){
	in[u] = tempo++;
	h[u] = h[p[u]]+1;
	v.pb(u);
	pos[u] = int(v.size())-1;

	for(int v : adj[u]){
		dfs(v);
	}
	out[u] = tempo-1;
}

bool cmp(int a, int b){
	return h[a] > h[b];
}

int main(void){
	scanf("%d", &t);
	
	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d%d%d", &n, &m, &A, &B);
	
		for(int i = 1; i < n; i++){
			scanf("%d", &p[i]);
			adj[p[i]].pb(i);
		}


		dfs(0);
		build(1, 0, n-1);
		// for(int i = 0; i < n; i++){
		// 	a = b = i;
		// 	printf("%d ", query(1,0,n-1));
		// }
		// printf("\n");

		for(int i = 0; i < m; i++){
			ll x = (ll(A)*ll(i) + ll(B))%ll(n);
			c[i] = int(x);
		}

		sort(c, c+m, cmp);

		ll ans = 0;
		for(int i = 0; i < m; i++){
			int u = c[i];

			a = in[u], b = out[u];
			int q = query(1, 0, n-1);
			if(q > 0){
				ans += q;

				a = b = pos[q];
				update(1, 0, 0, n-1);
			}
		}

		printf("Case #%d: %lld\n", caso, ans);
	}

	return 0;
}