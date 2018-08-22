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

const int N = 200005;
string s;
int n, q;
stack<int> p;
int last[30], nxt[N][30];

int main(void){
	fastcin;
	cin >> s >> q;
	s = '#' + s;
	n = s.size();

	for(int i = 0; i < 26; i++){
		last[i] = n;
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			nxt[i][j] = last[j];
		}
		if(i > 0) last[s[i]-'a'] = i;
	}

	// for(int i = 0; i < 3; i++){
	// 	for(int j = 0; j < n; j++){
	// 		printf("%d ", nxt[j][i]);
	// 	}
	// 	printf("\n");
	// }

	string op;
	char c;
	while(q--){
		cin >> op;

		if(op == "push"){
			cin >> c;

			if(p.empty()){
				p.push(nxt[0][c-'a']);
			}
			else if(p.top() < n){
				p.push(nxt[p.top()][c-'a']);
			}
			else{
				p.push(n);
			}
		}
		else{
			p.pop();
		}

		// if(p.empty()) cout << "vazio ";
		// else cout << p.top() << " ";

		if(p.empty() or p.top() < n){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}