# Notes

Implementation notes.

## Edax

Important things about edax v 4.6

* `play_go()` is defined in `src/play.c`, LC 215.
* `setboard` option can be used with SGF strings to bring the board to a specific state.
* `setboard` is set using `play_set_board(play, param)` in LC 416 of `edax.c`.
* `play_go()` uses `search_run()`.
* `search_run()` is defined in `src/root.c`, LC 837.
* `search_run()` is what we are looking for, since it searches for the best move in a given board.
    * the board has been set using `search_set_board()`;
    * all search options are also set using `search_set_board()`;
    * it returns the search result, which is an integer, essentially a status code - useless for our purposes;
    * while searching, this function most probably modifies a `Search* search` object, which contains a `result` field.
* `struct Search` is defined in `src/search.h`, LC 66.
    * it contains a `struct` field which has a `depth` parameter, which is maybe useful;
    * it also has a `Result* result` field which contains, most probably, the result.
* `Result` is also defined in `src/search.h` in LC 43.
    * it contains an `int move` field, which is the best move found - an integer, most probably the index of that move in some move list (there is such a field mentioned in `search_run()`).

## TODOs

- [x] Spot and modify the definition of `play_go()` to build a utility that reads an SGF string and gets a suggestion by Edax for that position at a specific depth.
- [x] Find where depth is modified as a search parameter.
- [x] Edit `agent.c` such that the Agent class is actually a subset of `Play`, properly joining search into its own thread and making any adjustments needed? (maybe this is why the current implemenation keeps failing).
- [ ] There is a but in play force go, where some parameters are not actually set.
