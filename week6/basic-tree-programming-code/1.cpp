template <typename E>
int count(BNode<E> * root) {
    return root == nullptr ? 0 : (1 + count(root->left()) + count(root->right()));
}
