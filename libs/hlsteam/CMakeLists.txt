 
    if(DCCM_ARCH_ARM64)
        # ARM64 stub — no Steam SDK available
        set(SOURCES ./native/stub_arm64.cpp)

        add_library(steam.hdll SHARED ${SOURCES})

        set_as_hdll(steam)

        target_include_directories(steam.hdll
            PRIVATE
            ./native
        )

        target_link_libraries(steam.hdll
            libhl
        )
    else()
        if(MSVC)
            set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
        endif()
 
        file(GLOB SOURCES ./native/*.cpp)

        get_filename_component(STEAMSDK_ROOT "../../include/Steamworks-SDK" ABSOLUTE)

        if(WIN32)
        find_library(Steam_LIBRARY steam_api64 PATHS ${STEAMSDK_ROOT}/redistributable_bin/win64)
        set(STEAM_DLL
            "${STEAMSDK_ROOT}/redistributable_bin/win64/steam_api64.dll"
        )
        else()
        find_library(Steam_LIBRARY steam_api PATHS ${STEAMSDK_ROOT}/redistributable_bin/linux64)
        set(STEAM_DLL
            "${STEAMSDK_ROOT}/redistributable_bin/linux64/libsteam_api.so"
        )
        endif()

        add_library(steam.hdll SHARED ${SOURCES})

        set_as_hdll(steam)

        target_include_directories(steam.hdll
            PRIVATE
            ${STEAMSDK_ROOT}/public
            PRIVATE 
            ./native
        )

        target_link_libraries(steam.hdll
            libhl
            ${Steam_LIBRARY}
        )
    
        add_custom_command(
                    TARGET steam.hdll POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        ${STEAM_DLL}
                        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
        )
    endif()
