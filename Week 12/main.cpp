#include <vector>
#include <algorithm>
#include <iostream>
#include <conio.h>
#include<list>
#include<deque>
#include<stack>
#include<bitset>
#include<numeric>
#include<functional>
#include<assert.h>
#include<cassert>
#include<cstring>
#include<string>

using namespace std;

const int N = 100;
    int set1[]= {1,2,3};
    int set2[]= {2,3,4};
    vector<int> set3(10);
    int vec1[10];
    int vec2[10];
    int vec[] = {1,2,3,4,5};
    class string {
        char* str;
    public : 
       string(){
        str = 0;
       }
    string(const char* s){
        str = strdup(s);
        assert(str);
    }
    int operator<(const string& s) const{
        return strcmp(str, s.str)<0;
    }
    operator char*() {
        return str;
    }
    };
int main(){
//Example 12.1
    vector<int>v;
    for (int i = 0;i < 25; i++)
    v.push_back(i);
    random_shuffle(v.begin(), v.end());
    for (int j =0 ;j < 25 ;j++)
    cout<<v[j]<<" ";
    cout<<endl;
    getch();
/*
//Example 12.2
    list<int> v;
    for (int i = 0;i<25; i++)
    v.push_back(i);
    for (int j = 0;j< 25;) {
        cout << v.back()<<"  ";
        v.pop_back();
    }
    cout <<endl;
    getch();

//Example 12.3
    deque<int> v;
    for (int i = 0; i<25; i++)
    v.push_back(i);
    random_shuffle(v.begin(), v.end());
    for(int j=0; j<25;j++){
        cout<< v.front()<<" ";
        v.pop_front();
    }
    cout<<endl;
    getch();
//Example 12.4
    stack<int, list<int> > stk;
    for (int i=1;i<=10; i++)
    stk.push(i);
    while(!stk.empty()){
        cout<< stk.top();
        stk.pop();
    }
    getch();
//Example 12.5
    bitset<16> b1("1011011110001011");
    bitset<16> b2;
    b2 =~b1;
    for (int i = b2.size()-1; i>=0; i--)
    cout<< b2[i];
    cout<<endl;
//Example 12.6
    vector<int> iv(N);
    iv[50] = 37;
    vector<int>::iterator iter = find(iv.begin(),iv.end(), 37);
    if(iter ==iv.end())
      cout<<"not found\n";
    else
      cout <<"found at"<<iter - iv.begin()<<"\n";
      getch();
//Example 12.7
    vector<int>::iterator first = set3.begin();
    vector<int>::iterator last =
    set_union(set1,set1 + 3, set2 , set2 + 3, first);
    while(first != last) {
        cout<<*first<<" ";
        first++;
    }
    cout<< endl;
    getch();
//Example 12.8
    fill(vec1,vec2 + 10, -1);
    for(int i = 0; i<10; i++)
       cout << vec1[i]<<" ";
       cout << endl;
    fill_n(vec2, 5, -1);
    for(int j = 0; j < 10; j++)
       cout <<vec2[j]<<" ";
       cout << endl;
    getch();
//Example 12.9
    int sum = accumulate(vec, vec + 5, 0);
    cout<< sum <<endl;
    int prod = accumulate(vec, vec + 5, 1, multiplies<int>());
    cout << prod <<endl;
    getch();
//Example 12.10
    char* list[] = {"epsilon","omega","theta","rho","alpha","beta","phi","gamma","delta"};
    const int N = sizeof(list) / sizeof(char*);
    int i,j;
    vector<string> v;
    for (i = 0; i< N; i++)
       v.push_back(string(list[i]));
    random_shuffle(v.begin(), v.end());
    for(j = 0; j<N; j++)
        cout<< v[j]<<" ";
        cout<<endl;
    getch();*/
    return 0;
}