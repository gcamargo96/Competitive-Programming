#include <bits/stdc++.h>
using namespace std;
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

string s;

int main(void){
	fastcin;
	cin >> s;

	char c = 'a';
	for(int i = 0; i < s.size() and c <= 'z'; i++){
		if(s[i] <= c){
			s[i] = c;
			c++;
		}
	}

	if(c > 'z'){
		cout << s << endl;
	}
	else{
		cout << -1 << endl;
	}

	return 0;
}