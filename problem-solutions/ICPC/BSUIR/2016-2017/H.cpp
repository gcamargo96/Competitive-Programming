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

const int N = 10005, B = 20;
ll n;
ll v[N];
ll cnt[B];
ll ans = 0;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);

		for(int j = 0; j < 20; j++){
			if((v[i]>>j)&1){
				cnt[j]++;
			}
		}
	}

	for(int i = 0; i < 20; i++){
		if(cnt[i] == 0) continue;

		ll aux = 0;

		// 3 ones
		aux += cnt[i]*(cnt[i]-1)*(cnt[i]-2);
		aux += cnt[i]*(cnt[i]-1)*3LL;
		aux += cnt[i];
	
		// 1 one and 2 zeros
		aux += cnt[i]*((n-cnt[i])*(n-cnt[i]-1)/2LL)*6LL; // zeros em pos diferentes
		aux += cnt[i]*(n-cnt[i])*3LL; // zeros em pos iguais

		ans += aux * (1LL<<i);
	}

	printf("%lld\n", ans);

	return 0;
}