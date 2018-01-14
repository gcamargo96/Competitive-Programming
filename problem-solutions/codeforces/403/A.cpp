#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n;
map<int, int> bag, table, fim;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		bag[i] = 2;
	}

	int x, res = 0;
	For(i,0,2*n){
		scanf("%d", &x);
		if(table[x] == 1){
			fim[x] = 2;
			table.erase(x);
		}
		else{
			table[x] = 1;
		}

		bag[x]--;
		if(bag[x] == 0) bag.erase(x);

		res = max(res, (int) table.size());
	}

	printf("%d\n", res);

	return 0;
}

