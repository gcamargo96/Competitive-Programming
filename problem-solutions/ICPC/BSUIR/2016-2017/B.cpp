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

ll a, b;

int main(void){
	scanf("%lld%lld", &a, &b);

	ll den = (1LL << b);

	string ans;
	while(den > 1){
		if(2LL*a <= den){
			den /= 2;
			ans += "0";
		}
		else{
			a = den-a;
			ans += "1";
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;

	return 0;
}