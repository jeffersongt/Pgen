# Pgen

- Pgen permits you to automatically create a dockerized postgresql database

## :warning: Requirement

- [CMake >= 3.17](https://cmake.org/download/)
- [C++17](https://en.cppreference.com/w/cpp/17)
- [Docker](https://www.docker.com)

## :computer: Usage

### :rocket: Clone repository

```sh
git clone https://github.com/jeffersongt/pg-gen
```

### :hammer: Build and Install project

The following command will build the project install `pgen` on your system:

```sh
./install.py
```

### :wrench: Helper

If you need some help:

```sh
pgen help
```

## :hammer: Usage

```sh
pgen [PORT] [PROJECT-NAME]
```

- PORT is the port on which you will listen to your database
- PROJECT-NAME is you project name, it permits to name the volumes and the db name

- When you'll execute the program, a docker will be launched. If you don't want to keep this terminal running constantly just kill the process and re-launch manually the docker !
