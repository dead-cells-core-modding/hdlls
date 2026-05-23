
    if(MSVC)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
    endif()

    if(WIN32)
    find_library(OpenAL_LIBRARY OpenAL32 PATHS ${HDLLS_INCLUDE}/openal/libs/Win64)
    set(OpenAL_LIBRARY_DLL ${HDLLS_INCLUDE}/openal/bin/Win64/soft_oal.dll)
    else()
    find_library(OpenAL_LIBRARY openal)
    set(OpenAL_LIBRARY_DLL ${OpenAL_LIBRARY})
    endif()

    add_library(openal.hdll SHARED openal.c)

    set_as_hdll(openal)

    target_include_directories(openal.hdll
        PRIVATE
        ${HDLLS_INCLUDE}/openal/include
    )

    target_link_libraries(openal.hdll
        libhl
        ${OpenAL_LIBRARY}
    )

    if(WIN32)
    add_custom_command(
    TARGET openal.hdll POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${OpenAL_LIBRARY_DLL}
            ${OUTPUT_DIR}/OpenAL32.dll
    )
    endif()

    install(
        TARGETS
            openal.hdll
        DESTINATION ${HDLL_DESTINATION}
    )
