/* xsoldier, a shoot 'em up game with "not shooting" bonus
 * Copyright (C) 1997 Yuusuke HASHIMOTO <s945750@educ.info.kanagawa-u.ac.jp>
 * Copyright (C) 2002 Oohara Yuuma  <oohara@libra.interq.or.jp>
 *
 * This is a copyleft program.  See the file LICENSE for details.
 */
/* $Id: sin.c,v 1.2 2002/04/07 13:38:23 oohara Exp $ */
#include "sin.h"

static double dsin_table[] = {
  0.0000,
  0.0175,  0.0349,  0.0523,  0.0698,  0.0872,  0.1045,  0.1219,  0.1392,  0.1564,  0.1736,
  0.1908,  0.2079,  0.2250,  0.2419,  0.2588,  0.2756,  0.2924,  0.3090,  0.3256,  0.3420,
  0.3584,  0.3746,  0.3907,  0.4067,  0.4226,  0.4384,  0.4540,  0.4695,  0.4848,  0.5000,
  0.5150,  0.5299,  0.5446,  0.5592,  0.5736,  0.5878,  0.6018,  0.6157,  0.6293,  0.6428,
  0.6561,  0.6691,  0.6820,  0.6947,  0.7071,  0.7193,  0.7314,  0.7431,  0.7547,  0.7660,
  0.7771,  0.7880,  0.7986,  0.8090,  0.8192,  0.8290,  0.8387,  0.8480,  0.8572,  0.8660,
  0.8746,  0.8829,  0.8910,  0.8988,  0.9063,  0.9135,  0.9205,  0.9272,  0.9336,  0.9397,
  0.9455,  0.9511,  0.9563,  0.9613,  0.9659,  0.9703,  0.9744,  0.9781,  0.9816,  0.9848,
  0.9877,  0.9903,  0.9925,  0.9945,  0.9962,  0.9976,  0.9986,  0.9994,  0.9998,  1.0000,
  0.9998,  0.9994,  0.9986,  0.9976,  0.9962,  0.9945,  0.9925,  0.9903,  0.9877,  0.9848,
  0.9816,  0.9781,  0.9744,  0.9703,  0.9659,  0.9613,  0.9563,  0.9511,  0.9455,  0.9397,
  0.9336,  0.9272,  0.9205,  0.9135,  0.9063,  0.8988,  0.8910,  0.8829,  0.8746,  0.8660,
  0.8572,  0.8480,  0.8387,  0.8290,  0.8192,  0.8090,  0.7986,  0.7880,  0.7771,  0.7660,
  0.7547,  0.7431,  0.7314,  0.7193,  0.7071,  0.6947,  0.6820,  0.6691,  0.6561,  0.6428,
  0.6293,  0.6157,  0.6018,  0.5878,  0.5736,  0.5592,  0.5446,  0.5299,  0.5150,  0.5000,
  0.4848,  0.4695,  0.4540,  0.4384,  0.4226,  0.4067,  0.3907,  0.3746,  0.3584,  0.3420,
  0.3256,  0.3090,  0.2924,  0.2756,  0.2588,  0.2419,  0.2250,  0.2079,  0.1908,  0.1736,
  0.1564,  0.1392,  0.1219,  0.1045,  0.0872,  0.0698,  0.0523,  0.0349,  0.0175,  0.0000,
 -0.0175, -0.0349, -0.0523, -0.0698, -0.0872, -0.1045, -0.1219, -0.1392, -0.1564, -0.1736,
 -0.1908, -0.2079, -0.2250, -0.2419, -0.2588, -0.2756, -0.2924, -0.3090, -0.3256, -0.3420,
 -0.3584, -0.3746, -0.3907, -0.4067, -0.4226, -0.4384, -0.4540, -0.4695, -0.4848, -0.5000,
 -0.5150, -0.5299, -0.5446, -0.5592, -0.5736, -0.5878, -0.6018, -0.6157, -0.6293, -0.6428,
 -0.6561, -0.6691, -0.6820, -0.6947, -0.7071, -0.7193, -0.7314, -0.7431, -0.7547, -0.7660,
 -0.7771, -0.7880, -0.7986, -0.8090, -0.8192, -0.8290, -0.8387, -0.8480, -0.8572, -0.8660,
 -0.8746, -0.8829, -0.8910, -0.8988, -0.9063, -0.9135, -0.9205, -0.9272, -0.9336, -0.9397,
 -0.9455, -0.9511, -0.9563, -0.9613, -0.9659, -0.9703, -0.9744, -0.9781, -0.9816, -0.9848,
 -0.9877, -0.9903, -0.9925, -0.9945, -0.9962, -0.9976, -0.9986, -0.9994, -0.9998, -1.0000,
 -0.9998, -0.9994, -0.9986, -0.9976, -0.9962, -0.9945, -0.9925, -0.9903, -0.9877, -0.9848,
 -0.9816, -0.9781, -0.9744, -0.9703, -0.9659, -0.9613, -0.9563, -0.9511, -0.9455, -0.9397,
 -0.9336, -0.9272, -0.9205, -0.9135, -0.9063, -0.8988, -0.8910, -0.8829, -0.8746, -0.8660,
 -0.8572, -0.8480, -0.8387, -0.8290, -0.8192, -0.8090, -0.7986, -0.7880, -0.7771, -0.7660,
 -0.7547, -0.7431, -0.7314, -0.7193, -0.7071, -0.6947, -0.6820, -0.6691, -0.6561, -0.6428,
 -0.6293, -0.6157, -0.6018, -0.5878, -0.5736, -0.5592, -0.5446, -0.5299, -0.5150, -0.5000,
 -0.4848, -0.4695, -0.4540, -0.4384, -0.4226, -0.4067, -0.3907, -0.3746, -0.3584, -0.3420,
 -0.3256, -0.3090, -0.2924, -0.2756, -0.2588, -0.2419, -0.2250, -0.2079, -0.1908, -0.1736,
 -0.1564, -0.1392, -0.1219, -0.1045, -0.0872, -0.0698, -0.0523, -0.0349, -0.0175, -0.0000,
};

static int isin_table[] = {
    0,
    4,    8,   13,   17,   22,   26,   31,   35,   40,   44,
   48,   53,   57,   61,   66,   70,   74,   79,   83,   87,
   91,   95,  100,  104,  108,  112,  116,  120,  124,  127,
  131,  135,  139,  143,  146,  150,  154,  157,  161,  164,
  167,  171,  174,  177,  181,  184,  187,  190,  193,  196,
  198,  201,  204,  207,  209,  212,  214,  217,  219,  221,
  223,  226,  228,  230,  232,  233,  235,  237,  238,  240,
  242,  243,  244,  246,  247,  248,  249,  250,  251,  252,
  252,  253,  254,  254,  255,  255,  255,  255,  255,  256,
  255,  255,  255,  255,  255,  254,  254,  253,  252,  252,
  251,  250,  249,  248,  247,  246,  244,  243,  242,  240,
  238,  237,  235,  233,  232,  230,  228,  226,  223,  221,
  219,  217,  214,  212,  209,  207,  204,  201,  198,  196,
  193,  190,  187,  184,  181,  177,  174,  171,  167,  164,
  161,  157,  154,  150,  146,  143,  139,  135,  131,  127,
  124,  120,  116,  112,  108,  104,  100,   95,   91,   87,
   83,   79,   74,   70,   66,   61,   57,   53,   48,   44,
   40,   35,   31,   26,   22,   17,   13,    8,    4,    0,
   -4,   -8,  -13,  -17,  -22,  -26,  -31,  -35,  -40,  -44,
  -48,  -53,  -57,  -61,  -66,  -70,  -74,  -79,  -83,  -87,
  -91,  -95, -100, -104, -108, -112, -116, -120, -124, -127,
 -131, -135, -139, -143, -146, -150, -154, -157, -161, -164,
 -167, -171, -174, -177, -181, -184, -187, -190, -193, -196,
 -198, -201, -204, -207, -209, -212, -214, -217, -219, -221,
 -223, -226, -228, -230, -232, -233, -235, -237, -238, -240,
 -242, -243, -244, -246, -247, -248, -249, -250, -251, -252,
 -252, -253, -254, -254, -255, -255, -255, -255, -255, -256,
 -255, -255, -255, -255, -255, -254, -254, -253, -252, -252,
 -251, -250, -249, -248, -247, -246, -244, -243, -242, -240,
 -238, -237, -235, -233, -232, -230, -228, -226, -223, -221,
 -219, -217, -214, -212, -209, -207, -204, -201, -198, -196,
 -193, -190, -187, -184, -181, -177, -174, -171, -167, -164,
 -161, -157, -154, -150, -146, -143, -139, -135, -131, -128,
 -124, -120, -116, -112, -108, -104, -100,  -95,  -91,  -87,
  -83,  -79,  -74,  -70,  -66,  -61,  -57,  -53,  -48,  -44,
  -40,  -35,  -31,  -26,  -22,  -17,  -13,   -8,   -4,    0,
};

/* table-based approximate sine */
double dsin(int theta)
{
    while(theta > 360)
	theta -= 360;

    return (dsin_table[theta]);
}

/* returns 256 * sin(theta) */
int isin(int theta)
{
    while(theta > 360)
	theta -= 360;

    return (isin_table[theta]);
}
