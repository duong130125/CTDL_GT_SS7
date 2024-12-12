#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Kích thước tối đa của hàng đợi

// Định nghĩa cấu trúc hàng đợi hai đầu
typedef struct
{
    int deque[MAX_SIZE]; // Mảng lưu trữ các phần tử
    int front, rear;     // Các chỉ số đầu và cuối của hàng đợi
} Deque;

// Hàm khởi tạo hàng đợi
void initDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(Deque *dq)
{
    return dq->front == -1;
}

// Hàm kiểm tra hàng đợi có đầy không
int isFull(Deque *dq)
{
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->rear == dq->front - 1);
}

// Hàm thêm phần tử vào đầu hàng đợi
void addFront(Deque *dq, int data)
{
    if (isFull(dq))
    {
        printf("Hàng đợi đầy!\n");
        return;
    }

    // Nếu hàng đợi rỗng
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {                             // Nếu đầu hàng đợi ở vị trí 0
        dq->front = MAX_SIZE - 1; // Quay vòng về cuối hàng đợi
    }
    else
    {
        dq->front--; // Di chuyển chỉ số đầu về trước
    }

    dq->deque[dq->front] = data; // Thêm phần tử vào đầu hàng đợi
    printf("Thêm phần tử vào đầu: %d\n", data);
}

// Hàm thêm phần tử vào cuối hàng đợi
void addRear(Deque *dq, int data)
{
    if (isFull(dq))
    {
        printf("Hàng đợi đầy!\n");
        return;
    }

    // Nếu hàng đợi rỗng
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX_SIZE - 1)
    {                 // Nếu cuối hàng đợi ở vị trí cuối mảng
        dq->rear = 0; // Quay vòng về đầu mảng
    }
    else
    {
        dq->rear++; // Di chuyển chỉ số cuối về phía sau
    }

    dq->deque[dq->rear] = data; // Thêm phần tử vào cuối hàng đợi
    printf("Thêm phần tử vào cuối: %d\n", data);
}

// Hàm lấy phần tử ra từ đầu hàng đợi
void removeFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    printf("Lấy ra phần tử từ đầu: %d\n", dq->deque[dq->front]);

    // Nếu chỉ còn một phần tử
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1; // Hàng đợi rỗng
    }
    else if (dq->front == MAX_SIZE - 1)
    {
        dq->front = 0; // Quay vòng về đầu mảng
    }
    else
    {
        dq->front++; // Di chuyển chỉ số đầu về phía sau
    }
}

// Hàm lấy phần tử ra từ cuối hàng đợi
void removeRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    printf("Lấy ra phần tử từ cuối: %d\n", dq->deque[dq->rear]);

    // Nếu chỉ còn một phần tử
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1; // Hàng đợi rỗng
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX_SIZE - 1; // Quay vòng về cuối mảng
    }
    else
    {
        dq->rear--; // Di chuyển chỉ số cuối về trước
    }
}

// Hàm in trạng thái hàng đợi
void printDeque(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Hàng đợi hiện tại: []\n");
        return;
    }

    printf("Hàng đợi hiện tại: [");
    int i = dq->front;
    while (i != dq->rear)
    {
        printf("%d, ", dq->deque[i]);
        i = (i + 1) % MAX_SIZE; // Quay vòng nếu cần thiết
    }
    printf("%d]\n", dq->deque[dq->rear]);
}

int main()
{
    Deque dq;
    initDeque(&dq);

    // Thêm các phần tử vào đầu và cuối hàng đợi
    addFront(&dq, 10);
    printDeque(&dq);

    addRear(&dq, 20);
    printDeque(&dq);

    addFront(&dq, 5);
    printDeque(&dq);

    // Thực hiện removeFront và removeRear
    removeFront(&dq);
    printDeque(&dq);

    removeRear(&dq);
    printDeque(&dq);

    return 0;
}
