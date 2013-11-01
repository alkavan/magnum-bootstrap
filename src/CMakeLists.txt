find_package(Magnum REQUIRED
    SceneGraph
    MeshTools
    Primitives
    Shaders
    Shapes
    Sdl2Application)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CORRADE_CXX_FLAGS}")

set(DNMIX "${CMAKE_SOURCE_DIR}/src/Dnmix") 
include_directories(${MAGNUM_INCLUDE_DIRS} ${MAGNUM_APPLICATION_INCLUDE_DIRS} ${DNMIX})

add_subdirectory (Dnmix)
add_executable(MyApplication MyApplication.cpp)

target_link_libraries(MyApplication Dnmix
    ${MAGNUM_LIBRARIES}
    ${MAGNUM_SCENEGRAPH_LIBRARIES}
    ${MAGNUM_MESHTOOLS_LIBRARIES}
    ${MAGNUM_PRIMITIVES_LIBRARIES}
    ${MAGNUM_SHADERS_LIBRARIES}
    ${MAGNUM_SHAPES_LIBRARIES}
    ${MAGNUM_APPLICATION_LIBRARIES})
