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
string s;

int main(void){
	cin >> n >> s;

	if(s == "0"){
		cout << s << endl;
		return 0;
	}

	int cnt0 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0')
			cnt0++;
	}

	cout << "1";
	for(int i = 0; i < cnt0; i++){
		cout << "0";
	}
	cout << endl;

	return 0;
}