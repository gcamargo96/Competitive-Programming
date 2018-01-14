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

const int N = 1000002;
string s, t;
stack<char> from;
string res;

void solve(int tam1, int tam2){
	if(tam1 < s.size()){
		from.push(s[tam1]);
		res.pb('i');
		solve(tam1+1, tam2);
		res.pop_back();
		from.pop();
	}

	if(!from.empty() and from.top() == t[tam2]){
		char aux = from.top();
		from.pop();
		res.pb('o');
		solve(tam1, tam2+1);
		from.push(aux);
		res.pop_back();
	}

	if(tam2 == t.size()){
		For(i,0,res.size()){
			cout << res[i];
			if(i < res.size()-1) cout << " ";
		}
		cout << endl;
	}
}

void init(){
	res.clear();
	while(!from.empty()){
		from.pop();
	}
}

int main(void){
	while(cin >> s >> t){
		init();
		cout << "[" << endl;
		solve(0, 0);
		cout << ']' << endl;
	}

	return 0;
}
