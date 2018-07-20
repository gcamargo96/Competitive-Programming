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

ll a, b;

int main(void){
	cin >> a >> b;

	ll x = min(a,b);

	ll ans = 1;
	while(x > 1){
		ans *= x;
		x--;
	}

	cout << ans << endl;

	return 0;
}