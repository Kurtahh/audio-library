#pragma once
#include "../Hierarchy/Track.h"
#include "StatStrategy.h"
#include <vector>
#include <map>

// Container for managing a collection of audio tracks (Songs, Podcasts, Audiobooks).
// Supports CRUD operations, iteration, deep copying, strategy-based computation,
// and predicate-based filtering.
class AudioLibrary {
    struct Impl; // Forward declaration of implementation (pimpl idiom)
    Impl* pImpl;
    public:
        // Constructs an empty library
        AudioLibrary();

        // Deep copies the given library, cloning each track polymorphically
        AudioLibrary(const AudioLibrary& other);

        // Destroys the library and frees all owned tracks
        ~AudioLibrary();

        // Adds a track to the library and assigns it a unique id
        void add(Track* t);

        // Returns the track with the given id, throws std::out_of_range if not found
        Track* get(int id) const;

        // Replaces the track at the given id with a new track, deleting the old one
        void update(int id, Track* newTrack);

        // Removes and deletes the track with the given id
        void remove(int id);

        // Forward iterator for traversing tracks in the library
        class Iterator {
            std::map<int, Track*>::iterator it;
        public:
            // Constructs an iterator wrapping the given map iterator
            Iterator(std::map<int, Track*>::iterator it) : it(it) {}

            // Dereferences to the current Track*
            Track* operator*() const {
                return it->second;
            }

            // Advances to the next track
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

        // Returns an iterator to the first track
        Iterator begin() const;

        // Returns an iterator past the last track
        Iterator end() const;

        // Returns all tracks for which the given predicate returns true
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

        // Sets the strategy to be used by compute()
        void setStrategy(StatStrategy* newStrat);

        // Computes a statistic over all tracks using the current strategy.
        // Throws StrategyNotSetException if no strategy has been set.
        double compute() const;

        // Returns the number of tracks in the library
        int size() const;

        // Returns a string representation of all tracks in the library
        std::string toString() const;
};