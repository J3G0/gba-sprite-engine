#ifndef GBA_SPRITE_ENGINE_PROJECT_SPRITE_DATA_H
#define GBA_SPRITE_ENGINE_PROJECT_SPRITE_DATA_H

const unsigned short sharedPal[14] __attribute__((aligned(4)))=
{
        0x0000,0x5B9F,0x0972,0x4100,0x0013,0x0842,0x7FFF,0x2108,
        0x001F,0x0BDD,0x025F,0x73E6,0x7FFF,0x4A52,
};

const unsigned int FireballTiles[16] __attribute__((aligned(4)))=
{
        0x090A0808,0x00000A0A,0x090A0008,0x0008080A,0x090A0A08,0x0008000A,0x090A0800,0x00080A09,
        0x090A0800,0x0000080A,0x090A0800,0x00080A09,0x0A0A0A08,0x00080A0A,0x08080800,0x00000808,
};

const unsigned int Walking_Gerard_RightTiles[1408] __attribute__((aligned(4)))=
{
        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00050502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06050405,0x00000000,0x06050405,
        0x00000000,0x05050405,0x00000000,0x01050405,0x00000000,0x05050405,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,
        0x00050405,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030305,0x00000000,0x03030500,0x00000000,0x03030500,0x00000000,0x03030500,
        0x00000000,0x03030500,0x00000000,0x05050500,0x00000000,0x07070500,0x00000000,0x05050500,
        0x00050303,0x00000000,0x00000503,0x00000000,0x00000005,0x00000000,0x00000005,0x00000000,
        0x00000005,0x00000000,0x00050505,0x00000000,0x00050707,0x00000000,0x00050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x05020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00000502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06050405,0x00000000,0x06050405,
        0x00000000,0x05040405,0x00000000,0x05040405,0x00000000,0x05040405,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050506,0x00000000,
        0x00050505,0x00000000,0x00050501,0x00000000,0x00050505,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030305,0x00000000,0x03030305,0x00000000,0x05030305,0x00000000,0x05030305,
        0x00000000,0x05030305,0x00000000,0x05050505,0x00000000,0x07070705,0x00000000,0x05050505,
        0x00050503,0x00000000,0x00050305,0x00000000,0x00050303,0x00000000,0x00000503,0x00000000,
        0x05050503,0x00000000,0x05070505,0x00000000,0x05050507,0x00000000,0x00000505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x05020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00000502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06050405,0x00000000,0x05040405,
        0x00000000,0x04040405,0x00000000,0x04040405,0x00000000,0x04040405,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050506,0x00000000,0x05050606,0x00000000,
        0x01050605,0x00000005,0x05050504,0x00000000,0x00050404,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030305,0x00000000,0x03030305,0x00000000,0x05030305,0x00000000,0x05030305,
        0x00000000,0x05030305,0x00000000,0x05050505,0x00000000,0x07070705,0x00000000,0x05050505,
        0x00050503,0x00000000,0x00050305,0x00000000,0x05030305,0x00000000,0x05030303,0x00000000,
        0x00050303,0x00000000,0x05050505,0x00000000,0x05070507,0x00000000,0x05050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x05020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00000502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06050405,0x00000000,0x06050405,
        0x00000000,0x05040405,0x00000000,0x05040405,0x00000000,0x05040405,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050506,0x00000000,
        0x00050505,0x00000000,0x00050501,0x00000000,0x00050505,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030305,0x00000000,0x03030305,0x00000000,0x05030305,0x00000000,0x05030305,
        0x00000000,0x05050505,0x00000000,0x07070705,0x00000000,0x05050505,0x00000000,0x05050000,
        0x00050503,0x00000000,0x00050305,0x00000000,0x00050303,0x00000000,0x00000503,0x00000000,
        0x00000505,0x00000000,0x05050507,0x00000000,0x05070505,0x00000000,0x05050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00050502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06050405,0x00000000,0x06050405,
        0x00000000,0x05050405,0x00000000,0x01050405,0x00000000,0x05050405,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,
        0x00050405,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030305,0x00000000,0x03030500,0x00000000,0x03030500,0x00000000,0x03030500,
        0x00000000,0x03030500,0x00000000,0x05050500,0x00000000,0x07070500,0x00000000,0x05050500,
        0x00050303,0x00000000,0x00000503,0x00000000,0x00000005,0x00000000,0x00000005,0x00000000,
        0x00000005,0x00000000,0x00050505,0x00000000,0x00050707,0x00000000,0x00050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00050502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06060505,0x00000000,0x05060505,
        0x00000000,0x05050505,0x00000000,0x05010505,0x00000000,0x05050505,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050404,0x00000000,
        0x05050404,0x00000000,0x00050404,0x00000000,0x00050404,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030500,0x00000000,0x03050500,0x00000000,0x05030305,0x05000000,0x03030303,
        0x05000000,0x05030303,0x05000000,0x05050505,0x05000000,0x05070707,0x05000000,0x05050505,
        0x00050303,0x00000000,0x05030303,0x00000000,0x03030303,0x00000005,0x05030305,0x00000000,
        0x05050505,0x00000005,0x07070707,0x00000005,0x05050505,0x00000005,0x00000005,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00050502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06050405,0x00000000,0x05060505,
        0x00000000,0x04050505,0x00000000,0x04050105,0x00000000,0x04050505,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x05050404,0x00000000,
        0x01050404,0x00000005,0x05050404,0x00000000,0x00050404,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030305,0x00000000,0x03030500,0x00000000,0x03050305,0x05000000,0x03050303,
        0x03050000,0x03050503,0x05050500,0x05050505,0x07070500,0x07050707,0x05050500,0x05050505,
        0x00050303,0x00000000,0x00000503,0x00000000,0x00000503,0x00000000,0x00050303,0x00000000,
        0x00000503,0x00000000,0x05050505,0x00000000,0x05070707,0x00000000,0x05050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x05020205,0x02020202,0x02050205,0x02020202,0x02020205,0x02020202,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020205,0x00050202,0x02020502,0x00050205,0x02050105,0x00050502,0x05010105,0x00000505,
        0x02020205,0x05050202,0x02020205,0x01010502,0x05020205,0x01010105,0x01050505,0x01010101,
        0x01010500,0x01010101,0x01050000,0x01010101,0x05000000,0x05050505,0x00000000,0x06060605,
        0x01050501,0x00000501,0x01050501,0x00000501,0x01010101,0x00000505,0x01050101,0x00000501,
        0x05010101,0x00000505,0x01010101,0x00000005,0x05050505,0x00000000,0x00050606,0x00000000,

        0x00000000,0x05050505,0x00000000,0x06050405,0x00000000,0x06060505,0x00000000,0x05060505,
        0x00000000,0x05050505,0x00000000,0x05010505,0x00000000,0x05050505,0x00000000,0x05050505,
        0x00050505,0x00000000,0x00050405,0x00000000,0x00050405,0x00000000,0x00050404,0x00000000,
        0x05050404,0x00000000,0x00050404,0x00000000,0x00050404,0x00000000,0x00050505,0x00000000,
        0x00000000,0x03030500,0x00000000,0x03050500,0x00000000,0x05030305,0x05000000,0x03030303,
        0x05000000,0x05050505,0x05000000,0x05050707,0x05000000,0x07050505,0x00000000,0x05050000,
        0x00050303,0x00000000,0x05030303,0x00000000,0x03030303,0x00000005,0x05030305,0x00000000,
        0x00050303,0x00000000,0x05050505,0x00000000,0x05070707,0x00000000,0x05050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x02050205,0x05020202,0x05010505,0x02020205,0x01010500,0x02050501,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020202,0x00050202,0x02020502,0x00050202,0x02050105,0x00050202,0x05010105,0x00000502,
        0x01010500,0x05010505,0x01010500,0x01010505,0x01010500,0x05010101,0x01010500,0x01010105,
        0x01010500,0x05050501,0x01050000,0x01010101,0x05000000,0x01010105,0x04050000,0x06060504,
        0x01050501,0x00000505,0x01050501,0x00000501,0x01010101,0x00000501,0x01050101,0x00000501,
        0x01010505,0x00000501,0x01010101,0x00000005,0x05050101,0x00000000,0x04040506,0x00000005,

        0x05060500,0x06050404,0x05060500,0x05040404,0x05060500,0x05040404,0x05060500,0x04040404,
        0x05050500,0x04040404,0x05010500,0x04040404,0x05050500,0x04040404,0x05000000,0x05050505,
        0x05040405,0x00000506,0x05040404,0x00000506,0x05040504,0x00000506,0x05040404,0x00000506,
        0x05040404,0x00000505,0x05040404,0x00000501,0x05040404,0x00000505,0x05050505,0x00000000,
        0x05000000,0x03030303,0x05000000,0x05030303,0x05000000,0x00050303,0x05000000,0x00050303,
        0x05000000,0x00050303,0x05000000,0x00050505,0x05000000,0x00050707,0x05000000,0x00050505,
        0x05030303,0x00000000,0x05030303,0x00000000,0x05030305,0x00000000,0x05030305,0x00000000,
        0x05030305,0x00000000,0x05050505,0x00000000,0x05070705,0x00000000,0x05050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x02050205,0x05020202,0x05010505,0x02020205,0x01010500,0x02050501,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020202,0x00050202,0x02020502,0x00050202,0x02050105,0x00050202,0x05010105,0x00000502,
        0x01010500,0x05010505,0x01010500,0x01010505,0x01010500,0x05010101,0x01010500,0x01010105,
        0x01010500,0x05050501,0x01050000,0x01010101,0x05000000,0x01010105,0x04050000,0x06060504,
        0x05050501,0x00000505,0x05050501,0x00000501,0x05010101,0x00000505,0x05050101,0x00000506,
        0x05010505,0x00000506,0x05010101,0x00000506,0x05050101,0x00000506,0x04040506,0x00000005,

        0x05060500,0x06050404,0x05060500,0x05040404,0x05060500,0x05040404,0x05050500,0x04040404,
        0x05010500,0x04040404,0x05050500,0x04040404,0x05000000,0x04040404,0x05000000,0x05050505,
        0x05040405,0x00000000,0x05040404,0x00000000,0x05040504,0x00000000,0x05040404,0x00000000,
        0x05040404,0x00000000,0x05040404,0x00000000,0x05040404,0x00000000,0x05050505,0x00000000,
        0x05000000,0x03030303,0x05000000,0x05030303,0x05000000,0x00050303,0x05000000,0x00050303,
        0x05000000,0x00050303,0x05000000,0x00050505,0x05000000,0x00050707,0x05000000,0x00050505,
        0x05030303,0x00000000,0x05030303,0x00000000,0x05030305,0x00000000,0x05030305,0x00000000,
        0x05030305,0x00000000,0x05050505,0x00000000,0x05070705,0x00000000,0x05050505,0x00000000,

        0x05000000,0x05050505,0x02050000,0x02020202,0x02020500,0x02020202,0x02020205,0x02020202,
        0x02020205,0x02020202,0x02050205,0x05020202,0x05060505,0x02020505,0x06060500,0x02050606,
        0x05050505,0x00000000,0x02020202,0x00000005,0x02020202,0x00000502,0x02020202,0x00050202,
        0x02020202,0x00050202,0x02020502,0x00050202,0x05050605,0x00050202,0x06060605,0x00000505,
        0x05060500,0x05060506,0x06060500,0x06060605,0x05060500,0x05060506,0x06060500,0x06060606,
        0x06060500,0x05050606,0x06050000,0x06060606,0x05000000,0x06060605,0x04050000,0x06060504,
        0x05060506,0x00000506,0x06050606,0x00000506,0x05060506,0x00000506,0x06060606,0x00000506,
        0x06060605,0x00000506,0x06060606,0x00000005,0x05050606,0x00000000,0x04040506,0x00000005,

        0x05060500,0x06050404,0x05060500,0x05040404,0x05060500,0x05040404,0x05060500,0x04040404,
        0x05050500,0x04040404,0x05060500,0x04040404,0x05050500,0x04040404,0x05000000,0x05050505,
        0x05040405,0x00000506,0x05040404,0x00000506,0x05040504,0x00000506,0x05040404,0x00000506,
        0x05040404,0x00000505,0x05040404,0x00000506,0x05040404,0x00000505,0x05050505,0x00000000,
        0x05000000,0x03030303,0x05000000,0x05030303,0x05000000,0x00050303,0x05000000,0x00050303,
        0x05000000,0x00050303,0x05000000,0x00050505,0x05000000,0x00050707,0x05000000,0x00050505,
        0x05030303,0x00000000,0x05030303,0x00000000,0x05030305,0x00000000,0x05030305,0x00000000,
        0x05030305,0x00000000,0x05050505,0x00000000,0x05070705,0x00000000,0x05050505,0x00000000,
};
const unsigned int Mad_Saaientist_WalkingTiles[1024] __attribute__((aligned(4)))=
        {
                0x00000000,0x00000000,0x00000000,0x00000000,0x07070700,0x00070707,0x00000700,0x00070000,
                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000070B,0x07070000,0x0000070B,
                0x00000000,0x00000000,0x07000000,0x000D0D00,0x07000000,0x0D0D0007,0x01010000,0x01010101,
                0x01010000,0x01010000,0x00000000,0x00000303,0x00010000,0x01000303,0x01010100,0x01010000,
                0x00000000,0x00000000,0x0D000707,0x0000000D,0x00070700,0x0000000D,0x01010101,0x0000000D,
                0x01000001,0x0000000D,0x00030300,0x00000000,0x00030300,0x0000000D,0x01000001,0x00000101,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000000B,0x07070100,0x00000107,
                0x01010000,0x00000001,0x00000000,0x00000000,0x0C000000,0x0C0C0C0C,0x00000000,0x0C0C0C00,
                0x01010000,0x00010101,0x01010000,0x01010101,0x00000000,0x00000101,0x00000000,0x01010100,
                0x00000000,0x01010100,0x000C0C00,0x01010202,0x0C000C0C,0x02020200,0x0C000C0C,0x0202000C,
                0x01010101,0x00000001,0x01010001,0x00000001,0x00010100,0x00000000,0x00000101,0x00000000,
                0x00000101,0x00000000,0x00020201,0x00000C0C,0x0C000202,0x0C0C0C00,0x0C0C0002,0x0C0C0C00,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x000C0C00,0x02000C00,0x0C0C0000,0x000C0C0C,0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,
                0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,0x0C040000,0x0C0C0C0C,0x04040000,0x0C000C0C,
                0x00000C00,0x0C0C0C0C,0x0C0C0C00,0x0C0C000C,0x0C0C0C00,0x0C0C0007,0x0C0C0C00,0x0C0C0007,
                0x0C0C0C00,0x0C0C0007,0x040C0C00,0x0C0C0007,0x0C0C0C00,0x00000007,0x0C0C0C00,0x01010007,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x04040000,0x0C0C0C04,0x00000000,0x00000000,0x0C000000,0x00000007,0x0C000000,0x00000007,
                0x00000000,0x00000000,0x0C0C0000,0x00000007,0x070C0000,0x00000007,0x00000000,0x00000000,
                0x0C0C0C00,0x00010007,0x00000000,0x00000000,0x070C0000,0x00000000,0x070C0000,0x00000000,
                0x00000000,0x00000000,0x070C0C00,0x00000000,0x07070C00,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x07070700,0x00070707,0x00000700,0x00070000,
                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000070B,0x07070000,0x0000070B,
                0x00000000,0x00000000,0x07000000,0x000D0D00,0x07000000,0x0D0D0007,0x01010000,0x01010101,
                0x01010000,0x01010000,0x00000000,0x00000303,0x00010000,0x01000303,0x01010100,0x01010000,
                0x00000000,0x00000000,0x0D000707,0x0000000D,0x00070700,0x0000000D,0x01010101,0x0000000D,
                0x01000001,0x0000000D,0x00030300,0x00000000,0x00030300,0x0000000D,0x01000001,0x00000101,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000000B,0x07070100,0x00000107,
                0x01010000,0x00000001,0x00000000,0x00000000,0x0C000000,0x0C0C0C0C,0x00000000,0x0C0C0C00,
                0x01010000,0x00010101,0x01010000,0x01010101,0x00000000,0x00000101,0x00000000,0x01010100,
                0x00000000,0x01010100,0x000C0C00,0x01010202,0x0C000C0C,0x02020200,0x0C000C0C,0x0202000C,
                0x01010101,0x00000001,0x01010001,0x00000001,0x00010100,0x00000000,0x00000101,0x00000000,
                0x00000101,0x00000000,0x00020201,0x00000C0C,0x0C000202,0x0C0C0C00,0x0C0C0002,0x0C0C0C00,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x000C0C00,0x02000C00,0x0C0C0000,0x000C0C0C,0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,
                0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,0x0C040000,0x0C0C0C0C,0x04040000,0x0C000C0C,
                0x00000C00,0x0C0C0C0C,0x0C0C0C00,0x0C0C000C,0x0C0C0C00,0x0C0C0007,0x0C0C0C00,0x0C0C0007,
                0x0C0C0C00,0x0C0C0007,0x040C0C00,0x0C0C0007,0x0C0C0C00,0x00000007,0x0C0C0C00,0x01010007,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x04040000,0x0C0C0C04,0x00000000,0x00000000,0x0C000000,0x00000007,0x00000000,0x00000000,
                0x0C0C0000,0x00000007,0x070C0000,0x00000007,0x00000000,0x00000000,0x00000000,0x00000000,
                0x0C0C0C00,0x00010007,0x00000000,0x00000000,0x070C0000,0x00000000,0x070C0000,0x00000000,
                0x00000000,0x00000000,0x070C0C00,0x00000000,0x07070C00,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x07070700,0x00070707,0x00000700,0x00070000,
                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000070B,0x07070000,0x0000070B,
                0x00000000,0x00000000,0x07000000,0x000D0D00,0x07000000,0x0D0D0007,0x01010000,0x01010101,
                0x01010000,0x01010000,0x00000000,0x00000303,0x00010000,0x01000303,0x01010100,0x01010000,
                0x00000000,0x00000000,0x0D000707,0x0000000D,0x00070700,0x0000000D,0x01010101,0x0000000D,
                0x01000001,0x0000000D,0x00030300,0x00000000,0x00030300,0x0000000D,0x01000001,0x00000101,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000000B,0x07070100,0x00000107,
                0x01010000,0x00000001,0x00000000,0x00000000,0x0C000000,0x0C0C0C0C,0x00000000,0x0C0C0C00,
                0x01010000,0x00010101,0x01010000,0x01010101,0x00000000,0x00000101,0x00000000,0x01010100,
                0x00000000,0x01010100,0x000C0C00,0x01010202,0x0C000C0C,0x02020200,0x0C000C0C,0x0202000C,
                0x01010101,0x00000001,0x01010001,0x00000001,0x00010100,0x00000000,0x00000101,0x00000000,
                0x00000101,0x00000000,0x00020201,0x00000C0C,0x0C000202,0x0C0C0C00,0x0C0C0002,0x0C0C0C00,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x000C0C00,0x02000C00,0x0C0C0000,0x000C0C0C,0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,
                0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,0x0C040000,0x0C0C0C0C,0x04040000,0x0C000C0C,
                0x00000C00,0x0C0C0C0C,0x0C0C0C00,0x0C0C000C,0x0C0C0C00,0x0C0C0007,0x0C0C0C00,0x0C0C0007,
                0x0C0C0C00,0x0C0C0007,0x040C0C00,0x0C0C0007,0x0C0C0C00,0x00000007,0x0C0C0C00,0x01010007,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x04040000,0x0C0C0C04,0x00000000,0x00000000,0x0C000000,0x00000007,0x0C000000,0x00000007,
                0x00000000,0x00000000,0x0C0C0000,0x00000007,0x070C0000,0x00000007,0x00000000,0x00000000,
                0x0C0C0C00,0x00010007,0x00000000,0x00000000,0x070C0000,0x00000000,0x070C0000,0x00000000,
                0x00000000,0x00000000,0x070C0C00,0x00000000,0x07070C00,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x07070700,0x00070707,0x00000700,0x00070000,
                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000070B,0x07070000,0x0000070B,
                0x00000000,0x00000000,0x07000000,0x000D0D00,0x07000000,0x0D0D0007,0x01010000,0x01010101,
                0x01010000,0x01010000,0x00000000,0x00000303,0x00010000,0x01000303,0x01010100,0x01010000,
                0x00000000,0x00000000,0x0D000707,0x0000000D,0x00070700,0x0000000D,0x01010101,0x0000000D,
                0x01000001,0x0000000D,0x00030300,0x00000000,0x00030300,0x0000000D,0x01000001,0x00000101,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x0B070000,0x0000070B,0x07070000,0x0000070B,0x0B070000,0x0000000B,0x07070100,0x00000107,
                0x01010000,0x00000001,0x00000000,0x00000000,0x0C000000,0x0C0C0C0C,0x00000000,0x0C0C0C00,
                0x01010000,0x00010101,0x01010000,0x01010101,0x00000000,0x00000101,0x00000000,0x01010100,
                0x00000000,0x01010100,0x000C0C00,0x01010202,0x0C000C0C,0x02020200,0x0C000C0C,0x0202000C,
                0x01010101,0x00000001,0x01010001,0x00000001,0x00010100,0x00000000,0x00000101,0x00000000,
                0x00000101,0x00000000,0x00020201,0x00000C0C,0x0C000202,0x0C0C0C00,0x0C0C0002,0x0C0C0C00,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x000C0C00,0x02000C00,0x0C0C0000,0x000C0C0C,0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,
                0x0C0C0000,0x0C0C0C0C,0x0C0C0000,0x0C000C0C,0x0C040000,0x0C0C0C0C,0x04040000,0x0C000C0C,
                0x00000C00,0x0C0C0C0C,0x0C0C0C00,0x0C0C000C,0x0C0C0C00,0x0C0C0007,0x0C0C0C00,0x0C0C0007,
                0x0C0C0C00,0x0C0C0007,0x040C0C00,0x0C0C0007,0x0C0C0C00,0x00000007,0x0C0C0C00,0x01010007,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,0x00000007,0x00000000,
                0x00000007,0x00000000,0x00000007,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x04040000,0x0C0C0C04,0x00000000,0x00000000,0x0C000000,0x00000007,0x0C000000,0x00000007,
                0x00000000,0x00000000,0x0C0C0000,0x00000007,0x070C0000,0x00000007,0x00000000,0x00000000,
                0x0C0C0C00,0x00010007,0x00000000,0x00000000,0x070C0000,0x00000000,0x00000000,0x00000000,
                0x070C0C00,0x00000000,0x07070C00,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
                0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
        };
#endif