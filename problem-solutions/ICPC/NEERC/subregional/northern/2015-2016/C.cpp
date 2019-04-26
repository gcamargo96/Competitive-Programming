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

string a, b;
ll cnt[30];

int main(void){
	fastcin;

	freopen("concatenation.in", "r", stdin);
	freopen("concatenation.out", "w", stdout);

	cin >> a >> b;
	ll la = a.size(), lb = b.size();

	for(int i = 1; i < la; i++){
		cnt[a[i]-'a']++;
	}

	ll ans = la*lb;
	for(int i = 0; i < lb-1; i++){
		ans -= cnt[b[i]-'a'];
	}

	cout << ans << endl;

	return 0;
}