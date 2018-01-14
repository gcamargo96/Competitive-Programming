#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string x, y, z;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> x >> y;

	For(i,0,x.size()){
		if(x[i] < y[i]){
			cout << -1 << endl;
			return 0;
		}
	}

	cout << y << endl;

	return 0;
}

