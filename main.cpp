//Name alphabetizer using inorder tree traversal

#include <iostream>
#include <cctype>
using namespace std;

struct tree{
    string data;
    struct tree *left, *right;
};

struct tree* newtree(string name){
    tree* node = (struct tree*)malloc(sizeof(struct tree));
    node->data = name;
    node->left = node->right = nullptr;
    return node;
}

struct tree* insert(struct tree* node, string name){
    if (node == nullptr) return newtree(name);
    if (name < node->data) node->left = insert(node->left, name);
    else if (name > node->data) node->right = insert(node->right, name);
    return node;
}

void print(struct tree* node){
    if (node != nullptr){
        print(node->left);
        cout << node->data << endl;
        print(node->right);
    }
}

int main(){
    cout << "NAME ALPHABETIZER!\nenter a number to finish.\n\n";
    struct tree* root = nullptr;
    string name = "x";
    cout << "name: ";
    cin >> name;
    cout << endl;
    root = insert(root, name);
    while(!isdigit(name[0])){
        cout << "name: ";
        cin >> name;
        if(isdigit(name[0])) break;
        cout << endl;
        insert(root, name);
    }
    cout << endl;
    print(root);
    cout << endl;
    return 0;
}
