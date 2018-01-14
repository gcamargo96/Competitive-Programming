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

const int N = 102;
int n;
int ca[7], cb[7];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	int x;
	For(i,0,n){
		cin >> x;
		ca[x]++;
	}

	For(i,0,n){
		cin >> x;
		cb[x]++;
	}

	int res = 0;
	For(i,1,6){
		if((ca[i] + cb[i])%2 != 0){
			cout << -1 << endl;
			return 0;
		}
		else{
			res += (max(ca[i], cb[i]) - min(ca[i], cb[i]))/2;
		}
	}

	cout << res/2 << endl;

	return 0;
}

