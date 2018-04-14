#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

const int N = 50002, INF = 1000000002;
int w[N];
int n, q;
int dist[N];
bool vis[N];

void dijkstra(){
	for(int i = 0; i < w[0]; i++)
		dist[i] = INF;

	dist[0] = 0;
	priority_queue<ii> pq;
	pq.push(mp(0, 0));

	while(!pq.empty()){
		int u = pq.top().se;
		int d = -pq.top().fi;
		pq.pop();

		if(vis[u])
			continue;
		vis[u] = 1;

		for(int i = 0; i < n; i++){
			int v = (u + w[i])%w[0];
			if(d+w[i] < dist[v]){
				dist[v] = d+w[i];
				pq.push(ii(-dist[v], v));
			}
		}
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);
	}

	dijkstra();

	scanf("%d", &q);

	int b;
	for(int i = 0; i < q; i++){
		scanf("%d", &b);

		if(dist[b%w[0]] <= b){
			printf("TAK\n");
		}
		else{
			printf("NIE\n");
		}
	}

	return 0;
}