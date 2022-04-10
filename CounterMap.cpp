#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class CounterMap {
public:
    
    CounterMap(vector<T> array){
        for(auto element : array)
            counter[element] += 1;
            vec = array;
    }
    
    unordered_map<T, int> GetCounter() const {
        return counter;
    }
    
    template <typename U>
    friend ostream & operator << (ostream &out, const CounterMap<U> &c);
    unordered_map<T, int> counter;
    vector<T> vec;
};

template <typename U>
ostream & operator << (ostream &out, const CounterMap<U> &c){
    
    out << "{ ";
    for (auto& it: c.GetCounter()) {
        cout << it.first << ":" << it.second << " ";
    }
    out << "}";
    return out;
}

int main()
{
    vector<int> vec = {1,2,3,1};
    CounterMap<int> counterMap(vec);
    cout << counterMap;
    return 0;
}
