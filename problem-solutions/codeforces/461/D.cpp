#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

const int N = 100002;
int n;
string s[N];

bool cmp(const string& a, const string& b){
	string x = a+b;
	string y = b+a;

	ll cx = 0;
	ll cs = 0;
	for(int i = 0; i < x.size(); i++){
		if(x[i] == 'h')
			cx += cs;
		if(x[i] == 's')
			cs++;
	}

	ll cy = 0;
	cs = 0;
	for(int i = 0; i < y.size(); i++){
		if(y[i] == 'h')
			cy += cs;
		if(y[i] == 's')
			cs++;
	}

	return cx > cy;
}

int main(void){
	fastcin;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	sort(s, s+n, cmp);

	ll ans = 0, cs = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s[i].size(); j++){
			if(s[i][j] == 'h')
				ans += cs;
			if(s[i][j] == 's')
				cs++; 
		}
	}

	cout << ans << endl;

	return 0;
}