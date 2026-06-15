#pragma once

class AudioLibrary;

class StatStrategy {
    public:
        virtual double compute(const AudioLibrary& other) const = 0;
        virtual ~StatStrategy() = default;
};

class AverageDuration : public StatStrategy {
    public:
        double compute(const AudioLibrary& other) const override;
};

class TotalDuration : public StatStrategy {
    public:
        double compute(const AudioLibrary& other) const override;
};

class TotalSize : public StatStrategy {
    public:
        double compute(const AudioLibrary& other) const override;
};