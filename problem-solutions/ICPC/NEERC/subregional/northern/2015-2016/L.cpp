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
int r, c;
int g[N][N];

int up(int x, int y){
	if(x == 1) return 1;
	
	int val = g[x][y];
	for(int i = x-1; i >= 1; i--){
		if(g[i][y] >= val) return 0;
	}

	return 1;
}

int right(int x, int y){
	if(y == c) return 1;

	int val = g[x][y];
	for(int i = y+1; i <= c; i++){
		if(g[x][i] >= val) return 0;
	}

	return 1;
}

int down(int x, int y){
	if(x == r) return 1;

	int val = g[x][y];
	for(int i = x+1; i <= r; i++){
		if(g[i][y] >= val) return 0;
	}

	return 1;
}

int left(int x, int y){
	if(y == 1) return 1;

	int val = g[x][y];
	for(int i = y-1; i >= 1; i--){
		if(g[x][i] >= val) return 0;
	}

	return 1;
}

int main(void){
	freopen("lucky.in", "r", stdin);
	freopen("lucky.out", "w", stdout);

	scanf("%d%d", &r, &c);

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			scanf("%d", &g[i][j]);
		}
	}

	int ans = 0;
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			ans += up(i,j);
			ans += right(i,j);
			ans += down(i,j);
			ans += left(i,j);
		
			// printf("%d %d %d %d\n", up(i,j), right(i,j), down(i,j), left(i,j));
		}
	}

	printf("%d\n", ans);

	return 0;
}