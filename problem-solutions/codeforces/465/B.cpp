#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define TOP 0
#define BOT 1

int n;
string s;

int main(void){
	fastcin;
	cin >> n >> s;

	int x = 0, y = 0;
	int side;
	if(s[0] == 'U'){
		side = TOP;
		y++;
	}
	else{
		side = BOT;
		x++;
	}

	int ans = 0;
	for(int i = 1; i < n; i++){
		char c = s[i];
		if(c == 'U'){
			if(x == y and side == BOT){
				ans++;
				side = TOP;
			}
			y++;
		}
		else{ // R
			if(x == y and side == TOP){
				ans++;
				side = BOT;
			}
			x++;
		}
	}

	cout << ans << endl;

	return 0;
}