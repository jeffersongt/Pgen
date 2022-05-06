#include "generate.hpp"

Generate::Generate(std::string_view port, std::string_view project_name)  {
  _port = port;
  _projname = project_name;
  core();
}

void Generate::core() {
  create();
  writeFile();
}

void Generate::create() {
  std::string dir = "mkdir " + _projname;
  const char* _dir = dir.c_str();
  system(_dir);

  std::string file = "cd " + _projname + "; touch docker-compose.yml";
  const char* _file = file.c_str();
  system(_file);

  return;
}

void Generate::writeFile() {
  std::ofstream docker(_projname + "/docker-compose.yml");
  docker << "test";

  return;
}