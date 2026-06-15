## Types of trees
1. Full Binary Tree -> either 0 or 2 children
2. Complete Binary Tree -> all levels are completely filled, except the last one. Last level have all elements as left as possible
3. Perfect Binary Tree -> all leaf nodes are at the same level
4. Balanced Binary Tree -> height of the tree can be at max log2(n), n is number of nodes
5. Degenerate Tree -> skewed tree -> linked list


## Represenation of Binary Tree in CPP
```cpp

struct Node{
    int data;
    Struct Node* left;
    Struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}

int main(){
    struct Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    root->left->right = new Node(5);
}

```

## DFS Traversal Techniques
1. InOrder Traversal
- left, root, right

2. preOrder Traversal
- root, left, right

3. PostOrder Traversal
- left, right, root

## BFS Traversal Techniques
1. level order


