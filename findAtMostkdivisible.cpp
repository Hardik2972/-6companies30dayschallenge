#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
class Solution {
public:
void print(vector<int> temp){
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<' ';
    }
    cout<<endl;
}
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> mySet;
        int i=0;
        int j=0;
        int count=0;
        vector<int> temp;
        while(j<=nums.size()){
            if(j<nums.size()){
            temp.push_back(nums[j]);
            if(nums[j]%p==0) count++;
            
            if(count<=k ){
                mySet.insert(temp);
            }
            j++;
            }
          
            if(count>k || j==nums.size()){
                temp.clear();
                i++;
                j=i;
                count=0;
            }
        }
        return mySet.size();
    }
};