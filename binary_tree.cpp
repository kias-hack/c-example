#include <iostream>

struct binary_tree_tt;

struct 
binary_tree_tt{
    int value;
    struct binary_tree_tt* first;
    struct binary_tree_tt* second;
};

typedef struct binary_tree_tt binary_tree_t;

class 
binary_tree{
public:
    binary_tree(int depth){
        this->depth = depth;
        this->b_tree.value = 1;
        this->recursive_generate(&this->b_tree, depth-1);
    }

    binary_tree_t *
    search(int value){
        if(this->b_tree.value == value)
            return &this->b_tree;

        return this->recursive_search(&this->b_tree, value);
    } 
    
protected:
    int depth;
    binary_tree_t b_tree;

    binary_tree_t *
    recursive_search ( binary_tree_t *tree, int value ) {
        if(!tree) return tree;

        if(tree->second->value == value) return tree->second;

        if(tree->first->value == value) return tree->first;

        if(tree->second->value < value) return this->recursive_search( tree->second, value );
        
        return this->recursive_search ( tree->first, value );
    }

    void 
    recursive_generate ( binary_tree_t *tree, int depth ) {
        static int count = 1;
        std::cout << "elements: " << count << std::endl;
        tree->value = count++;
        
        if(depth <= 0) return;

        tree->first = new binary_tree_t;
        tree->second = new binary_tree_t;

        this->recursive_generate(tree->first, depth-1);
        this->recursive_generate(tree->second, depth-1);      
    }
};

int main(){
    binary_tree b_tree(4);

    std::cout << b_tree.search(13)->value << std::endl;
    
    return 0;
}
