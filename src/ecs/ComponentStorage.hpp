#pragma once

#include <unordered_map>

#include "../core/EntityId.hpp"


class IComponentStorage {
    public:
    virtual ~IComponentStorage() = default;
    virtual std::size_t size() const = 0;
};


template<typename T>
class ComponentStorage : public IComponentStorage
{
    public:
    
    void add(EntityId entity, T component) { components[entity] = component; }
    
    const T& get(EntityId entity) const { return components.at(entity); }

    T& get(EntityId entity) { return components.at(entity); }

    bool has(EntityId entity) const { return components.contains(entity); } //return components.find(entity) != components.end(); c++17

    void remove(EntityId entity) { components.erase(entity); }

    std::size_t size() const override { return components.size(); }


    auto begin() { return components.begin(); }
    auto end() { return components.end(); }
    auto begin() const { return components.begin(); }
    auto end() const { return components.end(); }
    
    private:
        std::unordered_map<EntityId, T> components;
};
