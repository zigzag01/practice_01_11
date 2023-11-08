#include <iostream>
#include <iomanip>
using namespace std;

// Белоушко Елизавета

// Найти наименьший элемент последней строчки матрицы
// Посчитать сумму эл-тов столбца, в котором расположен этот эл-т

void MaSize(int& n, int& m) {
    do {
        cout << "Кол-во строк массива: ";
        cin >> n;
    } while (n > 100);
    do {
        cout << "Кол-во столбцов массива: ";
        cin >> m;
    } while (m > 100);
}

void RandMa(int Ma[100][100], int& n, int& m, int& i, int& j) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            Ma[i][j] = rand() % 10 - 5;
        }
    }
}

void Print(int Ma[100][100], int& n, int& m, int& i, int& j) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << Ma[i][j] << " ";
        }
        cout << endl;
    }
}

int MumSearch(int Ma[100][100], int& n, int& m) {
    int nmin = 0;
    int min = Ma[n - 1][0];
    for (int k = 0; k < m; k++) {
        if (Ma[n - 1][k] < min) {
            min = Ma[n - 1][k];
            nmin = k;
        }
    }
    return nmin;
}

int Sum(int Ma[100][100], int& n, int& value) {
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += Ma[i][value];
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "rus");

    int Ma[100][100];
    int n, m, i, j, value, answer;
    int num = 0; //номер столбца минимального эл-та строки
    int min = 0; //минимальный эл-т

    MaSize(n, m); // задает размер матрицы
    RandMa(Ma, n, m, i, j); // выводит случ эл-ты от 0 до 100
    Print(Ma, n, m, i, j); // выводит матрицу
    value = MumSearch(Ma, n, m); // ищет минимальный эл-т последней строки матрицы
    answer = Sum(Ma, n, value); // выводит результат

    cout << "Ответ: " << answer;
}
