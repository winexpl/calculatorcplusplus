#include <cstdio>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

struct TreeNode {
    TreeNode() = default;
    TreeNode(double value) : value { value } { };
    void set_value(double value) {
        this->value = value;
    }
    double get_value() {
        return value;
    }
    TreeNode* get_left() {
        return this->left;
    }
    void set_left(TreeNode *left) {
        this->left = left;
    }
    TreeNode* get_right() {
        return this->right;
    }
    void set_right(TreeNode *right) {
        this->right = right;
    }
    private:
        double value{};
        TreeNode *left{nullptr};
        TreeNode *right{nullptr};
};

struct Tree {
    Tree() = default;

    template <size_t len>
    Tree(double (&values)[len]) {
        if(len == 0 || isnan(values[0])) return;
        int h = log(len)/log(2); // length of tree
        TreeNode **nodes = new TreeNode*[len] {}; // array for save all elements of our tree 
        this->head = new TreeNode{values[0]}; // the first element is the head
        nodes[0] = this->head; // save head in array
        int i_parent = 0; // 
        int i_cur = 1;
        for(size_t i = 2; i < h+1; i++) {
            int len_level = pow(2,i+2);
            for(; i_cur < len_level-1; i_cur++, i_parent++) {
                if(i_cur==len) return;
                // set left
                nodes[i_cur] = isnan(values[i_cur])? nullptr: new TreeNode{values[i_cur]};
                if(nodes[i_parent]) {
                    nodes[i_parent]->set_left(nodes[i_cur]);
                    i_cur++; 
                    if(i_cur==len) return;
                    //set right
                    nodes[i_cur] = isnan(values[i_cur])? nullptr: new TreeNode{values[i_cur]};
                    nodes[i_parent]->set_right(nodes[i_cur]);

                } else i_cur++;
                
            }
            i_parent=len_level-1;
        }
    }
    Tree(TreeNode *head) : head{ head } { } 
    TreeNode *get_head() {
        return head;
    }
    void output_tree(int mul) {
        int weight{};
        TreeNode *templ = head;
        TreeNode *tempr = head;
        while(templ != nullptr || tempr != nullptr) {
            if (templ) templ = templ->get_left();
            if (tempr) tempr = tempr->get_right();
            weight++;
        }
        weight*=mul;
        TreeNode **array{new TreeNode*[1]{head}};
        BFS(array, 1, 1, weight);
    }

    private:
        TreeNode *head;
        void BFS(TreeNode **old_array, int len_node, int row, int weight) {

            for(int i{}; i < len_node; i++) {
                 
                for(int i{}; i < weight; i++) {
                    cout << ' ';
                }
                if(!old_array[i]) cout << ' ';
                else cout << old_array[i]->get_value();
                for(int i{}; i < weight; i++) {
                    cout << ' ';
                }
            }
            cout << endl << endl;
            
            TreeNode **new_array = new TreeNode*[len_node*2]{};
            int j{};
            for(int i{}; i < len_node; i++) {
                if(!old_array[i]) continue;
                TreeNode *left, *right;
                if(left = old_array[i]->get_left()) {
                    j++;
                }
                new_array[i*2] = left;
                if(right = old_array[i]->get_right()) {
                    j++;
                }
                new_array[i*2+1] = right;
            }
            delete[] old_array;
            if(!j) return;
            
            BFS(new_array, len_node*2, row+1, weight/2);
        }
};

int main() {
    cout << "hi!" << endl;

    double arr[]{1,2,3,NAN,5,6,7,8,9,10,11,12,13,14,15,16,17};
    Tree tree{arr};
    tree.output_tree(20);
}

string to_polish(string not_polish) {
    // построение арифметического дерева
    //      написать структуры узла и дерева 
}