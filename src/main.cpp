#include "core.hpp"

int main(int ac, char **av)
{
    try {
        core(ac, av);
        return EXIT_SUCCESS;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}