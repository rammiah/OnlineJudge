class Solution {
public:
	bool Test(string col, string test)
	{
		bool result = true;
		for (unsigned i = 0; i < test.length(); ++i)
		{
			if (col.find(test[i]) == -1)
			{
				result = false;
				break;
			}
		}
		return result;
	}
	vector<string> findWords(vector<string>& words) {
		vector<string> result = vector<string>();
		vector<string>::iterator index = words.begin();
		string temp;
		const string first = "qwertyuiopQWERTYUIOP";
		const string second = "asdfghjklASDFGHJKL";
		const string third = "zxcvbnmZXCVBNM";

		while (index != words.end())
		{
			if (first.find((*index)[0]) != -1)
			{
				if (Test(first, *index))
				{
					result.push_back(*index);
				}
			}
			else if (second.find((*index)[0]) != -1)
			{
				if (Test(second, *index))
				{
					result.push_back(*index);
				}
			}
			else
			{
				if (Test(third, *index))
				{
					result.push_back(*index);
				}
			}
			++index;
		}

		return result;
	}

};