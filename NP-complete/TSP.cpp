#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 20;
int n, m, beg, end;
int adj[N][N];

bool complete(int mask){
	for(int i = 1; i <= n; i++){
		if(mask & (1 << i) == 0) return false;
	}
	return true;
}

int TSP(int u, int mask, int sum){
	if(u == end and complete(mask)){
		return sum;
	}
	if(u == end and !complete(mask)) return INF;
	
	int ret = INF;
	for(int v = 1; v <= n; v++){
		if(adj[u][v] != 0){
			if((mask & (1 << v)) == 0){ // considerando a contagem comecando em 1
				ret = min(ret, TSP(v, mask + (1 << v), sum+adj[u][v]));
			}
		}
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cout << "Input: n vertices / n edges / begin / end" << endl;
	cin >> n >> m >> beg >> end;

	int u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		adj[u][v] = w;
		adj[v][u] = w;
	}

	int res = TSP(beg, 0, 0);

	cout << res << endl;

	return 0;
}
