#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 100002;
int B, S, l, r;
int L[N], R[N];

int main(void){
	ios_base::sync_with_stdio(false);
	
	while(cin >> S >> B, S != 0 or B != 0){
		For(i,0,S){
			L[i] = i-1;
			R[i] = i+1;
		}
		
		For(i,0,B){
			cin >> l >> r;
			L[R[r]] = L[l];
			R[L[l]] = R[r];
			if(L[l] > 0 and L[l] <= S) cout << L[l];
			else cout << "*";
			cout << " ";
			if(R[r] > 0 and R[r] <= S) cout << R[r];
			else cout << "*";
			cout << endl;
		}
		cout << "-" << endl;
	}

	return 0;
}
