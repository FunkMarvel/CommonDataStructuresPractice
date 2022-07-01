#pragma once

template <typename V, typename K>
class Dictionary {
public:
    Dictionary();
    Dictionary(K Key, V Value);

protected:
    K* Keys_{nullptr};
    V* Values_{nullptr};
    int Size_{};
    int Capacity_{};

    int Hash(K Key);
};

template <typename V, typename K>
Dictionary<V, K>::Dictionary() {}

template <typename V, typename K>
Dictionary<V, K>::Dictionary(K Key, V Value) {}

template <typename V, typename K>
int Dictionary<V, K>::Hash(K Key) {
    int HashedKey{};
    try {
        HashedKey = dynamic_cast<int>(Key) % Capacity_;
    }
    catch (...) {}

    return HashedKey;
}
