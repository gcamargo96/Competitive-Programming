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

map<char,int> peso, cnt;
char g[11][11];

int main(void){
	ios_base::sync_with_stdio(false);

	peso['Q'] = 9;
	peso['R'] = 5;
	peso['B'] = 3;
	peso['N'] = 3;
	peso['P'] = 1;
	peso['K'] = 0;


	peso['q'] = 9;
	peso['r'] = 5;
	peso['b'] = 3;
	peso['n'] = 3;
	peso['p'] = 1;
	peso['k'] = 0;

	char c;
	for(int i = 1; i <= 8; i++){
		for(int j = 1; j <= 8; j++){
			cin >> c;
			if(c != '.') cnt[c]++;
		}
	}

	int white = 0, black = 0;
	for(auto it = cnt.begin(); it != cnt.end(); it++){
		if(it->fi >= 'a' and it->fi <= 'z')
			black += it->se * peso[it->fi];
		else
			white += it->se * peso[it->fi];

	}

	if(white > black){
		cout << "White" << endl;
	}
	else if(white < black){
		cout << "Black" << endl;
	}
	else{
		cout << "Draw" << endl;
	}

	return 0;
}

