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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n, k;

int main(void){
	scanf("%lld%lld", &n, &k);

	if(k == 0){
		printf("%lld\n", n);
		return 0;
	}

	ll pot = 1;
	while(pot < 1000000000){
		for(ll i = 1; i <= 9; i++){
			ll x = n*pot*i;
			// printf("%lld\n", x);
			int cnt = 0;
			ll aux = x;
			while(aux%10 == 0){
				cnt++;
				aux /= 10;
			}
			// printf("cnt = %d\n", cnt);
			if(cnt >= k){
				printf("%lld\n", x);
				return 0;
			}
		}
		pot *= 10;
	}

	return 0;
}