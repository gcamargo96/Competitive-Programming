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

string s;
map<char,int> cnt;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;
	
	For(i,0,s.size()){
		cnt[s[i]]++;
	}

	vi v;
	v.pb(cnt['B']);
	v.pb(cnt['u']/2);
	v.pb(cnt['l']);
	v.pb(cnt['b']);
	v.pb(cnt['a']/2);
	v.pb(cnt['s']);
	v.pb(cnt['r']);

	int res = INF;
	For(i,0,v.size()){
		res = min(res, v[i]);
	}

	cout << res << endl;

	return 0;
}

