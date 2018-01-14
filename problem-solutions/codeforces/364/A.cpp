#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define enld "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

ii v[102];

int main(void){
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> v[i].fi;
		v[i].se = i+1;
	}

	sort(v,v+n);

	For(i,0,n/2){
		cout << v[i].se << " " << v[n-i-1].se << endl;
	}

	return 0;
}
