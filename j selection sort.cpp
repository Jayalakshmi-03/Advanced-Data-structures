#include<iostream>
using namespace std;
template<class T>

void selectionSort( int n)
{
T a[n];
int i, j, min;
T temp;
cout<<"\nEnter array elements:\n";
for(int i=0;i<n;i++)
    cin>>a[i];
 for(i = 0; i< n-1; i++)
 {
     min = i;
for(j = i+1; j<n; j++)
    if(a[j] < a[min])
    min = j;
temp = a[i];
a[i] =  a[min];
a[min] = temp;
}
cout << "\nArray after Sorting: ";
for(int i = 0; i<n; i++)
    cout << a[i] << " ";
cout << endl; }

int main()
{
    int n,c;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout<<"\n1.Int\t2.Char\t3.Float\n";
    cin>>c;
    if(c==1)
        selectionSort<int>(n);
    else if(c==2)
        selectionSort<char>(n);
    else if(c==3)
        selectionSort<float>(n);
    return 0;
}
