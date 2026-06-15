#include "StatStrategy.h"
#include "AudioLibrary.h"

double AverageDuration::compute(const AudioLibrary& lib) const {
    double durCounter = 0;
    for(AudioLibrary::Iterator it = lib.begin(); it != lib.end(); ++it){
        durCounter += (*it)->getDuration();  
    }
    return durCounter/lib.size();
}

double TotalDuration::compute(const AudioLibrary& lib) const {
    double durCounter = 0;
    for(AudioLibrary::Iterator it = lib.begin(); it != lib.end(); ++it){
        durCounter += (*it)->getDuration();  
    }
    return durCounter;
}

double TotalSize::compute(const AudioLibrary& lib) const {
    double sizeCounter = 0;
    for(AudioLibrary::Iterator it = lib.begin(); it != lib.end(); ++it){
        sizeCounter += (*it)->getSize();  
    }
    return sizeCounter;
}