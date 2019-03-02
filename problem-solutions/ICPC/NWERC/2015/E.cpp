#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define ii pair<int,int>
#define fi first
#define se second

const int INF = 1000000000; 
const int N=22000;

struct edge {
	int a, b, cap, flow;
	char op;
	edge() {}
	edge(int a, int b, int cap, int flow, char op):a(a), b(b), cap(cap), flow(flow), op(op){}
};

int so, si, d[N], ptr[N], q[N];
vector<edge> e;
vi g[N];
int n, cnt = 1;
unordered_map<int,int> m_ac, m_res, rev_ac, rev_res;
unordered_set<int> valid;
ii v[N];
char op[N];

void add_edge (int a, int b, int cap, char op) {
	edge e1(a, b, cap, 0, op);
	edge e2(b, a, 0, 0, op); //back edge
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
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (so, INF)) 
			flow += pushed;
	}
	return flow;
}

void update_ac(int a){
	if(!m_ac.count(a)) m_ac[a] = cnt++;
	rev_ac[m_ac[a]] = a;
}

void update_res(int a){
	if(!m_res.count(a)) m_res[a] = cnt++;
	rev_res[m_res[a]] = a;
}

int main(void){
	so = 0, si = N-1;
	scanf("%d", &n);

	int a, b;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		v[i].fi = a, v[i].se = b;

		update_ac(i);
		add_edge(so, m_ac[i], INF, '#');
	}

	for(int i = 1; i <= n; i++){
		a = v[i].fi, b = v[i].se;
		// printf("a = %d, b = %d\n", a, b);

		if(!m_res.count(a+b)){
			update_res(a+b);
			add_edge(m_ac[i], m_res[a+b], 1, '+');
			add_edge(m_res[a+b], si, 1, '#');
		}

		if(!m_res.count(a-b)){
			update_res(a-b);
			add_edge(m_ac[i], m_res[a-b], 1, '-');
			add_edge(m_res[a-b], si, 1, '#');
		}

		if(!m_res.count(a*b)){
			update_res(a*b);
			add_edge(m_ac[i], m_res[a*b], 1, '*');
			add_edge(m_res[a*b], si, 1, '#');
		}
	}

	int flow = dinic();
	// printf("flow = %d\n", flow);

	if(flow >= n){
		for(int i = 0; i < e.size(); i++){
			if(e[i].b == si and e[i].flow == 1){
				// printf("valid %d\n", rev_res[e[i].a]);
				valid.insert(e[i].a);
			}
		}
		for(int i = 0; i < e.size(); i++){
			if(e[i].a >= 1 and e[i].a <= n and e[i].flow == 1 and e[i].op != '#'){
				op[e[i].a] = e[i].op;
			}
		}

		for(int i = 1; i <= n; i++){
			int ans;
			if(op[i] == '+') ans = v[i].fi + v[i].se;
			if(op[i] == '-') ans = v[i].fi - v[i].se;
			if(op[i] == '*') ans = v[i].fi * v[i].se;

			printf("%d %c %d = %d\n", v[i].fi, op[i], v[i].se, ans);
		}
	}
	else{
		printf("impossible\n");
	}

	return 0;
}