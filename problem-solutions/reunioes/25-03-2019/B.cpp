/*
	O(q * log^2)
	Heavy-Light-Decomposition: on edges

	Same thing as in vertices, the cost of an edge is represented
	in some vertex v such that edge(u, v, c) and pai[v] = u, so
	value(v) = c

	************* ONE BASED VERTICES ***************
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 100005;
int n, q;
vector <int> g[N], p[N];
int dist[N], size[N], pai[N];
int ind, id[N], heavy[N], ch, chain[N], top[N];

ll v[N], seg[4*N + 1];

void build (int r, int i, int j) {

	if (i == j) {
		seg[r] = v[i];
	} else {
		int mid = (i + j)/2;
		build (2*r, i, mid);
		build (2*r + 1, mid + 1, j);
		seg[r] =  seg[2*r] + seg[2*r + 1];
	}
}

int a, b;
ll query (int r, int i, int j, int val) {
	if (j < a or i > b)	return 0;

	if (i >= a and j <= b) {
		if (val != INF)	seg[r] = val;
		return seg[r];
	} else {
		int mid = (i + j)/2;
		ll L = query (2*r, i, mid, val);
		ll R = query (2*r + 1, mid + 1, j, val);

		seg[r] = seg[2*r] + seg[2*r + 1];
		return L + R;
	}
}

ll update (int l, int r, int val) {
	a = l;	b = r;
	return query (1, 0, n - 1, val);
}

ll query (int l, int r) {
	return update (l, r, INF);
}

int pre (int at) {
	size[at] = 1;

	for (auto next : g[at]) {
		if (next == pai[at])	continue;
		dist[next] = dist[at] + 1;
		pai[next] = at;

		size[at] += pre (next);
		
		if (size[next] > size[heavy[at]])
			heavy[at] = next;
	}
	
	return size[at];
}

void dfs (int at, int pai) {
	id[at] = ind++;

	if (heavy[at])	{
		chain[heavy[at]] = chain[at];
		dfs (heavy[at], at);
	}

	for (auto next : g[at]) {
		if (next == pai or next == heavy[at])	continue;
		top[ch] = next;
		chain[next] = ch++;
		dfs (next, at);
	}

	for (int i = 0; i < (int)g[at].size(); i++) {
		int next = g[at][i];
		int peso = p[at][i];
		if (next == pai)	continue;

		v[id[next]] = peso;
	}
}

void build_hld () {
	pre (1);
	ind = ch = 0;
	chain[1] = ch++;
	top[0] = 1;
	dfs (1, 0);
	build (1, 0, n - 1);
}

ll go (int u, int v) {
	ll res = 0;
	while (chain[u] != chain[v]) {
		if (dist[top[chain[u]]] < dist[top[chain[v]]])	swap (u, v);

		int sobe = top[chain[u]];
		/********* ORDEM: id[sobe] < id[u] ***********/
		res += query (id[sobe], id[u]);
		u = pai[sobe];
	}
	if (id[u] > id[v])	swap (u, v);

	res += query (id[u] + 1, id[v]);
	return res;
}

int main (void) {
	scanf("%d", &n);
	
	vector <ii> edg;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;	scanf ("%d%d%d", &a, &b, &c);
		g[a].pb(b);	p[a].pb(c);
		g[b].pb(a);	p[b].pb(c);
		edg.pb(ii(a,b));
	}

	build_hld ();

	scanf("%d", &q);

	while(q--){
		int u, v, e, w, tipo;
		scanf ("%d", &tipo);

		if(tipo == 1){
			scanf("%d%d", &e, &w);
			e--;
			int a = edg[e].fi, b = edg[e].se;
			if (pai[b] == a)	swap (a, b);
			update (id[a], id[a], w);
		}
		else{
			scanf("%d%d", &u, &v);
			printf ("%lld\n", go (u, v));
		}
	}

	return 0;
}