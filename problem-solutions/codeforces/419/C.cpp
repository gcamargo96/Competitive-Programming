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

#define INF 1000
const int N = 102;
int n, m;
int g[N][N], a[N][N];
vector<ii> r, c;
int ans = 0;

void add_row(int i, int x){
	for(int j = 1; j <= m; j++){
		a[i][j] += x;
	}
}

void add_col(int j, int x){
	for(int i = 1; i <= n; i++){
		a[i][j] += x;
	}
}

bool complete(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] != g[i][j]) return 0;
		}
	}
	return 1;
}

void check_rows(){
	for(int i = 1; i <= n; i++){
		int mn = INF;
		for(int j = 1; j <= m; j++){
			mn = min(mn, g[i][j] - a[i][j]);
		}

		if(mn > 0){
			add_row(i, mn);
			r.eb(i, mn);
			ans += mn;
		}
	}
}

void check_cols(){
	for(int j = 1; j <= m; j++){
		int mn = INF;
		for(int i = 1; i <= n; i++){
			mn = min(mn, g[i][j]-a[i][j]);
		}

		if(mn > 0){
			add_col(j, mn);
			c.eb(j, mn);
			ans += mn;
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &g[i][j]);
		}
	}

	if(n >= m){
		check_cols();
		check_rows();
	}
	else{
		check_rows();
		check_cols();
	}

	if(complete()){
		printf("%d\n", ans);
		for(int i = 0; i < r.size(); i++){
			for(int j = 0; j < r[i].se; j++){
				printf("row %d\n", r[i].fi);
			}
		}
		for(int i = 0; i < c.size(); i++){
			for(int j = 0; j < c[i].se; j++){
				printf("col %d\n", c[i].fi);
			}
		}
	}
	else{
		printf("-1\n");
	}

	return 0;
}