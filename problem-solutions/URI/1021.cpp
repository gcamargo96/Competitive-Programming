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

string aux;
int n;
int c10000, c5000, c2000, c1000, c500, c200, c100, c50, c25, c10, c5, c1;


int main(void){
	fastcin;
	cin >> aux;
	string num;
	for(int i = 0; i < aux.size(); i++){
		if(aux[i] != '.'){
			num += aux[i];
		}
	}
	int n = stoi(num);

	while(n > 0){
		if(n >= 10000){
			c10000++;
			n -= 10000;
		}
		else if(n >= 5000){
			c5000++;
			n -= 5000;
		}
		else if(n >= 2000){
			c2000++;
			n -= 2000;
		}
		else if(n >= 1000){
			c1000++;
			n -= 1000;
		}
		else if(n >= 500){
			c500++;
			n -= 500;
		}
		else if(n >= 200){
			c200++;
			n -= 200;
		}
		else if(n >= 100){
			c100++;
			n -= 100;
		}
		else if(n >= 50){
			c50++;
			n -= 50;
		}
		else if(n >= 25){
			c25++;
			n -= 25;
		}
		else if(n >= 10){
			c10++;
			n -= 10;
		}
		else if(n >= 5){
			c5++;
			n -= 5;
		}
		else{
			n -= 1;
			c1++;
		}
	}

	cout << "NOTAS:" << endl;
	cout << c10000 <<  " nota(s) de R$ 100.00" << endl;
	cout << c5000 <<  " nota(s) de R$ 50.00" << endl;
	cout << c2000 <<  " nota(s) de R$ 20.00" << endl;
	cout << c1000 <<  " nota(s) de R$ 10.00" << endl;
	cout << c500 <<  " nota(s) de R$ 5.00" << endl;
	cout << c200 <<  " nota(s) de R$ 2.00" << endl;

	cout << "MOEDAS:" << endl;
	cout << c100 <<  " moeda(s) de R$ 1.00" << endl;
	cout << c50 <<  " moeda(s) de R$ 0.50" << endl;
	cout << c25 <<  " moeda(s) de R$ 0.25" << endl;
	cout << c10 <<  " moeda(s) de R$ 0.10" << endl;
	cout << c5 <<  " moeda(s) de R$ 0.05" << endl;
	cout << c1 <<  " moeda(s) de R$ 0.01" << endl;

	return 0;
}