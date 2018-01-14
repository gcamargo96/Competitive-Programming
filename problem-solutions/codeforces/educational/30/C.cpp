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

const int N = 102;
int g[N][N], dp[N][N], choice[N][N];
int n, m, k;

int solve(int i, int j){
	if(j == m) return 0;
	if(i == n) return solve(0, j+1);
	if(dp[i][j] != -1) return dp[i][j];

	int A = 0, B = 0;
	A = solve(i+1, j); // se g[i][j] é 0 ou é 1 e muda pra 0 

	if(g[i][j] == 1){ // se g[i][j] é 1 e nao muda pra 0
		int sum = 0;
		for(int c = 0; c < min(k, n-i+1); c++){
			sum += g[i+c][j];
		}
		B = solve(0, j+1) + sum;
	}

	if(A > B and g[i][j] == 1){ // se g[i][j] é 1 e é melhor mudar pra 0
		choice[i][j] = 1;
	}

	return dp[i][j] = max(A, B);
}

int solve2(int i, int j){
	if(j == m) return 0;
	if(i == n) return solve2(0, j+1);

	if(g[i][j] == 0){ // só continua
		return solve2(i+1, j);
	}
	if(g[i][j] == 1 and choice[i][j] == 0){ // se g[i][j] é 1 e nao mudou 
		return solve2(0, j+1);
	}
	if(g[i][j] == 1 and choice[i][j] == 1){ // se g[i][j] era 1 e mudou pra 0
		return solve2(i+1, j) + 1;
	}
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &g[i][j]);
		}
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	int cnt = solve2(0, 0);

	printf("%d %d\n", ans, cnt);

	return 0;
}