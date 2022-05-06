#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

class Generate
{
public:
  Generate(std::string_view port, std::string_view project_name);
  ~Generate() = default;

  void core();
  void create();
  void writeFile();
  void launch();

private:
  std::string _port;
  std::string _projname;
};