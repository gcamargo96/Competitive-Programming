#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define make_pair mp
#define push_back pb

const int N = 500005;
int n;
int p[N];
char s[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	scanf("%s", s);

	int i = 0, j;
	ll sumA = 0, sumB = 0, maior = 0;
	ll acum = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'B') acum += p[i];
	}
	maior = acum;
	ll acum2 = acum;

	for(j = 0; j < n; j++){
		if(s[j] == 'A'){
			acum += p[j];
			if(acum > maior) maior = acum;
		}
		if(s[j] == 'B'){
			acum -= p[j];
			if(acum > maior) maior = acum;
		}
	}

	for(i = n-1; i >= 0; i--){
		if(s[i] == 'A'){
			acum2 += p[i];
			if(acum2 > maior) maior = acum2;
		}
		if(s[i] == 'B'){
			acum2 -= p[i];
			if(acum2 > maior) maior = acum2;
		}
	}

	cout << maior << endl;

	return 0;
}
