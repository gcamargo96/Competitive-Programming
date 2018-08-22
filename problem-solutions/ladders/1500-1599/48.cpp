#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 52;
char g[N][N];
int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%s", g[i]);
	}

	bool res = 1;
	For(i,0,n){
		For(j,0,m){
			if(g[i][j] == 'B'){
				For(k,0,n){
					For(l,0,m){
						if(!(i == k and j == l) and g[k][l] == 'B'){
							int x = i, y = j;
							bool ok1 = 1;
							while(x < k){
								if(g[x][y] == 'W') ok1 = 0;
								x++;
							}
							while(x > k){
								if(g[x][y] == 'W') ok1 = 0;
								x--;
							}
							while(y < l){
								if(g[x][y] == 'W') ok1 = 0;
								y++;
							}
							while(y > l){
								if(g[x][y] == 'W') ok1 = 0;
								y--;
							}
						
							x = i, y = j;
							bool ok2 = 1;
							while(y < l){
								if(g[x][y] == 'W') ok2 = 0;
								y++;
							}
							while(y > l){
								if(g[x][y] == 'W') ok2 = 0;
								y--;
							}
							while(x < k){
								if(g[x][y] == 'W') ok2 = 0;
								x++;
							}
							while(x > k){
								if(g[x][y] == 'W') ok2 = 0;
								x--;
							}

							if(!ok1 and !ok2){
								//printf("%d %d -> %d %d\n", i, j, k, l);
								res = 0;
							}
						}
					}
				}
			}
		}
	}

	if(res) printf("YES\n");
	else printf("NO\n");

	return 0;
}

