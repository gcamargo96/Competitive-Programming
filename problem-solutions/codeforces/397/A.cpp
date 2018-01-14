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

int foi, voltou, n;
string home;

int main(void){
	cin >> n >> home;

	string aux;
	For(i,0,n){
		cin >> aux;
		
		string de;
		For(j,0,3){
			de += aux[j];
		}

		string para;
		For(j,5,8){
			para += aux[j];
		}

		if(de == home) foi++;
		if(para == home) voltou++;
	}

	if(voltou < foi){
		cout << "contest" << endl;
	}
	else{
		cout << "home" << endl;
	}

	return 0;
}

