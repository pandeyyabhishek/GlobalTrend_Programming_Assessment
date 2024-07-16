// 4. Design an algorithm to serialize and deserialize a binary tree.Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.Implement the serialize and deserialize methods.

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                result += "null,";
            }
        }
        return result.substr(0, result.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (getline(ss, item, ','))
            {
                if (item != "null")
                {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
                if (getline(ss, item, ','))
                {
                    if (item != "null")
                    {
                        node->right = new TreeNode(stoi(item));
                        q.push(node->right);
                    }
                }
            }
        }
        return root;
    }
};

int main()
{
    Codec codec;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode *deserialized = codec.deserialize(serialized);
    string deserializedString = codec.serialize(deserialized);
    cout << "Deserialized: " << deserializedString << endl;

    return 0;
}
