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

ll l, r, x, y, k;

int main(void){
	//scanf("%lld%lld%lld%lld%lld", &l, &r, &x, &y, &k);
	cin >> l >> r >> x >> y >> k;

	bool ans = 0;
	/*for(ll i = l; i <= r; i++){
		ll cur = i*k;
		if(x <= cur and cur <= y){
			ans = 1;
			break;
		}
	}*/

	for(ll i = x; i <= y; i++){
		ll cur = i*k;
		if(l <= cur and cur <= r){
			ans = 1;
			break;
		}
	}

	if(ans){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}