#include "reader.hpp"
#include <queue>
#include <utility>
#include <set>

/*
This is the utility class: used for computation of the orders.
Compare class is used to provide the comparator for the min heap used.

The order_processing is the main function, which can be used as function as here 
or can be used to bind with an API

*/

typedef pair<float, Order *> pi;

class Compare
{
public:
    bool operator()(pair<float, Order *> a, pair<float, Order *> b)
    {
        return a.first > b.first;
    }
};

set<Order *> order_processing(vector<Order *> list)
{

    int currentSlots = 7;
    set<Order *> result;
    priority_queue<pi, vector<pi>, Compare> heap;
    for (auto &order : list)
    {
        order->Process();
        if (!order->IsValid())
        {
            result.insert(order);
            continue;
        }
        float order_time = order->GetTotalTime();
        int slot = order->GetSlots();
        if (slot <= currentSlots)
        {
            result.insert(order);
            heap.push(make_pair(order_time, order));
            currentSlots = currentSlots - slot;
        }
        else
        {
            float waiting_time = 0;
            while (currentSlots < slot)
            {
                pair<float, Order *> element;
                element = heap.top();
                heap.pop();
                Order *order = element.second;
                currentSlots += order->GetSlots();
                waiting_time += element.first;
            }
            order->vTime.SetWaitingTime(waiting_time);
            order->Process();
            heap.push(make_pair(order_time + waiting_time, order));
            currentSlots = currentSlots - slot;
        }
    }
    while (!heap.empty())
    {
        pair<float, Order *> element;
        element = heap.top();
        heap.pop();
        Order *ord = element.second;
        if (result.find(ord) == result.end())
            result.insert(ord);
    }

    return result;
}
