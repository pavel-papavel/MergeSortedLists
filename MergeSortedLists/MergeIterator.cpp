#include "MergeIterator.h"

MergeIterator::MergeIterator(const std::vector<int>& _l1, const std::vector<int>& _l2, const std::vector<int>& _l3)
    : l1(_l1), l2(_l2), l3(_l3), s1(0), s2(0), s3(0) {
}

bool MergeIterator::HasNext() const
{
    return s1 < l1.size() || s2 < l2.size() || s3 < l3.size();
}

int MergeIterator::GetNext() {
    if (!HasNext()) {
        throw std::out_of_range("No more elements");
    }

    const bool has1 = s1 < l1.size();
    const bool has2 = s2 < l2.size();
    const bool has3 = s3 < l3.size();

    if (has1 &&
        (!has2 || l1[s1] <= l2[s2]) &&
        (!has3 || l1[s1] <= l3[s3])) {
        return l1[s1++];
    }

    if (has2 &&
        (!has1 || l2[s2] <= l1[s1]) &&
        (!has3 || l2[s2] <= l3[s3])) {
        return l2[s2++];
    }

    return l3[s3++];
}
