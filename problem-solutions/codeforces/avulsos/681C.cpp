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

#define INSERT 0
#define GET 1
#define REMOVE 2

int n;
priority_queue<int, vector<int>, greater<int> > pq;
vector<ii> ans;

int main(void){
	fastcin;
	cin >> n;

	string s; int x;
	for(int i = 0; i < n; i++){
		cin >> s;

		if(s[0] == 'i'){
			cin >> x;
			pq.push(x);
			ans.eb(INSERT, x);
		}
		if(s[0] == 'g'){
			cin >> x;

			if(pq.empty()){
				pq.push(x);
				ans.eb(INSERT, x);
			}

			while(!pq.empty() and pq.top() < x){
				pq.pop();
				ans.eb(REMOVE, 0);
			}

			if(pq.empty() or pq.top() > x){
				pq.push(x);
				ans.eb(INSERT, x);
			}

			ans.eb(GET, x);
		}
		if(s[0] == 'r'){
			if(pq.empty()){
				pq.push(1);
				ans.eb(INSERT, 1);
			}

			pq.pop();
			ans.eb(REMOVE, 0);			
		}
	}

	cout << ans.size() << endl;

	for(int i = 0; i < ans.size(); i++){
		if(ans[i].fi == INSERT){
			cout << "insert " << ans[i].se << endl;
		}
		if(ans[i].fi == GET){
			cout << "getMin " << ans[i].se << endl;
		}
		if(ans[i].fi == REMOVE){
			cout << "removeMin" << endl;
		}
	}

	return 0;
}