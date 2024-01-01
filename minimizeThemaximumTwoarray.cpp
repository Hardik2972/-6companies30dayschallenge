#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPossible(long long int mid,int d1, int d2, int Cnt1, int Cnt2 ){
        
            long long int lcm=(long long) d1* (long long )d2/__gcd(d1,d2);
        
            long long int common = mid/lcm;
            long long int c1 = mid/d1 - common;
            long long int c2 = mid/d2 - common;
            long long int both = mid - c1 - c2 - common;
            long long int remainig1 = 0;
            if((Cnt1 - c2)>=0) remainig1 = Cnt1 - c2;
            int remainig2 = 0;
            if((Cnt2 - c1)>=0) remainig2 = Cnt2 - c1;
            if(both>=(remainig1+remainig2)) return true;
            return false;
            
        
    }
    int minimizeSet(int divisor1, int divisor2, int Cnt1, int Cnt2) {
        long long int end=2e9;
        long long int start=2;
        long long int ans=-1;
        while(start<=end){
            long long int mid=start+(end-start)/2;
            bool check = isPossible(mid,divisor1,divisor2,Cnt1,Cnt2);
            if(check){
                ans = mid ;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};