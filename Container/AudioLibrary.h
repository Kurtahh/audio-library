#pragma once

#include "../Hierarchy/Track.h"
#include "StatStrategy.h"
#include <vector>
#include <map>

class AudioLibrary {
    struct Impl;
    Impl* pImpl;

    public:
        AudioLibrary();
        AudioLibrary(const AudioLibrary& other);
        ~AudioLibrary();

        void add(Track* t);
        Track* get(int id) const;
        void update(int id, Track* newTrack);
        void remove(int id);

        class Iterator {
            std::map<int, Track*>::iterator it;
            public:
                Iterator(std::map<int, Track*>::iterator it) :
                it(it) {}
                
                Track* operator*() const {
                    return it->second;
                }
                Iterator& operator++() {
                    ++it;
                    return *this;
                }
                bool operator!=(const Iterator& other) const {
                    return it != other.it;
                }
                bool operator==(const Iterator& other) const {
                    return it == other.it;
                }
        };
        Iterator begin() const;
        Iterator end() const;

        template<class Func>
        std::vector<Track*> filter(Func predicate) const {
            std::vector<Track*> results;
            for(Iterator it = begin(); it != end(); ++it){
                if(predicate(*it)){
                    results.push_back(*it);
                }
            }
            return results;
        }

        void setStrategy(StatStrategy* newStrat);
        double compute() const;

        int size() const;

        std::string toString() const;
};