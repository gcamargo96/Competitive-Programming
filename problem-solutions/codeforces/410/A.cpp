#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;

int main(void){
	cin >> s;

	if(s.size() == 1){
		cout << "YES" << endl;
		return 0;
	}

	int cnt = 0;
	for(int i = 0; i < s.size()/2; i++){
		if(s[i] != s[s.size()-1-i]) cnt++;
	}

	if(cnt == 1){
		cout << "YES" << endl;
	}
	else if(cnt == 0 and s.size()%2 == 1){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}

