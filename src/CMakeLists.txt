set(LIB ${PROJECT_NAME}-lib)
set(EXE ${PROJECT_NAME}-exe)

add_library(${LIB} STATIC shortest_path.cpp)

target_compile_options(${LIB} PRIVATE
    -Werror
    -pedantic-errors
    -Wall
    -Wextra
    -Wpedantic
    -Wcast-align
    -Wcast-qual
    -Wctor-dtor-privacy
    -Wduplicated-branches
    -Wduplicated-cond
    -Wextra-semi
    -Wfloat-equal
    -Wlogical-op
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-promo
)

add_executable(${EXE} main.cpp)
target_link_libraries(${EXE} PRIVATE ${LIB})
