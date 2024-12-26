#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Solution {
public:
    vector<int> runningSums;
    int totalSum;

    Solution(vector<int>& w) {
        int runningSum=0;
        for(int weight: w){
            runningSum+=weight;
            runningSums.push_back(runningSum);
        }
        totalSum=runningSum;
    }
    
    int pickIndex() {
        int target=rand()%totalSum+1;
        int low=0, high=runningSums.size();

        while(low<high){
            int mid=low+(high-low)/2;
            if(target>runningSums[mid]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};

int main(){
    return 0;
}