#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <filesystem>
#include <iterator>
#include <bitset>
#include <fstream>

using namespace std;
typedef struct node
{
    string s;
    int freq;
    node *left, *right;
} Node;

// operator overloading for priority queue
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

Node *newNode(string s, int freq)
{
    Node *temp = new Node;
    temp->s = s;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void createHuffmanCode(Node *root, string code, map<char, string> &huffmanCode)
{
    if (!root)
        return;
    if (root->s != "")
    {
        huffmanCode[root->s[0]] = code;
    }
    createHuffmanCode(root->left, code + "1", huffmanCode);
    createHuffmanCode(root->right, code + "0", huffmanCode);
}
void writeBinaryFile(const string &filename, const string &bitString)
{
    ofstream outFile(filename, ios::binary);
    if (!outFile.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }
    cout << "Len Of Binary String: " << bitString.size() << endl; // DEBUG
    cout << bitString << endl;                                     // DEBUG
    vector<unsigned char> bytes;
    for (size_t i = 0; i < bitString.size(); i += 8)
    {
        // cout << bitString.substr(i, 8); // DEBUG
        bitset<8> byte(bitString.substr(i, 8));
        bytes.push_back(static_cast<unsigned char>(byte.to_ulong()));
    }

    outFile.write(reinterpret_cast<const char *>(bytes.data()), bytes.size());
    outFile.close();
}
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    string data;
    getline(file, data);
    // file >> data;
    file.close();

    map<char, int> freq;
    for (char c : data)
    {
        freq[c]++;
    }
    // create a priority queue to store nodes
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (auto p : freq)
    {
        pq.push(newNode(string(1, p.first), p.second));
    }

    Node *root = NULL;
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *top = newNode("", left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    root = pq.top();

    map<char, string> huffmanCode;
    createHuffmanCode(root, "", huffmanCode);

    // this is the part to store code in a file
    ofstream file2("code.txt");
    for (auto p : huffmanCode)
    {
        file2 << p.first << p.second << endl;
    }
    file2.close();
    // file2.open("compressed.txt");
    string encoded = "";
    for (char c : data)
    {
        encoded += huffmanCode[c];
    }

    writeBinaryFile("compressed.bin", encoded);
    cout << endl
         << "Original data compressed to \'compressed.bin\' and Code Tree has been stored in \'code.txt\' file." << endl;
    return 0;
}
