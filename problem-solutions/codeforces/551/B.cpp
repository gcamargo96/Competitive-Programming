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

const int N = 105;
int n, m, h;
int a[N], b[N], g[N][N];

int main(void){
	scanf("%d%d%d", &n, &m, &h);

	for(int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &g[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == 1){
				g[i][j] = min(b[i], a[j]);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}