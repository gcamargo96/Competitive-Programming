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

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	bool foi = 0;
	For(i,0,s.size()){
		if(!foi and s[i] == '0'){
			foi = 1;
			continue;
		}
		else if(i < s.size()-1){
			cout << s[i];
		}
		else if(foi) cout << s[i];
	}
	cout << endl;

	return 0;
}

