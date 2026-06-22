
    if(MSVC)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
    endif()
 
    file(GLOB SOURCES ./src/dummy.c)

    add_library(gog.hdll SHARED ${SOURCES})

    set_as_hdll(gog)

 #   target_include_directories(hlgog.hdll
 #      PRIVATE
 #       ${STEAMSDK_ROOT}/public
 #      PRIVATE 
 #      ./native
 #  )

    target_link_libraries(gog.hdll
        libhl
    )
    
#    add_custom_command(
#                TARGET hlgog.hdll POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy_if_different
#                    ${STEAM_DLL}
#                    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
#    )

