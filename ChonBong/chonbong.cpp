#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#define inputFile "chonbong.inp"
#define outputFile "chonbong.out"

using namespace std;

int n, k; // n: số bóng, k: số màu
vector<int> color; // Mảng color với i là mã màu, color[i] là số bóng có màu i

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> k;

    color.resize(n + 1, 0); // Khởi tạo số bóng của mỗi màu đều là 0

    // Lần lượt đọc từng mã màu của các quả bóng
    int c; // color
    for (int i = 0; i < n; ++i)
    {
        f >> c;
        color[c]++; // Nếu mã màu là c thì tăng 1 cho color[c]
    }

    f.close();
}

int Process()
{
    // Sắp xếp mảng color giảm dần
    sort(color.begin(), color.end(), greater<>());

    int point = 0; // điểm sẽ đạt được

    int i = 0;
    while (true)
    {
        // Tại vị trí i, xét số bóng màu i và số bóng màu i + 1
        // Lấy một số bóng màu i và i + 1 ghép cặp, ta được số điểm point
        // point = số bóng của mã màu ít hơn
        // Lấy hiệu số bóng (là số bóng còn lại sau khi ghép cặp) gán cho color[i + 1]
        // Tăng i lên để xét mã màu khác
        if (color[i] > color[i + 1])
        {
            point += (color[i + 1] * 2);
            color[i + 1] = color[i] - color[i + 1];
            i += 1;
        }
        else if (color[i] == color[i + 1])
        {
            point += (color[i] * 2);
            color[i + 1] = 0;
            i += 2; // Tăng 2 vì sau khi ghép cặp, không còn quả bóng nào có mã màu i và i + 1
        }
        else
        {
            point += (color[i] * 2);
            color[i + 1] = color[i + 1] - color[i];
            i += 1;
        }       
        
        // color[i] == 0: Vì mảng color đã sắp xếp giảm dần, nên khi gặp phần tử 0 nghĩa là không còn quả bóng nào nữa
        // color[i + 1] = 0: Chỉ còn những quả bóng màu i, không còn bóng màu i + 1, nên không thể ghép cặp được nữa
        if (color[i] == 0 || color[i + 1] == 0) break;
    }

    return point;
}

void show_color()
{
    for (int i = 0; i < n + 1; ++i)
    {
        cout << i << ": " << color[i] << endl;
    }
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
    show_color();

    return 0;
}