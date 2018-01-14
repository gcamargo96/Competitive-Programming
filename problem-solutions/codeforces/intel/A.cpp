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

int n;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	if(n == 24){
		if(s[0] > '2') s[0] = '0';
		else if(s[0] == '2' and s[1] > '3'){
			s[1] = '0';
		}
	}
	if(n == 12){
		if(s[0] == '0' and s[1] == '0') s[1] = '1';
		if(s[0] > '1'){
			if(s[1] <= '2') s[0] = '1';
			else s[0] = '0';
		}
		if(s[0] == '1' and s[1] > '2') s[1] = '1';
	}

	if(s[3] > '5') s[3] = '0';

	cout << s << endl;

	return 0;
}
