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

#define MOD 1000000007

const int N = 200002;
string s;
ll sum1[N], sum2[N];
ll fat[N];

void precalc(){
	fat[0] = 1;
	for(ll i = 1; i < N; i++){
		fat[i] = (fat[i-1]*i)%MOD;
	}
}

ll fast_pow(ll b, ll e){
	if(e == 0) return 1LL;

	ll x = fast_pow(b, e/2LL);
	if(e%2 == 0) return (x*x)%MOD;
	else return ((b * x)%MOD * x)%MOD;
}

int main(void){
	ios_base::sync_with_stdio(false);
	precalc();
	cin >> s;
	s = "#" + s;

	for(int i = 1; i < s.size(); i++){
		sum1[i] = sum1[i-1];
		if(s[i] == '(') sum1[i]++;
	}

	for(int i = s.size()-1; i >= 1; i--){
		sum2[i] = sum2[i+1];
		if(s[i] == ')') sum2[i]++;
	}

	ll res = 0;
	for(int i = 1; i <= s.size(); i++){
		if(s[i] == '('){
			ll x = sum1[i];
			ll y = sum2[i+1];
			res = (res + (fat[x+y-1] * fast_pow((fat[x]*fat[y-1])%MOD, MOD-2)%MOD )%MOD )%MOD;
		}
	}

	cout << res << endl;

	return 0;
}

