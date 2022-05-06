#pragma once
#include <string>
#include <iostream>

class core {
  public:
    core(int ac, char **av);
    ~core() = default;

    static void help(int exit_status);
    void parsing(int ac, char **av);
};