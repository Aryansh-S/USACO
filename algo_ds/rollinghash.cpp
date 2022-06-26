const int p = 31; // p = prime close to but > #char in alphabet; i.e., 53 for both upper and lower

//precompute powers modulo MOD for performance boost 

/*
#if (p == 31) 
  const ll p_pow[] = {1, 31, 961, 29791, 923521, 28629151,
887503681, 512613922, 891031477, 621975598, 281243405,
718545499, 274910315, 522219709, 188810867, 853136842,
447241920, 864499429, 799482117, 783945459, 302309061,
371580828, 519005591, 89173209, 764369465, 695453254,
559050727, 330572418, 247744888, 680091479, 82835702,
567906748, 605109069, 758381013, 509811242, 804148397,
928600139, 786604113, 384727335, 926547308, 722966352,
411956758, 770659414, 890441673, 603691674, 714441768,
147694654, 578534246, 934561507, 971406521, 113601941,
521660150, 171464538, 315400643, 777419870, 100015802,
100489841, 115185050, 570736529, 692832280, 477800533,
811816425, 166309000, 155578965, 822947887, 511384322,
852913877, 440330005, 650230064, 157131844, 871087136,
3701027, 114731837, 556686926, 257294587, 976132148,
260096378, 62987662, 952617515, 531142762, 465425510,
428190712, 273911981, 491271355, 229411900, 111768851,
464834360, 409865062, 705816838, 880321831, 289976572,
989273676, 667483746, 691995986, 451875419, 8137891,
252274621, 820513202, 435909087, 513181606, 908629681}; 
#else 
  const ll p_pow[] = {1, 53, 2809, 148877, 7890481, 418195493,
164360975, 711131619, 689975548, 568703792, 141300766,
488940549, 913848922, 433992530, 1603929, 85008237,
505436533, 788136067, 771211264, 874196712, 332425414,
618546823, 782981395, 498013648, 394723162, 920327446,
777354302, 199777719, 588219037, 175608744, 307263369,
284958445, 102797480, 448266405, 758119304, 180322832,
557110033, 526831546, 922071749, 869802361, 99524811,
274814948, 565192146, 955183535, 624727005, 110531034,
858144767, 481672336, 528633633, 17582353, 931864709,
388829234, 607949262, 221310662, 729465009, 661645211,
67195938, 561384693, 753388526, 929591605, 268354722,
222800168, 808408827, 845667537, 820379153, 480094808,
445024649, 586306236, 74230291, 934205402, 512885963,
182955850, 696659987, 922979059, 917889791, 648158587,
352404873, 677458143, 905281334, 979910373, 935249412,
568218493, 115579919, 125735665, 663990203, 191480514,
148467172, 868760067, 44283229, 347011123, 391589393,
754237689, 974597244, 653653575, 643639237, 112879323,
982604084, 78016088, 134852636, 147189659, 801051878}; 
#endif
*/

ll p_pow[102]; 

void precomp(int p) { //fill p_pow for a value of p
  p_pow[0] = 1; 
  F0R(i, sizeof(p_pow) / sizeof(p_pow[0]) - 1) p_pow[i + 1] = (p_pow[i] * p) % MOD;  
}

ll roll(const str& s) { //get rolling hash
  ll ret = 0;
  F0R(i, sz(s)) ret = (ret + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
  return ret; 
}