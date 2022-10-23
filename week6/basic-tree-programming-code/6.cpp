template <typename E>
BNode<E>* BSTinsert(BNode<E> * root,E val) {
    BNode<E>* node = new BNode<E>(val);
    if (root == nullptr) return node;
    if (val >= root->element()) {
        if (root->right() == nullptr) root->setRight(node);
        else BSTinsert(root->right(), val);
    } else {
        // insert to left
        if (root->left() == nullptr) root->setLeft(node);
        else BSTinsert(root->left(), val);
    }
    return root;
}
