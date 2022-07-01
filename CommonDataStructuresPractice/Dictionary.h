#pragma once

template <typename V, typename K>
class Dictionary {
public:
    Dictionary();
    Dictionary(K Key, V Value);

protected:
    K* Keys{nullptr};
    V* Values{nullptr};
    int Size{};
    int Capacity{};

    int Hash(K Key);
};
