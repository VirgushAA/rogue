#pragma once

#include <unordered_map>
#include <memory>
#include <typeindex>

#include "EventQueue.hpp"


class EventManager {
    public:

    template<typename T>
    EventQueue<T>& queue() {

        auto  type = std::type_index(typeid(T));
        auto it = queues.find(type);

        if (it == queues.end()) {

            auto queue = std::make_unique<EventQueue<T>>();
            auto* ptr = queue.get();
            queues.emplace(type, std::move(queue));

            return *ptr;
        }

        return *dynamic_cast<EventQueue<T>*>(it->second.get());
    }

    template<typename T>
    EventQueue<T>* findQueue() {
        auto it = queues.find(std::type_index(typeid(T)));

        if (it == queues.end()) { 
            return nullptr;
        }

        return dynamic_cast<EventQueue<T>*>(it->second.get());
    }

    template<typename T>
    const EventQueue<T>* findQueue() const {
        auto it = queues.find(std::type_index(typeid(T)));

        if (it == queues.end()) { 
            return nullptr;
        }

        return dynamic_cast<const EventQueue<T>*>(it->second.get());
    }

    template<typename T>
    void push(T event) { queue<T>().push(event); }

    template<typename T>
    const std::vector<T>& get() const {
        static const std::vector<T> empty;

        auto queue = findQueue<T>();

        if (!queue) return empty;

        return queue->get();
    }

    template<typename T>
    void clear() { queue<T>().clear(); }

    private:

    std::unordered_map<
        std::type_index,
        std::unique_ptr<IEventQueue>
        > queues;
};
