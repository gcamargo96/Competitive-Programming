#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 200002;
string s;
int q;
ll k, p, g, m;

int main(void){
	fastcin;
	cin >> s >> q;

	vector<string> v;
	for(int i = 0; i < s.size(); i++){
		for(int j = 1; i+j <= s.size(); j++){
			v.pb(s.substr(i,j));
		}
	}

	sort(v.begin(), v.end());
	s.clear();
	for(int i = 0; i < v.size(); i++){
		s += v[i];
	}

	// cout << s << endl;

	while(q--){
		cin >> p >> m;
		k = (p*g)%m;
		cout << s[k] << endl;
		g += s[k];
	}

	return 0;
}