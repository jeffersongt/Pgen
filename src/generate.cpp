#include "generate.hpp"

Generate::Generate(std::string_view port, std::string_view project_name)
{
  _port = port;
  _projname = project_name;
  core();
}

void Generate::core()
{
  create();
  writeFile();
  launch();
}

void Generate::create()
{
  std::string dir = "mkdir " + _projname;
  const char *_dir = dir.c_str();
  system(_dir);

  std::string file = "cd " + _projname + "; touch docker-compose.yml";
  const char *_file = file.c_str();
  system(_file);

  return;
}

void Generate::writeFile()
{
  std::string header = "version: '3'\n\nservices:\n";
  std::string service1 = "  db:\n    image: postgres:alpine\n    restart: always\n    environment:\n      - POSTGRES_USER=root\n      - POSTGRES_PASSWORD=dbpass\n      - POSTGRES_DB=" + _projname + "\n    volumes:\n      - db-data-" + _projname + ":/var/lib/postgresql/data-" + _projname + "\n    ports:\n      - " + _port + ":5432\n";
  std::string volumes = "\nvolumes:\n  db-data-" + _projname + ":\n";

  std::ofstream docker(_projname + "/docker-compose.yml");
  docker << header << service1 << volumes;

  return;
}

void Generate::launch()
{
  std::string init = "cd " + _projname + "; docker-compose up";
  const char *_init = init.c_str();
  system(_init);

  return;
}