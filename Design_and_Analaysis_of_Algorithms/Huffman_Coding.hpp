#ifndef DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_HUFFMAN_CODING_HPP
#define DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_HUFFMAN_CODING_HPP

#include <memory>
#include <string>
#include <vector>

class MinHeapNode
{
public:
    char data;
    int freq;
    std::shared_ptr<MinHeapNode> left;
    std::shared_ptr<MinHeapNode> right;

    MinHeapNode(char data, int freq) : data{data}, freq{freq}, left(), right()
    {

    }
};

void PrintCodes(std::shared_ptr<MinHeapNode> root, std::string str);

void HuffmanCodes(std::string data, std::vector<int> freq);

#endif //DESIGN_AND_ANALAYSIS_OF_ALGORITHMS_HUFFMAN_CODING_HPP
