class Solution {
public:
    int consecutiveNumbersSum(int num) {
    	int result = 0;
		for (long long i = 0; i < num; ++i) {
			if (i * (i + 1) > 2 * num) {
				break;
			}
			long long as = num - (i + 1) * i / 2;
			// 不能整除继续
			if (as % (i + 1) != 0)continue;
			// 开始的数字大于0
			if (as / (i + 1) > 0){
				++result;
			} 
		}
        
        return result;
    }
};

