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

int n;
int c100, c50, c20, c10, c5, c2, c1;

int main(void){
	cin >> n;
	cout << n << endl;

	while(n > 0){
		if(n >= 100){
			c100++;
			n -= 100;
		}
		else if(n >= 50){
			c50++;
			n -= 50;
		}
		else if(n >= 20){
			c20++;
			n -= 20;
		}
		else if(n >= 10){
			c10++;
			n -= 10;
		}
		else if(n >= 5){
			c5++;
			n -= 5;
		}
		else if(n >= 2){
			c2++;
			n -= 2;
		}
		else if(n >= 1){
			n -= 1;
			c1++;
		}
	}

	cout << c100 << " nota(s) de R$ 100,00" << endl;
	cout << c50 << " nota(s) de R$ 50,00" << endl;
	cout << c20 << " nota(s) de R$ 20,00" << endl;
	cout << c10 << " nota(s) de R$ 10,00" << endl;
	cout << c5 << " nota(s) de R$ 5,00" << endl;
	cout << c2 << " nota(s) de R$ 2,00" << endl;
	cout << c1 << " nota(s) de R$ 1,00" << endl;

	return 0;
}