#pragma once

#include "ComponentStorage.hpp"

class ComponentManager {
    public:

    template<typename T>
    void add(EntityId entity, T component);

    template<typename T>
    T& get(EntityId entity);

    template<typename T>
    bool has(EntityId entity) const;
};
