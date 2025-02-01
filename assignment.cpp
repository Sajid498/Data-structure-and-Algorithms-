//haffman
#include <bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};
struct PriorityQueue {
    struct PQNode {
        Node* treeNode;
        PQNode* next;
        PQNode(Node* treeNode, PQNode* next = nullptr) {
            this->treeNode = treeNode;
            this->next = next;
        }
    };

    PQNode* head;

    PriorityQueue() {
        head = nullptr;
    }

    void push(Node* node) {
        PQNode* newNode = new PQNode(node);
        if (!head || head->treeNode->freq > node->freq) {
            newNode->next = head;
            head = newNode;
        } else {
            PQNode* temp = head;
            while (temp->next && temp->next->treeNode->freq <= node->freq) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    Node* pop() {
        if (!head) return nullptr;
        PQNode* temp = head;
        head = head->next;
        Node* treeNode = temp->treeNode;
        delete temp;
        return treeNode;
    }

    bool size() {
        return head != nullptr && head->next == nullptr;
    }
    bool empty() {
        return head == nullptr;
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void printCodes(unordered_map<char, string>& huffmanCode, unordered_map<char, int>& freq) {
    cout << "Character\tFrequency\tCodeword\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << "\t\t" << freq[pair.first] << "\t\t" << pair.second << '\n';
    }
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    PriorityQueue pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    while (!pq.size()) {
        Node* left = pq.pop();
        Node* right = pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.pop();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    printCodes(huffmanCode, freq);
}

int main() {
    string text;
    cout << "Enter the input message: ";
    cin >> text;

    buildHuffmanTree(text);

    return 0;
}

