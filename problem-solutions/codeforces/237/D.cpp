#include <bits/stdc++.h>
using namespace std;
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

const int N = 1000002;
const ll M = 1000000007;
string s;
ll dp[N][5];

ll solve(int i, int last){
	// cout << i << " " << last << endl;
	if(i == s.size()){
		if(last == 1 or last == 3)
			return 0;
		return 1;
	}

	ll& DP = dp[i][last];
	if(DP != -1)
		return DP;

	ll ret = 0;
	
	if(s[i] == '0'){
		if(last == 1 or last == 3 or last == 4)
			return DP = 0;
		else
			return DP = (ret + solve(i+1, 0))%M;
	}
	else if(s[i] == '1'){
		if(last == 1 or last == 3)
			return DP = 0;
		if(last == 4)
			return DP = (ret + solve(i+1, 2))%M;
		else
			return DP = (ret + solve(i+1, 1))%M;
	}
	else if(s[i] == '2'){
		if(last == 4)
			return DP = (ret + solve(i+1, 3))%M;
		else
			return DP = 0;
	}
	else if(s[i] == '*'){
		if(last == 0 or last == 2)
			return DP = 0;
		else
			return DP = (ret + solve(i+1, 4))%M;
	}

	if(last == 0){
		ret = (ret + solve(i+1, 0))%M;
		ret = (ret + solve(i+1, 1))%M;
	}
	else if(last == 1){
		ret = (ret + solve(i+1, 4))%M;
	}
	else if(last == 2){
		ret = (ret + solve(i+1, 0))%M;
		ret = (ret + solve(i+1, 1))%M;
	}
	else if(last == 3){
		ret = (ret + solve(i+1, 4))%M;
	}
	else if(last == 4){
		ret = (ret + solve(i+1, 2))%M;
		ret = (ret + solve(i+1, 3))%M;
		ret = (ret + solve(i+1, 4))%M;
	}

	return DP = ret;
}

int main(void){
	fastcin;
	cin >> s;

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 1);
	ll ans2 = solve(0, 2);
	// cout << ans << " " << ans2 << endl;
	cout << (ans + ans2)%M << endl;

	return 0;
}