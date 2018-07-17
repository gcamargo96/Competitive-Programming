#include <bits/stdc++.h>
using namespace std;
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

string s;
int n;

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	vector<ii> v;

	for(int i = 0; i < n;){
		int cnt = 0;
		while(i < n and s[i] == '0'){
			cnt++;
			i++;
		}
		if(cnt > 0){
			v.pb(mp(0, cnt));
		}

		cnt = 0;
		while(i < n and s[i] == '1'){
			cnt++;
			i++;
		}
		if(cnt > 0){
			v.pb(mp(1, cnt));
		}

		cnt = 0;
		while(i < n and s[i] == '2'){
			cnt++;
			i++;
		}
		if(cnt > 0){
			v.pb(mp(2, cnt));
		}
	}

	int m = v.size();
	for(int i = 0; i < m-1; i++){
		if(v[i].fi == 2 and v[i+1].fi == 1){
			swap(v[i], v[i+1]);
		}
	}

	for(int i = 0; i < m-1; i++){
		if(v[i].fi == 1 and v[i+1].fi == 0){
			swap(v[i], v[i+1]);
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < v[i].se; j++){
			printf("%d", v[i].fi);
		}
	}
	printf("\n");

	return 0;
}