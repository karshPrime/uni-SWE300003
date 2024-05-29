// Table.h

#pragma once

#include <iostream>
#include <cstddef>

class Table {
private:
    size_t fID;
    size_t fSize;
    bool fIsFree;

public:
    Table();

    void MakeFree() noexcept;
    void Reserve() noexcept;
};

