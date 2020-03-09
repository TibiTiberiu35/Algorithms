/*
    QUICK SORT
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("tinyUF.in");
ofstream fout("tinyUF.out");

int arr[105], n;

void init(int arr[105]) {
    for(int i = 0; i < n; i++)
        arr[i] = i;
}

void unite(int p, int q) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == arr[p]) {
            arr[i] = arr[q];
        }
    }
}

bool connected(int p, int q) {
    return arr[p] == arr[q];
}

int main()
{
    int p, q;

    fin >> n;

    init(arr);

    while(fin >> p >> q) {
        if(!connected(p, q)) {
            unite(p, q);
            // cout << p << " " << q << "\n";
        }
    }

    for(int i = 0; i < n; i++)
        fout << arr[i] << " ";
    return 0;
}
