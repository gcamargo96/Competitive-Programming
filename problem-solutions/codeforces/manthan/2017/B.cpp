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
#define fast_cin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n;
ll p, q, r;

int main(void){
	scanf("%d%lld%lld%lld", &n, &p, &q, &r);

	ll maxx = -1000000010, minn = 1000000010;
	ll x;
	bool hasZero = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &x);
		minn = min(minn, x);
		maxx = max(maxx, x);
		if(x == 0) hasZero = 1;
	}

	ll ans = 0;
	if(p < 0){
		ans += p * minn;
	}
	else{
		ans += p * maxx;
	}

	if(q < 0){
		ans += q * minn;
	}
	else{
		ans += q * maxx;
	}

	if(r < 0){
		ans += r * minn;
	}
	else{
		ans += r * maxx;
	}

	printf("%lld\n", ans);

	return 0;
}