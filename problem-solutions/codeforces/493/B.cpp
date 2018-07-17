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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int dp[N][2*N][N]; // pos, dif, peso
int v[N];
int n, b;

int solve(int i, int dif, int peso){
	if(peso > b) return -INF;
	if(i == n){
		if(dif == 102) return 0;
		return -INF;
	}
	
	int& DP = dp[i][dif][peso];
	if(DP != -1) return DP;

	if(v[i]%2 == 0) dif++;
	else dif--;

	int ret = solve(i+1, dif, peso);
	if(dif == 102 and i < n-1){
		ret = max(ret, solve(i+1, dif, peso+abs(v[i+1]-v[i])) + 1);
	}

	return DP = ret;
}

int main(void){
	scanf("%d%d", &n, &b);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(0,102,0);

	printf("%d\n", ans);

	return 0;
}