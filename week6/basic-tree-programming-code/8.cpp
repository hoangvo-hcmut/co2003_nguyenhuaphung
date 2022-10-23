template <typename E>
bool isBST(BNode<E> * root) {
    if (!root) return false;
    BNode<E> * left = root->left();
    BNode<E> * right = root->right();
    if (left != nullptr && left->element() >= root->element()) return false;
    if (right != nullptr && right->element() < root->element()) return false;
    if (left != nullptr) {
        if (!isBST(left)) return false;
        if (left->right() != nullptr) {
            if (left->right()->element() > root->element()) return false;
        }
    }
    if (right != nullptr) {
        if (!isBST(right)) return false;
        if (right->left() != nullptr) {
            if (right->left()->element() < root->element()) return false;
        }
    }
    return true;
}
