project(unfairGameName)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        scenes/UnfairScene.cpp
        scenes/UnfairScene.h
        scenes/StartScene.cpp
        scenes/StartScene.h
        sprite/sprite_data.h
        src/Killable.h
        src/Killable.cpp
        src/Renderable.cpp
        src/Renderable.h
        src/Gerard.cpp
        src/Gerard.h
        )

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
