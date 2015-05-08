//#include <memory>
//
//class binarytree
//{
//private:
//    class node
//    {
//    private:
//        int data_;
//        std::unique_ptr<node> left_;
//        std::unique_ptr<node> right_;
//    public:
//        inline node(int data) : data_(data){};
//        inline node(int data, node left, node right)
//            : left_(std::make_unique<node>(left))
//            , right_(std::make_unique<node>(right))
//            , data_(data) {};
//    };
//
//    std::unique_ptr<node> root_;
//
//    inline binarytree(node root)
//        : root_(std::make_unique<node>(root))
//    {}
//
//    // Pre-order root then left then right (process left side)
//    // in-order left, then root, then right (process bottom)
//    // post-order left/right then root. (process right)
//    // binary search tree: left is less than root, right is greater.
//
//};