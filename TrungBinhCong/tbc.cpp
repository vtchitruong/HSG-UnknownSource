#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

#define inputFile "tbc.inp"
#define outputFile "tbc.out"

using namespace std;

int n;
vector<int> a;

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
    // Bước 1: Khởi tạo mảng b gồm các phần tử 0
    vector<int> b(n, 0);
    b[0] = a[0];

    // Bước 2: Lấy tổng tất cả phần tử trừ đi tổng của những phần tử đã có
    //         sẽ ra được phần tử b[i] đang xét.
    for (int i = 1; i < n; ++i)
    {
        // Tính tổng tất cả phần tử
        int sum_all = a[i] * (i + 1);
        
        // Tính tổng của những phần tử đã có trước đó trong mảng b
        int sum_before = accumulate(b.begin(), b.begin() + i + 1, 0);
        
        // Tính b[i] cần tìm
        b[i] = sum_all - sum_before;
    }

    return b;
}

void Output()
{
    vector<int> b = Process();
    
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    ofstream f;
    f.open(outputFile);

    for (int i = 0; i < n; ++i)
    {
        f << b[i] << ' ';
    }

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}