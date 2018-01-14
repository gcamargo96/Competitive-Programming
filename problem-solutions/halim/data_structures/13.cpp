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

	while(getline(cin, s)){
		list<char> res;

		auto pos = res.begin();
		For(i,0,s.size()){
			if(s[i] == '['){
				pos = res.begin();
			}
			else if(s[i] == ']'){
				pos = res.end();
			}
			else{
				res.insert(pos, s[i]);
			}
		}
		
		for(auto it = res.begin(); it != res.end(); it++){
			cout << *it;
		}
		cout << endl;
	}

	return 0;
}
