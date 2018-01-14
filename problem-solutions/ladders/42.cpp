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

#define MOD 1000000007

const int N = 102;
int n, m;
string s;
set<char> dic[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	For(i,0,n){
		cin >> s;
		For(i,0,m){
			dic[i].insert(s[i]);
		}
	}

	ll res = 1;
	For(i,0,m){
		res = (res * dic[i].size())%MOD;
	}

	cout << res << endl;

	return 0;
}

