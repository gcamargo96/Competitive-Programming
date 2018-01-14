#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int dist[N], pai[N];
vector<int> g[N], peso[N];
int n, m;

void bellman_ford(int s){ // s = source
	for(int u = 1; u <= n; u++){
		pai[u] = 0;
		if(u == s) dist[u] = 0;
		else dist[u] = INF;	
	}
	
	bool stop = 0;
	for(int t = 0; t < n; t++){
		stop = 1;
		for(int u = 1; u <= n; u++){
			for(int i = 0; i < g[u].size(); i++){
				int v = g[u][i], w = peso[u][i];
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					pai[v] = u;
					stop = 0;
				}
			}
		}
		if(stop) break;
	}
}

int main(void){
	scanf("%d%d", &n, &m); // number of vertices

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(v);
		g[v].pb(u);
		peso[u].pb(w);
		peso[v].pb(w);
	}

	int s, t;
	scanf("%d", &s);

	bellman_ford(s);

	scanf("%d", &t);

	printf("Distance from %d to %d = %d\n", s, t, dist[t]);

	return 0;
}

