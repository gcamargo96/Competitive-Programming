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

int n;
string s;

void no(){
	printf(":(\n");
	exit(0);
}

int main(void){
	fastcin;
	cin >> n >> s;

	if(n%2 == 1){
		no();
	}

	int cntOpen = n/2, cntClose = n/2;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			cntOpen--;
		if(s[i] == ')')
			cntClose--;
	}

	if(cntOpen < 0 or cntClose < 0){
		no();
	}

	stack<char> p;
	// string ans(s);

	for(int i = 0; i < n-1; i++){
		if(s[i] == '('){
			p.push('(');
		}
		if(s[i] == ')'){
			if(!p.empty()){
				p.pop();
			
				if(p.empty()){
					no();
				}
			}
			else{
				no();
			}
		}
		if(s[i] == '?'){
			if(cntOpen > 0){
				s[i] = '(';
				p.push('(');
				cntOpen--;
			}
			else if(!p.empty()){
				s[i] = ')';
				p.pop();
				cntClose--;

				if(p.empty()){
					no();
				}
			}
			else{
				no();
			}
		}
	}

	if(s[n-1] == ')' or (s[n-1] == '?' and cntClose == 1)){
		s[n-1] = ')';
		cout << s << endl;
	}
	else{
		no();
	}


	return 0;
}