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

map<ll, ll> m;
ll n, l, r, lv = 0, a , b;

ll query(ll x, ll l, ll r){
	if(l > b or r < a) return 0;
	if(m.count(x) and a <= l and r <= b) return m[x];
	if(l == r){
		//cout << "l = r = " << l << " x = " << x << endl;
		return x;
	}

	ll ret = 0, mid = (l+r)/2;
	if(mid >= a and mid <= b) ret += x%2;
	if((l+r)%2 == 0) mid--;

	ret += query(x/2, l, mid);
	//cout << "mid1 = " << mid << endl;
	if((l+r)%2 == 0) mid++;
	//cout << "mid2  = " << mid << endl;
	ret += query(x/2, mid+1, r);

	//cout << l << " a " << r << " -> m[" << x << "] = " <<  ret << endl;
	
	if(a <= l and r <= b) m[x] = ret;
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> l >> r;

	if(n == 0){
		cout << 0 << endl;
		return 0;
	}

	ll aux = n;
	while(aux >= 0){
		lv++;
		if(aux == 1) break;
		aux /= 2;
	}

	//cout << "lv = " << lv << endl;

	ll R = 1, pot = 1;
	for(ll i = 1; i < lv; i++){
		pot *= 2LL;
		R += pot;
	}

	//cout << R << endl;

	a = l, b = r;
	ll res = query(n, 1, R);

	cout << res << endl;

	return 0;
}

