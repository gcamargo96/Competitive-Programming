#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

queue<int> esq;
stack<int> dir;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;
	
	For(i,0,s.size()){
		if(s[i] == 'l'){
			dir.push(i+1);
		}
		else{
			esq.push(i+1);
		}
	}

	while(!esq.empty()){
		cout << esq.front() << endl;
		esq.pop();
	}
	while(!dir.empty()){
		cout << dir.top() << endl;
		dir.pop();
	}

	return 0;
}

