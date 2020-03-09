/*
    QUICK UNION
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("tinyUF.in");
ofstream fout("tinyUF.out");

int id[105], sz[105], n;

void init(int id[105]) {
    for(int i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

int root(int i) {
    while(i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void unite(int p, int q) {
    int i = root(p);
    int j = root(q);
    if(i == j) return;
    if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}

bool connected(int p, int q) {
    return root(p) == root(q);
}

int main()
{
    int p, q;

    fin >> n;

    init(id);

    while(fin >> p >> q)
        if(!connected(p, q))
            unite(p, q);

    for(int i = 0; i < n; i++)
        fout << id[i] << " ";

    fout << endl;

    for(int i = 0; i < n; i++)
        fout << sz[i] << " ";

    fin.close();
    fout.close();
    return 0;
}
