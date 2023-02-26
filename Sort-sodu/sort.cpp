#include <iostream>
#include <fstream>
#include <vector>

#define inputFile "sort.inp"
#define outputFile "sort.out"

using namespace std;

int n, m, t;
vector<int> v;

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n >> m >> t;

    f.close();
}

int Process()
{
    v.resize(n + 1);

    int r = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        v[i] = r;
        r++;

        if (r == m) r = 0;
    }

    int rowNumber = int((n + 1) / m);
    if ((n + 1) % m > 0) rowNumber += 1;

    int start = int(t / rowNumber);
    int step = t % rowNumber;     

    int res = start + (step * m);

    return res;
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