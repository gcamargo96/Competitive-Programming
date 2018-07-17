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

int n, p;
string s;

int main(void){
	cin >> n >> p;
	cin >> s;

	bool ok = 0;
	for(int i = 0; i < n-p; i++){
		if(s[i] == '.' and s[i+p] == '.'){
			s[i] = '0';
			s[i+p] = '1';
			ok = 1;
		}
		else if(s[i] == '.'){
			if(s[i+p] == '0') s[i] = '1';
			else s[i] = '0';
			ok = 1;
		}
		else if(s[i+p] == '.'){
			if(s[i] == '0') s[i+p] = '1';
			else s[i+p] = '0';
			ok = 1;
		}
		else if(s[i] != s[i+p]){
			ok = 1;
		}
	}

	for(int i = 0; i < n; i++){
		if(s[i] == '.') s[i] = '0';
	}

	if(ok){
		cout << s << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}