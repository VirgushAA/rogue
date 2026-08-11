#pragma once

#include <unordered_map>

#include "../core/EntityId.hpp"

template<typename T>
class ComponentStorage
{
    public:
    
    void add(EntityId entity, T component) { components[entity] = component; }
    
    T& get(EntityId entity) { return components.at(entity) }
    
    bool has(EntityId entity) { return components.contains(entity); }

    void remove(EntityId entity) { components.erase(entity); }


    auto begin() { return components.begin(); }
    auto end() { return components.end(); }
    auto begin() const { return components.begin(); }
    auto end() const { return components.end(); }
    
    private:
        std::unordered_map<EntityId, T> components;
};

// template<typename T>
// void ComponentStorage<T>::add(EntityId entity, T component) {
//     components[entity] = component;
// }

// template<typename T>
// T& ComponentStorage<T>::get(EntityId entity) {
//     if (components.contains(entity)) {
//         return components.at(entity);
//     }
// }

// template<typename T>
// bool ComponentStorage<T>::has(EntityId entity) {
//     return components.contains(entity);
// }

// template<typename T>
// void ComponentStorage<T>::remove(EntityId entity) {
//     components.erase(entity);
// }
