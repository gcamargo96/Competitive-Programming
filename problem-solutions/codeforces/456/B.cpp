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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n, k;

int main(void){
	scanf("%lld%lld", &n, &k);

	if(k == 1){
		printf("%lld\n", n);
	}
	else{
		ll ans = n;
		bool flag = 0;
		for(int i = 63; i >= 0; i--){
			if(((n>>i) & 1) == 1){
				flag = 1;
			}

			if(flag){
				ans |= (1LL<<i);
			}
		}
		printf("%lld\n", ans);
	}


	return 0;
}