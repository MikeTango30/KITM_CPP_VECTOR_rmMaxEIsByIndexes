#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const string FILENAME = "nums.txt";
const string RESULTS_FILE = "numsRes.txt";

void readFile(vector<int> &Nums);
void writeVector(vector<int> &Nums, string text);
void findMaxElementIndexes(vector<int> &Nums, vector<int> &Indexes);
void eraseMaxElements(vector<int> &Nums, vector<int> &Indexes);

int main() {
    vector<int> Nums;
    vector<int> Indexes;

    readFile(Nums);
    writeVector(Nums, "Starting nums:");

    findMaxElementIndexes(Nums, Indexes);
    writeVector(Indexes, "Starting max elements indexes:");

    eraseMaxElements(Nums, Indexes);
    writeVector(Nums, "Deleted max elements:");

    return 0;
}

void readFile(vector<int> &Nums)
{
    int i;
    ifstream in(FILENAME.c_str());

    while(!in.eof()) {
        in >> i;
        Nums.push_back(i);
    }

    in.close();
}

void writeVector(vector<int> &Nums, string text)
{
    ofstream out(RESULTS_FILE, ios_base::app);

    out << text << '\n';

    for(int i : Nums) {
        out << i << " ";
    }

    out << '\n';

    out.close();
}

void findMaxElementIndexes(vector<int> &Nums, vector<int> &Indexes)
{
    int maxElement = *max_element(Nums.begin(), Nums.end());

    for (int i = 0; i < Nums.size(); i++) {
        if (Nums[i] == maxElement) {
            Indexes.push_back(i);
        }
    }

}

void eraseMaxElements(vector<int> &Nums, vector<int> &Indexes)
{
    for (int i = 0; i < Indexes.size(); i++) {
        Nums.erase(Nums.begin() + Indexes[i] - i);
    }
}