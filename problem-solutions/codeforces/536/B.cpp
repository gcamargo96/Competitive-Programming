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

const int N = 200005;
ll n, m, k;
ll a[N];

int main(void){
	scanf("%lld%lld%lld", &n, &m, &k);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	sort(a, a+n);
	reverse(a, a+n);

	ll x = k*a[0] + a[1];

	ll ans = (m/(k+1LL))*x + (m%(k+1LL))*a[0];

	printf("%lld\n", ans);

	return 0;
}