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

int t;
ll c, d, l; 

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lld%lld%lld", &c, &d, &l);

		ll lo, hi = d+c;
		if(d >= 2*c){
			lo = d;
		}
		else{
			lo = d + c - min(c, 2*d);
		}

		//printf("%d %d\n", lo, hi);
		if(l%4 == 0 and l >= 4*lo and l <= 4*hi) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}

