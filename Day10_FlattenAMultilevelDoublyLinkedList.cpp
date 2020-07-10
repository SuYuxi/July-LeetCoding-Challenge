/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        vector<Node*> stack;
        Node* node = head;
        while(node || !stack.empty())
        {
            while(node->next && !node->child)
            {
                node = node->next;
            }
            if(node->child)
            {
                if(node->next) stack.emplace_back(node->next);
                node->next = node->child;
                node->child->prev = node;
                node->child = nullptr;
            }
            else if(!stack.empty())
            {
                node->next = stack.back();
                stack.back()->prev = node;
                stack.pop_back();
            }
            node = node->next;
        }

        return head;
    }
};
