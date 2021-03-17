#include <stdio.h>
#include <stdbool.h>

int main()
{
    /*
     int형 2차원 배열(5*5)에 1부터 25까지 시계방향으로 채워넣기 연습

     5 -> 4  +  (0,4) -> (4,4) i == j
     4 -> 3  -  (4,0) -> (1,0)
     3 -> 2  +  (1,3) -> (3,3) i == j
     2 -> 1  -  (3,1) -> (2,1)
     1       +  -> (2,2)       i == j
     */

    int nArr[5][5] = { 0 };
    int i = 0, j = -1, k = 1, swch = 1, a = 0, b = 0;
    bool isCol = true;
    while (true) {
        while (isCol) {
            j += swch;
            nArr[i][j] = k++;
            if (j == (4 + a) && swch == 1) { a--; isCol = false; }
            else if (j == b && swch == -1) { b++; isCol = false; }
        }
        if (k >= 25) break;
        i += swch;
        nArr[i][j] = k++;
        if (i == j && swch == 1) { swch = -1; isCol = true; }
        else if (i == b && swch == -1) { swch = 1; isCol = true; }
    }

    // 출력테스트
    for (int c = 0; c < 5; c++) {
        for (int d = 0; d < 5; d++) {
            printf("%d ", nArr[c][d]);
        }
        printf("\n");
    }

    return 0;
}