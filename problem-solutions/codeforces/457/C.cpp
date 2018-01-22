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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n, m;
vector<ii> adj[N];

int main(void){
	scanf("%d%d", &n, &m);

	if(n == 2 and m == 1){
		printf("2 2\n");
		printf("1 2 2\n");
		return 0;
	}

	int e = 0;
	int sum = 0;
	adj[1].pb(ii(n,2));
	e++;
	sum += 2;

	for(int i = 1; i < n-1; i++){
		if(i < n-2){
			adj[i].pb(ii(i+1,2));
			sum += 2;
		}
		else{
			adj[i].pb(ii(i+1, 200183 - sum));
		}
		e++;
	}

	for(int u = 1; u < n and e < m; u++){
		for(int v = u+2; v <= n and e < m; v++){
			if(u == 1 and v == n)
				continue;


			adj[u].pb(ii(v, 1000000000));
			e++;
		}
	}

	if(e < m){
		adj[n-1].pb(ii(n, 1000000000));
		e++;
	}

	// printf("e = %d\n", e);

	printf("2 200183\n");

	for(int i = 0; i < N; i++){
		for(int j = 0; j < adj[i].size(); j++){
			printf("%d %d %d\n", i, adj[i][j].fi, adj[i][j].se);
		}
	}

	return 0;
}