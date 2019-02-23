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

const int N = 100005;
ll n, k, A, B;
int v[N];

ll POW(ll b, ll e){
	ll x = 1;

	for(int i = 0; i < e; i++){
		x *= b;
	}

	return x;
}

ll solve(ll l, ll r){
	ll na = upper_bound(v, v+k, r) - lower_bound(v, v+k, l);
	if(na == 0) return A;
	if(l == r) return na*B;

	ll ret = B*na*ll(r-l+1);
	
	ll mid = (l+r)/2LL;
	// printf("mid = %lld\n", mid);
	ret = min(ret, solve(l, mid) + solve(mid+1, r));

	return ret; 
}

int main(void){
	scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
	n = POW(2, n);

	for(int i = 0; i < k; i++){
		scanf("%d", &v[i]);
		v[i]--;
	}

	sort(v, v+k);

	ll ans = solve(0, n-1);

	printf("%lld\n", ans);

	return 0;
}