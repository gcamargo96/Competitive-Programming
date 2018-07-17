#include <bits/stdc++.h>
using namespace std;
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

string s;
set<char> vw;

int main(void){
	vw.insert('a');
	vw.insert('e');
	vw.insert('i');
	vw.insert('o');
	vw.insert('u');

	cin >> s;
	int len = s.size();

	if(s[len-1] != 'n' and !vw.count(s[len-1])){
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < len-1; i++){
		if(s[i] != 'n' and !vw.count(s[i]) and !vw.count(s[i+1])){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}