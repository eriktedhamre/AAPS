
#include <variant>
#include <vector>

struct VariableDepthList : std::variant<std::vector<VariableDepthList>, int> {
private:
    using base = std::variant<std::vector<VariableDepthList>, int>;
public:
    using base::base;
    VariableDepthList(std::initializer_list<VariableDepthList> v) : base(v) {}
};

// This does not look right

typedef struct setstack;

struct setstack
{
    int value;
    std::vector<setstack> list;
};
