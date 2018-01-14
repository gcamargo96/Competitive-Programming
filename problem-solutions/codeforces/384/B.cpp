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

ll n, k;
vector<ll> powers;

ll POW(ll b, ll e){
	ll x = 1;
	For(i,0,e){
		x *= b;
	}
	return x;
}

void init(){
	For(i,0,51){
		powers.pb(POW(2,i));
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	init();
	cin >> n >> k;

	For(i,0,51){
		if(powers[i] == k){
			cout << i+1 << endl;
			return 0;
		}
	}

	For(i,0,51){
		ll beg = powers[i];
		if((k-beg)%powers[i+1] == 0){
			cout << i+1 << endl;
			return 0;
			}
	}

	return 0;
}

