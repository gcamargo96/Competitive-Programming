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

const int N = 502;
int n, v[N];
ll g[N][N], ans[N];
bool used[N];

void floyd(){
	for(int k = n-1; k >= 0; k--){
		used[v[k]] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j] = min(g[i][j], g[i][v[k]] + g[v[k]][j]);
				if(used[i] and used[j]){
					ans[k] += g[i][j];
				}
			}
		}
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%lld", &g[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	floyd();

	for(int i = 0; i < n; i++){
		printf("%lld ", ans[i]);
	}
	printf("\n");

	return 0;
}