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
char last = 'a'-1;

int main(void){
	cin >> s;

	int n = s.size();
	bool res = 1;
	For(i,0,n){
		if(s[i] > last+1) res = 0;
		if(s[i] == last+1) last++;
	}

	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}

