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
	ios_base::sync_with_stdio(false);
	cin >> a >> b;

	if(b-a+1 >= 10){
		cout << 0 << endl;
	}
	else{
		ll ans = 1;
		for(ll i = a+1; i <= b; i++){
			ans = (ans * (i%10))%10;
		}
		cout << ans << endl;
	}

	return 0;
}