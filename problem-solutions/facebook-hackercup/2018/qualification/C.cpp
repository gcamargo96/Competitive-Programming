#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int t;
string a;

bool ethan(string& b){
	int i = 0, j = 0;
	while(1){
		// cout << i << " " << j << endl;
		if(i >= a.size()) return true;
		if(j >= b.size()) return false;
		if(a[i] == b[j]){
			i++;
			j++;
			continue;
		}
		if(i == 0){
			j++;
			continue;
		}
		i = 0;
	}
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> a;

		int id = -1;
		for(int i = 1; i < int(a.size())-1; i++){
			if(a[i] == a[0]){
				id = i;
				break;
			}
		}

		if(id == -1){
			cout << "Case #" << caso << ": Impossible" << endl;
			continue;
		}

		string b;
		for(int i = 0; i <= id; i++){
			b += a[i];
		}
		for(int i = 1; i < a.size(); i++){
			b += a[i];
		}

		if(ethan(b) == false){
			cout << "Case #" << caso << ": " << b << endl;
		}
		else{
			cout << "Case #" << caso << ": Impossible" << endl;
		}
	}

	return 0;
}