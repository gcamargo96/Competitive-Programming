#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

struct event{
	int aud, sub, id;
	bool operator<(const event &b) const{
		if(aud == b.aud){
			return sub < b.sub;
		}
		return aud < b.aud;
	}
};

const int N = 200005;
map<int,int> cnt;
event movies[N];
int n, m;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;
	}

	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a;
		movies[i].aud = cnt[a];
	}
	for(int i = 0; i < m; i++){
		cin >> a;
		movies[i].sub = cnt[a];
		movies[i].id = i+1;
	}

	/*for(int i = 0; i < m; i++){
		cout << "aud " << movies[i].aud << endl;
		cout << "sub " << movies[i].sub << endl;
		cout << "id " << movies[i].id << endl << endl;
	}*/

	sort(movies, movies+m);

	/*for(int i = 0; i < m; i++){
		cout << "aud " << movies[i].aud << endl;
		cout << "sub " << movies[i].sub << endl;
		cout << "id " << movies[i].id << endl << endl;
	}*/
	cout << movies[m-1].id << endl;

	return 0;
}
