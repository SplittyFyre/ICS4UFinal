#include "RBTree.h"

void RBTree::insert(Record *data) {
    root = RBNode::insert(root, data);
    root->colour = BLACK;
}

void RBTree::erase(Record *data) {
    if (!contains(data)) return;
    if (!RBNode::isRed(root->left) && !RBNode::isRed(root->right))
        root->colour = RED; // red-black tree special case
    root = RBNode::erase(root, data);
    if (root) root->colour = BLACK;
}

bool RBTree::contains(Record *data) {
    return RBNode::find(root, data) != nullptr;
}

Record* RBTree::get(Record *data) {
    RBNode *h = RBNode::find(root, data);
    if (h == nullptr) return nullptr;
    return h->data;
}


void RBTree::save(std::ofstream &fout) const {
    writeByte(fout, root != nullptr); // do we even have a tree?
    if (root != nullptr)
        root->save(fout);
}
void RBTree::load(std::ifstream &fin, Record *type) {
    bool hasTree = readByte(fin); // do we even have a tree?
    if (hasTree) {
        root = new RBNode(type->duplicateType(), 0);
        root->load(fin, type);
    }
}

void RBTree::forEach(const std::function<void(Record*)> &func) {
    if (root != nullptr)
        root->forEach(func);
}
