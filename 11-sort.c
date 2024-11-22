#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define ATTEMPTS 20

// �迭�� ����ϴ� �Լ�
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0); // 10�� ��� �� �� �ٲ�
    }
    printf("\n");
}

// ���� �����͸� �����ϴ� �Լ�
void generateRandomData(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // 0���� 999���� ���� ����
    }
}

// ���� ������ �����ϴ� �Լ�
void doSelectionSort(int arr[]) {
    printf("Selection Sort:\n");
    int selTemp[SIZE];
    for (int i = 0; i < SIZE; i++) selTemp[i] = arr[i]; // ���� �����͸� ������ ���� ����
    int selTempVal, selMinIdx;

    for (int i = 0; i < SIZE - 1; i++) {
        selMinIdx = i; // ���� �ܰ��� �ּҰ� ã�� ���� ���� ��ġ ����
        for (int j = i + 1; j < SIZE; j++) {
            if (selTemp[j] < selTemp[selMinIdx]) {
                selMinIdx = j; // �� ���� �� �߰� �� �ּҰ� ��ġ ����
            }
        }
        // ���� ��ġ�� �ּҰ� ��ġ�� ��ȯ
        selTempVal = selTemp[i];
        selTemp[i] = selTemp[selMinIdx];
        selTemp[selMinIdx] = selTempVal;

        // Ư�� �ܰ�(10, 30, 50, ..., 99)���� �迭 ���� ���
        if (i + 1 == 10 || (i + 1) % 20 == 10 || i + 1 == 99) {
            printf("\nStep %d:", i + 1);
            printArray(selTemp, SIZE);
        }
    }
}

// ���� ������ �����ϴ� �Լ�
void doInsertionSort(int arr[]) {
    int totalComparisons = 0; // ��� �õ����� �� Ƚ���� ����

    for (int attempt = 0; attempt < ATTEMPTS; attempt++) {
        int insTemp[SIZE];
        generateRandomData(insTemp); // ���ο� ���� ������ ����
        int insComparisons = 0; // �̹� �õ��� �� Ƚ��

        for (int i = 1; i < SIZE; i++) {
            int insKey = insTemp[i]; // ���� ������ ��
            int insJ = i - 1;
            // ���� ��ġ�� ã�� ���� ���������� ��
            while (insJ >= 0 && insTemp[insJ] > insKey) {
                insTemp[insJ + 1] = insTemp[insJ]; // ���� ���������� �̵�
                insJ--;
                insComparisons++;
            }
            insComparisons++; // ���� �õ� ��ü�� �񱳷� ����
            insTemp[insJ + 1] = insKey; // ���� ��ġ�� �� ����
        }
        totalComparisons += insComparisons; // �̹� �õ��� �� Ƚ���� ����
    }

    // ��� �� Ƚ�� ���
    printf("\nInsertion Sort Compare Average: %.0f\n", (double)totalComparisons / ATTEMPTS);

    // ���� ���� ��� ���
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

// ���� ������ �����ϴ� �Լ�
void doBubbleSort(int arr[]) {
    int totalMoves = 0; // ��� �õ����� �̵� Ƚ���� ����

    for (int attempt = 0; attempt < ATTEMPTS; attempt++) {
        int bubbleTemp[SIZE];
        generateRandomData(bubbleTemp); // ���ο� ���� ������ ����

        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (bubbleTemp[j] > bubbleTemp[j + 1]) {
                    // �� ��Ҹ� ��ȯ
                    int bubbleTempVal = bubbleTemp[j];
                    bubbleTemp[j] = bubbleTemp[j + 1];
                    bubbleTemp[j + 1] = bubbleTempVal;
                    totalMoves += 3; // �� ���� ��ȯ�� ���� 3�� �̵� �߻�
                }
            }
        }
    }

    // ��� �̵� Ƚ�� ���
    printf("\nBubble Sort Move Average: %.0f\n", (double)totalMoves / ATTEMPTS);

    // ���� ���� ��� ���
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

// ���� �Լ�
int main() {
    int randomData[SIZE];
    srand(time(NULL));
    generateRandomData(randomData);

    doSelectionSort(randomData);
    doInsertionSort(randomData);
    doBubbleSort(randomData);

    return 0;
}
