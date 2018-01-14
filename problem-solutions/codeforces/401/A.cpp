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

ll n;
int x;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> x;

	int moves = n%6;

	for(int i = moves; i > 0; i--){
		//cout << x << endl;
		if(i%2 == 1){
			if(x == 0) x = 1;
			else if(x == 1) x = 0;
		}
		else{
			if(x == 1) x = 2;
			else if(x == 2) x = 1;
		}
	}

	cout << x << endl;

	return 0;
}

