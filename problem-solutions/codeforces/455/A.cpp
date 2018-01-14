#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s, t;

int main(void){
	fastcin;
	cin >> s >> t;

	vector<string> v;
	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= t.size(); j++){
			v.pb(s.substr(0,i) + t.substr(0,j));
		}
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}

	cout << v[0] << endl;

	return 0;
}