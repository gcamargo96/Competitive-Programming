#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 105;
int n, k;
char g[N][N];
int cnt[N][N];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &g[i][j]);
		}
	}

	// horizontal
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-k+1; j++){
			bool ok = 1;
			for(int l = 0; l < k; l++){
				if(g[i][j+l] == '#'){
					ok = 0;
				}
			}
			if(ok){
				// printf("h %d %d\n", i, j);
				for(int l = 0; l < k; l++){
					cnt[i][j+l]++;
				}
			}
		}
	}	

	// vertical
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= n-k+1; i++){
			bool ok = 1;
			for(int l = 0; l < k; l++){
				if(g[i+l][j] == '#'){
					ok = 0;
				}
			}
			if(ok){
				// printf("v %d %d\n", i, j);
				for(int l = 0; l < k; l++){
					cnt[i+l][j]++;
				}
			}
		}
	}

	int x = 1, y = 1, mx = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			// printf("%d ", cnt[i][j]);
			if(cnt[i][j] > mx){
				mx = cnt[i][j];
				x = i;
				y = j;
			}
		}
		// printf("\n");
	}

	printf("%d %d\n", x, y);

	return 0;
}