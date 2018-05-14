#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct cashier{
	ll m, s, p, x;

	cashier() {}

	cashier(ll _m, ll _s, ll _p){
		m = _m;
		s = _s;
		p = _p;
	}

	void calc_x(ll t){
		x = min(m, max(0LL, (t-p)/s));
	}

	bool operator<(const cashier& b) const{
		return x > b.x;
	}
};

const int N = 1005;
int t, r, b, c;
cashier v[N];

bool check(ll t){
	int n = min(r,c);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += v[i].x;
	}
	return sum >= b;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d%d", &r, &b, &c);
	
		for(int i = 0; i < c; i++){
			scanf("%lld%lld%lld", &v[i].m, &v[i].s, &v[i].p);
		}

		ll l = 0, r = 2000000000000000000LL, ans = 0;
		while(l <= r){
			ll mid = (l+r)/2LL;

			for(int i = 0; i < c; i++){
				v[i].calc_x(mid);
			}
			sort(v, v+c);

			if(check(mid)){
				// printf("%lld\n", mid);
				ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}

		printf("Case #%d: %lld\n", caso, ans);
	}

	return 0;
}