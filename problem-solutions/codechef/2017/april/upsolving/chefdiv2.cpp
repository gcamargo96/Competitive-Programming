#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
 
const int N = 100002, M = 1000002;
map<ll,ll> divs[N];
ll a, b;
bool is_prime[M];
//vector<ll> primes;
 
void sieve(){
    for(ll i = 2; i < M; i++){
        if(!is_prime[i]){
			ll l = a/i * i;
			if(a%i != 0) l += i;
			
			for(ll j = l; j <= b; j += i){
				ll aux = j;
				while(aux%i == 0){
					//printf("divs[%d][%d]++\n", j, primes[i]);
					divs[j-a][i]++;
					aux /= i;
				}
			}
			
			
			for(int j = i+i; j < M; j += i){
                is_prime[j] = 1;
            }
        }
    }
}
 
int main(void){
    scanf("%lld%lld", &a, &b);
    sieve();
 
 
    ll res = 0;
    for(ll i = a; i <= b; i++){
        ll aux = 1;
        for(auto it = divs[i-a].begin(); it != divs[i-a].end(); it++){
            For(j,0,it->se){
                aux *= it->fi;
            }
        }
        if(aux < i) divs[i-a][i/aux] = 1;
       
        map<ll,ll> divs2 = divs[i-a];
 
        while(1){
            map<ll,ll>::iterator maior = divs2.begin();
            ll sum = 1;
            bool ok = 0;
            for(auto it = divs2.begin(); it != divs2.end(); it++){
                if(it->se > 0) ok = 1;
               
                sum *= (it->se+1);
                if(it->se > maior->se){
                    maior = it;
                }
            }
           
            if(ok){
                res += sum;
                maior->se--;
            }
            else{
                res++;
                break;
            }
        }
        res--;
    }
 
    printf("%lld\n", res);
   
    return 0;
}
