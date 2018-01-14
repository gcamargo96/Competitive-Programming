#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n, m, k;

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	int l = k, r = n-k;

	ll lo = 1, hi = 1000000000;	
	while(lo < hi)
		ll mi = (lo+hi)/2;n
		
		ll pos = mi/2 + 1;

		ll sum = 0;
		if(pos < k){
			sum = 1 + (pos-k)*2;
			sum += k - pos;

			sum += 1 + (k-pos-1)*2;
		}
		if(pos == k){
			sum = 1 + (k-1)*2;

		}
		if(pos > k){
			sum = 1 + (pos-1)*2 - (1 + (pos-k)*2);
		}

		if(sum > m){
			hi = mi-1;
		}
		else{
			lo = mi+1;
		}
		printf("%d %d\n", lo, hi);
	}

	ll res = lo +(l-1)*2;
	printf("%lld\n", res);

	return 0;
}

