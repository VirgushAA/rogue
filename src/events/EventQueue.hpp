#pragma once

#include <vector>


class IEventQueue {
    public:

    virtual ~IEventQueue() = default;
};

template<typename T>
class EventQueue : public IEventQueue {
    public:

    void push(T event) {events.push_back(event); }

    const std::vector<T>& get() const { return events; }

    void clear() { events.clear(); }


    auto begin() { return events.begin(); }
    auto end() { return events.end(); }
    auto begin() const { return events.begin(); }
    auto end() const { return events.end(); }

    private:

    std::vector<T> events;
};
