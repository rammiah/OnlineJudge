#include <stdio.h>
#include <stdlib.h>

int result;

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int val) {
    if (root != NULL) {
        result = root->val;
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->val = val;
    return node;
}

void free_tree(struct Node *tree) {
    if (tree != NULL) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

int main() {
    int cnt, num;
    while (~scanf("%d", &cnt)) {
        struct Node *head = NULL;
        result = -1;
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &num);
            head = insert(head, num);
            printf("%d\n", result);
        }
        free_tree(head);
    }

    return 0;
}