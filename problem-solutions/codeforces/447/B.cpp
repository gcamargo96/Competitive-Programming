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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002;
int n, m, k;
int g[N][N];

bool check(){
	for(int i = 0; i < n; i++){
		int mod = 0;
		for(int j = 0; j < m; j++){
			if(g[i][j] == -1){
				mod++;
				mod %= 2;
			}
		}
		if(k == 1 and mod == 1) return 0;
		if(k == -1 and mod == 0) return 0;
	}

	for(int i = 0; i < m; i++){
		int mod = 0;
		for(int j = 0; j < n; j++){
			if(g[j][i] == -1){
				mod++;
				mod %= 2;
			}
		}
		if(k == 1 and mod == 1) return 0;
		if(k == -1 and mod == 0) return 0;
	}
	return 1;
}

void solve(int x, int y){
	if(x == n){
		if(check()){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					printf("%d ", g[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		return;
	}

	g[x][y] = 1;
	if(y < m) solve(x,y+1);
	else solve(x+1, 0);
	
	g[x][y] = -1;
	if(y < m) solve(x,y+1);
	else solve(x+1, 0);
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	solve(0,0);

	return 0;
}