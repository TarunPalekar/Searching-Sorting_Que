
#include<bits/stdc++.h>
using namespace std;
//bs wale method me sabse pahle mini diff element par high ka pointer place kar do aur h-1 par low element phir 
// dikho ki min differenc element high or low me se konsa hai high ho to high ko+1 kar do nahi to lowko -1 kar do
//agar high 0 par ho to high ko k tak increase karo aur agare high size par hot to low ko k tak decrease karo
class Solution {
public:
int lowerBound(vector<int> &arr, int x){
    int start=0;
    int end=arr.size()-1;
    int ans=end;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]>=x){
            ans=mid;
            end=mid-1;

        }
        else if(x>arr[mid]){
            start=mid+1;

        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int h=lowerBound(arr, x);
        int l=h-1;
        while(k--){
            if(l<0){
                h++;
            }
            else if(h>=arr.size()){
                l--;
            }
           else if(x-arr[l]>arr[h]-x){
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int> (arr.begin()+l+1, arr.begin()+h);
    //    int l=0;
    //    int h=arr.size()-1;
    //    while(h-l>=k){
    //     if(x-arr[l]>arr[h]-x){
    //         l++;
    //     }
    //     else{
    //         h--;
    //     }
    //    }
    //    vector<int> ans;
    //    for(int i=l;i<=h;i++){
    //     ans.push_back(arr[i]);

    //    }
    //    return ans;
    }
};