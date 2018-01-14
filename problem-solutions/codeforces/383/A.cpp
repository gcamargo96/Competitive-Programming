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

int main(void){
	cin >> n;

	if(n == 0){
		cout << 1 << endl;
		return 0;
	}

	if(n%4 == 0){
		cout << 6 << endl;
	}
	if(n%4 == 1)
		cout << 8 << endl;
	if(n%4 == 2)
		cout << 4 << endl;
	if(n%4 == 3)
		cout << 2 << endl;

	return 0;
}

