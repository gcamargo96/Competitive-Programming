#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005, K = 105;
int dist[N][K];
int n, m, s, k;
vi adj[N], tipos[N];
queue<int> q;

void bfs(int label){
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : adj[u]){
			if(dist[u][label]+1 < dist[v][label]){
				dist[v][label] = dist[u][label]+1;
				q.push(v);
			}
		}
	}
}

void print_matrix(){
	for(int u = 1; u <= n; u++){
		for(int l = 1; l <= k; l++){
			printf("%d ", dist[u][l]);
		}
		printf("\n");
	}
}

int main(void){
	scanf("%d%d%d%d", &n, &m, &k, &s);

	int u, v;
	for(int i = 1; i <= n; i++){
		scanf("%d", &u);
		tipos[u].pb(i);
	}

	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	memset(dist, INF, sizeof dist);
	for(int i = 1; i <= k; i++){ // label
		for(int u : tipos[i]){ // nodes
			dist[u][i] = 0;
			q.push(u);
		}
		bfs(i);
	}

	// print_matrix();

	for(int u = 1; u <= n; u++){
		int ans = 0;
		vi d;
		
		for(int i = 1; i <= k; i++){
			d.pb(dist[u][i]);
		}
		
		sort(d.begin(), d.end());

		for(int i = 0; i < s; i++){
			ans += d[i];
		}

		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}