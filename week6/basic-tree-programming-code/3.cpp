template <typename E>
BNode<E>* BSTsearch(BNode<E> * root,E val) {
    if (root == nullptr) return nullptr;
    E el = root->element();
    cout << el;
 cout << ",";
    if (val == el) return root;
    if (el < val) return BSTsearch(root->right(), val);
    return BSTsearch(root->left(), val);
}

