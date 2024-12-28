// 作业3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("堆内存分配失败\n");
        exit(1);//因内存分配异常而退出程序
    }
    newNode->data = data;//将输入data赋值给节点里的data
    newNode->next = NULL;//节点里指针指向初始化为NULL
    return newNode;//返回新节点的地址
}

// 在链表头部插入节点
void insertAtHead(Node** head, int data) 
{
    Node* newNode = createNode(data);
    newNode->next = *head;//将当前指针指向头部节点
    *head = newNode;//将新节点设置为头部节点
}

// 在链表尾部插入节点
void insertAtTail(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 删除节点
void deleteNode(Node** head, int key) 
{
    Node* temp = *head, * prev = NULL;

    // 如果头部节点就是要删除的节点
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // 搜索要删除的节点
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果没有找到
    if (temp == NULL) return;

    // 从链表中删除节点
    prev->next = temp->next;
    free(temp);
}

// 打印链表
void printList(Node* node) 
{
    while (node != NULL) 
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 主函数
int main()
{
    Node* head = NULL;

    insertAtHead(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtHead(&head, 5);
    insertAtTail(&head, 40);

    printf("Linked List: ");
    printList(head);

    deleteNode(&head, 20);
    printf("Linked List after deleting 20: ");
    printList(head);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
