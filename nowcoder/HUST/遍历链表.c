#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *create(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    return node;
}

void free_list(struct Node *node) {
    struct Node *n;
    while (node != NULL) {
        n = node->next;
        free(node);
        node = n;
    }
}

int main() {
    struct Node *head = NULL, *end = NULL;
    int cnt, val;

    while (~scanf("%d", &cnt)) {
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &val);
            if (i > 0) {
                struct Node *crea = create(val);
                // 将数据插入到链表中
                if (head->val > val) {
                    crea->next = head;
                    head = crea;
                } else {
                    struct Node *t = head;
                    while (t->next != NULL && t->next->val < val) {
                        t = t->next;
                    }
                    // 插入到t后面即可
                    crea->next = t->next;
                    t->next = crea;
                }
            } else {
                head = create(val);
            }
        }
        end = head;
        while (end != NULL) {
            printf("%d%c", end->val, end->next ? ' ' : '\n');
            end = end->next;
        }
        free_list(head);
        head = end = NULL;
    }
    return 0;
}