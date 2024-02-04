#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

#define inputFile "tbc.inp"
#define outputFile "tbc.out"

using namespace std;

int N;
vector<int> B;


void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> N;

    int x;
    for (int i = 0; i < N; ++i)
    {
        f >> x;
        B.push_back(x);
    }

    f.close();
}


vector<int> Process()
{
    // Bước 1: Khởi tạo mảng A gồm các phần tử 0
    vector<int> A(N, 0);
    A[0] = B[0];

    // Bước 2: Lấy tổng suy từ giá trị trung bình trừ đi tổng các phần tử hiện có
    for (int i = 1; i < N; ++i)
    {
        // Tính tổng suy từ giá trị trung bình
        int totalAverage = B[i] * (i + 1);
        
        // Tính tổng các phần tử hiện có trong mảng A
        int totalCurrent = accumulate(A.begin(), A.begin() + i + 1, 0);
        
        // Tính A[i]
        A[i] = totalAverage - totalCurrent;
    }

    return A;
}


void Output()
{
    vector<int> A = Process();

    ofstream f;
    f.open(outputFile);

    for (int i = 0; i < N; ++i)
    {
        f << A[i];
        if (i != N - 1) f << ' ';
    }

    f.close();
}


int main()
{
    Input();
    Output();

    return 0;
}