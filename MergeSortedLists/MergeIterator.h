#include <vector>
#include <stdexcept>

class MergeIterator {
public:
    MergeIterator(const std::vector<int>& _l1,
        const std::vector<int>& _l2,
        const std::vector<int>& _l3);

    bool HasNext() const;
    int GetNext();

private:
    const std::vector<int>& l1;
    const std::vector<int>& l2;
    const std::vector<int>& l3;

    size_t s1, s2, s3;
};
