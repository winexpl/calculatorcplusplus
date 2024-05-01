#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct TreeNode {
    TreeNode() = default;
    TreeNode(int value) : value { value } { };
    void set_value(int value) {
        this->value = value;
    }
    int get_value() {
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
        int value{};
        TreeNode *left{nullptr};
        TreeNode *right{nullptr};
};

struct Tree {
    Tree() = default;
    Tree(TreeNode *head) : head{ head } { } 
    TreeNode *get_head() {
        return head;
    }
    void output_tree(int mul) {
        int weight{};
        TreeNode *templ = head;
        TreeNode *tempr = head;
        while(templ != nullptr & tempr != nullptr) {
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
    TreeNode node1{1};
    TreeNode node10{2};
    TreeNode node11{3};
    TreeNode node101{4};
    TreeNode node110{5};
    TreeNode node111{6};
    TreeNode node1110{7};
    node1.set_left(&node10);
    node1.set_right(&node11);
    node10.set_right(&node101);
    node11.set_left(&node110);
    node11.set_right(&node111);
    node111.set_left(&node1110);
    Tree tree{&node1};
    tree.output_tree(10);

}

string to_polish(string not_polish) {
    // построение арифметического дерева
    //      написать структуры узла и дерева 
}