#include<bits/stdc++.h>
using namespace std;
//very imp question
//isme sabse pahle ek search space banao sare pages ko add karke
//ab use search space me binary search lagake ek ek number ko dekho ki kya ye ek valid permutation bana sakta hai kya
//agar mid ki value me valid nahi ban raha hai to start ko mid +2 kar do nahi to ans to save karke end ko optimal ke liye end ko mid -1 kaR DO
// ab ispossible solution type karo jisme permutation ko bana ke try karo
//ab isme ek page sum banao aur ek c variable lo vo no of students ko save karega
// ab agar a[i ]ki val mid se badi hai to return false kar do kyoki koi book usme nahi  a sakti
//ab page sum me a[i ]book ko add kar lo aur mid se badi ho jae to c++ kar ke pagesum me new book dal do means ki ek student complete ho gaya hai ab next book dusre student ko deni hai
//ab agar c ki value M se badi ho to return false kar do 
// ab agar ye sab nahi hai iska matlab allocation possible hai to return true kar do
class Solution 
{
    public:
    bool isPossibleSolution(int a[], int N, int M, int mid){
        int pageSum=0;
        int c=1;
        for(int i=0;i<N;i++){
            if(a[i]>mid){
                return false;
            }
            if(pageSum+a[i]>mid){
                c++;
                pageSum=a[i];
                if(c>M){
                    return false;
                }
            }
            else{
                pageSum+=a[i];
            }
        }
        return true;
        
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int N, int M) 
    {
        if(M>N){
            return -1;
        }
        int start=0;
        int end=accumulate(a, a+N, 0);
        int ans=-1;
        
      
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossibleSolution(a, N, M, mid)){
                ans=mid;
                end=mid-1;
                
            }
            else{
                start=mid+1;
            }
        }
        return ans;
        //code here
    }
};