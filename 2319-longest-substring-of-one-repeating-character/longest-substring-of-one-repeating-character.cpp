class Solution {
public:
    struct Node {
        int len;
        int leftChar, rightChar;
        int pref, suff, best;

        Node() {
            len = 0;
            leftChar = rightChar = -1;
            pref = suff = best = 0;
        }

        Node(char c) {
            len = 1;
            leftChar = rightChar = c;
            pref = suff = best = 1;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;

        // Prefix can extend into b
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref = a.len + b.pref;

        // Suffix can extend into a
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff = b.len + a.suff;

        // Best substring
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();
        int k = queryIndices.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> lengths;

        for (int i = 0; i < k; i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, index, c);

            lengths.push_back(tree[1].best);
        }

        return lengths;
    }
};