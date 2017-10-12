#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class MySet {
    class Node {
        int data;
        size_t vecIdx;
        vector<unordered_set<Node, MyHasher>::iterator>::iterator pit;
    public:
        Node(int d, int i) : data(d), vecIdx(i) {}
        int getData() const { return data; }
        size_t getVecIdx () const { return vecIdx; }
        void setVecIdx (size_t i) { vecIdx = i; }
        bool operator ==(const Node& node) const {
            return node.data == this->data;
        } 
    };
    struct MyHasher {
        size_t operator()(const Node& node) const {
            return std::hash<int>()(node.getData());
        }
    };

    unordered_set<Node, MyHasher> uset;
    vector<unordered_set<Node, MyHasher>::iterator> its;
public:
    bool insert(int data) {
        auto p = uset.insert(Node(data, uset.size()));
        if (p.second) its.emplace_back(p.first);
        return p.second;
    }
    bool remove(int data) {
        Node node(data, 0);
        auto it = uset.find(node);
        if (it != uset.end()) {//remove
            auto idx = it->getVecIdx();
            swap(its[idx], its[uset.size()-1]);
            *(its[idx]) = its[uset.size()-1];
            its.pop_back();
            return 1;
        }
        else return 0;
    }
    int getRandomElement() {
        srand((unsigned)time(0));
        int r = rand() % uset.size();
        return its[r]->getData();
    }//*/
};

int main() {
    std::cout << "Hello World!\n";
}
