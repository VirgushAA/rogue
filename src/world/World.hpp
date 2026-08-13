#include "../ecs/ComponentManager.hpp"


class World {
    public:

    EntityId create_entity();

    template<typename T>
    void add(EntityId entity, T component) { components.add(entity, component); }

    template<typename T>
    T& get(EntityId entity) { return components.get<T>(entity); }

    private:

    ComponentManager components;

    EntityId next_entity_id = 1;
};
