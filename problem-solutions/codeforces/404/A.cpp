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

int n;
string s;

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;

	ll res = 0;
	For(i,0,n){
		cin >> s;
		if(s == "Tetrahedron"){
			res += 4;
		}
		if(s == "Cube"){
			res += 6;
		}
		if(s == "Octahedron"){
			res += 8;
		}
		if(s == "Dodecahedron"){
			res += 12;
		}
		if(s == "Icosahedron"){
			res += 20;
		}
	}

	cout << res << endl;

	return 0;
}

