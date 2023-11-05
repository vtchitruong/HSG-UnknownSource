#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define inputFile "chain4.inp"
#define outputFile "chain4.out"

using namespace std;

int n; // Số lượng chuỗi
vector<int> L; // Độ dài của mỗi chuỗi

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    int x;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        L.push_back(x);
    }

    f.close();
}

int Process()
{
    // Sắp xếp số vòng trong mỗi chuỗi tăng dần
    sort(L.begin(), L.end());

    // Số lần mở vòng
    int remove_times = 0;

    // Mở từng vòng, bắt đầu từ chuỗi đầu tiên, có ít vòng nhất (đã sort ở trên)
    while (L[0] > 0)
    {
        // Mở 1 vòng
        L[0]--;

        // Xóa bỏ chuỗi cuối cùng
        L.pop_back();

        // Cộng thêm 1 lần mở vòng
        remove_times++;
        
        // Nếu chỉ còn một chuỗi duy nhất thì dừng thuật toán
        if (L.size() == 1)
            return remove_times;

        // Nếu chuỗi đầu tiên không còn vòng nào để mở nữa
        // thì "xóa bỏ" chuỗi này khỏi vector L để chuẩn bị mở vòng của chuỗi tiếp theo
        if (L[0] == 0)
        {
            L.erase(L.begin());

            // Nếu chỉ còn một chuỗi duy nhất thì dừng thuật toán
            if (L.size() == 1)
            {
                return remove_times;
            }
        }
    }
    return remove_times;
}

void Output()
{
    int res = Process();
    
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