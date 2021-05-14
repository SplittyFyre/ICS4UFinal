#include "RBNode.h"

RBNode::~RBNode() { // delete left and right children as well as data
    // this works fine even if any of these pointers are null
    // c++ standard guarantees delete is ignored of argument is null
    delete left;
    delete right;
    delete data;
}

void RBNode::flipColours() {
    colour ^= 1;
    left->colour ^= 1;
    right->colour ^= 1;
}
bool RBNode::isRed(RBNode *node) {
    if (!node) return false; // if node is null
    return node->colour == RED;
}

RBNode* RBNode::rotateLeft(RBNode *h) {
    RBNode *x = h->right;
    h->right = x->left;
    x->left = h;
    x->colour = h->colour;
    h->colour = RED;
    return x;
}
RBNode* RBNode::rotateRight(RBNode *h) {
    RBNode *x = h->left;
    h->left = x->right;
    x->right = h;
    x->colour = h->colour;
    h->colour = RED;
    return x;
}

RBNode* RBNode::balance(RBNode *h) {
    if (isRed(h->right)) h = rotateLeft(h);
    //if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) h->flipColours();
    return h;
}

/*RBNode* RBNode::moveRedLeft(RBNode *h) {
    h->flipColours();
    if (isRed(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
    }
    return h;
}
RBNode* RBNode::moveRedRight(RBNode *h) {
    h->flipColours();
    if (!isRed(h->left->left))
        h = rotateRight(h);
    return h;
}*/
RBNode* RBNode::moveRedLeft(RBNode *h) {
    h->flipColours();
    if (isRed(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        h->flipColours();
    }
    return h;
}
RBNode* RBNode::moveRedRight(RBNode *h) {
    h->flipColours();
    if (isRed(h->left->left)) {
        h = rotateRight(h);
        h->flipColours();
    }
    return h;
}

RBNode* RBNode::insert(RBNode *h, Record *data) {
    if (h == nullptr) return new RBNode(data, RED); // recursion base case
    
    int comp = data->compare(h->data);
    if (comp < 0) h->left = insert(h->left, data);
    else if (comp > 0) h->right = insert(h->right, data);
    // else: this current node contains target key

    // insertion may have imbalanced tree, restore balance:
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) h->flipColours();

    return h;
}

RBNode* RBNode::erase(RBNode *h, Record *data) {
    if (data->compare(h->data) < 0) {
        if (!isRed(h->left) && !isRed(h->left->left))
            h = moveRedLeft(h);
        h->left = erase(h->left, data);
    }
    else {
        if (isRed(h->left)) h = rotateRight(h);
        if (data->compare(h->data) == 0 && h->right == nullptr) { // matching key found
            delete h;
            return nullptr;
        }
        if (!isRed(h->right) && !isRed(h->right->left))
            h = moveRedRight(h);
        if (data->compare(h->data) == 0) {
            RBNode *tmp = findMin(h->right);

            delete h->data;
            h->data = tmp->data; // move data from tmp to h
            tmp->data = nullptr;

            h->right = eraseMin(h->right);
        }
        else h->right = erase(h->right, data);
    }
    return balance(h);
}

RBNode* RBNode::find(RBNode *h, Record *data) {
    if (h == nullptr) return nullptr;
    int comp = data->compare(h->data);
    if (comp == 0) return h;
    if (comp < 0) return find(h->left, data);
    else return find(h->right, data);
}

RBNode* RBNode::findMin(RBNode *h) {
    if (h->left == nullptr) return h;
    return findMin(h->left);
}

RBNode* RBNode::eraseMin(RBNode *h) {
    if (h->left == nullptr) { // recursion base case
        delete h;
        return nullptr;
    }
    if (!isRed(h->left) && !isRed(h->left->left))
        h = moveRedLeft(h);
    h->left = eraseMin(h->left);
    return balance(h);
}

void RBNode::save(std::ofstream &fout) const {
    writeByte(fout, colour);
    data->save(fout);
    writeByte(fout, left != nullptr); // is there a left child?
    if (left != nullptr) left->save(fout);
    writeByte(fout, right != nullptr); // is there a right child?
    if (right != nullptr) right->save(fout);
}

void RBNode::load(std::ifstream &fin, Record *type) {
    colour = readByte(fin);
    data->load(fin);
    if (readByte(fin)) { // has left child
        left = new RBNode(type->duplicateType(), 0);
        left->load(fin, type);
    }
    if (readByte(fin)) { // has right child
        right = new RBNode(type->duplicateType(), 0);
        right->load(fin, type);
    }
}

void RBNode::forEach(const std::function<void(Record*)> &func) {
    if (left) left->forEach(func); // if left child isnt null, run theirs
    func(data); // call func with our data
    if (right) right->forEach(func); // if right child isnt null, run theirs
}
