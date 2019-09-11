#include <bits/stdc++.h> 
using namespace std; 
  
void SieveOfEratosthenes(long long int n, bool prime[], 
                         bool primesquare[], long long int a[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    for (long long int i = 2; i <= n; i++) 
        prime[i] = true; 
  
    // Create a boolean array "primesquare[0..n*n+1]" 
    // and initialize all entries it as false. A value 
    // in squareprime[i] will finally be true if i is 
    // square of prime, else false. 
    for (long long int i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (long long int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (long long int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    long long int j = 0; 
    for (long long int p = 2; p <= n; p++) { 
        if (prime[p]) { 
            // Storing primes in an array 
            a[j] = p; 
  
            // Update value in primesquare[p*p], 
            // if p is prime. 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
  
// Function to count divisors 
long long int countDivisors(long long int n) 
{   
    long long int oddDiv = 1;
    long long int evenDiv = 1;
    // If number is 1, then it will have only 1 
    // as a factor. So, total factors will be 1. 
    if (n == 1) 
        return 1; 
        
    bool prime[n + 1], primesquare[n * n + 1]; 
  
    long long int a[n]; // for storing primes upto n 
  
    // Calling SieveOfEratosthenes to store prime 
    // factors of n and to store square of prime 
    // factors of n 
    SieveOfEratosthenes(pow(n, 1/3) + 1, prime, primesquare, a); 
  
    // ans will contain total number of distinct 
    // divisors 
    long long int ans = 1; 
  
    // Loop for counting factors of n 
    for (long long int i = 0;; i++) { 
        // a[i] is not less than cube root n 
        if (a[i] * a[i] * a[i] > n) 
            break; 
  
        // Calculating power of a[i] in n. 
        long long int cnt = 1; // cnt is power of prime a[i] in n. 
        while (n % a[i] == 0) // if a[i] is a factor of n 
        { 
            n = n / a[i]; 
            cnt = cnt + 1; // incrementing power 
        } 
  
        // Calculating number of divisors 
        // If n = a^p * b^q then total divisors of n 
        // are (p+1)*(q+1) 
        ans = ans * cnt; 
        if(i%2 == 0){
            evenDiv *= cnt;
        }
        else{
            oddDiv *= cnt;
        }
    } 
  
    // if a[i] is greater than cube root of n 
  
    // First case 
    if (prime[n]) {
        ans = ans * 2;
        oddDiv = oddDiv*2;
    }
    // Second case 
    else if (primesquare[n]) {
        ans = ans * 3; 
        if(n == 4){
            evenDiv *= 2;
        }
        else{
            oddDiv *= 3;
        }
    }
  
    // Third casse 
    else if (n != 1) {
        ans = ans * 4; 
        if(n%2 == 0){
            oddDiv *= 3;       
        }
        else{
            oddDiv *= 4;
        }
    }
  
    return abs(oddDiv - evenDiv) <= 2 ? 1 : 0; // Total divisors 
} 
  


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long int T;
cin>>T;
long long int cnt = 1;
while(T--){

	long long int L, R;
	cin>>L>>R;

	long long int ans = 0;
	for(long long int i = L; i <= R; i++){
		ans += countDivisors(i);
	}
	cout<<"Case #"<<cnt<<": "<<ans<<endl;
	cnt++;
}

}