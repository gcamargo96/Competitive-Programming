#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 500005;
string s;
int t, n;

void ES_path(){
	for(int i = 0; i < n-1; i++){
		cout << 'E';
	}
	for(int i = 0; i < n-1; i++){
		cout << 'S';
	}
	cout << endl;
}

void SE_path(){
	for(int i = 0; i < n-1; i++){
		cout << 'S';
	}
	for(int i = 0; i < n-1; i++){
		cout << 'E';
	}
	cout << endl;		
}

void ESE_path(){
	int pos = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'E'){
			pos++;
			if(s[i+1] == 'E'){
				break;
			}
		}
	}

	for(int i = 0; i < pos; i++){
		cout << 'E';
	}
	for(int i = 0; i < n-1; i++){
		cout << 'S';
	}
	for(int i = 0; i < n-1-pos; i++){
		cout << 'E';
	}
	cout << endl;
}

void SES_path(){
	int pos = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'S'){
			pos++;
			if(s[i+1] == 'S'){
				break;
			}
		}
	}

	for(int i = 0; i < pos; i++){
		cout << 'S';
	}
	for(int i = 0; i < n-1; i++){
		cout << 'E';
	}
	for(int i = 0; i < n-1-pos; i++){
		cout << 'S';
	}
	cout << endl;
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> n;
		cin >> s;

		cout << "Case #" << caso << ": ";

		if(s[0] == 'S'){
			if(s[2*n-2-1] == 'S'){
				ESE_path();
			}
			else{ // s[n-1] == 'E'
				ES_path();
			}
		}
		else{ // s[0] == 'E'
			if(s[2*n-2-1] == 'S'){
				SE_path();
			}
			else{ // s[n-1] == 'E'
				SES_path();
			}
		}
	}

	return 0;
}