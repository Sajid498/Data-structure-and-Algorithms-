#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min-heap based on frequency
    }
};

// Function to traverse the Huffman tree and generate codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    // Recursive traversal
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string input = "ABBCCBABADDDRRRRZZZETYERT";

    // Step 1: Count frequencies
    unordered_map<char, int> frequency;
    for (char ch : input) {
        frequency[ch]++;
    }

    // Step 2: Create a priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 3: Build the Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with combined frequency
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 4: Generate Huffman Codes
    Node* root = pq.top();
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Step 5: Output the results
    cout << "Character\tFrequency\tCodeword\n";
    for (auto pair : frequency) {
        cout << pair.first << "\t\t" << pair.second << "\t\t" << huffmanCodes[pair.first] << "\n";
    }

    return 0;
}

