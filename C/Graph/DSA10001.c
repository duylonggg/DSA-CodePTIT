#include <stdio.h>
#include <stdlib.h>

int N, M;
char matrix[501][501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef struct Node {
    int x, y, turn;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *back;
} Queue;

void initQueue(Queue *q) {
    q->front = q->back = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void push(Queue *q, int x, int y, int turn) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = x;
    temp->y = y;
    temp->turn = turn;
    temp->next = NULL;
    
    if (q->back == NULL) {
        q->front = q->back = temp;
        return;
    }
    
    q->back->next = temp;
    q->back = temp;
}

Node pop(Queue *q) {
    Node result = {-1, -1, -1, NULL};
    if (isEmpty(q)) return result;
    
    Node* temp = q->front;
    result = *temp;
    q->front = q->front->next;

    if (q->front == NULL) q->back = NULL;

    free(temp);
    return result;
}

char* BFS(int x, int y) {
    Queue queue;
    initQueue(&queue);
    
    push(&queue, x, y, 0);
    
    while (!isEmpty(&queue)) {
        Node cur = pop(&queue);

        if (cur.turn > 2) continue;
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x;
            int ny = cur.y;
            
            while (1) {
                nx += dx[i];
                ny += dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M || matrix[nx][ny] == '*')
                    break;

                if (matrix[nx][ny] == 'T')
                    return "YES";

                if (matrix[nx][ny] == '.') {
                    matrix[nx][ny] = '*';
                    push(&queue, nx, ny, cur.turn + 1);
                }
            }
        }
    }
    return "NO";
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &N, &M);
        getchar();

        int sx, sy;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%c", &matrix[i][j]);
                if (matrix[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
            getchar();
        }

        puts(BFS(sx, sy));
    }
    return 0;
}
