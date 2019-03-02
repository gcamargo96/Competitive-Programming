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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f;

const int N = 55;
int n;
char g[N][N];
int r1, c1, r2, c2;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0} };
bool vis[N][N];
vector<ii> v1, v2;

bool dfs(int r, int c, vector<ii>& v){
	vis[r][c] = 1;
	v.pb(ii(r,c));

	bool ret = 0;
	if(r == r2 and c == c2) ret = 1;
	
	for(int i = 0; i < 4; i++){
		int nr = r + dir[i][0];
		int nc = c + dir[i][1];

		if(nr >= 1 and nr <= n and nc >= 1 and nc <= n and !vis[nr][nc] and g[nr][nc] == '0'){
			ret |= dfs(nr, nc, v);
		}
	}

	return ret;
}

void calc_ans(){
	int ans = INF;
	for(int i = 0; i < v1.size(); i++){
		for(int j = 0; j < v2.size(); j++){
			int aux = (v1[i].fi-v2[j].fi)*(v1[i].fi-v2[j].fi) + (v1[i].se-v2[j].se)*(v1[i].se-v2[j].se);

			if(aux < ans){
				ans = aux;

			}
			// printf("%d %d -> %d %d\n", v1[i].fi, v1[i].se, v2[j].fi, v2[j].se);
		}
	}

	printf("%d\n", ans);
	exit(0);
}

int main(void){
	scanf("%d", &n);

	scanf("%d%d", &r1, &c1);
	scanf("%d%d", &r2, &c2);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &g[i][j]);
		}
	}

	bool ok = dfs(r1, c1, v1);

	if(ok){
		printf("0\n");
		return 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			bool ok = 0;
			if(g[i][j] == '0' and vis[i][j] == 0){
				v2.clear();
				ok = dfs(i, j, v2);
			}

			if(ok){
				calc_ans();
			}
		}
	}


	return 0;
}