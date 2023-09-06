/// Max Heap

#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int a[101], size;
    Heap()
    {
        size = 0;
    }

private:
    void bottomTopAdjust(int i)
    {

        for (int k = i; k > 0; k /= 2)
        {
            int parent = k / 2;
            if (a[k] < a[parent])
                swap(a[k], a[parent]);
            else
                break;
        }
    }

    void topBottomAdjust(int i)
    {
        //   for (int k = i; k <= size/2; k++)
        //   {
        //         if(a[k] < a[2*k+1] and a[2*k+1] > a[2*k])
        //         {
        //             swap(a[k], a[2*k+1]);
        //         }
        //         else if(a[k] < a[2*k] and a[2*k] > a[2*k+1])
        //         {
        //             swap(a[k], a[2*k]);
        //         }
        //         else continue;
        //   }

        int largest = i; // MAX HEAPIFY FUNCTION
        int l = 2 * i;
        int r = 2 * i + 1;
        if (l == size)
        {
            if (a[l] > a[i])
            {
                swap(a[l], a[i]);
                topBottomAdjust(l);
            }
        }
        else
        {
            if (l <= size && a[l] < a[largest])
            {
                largest = l;
            }
            else
                largest = i;
            if (r <= size && a[r] < a[largest])
            {
                largest = r;
            }
            if (largest != i)
            {
                swap(a[i], a[largest]);
                topBottomAdjust(largest);
            }
        }
    }

public:
    bool insert(int val)
    {

        size++;
        a[size] = val;
        bottomTopAdjust(size);
    }

    int showMax()
    {
        // buildHeap();
        cout << a[1] << endl;
    }

    int showSize()
    {
        cout << size << endl;
    }

    bool deleteRoot()
    {

        swap(a[size], a[1]);
        size--;
        topBottomAdjust(1);
    }

    void delanypos(int pos)
    {
        swap(a[size], a[pos]);
        size--;
        bottomTopAdjust(size);
        topBottomAdjust(1);
    }
    void buildHeap()
    {
        int s = size / 2;
        for (int i = s; i >= 1; i--)
        {
            topBottomAdjust(i);
        }
    }

    void sort()
    {
        int x = size;
        while (size != 0)
        {
            swap(a[1], a[size]);
            size--;
            topBottomAdjust(1);
        }
        size = x;
        for (int i = 1; i <= size; i++)
        {
            cout << a[i] << endl;
        }
    }

    void bfs()
    {
        if (size == 0)
            return;
        int level = 2;
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            if (parent == level)
            {
                cout << endl;
                level = level * 2;
            }
            cout << a[parent] << " ";
            if (2 * parent <= size)
                q.push(2 * parent);
            if (2 * parent + 1 <= size)
                q.push(2 * parent + 1);
        }
    }
};

/* 1 16
   1 14
   1 9
   1 10
   1 4
   1 3
   1 7
   1 8
   1 1
   1 2
 */
int main()
{

    Heap heap;

    while (1)
    {
        cout << "1. Insert    2. Show Max    3. Delete Max    4. Sort    5. Level    6. Build Heap    7. End      8. Delete any" << endl
             << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(y);

            if (b)
                cout << y << " is inserted in the heap" << endl;
        }

        else if (choice == 2)
        {
            if (heap.showSize() != 0)
                cout << "Max Element: " << heap.showMax();
            else
                cout << "No element in the heap" << endl;
        }

        else if (choice == 3)
        {
            bool b = heap.deleteRoot();
            if (b)
                cout << "Root deleted from heap";
            else
                cout << "Heap is empty";
            cout << endl;
        }

        else if (choice == 4)
        {
            heap.sort();
        }

        else if (choice == 5)
        {
            cout << "Level Wise Traversal of the heap:" << endl;
            heap.bfs();
            cout << endl;
        }
        else if (choice == 6)
        {
            if (heap.showSize() == 0)
                cout << "Heap is Empty!" << endl;
            else
                heap.buildHeap();
        }
        else if (choice == 8)
        {
            int pos;
            cin >> pos;
            heap.delanypos(pos);
        }
        else if (choice == 7)
        {
            break;
        }

        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}

/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
*/