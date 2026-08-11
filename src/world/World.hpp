

class World {
    public:

    EntityId create_entity();

    private:

    EntityId next_entity_id = 1;
};
