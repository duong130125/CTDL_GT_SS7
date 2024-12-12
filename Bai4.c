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

// Hàm kiểm tra xem hàng đợi có rỗng hay không
int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
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
    printf("Đã thêm: %d\n", value);
}

// Hàm trả về phần tử đầu tiên của hàng đợi (peek)
void peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hàng đợi trống, không thể trả về phần tử đầu tiên.\n");
        return;
    }
    printf("Phần tử đầu tiên trong hàng đợi: %d\n", queue->front->data);
}

// Hàm in các phần tử trong hàng đợi
void printQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Hàng đợi trống.\n");
        return;
    }

    struct Node *temp = queue->front;
    printf("Các phần tử trong hàng đợi: ");
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
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Thêm phần tử (Enqueue)\n");
        printf("2. In hàng đợi (Print Queue)\n");
        printf("3. Kiểm tra hàng đợi rỗng (Check if Queue is Empty)\n");
        printf("4. Xem phần tử đầu tiên (Peek)\n");
        printf("5. Thoát (Exit)\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhập giá trị cần thêm: ");
            scanf("%d", &value);
            enqueue(queue, value);
            break;
        case 2:
            printQueue(queue);
            break;
        case 3:
            printf("Hàng đợi có rỗng không? %s\n", isEmpty(queue) ? "Có" : "Không");
            break;
        case 4:
            peek(queue);
            break;
        case 5:
            printf("Đang thoát...\n");
            return 0;
        default:
            printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    }

    return 0;
}
