#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

string s;

int main(void){
	ios_base::sync_with_stdio(false);
	
	while(cin >> s, s[0] != '#'){
		if(next_permutation(s.begin(), s.end())){
			cout << s << endl;
		}
		else{
			cout << "No Successor" << endl;
		}

	}

	return 0;
}
