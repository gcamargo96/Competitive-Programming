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

const int N = 102, INF = 10000000;
int n, m;
int d[N][N], a[N][N];
vector<pair<ii, int> > q;

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			d[i][j] = a[i][j] = INF;
		}
	}

	for(int i = 0; i < N; i++){
		d[i][i] = a[i][i] = 0;
	}
}

void floyd_warshall(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
}

int main(void){
	scanf("%d%d", &n, &m);
	init();

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		d[u][v] = a[u][v] = min(d[u][v], w);
		d[v][u] = a[v][u] = min(d[v][u], w);
		q.pb(mp(ii(u, v), w));
	}

	floyd_warshall();

	bool ok = 1;
	for(int i = 0; i < m; i++){
		u = q[i].fi.fi;
		v = q[i].fi.se;
		w = q[i].se;
		
		if(a[u][v] != d[u][v] or a[v][u] != d[v][u]){
			ok = 0;
			break;
		}
	}

	if(ok){
		printf("%d\n", (n*(n-1))/2);
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				printf("%d %d %d\n", i, j, a[i][j]);
			}
		}
	}
	else{
		printf("-1\n");
	}

	return 0;
}