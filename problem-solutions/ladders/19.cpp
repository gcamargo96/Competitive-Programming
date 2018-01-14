#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	For(i,0,s.size()){
		char c = s[i];
		if(c >= 'a' and c <= 'z' and c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u' and c != 'y'){
			cout << "." << c;
		}
		if(c >= 'A' and c <= 'Z' and c != 'A' and c != 'E' and c != 'I' and c != 'O' and c != 'U' and c != 'Y'){
			cout << "." << (char)(c-'A'+'a');
		}
	}
	cout << endl;

	return 0;
}

