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

const int N = 1002;
int n, q;
ll g[N][N], v[N][N], h[N][N];

int main(void){
	scanf("%d%d", &n, &q);

	int r, c, l, s;
	for(int i = 0; i < q; i++){
		scanf("%d%d%d%d", &r, &c, &l, &s);

		v[r][c] += s;
		int R = min(r+l, n+1);
		v[R][c] -= s;

		h[R][c+1] -= s;
		int C = min(c+1+l, n+1);
		h[R][C] += s;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			h[i][j] += h[i][j-1];
		}
	}

	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= n; i++){
			v[i][j] += v[i-1][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = h[i][j] + v[i][j];
		}
	}



	// lower triangle
	for(int i = 1; i <= n; i++){
		int r = i;
		for(int c = 1; r <= n and c <= n; r++, c++){
			g[r][c] = g[r-1][c-1] + g[r][c];
		}
	}

	// upper triangle
	for(int i = 2; i <= n; i++){
		int c = i;
		for(int r = 1; r <= n and c <= n; r++, c++){
			g[r][c] = g[r-1][c-1] + g[r][c];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%lld ", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}