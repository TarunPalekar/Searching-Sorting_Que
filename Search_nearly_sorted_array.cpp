#include <bits/stdc++.h>
using namespace std;
int searchNearlySorted(int arr[], int n, int target)
{
  int start = 0;
  int end = n - 1;

  int mid = 0;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    if (mid - 1 >= 0 && arr[mid - 1] == target)
    {
      return mid - 1;
    }
    if (mid + 1 < n && arr[mid + 1] == target)
    {
      return mid + 1;
    }
    if (target > arr[mid])
    {
      start = mid = 1;
    }
    else
    {
      end = mid - 1;
    }
  }

  return -1;

  // int s = 0;
  // int e = n-1;
  // int mid = s + (e-s)/2;

  // while(s <= e) {
  //   if(mid-1 >= 0 &&  arr[mid-1] == target) {
  //     return mid-1;
  //   }
  //   if(arr[mid] == target)
  //     return mid;

  //   if(mid+1 < n && arr[mid+1] == target)
  //     return mid+1;

  //   if(target > arr[mid] ){
  //     //right
  //     s = mid + 2;
  //   }
  //   else {
  //     //left
  //     e = mid - 2;
  //   }
  //   mid = s + (e-s)/2;
  // }
  // return -1;
}