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
vector<vector<int>> choices; // Mảng chứa các cách chọn bộ k số


void Input()
{
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


// Hàm tạo bộ k số từ n số bằng back-tracking và đệ quy
void Generate(vector<int>& choice, int next)
{
    // Nếu một bộ đã có đủ k số thì nạp vào choices và dừng đệ quy
    if (choice.size() == k)
    {
        choices.push_back(choice);
        return;
    }

    // Ứng với mỗi số x trong n số:
    // - Nạp số x này vào bộ đang xét chọn
    // - Gọi đệ quy để nạp số tiếp theo vào vị trí tiếp theo của bộ đang xét chọn
    // - Gỡ bỏ x ở vị trí cuối của bộ đang xét chọn 
    for (int i = next; i < a.size(); ++i)
    {
        choice.push_back(a[i]);
        Generate(choice, i + 1);
        choice.pop_back();
    }
}


lli Process()
{
    // Khởi tạo biến choice nhằm phục vụ cho việc gọi đệ quy
    vector<int> choice;
    Generate(choice, 0);

    // Mảng chứa các điểm thưởng
    vector<int> bonus;

    // Tính điểm thưởng của từng bộ số rồi nạp vào bonus
    for (int i = 0; i < choices.size(); ++i)
    {
        int m = *max_element(choices[i].begin(), choices[i].end());
        bonus.push_back(m);
    }

    // Tính tổng điểm thưởng
    lli sum_bonus = (lli)accumulate(bonus.begin(), bonus.end(), 0);
    return sum_bonus % (lli)(10E9 + 7);
}

void Output()
{
    int res = Process();

    ofstream f;
    f.open(outputFile);

    f << res;

    f.close();
}


void Show_choices()
{
    for (vector<int> choice : choices)
    {
        for (int num : choice)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
}


int main()
{
    Input();
    Output();
    Show_choices();

    return 0;
}