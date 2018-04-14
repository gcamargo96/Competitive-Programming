#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
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
typedef complex<double> base;

int n;
map<int,int> dp;

int solve(int n){
	if(n == 1)
		return 1;
	if(dp.count(n))
		return dp[n];

	int ret = n/2+1, s = sqrt(n);
	for(int i = 2; i <= s; i++){
		if(n%i == 0){
			ret = min(ret, solve(n/i) * (i/2+1));
			int j = n/i;
			ret = min(ret, solve(n/j) * (j/2+1));
		}
	}

	return dp[n] = ret;
}

int main(void){
	scanf("%d", &n);
	printf("%d\n", solve(n));

	return 0;
}