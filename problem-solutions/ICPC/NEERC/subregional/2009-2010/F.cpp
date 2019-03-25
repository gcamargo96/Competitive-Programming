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

const int N = 25;
int t, h, w, n;
char g[N][N];

int main(void){
	freopen("figure.in", "r", stdin);
	freopen("figure.out", "w", stdout);

	scanf("%d", &t);

	while(t--){
		scanf("%d%d%d", &h, &w, &n);

		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				g[i][j] = '.';
			}
		}

		for(int i = 2; i < h; i++){
			for(int j = 2; j < w; j++){
				if((i+j)%2 == 0 and n){
					g[i][j] = '#';
					n--;
				}
			}
		}

		if(n == 0){
			for(int i = 1; i <= h; i++){
				for(int j = 1; j <= w; j++){
					printf("%c", g[i][j]);
				}
				printf("\n");
			}
		}
		else{
			printf("Impossible\n");
		}

		if(t > 0) printf("\n");
	}

	return 0;
}