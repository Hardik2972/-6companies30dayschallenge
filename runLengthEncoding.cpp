#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

string encode(string src)
{     
  int i=0;
  int j=0;
  string ans;
  while(j<src.size()){
      if(src[i]!=src[j] || j==src.size()-1){
          if(j==src.size()-1){
              if(src[i]==src[j]){
                  ans+=src[i]+to_string(j-i+1);
              }
              else{
                  ans+=src[i]+to_string(j-i);
                  ans+=src[j]+to_string(1);
              }
          }
          else{
              ans+=src[i]+to_string(j-i);
          }
          i=j;
      }
      j++;
  }
  return ans;
}     