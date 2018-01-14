#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 100002;
int n;
int v[N];

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	For(i, 0, n){
		cin >> v[i];
	}

	sort(v, v+n);
	if(v[n-1] != 1) v[n-1] = 1;
	else v[n-1] = 2;
	sort(v, v+n);

	For(i, 0, n){
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
