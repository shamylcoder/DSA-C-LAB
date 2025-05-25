#include<iostream>
#include <conio.h>
#include <time.h>
using namespace std;

    int comparison=0;
    int exchange=0;
void Bubble(int x[], int n)
{
    int hold, j ,pass;
    int switched = true;
for (pass = 0; pass < n-1 && switched ==true ; pass++){
    switched = false;
    comparison++;
    for ( j = 0; j < n-pass-1; j++){
        if (x[j] > x[j+1])
        {
            switched = true;
            exchange++;
            hold = x[j];
            x[j] = x[j+1];
            x[j+1] = hold;

        }
    }
}
}
void insertionsort(int x[], int n)
{
    int j, k, y;
    for (k = 1; k < n; k++) {
        y = x[k];
        for (j = k - 1; j >= 0 && y < x[j]; j--) {
              comparison++;
            if (y < x[j]) {
                x[j + 1] = x[j];
                exchange++;
            } else {
                break;
            }
        }
        x[j + 1] = y;
        exchange++;
    }
}
void selectionsort(int x[], int n){
    int key;
    for(int a=0; a<n;a++){
        key = a;
       for(int b=a+1;b<n;b++){
        comparison++;
        if(x[b] < x[key]) {key = b;
        
        }
       }if (key > a){
        int temp = x[a];
        x[a] = x[key];
        x[key] = temp;
        exchange++;
       }

    }
}


int main(){
    int capacity;
    cout<< "Enter Size of Array : ";
    cin>> capacity;

    int *arr = new int[capacity];
    int size = 0;

    for (int i = 0; i < capacity; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
        ++size;
    }
    comparison = 0;
    exchange = 0;
 //Bubble(arr , capacity);
//insertionsort(arr , capacity);
selectionsort(arr , capacity);
        cout << "Entered values are : ";
    for (int i = 0; i < capacity; ++i) {
        cout << arr[i]<<" ";
    }
    //Exercise 13.1
        cout << "Total comparisons: " << comparison << endl;
    cout << "Total exchanges: " << exchange << endl;
//Example 13.1
time_t start, end;
char szInput [25];
double dif;
time (&start);
cout << "Please, enter your name: ";
cin>> szInput;
time (&end);
double dif=difftime (end, start);
cout <<"Hi "<< szInput;
cout << " It took you "<< dif<< " seconds to type your name."<< endl;
getch();

    delete[] arr;
    return 0;
}