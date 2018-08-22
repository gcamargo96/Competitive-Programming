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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n, m;

int main(void){
	fastcin;
	cin >> n >> m;

	ll x;
	ll cur = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		cur += x;
		ll cicles = cur/m;
		cout << cicles << " ";
		cur %= m;
	}

	cout << endl;

	return 0;
}