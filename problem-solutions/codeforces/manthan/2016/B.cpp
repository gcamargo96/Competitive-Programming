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

ll m;

int main(void){
	scanf("%lld", &m);

	vector<ll> ans;
	ll cnt, i = 5;
	while(1){
		ll cur = 5;
		cnt = 0;
		while(cur <= i){
			cnt += i/cur;
			cur *= 5LL;
		}
		if(cnt == m){
			ans.pb(i);
		}
		else if(cnt > m){
			// printf("saiu com i = %lld\n", i);
			break;
		}
		i++;
	}

	// printf("cnt = %lld\n", cnt);

	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%lld ", ans[i]);
	}
	printf("\n");

	return 0;
}