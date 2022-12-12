#include<iostream>
using namespace std;
template<typename T>
void Merge(T arr[], int start, int end)
{
    int z, x, y, mid;
    T temp[end];
    mid = (start + end) / 2;
    z = 0;
    x = start;
    y = mid + 1;

    while (x <= mid && y <= end)
    {
        if (arr[x] < arr[y])
        {
            temp[z] = arr[x];
            ++x, ++z;
        }
        else
        {
            temp[z] = arr[y];
            ++y, ++z;
        }
    }

    while (x <= mid)
    {
        temp[z] = arr[x];
        ++x, ++z;
    }

    while (y <= end)
    {
        temp[z] = arr[y];
        ++y, ++z;
    }
    for (int i = start; i <= end; ++i)
    {
        arr[i] = temp[i - start];
    }

}

template<typename T>
void MergeSort(T arr[], int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, end);
    }

}

template<typename T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int main()
{
  int n,c;
  cout<<"\nEnter size of array:";
  cin>>n;
  cout<<"\n1.Int\t2.Char\n";
  cin>>c;
  if(c==1)
  {
    int a[n];
	cout<<"\nEnter array elements:\n";
	for(int i=0;i<n;i++)
      cin>>a[i];
    cout << "\nArray Before Sorting: " << endl;
    PrintArray(a, n);
    MergeSort(a, 0, n - 1);
    cout << "Array After Sorting: " << endl;
    PrintArray(a, n);
  }
  else if(c==2)
  {
    char a[n];
	cout<<"\nEnter array elements:\n";
	for(int i=0;i<n;i++)
      cin>>a[i];
    cout << "\nArray Before Sorting: " << endl;
    PrintArray(a, n);
    MergeSort(a, 0, n - 1);
    cout << "Array After Sorting: " << endl;
    PrintArray(a, n);
  }
  return 0;
}
