#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002;
int n, k, d;
int cor[N];
vi adj[N];
queue<int> q;
//int dist[N];
map<ii, int> road;

void bfs(){
	while(!q.empty()){
		int u = q.front();
		q.pop();

		For(i,0,adj[u].size()){
			int v = adj[u][i];
			if(cor[v] == 0){
				q.push(v);
				cor[v] = cor[u];
			}
		}
	}
}

int main(void){
	scanf("%d%d%d", &n, &k, &d);

	//memset(dist, INF, sizeof dist);
	int u, v;
	For(i,0,k){
		scanf("%d", &u);
		q.push(u);
		cor[u] = i+1;
	}

	For(i,0,n-1){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
		road[ii(u,v)] = i+1;
		road[ii(v,u)] = i+1;
	}

	bfs();

	set<int> res;
	for(int u = 1; u <= n; u++){
		For(i,0,adj[u].size()){
			int v = adj[u][i];
			if(cor[u] != cor[v])
				res.insert(road[ii(u,v)]);
		}
	}

	printf("%d\n", res.size());
	for(int x : res){
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}

