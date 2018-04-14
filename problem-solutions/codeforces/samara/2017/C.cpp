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

ll a, b, c;
ll n, m;

int main(void){
	cin >> a >> b >> c;
	cin >> n >> m;

	ll ans = 0;
	if(n >= a+c and m >= b+c){
		ans = a + b + c;
	}
	else if(n >= a+c and m < b+c){
		ans = m;
	}
	else if(n < a+c and m >= b+c){
		ans = n;
	}
	else{
		ans = min(n, m);
	}

	printf("%lld\n", ans);

	return 0;
}