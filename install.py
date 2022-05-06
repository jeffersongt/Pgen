#!/usr/bin/env python3

import sys
import os
import platform

if os.system('cmake . -B build') != 0:
  print("Failed to generate build file, please make sure that CMake is installed", file=sys.stderr)
  exit(1)

if os.system('cmake --build build') != 0:
  print("Build failed", file=sys.stderr)
  exit(1)

actual_os = platform.system()

if actual_os == "Darwin":
  tool = "sudo cp"
  bin = "pgen"
  install_path = "/usr/local/bin"
elif actual_os == "Linux":
  tool = "cp"
  bin = "pgen"
  usr = os.getenv("USERNAME")
  if usr == None:
    install_path = "/usr/local/bin"
  else:
    install_path = "/home/" + usr + "/.local/bin"
elif actual_os == "Windows":
  tool = "copy"
  bin = "Debug/pgen.exe"
  install_path = "$env:UserProfile/AppData/Local/Microsoft/WindowsApps"
else:
  print("Unknown system, you will need to install pgen manually", file=sys.stderr)
  exit(1)

if os.system(tool + " " + bin + " " + install_path) != 0:
  print("Failed to install pgen at \"" + install_path + "\"", file=sys.stderr)
  exit(1)

print("pgen has been installed at \"" + install_path + "\"")