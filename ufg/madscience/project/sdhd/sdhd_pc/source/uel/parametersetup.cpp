// File Line: 9
// RVA: 0x5B8790
void __fastcall InitParameters(UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *pParameterData)
{
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v2; // rsi
  UFG::allocator::free_link *v3; // rdx
  unsigned int v4; // eax
  UFG::allocator::free_link *v5; // rbx
  UFG::qSymbol *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::qSymbol *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::qSymbol *v10; // rax
  UFG::allocator::free_link *v11; // rbx
  UFG::qSymbol *v12; // rax
  UFG::qBaseTreeRB *v13; // rax
  UFG::qBaseTreeRB *v14; // rbx
  UFG::allocator::free_link *v15; // rdx
  unsigned int v16; // eax
  UFG::allocator::free_link *v17; // rdx
  unsigned int v18; // eax
  UFG::allocator::free_link *v19; // rdx
  int v20; // eax
  UFG::qBaseTreeRB *v21; // rax
  UFG::qBaseTreeRB *v22; // rbx
  UFG::allocator::free_link *v23; // rdx
  unsigned int v24; // eax
  UFG::allocator::free_link *v25; // rdx
  int v26; // eax
  UFG::qBaseTreeRB *v27; // rax
  UFG::qBaseTreeRB *v28; // rbx
  UFG::allocator::free_link *v29; // rdx
  unsigned int v30; // eax
  UFG::allocator::free_link *v31; // rdx
  unsigned int v32; // eax
  UFG::allocator::free_link *v33; // rdx
  unsigned int v34; // eax
  UFG::allocator::free_link *v35; // rdx
  int v36; // eax
  UFG::qBaseTreeRB *v37; // rax
  UFG::qBaseTreeRB *v38; // rbx
  UFG::allocator::free_link *v39; // rdx
  unsigned int v40; // eax
  UFG::allocator::free_link *v41; // rdx
  int v42; // eax
  UFG::qBaseTreeRB *v43; // rax
  UFG::qBaseTreeRB *v44; // rbx
  UFG::allocator::free_link *v45; // rdx
  unsigned int v46; // eax
  UFG::allocator::free_link *v47; // rdx
  unsigned int v48; // eax
  UFG::qBaseTreeRB *v49; // rax
  UFG::qBaseTreeRB *v50; // rbx
  UFG::allocator::free_link *v51; // rdx
  unsigned int v52; // eax
  UFG::allocator::free_link *v53; // rdx
  unsigned int v54; // eax
  UFG::qBaseTreeRB *v55; // rax
  UFG::qBaseTreeRB *v56; // rbx
  UFG::allocator::free_link *v57; // rdx
  unsigned int v58; // eax
  UFG::allocator::free_link *v59; // rdx
  unsigned int v60; // eax
  UFG::allocator::free_link *v61; // rdx
  unsigned int v62; // eax
  UFG::allocator::free_link *v63; // rdx
  unsigned int v64; // eax
  UFG::allocator::free_link *v65; // rdx
  unsigned int v66; // eax
  UFG::allocator::free_link *v67; // rdx
  unsigned int v68; // eax
  UFG::allocator::free_link *v69; // rdx
  unsigned int v70; // eax
  UFG::allocator::free_link *v71; // rdx
  unsigned int v72; // eax
  UFG::allocator::free_link *v73; // rdx
  unsigned int v74; // eax
  UFG::allocator::free_link *v75; // rdx
  unsigned int v76; // eax
  UFG::allocator::free_link *v77; // rdx
  unsigned int v78; // eax
  UFG::allocator::free_link *v79; // rdx
  unsigned int v80; // eax
  UFG::allocator::free_link *v81; // rdx
  unsigned int v82; // eax
  UFG::allocator::free_link *v83; // rdx
  unsigned int v84; // eax
  UFG::qBaseTreeRB *v85; // rax
  UFG::qBaseTreeRB *v86; // rbx
  UFG::allocator::free_link *v87; // rdx
  unsigned int v88; // eax
  UFG::allocator::free_link *v89; // rdx
  unsigned int v90; // eax
  UFG::allocator::free_link *v91; // rdx
  unsigned int v92; // eax
  UFG::allocator::free_link *v93; // rdx
  unsigned int v94; // eax
  UFG::allocator::free_link *v95; // rdx
  unsigned int v96; // eax
  UFG::qBaseTreeRB *v97; // rax
  UFG::qBaseTreeRB *v98; // rbx
  UFG::allocator::free_link *v99; // rdx
  unsigned int v100; // eax
  UFG::allocator::free_link *v101; // rdx
  unsigned int v102; // eax
  UFG::allocator::free_link *v103; // rdx
  unsigned int v104; // eax
  UFG::allocator::free_link *v105; // rdx
  unsigned int v106; // eax
  UFG::qBaseTreeRB *v107; // rax
  UFG::qBaseTreeRB *v108; // rbx
  UFG::allocator::free_link *v109; // rdx
  unsigned int v110; // eax
  UFG::allocator::free_link *v111; // rdx
  unsigned int v112; // eax
  UFG::allocator::free_link *v113; // rdx
  unsigned int v114; // eax
  UFG::allocator::free_link *v115; // rdx
  unsigned int v116; // eax
  UFG::qBaseTreeRB *v117; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *parameterNameToDataMap; // r15
  UFG::allocator::free_link *v119; // rdx
  unsigned int v120; // eax
  UFG::allocator::free_link *v121; // rdx
  unsigned int v122; // eax
  UFG::allocator::free_link *v123; // rdx
  unsigned int v124; // eax
  UFG::allocator::free_link *v125; // rdx
  unsigned int v126; // eax
  UFG::allocator::free_link *v127; // rbx
  UFG::qSymbol *v128; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v129; // rax
  char *v130; // r12
  UEL::Value::Type v131; // rax
  UEL::Value::Type v132; // rdi
  UEL::Value::Type v133; // rax
  UEL::Value::Type v134; // rbx
  UFG::qSymbol *v135; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v136; // rax
  char *v137; // r12
  UEL::Value::Type v138; // rax
  UEL::Value::Type v139; // rdi
  UEL::Value::Type v140; // rax
  UEL::Value::Type v141; // rbx
  UFG::qSymbol *v142; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v143; // rax
  char *v144; // r12
  UEL::Value::Type v145; // rax
  UEL::Value::Type v146; // rdi
  UEL::Value::Type v147; // rax
  UEL::Value::Type v148; // rbx
  UFG::qSymbol *v149; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v150; // rax
  char *v151; // r12
  UEL::Value::Type v152; // rax
  UEL::Value::Type v153; // rdi
  UEL::Value::Type v154; // rax
  UEL::Value::Type v155; // rbx
  UFG::qSymbol *v156; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v157; // rax
  char *v158; // r12
  UEL::Value::Type v159; // rax
  UEL::Value::Type v160; // rdi
  UEL::Value::Type v161; // rax
  UEL::Value::Type v162; // rbx
  UFG::qSymbol *v163; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v164; // rax
  char *v165; // r12
  UEL::Value::Type v166; // rax
  UEL::Value::Type v167; // rdi
  UEL::Value::Type v168; // rax
  UEL::Value::Type v169; // rbx
  UFG::qSymbol *v170; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v171; // rax
  char *v172; // r12
  UEL::Value::Type v173; // rax
  UEL::Value::Type v174; // rdi
  UEL::Value::Type v175; // rax
  UEL::Value::Type v176; // rbx
  UFG::qSymbol *v177; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v178; // rax
  char *v179; // r12
  UEL::Value::Type v180; // rax
  UEL::Value::Type v181; // rdi
  UEL::Value::Type v182; // rax
  UEL::Value::Type v183; // rbx
  UFG::qSymbol *v184; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v185; // rax
  char *v186; // r12
  UFG::qSymbol *v187; // rax
  UEL::Value::Type *v188; // rax
  UEL::Value::Type v189; // rax
  UEL::Value::Type v190; // rdi
  UFG::qSymbol *v191; // rax
  UEL::Value::Type *v192; // rax
  UEL::Value::Type v193; // rax
  UEL::Value::Type v194; // rbx
  UFG::qSymbol *v195; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v196; // rax
  char *v197; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v198; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v199; // r15
  char *v200; // r12
  UEL::Value::Type v201; // rax
  UEL::Value::Type v202; // rdi
  UEL::Value::Type v203; // rax
  UEL::Value::Type v204; // rbx
  UFG::qSymbol *v205; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v206; // rax
  char *v207; // r12
  UEL::Value::Type v208; // rax
  UEL::Value::Type v209; // rdi
  UEL::Value::Type v210; // rax
  UEL::Value::Type v211; // rbx
  UFG::qSymbol *v212; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v213; // rax
  char *v214; // r12
  UEL::Value::Type v215; // rax
  UEL::Value::Type v216; // rdi
  UEL::Value::Type v217; // rax
  UEL::Value::Type v218; // rbx
  UFG::qSymbol *v219; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v220; // rax
  char *v221; // r12
  UFG::qSymbol *v222; // rax
  UEL::Value::Type *v223; // rax
  UEL::Value::Type v224; // rax
  UEL::Value::Type v225; // rdi
  UFG::qSymbol *v226; // rax
  UEL::Value::Type *v227; // rax
  UEL::Value::Type v228; // rax
  UEL::Value::Type v229; // rbx
  UFG::qSymbol *v230; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v231; // rax
  char *v232; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v233; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v234; // r15
  char *v235; // r12
  UEL::Value::Type v236; // rax
  UEL::Value::Type v237; // rdi
  UEL::Value::Type v238; // rax
  UEL::Value::Type v239; // rbx
  UFG::qSymbol *v240; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v241; // rax
  char *v242; // r12
  UEL::Value::Type v243; // rax
  UEL::Value::Type v244; // rdi
  UEL::Value::Type v245; // rax
  UEL::Value::Type v246; // rbx
  UFG::qSymbol *v247; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v248; // rax
  char *v249; // r12
  UEL::Value::Type v250; // rax
  UEL::Value::Type v251; // rdi
  UEL::Value::Type v252; // rax
  UEL::Value::Type v253; // rbx
  UFG::qSymbol *v254; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v255; // rax
  char *v256; // r12
  UEL::Value::Type v257; // rax
  UEL::Value::Type v258; // rdi
  UEL::Value::Type v259; // rax
  UEL::Value::Type v260; // rbx
  UFG::qSymbol *v261; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v262; // rax
  char *v263; // r12
  UFG::qSymbol *v264; // rax
  UEL::Value::Type *v265; // rax
  UEL::Value::Type v266; // rax
  UEL::Value::Type v267; // rdi
  UFG::qSymbol *v268; // rax
  UEL::Value::Type *v269; // rax
  UEL::Value::Type v270; // rax
  UEL::Value::Type v271; // rbx
  UFG::qSymbol *v272; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v273; // rax
  char *v274; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v275; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v276; // r15
  char *v277; // r12
  UEL::Value::Type v278; // rax
  UEL::Value::Type v279; // rdi
  UEL::Value::Type v280; // rax
  UEL::Value::Type v281; // rbx
  UFG::qSymbol *v282; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v283; // rax
  char *v284; // r12
  UEL::Value::Type v285; // rax
  UEL::Value::Type v286; // rdi
  UEL::Value::Type v287; // rax
  UEL::Value::Type v288; // rbx
  UFG::qSymbol *v289; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v290; // rax
  char *v291; // r12
  UEL::Value::Type v292; // rax
  UEL::Value::Type v293; // rdi
  UEL::Value::Type v294; // rax
  UEL::Value::Type v295; // rbx
  UFG::qSymbol *v296; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v297; // rax
  char *v298; // r12
  UFG::qSymbol *v299; // rax
  UEL::Value::Type *v300; // rax
  UEL::Value::Type v301; // rax
  UEL::Value::Type v302; // rdi
  UFG::qSymbol *v303; // rax
  UEL::Value::Type *v304; // rax
  UEL::Value::Type v305; // rax
  UEL::Value::Type v306; // rbx
  UFG::qSymbol *v307; // rax
  UFG::qNodeRB<UEL::ParameterBindingEntry> *v308; // rax
  UEL::Value::Type v309; // [rsp+48h] [rbp-B8h] BYREF
  UEL::Value::Type p_alwaysReturns; // [rsp+50h] [rbp-B0h] BYREF
  UEL::Value::Type v311; // [rsp+58h] [rbp-A8h] BYREF
  UEL::Value::Type v312; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qSymbol v313; // [rsp+68h] [rbp-98h] BYREF
  UFG::qSymbol v314; // [rsp+6Ch] [rbp-94h] BYREF
  UFG::qSymbol v315; // [rsp+70h] [rbp-90h] BYREF
  UFG::qSymbol v316; // [rsp+74h] [rbp-8Ch] BYREF
  UFG::qSymbol v317; // [rsp+78h] [rbp-88h] BYREF
  UFG::qSymbol v318; // [rsp+7Ch] [rbp-84h] BYREF
  UFG::qSymbol v319; // [rsp+80h] [rbp-80h] BYREF
  UFG::qSymbol v320; // [rsp+84h] [rbp-7Ch] BYREF
  UFG::qSymbol v321; // [rsp+88h] [rbp-78h] BYREF
  UFG::qSymbol v322; // [rsp+8Ch] [rbp-74h] BYREF
  __int16 v323; // [rsp+90h] [rbp-70h] BYREF
  unsigned int v324; // [rsp+94h] [rbp-6Ch]
  __int16 v325; // [rsp+98h] [rbp-68h] BYREF
  int v326; // [rsp+9Ch] [rbp-64h]
  __int16 v327; // [rsp+A0h] [rbp-60h] BYREF
  unsigned int v328; // [rsp+A4h] [rbp-5Ch]
  __int16 v329; // [rsp+A8h] [rbp-58h] BYREF
  unsigned int v330; // [rsp+ACh] [rbp-54h]
  __int16 v331; // [rsp+B0h] [rbp-50h] BYREF
  unsigned int v332; // [rsp+B4h] [rbp-4Ch]
  __int16 v333; // [rsp+B8h] [rbp-48h] BYREF
  unsigned int v334; // [rsp+BCh] [rbp-44h]
  __int16 v335; // [rsp+C0h] [rbp-40h] BYREF
  unsigned int v336; // [rsp+C4h] [rbp-3Ch]
  __int16 v337; // [rsp+C8h] [rbp-38h] BYREF
  unsigned int v338; // [rsp+CCh] [rbp-34h]
  __int16 v339; // [rsp+D0h] [rbp-30h] BYREF
  unsigned int v340; // [rsp+D4h] [rbp-2Ch]
  __int16 v341; // [rsp+D8h] [rbp-28h] BYREF
  unsigned int v342; // [rsp+DCh] [rbp-24h]
  __int16 v343; // [rsp+E0h] [rbp-20h] BYREF
  unsigned int v344; // [rsp+E4h] [rbp-1Ch]
  __int16 v345; // [rsp+E8h] [rbp-18h] BYREF
  unsigned int v346; // [rsp+ECh] [rbp-14h]
  __int16 v347; // [rsp+F0h] [rbp-10h] BYREF
  unsigned int v348; // [rsp+F4h] [rbp-Ch]
  __int16 v349; // [rsp+F8h] [rbp-8h] BYREF
  unsigned int v350; // [rsp+FCh] [rbp-4h]
  __int16 v351; // [rsp+100h] [rbp+0h] BYREF
  unsigned int v352; // [rsp+104h] [rbp+4h]
  __int16 v353; // [rsp+108h] [rbp+8h] BYREF
  unsigned int v354; // [rsp+10Ch] [rbp+Ch]
  __int16 v355; // [rsp+110h] [rbp+10h] BYREF
  unsigned int v356; // [rsp+114h] [rbp+14h]
  __int16 v357; // [rsp+118h] [rbp+18h] BYREF
  unsigned int v358; // [rsp+11Ch] [rbp+1Ch]
  __int16 v359; // [rsp+120h] [rbp+20h] BYREF
  unsigned int v360; // [rsp+124h] [rbp+24h]
  __int16 v361; // [rsp+128h] [rbp+28h] BYREF
  unsigned int v362; // [rsp+12Ch] [rbp+2Ch]
  __int16 v363; // [rsp+130h] [rbp+30h] BYREF
  int v364; // [rsp+134h] [rbp+34h]
  __int16 v365; // [rsp+138h] [rbp+38h] BYREF
  unsigned int v366; // [rsp+13Ch] [rbp+3Ch]
  __int16 v367; // [rsp+140h] [rbp+40h] BYREF
  unsigned int v368; // [rsp+144h] [rbp+44h]
  __int16 v369; // [rsp+148h] [rbp+48h] BYREF
  unsigned int v370; // [rsp+14Ch] [rbp+4Ch]
  __int16 v371; // [rsp+150h] [rbp+50h] BYREF
  unsigned int v372; // [rsp+154h] [rbp+54h]
  __int16 v373; // [rsp+158h] [rbp+58h] BYREF
  unsigned int v374; // [rsp+15Ch] [rbp+5Ch]
  __int16 v375; // [rsp+160h] [rbp+60h] BYREF
  unsigned int v376; // [rsp+164h] [rbp+64h]
  __int16 v377; // [rsp+168h] [rbp+68h] BYREF
  unsigned int v378; // [rsp+16Ch] [rbp+6Ch]
  __int16 v379; // [rsp+170h] [rbp+70h] BYREF
  int v380; // [rsp+174h] [rbp+74h]
  __int16 v381; // [rsp+178h] [rbp+78h] BYREF
  unsigned int v382; // [rsp+17Ch] [rbp+7Ch]
  __int16 v383; // [rsp+180h] [rbp+80h] BYREF
  unsigned int v384; // [rsp+184h] [rbp+84h]
  __int16 v385; // [rsp+188h] [rbp+88h] BYREF
  unsigned int v386; // [rsp+18Ch] [rbp+8Ch]
  __int16 v387; // [rsp+190h] [rbp+90h] BYREF
  int v388; // [rsp+194h] [rbp+94h]
  __int16 v389; // [rsp+198h] [rbp+98h] BYREF
  unsigned int v390; // [rsp+19Ch] [rbp+9Ch]
  __int16 v391; // [rsp+1A0h] [rbp+A0h] BYREF
  unsigned int v392; // [rsp+1A4h] [rbp+A4h]
  __int16 v393; // [rsp+1A8h] [rbp+A8h] BYREF
  unsigned int v394; // [rsp+1ACh] [rbp+ACh]
  __int16 v395; // [rsp+1B0h] [rbp+B0h] BYREF
  unsigned int v396; // [rsp+1B4h] [rbp+B4h]
  __int16 v397; // [rsp+1B8h] [rbp+B8h] BYREF
  unsigned int v398; // [rsp+1BCh] [rbp+BCh]
  __int16 v399; // [rsp+1C0h] [rbp+C0h] BYREF
  unsigned int v400; // [rsp+1C4h] [rbp+C4h]
  __int16 v401; // [rsp+1C8h] [rbp+C8h] BYREF
  unsigned int v402; // [rsp+1CCh] [rbp+CCh]
  __int16 v403; // [rsp+1D0h] [rbp+D0h] BYREF
  unsigned int v404; // [rsp+1D4h] [rbp+D4h]
  __int16 v405; // [rsp+1D8h] [rbp+D8h] BYREF
  unsigned int v406; // [rsp+1DCh] [rbp+DCh]
  __int16 v407; // [rsp+1E0h] [rbp+E0h] BYREF
  unsigned int v408; // [rsp+1E4h] [rbp+E4h]
  __int16 v409; // [rsp+1E8h] [rbp+E8h] BYREF
  unsigned int v410; // [rsp+1ECh] [rbp+ECh]
  __int16 v411; // [rsp+1F0h] [rbp+F0h] BYREF
  unsigned int v412; // [rsp+1F4h] [rbp+F4h]
  __int16 v413; // [rsp+1F8h] [rbp+F8h] BYREF
  unsigned int v414; // [rsp+1FCh] [rbp+FCh]
  __int16 v415; // [rsp+200h] [rbp+100h] BYREF
  unsigned int v416; // [rsp+204h] [rbp+104h]
  __int16 v417; // [rsp+208h] [rbp+108h] BYREF
  unsigned int v418; // [rsp+20Ch] [rbp+10Ch]
  __int16 v419; // [rsp+210h] [rbp+110h] BYREF
  unsigned int v420; // [rsp+214h] [rbp+114h]
  __int16 v421; // [rsp+218h] [rbp+118h] BYREF
  unsigned int v422; // [rsp+21Ch] [rbp+11Ch]
  __int16 v423; // [rsp+220h] [rbp+120h] BYREF
  unsigned int v424; // [rsp+224h] [rbp+124h]
  __int16 v425; // [rsp+228h] [rbp+128h] BYREF
  unsigned int v426; // [rsp+22Ch] [rbp+12Ch]
  __int16 v427; // [rsp+230h] [rbp+130h] BYREF
  unsigned int v428; // [rsp+234h] [rbp+134h]
  __int16 v429; // [rsp+238h] [rbp+138h] BYREF
  unsigned int v430; // [rsp+23Ch] [rbp+13Ch]
  __int16 v431; // [rsp+240h] [rbp+140h] BYREF
  unsigned int mUID; // [rsp+244h] [rbp+144h]
  __int16 v433; // [rsp+248h] [rbp+148h] BYREF
  unsigned int v434; // [rsp+24Ch] [rbp+14Ch]
  __int16 v435; // [rsp+250h] [rbp+150h] BYREF
  unsigned int v436; // [rsp+254h] [rbp+154h]
  __int16 v437; // [rsp+258h] [rbp+158h] BYREF
  unsigned int v438; // [rsp+25Ch] [rbp+15Ch]
  __int16 v439; // [rsp+260h] [rbp+160h] BYREF
  unsigned int v440; // [rsp+264h] [rbp+164h]
  __int16 v441; // [rsp+268h] [rbp+168h] BYREF
  unsigned int v442; // [rsp+26Ch] [rbp+16Ch]
  __int16 v443; // [rsp+270h] [rbp+170h] BYREF
  int v444; // [rsp+274h] [rbp+174h]
  __int16 v445; // [rsp+278h] [rbp+178h] BYREF
  unsigned int v446; // [rsp+27Ch] [rbp+17Ch]
  __int16 v447; // [rsp+280h] [rbp+180h] BYREF
  int v448; // [rsp+284h] [rbp+184h]
  __int16 v449; // [rsp+288h] [rbp+188h] BYREF
  unsigned int v450; // [rsp+28Ch] [rbp+18Ch]
  __int16 v451; // [rsp+290h] [rbp+190h] BYREF
  unsigned int v452; // [rsp+294h] [rbp+194h]
  __int16 v453; // [rsp+298h] [rbp+198h] BYREF
  unsigned int v454; // [rsp+29Ch] [rbp+19Ch]
  __int16 v455; // [rsp+2A0h] [rbp+1A0h] BYREF
  int v456; // [rsp+2A4h] [rbp+1A4h]
  __int16 v457; // [rsp+2A8h] [rbp+1A8h] BYREF
  unsigned int v458; // [rsp+2ACh] [rbp+1ACh]
  __int16 v459; // [rsp+2B0h] [rbp+1B0h] BYREF
  int v460; // [rsp+2B4h] [rbp+1B4h]
  __int16 v461; // [rsp+2B8h] [rbp+1B8h] BYREF
  unsigned int v462; // [rsp+2BCh] [rbp+1BCh]
  __int16 v463; // [rsp+2C0h] [rbp+1C0h] BYREF
  unsigned int v464; // [rsp+2C4h] [rbp+1C4h]
  __int16 v465; // [rsp+2C8h] [rbp+1C8h] BYREF
  unsigned int v466; // [rsp+2CCh] [rbp+1CCh]
  __int16 v467; // [rsp+2D0h] [rbp+1D0h] BYREF
  unsigned int v468; // [rsp+2D4h] [rbp+1D4h]
  __int16 v469; // [rsp+2D8h] [rbp+1D8h] BYREF
  unsigned int v470; // [rsp+2DCh] [rbp+1DCh]
  __int16 v471; // [rsp+2E0h] [rbp+1E0h] BYREF
  unsigned int v472; // [rsp+2E4h] [rbp+1E4h]
  __int16 v473; // [rsp+2E8h] [rbp+1E8h] BYREF
  unsigned int v474; // [rsp+2ECh] [rbp+1ECh]
  __int16 v475; // [rsp+2F0h] [rbp+1F0h] BYREF
  unsigned int v476; // [rsp+2F4h] [rbp+1F4h]
  __int16 v477; // [rsp+2F8h] [rbp+1F8h] BYREF
  unsigned int v478; // [rsp+2FCh] [rbp+1FCh]
  UEL::Value::Type v479; // [rsp+300h] [rbp+200h] BYREF
  __int16 v480; // [rsp+308h] [rbp+208h] BYREF
  unsigned int v481; // [rsp+30Ch] [rbp+20Ch]
  __int16 v482; // [rsp+310h] [rbp+210h] BYREF
  unsigned int v483; // [rsp+314h] [rbp+214h]
  __int16 v484; // [rsp+318h] [rbp+218h] BYREF
  unsigned int v485; // [rsp+31Ch] [rbp+21Ch]
  __int16 v486; // [rsp+320h] [rbp+220h] BYREF
  unsigned int v487; // [rsp+324h] [rbp+224h]
  __int16 v488; // [rsp+328h] [rbp+228h] BYREF
  unsigned int v489; // [rsp+32Ch] [rbp+22Ch]
  __int16 v490; // [rsp+330h] [rbp+230h] BYREF
  unsigned int v491; // [rsp+334h] [rbp+234h]
  __int16 v492; // [rsp+338h] [rbp+238h] BYREF
  unsigned int v493; // [rsp+33Ch] [rbp+23Ch]
  __int16 v494; // [rsp+340h] [rbp+240h] BYREF
  unsigned int v495; // [rsp+344h] [rbp+244h]
  __int16 v496; // [rsp+348h] [rbp+248h] BYREF
  unsigned int v497; // [rsp+34Ch] [rbp+24Ch]
  __int16 v498; // [rsp+350h] [rbp+250h] BYREF
  unsigned int v499; // [rsp+354h] [rbp+254h]
  __int16 v500; // [rsp+358h] [rbp+258h] BYREF
  unsigned int v501; // [rsp+35Ch] [rbp+25Ch]
  __int16 v502; // [rsp+360h] [rbp+260h] BYREF
  unsigned int v503; // [rsp+364h] [rbp+264h]
  __int16 v504; // [rsp+368h] [rbp+268h] BYREF
  unsigned int v505; // [rsp+36Ch] [rbp+26Ch]
  __int16 v506; // [rsp+370h] [rbp+270h] BYREF
  unsigned int v507; // [rsp+374h] [rbp+274h]
  __int16 v508; // [rsp+378h] [rbp+278h] BYREF
  unsigned int v509; // [rsp+37Ch] [rbp+27Ch]
  __int16 v510; // [rsp+380h] [rbp+280h] BYREF
  unsigned int v511; // [rsp+384h] [rbp+284h]
  __int16 v512; // [rsp+388h] [rbp+288h] BYREF
  unsigned int v513; // [rsp+38Ch] [rbp+28Ch]
  __int16 v514; // [rsp+390h] [rbp+290h] BYREF
  unsigned int v515; // [rsp+394h] [rbp+294h]
  __int16 v516; // [rsp+398h] [rbp+298h] BYREF
  unsigned int v517; // [rsp+39Ch] [rbp+29Ch]
  __int16 v518; // [rsp+3A0h] [rbp+2A0h] BYREF
  unsigned int v519; // [rsp+3A4h] [rbp+2A4h]
  __int16 v520; // [rsp+3A8h] [rbp+2A8h] BYREF
  unsigned int v521; // [rsp+3ACh] [rbp+2ACh]
  __int16 v522; // [rsp+3B0h] [rbp+2B0h] BYREF
  unsigned int v523; // [rsp+3B4h] [rbp+2B4h]
  __int16 v524; // [rsp+3B8h] [rbp+2B8h] BYREF
  unsigned int v525; // [rsp+3BCh] [rbp+2BCh]
  __int16 v526; // [rsp+3C0h] [rbp+2C0h] BYREF
  unsigned int v527; // [rsp+3C4h] [rbp+2C4h]
  UEL::Value::Type v528; // [rsp+3C8h] [rbp+2C8h] BYREF
  UFG::qSymbol v529; // [rsp+3D0h] [rbp+2D0h] BYREF
  UFG::qSymbol v530; // [rsp+3D4h] [rbp+2D4h] BYREF
  UFG::qSymbol v531; // [rsp+3D8h] [rbp+2D8h] BYREF
  UFG::qSymbol v532; // [rsp+3DCh] [rbp+2DCh] BYREF
  UFG::qSymbol v533; // [rsp+3E0h] [rbp+2E0h] BYREF
  UFG::qSymbol v534; // [rsp+3E4h] [rbp+2E4h] BYREF
  UFG::qSymbol v535; // [rsp+3E8h] [rbp+2E8h] BYREF
  UFG::qSymbol v536; // [rsp+3ECh] [rbp+2ECh] BYREF
  UFG::qSymbol v537; // [rsp+3F0h] [rbp+2F0h] BYREF
  UFG::qSymbol v538; // [rsp+3F4h] [rbp+2F4h] BYREF
  UFG::qSymbol v539; // [rsp+3F8h] [rbp+2F8h] BYREF
  UFG::qSymbol result; // [rsp+3FCh] [rbp+2FCh] BYREF
  UFG::qSymbol v541; // [rsp+400h] [rbp+300h] BYREF
  UFG::qSymbol v542; // [rsp+404h] [rbp+304h] BYREF
  UFG::qSymbol v543; // [rsp+408h] [rbp+308h] BYREF
  UFG::qSymbol v544; // [rsp+40Ch] [rbp+30Ch] BYREF
  UFG::qSymbol v545; // [rsp+410h] [rbp+310h] BYREF
  UFG::qSymbol v546; // [rsp+414h] [rbp+314h] BYREF
  UFG::qSymbol v547; // [rsp+418h] [rbp+318h] BYREF
  UFG::qSymbol v548; // [rsp+41Ch] [rbp+31Ch] BYREF
  UFG::qSymbol v549; // [rsp+420h] [rbp+320h] BYREF
  UFG::qSymbol v550; // [rsp+424h] [rbp+324h] BYREF
  UFG::qSymbol v551; // [rsp+428h] [rbp+328h] BYREF
  UFG::qSymbol v552; // [rsp+42Ch] [rbp+32Ch] BYREF
  UFG::qSymbol v553; // [rsp+430h] [rbp+330h] BYREF
  UFG::qSymbol v554; // [rsp+434h] [rbp+334h] BYREF
  UFG::qSymbol v555; // [rsp+438h] [rbp+338h] BYREF
  UFG::qSymbol v556; // [rsp+43Ch] [rbp+33Ch] BYREF
  UFG::qSymbol v557; // [rsp+440h] [rbp+340h] BYREF
  UFG::qSymbol v558; // [rsp+444h] [rbp+344h] BYREF
  UFG::qSymbol v559; // [rsp+448h] [rbp+348h] BYREF
  UFG::qSymbol v560; // [rsp+44Ch] [rbp+34Ch] BYREF
  UFG::qSymbol v561; // [rsp+450h] [rbp+350h] BYREF
  UFG::qSymbol v562; // [rsp+454h] [rbp+354h] BYREF
  UFG::qSymbol v563; // [rsp+458h] [rbp+358h] BYREF
  UFG::qSymbol v564; // [rsp+45Ch] [rbp+35Ch] BYREF
  UFG::qSymbol v565; // [rsp+460h] [rbp+360h] BYREF
  UFG::qSymbol v566; // [rsp+464h] [rbp+364h] BYREF
  UFG::qSymbol v567; // [rsp+468h] [rbp+368h] BYREF
  UFG::qSymbol v568; // [rsp+46Ch] [rbp+36Ch] BYREF
  UFG::qSymbol v569; // [rsp+470h] [rbp+370h] BYREF
  UFG::qSymbol v570; // [rsp+474h] [rbp+374h] BYREF
  UFG::qSymbol v571; // [rsp+478h] [rbp+378h] BYREF
  UFG::qSymbol v572; // [rsp+47Ch] [rbp+37Ch] BYREF
  UFG::qSymbol v573; // [rsp+480h] [rbp+380h] BYREF
  UFG::qSymbol v574; // [rsp+484h] [rbp+384h] BYREF
  UFG::qSymbol v575; // [rsp+488h] [rbp+388h] BYREF
  UFG::qSymbol v576; // [rsp+48Ch] [rbp+38Ch] BYREF
  UFG::qSymbol v577; // [rsp+490h] [rbp+390h] BYREF
  UFG::qSymbol v578; // [rsp+494h] [rbp+394h] BYREF
  UFG::qSymbol v579; // [rsp+498h] [rbp+398h] BYREF
  UFG::qSymbol v580; // [rsp+49Ch] [rbp+39Ch] BYREF
  UFG::qSymbol v581; // [rsp+4A0h] [rbp+3A0h] BYREF
  UFG::qSymbol v582; // [rsp+4A4h] [rbp+3A4h] BYREF
  UFG::qSymbol v583; // [rsp+4A8h] [rbp+3A8h] BYREF
  UFG::qSymbol v584; // [rsp+4ACh] [rbp+3ACh] BYREF
  UFG::qSymbol v585; // [rsp+4B0h] [rbp+3B0h] BYREF
  UFG::qSymbol v586; // [rsp+4B4h] [rbp+3B4h] BYREF
  UFG::qSymbol v587; // [rsp+4B8h] [rbp+3B8h] BYREF
  UFG::qSymbol v588; // [rsp+4BCh] [rbp+3BCh] BYREF
  UFG::qSymbol v589; // [rsp+4C0h] [rbp+3C0h] BYREF
  UFG::qSymbol v590; // [rsp+4C4h] [rbp+3C4h] BYREF
  UFG::qSymbol v591; // [rsp+4C8h] [rbp+3C8h] BYREF
  UFG::qSymbol v592; // [rsp+4CCh] [rbp+3CCh] BYREF
  UFG::qSymbol v593; // [rsp+4D0h] [rbp+3D0h] BYREF
  UFG::qSymbol v594; // [rsp+4D4h] [rbp+3D4h] BYREF
  UFG::qSymbol v595; // [rsp+4D8h] [rbp+3D8h] BYREF
  UFG::qSymbol v596; // [rsp+4DCh] [rbp+3DCh] BYREF
  UFG::qSymbol v597; // [rsp+4E0h] [rbp+3E0h] BYREF
  UFG::qSymbol v598; // [rsp+4E4h] [rbp+3E4h] BYREF
  UFG::qSymbol v599; // [rsp+4E8h] [rbp+3E8h] BYREF
  UFG::qSymbol v600; // [rsp+4ECh] [rbp+3ECh] BYREF
  UFG::qSymbol v601; // [rsp+4F0h] [rbp+3F0h] BYREF
  UFG::qSymbol v602; // [rsp+4F4h] [rbp+3F4h] BYREF
  UFG::qSymbol v603; // [rsp+4F8h] [rbp+3F8h] BYREF
  UFG::qSymbol v604; // [rsp+4FCh] [rbp+3FCh] BYREF
  UFG::qSymbol v605; // [rsp+500h] [rbp+400h] BYREF
  UFG::qSymbol v606; // [rsp+504h] [rbp+404h] BYREF
  UFG::qSymbol v607; // [rsp+508h] [rbp+408h] BYREF
  UFG::qSymbol v608; // [rsp+50Ch] [rbp+40Ch] BYREF
  UFG::qSymbol source; // [rsp+510h] [rbp+410h] BYREF
  UFG::qSymbol v610; // [rsp+514h] [rbp+414h] BYREF
  UFG::qSymbol v611[2]; // [rsp+518h] [rbp+418h] BYREF
  UFG::qSymbol v612; // [rsp+520h] [rbp+420h] BYREF
  UEL::Value::Type alwaysReturns; // [rsp+528h] [rbp+428h] BYREF
  UFG::qSymbol v614; // [rsp+530h] [rbp+430h] BYREF
  qEnum<enum UEL::Value::BaseType,unsigned short> v615; // [rsp+538h] [rbp+438h] BYREF
  UFG::qSymbol v616; // [rsp+53Ch] [rbp+43Ch] BYREF
  UFG::qSymbol v617; // [rsp+540h] [rbp+440h] BYREF
  UFG::qSymbol v618; // [rsp+544h] [rbp+444h] BYREF
  UFG::qSymbol v619; // [rsp+548h] [rbp+448h] BYREF
  UFG::qSymbol v620; // [rsp+54Ch] [rbp+44Ch] BYREF
  UFG::qSymbol v621[2]; // [rsp+550h] [rbp+450h] BYREF
  UFG::qSymbol v622[2]; // [rsp+558h] [rbp+458h] BYREF
  unsigned int v623; // [rsp+560h] [rbp+460h]
  __int16 v624; // [rsp+564h] [rbp+464h]
  int v625; // [rsp+568h] [rbp+468h]
  __int16 v626; // [rsp+56Ch] [rbp+46Ch]
  int v627; // [rsp+570h] [rbp+470h]
  unsigned int v628; // [rsp+574h] [rbp+474h]
  __int16 v629; // [rsp+578h] [rbp+478h]
  int v630; // [rsp+57Ch] [rbp+47Ch]
  unsigned int v631; // [rsp+580h] [rbp+480h]
  __int16 v632; // [rsp+584h] [rbp+484h]
  unsigned int v633; // [rsp+588h] [rbp+488h]
  unsigned int v634; // [rsp+58Ch] [rbp+48Ch]
  __int16 v635; // [rsp+590h] [rbp+490h]
  unsigned int v636; // [rsp+594h] [rbp+494h]
  unsigned int v637; // [rsp+598h] [rbp+498h]
  __int16 v638; // [rsp+59Ch] [rbp+49Ch]
  unsigned int v639; // [rsp+5A0h] [rbp+4A0h]
  unsigned int v640; // [rsp+5A4h] [rbp+4A4h]
  __int16 v641; // [rsp+5A8h] [rbp+4A8h]
  unsigned int v642; // [rsp+5ACh] [rbp+4ACh]
  unsigned int v643; // [rsp+5B0h] [rbp+4B0h]
  __int16 v644; // [rsp+5B4h] [rbp+4B4h]
  unsigned int v645; // [rsp+5B8h] [rbp+4B8h]
  unsigned int v646; // [rsp+5BCh] [rbp+4BCh]
  __int16 v647; // [rsp+5C0h] [rbp+4C0h]
  unsigned int v648; // [rsp+5C4h] [rbp+4C4h]
  unsigned int v649; // [rsp+5C8h] [rbp+4C8h]
  __int16 v650; // [rsp+5CCh] [rbp+4CCh]
  unsigned int v651; // [rsp+5D0h] [rbp+4D0h]
  unsigned int v652; // [rsp+5D4h] [rbp+4D4h]
  __int16 v653; // [rsp+5D8h] [rbp+4D8h]
  unsigned int v654; // [rsp+5DCh] [rbp+4DCh]
  unsigned int v655; // [rsp+5E0h] [rbp+4E0h]
  __int16 v656; // [rsp+5E4h] [rbp+4E4h]
  unsigned int v657; // [rsp+5E8h] [rbp+4E8h]
  int v658; // [rsp+5ECh] [rbp+4ECh]
  __int16 v659; // [rsp+5F0h] [rbp+4F0h]
  unsigned int v660; // [rsp+5F4h] [rbp+4F4h]
  unsigned int v661; // [rsp+5F8h] [rbp+4F8h]
  __int16 v662; // [rsp+5FCh] [rbp+4FCh]
  unsigned int v663; // [rsp+600h] [rbp+500h]
  int v664; // [rsp+604h] [rbp+504h]
  __int16 v665; // [rsp+608h] [rbp+508h]
  unsigned int v666; // [rsp+60Ch] [rbp+50Ch]
  unsigned int v667; // [rsp+610h] [rbp+510h]
  UEL::Value::Type v668; // [rsp+618h] [rbp+518h] BYREF
  unsigned int v669; // [rsp+620h] [rbp+520h]
  UEL::Value::Type v670; // [rsp+628h] [rbp+528h] BYREF
  unsigned int v671; // [rsp+630h] [rbp+530h]
  UEL::Value::Type v672; // [rsp+638h] [rbp+538h] BYREF
  unsigned int v673; // [rsp+640h] [rbp+540h]
  UEL::Value::Type v674; // [rsp+648h] [rbp+548h] BYREF
  unsigned int v675; // [rsp+650h] [rbp+550h]
  UEL::Value::Type v676; // [rsp+658h] [rbp+558h] BYREF
  unsigned int v677; // [rsp+660h] [rbp+560h]
  UEL::Value::Type v678; // [rsp+668h] [rbp+568h] BYREF
  unsigned int v679; // [rsp+670h] [rbp+570h]
  UEL::Value::Type v680; // [rsp+678h] [rbp+578h] BYREF
  unsigned int v681; // [rsp+680h] [rbp+580h]
  UEL::Value::Type v682; // [rsp+688h] [rbp+588h] BYREF
  unsigned int v683; // [rsp+690h] [rbp+590h]
  UEL::Value::Type v684; // [rsp+698h] [rbp+598h] BYREF
  unsigned int v685; // [rsp+6A0h] [rbp+5A0h]
  UEL::Value::Type v686; // [rsp+6A8h] [rbp+5A8h] BYREF
  unsigned int v687; // [rsp+6B0h] [rbp+5B0h]
  UEL::Value::Type v688; // [rsp+6B8h] [rbp+5B8h] BYREF
  unsigned int v689; // [rsp+6C0h] [rbp+5C0h]
  UEL::Value::Type v690; // [rsp+6C8h] [rbp+5C8h] BYREF
  UFG::qSymbol v691; // [rsp+6D0h] [rbp+5D0h] BYREF
  UEL::Value::Type v692; // [rsp+6D8h] [rbp+5D8h] BYREF
  UFG::qSymbol v693; // [rsp+6E0h] [rbp+5E0h] BYREF
  UEL::Value::Type v694; // [rsp+6E8h] [rbp+5E8h] BYREF
  UFG::qSymbol v695; // [rsp+6F0h] [rbp+5F0h] BYREF
  UEL::Value::Type v696; // [rsp+6F8h] [rbp+5F8h] BYREF
  UFG::qSymbol v697; // [rsp+700h] [rbp+600h] BYREF
  UEL::Value::Type v698; // [rsp+708h] [rbp+608h] BYREF
  unsigned int v699; // [rsp+710h] [rbp+610h]
  UEL::Value::Type v700; // [rsp+718h] [rbp+618h] BYREF
  int v701; // [rsp+720h] [rbp+620h]
  UEL::Value::Type v702; // [rsp+728h] [rbp+628h] BYREF
  int v703; // [rsp+730h] [rbp+630h]
  UEL::Value::Type v704; // [rsp+738h] [rbp+638h] BYREF
  int v705; // [rsp+740h] [rbp+640h]
  UEL::Value::Type v706; // [rsp+748h] [rbp+648h] BYREF
  unsigned int v707; // [rsp+750h] [rbp+650h]
  UEL::Value::Type v708; // [rsp+758h] [rbp+658h] BYREF
  __int16 v709; // [rsp+760h] [rbp+660h]
  unsigned int v710; // [rsp+764h] [rbp+664h]
  UEL::Value::Type v711; // [rsp+768h] [rbp+668h] BYREF
  __int16 v712; // [rsp+770h] [rbp+670h]
  unsigned int v713; // [rsp+774h] [rbp+674h]
  UEL::Value::Type v714; // [rsp+778h] [rbp+678h] BYREF
  __int16 v715; // [rsp+780h] [rbp+680h]
  int v716; // [rsp+784h] [rbp+684h]
  UEL::Value::Type v717; // [rsp+788h] [rbp+688h] BYREF
  __int16 v718; // [rsp+790h] [rbp+690h]
  int v719; // [rsp+794h] [rbp+694h]
  UEL::Value::Type v720; // [rsp+798h] [rbp+698h] BYREF
  unsigned int v721; // [rsp+7A0h] [rbp+6A0h]
  UEL::Value::Type v722; // [rsp+7A8h] [rbp+6A8h] BYREF
  unsigned int v723; // [rsp+7B0h] [rbp+6B0h]
  UEL::Value::Type v724; // [rsp+7B8h] [rbp+6B8h] BYREF
  unsigned int v725; // [rsp+7C0h] [rbp+6C0h]
  UEL::Value::Type v726; // [rsp+7C8h] [rbp+6C8h] BYREF
  unsigned int v727; // [rsp+7D0h] [rbp+6D0h]
  UEL::Value::Type v728; // [rsp+7D8h] [rbp+6D8h] BYREF
  unsigned int v729; // [rsp+7E0h] [rbp+6E0h]
  UEL::Value::Type v730; // [rsp+7E8h] [rbp+6E8h] BYREF
  int v731; // [rsp+7F0h] [rbp+6F0h]
  UEL::Value::Type v732; // [rsp+7F8h] [rbp+6F8h] BYREF
  int v733; // [rsp+800h] [rbp+700h]
  UEL::Value::Type v734; // [rsp+808h] [rbp+708h] BYREF
  unsigned int v735; // [rsp+810h] [rbp+710h]
  UEL::Value::Type v736; // [rsp+818h] [rbp+718h] BYREF
  unsigned int v737; // [rsp+820h] [rbp+720h]
  UEL::Value::Type v738; // [rsp+828h] [rbp+728h] BYREF
  unsigned int v739; // [rsp+830h] [rbp+730h]
  UEL::Value::Type v740; // [rsp+838h] [rbp+738h] BYREF
  unsigned int v741; // [rsp+840h] [rbp+740h]
  UEL::Value::Type v742; // [rsp+848h] [rbp+748h] BYREF
  unsigned int v743; // [rsp+850h] [rbp+750h]
  UEL::Value::Type v744; // [rsp+858h] [rbp+758h] BYREF
  unsigned int v745; // [rsp+860h] [rbp+760h]
  int v746; // [rsp+864h] [rbp+764h]
  unsigned int v747; // [rsp+868h] [rbp+768h]
  int v748; // [rsp+86Ch] [rbp+76Ch]
  unsigned int v749; // [rsp+870h] [rbp+770h]
  unsigned int v750; // [rsp+874h] [rbp+774h]
  unsigned int v751; // [rsp+878h] [rbp+778h]
  unsigned int v752; // [rsp+87Ch] [rbp+77Ch]
  unsigned int v753; // [rsp+880h] [rbp+780h]
  unsigned int v754; // [rsp+884h] [rbp+784h]
  __int16 v755; // [rsp+888h] [rbp+788h]
  unsigned int v756; // [rsp+88Ch] [rbp+78Ch]
  unsigned int v757; // [rsp+890h] [rbp+790h]
  __int16 v758; // [rsp+894h] [rbp+794h]
  int v759; // [rsp+898h] [rbp+798h]
  unsigned int v760; // [rsp+89Ch] [rbp+79Ch]
  unsigned int v761; // [rsp+8A0h] [rbp+7A0h]
  unsigned int v762; // [rsp+8A4h] [rbp+7A4h]
  unsigned int v763; // [rsp+8A8h] [rbp+7A8h]
  unsigned int v764; // [rsp+8ACh] [rbp+7ACh]
  unsigned int v765; // [rsp+8B0h] [rbp+7B0h]
  unsigned int v766; // [rsp+8B4h] [rbp+7B4h]
  unsigned int v767; // [rsp+8B8h] [rbp+7B8h]
  int v768; // [rsp+8BCh] [rbp+7BCh]
  unsigned int v769; // [rsp+8C0h] [rbp+7C0h]
  __int16 v770; // [rsp+8C4h] [rbp+7C4h]
  int v771; // [rsp+8C8h] [rbp+7C8h]
  unsigned int v772; // [rsp+8CCh] [rbp+7CCh]
  unsigned int v773; // [rsp+8D0h] [rbp+7D0h]
  int v774; // [rsp+8D4h] [rbp+7D4h]
  unsigned int v775; // [rsp+8D8h] [rbp+7D8h]
  unsigned int v776; // [rsp+8DCh] [rbp+7DCh]
  int v777; // [rsp+8E0h] [rbp+7E0h]
  __int16 v778; // [rsp+8E4h] [rbp+7E4h]
  unsigned int v779; // [rsp+8E8h] [rbp+7E8h]
  unsigned int v780; // [rsp+8ECh] [rbp+7ECh]
  __int16 v781; // [rsp+8F0h] [rbp+7F0h]
  int v782; // [rsp+8F4h] [rbp+7F4h]
  __int64 v783; // [rsp+8F8h] [rbp+7F8h]
  UFG::qSymbol *v784; // [rsp+900h] [rbp+800h]
  UEL::Value::Type *v785; // [rsp+908h] [rbp+808h]
  UEL::Value::Type v786; // [rsp+910h] [rbp+810h] BYREF
  UFG::qSymbol *v787; // [rsp+918h] [rbp+818h]
  UEL::Value::Type v788; // [rsp+920h] [rbp+820h] BYREF
  UFG::qSymbol *v789; // [rsp+928h] [rbp+828h]
  UEL::Value::Type v790; // [rsp+930h] [rbp+830h] BYREF
  UEL::Value::Type v791; // [rsp+938h] [rbp+838h] BYREF
  UEL::Value::Type v792; // [rsp+940h] [rbp+840h] BYREF
  UEL::Value::Type v793; // [rsp+948h] [rbp+848h] BYREF
  UEL::Value::Type v794; // [rsp+950h] [rbp+850h] BYREF
  __int64 v795; // [rsp+958h] [rbp+858h]
  __int64 v796; // [rsp+960h] [rbp+860h]
  UEL::Value::Type v797; // [rsp+968h] [rbp+868h] BYREF
  __int64 v798; // [rsp+970h] [rbp+870h]
  __int64 v799; // [rsp+978h] [rbp+878h]
  UEL::Value::Type *v800; // [rsp+980h] [rbp+880h]
  __int64 v801; // [rsp+988h] [rbp+888h]
  __int64 v802; // [rsp+990h] [rbp+890h]
  char *v803; // [rsp+998h] [rbp+898h]
  UEL::Value::Type v804; // [rsp+9A0h] [rbp+8A0h] BYREF
  UFG::ScalingPreset::RegionValues v805; // [rsp+9B0h] [rbp+8B0h] BYREF
  __int64 v806; // [rsp+A00h] [rbp+900h]
  __int64 v807; // [rsp+A08h] [rbp+908h]
  __int64 v808; // [rsp+A10h] [rbp+910h]
  __int64 v809; // [rsp+A18h] [rbp+918h]
  __int64 v810; // [rsp+A20h] [rbp+920h]
  __int64 v811; // [rsp+A28h] [rbp+928h]
  __int64 v812; // [rsp+A30h] [rbp+930h]
  __int64 v813; // [rsp+A38h] [rbp+938h]
  __int64 v814; // [rsp+A40h] [rbp+940h]
  __int64 v815; // [rsp+A48h] [rbp+948h]
  UFG::allocator::free_link *v816; // [rsp+AF0h] [rbp+9F0h] BYREF
  __int16 *v817; // [rsp+AF8h] [rbp+9F8h] BYREF
  __int16 *v818; // [rsp+B00h] [rbp+A00h] BYREF
  __int16 *v819; // [rsp+B08h] [rbp+A08h] BYREF

  v783 = -2i64;
  v2 = 0i64;
  v806 = 0i64;
  v807 = 0i64;
  v808 = 0i64;
  v809 = 0i64;
  v810 = 0i64;
  v811 = 0i64;
  v812 = 0i64;
  v813 = 0i64;
  v814 = 0i64;
  v815 = 0i64;
  UFG::qSymbol::create_from_string(&result, "Properties");
  v3 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v816 = v3;
  if ( v3 )
  {
    v817 = &v431;
    v818 = &v331;
    v431 = 0;
    mUID = UFG::gNullQSymbol.mUID;
    v331 = 9;
    v332 = UFG::gNullQSymbol.mUID;
    v4 = result.mUID;
    v767 = result.mUID;
    v3->mNext = 0i64;
    v3[1].mNext = 0i64;
    v3[2].mNext = 0i64;
    LODWORD(v3[3].mNext) = v4;
    LODWORD(v3[4].mNext) = v4;
    WORD2(v3[4].mNext) = v331;
    LODWORD(v3[5].mNext) = v332;
    WORD2(v3[5].mNext) = v431;
    LODWORD(v3[6].mNext) = mUID;
    BYTE4(v3[6].mNext) = 0;
    LODWORD(v3[7].mNext) = 0;
    v3[8].mNext = 0i64;
    LOBYTE(v3[9].mNext) = 0;
  }
  else
  {
    v3 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v3);
  UFG::qSymbol::create_from_string(&v618, "GangMember2");
  v5 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v816 = v5;
  if ( v5 )
  {
    v817 = &v522;
    v818 = &v335;
    v6 = UFG::qSymbol::create_from_string(&v691, "GangMemberStatData2");
    v755 = 8;
    v756 = v6->mUID;
    v522 = 8;
    v523 = v756;
    v335 = 10;
    v336 = UFG::gNullQSymbol.mUID;
    LODWORD(v6) = v618;
    v747 = v618.mUID;
    v5->mNext = 0i64;
    v5[1].mNext = 0i64;
    v5[2].mNext = 0i64;
    LODWORD(v5[3].mNext) = (_DWORD)v6;
    LODWORD(v5[4].mNext) = (_DWORD)v6;
    WORD2(v5[4].mNext) = v335;
    LODWORD(v5[5].mNext) = v336;
    WORD2(v5[5].mNext) = v522;
    LODWORD(v5[6].mNext) = v523;
    BYTE4(v5[6].mNext) = 1;
    LODWORD(v5[7].mNext) = 16;
    v5[8].mNext = 0i64;
    LOBYTE(v5[9].mNext) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v5);
  UFG::qSymbol::create_from_string(&v620, "MeleeWeapon2");
  v7 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v816 = v7;
  if ( v7 )
  {
    v817 = &v435;
    v818 = &v339;
    v8 = UFG::qSymbol::create_from_string(&v693, "MeleeWeaponStatData2");
    v709 = 8;
    v710 = v8->mUID;
    v435 = 8;
    v436 = v710;
    v339 = 10;
    v340 = UFG::gNullQSymbol.mUID;
    LODWORD(v8) = v620;
    v769 = v620.mUID;
    v7->mNext = 0i64;
    v7[1].mNext = 0i64;
    v7[2].mNext = 0i64;
    LODWORD(v7[3].mNext) = (_DWORD)v8;
    LODWORD(v7[4].mNext) = (_DWORD)v8;
    WORD2(v7[4].mNext) = v339;
    LODWORD(v7[5].mNext) = v340;
    WORD2(v7[5].mNext) = v435;
    LODWORD(v7[6].mNext) = v436;
    BYTE4(v7[6].mNext) = 1;
    LODWORD(v7[7].mNext) = 32;
    v7[8].mNext = 0i64;
    LOBYTE(v7[9].mNext) = 0;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v7);
  UFG::qSymbol::create_from_string(&v608, "RangedWeapon2");
  v9 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v816 = v9;
  if ( v9 )
  {
    v817 = &v323;
    v818 = &v343;
    v10 = UFG::qSymbol::create_from_string(&v695, "RangedWeaponStatData2");
    v778 = 8;
    v779 = v10->mUID;
    v323 = 8;
    v324 = v779;
    v343 = 10;
    v344 = UFG::gNullQSymbol.mUID;
    LODWORD(v10) = v608;
    v749 = v608.mUID;
    v9->mNext = 0i64;
    v9[1].mNext = 0i64;
    v9[2].mNext = 0i64;
    LODWORD(v9[3].mNext) = (_DWORD)v10;
    LODWORD(v9[4].mNext) = (_DWORD)v10;
    WORD2(v9[4].mNext) = v343;
    LODWORD(v9[5].mNext) = v344;
    WORD2(v9[5].mNext) = v323;
    LODWORD(v9[6].mNext) = v324;
    BYTE4(v9[6].mNext) = 1;
    LODWORD(v9[7].mNext) = 48;
    v9[8].mNext = 0i64;
    LOBYTE(v9[9].mNext) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v9);
  UFG::qSymbol::create_from_string(&v532, "ThrownWeapon2");
  v11 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v816 = v11;
  if ( v11 )
  {
    v817 = &v347;
    v818 = &v482;
    v12 = UFG::qSymbol::create_from_string(&v697, "ThrownWeaponStatData2");
    v712 = 8;
    v713 = v12->mUID;
    v347 = 8;
    v348 = v713;
    v482 = 10;
    v483 = UFG::gNullQSymbol.mUID;
    LODWORD(v12) = v532;
    v772 = v532.mUID;
    v11->mNext = 0i64;
    v11[1].mNext = 0i64;
    v11[2].mNext = 0i64;
    LODWORD(v11[3].mNext) = (_DWORD)v12;
    LODWORD(v11[4].mNext) = (_DWORD)v12;
    WORD2(v11[4].mNext) = v482;
    LODWORD(v11[5].mNext) = v483;
    WORD2(v11[5].mNext) = v347;
    LODWORD(v11[6].mNext) = v348;
    BYTE4(v11[6].mNext) = 1;
    LODWORD(v11[7].mNext) = 64;
    v11[8].mNext = 0i64;
    LOBYTE(v11[9].mNext) = 0;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v11);
  v13 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v14 = v13;
  v817 = (__int16 *)v13;
  if ( v13 )
    UFG::qBaseTreeRB::qBaseTreeRB(v13);
  else
    v14 = 0i64;
  UFG::qSymbol::create_from_string(&v529, "Current");
  v15 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v817 = (__int16 *)v15;
  if ( v15 )
  {
    v818 = &v351;
    v819 = &v439;
    v351 = 4;
    v352 = UFG::gNullQSymbol.mUID;
    v439 = 4;
    v440 = UFG::gNullQSymbol.mUID;
    v16 = v529.mUID;
    v699 = v529.mUID;
    v15->mNext = 0i64;
    v15[1].mNext = 0i64;
    v15[2].mNext = 0i64;
    LODWORD(v15[3].mNext) = v16;
    LODWORD(v15[4].mNext) = v16;
    WORD2(v15[4].mNext) = v439;
    LODWORD(v15[5].mNext) = v440;
    WORD2(v15[5].mNext) = v351;
    LODWORD(v15[6].mNext) = v352;
    BYTE4(v15[6].mNext) = 0;
    LODWORD(v15[7].mNext) = 0;
    v15[8].mNext = 0i64;
    LOBYTE(v15[9].mNext) = 0;
  }
  else
  {
    v15 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v14, (UFG::qBaseNodeRB *)v15);
  UFG::qSymbol::create_from_string(&v548, "Max");
  v17 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v817 = (__int16 *)v17;
  if ( v17 )
  {
    v818 = &v355;
    v819 = &v506;
    v355 = 4;
    v356 = UFG::gNullQSymbol.mUID;
    v506 = 4;
    v507 = UFG::gNullQSymbol.mUID;
    v18 = v548.mUID;
    v751 = v548.mUID;
    v17->mNext = 0i64;
    v17[1].mNext = 0i64;
    v17[2].mNext = 0i64;
    LODWORD(v17[3].mNext) = v18;
    LODWORD(v17[4].mNext) = v18;
    WORD2(v17[4].mNext) = v506;
    LODWORD(v17[5].mNext) = v507;
    WORD2(v17[5].mNext) = v355;
    LODWORD(v17[6].mNext) = v356;
    BYTE4(v17[6].mNext) = 0;
    LODWORD(v17[7].mNext) = 8;
    v17[8].mNext = 0i64;
    LOBYTE(v17[9].mNext) = 0;
  }
  else
  {
    v17 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v14, (UFG::qBaseNodeRB *)v17);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v816, "Health");
  v19 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v817 = (__int16 *)v19;
  if ( v19 )
  {
    v818 = &v325;
    v819 = &v443;
    v701 = (int)v816;
    v758 = 8;
    v759 = (int)v816;
    v325 = 8;
    v326 = (int)v816;
    v774 = (int)v816;
    v715 = 8;
    v716 = (int)v816;
    v443 = 8;
    v444 = (int)v816;
    v20 = (int)v816;
    v703 = (int)v816;
    v19->mNext = 0i64;
    v19[1].mNext = 0i64;
    v19[2].mNext = 0i64;
    LODWORD(v19[3].mNext) = v20;
    LODWORD(v19[4].mNext) = v20;
    WORD2(v19[4].mNext) = v443;
    LODWORD(v19[5].mNext) = v444;
    WORD2(v19[5].mNext) = v325;
    LODWORD(v19[6].mNext) = v326;
    BYTE4(v19[6].mNext) = 0;
    LODWORD(v19[7].mNext) = 80;
    v19[8].mNext = (UFG::allocator::free_link *)v14;
    LOBYTE(v19[9].mNext) = 1;
  }
  else
  {
    v19 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v19);
  v21 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v22 = v21;
  v818 = (__int16 *)v21;
  if ( v21 )
    UFG::qBaseTreeRB::qBaseTreeRB(v21);
  else
    v22 = 0i64;
  UFG::qSymbol::create_from_string(&v610, "AimIntention");
  v23 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v818 = (__int16 *)v23;
  if ( v23 )
  {
    v819 = &v486;
    v309 = (UEL::Value::Type)&v359;
    v486 = 7;
    v487 = UFG::gNullQSymbol.mUID;
    v359 = 7;
    v360 = UFG::gNullQSymbol.mUID;
    v24 = v610.mUID;
    v753 = v610.mUID;
    v23->mNext = 0i64;
    v23[1].mNext = 0i64;
    v23[2].mNext = 0i64;
    LODWORD(v23[3].mNext) = v24;
    LODWORD(v23[4].mNext) = v24;
    WORD2(v23[4].mNext) = v359;
    LODWORD(v23[5].mNext) = v360;
    WORD2(v23[5].mNext) = v486;
    LODWORD(v23[6].mNext) = v487;
    BYTE4(v23[6].mNext) = 0;
    LODWORD(v23[7].mNext) = 0;
    v23[8].mNext = 0i64;
    LOBYTE(v23[9].mNext) = 0;
  }
  else
  {
    v23 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v22, (UFG::qBaseNodeRB *)v23);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v817, "Aiming");
  v25 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v818 = (__int16 *)v25;
  if ( v25 )
  {
    v819 = &v447;
    v309 = (UEL::Value::Type)&v363;
    v705 = (int)v817;
    v781 = 8;
    v782 = (int)v817;
    v447 = 8;
    v448 = (int)v817;
    v746 = (int)v817;
    v718 = 8;
    v719 = (int)v817;
    v363 = 8;
    v364 = (int)v817;
    v26 = (int)v817;
    v748 = (int)v817;
    v25->mNext = 0i64;
    v25[1].mNext = 0i64;
    v25[2].mNext = 0i64;
    LODWORD(v25[3].mNext) = v26;
    LODWORD(v25[4].mNext) = v26;
    WORD2(v25[4].mNext) = v363;
    LODWORD(v25[5].mNext) = v364;
    WORD2(v25[5].mNext) = v447;
    LODWORD(v25[6].mNext) = v448;
    BYTE4(v25[6].mNext) = 0;
    LODWORD(v25[7].mNext) = 88;
    v25[8].mNext = (UFG::allocator::free_link *)v22;
    LOBYTE(v25[9].mNext) = 1;
  }
  else
  {
    v25 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v25);
  v27 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v28 = v27;
  v819 = (__int16 *)v27;
  if ( v27 )
    UFG::qBaseTreeRB::qBaseTreeRB(v27);
  else
    v28 = 0i64;
  UFG::qSymbol::create_from_string(&v534, "Motion");
  v29 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v819 = (__int16 *)v29;
  if ( v29 )
  {
    v309 = (UEL::Value::Type)&v518;
    p_alwaysReturns = (UEL::Value::Type)&v367;
    v518 = 7;
    v519 = UFG::gNullQSymbol.mUID;
    v367 = 7;
    v368 = UFG::gNullQSymbol.mUID;
    v30 = v534.mUID;
    v623 = v534.mUID;
    v29->mNext = 0i64;
    v29[1].mNext = 0i64;
    v29[2].mNext = 0i64;
    LODWORD(v29[3].mNext) = v30;
    LODWORD(v29[4].mNext) = v30;
    WORD2(v29[4].mNext) = v367;
    LODWORD(v29[5].mNext) = v368;
    WORD2(v29[5].mNext) = v518;
    LODWORD(v29[6].mNext) = v519;
    BYTE4(v29[6].mNext) = 0;
    LODWORD(v29[7].mNext) = 0;
    v29[8].mNext = 0i64;
    LOBYTE(v29[9].mNext) = 0;
  }
  else
  {
    v29 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v28, (UFG::qBaseNodeRB *)v29);
  UFG::qSymbol::create_from_string(&v578, "MotionSpeed");
  v31 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v819 = (__int16 *)v31;
  if ( v31 )
  {
    v309 = (UEL::Value::Type)&v451;
    p_alwaysReturns = (UEL::Value::Type)&v371;
    v451 = 4;
    v452 = UFG::gNullQSymbol.mUID;
    v371 = 4;
    v372 = UFG::gNullQSymbol.mUID;
    v32 = v578.mUID;
    v671 = v578.mUID;
    v31->mNext = 0i64;
    v31[1].mNext = 0i64;
    v31[2].mNext = 0i64;
    LODWORD(v31[3].mNext) = v32;
    LODWORD(v31[4].mNext) = v32;
    WORD2(v31[4].mNext) = v371;
    LODWORD(v31[5].mNext) = v372;
    WORD2(v31[5].mNext) = v451;
    LODWORD(v31[6].mNext) = v452;
    BYTE4(v31[6].mNext) = 0;
    LODWORD(v31[7].mNext) = 8;
    v31[8].mNext = 0i64;
    LOBYTE(v31[9].mNext) = 0;
  }
  else
  {
    v31 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v28, (UFG::qBaseNodeRB *)v31);
  UFG::qSymbol::create_from_string(&v536, "ActionRequests");
  v33 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v819 = (__int16 *)v33;
  if ( v33 )
  {
    v309 = (UEL::Value::Type)&v490;
    p_alwaysReturns = (UEL::Value::Type)&v375;
    v490 = 5;
    v491 = UFG::gNullQSymbol.mUID;
    v375 = 23;
    v376 = UFG::gNullQSymbol.mUID;
    v34 = v536.mUID;
    v655 = v536.mUID;
    v33->mNext = 0i64;
    v33[1].mNext = 0i64;
    v33[2].mNext = 0i64;
    LODWORD(v33[3].mNext) = v34;
    LODWORD(v33[4].mNext) = v34;
    WORD2(v33[4].mNext) = v375;
    LODWORD(v33[5].mNext) = v376;
    WORD2(v33[5].mNext) = v490;
    LODWORD(v33[6].mNext) = v491;
    BYTE4(v33[6].mNext) = 0;
    LODWORD(v33[7].mNext) = 16;
    v33[8].mNext = 0i64;
    LOBYTE(v33[9].mNext) = 0;
  }
  else
  {
    v33 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v28, (UFG::qBaseNodeRB *)v33);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v818, "Intention");
  v35 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v819 = (__int16 *)v35;
  if ( v35 )
  {
    v309 = (UEL::Value::Type)&v455;
    p_alwaysReturns = (UEL::Value::Type)&v379;
    v731 = (int)v818;
    v770 = 8;
    v771 = (int)v818;
    v455 = 8;
    v456 = (int)v818;
    v658 = (int)v818;
    v624 = 8;
    v625 = (int)v818;
    v379 = 8;
    v380 = (int)v818;
    v36 = (int)v818;
    v777 = (int)v818;
    v35->mNext = 0i64;
    v35[1].mNext = 0i64;
    v35[2].mNext = 0i64;
    LODWORD(v35[3].mNext) = v36;
    LODWORD(v35[4].mNext) = v36;
    WORD2(v35[4].mNext) = v379;
    LODWORD(v35[5].mNext) = v380;
    WORD2(v35[5].mNext) = v455;
    LODWORD(v35[6].mNext) = v456;
    BYTE4(v35[6].mNext) = 0;
    LODWORD(v35[7].mNext) = 96;
    v35[8].mNext = (UFG::allocator::free_link *)v28;
    LOBYTE(v35[9].mNext) = 1;
  }
  else
  {
    v35 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v35);
  v37 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v38 = v37;
  v309 = (UEL::Value::Type)v37;
  if ( v37 )
    UFG::qBaseTreeRB::qBaseTreeRB(v37);
  else
    v38 = 0i64;
  v795 = 0i64;
  v796 = 0i64;
  UFG::qSymbol::create_from_string(&v600, "Velocity");
  v39 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v39;
  if ( v39 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v510;
    v311 = (UEL::Value::Type)&v383;
    v510 = 7;
    v511 = UFG::gNullQSymbol.mUID;
    v383 = 10;
    v384 = UFG::gNullQSymbol.mUID;
    v40 = v600.mUID;
    v661 = v600.mUID;
    v39->mNext = 0i64;
    v39[1].mNext = 0i64;
    v39[2].mNext = 0i64;
    LODWORD(v39[3].mNext) = v40;
    LODWORD(v39[4].mNext) = v40;
    WORD2(v39[4].mNext) = v383;
    LODWORD(v39[5].mNext) = v384;
    WORD2(v39[5].mNext) = v510;
    LODWORD(v39[6].mNext) = v511;
    BYTE4(v39[6].mNext) = 1;
    LODWORD(v39[7].mNext) = 0;
    v39[8].mNext = 0i64;
    LOBYTE(v39[9].mNext) = 0;
  }
  else
  {
    v39 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v38, (UFG::qBaseNodeRB *)v39);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v819, "Character");
  v41 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v41;
  if ( v41 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v459;
    v311 = (UEL::Value::Type)&v387;
    v733 = (int)v819;
    v626 = 8;
    v627 = (int)v819;
    v459 = 8;
    v460 = (int)v819;
    v664 = (int)v819;
    v629 = 8;
    v630 = (int)v819;
    v387 = 8;
    v388 = (int)v819;
    v42 = (int)v819;
    v768 = (int)v819;
    v41->mNext = 0i64;
    v41[1].mNext = 0i64;
    v41[2].mNext = 0i64;
    LODWORD(v41[3].mNext) = v42;
    LODWORD(v41[4].mNext) = v42;
    WORD2(v41[4].mNext) = v387;
    LODWORD(v41[5].mNext) = v388;
    WORD2(v41[5].mNext) = v459;
    LODWORD(v41[6].mNext) = v460;
    BYTE4(v41[6].mNext) = 0;
    LODWORD(v41[7].mNext) = 104;
    v41[8].mNext = (UFG::allocator::free_link *)v38;
    LOBYTE(v41[9].mNext) = 1;
  }
  else
  {
    v41 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v41);
  v43 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v44 = v43;
  v309 = (UEL::Value::Type)v43;
  if ( v43 )
    UFG::qBaseTreeRB::qBaseTreeRB(v43);
  else
    v44 = 0i64;
  v798 = 0i64;
  v799 = 0i64;
  UFG::qSymbol::create_from_string(&v538, "Owner");
  v45 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v45;
  if ( v45 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v494;
    v311 = (UEL::Value::Type)&v391;
    v494 = 8;
    v495 = UFG::gNullQSymbol.mUID;
    v391 = 10;
    v392 = UFG::gNullQSymbol.mUID;
    v46 = v538.mUID;
    v667 = v538.mUID;
    v45->mNext = 0i64;
    v45[1].mNext = 0i64;
    v45[2].mNext = 0i64;
    LODWORD(v45[3].mNext) = v46;
    LODWORD(v45[4].mNext) = v46;
    WORD2(v45[4].mNext) = v391;
    LODWORD(v45[5].mNext) = v392;
    WORD2(v45[5].mNext) = v494;
    LODWORD(v45[6].mNext) = v495;
    BYTE4(v45[6].mNext) = 1;
    LODWORD(v45[7].mNext) = 0;
    v45[8].mNext = 0i64;
    LOBYTE(v45[9].mNext) = 0;
  }
  else
  {
    v45 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v44, (UFG::qBaseNodeRB *)v45);
  UFG::qSymbol::create_from_string(&v319, "Item");
  v47 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v47;
  if ( v47 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v463;
    v311 = (UEL::Value::Type)&v395;
    v735 = v319.mUID;
    v632 = 8;
    v633 = v319.mUID;
    v463 = 8;
    v464 = v319.mUID;
    v669 = v319.mUID;
    v635 = 8;
    v636 = v319.mUID;
    v395 = 8;
    v396 = v319.mUID;
    v48 = v319.mUID;
    v775 = v319.mUID;
    v47->mNext = 0i64;
    v47[1].mNext = 0i64;
    v47[2].mNext = 0i64;
    LODWORD(v47[3].mNext) = v48;
    LODWORD(v47[4].mNext) = v48;
    WORD2(v47[4].mNext) = v395;
    LODWORD(v47[5].mNext) = v396;
    WORD2(v47[5].mNext) = v463;
    LODWORD(v47[6].mNext) = v464;
    BYTE4(v47[6].mNext) = 0;
    LODWORD(v47[7].mNext) = 112;
    v47[8].mNext = (UFG::allocator::free_link *)v44;
    LOBYTE(v47[9].mNext) = 1;
  }
  else
  {
    v47 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v47);
  v49 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v50 = v49;
  v309 = (UEL::Value::Type)v49;
  if ( v49 )
    UFG::qBaseTreeRB::qBaseTreeRB(v49);
  else
    v50 = 0i64;
  v801 = 0i64;
  v802 = 0i64;
  UFG::qSymbol::create_from_string(&v580, "Grapple");
  v51 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v51;
  if ( v51 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v526;
    v311 = (UEL::Value::Type)&v399;
    v526 = 8;
    v527 = UFG::gNullQSymbol.mUID;
    v399 = 10;
    v400 = UFG::gNullQSymbol.mUID;
    v52 = v580.mUID;
    v737 = v580.mUID;
    v51->mNext = 0i64;
    v51[1].mNext = 0i64;
    v51[2].mNext = 0i64;
    LODWORD(v51[3].mNext) = v52;
    LODWORD(v51[4].mNext) = v52;
    WORD2(v51[4].mNext) = v399;
    LODWORD(v51[5].mNext) = v400;
    WORD2(v51[5].mNext) = v526;
    LODWORD(v51[6].mNext) = v527;
    BYTE4(v51[6].mNext) = 1;
    LODWORD(v51[7].mNext) = 0;
    v51[8].mNext = 0i64;
    LOBYTE(v51[9].mNext) = 0;
  }
  else
  {
    v51 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v50, (UFG::qBaseNodeRB *)v51);
  UFG::qSymbol::create_from_string(&v316, "Targeting");
  v53 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v53;
  if ( v53 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v467;
    v311 = (UEL::Value::Type)&v403;
    v673 = v316.mUID;
    v638 = 8;
    v639 = v316.mUID;
    v467 = 8;
    v468 = v316.mUID;
    v760 = v316.mUID;
    v641 = 8;
    v642 = v316.mUID;
    v403 = 8;
    v404 = v316.mUID;
    v54 = v316.mUID;
    v675 = v316.mUID;
    v53->mNext = 0i64;
    v53[1].mNext = 0i64;
    v53[2].mNext = 0i64;
    LODWORD(v53[3].mNext) = v54;
    LODWORD(v53[4].mNext) = v54;
    WORD2(v53[4].mNext) = v403;
    LODWORD(v53[5].mNext) = v404;
    WORD2(v53[5].mNext) = v467;
    LODWORD(v53[6].mNext) = v468;
    BYTE4(v53[6].mNext) = 0;
    LODWORD(v53[7].mNext) = 120;
    v53[8].mNext = (UFG::allocator::free_link *)v50;
    LOBYTE(v53[9].mNext) = 1;
  }
  else
  {
    v53 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v53);
  v55 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v56 = v55;
  v309 = (UEL::Value::Type)v55;
  if ( v55 )
    UFG::qBaseTreeRB::qBaseTreeRB(v55);
  else
    v56 = 0i64;
  UFG::qSymbol::create_from_string(&v619, "LocoSpeed");
  v57 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v57;
  if ( v57 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v498;
    v311 = (UEL::Value::Type)&v407;
    v498 = 4;
    v499 = UFG::gNullQSymbol.mUID;
    v407 = 4;
    v408 = UFG::gNullQSymbol.mUID;
    v58 = v619.mUID;
    v739 = v619.mUID;
    v57->mNext = 0i64;
    v57[1].mNext = 0i64;
    v57[2].mNext = 0i64;
    LODWORD(v57[3].mNext) = v58;
    LODWORD(v57[4].mNext) = v58;
    WORD2(v57[4].mNext) = v407;
    LODWORD(v57[5].mNext) = v408;
    WORD2(v57[5].mNext) = v498;
    LODWORD(v57[6].mNext) = v499;
    BYTE4(v57[6].mNext) = 0;
    LODWORD(v57[7].mNext) = 0;
    v57[8].mNext = 0i64;
    LOBYTE(v57[9].mNext) = 0;
  }
  else
  {
    v57 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v57);
  UFG::qSymbol::create_from_string(&v542, "GrappleDamage");
  v59 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v59;
  if ( v59 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v471;
    v311 = (UEL::Value::Type)&v411;
    v471 = 4;
    v472 = UFG::gNullQSymbol.mUID;
    v411 = 4;
    v412 = UFG::gNullQSymbol.mUID;
    v60 = v542.mUID;
    v677 = v542.mUID;
    v59->mNext = 0i64;
    v59[1].mNext = 0i64;
    v59[2].mNext = 0i64;
    LODWORD(v59[3].mNext) = v60;
    LODWORD(v59[4].mNext) = v60;
    WORD2(v59[4].mNext) = v411;
    LODWORD(v59[5].mNext) = v412;
    WORD2(v59[5].mNext) = v471;
    LODWORD(v59[6].mNext) = v472;
    BYTE4(v59[6].mNext) = 0;
    LODWORD(v59[7].mNext) = 8;
    v59[8].mNext = 0i64;
    LOBYTE(v59[9].mNext) = 0;
  }
  else
  {
    v59 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v59);
  UFG::qSymbol::create_from_string(&v582, "MitigateWorldCollision");
  v61 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v61;
  if ( v61 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v514;
    v311 = (UEL::Value::Type)&v415;
    v514 = 4;
    v515 = UFG::gNullQSymbol.mUID;
    v415 = 4;
    v416 = UFG::gNullQSymbol.mUID;
    v62 = v582.mUID;
    v761 = v582.mUID;
    v61->mNext = 0i64;
    v61[1].mNext = 0i64;
    v61[2].mNext = 0i64;
    LODWORD(v61[3].mNext) = v62;
    LODWORD(v61[4].mNext) = v62;
    WORD2(v61[4].mNext) = v415;
    LODWORD(v61[5].mNext) = v416;
    WORD2(v61[5].mNext) = v514;
    LODWORD(v61[6].mNext) = v515;
    BYTE4(v61[6].mNext) = 0;
    LODWORD(v61[7].mNext) = 16;
    v61[8].mNext = 0i64;
    LOBYTE(v61[9].mNext) = 0;
  }
  else
  {
    v61 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v61);
  UFG::qSymbol::create_from_string(&v544, "MitigateExplosive");
  v63 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v63;
  if ( v63 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v475;
    v311 = (UEL::Value::Type)&v419;
    v475 = 4;
    v476 = UFG::gNullQSymbol.mUID;
    v419 = 4;
    v420 = UFG::gNullQSymbol.mUID;
    v64 = v544.mUID;
    v679 = v544.mUID;
    v63->mNext = 0i64;
    v63[1].mNext = 0i64;
    v63[2].mNext = 0i64;
    LODWORD(v63[3].mNext) = v64;
    LODWORD(v63[4].mNext) = v64;
    WORD2(v63[4].mNext) = v419;
    LODWORD(v63[5].mNext) = v420;
    WORD2(v63[5].mNext) = v475;
    LODWORD(v63[6].mNext) = v476;
    BYTE4(v63[6].mNext) = 0;
    LODWORD(v63[7].mNext) = 24;
    v63[8].mNext = 0i64;
    LOBYTE(v63[9].mNext) = 0;
  }
  else
  {
    v63 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v63);
  UFG::qSymbol::create_from_string(&v602, "MitigateBallistic");
  v65 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v65;
  if ( v65 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v502;
    v311 = (UEL::Value::Type)&v423;
    v502 = 4;
    v503 = UFG::gNullQSymbol.mUID;
    v423 = 4;
    v424 = UFG::gNullQSymbol.mUID;
    v66 = v602.mUID;
    v741 = v602.mUID;
    v65->mNext = 0i64;
    v65[1].mNext = 0i64;
    v65[2].mNext = 0i64;
    LODWORD(v65[3].mNext) = v66;
    LODWORD(v65[4].mNext) = v66;
    WORD2(v65[4].mNext) = v423;
    LODWORD(v65[5].mNext) = v424;
    WORD2(v65[5].mNext) = v502;
    LODWORD(v65[6].mNext) = v503;
    BYTE4(v65[6].mNext) = 0;
    LODWORD(v65[7].mNext) = 32;
    v65[8].mNext = 0i64;
    LOBYTE(v65[9].mNext) = 0;
  }
  else
  {
    v65 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v65);
  UFG::qSymbol::create_from_string(&v546, "MitigateUnarmedMelee");
  v67 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v67;
  if ( v67 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v327;
    v311 = (UEL::Value::Type)&v427;
    v327 = 4;
    v328 = UFG::gNullQSymbol.mUID;
    v427 = 4;
    v428 = UFG::gNullQSymbol.mUID;
    v68 = v546.mUID;
    v681 = v546.mUID;
    v67->mNext = 0i64;
    v67[1].mNext = 0i64;
    v67[2].mNext = 0i64;
    LODWORD(v67[3].mNext) = v68;
    LODWORD(v67[4].mNext) = v68;
    WORD2(v67[4].mNext) = v427;
    LODWORD(v67[5].mNext) = v428;
    WORD2(v67[5].mNext) = v327;
    LODWORD(v67[6].mNext) = v328;
    BYTE4(v67[6].mNext) = 0;
    LODWORD(v67[7].mNext) = 40;
    v67[8].mNext = 0i64;
    LOBYTE(v67[9].mNext) = 0;
  }
  else
  {
    v67 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v67);
  UFG::qSymbol::create_from_string(&v584, "MitigateArmedMelee");
  v69 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v69;
  if ( v69 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v333;
    v311 = (UEL::Value::Type)&v329;
    v333 = 4;
    v334 = UFG::gNullQSymbol.mUID;
    v329 = 4;
    v330 = UFG::gNullQSymbol.mUID;
    v70 = v584.mUID;
    v763 = v584.mUID;
    v69->mNext = 0i64;
    v69[1].mNext = 0i64;
    v69[2].mNext = 0i64;
    LODWORD(v69[3].mNext) = v70;
    LODWORD(v69[4].mNext) = v70;
    WORD2(v69[4].mNext) = v329;
    LODWORD(v69[5].mNext) = v330;
    WORD2(v69[5].mNext) = v333;
    LODWORD(v69[6].mNext) = v334;
    BYTE4(v69[6].mNext) = 0;
    LODWORD(v69[7].mNext) = 48;
    v69[8].mNext = 0i64;
    LOBYTE(v69[9].mNext) = 0;
  }
  else
  {
    v69 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v69);
  UFG::qSymbol::create_from_string(&v612, "MitigateGrapple");
  v71 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v71;
  if ( v71 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v341;
    v311 = (UEL::Value::Type)&v337;
    v341 = 4;
    v342 = UFG::gNullQSymbol.mUID;
    v337 = 4;
    v338 = UFG::gNullQSymbol.mUID;
    v72 = v612.mUID;
    v683 = v612.mUID;
    v71->mNext = 0i64;
    v71[1].mNext = 0i64;
    v71[2].mNext = 0i64;
    LODWORD(v71[3].mNext) = v72;
    LODWORD(v71[4].mNext) = v72;
    WORD2(v71[4].mNext) = v337;
    LODWORD(v71[5].mNext) = v338;
    WORD2(v71[5].mNext) = v341;
    LODWORD(v71[6].mNext) = v342;
    BYTE4(v71[6].mNext) = 0;
    LODWORD(v71[7].mNext) = 56;
    v71[8].mNext = 0i64;
    LOBYTE(v71[9].mNext) = 0;
  }
  else
  {
    v71 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v71);
  UFG::qSymbol::create_from_string(&v550, "MaxHP");
  v73 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v73;
  if ( v73 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v349;
    v311 = (UEL::Value::Type)&v345;
    v349 = 4;
    v350 = UFG::gNullQSymbol.mUID;
    v345 = 4;
    v346 = UFG::gNullQSymbol.mUID;
    v74 = v550.mUID;
    v743 = v550.mUID;
    v73->mNext = 0i64;
    v73[1].mNext = 0i64;
    v73[2].mNext = 0i64;
    LODWORD(v73[3].mNext) = v74;
    LODWORD(v73[4].mNext) = v74;
    WORD2(v73[4].mNext) = v345;
    LODWORD(v73[5].mNext) = v346;
    WORD2(v73[5].mNext) = v349;
    LODWORD(v73[6].mNext) = v350;
    BYTE4(v73[6].mNext) = 0;
    LODWORD(v73[7].mNext) = 64;
    v73[8].mNext = 0i64;
    LOBYTE(v73[9].mNext) = 0;
  }
  else
  {
    v73 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v73);
  UFG::qSymbol::create_from_string(&v586, "MinHP");
  v75 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v75;
  if ( v75 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v357;
    v311 = (UEL::Value::Type)&v353;
    v357 = 4;
    v358 = UFG::gNullQSymbol.mUID;
    v353 = 4;
    v354 = UFG::gNullQSymbol.mUID;
    v76 = v586.mUID;
    v685 = v586.mUID;
    v75->mNext = 0i64;
    v75[1].mNext = 0i64;
    v75[2].mNext = 0i64;
    LODWORD(v75[3].mNext) = v76;
    LODWORD(v75[4].mNext) = v76;
    WORD2(v75[4].mNext) = v353;
    LODWORD(v75[5].mNext) = v354;
    WORD2(v75[5].mNext) = v357;
    LODWORD(v75[6].mNext) = v358;
    BYTE4(v75[6].mNext) = 0;
    LODWORD(v75[7].mNext) = 72;
    v75[8].mNext = 0i64;
    LOBYTE(v75[9].mNext) = 0;
  }
  else
  {
    v75 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v75);
  UFG::qSymbol::create_from_string(&v552, "HpBoost");
  v77 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v77;
  if ( v77 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v365;
    v311 = (UEL::Value::Type)&v361;
    v365 = 4;
    v366 = UFG::gNullQSymbol.mUID;
    v361 = 4;
    v362 = UFG::gNullQSymbol.mUID;
    v78 = v552.mUID;
    v765 = v552.mUID;
    v77->mNext = 0i64;
    v77[1].mNext = 0i64;
    v77[2].mNext = 0i64;
    LODWORD(v77[3].mNext) = v78;
    LODWORD(v77[4].mNext) = v78;
    WORD2(v77[4].mNext) = v361;
    LODWORD(v77[5].mNext) = v362;
    WORD2(v77[5].mNext) = v365;
    LODWORD(v77[6].mNext) = v366;
    BYTE4(v77[6].mNext) = 0;
    LODWORD(v77[7].mNext) = 80;
    v77[8].mNext = 0i64;
    LOBYTE(v77[9].mNext) = 0;
  }
  else
  {
    v77 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v77);
  UFG::qSymbol::create_from_string(&v604, "KoChance");
  v79 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v79;
  if ( v79 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v373;
    v311 = (UEL::Value::Type)&v369;
    v373 = 4;
    v374 = UFG::gNullQSymbol.mUID;
    v369 = 4;
    v370 = UFG::gNullQSymbol.mUID;
    v80 = v604.mUID;
    v687 = v604.mUID;
    v79->mNext = 0i64;
    v79[1].mNext = 0i64;
    v79[2].mNext = 0i64;
    LODWORD(v79[3].mNext) = v80;
    LODWORD(v79[4].mNext) = v80;
    WORD2(v79[4].mNext) = v369;
    LODWORD(v79[5].mNext) = v370;
    WORD2(v79[5].mNext) = v373;
    LODWORD(v79[6].mNext) = v374;
    BYTE4(v79[6].mNext) = 0;
    LODWORD(v79[7].mNext) = 88;
    v79[8].mNext = 0i64;
    LOBYTE(v79[9].mNext) = 0;
  }
  else
  {
    v79 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v79);
  UFG::qSymbol::create_from_string(&v554, "CritChance");
  v81 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v81;
  if ( v81 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v381;
    v311 = (UEL::Value::Type)&v377;
    v381 = 4;
    v382 = UFG::gNullQSymbol.mUID;
    v377 = 4;
    v378 = UFG::gNullQSymbol.mUID;
    v82 = v554.mUID;
    v745 = v554.mUID;
    v81->mNext = 0i64;
    v81[1].mNext = 0i64;
    v81[2].mNext = 0i64;
    LODWORD(v81[3].mNext) = v82;
    LODWORD(v81[4].mNext) = v82;
    WORD2(v81[4].mNext) = v377;
    LODWORD(v81[5].mNext) = v378;
    WORD2(v81[5].mNext) = v381;
    LODWORD(v81[6].mNext) = v382;
    BYTE4(v81[6].mNext) = 0;
    LODWORD(v81[7].mNext) = 96;
    v81[8].mNext = 0i64;
    LOBYTE(v81[9].mNext) = 0;
  }
  else
  {
    v81 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v56, (UFG::qBaseNodeRB *)v81);
  UFG::qSymbol::create_from_string(&v318, "GangMember");
  v83 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v83;
  if ( v83 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v389;
    v311 = (UEL::Value::Type)&v385;
    v689 = v318.mUID;
    v644 = 8;
    v645 = v318.mUID;
    v389 = 8;
    v390 = v318.mUID;
    v776 = v318.mUID;
    v647 = 8;
    v648 = v318.mUID;
    v385 = 8;
    v386 = v318.mUID;
    v84 = v318.mUID;
    v707 = v318.mUID;
    v83->mNext = 0i64;
    v83[1].mNext = 0i64;
    v83[2].mNext = 0i64;
    LODWORD(v83[3].mNext) = v84;
    LODWORD(v83[4].mNext) = v84;
    WORD2(v83[4].mNext) = v385;
    LODWORD(v83[5].mNext) = v386;
    WORD2(v83[5].mNext) = v389;
    LODWORD(v83[6].mNext) = v390;
    BYTE4(v83[6].mNext) = 0;
    LODWORD(v83[7].mNext) = 128;
    v83[8].mNext = (UFG::allocator::free_link *)v56;
    LOBYTE(v83[9].mNext) = 1;
  }
  else
  {
    v83 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v83);
  v85 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v86 = v85;
  v309 = (UEL::Value::Type)v85;
  if ( v85 )
    UFG::qBaseTreeRB::qBaseTreeRB(v85);
  else
    v86 = 0i64;
  UFG::qSymbol::create_from_string(&v588, "Damage");
  v87 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v87;
  if ( v87 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v397;
    v311 = (UEL::Value::Type)&v393;
    v397 = 4;
    v398 = UFG::gNullQSymbol.mUID;
    v393 = 4;
    v394 = UFG::gNullQSymbol.mUID;
    v88 = v588.mUID;
    v750 = v588.mUID;
    v87->mNext = 0i64;
    v87[1].mNext = 0i64;
    v87[2].mNext = 0i64;
    LODWORD(v87[3].mNext) = v88;
    LODWORD(v87[4].mNext) = v88;
    WORD2(v87[4].mNext) = v393;
    LODWORD(v87[5].mNext) = v394;
    WORD2(v87[5].mNext) = v397;
    LODWORD(v87[6].mNext) = v398;
    BYTE4(v87[6].mNext) = 0;
    LODWORD(v87[7].mNext) = 0;
    v87[8].mNext = 0i64;
    LOBYTE(v87[9].mNext) = 0;
  }
  else
  {
    v87 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v86, (UFG::qBaseNodeRB *)v87);
  UFG::qSymbol::create_from_string(&v556, "AttackSpeed");
  v89 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v89;
  if ( v89 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v405;
    v311 = (UEL::Value::Type)&v401;
    v405 = 4;
    v406 = UFG::gNullQSymbol.mUID;
    v401 = 4;
    v402 = UFG::gNullQSymbol.mUID;
    v90 = v556.mUID;
    v752 = v556.mUID;
    v89->mNext = 0i64;
    v89[1].mNext = 0i64;
    v89[2].mNext = 0i64;
    LODWORD(v89[3].mNext) = v90;
    LODWORD(v89[4].mNext) = v90;
    WORD2(v89[4].mNext) = v401;
    LODWORD(v89[5].mNext) = v402;
    WORD2(v89[5].mNext) = v405;
    LODWORD(v89[6].mNext) = v406;
    BYTE4(v89[6].mNext) = 0;
    LODWORD(v89[7].mNext) = 8;
    v89[8].mNext = 0i64;
    LOBYTE(v89[9].mNext) = 0;
  }
  else
  {
    v89 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v86, (UFG::qBaseNodeRB *)v89);
  UFG::qSymbol::create_from_string(&v617, "Durability");
  v91 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v91;
  if ( v91 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v413;
    v311 = (UEL::Value::Type)&v409;
    v413 = 4;
    v414 = UFG::gNullQSymbol.mUID;
    v409 = 4;
    v410 = UFG::gNullQSymbol.mUID;
    v92 = v617.mUID;
    v754 = v617.mUID;
    v91->mNext = 0i64;
    v91[1].mNext = 0i64;
    v91[2].mNext = 0i64;
    LODWORD(v91[3].mNext) = v92;
    LODWORD(v91[4].mNext) = v92;
    WORD2(v91[4].mNext) = v409;
    LODWORD(v91[5].mNext) = v410;
    WORD2(v91[5].mNext) = v413;
    LODWORD(v91[6].mNext) = v414;
    BYTE4(v91[6].mNext) = 0;
    LODWORD(v91[7].mNext) = 16;
    v91[8].mNext = 0i64;
    LOBYTE(v91[9].mNext) = 0;
  }
  else
  {
    v91 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v86, (UFG::qBaseNodeRB *)v91);
  UFG::qSymbol::create_from_string(&v558, "CritChance");
  v93 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v93;
  if ( v93 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v421;
    v311 = (UEL::Value::Type)&v417;
    v421 = 4;
    v422 = UFG::gNullQSymbol.mUID;
    v417 = 4;
    v418 = UFG::gNullQSymbol.mUID;
    v94 = v558.mUID;
    v757 = v558.mUID;
    v93->mNext = 0i64;
    v93[1].mNext = 0i64;
    v93[2].mNext = 0i64;
    LODWORD(v93[3].mNext) = v94;
    LODWORD(v93[4].mNext) = v94;
    WORD2(v93[4].mNext) = v417;
    LODWORD(v93[5].mNext) = v418;
    WORD2(v93[5].mNext) = v421;
    LODWORD(v93[6].mNext) = v422;
    BYTE4(v93[6].mNext) = 0;
    LODWORD(v93[7].mNext) = 24;
    v93[8].mNext = 0i64;
    LOBYTE(v93[9].mNext) = 0;
  }
  else
  {
    v93 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v86, (UFG::qBaseNodeRB *)v93);
  UFG::qSymbol::create_from_string(&v320, "MeleeWeapon");
  v95 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v95;
  if ( v95 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v429;
    v311 = (UEL::Value::Type)&v425;
    v721 = v320.mUID;
    v650 = 8;
    v651 = v320.mUID;
    v429 = 8;
    v430 = v320.mUID;
    v628 = v320.mUID;
    v653 = 8;
    v654 = v320.mUID;
    v425 = 8;
    v426 = v320.mUID;
    v96 = v320.mUID;
    v762 = v320.mUID;
    v95->mNext = 0i64;
    v95[1].mNext = 0i64;
    v95[2].mNext = 0i64;
    LODWORD(v95[3].mNext) = v96;
    LODWORD(v95[4].mNext) = v96;
    WORD2(v95[4].mNext) = v425;
    LODWORD(v95[5].mNext) = v426;
    WORD2(v95[5].mNext) = v429;
    LODWORD(v95[6].mNext) = v430;
    BYTE4(v95[6].mNext) = 0;
    LODWORD(v95[7].mNext) = 136;
    v95[8].mNext = (UFG::allocator::free_link *)v86;
    LOBYTE(v95[9].mNext) = 1;
  }
  else
  {
    v95 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v95);
  v97 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v98 = v97;
  v309 = (UEL::Value::Type)v97;
  if ( v97 )
    UFG::qBaseTreeRB::qBaseTreeRB(v97);
  else
    v98 = 0i64;
  UFG::qSymbol::create_from_string(&v590, "ReloadSpeed");
  v99 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v99;
  if ( v99 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v437;
    v311 = (UEL::Value::Type)&v433;
    v437 = 4;
    v438 = UFG::gNullQSymbol.mUID;
    v433 = 4;
    v434 = UFG::gNullQSymbol.mUID;
    v100 = v590.mUID;
    v631 = v590.mUID;
    v99->mNext = 0i64;
    v99[1].mNext = 0i64;
    v99[2].mNext = 0i64;
    LODWORD(v99[3].mNext) = v100;
    LODWORD(v99[4].mNext) = v100;
    WORD2(v99[4].mNext) = v433;
    LODWORD(v99[5].mNext) = v434;
    WORD2(v99[5].mNext) = v437;
    LODWORD(v99[6].mNext) = v438;
    BYTE4(v99[6].mNext) = 0;
    LODWORD(v99[7].mNext) = 0;
    v99[8].mNext = 0i64;
    LOBYTE(v99[9].mNext) = 0;
  }
  else
  {
    v99 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v98, (UFG::qBaseNodeRB *)v99);
  UFG::qSymbol::create_from_string(&v560, "Accuracy");
  v101 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v101;
  if ( v101 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v445;
    v311 = (UEL::Value::Type)&v441;
    v445 = 4;
    v446 = UFG::gNullQSymbol.mUID;
    v441 = 4;
    v442 = UFG::gNullQSymbol.mUID;
    v102 = v560.mUID;
    v723 = v560.mUID;
    v101->mNext = 0i64;
    v101[1].mNext = 0i64;
    v101[2].mNext = 0i64;
    LODWORD(v101[3].mNext) = v102;
    LODWORD(v101[4].mNext) = v102;
    WORD2(v101[4].mNext) = v441;
    LODWORD(v101[5].mNext) = v442;
    WORD2(v101[5].mNext) = v445;
    LODWORD(v101[6].mNext) = v446;
    BYTE4(v101[6].mNext) = 0;
    LODWORD(v101[7].mNext) = 8;
    v101[8].mNext = 0i64;
    LOBYTE(v101[9].mNext) = 0;
  }
  else
  {
    v101 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v98, (UFG::qBaseNodeRB *)v101);
  UFG::qSymbol::create_from_string(&v606, "AimRecover");
  v103 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v103;
  if ( v103 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v453;
    v311 = (UEL::Value::Type)&v449;
    v453 = 4;
    v454 = UFG::gNullQSymbol.mUID;
    v449 = 4;
    v450 = UFG::gNullQSymbol.mUID;
    v104 = v606.mUID;
    v634 = v606.mUID;
    v103->mNext = 0i64;
    v103[1].mNext = 0i64;
    v103[2].mNext = 0i64;
    LODWORD(v103[3].mNext) = v104;
    LODWORD(v103[4].mNext) = v104;
    WORD2(v103[4].mNext) = v449;
    LODWORD(v103[5].mNext) = v450;
    WORD2(v103[5].mNext) = v453;
    LODWORD(v103[6].mNext) = v454;
    BYTE4(v103[6].mNext) = 0;
    LODWORD(v103[7].mNext) = 16;
    v103[8].mNext = 0i64;
    LOBYTE(v103[9].mNext) = 0;
  }
  else
  {
    v103 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v98, (UFG::qBaseNodeRB *)v103);
  UFG::qSymbol::create_from_string(&v322, "RangedWeapon");
  v105 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v105;
  if ( v105 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v461;
    v311 = (UEL::Value::Type)&v457;
    v780 = v322.mUID;
    v656 = 8;
    v657 = v322.mUID;
    v461 = 8;
    v462 = v322.mUID;
    v637 = v322.mUID;
    v659 = 8;
    v660 = v322.mUID;
    v457 = 8;
    v458 = v322.mUID;
    v106 = v322.mUID;
    v725 = v322.mUID;
    v105->mNext = 0i64;
    v105[1].mNext = 0i64;
    v105[2].mNext = 0i64;
    LODWORD(v105[3].mNext) = v106;
    LODWORD(v105[4].mNext) = v106;
    WORD2(v105[4].mNext) = v457;
    LODWORD(v105[5].mNext) = v458;
    WORD2(v105[5].mNext) = v461;
    LODWORD(v105[6].mNext) = v462;
    BYTE4(v105[6].mNext) = 0;
    LODWORD(v105[7].mNext) = 144;
    v105[8].mNext = (UFG::allocator::free_link *)v98;
    LOBYTE(v105[9].mNext) = 1;
  }
  else
  {
    v105 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v105);
  v107 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  v108 = v107;
  v309 = (UEL::Value::Type)v107;
  if ( v107 )
    UFG::qBaseTreeRB::qBaseTreeRB(v107);
  else
    v108 = 0i64;
  UFG::qSymbol::create_from_string(&v562, "Radius");
  v109 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v109;
  if ( v109 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v469;
    v311 = (UEL::Value::Type)&v465;
    v469 = 4;
    v470 = UFG::gNullQSymbol.mUID;
    v465 = 4;
    v466 = UFG::gNullQSymbol.mUID;
    v110 = v562.mUID;
    v640 = v562.mUID;
    v109->mNext = 0i64;
    v109[1].mNext = 0i64;
    v109[2].mNext = 0i64;
    LODWORD(v109[3].mNext) = v110;
    LODWORD(v109[4].mNext) = v110;
    WORD2(v109[4].mNext) = v465;
    LODWORD(v109[5].mNext) = v466;
    WORD2(v109[5].mNext) = v469;
    LODWORD(v109[6].mNext) = v470;
    BYTE4(v109[6].mNext) = 0;
    LODWORD(v109[7].mNext) = 0;
    v109[8].mNext = 0i64;
    LOBYTE(v109[9].mNext) = 0;
  }
  else
  {
    v109 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v108, (UFG::qBaseNodeRB *)v109);
  UFG::qSymbol::create_from_string(&v592, "Duration");
  v111 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v111;
  if ( v111 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v477;
    v311 = (UEL::Value::Type)&v473;
    v477 = 4;
    v478 = UFG::gNullQSymbol.mUID;
    v473 = 4;
    v474 = UFG::gNullQSymbol.mUID;
    v112 = v592.mUID;
    v764 = v592.mUID;
    v111->mNext = 0i64;
    v111[1].mNext = 0i64;
    v111[2].mNext = 0i64;
    LODWORD(v111[3].mNext) = v112;
    LODWORD(v111[4].mNext) = v112;
    WORD2(v111[4].mNext) = v473;
    LODWORD(v111[5].mNext) = v474;
    WORD2(v111[5].mNext) = v477;
    LODWORD(v111[6].mNext) = v478;
    BYTE4(v111[6].mNext) = 0;
    LODWORD(v111[7].mNext) = 8;
    v111[8].mNext = 0i64;
    LOBYTE(v111[9].mNext) = 0;
  }
  else
  {
    v111 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v108, (UFG::qBaseNodeRB *)v111);
  UFG::qSymbol::create_from_string(&v564, "Damage");
  v113 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v113;
  if ( v113 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v484;
    v311 = (UEL::Value::Type)&v480;
    v484 = 4;
    v485 = UFG::gNullQSymbol.mUID;
    v480 = 4;
    v481 = UFG::gNullQSymbol.mUID;
    v114 = v564.mUID;
    v643 = v564.mUID;
    v113->mNext = 0i64;
    v113[1].mNext = 0i64;
    v113[2].mNext = 0i64;
    LODWORD(v113[3].mNext) = v114;
    LODWORD(v113[4].mNext) = v114;
    WORD2(v113[4].mNext) = v480;
    LODWORD(v113[5].mNext) = v481;
    WORD2(v113[5].mNext) = v484;
    LODWORD(v113[6].mNext) = v485;
    BYTE4(v113[6].mNext) = 0;
    LODWORD(v113[7].mNext) = 16;
    v113[8].mNext = 0i64;
    LOBYTE(v113[9].mNext) = 0;
  }
  else
  {
    v113 = 0i64;
  }
  UFG::qBaseTreeRB::Add(v108, (UFG::qBaseNodeRB *)v113);
  UFG::qSymbol::create_from_string(&v315, "ThrownWeapon");
  v115 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v115;
  if ( v115 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v492;
    v311 = (UEL::Value::Type)&v488;
    v727 = v315.mUID;
    v662 = 8;
    v663 = v315.mUID;
    v492 = 8;
    v493 = v315.mUID;
    v646 = v315.mUID;
    v665 = 8;
    v666 = v315.mUID;
    v488 = 8;
    v489 = v315.mUID;
    v116 = v315.mUID;
    v773 = v315.mUID;
    v115->mNext = 0i64;
    v115[1].mNext = 0i64;
    v115[2].mNext = 0i64;
    LODWORD(v115[3].mNext) = v116;
    LODWORD(v115[4].mNext) = v116;
    WORD2(v115[4].mNext) = v488;
    LODWORD(v115[5].mNext) = v489;
    WORD2(v115[5].mNext) = v492;
    LODWORD(v115[6].mNext) = v493;
    BYTE4(v115[6].mNext) = 0;
    LODWORD(v115[7].mNext) = 152;
    v115[8].mNext = (UFG::allocator::free_link *)v108;
    LOBYTE(v115[9].mNext) = 1;
  }
  else
  {
    v115 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&pParameterData->mTree, (UFG::qBaseNodeRB *)v115);
  v117 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  parameterNameToDataMap = (UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *)v117;
  v309 = (UEL::Value::Type)v117;
  if ( v117 )
    UFG::qBaseTreeRB::qBaseTreeRB(v117);
  else
    parameterNameToDataMap = 0i64;
  *(_QWORD *)&v805.mName.mText.mData.mNumItems = 0i64;
  v805.mName.mText.mData.mItems = 0i64;
  UFG::qSymbol::create_from_string(&v607, "LocoSpeed");
  v119 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v119;
  if ( v119 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v500;
    v311 = (UEL::Value::Type)&v496;
    v500 = 4;
    v501 = UFG::gNullQSymbol.mUID;
    v496 = 4;
    v497 = UFG::gNullQSymbol.mUID;
    v120 = v607.mUID;
    v649 = v607.mUID;
    v119->mNext = 0i64;
    v119[1].mNext = 0i64;
    v119[2].mNext = 0i64;
    LODWORD(v119[3].mNext) = v120;
    LODWORD(v119[4].mNext) = v120;
    WORD2(v119[4].mNext) = v496;
    LODWORD(v119[5].mNext) = v497;
    WORD2(v119[5].mNext) = v500;
    LODWORD(v119[6].mNext) = v501;
    BYTE4(v119[6].mNext) = 0;
    LODWORD(v119[7].mNext) = 16;
    v119[8].mNext = 0i64;
    LOBYTE(v119[9].mNext) = 0;
  }
  else
  {
    v119 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&parameterNameToDataMap->mTree, (UFG::qBaseNodeRB *)v119);
  UFG::qSymbol::create_from_string(&v566, "GrappleDamage");
  v121 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v121;
  if ( v121 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v508;
    v311 = (UEL::Value::Type)&v504;
    v508 = 4;
    v509 = UFG::gNullQSymbol.mUID;
    v504 = 4;
    v505 = UFG::gNullQSymbol.mUID;
    v122 = v566.mUID;
    v729 = v566.mUID;
    v121->mNext = 0i64;
    v121[1].mNext = 0i64;
    v121[2].mNext = 0i64;
    LODWORD(v121[3].mNext) = v122;
    LODWORD(v121[4].mNext) = v122;
    WORD2(v121[4].mNext) = v504;
    LODWORD(v121[5].mNext) = v505;
    WORD2(v121[5].mNext) = v508;
    LODWORD(v121[6].mNext) = v509;
    BYTE4(v121[6].mNext) = 0;
    LODWORD(v121[7].mNext) = 20;
    v121[8].mNext = 0i64;
    LOBYTE(v121[9].mNext) = 0;
  }
  else
  {
    v121 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&parameterNameToDataMap->mTree, (UFG::qBaseNodeRB *)v121);
  UFG::qSymbol::create_from_string(&v594, "MitigateWorldCollision");
  v123 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v123;
  if ( v123 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v516;
    v311 = (UEL::Value::Type)&v512;
    v516 = 4;
    v517 = UFG::gNullQSymbol.mUID;
    v512 = 4;
    v513 = UFG::gNullQSymbol.mUID;
    v124 = v594.mUID;
    v652 = v594.mUID;
    v123->mNext = 0i64;
    v123[1].mNext = 0i64;
    v123[2].mNext = 0i64;
    LODWORD(v123[3].mNext) = v124;
    LODWORD(v123[4].mNext) = v124;
    WORD2(v123[4].mNext) = v512;
    LODWORD(v123[5].mNext) = v513;
    WORD2(v123[5].mNext) = v516;
    LODWORD(v123[6].mNext) = v517;
    BYTE4(v123[6].mNext) = 0;
    LODWORD(v123[7].mNext) = 24;
    v123[8].mNext = 0i64;
    LOBYTE(v123[9].mNext) = 0;
  }
  else
  {
    v123 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&parameterNameToDataMap->mTree, (UFG::qBaseNodeRB *)v123);
  UFG::qSymbol::create_from_string(&v568, "MitigateExplosive");
  v125 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v125;
  if ( v125 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v524;
    v311 = (UEL::Value::Type)&v520;
    v524 = 4;
    v525 = UFG::gNullQSymbol.mUID;
    v520 = 4;
    v521 = UFG::gNullQSymbol.mUID;
    v126 = v568.mUID;
    v766 = v568.mUID;
    v125->mNext = 0i64;
    v125[1].mNext = 0i64;
    v125[2].mNext = 0i64;
    LODWORD(v125[3].mNext) = v126;
    LODWORD(v125[4].mNext) = v126;
    WORD2(v125[4].mNext) = v520;
    LODWORD(v125[5].mNext) = v521;
    WORD2(v125[5].mNext) = v524;
    LODWORD(v125[6].mNext) = v525;
    BYTE4(v125[6].mNext) = 0;
    LODWORD(v125[7].mNext) = 28;
    v125[8].mNext = 0i64;
    LOBYTE(v125[9].mNext) = 0;
  }
  else
  {
    v125 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&parameterNameToDataMap->mTree, (UFG::qBaseNodeRB *)v125);
  UFG::qSymbol::create_from_string(&source, "MitigateBallistic");
  v127 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  v309 = (UEL::Value::Type)v127;
  if ( v127 )
  {
    p_alwaysReturns = (UEL::Value::Type)&alwaysReturns;
    v311 = (UEL::Value::Type)&v615;
    v312 = (UEL::Value::Type)&v570;
    alwaysReturns.mBaseType.mValue = 4;
    alwaysReturns.mDetailedType = UFG::gNullQSymbol;
    qEnum<enum UEL::Value::BaseType,unsigned short>::qEnum<enum UEL::Value::BaseType,unsigned short>(&v615, ANSIX923);
    UFG::qSymbol::qSymbol(&v616, &UFG::gNullQSymbol);
    v128 = UFG::qSymbol::qSymbol(&v570, &source);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v127,
      &v128->mUID,
      (UEL::Value::Type)&v615,
      (UEL::Value::Type)&alwaysReturns,
      0,
      0x20u,
      0i64,
      0);
  }
  else
  {
    v129 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v129);
  UFG::qSymbol::create_from_string(&v596, "MitigateUnarmedMelee");
  v130 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v130;
  if ( v130 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v668;
    v311 = (UEL::Value::Type)&v670;
    v312 = (UEL::Value::Type)&v572;
    UEL::Value::Type::Type(&v668, ANSIX923);
    v132 = v131;
    UEL::Value::Type::Type(&v670, ANSIX923);
    v134 = v133;
    v135 = UFG::qSymbol::qSymbol(&v572, &v596);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v130,
      &v135->mUID,
      v134,
      v132,
      0,
      0x24u,
      0i64,
      0);
  }
  else
  {
    v136 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v136);
  UFG::qSymbol::create_from_string(&v614, "MitigateArmedMelee");
  v137 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v137;
  if ( v137 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v672;
    v311 = (UEL::Value::Type)&v674;
    v312 = (UEL::Value::Type)&v574;
    UEL::Value::Type::Type(&v672, ANSIX923);
    v139 = v138;
    UEL::Value::Type::Type(&v674, ANSIX923);
    v141 = v140;
    v142 = UFG::qSymbol::qSymbol(&v574, &v614);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v137,
      &v142->mUID,
      v141,
      v139,
      0,
      0x28u,
      0i64,
      0);
  }
  else
  {
    v143 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v143);
  UFG::qSymbol::create_from_string(&v598, "MitigateGrapple");
  v144 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v144;
  if ( v144 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v676;
    v311 = (UEL::Value::Type)&v678;
    v312 = (UEL::Value::Type)&v576;
    UEL::Value::Type::Type(&v676, ANSIX923);
    v146 = v145;
    UEL::Value::Type::Type(&v678, ANSIX923);
    v148 = v147;
    v149 = UFG::qSymbol::qSymbol(&v576, &v598);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v144,
      &v149->mUID,
      v148,
      v146,
      0,
      0x2Cu,
      0i64,
      0);
  }
  else
  {
    v150 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v150);
  UFG::qSymbol::create_from_string(&v531, "MaxHP");
  v151 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v151;
  if ( v151 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v680;
    v311 = (UEL::Value::Type)&v682;
    v312 = (UEL::Value::Type)&v533;
    UEL::Value::Type::Type(&v680, ANSIX923);
    v153 = v152;
    UEL::Value::Type::Type(&v682, ANSIX923);
    v155 = v154;
    v156 = UFG::qSymbol::qSymbol(&v533, &v531);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v151,
      &v156->mUID,
      v155,
      v153,
      0,
      0x30u,
      0i64,
      0);
  }
  else
  {
    v157 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v157);
  UFG::qSymbol::create_from_string(&v535, "MinHP");
  v158 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v158;
  if ( v158 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v684;
    v311 = (UEL::Value::Type)&v686;
    v312 = (UEL::Value::Type)&v537;
    UEL::Value::Type::Type(&v684, ANSIX923);
    v160 = v159;
    UEL::Value::Type::Type(&v686, ANSIX923);
    v162 = v161;
    v163 = UFG::qSymbol::qSymbol(&v537, &v535);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v158,
      &v163->mUID,
      v162,
      v160,
      0,
      0x34u,
      0i64,
      0);
  }
  else
  {
    v164 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v164);
  UFG::qSymbol::create_from_string(&v539, "HPBoost");
  v165 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v165;
  if ( v165 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v688;
    v311 = (UEL::Value::Type)&v690;
    v312 = (UEL::Value::Type)&v541;
    UEL::Value::Type::Type(&v688, ANSIX923);
    v167 = v166;
    UEL::Value::Type::Type(&v690, ANSIX923);
    v169 = v168;
    v170 = UFG::qSymbol::qSymbol(&v541, &v539);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v165,
      &v170->mUID,
      v169,
      v167,
      0,
      0x38u,
      0i64,
      0);
  }
  else
  {
    v171 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v171);
  UFG::qSymbol::create_from_string(&v543, "KOChance");
  v172 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v172;
  if ( v172 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v692;
    v311 = (UEL::Value::Type)&v694;
    v312 = (UEL::Value::Type)&v545;
    UEL::Value::Type::Type(&v692, ANSIX923);
    v174 = v173;
    UEL::Value::Type::Type(&v694, ANSIX923);
    v176 = v175;
    v177 = UFG::qSymbol::qSymbol(&v545, &v543);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v172,
      &v177->mUID,
      v176,
      v174,
      0,
      0x3Cu,
      0i64,
      0);
  }
  else
  {
    v178 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v178);
  UFG::qSymbol::create_from_string(&v547, "CritChance");
  v179 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v179;
  if ( v179 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v696;
    v311 = (UEL::Value::Type)&v698;
    v312 = (UEL::Value::Type)&v549;
    UEL::Value::Type::Type(&v696, ANSIX923);
    v181 = v180;
    UEL::Value::Type::Type(&v698, ANSIX923);
    v183 = v182;
    v184 = UFG::qSymbol::qSymbol(&v549, &v547);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v179,
      &v184->mUID,
      v183,
      v181,
      0,
      0x40u,
      0i64,
      0);
  }
  else
  {
    v185 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(parameterNameToDataMap, v185);
  UFG::qSymbol::create_from_string(&v313, "GangMemberStatData2");
  v186 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v186;
  if ( v186 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v700;
    v311 = (UEL::Value::Type)&v551;
    v312 = (UEL::Value::Type)&v702;
    v479 = (UEL::Value::Type)&v553;
    v528 = (UEL::Value::Type)&v555;
    v187 = UFG::qSymbol::qSymbol(&v551, &v313);
    UEL::Value::Type::Type(&v794, (UEL::Value::BaseType)8, &v187->mUID);
    UEL::Value::Type::Type(&v700, v188);
    v190 = v189;
    v191 = UFG::qSymbol::qSymbol(&v553, &v313);
    UEL::Value::Type::Type(&v786, (UEL::Value::BaseType)8, &v191->mUID);
    UEL::Value::Type::Type(&v702, v192);
    v194 = v193;
    v195 = UFG::qSymbol::qSymbol(&v555, &v313);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v186,
      &v195->mUID,
      v194,
      v190,
      0,
      0,
      parameterNameToDataMap,
      1);
  }
  else
  {
    v196 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(pParameterData, v196);
  UFG::ScalingPreset::RegionValues::~RegionValues(&v805);
  v197 = AMemory::malloc_default(0x48ui64);
  v309 = (UEL::Value::Type)v197;
  if ( v197 )
  {
    UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>((UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0> *)v197);
    v199 = v198;
  }
  else
  {
    v199 = 0i64;
  }
  UFG::qSymbol::create_from_string(&v557, "ReloadSpeed");
  v200 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v200;
  if ( v200 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v704;
    v311 = (UEL::Value::Type)&v706;
    v312 = (UEL::Value::Type)&v559;
    UEL::Value::Type::Type(&v704, ANSIX923);
    v202 = v201;
    UEL::Value::Type::Type(&v706, ANSIX923);
    v204 = v203;
    v205 = UFG::qSymbol::qSymbol(&v559, &v557);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v200,
      &v205->mUID,
      v204,
      v202,
      0,
      4u,
      0i64,
      0);
  }
  else
  {
    v206 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v199, v206);
  UFG::qSymbol::create_from_string(&v561, "Accuracy");
  v207 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v207;
  if ( v207 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v708;
    v311 = (UEL::Value::Type)&v711;
    v312 = (UEL::Value::Type)&v563;
    UEL::Value::Type::Type(&v708, ANSIX923);
    v209 = v208;
    UEL::Value::Type::Type(&v711, ANSIX923);
    v211 = v210;
    v212 = UFG::qSymbol::qSymbol(&v563, &v561);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v207,
      &v212->mUID,
      v211,
      v209,
      0,
      0,
      0i64,
      0);
  }
  else
  {
    v213 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v199, v213);
  UFG::qSymbol::create_from_string(&v565, "AimRecover");
  v214 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v214;
  if ( v214 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v714;
    v311 = (UEL::Value::Type)&v717;
    v312 = (UEL::Value::Type)&v567;
    UEL::Value::Type::Type(&v714, ANSIX923);
    v216 = v215;
    UEL::Value::Type::Type(&v717, ANSIX923);
    v218 = v217;
    v219 = UFG::qSymbol::qSymbol(&v567, &v565);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v214,
      &v219->mUID,
      v218,
      v216,
      0,
      8u,
      0i64,
      0);
  }
  else
  {
    v220 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v199, v220);
  UFG::qSymbol::create_from_string(&v317, "RangedWeaponStatData2");
  v221 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v221;
  if ( v221 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v720;
    v311 = (UEL::Value::Type)&v569;
    v312 = (UEL::Value::Type)&v722;
    v479 = (UEL::Value::Type)&v571;
    v528 = (UEL::Value::Type)&v573;
    v222 = UFG::qSymbol::qSymbol(&v569, &v317);
    UEL::Value::Type::Type(&v804, (UEL::Value::BaseType)8, &v222->mUID);
    UEL::Value::Type::Type(&v720, v223);
    v225 = v224;
    v226 = UFG::qSymbol::qSymbol(&v571, &v317);
    UEL::Value::Type::Type(&v788, (UEL::Value::BaseType)8, &v226->mUID);
    UEL::Value::Type::Type(&v722, v227);
    v229 = v228;
    v230 = UFG::qSymbol::qSymbol(&v573, &v317);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v221,
      &v230->mUID,
      v229,
      v225,
      0,
      0,
      v199,
      1);
  }
  else
  {
    v231 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(pParameterData, v231);
  v232 = AMemory::malloc_default(0x48ui64);
  v309 = (UEL::Value::Type)v232;
  if ( v232 )
  {
    UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>((UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0> *)v232);
    v234 = v233;
  }
  else
  {
    v234 = 0i64;
  }
  UFG::qSymbol::create_from_string(&v575, "Damage");
  v235 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v235;
  if ( v235 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v724;
    v311 = (UEL::Value::Type)&v726;
    v312 = (UEL::Value::Type)&v530;
    UEL::Value::Type::Type(&v724, ANSIX923);
    v237 = v236;
    UEL::Value::Type::Type(&v726, ANSIX923);
    v239 = v238;
    v240 = UFG::qSymbol::qSymbol(&v530, &v575);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v235,
      &v240->mUID,
      v239,
      v237,
      0,
      0,
      0i64,
      0);
  }
  else
  {
    v241 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v234, v241);
  UFG::qSymbol::create_from_string(&v577, "AttackSpeed");
  v242 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v242;
  if ( v242 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v728;
    v311 = (UEL::Value::Type)&v730;
    v312 = (UEL::Value::Type)&v579;
    UEL::Value::Type::Type(&v728, ANSIX923);
    v244 = v243;
    UEL::Value::Type::Type(&v730, ANSIX923);
    v246 = v245;
    v247 = UFG::qSymbol::qSymbol(&v579, &v577);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v242,
      &v247->mUID,
      v246,
      v244,
      0,
      4u,
      0i64,
      0);
  }
  else
  {
    v248 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v234, v248);
  UFG::qSymbol::create_from_string(&v581, "Durability");
  v249 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v249;
  if ( v249 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v732;
    v311 = (UEL::Value::Type)&v734;
    v312 = (UEL::Value::Type)&v583;
    UEL::Value::Type::Type(&v732, ANSIX923);
    v251 = v250;
    UEL::Value::Type::Type(&v734, ANSIX923);
    v253 = v252;
    v254 = UFG::qSymbol::qSymbol(&v583, &v581);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v249,
      &v254->mUID,
      v253,
      v251,
      0,
      8u,
      0i64,
      0);
  }
  else
  {
    v255 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v234, v255);
  UFG::qSymbol::create_from_string(&v585, "CritChance");
  v256 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v256;
  if ( v256 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v736;
    v311 = (UEL::Value::Type)&v738;
    v312 = (UEL::Value::Type)&v587;
    UEL::Value::Type::Type(&v736, ANSIX923);
    v258 = v257;
    UEL::Value::Type::Type(&v738, ANSIX923);
    v260 = v259;
    v261 = UFG::qSymbol::qSymbol(&v587, &v585);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v256,
      &v261->mUID,
      v260,
      v258,
      0,
      0xCu,
      0i64,
      0);
  }
  else
  {
    v262 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v234, v262);
  UFG::qSymbol::create_from_string(&v321, "MeleeWeaponStatData2");
  v263 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v263;
  if ( v263 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v740;
    v311 = (UEL::Value::Type)&v589;
    v312 = (UEL::Value::Type)&v742;
    v479 = (UEL::Value::Type)&v591;
    v528 = (UEL::Value::Type)&v593;
    v264 = UFG::qSymbol::qSymbol(&v589, &v321);
    UEL::Value::Type::Type(&v797, (UEL::Value::BaseType)8, &v264->mUID);
    UEL::Value::Type::Type(&v740, v265);
    v267 = v266;
    v268 = UFG::qSymbol::qSymbol(&v591, &v321);
    UEL::Value::Type::Type(&v790, (UEL::Value::BaseType)8, &v268->mUID);
    UEL::Value::Type::Type(&v742, v269);
    v271 = v270;
    v272 = UFG::qSymbol::qSymbol(&v593, &v321);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v263,
      &v272->mUID,
      v271,
      v267,
      0,
      0,
      v234,
      1);
  }
  else
  {
    v273 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(pParameterData, v273);
  v274 = AMemory::malloc_default(0x48ui64);
  v309 = (UEL::Value::Type)v274;
  if ( v274 )
  {
    UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>((UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0> *)v274);
    v276 = v275;
  }
  else
  {
    v276 = 0i64;
  }
  UFG::qSymbol::create_from_string(&v595, "Radius");
  v277 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v277;
  if ( v277 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v744;
    v311 = (UEL::Value::Type)&v528;
    v312 = (UEL::Value::Type)&v597;
    UEL::Value::Type::Type(&v744, ANSIX923);
    v279 = v278;
    UEL::Value::Type::Type(&v528, ANSIX923);
    v281 = v280;
    v282 = UFG::qSymbol::qSymbol(&v597, &v595);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v277,
      &v282->mUID,
      v281,
      v279,
      0,
      0,
      0i64,
      0);
  }
  else
  {
    v283 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v276, v283);
  UFG::qSymbol::create_from_string(&v599, "Duration");
  v284 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v284;
  if ( v284 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v479;
    v311 = (UEL::Value::Type)&v312;
    *(_QWORD *)&v611[0].mUID = &v601;
    UEL::Value::Type::Type(&v479, ANSIX923);
    v286 = v285;
    UEL::Value::Type::Type(&v312, ANSIX923);
    v288 = v287;
    v289 = UFG::qSymbol::qSymbol(&v601, &v599);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v284,
      &v289->mUID,
      v288,
      v286,
      0,
      4u,
      0i64,
      0);
  }
  else
  {
    v290 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v276, v290);
  UFG::qSymbol::create_from_string(&v603, "Damage");
  v291 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v291;
  if ( v291 )
  {
    *(_QWORD *)&v611[0].mUID = &v311;
    *(_QWORD *)&v622[0].mUID = &p_alwaysReturns;
    *(_QWORD *)&v621[0].mUID = &v605;
    UEL::Value::Type::Type(&v311, ANSIX923);
    v293 = v292;
    UEL::Value::Type::Type(&p_alwaysReturns, ANSIX923);
    v295 = v294;
    v296 = UFG::qSymbol::qSymbol(&v605, &v603);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v291,
      &v296->mUID,
      v295,
      v293,
      0,
      8u,
      0i64,
      0);
  }
  else
  {
    v297 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v276, v297);
  UFG::qSymbol::create_from_string(&v314, "ThrownWeaponStatData2");
  v298 = AMemory::malloc_default(0x50ui64);
  v803 = v298;
  if ( v298 )
  {
    v800 = &v792;
    v784 = v621;
    v785 = &v309;
    v787 = v622;
    v789 = v611;
    v299 = UFG::qSymbol::qSymbol(v621, &v314);
    UEL::Value::Type::Type(&v791, (UEL::Value::BaseType)8, &v299->mUID);
    UEL::Value::Type::Type(&v792, v300);
    v302 = v301;
    v303 = UFG::qSymbol::qSymbol(v622, &v314);
    UEL::Value::Type::Type(&v793, (UEL::Value::BaseType)8, &v303->mUID);
    UEL::Value::Type::Type(&v309, v304);
    v306 = v305;
    v307 = UFG::qSymbol::qSymbol(v611, &v314);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v298,
      &v307->mUID,
      v306,
      v302,
      0,
      0,
      v276,
      1);
    v2 = v308;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(pParameterData, v2);
} = 0i64;
  }
  UFG::qSymbol::create_from_string(&v595, "Radius");
  v277 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v277;
  if ( v277 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v744;
    v311 = (UEL::Value::Type)&v528;
    v312 = (UEL::Value::Type)&v597;
    UEL::Value::Type::Type(&v744, ANSIX923);
    v279 = v278;
    UEL::Value::Type::Type(&v528, ANSIX923);
    v281 = v280;
    v282 = UFG::qSymbol::qSymbol(&v597, &v595);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v277,
      &v282->mUID,
      v281,
      v279,
      0,
      0,
      0i64,
      0);
  }
  else
  {
    v283 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v276, v283);
  UFG::qSymbol::create_from_string(&v599, "Duration");
  v284 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v284;
  if ( v284 )
  {
    p_alwaysReturns = (UEL::Value::Type)&v479;
    v311 = (UEL::Value::Type)&v312;
    *(_QWORD *)&v611[0].mUID = &v601;
    UEL::Value::Type::Type(&v479, ANSIX923);
    v286 = v285;
    UEL::Value::Type::Type(&v312, ANSIX923);
    v288 = v287;
    v289 = UFG::qSymbol::qSymbol(&v601, &v599);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v284,
      &v289->mUID,
      v288,
      v286,
      0,
      4u,
      0i64,
      0);
  }
  else
  {
    v290 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v276, v290);
  UFG::qSymbol::create_from_string(&v603, "Damage");
  v291 = AMemory::malloc_default(0x50ui64);
  v309 = (UEL::Value::Type)v291;
  if ( v291 )
  {
    *(_QWORD *)&v611[0].mUID = &v311;
    *(_QWORD *)&v622[0].mUID = &p_alwaysReturns;
    *(_QWORD *)&v621[0].mUID = &v605;
    UEL::Value::Type::Type(&v311, ANSIX923);
    v293 = v292;
    UEL::Value::Type::Type(&p_alwaysReturns, ANSIX923);
    v295 = v294;
    v296 = UFG::qSymbol::qSymbol(&v605, &v603);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v291,
      &v296->mUID,
      v295,
      v293,
      0,
      8u,
      0i64,
      0);
  }
  else
  {
    v297 = 0i64;
  }
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(v276, v297);
  UFG::qSymbol::create_from_string(&v314, "ThrownWeaponStatData2");
  v298 = AMemory::malloc_default(0x50ui64);
  v803 = v298;
  if ( v298 )
  {
    v800 = &v792;
    v784 = v621;
    v785 = &v309;
    v787 = v622;
    v789 = v611;
    v299 = UFG::qSymbol::qSymbol(v621, &v314);
    UEL::Value::Type::Type(&v791, (UEL::Value::BaseType)8, &v299->mUID);
    UEL::Value::Type::Type(&v792, v300);
    v302 = v301;
    v303 = UFG::qSymbol::qSymbol(v622, &v314);
    UEL::Value::Type::Type(&v793, (UEL::Value::BaseType)8, &v303->mUID);
    UEL::Value::Type::Type(&v309, v304);
    v306 = v305;
    v307 = UFG::qSymbol::qSymbol(v611, &v314);
    UEL::ParameterBindingEntry::ParameterBindingEntry(
      (UEL::ParameterBindingEntry *)v298,

