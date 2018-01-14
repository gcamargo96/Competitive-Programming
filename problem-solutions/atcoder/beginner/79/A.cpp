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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;
int cnt[10];

int main(void){
	cin >> s;

	bool ans = 0;
	for(int i = 0; i <= 1; i++){
		bool ok = 1;
		for(int j = i; j < i+2; j++){
			if(s[j] != s[j+1]) ok = 0;
		}
		if(ok) ans = 1;
	}

	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}