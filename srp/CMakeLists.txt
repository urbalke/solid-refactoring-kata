cmake_minimum_required(VERSION 3.12)
project(srp)

set(CMAKE_CXX_STANDARD 14)

add_library(srp UserManager.cpp UserManager.h DbService.cpp DbService.h User.cpp User.h SmtpClient.cpp SmtpClient.h)