#include<iostream>
#include "Heap.h"
using namespace std;

int main()
{
  /* Create the heap */
  Heap holder;
  holder.createHeap();

  /* Read in the inputs */
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];

  /* Add inputs to heap */
  for(int i=0; i<n; i++)
  {
    holder.insertHeap(a[i]);
    holder.printHeap();
  }

  /* Delete elements from heap based on priority */
  for(int i=0; i<n; i++)
  {
    cout<<(a[i]=holder.deleteRoot())<<"\n";
    holder.printHeap();
  }

  /* Print the sorted array */
  for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
  cout<<"\n";
}