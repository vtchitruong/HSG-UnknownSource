#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#define inputFile "chonbong.inp"
#define outputFile "chonbong.out"

using namespace std;

int n, k; // n: số bóng, k: số màu
vector<int> color;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> k;

    color.resize(n + 1, 0);

    int c; // color
    for (int i = 0; i < n; ++i)
    {
        f >> c;
        color[c]++;
    }

    f.close();
}

int Process()
{
    sort(color.begin(), color.end(), greater<>());

    int point = 0;

    int i = 0;
    while (true)
    {
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
            i += 2;
        }
        else
        {
            point += (color[i] * 2);
            color[i + 1] = color[i + 1] - color[i];
            i += 1;
        }       
        
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