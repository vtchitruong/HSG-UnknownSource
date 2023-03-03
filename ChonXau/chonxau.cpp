#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // sort

#define inputFile "chonxau.inp"
#define outputFile "chonxau.out"

using namespace std;

string s1, s2;
vector<pair<char, int>> v1;
vector<pair<char, int>> v2;
vector<char> res;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> s1;
    f >> s2;

    f.close();
}

void Init()
{
    // v1.resize(s1.length, {});
    for (int i = 0; i < s1.length(); ++i)
    {
        v1.push_back({s1[i], i});
    }

    for (int i = 0; i < s2.length(); ++i)
    {
        v2.push_back({s2[i], i});
    }
}

bool compare(const pair<char, int>& a, const pair<char, int>& b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;    
    }
}

void Process()
{
    // Bước 1: Khởi tạo vector v1 và v2
    Init();

    // Bước 2: Sắp xếp
    sort(v1.begin(), v1.end(), compare);
    sort(v2.begin(), v2.end(), compare);

    // Bước 3:
    // Xác định vị trí giống nhau đầu tiên giữa v1 và v2
    int p1 = -1;
    int p2 = -1;

    bool break_loop = false;
    for (int i1 = 0; i1 < v1.size(); ++i1)
    {
        for (int i2 = 0; i2 < v2.size(); ++i2)
        {
            // Nếu có ký tự giống nhau thì đặt lại mốc p1 và p2 mới
            if (v1[i1].first == v2[i2].first)
            {
                p1 = i1;
                p2 = i2;

                res.push_back(v1[i1].first);
                
                break_loop = true;
                break;
            }
        }
        if (break_loop) break;
    }

    // Nếu có ký tự giống nhau (tức p1 không còn là -1) thì bắt đầu tìm các ký tự khác
    if (p1 != -1)
    {
        int i1 = p1 + 1;
        int i2;    
        while (i1 < v1.size())
        {
            if (v1[i1].second > v1[p1].second)
            {
                i2 = p2 + 1;
                while (i2 < v2.size())
                {
                    if (v2[i2].second > v2[p2].second)
                    {
                        if (v1[i1].first == v2[i2].first)
                        {
                            res.push_back(v1[i1].first);

                            p1 = i1;
                            p2 = i2;

                            i1 += 1;
                            i2 += 1;
                        }
                        else
                        {
                            i2 += 1;
                        }
                    }
                    else
                    {
                        i2 += 1;
                    }
                }
            }

            i1 += 1;
        }
    } // if p1
}

void Output()
{
    ofstream f;
    f.open(outputFile);

    if (res.size() == 0)
    {
        f << -1;
    }
    else
    {
        for (int i = 0; i < res.size(); ++i)
        {
            f << res[i];
        }
    }

    f.close();
}

void show_v()
{
    for (int i = 0; i < v1.size(); ++i)
    {
        cout << i << ": " << v1[i].first << ' ' << v1[i].second <<  endl; 
    }

    cout << "------------\n";

    for (int i = 0; i < v2.size(); ++i)
    {
        cout << i << ": " << v2[i].first << ' ' << v2[i].second <<  endl; 
    }
}

int main()
{
    Input();
    Process();
    Output();

    show_v();
    return 0;
}