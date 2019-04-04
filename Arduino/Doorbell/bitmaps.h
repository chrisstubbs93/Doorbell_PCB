/**
    \file bitmaps.h
    Stores bitmap images for display in program memory
*/

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

/*! The LSBU logo stored as an array. */
/*! Generated from http://javl.github.io/image2cpp/ */
/*! Invert colours. */
const unsigned char BmpLSBU [] PROGMEM = {
  // LSBU Crest_simple white text_Horizon_BlackOutline, 296x128px
  0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x48, 0x00, 0x00, 0x00, 0x24, 0x30, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x44, 0x00, 
  0x00, 0x00, 0x44, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x04, 0x00, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x89, 0x84, 0x00, 0x00, 0x00, 0x42, 0x22, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x18, 0xc8, 0x00, 0x00, 
  0x00, 0x06, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x04, 0x20, 0x28, 0x00, 0x00, 0x00, 0x28, 0x08, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x10, 0x06, 0x20, 0x00, 0x10, 0x00, 0x60, 0x00, 0x00, 
  0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x60, 0x49, 0xf0, 0x00, 
  0x1c, 0x00, 0x20, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
  0x1c, 0x00, 0xdf, 0xa9, 0x00, 0x00, 0xf0, 0x20, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x04, 0xd0, 0x0f, 0xeb, 0x73, 0x00, 0x00, 0x16, 0x40, 0x00, 0x00, 0x00, 
  0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x10, 0x0d, 0x5b, 0x45, 0x00, 0x88, 
  0x01, 0x40, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x08, 
  0x0b, 0x44, 0x9b, 0x00, 0xf8, 0x20, 0x80, 0x01, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0x80, 0x03, 0x00, 0x17, 0xf0, 0x6b, 0x61, 0x47, 0x41, 0x80, 0x03, 0x00, 0x00, 0x1e, 
  0x00, 0x01, 0xf0, 0x00, 0x0f, 0x00, 0x03, 0xfc, 0x00, 0xf8, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0xbc, 0x6b, 0xdd, 0x6d, 0xca, 0x51, 0x7a, 
  0x00, 0x05, 0x00, 0x00, 0x1e, 0x00, 0x07, 0xfc, 0x3f, 0xbf, 0xc0, 0x1f, 0xfc, 0x03, 0xfe, 0x1f, 
  0xcf, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0x0c, 0x1e, 
  0x15, 0xba, 0xc9, 0x54, 0x41, 0x00, 0x11, 0x00, 0x00, 0x1e, 0x00, 0x1f, 0xfe, 0x3f, 0xff, 0xe0, 
  0x3f, 0xfc, 0x07, 0xff, 0x1f, 0xdf, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x10, 0xe2, 0x08, 0x18, 0x2e, 0xad, 0xf0, 0x98, 0x21, 0x0e, 0x21, 0x00, 0x00, 0x1e, 0x00, 
  0x3f, 0xff, 0x3f, 0xff, 0xe0, 0x7f, 0xfc, 0x0f, 0xff, 0x9f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x09, 0x22, 0x11, 0xe6, 0xdf, 0xff, 0x74, 0x90, 0x10, 0x89, 
  0x21, 0x00, 0x00, 0x1e, 0x00, 0x3e, 0x1f, 0x07, 0xe3, 0xe0, 0xfc, 0x3c, 0x1f, 0x8f, 0xc3, 0xf8, 
  0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x24, 0x21, 0x39, 0xee, 
  0x10, 0xf5, 0xb0, 0x10, 0x48, 0x41, 0x00, 0x00, 0x1e, 0x00, 0x7c, 0x0f, 0x87, 0xc1, 0xe0, 0xf8, 
  0x3c, 0x1e, 0x07, 0xc3, 0xf0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x86, 0x20, 0x20, 0xaa, 0x74, 0x10, 0x5a, 0x70, 0x08, 0x48, 0xc2, 0x00, 0x00, 0x1e, 0x00, 0x7c, 
  0x0f, 0x87, 0xc1, 0xe1, 0xf0, 0x3c, 0x3e, 0x03, 0xc3, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x40, 0x8c, 0xb4, 0x10, 0x5f, 0x60, 0x04, 0x28, 0x84, 
  0x00, 0x00, 0x1e, 0x00, 0x78, 0x07, 0x87, 0x81, 0xe1, 0xf0, 0x3c, 0x3e, 0x03, 0xc3, 0xe0, 0xf8, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x50, 0x00, 0x8e, 0xb4, 0x10, 
  0x5b, 0xf8, 0x04, 0x04, 0x04, 0x00, 0x00, 0x1e, 0x00, 0x78, 0x07, 0x87, 0x81, 0xe1, 0xf0, 0x3c, 
  0x3c, 0x03, 0xc3, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x64, 
  0x10, 0x80, 0x06, 0xf4, 0x10, 0x59, 0xa8, 0x02, 0x14, 0x08, 0x40, 0x00, 0x1e, 0x00, 0x78, 0x07, 
  0x87, 0x81, 0xe1, 0xf0, 0x3e, 0x3c, 0x03, 0xc3, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x08, 0x10, 0xa1, 0x06, 0x0d, 0xb4, 0x10, 0x58, 0xa8, 0xc1, 0x02, 0x10, 0x20, 
  0x00, 0x1e, 0x00, 0x78, 0x07, 0x87, 0x81, 0xe1, 0xf0, 0x3c, 0x3e, 0x03, 0xc3, 0xe0, 0xf8, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x20, 0x12, 0x4d, 0x74, 0x10, 0x58, 
  0x48, 0x11, 0x0a, 0x00, 0x40, 0x00, 0x1e, 0x0e, 0x7c, 0x0f, 0x87, 0x81, 0xe1, 0xf0, 0x3c, 0x3e, 
  0x03, 0xc3, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x42, 
  0x42, 0x5f, 0x34, 0x10, 0x5c, 0x48, 0x88, 0x80, 0x01, 0x80, 0x00, 0x1e, 0x0e, 0x7c, 0x0f, 0x87, 
  0x81, 0xe1, 0xf0, 0x7e, 0x3e, 0x07, 0xc3, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x60, 0x44, 0x02, 0x2a, 0xb4, 0x10, 0x5c, 0x20, 0x84, 0x04, 0x08, 0x00, 0x00, 
  0x1e, 0x0e, 0x7e, 0x1f, 0x07, 0x81, 0xe1, 0xf8, 0xfc, 0x1f, 0x0f, 0x83, 0xc0, 0xf8, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x84, 0x84, 0x1a, 0x74, 0x10, 0x5c, 0xf0, 
  0x02, 0x42, 0x10, 0x00, 0x00, 0x3f, 0xfe, 0x3f, 0xff, 0x0f, 0xc1, 0xf0, 0xff, 0xff, 0x9f, 0xff, 
  0x87, 0xe0, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x89, 0x08, 
  0x06, 0x75, 0xba, 0x5d, 0x90, 0x41, 0x22, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x3f, 0xfe, 0x3f, 0xe1, 
  0xfc, 0xff, 0xff, 0x8f, 0xff, 0x1f, 0xf8, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x04, 0x1e, 0x03, 0x76, 0xfe, 0xdb, 0x61, 0xf0, 0xa2, 0x20, 0x00, 0x00, 0xff, 
  0xfe, 0x1f, 0xfc, 0x3f, 0xe1, 0xfc, 0x7f, 0xbf, 0x87, 0xfe, 0x1f, 0xf8, 0xfe, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x18, 0x00, 0x82, 0x7f, 0xff, 0xee, 0xc2, 0x08, 
  0x21, 0x20, 0x00, 0x00, 0xff, 0xfe, 0x07, 0xf0, 0x3f, 0xe1, 0xfc, 0x1f, 0x3f, 0x01, 0xf8, 0x0f, 
  0xf8, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x42, 
  0xbe, 0x11, 0xfd, 0x08, 0x00, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x08, 0x00, 0x00, 0x15, 0xc1, 0xf8, 0x06, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x30, 0x23, 0x2c, 0x1f, 0x89, 0x08, 0x18, 0x00, 
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x02, 0x0b, 0x82, 0x60, 
  0x77, 0x39, 0x03, 0xa0, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0x08, 0x88, 0x03, 0x81, 0x0a, 0x47, 0x00, 0x02, 0x21, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x90, 0x80, 0x07, 0x02, 0x83, 0x20, 0xe0, 0x42, 0x12, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x60, 0x40, 0x32, 0x04, 0x70, 
  0x10, 0x1c, 0x04, 0x1c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  0x0e, 0x3f, 0x8c, 0x33, 0x00, 0x68, 0x01, 0xd8, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x13, 0x98, 0x00, 0x50, 0x00, 0x0c, 0x01, 0x60, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x3d, 0x80, 0x01, 0x40, 
  0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 
  0x00, 0x16, 0x40, 0x01, 0x40, 0xc0, 0x00, 0x03, 0x10, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 
  0x00, 0x01, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 
  0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x14, 0x20, 0x01, 0x40, 0xf8, 0x00, 0x06, 0x10, 0x00, 0x00, 
  0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x7f, 0x80, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x10, 0xa0, 0x03, 0xf2, 0x10, 0x00, 0x00, 0xc7, 
  0x80, 0x1a, 0x10, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x0f, 0x80, 0x00, 
  0x03, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0f, 0xf9, 
  0x91, 0x08, 0x02, 0x88, 0x42, 0x7f, 0xe4, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0xf0, 0x0f, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
  0x00, 0x1c, 0xc8, 0x40, 0x46, 0x10, 0x88, 0x03, 0x08, 0x40, 0xc0, 0x04, 0x2f, 0xf0, 0x00, 0xfc, 
  0x78, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x0f, 0x80, 0x00, 0x00, 0x7c, 0x1f, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x40, 0x1c, 0x30, 0x42, 0x10, 0xd4, 0x04, 0x18, 0x20, 0x84, 
  0x18, 0x70, 0x0c, 0x00, 0xf8, 0x78, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x0f, 0x80, 0x00, 0x00, 
  0x7c, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x20, 0x06, 0x00, 0x21, 0x20, 
  0xa0, 0x00, 0x18, 0x23, 0x0b, 0x80, 0xc0, 0x08, 0x00, 0xf0, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 
  0xf0, 0x0f, 0x0f, 0x00, 0x00, 0x7c, 0x0f, 0x83, 0xf8, 0x00, 0x01, 0xe0, 0x0f, 0x00, 0x00, 0x00, 
  0x20, 0x01, 0x00, 0x16, 0xa0, 0xa2, 0x08, 0x24, 0x13, 0x90, 0x03, 0x00, 0x10, 0x01, 0xf0, 0x00, 
  0x0f, 0xf8, 0x7f, 0x0f, 0xef, 0xff, 0x0f, 0x3f, 0x80, 0x00, 0x7c, 0x0f, 0x8f, 0xfe, 0x0f, 0xe7, 
  0xf0, 0x0f, 0x1f, 0xe0, 0x00, 0x10, 0x00, 0x00, 0x08, 0x81, 0x52, 0x10, 0x44, 0x02, 0x60, 0x00, 
  0x00, 0x20, 0x00, 0xf8, 0x00, 0x1f, 0xfe, 0x7f, 0x0f, 0xe7, 0xff, 0x0f, 0xff, 0xc0, 0x00, 0x7c, 
  0x0f, 0x0f, 0xff, 0x0f, 0xef, 0xf8, 0x0f, 0x1f, 0xe0, 0x00, 0x04, 0x00, 0x00, 0x10, 0x41, 0xa9, 
  0x4f, 0xe2, 0x0a, 0x00, 0x00, 0x00, 0x40, 0x00, 0xfc, 0x00, 0x3f, 0xfe, 0x7f, 0x0f, 0xef, 0xff, 
  0x0f, 0xff, 0xe0, 0x00, 0x7c, 0x3f, 0x0f, 0xff, 0x07, 0xff, 0xfc, 0x0f, 0x0f, 0x80, 0x00, 0x01, 
  0xff, 0x00, 0x11, 0x80, 0xa9, 0x81, 0x8a, 0x06, 0x10, 0x01, 0xc7, 0x00, 0x00, 0xff, 0x80, 0x7e, 
  0x3f, 0x0f, 0x03, 0xe1, 0xf0, 0x0f, 0xe3, 0xe0, 0x00, 0x7f, 0xfe, 0x0e, 0x0f, 0x81, 0xfc, 0x7c, 
  0x0f, 0x1f, 0x00, 0x00, 0x00, 0x18, 0x01, 0xf1, 0x02, 0x93, 0x02, 0x05, 0x02, 0x3e, 0x00, 0x60, 
  0x00, 0x00, 0x7f, 0xe0, 0x7c, 0x1f, 0x0f, 0x03, 0xe1, 0xf0, 0x0f, 0xc3, 0xe0, 0x00, 0x7f, 0xfc, 
  0x0e, 0x0f, 0x81, 0xf8, 0x7c, 0x0f, 0x3e, 0x00, 0x00, 0x00, 0x20, 0x1c, 0xcd, 0x04, 0x16, 0x26, 
  0x00, 0x80, 0x60, 0xe0, 0x18, 0x00, 0x00, 0x3f, 0xf0, 0xf8, 0x0f, 0x0f, 0x03, 0xe1, 0xf0, 0x0f, 
  0x83, 0xe0, 0x00, 0x7f, 0xff, 0x00, 0x0f, 0x81, 0xf0, 0x7c, 0x0f, 0x3e, 0x00, 0x00, 0x00, 0x41, 
  0x83, 0x03, 0x09, 0x2a, 0x21, 0x02, 0x41, 0x80, 0x06, 0x04, 0x00, 0x00, 0x07, 0xf8, 0xf8, 0x0f, 
  0x8f, 0x03, 0xe1, 0xf0, 0x0f, 0x83, 0xe0, 0x00, 0x7c, 0xff, 0x00, 0x3f, 0x81, 0xf0, 0x7c, 0x0f, 
  0x7c, 0x00, 0x00, 0x00, 0x80, 0x0c, 0x05, 0xbf, 0xc2, 0x3f, 0xff, 0xf3, 0x40, 0x41, 0x00, 0x00, 
  0x00, 0x01, 0xfc, 0xf8, 0x0f, 0x8f, 0x03, 0xe1, 0xf0, 0x0f, 0x83, 0xe0, 0x00, 0x7c, 0x1f, 0x83, 
  0xff, 0x81, 0xf0, 0x7c, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x82, 0x10, 0x09, 0xff, 0xfe, 0x3f, 0xff, 
  0xff, 0x20, 0x10, 0x82, 0x00, 0x00, 0x00, 0x7c, 0xf8, 0x0f, 0x8f, 0x03, 0xe1, 0xf0, 0x0f, 0x03, 
  0xe0, 0x00, 0x7c, 0x0f, 0x8f, 0xff, 0x81, 0xe0, 0x7c, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x04, 0x40, 
  0x11, 0x80, 0x22, 0xc0, 0x00, 0x03, 0x10, 0x00, 0x42, 0x00, 0x00, 0x00, 0x7c, 0xf8, 0x0f, 0x0f, 
  0x03, 0xe1, 0xf0, 0x0f, 0x03, 0xe0, 0x00, 0x7c, 0x0f, 0x9f, 0x8f, 0x81, 0xe0, 0x7c, 0x0f, 0x7e, 
  0x00, 0x00, 0x00, 0x10, 0x80, 0x43, 0x80, 0x17, 0x00, 0x00, 0x03, 0x80, 0x02, 0x32, 0x00, 0x00, 
  0xe0, 0x7c, 0xf8, 0x0f, 0x0f, 0x03, 0xe1, 0xf0, 0x0f, 0x83, 0xe0, 0x00, 0x7c, 0x0f, 0x9e, 0x0f, 
  0x81, 0xe0, 0x7c, 0x0f, 0x3e, 0x00, 0x00, 0x01, 0xc1, 0x00, 0x8b, 0x80, 0x80, 0x00, 0x02, 0x03, 
  0x22, 0x01, 0x0e, 0x00, 0x00, 0xf0, 0x7c, 0xf8, 0x1f, 0x0f, 0x07, 0xe1, 0xf0, 0x0f, 0x03, 0xe0, 
  0x00, 0x7c, 0x0f, 0x9e, 0x0f, 0x81, 0xe0, 0x7c, 0x0f, 0x1f, 0x00, 0x00, 0x00, 0x04, 0x01, 0x23, 
  0x81, 0x80, 0x00, 0x03, 0x03, 0x19, 0x00, 0x80, 0x00, 0x00, 0xf0, 0xfc, 0x7c, 0x3e, 0x0f, 0x8f, 
  0xc1, 0xf0, 0x0f, 0x03, 0xe0, 0x00, 0x7c, 0x1f, 0x9e, 0x1f, 0x81, 0xe0, 0x7c, 0x0f, 0x1f, 0x80, 
  0x00, 0x00, 0x08, 0x1c, 0x43, 0x83, 0x80, 0x00, 0x03, 0x83, 0x80, 0x30, 0x00, 0x00, 0x00, 0xff, 
  0xf8, 0x7f, 0xfe, 0x0f, 0xff, 0xf8, 0xff, 0x1f, 0x83, 0xf0, 0x00, 0xff, 0xff, 0x1f, 0x3f, 0xe3, 
  0xf0, 0x7e, 0x1f, 0x8f, 0xe0, 0x00, 0x00, 0x00, 0x24, 0x03, 0x82, 0x00, 0x00, 0x01, 0x83, 0x84, 
  0x40, 0x20, 0x00, 0x00, 0xff, 0xf0, 0x3f, 0xfc, 0x0f, 0xff, 0xf8, 0xff, 0x7f, 0xe3, 0xf8, 0x03, 
  0xff, 0xfe, 0x1f, 0xff, 0xe7, 0xfc, 0x7f, 0x7f, 0xc7, 0xf0, 0x00, 0x00, 0x10, 0x22, 0x81, 0x83, 
  0x80, 0x00, 0x03, 0x03, 0x82, 0x88, 0x10, 0x00, 0x00, 0xff, 0xe0, 0x1f, 0xf8, 0x07, 0xfb, 0xf8, 
  0xff, 0x7f, 0xe3, 0xf8, 0x03, 0xff, 0xfc, 0x0f, 0xf7, 0xe7, 0xfc, 0x7f, 0x7f, 0xc3, 0xf0, 0x00, 
  0x00, 0x20, 0x22, 0x01, 0x83, 0x80, 0x00, 0x03, 0x03, 0x02, 0x88, 0x00, 0x00, 0x00, 0x3f, 0x80, 
  0x07, 0xe0, 0x03, 0xf1, 0xf8, 0x7f, 0x7f, 0xe1, 0xf8, 0x01, 0xff, 0xe0, 0x07, 0xc7, 0xe7, 0xf8, 
  0x3f, 0x3f, 0xc3, 0xf0, 0x00, 0x00, 0x20, 0x63, 0x05, 0x83, 0x80, 0x00, 0x0b, 0x83, 0x41, 0x08, 
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa3, 0x05, 0x83, 0xb0, 
  0x00, 0x1b, 0x83, 0x41, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x21, 0x02, 0x09, 0x83, 0xb0, 0x00, 0x3b, 0x83, 0x20, 0x80, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x24, 0x11, 0xa7, 0xb0, 0x00, 0x1b, 0xc3, 0x10, 0x80, 0x18, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x40, 0x61, 0xb7, 0xf8, 0x00, 
  0x3f, 0xdb, 0x08, 0x0c, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 
  0x01, 0xf9, 0x80, 0x00, 0x00, 0x00, 0x03, 0x3e, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x05, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x40, 0x00, 0x10, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
  0x05, 0x00, 0x1f, 0xc7, 0xf0, 0x01, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x10, 0x7c, 0x79, 0x00, 0x2f, 0xc7, 0xe8, 0x00, 0x3c, 0x7c, 0x10, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x01, 0x00, 0x30, 0x0c, 0x18, 0x00, 
  0x00, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x03, 0x01, 
  0x00, 0x60, 0x6c, 0x08, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x00, 0x0e, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0xc1, 0x00, 0x60, 0x6c, 0x0c, 0x00, 0x06, 0x02, 0x20, 0x00, 0x00, 0xc0, 
  0x01, 0x80, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x30, 0x00, 0x40, 0x10, 0x0c, 0x02, 0x18, 
  0x0c, 0x20, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x50, 0x08, 0x00, 
  0xa0, 0x18, 0x08, 0x02, 0x20, 0x10, 0x40, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x04, 0x28, 0x04, 0x80, 0x50, 0xae, 0x14, 0x02, 0x80, 0x68, 0x40, 0x00, 0x00, 0xc0, 0x01, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x80, 0x39, 0x45, 0x30, 0x03, 0x00, 0x90, 
  0x80, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x1c, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x60, 0x00, 
  0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x11, 0x01, 0x80, 0x0b, 
  0x03, 0xa0, 0x02, 0x01, 0x20, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x8c, 0x7f, 0x06, 0x70, 0x03, 0x0f, 
  0xf0, 0x33, 0xc3, 0xf8, 0x67, 0xff, 0xb8, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x02, 0x08, 0x80, 0x81, 0xee, 0x00, 0xce, 0x02, 0x06, 0x20, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x8d, 
  0xc7, 0x86, 0x30, 0x07, 0x1c, 0x38, 0x37, 0xc7, 0x08, 0x60, 0x70, 0x38, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x20, 0x81, 0xfa, 0x00, 0xbd, 0x04, 0x08, 0x40, 0x00, 
  0x00, 0x00, 0xc0, 0x01, 0x8f, 0x81, 0x86, 0x38, 0x06, 0x38, 0x1c, 0x3c, 0x0c, 0x00, 0x60, 0x60, 
  0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x10, 0xc2, 0x06, 0x00, 
  0xc3, 0x04, 0x11, 0x00, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x8f, 0x01, 0x86, 0x38, 0x06, 0x30, 0x0c, 
  0x38, 0x0c, 0x00, 0x60, 0x60, 0x1c, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xc8, 0x43, 0x02, 0x00, 0x81, 0x84, 0x24, 0x00, 0x80, 0x00, 0x00, 0xc0, 0x01, 0x8e, 0x01, 
  0x86, 0x18, 0x0e, 0x70, 0x0e, 0x38, 0x0c, 0x00, 0x60, 0x60, 0x0c, 0x06, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x24, 0xc3, 0x03, 0x01, 0x81, 0x84, 0x48, 0x20, 0x40, 0x00, 
  0x00, 0xc0, 0x01, 0x8e, 0x01, 0x86, 0x1c, 0x0c, 0x60, 0x0e, 0x38, 0x0c, 0x00, 0x60, 0x60, 0x0e, 
  0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x44, 0x22, 0xe2, 0x03, 0x01, 0x81, 
  0x8c, 0x80, 0x44, 0x20, 0x00, 0x00, 0xc0, 0x01, 0x8e, 0x01, 0x86, 0x0c, 0x1c, 0x7f, 0xfe, 0x30, 
  0x0f, 0x00, 0x60, 0x60, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x86, 
  0x11, 0xa6, 0x02, 0x02, 0x00, 0x4b, 0x10, 0xc6, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x8c, 0x01, 0x86, 
  0x0c, 0x18, 0x60, 0x00, 0x30, 0x07, 0xe0, 0x60, 0x60, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x11, 0x85, 0x90, 0xa7, 0x05, 0x3b, 0xc1, 0x92, 0x13, 0x42, 0x10, 0x00, 0x00, 
  0xc0, 0x01, 0x8c, 0x01, 0x86, 0x0e, 0x18, 0x60, 0x00, 0x30, 0x01, 0xf8, 0x60, 0x60, 0x07, 0x1c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x84, 0x01, 0x11, 0xcb, 0x84, 0xa5, 0x11, 
  0x00, 0x01, 0x10, 0x00, 0x00, 0xc0, 0x01, 0x8c, 0x01, 0x86, 0x06, 0x38, 0x60, 0x00, 0x30, 0x00, 
  0x3c, 0x60, 0x60, 0x03, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x84, 0x02, 
  0x10, 0xb9, 0x83, 0x7e, 0x20, 0x80, 0x02, 0x70, 0x00, 0x00, 0xc0, 0x01, 0x8c, 0x01, 0x86, 0x06, 
  0x30, 0x60, 0x00, 0x30, 0x00, 0x0c, 0x60, 0x60, 0x03, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x84, 0x38, 0x08, 0x31, 0x03, 0x18, 0x20, 0x38, 0x02, 0x00, 0x00, 0x00, 0xc0, 
  0x01, 0x8c, 0x01, 0x86, 0x03, 0x30, 0x70, 0x00, 0x30, 0x00, 0x0c, 0x60, 0x60, 0x03, 0xb0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x20, 0x0c, 0x03, 0x01, 0x00, 0x60, 0x00, 
  0x40, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x0c, 0x01, 0x86, 0x03, 0x60, 0x70, 0x00, 0x30, 0x00, 0x0c, 
  0x60, 0x60, 0x01, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x88, 
  0x03, 0x01, 0x80, 0xa2, 0x10, 0x44, 0x00, 0x00, 0x00, 0x60, 0x07, 0x0c, 0x01, 0x86, 0x03, 0x60, 
  0x38, 0x00, 0x30, 0x00, 0x0c, 0x60, 0x70, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x48, 0x11, 0x0a, 0x03, 0x02, 0x80, 0xa1, 0x10, 0x20, 0x00, 0x00, 0x00, 0x78, 0x0e, 
  0x0c, 0x01, 0x86, 0x01, 0xe0, 0x3c, 0x04, 0x30, 0x00, 0x38, 0x60, 0x70, 0x00, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x05, 0x01, 0x01, 0x45, 0x01, 0x21, 0x40, 0x28, 
  0x00, 0x00, 0x00, 0x3f, 0xfc, 0x0c, 0x01, 0x86, 0x01, 0xc0, 0x1f, 0xfc, 0x30, 0x0f, 0xf0, 0x60, 
  0x3f, 0x80, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x10, 0x80, 
  0xbc, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x0c, 0x01, 0x86, 0x00, 0xc0, 0x07, 
  0xf0, 0x30, 0x0f, 0xe0, 0x60, 0x1f, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x10, 0x40, 0x28, 0x04, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x10, 0x0f, 0x90, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 
  0x18, 0x18, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x03, 0x80, 0x18, 0x00, 0x30, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x1c, 0x00, 0x50, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe6, 0x01, 0xce, 
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x4e, 0x42, 0x82, 0x84, 0xc4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x42, 0x44, 0x04, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x10, 0x88, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x24, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xcf, 0x7c, 0x33, 0xc7, 
  0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x02, 0x08, 0x10, 0x12, 0x28, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x08, 0x10, 0x12, 0x48, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xcc, 0x10, 0x11, 0x88, 0x82, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
  0x03, 0x10, 0x11, 0x47, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x10, 0x12, 0x20, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x10, 0x12, 0x21, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xce, 
  0x10, 0x11, 0xc6, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
