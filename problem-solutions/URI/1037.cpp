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

double x;

int main(void){
	cin >> x;

	if(x >= 0 and x <= 25){
		cout << "Intervalo [0,25]" << endl;
	}
	else if(x > 25 and x <= 50){
		cout << "Intervalo (25,50]" << endl;		
	}
	else if(x > 50 and x <= 75){
		cout << "Intervalo (50,75]" << endl;
	}
	else if(x > 75 and x <= 100){
		cout << "Intervalo (75,100]" << endl;
	}
	else{
		cout << "Fora de intervalo" << endl;
	}

	return 0;
}