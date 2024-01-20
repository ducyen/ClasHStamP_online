#pragma warning(disable : 4996)
#define __Main_INTERNAL__
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#if defined( _MSC_VER )
#include <windows.h>
#include <wincodec.h>
#endif
#include <assert.h>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "Model/ContextImpl.h"

int InputValue(char* pMsg) {
    char n;
    printf( "%s", pMsg );
    scanf( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf( "%c", &c );
    }
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    printf( "%s\n", pMsg );
}

#define FONT_CHAR_HEIGHT 7
#define FONT_CHAR_WIDTH 5

/* Generic to compute font bit on/off for this font */
#define FONT_BIT(c, column, row) \
  ((font_data[(c)+(column)] & 1<<(7-(row))) != 0)


static const unsigned char font_data[][5] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x3E, 0x5B, 0x4F, 0x5B, 0x3E },
	{ 0x3E, 0x6B, 0x4F, 0x6B, 0x3E },
	{ 0x1C, 0x3E, 0x7C, 0x3E, 0x1C },
	{ 0x18, 0x3C, 0x7E, 0x3C, 0x18 },
	{ 0x1C, 0x57, 0x7D, 0x57, 0x1C },
	{ 0x1C, 0x5E, 0x7F, 0x5E, 0x1C },
	{ 0x00, 0x18, 0x3C, 0x18, 0x00 },
	{ 0xFF, 0xE7, 0xC3, 0xE7, 0xFF },
	{ 0x00, 0x18, 0x24, 0x18, 0x00 },
	{ 0xFF, 0xE7, 0xDB, 0xE7, 0xFF },
	{ 0x30, 0x48, 0x3A, 0x06, 0x0E },
	{ 0x26, 0x29, 0x79, 0x29, 0x26 },
	{ 0x40, 0x7F, 0x05, 0x05, 0x07 },
	{ 0x40, 0x7F, 0x05, 0x25, 0x3F },
	{ 0x5A, 0x3C, 0xE7, 0x3C, 0x5A },
	{ 0x7F, 0x3E, 0x1C, 0x1C, 0x08 },
	{ 0x08, 0x1C, 0x1C, 0x3E, 0x7F },
	{ 0x14, 0x22, 0x7F, 0x22, 0x14 },
	{ 0x5F, 0x5F, 0x00, 0x5F, 0x5F },
	{ 0x06, 0x09, 0x7F, 0x01, 0x7F },
	{ 0x00, 0x66, 0x89, 0x95, 0x6A },
	{ 0x60, 0x60, 0x60, 0x60, 0x60 },
	{ 0x94, 0xA2, 0xFF, 0xA2, 0x94 },
	{ 0x08, 0x04, 0x7E, 0x04, 0x08 },
	{ 0x10, 0x20, 0x7E, 0x20, 0x10 },
	{ 0x08, 0x08, 0x2A, 0x1C, 0x08 },
	{ 0x08, 0x1C, 0x2A, 0x08, 0x08 },
	{ 0x1E, 0x10, 0x10, 0x10, 0x10 },
	{ 0x0C, 0x1E, 0x0C, 0x1E, 0x0C },
	{ 0x30, 0x38, 0x3E, 0x38, 0x30 },
	{ 0x06, 0x0E, 0x3E, 0x0E, 0x06 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x5F, 0x00, 0x00 },
	{ 0x00, 0x07, 0x00, 0x07, 0x00 },
	{ 0x14, 0x7F, 0x14, 0x7F, 0x14 },
	{ 0x24, 0x2A, 0x7F, 0x2A, 0x12 },
	{ 0x23, 0x13, 0x08, 0x64, 0x62 },
	{ 0x36, 0x49, 0x56, 0x20, 0x50 },
	{ 0x00, 0x08, 0x07, 0x03, 0x00 },
	{ 0x00, 0x1C, 0x22, 0x41, 0x00 },
	{ 0x00, 0x41, 0x22, 0x1C, 0x00 },
	{ 0x2A, 0x1C, 0x7F, 0x1C, 0x2A },
	{ 0x08, 0x08, 0x3E, 0x08, 0x08 },
	{ 0x00, 0x80, 0x70, 0x30, 0x00 },
	{ 0x08, 0x08, 0x08, 0x08, 0x08 },
	{ 0x00, 0x00, 0x60, 0x60, 0x00 },
	{ 0x20, 0x10, 0x08, 0x04, 0x02 },
	{ 0x3E, 0x51, 0x49, 0x45, 0x3E },
	{ 0x00, 0x42, 0x7F, 0x40, 0x00 },
	{ 0x72, 0x49, 0x49, 0x49, 0x46 },
	{ 0x21, 0x41, 0x49, 0x4D, 0x33 },
	{ 0x18, 0x14, 0x12, 0x7F, 0x10 },
	{ 0x27, 0x45, 0x45, 0x45, 0x39 },
	{ 0x3C, 0x4A, 0x49, 0x49, 0x31 },
	{ 0x41, 0x21, 0x11, 0x09, 0x07 },
	{ 0x36, 0x49, 0x49, 0x49, 0x36 },
	{ 0x46, 0x49, 0x49, 0x29, 0x1E },
	{ 0x00, 0x00, 0x14, 0x00, 0x00 },
	{ 0x00, 0x40, 0x34, 0x00, 0x00 },
	{ 0x00, 0x08, 0x14, 0x22, 0x41 },
	{ 0x14, 0x14, 0x14, 0x14, 0x14 },
	{ 0x00, 0x41, 0x22, 0x14, 0x08 },
	{ 0x02, 0x01, 0x59, 0x09, 0x06 },
	{ 0x3E, 0x41, 0x5D, 0x59, 0x4E },
	{ 0x7C, 0x12, 0x11, 0x12, 0x7C },
	{ 0x7F, 0x49, 0x49, 0x49, 0x36 },
	{ 0x3E, 0x41, 0x41, 0x41, 0x22 },
	{ 0x7F, 0x41, 0x41, 0x41, 0x3E },
	{ 0x7F, 0x49, 0x49, 0x49, 0x41 },
	{ 0x7F, 0x09, 0x09, 0x09, 0x01 },
	{ 0x3E, 0x41, 0x41, 0x51, 0x73 },
	{ 0x7F, 0x08, 0x08, 0x08, 0x7F },
	{ 0x00, 0x41, 0x7F, 0x41, 0x00 },
	{ 0x20, 0x40, 0x41, 0x3F, 0x01 },
	{ 0x7F, 0x08, 0x14, 0x22, 0x41 },
	{ 0x7F, 0x40, 0x40, 0x40, 0x40 },
	{ 0x7F, 0x02, 0x1C, 0x02, 0x7F },
	{ 0x7F, 0x04, 0x08, 0x10, 0x7F },
	{ 0x3E, 0x41, 0x41, 0x41, 0x3E },
	{ 0x7F, 0x09, 0x09, 0x09, 0x06 },
	{ 0x3E, 0x41, 0x51, 0x21, 0x5E },
	{ 0x7F, 0x09, 0x19, 0x29, 0x46 },
	{ 0x26, 0x49, 0x49, 0x49, 0x32 },
	{ 0x03, 0x01, 0x7F, 0x01, 0x03 },
	{ 0x3F, 0x40, 0x40, 0x40, 0x3F },
	{ 0x1F, 0x20, 0x40, 0x20, 0x1F },
	{ 0x3F, 0x40, 0x38, 0x40, 0x3F },
	{ 0x63, 0x14, 0x08, 0x14, 0x63 },
	{ 0x03, 0x04, 0x78, 0x04, 0x03 },
	{ 0x61, 0x59, 0x49, 0x4D, 0x43 },
	{ 0x00, 0x7F, 0x41, 0x41, 0x41 },
	{ 0x02, 0x04, 0x08, 0x10, 0x20 },
	{ 0x00, 0x41, 0x41, 0x41, 0x7F },
	{ 0x04, 0x02, 0x01, 0x02, 0x04 },
	{ 0x40, 0x40, 0x40, 0x40, 0x40 },
	{ 0x00, 0x03, 0x07, 0x08, 0x00 },
	{ 0x20, 0x54, 0x54, 0x78, 0x40 },
	{ 0x7F, 0x28, 0x44, 0x44, 0x38 },
	{ 0x38, 0x44, 0x44, 0x44, 0x28 },
	{ 0x38, 0x44, 0x44, 0x28, 0x7F },
	{ 0x38, 0x54, 0x54, 0x54, 0x18 },
	{ 0x00, 0x08, 0x7E, 0x09, 0x02 },
	{ 0x18, 0xA4, 0xA4, 0x9C, 0x78 },
	{ 0x7F, 0x08, 0x04, 0x04, 0x78 },
	{ 0x00, 0x44, 0x7D, 0x40, 0x00 },
	{ 0x20, 0x40, 0x40, 0x3D, 0x00 },
	{ 0x7F, 0x10, 0x28, 0x44, 0x00 },
	{ 0x00, 0x41, 0x7F, 0x40, 0x00 },
	{ 0x7C, 0x04, 0x78, 0x04, 0x78 },
	{ 0x7C, 0x08, 0x04, 0x04, 0x78 },
	{ 0x38, 0x44, 0x44, 0x44, 0x38 },
	{ 0xFC, 0x18, 0x24, 0x24, 0x18 },
	{ 0x18, 0x24, 0x24, 0x18, 0xFC },
	{ 0x7C, 0x08, 0x04, 0x04, 0x08 },
	{ 0x48, 0x54, 0x54, 0x54, 0x24 },
	{ 0x04, 0x04, 0x3F, 0x44, 0x24 },
	{ 0x3C, 0x40, 0x40, 0x20, 0x7C },
	{ 0x1C, 0x20, 0x40, 0x20, 0x1C },
	{ 0x3C, 0x40, 0x30, 0x40, 0x3C },
	{ 0x44, 0x28, 0x10, 0x28, 0x44 },
	{ 0x4C, 0x90, 0x90, 0x90, 0x7C },
	{ 0x44, 0x64, 0x54, 0x4C, 0x44 },
	{ 0x00, 0x08, 0x36, 0x41, 0x00 },
	{ 0x00, 0x00, 0x77, 0x00, 0x00 },
	{ 0x00, 0x41, 0x36, 0x08, 0x00 },
	{ 0x02, 0x01, 0x02, 0x04, 0x02 },
	{ 0x3C, 0x26, 0x23, 0x26, 0x3C },
	{ 0x1E, 0xA1, 0xA1, 0x61, 0x12 },
	{ 0x3A, 0x40, 0x40, 0x20, 0x7A },
	{ 0x38, 0x54, 0x54, 0x55, 0x59 },
	{ 0x21, 0x55, 0x55, 0x79, 0x41 },
	{ 0x21, 0x54, 0x54, 0x78, 0x41 },
	{ 0x21, 0x55, 0x54, 0x78, 0x40 },
	{ 0x20, 0x54, 0x55, 0x79, 0x40 },
	{ 0x0C, 0x1E, 0x52, 0x72, 0x12 },
	{ 0x39, 0x55, 0x55, 0x55, 0x59 },
	{ 0x39, 0x54, 0x54, 0x54, 0x59 },
	{ 0x39, 0x55, 0x54, 0x54, 0x58 },
	{ 0x00, 0x00, 0x45, 0x7C, 0x41 },
	{ 0x00, 0x02, 0x45, 0x7D, 0x42 },
	{ 0x00, 0x01, 0x45, 0x7C, 0x40 },
	{ 0xF0, 0x29, 0x24, 0x29, 0xF0 },
	{ 0xF0, 0x28, 0x25, 0x28, 0xF0 },
	{ 0x7C, 0x54, 0x55, 0x45, 0x00 },
	{ 0x20, 0x54, 0x54, 0x7C, 0x54 },
	{ 0x7C, 0x0A, 0x09, 0x7F, 0x49 },
	{ 0x32, 0x49, 0x49, 0x49, 0x32 },
	{ 0x32, 0x48, 0x48, 0x48, 0x32 },
	{ 0x32, 0x4A, 0x48, 0x48, 0x30 },
	{ 0x3A, 0x41, 0x41, 0x21, 0x7A },
	{ 0x3A, 0x42, 0x40, 0x20, 0x78 },
	{ 0x00, 0x9D, 0xA0, 0xA0, 0x7D },
	{ 0x39, 0x44, 0x44, 0x44, 0x39 },
	{ 0x3D, 0x40, 0x40, 0x40, 0x3D },
	{ 0x3C, 0x24, 0xFF, 0x24, 0x24 },
	{ 0x48, 0x7E, 0x49, 0x43, 0x66 },
	{ 0x2B, 0x2F, 0xFC, 0x2F, 0x2B },
	{ 0xFF, 0x09, 0x29, 0xF6, 0x20 },
	{ 0xC0, 0x88, 0x7E, 0x09, 0x03 },
	{ 0x20, 0x54, 0x54, 0x79, 0x41 },
	{ 0x00, 0x00, 0x44, 0x7D, 0x41 },
	{ 0x30, 0x48, 0x48, 0x4A, 0x32 },
	{ 0x38, 0x40, 0x40, 0x22, 0x7A },
	{ 0x00, 0x7A, 0x0A, 0x0A, 0x72 },
	{ 0x7D, 0x0D, 0x19, 0x31, 0x7D },
	{ 0x26, 0x29, 0x29, 0x2F, 0x28 },
	{ 0x26, 0x29, 0x29, 0x29, 0x26 },
	{ 0x30, 0x48, 0x4D, 0x40, 0x20 },
	{ 0x38, 0x08, 0x08, 0x08, 0x08 },
	{ 0x08, 0x08, 0x08, 0x08, 0x38 },
	{ 0x2F, 0x10, 0xC8, 0xAC, 0xBA },
	{ 0x2F, 0x10, 0x28, 0x34, 0xFA },
	{ 0x00, 0x00, 0x7B, 0x00, 0x00 },
	{ 0x08, 0x14, 0x2A, 0x14, 0x22 },
	{ 0x22, 0x14, 0x2A, 0x14, 0x08 },
	{ 0xAA, 0x00, 0x55, 0x00, 0xAA },
	{ 0xAA, 0x55, 0xAA, 0x55, 0xAA },
	{ 0x00, 0x00, 0x00, 0xFF, 0x00 },
	{ 0x10, 0x10, 0x10, 0xFF, 0x00 },
	{ 0x14, 0x14, 0x14, 0xFF, 0x00 },
	{ 0x10, 0x10, 0xFF, 0x00, 0xFF },
	{ 0x10, 0x10, 0xF0, 0x10, 0xF0 },
	{ 0x14, 0x14, 0x14, 0xFC, 0x00 },
	{ 0x14, 0x14, 0xF7, 0x00, 0xFF },
	{ 0x00, 0x00, 0xFF, 0x00, 0xFF },
	{ 0x14, 0x14, 0xF4, 0x04, 0xFC },
	{ 0x14, 0x14, 0x17, 0x10, 0x1F },
	{ 0x10, 0x10, 0x1F, 0x10, 0x1F },
	{ 0x14, 0x14, 0x14, 0x1F, 0x00 },
	{ 0x10, 0x10, 0x10, 0xF0, 0x00 },
	{ 0x00, 0x00, 0x00, 0x1F, 0x10 },
	{ 0x10, 0x10, 0x10, 0x1F, 0x10 },
	{ 0x10, 0x10, 0x10, 0xF0, 0x10 },
	{ 0x00, 0x00, 0x00, 0xFF, 0x10 },
	{ 0x10, 0x10, 0x10, 0x10, 0x10 },
	{ 0x10, 0x10, 0x10, 0xFF, 0x10 },
	{ 0x00, 0x00, 0x00, 0xFF, 0x14 },
	{ 0x00, 0x00, 0xFF, 0x00, 0xFF },
	{ 0x00, 0x00, 0x1F, 0x10, 0x17 },
	{ 0x00, 0x00, 0xFC, 0x04, 0xF4 },
	{ 0x14, 0x14, 0x17, 0x10, 0x17 },
	{ 0x14, 0x14, 0xF4, 0x04, 0xF4 },
	{ 0x00, 0x00, 0xFF, 0x00, 0xF7 },
	{ 0x14, 0x14, 0x14, 0x14, 0x14 },
	{ 0x14, 0x14, 0xF7, 0x00, 0xF7 },
	{ 0x14, 0x14, 0x14, 0x17, 0x14 },
	{ 0x10, 0x10, 0x1F, 0x10, 0x1F },
	{ 0x14, 0x14, 0x14, 0xF4, 0x14 },
	{ 0x10, 0x10, 0xF0, 0x10, 0xF0 },
	{ 0x00, 0x00, 0x1F, 0x10, 0x1F },
	{ 0x00, 0x00, 0x00, 0x1F, 0x14 },
	{ 0x00, 0x00, 0x00, 0xFC, 0x14 },
	{ 0x00, 0x00, 0xF0, 0x10, 0xF0 },
	{ 0x10, 0x10, 0xFF, 0x10, 0xFF },
	{ 0x14, 0x14, 0x14, 0xFF, 0x14 },
	{ 0x10, 0x10, 0x10, 0x1F, 0x00 },
	{ 0x00, 0x00, 0x00, 0xF0, 0x10 },
	{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
	{ 0xF0, 0xF0, 0xF0, 0xF0, 0xF0 },
	{ 0xFF, 0xFF, 0xFF, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0xFF, 0xFF },
	{ 0x0F, 0x0F, 0x0F, 0x0F, 0x0F },
	{ 0x38, 0x44, 0x44, 0x38, 0x44 },
	{ 0x7C, 0x2A, 0x2A, 0x3E, 0x14 },
	{ 0x7E, 0x02, 0x02, 0x06, 0x06 },
	{ 0x02, 0x7E, 0x02, 0x7E, 0x02 },
	{ 0x63, 0x55, 0x49, 0x41, 0x63 },
	{ 0x38, 0x44, 0x44, 0x3C, 0x04 },
	{ 0x40, 0x7E, 0x20, 0x1E, 0x20 },
	{ 0x06, 0x02, 0x7E, 0x02, 0x02 },
	{ 0x99, 0xA5, 0xE7, 0xA5, 0x99 },
	{ 0x1C, 0x2A, 0x49, 0x2A, 0x1C },
	{ 0x4C, 0x72, 0x01, 0x72, 0x4C },
	{ 0x30, 0x4A, 0x4D, 0x4D, 0x30 },
	{ 0x30, 0x48, 0x78, 0x48, 0x30 },
	{ 0xBC, 0x62, 0x5A, 0x46, 0x3D },
	{ 0x3E, 0x49, 0x49, 0x49, 0x00 },
	{ 0x7E, 0x01, 0x01, 0x01, 0x7E },
	{ 0x2A, 0x2A, 0x2A, 0x2A, 0x2A },
	{ 0x44, 0x44, 0x5F, 0x44, 0x44 },
	{ 0x40, 0x51, 0x4A, 0x44, 0x40 },
	{ 0x40, 0x44, 0x4A, 0x51, 0x40 },
	{ 0x00, 0x00, 0xFF, 0x01, 0x03 },
	{ 0xE0, 0x80, 0xFF, 0x00, 0x00 },
	{ 0x08, 0x08, 0x6B, 0x6B, 0x08 },
	{ 0x36, 0x12, 0x36, 0x24, 0x36 },
	{ 0x06, 0x0F, 0x09, 0x0F, 0x06 },
	{ 0x00, 0x00, 0x18, 0x18, 0x00 },
	{ 0x00, 0x00, 0x10, 0x10, 0x00 },
	{ 0x30, 0x40, 0xFF, 0x01, 0x01 },
	{ 0x00, 0x1F, 0x01, 0x01, 0x1E },
	{ 0x00, 0x19, 0x1D, 0x17, 0x12 },
	{ 0x00, 0x3C, 0x3C, 0x3C, 0x3C },
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }
};
// Function to place a character from the font into an RGBA bitmap
void placeCharacterInBitmap(BYTE *pv, unsigned char ch, int scale, int x, int y, int cbStride, uint8_t byRed, uint8_t byGreen, uint8_t byBlue ) {
    int fontIndex, i, j;
#if 0
    // Check if the character is in the font
    if (ch >= 'A' && ch <= 'Z') {
        fontIndex = ch - 'A';
    } else if (ch >= '0' && ch <= '9') {
        fontIndex = ch - '0' + 26;
    } else {
        // Character not in font
        return;
    }
#else
    fontIndex = ch;
#endif

    // Place the character into the bitmap
    for (i = 0; i < FONT_CHAR_WIDTH; ++i) {
        for (j = 0; j < FONT_CHAR_HEIGHT; ++j) {
            if ((font_data[fontIndex][i] >> j) & 1) {
                // Set the pixel to white (RGBA: 255, 255, 255, 255)
                UINT destIndex = ( y + j*scale ) * cbStride + ( x + i*scale ) * 4;

                // For simplicity, we'll just set the pixel to red (assuming 32bpp BGRA format)
                pv[ destIndex ] = byBlue;       // Blue
                pv[ destIndex + 1 ] = byGreen;   // Green
                pv[ destIndex + 2 ] = byRed; // Red
                pv[ destIndex + 3 ] = 255; // Alpha
            }
        }
    }
}

#if defined( _MSC_VER )
#define CALL(ptr, method, ...) ((ptr)->lpVtbl->method((ptr), __VA_ARGS__))

void SavePngImage( char* sPath );

/**
 * Convert char to wide char
 */
WCHAR* ConvertCharToWChar(const char* charString, UINT codePage) {
    int requiredSize = MultiByteToWideChar(codePage, 0, charString, -1, NULL, 0);
    if (requiredSize == 0) {
        fprintf(stderr, "MultiByteToWideChar failed.\n");
        return NULL;
    }

    WCHAR* wideString = (WCHAR*)malloc(requiredSize * sizeof(WCHAR));
    if (wideString == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    if (MultiByteToWideChar(codePage, 0, charString, -1, wideString, requiredSize) == 0) {
        free(wideString);
        fprintf(stderr, "MultiByteToWideChar failed.\n");
        return NULL;
    }

    return wideString;
}

IWICImagingFactory* m_pIWICFactory = NULL;
/**
 * Load image from png file
 */
IWICBitmap* LoadPngImage( char* sPath ){
    WCHAR* wideString = ConvertCharToWChar(sPath, CP_UTF8);  // Using UTF-8 code page
    WCHAR strInputFile[ 256 ];
    swprintf( strInputFile, sizeof( strInputFile ) / sizeof( strInputFile[ 0 ] ), L"../Image/Design/%s.png", wideString );
    HRESULT hr = S_OK;

    IWICBitmapDecoder *pIDecoder = NULL;
    IWICBitmapFrameDecode *pIDecoderFrame = NULL;

    hr = CALL( m_pIWICFactory, CreateDecoderFromFilename,
        strInputFile,                   // Image to be decoded
        NULL,                           // Do not prefer a particular vendor
        GENERIC_READ,                   // Desired read access to the file
        WICDecodeMetadataCacheOnDemand, // Cache metadata when needed
        &pIDecoder                      // Pointer to the decoder
    );

    // Retrieve the first bitmap frame.
    if( SUCCEEDED( hr ) ){
        hr = CALL( pIDecoder, GetFrame, 0, &pIDecoderFrame );
    }

    IWICBitmap *pIBitmap = NULL;

    // Create the bitmap from the image frame.
    if( SUCCEEDED( hr ) ){
        hr = CALL( m_pIWICFactory, CreateBitmapFromSource,
            pIDecoderFrame,          // Create a bitmap from the image frame
            WICBitmapCacheOnDemand,  // Cache bitmap pixels on first access
            &pIBitmap );              // Pointer to the bitmap
    }
    if( pIDecoder ) CALL( pIDecoder, Release );
    if( pIDecoderFrame ) CALL( pIDecoderFrame, Release );

    return pIBitmap;
}

/**
 * find bitmap from path
 */
static int g_nPathToBitmapCnt = 0;
static struct{
    char m_sPath[ 256 ];
    IWICBitmap* m_pIBitmap;
} g_arrPathToBitmap[ 10 ];

void LoadAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        g_arrPathToBitmap[ i ].m_pIBitmap = LoadPngImage( g_arrPathToBitmap[ i ].m_sPath );
    }
}

void ReleaseAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        if( g_arrPathToBitmap[ i ].m_pIBitmap ) CALL( g_arrPathToBitmap[ i ].m_pIBitmap, Release );
    }
}

void SaveAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        SavePngImage( g_arrPathToBitmap[ i ].m_sPath );
    }
}

IWICBitmap* FindBitmapFromPath( char* sPath ){
    // Find if existed or not
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        if( strcmp( sPath, g_arrPathToBitmap[ i ].m_sPath ) == 0 ){
            return g_arrPathToBitmap[ i ].m_pIBitmap;
        }
    }
    // If not exsited, add new
    strcpy( g_arrPathToBitmap[ g_nPathToBitmapCnt ].m_sPath, sPath );
    IWICBitmap* pIBitmap = LoadPngImage( sPath );
    g_arrPathToBitmap[ g_nPathToBitmapCnt ].m_pIBitmap = pIBitmap;
    g_nPathToBitmapCnt++;
    assert( g_nPathToBitmapCnt < sizeof( g_arrPathToBitmap ) / sizeof( g_arrPathToBitmap[ 0 ] ) );
    return pIBitmap;
}


/**
 * Draw rectangle on a png file
 */
int DrawRectangle( char* 
    sPath, 
    int nLeft, int nTop, int nWidth, int nHeight, 
    int nDgrLeft, int nDgrTop, int nDgrWidth, int nDgrHeight,
    uint8_t byRed, uint8_t byGreen, uint8_t byBlue 
){
    HRESULT hr = S_OK;
    IWICBitmap *pIBitmap = FindBitmapFromPath( sPath );
    IWICBitmapLock *pILock = NULL;

    if( SUCCEEDED( hr ) ){
        UINT uiWidth = 10;
        UINT uiHeight = 10;

        hr = CALL( pIBitmap, GetSize, &uiWidth, &uiHeight );
        if( FAILED( hr ) ) return hr;

        WICRect rcLock = { 0, 0, uiWidth, uiHeight };

        // Obtain a bitmap lock for exclusive write.
        // The lock is for a 10x10 rectangle starting at the top left of the
        // bitmap.
        hr = CALL( pIBitmap, Lock, &rcLock, WICBitmapLockWrite, &pILock );

        if( SUCCEEDED( hr ) ){
            UINT cbBufferSize = 0;
            BYTE *pv = NULL;

            // Retrieve a pointer to the pixel data.
            if( SUCCEEDED( hr ) ){
                hr = CALL( pILock, GetDataPointer, &cbBufferSize, &pv );
            }

            // Pixel manipulation using the image data pointer pv.
            UINT cbStride;
            hr = CALL( pILock, GetStride, &cbStride );
            uiHeight -= ( 40 - 14 );
            //uiWidth  -= ( nLeftMgn + nRightMgn );
            nTop = ( float )( nTop - nDgrTop ) * uiHeight / nDgrHeight;
            nLeft = ( float )( nLeft - nDgrLeft ) * uiWidth / nDgrWidth;
            nHeight = ( float )nHeight * uiHeight / nDgrHeight;
            nWidth = ( float )nWidth * uiWidth / nDgrWidth;
            UINT nDotSize = 3;
            // Draw the rectangle on the destination bitmap
            for( UINT y = nTop; y < nTop + nHeight; y++ ){
                for( UINT x = nLeft; x < nLeft + nWidth; x++ ){
                    if( y >= nTop + nDotSize && y < nTop + nHeight - nDotSize && x >= nLeft + nDotSize && x < nLeft + nWidth - nDotSize ){
                        ; // Do nothing
                    } else{
                        UINT destIndex = y * cbStride + x * 4;

                        // For simplicity, we'll just set the pixel to red (assuming 32bpp BGRA format)
                        pv[ destIndex ] = byBlue;       // Blue
                        pv[ destIndex + 1 ] = byGreen;   // Green
                        pv[ destIndex + 2 ] = byRed; // Red
                        pv[ destIndex + 3 ] = 255; // Alpha
                    }
                }
            }
            // Draw some text
            for( int i = 0; i < sizeof( font_data ) / sizeof( font_data[ 0 ] ) / 2; i++ ){
                int scale = 2;
                placeCharacterInBitmap( pv, i, scale, 
                    10 + i * ( FONT_CHAR_WIDTH + 1 )*scale, 
                    50, 
                    cbStride, 
                    0, 0, 255 
                );
            }

            // Release the bitmap lock.
            CALL( pILock, Release );

        }
    }
    SavePngImage( sPath );
}

/**
 * Save png image to file
 */
void SavePngImage( char* sPath ){
    WCHAR* wideString = ConvertCharToWChar(sPath, CP_UTF8);  // Using UTF-8 code page
    WCHAR strOutputFile[ 256 ];
    swprintf( strOutputFile, sizeof( strOutputFile ) / sizeof( strOutputFile[ 0 ] ), L"../TransImg/Design/%s.png", wideString );
    HRESULT hr = S_OK;
    IWICBitmap *pIBitmap = FindBitmapFromPath( sPath );

    if( SUCCEEDED( hr ) ){
        IWICStream* pStream = NULL;
        IWICBitmapEncoder* pEncoder = NULL;
        IWICBitmapFrameEncode* pFrameEncode = NULL;

        hr = CALL( m_pIWICFactory, CreateStream, &pStream );

        if( SUCCEEDED( hr ) ){
            hr = CALL( pStream, InitializeFromFilename, strOutputFile, GENERIC_WRITE );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( m_pIWICFactory, CreateEncoder, &GUID_ContainerFormatPng, NULL, &pEncoder );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, Initialize, pStream, WICBitmapEncoderNoCache );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, CreateNewFrame, &pFrameEncode, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, Initialize, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, WriteSource, pIBitmap, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, Commit );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, Commit );
        }
        if( pFrameEncode ) CALL( pFrameEncode, Release );
        if( pEncoder ) CALL( pEncoder, Release );
        if( pStream ) CALL( pStream, Release );
    }

    free(wideString);
}

// Linker pragmas
#pragma comment(lib, "windowscodecs.lib")

#endif

void ShowEntry( char* pMsg ){

    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, 0, 255, 0 );
    Sleep( 500 );
}

void ShowDoing( char* pMsg ){

    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, 255, 255, 0 );
}

void ShowExit( char* pMsg ){
    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, 255, 0, 0 );
    Sleep( 500 );
}

int main( void ){
    HRESULT hr = CoInitialize( NULL );
    if( FAILED( hr ) ){
        printf( "Failed to initialize COM: %08X\n", hr );
        return 1;
    }

    // Create WIC factory
    hr = CoCreateInstance(
        &CLSID_WICImagingFactory,
        NULL,
        CLSCTX_INPROC_SERVER,
        &IID_IWICImagingFactory,
        &m_pIWICFactory
    );


    ContextImpl context = ContextImpl_Ctor( ContextImpl_Init( 
        4, "", 1, 2, 3, { 0 },
        Composition_Ctor( Composition_Init( 3 ), )
    ), );
    char n;
    do {
        ContextImpl_Start( &context );

        do {
            LoadAllImages();
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            EventParams* pParams = NULL;
            E1Params e1Params = { .x = Two };
            if (n == ContextImpl_E1) {
                pParams = &e1Params;
            }
            ContextImpl_EventProc( &context, (ContextImpl_EVENT)n, pParams);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');
       
    ReleaseAllImages();
    if( m_pIWICFactory ) CALL( m_pIWICFactory, Release );
    CoUninitialize();

    return 0;
}