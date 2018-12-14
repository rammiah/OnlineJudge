#include <stdio.h>
#include <stdlib.h>


struct Tree {
    int val;
    struct Tree *left, *right;
};


struct Tree *make(int val) {
    struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Tree *insert(struct Tree *root, int val) {
    if (root != NULL) {
        if (val > root->val) {
            root->right = insert(root->right, val);
        } else if (val < root->val) {
            root->left = insert(root->left, val);
        }
    } else {
        root = make(val);        
    }
    return root;
}

void pre_order(struct Tree *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(struct Tree *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->val);
        in_order(root->right);
    }
}

void post_order(struct Tree *root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->val);
    }
}

void free_tree(struct Tree *tree) {
    if (tree != NULL) {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}


int main() {
    int cnt, val;
    struct Tree *root;

    while (~scanf("%d", &cnt)) {
        root = NULL;
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &val);
            root = insert(root, val);
        }
        // 开始前中后序遍历
        pre_order(root);
        printf("\n");
        in_order(root);
        printf("\n");
        post_order(root);
        printf("\n");
    }


    return 0;
}