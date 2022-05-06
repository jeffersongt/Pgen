#include "core.hpp"
#include "generate.hpp"

void core::help(int exit_status) {
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tpgen [ACTION || port] [project-name]\n" << std::endl;
    std::cout << "ACTIONS:" << std::endl;
    std::cout << "\thelp               print this help section" << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << "\tport               the port you wish to use for your database" << std::endl;
    std::cout << "\tproject-name       the project name" << std::endl;
    exit(exit_status);
}

void core::parsing(int ac, char **av)
{
    if (ac != 3 && ac != 1)
        help(EXIT_FAILURE);
    std::string_view fst_arg = av[1];
    if (fst_arg == "help" || fst_arg == "--help" || fst_arg == "-h")
        help(EXIT_SUCCESS);
}

core::core(int ac, char **av)
{
    parsing(ac, av);
    std::string_view port = av[1];
    std::string_view project = av[2];
    Generate(port, project);
}
