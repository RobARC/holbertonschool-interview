# 0x0B. Menger sponge

## 2D Menger sponge

Write a function that draws a 2D Menger Sponge

##### <li>Prototype: void menger(int level)</li>
##### <li>Where level is the level of the Menger Sponge to draw</li>
##### <li>If level is lower than 0, your function must do nothing</li>
##### <li>You’re allowed to use the math library. Your program will be compiled using the ld flag -lm</li>

Format:

##### <li>First, read Menger sponge</li>
##### <li>Here, we will only draw a 2D version of the Menger sponge, but the principle is the same</li>
##### <li>A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty</li>
##### <li>A level 0 sponge is represented by the # character</li>
##### <li>Examples:
#####   &nbsp;&nbsp;&nbsp;&nbsp; o &nbsp;&nbsp;&nbsp;&nbsp; A level 0 sponge is a simple 1x1 square
#####   &nbsp;&nbsp;&nbsp;&nbsp; o &nbsp;&nbsp;&nbsp;&nbsp; A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
#####   &nbsp;&nbsp;&nbsp;&nbsp; o &nbsp;&nbsp;&nbsp;&nbsp; A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty

##### <li>TIP: The size of a level N Menger sponge is calculated as follows: 3^N</li>
