# 0x0A. 2048 (single line)
The goal of this task is to reproduce the 2048 game(NSFW !!) mechanics on a single horizontal line.

Given an array of integers, we want to be able to slide & merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeros, should be merged (See example)

### <li>Write a function that slides and merges an array of integers</li>
### <li>Prototype: int slide_line(int *line, size_t size, int direction);</li>
### <li>Where line points to an array of integers containing size elements, that must be slided & merged to the direction represented by direction. direction can be either:</li>
         o SLIDE_LEFT
         o SLIDE_RIGHT
         o If it is something else, the function must fail
         o Both macros SLIDE_LEFT and SLIDE_RIGHT must be defined in slide_line.h
### <li>Your function must return 1 upon success, or 0 upon failure</li>
### <li>You are not allowed to allocate memory dynamically (malloc, calloc, …)</li>