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

int n;
priority_queue<ii, vector<ii>, greater<ii> > pq;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	char c;
	int x;
	for(int i = 2; i< n; i++){
		cin >> c >> x;

		if(c == 'd'){
			pq.push(ii(x,i));
		}
		else{
			while(pq.size() > x-1){
				pq.pop();
			}
		}
	}

	cin >> c >> x;

	if(pq.size() < x){
		cout << -1 << endl;
		return 0;
	}

	vi v;
	ll res = 0;
	while(!pq.empty()){
		res += pq.top().fi;
		v.pb(pq.top().se);
		pq.pop();
	}

	sort(v.begin(), v.end());

	cout << res << endl;
	cout << v.size() << endl;
	For(i,0,v.size()){
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}

