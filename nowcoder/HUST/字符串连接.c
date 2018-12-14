#include <stdio.h>
#include <stdlib.h>

struct Char{
    char ch;
    struct Char *next;
};

struct Char *create(char ch) {
    struct Char *node = (struct Char *)malloc(sizeof(struct Char));
    node->ch = ch;
    node->next = NULL;
    
    return node;
}

void free_list(struct Char *head) {
    struct Char *next;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    struct Char *str1, *str2, *end;
    char ch;
    while (~scanf("%c", &ch)) {
        str2 = NULL;
        str1 = create(ch);
        end = str1;
        while ((ch = getchar()) != ' ') {
            end = end->next = create(ch);
        }
        while ((ch = getchar()) != '\n') {
            if (str2 == NULL) {
                str2 = create(ch);
                end = str2;
            } else {
                end = end->next = create(ch);
            }
        }
        // 开始连接操作
        end = str1;
        while (end->next != NULL) {
            end = end->next;
        }
        // 连接
        end->next = str2;
        // 进行输出
        end = str1;
        while (end != NULL) {
            putchar(end->ch);
            end = end->next;
        }
        putchar('\n');
    }
    
    return 0;
}
