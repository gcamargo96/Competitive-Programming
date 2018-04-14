#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002, INF = 10000;
int n, m, s, t;
vi adj[N];
int d[N][N], madj[N][N];

void init(){
	for(int u = 1; u < N; u++){
		for(int v = 1; v < N; v++){
			d[u][v] = INF;
		}
	}
}

void bfs(int s){
	queue<int> q;
	q.push(s);
	d[s][s] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : adj[u]){
			if(d[s][u]+1 < d[s][v]){
				d[s][v] = d[s][u]+1;
				q.push(v);
			}
		}
	}
}

int main(void){
	init();
	scanf("%d%d%d%d", &n, &m, &s, &t);

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);	
		madj[u][v] = 1;
		madj[v][u] = 1;
	}

	for(int u = 1; u <= n; u++){
		bfs(u);
	}

	// for(int u = 1; u <= n; u++){
	// 	for(int v = u+1; v <= n; v++){
	// 		printf("d[%d][%d] = %d\n", u, v, d[u][v]);
	// 	}
	// }

	int ans = 0;
	for(int u = 1; u <= n; u++){
		for(int v = u+1; v <= n; v++){
			if(madj[u][v] == 0 and d[s][u] + 1 + d[v][t] >= d[s][t] and d[s][v] + 1 + d[u][t] >= d[s][t]){
				// printf("%d %d\n", u, v);
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}