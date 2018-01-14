#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 502;
int t, n;
char g[2][N];
bool vis[2][N];

void dfs(int i, int j){
	if(i < 0 or i > 1 or j < 0 or j >= n) return;
	if(g[i][j] == '.') return;
	vis[i][j] = 1;
	
	if(!vis[i-1][j]) dfs(i-1, j);
	if(!vis[i+1][j]) dfs(i+1, j);
	if(!vis[i][j-1]) dfs(i, j-1);
	if(!vis[i][j+1]) dfs(i, j+1);
}

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(vis, 0, sizeof vis);
		scanf("%d", &n);

		For(i,0,n){
			//scanf(" %c", g[0][i]);
			cin >> g[0][i];
		}
		For(i,0,n){
			//scanf(" %c", g[1][i]);
			cin >> g[1][i];
		}

		if(n <= 2){
			printf("yes\n");
			continue;
		}

		bool ok = 1;
		for(int i = 1; i <= n-1; i++){
			if(g[0][i-1] == '#' and g[0][i] == '#' and g[0][i+1] == '#' and g[1][i] == '#' and g[1][i-1] == '.' and g[1][i+1] == '.'){
				ok = 0;
				break;
			}
			if(g[1][i-1] == '#' and g[1][i] == '#' and g[1][i+1] == '#' and g[0][i] == '#' and g[0][i-1] == '.' and g[0][i+1] == '.'){
				ok = 0;
				break;
			}
		}

		For(i,0,n-2){
			if(g[0][i] == '#' and g[0][i+1] == '#' and g[0][i+2] == '#' and g[1][i] == '#' and g[1][i+1] == '#' and g[1][i+2] == '#'){
				ok = 0;
				break;
			}
		}

		int comp = 0;
		For(i,0,2){
			For(j,0,n){
				if(g[i][j] == '#' and !vis[i][j]){
					dfs(i,j);
					comp++;
				}
			}
		}

		if(comp != 1) ok = 0;

		if(ok){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}

