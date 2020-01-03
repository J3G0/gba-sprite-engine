
//{{BLOCK(backgroundFront)

//======================================================================
//
//	backgroundFront, 512x256@8, 
//	+ palette 256 entries, not compressed
//	+ 182 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 11648 + 4096 = 16256
//
//	Time-stamp: 2020-01-03, 15:16:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUNDFRONT_H
#define GRIT_BACKGROUNDFRONT_H

#define backgroundFrontTilesLen 11648
extern const unsigned int backgroundFrontTiles[2912];

#define backgroundFrontMapLen 4096
extern const unsigned short backgroundFrontMap[2048];

#define backgroundFrontPalLen 512
extern const unsigned short backgroundFrontPal[256];

#endif // GRIT_BACKGROUNDFRONT_H

//}}BLOCK(backgroundFront)
