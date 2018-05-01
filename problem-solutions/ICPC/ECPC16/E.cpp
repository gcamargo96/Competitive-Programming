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

const int N = 100005;
int t, n;
int dist[N];
vi adj[N];

void init(){
	memset(dist, INF, sizeof dist);
	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
}

void bfs(){
	queue<int> q;
	dist[n] = 0;
	q.push(n);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : adj[u]){
			if(dist[u]+1 < dist[v]){
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

int main(void){
	freopen("jumping.in", "r", stdin);
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d", &n);

		int d;
		for(int i = 1; i <= n; i++){
			scanf("%d", &d);
			if(i-d >= 1){
				adj[i-d].pb(i);
			}
			if(i+d <= n){
				adj[i+d].pb(i);
			}
		}

		bfs();

		for(int u = 1; u <= n; u++){
			if(dist[u] != INF){
				printf("%d\n", dist[u]);
			}
			else{
				printf("-1\n");
			}
		}
	}

	return 0;
}