//23k-0832
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


struct Compare
{
    bool operator()(pair<int, ListNode *> a, pair<int, ListNode *> b)
    {
        return a.first > b.first; 
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, Compare> minHeap;


    for (ListNode *list : lists)
    {
        if (list != nullptr)
        {
            minHeap.push({list->val, list});
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;


    while (!minHeap.empty())
    {

        auto [val, node] = minHeap.top();
        minHeap.pop();

        // Append it to the result list
        current->next = node;
        current = current->next;

        // Push the next element from the same list into the heap
        if (node->next != nullptr)
        {
            minHeap.push({node->next->val, node->next});
        }
    }

    return dummy->next; // Return the merged list, skipping the dummy node
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode *> lists = {list1, list2, list3};

    ListNode *mergedList = mergeKLists(lists);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
