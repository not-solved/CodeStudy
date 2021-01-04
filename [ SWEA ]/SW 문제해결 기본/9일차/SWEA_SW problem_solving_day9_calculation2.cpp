#define MAX_NODE_NUM 1000
#define MAX_CHILD_NUM 2
#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

typedef struct
{
    int parent;
    int child[MAX_CHILD_NUM];
    double data;
    char op;
} TreeNode;

TreeNode tree[MAX_NODE_NUM];
int nodeNum;
stack <double> s;
queue <double> q;

void initTree(void)
{
    int i;
    int j;
    for (i = 0; i <= nodeNum; i++)
    {
        tree[i].parent = -1;
        for (j = 0; j < MAX_CHILD_NUM; j++)
        {
            tree[i].child[j] = -1;
        }
        tree[i].data = 0;
        tree[i].op = 0;
    }
}

void addChild(int parent, int child)
{
    int i;
    for (i = 0; i < MAX_CHILD_NUM; i++)
    {
        if (tree[parent].child[i] == -1)
        {
            break;
        }
    }
    tree[parent].child[i] = child;
    tree[child].parent = parent;
}

void postorder(int x) {
    int child;
    for (int i = 0; i < MAX_CHILD_NUM; i++)
    {
        child = tree[x].child[i];
        if (child != -1)
        {
            postorder(child);
        }
    }
    if (tree[x].data == 0) {
        q.push(tree[x].op * (-1));
    }
    else q.push(tree[x].data);
}

int calc() {
    while (!q.empty()) {//calc
        double op1, op2;
        if (q.front() == ((int)'+' * (-1)) || q.front() == ((int)'-' * (-1)) || q.front() == ((int)'*' * (-1)) || q.front() == ((int)'/' * (-1))) {
            if (q.front() == ((int)'+' * (-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 + op1);
            }
            else if (q.front() == ((int)'-' * (-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 - op1);
            }
            else if (q.front() == ((int)'*' * (-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 * op1);
            }
            else if (q.front() == ((int)'/' * (-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 / op1);
            }
        }
        else {
            s.push(q.front());
            q.pop();
        }
    }
    int answer = s.top();
    return answer;
}

int main(void)
{
    int test_case;
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> nodeNum;
        initTree();
        for (int i = 1; i <= nodeNum; i++) {
            string str;
            int num;
            cin >> num >> str;
            if (str.compare("+") == 0 || str.compare("-") == 0 || str.compare("*") == 0 || str.compare("/") == 0) {
                int L, R;
                cin >> L >> R;
                addChild(i, L);
                addChild(i, R);
                tree[i].op = str.front();
            }
            else {
                double x = stoi(str);
                tree[i].data = x;
            }
        }
        postorder(1);
        cout << "#" << test_case << ' ' << calc() << endl;
        while (!q.empty())q.pop();
        while (!s.empty())s.pop();
    }
    return 0;
}