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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;

bool palindrome(string& s, int i, int j){
	for(int l = i, r = j; l < r; l++, r--){
		if(s[l] != s[r]) return 0;
	}
	return 1;
}

int main(void){
	fastcin;
	cin >> s;

	bool dif = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] != s[i-1]) dif = 1;
	}

	if(!dif){
		printf("Impossible\n");
		return 0;
	}

	string t = s+s;
	for(int i = 0; i < s.size(); i++){
		// cout << t.substr(i, s.size()) << endl;
		if(t.substr(i, s.size()) != s and palindrome(t, i, i+s.size()-1)){
			printf("1\n");
			return 0;
		}
	}

	printf("2\n");

	return 0;
}