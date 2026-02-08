# Notes

Implementation notes.

## Edax

Important things about edax v 4.6

* `play_go()` is defined in `src/play.c`
* `setboard` option can be used with SGF strings to bring the board to a specific state.
* `setboard` is set using `play_set_board(play, param)` in LC 416 of `edax.c`.:W

## TODOs

- [ ] Spot and modify the definition of `play_go()` to build a utility that reads an SGF string and gets a suggestion by Edax for that position at a specific depth.
- [ ] Find where depth is modified as a search parameter.
