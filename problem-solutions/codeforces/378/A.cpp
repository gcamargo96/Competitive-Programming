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

string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;	

	int cnt = 1, res = 0;
	For(i,0,s.size()){
		if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or s[i] == 'Y'){
			res = max(res, cnt);
			cnt = 0;
		}
		cnt++;
	}
	res = max(res, cnt);

	cout << res << endl;

	return 0;
}

