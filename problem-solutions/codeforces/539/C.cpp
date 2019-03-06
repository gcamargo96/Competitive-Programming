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

const int N = 300005;
ll v[N];
ll acc[N];
unordered_map<ll, ll> odd, even;
int n;

int main(void){
	scanf("%d", &n);

	even[0]++;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
		acc[i] = acc[i-1] ^ v[i];
		
		if((i&1) == 0){ // even pos
			even[acc[i]]++;
		}
		else{ // odd pos
			odd[acc[i]]++;
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", acc[i]);
	// }
	// printf("\n");

	ll ans = 0;
	for(auto it : even){
		ans += (it.se*(it.se-1LL))/2LL;
	}
	for(auto it : odd){
		ans += (it.se*(it.se-1LL))/2LL;
	}

	printf("%lld\n", ans);

	return 0;
}