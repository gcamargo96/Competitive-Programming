#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 305;
int n, m, k;
char g[N][N];

void print_ans(int r, int x, int y){
	printf("%d %d\n", x, y);
	printf("%d %d\n", x-r, y);
	printf("%d %d\n", x+r, y);
	printf("%d %d\n", x, y-r);
	printf("%d %d\n", x, y+r);	
	exit(0);
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);
			// printf("%c", g[i][j]);
		}
		// printf("\n");
	}

	int cnt = 0;
	for(int r = 1; 2*r+1 <= min(n,m); r++){
		for(int i = r+1; i <= n-r; i++){
			for(int j = r+1; j <= m-r; j++){
				if(g[i][j] == '*' and 
					g[i-r][j] == '*' and g[i+r][j] == '*'
					and g[i][j-r] == '*' and g[i][j+r] == '*'){

					cnt++;
					if(cnt == k){
						print_ans(r, i, j);
					}
				}
			}
		}
	}

	printf("-1\n");

	return 0;
}