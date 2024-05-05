#include<bits/stdc++.h>
using namespace std;
int findOddOccuringElement(int arr[], int n) {
  int start=0;
  int end= n-1;
  int mid;
  while(start<=end){
    mid=start+(end-start)/2;
    if(start==end){
      return arr[start];
    }
    if(mid&1){
      if(mid-1>=0&&arr[mid]==arr[mid-1]){
        start=mid+1;
      }
      else{
        end=mid-1;
      }
    }
    else{
      if(mid+1<n&&arr[mid]==arr[mid+1]){
        start=mid+2;
      }
      else{
        end=mid;
      }
    }
    
  }
  return -1;
















  // int s = 0;
  // int e = n-1;
  // int mid = s + (e-s)/2;

  // while(s <= e) {

  //   //single element
  //   if(s == e) {
  //     return s;
  //   }

  //   //mid check -> even or odd
  //   if(mid & 1) { //mid&1 -> true -> odd number
  //     if(mid-1 >=0 && arr[mid-1] == arr[mid]) {
  //       //right me jao
  //       s = mid + 1;
  //     }
  //     else {
  //       //left me jao
  //       e = mid - 1;
  //     }
  //   }
  //   else {
  //     //even
  //     if(mid+1 < n && arr[mid] == arr[mid+1]){
  //       //right me jao
  //       s = mid + 2;
  //     }
  //     else {
  //       //ya toh main right part pr khada hu
  //       //ya toh main answer k upar khada hu
  //       //that's why e = mid krra hu
  //       // kyoki e = mid - 1; se ans lost ho skta h 
  //       e = mid;    
  //     }
  //   }
  //   mid = s + (e-s)/2;
  // }
  // return -1;
}