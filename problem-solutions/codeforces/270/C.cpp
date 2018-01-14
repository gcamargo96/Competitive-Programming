#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define enld "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 100002;
int n;
string names[N][2];
int ordem[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> names[i][0] >> names[i][1];
	}

	For(i,0,n){
		cin >> ordem[i];
	}

	string last;
	if(names[ordem[0]-1][0] < names[ordem[0]-1][1]){
		last = names[ordem[0]-1][0];
	}
	else{
		last = names[ordem[0]-1][1];
	}

	bool res = 1;
	string menor, maior;
	For(i,1,n){
		if(names[ordem[i]-1][0] < names[ordem[i]-1][1]){
			menor = names[ordem[i]-1][0];
			maior = names[ordem[i]-1][1];
		}
		else{
			menor = names[ordem[i]-1][1];
			maior = names[ordem[i]-1][0];
		}
		
		if(menor > last){
			last = menor;
		}
		else if(maior > last){
			last = maior;
		}
		else{
			res = 0;
			break;
		}
	}

	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
