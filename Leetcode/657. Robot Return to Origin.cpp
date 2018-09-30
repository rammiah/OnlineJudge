class Solution {
public:
	bool judgeCircle(string moves) {
		int row = 0, col = 0;
		for (auto &ch : moves) {
			switch (ch){
			case 'L':
				col--;
				break;
			case 'R':
				col++;
				break;
			case 'U':
				row++;
				break;
			case 'D':
				row--;
				break;
			}
		}
		return row == 0 && col == 0;
	}
};