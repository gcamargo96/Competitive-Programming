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
#define N 0
#define NE 1
#define L 2
#define SL 3
#define S 4
#define SO 5
#define O 6
#define NO 7

int n;
string s;
vector<int> v;

bool check(){
	int ret = 0;
	//if(dir == N){
		//cout << "deu ruim em N" << endl;
		For(i,0,v.size()){
			if(!(v[i] >= 1 and v[i] <= 3)) return 1;
		}
	//}
	//if(dir == NE){
	//	cout << "deu ruim em NE" << endl;
		For(i,0,v.size()){
			if(!((v[i] >= 1 and v[i] <= 3) or (v[i] == 6 or v[i] == 9))) return 1;
		}
	//}
	//if(dir == L){
	//	cout << "deu ruim em L" << endl;
		For(i,0,v.size()){
			if(!(v[i] == 3 or v[i] == 6 or v[i] == 9)) return 1;
		}
	//}
	//if(dir == SL){
	//	cout << "deu ruim em SL" << endl;
		For(i,0,v.size()){
			if(!(v[i] == 3 or v[i] == 6 or v[i] == 9 or v[i] == 8 or v[i] == 0)) return 1;
		}
	//}
	//if(dir == S){
	//	cout << "deu ruim em S" << endl;
		For(i,0,v.size()){
			if(!(v[i] == 7 or v[i] == 0 or v[i] == 9)) return 1;
		}
	//}
	//if(dir == SO){
	//	cout << "deu ruim em SO" << endl;
		For(i,0,v.size()){
			if(!(v[i] == 1 or v[i] == 4 or v[i] == 7 or v[i] == 8 or v[i] == 0)) return 1;
		}
	//}
	//if(dir == O){
	//	cout << "deu ruim em O" << endl;
		For(i,0,v.size()){
			if(!(v[i] == 1 or v[i] == 4 or v[i] == 7 or v[i] == 0)) return 1;
		}
	//}
	//if(dir == NO){
	//	cout << "deu ruim em NO" << endl;
		For(i,0,v.size()){
			if(!(v[i] == 1 or v[i] == 2 or v[i] == 3 or v[i] == 4 or v[i] == 7)) return 1;
		}
	//}

	return 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	For(i,0,s.size()){
		v.pb(s[i]-'0');
	}

	bool res = check();

	if(res) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}
