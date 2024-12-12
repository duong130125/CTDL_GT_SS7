#include <stdio.h>
#include <stdlib.h>

// Cấu trúc nút cho danh sách liên kết
struct Node
{
    int data;
    struct Node *next;
};

// Cấu trúc hàng đợi sử dụng danh sách liên kết
struct Queue
{
    struct Node *front; // con trỏ đến phần tử đầu tiên (đầu hàng)
    struct Node *rear;  // con trỏ đến phần tử cuối cùng (cuối hàng)
};

// Hàm khởi tạo hàng đợi trống
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Hàm thêm phần tử vào hàng đợi (enqueue)
void enqueue(struct Queue *queue, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL)
    { // Nếu hàng đợi trống
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Phần tử: %d\n", value);
}

// Hàm lấy phần tử ra khỏi hàng đợi (dequeue)
void dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    { // Kiểm tra hàng đợi rỗng
        printf("Hàng đợi trống, không thể xếp hàng.\n");
        return;
    }

    struct Node *temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;

    // Nếu hàng đợi trở nên trống sau khi dequeue
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    printf("Phần tử lấy ra khỏi đầu hàng đợi: %d\n", dequeuedValue);
}

// Hàm in các phần tử trong hàng đợi
void printQueue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Hàng đợi đang trống.\n");
        return;
    }

    struct Node *temp = queue->front;
    printf("Hàng đợi: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm chính để kiểm tra
int main()
{
    // Tạo hàng đợi trống
    struct Queue *queue = createQueue();

    // Thêm phần tử vào hàng đợi
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // In ra tất cả các phần tử trong hàng đợi
    printQueue(queue);

    // Thực hiện dequeue và in trạng thái hàng đợi sau mỗi lần
    dequeue(queue);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    // Cố gắng dequeue khi hàng đợi rỗng
    dequeue(queue);

    return 0;
}
