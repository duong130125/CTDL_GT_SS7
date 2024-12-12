#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5 // Kích thước tối đa của hàng đợi

// Định nghĩa cấu trúc phần tử trong hàng đợi
typedef struct
{
    int priority;  // Mức độ ưu tiên
    char data[50]; // Dữ liệu (ví dụ tên công việc)
} Element;

// Định nghĩa cấu trúc hàng đợi ưu tiên
typedef struct
{
    Element queue[MAX_SIZE]; // Mảng lưu trữ các phần tử
    int front, rear;         // Các chỉ số đầu và cuối của hàng đợi
} PriorityQueue;

// Hàm khởi tạo hàng đợi
void initQueue(PriorityQueue *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(PriorityQueue *pq)
{
    return pq->front == -1;
}

// Hàm kiểm tra hàng đợi có đầy không
int isFull(PriorityQueue *pq)
{
    return pq->rear == MAX_SIZE - 1;
}

// Hàm thêm phần tử vào hàng đợi (enqueue)
void enqueue(PriorityQueue *pq, int priority, const char *data)
{
    if (isFull(pq))
    {
        printf("Hàng đợi đầy!\n");
        return;
    }

    // Tạo phần tử mới
    Element newElement;
    newElement.priority = priority;
    strncpy(newElement.data, data, sizeof(newElement.data) - 1);
    newElement.data[sizeof(newElement.data) - 1] = '\0';

    // Nếu hàng đợi rỗng, thêm phần tử vào vị trí đầu tiên
    if (isEmpty(pq))
    {
        pq->front = pq->rear = 0;
        pq->queue[pq->rear] = newElement;
    }
    else
    {
        // Tìm vị trí thích hợp để thêm phần tử theo ưu tiên
        int i = pq->rear;
        while (i >= pq->front && pq->queue[i].priority > priority)
        {
            pq->queue[i + 1] = pq->queue[i];
            i--;
        }
        pq->queue[i + 1] = newElement;
        pq->rear++;
    }

    // In ra trạng thái hàng đợi sau khi thêm phần tử
    printf("Thêm phần tử (%d, \"%s\"): Hàng đợi không rỗng\n", priority, data);
}

// Hàm lấy phần tử có ưu tiên cao nhất ra khỏi hàng đợi (dequeue)
void dequeue(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    // Phần tử có ưu tiên cao nhất sẽ ở vị trí đầu tiên
    Element highestPriorityElement = pq->queue[pq->front];
    printf("Phần tử ưu tiên cao nhất: \"%s\" (ưu tiên %d)\n", highestPriorityElement.data, highestPriorityElement.priority);

    // Xóa phần tử ở đầu hàng đợi
    for (int i = pq->front; i < pq->rear; i++)
    {
        pq->queue[i] = pq->queue[i + 1];
    }
    pq->rear--;
    if (pq->rear == -1)
        pq->front = -1;

    // In ra trạng thái hàng đợi sau khi lấy phần tử
    printf("Lấy ra phần tử: \"%s\"\n", highestPriorityElement.data);
}

// Hàm in trạng thái hàng đợi
void printQueue(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    printf("Các phần tử trong hàng đợi: ");
    for (int i = pq->front; i <= pq->rear; i++)
    {
        printf("\"%s\" (ưu tiên %d) ", pq->queue[i].data, pq->queue[i].priority);
    }
    printf("\n");
}

int main()
{
    PriorityQueue pq;
    initQueue(&pq);

    // Thêm các phần tử vào hàng đợi
    enqueue(&pq, 2, "Task A");
    printQueue(&pq);

    enqueue(&pq, 1, "Task B");
    printQueue(&pq);

    enqueue(&pq, 3, "Task C");
    printQueue(&pq);

    // Thực hiện dequeue 2 lần
    dequeue(&pq);
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    return 0;
}
