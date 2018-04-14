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

int n;
string s;

int main(void){
	fastcin;
	cin >> n >> s;

	int maxjump = 1;
	for(int i = 0; i < n; i++){
		int j = 0;
		for( ; j < i and i+j < n and s[j] == s[i+j]; j++){
			//
		}
		if(j == i)
			maxjump = max(maxjump, j);
	}

	// cout << maxjump << endl;
	cout << n-maxjump+1 << endl;

	return 0;
}