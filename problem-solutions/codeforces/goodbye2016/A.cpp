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

int n, k;

int main(void){
	cin >> n >> k;
	int total = 4*60 - k;

	int cnt = 0, sum = 0;
	for(int i = 1; sum <= total and i <= n; i++){
		sum += i*5;
		if(sum <= total) cnt++;
	}

	cout << cnt << endl;

	return 0;
}

