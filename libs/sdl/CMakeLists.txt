
if(WIN32)
    set(SDL3_PATH ${HDLLS_INCLUDE}/sdl)
    set(SDL3_INCLUDE_DIR ${SDL3_PATH}/include)

    set(SDL3_DIR ${SDL3_PATH}/cmake)

    find_package(SDL3 REQUIRED)

else()
    find_package(SDL3 REQUIRED)
endif()



add_library(sdl.hdll SHARED
    sdl.c
    gl.c
)
set_as_hdll(sdl)

target_include_directories(sdl.hdll
    PRIVATE
    ${SDL3_INCLUDE_DIR}
    ${INCLUDES_BASE_DIR}/gl
    ${INCLUDES_BASE_DIR}
)

if(WIN32)
    target_link_libraries(sdl.hdll
        libhl
        SDL3::SDL3
        winmm
        opengl32
    )
elseif(ANDROID)
    target_link_libraries(sdl.hdll
        libhl
        SDL3::SDL3
        GLESv3
    )
else()
    target_link_libraries(sdl.hdll libhl SDL3::SDL3)
    hdll_copy_dependency(sdl SDL3)

    find_package(OpenGL REQUIRED)
    target_include_directories(sdl.hdll PRIVATE ${OPENGL_INCLUDE_DIR})
    hdll_copy_dependency(sdl GL)
endif()

if(WIN32)
set(SDL3_LIBRARY_DLL ${SDL3_PATH}/lib/x64/SDL3.dll)
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
