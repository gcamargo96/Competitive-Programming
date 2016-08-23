#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1000;
const int INF = 0x3f3f3f3f;
int so, si;
int cap[N][N], flow[N][N];
int prv[N]; // vetor de pais dos nos
int n, m;
vector <int> adj[N];

void init(){
	so = 0, si = n+1;
	for(int i = 0; i < N; i++) adj[i].clear();
	memset(cap, 0, sizeof cap);
	memset(flow, 0, sizeof flow);
}

void add_edge(int u, int v, int cc){
	cap[u][v] = cc
	adj[u].pb(v);
	adj[v].pb(u);
}

bool bfs(){
	queue <int> q;
	memset(prv, -1, sizeof prv);
	prv[so] = -2;

	q.push(so);

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(cur == si) return true;

		for(int i = 0; i < adj[cur].size(); i++){
			int nxt = adj[cur][i];
			if(prv[nxt] == -1 and cap[cur][nxt]-flow[cur][nxt] > 0){
				prv[nxt] = cur;
				q.push(nxt);
			}
		}
	}
	return false;
}

int aug(){
	int mf = INF;
	
	for(int i = si; i != so; i = prv[i]){
		mf = min(mf, cap[prv[i]][i]-flow[prv[i]][i]);
	}

	for(int i = si; i != so; i = prv[i]){
		flow[prv[i]][i] += mf;
		flow[i][prv[i]] -= mf;
	}
	
	return mf;
}

int maxflow(){
	int r = 0;
	while(bfs()){
		r += aug();
	}
	return r;
}

int main(void){
	cin >> n >> m;
	init();

	for(int i = 0; i < m; i++){
		int u, v, cc;
		cin >> u >> v >> cc;
		add_edge(u, v, cc);
	}

	int res = maxflow();
	cout << res << endl;

	return 0;
}







