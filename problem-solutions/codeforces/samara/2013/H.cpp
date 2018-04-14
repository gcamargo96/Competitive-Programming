#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

int n;
string s, t;

int main(void){
	cin >> n >> s >> t;

	bool dif = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			dif = 1;
		}
		else if(dif == 1){
			ans++;
			dif = 0;
		}
	}
	if(dif == 1){
		ans++;
	}

	cout << ans << endl;

	return 0;
}