
//{{BLOCK(mario_bg)

//======================================================================
//
//	mario_bg, 1024x576@8, 
//	+ palette 256 entries, not compressed
//	+ 37 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 64x36 
//	Metatiled by 2x2
//	Total size: 512 + 2368 + 792 + 4608 = 8280
//
//	Time-stamp: 2019-11-29, 10:40:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MARIO_BG_H
#define GRIT_MARIO_BG_H

#define mario_bgTilesLen 2368
extern const unsigned char mario_bgTiles[2368];

#define mario_bgMetaTilesLen 792
extern const unsigned char mario_bgMetaTiles[792];

#define mario_bgMetaMapLen 4608
extern const unsigned char mario_bgMetaMap[4608];

#define mario_bgPalLen 512
extern const unsigned char mario_bgPal[512];

#endif // GRIT_MARIO_BG_H

//}}BLOCK(mario_bg)
