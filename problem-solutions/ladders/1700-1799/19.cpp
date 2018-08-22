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

stack<int> p;
string s;
int tags = 0, last = -1;

int main(void){
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '#'){
			tags++;
			last = i;
		}
	}

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			p.push(i);
		}
		else if(s[i] == ')' or s[i] == '#'){
			if(p.empty()){
				cout << -1 << endl;
				return 0;
			}
			else{
				p.pop();
			}
		}
	}

	if(!p.empty() and p.top() > last){
		cout << -1 << endl;
		return 0;
	}

	int extra = 0;
	if(!p.empty() and p.top() < last){
		extra = p.size();
	}

	for(int i = 0; i < tags-1; i++){
		cout << 1 << endl;
	}
	cout << (1+extra) << endl;

	return 0;
}