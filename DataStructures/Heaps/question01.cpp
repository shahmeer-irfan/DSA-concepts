#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int validateMinHeap(const vector<int> &heap, int maxHeight)
{
    int size = heap.size();
    int height = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty() && height <= maxHeight)
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            int parent = q.front();
            q.pop();

            int l = 2 * parent + 1;
            int r = 2 * parent + 2;

            if (l < size)
            {
                if (heap[l] < heap[parent]) //violates min heap property
                    return height; //returning current height
                q.push(l);
            }

            if (r < size)
            {
                if (heap[r] < heap[parent])
                    return height;
                q.push(r);
            }
        }
        height++;
    }

    return height-1;
}
