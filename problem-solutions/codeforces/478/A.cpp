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

int n;
set<string> SET;

int main(void){
	fastcin;
	cin >> n;

	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		
		sort(s.begin(), s.end());

		s.resize(unique(s.begin(), s.end()) - s.begin());
		// cout << s << endl;

		SET.insert(s);
	}

	cout << SET.size() << endl;

	return 0;
}