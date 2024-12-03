#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <fstream>
#include <bitset>

using namespace std;
string readBinaryFile(const string &filename)
{
    ifstream inFile(filename, ios::binary);
    if (!inFile.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return "";
    }

    vector<unsigned char> bytes((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    string bitString;
    for (unsigned char byte : bytes)
    {
        bitset<8> b(byte);
        // cout << b;
        bitString += b.to_string();
    }

    return bitString;
}
int main(int argc, char const *argv[])
{
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << "Usage: " << "./crack" << " <hash_file> <compress_file>" << endl;
        return 0;
    }
    if (argc != 3)
    {
        cout << "Usage: " << "./crack" << " <hash_file> <compress_file>" << endl;
        return 1;
    }
    string hash_file = argv[1];
    string compress_file = argv[2];

    ifstream hash_f(hash_file);
    ifstream compress_f(compress_file);
    ofstream decompress_f("decompressed.txt");
    vector<string> hash;
    string stringLine;
    vector<pair<char, string>> hash_string;

    if (!hash_f.is_open())
    {
        cout << "Error: " << hash_file << " not found" << endl;
        return 1;
    }
    if (!compress_f.is_open())
    {
        cout << "Error: " << compress_file << " not found" << endl;
        return 1;
    }
    while (getline(hash_f, stringLine))
    {
        hash.push_back(stringLine);
    }
    hash_f.close();
    compress_f.close();
    stringLine = "";
    for (int i = 0; i < hash.size(); i++)
    {

        hash_string.push_back(make_pair(hash[i][0], hash[i].substr(1, hash[i].length() - 1)));
    }
    hash.clear();
    stringLine = readBinaryFile(compress_file);
    // cout << stringLine<<endl;
    // for (int i = 0; i < hash_string.size(); i++)
    // {
    //     cout << hash_string[i].first << " " << hash_string[i].second << endl;
    // }
    // return 0;

    cout << stringLine << endl;
    cout << "Decompressed Data: ";
    int track = 0;

    while (stringLine.length() > 0)
    {
        track++;
        for (int i = 0; i < hash_string.size(); i++)
        {
            if (hash_string[i].second == stringLine.substr(0, track))
            {

                // cout << (hash_string[i].first);
                decompress_f << (hash_string[i].first);
                stringLine = stringLine.substr(track, stringLine.length() - 1);
                track = 0;
                break;
            }
        }
    }

    hash_string.clear();
    decompress_f.close();
    cout << "Decompressed data saved in \'decompressed.txt\'" << endl;
    return 0;
}
