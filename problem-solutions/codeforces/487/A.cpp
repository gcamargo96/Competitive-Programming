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

string s;
int n;
set<char> m;

int main(void){
	cin >> s;
	n = s.size();
	s = "#" + s + "#";

	if(n < 3){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i = 2; i <= n-1; i++){
		m.clear();
		if(s[i-1] != '.') m.insert(s[i-1]);
		if(s[i] != '.') m.insert(s[i]);
		if(s[i+1] != '.') m.insert(s[i+1]);

		if(m.size() == 3){
			// cout << "i = " << i << endl;
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}