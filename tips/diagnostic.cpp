// Tips / What to Look For

// // // // // // // // // // // // // // // // //
// do something! stay organized!                //  
// int overflow : ll                            //
// segfault : exit(9), goto pt; pt: <do smth>;  //
// wrong ans : what(x)                          //
// tle : if(TIME > 2000)                        //
// index carefully!                             //
// sort global array : use a + n, not all(a)    //
// bsearch if monotonic                         //
// try amortized, use stack/queue, heuristic    //
// if using double/ld use pres(d)               //
// runtime : 1e7 usually, 2e8 edgy              //
// careful using ++, etc. for macros like all() //
// // // // // // // // // // // // // // // // //
  
//gp hash tables: init with ({},{},{},{},{1<<16}) suffix to control sz (always power of 2), speeds up 
//lb: first el in [left_it,right_it) >= val, use set::
//rb: first el in [left_it,right_it) > val, use set::
