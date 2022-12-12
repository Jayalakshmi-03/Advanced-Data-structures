#include<iostream>
using namespace std;

template <class T>
void InsertionSort( int n)
{
 T a[n];
 int i, j;
 T temp;
 cout<<"\nEnter array elements:\n";
 for(int i=0;i<n;i++)
 cin>>a[i];
 for (int i = 1; i < n; ++i)
 {
  temp = a[i];
  j = i - 1;
  while (j >= 0 && a[j] > temp)
    {
     a[j + 1] = a[j];
     j = j - 1;
    }
   a[j + 1] = temp;
  }
  cout << "\nArray After Sorting: ";
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
 }

 int main()
 {
  int n,c;
  cout<<"\nEnter size of array:";
  cin>>n;
  cout<<"\n1.Int\t2.Char\n";
  cin>>c;
  if(c==1)
    InsertionSort<int>(n);
  else if(c==2)
    InsertionSort<char>(n);
  return 0;
 }
