#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class DataStream {
public:
    int value;
    int k;
    int count;
    int prev=-1;
    DataStream(int value, int k) {
        this->value=value;
        this->k=k;
    }
    
    bool consec(int num) {
       if(prev==num){
           count++;
       }
       else{
           count=1;
       }
       prev=num;
       if(count>=k && prev==value) return true;
       return false;

        
    }
};