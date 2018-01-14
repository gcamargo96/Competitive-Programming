#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

ll n, m, x, y;

bool f(ll vende){
	if((n-vende)*x <= m + vende*y) return 1;
	return 0;
}

ll bin_search(ll l, ll r){
	ll last = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if(f(mid)){
			last = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	// printf("l = %lld / r = %lld / last = %lld\n", l, r, last);
	return last;
}

int main(void){
	scanf("%lld%lld%lld%lld", &n, &m, &x, &y);

	/*ll evolui = m/x;
	n -= evolui;
	m -= evolui*x;
	*/

	ll evolui = n-bin_search(0, n);

	printf("%lld\n", evolui);

	return 0;
}