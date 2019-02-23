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

int cnt[30];
int n, k;
string s;

int main(void){
	fastcin;
	cin >> n >> k >> s;

	for(int i = 0; i < n; i++){
		cnt[s[i]-'A']++;
	}

	int mn = 1000000000;
	for(int i = 0; i < k; i++){
		mn = min(mn, cnt[i]);
	}

	ll ans = ll(mn) * ll(k);
	cout << ans << endl;

	return 0;
}