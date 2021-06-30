// credit to https://github.com/rohin-garg

template <typename K>
struct ms : public map<K, int> {
    using map<K, int>::count;
    using map<K, int>::at;
    using map<K, int>::insert;
    using map<K, int>::erase;
    
    int my_size=0;
    size_t size(){
        return my_size;
    }
    void clear() {
        map<K, int>::clear();
        my_size = 0;
    }
    void er(K x){
        if (count(x)) {
            at(x)--;
            if (!at(x)) erase(x);
            my_size--;
        }
    }
    void add(K x){
        if (count(x)) at(x)++;
        else insert(make_pair(x, 1));
        my_size++;
    }
};
