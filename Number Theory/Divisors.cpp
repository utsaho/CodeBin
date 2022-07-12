#include <bits/stdc++.h>
#define     int         long long
#define     tc()        int test_case; cin>>test_case; while(test_case--)
#define     cout(a)     cout<<a<<ed
#define     ed          '\n'
#define     UTSHO       ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

const int N = 1000;
bool prime[N];	// prime marker
vector<int>primes;	// Array of all primes

vector<int>divisors[N]; // array of Divisors list

// Finding Divisors List
void Find_Divisors(){
	for(int i=1; i<=N-1; i++){
		for(int j=1; j<=N-1; j+=i){
			divisors[j-1].push_back(i);
		}
	}
}

// Printing Divisors List...
void Print_Divisors_List() {
	int n; cin>>n;
	for(int i=0; i<divisors[n].size(); i++){
		cout<<divisors[n][i]<<" ";
	}
	cout<<ed;
}

// Gettint prime numbers...
void get_prime(){
	int sq = sqrt(N);
	primes.push_back(2);
	for(int i=4; i<=N; i+=2) prime[i] = true;
	for(int i=3; i<=sq; i+=2){
		if(!prime[i]){
			for(int j=i*i; j<=N; j+=(2*i)) prime[j] = true;
		}
	}
	for(int i=3; i<=N; i+=2){
		if(!prime[i]){
			primes.push_back(i);
		}
	}
	// cout(primes.size());
}

// Finding Number of Divisors...
void Number_and_sum_of_Divisors() {
	int n; cin>>n;
	int NOD = 1, SOD = 1;	// NOD: Number of Divisors, SOD: Sum of Divisors
	vector<pair<int, int>>v;
	for(auto it:primes){
		if(n==0 || n==1){
			break;
		}
		int c=0;
		while(n%it == 0){
			++c;
			n/=it;
		}
		if(c!=0){
			NOD*=(c+1);
			SOD*=((pow(it, c+1)-1)/(it-1));
		}
	}
	// int NOD = 1;	// Number of Divisors
	// for(auto it:v){
	// 	NOD*=(it.second+1);
	// }
	cout("Number of divisors: "<< NOD);
	cout("Sum of Divisors: "<< SOD);
}

int32_t main() {
	UTSHO;
	OJ;
	// Find_Divisors();
	// Print_Divisors_List();

	get_prime();
	Number_and_sum_of_Divisors();
	return 0;
}
