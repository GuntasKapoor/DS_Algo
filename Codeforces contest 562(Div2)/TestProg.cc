// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;




int main(){
    int y = 4;
    if(y & (y = 2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}
// int main(){
//     int y = 0;
//     if(1 | (y = 1)) {
//         cout << "y is " << y;
//     }
//     else {
//         cout << y;
//     }
// }

// int main(){
//     if(~0 == 1) {
//         cout << "yes";
//     }
//     else {
//         cout << "no";
//     }
//     cout<<~0<<endl;
// }

// #include <iostream>
// using namespace std;

// int main(){
//     int x = -2;
//     x = x >> 1;
//     cout << x;
// }


// int main(){
// 	cout<<(-2%10)<<endl;
// }



// void findDecresingints(int end,string s,int n){

// if(n==0){
// 	cout<<s<<endl;
// 	return;
// }

// for(int i = end; i>=1 ; i--){
// 	string str = s + to_string(i);
// 	findDecresingints(i-1, str , n-1);
// }
// }


// int main(){
// 	findDecresingints(9, "", 3);
// }
// class Gfg
// {
// public:
//     int main(int s)
//     {
//         cout << s << ", ";
//         return 0;
//     }
//     int main(char *s)
//     { 
//         cout << s<<“, ”;
//         return 0;
//     }
//     int main(int s ,int m)
//     {
//         cout << s << " " << m;
//         return 0;
//     }
// };

// int main()
// {
//     Gfg obj;
//     obj.main(3);
//     obj.main(&quot;Hello World!&quot;);
//     obj.main(9, 6);
//     return 0;
// }


// void Parenthesis(int n , int open ,int close,int pos,char str[]){
//     if(close == n){
//         cout<<str<<endl;
//         return;
//     }
    
//     if(open>close){
//        	str[pos]=')';
//         str[pos+1]='\0';
//         cout<<str<<endl;
//         Parenthesis(n, open, close + 1,pos + 1,str);
//     }
//     if(open<n){
// 		str[pos]='(';
//         str[pos+1]='\0';
//         cout<<str<<endl;
//         Parenthesis(n,open+1, close,pos + 1,str);
//     }
// }

// void printWellFormedParanthesis(int n){
//     if(n==0){
//         return;
//     }
//     char str[20];
// 	Parenthesis(n,0,0,0,str);
// }


// int main(){
// 	int n;
// 	cin>>n;
// 	printWellFormedParanthesis(n);
// }


// class Student {
//     public :

//     int rollNumber;

//     static int getRollNumber() {
//         return rollNumber;
//     }
// };


// int main() {
//     Student s;
//     s.rollNumber = 101;
//     cout << s.getRollNumber() << endl;
// }

// class Student {
//     int rollNumber;

//     public :

//     int age;

//     Student(int r) {
//         rollNumber = r;
//     }

//     int getRollNumber() const {
//         return rollNumber;
//     }

// };


// int main() {
//     Student s1(101);
//     s1.age = 20;

//     Student const s2 = s1;
//     cout << s2.getRollNumber();
// }







// class Student {
//     public :

//     int rollNumber;
//     int age;

// };


// int main() {
//     Student s1;

//     Student const s2 = s1;

//     s1.rollNumber = 101;
//     s1.age = 20;

//     cout << s2.rollNumber << " " << s2.age;
// }
// class Pair{
//   public :
//   int first;
//   int second;
// };

// int main(){

//   Pair *p1 = new Pair;
//   Pair p2;
//   p2 = *p1;
// }
// class Box{
// private:
// 	~Box(){

// 	}

// public:
// 	Box(){

// 	}

//     public :
//     int width;
//     int height;
//     int length;
//     void volume(){
//         cout << length * width * height;
//     }
// };

// int main() {
//     Box b;
//     b.height = 5;
//     b.width = 4;
//     b.volume();
// }


// class Shape{
//     public : 
//     int height;
//     int width;
// };

// int main() {
//     Shape *s = new Shape();
//     s -> height = 1;
//     cout << s -> height;
// }


// class Student {
//     int rollNumber;
// };

// int main() {
//     Student s;
//     cout << s.rollNumber;
// }


// #define SQUARE(x) x*x

// int main(){
// 	int x = 6;
//     int y = (36 / 2*2);
//     cout << y;

//     return 0;
// }


// int x = 1;

// void print(){
//     int x = 2;
//     {
//         int x = 3;
//         cout << x << endl;
//     }
// }
// int main(){
//     print();
//     return 0;
// }








// void updateValue(int *p){
//     *p = 610 % 255;
// }


// void func(int i, int& j, int p){
//     i++;
//     j++;
//     p++;
// }

// int main(){
//     int i = 10;
//     int j = 6;
//     int &p = i;
//     func(i, j, p);
//     cout << i << " " << j << " " << p;
// }



// if we pass i++ to a function it will only send it i and after returning it will increment i;
// void func(int p){
//     cout << p << " ";
// }

// int main(){
//     int i = 10;
 
//     func(++i);
//     cout << i;
// }



// int main(){
//     char ch = 97;
//     // int * q = (int*) 
//     cout<<610%255<<endl;
//     // updateValue((int*)&ch);
//     cout << ch;
// }

// int main()
// {
//   float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
//   float *ptr1 = &arr[0];
//   float *ptr2 = ptr1 + 3;
//   cout<<*ptr2<<" ";
//   cout<< ptr2 - ptr1;
//   cout<<ptr2<<endl;
//   cout<<ptr1<<endl;
//   cout<<ptr1+1;
//   return 0;
// }


// char *ans(char * arr,int N){
// 	char arra[100]={};
// 	for(int i=0;i<N;i++){
// 		arra[i]=arr[i];
// 	}
// 	return arr;
// }
// void swap (char *x, char *y) 
// {
//   char *t = x;
//   x = y;
//   y = t;
// }

// int main()
// {
//    char *x = "geeksquiz";
//    char *y = "geeksforgeeks";
//    char *t;
//    swap(x, y);
//    cout<<x << " "<<y;
//    t = x;
//    x = y;
//    y = t; 
//    cout<<" "<<x<< " "<<y;
//    return 0;
// }


// int main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

// // vector<vector<int>> A(20);
// // for(int i=0;i<5;i++){
// // 	for(int j=0;j<4;j++){
// // 		int a;
// // 		cin>>a;
// // 		A[i].push_back(a);
// // 	}
// // }
// // cout<<A[0].size()<<endl;
// // cout<<A.size()/A[0].size()<<endl;
// // int N;
// // cin>>N;
// // char array[100]="hello";

// // char *a=ans(array,N);

// // for(int i=0;i<N;i++){
// // 	cout<<array[i]<<" ";
// // }

// char * ptr = "abcdef";
// cout<<ptr<
// }