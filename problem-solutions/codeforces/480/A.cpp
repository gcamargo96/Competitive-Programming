#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int l, p;
string s;

int main(void){
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '-') l++;
		else p++;
	}

	if(p == 0){
		cout << "YES" << endl;
		return 0;
	}

	if(l%p == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}