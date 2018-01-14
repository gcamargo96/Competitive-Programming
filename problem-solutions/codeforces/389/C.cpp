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

#define NADA -1
#define L 0
#define R 1
#define D 2
#define U 3

int n;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	
	int x = 0, y = 0;
	int ver = NADA, hor = NADA;

	int res = 0;
	For(i,0,n){
		if(s[i] == 'L'){
			if(hor == R){
				res++;
				ver = NADA;
			}	
			hor = L;
		}
		else if(s[i] == 'R'){
			if(hor == L){
				res++;
				ver = NADA;
			}
			hor = R;
		}
		else if(s[i] == 'D'){
			if(ver == U){
				res++;
				hor = NADA;
			}
			ver = D;
		}
		else if(s[i] == 'U'){
			if(ver == D){
				res++;
				hor = NADA;
			}
			ver = U;
		}
	}
	res++;

	cout << res << endl;

	return 0;
}

