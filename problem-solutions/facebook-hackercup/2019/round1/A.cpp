#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 55;
int a[N][N], d[N][N];
int U[N], V[N], W[N];
int t, n, m;

void init(){
	memset(a, INF, sizeof a);
	memset(d, INF, sizeof d);
	for(int i = 0; i < N; i++){
		a[i][i] = 0;
		d[i][i] = 0;
	}
}

// alterar o INF por segurança?
void floyd_warshall(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
}

bool check(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;

			if(a[i][j] != INF and d[i][j] != a[i][j]){
				return 0;
			}
		}
	}

	return 1;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d", &n, &m);

		int u, v, w;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &w);
			U[i] = u;
			V[i] = v;
			W[i] = w;

			a[u][v] = w;
			a[v][u] = w;

			d[u][v] = w;
			d[v][u] = w;
		}

		floyd_warshall();
		bool ok = check();

		if(ok){
			printf("Case #%d: %d\n", caso, m);

			for(int i = 0; i < m; i++){
				printf("%d %d %d\n", U[i], V[i], W[i]);
			}
		}
		else{
			printf("Case #%d: Impossible\n", caso);			
		}
	}

	return 0;
}