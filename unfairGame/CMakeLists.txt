project(unfairGameName)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        scenes/UnfairScene.cpp
        scenes/UnfairScene.h
        scenes/StartScene.cpp
        scenes/StartScene.h
        scenes/BossScene.cpp
        scenes/BossScene.h
        sprite/sprite_data/sprite_data.h
        src/killable/Killable.h
        src/killable/Killable.cpp
        src/Renderable.cpp
        src/Renderable.h
        src/Gerard.cpp
        src/Gerard.h
        src/Data.cpp
        src/Data.h
        src/Scientist.cpp
        src/Scientist.h
        src/killable/FireBall.cpp
        src/killable/FireBall.h
        src/killable/Testtube.cpp
        src/killable/Testtube.h
        )

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
