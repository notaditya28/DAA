//Q1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct act {
    int s, f;
};

bool cmp(act a, act b) {
    return a.f < b.f;
}

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    vector<act> v(n);
    for (int i = 0; i < n; i++) {
        v[i].s = start[i];
        v[i].f = finish[i];
    }

    sort(v.begin(), v.end(), cmp);

    vector<act> res;
    res.push_back(v[0]);
    int last_f = v[0].f;

    for (int i = 1; i < n; i++) {
        if (v[i].s >= last_f) {
            res.push_back(v[i]);
            last_f = v[i].f;
        }
    }

    cout << "Maximum number of activities = " << res.size() << endl;
    cout << "Selected activities: ";
    for (int i = 0; i < res.size(); i++) {
        cout << "(" << res[i].s << ", " << res[i].f << ")";
        if (i < res.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}


//Q2

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    string at[] = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    string dt[] = {"09:40", "12:00", "09:50", "11:30", "11:40"};
    int n = 5;
    vector<int> arr(n), dep(n);

    for (int i = 0; i < n; i++) {
        arr[i] = stoi(at[i].substr(0, 2)) * 60 + stoi(at[i].substr(3, 2));
        dep[i] = stoi(dt[i].substr(0, 2)) * 60 + stoi(dt[i].substr(3, 2));}

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int plat = 1, res = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat++;
            i++;
        } else {
            plat--;
            j++;
}
        res = max(res, plat);}
    cout << "Minimum number of platforms required = " << res << endl;
    return 0;
}


//Q3 Knapsack Problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct item {
    int v, w;
    double r;};
bool cmp(item a, item b) {
    return a.r > b.r;}

int main() {
    int n = 3;
    int value[] = {100, 60, 120};
    int weight[] = {20, 10, 40};
    int w_limit = 50;
    vector<item> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].v = value[i];
        arr[i].w = weight[i];
        arr[i].r = (double)value[i] / weight[i];
    }   
    sort(arr.begin(), arr.end(), cmp);

    int total_v = 0;
    int curr_w = 0;
    for (int i = 0; i < n; i++) {
        if (curr_w + arr[i].w <= w_limit) {
            curr_w += arr[i].w;
            total_v += arr[i].v;
        } else {
            int remain = w_limit - curr_w;
            total_v += arr[i].v * ((double)remain / arr[i].w);
            break;}
    }
    cout << fixed << setprecision(2);
    cout << "Max val = " << total_v << endl;

    return 0;}



//Q4 Job Scheduling
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    string id;
    int dl;
    int profit;
};
bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

void result(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), comp);
    int max_d = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].dl > max_d) max_d = jobs[i].dl;
    }

    vector<int> slot(max_d + 1, -1);
    int total_p = 0;
    vector<string> res;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].dl; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                total_p += jobs[i].profit;
                res.push_back(jobs[i].id);
                break;}}}

    cout << "Selected Jobs: [";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "" : ", ");}
    cout << "]\nMaximum Profit = " << total_p << endl;
}

int main() {
    int n = 5;
    string ids[] = {"J1", "J2", "J3", "J4", "J5"};
    int dead[] = {2, 1, 2, 1, 3};
    int prof[] = {100, 19, 27, 25, 15};
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = {ids[i], dead[i], prof[i]};}

    result(jobs, n);
    return 0;}


//Q4

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    char symbol;
    int weight;
    TreeNode *leftChild, *rightChild;
};

TreeNode* makeNode(char s, int w) {
    TreeNode* temp = new TreeNode();
    temp->symbol = s;
    temp->weight = w;
    temp->leftChild = temp->rightChild = NULL;
    return temp;
}

struct minOrder {
    bool operator()(TreeNode* x, TreeNode* y) {
        return x->weight > y->weight;
    }
};

void displayCode(TreeNode* root, string path) {
    if (!root) return;

    if (root->symbol != '#')
        cout << root->symbol << "   " << path << endl;

    displayCode(root->leftChild, path + "0");
    displayCode(root->rightChild, path + "1");
}

int main() {
    char letters[] = {'a','b','c','d','e','f'};
    int weights[] = {5,9,12,13,16,45};

    priority_queue<TreeNode*, vector<TreeNode*>, minOrder> heap;

    for (int i = 0; i < 6; i++)
        heap.push(makeNode(letters[i], weights[i]));

    while (heap.size() > 1) {
        TreeNode* first = heap.top(); heap.pop();
        TreeNode* second = heap.top(); heap.pop();

        TreeNode* merged = makeNode('#', first->weight + second->weight);
        merged->leftChild = first;
        merged->rightChild = second;

        heap.push(merged);
    }

    cout << "Character  Code\n";
    displayCode(heap.top(), "");

    return 0;
}
