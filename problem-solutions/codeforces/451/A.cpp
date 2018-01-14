#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

string s;
int n;

int main(void){
	cin >> n;
	int d = n%10;

	if(d == 0){
		cout << n << endl;
	}
	else{
		if(d <= 5){
			n -= d;
		}
		else{
			n += 10-d;
		}
		cout << n << endl;
	}

	return 0;
}