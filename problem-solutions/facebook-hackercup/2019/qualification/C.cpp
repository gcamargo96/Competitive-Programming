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

int t;
string s;

char operation(char a, char op, char b){
	if(a > b) swap(a,b);
	if(a == 'X' and b == 'x') swap(a,b);

	char ret;
	if(op == '&'){
		if(a == '0'){
			ret = '0';
		}
		if(a == '1'){
			if(b == '1') ret = '1';
			if(b == 'x') ret = 'x';
			if(b == 'X') ret = 'X';
		}
		if(a == 'x'){
			if(b == 'x') ret = 'x';
			if(b == 'X') ret = '0';
		}
		if(a == 'X'){
			ret = 'X';
		}
	}
	if(op == '|'){
		if(a == '0'){
			if(b == '0') ret = '0';
			if(b == '1') ret = '1';
			if(b == 'x') ret = 'x';
			if(b == 'X') ret = 'X';
		}
		if(a == '1'){
			ret = '1';
		}
		if(a == 'x'){
			if(b == 'x') ret = 'x';
			if(b == 'X') ret = '1';
		}
		if(a == 'X'){
			ret = 'X';
		}
	}
	if(op == '^'){
		if(a == '0'){
			if(b == '0') ret = '0';
			if(b == '1') ret = '1';
			if(b == 'x') ret = 'x';
			if(b == 'X') ret = 'X';
		}
		if(a == '1'){
			if(b == '1') ret = '0';
			if(b == 'x') ret = 'X';
			if(b == 'X') ret = 'x';
		}
		if(a == 'x'){
			if(b == 'x') ret = '0';
			if(b == 'X') ret = '1';
		}
		if(a == 'X'){
			ret = '0';
		}
	}

	return ret;
}

char solve(){
	stack<char> p;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') continue;
		if(s[i] == ')'){
			char b = p.top(); p.pop();
			char op = p.top(); p.pop();
			char a = p.top(); p.pop();

			p.push(operation(a, op, b));
		}
		else{
			p.push(s[i]);
		}
	}

	return p.top();
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> s;

		if(s.size() == 1){
			cout << "Case #" << caso << ": ";
			if(s[0] == '0' or s[0] == '1'){
				cout << 0 << endl;
			}
			else{
				cout << 1 << endl;
			}
			continue;
		}

		char ans = solve();
	
		cout << "Case #" << caso << ": ";
		if(ans == '0' or ans == '1'){
			cout << 0 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}

	return 0;
}