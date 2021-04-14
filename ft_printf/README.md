This project aims at realizing a function that mimics `printf`. It has been graded 101/100 from Deepthought, since it also admits the `#` flag. 

#### KNOWN ISSUES:
Under some conditions, the `u` type does not work correctly when used when the `0` value is passed. Although I have not been able to replicate this error, it can be found by testing with [this](https://github.com/Mazoise/42TESTERS-PRINTF) tester.

Also, the testing main (contained in the `tester` folder) only checks for errors in the `c`, `s` and `d` types.
