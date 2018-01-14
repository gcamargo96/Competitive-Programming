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

#define E 0
#define D 1

int n;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> s;

	int p;
	if(n%2 == 0) p = E;
	else p = D;

	string res;
	For(i,0,n){
		if(p == E){
			string aux;
			aux += s[i];
			aux += res;
			res = aux;
		}
		else{ // p == D
			res += s[i];
		}
		p = !p;
	}

	cout << res << endl;

	return 0;
}

