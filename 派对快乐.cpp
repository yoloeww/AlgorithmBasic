
#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Employee{
public:
    int happy;
    vector<Employee*> sub;
    Employee(int h):happy(h){}
   
};
class returnData{
public:
    int yesMax;
    int noMax;
    returnData(int yes,int no):yesMax(yes),noMax(no)
    {}
};
returnData process(Employee* x) {
    int yesX = x -> happy;
    int noX = 0;
    if(x -> sub.size() == 0) {
        return returnData(yesX,noX);
    }
    else {
        for (auto next : x -> sub) {
            returnData subTree = process(next);
            yesX += subTree.noMax;
            noX += max(subTree.noMax,subTree.yesMax);
        }
    }
    return returnData(yesX,noX);
}
int getMaxHappy(Employee* boss) {
    returnData allTreeinfo =  process(boss);
    return max(allTreeinfo.yesMax,allTreeinfo.noMax);
}
int main() {
    int n,root;
    cin >> n >> root;
    vector<Employee*> happy(n);
    int t;
    for(int i = 0;i < n;++i){
        cin >> t;
        happy[i] = new Employee(t);
    }
    int u,v;
    for(int i = 1;i < n;++i){
        cin >> u >> v;
        happy[u-1]->sub.push_back(happy[v-1]);
    }
    auto x= getMaxHappy(happy[root-1]);
    cout << x << endl;
    return 0;
}
