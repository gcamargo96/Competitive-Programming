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

int tests;
string s, t; 
ll dp[20][4][3];
int n, m;

ll solve(int i, int used, int maior, int menor){
	if(used > 3) return 0;
	if(i == m) return 1;
	if(dp[i][used][maior] != -1) return dp[i][used][maior];

	ll ret = 0;

	if(maior){
		ret += solve(i+1, used, 1, menor | (0 < t[i]-'0')); // coloca 0

		if(menor){
			for(int j = 1; j <= 9; j++){ // coloca outro digito
				ret += solve(i+1, used+1, 1, 1);
			}
		}
		else{
			for(int j = 1; j <= t[i]-'0'; j++){
				ret += solve(i+1, used+1, 1, j < t[i]-'0');
			}
		}
	}
	else{ // se nao é maior
		for(int j = s[i]-'0'; j <= t[i]-'0'; j++){
			ret += solve(i+1, used + (j>0), maior | (j > s[i]-'0'), menor | (j < t[i]-'0'));
		}
	}

	return dp[i][used][maior] = ret;
}

int main(void){
	fastcin;
	cin >> tests;

	while(tests--){
		cin >> s >> t;
		n = s.size(), m = t.size();

		for(int i = 0; i < m-n; i++){
			s = "0" + s;
		}

		// cout << s << " " << t;

		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0, 0, 1);
		cout << ans << endl;
	}

	return 0;
}