#include<iostream>
using namespace std;

void Merge(int arr[],int p, int q,int r)     
{

    int n1,n2,i,j,k;    
    n1=q-p+1;
    n2=r-q;             
    int L[n1],R[n2];
   
    for(i=0;i<n1;i++)
    {
        L[i]=arr[p+i];
    }
    
    for(j=0;j<n2;j++)
    {
        R[j]=arr[q+j+1];
    }
    
    i=0,j=0;
  
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            arr[k]=L[i++];
        }
        else
        {
            arr[k]=R[j++];
        }
    }
    while(i<n1)             
    {
        arr[k++]=L[i++];
    }
  
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
  
}

void MergeSort(int arr[],int p,int r)    
{
    int q;                                
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
}
void Display(int arr[], int size);
void Sort(int arr[], int low, int high);
int ListDivision (int arr[], int low, int high);
int ListDivision (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {

            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
            int temp=arr[i+1];
            arr[i+1]=arr[high];
            arr[high]=temp;
    return (i + 1);
}
void Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = ListDivision(arr, low, high);
        Sort(arr, low, pi - 1);
        Sort(arr, pi + 1, high);
    }
}
void Display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cout<<"Enter size of the Array: ";
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        cout<<"Enter Value "<<i+1<<" : "; cin>>arr[i];
    }
    cout<<"Sorted Array (Merge Sort): ";
    MergeSort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nAgain Enter Values : \n";
    for(i=0;i<n;i++){
        cout<<"Enter Value "<<i+1<<" : "; cin>>arr[i];
    }
    cout<<"Sorted Array (Quick Sort): ";
    Sort(arr, 0, n - 1);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
  
}
