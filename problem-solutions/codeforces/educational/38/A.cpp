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

	set<char> vowel;
	vowel.insert('a');
	vowel.insert('e');
	vowel.insert('i');
	vowel.insert('o');
	vowel.insert('u');
	vowel.insert('y');
	
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < int(s.size())-1; j++){
			if(vowel.count(s[j]) and vowel.count(s[j+1])){
				s.erase(j+1, 1);
				break;
			}
		}
	}

	// for(int i = 0; i < int(s.size())-1; i++){
	// 	if(vowel.count(s[i]) and vowel.count(s[i+1])){
	// 		cout << "apagou " << i+1 << " " << s[i+1] << endl;
	// 		s.erase(i+1, 1);
	// 	}
	// }

	cout << s << endl;

	return 0;
}