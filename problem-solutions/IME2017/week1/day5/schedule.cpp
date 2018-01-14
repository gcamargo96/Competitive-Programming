#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

const int INF = 1000000000; 
const int N=2002;

int n, m;

struct edge {
	int a, b, cap, flow;
	edge() {}
	edge(int a, int b, int cap, int flow):a(a), b(b), cap(cap), flow(flow){}
};

int so, si, d[N], ptr[N], q[N];
vector<edge> e;
vi g[N];

void add_edge (int a, int b, int cap) {
	edge e1(a, b, cap, 0 );
	edge e2(b, a, 0, 0 ); //back edge
	g[a].push_back ((int) e.size());
	e.push_back(e1);
	g[b].push_back ((int) e.size());
	e.push_back(e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++]=so;
	memset (d, -1, sizeof d);
	d[so] = 0;
	while(qh<qt && d[si]==-1) {
		int v=q[qh++];
		for(size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
			to = e[id].b;
			if(d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++]=to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[si]!=-1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == si)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
		to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	memset(ptr, 0, sizeof ptr);
	memset(d, 0, sizeof d);
	memset(q, 0, sizeof q);


	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (so, INF)) 
			flow += pushed;
	}
	return flow;
}

int binary_search(int l, int r){
	int ans = (l+r)/2;
	while(l <= r){
		// printf("loop\n");

		int mid = (l+r)/2;

		for(int i = 0; i < e.size(); i++){
			e[i].flow = 0;
			if(e[i].a == so){
				e[i].cap = mid;
			}
		}

		int flow = dinic();
		 // printf("l = %d / r = %d / mid = %d / flow = %d\n", l, r, mid, flow);
		if(flow == n*mid){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}

	return ans;
}

int main(void){
	scanf("%d%d", &n, &m);
	so = 0, si = n+m+1;

	int k, v;
	for(int u = 1; u <= n; u++){
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			scanf("%d", &v);
			add_edge(u, n+v, 1);
		}
	}

	for(int u = 1; u <= n; u++){
		add_edge(so, u, 1);
	}

	for(int u = 1; u <= m; u++){
		add_edge(n+u, si, 1);
	}

	int ans = binary_search(0, 1000);

	if(ans > 0){
		printf("YES %d\n", ans);
	}
	else{
		for(int i = 0; i < e.size(); i++){
			e[i].flow = 0;
			if(e[i].a == so){
				e[i].cap = 1;
			}
		}
		ans = dinic();
		printf("NO %d\n", ans);
	}

	return 0;
}