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

string s, t;
set<char> vow;

int main(void){
	fastcin;
	cin >> s >> t;

	if(s.size() != t.size()){
		cout << "No" << endl;
		return 0;
	}

	vow.insert('a');
	vow.insert('e');
	vow.insert('i');
	vow.insert('o');
	vow.insert('u');

	for(int i = 0; i < s.size(); i++){
		if((vow.count(s[i]) and !vow.count(t[i])) or (!vow.count(s[i]) and vow.count(t[i]))){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}