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
int flag = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'h' and flag == 0) flag = 1;
		if(s[i] == 'e' and flag == 1) flag = 2;
		if(s[i] == 'l' and flag == 2){flag = 3; continue; }
		if(s[i] == 'l' and flag == 3) flag = 4;
		if(s[i] == 'o' and flag == 4) flag = 5;
	}

	if(flag == 5) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}

