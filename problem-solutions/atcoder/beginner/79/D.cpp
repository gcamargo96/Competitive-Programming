#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

// ll c[12][12];
ll a[12][12];
int n, m;

void floyd_warshall(){
    for(int k = 0; k <= 9; k++)
        for(int i = 0; i <= 9; i++)
            for(int j = 0; j <= 9; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
}

// void dijkstra(int u){
// 	d[u] = 0;
// 	priority_queue(pair<ll,int>) pq;
// 	pq.push(mp(0,u));

// 	while(!pq.empty()){
// 		u = pq.top().se;
// 		ll dist = -pq.top().fi;
// 		pq.pop();

// 		for(int v = 0; v <= 9; v++){
// 			ll w = c[u][v];
// 			if(dist + w < d[v]){
// 				d[v] = dist+w;
// 				pq.push(mp(-d[v], v));
// 			}
// 		}
// 	}
// }

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			scanf("%lld", &a[i][j]);
		}
	}
	
	floyd_warshall();

	ll x;
	ll ans = 0;
	for(int i = 0; i < n*m; i++){
		scanf("%lld", &x);
		if(x != -1){
			ans += a[x][1];
		}
	}

	printf("%lld\n", ans);

	return 0;
}