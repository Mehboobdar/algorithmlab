#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// Structure to represent a Huffman tree node
struct HuffmanNode {
    char data; // Character
    int freq; // Frequency
    HuffmanNode *left, *right; // Left and right child pointers

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator function for priority queue (min-heap)
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) const {
        return a->freq > b->freq; // Sort nodes by frequency
    }
};

// Function to build the Huffman tree and return the root node
HuffmanNode* buildHuffmanTree(map<char, int>& freqMap) {
    // Priority queue to store nodes (min-heap)
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto& entry : freqMap) {
        HuffmanNode* node = new HuffmanNode(entry.first, entry.second);
        pq.push(node);
    }

    // Merge nodes until only one node remains (Huffman tree)
    while (pq.size() > 1) {
        // Remove the two nodes with the lowest frequency from the priority queue
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        // Create a new internal node with sum of frequencies of the two nodes
        // and make the two nodes its left and right children
        HuffmanNode* mergedNode = new HuffmanNode('$', left->freq + right->freq);
        mergedNode->left = left;
        mergedNode->right = right;

        // Add the new node to the priority queue
        pq.push(mergedNode);
    }

    // The remaining node in the priority queue is the root of the Huffman tree
    return pq.top();
}

// Function to traverse the Huffman tree and generate Huffman codes for each character
void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr)
        return;

    // If the node is a leaf node (has no children), add its Huffman code to the map
    if (!root->left && !root->right)
        huffmanCodes[root->data] = code;

    // Traverse left subtree and append '0' to the code
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);

    // Traverse right subtree and append '1' to the code
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode a given string using Huffman codes
string encode(string input, map<char, string>& huffmanCodes) {
    string encodedString;
    for (char c : input) {
        encodedString += huffmanCodes[c];
    }
    return encodedString;
}

// Function to decode a given string using Huffman codes
string decode(string encodedString, HuffmanNode* root) {
    string decodedString;
    HuffmanNode* curr = root;
    for (char bit : encodedString) {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right) {
            decodedString += curr->data;
            curr = root;
        }
    }
    return decodedString;
}

int main() {
    string input = "huffman coding example";
    
    // Calculate character frequencies
    map<char, int> freqMap;
    for (char c : input)
        freqMap[c]++;

    // Build Huffman tree
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // Generate Huffman codes
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Encode input string using Huffman codes
    string encodedString = encode(input, huffmanCodes);
    cout << "Encoded string: " << encodedString << endl;

    // Decode encoded string using Huffman tree
    string decodedString = decode(encodedString, root);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}