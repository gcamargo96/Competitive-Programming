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

int n, k;

ll f(ll x){
	return ((1LL+x)*x)/2LL;
}

int main(void){
	scanf("%d%d", &n, &k);

	ll lo = 1, hi = n, ans = 0;
	while(lo <= hi){
		ll mid = (lo+hi)/2LL;

		if(f(mid) - (n-mid) == k){
			// printf("mid = %d\n", mid);
			ans = n-mid;
			break;
		}
		else if(f(mid) - (n-mid) < k){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}