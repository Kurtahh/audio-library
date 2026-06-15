#pragma once
#include <stdexcept>

// Thrown when a method is deliberately not implemented (e.g. Audiobook::toString())
class NotImplementedException : public std::logic_error {
    public:
        NotImplementedException() : std::logic_error("Method not implemented") {}
};

// Thrown when AudioLibrary::compute() is called without a strategy set
class StrategyNotSetException : public std::logic_error {
    public:
        StrategyNotSetException() : std::logic_error("Strategy not set") {}
};