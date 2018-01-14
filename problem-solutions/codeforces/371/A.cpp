#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

ll k, l1, r1, l2, r2;

int main(void){
	scanf("%lld%lld%lld%lld%lld", &l1, &r1, &l2, &r2, &k);

	ll res = min(r1, r2) - max(l1, l2) + 1;

	if(res < 0){
		printf("0\n");
		return 0;
	}

	if(k >= max(l1, l2) and k <= min(r1, r2)) res--;

	printf("%lld\n", res);

	return 0;
}
