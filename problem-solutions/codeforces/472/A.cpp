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

int n;
string s;

int main(void){
	fastcin;
	cin >> n >> s;
	s = "#" + s;

	bool ok = 0;
	for(int i = 2; i <= n-1; i++){
		if(s[i] == '?' and s[i+1] == '?')
			ok = 1;
		if(s[i] == '?' and s[i-1] == s[i+1])
			ok = 1;
	}

	if(s[1] == '?' or s[n] == '?')
		ok = 1;

	for(int i = 1; i <= n-1; i++){
		if(s[i] == s[i+1] and s[i] != '?')
			ok = 0;
	}

	if(ok){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}