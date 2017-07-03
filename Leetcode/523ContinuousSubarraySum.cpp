#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		
		map<int, int> ma = map<int, int>();
		ma.insert_or_assign(0, -1);
		int runningSum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			runningSum += nums[i];
			runningSum %= k;
			
		}
	}
};
/*
public boolean checkSubarraySum(int[] nums, int k) {
	Map<Integer, Integer> map = new HashMap<Integer, Integer>(){{put(0,-1);}}
	int runningSum = 0;
	for (int i=0;i<nums.length;i++) {
		runningSum += nums[i];
		if (k != 0) runningSum %= k;
		Integer prev = map.get(runningSum);
		if (prev != null) {
			if (i - prev > 1) return true;
		}
		else map.put(runningSum, i);
	}
	return false;
}
*/
int main(void)
{


	return 0;
}

/*
Given a list of non-negative numbers and a target integer k, write a function to check if the array has 
a continuous subarray of size at least 2 that sums up to the multiple of k, that is, 
sums up to n*k where n is also an integer.
*/
