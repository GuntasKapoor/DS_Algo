// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;



int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
string ans = countAndSay(n);
cout<<ans;
}