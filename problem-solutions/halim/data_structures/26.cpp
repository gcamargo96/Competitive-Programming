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

priority_queue<ii, vector<ii>, greater<ii> > pq;
string s;
map<int,int> m;

int main(void){
	ios_base::sync_with_stdio(false);

	int id, freq, k;
	while(cin >> s and s != "#"){
		cin >> id >> freq;
		m[id] = freq;
		pq.emplace(freq, id);
	}

	cin >> k;

	For(i,0,k){
		ii a = pq.top();
		pq.pop();
		cout << a.se << endl;
		pq.emplace(a.fi+m[a.se], a.se);
	}

	return 0;
}
