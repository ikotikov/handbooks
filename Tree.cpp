#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node* currentLeaf = &root;
    for (const auto& folder : node) {
        if (currentLeaf->children.contains(folder)) {
            currentLeaf = &currentLeaf->children.at(folder);
        } else {
            return false;
        }
    }

    return true;
}

void Tree::Insert(const std::vector<std::string>& node) {
    Node* currentLeaf = &root;
    for (const auto& folder : node) {
        if (currentLeaf->children.contains(folder)) {
            currentLeaf = &currentLeaf->children.at(folder);
        } else {
            currentLeaf->children[folder];
        }
    }
}

void Tree::Delete(const std::vector<std::string>& node) {
    Node* currentLeaf = &root;
    for (size_t i = 0; i < node.size(); ++i) {
        const auto& folder = node[i];
        if (currentLeaf->children.contains(folder)) {
            if (i + 1 == node.size()) {
                currentLeaf->children.erase(folder);
            } else {
                currentLeaf = &currentLeaf->children.at(folder);
            }
        } else {
            return;
        }
    }
}


int main () {
    
}
