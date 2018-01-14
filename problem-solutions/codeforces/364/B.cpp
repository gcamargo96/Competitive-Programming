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

const int N = 100002;
ll n, m;
int clin = 0, ccol = 0;
bool lin[N], col[N];
ll res;

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	res = n*n;
	
	int x, y;
	For(i,0,m){
		cin >> x >> y;
		
		if(!lin[x]){
			res -= n-ccol;
			clin++;
			lin[x] = 1;
		}

		if(!col[y]){
			res -= n-clin;
			ccol++;
			col[y] = 1;
		}

		cout << res <<  " ";
	}
	
	cout << endl;

	return 0;
}
