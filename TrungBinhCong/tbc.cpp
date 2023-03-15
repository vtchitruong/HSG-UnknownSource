#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

#define inputFile "tbc.inp"
#define outputFile "tbc.out"

using namespace std;

int n;
vector<int> a; // average

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream f;
    f.open(inputFile);

    f >> n;

    int x;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        a.push_back(x);
    }

    f.close();
}

vector<int> Process()
{
    // Bước 1: Khởi tạo mảng các số cần tìm
    vector<int> res(n, 0);
    res[0] = a[0];

    // Bước 2: Lấy tổng tất cả phần tử trừ đi tổng các phần tử đã có
    //         ra được phần tử res[i] tiếp theo cần tìm.
    for (int i = 1; i < n; ++i)
    {
        int sum_all = a[i] * (i + 1);
        int sum_before = accumulate(res.begin(), res.begin() + i + 1, 0);
        res[i] = sum_all - sum_before;
    }

    return res;
}

void Output()
{
    vector<int> res = Process();
    
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    ofstream f;
    f.open(outputFile);

    for (int i = 0; i < n; ++i)
    {
        f << res[i] << ' ';
    }

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}