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

string a, b;

int main(void){
	//cin >> a >> b;
	getline(cin, a);
	//cin.get();
	getline(cin, b);
	//cin.get();
	
	//cout << a << " " << b << endl;
	if(a.size() == 0 or b.size() == 0) cout << 0 << endl;
	else if(a != b) cout << max(a.size(), b.size()) << endl;
	else cout << -1 << endl;

	return 0;
}

