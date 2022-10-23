template <typename E>
int height(BNode<E> * root) {
    if (!root) return 0;
    return max(height(root->left()), height(root->right())) + 1;
}
