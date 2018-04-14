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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll a, b, c, d;

int main(void){
	cin >> a >> b >> c >> d;

	if(b > c and d > a and c+d > a+b and c > 0 and d > 0 and a%2 == 0){
		cout << "Valores aceitos" << endl;
	}
	else{
		cout << "Valores nao aceitos" << endl;
	}

	return 0;
}