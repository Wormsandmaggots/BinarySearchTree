#include <stdio.h>
#include <stdlib.h>
struct node_t{
    int x;
    struct node_t *right;
    struct node_t *left;
};
struct tree_t{
    struct node_t *root;
};
int tree_init(struct tree_t* ptree);
int tree_add2(struct tree_t* ptree, int value);
int tree_minimum(const struct tree_t* ptree, int* poutput);
int tree_maximum(const struct tree_t* ptree, int* poutput);
int node_add(struct node_t *node,int value);
void display_tree(struct node_t *node);
int main() {
    struct tree_t tree;
    tree_init(&tree);
    int tab[] = {8,10,3,6,1,4,7,14,13};
    for (int i=0; i<9; i++)
        tree_add2(&tree, *(tab+i));
    display_tree(tree.root);
    int x;
    tree_minimum(&tree,&x);
    printf("\n%d", x);
    tree_maximum(&tree,&x);
    printf("\n%d", x);
    return 0;
}
int tree_init(struct tree_t* ptree)
{
    if(ptree==NULL)
        return 1;
    ptree->root=NULL;
    return 0;
}
int node_add(struct node_t* node, int value){
    if (node==NULL)
        return 1;
    if (value>node->x){
        if (node->right==NULL){
            node->right = calloc(1,sizeof(struct node_t));
            if (node->right==NULL)
                return 2;
            node->right->x=value;
        }
        else
            return node_add(node->right,value);
    }
    else {
        if (node->left==NULL){
            node->left = calloc(1,sizeof(struct node_t));
            if (node->left==NULL)
                return 2;
            node->left->x=value;
        }
        else
            return node_add(node->left,value);
    }
    return 0;
}
int tree_add2(struct tree_t* ptree, int value){
    if (ptree==NULL)
        return 1;
    if (ptree->root==NULL){
        struct node_t * node = calloc(1,sizeof(struct node_t));
        if (node==NULL)
            return 2;
        node->x=value;
        ptree->root=node;
        return 0;
    }
    return node_add(ptree->root, value);
}
void display_tree(struct node_t *node){
    if (node==NULL) {
        printf("x");
        return;
    }
    printf("%d [", node->x);
    display_tree(node->left);
    display_tree(node->right);
    printf("] ");
}
int node_maximum(const struct node_t* node, int* poutput){
    if (node==NULL || poutput==NULL)
        return 1;
    if (node->right==NULL){
        *poutput=node->x;
        return 0;
    }
    return node_maximum(node->right, poutput);
}
int node_minimum(const struct node_t* node, int* poutput){
    if (node==NULL || poutput==NULL)
        return 1;
    if (node->left==NULL){
        *poutput=node->x;
        return 0;
    }
    return node_minimum(node->left, poutput);
}
int tree_minimum(const struct tree_t* ptree, int* poutput){
    if (ptree==NULL)
        return 1;
    return node_minimum(ptree->root, poutput);
}
int tree_maximum(const struct tree_t* ptree, int* poutput){
    if (ptree==NULL)
        return 1;
    return node_maximum(ptree->root, poutput);
}
int find(struct tree_t *ptree,int value)
{
    if(ptree==NULL)
        return 1;
    struct node_t *temp=ptree->root;
    while(temp!=NULL)
    {
        if(temp->x>value)
            temp=temp->left;
        else if(temp->x<value)
            temp=temp->right;
        else
            return 1;
    }
    return 0;
}
int rode_to_min(struct tree_t *ptree,int *tab,int value)
{
    if(ptree==NULL)
        return 1;
    struct node_t *temp=ptree->root;
    for (int i = 0;temp->left!=NULL; ++i) {
        tab[i]=temp->x;
        if(temp->x==value)
            break;
        temp=temp->left;
    }
    return 0;
}