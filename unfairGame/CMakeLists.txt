project(unfairGameName)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        scenes/UnfairScene.cpp
        scenes/UnfairScene.h
        scenes/StartScene.cpp
        scenes/StartScene.h
        scenes/BossScene.cpp
        scenes/BossScene.h
        scenes/GenericScene.cpp
        scenes/GenericScene.h
        scenes/EndScene.cpp
        scenes/EndScene.h
        src/killable/Killable.h
        src/killable/Killable.cpp
        src/renderable/Renderable.cpp
        src/renderable/Renderable.h
        src/renderable/Gerard.cpp
        src/renderable/Gerard.h
        src/renderable/Healthbar.cpp
        src/renderable/Healthbar.h
        src/renderable/ImaginaryBlock.cpp
        src/renderable/ImaginaryBlock.h
        src/renderable/Flag.cpp
        src/renderable/Flag.h
        src/Data.cpp
        src/Data.h
        src/renderable/Scientist.cpp
        src/renderable/Scientist.h
        src/killable/FireBall.cpp
        src/killable/FireBall.h
        src/killable/Testtube.cpp
        src/killable/Testtube.h
        src/killable/Mine.cpp
        src/killable/Mine.h
        src/killable/Plant.cpp
        src/killable/Plant.h
        src/sound/Explosion1.h src/sound/Laugh1.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
