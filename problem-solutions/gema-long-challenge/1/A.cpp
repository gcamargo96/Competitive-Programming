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

const int N = 200005;
string s, t, sr;
int m;
int p[N], pref[N], suf[N];

void init(){
	memset(p, 0, sizeof p);
	memset(pref, 0, sizeof pref);
	memset(suf, 0, sizeof suf);
}

// prefix function will be 1-based
void prefix_function(string& s){
	int n = s.size();
	for(int i = 2; i <= n; i++){
		p[i] = p[i-1];
		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}
}

int main(void){
	fastcin;
	cin >> s;
	cin >> m;

	sr = s;
	reverse(sr.begin(), sr.end());

	int ans = 0;
	while(m--){
		init();

		cin >> t;

		if(t.size() == 1)
			continue;

		string aux = t + "#" + s;
		memset(p, 0, sizeof p);
		prefix_function(aux);

		for(int i = 1; i <= s.size(); i++){
			// cout << p[i+t.size()+1] << " ";
			pref[i] = max(pref[i-1], p[i+t.size()+1]);
		}
		// cout << endl;

		reverse(t.begin(), t.end());
		aux = t + "#" + sr;
		memset(p, 0, sizeof p);
		prefix_function(aux);

		for(int i = 1; i <= s.size(); i++){
			suf[i] = max(suf[i-1], p[i+t.size()+1]);
		}

		reverse(suf+1, suf+s.size()+1);

		for(int i = 1; i < s.size(); i++){
			if(pref[i] + suf[i+1] >= t.size()){
				ans++;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}