#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

const int INF = 1000000000; 
const int N=3005;

struct edge {
	int a, b, cap, flow, t;
	edge() {}
	edge(int a, int b, int cap, int flow, int t):a(a), b(b), cap(cap), flow(flow), t(t){}
};

int so, si, d[N], ptr[N], q[N];
vector<edge> e;
vi g[N];
int P, R, C;
int p[N], r[N];

void add_edge (int a, int b, int cap, int t) {
	edge e1(a, b, cap, 0, t);
	edge e2(b, a, 0, 0, t); //back edge
	g[a].push_back ((int) e.size());
	e.push_back(e1);
	g[b].push_back ((int) e.size());
	e.push_back(e2);
}

bool bfs(int t) {
	int qh=0, qt=0;
	q[qt++]=so;
	memset (d, -1, sizeof d);
	d[so] = 0;
	while(qh<qt && d[si]==-1) {
		int v=q[qh++];
		for(size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
			to = e[id].b;
			if(d[to] == -1 && e[id].flow < e[id].cap && e[id].t <= t) {
				q[qt++]=to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[si]!=-1;
}

int dfs (int v, int flow, int t) {
	if (!flow)  return 0;
	if (v == si)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
		to = e[id].b;
		if (d[to] != d[v] + 1 or e[id].t > t)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow), t);
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic(int t) {
	// memset(d, 0, sizeof d);
	// memset(q, 0, sizeof q);

	for(int i = 0; i < e.size(); i++)
		e[i].flow = 0;

	int flow = 0;
	for (;;) {
		if (!bfs(t))  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (so, INF, t)) 
			flow += pushed;
	}
	return flow;
}

int post(int u){
	return u+R;
}

int main(void){
	so = 0, si = N-1;
	scanf("%d%d%d", &P, &R, &C);

	int total = 0;
	for(int i = 1; i <= P; i++){
		scanf("%d", &p[i]);
		add_edge(post(i), si, p[i], 0);
		total += p[i];
	}

	for(int i = 1; i <= R; i++){
		scanf("%d", &r[i]);
		add_edge(so, i, r[i], 0);
	}

	int v, u, t;
	for(int i = 0; i < C; i++){
		scanf("%d%d%d", &v, &u, &t);
		
		add_edge(u, post(v), INF, t);
	}

	int lo = 1, hi = 1e6+5, ans = hi;
	while(lo <= hi){
		// printf("lo = %d, hi = %d\n", lo, hi);
		int mid = (lo+hi)/2;
		int flow = dinic(mid);
		// printf("flow = %d\n", flow);

		if(flow == total){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}

	if(ans < 1e6+5){
		printf("%d\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}