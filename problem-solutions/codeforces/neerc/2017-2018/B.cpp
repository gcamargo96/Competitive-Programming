#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 300;
string s;
bool pos[N], neg[N];

ll POW(ll b, ll e){
	ll ret = 1;
	for(int i = 0; i < e; i++){
		ret *= b;
	}
	return ret;
}

int main(void){
	freopen("boolean.in", "r", stdin);
	freopen("boolean.out", "w", stdout);

	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '|'){
			continue;
		}
		else if(s[i] == '~'){
			neg[s[i+1]] = 1;
			i++;
		}
		else{
			pos[s[i]] = 1;
		}
	}

	bool flag = 0;
	ll cnt = 0;
	for(int i = 0; i < N; i++){
		if(pos[i] or neg[i]){
			cnt++;
		}
		if(pos[i] and neg[i]){
			flag = 1;
		}
	}

	ll ans = POW(2, cnt);
	if(!flag) ans--;

	cout << ans << endl;

	return 0;
}