#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i = 0, int j = 0) {
    if (i < k) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, k, n, Low, High, i, j + 1); // Рекурсивно заповнюємо наступний елемент у рядку
        }
        else {
            Create(a, k, n, Low, High, i + 1, 0); // Переходимо до наступного рядка
        }
    }
}

void Print(int** a, const int k, const int n, int i = 0, int j = 0) {
    if (i < k) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, k, n, i, j + 1); // Рекурсивно друкуємо наступний елемент у рядку
        }
        else {
            cout << endl;
            Print(a, k, n, i + 1, 0); // Переходимо до наступного рядка
        }
    }
}

int MinInRow(int* row, const int n, int j = 0, int minElement = INT_MAX) {
    if (j < n) {
        if (row[j] < minElement) {
            minElement = row[j];
        }
        return MinInRow(row, n, j + 1, minElement); // Рекурсивно шукаємо мінімум у рядку
    }
    return minElement;
}

int SumMinOddRows(int** a, const int k, const int n, int i = 1) {
    if (i < k) {
        int minElement = MinInRow(a[i], n);
        return minElement + SumMinOddRows(a, k, n, i + 2); // Рекурсивно обчислюємо суму для наступного непарного рядка
    }
    return 0;
}

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int k, n;

    cout << "k (rows) = ";
    cin >> k;
    cout << "n (columns) = ";
    cin >> n;

    // Динамічне виділення пам'яті для матриці
    int** a = new int* [k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    // Використовуємо рекурсивні функції
    Create(a, k, n, Low, High);
    cout << "Generated Matrix:" << endl;
    Print(a, k, n);

    int sumMinOddRows = SumMinOddRows(a, k, n);
    cout << "Sum of minimum elements in odd rows = " << sumMinOddRows << endl;

    // Очищення динамічної пам'яті
    for (int i = 0; i < k; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}