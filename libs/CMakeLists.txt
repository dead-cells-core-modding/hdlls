
get_filename_component(INCLUDES_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include" ABSOLUTE)

function(set_as_hdll target)
    set_target_properties(${target}.hdll
        PROPERTIES
        PREFIX ""
        OUTPUT_NAME ${target}
        NO_SONAME TRUE
        IMPORTED_NO_SONAME TRUE
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
    unset(DEP_LIB_PATH CACHE)
    unset(DEP_LIB_NAME)
    unset(DEP_LIB_NAME CACHE)
    find_library(DEP_LIB_PATH ${lib_identifier})
    if(NOT DEP_LIB_PATH)
        message(WARNING "hdll_copy_dependency: could not find ${lib_identifier}")
        return()
    endif()

    # Extract SONAME from the ELF (e.g. libuv.so.1); fall back to the filename
    execute_process(
        COMMAND objdump -p ${DEP_LIB_PATH}
        OUTPUT_VARIABLE _OBJDUMP_OUT
        ERROR_QUIET
    )
    if(_OBJDUMP_OUT MATCHES "SONAME +([^\n]+)")
        string(STRIP "${CMAKE_MATCH_1}" DEP_LIB_NAME)
    else()
        get_filename_component(DEP_LIB_NAME ${DEP_LIB_PATH} NAME)
    endif()

    message(STATUS "hdll_copy_dependency(${target}): ${lib_identifier} ${DEP_LIB_NAME} → ${DCCM_OUTPUT_DIR}")

    # Copy the shared library beside the .hdll after build, using the soname
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
add_subdirectory(hlchroma)
add_subdirectory(hldiscord)
