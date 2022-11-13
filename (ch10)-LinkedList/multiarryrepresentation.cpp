#include <bits/stdc++.h>
using namespace std;
int pre[105], val[105], nex[105];
int root = -1, tail = -1;
int random()
{
    return 5 + (rand() % 50);
}
void insert(int value)
{
    if (root == -1)
    {
        root = random();
        pre[root] = -1;
        val[root] = value;
        nex[root] = -1;
        tail = root;
    }
    else
    {
        int check;
        while (true)
        {
            check = random();
            if (pre[check] == 0)
            {
                break;
            }
        }
        nex[tail] = check;
        val[check] = value;
        pre[check] = nex[tail];
        nex[check] = -1;
        tail = check;
    }
}
void display()
{
    int temp = root;
    while (nex[temp] != -1)
    {
        cout << val[temp] << " ";
        temp = nex[temp];
    }
    cout << val[temp] << endl;
}
s
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();

    cout << endl;
   //delete_data(4);
  // display();

    return 0;
}
