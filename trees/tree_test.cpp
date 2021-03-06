#include "AVLTree.h"
#include "BST.h"
#include "RedBlackTree.h"
#include "Treap.h"

#include <chrono>
#include <climits>
#include <random>
#include <string>

class TimeProfiler {
    using time_point = typename std::chrono::high_resolution_clock::time_point;
public:
    TimeProfiler() : message_("operation took"), out_(std::cout) {
        now_ = std::chrono::high_resolution_clock::now();
    }

    explicit TimeProfiler(const std::string& msg, std::ostream& out = std::cout)
            : message_(msg),
              out_(out) {
        now_ = std::chrono::high_resolution_clock::now();
    }

    ~TimeProfiler() {
        time_point tmp = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double, std::milli>(tmp - now_).count() / 1000;
        out_ << message_ << ' '
             << time
             << " seconds\n";
    }

private:
    time_point now_;
    std::string message_;
    std::ostream& out_;
};

int main() {
    const size_t kSize = 1 << 10;
    const int kSeed = INT_MAX;

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<> distr(-kSeed, kSeed);

    BST<int> bstree;
    RedBlackTree<int> rbtree;
    AVLTree<int> avl;
    Treap<int> treap;

    /*{
        TimeProfiler profiler1("naive Binary Search Tree test");

        for (size_t i = 0; i < kSize; ++i) {
            bstree.Insert(distr(generator));
        }

        for (size_t i = 0; i < kSize; ++i) {
            bstree.Delete(distr(generator));
        }
    }

    {
        TimeProfiler profiler2("Red-Black Tree test");

        for (size_t i = 0; i < kSize; ++i) {
            rbtree.Insert(distr(generator));
        }

        for (size_t i = 0; i < kSize; ++i) {
            rbtree.Delete(distr(generator));
        }
    }

    {
        TimeProfiler profiler3("AVL Tree test");

        for (size_t i = 0; i < kSize; ++i) {
            avl.Insert(distr(generator));
        }

        for (size_t i = 0; i < kSize; ++i) {
            avl.Delete(distr(generator));
        }
    }*/

    {
        TimeProfiler profile;
        for (size_t i = 0; i < kSize; ++i) {
            treap.Insert(distr(generator));
        }

        for (size_t i = 0; i < kSize; ++i) {
            treap.Delete(distr(generator));
        }
    }

    return 0;
}