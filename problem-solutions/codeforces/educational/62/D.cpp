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

ll n;

int main(void){
	scanf("%lld", &n);

	ll ans = 0;
	for(ll i = 2; i <= n-1; i++){
		ans += i*(i+1LL);
	}

	printf("%lld\n", ans);

	return 0;
}