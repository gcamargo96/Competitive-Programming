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

#define N "North"
#define S "South"
#define O "West"
#define L "East"

int n, t;
string dir;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	int y = 20000;
	bool ok = 1;
	For(i,0,n){
		cin >> t >> dir;

		if(y == 20000 and dir != S) ok = 0;
		if(y == 0 and dir != N) ok = 0;

		if(dir == S) y -= t;
		if(dir == N) y += t;
	
		if(y < 0 or y > 20000) ok = 0;
	}

	if(y == 20000 and ok == 1){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
	return 0;
}

