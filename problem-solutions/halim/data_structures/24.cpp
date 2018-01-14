#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

multiset<int> bills;
int n, k, x;

int main(void){
	while(scanf("%d", &n) and n != 0){
		bills.clear();
		ll res = 0;

		For(i,0,n){
			scanf("%d", &k);
			For(j,0,k){
				scanf("%d", &x);
				bills.insert(x);
			}
			auto lo = bills.begin();
			auto hi = --bills.end();

			res += *hi - *lo;
			bills.erase(lo);
			bills.erase(hi);
		}
		
		printf("%lld\n", res);
	}

	return 0;
}
