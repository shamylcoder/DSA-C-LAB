#include<iostream>
#include<conio.h>
using namespace std;

//Example 3.1
int fact(int n)
{
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
//Example 3.2
/*void rev() {
    char ch;
    cout<< "Enter the string tobe reversed : ";
    cin.get(ch);
    if(ch !='/n')
    {
        rev();
        cout.put(ch);
    }
}*/
//Example 3.3
int power(int x,int n)
{
    if(n==0)
    return 1;
    else
    return x*power(x,n-1);
}
//Example 3.4
int Ackermann(int m,int n)
{
    if(m==0)
    return n+1;
    else if (m>0 && n==0)
    return Ackermann(m-1,1);
    else if (m>0 && n>0)
    return Ackermann(m-1,Ackermann(m,n-1));
}
//Exercise 3.3(a)
int print(int n){
    if(n <= 0){
    cout<<0;
    }
    else{
     cout<<n<<endl;
     print(n-1);
    }
}
//Exercise 3.3(b)
int coef(int n,int k)
{
    if(n==k)
    return 1;
    else if(k==0)
    return 1;
    else {
        return coef(n-1,k-1) + coef(n-1,k);
    }
}
//Exercise 3.3(c)
int cbc(int n, int k) {
	if (n == k)
		return 1;
	else if (k == 0)
		return 1;
	else if (n > 1 && k > 0)
		return cbc(n - 1, k - 1) + cbc(n - 1, k);
}
bool isPrime(int n, int i = 2)
{
	if (n <= 2)
		return (n == 2) ? true : false;
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;
	return isPrime(n, i + 1);
}


int main(){
    /*int factorial;
    cout<< "Enter the Number you like ";
    cin>>factorial;
    cout<<fact(factorial);
    //rev();//Example 3.2
    //Exercise 3.1
    cout<< "Enter the number and \t it Power : ";
    int num,pwr;
    cin>>num>>pwr;
    power(num,pwr);
    int *arr;
    arr =new int[pwr];
    int size = size;
    for(int i=0;i<size;i++){
        cout<<num<<" x "<<pwr<<" = "<<power(num,pwr)<<endl;
        pwr--;
        if(pwr==0){
              break;
        }
    }
    while (pwr < 1) { 
        cout << num << " x " << pwr << " = " << power(num, pwr) << endl;
        pwr--;
    }
   //Exercise 3.2
     cout<<Ackermann(3,4)<<endl;*/
     //Exercise 3.3
   // print(6);
   int num = 20;
	int nB = 4, kB = 5;
	cout << isPrime(kB) << endl;
	cout<<"Binomial computation: " << cbc(nB, kB);
	print(num);
   cout<<coef(6,3);
    // getch();
    return 0;
}