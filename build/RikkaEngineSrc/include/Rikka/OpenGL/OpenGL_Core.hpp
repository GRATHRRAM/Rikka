#include <string>
#include "../Types.hpp"

namespace rkk { 
    class Engine {
        public:
        Engine(const std::string& Title, ruint Width, ruint Height);
        ~Engine();
    };
}