project(stupidCompiler_exe)

find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

add_executable(tscp main.cpp)
target_link_libraries(tscp PRIVATE 
                        fmt::fmt
                        CLI11::CLI11)