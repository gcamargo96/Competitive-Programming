#include <bits/stdc++.h>
using namespace std;
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

int main(void){
	srand(time(NULL));
	cout << 10000 << endl;

	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < 10; j++){
			int x = rand()%2;
			if(x){
				cout << 's';
			}
			else{
				cout << 'h';
			}
		}
		cout << endl;
	}

	return 0;
}