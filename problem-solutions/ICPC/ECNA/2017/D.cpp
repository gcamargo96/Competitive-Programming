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

int n, k;

int sum(int a, int b){
	return ((a+b)%n + n)%n;
}


int main(void){
	fastcin;
	cin >> n >> k;

	int pos = 0;
	stack<int> p;
	string op;
	for(int i = 0; i < k; i++){
		cin >> op;

		if(op != "undo"){
			int x = stoi(op);
			x %= n;
			pos = sum(pos, x);
			p.push(x);
		}
		else{
			int x;
			cin >> x;
			
			while(x--){
				pos = sum(pos, -p.top());
				p.pop();
			}
		}
	}

	cout << pos << endl;

	return 0;
}