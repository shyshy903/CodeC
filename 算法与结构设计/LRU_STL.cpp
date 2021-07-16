#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


class Lru{
    size_t _capacity;  // 容量
    unordered_map<int, list<pair<int, int>> > map;  // hashmap
    list<pair<int, int>> m_list;  // 双向链表
public:
    Lru(size_t capa):_capacity(capa){};

    int get(int key){
        auto it = map.find(key);
        if(it != map.end()){
            m_list.splice(m_list.begin(), m_list, it->second);  //移动到队头节点
            return it->second->second;
        }
        return -1;
    }

    void push(int key, int value){
        auto it = map.find(key);
        if(map.find(key) != map.end()){
            m_list.splice(m_list.begin(), m_list, it->second); 
            it->second->second = value;
        }

        if(map.size == _capacity){
            int key_to_del = m_list.back().first;
            m_list.pop_back();
            map.erase(key_to_del);
        }
        m_list.emplace_front(key,value);
        map[key] = m_list.begin();
    }
}