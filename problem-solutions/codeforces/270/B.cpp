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

const int N = 2002;
int n, k;
int v[N];

int main(void){
	//ios_base::sync_with_stdio(false);
	cin >> n >> k;

	For(i,0,n){
		cin >> v[i];
	}

	sort(v, v+n);

	ll res = 0;

	int i = n-1;
	while(i >= 0){
		res += 2*(v[i]-1);
		i -= k;
	}

	cout << res << endl;

	return 0;
}
