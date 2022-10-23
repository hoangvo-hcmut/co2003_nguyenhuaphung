template <typename E>
BNode<E>* BSTdelete(BNode<E> * root,E val) {
    if (root == nullptr) return root;
    if (val < root->element()) {
        // lies on left tree
        root->setLeft( BSTdelete(root->left(), val));
    } else if (val > root->element()) {
        // lies on right tree
        root->setRight(BSTdelete(root->right(), val));
    } else {
        if (root->left() == nullptr && root->right() == nullptr) {
            return nullptr;
        }
        if (root->left() == nullptr) {
            BNode<E> * temp =root->right();
            //delete root;
            return temp;
        }
        if (root->right() == nullptr) {
            BNode<E> * temp =root->left();
            //delete root;
            return temp;
        }
        // two subtree
        // get left most leaf of right subtree
        BNode<E>* current = root->right();
        while (current && current->left() != nullptr)
            current = current->left();
        root->setElement(current->element());
        root->setRight(BSTdelete(root->right(), current->element()));
    }
    return root;
}
