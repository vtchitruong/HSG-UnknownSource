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
    int rowNumber = int((n + 1) / m);
    if ((n + 1) % m > 0) rowNumber += 1;

    int row = int(t / rowNumber);
    int col = t % rowNumber;     

    int res = row + (col * m);

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