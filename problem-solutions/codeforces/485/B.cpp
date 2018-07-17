#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll x, y;

int main(void){
	cin >> x >> y;

	if(x == y){
		cout << "=" << endl;
		return 0;
	}

	if(x >= 3 and y >= 3){
		if(x > y){
			cout << "<" << endl;
		}
		else{
			cout << ">" << endl;
		}
	}
	else{
		if(x == 1){
			cout << "<" << endl;
		}
		else if(y == 1){
			cout << ">" << endl;
		}
		else if(x == 2){
			if(y == 3)
				cout << "<" << endl;
			else if(y == 4)
				cout << "=" << endl;
			else
				cout << ">" << endl;
		}
		else if(y == 2){
			if(x == 3)
				cout << ">" << endl;
			else if(x == 4)
				cout << "=" << endl;
			else
				cout << "<" << endl;
		}
	}

	return 0;
}