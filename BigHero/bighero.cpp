#include <iostream>
#include <fstream>
#include <vector>

#define inputFile "bighero.inp"
#define outputFile "bighero.out"

using namespace std;

int n;
vector<vector<pair<int, int>>> a; // danh sách đỉnh kề, mỗi đỉnh kề gồm 2 thành phần: first là tên đỉnh, second là năng lượng hao phí z
vector<pair<int, int>> cost; // mảng lưu kết quả của các phương án, trong đó first là power, second là loss

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    a.resize(n + 1); // Khởi tạo n + 1 vector (chưa có phần tử) tương ứng n đỉnh

    int u, v, z; // z: power
    while (!f.eof())
    {
        f >> u >> v >> z;   
        a[u].push_back({v, z});
    }

    f.close();
}

void DFS(int current_node, int current_power, int current_loss)
{
    int next_node, next_power, next_loss;
    
    // Duyệt tất cả các đỉnh kề với đỉnh current
    for (vector<pair<int, int>>::iterator it = a[current_node].begin(); it != a[current_node].end(); ++it)
    {       
        // Lưu tạm đỉnh kề vào next
        next_node = (*it).first;

        // Nếu đi đến đỉnh next mà mất mạng thì cộng mạng vào next_loss
        if ((*it).second == 0)
        {            
            next_loss = current_loss + 1;
            next_power = current_power; 
        }
        else // Ngược lại, không mất mạng, thì cộng năng lượng vào next_power
        { 
            next_power = current_power + (*it).second;
            next_loss = current_loss;
        }

        if (next_node == n) // tới đích
        {
            cost.push_back({next_power, next_loss}); // Thêm kết quả của một phương án vào mảng cost
            return;
        }
        
        // Gọi đệ quy với đỉnh xuất phát là đỉnh next
        DFS(next_node, next_power, next_loss);
    }
}

// Hàm minCost tìm kết quả của phương án tốt nhất
pair<int, int> minCost()
{
    // Giả sử phương án đầu tiên là tốt nhất
    int min_power = cost[0].first;
    int min_loss = cost[0].second;

    // Duyệt các phương án tiếp theo
    for (int i = 1; i < cost.size(); ++i)
    {
        // Nếu loss ít hơn thì chọn
        if (cost[i].second < min_loss)
        {
            min_loss = cost[i].second;
            min_power = cost[i].first;
        }
        else
        {
            // Nếu loss không thay đổi, thì xét tới power
            // Nếu power ít hơn thì chọn
            if (cost[i].second == min_loss)
            {
                if (cost[i].first < min_power)
                {
                    min_power = cost[i].first;
                }
            }
        }
    }

    return {min_power, min_loss};
}

void Output()
{
    // Gọi hàm DFS để hoàn thành mảng cost
    DFS(1, 0, 0); // Xuất phát từ đỉnh 1, 0 power và 0 loss

    // Gọi hàm minCost để tìm kết quả tốt nhất
    pair<int, int> res = minCost();

    ofstream f;
    f.open(outputFile);

    f << res.first << endl;
    f << res.second;

    f.close();
}

// Hàm in danh sách đỉnh kề
void show_a()
{
    for (int i = 1; i < n + 1; ++i)
    {
        cout << i << ": ";
        for (vector<pair<int, int>>::iterator it = a[i].begin(); it != a[i].end(); ++it)
        {
            cout << "{" << (*it).first << ", " << (*it).second << "} ";
        }
        cout << endl;
    }
}

// Hàm in mảng cost
void show_cost()
{
    for (int i = 0; i < cost.size(); ++i)
    {
        cout << "{" << cost[i].first << ", " << cost[i].second << "}" << endl;
    }
}

int main()
{
    Input();
    Output();
    show_a();
    show_cost();

    return 0;
}