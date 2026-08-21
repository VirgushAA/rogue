#pragma once

#include <unordered_set>
#include <vector>

#include "../ecs/ComponentManager.hpp"
#include "../events/EventManager.hpp"
#include "../events/events.hpp"
#include "../components/Transform.hpp"
#include "../components/Velocity.hpp"
#include "../components/Name.hpp"
#include "../components/Health.hpp"
#include "../components/Mana.hpp"
#include "../components/Inventory.hpp"
#include "../components/Damage.hpp"


class World {
    public:

    EntityId create_entity();

    const std::unordered_set<EntityId>& entities() const;

    template<typename T>
    void add(EntityId entity, T component) { components.add(entity, component); }

    template<typename T>
    T& get(EntityId entity) { return components.get<T>(entity); }

    template<typename T>
    bool has(EntityId entity) const { return components.has<T>(entity); }

    template<typename T>
    void remove(EntityId entity) { components.remove<T>(entity); }

    template<typename First, typename... Rest>
    std::vector<EntityId> query() const {
        std::vector<EntityId> query = {};
        
        const auto* firstStorage = components.findStorage<First>();

        if (!firstStorage) return query;

        for (const auto& [entity, component] : *firstStorage) {
            if ((components.has<Rest>(entity) && ...)) query.push_back(entity);
        }

        return query;
    }

    template<typename T>
    void emit(T event) { events.push(event); };
    
    template<typename T>
    const std::vector<T>& getEvents() const { return events.get<T>(); }

    template<typename T>
    void clearEvents() { events.clear<T>(); }

    std::vector<MoveCommand> commands();

    private:

    EventManager events;
    ComponentManager components;
    std::unordered_set<EntityId> entities_;
    EntityId next_entity_id = 1;

    std::vector<MoveCommand> commands_;
};

#include <string>
struct MoveCommand {
    EntityId target;
    int x;
    int y;
};
