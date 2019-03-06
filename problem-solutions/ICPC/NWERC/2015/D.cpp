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

const ll INF = 1000000000000000000LL;
ll n, r, p;

ll LOG(ll x){
	ll cnt = 0, cur = 1;
	while(cur*2LL <= x){
		cnt++;
		cur *= 2;
	}
	return cnt;
}

int main(void){
	scanf("%lld%lld%lld", &n, &r, &p);

	if(n == 1){
		printf("0\n");
		return 0;
	}

	ll ans = LOG(n)*(r+p);
	for(int i = 1; i < n; i++){
		ans = min(ans, r + ll(i)*p + LOG(n-i)*(r+p));
	}

	printf("%lld\n", ans);

	return 0;
}