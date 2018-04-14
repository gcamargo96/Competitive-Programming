#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 200002;
int n;
ll p, q;
ll v[N];

bool f(ll x){
	ll dmg = x*q;

	ll cnt = 0;
	for(int i = 0; i < n; i++){
		ll sobra = v[i] - dmg;
		// printf("%lld ", sobra);
		if(sobra > 0){
			cnt += (sobra+(p-q-1))/(p-q);
		}
	}
	// printf("\n");

	// printf("x = %lld, cnt = %lld\n", x, cnt);

	return cnt <= x;
}

int main(void){
	scanf("%d%lld%lld", &n, &p, &q);

	ll mx = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		mx = max(mx, v[i]);
	}

	ll ans = 0;
	if(p == q){
		ans = (mx+p-1)/p;
		printf("%lld\n", ans);
		return 0;
	}

	ll l = 0, r = 1000000000;
	while(l <= r){
		int mid = (l+r)/2;

		if(f(mid) == 1){ // deu bom, tenta com menos golpes
			ans = mid;
			r = mid-1;
		}
		else{ // deu ruim, tenta com mais golpes
			l = mid+1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}