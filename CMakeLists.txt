cmake_minimum_required(VERSION 3.2)

set(PR_NAME BDSM-Client)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(${PR_NAME})

file(GLOB_RECURSE SOURCE src/*.cpp)
file(GLOB_RECURSE INCLUDE include/*.h)

add_executable(${PR_NAME} ${INCLUDE} ${SOURCE})
target_include_directories(${PR_NAME} PUBLIC ${INCLUDE})

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PR_NAME}
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(${PR_NAME} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

# this is heuristically generated, and may not be correct
find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PR_NAME} PRIVATE imgui::imgui)

# this is heuristically generated, and may not be correct
find_package(gRPC CONFIG REQUIRED)
# note: 7 additional targets are not displayed.
target_link_libraries(${PR_NAME} PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(${PR_NAME} PRIVATE unofficial::sqlite3::sqlite3)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(${PR_NAME} PRIVATE nlohmann_json::nlohmann_json)