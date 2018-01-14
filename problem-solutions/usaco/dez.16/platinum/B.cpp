#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define MOD 1000000009
const int N = 1002;
int n, m, k;
int fj[N], fp[N];
int pd[11][11][11];

int solve(int i, int j, int falta){
	if(falta == 0) return 1;
	if(i == n or j == m) return 0;
	int& dp = pd[i][j][falta];
	//if(dp != -1) return dp;
	
	int ret = 0;
	if(fj[i] > fp[j]){
		ret = (ret + solve(i+1, j+1, falta-1))%MOD;
	}
	ret = (ret + solve(i, j+1, falta))%MOD;
	ret = (ret + solve(i+1, j, falta))%MOD;

	return dp = ret;
}

/*int solve(int i, int j, int falta){
	if(falta == 0) return 1;
	if(i == n or j == m) return 0;
	int& dp = pd[i][j][falta];
	//if(dp != -1) return dp;

	int ret = 0;
	for(int k = i; k < n; k++){
		if(fj[k] > fp[j]){
			ret = (ret + solve(i+1, k+1, falta-1))%MOD;
		}
	}
	for(int k = j+1; k < m; k++){
		ret = (ret + solve(i, k, falta))%MOD;
	}

	return dp = ret;
}*/

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	For(i,0,n){
		scanf("%d", &fj[i]);
	}

	For(i,0,m){
		scanf("%d", &fp[i]);
	}

	int res = solve(0,0,k);

	printf("%d\n", res);

	return 0;
}

