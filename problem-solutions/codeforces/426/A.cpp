#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

char s, e;
int n;

map<char,int> m;

int main(void){
	m['v'] = 0;
	m['<'] = 1;
	m['^'] = 2;
	m['>'] = 3;

	cin >> s >> e >> n;
	
	n %= 4;

	if(n == 0){
		cout << "undefined" << endl;
		return 0;
	}


	int cw = 0, ccw = 0;
	if(m[s] < m[e]){
		cw = m[e] - m[s];
		ccw = 4 - cw;
	}
	else{
		ccw = m[s] - m[e];
		cw = 4 - ccw;
	}

	if(cw == n and ccw == n){
		cout << "undefined" << endl;
	}
	else if(cw == n){
		cout << "cw" << endl;
	}
	else{
		cout << "ccw" << endl;
	}

	return 0;
}