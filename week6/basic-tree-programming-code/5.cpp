template <typename E>
void BFtraversal(BNode<E> * root, void (*f)(E)) {
    if (!root) return;
    LQueue<BNode<E> *> * queue = new LQueue<BNode<E>*>();
    queue->enqueue(root);
    f(root->element());
    while (queue->length() > 0) {
        BNode<E>* n = queue->dequeue();
        if (n->left()) {
            f(n->left()->element());
            queue->enqueue(n->left());
        }
        if (n->right()) {
            f(n->right()->element());
            queue->enqueue(n->right());
        }
    }
}
