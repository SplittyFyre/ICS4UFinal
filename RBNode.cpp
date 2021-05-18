#include "RBNode.h"

const int8_t RBNode::BLACK = 0;
const int8_t RBNode::RED = 1;

RBNode::~RBNode() { // delete left and right children as well as data
    // this works fine even if any of these pointers are null
    // c++ standard guarantees delete is ignored if the argument is null
    delete left;
    delete right;
    delete data;
}

void RBNode::flipColours() {
    colour ^= 1; // xoring with one flips between 0 (BLACK) and 1 (RED)
    left->colour ^= 1;
    right->colour ^= 1;
}
bool RBNode::isRed(RBNode *node) {
    if (!node) return false; // in red-black trees, null nodes are considered black
    return node->colour == RED;
}

// make a right-leaning link lean to the left
// rotations are used in red-black trees to restore the invariant
// since they can reposition nodes while preserving the bst ordering requirement
// rotation visualized: https://www.codesdope.com/staticroot/images/ds/rb14.gif
RBNode* RBNode::rotateLeft(RBNode *h) {
    RBNode *x = h->right;
    h->right = x->left;
    x->left = h;
    x->colour = h->colour;
    h->colour = RED;
    return x;
}
// make a left-leaning link lean to the right
RBNode* RBNode::rotateRight(RBNode *h) {
    RBNode *x = h->left;
    h->left = x->right;
    x->right = h;
    x->colour = h->colour;
    h->colour = RED;
    return x;
}

// restore red-black tree invariant
RBNode* RBNode::balance(RBNode *h) {
    if (isRed(h->right)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) h->flipColours();
    return h;
}

// assuming that h is red and both h->left and h->left->left
// are black, make h->left or one of its children red
RBNode* RBNode::moveRedLeft(RBNode *h) {
    h->flipColours();
    if (isRed(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        h->flipColours();
    }
    return h;
}
// assuming that h is red and both h->right and h->right->left
// are black, make h->right or one of its children red
RBNode* RBNode::moveRedRight(RBNode *h) {
    h->flipColours();
    if (isRed(h->left->left)) {
        h = rotateRight(h);
        h->flipColours();
    }
    return h;
}

// insert Record into red-back tree, does nothing if record already exists
RBNode* RBNode::insert(RBNode *h, Record *data) {
    if (h == nullptr) return new RBNode(data, RED); // recursion base case
    
    int comp = data->compare(h->data);
    if (comp < 0) h->left = insert(h->left, data); // bst: smaller values are to the left
    else if (comp > 0) h->right = insert(h->right, data); // bst: larger values are to the right
    // else: this current node contains target key

    // insertion may have broken invariant tree, so restore invariant:
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) h->flipColours();

    return h;
}

// erase Record from red-black tree, record must exist (that check is performed in RBTree)
RBNode* RBNode::erase(RBNode *h, Record *data) {
    if (data->compare(h->data) < 0) { // bst: smaller values are to the left
        if (!isRed(h->left) && !isRed(h->left->left))
            h = moveRedLeft(h);
        h->left = erase(h->left, data);
    }
    else {
        if (isRed(h->left)) h = rotateRight(h);
        if (data->compare(h->data) == 0 && h->right == nullptr) {
            delete h; // h is the node to delete, and there are no children larger than it (h->right is null)
            return nullptr; // node h has been deleted, so its parent marks it as null
        }
        if (!isRed(h->right) && !isRed(h->right->left))
            h = moveRedRight(h);
        if (data->compare(h->data) == 0) { // matching key found
            // problem reduced to erasing the minimum from right subtree
            // and then having h, the target, assume the identity of the removed node
            // eraseMin() will maintain invariant as it climbs up the tree
            RBNode *tmp = findMin(h->right);

            delete h->data;
            h->data = tmp->data; // move data from tmp to h
            tmp->data = nullptr;

            h->right = eraseMin(h->right);
        }
        else h->right = erase(h->right, data); // bst: larger values are to the right
    }
    return balance(h);
}

// returns Node holding matching Record in subtree rooted at h
// note that the data argument points to an 'incomplete' Record which
// contains only enough data to compare with other Records
RBNode* RBNode::find(RBNode *h, Record *data) {
    if (h == nullptr) return nullptr;
    int comp = data->compare(h->data);
    if (comp == 0) return h;
    if (comp < 0) return find(h->left, data); // bst: smaller values are to the left
    else return find(h->right, data); // bst: larger values are to the right
}

// returns Node with smallest Record in subtree rooted at h
RBNode* RBNode::findMin(RBNode *h) {
    if (h->left == nullptr) return h;
    return findMin(h->left);
}

// erases Node with smallest Record in subtree rooted at h
RBNode* RBNode::eraseMin(RBNode *h) {
    if (h->left == nullptr) { // recursion base case
        delete h;
        return nullptr;
    }
    if (!isRed(h->left) && !isRed(h->left->left)) // prepare tree for traversal
        h = moveRedLeft(h);
    h->left = eraseMin(h->left); // continued recursive traversal
    return balance(h); // restore invariant
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
