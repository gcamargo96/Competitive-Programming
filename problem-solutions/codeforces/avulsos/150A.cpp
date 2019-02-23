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

ll n;
unordered_map<ll, bool> dp;

bool solve(ll n){
	if(dp.count(n)) return dp[n];

	bool prime = 1, nxt = 1;
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			prime = 0;
			nxt &= solve(i);
			nxt &= solve(n/i);
		}
	}

	if(prime) return dp[n] = 1;
	return dp[n] = !nxt;
}

int main(void){
	scanf("%lld", &n);

	if(n == 1){
		printf("1\n");
		printf("0\n");
		return 0;
	}

	bool ans = solve(n);

	if(ans == 1){
		printf("1\n");

		bool prime = 1;
		ll nxt = 1;
		for(ll i = 2; i*i <= n; i++){
			if(n%i == 0){
				prime = 0;
				if(dp[i] == 0){
					nxt = i;
					break;
				}
				if(dp[n/i] == 0){
					nxt = n/i;
					break;
				}
			}
		}

		if(prime) printf("0\n");
		else printf("%lld\n", nxt);
	}
	else{
		printf("2\n");
	}

	return 0;
}