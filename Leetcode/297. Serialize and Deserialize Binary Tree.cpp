class Codec {
	// 树的序列化和反序列化
	// 前序遍历就好了
	TreeNode *deserialize(stringstream &s) {
		string str;
		s >> str;
		if (str == "#") {
			return nullptr;
		}
		TreeNode *node = new TreeNode(stoi(str));
		node->left = deserialize(s);
		node->right = deserialize(s);
		return node;
	}
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root != nullptr) {
			string left = serialize(root->left);
			string right = serialize(root->right);
			return to_string(root->val) + " " + left + " " + right;
		}
		return "#";
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		stringstream s(data);
		return deserialize(s);
	}
};