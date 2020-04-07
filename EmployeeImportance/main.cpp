#include <bits/stdc++.h>

using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    vector<Employee *> Emp;
    unordered_map<int, Employee *> map_;
    int getImp(int id) {
        int rate = map_[id]->importance;
        for (const auto& it : map_[id]->subordinates) rate += getImp(it);
        return rate;
    }
    int getImportance(vector<Employee*> employees, int id) {
        Emp.swap(employees);
//        sort(Emp.begin(), Emp.end(), [](const Employee *a, const Employee *b) {
//            return a->id < b->id;
//        });
        for (const auto& it : Emp) map_[it->id] = it;
        return getImp(id);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
