#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 200005;
ll pot[25];
pair<ll, ll> v[N];
int n, a, b;

void precalc(){
	pot[0] = 1LL;
	for(int i = 1; i <= 20; i++){
		pot[i] = 2LL*pot[i-1];
	}
}

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return a.fi-a.se > b.fi-b.se;
}

int main(void){
	precalc();
	scanf("%d%d%d", &n, &a, &b);

	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &v[i].fi, &v[i].se);
	}

	sort(v, v+n, cmp);

	ll ans = 0;
	for(ll x = 0; x <= a; x++){
		ll mx = -1000000000000000000LL, id = 0;
		for(int i = 0; i < n; i++){
			ll gain = v[i].fi*pot[x] - v[i].se;
			if(gain > mx){
				mx = gain;
				id = i;
			}
		}
		
		ll total = 0;
		int baux = b;

		if(baux > 0){
			total += v[id].fi*pot[x];
			baux--;
		}

		for(int i = 0; i < n; i++){
			if(i != id){
				if(v[i].fi > v[i].se and baux > 0){
					total += v[i].fi;
					baux--;
				}
				else{
					total += v[i].se;
				}
			}
		}

		ans = max(ans, total);

		baux = b, total = 0;
		for(int i = 0; i < n; i++){
			if(v[i].fi > v[i].se and baux > 0){
				total += v[i].fi;
				baux--;
			}
			else{
				total += v[i].se;
			}
		}

		ans = max(ans, total);
	}

	printf("%lld\n", ans);

	return 0;
}