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

const int N = 1002;
string s[N];
int n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n) cin >> s[i];
	
	bool ok = 0;
	For(i,0,n){
		if(s[i][0] == 'O' and s[i][1] == 'O'){
			ok = 1;
			s[i][0] = s[i][1] = '+';
			break;
		}
		else if(s[i][3] == 'O' and s[i][4] == 'O'){
			ok = 1;
			s[i][3] = s[i][4] = '+';
			break;
		}
	}

	if(ok){
		cout << "YES" << endl;
		For(i,0,n) cout << s[i] << endl;
	}
	else cout << "NO" << endl;


	return 0;
}
