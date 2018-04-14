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

const int N = 42;
int n, m, q;
int g[N][N], memo[N][N][N][N];

int main(void){
	scanf("%d%d%d", &n, &m, &q);

	char ch;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &ch);
			if(ch == '0'){
				g[i][j] = 0;
			}
			else{
				g[i][j] = 1;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = i; k <= n; k++){
				bool ok = 1;
				for(int l = j; l <= m; l++){
					for(int a = i; a <= k; a++){
						if(g[a][l] == 1){
							ok = 0;
						}
					}
					if(ok){
						memo[i][j][k][l] = 1;
					}
				}
			}
		}
	}


	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = i; k <= n; k++){
				for(int l = j; l <= m; l++){
					memo[i][j][k][l] += memo[i][j][k-1][l] + memo[i][j][k][l-1]
						- memo[i][j][k-1][l-1];
				}
			}
		}
	}

	for(int k = n; k >= 1; k--){
		for(int l = m; l >= 1; l--){
			for(int i = k; i >= 1; i--){
				for(int j = l; j >= 1; j--){
					memo[i][j][k][l] += memo[i+1][j][k][l] + memo[i][j+1][k][l]
						- memo[i+1][j+1][k][l];
				}
			}
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		printf("%d ", memo[1][1][i][j]);
	// 	}
	// 	printf("\n");
	// }

	int a, b, c, d;
	for(int i = 0; i < q; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", memo[a][b][c][d]);
	}

	return 0;
}