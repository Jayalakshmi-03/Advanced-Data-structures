#include<iostream>
using namespace std;

template<typename T>
void swap(T arr[] , int pos1, int pos2)
{
	T temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

template<typename T>
int partition(T arr[], int low, int high, int pivot)
{
	int i = low;
	int j = low;
	while( i <= high)
	{
		if(arr[i] > pivot)
		{
			i++;
		}
		else
		{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

template<typename T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

template<typename T>
void QuickSort(T arr[], int low, int high)
{
	if(low < high)
	{
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	QuickSort(arr, low, pos-1);
	QuickSort(arr, pos+1, high);
	}
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
    QuickSort(a, 0 , n-1);
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
    QuickSort(a, 0 , n-1);
    cout << "Array After Sorting: " << endl;
    PrintArray(a, n);
  }
  return 0;
}
