#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

#define inputFile "xoso.inp"
#define outputFile "xoso.out"

using namespace std;

typedef long long int lli;

int n, k;
vector<int> a;
vector<vector<int>> cac_cachchon; // Các cách chọn bộ k số

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream f;
    f.open(inputFile);

    f >> n >> k;

    int x;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        a.push_back(x);
    }

    f.close();
}

// Hàm tạo bộ k số từ n số bằng đệ quy
void Generate(vector<int>& cachchon_hientai, int batdau)
{
    // Nếu một bộ đã có đủ k số thì dừng đệ quy
    // và nạp vào vector cac_cachchon
    if (cachchon_hientai.size() == k)
    {
        cac_cachchon.push_back(cachchon_hientai);
        return;
    }

    for (int i = batdau; i < a.size(); ++i)
    {
        cachchon_hientai.push_back(a[i]);
        Generate(cachchon_hientai, i + 1);
        cachchon_hientai.pop_back();
    }
}

void Get_cac_cachchon()
{
    vector<int> cachchon_hientai;
    Generate(cachchon_hientai, 0);
}

lli Process()
{
    vector<int> cachchon_hientai;
    Generate(cachchon_hientai, 0);

    vector<int> diem_thuong;

    for (int i = 0; i < cac_cachchon.size(); ++i)
    {
        int m = *max_element(cac_cachchon[i].begin(), cac_cachchon[i].end());
        diem_thuong.push_back(m);
    }

    lli tong_diem = (lli)accumulate(diem_thuong.begin(), diem_thuong.end(), 0);
    return tong_diem % (lli)(10E9 + 7);
}

void Output()
{
    int res = Process();

    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    ofstream f;
    f.open(outputFile);

    f << res;

    f.close();
}

int main()
{
    Input();
    Output();

    return 0;
}