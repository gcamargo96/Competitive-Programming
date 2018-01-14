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

int n;
int v[100002];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> v[i];
	}

	int i = 0, res = 0, cnt = 0, ant = -1;
	while(i < n){
		while(i < n and v[i] > ant){
			cnt++;
			ant = v[i];
			i++;
		}
		res = max(res, cnt);
		cnt = 0;
		ant = -1;
	}

	cout << res << endl;

	return 0;
}
