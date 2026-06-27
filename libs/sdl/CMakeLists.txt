
if(WIN32)
    set(SDL2_PATH ${HDLLS_INCLUDE}/sdl)
    set(SDL2_INCLUDE_DIR ${SDL2_PATH}/include)

    find_library(SDL2_LIBRARY SDL2 PATHS ${SDL2_PATH}/lib/x64)
endif()

find_package(SDL2 REQUIRED)

add_library(sdl.hdll SHARED
    sdl.c
    gl.c
)
set_as_hdll(sdl)

message("SDL include: ${SDL2_INCLUDE_DIR}")

target_include_directories(sdl.hdll
    PRIVATE
    ${SDL2_INCLUDE_DIR}
    ${INCLUDES_BASE_DIR}/gl
    ${INCLUDES_BASE_DIR}
)

if(WIN32)
    target_link_libraries(sdl.hdll
        libhl
        ${SDL2_LIBRARY}
        winmm
        opengl32
    )
elseif(ANDROID)
    target_link_libraries(sdl.hdll
        libhl
        ${SDL2_LIBRARY}
        GLESv3
    )
else()
    target_link_libraries(sdl.hdll libhl)
    hdll_copy_dependency(sdl SDL2)

    find_package(OpenGL REQUIRED)
    target_include_directories(sdl.hdll PRIVATE ${OPENGL_INCLUDE_DIR})
    hdll_copy_dependency(sdl GL)
endif()

if(WIN32)
set(SDL2_LIBRARY_DLL ${SDL2_PATH}/lib/x64/SDL2.dll)
set(SDL3_LIBRARY_DLL ${SDL2_PATH}/lib/x64/SDL3.dll)
add_custom_command(
    TARGET sdl.hdll POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL2_LIBRARY_DLL}
            ${OUTPUT_DIR}/SDL2.dll
)
add_custom_command(
    TARGET sdl.hdll POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL3_LIBRARY_DLL}
            ${OUTPUT_DIR}/SDL3.dll
)
endif()


install(
    TARGETS sdl.hdll
    DESTINATION ${HDLL_DESTINATION}
)
