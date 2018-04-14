#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 1000002;
int n;
map<string, ll> cnt;

int main(void){
	fastcin;
	cin >> n;

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;

		string t;
		map<char, char> m;
		for(int j = 0; j < s.size(); j++){
			if(m.count(s[j])){
				t += m[s[j]];
			}
			else{
				int tam = m.size();
				t += tam + 'a';
				m[s[j]] = tam + 'a';
			}
		}

		cnt[t]++;
	}

	ll ans = 0;
	for(auto it : cnt){
		// cout << it.fi << endl;
		ans += (it.se * (it.se-1))/2LL;
	}

	cout << ans << endl;

	return 0;
}