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

int go(int x){
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

ll go2(ll x, ll div){
	if(x == 1) return 1;
	if(dp2.count(x)) return dp2[x];

	ll ret = 1, cnt = 1;
	for(ll i = div; i*i <= x; i++){
		if(x%i == 0){
			//printf("%d ", i);
			ret = max(ret, go2(x/i, i));
			cnt++;
			if(i*i != x){
				//buffer.pb(x/i);
				//ret = max(ret, go2(i), x/i);
				cnt++;
			}
		}
	}

	return dp2[x] = ret + cnt + 1LL;
}
 
void init(){
	memset(dp, -1, sizeof dp);
}
 
int main(void){
	init();
	scanf("%lld%lld", &a, &b);
 
	ll res = 0;
	if(b <= 1000000){
		for(ll i = b; i >= a; i--){
			res += go(i) - 1;
		}
	}
	else{
		for(ll i = b; i >= a; i--){
			res += go2(i, 2) - 1;
		}	
	}

	/*for(int i = 1; i <= 100; i++){
		printf("%d ", dp[i]);
	}
	printf("\n");
 	*/

	printf("%lld\n", res);
 
	return 0;
}
