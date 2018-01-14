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
#define fastcin ios_base::sync_with_stdio(false)

string s;

int main(void){
	fastcin;
	cin >> s;

	// if(s.size() < 7){
	// 	cout << "no" << endl;
	// 	return 0;
	// }

	int cnt = 0;
	bool ans = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] == '0') cnt++;
		if(cnt >= 6 and s[i] == '1') ans = 1;
	}

	if(ans){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}

	return 0;
}