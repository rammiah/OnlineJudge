class Solution {
private:
	bool Check(const vector<int>& value, const int first, const int last) {
		if (first >= last)return true;
		else if (value[first] == value[last])return Check(value, first + 1, last - 1);
		else return false;
	}
public:
	bool isPalindrome(ListNode* head) {
		ListNode *temp = head;
		vector<int> value;
		while (temp != nullptr) {
			value.push_back(temp->val);
			temp = temp->next;
		}
		int size = value.size();
		return Check(value, 0, size - 1);
	}
};