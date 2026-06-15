#include <stdexcept>

class NotImplementedException : public std::logic_error {
    public:
        NotImplementedException() : std::logic_error("Method not implemented") {}
};

class StrategyNotSetException : public std::logic_error {
    public:
        StrategyNotSetException() : std::logic_error("Strategy not set") {}
};