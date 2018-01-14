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

const int N = 100002;

int main(void){

	ll x = 2LL*99999LL + 100001LL*100000LL;
	x %= (1LL<<32);

	ll y = 99999LL + 100001LL*100001LL;
	y %= (1LL<<32);

	printf("%lld %lld\n", x, y);

	return 0;
}