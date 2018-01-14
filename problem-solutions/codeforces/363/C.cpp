#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rest 0
#define contest 1
#define gym 2
#define MAXX 1002

const int N = 102;
int n;
int v[N], dp[N][3];

int solve(int pos, int last, int cnt){
	if(pos == n) return cnt;
	if(dp[pos][last] != -1) return dp[pos][last];

	int a = MAXX, b = MAXX, c = MAXX;
	if((v[pos] == 1 or v[pos] == 3) and last != contest){
		a = solve(pos+1, contest, cnt);
	}
	
	if((v[pos] == 2 or v[pos] == 3) and last != gym){
		b = solve(pos+1, gym, cnt);
	}

	c = solve(pos+1, rest, cnt+1);

	return dp[pos][last] = min(min(a,b), c);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> v[i];
	}

	memset(dp, -1, sizeof dp);
	int res = solve(0, 0, 0);

	cout << res << endl;

	return 0;
}
