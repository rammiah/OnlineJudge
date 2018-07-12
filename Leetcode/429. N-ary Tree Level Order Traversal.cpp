class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<Node*> new_nodes, old_nodes;
		vector<vector<int>> result;
		if (root == nullptr) {
			return result;
		}
		// 开始遍历
		old_nodes.push_back(root);
		while (!old_nodes.empty()) {
			vector<int> temp;
			for (auto &n : old_nodes) {
				temp.push_back(n->val);
				for (auto &p : n->children) {
					new_nodes.push_back(p);
				}
			}
			old_nodes.swap(new_nodes);
			new_nodes.clear();
			result.push_back(temp);
		}

		return result;
	}
};
