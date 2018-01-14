#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
 
const int N = 1000002;
ll a, b;
//int dp[N];
map<ll,ll> dp2;
ll res = 0;

ll go(ll x){
	if(x == 1){
		//cout << "res += 1" << endl;
		res++;
		return 1;
	}
	//if(dp2.count(x)) return dp2[x];
	ll alt = 1, i;
	bool foi = 0;
	for(i = 2; i*i <= x; i++){
		if(x%i == 0){
			//printf("%d ", i);
			alt = go(x/i);
			res += 2*alt;
			//if(i*i == x) res--;
			foi = 1;
			break;
		}
	}
	if(!foi){
		alt = go(1);
		res += 2*alt;
	}	
	//printf("altura de %lld = %lld/ res += %lld\n", x, alt, 2*alt);

	return alt+1;
	//dp2[x] = ret +  + 1LL;
}
 
int main(void){
	scanf("%lld%lld", &a, &b);
 
	for(ll i = b; i >= a; i--){
		go(i);
		res--;
	}	

	/*for(int i = 1; i <= 100; i++){
		printf("%d ", dp[i]);
	}
	printf("\n");
 	*/

	printf("%lld\n", res);
 
	return 0;
}
