#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

ll k, n, s, p;

int main(void){
	scanf("%lld%lld%lld%lld", &k, &n, &s, &p);

	ll fpp = (n+s-1)/s;
	ll ft = fpp*k;
	ll pt = (ft+p-1)/p;

	printf("%lld\n", pt);

	return 0;
}