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

ll dp[20][3][3];
int t;
ll n;
string s;

ll solve(int i, int last, int flag){
	if(i == s.size()) return 1;
	if(dp[i][last][flag] != -1) return dp[i][last][flag];

	ll ret = 0;
	if(flag){
		ret += solve(i+1, 1, 1); // coloca 1
		ret += 8LL*(solve(i+1, 0, 1)); // qualquer digito menos 1 e 3
		if(!last) ret += solve(i+1, 0, 1); // coloca 3
	}
	else{
		if(!(s[i] == '3' and last)){ // coloca s[i]
			ret += solve(i+1, s[i] == '1', 0);
		}

		ll cnt = s[i]-'0';
		if(s[i] > '1'){ // coloca 1
			ret += solve(i+1, 1, 1);
			cnt--;
		}
		if(s[i] > '3' and !last){ // coloca 3
			ret += solve(i+1, 0, 1);
			cnt--;
		}
		if(s[i] > '3' and last){
			cnt--;
		}

		// printf("cnt = %lld\n", cnt);
		if(cnt > 0){
			ret += cnt * solve(i+1, 0, 1);
		}
	}

	// printf("dp[%d][%d][%d] = %lld\n", i, last, flag, ret);

	return dp[i][last][flag] = ret;
}

int main(void){
	freopen("hotel.in", "r", stdin);
	freopen("hotel.out", "w", stdout);
	
	scanf("%d", &t);

	while(t--){
		scanf("%lld", &n);
		s = to_string(n);

		// memset(dp, -1, sizeof dp);
		// ll pos = solve(0,0,0) - 1;
		// printf("pos n = %lld\n", pos);

		// memset(dp, -1, sizeof dp);
		// ll ans = solve(0,0,0) - 1;
		// printf("%lld\n", ans);

		ll l = 1, r = 2000000000000000000LL, ans;
		while(l <= r){
			ll mid = (l+r)/2LL;
			s = to_string(mid);

			memset(dp, -1, sizeof dp);
			ll pos = solve(0,0,0) - 1;

			// printf("%lld %lld %lld %lld\n", l, r, mid, pos);

			if(pos == n){
				ans = mid;
				r = mid-1;
			}
			else if(pos < n){
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}