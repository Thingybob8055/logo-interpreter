#ifndef _HEADING_H_
#define _HEADING_H_

typedef enum Direction { FORWARDS, BACKWARDS } Direction;

typedef enum Heading {
  HEADING_UP = 270,
  HEADING_DOWN = 90,
  HEADING_LEFT = 180,
  HEADING_RIGHT = 0
} Heading;

#endif /* _HEADING_H_ */