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
map<ii, int> road;
vi adj[N];
priority_queue<pair<int, ii> > pq;
int dist[N], cor[N];
vi res;
set<int> police;

void dijkstra(){
	//memset(dist, INF, sizeof dist);

	while(!pq.empty()){
		int u = pq.top().se.fi;
		int di = -pq.top().fi;
		int c = pq.top().se.se;
		pq.pop();


		cor[u] = c;
		if(di > d) continue;

		//printf("%d\n", u);

		For(i,0,adj[u].size()){
			int v = adj[u][i];
			if(cor[v] != 0 and cor[u] != cor[v] and di+1 >= dist[v]){
				if(road.count(ii(u,v))){
					res.pb(road[ii(u,v)]);
				}
				else{
					res.pb(road[ii(v,u)]);
				}
				continue;
			}

			if(di+1 < dist[v]){
				dist[v] = di+1;
				//cor[v] = cor[u];
				pq.push(mp(-dist[v], ii(v, c)));
			}
		}
	}
}

int main(void){
	scanf("%d%d%d", &n, &k, &d);

	int x;
	For(i,0,N) dist[i] = INF;
	For(i,0,k){
		scanf("%d", &x);
		police.insert(x);
		pq.push(mp(0, ii(x, i+1)));
		cor[x] = i+1;
		dist[x] = 0;
	}

	int u, v;
	For(i,0,n-1){
		scanf("%d%d", &u, &v);
		road[ii(u,v)] = i+1;
		
		if(police.count(u) and police.count(v)){
			if(road.count(ii(u,v))){
				res.pb(road[ii(u,v)]);
			}
			else{
				res.pb(road[ii(v,u)]);
			}
		}
		else{
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}

	if(d == 0){
		printf("%d\n", n-1);
		for(int i = 1; i <= n-1; i++){
			printf("%d ", i);
		}
		printf("\n");
		return 0;
	}

	dijkstra();

	/*printf("dists = ");
	for(int i = 1; i <= n; i++){
		printf("%d ", dist[i]);
	}
	printf("\n");
	*/

	/*sort(res.begin(), res.end());
	auto it = unique(res.begin(), res.end());
	res.resize(it-res.begin());
	*/

	printf("%d\n", res.size());
	For(i,0,res.size()){
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}

