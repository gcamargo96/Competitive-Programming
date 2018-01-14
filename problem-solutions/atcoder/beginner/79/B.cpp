#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 90;
ll lucas[N];
int n;

int main(void){
	fastcin;
	cin >> n;

	lucas[0] = 2;
	lucas[1] = 1;

	for(int i = 2; i <= n; i++){
		lucas[i] = lucas[i-2] + lucas[i-1];
	}

	cout << lucas[n] << endl;

	return 0;
}