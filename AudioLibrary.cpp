#include "AudioLibrary.h"
#include "Exceptions.h"
#include <sstream>
using namespace std;

struct AudioLibrary::Impl {
    map<int, Track*> tracks;
    int nextID = 0;
    StatStrategy* strat = nullptr;    
};

AudioLibrary::AudioLibrary() : pImpl(new Impl) {};

AudioLibrary::AudioLibrary(const AudioLibrary& other) {
    pImpl = new Impl;
    pImpl->nextID = other.pImpl->nextID;
    pImpl->strat = other.pImpl->strat;
    for(const auto& [id, track] : other.pImpl->tracks){
        pImpl->tracks[id] = track->clone();
    }
}

AudioLibrary::~AudioLibrary() {
    for(const auto& [id, track] : pImpl->tracks){
        delete track;
    }
    delete pImpl;
}

void AudioLibrary::add(Track* t) {
    t->setID(pImpl->nextID);
    pImpl->tracks[pImpl->nextID] = t;
    pImpl->nextID++;
}

Track* AudioLibrary::get(int id) const {
    return pImpl->tracks.at(id);
}

void AudioLibrary::update(int id, Track* newTrack) {
    delete pImpl->tracks[id];
    newTrack->setID(id);
    pImpl->tracks[id] = newTrack;
}

void AudioLibrary::remove(int id) {
    delete pImpl->tracks[id];
    pImpl->tracks.erase(id);
}

AudioLibrary::Iterator AudioLibrary::begin() const {
    return AudioLibrary::Iterator(pImpl->tracks.begin());
}

AudioLibrary::Iterator AudioLibrary::end() const {
    return AudioLibrary::Iterator(pImpl->tracks.end());
}

void AudioLibrary::setStrategy(StatStrategy* s) {
    pImpl->strat = s;
}

double AudioLibrary::compute() const {
    if(pImpl->strat == nullptr){
        throw StrategyNotSetException();
    }

    return pImpl->strat->compute(*this);
}

int AudioLibrary::size() const {
    return pImpl->tracks.size();
}

std::string AudioLibrary::toString() const {
    stringstream ss;
    for(Iterator it = begin(); it != end(); ++it){
        ss << (*it)->toString() << "\n";
    }
    return ss.str();
}