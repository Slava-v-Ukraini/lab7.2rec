#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i = 0, int j = 0) {
    if (i < k) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, k, n, Low, High, i, j + 1); // ���������� ���������� ��������� ������� � �����
        }
        else {
            Create(a, k, n, Low, High, i + 1, 0); // ���������� �� ���������� �����
        }
    }
}

void Print(int** a, const int k, const int n, int i = 0, int j = 0) {
    if (i < k) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, k, n, i, j + 1); // ���������� ������� ��������� ������� � �����
        }
        else {
            cout << endl;
            Print(a, k, n, i + 1, 0); // ���������� �� ���������� �����
        }
    }
}

int MinInRow(int* row, const int n, int j = 0, int minElement = INT_MAX) {
    if (j < n) {
        if (row[j] < minElement) {
            minElement = row[j];
        }
        return MinInRow(row, n, j + 1, minElement); // ���������� ������ ����� � �����
    }
    return minElement;
}

int SumMinOddRows(int** a, const int k, const int n, int i = 1) {
    if (i < k) {
        int minElement = MinInRow(a[i], n);
        return minElement + SumMinOddRows(a, k, n, i + 2); // ���������� ���������� ���� ��� ���������� ��������� �����
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

    // �������� �������� ���'�� ��� �������
    int** a = new int* [k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    // ������������� ��������� �������
    Create(a, k, n, Low, High);
    cout << "Generated Matrix:" << endl;
    Print(a, k, n);

    int sumMinOddRows = SumMinOddRows(a, k, n);
    cout << "Sum of minimum elements in odd rows = " << sumMinOddRows << endl;

    // �������� �������� ���'��
    for (int i = 0; i < k; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}