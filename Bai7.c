#include <stdio.h>
#include <stdlib.h>

// Cấu trúc dữ liệu cho phần tử trong hàng đợi ưu tiên
typedef struct Node
{
    int data;          // Dữ liệu của phần tử
    int priority;      // Độ ưu tiên của phần tử
    struct Node *next; // Con trỏ tới phần tử tiếp theo
} Node;

// Cấu trúc hàng đợi ưu tiên
typedef struct
{
    Node *front; // Con trỏ tới phần tử đầu tiên trong danh sách
} PriorityQueue;

// Hàm khởi tạo hàng đợi ưu tiên
void initQueue(PriorityQueue *pq)
{
    pq->front = NULL;
}

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(PriorityQueue *pq)
{
    return pq->front == NULL;
}

// Hàm thêm phần tử vào hàng đợi theo độ ưu tiên
void enqueue(PriorityQueue *pq, int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Không thể cấp phát bộ nhớ cho phần tử!\n");
        return;
    }

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    // Trường hợp hàng đợi rỗng
    if (isEmpty(pq))
    {
        pq->front = newNode;
    }
    else
    {
        Node *temp = pq->front;
        Node *prev = NULL;

        // Tìm vị trí thích hợp cho phần tử mới dựa trên độ ưu tiên
        while (temp != NULL && temp->priority >= priority)
        {
            prev = temp;
            temp = temp->next;
        }

        // Nếu phần tử có độ ưu tiên cao nhất, thêm vào đầu hàng đợi
        if (prev == NULL)
        {
            newNode->next = pq->front;
            pq->front = newNode;
        }
        else
        {
            prev->next = newNode;
            newNode->next = temp;
        }
    }

    printf("Thêm phần tử: %d với ưu tiên %d\n", data, priority);
    printQueue(pq); // In ra trạng thái của hàng đợi
}

// Hàm lấy phần tử có độ ưu tiên cao nhất ra khỏi hàng đợi
void dequeue(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    Node *temp = pq->front;
    pq->front = pq->front->next;
    printf("Lấy ra phần tử: %d với ưu tiên %d\n", temp->data, temp->priority);
    free(temp);

    printQueue(pq); // In ra trạng thái của hàng đợi
}

// Hàm trả về phần tử có độ ưu tiên cao nhất mà không xóa nó khỏi hàng đợi
void peek(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    printf("Phần tử có độ ưu tiên cao nhất là: %d với ưu tiên %d\n", pq->front->data, pq->front->priority);
}

// Hàm in trạng thái của hàng đợi
void printQueue(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Hàng đợi hiện tại: []\n");
        return;
    }

    Node *temp = pq->front;
    printf("Hàng đợi hiện tại: [");
    while (temp != NULL)
    {
        printf("%d(%d)", temp->data, temp->priority);
        if (temp->next != NULL)
        {
            printf(", ");
        }
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    PriorityQueue pq;
    initQueue(&pq);

    // Thêm phần tử vào hàng đợi
    enqueue(&pq, 10, 1);
    enqueue(&pq, 20, 2);
    enqueue(&pq, 30, 1);

    // Thực hiện dequeue
    dequeue(&pq);

    // Thêm phần tử vào hàng đợi
    enqueue(&pq, 40, 3);

    // Thực hiện dequeue
    dequeue(&pq);

    return 0;
}
