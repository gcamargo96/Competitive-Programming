#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define eb emplace_back

const int INF = 1000000000; 
const int N=55;

struct edge {
	int a, b, cap, flow;
	edge() {}
	edge(int a, int b, int cap, int flow):a(a), b(b), cap(cap), flow(flow){}
};

struct seg {
	int a, b, x, id;
	seg() {}
	seg(int a, int b, int x, int id) : a(a), b(b), x(x), id(id){}

	bool operator<(const seg& s) const{
		if(x == s.x){
			if(a == s.a)
				return b < s.b;
			return a < s.a;
		}
		return x < s.x;
	}
};

int so = 0, si = N-1, d[N], ptr[N], q[N];
vector<edge> e;
vi g[N];

int t, n, h;
vector<seg> segs;

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
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (so, INF)){ 
			flow += pushed;
		}
	}
	return flow;
}

void intersect(seg u, seg v, set<seg> subs){
	if(u.x == v.x) return;

	if(u.a >= v.a and u.b <= v.b){ // totalmente dentro
		subs.erase(u);
		add_edge(u.id, v.id, u.b-u.a);
	}
	else if(u.a < v.a and u.b < v.b){ // totalmente fora
		subs.erase(u);
		subs.insert(seg(u.a, v.a, u.x, u.id));
		subs.insert(seg(v.b, u.b, u.x, u.id));
		add_edge(u.id, v.id, v.b-v.a);
	}
	else if(u.a < v.a and u.b <= v.b){
		subs.erase(u);
		subs.insert(seg(u.a, v.a, u.x, u.id));
		add_edge(u.id, v.id, u.b-v.a);
	}
	else if(u.a >= v.a and u.b > v.b){
		subs.erase(u);
		subs.insert(seg(v.b, u.b, u.x, u.id));
		add_edge(u.id, v.id, v.b-u.a);
	}
}

void build(){
	sort(segs.begin(), segs.end());

	for(int i = 0; i < segs.size(); i++){
		set<seg> subs;
		subs.insert(segs[i]);

		for(int j = i-1; j >= 0; j--){
			auto it = subs.begin();
			while(it != subs.end()){
				seg s = *it;
				set<seg> ss = s;
				intersect(segs[j], s, subs);
				if(s != ss) it = subs.begin();
				else it++;
			}
		}

		subs.clear();

		for(int j = i+1; j < segs.size(); j++){
			for(seg s : subs){
				intersect(s, segs[j], subs);
			}
		}
	}
}

bool vis[N];

void dfs2(int u){
	vis[u] = 1;
	cout << "u = " << u << endl;

	for(int v : g[u]){
		if(!vis[v]){
			dfs2(v);
		}
	}
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &n, &h);

		bool ok = 0;
		int x, a, b;
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &x, &a, &b);
			segs.eb(a,b,x,i+1);

			if(a == 0){
				add_edge(so, i+1, INF);
			}
			if(b == h){
				add_edge(i+1, si, INF);
			}
			if(a == 0 and b == h){
				ok = 1;
			}
		}

		// dfs2(1);

		if(ok){
			printf("Case #%d: -1\n", caso);
			continue;
		}

		build();

		int ans = dinic();

		printf("Case #%d: %d\n", caso, ans);
	}

	return 0;
}