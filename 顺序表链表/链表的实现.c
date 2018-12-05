
#include<stdio.h>
#include<stdlib.h>

typedef int LinkType; //�洢��Ԫ����
typedef struct linkNode {
    LinkType key; //����keyֵ
    struct linkNode *next; //ָ����һ�����
} LNode, *LinkList;//LNode ����ͨ���ͣ�LinkList��ָ������

//����LinkType���ͣ�ʹ������ṹ�ʺϸ����������͡�ÿ������Ľ�㣬����һ��ֵ��key��һ��ָ����next��
//����������������LNode��LinkList���������д����ǵȼ۵ġ�

/**
* ����ͷ���
*/
LinkList createHead_link() {
    static int n = 0;
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    return head;
}
//�����Ƕ�̬����һ���ڴ浥Ԫ�洢ͷ��㣬Ҳ���Բ���˳����У�ʹ��LNode head����ϵͳ�����ڴ档

/**
* ͷ�巨
*/
void insertFirst_link(LinkList head, LinkType val) {
    LinkList node = (LinkList)malloc(sizeof(LNode));
    node->key = val;
    node->next = head->next;
    head->next = node;
}
//�ڴ�ͷ���������У�ͷ�巨��ʾÿ�ν������뵽ͷ���ĺ��档�ڲ���ͷ���������У�
//��������Ľ����������е�һ������ǰ�棬����֮��Ϊ��һ����㡣

/**
* β�巨
*/
void insertLast_link(LinkList head, LinkType val) {
    LinkList temp = head;
    while (temp->next != NULL) //�ҵ�ĩβ���
        temp = temp->next;
    LinkList node = (LinkList)malloc(sizeof(LNode));
    node->key = val;
    temp->next = node;
    node->next = NULL;
}

//����β�巨���ԣ������ִ�ͷ���Ͳ���ͷ��������
//ֻ��������Ľ��嵽��������һ��λ�á������Ҫ��ѭ���������ĩβ��

/**
* ָ��λ�ò��룬position��ʾ������λ�ã�0��ʾͷ����ĵ�һ�����
*/
void insert_link(LinkList head, int position, LinkType val) {
    if (position < 0) //-1 ��ĩβ��ӣ�����β�巨
        insertLast_link(head, val);
    else if (position == 0) //�ӵ�һ�������룬����ͷ�巨
        insertFirst_link(head, val);
    else { //
        LinkList temp = head;
        while (temp->next != NULL && --position > 0) { //�ҵ����ʵ�λ�ý��
            temp = temp->next;
        }
        LinkList node = (LinkList)malloc(sizeof(LNode));
        node->key = val;
        node->next = temp->next;
        temp->next = node;
    }
}
//�ȸ����±��ҵ��������λ�ã�Ȼ������㡣�Ա�˳������ƶ�ָ��λ�õĺ�����㣬�ٲ����µĽ�㡣

/**
* ɾ���ڵ㣨ָ��λ�ã�,�±��0��ʼ
*/
void removeNode_link_fetch(LinkList head, int index, LinkType key) {
    if (index < 0) {
        printf("ָ���±�ֵ����ȷ\n");
        return;
    }
    LinkList node = head;
    int i = 0;
    while (!node->next || i < index) { //Ѱ��ָ���±�Ľڵ㣬����ѭ��ʱ��i==index
        node = node->next;
        i++;
    }
    if (i == index) { //�ҵ�ָ���ڵ�
        LinkList temp = node->next; //temp ��Ҫ��ɾ���Ľڵ�
        node->next = temp->next;
        temp->next = NULL;
        key = temp->key;
        free(temp);
    }
    else { //û�ҵ�
        printf("û�ҵ�ָ���±��ֵ");
    }
}
//�±��0��ʼ����ʾͷ����ĵ�һ����㡣���ҵ���ɾ���Ľ�㣬ȡ��keyֵ����ɾ���ý�㡣

/**
* ɾ���ڵ㣨ָ���ڵ㣩
*/
void removeNode_link(LinkList head, LinkType val) {
    LinkList node = head;
    while (!node->next) {
        if (node->next->key == val)
            break;
        node = node->next;
    }
    if (node->next != NULL) { //�ҵ�Ҫɾ���Ľڵ�
        LinkList temp = node->next; //temp ��Ҫ��ɾ���Ľڵ�
        node->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else {
        printf("û�ҵ�Ҫɾ���Ľڵ�\n");
    }
}
//���ȸ���valֵ���ҵ���ɾ���Ľ�㣬���ɾ��֮��

/**
* ��������
*/
void destory_link(LinkList head) {
    while (head->next != NULL) {
        LinkList node = head->next;
        head->next = node->next;
        free(node);
    }
}
//�ͷŵ���ͷ���֮������н��ռ�õ��ڴ档

/**
��������
*/
void print_list(LinkList head)
{
    int n = 0;
    LinkList p = head;
    if (p == NULL) { printf("list is empty!\n"); exit(0); }
    while (p->next != NULL) {
        printf("%d\n", p->next->key);
        n++;
        p = p->next;
    }
    printf("\n total %d nodes\n", n);
}

void reverse(LinkList head)
{
    LinkList p, q;
    p = head->next;
    head->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}

int main_linked_list()
{
    int n=0;
    LinkList head = createHead_link();
    insertLast_link(head, 6);
    insertFirst_link(head, 9);
    insert_link(head, 1, 3);
    insert_link(head, 2, 4);
    insert_link(head, 3, 5);
    removeNode_link(head, 3);
    removeNode_link(head, 4);
    print_list(head);
    reverse(head);
    print_list(head);
    destory_link(head);
    return(1);
}