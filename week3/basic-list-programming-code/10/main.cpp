template <typename E>
List<E>* merge(List<E>* in1, List<E>* in2) {
    LList<E>* result = new LList<E>();
    while (in1->length() != 0 || in2->length() != 0) {
        if (in1->length() == 0) {
            result->append(in2->remove());
        } else if (in2->length() == 0) {
            result->append(in1->remove());
        } else if (in1->getValue() < in2->getValue()) {
            result->append(in1->remove());
        } else {
            result->append(in2->remove());
        }
    }
    return result;
}
