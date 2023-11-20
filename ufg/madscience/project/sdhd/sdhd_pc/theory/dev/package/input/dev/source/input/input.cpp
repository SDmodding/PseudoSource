// File Line: 32
// RVA: 0x146A9B0
char *UFG::_dynamic_initializer_for__testController__()
{
  signed int v0; // ecx
  char *result; // rax

  v0 = 21;
  result = (char *)&UFG::testController.testInput[0].fDataY;
  do
  {
    --v0;
    *(result - 12) = 0;
    *(_QWORD *)(result - 4) = 0i64;
    result += 16;
  }
  while ( v0 >= 0 );
  return result;
}

// File Line: 84
// RVA: 0x146A930
__int64 UFG::_dynamic_initializer_for__gMoveThatMatchedRefMove__()
{
  UFG::qMemSet(UFG::gMoveThatMatchedRefMove.mR, 0, 0x100u);
  UFG::qMemSet(UFG::gMoveThatMatchedRefMove.mTheta, 0, 0x100u);
  UFG::qMemSet(UFG::gMoveThatMatchedRefMove.mOctantHistory, -1, 0x40u);
  *(_QWORD *)&UFG::gMoveThatMatchedRefMove.mIndex = 0i64;
  *(_QWORD *)&UFG::gMoveThatMatchedRefMove.mEndTrim = 0i64;
  UFG::gMoveThatMatchedRefMove.mLocked = 0;
  UFG::gMoveThatMatchedRefMove.mOctantIndex = 0;
  return atexit(UFG::_dynamic_atexit_destructor_for__gMoveThatMatchedRefMove__);
}

// File Line: 100
// RVA: 0x1B7D90
const char *__fastcall UFG::MapInputVKeyToString(int key)
{
  const char *v2; // [rsp+0h] [rbp-100h]
  const char *v3; // [rsp+8h] [rbp-F8h]
  const char *v4; // [rsp+10h] [rbp-F0h]
  const char *v5; // [rsp+18h] [rbp-E8h]
  const char *v6; // [rsp+20h] [rbp-E0h]
  const char *v7; // [rsp+28h] [rbp-D8h]
  const char *v8; // [rsp+30h] [rbp-D0h]
  const char *v9; // [rsp+38h] [rbp-C8h]
  const char *v10; // [rsp+40h] [rbp-C0h]
  const char *v11; // [rsp+48h] [rbp-B8h]
  const char *v12; // [rsp+50h] [rbp-B0h]
  const char *v13; // [rsp+58h] [rbp-A8h]
  const char *v14; // [rsp+60h] [rbp-A0h]
  const char *v15; // [rsp+68h] [rbp-98h]
  const char *v16; // [rsp+70h] [rbp-90h]
  const char *v17; // [rsp+78h] [rbp-88h]
  const char *v18; // [rsp+80h] [rbp-80h]
  const char *v19; // [rsp+88h] [rbp-78h]
  const char *v20; // [rsp+90h] [rbp-70h]
  const char *v21; // [rsp+98h] [rbp-68h]
  const char *v22; // [rsp+A0h] [rbp-60h]
  const char *v23; // [rsp+A8h] [rbp-58h]
  const char *v24; // [rsp+B0h] [rbp-50h]
  const char *v25; // [rsp+B8h] [rbp-48h]
  const char *v26; // [rsp+C0h] [rbp-40h]
  const char *v27; // [rsp+C8h] [rbp-38h]
  const char *v28; // [rsp+D0h] [rbp-30h]
  const char *v29; // [rsp+D8h] [rbp-28h]
  const char *v30; // [rsp+E0h] [rbp-20h]
  const char *v31; // [rsp+E8h] [rbp-18h]
  const char *v32; // [rsp+F0h] [rbp-10h]
  const char *v33; // [rsp+F8h] [rbp-8h]
  const char *v34; // [rsp+100h] [rbp+0h]
  const char *v35; // [rsp+108h] [rbp+8h]
  const char *v36; // [rsp+110h] [rbp+10h]
  const char *v37; // [rsp+118h] [rbp+18h]
  const char *v38; // [rsp+120h] [rbp+20h]
  const char *v39; // [rsp+128h] [rbp+28h]
  const char *v40; // [rsp+130h] [rbp+30h]
  const char *v41; // [rsp+138h] [rbp+38h]
  const char *v42; // [rsp+140h] [rbp+40h]
  const char *v43; // [rsp+148h] [rbp+48h]
  const char *v44; // [rsp+150h] [rbp+50h]
  const char *v45; // [rsp+158h] [rbp+58h]
  const char *v46; // [rsp+160h] [rbp+60h]
  const char *v47; // [rsp+168h] [rbp+68h]
  const char *v48; // [rsp+170h] [rbp+70h]
  const char *v49; // [rsp+178h] [rbp+78h]
  const char *v50; // [rsp+180h] [rbp+80h]
  const char *v51; // [rsp+188h] [rbp+88h]
  const char *v52; // [rsp+190h] [rbp+90h]
  const char *v53; // [rsp+198h] [rbp+98h]
  const char *v54; // [rsp+1A0h] [rbp+A0h]
  const char *v55; // [rsp+1A8h] [rbp+A8h]
  const char *v56; // [rsp+1B0h] [rbp+B0h]
  const char *v57; // [rsp+1B8h] [rbp+B8h]
  const char *v58; // [rsp+1C0h] [rbp+C0h]
  const char *v59; // [rsp+1C8h] [rbp+C8h]
  const char *v60; // [rsp+1D0h] [rbp+D0h]
  const char *v61; // [rsp+1D8h] [rbp+D8h]
  const char *v62; // [rsp+1E0h] [rbp+E0h]
  const char *v63; // [rsp+1E8h] [rbp+E8h]
  const char *v64; // [rsp+1F0h] [rbp+F0h]
  const char *v65; // [rsp+1F8h] [rbp+F8h]
  const char *v66; // [rsp+200h] [rbp+100h]
  const char *v67; // [rsp+208h] [rbp+108h]
  const char *v68; // [rsp+210h] [rbp+110h]
  const char *v69; // [rsp+218h] [rbp+118h]
  const char *v70; // [rsp+220h] [rbp+120h]
  const char *v71; // [rsp+228h] [rbp+128h]
  const char *v72; // [rsp+230h] [rbp+130h]
  const char *v73; // [rsp+238h] [rbp+138h]
  const char *v74; // [rsp+240h] [rbp+140h]
  const char *v75; // [rsp+248h] [rbp+148h]
  const char *v76; // [rsp+250h] [rbp+150h]
  const char *v77; // [rsp+258h] [rbp+158h]
  const char *v78; // [rsp+260h] [rbp+160h]
  const char *v79; // [rsp+268h] [rbp+168h]
  const char *v80; // [rsp+270h] [rbp+170h]
  const char *v81; // [rsp+278h] [rbp+178h]
  const char *v82; // [rsp+280h] [rbp+180h]
  const char *v83; // [rsp+288h] [rbp+188h]
  const char *v84; // [rsp+290h] [rbp+190h]
  const char *v85; // [rsp+298h] [rbp+198h]
  const char *v86; // [rsp+2A0h] [rbp+1A0h]
  const char *v87; // [rsp+2A8h] [rbp+1A8h]
  const char *v88; // [rsp+2B0h] [rbp+1B0h]
  const char *v89; // [rsp+2B8h] [rbp+1B8h]
  const char *v90; // [rsp+2C0h] [rbp+1C0h]
  const char *v91; // [rsp+2C8h] [rbp+1C8h]
  const char *v92; // [rsp+2D0h] [rbp+1D0h]
  const char *v93; // [rsp+2D8h] [rbp+1D8h]
  const char *v94; // [rsp+2E0h] [rbp+1E0h]
  const char *v95; // [rsp+2E8h] [rbp+1E8h]
  const char *v96; // [rsp+2F0h] [rbp+1F0h]
  const char *v97; // [rsp+2F8h] [rbp+1F8h]
  const char *v98; // [rsp+300h] [rbp+200h]
  const char *v99; // [rsp+308h] [rbp+208h]
  const char *v100; // [rsp+310h] [rbp+210h]
  const char *v101; // [rsp+318h] [rbp+218h]
  const char *v102; // [rsp+320h] [rbp+220h]
  const char *v103; // [rsp+328h] [rbp+228h]
  const char *v104; // [rsp+330h] [rbp+230h]
  const char *v105; // [rsp+338h] [rbp+238h]
  const char *v106; // [rsp+340h] [rbp+240h]
  const char *v107; // [rsp+348h] [rbp+248h]
  const char *v108; // [rsp+350h] [rbp+250h]
  const char *v109; // [rsp+358h] [rbp+258h]
  const char *v110; // [rsp+360h] [rbp+260h]
  const char *v111; // [rsp+368h] [rbp+268h]
  const char *v112; // [rsp+370h] [rbp+270h]
  const char *v113; // [rsp+378h] [rbp+278h]
  const char *v114; // [rsp+380h] [rbp+280h]
  const char *v115; // [rsp+388h] [rbp+288h]
  const char *v116; // [rsp+390h] [rbp+290h]
  const char *v117; // [rsp+398h] [rbp+298h]
  const char *v118; // [rsp+3A0h] [rbp+2A0h]
  const char *v119; // [rsp+3A8h] [rbp+2A8h]
  const char *v120; // [rsp+3B0h] [rbp+2B0h]
  const char *v121; // [rsp+3B8h] [rbp+2B8h]
  const char *v122; // [rsp+3C0h] [rbp+2C0h]
  const char *v123; // [rsp+3C8h] [rbp+2C8h]
  const char *v124; // [rsp+3D0h] [rbp+2D0h]
  const char *v125; // [rsp+3D8h] [rbp+2D8h]
  const char *v126; // [rsp+3E0h] [rbp+2E0h]
  const char *v127; // [rsp+3E8h] [rbp+2E8h]
  const char *v128; // [rsp+3F0h] [rbp+2F0h]
  const char *v129; // [rsp+3F8h] [rbp+2F8h]
  const char *v130; // [rsp+400h] [rbp+300h]
  const char *v131; // [rsp+408h] [rbp+308h]
  const char *v132; // [rsp+410h] [rbp+310h]
  const char *v133; // [rsp+418h] [rbp+318h]
  const char *v134; // [rsp+420h] [rbp+320h]
  const char *v135; // [rsp+428h] [rbp+328h]
  const char *v136; // [rsp+430h] [rbp+330h]
  const char *v137; // [rsp+438h] [rbp+338h]
  const char *v138; // [rsp+440h] [rbp+340h]
  const char *v139; // [rsp+448h] [rbp+348h]
  const char *v140; // [rsp+450h] [rbp+350h]
  const char *v141; // [rsp+458h] [rbp+358h]
  const char *v142; // [rsp+460h] [rbp+360h]
  const char *v143; // [rsp+468h] [rbp+368h]
  const char *v144; // [rsp+470h] [rbp+370h]
  const char *v145; // [rsp+478h] [rbp+378h]
  const char *v146; // [rsp+480h] [rbp+380h]
  const char *v147; // [rsp+488h] [rbp+388h]
  const char *v148; // [rsp+490h] [rbp+390h]
  const char *v149; // [rsp+498h] [rbp+398h]
  const char *v150; // [rsp+4A0h] [rbp+3A0h]
  const char *v151; // [rsp+4A8h] [rbp+3A8h]
  const char *v152; // [rsp+4B0h] [rbp+3B0h]
  const char *v153; // [rsp+4B8h] [rbp+3B8h]
  const char *v154; // [rsp+4C0h] [rbp+3C0h]
  const char *v155; // [rsp+4C8h] [rbp+3C8h]
  const char *v156; // [rsp+4D0h] [rbp+3D0h]
  const char *v157; // [rsp+4D8h] [rbp+3D8h]
  const char *v158; // [rsp+4E0h] [rbp+3E0h]
  const char *v159; // [rsp+4E8h] [rbp+3E8h]
  const char *v160; // [rsp+4F0h] [rbp+3F0h]
  const char *v161; // [rsp+4F8h] [rbp+3F8h]
  const char *v162; // [rsp+500h] [rbp+400h]
  const char *v163; // [rsp+508h] [rbp+408h]
  const char *v164; // [rsp+510h] [rbp+410h]
  const char *v165; // [rsp+518h] [rbp+418h]
  const char *v166; // [rsp+520h] [rbp+420h]
  const char *v167; // [rsp+528h] [rbp+428h]
  const char *v168; // [rsp+530h] [rbp+430h]
  const char *v169; // [rsp+538h] [rbp+438h]
  const char *v170; // [rsp+540h] [rbp+440h]
  const char *v171; // [rsp+548h] [rbp+448h]
  const char *v172; // [rsp+550h] [rbp+450h]
  const char *v173; // [rsp+558h] [rbp+458h]
  const char *v174; // [rsp+560h] [rbp+460h]
  const char *v175; // [rsp+568h] [rbp+468h]
  const char *v176; // [rsp+570h] [rbp+470h]
  const char *v177; // [rsp+578h] [rbp+478h]
  const char *v178; // [rsp+580h] [rbp+480h]
  const char *v179; // [rsp+588h] [rbp+488h]
  const char *v180; // [rsp+590h] [rbp+490h]
  const char *v181; // [rsp+598h] [rbp+498h]
  const char *v182; // [rsp+5A0h] [rbp+4A0h]
  const char *v183; // [rsp+5A8h] [rbp+4A8h]
  const char *v184; // [rsp+5B0h] [rbp+4B0h]
  const char *v185; // [rsp+5B8h] [rbp+4B8h]
  const char *v186; // [rsp+5C0h] [rbp+4C0h]
  const char *v187; // [rsp+5C8h] [rbp+4C8h]
  const char *v188; // [rsp+5D0h] [rbp+4D0h]
  const char *v189; // [rsp+5D8h] [rbp+4D8h]
  const char *v190; // [rsp+5E0h] [rbp+4E0h]
  const char *v191; // [rsp+5E8h] [rbp+4E8h]
  const char *v192; // [rsp+5F0h] [rbp+4F0h]
  const char *v193; // [rsp+5F8h] [rbp+4F8h]
  const char *v194; // [rsp+600h] [rbp+500h]
  const char *v195; // [rsp+608h] [rbp+508h]
  const char *v196; // [rsp+610h] [rbp+510h]
  const char *v197; // [rsp+618h] [rbp+518h]
  const char *v198; // [rsp+620h] [rbp+520h]
  const char *v199; // [rsp+628h] [rbp+528h]
  const char *v200; // [rsp+630h] [rbp+530h]
  const char *v201; // [rsp+638h] [rbp+538h]
  const char *v202; // [rsp+640h] [rbp+540h]
  const char *v203; // [rsp+648h] [rbp+548h]
  const char *v204; // [rsp+650h] [rbp+550h]
  const char *v205; // [rsp+658h] [rbp+558h]
  const char *v206; // [rsp+660h] [rbp+560h]
  const char *v207; // [rsp+668h] [rbp+568h]
  const char *v208; // [rsp+670h] [rbp+570h]
  const char *v209; // [rsp+678h] [rbp+578h]
  const char *v210; // [rsp+680h] [rbp+580h]
  const char *v211; // [rsp+688h] [rbp+588h]
  const char *v212; // [rsp+690h] [rbp+590h]
  const char *v213; // [rsp+698h] [rbp+598h]
  const char *v214; // [rsp+6A0h] [rbp+5A0h]
  const char *v215; // [rsp+6A8h] [rbp+5A8h]
  const char *v216; // [rsp+6B0h] [rbp+5B0h]
  const char *v217; // [rsp+6B8h] [rbp+5B8h]
  const char *v218; // [rsp+6C0h] [rbp+5C0h]
  const char *v219; // [rsp+6C8h] [rbp+5C8h]
  const char *v220; // [rsp+6D0h] [rbp+5D0h]
  const char *v221; // [rsp+6D8h] [rbp+5D8h]
  const char *v222; // [rsp+6E0h] [rbp+5E0h]
  const char *v223; // [rsp+6E8h] [rbp+5E8h]
  const char *v224; // [rsp+6F0h] [rbp+5F0h]
  const char *v225; // [rsp+6F8h] [rbp+5F8h]
  const char *v226; // [rsp+700h] [rbp+600h]
  const char *v227; // [rsp+708h] [rbp+608h]
  const char *v228; // [rsp+710h] [rbp+610h]
  const char *v229; // [rsp+718h] [rbp+618h]
  const char *v230; // [rsp+720h] [rbp+620h]
  const char *v231; // [rsp+728h] [rbp+628h]
  const char *v232; // [rsp+730h] [rbp+630h]
  const char *v233; // [rsp+738h] [rbp+638h]
  const char *v234; // [rsp+740h] [rbp+640h]
  const char *v235; // [rsp+748h] [rbp+648h]
  const char *v236; // [rsp+750h] [rbp+650h]
  const char *v237; // [rsp+758h] [rbp+658h]
  const char *v238; // [rsp+760h] [rbp+660h]
  const char *v239; // [rsp+768h] [rbp+668h]
  const char *v240; // [rsp+770h] [rbp+670h]
  const char *v241; // [rsp+778h] [rbp+678h]
  const char *v242; // [rsp+780h] [rbp+680h]
  const char *v243; // [rsp+788h] [rbp+688h]
  const char *v244; // [rsp+790h] [rbp+690h]
  const char *v245; // [rsp+798h] [rbp+698h]
  const char *v246; // [rsp+7A0h] [rbp+6A0h]
  const char *v247; // [rsp+7A8h] [rbp+6A8h]
  const char *v248; // [rsp+7B0h] [rbp+6B0h]
  const char *v249; // [rsp+7B8h] [rbp+6B8h]
  const char *v250; // [rsp+7C0h] [rbp+6C0h]
  const char *v251; // [rsp+7C8h] [rbp+6C8h]
  const char *v252; // [rsp+7D0h] [rbp+6D0h]
  const char *v253; // [rsp+7D8h] [rbp+6D8h]
  const char *v254; // [rsp+7E0h] [rbp+6E0h]
  const char *v255; // [rsp+7E8h] [rbp+6E8h]
  const char *v256; // [rsp+7F0h] [rbp+6F0h]
  const char *v257; // [rsp+7F8h] [rbp+6F8h]

  v2 = "0x00";
  v3 = "LBUTTON";
  v4 = "RBUTTON";
  v5 = "CANCEL";
  v6 = "MBUTTON";
  v7 = "XBUTTON1";
  v8 = "XBUTTON2";
  v9 = "0x07";
  v10 = "BACK";
  v11 = "TAB";
  v12 = "0x0a";
  v13 = "0x0b";
  v14 = "CLEAR";
  v15 = "RETURN";
  v16 = "0x0e";
  v17 = "0x0f";
  v18 = "SHIFT";
  v19 = "CTRL";
  v20 = "ALT";
  v21 = "PAUSE";
  v22 = "CAPITAL";
  v23 = "KANA";
  v24 = "0x16";
  v25 = "JUNJA";
  v26 = "FINAL";
  v27 = "KANJI";
  v28 = "0x1a";
  v29 = "ESCAPE";
  v30 = "CONVERT";
  v31 = "NONCONVERT";
  v32 = "ACCEPT";
  v33 = "MODECHANGE";
  v34 = "SPACE";
  v35 = "PAGE UP";
  v36 = "PAGE DOWN";
  v37 = "END";
  v38 = "HOME";
  v39 = "LEFT";
  v40 = "UP";
  v41 = "RIGHT";
  v42 = "DOWN";
  v43 = "SELECT";
  v44 = "PRINT";
  v45 = "EXECUTE";
  v46 = "SNAPSHOT";
  v47 = "INSERT";
  v48 = "DELETE";
  v49 = "HELP";
  v50 = "0";
  v51 = "1";
  v52 = "2";
  v53 = "3";
  v54 = "4";
  v55 = "5";
  v56 = "6";
  v57 = "7";
  v58 = "8";
  v59 = "9";
  v60 = "0x3a";
  v61 = "0x3b";
  v62 = "0x3c";
  v63 = "0x3d";
  v64 = "0x3e";
  v65 = "0x3f";
  v66 = "0x40";
  v67 = "A";
  v68 = "B";
  v69 = "C";
  v70 = "D";
  v71 = "E";
  v72 = "F";
  v73 = "G";
  v74 = "H";
  v75 = "I";
  v76 = "J";
  v77 = "K";
  v78 = "L";
  v79 = "M";
  v80 = "N";
  v81 = "O";
  v82 = "P";
  v83 = "Q";
  v84 = "R";
  v85 = "S";
  v86 = "T";
  v87 = "U";
  v88 = "V";
  v89 = "W";
  v90 = "X";
  v91 = "Y";
  v92 = "Z";
  v93 = "LWIN";
  v94 = "RWIN";
  v95 = "APPS";
  v96 = "0x5e";
  v97 = "SLEEP";
  v98 = "NUMPAD0";
  v99 = "NUMPAD1";
  v100 = "NUMPAD2";
  v101 = "NUMPAD3";
  v102 = "NUMPAD4";
  v103 = "NUMPAD5";
  v104 = "NUMPAD6";
  v105 = "NUMPAD7";
  v106 = "NUMPAD8";
  v107 = "NUMPAD9";
  v108 = "MULTIPLY";
  v109 = "ADD";
  v110 = "SEPARATOR";
  v111 = "SUBTRACT";
  v112 = "DECIMAL";
  v113 = "DIVIDE";
  v114 = "F1";
  v115 = "F2";
  v116 = "F3";
  v117 = "F4";
  v118 = "F5";
  v119 = "F6";
  v120 = "F7";
  v121 = "F8";
  v122 = "F9";
  v123 = "F10";
  v124 = "F11";
  v125 = "F12";
  v126 = "F13";
  v127 = "F14";
  v128 = "F15";
  v129 = "F16";
  v130 = "F17";
  v131 = "F18";
  v132 = "F19";
  v133 = "F20";
  v134 = "F21";
  v135 = "F22";
  v136 = "F23";
  v137 = "F24";
  v138 = "0x88";
  v139 = "0x89";
  v140 = "0x8a";
  v141 = "0x8b";
  v142 = "0x8c";
  v143 = "0x8d";
  v144 = "0x8e";
  v145 = "0x8f";
  v146 = "NUMLOCK";
  v147 = "SCROLL";
  v148 = "OEM_NEC_EQUAL";
  v149 = "OEM_FJ_MASSHOU";
  v150 = "OEM_FJ_TOUROKU";
  v151 = "OEM_FJ_LOYA";
  v152 = "OEM_FJ_ROYA";
  v153 = "0x97";
  v154 = "0x98";
  v155 = "0x99";
  v156 = "0x9a";
  v157 = "0x9b";
  v158 = "0x9c";
  v159 = "0x9d";
  v160 = "0x9e";
  v161 = "0x9f";
  v162 = "LSHIFT";
  v163 = "RSHIFT";
  v164 = "LCONTROL";
  v165 = "RCONTROL";
  v166 = "LMENU";
  v167 = "RMENU";
  v168 = "BROWSER_BACK";
  v169 = "BROWSER_FORWARD";
  v170 = "BROWSER_REFRESH";
  v171 = "BROWSER_STOP";
  v172 = "BROWSER_SEARCH";
  v173 = "BROWSER_FAVORITES";
  v174 = "BROWSER_HOME";
  v175 = "VOLUME_MUTE";
  v176 = "VOLUME_DOWN";
  v177 = "VOLUME_UP";
  v178 = "MEDIA_NEXT_TRACK";
  v179 = "MEDIA_PREV_TRACK";
  v180 = "MEDIA_STOP";
  v181 = "MEDIA_PLAY_PAUSE";
  v182 = "LAUNCH_MAIL";
  v183 = "LAUNCH_MEDIA_SELECT";
  v184 = "LAUNCH_APP1";
  v185 = "LAUNCH_APP2";
  v186 = "0xb8";
  v187 = "0xb9";
  v188 = "SEMI_COLON";
  v189 = "PLUS";
  v190 = "COMMA";
  v191 = "MINUS";
  v192 = "PERIOD";
  v193 = "QUESTION_MARK";
  v194 = "TILDE";
  v195 = "0xc1";
  v196 = "0xc2";
  v197 = "0xc3";
  v198 = "0xc4";
  v199 = "0xc5";
  v200 = "0xc6";
  v201 = "0xc7";
  v202 = "0xc8";
  v203 = "0xc9";
  v204 = "0xca";
  v205 = "0xcb";
  v206 = "0xcc";
  v207 = "0xcd";
  v208 = "0xce";
  v209 = "0xcf";
  v210 = "0xd0";
  v211 = "0xd1";
  v212 = "0xd2";
  v213 = "0xd3";
  v214 = "0xd4";
  v215 = "0xd5";
  v216 = "0xd6";
  v217 = "0xd7";
  v218 = "0xd8";
  v219 = "0xd9";
  v220 = "0xda";
  v221 = "OEM_4";
  v222 = "OEM_5";
  v223 = "OEM_6";
  v224 = "OEM_7";
  v225 = "OEM_8";
  v226 = "0xe0";
  v227 = "OEM_AX";
  v228 = "OEM_102";
  v229 = "ICO_HELP";
  v230 = "ICO_00";
  v231 = "PROCESSKEY";
  v232 = "ICO_CLEAR";
  v233 = "0xe7";
  v234 = "0xe8";
  v235 = "OEM_RESET";
  v236 = "OEM_JUMP";
  v237 = "OEM_PA1";
  v238 = "OEM_PA2";
  v239 = "OEM_PA3";
  v240 = "OEM_WSCTRL";
  v241 = "OEM_CUSEL";
  v242 = "OEM_ATTN";
  v243 = "OEM_FINISH";
  v244 = "OEM_COPY";
  v245 = "OEM_AUTO";
  v246 = "OEM_ENLW";
  v247 = "OEM_BACKTAB";
  v248 = "ATTN";
  v249 = "CRSEL";
  v250 = "EXSEL";
  v251 = "EREOF";
  v252 = "PLAY";
  v253 = "ZOOM";
  v254 = "NONAME";
  v255 = "PA1";
  v256 = "OEM_CLEAR";
  v257 = "0xff";
  return (&v2)[(unsigned __int8)key];
}5 = "OEM_RESET";
  v236 = "OEM_JUMP";
  v237 = "OEM_PA1";
  v238 = "OEM_PA2";
  v239 = "OEM_PA3";
  v240 = "OEM_WSCTRL";
  v241 = "OEM_CUSEL";
  v242 = "OEM_ATTN";
  v243 = "OEM_FINISH";
  v244 = "OEM_COPY";
  v245 = "OEM_AUTO";
  v246 = "OEM_ENLW";
  v247 = "OEM_BACKTAB";
  v248 = "ATTN";
  v249 = "CRSEL";
  v250 = "EXSEL";
  v251 = "EREOF";
  v252 = "PLAY";
  v253 = "ZOOM";
  v254 = 

// File Line: 650
// RVA: 0x1B7420
void __fastcall UFG::InputState::Clear(UFG::InputState *this)
{
  char *v1; // rcx

  v1 = this->mKeyState;
  *(_QWORD *)(v1 - 20) = 0i64;
  *((_WORD *)v1 - 6) = -1;
  *((_WORD *)v1 - 5) = -1;
  *((_WORD *)v1 - 4) = 0;
  *((_WORD *)v1 - 3) = -1;
  *((_WORD *)v1 - 2) = -1;
  *((_WORD *)v1 - 1) = 0;
  UFG::qMemSet(v1, 0, 256u);
}

// File Line: 665
// RVA: 0x1B79F0
__int64 __fastcall UFG::InputState::GetModiferKeys(UFG::InputState *this)
{
  UFG::InputState *v1; // rbx
  signed int v2; // esi
  signed int v3; // edi
  bool v4; // zf
  signed int v5; // eax
  int v6; // edi
  int v7; // edi

  v1 = this;
  v2 = 0;
  if ( UFG::InputState::IsPressed(this, 160) || (v3 = 0, UFG::InputState::IsPressed(v1, 161)) )
    v3 = 1;
  if ( UFG::InputState::IsPressed(v1, 162) || (v4 = UFG::InputState::IsPressed(v1, 163) == 0, v5 = 0, !v4) )
    v5 = 2;
  v6 = v5 | v3;
  if ( UFG::InputState::IsPressed(v1, 164) || UFG::InputState::IsPressed(v1, 165) )
    v2 = 4;
  v7 = v2 | (UFG::InputState::IsPressed(v1, 91) != 0 ? 8 : 0) | v6;
  return v7 | (UFG::InputState::IsPressed(v1, 93) != 0 ? 0x10 : 0);
}

// File Line: 678
// RVA: 0x1B7AC0
__int64 __fastcall UFG::InputState::GetMouseButtons(UFG::InputState *this)
{
  UFG::InputState *v1; // rbx
  _BOOL8 v2; // rdi

  v1 = this;
  v2 = UFG::InputState::IsPressed(this, 1) != 0;
  LODWORD(v2) = (UFG::InputState::IsPressed(v1, 2) != 0 ? 2 : 0) | v2;
  LODWORD(v2) = (UFG::InputState::IsPressed(v1, 4) != 0 ? 4 : 0) | v2;
  LODWORD(v2) = (UFG::InputState::IsPressed(v1, 8) != 0 ? 8 : 0) | v2;
  return (unsigned int)v2 | (UFG::InputState::IsPressed(v1, 16) != 0 ? 0x10 : 0);
}

// File Line: 700
// RVA: 0x1B7BB0
__int64 __fastcall UFG::InputState::GetRepeatCount(UFG::InputState *this, int key)
{
  return this->mKeyState[key] & 0x7F;
}

// File Line: 712
// RVA: 0x1B7D80
bool __fastcall UFG::InputState::IsMouseVisible(UFG::InputState *this)
{
  return this->mMouseX != -1;
}

// File Line: 717
// RVA: 0x1B7B90
__int64 __fastcall UFG::WayFinderClient::GetWayEdge(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  return this->m_CurrWayEdge;
}

// File Line: 722
// RVA: 0x1B7BA0
__int64 __fastcall UFG::WayFinderClient::GetWayNode(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  return this->m_CurrWayNode;
}

// File Line: 733
// RVA: 0x1B7B50
__int64 __fastcall UFG::InputState::GetMouseDeltaX(UFG::InputState *this)
{
  return (unsigned int)(this->mMouseX - this->mPrevMouseX);
}

// File Line: 738
// RVA: 0x1B7B60
__int64 __fastcall UFG::InputState::GetMouseDeltaY(UFG::InputState *this)
{
  return (unsigned int)(this->mMouseY - this->mPrevMouseY);
}

// File Line: 743
// RVA: 0x1B7B70
float __fastcall UFG::InputState::GetMouseWheelDelta(UFG::InputState *this)
{
  return (float)(this->mMouseWheel - this->mPrevMouseWheel) * 0.0083333338;
}

// File Line: 748
// RVA: 0x1B8BC0
void __fastcall UFG::InputState::ProcessMessage(UFG::InputState *this, UFG::InputMessage *msg)
{
  UFG::InputMessage *v2; // rsi
  UFG::InputState *v3; // rbx
  __int64 v4; // rdi
  int v5; // ebp
  __int16 v6; // r14
  __int16 v7; // dx
  int v8; // ecx
  _FILETIME v9; // rax
  __int16 v10; // ax
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl

  if ( !msg )
    return;
  v2 = msg;
  v3 = this;
  if ( !this->mLastMouseXYTime )
    this->mLastMouseXYTime = (unsigned __int64)UFG::qGetSystemTime();
  v4 = (unsigned __int8)v2->mVKey;
  v5 = v2->mMouseX;
  v6 = v2->mMouseY;
  v7 = v2->mMouseWheelDelta;
  switch ( v2->mMessageID )
  {
    case 0:
    case 1:
      UFG::InputState::Clear(v3);
      goto LABEL_23;
    case 2:
      if ( UFG::InputState::IsPressed(v3, (unsigned __int8)v2->mVKey) )
      {
        v8 = ((v3->mKeyState[(signed int)v4] & 0x7F) + 1) % 127;
        if ( v8 <= 1 )
        {
          v3->mKeyState[(signed int)v4] = -127;
          goto LABEL_23;
        }
      }
      else
      {
        LOBYTE(v8) = 0;
      }
      v3->mKeyState[(signed int)v4] = v8 | 0x80;
LABEL_23:
      v11 = v3->mKeyState[161];
      if ( v3->mKeyState[160] > v11 )
        v11 = v3->mKeyState[160];
      v3->mKeyState[16] = v11;
      v12 = v3->mKeyState[163];
      if ( v3->mKeyState[162] > v12 )
        v12 = v3->mKeyState[162];
      v3->mKeyState[17] = v12;
      v13 = v3->mKeyState[165];
      if ( v3->mKeyState[164] > v13 )
        v13 = v3->mKeyState[164];
      v3->mKeyState[18] = v13;
      return;
    case 3:
    case 8:
      v3->mKeyState[(unsigned __int8)v2->mVKey] = 0;
      goto LABEL_23;
    case 4:
      if ( v5 >= 0 || UFG::InputSystem::msCursorCurrentlyRestricted )
      {
        v9 = UFG::qGetSystemTime();
        if ( UFG::qGetSystemTimeDifference(v3->mLastMouseXYTime, *(_QWORD *)&v9) >= 0.5 )
        {
          v3->mPrevMouseX = v5;
          v3->mPrevMouseY = v6;
        }
        else
        {
          v3->mPrevMouseX = v3->mMouseX;
          v3->mPrevMouseY = v3->mMouseY;
        }
        v3->mMouseX = v5;
        v3->mMouseY = v6;
        v3->mLastMouseXYTime = (unsigned __int64)UFG::qGetSystemTime();
      }
      else
      {
        v3->mPrevMouseX = v3->mMouseX;
        v3->mPrevMouseY = v3->mMouseY;
      }
      goto LABEL_23;
    case 5:
      v3->mMouseX += v2->mMouseX;
      v3->mMouseY += v6;
      *(_DWORD *)&v3->mPrevMouseX = 0;
      v3->mLastMouseXYTime = (unsigned __int64)UFG::qGetSystemTime();
      goto LABEL_23;
    case 7:
      v3->mKeyState[(unsigned __int8)v2->mVKey] = -128;
      goto LABEL_23;
    case 9:
      v3->mKeyState[v4] = -128;
      goto LABEL_23;
    case 10:
      v10 = v3->mMouseWheel;
      v3->mPrevMouseWheel = v10;
      v3->mMouseWheel = v7 + v10;
      goto LABEL_23;
    default:
      goto LABEL_23;
  }
}

// File Line: 889
// RVA: 0x1B79D0
float __fastcall UFG::InputActionData::GetAxisVelX(UFG::InputActionData *this)
{
  return this->mAxisRawX[0] - this->mAxisRawX[1];
}

// File Line: 902
// RVA: 0x1B79E0
float __fastcall UFG::InputActionData::GetAxisVelY(UFG::InputActionData *this)
{
  return this->mAxisRawY[0] - this->mAxisRawY[1];
}

// File Line: 967
// RVA: 0x1B6A90
void __fastcall UFG::InputSystem::InputSystem(UFG::InputSystem *this)
{
  UFG::InputSystem *v1; // rbx
  UFG::JoyMoveWatcher *v2; // rax

  v1 = this;
  this->vfptr = (UFG::InputSystemVtbl *)&UFG::InputSystem::`vftable';
  *(_WORD *)&this->mbSentDisconnectMsg = 0;
  this->mKeyboardIndex = -1;
  v2 = (UFG::JoyMoveWatcher *)UFG::qMalloc(0x10ui64, "JoyMoveWatcher", 0i64);
  if ( v2 )
  {
    v2->mListOfMoves.mNode.mPrev = &v2->mListOfMoves.mNode;
    v2->mListOfMoves.mNode.mNext = &v2->mListOfMoves.mNode;
  }
  UFG::gJoyMoveWatcher = v2;
  UFG::qMemSet(v1->mControllers, 0, 0x28u);
  UFG::gInputSystem = v1;
  *(_DWORD *)v1->mIsAssigned = 0;
  v1->mIsAssigned[4] = 0;
}

// File Line: 983
// RVA: 0x1B6E00
void __fastcall UFG::InputSystem::~InputSystem(UFG::InputSystem *this)
{
  UFG::Controller *v1; // rcx

  this->vfptr = (UFG::InputSystemVtbl *)&UFG::InputSystem::`vftable';
  v1 = this->mControllers[0];
  if ( v1 )
    ((void (__fastcall *)(UFG::Controller *, signed __int64))v1->vfptr->~Controller)(v1, 1i64);
}

// File Line: 988
// RVA: 0x1B9050
void __fastcall UFG::InputSystem::SetShouldRestrictCursor(bool b_gamepad_window, bool b_keyboard_window, bool b_gamepad_fullscreen, bool b_keyboard_fullscreen)
{
  UFG::InputSystem::msShouldRestrictCursorGamepad[0] = b_gamepad_window;
  byte_14235FB85 = b_gamepad_fullscreen;
  UFG::InputSystem::msShouldRestrictCursorKeyboard[0] = b_keyboard_window;
  byte_14235FB89 = b_keyboard_fullscreen;
}

// File Line: 997
// RVA: 0x1B9030
void __fastcall UFG::InputSystem::SetShouldHideCursor(bool b_gamepad_window, bool b_keyboard_window, bool b_gamepad_fullscreen, bool b_keyboard_fullscreen)
{
  UFG::InputSystem::msShouldHideCursorGamepad[0] = b_gamepad_window;
  byte_14235FB8D = b_gamepad_fullscreen;
  UFG::InputSystem::msShouldHideCursorKeyboard[0] = b_keyboard_window;
  byte_14235FB91 = b_keyboard_fullscreen;
}

// File Line: 1005
// RVA: 0x1B8DD0
void UFG::InputSystem::PushRestrictAndHideSettings(void)
{
  __int64 v0; // rdx
  __int64 v1; // rcx
  __int64 v2; // rcx
  __int64 v3; // rcx

  v0 = UFG::InputSystem::msSavedRestrictAndHideStackIndex;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v0] = UFG::InputSystem::msShouldRestrictCursorGamepad[0];
  LODWORD(v0) = v0 + 1;
  v1 = (signed int)v0;
  LODWORD(v0) = v0 + 1;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v1] = byte_14235FB85;
  UFG::InputSystem::msSavedRestrictAndHideSettings[(signed int)v0] = UFG::InputSystem::msShouldRestrictCursorKeyboard[0];
  LODWORD(v0) = v0 + 1;
  v2 = (signed int)v0;
  LODWORD(v0) = v0 + 1;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v2] = byte_14235FB89;
  UFG::InputSystem::msSavedRestrictAndHideSettings[(signed int)v0] = UFG::InputSystem::msShouldHideCursorGamepad[0];
  LODWORD(v0) = v0 + 1;
  v3 = (signed int)v0;
  LODWORD(v0) = v0 + 1;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v3] = byte_14235FB8D;
  UFG::InputSystem::msSavedRestrictAndHideSettings[(signed int)v0] = UFG::InputSystem::msShouldHideCursorKeyboard[0];
  LODWORD(v0) = v0 + 1;
  UFG::InputSystem::msSavedRestrictAndHideSettings[(signed int)v0] = byte_14235FB91;
  UFG::InputSystem::msSavedRestrictAndHideStackIndex = v0 + 1;
}

// File Line: 1019
// RVA: 0x1B8B30
void UFG::InputSystem::PopRestrictAndHideSettings(void)
{
  bool v0; // al

  byte_14235FB91 = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex
                                                                  - 1];
  UFG::InputSystem::msShouldHideCursorKeyboard[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 2];
  byte_14235FB8D = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex
                                                                  - 3];
  UFG::InputSystem::msShouldHideCursorGamepad[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 4];
  byte_14235FB89 = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex
                                                                  - 5];
  UFG::InputSystem::msShouldRestrictCursorKeyboard[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 6];
  v0 = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 7];
  UFG::InputSystem::msSavedRestrictAndHideStackIndex -= 8;
  byte_14235FB85 = v0;
  UFG::InputSystem::msShouldRestrictCursorGamepad[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex];
}

// File Line: 1036
// RVA: 0x1B7BC0
void __fastcall UFG::InputSystem::InternalUpdate(UFG::InputSystem *this, const float elapsedTime, const float simTime)
{
  UFG::Controller **v3; // r12
  signed __int64 v4; // r13
  UFG::Controller *v5; // rbx
  UFG::Controller *v6; // rbp
  signed __int64 v7; // r14
  UFG::InputActionMap **v8; // r15
  UFG::InputActionMap *v9; // rsi
  __int64 v10; // rbx
  UFG::InputActionData *v11; // rdi
  void (__fastcall *v12)(UFG::Controller *, UFG::InputActionData *, float); // rax
  signed __int64 v13; // rsi
  UFG::MultiInputMap **v14; // r14
  UFG::MultiInputMap *v15; // rdi
  int i; // ebx

  ++UFG::InputSystem::mServiceTickCounter;
  v3 = this->mControllers;
  v4 = 5i64;
  do
  {
    v5 = *v3;
    if ( *v3 && (v5->vfptr->IsConnected(*v3) || v5->mIsInitialized) )
    {
      v6 = *v3;
      v7 = 0i64;
      v8 = (*v3)->mInputActionMaps;
      do
      {
        v9 = *v8;
        if ( *v8 && (simTime > 0.0 || v9->mUpdateWhenSimPaused) && v6->mInputActionMapEnable[v7] == 1 )
        {
          v10 = 0i64;
          if ( v9->mNumEntries )
          {
            do
            {
              v11 = v9->mActionMapInfoArray[v10].pActionDef->mDataPerController[v6->mControllerIndex];
              if ( v11 )
              {
                if ( v11->mServicedFlag != UFG::InputSystem::mServiceTickCounter )
                {
                  v12 = v11->mInputFunc;
                  if ( v9->mActionMapInfoArray[v10].mInputFunc == v12 )
                  {
                    ((void (__fastcall *)(UFG::Controller *, UFG::InputActionData *))v12)(v6, v11);
                    v11->mServicedFlag = UFG::InputSystem::mServiceTickCounter;
                  }
                }
              }
              v10 = (unsigned int)(v10 + 1);
            }
            while ( (unsigned int)v10 < v9->mNumEntries );
          }
        }
        ++v7;
        ++v8;
      }
      while ( v7 < 32 );
      v13 = 0i64;
      v14 = v6->mMultiInputMaps;
      do
      {
        v15 = *v14;
        if ( *v14 )
        {
          if ( v6->mMultiInputMapEnable[v13] == 1 )
          {
            for ( i = 0; i < v15->mNumEntries; ++i )
              UFG::Controller::UpdateCompoundAction(v6, &v15->mCompoundDefinitions[i], elapsedTime);
          }
        }
        ++v13;
        ++v14;
      }
      while ( v13 < 32 );
      v6->m_fTimeSinceLastInput = elapsedTime + v6->m_fTimeSinceLastInput;
      v6->mInputState.mPrevMouseWheel = v6->mInputState.mMouseWheel;
    }
    ++v3;
    --v4;
  }
  while ( v4 );
}

// File Line: 1071
// RVA: 0x1B6EB0
UFG::Controller *__fastcall UFG::InputSystem::AcquireController(UFG::InputSystem *this, int index)
{
  int v2; // er8
  UFG::Controller **v3; // rdx
  signed __int64 v4; // rax
  UFG::Controller *result; // rax

  if ( index == -1 )
  {
    v2 = 0;
    v3 = this->mControllers;
    v4 = 0i64;
    while ( !*v3 || this->mIsAssigned[v4] )
    {
      ++v4;
      ++v2;
      ++v3;
      if ( v4 >= 5 )
        goto LABEL_6;
    }
    this->mIsAssigned[v2] = 1;
    result = this->mControllers[v2];
  }
  else if ( index < 5 && this->mControllers[index] )
  {
    this->mIsAssigned[index] = 1;
    result = this->mControllers[index];
  }
  else
  {
LABEL_6:
    result = 0i64;
  }
  return result;
}

// File Line: 1101
// RVA: 0x1B8E70
void __fastcall UFG::InputSystem::ReleaseController(UFG::InputSystem *this, UFG::Controller *c)
{
  int v2; // er9
  UFG::Controller **v3; // rax
  signed __int64 v4; // r8

  v2 = 0;
  v3 = this->mControllers;
  v4 = 0i64;
  while ( c != *v3 )
  {
    ++v4;
    ++v2;
    ++v3;
    if ( v4 >= 5 )
      return;
  }
  this->mIsAssigned[v2] = 0;
}

// File Line: 1131
// RVA: 0x1B6930
void __fastcall UFG::Controller::Controller(UFG::Controller *this, int index)
{
  UFG::Controller *v2; // rbx
  char v3; // cl
  bool *v4; // rax
  UFG::MultiInputMap **v5; // rcx
  signed __int64 v6; // rdx
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *v7; // [rsp+50h] [rbp+18h]
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *v8; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (UFG::ControllerVtbl *)&UFG::Controller::`vftable';
  *(_WORD *)&this->mIsInitialized = 0;
  this->mControllerIndex = index;
  v7 = &this->mInputMessages;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &this->mRemappableActions;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  this->mInputState.mLastMouseXYTime = 0i64;
  this->mInputState.mMouseX = -1;
  this->mInputState.mMouseY = -1;
  this->mInputState.mMouseWheel = 0;
  this->mInputState.mPrevMouseX = -1;
  this->mInputState.mPrevMouseY = -1;
  this->mInputState.mPrevMouseWheel = 0;
  UFG::qMemSet(this->mInputState.mKeyState, 0, 0x100u);
  v2->mPreviousInputState.mLastMouseXYTime = 0i64;
  v2->mPreviousInputState.mMouseX = -1;
  v2->mPreviousInputState.mMouseY = -1;
  v2->mPreviousInputState.mMouseWheel = 0;
  v2->mPreviousInputState.mPrevMouseX = -1;
  v2->mPreviousInputState.mPrevMouseY = -1;
  v2->mPreviousInputState.mPrevMouseWheel = 0;
  UFG::qMemSet(v2->mPreviousInputState.mKeyState, 0, 0x100u);
  UFG::JoyInputHistory::JoyInputHistory(&v2->mJoyInputHistory);
  v2->mRightThumbServiceTick = 0;
  v2->m_fTimeSinceLastInput = 0.0;
  v2->m_pRemapArray = 0i64;
  *(_QWORD *)&v2->m_ActiveMapSet = 0i64;
  *(_WORD *)&v2->m_IsKeyboardController = 0;
  v3 = regTweaks;
  if ( !regTweaks )
    v3 = 1;
  regTweaks = v3;
  v4 = v2->mMultiInputMapEnable;
  v5 = v2->mMultiInputMaps;
  v6 = 32i64;
  do
  {
    *(v5 - 32) = 0i64;
    *v5 = 0i64;
    *(v4 - 32) = 0;
    *v4 = 0;
    ++v5;
    ++v4;
    --v6;
  }
  while ( v6 );
}

// File Line: 1160
// RVA: 0x1B6BA0
void __fastcall UFG::Controller::~Controller(UFG::Controller *this)
{
  UFG::Controller *v1; // r14
  bool *v2; // r12
  UFG::InputActionMap **v3; // rbp
  signed __int64 v4; // r13
  UFG::InputActionMap *v5; // rdi
  unsigned int v6; // ebx
  UFG::InputActionDef *v7; // rsi
  UFG::InputActionData *v8; // rcx
  UFG::InputActionMap *v9; // rsi
  signed int v10; // ebx
  __int64 v11; // rdi
  __int64 v12; // r15
  void *v13; // rcx
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *v14; // rbx
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *v15; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v16; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v17; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v18; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v19; // rax
  UFG::JoyInputHistory *v20; // rdx
  UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *v21; // rcx
  UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *v22; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v24; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v25; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v26; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v27; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v28; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v29; // rax
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *v30; // r14
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *j; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v32; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v33; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v34; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v35; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v36; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v37; // rax

  v1 = this;
  this->vfptr = (UFG::ControllerVtbl *)&UFG::Controller::`vftable';
  v2 = this->mMultiInputMapEnable;
  v3 = this->mInputActionMaps;
  v4 = 32i64;
  do
  {
    v5 = *v3;
    if ( *v3 )
    {
      v6 = 0;
      if ( v5->mNumEntries )
      {
        do
        {
          v7 = v5->mActionMapInfoArray[v6].pActionDef;
          v8 = v7->mDataPerController[v1->mControllerIndex];
          if ( v8 )
          {
            operator delete[](v8);
            v7->mDataPerController[v1->mControllerIndex] = 0i64;
          }
          ++v6;
        }
        while ( v6 < v5->mNumEntries );
      }
      *v3 = 0i64;
    }
    v9 = v3[32];
    if ( v9 )
    {
      v10 = 0;
      if ( (signed int)v9->mNumEntries > 0 )
      {
        v11 = 0i64;
        do
        {
          v12 = *(__int64 *)((char *)&v9->mActionMapInfoArray->pActionDef + v11);
          v13 = *(void **)(v12 + 8i64 * v1->mControllerIndex);
          if ( v13 )
          {
            operator delete[](v13);
            *(_QWORD *)(v12 + 8i64 * v1->mControllerIndex) = 0i64;
          }
          ++v10;
          v11 += 304i64;
        }
        while ( v10 < (signed int)v9->mNumEntries );
      }
    }
    *(v2 - 32) = 0;
    *v2 = 0;
    ++v3;
    ++v2;
    --v4;
  }
  while ( v4 );
  v14 = &v1->mRemappableActions;
  v15 = (UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *)v1->mRemappableActions.mNode.mNext;
  if ( v15 != &v1->mRemappableActions )
  {
    do
    {
      v16 = v15->mNode.mPrev;
      v17 = v15->mNode.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mNode.mPrev = &v15->mNode;
      v15->mNode.mNext = &v15->mNode;
      v18 = v15->mNode.mPrev;
      v19 = v15->mNode.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v15->mNode.mPrev = &v15->mNode;
      v15->mNode.mNext = &v15->mNode;
      operator delete[](v15);
      v15 = (UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *)v1->mRemappableActions.mNode.mNext;
    }
    while ( v15 != v14 );
  }
  v20 = &v1->mJoyInputHistory;
  v21 = v1->mJoyInputHistory.mPrev;
  v22 = v1->mJoyInputHistory.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v20->mPrev = (UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *)&v20->mPrev;
  v20->mNext = (UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *)&v20->mPrev;
  for ( i = v1->mRemappableActions.mNode.mNext;
        i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v14;
        i = v1->mRemappableActions.mNode.mNext )
  {
    v24 = i->mPrev;
    v25 = i->mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    i->mPrev = i;
    i->mNext = i;
    v26 = i->mPrev;
    v27 = i->mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    i->mPrev = i;
    i->mNext = i;
    operator delete[](i);
  }
  v28 = v14->mNode.mPrev;
  v29 = v1->mRemappableActions.mNode.mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  v14->mNode.mPrev = &v14->mNode;
  v1->mRemappableActions.mNode.mNext = &v1->mRemappableActions.mNode;
  v30 = &v1->mInputMessages;
  for ( j = (UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *)v30->mNode.mNext;
        j != v30;
        j = (UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *)v30->mNode.mNext )
  {
    v32 = j->mNode.mPrev;
    v33 = j->mNode.mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    j->mNode.mPrev = &j->mNode;
    j->mNode.mNext = &j->mNode;
    v34 = j->mNode.mPrev;
    v35 = j->mNode.mNext;
    v34->mNext = v35;
    v35->mPrev = v34;
    j->mNode.mPrev = &j->mNode;
    j->mNode.mNext = &j->mNode;
    operator delete[](j);
  }
  v36 = v30->mNode.mPrev;
  v37 = v30->mNode.mNext;
  v36->mNext = v37;
  v37->mPrev = v36;
  v30->mNode.mPrev = &v30->mNode;
  v30->mNode.mNext = &v30->mNode;
}

// File Line: 1218
// RVA: 0x1B76C0
void __fastcall UFG::Controller::DeleteMapDataStructures(UFG::Controller *this)
{
  UFG::Controller *v1; // rbp
  UFG::MultiInputMap **v2; // r15
  signed __int64 v3; // r12
  __int64 v4; // rdi
  unsigned int i; // ebx
  __int64 v6; // rsi
  void *v7; // rcx
  UFG::MultiInputMap *v8; // rsi
  int v9; // ebx
  __int64 v10; // rdi
  UFG::InputActionDef *v11; // r14
  UFG::InputActionData *v12; // rcx

  v1 = this;
  v2 = this->mMultiInputMaps;
  v3 = 32i64;
  do
  {
    v4 = (__int64)*(v2 - 32);
    if ( v4 )
    {
      for ( i = 0; i < *(_DWORD *)(v4 + 8); ++i )
      {
        v6 = *(_QWORD *)(*(_QWORD *)v4 + 24i64 * i);
        v7 = *(void **)(v6 + 8i64 * v1->mControllerIndex);
        if ( v7 )
        {
          operator delete[](v7);
          *(_QWORD *)(v6 + 8i64 * v1->mControllerIndex) = 0i64;
        }
      }
    }
    v8 = *v2;
    if ( *v2 )
    {
      v9 = 0;
      if ( v8->mNumEntries > 0 )
      {
        v10 = 0i64;
        do
        {
          v11 = v8->mCompoundDefinitions[v10].mActionDefName;
          v12 = v11->mDataPerController[v1->mControllerIndex];
          if ( v12 )
          {
            operator delete[](v12);
            v11->mDataPerController[v1->mControllerIndex] = 0i64;
          }
          ++v9;
          ++v10;
        }
        while ( v9 < v8->mNumEntries );
      }
    }
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 1300
// RVA: 0x1B6F10
void __fastcall UFG::Controller::AddActionToRemappableList(UFG::Controller *this, UFG::InputActionDef *actionDef, unsigned int id, UFG::InputActionDef *actionDef_2, UFG::InputActionDef *actionDef_3)
{
  UFG::InputActionDef *v5; // rbp
  unsigned int v6; // er14
  UFG::InputActionDef *v7; // rdi
  UFG::Controller *v8; // rsi
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v9; // rax
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdx
  UFG::InputActionData *v13; // rcx
  unsigned int v14; // eax
  UFG::allocator::free_link *v15; // rax

  v5 = actionDef_2;
  v6 = id;
  v7 = actionDef;
  v8 = this;
  v9 = this->mRemappableActions.mNode.mNext;
  v10 = &this->mRemappableActions;
  if ( v9 == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&this->mRemappableActions )
  {
LABEL_4:
    v11 = UFG::qMalloc(0x38ui64, "ActionRemapInfo", 0i64);
    v12 = v11;
    if ( v11 )
    {
      v11->mNext = v11;
      v11[1].mNext = v11;
      v11[2].mNext = (UFG::allocator::free_link *)v7;
      v11[3].mNext = (UFG::allocator::free_link *)v5;
      v11[4].mNext = (UFG::allocator::free_link *)actionDef_3;
      LODWORD(v11[5].mNext) = v6;
      *(UFG::allocator::free_link **)((char *)&v11[5].mNext + 4) = (UFG::allocator::free_link *)-1i64;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = v7->mDataPerController[v8->mControllerIndex];
    v14 = v13->mButton;
    LODWORD(v12[6].mNext) = v13->mButton;
    HIDWORD(v12[5].mNext) = v14;
    v15 = (UFG::allocator::free_link *)v10->mNode.mNext;
    v10->mNode.mNext = (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v12;
    v12->mNext = (UFG::allocator::free_link *)v10;
    v12[1].mNext = v15;
    v15->mNext = v12;
  }
  else
  {
    while ( (UFG::InputActionDef *)v9[1].mPrev != actionDef )
    {
      v9 = v9->mNext;
      if ( v9 == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v10 )
        goto LABEL_4;
    }
  }
}

// File Line: 1341
// RVA: 0x1B73C0
void __fastcall UFG::Controller::ApplyRemapList(UFG::Controller *this)
{
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v2; // r8
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v3; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v4; // rdx

  for ( i = this->mRemappableActions.mNode.mNext;
        i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&this->mRemappableActions;
        i = i->mNext )
  {
    v2 = i[1].mPrev;
    if ( v2 )
      **((_DWORD **)&v2->mPrev + this->mControllerIndex) = i[3].mPrev;
    v3 = i[1].mNext;
    if ( v3 )
      **((_DWORD **)&v3->mPrev + this->mControllerIndex) = i[3].mPrev;
    v4 = i[2].mPrev;
    if ( v4 )
      **((_DWORD **)&v4->mPrev + this->mControllerIndex) = i[3].mPrev;
  }
}

// File Line: 1358
// RVA: 0x1B8EA0
void __fastcall UFG::Controller::ResetRemapList(UFG::Controller *this)
{
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v2; // r8
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v3; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v4; // rdx

  for ( i = this->mRemappableActions.mNode.mNext;
        i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&this->mRemappableActions;
        i = i->mNext )
  {
    v2 = i[1].mPrev;
    if ( v2 )
      **((_DWORD **)&v2->mPrev + this->mControllerIndex) = HIDWORD(i[2].mNext);
    v3 = i[1].mNext;
    if ( v3 )
      **((_DWORD **)&v3->mPrev + this->mControllerIndex) = HIDWORD(i[2].mNext);
    v4 = i[2].mPrev;
    if ( v4 )
      **((_DWORD **)&v4->mPrev + this->mControllerIndex) = HIDWORD(i[2].mNext);
    LODWORD(i[3].mPrev) = HIDWORD(i[2].mNext);
  }
}

// File Line: 1374
// RVA: 0x1B74B0
void __fastcall UFG::Controller::CreateSingleMapStructure(UFG::Controller *this, int index)
{
  UFG::Controller *v2; // rbp
  UFG::InputActionMap *v3; // r15
  unsigned int v4; // ebx
  UFG::InputActionMapInfo *v5; // rsi
  UFG::InputActionDef *v6; // r14
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  __int64 v9; // rax
  const unsigned int *v10; // rdx

  v2 = this;
  v3 = this->mInputActionMaps[index];
  v4 = 0;
  if ( v3->mNumEntries )
  {
    do
    {
      v5 = v3->mActionMapInfoArray;
      v6 = v3->mActionMapInfoArray[v4].pActionDef;
      if ( !v6->mDataPerController[v2->mControllerIndex] )
      {
        v7 = UFG::qMalloc(0x50ui64, "InputActionData", 0i64);
        v8 = v7;
        if ( v7 )
        {
          v7[2].mNext = 0i64;
          *(UFG::allocator::free_link **)((char *)&v7[8].mNext + 4) = 0i64;
          BYTE4(v7[9].mNext) = 0;
          v7[3].mNext = 0i64;
          v7[4].mNext = 0i64;
          *(UFG::allocator::free_link **)((char *)&v7[5].mNext + 4) = 0i64;
          LODWORD(v7[5].mNext) = 0;
          v7[7].mNext = 0i64;
          HIDWORD(v7[6].mNext) = 0;
          LODWORD(v7[8].mNext) = 0;
        }
        else
        {
          v8 = 0i64;
        }
        v6->mDataPerController[v2->mControllerIndex] = (UFG::InputActionData *)v8;
        v9 = v5[v4].mButtonDef;
        v10 = v2->m_pRemapArray;
        if ( v10
          && (unsigned int)v9 < 0x12
          && (void (__fastcall *)(UFG::Controller *, UFG::InputActionData *, const float))v5[v4].mInputFunc != UFG::Keyboard_IAD_Func )
        {
          LODWORD(v9) = v10[v9];
        }
        LODWORD(v8->mNext) = v9;
        v8[1].mNext = (UFG::allocator::free_link *)v5[v4].mInputFunc;
        HIDWORD(v8->mNext) = v5[v4].mSignalType;
      }
      ++v4;
    }
    while ( v4 < v3->mNumEntries );
  }
}

// File Line: 1427
// RVA: 0x1B7450
void __fastcall UFG::Controller::CreateMapDataStructures(UFG::Controller *this)
{
  UFG::Controller *v1; // rsi
  int v2; // ebx
  UFG::MultiInputMap **v3; // rdi

  v1 = this;
  v2 = 0;
  v3 = this->mMultiInputMaps;
  do
  {
    if ( *(v3 - 32) )
      UFG::Controller::CreateSingleMapStructure(v1, v2);
    if ( *v3 )
      UFG::Controller::CreateSingleMultiMapStruct(v1, v2);
    ++v2;
    ++v3;
  }
  while ( v2 < 32 );
}

// File Line: 1444
// RVA: 0x1B7110
void __fastcall UFG::Controller::AddInputActionMap(UFG::Controller *this, UFG::InputActionMap *actionMap, const unsigned int *pRemapArray)
{
  UFG::Controller *v3; // rbp
  __int64 v4; // rax
  signed int v5; // er8
  UFG::InputActionMap **v6; // r9
  UFG::InputActionMap *v7; // r15
  unsigned int i; // ebx
  UFG::InputActionMapInfo *v9; // rsi
  UFG::InputActionDef *v10; // r14
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rcx
  __int64 v13; // rax
  const unsigned int *v14; // rdx

  v3 = this;
  if ( !this->m_pRemapArray )
    this->m_pRemapArray = pRemapArray;
  LODWORD(v4) = -1;
  v5 = 0;
  v6 = this->mInputActionMaps;
  while ( actionMap != *v6 )
  {
    if ( !*v6 && (_DWORD)v4 == -1 )
      LODWORD(v4) = v5;
    ++v5;
    ++v6;
    if ( v5 >= 32 )
    {
      v4 = (signed int)v4;
      this->mInputActionMaps[v4] = actionMap;
      this->mInputActionMapEnable[v4] = 1;
      v7 = this->mInputActionMaps[(signed int)v4];
      for ( i = 0; i < v7->mNumEntries; ++i )
      {
        v9 = v7->mActionMapInfoArray;
        v10 = v7->mActionMapInfoArray[i].pActionDef;
        if ( !v10->mDataPerController[v3->mControllerIndex] )
        {
          v11 = UFG::qMalloc(0x50ui64, "InputActionData", 0i64);
          v12 = v11;
          if ( v11 )
          {
            v11[2].mNext = 0i64;
            *(UFG::allocator::free_link **)((char *)&v11[8].mNext + 4) = 0i64;
            BYTE4(v11[9].mNext) = 0;
            v11[3].mNext = 0i64;
            v11[4].mNext = 0i64;
            *(UFG::allocator::free_link **)((char *)&v11[5].mNext + 4) = 0i64;
            LODWORD(v11[5].mNext) = 0;
            v11[7].mNext = 0i64;
            HIDWORD(v11[6].mNext) = 0;
            LODWORD(v11[8].mNext) = 0;
          }
          else
          {
            v12 = 0i64;
          }
          v10->mDataPerController[v3->mControllerIndex] = (UFG::InputActionData *)v12;
          v13 = v9[i].mButtonDef;
          v14 = v3->m_pRemapArray;
          if ( v14
            && (unsigned int)v13 < 0x12
            && (void (__fastcall *)(UFG::Controller *, UFG::InputActionData *, const float))v9[i].mInputFunc != UFG::Keyboard_IAD_Func )
          {
            LODWORD(v13) = v14[v13];
          }
          LODWORD(v12->mNext) = v13;
          v12[1].mNext = (UFG::allocator::free_link *)v9[i].mInputFunc;
          HIDWORD(v12->mNext) = v9[i].mSignalType;
        }
      }
      return;
    }
  }
}

// File Line: 1475
// RVA: 0x1B7990
signed __int64 __fastcall UFG::Controller::EnableInputActionMap(UFG::Controller *this, UFG::InputActionMap *actionMap)
{
  int v2; // er9
  UFG::InputActionMap **v3; // rax
  signed __int64 v4; // r8

  v2 = 0;
  v3 = this->mInputActionMaps;
  v4 = 0i64;
  while ( actionMap != *v3 )
  {
    ++v4;
    ++v2;
    ++v3;
    if ( v4 >= 32 )
      return 1i64;
  }
  this->mInputActionMapEnable[v2] = 1;
  return 0i64;
}

// File Line: 1521
// RVA: 0x1B78F0
signed __int64 __fastcall UFG::Controller::DisableInputActionMap(UFG::Controller *this, UFG::InputActionMap *actionMap)
{
  UFG::InputActionMap *v2; // r9
  int v3; // er8
  signed __int64 v4; // rdx
  UFG::InputActionMap **v5; // rax
  __int64 v7; // rax
  unsigned int v8; // er8
  UFG::InputActionData *v9; // rdx

  v2 = actionMap;
  v3 = 0;
  v4 = 0i64;
  v5 = this->mInputActionMaps;
  while ( v2 != *v5 || !v2 )
  {
    ++v4;
    ++v3;
    ++v5;
    if ( v4 >= 32 )
      return 1i64;
  }
  v7 = v3;
  v8 = 0;
  for ( this->mInputActionMapEnable[v7] = 0; v8 < v2->mNumEntries; ++v8 )
  {
    v9 = v2->mActionMapInfoArray[v8].pActionDef->mDataPerController[this->mControllerIndex];
    if ( v9 )
    {
      v9->mActionTrue = 0;
      *(_QWORD *)&v9->mData0i = 0i64;
      *(_QWORD *)&v9->mData2i = 0i64;
      *(_QWORD *)&v9->mAxisPositionY = 0i64;
      *(_QWORD *)&v9->mAxisRawX[1] = 0i64;
      *(_QWORD *)&v9->mAxisRawY[1] = 0i64;
      v9->mAxisRawY[0] = 0.0;
      *(_QWORD *)&v9->mOnSeconds = 0i64;
    }
  }
  return 0i64;
}

// File Line: 1588
// RVA: 0x1B77B0
void __fastcall UFG::Controller::DisableAllMaps(UFG::Controller *this)
{
  UFG::Controller *v1; // r11
  UFG::InputActionMap **v2; // rbx
  signed __int64 v3; // r10
  UFG::InputActionMap *v4; // r9
  signed int v5; // edx
  __int64 v6; // r8
  UFG::InputActionDef *v7; // rcx
  UFG::InputActionData *v8; // rcx
  signed __int64 v9; // r10
  UFG::MultiInputMap **v10; // rbx
  UFG::MultiInputMap *v11; // r9
  int v12; // edx
  __int64 v13; // r8
  UFG::InputActionDef *v14; // rcx
  UFG::InputActionData *v15; // rcx

  v1 = this;
  v2 = this->mInputActionMaps;
  v3 = 0i64;
  do
  {
    v4 = *v2;
    v1->mInputActionMapEnable[v3] = 0;
    if ( v4 )
    {
      v5 = 0;
      if ( (signed int)v4->mNumEntries > 0 )
      {
        v6 = 0i64;
        do
        {
          v7 = v4->mActionMapInfoArray[v6].pActionDef;
          if ( v7 )
          {
            v8 = v7->mDataPerController[v1->mControllerIndex];
            if ( v8 )
            {
              v8->mActionTrue = 0;
              *(_QWORD *)&v8->mData0i = 0i64;
              *(_QWORD *)&v8->mData2i = 0i64;
              *(_QWORD *)&v8->mAxisPositionY = 0i64;
              *(_QWORD *)&v8->mAxisRawX[1] = 0i64;
              *(_QWORD *)&v8->mAxisRawY[1] = 0i64;
              v8->mAxisRawY[0] = 0.0;
              *(_QWORD *)&v8->mOnSeconds = 0i64;
            }
          }
          ++v5;
          ++v6;
        }
        while ( v5 < (signed int)v4->mNumEntries );
      }
    }
    ++v3;
    ++v2;
  }
  while ( v3 < 32 );
  v9 = 0i64;
  v10 = v1->mMultiInputMaps;
  do
  {
    v11 = *v10;
    v1->mMultiInputMapEnable[v9] = 0;
    if ( v11 )
    {
      v12 = 0;
      if ( v11->mNumEntries > 0 )
      {
        v13 = 0i64;
        do
        {
          v14 = v11->mCompoundDefinitions[v13].mActionDefName;
          if ( v14 )
          {
            v15 = v14->mDataPerController[v1->mControllerIndex];
            if ( v15 )
            {
              v15->mActionTrue = 0;
              *(_QWORD *)&v15->mData0i = 0i64;
              *(_QWORD *)&v15->mData2i = 0i64;
              *(_QWORD *)&v15->mAxisPositionY = 0i64;
              *(_QWORD *)&v15->mAxisRawX[1] = 0i64;
              *(_QWORD *)&v15->mAxisRawY[1] = 0i64;
              v15->mAxisRawY[0] = 0.0;
              *(_QWORD *)&v15->mOnSeconds = 0i64;
              v15[1].mButton = 0;
              v15[1].mInputFunc = 0i64;
              v15->mDebouncer = 1;
            }
          }
          ++v12;
          ++v13;
        }
        while ( v12 < v11->mNumEntries );
      }
    }
    ++v9;
    ++v10;
  }
  while ( v9 < 32 );
}

// File Line: 1628
// RVA: 0x1B75D0
void __fastcall UFG::Controller::CreateSingleMultiMapStruct(UFG::Controller *this, int index)
{
  UFG::Controller *v2; // rbp
  UFG::MultiInputMap *v3; // rsi
  int v4; // ebx
  __int64 v5; // rdi
  UFG::InputActionDef *v6; // r14
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx

  v2 = this;
  v3 = this->mMultiInputMaps[index];
  v4 = 0;
  if ( v3->mNumEntries > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->mCompoundDefinitions[v5].mActionDefName;
      if ( !v6->mDataPerController[v2->mControllerIndex] )
      {
        v7 = UFG::qMalloc(0x60ui64, "MultiInputActionData", 0i64);
        v8 = v7;
        if ( v7 )
        {
          v7[2].mNext = 0i64;
          *(UFG::allocator::free_link **)((char *)&v7[8].mNext + 4) = 0i64;
          BYTE4(v7[9].mNext) = 0;
          v7[3].mNext = 0i64;
          v7[4].mNext = 0i64;
          *(UFG::allocator::free_link **)((char *)&v7[5].mNext + 4) = 0i64;
          LODWORD(v7[5].mNext) = 0;
          v7[7].mNext = 0i64;
          HIDWORD(v7[6].mNext) = 0;
          LODWORD(v7[8].mNext) = 0;
          LODWORD(v7[10].mNext) = 0;
          v7[11].mNext = 0i64;
          BYTE4(v7[10].mNext) = 0;
        }
        else
        {
          v8 = 0i64;
        }
        v6->mDataPerController[v2->mControllerIndex] = (UFG::InputActionData *)v8;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3->mNumEntries );
  }
}

// File Line: 1653
// RVA: 0x1B7290
void __fastcall UFG::Controller::AddMultiInputMap(UFG::Controller *this, UFG::MultiInputMap *multiMap)
{
  UFG::Controller *v2; // rsi
  __int64 v3; // rax
  signed int v4; // er8
  UFG::MultiInputMap **v5; // r9
  UFG::MultiInputMap *v6; // r14
  int v7; // ebx
  __int64 v8; // rdi
  UFG::InputActionDef *v9; // r15
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rcx

  v2 = this;
  LODWORD(v3) = -1;
  v4 = 0;
  v5 = this->mMultiInputMaps;
  while ( multiMap != *v5 )
  {
    if ( !*v5 && (_DWORD)v3 == -1 )
      LODWORD(v3) = v4;
    ++v4;
    ++v5;
    if ( v4 >= 32 )
    {
      v3 = (signed int)v3;
      this->mMultiInputMaps[v3] = multiMap;
      this->mMultiInputMapEnable[v3] = 1;
      v6 = this->mMultiInputMaps[(signed int)v3];
      v7 = 0;
      if ( v6->mNumEntries > 0 )
      {
        v8 = 0i64;
        do
        {
          v9 = v6->mCompoundDefinitions[v8].mActionDefName;
          if ( !v9->mDataPerController[v2->mControllerIndex] )
          {
            v10 = UFG::qMalloc(0x60ui64, "MultiInputActionData", 0i64);
            v11 = v10;
            if ( v10 )
            {
              v10[2].mNext = 0i64;
              *(UFG::allocator::free_link **)((char *)&v10[8].mNext + 4) = 0i64;
              BYTE4(v10[9].mNext) = 0;
              v10[3].mNext = 0i64;
              v10[4].mNext = 0i64;
              *(UFG::allocator::free_link **)((char *)&v10[5].mNext + 4) = 0i64;
              LODWORD(v10[5].mNext) = 0;
              v10[7].mNext = 0i64;
              HIDWORD(v10[6].mNext) = 0;
              LODWORD(v10[8].mNext) = 0;
              LODWORD(v10[10].mNext) = 0;
              v10[11].mNext = 0i64;
              BYTE4(v10[10].mNext) = 0;
            }
            else
            {
              v11 = 0i64;
            }
            v9->mDataPerController[v2->mControllerIndex] = (UFG::InputActionData *)v11;
          }
          ++v7;
          ++v8;
        }
        while ( v7 < v6->mNumEntries );
      }
      return;
    }
  }
}

// File Line: 1758
// RVA: 0x1B9070
void __fastcall UFG::Controller::UpdateCompoundAction(UFG::Controller *this, UFG::CompoundAction *ca, float elapsedTime)
{
  UFG::InputActionData *v3; // r9
  float v4; // xmm3_4
  __int64 v5; // rbp
  float v6; // xmm3_4
  float v7; // xmm0_4
  UFG::InputActionDef *v8; // r11
  float v9; // xmm2_4
  int v10; // er10
  UFG::InputActionData *v11; // rax
  UFG::InputActionDef *v12; // r11
  UFG::InputActionData *v13; // rax
  float v14; // xmm0_4
  UFG::InputActionDef *v15; // r11
  UFG::InputActionData *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4

  v3 = ca->mActionDefName->mDataPerController[this->mControllerIndex];
  v4 = 0.0;
  v5 = (signed int)v3[1].mButton;
  if ( v3->mActionTrue == 1 )
    v3->mActionTrue = 0;
  if ( (_DWORD)v5 )
  {
    v6 = elapsedTime + *(float *)&v3[1].mInputFunc;
    *(float *)&v3[1].mInputFunc = v6;
    v4 = v6 - *((float *)&v3[1].mInputFunc + 1);
    v7 = ca->mActionNodes[v5].mEndTime;
    if ( v4 > v7 && v7 >= 0.0 )
    {
      v3->mActionTrue = 0;
LABEL_59:
      *(_QWORD *)&v3->mData0i = 0i64;
      *(_QWORD *)&v3->mData2i = 0i64;
      *(_QWORD *)&v3->mAxisPositionY = 0i64;
      *(_QWORD *)&v3->mAxisRawX[1] = 0i64;
      *(_QWORD *)&v3->mAxisRawY[1] = 0i64;
      v3->mAxisRawY[0] = 0.0;
      v3->mDebouncer = 1;
      v3[1].mInputFunc = 0i64;
      v3[1].mButton = 0;
      *(_QWORD *)&v3->mOnSeconds = 0i64;
      return;
    }
  }
  v8 = ca->mActionNodes[v5].mActions[0];
  v9 = FLOAT_999_0;
  v10 = 0;
  if ( v8 )
  {
    v11 = v8->mDataPerController[this->mControllerIndex];
    if ( !v11 )
      goto LABEL_62;
    if ( v11->mActionTrue )
      v10 = 1;
    if ( !v11 )
      goto LABEL_62;
    if ( v11->mOnSeconds >= 999.0 )
      goto LABEL_16;
    if ( v11 )
      v9 = v11->mOnSeconds;
    else
LABEL_62:
      v9 = 0.0;
  }
LABEL_16:
  v12 = ca->mActionNodes[v5].mActions[1];
  if ( v12 )
  {
    v13 = v12->mDataPerController[this->mControllerIndex];
    if ( !v13 )
      goto LABEL_63;
    if ( v13->mActionTrue )
      ++v10;
    if ( v13 )
      v14 = v13->mOnSeconds;
    else
LABEL_63:
      v14 = 0.0;
    if ( v14 < v9 )
    {
      if ( v13 )
        v9 = v13->mOnSeconds;
      else
        v9 = 0.0;
    }
  }
  v15 = ca->mActionNodes[v5].mActions[2];
  if ( v15 )
  {
    v16 = v15->mDataPerController[this->mControllerIndex];
    if ( !v16 )
      goto LABEL_64;
    if ( v16->mActionTrue )
      ++v10;
    if ( v16 )
      v17 = v16->mOnSeconds;
    else
LABEL_64:
      v17 = 0.0;
    if ( v17 < v9 )
    {
      if ( v16 )
        v9 = v16->mOnSeconds;
      else
        v9 = 0.0;
    }
  }
  if ( v3->mDebouncer && ca->mShouldDebounce || v10 < ca->mActionNodes[v5].mNumActionsCombined )
  {
    if ( v10 )
      return;
    if ( !(_DWORD)v5 )
    {
      v3->mDebouncer = 0;
      return;
    }
    if ( ca->mActionNodes[v5].mMinHoldTime < 0.0 && ca->mActionNodes[v5].mMaxHoldTime < 0.0 )
    {
      v3->mActionTrue = 0;
      goto LABEL_59;
    }
  }
  else if ( v4 >= ca->mActionNodes[v5].mStartTime )
  {
    v18 = ca->mActionNodes[v5].mEndTime;
    if ( (v4 <= v18 || v18 < 0.0) && v9 >= ca->mActionNodes[v5].mMinHoldTime )
    {
      v19 = ca->mActionNodes[v5].mMaxHoldTime;
      if ( v19 >= v9 || v19 < 0.0 )
      {
        v3[1].mButton = v5 + 1;
        if ( (_DWORD)v5 + 1 == ca->mNumNodes )
        {
          if ( ca->mActionNodes[v5].mMinHoldTime >= 0.0 || ca->mActionNodes[v5].mMaxHoldTime >= 0.0 )
          {
            v3->mActionTrue = 0;
            *(_QWORD *)&v3->mData0i = 0i64;
            *(_QWORD *)&v3->mData2i = 0i64;
            *(_QWORD *)&v3->mAxisPositionY = 0i64;
            *(_QWORD *)&v3->mAxisRawX[1] = 0i64;
            *(_QWORD *)&v3->mAxisRawY[1] = 0i64;
            v3->mAxisRawY[0] = 0.0;
            *(_QWORD *)&v3->mOnSeconds = 0i64;
            v3[1].mButton = 0;
            v3[1].mInputFunc = 0i64;
            v3->mDebouncer = 1;
            v3->mActionTrue = 1;
          }
          else
          {
            v3->mActionTrue = 1;
            v3[1].mButton = v5;
          }
        }
        else
        {
          HIDWORD(v3[1].mInputFunc) = v3[1].mInputFunc;
        }
      }
    }
  }
}

// File Line: 1883
// RVA: 0x1B9300
void __fastcall UFG::Controller::UpdateRightThumbHistory(UFG::Controller *this, float x, float y, float elapsedTime)
{
  if ( this->mRightThumbServiceTick != UFG::InputSystem::mServiceTickCounter )
  {
    this->mRightThumbServiceTick = UFG::InputSystem::mServiceTickCounter;
    UFG::JoyInputHistory::AddAxisInfo(&this->mJoyInputHistory, x, y, elapsedTime);
  }
}

// File Line: 1901
// RVA: 0x1B8F10
char __fastcall UFG::Controller::RightStick_HoldThenFlickAcross(UFG::Controller *this)
{
  UFG::Controller *v1; // r8
  char v2; // dl
  __int64 v4; // rcx
  int v5; // er9
  signed int v6; // eax
  signed int v7; // ecx
  signed __int64 v8; // rdx
  float v9; // xmm0_4
  int v10; // er11
  signed int v11; // er9
  int v12; // eax
  int v13; // ecx

  v1 = this;
  v2 = tweaksAdded;
  if ( !tweaksAdded )
    v2 = 1;
  tweaksAdded = v2;
  if ( this->mRightThumbServiceTick != UFG::InputSystem::mServiceTickCounter )
    return 0;
  v4 = this->mJoyInputHistory.mOctantIndex;
  v5 = v1->mJoyInputHistory.mOctantHistory[v4].mOctant;
  if ( UFG::gFlickDuration >= v1->mJoyInputHistory.mOctantHistory[v4].mDuration )
  {
    v6 = v4 - 1;
    v7 = 7;
    if ( v6 >= 0 )
      v7 = v6;
    v8 = v7;
    if ( v1->mJoyInputHistory.mOctantHistory[v7].mOctant == -1
      && UFG::gFlickDuration > v1->mJoyInputHistory.mOctantHistory[v7].mDuration )
    {
      ++count;
      v9 = 0.0;
      v10 = ((_BYTE)v5 - 8) & 0xF;
      v11 = 0;
      do
      {
        if ( --v8 < 0 )
          v8 = 7i64;
        v12 = v10 - v1->mJoyInputHistory.mOctantHistory[v8].mOctant;
        v13 = v12;
        if ( v12 < 0 )
          v13 = v1->mJoyInputHistory.mOctantHistory[v8].mOctant - v10;
        if ( v13 > 8 )
        {
          if ( v12 < 0 )
            v12 = v1->mJoyInputHistory.mOctantHistory[v8].mOctant - v10;
          v12 = 16 - v12;
        }
        else if ( v12 < 0 )
        {
          v12 = v1->mJoyInputHistory.mOctantHistory[v8].mOctant - v10;
        }
        if ( v12 > UFG::gAllowedSectionDelt )
          break;
        v9 = v9 + v1->mJoyInputHistory.mOctantHistory[v8].mDuration;
        if ( v9 >= UFG::gHoldDuration )
          return 1;
        ++v11;
      }
      while ( v11 < 4 );
    }
  }
  return 0;
}

// File Line: 2000
// RVA: 0x1B6FD0
void __fastcall UFG::JoyInputHistory::AddAxisInfo(UFG::JoyInputHistory *this, float x, float y, float elapsedTime)
{
  UFG::JoyInputHistory *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm1_4
  signed int v7; // eax
  signed int v8; // eax
  int v9; // ecx
  __int64 v10; // rdx
  int v11; // eax

  v4 = this;
  if ( !this->mLocked )
  {
    v5 = atan2f(y, x);
    if ( fsqrt((float)(x * x) + (float)(y * y)) <= 0.85000002 )
      v6 = 0.0;
    else
      v6 = *(float *)&FLOAT_1_0;
    v4->mTheta[v4->mIndex] = v5;
    v4->mR[v4->mIndex++] = v6;
    v7 = v4->mIndex;
    if ( v7 >= 64 )
      v7 = 0;
    v4->mIndex = v7;
    v8 = v4->mValidHistorySize;
    if ( v8 < 64 )
      v4->mValidHistorySize = v8 + 1;
    v9 = -1;
    if ( v6 != 0.0 )
    {
      if ( v5 < 0.0 )
        v5 = v5 + 6.2831855;
      v9 = (signed int)(float)((float)(v5 + 0.19634955) * 2.546479) & 0xF;
    }
    v10 = v4->mOctantIndex;
    if ( v9 == v4->mOctantHistory[v10].mOctant )
    {
      v4->mOctantHistory[v10].mDuration = elapsedTime + v4->mOctantHistory[v10].mDuration;
    }
    else
    {
      v11 = v10 + 1;
      if ( (_DWORD)v10 == 7 )
        v11 = 0;
      v4->mOctantIndex = v11;
      v4->mOctantHistory[v11].mDuration = elapsedTime;
      v4->mOctantHistory[v4->mOctantIndex].mOctant = v9;
    }
  }
}

