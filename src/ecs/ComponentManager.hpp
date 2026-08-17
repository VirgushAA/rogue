#pragma once

#include <typeindex>
#include <memory>
#include <stdexcept>

#include "ComponentStorage.hpp"


class ComponentManager {
    public:

    template<typename T>
    ComponentStorage<T>& get() {

        auto it = findStorage<T>();

        if (!it) throw std::runtime_error("Component storage does not exist");

        return *it;
    }

    template<typename T>
    const ComponentStorage<T>& get() const {

        auto it = findStorage<T>();

        if (!it) throw std::runtime_error("Component storage does not exist");

        return *it;
    }

    template<typename T>
    ComponentStorage<T>& storage() {

        auto type = std::type_index(typeid(T));
        
        auto it = storages.find(type);

        if (it == storages.end()) {

            auto storage = std::make_unique<ComponentStorage<T>>();

            auto* ptr = storage.get();

            storages.emplace(type, std::move(storage));

            return *ptr;
        }

        return *dynamic_cast<ComponentStorage<T>*>(it->second.get());
    }

    template<typename T>
    ComponentStorage<T>* findStorage() {
        auto it = storages.find(typeid(T));

        if (it == storages.end()) { 
            return nullptr;
        }

        return dynamic_cast<ComponentStorage<T>*>(it->second.get());
    }

    template<typename T>
    const ComponentStorage<T>* findStorage() const {
        auto it = storages.find(typeid(T));

        if (it == storages.end()) {
            return nullptr;
        }

        return dynamic_cast<const ComponentStorage<T>*>(it->second.get());
    }

    template<typename T>
    void add(EntityId entity, T component) { storage<T>().add(entity, component); }

    template<typename T>
    T& get(EntityId entity) { return storage<T>().get(entity); }

    template<typename T>
    bool has(EntityId entity) const { return get<T>().has(entity); }
    
    template<typename T>
    void remove(EntityId entity) { storage<T>().remove(entity); }

    private:

    std::unordered_map<
        std::type_index,
        std::unique_ptr<IComponentStorage>
    > storages;
};
