#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n;
int v[102];

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	int x;
	For(i, 1, n+1){
		cin >> x;
		v[x] = i;
	}

	For(i, 1, n+1){
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
