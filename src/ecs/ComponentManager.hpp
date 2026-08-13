#pragma once

#include <typeindex>
#include <memory>

#include "ComponentStorage.hpp"


class ComponentManager {
    public:

    template<typename T>
    ComponentStorage<T>& get() {

        auto it = storages.find(typeid(T));
    
        // auto* storage = dynamic_cast<ComponentStorage<T>*>(it->second.get());

        return *dynamic_cast<ComponentStorage<T>*>(it->second.get());;
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
    void add(EntityId entity, T component) { storage<T>().add(entity, component); }

    template<typename T>
    T& get(EntityId entity) { return storage<T>().get(entity); }

    private:

    std::unordered_map<
        std::type_index,
        std::unique_ptr<IComponentStorage>
    > storages;
};
