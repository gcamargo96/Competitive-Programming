#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

string s;
set<string> tem;
int res = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	For(i,0,s.size()){
		string t;
		for(int cnt = 0; cnt < s.size(); cnt++){
			t += s[(i+cnt)%s.size()];
		}
		if(!tem.count(t)) res++;
		tem.insert(t);
	}

	cout << res << endl;

	return 0;
}

