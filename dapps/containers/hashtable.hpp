#include <vector>
#include <memory>

class hashtable
{
public:
    typedef std::vector<int>::size_type size_type;

private:
    class hashentry
    {
    private:
        int key_;
        int value_;
    public:
        inline hashentry(int key, int value) : key_(key), value_(value) {}

        inline int get_key() { return key_; }

        inline int get_value() { return value_; }
    };

    std::vector<std::unique_ptr<hashentry>> table_;

public:
    hashtable();
    ~hashtable();
    int get(int key);
    void put(int key, int value);
    inline size_type size() { return table_.size(); }
};

hashtable::hashtable() : table_()
{
    table_.resize(table_.capacity());
}

int hashtable::get(int key)
{
    int hash = key % size();
    while (table_[hash] != nullptr && table_[hash]->get_key() != key)
    {
        // linear probing
        hash = (hash + 1) % size();
    }
    return table_[hash] == nullptr ? -1 : table_[hash]->get_value();
}

void hashtable::put(int key, int value)
{
    int hash = (key % size());
    while (table_[hash] != nullptr && table_[hash]->get_key() != key)
    {
        // linear probing
        hash = (hash + 1) % size();
    }
    table_[hash].swap(std::make_unique<hashentry>(key, value));
}

// collision resolution
// linear probing
// clustering
// chaining