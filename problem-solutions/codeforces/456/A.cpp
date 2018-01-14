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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll y, b;
ll Y, G, B;

int main(void){
	scanf("%lld%lld", &y, &b);
	scanf("%lld%lld%lld", &Y, &G, &B);

	ll yellow = 2LL*Y + 1LL*G;
	ll blue = 1LL*G + 3LL*B;

	ll ans = 0;
	if(yellow > y)
		ans += yellow - y;

	if(blue > b)
		ans += blue - b;

	printf("%lld\n", ans);

	return 0;
}