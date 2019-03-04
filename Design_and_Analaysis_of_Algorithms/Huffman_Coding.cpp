#include "Huffman_Coding.hpp"
#include <iostream>
#include <queue>

using std::cout;
using std::endl;

void PrintCodes(std::shared_ptr<MinHeapNode> root, std::string str)
{
    if (!root)
    {
        return;
    }
    else if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
    }
    PrintCodes(root->left, str + "0");
    PrintCodes(root->right, str + "1");
}

void HuffmanCodes(std::string data, std::vector<int> freq)
{
    auto comparator = [](std::shared_ptr<MinHeapNode> x, std::shared_ptr<MinHeapNode> y)
    {
        return x->freq > y->freq;
    };
    std::priority_queue<
            std::shared_ptr<MinHeapNode>,
            std::vector<std::shared_ptr<MinHeapNode>>,
            decltype(comparator)>
            minHeap(comparator);
    for (int i = 0; i < freq.size(); i++)
    {
        minHeap.push(std::make_shared<MinHeapNode>(data.at(i), freq.at(i)));
    }
    while (minHeap.size() != 1)
    {
        auto left = minHeap.top();
        minHeap.pop();
        auto right = minHeap.top();
        minHeap.pop();
        auto top = std::make_shared<MinHeapNode>('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    PrintCodes(minHeap.top(), "");
}
