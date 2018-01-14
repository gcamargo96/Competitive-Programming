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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002;
ll a, b;
int dp[N];
map<ll,ll> dp2;

int go(ll x){
	if(x == 1) return 1;
	if(dp[x] != -1) return dp[x];

	int ret = 1, cnt = 1;
	for(int i = 2; i*i <= x; i++){
		if(x%i == 0){
			//printf("%d ", i);
			ret = max(ret, go(x/i));
			cnt++;
			if(i*i != x){
				//buffer.pb(x/i);
				ret = max(ret, go(i));
				cnt++;
			}
		}
	}

	return dp[x] = ret + cnt + 1;
}

ll go2(ll x){
	if(x == 1) return 1;
	if(dp2.count(x)) return dp2[x];

	ll ret = 1, cnt = 1;
	for(ll i = 2; i*i <= x; i++){
		if(x%i == 0){
			//printf("%d ", i);
			ret = max(ret, go2(x/i));
			cnt++;
			if(i*i != x){
				//buffer.pb(x/i);
				ret = max(ret, go2(i));
				cnt++;
			}
		}
	}

	return dp2[x] = ret + cnt + 1LL;
}

void init(){
	memset(dp, -1, sizeof dp);
	dp2.clear();
}

int main(void){
	init();
	scanf("%lld%lld", &a, &b);

	ll res = 0;
	if(b <= 1000000){
		int aa = a, bb = b;
		for(int i = bb; i >= aa; i--){
			res += go(i) - 1;
		}
	}
	
	/*if(b > 1000000){
		for(ll i = b; i >= a; i--){
			res += go2(i) - 1;
		}	
	}*/

	printf("%lld\n", res);
	
	/*for(int i = 1; i <= 1000000; i++){
		go(i);
	}
	
	printf("{");
	for(int i = 1; i <= 1000000-1; i++){
		printf("%d,", dp[i]);
		if(i%1000 == 0) printf("\n");
	}
	printf("%d};", dp[1000000]);
	*/

	return 0;
}

