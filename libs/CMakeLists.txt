
get_filename_component(INCLUDES_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include" ABSOLUTE)

function(set_as_hdll target)
    set_target_properties(${target}.hdll
        PROPERTIES
        PREFIX ""
        OUTPUT_NAME ${target}
        SUFFIX .hdll
        RUNTIME_OUTPUT_DIRECTORY ${DCCM_OUTPUT_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${DCCM_OUTPUT_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${DCCM_OUTPUT_DIR}
    )
endfunction()

# hdll_copy_dependency(target lib_identifier)
#
# On Linux, resolves a system shared library and copies it alongside the .hdll
# output so it can be found at runtime.  Also sets RPATH to $ORIGIN and uses
# --no-as-needed to ensure the dependency stays in DT_NEEDED even when the
# linker is configured with --as-needed.
#
# Usage:
#   hdll_copy_dependency(uv uv)          # copies libuv.so → DCCM_OUTPUT_DIR
#   hdll_copy_dependency(sdl SDL2::SDL2) # copies libSDL2.so → DCCM_OUTPUT_DIR
function(hdll_copy_dependency target lib_identifier)
    if(NOT UNIX)
        return()
    endif()

    # Resolve the library to an absolute .so path
    find_library(DEP_LIB_PATH ${lib_identifier})
    if(NOT DEP_LIB_PATH)
        message(WARNING "hdll_copy_dependency: could not find ${lib_identifier}")
        return()
    endif()

    get_filename_component(DEP_LIB_NAME ${DEP_LIB_PATH} NAME)

    # Copy the shared library beside the .hdll after build
    add_custom_command(TARGET ${target}.hdll POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DEP_LIB_PATH}
            "${DCCM_OUTPUT_DIR}/${DEP_LIB_NAME}"
        COMMENT "Copying ${DEP_LIB_NAME} → ${DCCM_OUTPUT_DIR}"
    )

    # Ensure the dependency stays in DT_NEEDED despite --as-needed
    target_link_options(${target}.hdll PRIVATE
        LINKER:--no-as-needed
    )
    target_link_libraries(${target}.hdll
        ${DEP_LIB_PATH}
    )
    target_link_options(${target}.hdll PRIVATE
        LINKER:--as-needed
    )

    # RPATH: search the .hdll's own directory first
    set_target_properties(${target}.hdll PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        BUILD_RPATH "$ORIGIN"
        INSTALL_RPATH_USE_LINK_PATH TRUE
    )
endfunction()

# Same as hdll_copy_dependency but takes an explicit library file path
# instead of searching via find_library.
function(hdll_copy_dependency_path target lib_path)
    if(NOT UNIX OR NOT lib_path)
        return()
    endif()

    get_filename_component(DEP_LIB_NAME ${lib_path} NAME)

    add_custom_command(TARGET ${target}.hdll POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${lib_path}
            "${DCCM_OUTPUT_DIR}/${DEP_LIB_NAME}"
        COMMENT "Copying ${DEP_LIB_NAME} → ${DCCM_OUTPUT_DIR}"
    )

    target_link_options(${target}.hdll PRIVATE
        LINKER:--no-as-needed
    )
    target_link_libraries(${target}.hdll
        ${lib_path}
    )
    target_link_options(${target}.hdll PRIVATE
        LINKER:--as-needed
    )

    set_target_properties(${target}.hdll PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        BUILD_RPATH "$ORIGIN"
        INSTALL_RPATH_USE_LINK_PATH TRUE
    )
endfunction()

#add_subdirectory(directx)
add_subdirectory(fmt)
add_subdirectory(openal)
add_subdirectory(sdl)
add_subdirectory(sqlite)
add_subdirectory(ssl)
add_subdirectory(ui)
add_subdirectory(uv)
add_subdirectory(hlsteam)
add_subdirectory(hlgog)


if(WIN32)
add_subdirectory(hlchroma)
add_subdirectory(hldiscord)
endif()
