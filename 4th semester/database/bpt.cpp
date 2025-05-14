#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

const int DEFAULT_ORDER = 3; // Default order of the B+ tree

template <typename Key, typename Value>
class BPlusTree
{
private:
    struct Node
    {
        bool is_leaf;
        vector<Key> keys;
        vector<Node *> children; // For non-leaf nodes
        vector<Value> values;    // For leaf nodes
        Node *next;              // Pointer to next leaf node (for leaf nodes)
        Node *parent;

        Node(bool leaf = false) : is_leaf(leaf), next(nullptr), parent(nullptr) {}

        bool is_full(int order)
        {
            return is_leaf ? (values.size() > order) : (children.size() > order + 1);
        }
    };

    Node *root;
    int order;

    // Helper functions
    Node *find_leaf_node(const Key &key)
    {
        Node *current = root;
        while (!current->is_leaf)
        {
            int idx = upper_bound(current->keys.begin(), current->keys.end(), key) - current->keys.begin();
            current = current->children[idx];
        }
        return current;
    }

    void insert_in_leaf(Node *leaf, const Key &key, const Value &value)
    {
        auto it = upper_bound(leaf->keys.begin(), leaf->keys.end(), key);
        int idx = it - leaf->keys.begin();

        leaf->keys.insert(it, key);
        leaf->values.insert(leaf->values.begin() + idx, value);
    }

    void insert_in_parent(Node *n, const Key &key, Node *n_prime)
    {
        if (n == root)
        {
            root = new Node(false);
            root->keys.push_back(key);
            root->children.push_back(n);
            root->children.push_back(n_prime);
            n->parent = root;
            n_prime->parent = root;
            return;
        }

        Node *parent = n->parent;
        auto it = upper_bound(parent->keys.begin(), parent->keys.end(), key);
        int idx = it - parent->keys.begin();

        parent->keys.insert(it, key);
        parent->children.insert(parent->children.begin() + idx + 1, n_prime);
        n_prime->parent = parent;

        if (parent->is_full(order))
        {
            split_non_leaf(parent);
        }
    }

    void split_leaf(Node *leaf)
    {
        Node *new_leaf = new Node(true);
        int split_pos = (order + 1) / 2;

        // Move half the keys and values to the new leaf
        new_leaf->keys.assign(leaf->keys.begin() + split_pos, leaf->keys.end());
        new_leaf->values.assign(leaf->values.begin() + split_pos, leaf->values.end());
        leaf->keys.resize(split_pos);
        leaf->values.resize(split_pos);

        // Update linked list pointers
        new_leaf->next = leaf->next;
        leaf->next = new_leaf;
        new_leaf->parent = leaf->parent;

        // Promote the first key of new leaf to parent
        Key promote_key = new_leaf->keys[0];
        insert_in_parent(leaf, promote_key, new_leaf);
    }

    void split_non_leaf(Node *node)
    {
        Node *new_node = new Node(false);
        int split_pos = (order + 1) / 2;
        Key promote_key = node->keys[split_pos];

        // Move half the keys and children to the new node
        new_node->keys.assign(node->keys.begin() + split_pos + 1, node->keys.end());
        new_node->children.assign(node->children.begin() + split_pos + 1, node->children.end());
        node->keys.resize(split_pos);
        node->children.resize(split_pos + 1);

        // Update parent pointers of moved children
        for (Node *child : new_node->children)
        {
            child->parent = new_node;
        }
        new_node->parent = node->parent;

        insert_in_parent(node, promote_key, new_node);
    }

public:
    BPlusTree(int ord = DEFAULT_ORDER) : order(ord), root(nullptr) {}

    ~BPlusTree()
    {
        // Implement proper destruction to avoid memory leaks
        // This is a simplified version - in production, you'd need a proper cleanup
        if (root)
        {
            queue<Node *> q;
            q.push(root);
            while (!q.empty())
            {
                Node *current = q.front();
                q.pop();
                if (!current->is_leaf)
                {
                    for (Node *child : current->children)
                    {
                        if (child)
                            q.push(child);
                    }
                }
                delete current;
            }
        }
    }

    void insert(const Key &key, const Value &value)
    {
        if (root == nullptr)
        {
            root = new Node(true);
            root->keys.push_back(key);
            root->values.push_back(value);
            return;
        }

        Node *leaf = find_leaf_node(key);
        insert_in_leaf(leaf, key, value);

        if (leaf->is_full(order))
        {
            split_leaf(leaf);
        }
    }

    bool search(const Key &key, Value &result)
    {
        if (root == nullptr)
            return false;

        Node *leaf = find_leaf_node(key);
        auto it = lower_bound(leaf->keys.begin(), leaf->keys.end(), key);

        if (it != leaf->keys.end() && *it == key)
        {
            int idx = it - leaf->keys.begin();
            result = leaf->values[idx];
            return true;
        }
        return false;
    }

    vector<Value> range_query(const Key &start, const Key &end)
    {
        vector<Value> results;
        if (root == nullptr)
            return results;

        Node *leaf = find_leaf_node(start);
        while (leaf != nullptr)
        {
            for (size_t i = 0; i < leaf->keys.size(); ++i)
            {
                if (leaf->keys[i] >= start && leaf->keys[i] <= end)
                {
                    results.push_back(leaf->values[i]);
                }
                if (leaf->keys[i] > end)
                {
                    return results;
                }
            }
            leaf = leaf->next;
        }
        return results;
    }

    void print_tree()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node *> q;
        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            cout << "Level " << level << ": ";
            for (int i = 0; i < size; ++i)
            {
                Node *current = q.front();
                q.pop();

                cout << "[";
                for (size_t j = 0; j < current->keys.size(); ++j)
                {
                    cout << current->keys[j];
                    if (j != current->keys.size() - 1)
                        cout << ", ";
                }
                cout << "] ";

                if (!current->is_leaf)
                {
                    for (Node *child : current->children)
                    {
                        q.push(child);
                    }
                }
            }
            cout << endl;
            level++;
        }
    }

    void print_graph()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<pair<Node *, int>> q;
        q.push({root, 0});
        int current_level = 0;

        cout << "B+ Tree Structure:" << endl;
        cout << "==================" << endl;

        while (!q.empty())
        {
            auto [node, level] = q.front();
            q.pop();

            if (level > current_level)
            {
                cout << endl;
                current_level = level;
            }

            // Print node
            if (node->is_leaf)
            {
                cout << "L[";
            }
            else
            {
                cout << "I[";
            }

            for (size_t i = 0; i < node->keys.size(); ++i)
            {
                cout << node->keys[i];
                if (i != node->keys.size() - 1)
                    cout << "|";
            }
            cout << "] ";

            // Push children
            if (!node->is_leaf)
            {
                for (Node *child : node->children)
                {
                    q.push({child, level + 1});
                }
            }
        }
        cout << endl
             << "==================" << endl;
    }

    void print_graph_with_connections()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<pair<Node *, int>> q;
        q.push({root, 0});
        int current_level = 0;

        cout << "\nB+ Tree with Connections:" << endl;
        cout << "=========================" << endl;

        while (!q.empty())
        {
            auto [node, level] = q.front();
            q.pop();

            if (level > current_level)
            {
                cout << endl;
                current_level = level;
                // Print connecting lines
                cout << string(50, '-') << endl;
            }

            // Print node
            if (node->is_leaf)
            {
                cout << "L[";
            }
            else
            {
                cout << "I[";
            }

            for (size_t i = 0; i < node->keys.size(); ++i)
            {
                cout << node->keys[i];
                if (i != node->keys.size() - 1)
                    cout << "|";
            }
            cout << "] ";

            // Print parent info
            if (node->parent)
            {
                cout << "(P:";
                for (size_t i = 0; i < node->parent->keys.size(); ++i)
                {
                    cout << node->parent->keys[i];
                    if (i != node->parent->keys.size() - 1)
                        cout << "|";
                }
                cout << ") ";
            }

            // Print next pointer for leaves
            if (node->is_leaf && node->next)
            {
                cout << "-> L[";
                for (size_t i = 0; i < node->next->keys.size(); ++i)
                {
                    cout << node->next->keys[i];
                    if (i != node->next->keys.size() - 1)
                        cout << "|";
                }
                cout << "]\t\t";
            }

            // Push children
            if (!node->is_leaf)
            {
                for (Node *child : node->children)
                {
                    q.push({child, level + 1});
                }
            }
        }
        cout << endl
             << "=========================" << endl;
    }
};

string numtos(int n)
{
    return std::to_string(n);
}

int main()
{
    int n, k;
    cin >> n >> k;
    BPlusTree<int, string> bptree(k);

    // Insert some data
    for (int i = 0; i < n; i++)
    {
        int x = 10;
        cin >> x;
        bptree.insert(x, numtos(x));
    }

    // Print the tree structure
    cout << "Basic Tree Structure:" << endl;
    bptree.print_tree();
    cout << endl;

    // Print the tree as a graph
    bptree.print_graph();
    cout << endl;

    // Print the tree with connections
    bptree.print_graph_with_connections();
    cout << endl;

    // Search for a key
    string value;
    if (bptree.search(35, value))
    {
        cout << "Found key 35: " << value << endl;
    }
    else
    {
        cout << "Key 35 not found" << endl;
    }

    // Range query
    cout << "\nRange query [25-60]:" << endl;
    auto results = bptree.range_query(25, 60);
    for (const auto &val : results)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}