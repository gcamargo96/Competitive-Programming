#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int p[N], n;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> p[i];
	}

	cin.get();

	bool ok = 1;
	For(i,0,n){
		getline(cin, s);
		int cnt = 0;
		For(j,0,s.size()){
			if(s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u' or s[j] == 'y'){
				cnt++;
			}
		}
		if(cnt != p[i]){
			ok = 0;
		}
	}

	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}

