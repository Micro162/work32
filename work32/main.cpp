#include <iostream>
#include <cstdlib>

using namespace std;

//  матрица
template <typename T>
class Matrix {
private:
    int rows, cols;
    T** a;

public:
    // Конструктор
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        a = new T * [rows];        
        for (int i = 0; i < rows; i++)
            a[i] = new T[cols]; 
    }

  
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] a[i];
        delete[] a;      
    }

    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> a[i][j];
    }

    void randomFill(int min = 0, int max = 9) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                a[i][j] = min + rand() % (max - min + 1);
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    T minElement() const {
        T min = a[0][0];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (a[i][j] < min)
                    min = a[i][j];
        return min;
    }

    T maxElement() const {
        T max = a[0][0];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (a[i][j] > max)
                    max = a[i][j];
        return max;
    }

    Matrix operator+(const Matrix& m) {
        Matrix r(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                r.a[i][j] = a[i][j] + m.a[i][j];
        return r;
    }

    Matrix operator-(const Matrix& m) {
        Matrix r(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                r.a[i][j] = a[i][j] - m.a[i][j];
        return r;
    }

    Matrix operator*(const Matrix& m) {
        Matrix r(rows, m.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++) {
                r.a[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    r.a[i][j] += a[i][k] * m.a[k][j];
            }
        return r;
    }

    Matrix operator/(const Matrix& m) {
        Matrix r(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                r.a[i][j] = a[i][j] / m.a[i][j];
        return r;
    }
};

int main() {
    srand(1); 

    Matrix<int> A(2, 2), B(2, 2);

    A.randomFill();
    B.randomFill();

    cout << "A:\n";
    A.print();

    cout << "B:\n";
    B.print();

    Matrix<int> C = A + B;

    cout << "A + B:\n";
    C.print();

    cout << "Min A: " << A.minElement() << endl;
    cout << "Max A: " << A.maxElement() << endl;

    return 0;
}
