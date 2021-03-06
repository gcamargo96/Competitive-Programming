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
ll dp[N];

ll go(ll x){
	if(x == 1) return 1;
	if(dp[x] != -1) return dp[x];

	ll ret = 1, cnt = 1;
	vi buffer;
	for(ll i = 2; i*i <= x; i++){
		if(x%i == 0){
			//printf("%d ", i);
			ret = max(ret, go(i));
			cnt++;
			if(i*i != x){
				buffer.pb(x/i);
				//ret = max(ret, go(x/i));
				//cnt++;
			}
		}
	}
	For(i,0,buffer.size()){
		ret = max(ret, go(buffer[i]));
		cnt++;
	}
	//printf("\n");

	return dp[x] = ret + cnt + 1;
}

void init(){
	For(i,0,N){
		dp[i] = -1;
	}
}

int main(void){
	init();
	scanf("%lld%lld", &a, &b);

	ll res = 0;
	for(ll i = a; i <= b; i++){
		res += go(i) - 1;
	}

	printf("%lld\n", res);
	
	/*for(int i = 1; i <= 1000000; i++){
		go(i);
	}
	
	printf("{");
	for(int i = 1; i <= 1000000-1; i++){
		printf("%d,", dp[i]);
		if(i%1000 == 0) printf("\n");
	}
	printf("%d};", dp[1000000]);
	*/

	return 0;
}

