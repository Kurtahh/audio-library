#pragma once

class AudioLibrary;

// Abstract base class for strategies that compute a statistic over an AudioLibrary.
// Implement compute() in a derived class to define a new computation.
class StatStrategy {
    public:
        // Computes and returns a statistic over the given library
        virtual double compute(const AudioLibrary& other) const = 0;

        virtual ~StatStrategy() = default;
};

// Computes the average duration of all tracks in the library (in seconds)
class AverageDuration : public StatStrategy {
    public:
        double compute(const AudioLibrary& other) const override;
};

// Computes the total combined duration of all tracks in the library (in seconds)
class TotalDuration : public StatStrategy {
    public:
        double compute(const AudioLibrary& other) const override;
};

// Computes the total combined file size of all tracks in the library (in MB)
class TotalSize : public StatStrategy {
    public:
        double compute(const AudioLibrary& other) const override;
};