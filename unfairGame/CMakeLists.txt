project(unfairGameName)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        scenes/UnfairScene.cpp
        scenes/UnfairScene.h
        sprite/sprite_data.h
        src/Fireball.cpp
        src/Walkable.cpp
        )

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
