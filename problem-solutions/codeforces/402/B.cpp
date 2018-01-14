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

//ll n, k;
string n; 
int k;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	if(n.size() == 1 and n[0] == '0'){
		cout << 0 << endl;
		return 0;
	}

	if(n.size()-1 < k){
		cout << n.size()-1 << endl;
		return 0;
	}

	int res= 0, zeros = 0;
	for(int i = 0; i < n.size()-1; i++){
		if(n[n.size()-i-1] != '0') res++;
		else zeros++;
		
		if(zeros == k) break;
	}
	
	if(zeros < k){
		cout << n.size()-1 << endl;
	}
	else{
		cout << res << endl;
	}

	return 0;
}

