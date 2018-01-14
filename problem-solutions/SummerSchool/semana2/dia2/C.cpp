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
int p[2*N];
string s, t, rev;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	rev = t;
	reverse(rev.begin(), rev.end());
	s = t + '#' + rev;

	for(int i = 2; i <= s.size(); i++){
		p[i] = p[i-1];
		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}

	int res = 0;
	for(int i = t.size()+1; i <= s.size(); i++){
		//cout << p[i] << " ";
		res = max(res, p[i]);
	}

	cout << res << endl;

	return 0;
}

