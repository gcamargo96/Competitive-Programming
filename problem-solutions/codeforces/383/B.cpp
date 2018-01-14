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

const int N = 100002;
ll n, x;
ll v[N];
map<int,int> m;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> x;

	For(i,0,n){
		cin >> v[i];
		m[v[i]]++;
	}

	ll res = 0;
	For(i,0,n){
		ll xo = v[i]^x;
		if(xo == v[i]) res += m[v[i]]-1;
		else res += m[xo];
	}

	res /= 2;

	cout << res << endl;

	return 0;
}

