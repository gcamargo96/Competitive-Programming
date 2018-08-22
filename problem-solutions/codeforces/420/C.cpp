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

int n;
stack<int> p;
priority_queue<int, vi, greater<int> > pq;

int main(void){
	fastcin;
	cin >> n;

	string op;
	int x, nxt = 1, ans = 0;
	for(int i = 0; i < 2*n; i++){
		cin >> op;
		
		if(op == "add"){
			cin >> x;
			p.push(x);
		}
		else{
			if(!p.empty() and p.top() == nxt){
				// cout << "pop" << endl;
				p.pop();
			}
			else{
				// cout << "i = " << i << endl;
				if(!p.empty()) ans++;
				while(!p.empty()){
					pq.push(p.top());
					p.pop();
				}
				pq.pop();
			}
			nxt++;
		}
	}

	cout << ans << endl;

	return 0;
}