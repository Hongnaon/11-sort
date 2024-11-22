#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define ATTEMPTS 20

// 배열을 출력하는 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0); // 10개 출력 후 줄 바꿈
    }
    printf("\n");
}

// 랜덤 데이터를 생성하는 함수
void generateRandomData(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // 0부터 999까지 난수 생성
    }
}

// 선택 정렬을 수행하는 함수
void doSelectionSort(int arr[]) {
    printf("Selection Sort:\n");
    int selTemp[SIZE];
    for (int i = 0; i < SIZE; i++) selTemp[i] = arr[i]; // 원본 데이터를 복사해 정렬 수행
    int selTempVal, selMinIdx;

    for (int i = 0; i < SIZE - 1; i++) {
        selMinIdx = i; // 현재 단계의 최소값 찾기 위해 시작 위치 설정
        for (int j = i + 1; j < SIZE; j++) {
            if (selTemp[j] < selTemp[selMinIdx]) {
                selMinIdx = j; // 더 작은 값 발견 시 최소값 위치 갱신
            }
        }
        // 현재 위치와 최소값 위치를 교환
        selTempVal = selTemp[i];
        selTemp[i] = selTemp[selMinIdx];
        selTemp[selMinIdx] = selTempVal;

        // 특정 단계(10, 30, 50, ..., 99)에서 배열 상태 출력
        if (i + 1 == 10 || (i + 1) % 20 == 10 || i + 1 == 99) {
            printf("\nStep %d:", i + 1);
            printArray(selTemp, SIZE);
        }
    }
}

// 삽입 정렬을 수행하는 함수
void doInsertionSort(int arr[]) {
    int totalComparisons = 0; // 모든 시도에서 비교 횟수를 누적

    for (int attempt = 0; attempt < ATTEMPTS; attempt++) {
        int insTemp[SIZE];
        generateRandomData(insTemp); // 새로운 랜덤 데이터 생성
        int insComparisons = 0; // 이번 시도의 비교 횟수

        for (int i = 1; i < SIZE; i++) {
            int insKey = insTemp[i]; // 현재 삽입할 값
            int insJ = i - 1;
            // 삽입 위치를 찾기 위해 역방향으로 비교
            while (insJ >= 0 && insTemp[insJ] > insKey) {
                insTemp[insJ + 1] = insTemp[insJ]; // 값을 오른쪽으로 이동
                insJ--;
                insComparisons++;
            }
            insComparisons++; // 삽입 시도 자체를 비교로 간주
            insTemp[insJ + 1] = insKey; // 삽입 위치에 값 저장
        }
        totalComparisons += insComparisons; // 이번 시도의 비교 횟수를 누적
    }

    // 평균 비교 횟수 출력
    printf("\nInsertion Sort Compare Average: %.0f\n", (double)totalComparisons / ATTEMPTS);

    // 삽입 정렬 결과 출력
    printf("Insertion Sort Result:\n");
    int finalData[SIZE];
    generateRandomData(finalData);
    for (int i = 1; i < SIZE; i++) {
        int finalKey = finalData[i];
        int finalJ = i - 1;
        while (finalJ >= 0 && finalData[finalJ] > finalKey) {
            finalData[finalJ + 1] = finalData[finalJ];
            finalJ--;
        }
        finalData[finalJ + 1] = finalKey;
    }
    printArray(finalData, SIZE);
}

// 버블 정렬을 수행하는 함수
void doBubbleSort(int arr[]) {
    int totalMoves = 0; // 모든 시도에서 이동 횟수를 누적

    for (int attempt = 0; attempt < ATTEMPTS; attempt++) {
        int bubbleTemp[SIZE];
        generateRandomData(bubbleTemp); // 새로운 랜덤 데이터 생성

        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (bubbleTemp[j] > bubbleTemp[j + 1]) {
                    // 두 요소를 교환
                    int bubbleTempVal = bubbleTemp[j];
                    bubbleTemp[j] = bubbleTemp[j + 1];
                    bubbleTemp[j + 1] = bubbleTempVal;
                    totalMoves += 3; // 한 번의 교환에 대해 3번 이동 발생
                }
            }
        }
    }

    // 평균 이동 횟수 출력
    printf("\nBubble Sort Move Average: %.0f\n", (double)totalMoves / ATTEMPTS);

    // 버블 정렬 결과 출력
    printf("Bubble Sort Result:\n");
    int finalBubbleData[SIZE];
    generateRandomData(finalBubbleData);
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (finalBubbleData[j] > finalBubbleData[j + 1]) {
                int finalBubbleVal = finalBubbleData[j];
                finalBubbleData[j] = finalBubbleData[j + 1];
                finalBubbleData[j + 1] = finalBubbleVal;
            }
        }
    }
    printArray(finalBubbleData, SIZE);
}

// 메인 함수
int main() {
    int randomData[SIZE];
    srand(time(NULL));
    generateRandomData(randomData);

    doSelectionSort(randomData);
    doInsertionSort(randomData);
    doBubbleSort(randomData);

    return 0;
}
