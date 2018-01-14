#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n, m;

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;

	For(i,0,n){
		if(i == n-1){
			if(i%2 == 0) cout << "I hate it ";
			else cout << "I love it ";	
		}
		else{
			if(i%2 == 0) cout << "I hate that ";
			else cout << "I love that ";		
		}
	}
	cout << endl;

	return 0;
}
