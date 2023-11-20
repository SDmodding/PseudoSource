// File Line: 53
// RVA: 0x3FA50
void __fastcall UFG::RenderContext::RenderContext(UFG::RenderContext *this, const char *description, unsigned int scene_output_width, unsigned int scene_output_height, unsigned int reflection_width, unsigned int reflection_height, unsigned int envmap_size, bool bRequireReadAccess, bool bLightMRT, Render::eAAQuality aaQuality, UFG::RenderContext::AntiAliasState aa_state)
{
  unsigned int v11; // edi
  unsigned int v12; // esi
  const char *v13; // rbp
  UFG::RenderContext *v14; // rbx
  signed int v15; // eax
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm3
  UFG::qVector4 v19; // xmm1
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm3
  char *v22; // rax
  Render::RenderOutputParams outSettings; // [rsp+60h] [rbp-78h]

  v11 = scene_output_height;
  v12 = scene_output_width;
  v13 = description;
  v14 = this;
  Render::RenderOutputParams::RenderOutputParams(&this->mRenderSettingsForFrame);
  *(_DWORD *)&v14->mRenderFeatures.mWorld = 0x1000101;
  *(_DWORD *)&v14->mRenderFeatures.mAlternateGradientBackground = 16843008;
  *(_DWORD *)&v14->mRenderFeatures.mAO = 65793;
  Render::ViewMetrics::Reset(&v14->mRenderStats);
  UFG::qMemSet(v14, 0, 0x4D0u);
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  v14->mNumCascades = 0;
  v15 = 0;
  if ( outSettings.mShadowRes >= SHADOW_RES_NORMAL )
    v15 = 4;
  v14->mNumSpotShadowsAllowed = v15;
  *(_QWORD *)&v14->mAOOpacity = 1065353216i64;
  v14->mLightWithIrradianceVolumesType = 1;
  v14->mAmbientOcclusionVolumesType = 2;
  v14->mAntiAliasState = aa_state;
  v14->mReflection = 0i64;
  v14->mCombineAmbientSpecAndSun = 1;
  v14->mTargetsCreated = 0;
  v14->mMainViewSettings.mCullIndex = -1;
  v16 = UFG::qMatrix44::msIdentity.v1;
  v17 = UFG::qMatrix44::msIdentity.v2;
  v18 = UFG::qMatrix44::msIdentity.v3;
  v14->mMainViewSettings.mWorldView.v0 = UFG::qMatrix44::msIdentity.v0;
  v14->mMainViewSettings.mWorldView.v1 = v16;
  v14->mMainViewSettings.mWorldView.v2 = v17;
  v14->mMainViewSettings.mWorldView.v3 = v18;
  v19 = UFG::qMatrix44::msIdentity.v1;
  v20 = UFG::qMatrix44::msIdentity.v2;
  v21 = UFG::qMatrix44::msIdentity.v3;
  v14->mMainViewSettings.mProjection.v0 = UFG::qMatrix44::msIdentity.v0;
  v14->mMainViewSettings.mProjection.v1 = v19;
  v14->mMainViewSettings.mProjection.v2 = v20;
  v14->mMainViewSettings.mProjection.v3 = v21;
  v22 = UFG::qMalloc(0x10ui64, "RenderContextPlat", 0i64);
  if ( v22 )
    *(_QWORD *)v22 = v14;
  v14->mRenderContextPlat = (UFG::RenderContextPlat *)v22;
  UFG::RenderContext::CreateTargets(
    v14,
    v13,
    v12,
    v11,
    reflection_width,
    reflection_height,
    envmap_size,
    bRequireReadAccess,
    bLightMRT,
    aaQuality);
  UFG::RenderContext::CreateMaterials(v14);
}

// File Line: 90
// RVA: 0x435A0
void __fastcall UFG::RenderContext::CreateTargets(UFG::RenderContext *this, const char *description, unsigned int scene_output_width, unsigned int scene_output_height, unsigned int reflection_width, unsigned int reflection_height, unsigned int envmap_size, bool bRequireReadAccess, bool bLightMRT, Render::eAAQuality aaQuality)
{
  signed int v10; // edi
  signed int v11; // esi
  const char *v12; // r12
  UFG::RenderContext *v13; // r15
  float v14; // xmm1_4
  unsigned int v15; // eax
  unsigned int v16; // eax
  char *v17; // rax
  char *v18; // rdi
  UFG::qString *v19; // rax
  Illusion::Target *v20; // rax
  Illusion::Texture *v21; // r14
  Illusion::Texture *v22; // rbx
  Illusion::Texture *v23; // rdi
  Illusion::Texture *v24; // rsi
  UFG::qString *v25; // rax
  UFG::qString *v26; // rax
  Illusion::Target *v27; // rax
  Illusion::Texture *v28; // rbx
  unsigned int v29; // eax
  UFG::qString *v30; // rax
  Illusion::Target *v31; // rax
  Illusion::Texture *v32; // rbx
  unsigned int v33; // eax
  Illusion::Texture *v34; // rbx
  unsigned int v35; // eax
  UFG::qString *v36; // rax
  unsigned int v37; // edi
  unsigned int v38; // ebx
  UFG::qString *v39; // rax
  UFG::qString *v40; // rax
  unsigned int v41; // edi
  unsigned int v42; // ebx
  UFG::qString *v43; // rax
  Illusion::Target *v44; // rax
  UFG::qString *v45; // rax
  UFG::qString *v46; // rax
  Illusion::Target *v47; // rax
  UFG::qString *v48; // rax
  Illusion::Target *v49; // rax
  unsigned int v50; // eax
  UFG::qString *v51; // rax
  Illusion::Target *v52; // rax
  signed int v53; // ebx
  UFG::qString *v54; // rax
  UFG::qString *v55; // rax
  UFG::qString *v56; // rax
  UFG::qString *v57; // rax
  UFG::qString *v58; // rax
  UFG::qString *v59; // rax
  UFG::qString *v60; // rax
  UFG::qString *v61; // rax
  UFG::qString *v62; // rax
  UFG::qString *v63; // rax
  UFG::qString *v64; // rax
  UFG::qString *v65; // rax
  UFG::qString *v66; // rax
  Illusion::Texture *v67; // rbx
  UFG::qString *v68; // rax
  Illusion::Texture *v69; // rbx
  UFG::qString *v70; // rax
  UFG::qString *v71; // rax
  UFG::qString *v72; // rax
  Illusion::Target *v73; // rax
  unsigned int v74; // edi
  UFG::qString *v75; // rax
  UFG::qString *v76; // rax
  UFG::qString *v77; // rax
  unsigned int v78; // eax
  Illusion::Target *v79; // rax
  Illusion::Texture *v80; // rbx
  unsigned int v81; // eax
  UFG::qString *v82; // rax
  unsigned int v83; // eax
  Illusion::Target *v84; // rax
  Illusion::Texture *v85; // rbx
  unsigned int v86; // eax
  UFG::qString *v87; // rax
  unsigned int v88; // eax
  Illusion::Target *v89; // rax
  Illusion::Texture *v90; // rbx
  unsigned int v91; // eax
  UFG::qString *v92; // rax
  Illusion::Target *v93; // rax
  Illusion::Texture *v94; // rbx
  unsigned int v95; // eax
  UFG::qString *v96; // rax
  UFG::qString *v97; // rax
  Illusion::Target *v98; // rax
  Illusion::Texture *v99; // rbx
  unsigned int v100; // eax
  UFG::qString *v101; // rax
  unsigned int v102; // eax
  UFG::qString *v103; // rax
  unsigned int v104; // eax
  UFG::qString *v105; // rax
  unsigned int v106; // eax
  UFG::qString *v107; // rax
  unsigned int v108; // eax
  UFG::qString *v109; // rax
  unsigned int v110; // eax
  UFG::qString *v111; // rax
  unsigned int v112; // eax
  UFG::qString *v113; // rax
  unsigned int v114; // eax
  UFG::qString *v115; // rax
  UFG::qString *v116; // rax
  UFG::qString *v117; // rax
  Render::eHardwareFeatureLevel v118; // eax
  UFG::qString *v119; // rax
  UFG::qString *v120; // rax
  Illusion::Texture *v121; // rbx
  UFG::qString *v122; // rax
  Illusion::Target *v123; // rax
  UFG::qString *v124; // rax
  UFG::qString *v125; // rax
  UFG::qString result; // [rsp+50h] [rbp-B0h]
  UFG::qString v127; // [rsp+80h] [rbp-80h]
  unsigned __int64 v128; // [rsp+A8h] [rbp-58h]
  int v129; // [rsp+B0h] [rbp-50h]
  int v130; // [rsp+B4h] [rbp-4Ch]
  int v131; // [rsp+B8h] [rbp-48h]
  __int64 v132; // [rsp+BCh] [rbp-44h]
  int v133; // [rsp+C4h] [rbp-3Ch]
  int v134; // [rsp+C8h] [rbp-38h]
  __int128 v135; // [rsp+D0h] [rbp-30h]
  __int128 v136; // [rsp+E0h] [rbp-20h]
  __int64 v137; // [rsp+F0h] [rbp-10h]
  __int64 v138; // [rsp+F8h] [rbp-8h]
  __int64 v139; // [rsp+100h] [rbp+0h]
  __int64 v140; // [rsp+108h] [rbp+8h]
  __int64 v141; // [rsp+110h] [rbp+10h]
  __int64 v142; // [rsp+118h] [rbp+18h]
  int v143; // [rsp+120h] [rbp+20h]
  char v144; // [rsp+124h] [rbp+24h]
  UFG::qString v145; // [rsp+130h] [rbp+30h]
  __int64 v146; // [rsp+158h] [rbp+58h]
  int v147; // [rsp+160h] [rbp+60h]
  int v148; // [rsp+164h] [rbp+64h]
  int v149; // [rsp+168h] [rbp+68h]
  __int64 v150; // [rsp+16Ch] [rbp+6Ch]
  int v151; // [rsp+174h] [rbp+74h]
  int v152; // [rsp+178h] [rbp+78h]
  __int128 v153; // [rsp+180h] [rbp+80h]
  __int128 v154; // [rsp+190h] [rbp+90h]
  Illusion::Texture *v155; // [rsp+1A0h] [rbp+A0h]
  __int64 v156; // [rsp+1A8h] [rbp+A8h]
  __int64 v157; // [rsp+1B0h] [rbp+B0h]
  __int64 v158; // [rsp+1B8h] [rbp+B8h]
  __int64 v159; // [rsp+1C0h] [rbp+C0h]
  __int64 v160; // [rsp+1C8h] [rbp+C8h]
  int v161; // [rsp+1D0h] [rbp+D0h]
  char v162; // [rsp+1D4h] [rbp+D4h]
  UFG::qString v163; // [rsp+1E0h] [rbp+E0h]
  __int64 v164; // [rsp+208h] [rbp+108h]
  int v165; // [rsp+210h] [rbp+110h]
  int v166; // [rsp+214h] [rbp+114h]
  int v167; // [rsp+218h] [rbp+118h]
  __int64 v168; // [rsp+21Ch] [rbp+11Ch]
  int v169; // [rsp+224h] [rbp+124h]
  int v170; // [rsp+228h] [rbp+128h]
  __int128 v171; // [rsp+230h] [rbp+130h]
  __int128 v172; // [rsp+240h] [rbp+140h]
  __int64 v173; // [rsp+250h] [rbp+150h]
  __int64 v174; // [rsp+258h] [rbp+158h]
  __int64 v175; // [rsp+260h] [rbp+160h]
  __int64 v176; // [rsp+268h] [rbp+168h]
  __int64 v177; // [rsp+270h] [rbp+170h]
  __int64 v178; // [rsp+278h] [rbp+178h]
  int v179; // [rsp+280h] [rbp+180h]
  char v180; // [rsp+284h] [rbp+184h]
  UFG::qString v181; // [rsp+290h] [rbp+190h]
  __int64 v182; // [rsp+2B8h] [rbp+1B8h]
  int v183; // [rsp+2C0h] [rbp+1C0h]
  int v184; // [rsp+2C4h] [rbp+1C4h]
  int v185; // [rsp+2C8h] [rbp+1C8h]
  __int64 v186; // [rsp+2CCh] [rbp+1CCh]
  int v187; // [rsp+2D4h] [rbp+1D4h]
  int v188; // [rsp+2D8h] [rbp+1D8h]
  __int128 v189; // [rsp+2E0h] [rbp+1E0h]
  __int128 v190; // [rsp+2F0h] [rbp+1F0h]
  __int64 v191; // [rsp+300h] [rbp+200h]
  __int64 v192; // [rsp+308h] [rbp+208h]
  __int64 v193; // [rsp+310h] [rbp+210h]
  __int64 v194; // [rsp+318h] [rbp+218h]
  __int64 v195; // [rsp+320h] [rbp+220h]
  __int64 v196; // [rsp+328h] [rbp+228h]
  int v197; // [rsp+330h] [rbp+230h]
  char v198; // [rsp+334h] [rbp+234h]
  UFG::qString v199; // [rsp+340h] [rbp+240h]
  __int64 v200; // [rsp+368h] [rbp+268h]
  int v201; // [rsp+370h] [rbp+270h]
  int v202; // [rsp+374h] [rbp+274h]
  int v203; // [rsp+378h] [rbp+278h]
  __int64 v204; // [rsp+37Ch] [rbp+27Ch]
  int v205; // [rsp+384h] [rbp+284h]
  int v206; // [rsp+388h] [rbp+288h]
  __int128 v207; // [rsp+390h] [rbp+290h]
  __int128 v208; // [rsp+3A0h] [rbp+2A0h]
  __int64 v209; // [rsp+3B0h] [rbp+2B0h]
  __int64 v210; // [rsp+3B8h] [rbp+2B8h]
  __int64 v211; // [rsp+3C0h] [rbp+2C0h]
  __int64 v212; // [rsp+3C8h] [rbp+2C8h]
  __int64 v213; // [rsp+3D0h] [rbp+2D0h]
  __int64 v214; // [rsp+3D8h] [rbp+2D8h]
  int v215; // [rsp+3E0h] [rbp+2E0h]
  char v216; // [rsp+3E4h] [rbp+2E4h]
  UFG::qString v217; // [rsp+3F0h] [rbp+2F0h]
  __int64 v218; // [rsp+418h] [rbp+318h]
  int v219; // [rsp+420h] [rbp+320h]
  int v220; // [rsp+424h] [rbp+324h]
  int v221; // [rsp+428h] [rbp+328h]
  __int64 v222; // [rsp+42Ch] [rbp+32Ch]
  int v223; // [rsp+434h] [rbp+334h]
  int v224; // [rsp+438h] [rbp+338h]
  __int128 v225; // [rsp+440h] [rbp+340h]
  __int128 v226; // [rsp+450h] [rbp+350h]
  Illusion::Texture *v227; // [rsp+460h] [rbp+360h]
  __int64 v228; // [rsp+468h] [rbp+368h]
  __int64 v229; // [rsp+470h] [rbp+370h]
  __int64 v230; // [rsp+478h] [rbp+378h]
  __int64 v231; // [rsp+480h] [rbp+380h]
  __int64 v232; // [rsp+488h] [rbp+388h]
  int v233; // [rsp+490h] [rbp+390h]
  char v234; // [rsp+494h] [rbp+394h]
  UFG::qString v235; // [rsp+4A0h] [rbp+3A0h]
  __int64 v236; // [rsp+4C8h] [rbp+3C8h]
  int v237; // [rsp+4D0h] [rbp+3D0h]
  int v238; // [rsp+4D4h] [rbp+3D4h]
  int v239; // [rsp+4D8h] [rbp+3D8h]
  __int64 v240; // [rsp+4DCh] [rbp+3DCh]
  int v241; // [rsp+4E4h] [rbp+3E4h]
  int v242; // [rsp+4E8h] [rbp+3E8h]
  __int128 v243; // [rsp+4F0h] [rbp+3F0h]
  __int128 v244; // [rsp+500h] [rbp+400h]
  Illusion::Texture *v245; // [rsp+510h] [rbp+410h]
  __int64 v246; // [rsp+518h] [rbp+418h]
  __int64 v247; // [rsp+520h] [rbp+420h]
  __int64 v248; // [rsp+528h] [rbp+428h]
  __int64 v249; // [rsp+530h] [rbp+430h]
  __int64 v250; // [rsp+538h] [rbp+438h]
  int v251; // [rsp+540h] [rbp+440h]
  char v252; // [rsp+544h] [rbp+444h]
  UFG::qString v253; // [rsp+550h] [rbp+450h]
  __int64 v254; // [rsp+578h] [rbp+478h]
  int v255; // [rsp+580h] [rbp+480h]
  int v256; // [rsp+584h] [rbp+484h]
  int v257; // [rsp+588h] [rbp+488h]
  __int64 v258; // [rsp+58Ch] [rbp+48Ch]
  int v259; // [rsp+594h] [rbp+494h]
  int v260; // [rsp+598h] [rbp+498h]
  __int128 v261; // [rsp+5A0h] [rbp+4A0h]
  __int128 v262; // [rsp+5B0h] [rbp+4B0h]
  Illusion::Texture *v263; // [rsp+5C0h] [rbp+4C0h]
  __int64 v264; // [rsp+5C8h] [rbp+4C8h]
  __int64 v265; // [rsp+5D0h] [rbp+4D0h]
  __int64 v266; // [rsp+5D8h] [rbp+4D8h]
  __int64 v267; // [rsp+5E0h] [rbp+4E0h]
  __int64 v268; // [rsp+5E8h] [rbp+4E8h]
  int v269; // [rsp+5F0h] [rbp+4F0h]
  char v270; // [rsp+5F4h] [rbp+4F4h]
  UFG::qString v271; // [rsp+600h] [rbp+500h]
  __int64 v272; // [rsp+628h] [rbp+528h]
  int v273; // [rsp+630h] [rbp+530h]
  int v274; // [rsp+634h] [rbp+534h]
  int v275; // [rsp+638h] [rbp+538h]
  __int64 v276; // [rsp+63Ch] [rbp+53Ch]
  int v277; // [rsp+644h] [rbp+544h]
  int v278; // [rsp+648h] [rbp+548h]
  __int128 v279; // [rsp+650h] [rbp+550h]
  __int128 v280; // [rsp+660h] [rbp+560h]
  __int64 v281; // [rsp+670h] [rbp+570h]
  __int64 v282; // [rsp+678h] [rbp+578h]
  __int64 v283; // [rsp+680h] [rbp+580h]
  __int64 v284; // [rsp+688h] [rbp+588h]
  __int64 v285; // [rsp+690h] [rbp+590h]
  __int64 v286; // [rsp+698h] [rbp+598h]
  int v287; // [rsp+6A0h] [rbp+5A0h]
  char v288; // [rsp+6A4h] [rbp+5A4h]
  UFG::qString v289; // [rsp+6B0h] [rbp+5B0h]
  __int64 v290; // [rsp+6D8h] [rbp+5D8h]
  int v291; // [rsp+6E0h] [rbp+5E0h]
  int v292; // [rsp+6E4h] [rbp+5E4h]
  int v293; // [rsp+6E8h] [rbp+5E8h]
  __int64 v294; // [rsp+6ECh] [rbp+5ECh]
  int v295; // [rsp+6F4h] [rbp+5F4h]
  int v296; // [rsp+6F8h] [rbp+5F8h]
  __int128 v297; // [rsp+700h] [rbp+600h]
  __int128 v298; // [rsp+710h] [rbp+610h]
  Illusion::Texture *v299; // [rsp+720h] [rbp+620h]
  __int64 v300; // [rsp+728h] [rbp+628h]
  __int64 v301; // [rsp+730h] [rbp+630h]
  __int64 v302; // [rsp+738h] [rbp+638h]
  __int64 v303; // [rsp+740h] [rbp+640h]
  __int64 v304; // [rsp+748h] [rbp+648h]
  int v305; // [rsp+750h] [rbp+650h]
  char v306; // [rsp+754h] [rbp+654h]
  UFG::qString v307; // [rsp+760h] [rbp+660h]
  __int64 v308; // [rsp+788h] [rbp+688h]
  int v309; // [rsp+790h] [rbp+690h]
  int v310; // [rsp+794h] [rbp+694h]
  int v311; // [rsp+798h] [rbp+698h]
  __int64 v312; // [rsp+79Ch] [rbp+69Ch]
  int v313; // [rsp+7A4h] [rbp+6A4h]
  int v314; // [rsp+7A8h] [rbp+6A8h]
  __int128 v315; // [rsp+7B0h] [rbp+6B0h]
  __int128 v316; // [rsp+7C0h] [rbp+6C0h]
  __int64 v317; // [rsp+7D0h] [rbp+6D0h]
  __int64 v318; // [rsp+7D8h] [rbp+6D8h]
  __int64 v319; // [rsp+7E0h] [rbp+6E0h]
  __int64 v320; // [rsp+7E8h] [rbp+6E8h]
  __int64 v321; // [rsp+7F0h] [rbp+6F0h]
  __int64 v322; // [rsp+7F8h] [rbp+6F8h]
  int v323; // [rsp+800h] [rbp+700h]
  char v324; // [rsp+804h] [rbp+704h]
  UFG::qString v325; // [rsp+810h] [rbp+710h]
  unsigned __int64 v326; // [rsp+838h] [rbp+738h]
  int v327; // [rsp+840h] [rbp+740h]
  int v328; // [rsp+844h] [rbp+744h]
  int v329; // [rsp+848h] [rbp+748h]
  __int64 v330; // [rsp+84Ch] [rbp+74Ch]
  int v331; // [rsp+854h] [rbp+754h]
  int v332; // [rsp+858h] [rbp+758h]
  __int128 v333; // [rsp+860h] [rbp+760h]
  __int128 v334; // [rsp+870h] [rbp+770h]
  Illusion::Texture *v335; // [rsp+880h] [rbp+780h]
  __int64 v336; // [rsp+888h] [rbp+788h]
  __int64 v337; // [rsp+890h] [rbp+790h]
  __int64 v338; // [rsp+898h] [rbp+798h]
  __int64 v339; // [rsp+8A0h] [rbp+7A0h]
  __int64 v340; // [rsp+8A8h] [rbp+7A8h]
  int v341; // [rsp+8B0h] [rbp+7B0h]
  char v342; // [rsp+8B4h] [rbp+7B4h]
  UFG::qString v343; // [rsp+8C0h] [rbp+7C0h]
  __int64 v344; // [rsp+8E8h] [rbp+7E8h]
  int v345; // [rsp+8F0h] [rbp+7F0h]
  int v346; // [rsp+8F4h] [rbp+7F4h]
  int v347; // [rsp+8F8h] [rbp+7F8h]
  __int64 v348; // [rsp+8FCh] [rbp+7FCh]
  int v349; // [rsp+904h] [rbp+804h]
  int v350; // [rsp+908h] [rbp+808h]
  __int128 v351; // [rsp+910h] [rbp+810h]
  __int128 v352; // [rsp+920h] [rbp+820h]
  __int64 v353; // [rsp+930h] [rbp+830h]
  __int64 v354; // [rsp+938h] [rbp+838h]
  __int64 v355; // [rsp+940h] [rbp+840h]
  __int64 v356; // [rsp+948h] [rbp+848h]
  __int64 v357; // [rsp+950h] [rbp+850h]
  __int64 v358; // [rsp+958h] [rbp+858h]
  int v359; // [rsp+960h] [rbp+860h]
  char v360; // [rsp+964h] [rbp+864h]
  UFG::qString v361; // [rsp+970h] [rbp+870h]
  __int64 v362; // [rsp+998h] [rbp+898h]
  int v363; // [rsp+9A0h] [rbp+8A0h]
  int v364; // [rsp+9A4h] [rbp+8A4h]
  int v365; // [rsp+9A8h] [rbp+8A8h]
  __int64 v366; // [rsp+9ACh] [rbp+8ACh]
  int v367; // [rsp+9B4h] [rbp+8B4h]
  int v368; // [rsp+9B8h] [rbp+8B8h]
  __int128 v369; // [rsp+9C0h] [rbp+8C0h]
  __int128 v370; // [rsp+9D0h] [rbp+8D0h]
  __int64 v371; // [rsp+9E0h] [rbp+8E0h]
  __int64 v372; // [rsp+9E8h] [rbp+8E8h]
  __int64 v373; // [rsp+9F0h] [rbp+8F0h]
  __int64 v374; // [rsp+9F8h] [rbp+8F8h]
  __int64 v375; // [rsp+A00h] [rbp+900h]
  __int64 v376; // [rsp+A08h] [rbp+908h]
  int v377; // [rsp+A10h] [rbp+910h]
  char v378; // [rsp+A14h] [rbp+914h]
  UFG::qString v379; // [rsp+A20h] [rbp+920h]
  unsigned __int64 v380; // [rsp+A48h] [rbp+948h]
  int v381; // [rsp+A50h] [rbp+950h]
  int v382; // [rsp+A54h] [rbp+954h]
  int v383; // [rsp+A58h] [rbp+958h]
  __int64 v384; // [rsp+A5Ch] [rbp+95Ch]
  int v385; // [rsp+A64h] [rbp+964h]
  int v386; // [rsp+A68h] [rbp+968h]
  __int128 v387; // [rsp+A70h] [rbp+970h]
  __int128 v388; // [rsp+A80h] [rbp+980h]
  __int64 v389; // [rsp+A90h] [rbp+990h]
  __int64 v390; // [rsp+A98h] [rbp+998h]
  __int64 v391; // [rsp+AA0h] [rbp+9A0h]
  __int64 v392; // [rsp+AA8h] [rbp+9A8h]
  __int64 v393; // [rsp+AB0h] [rbp+9B0h]
  __int64 v394; // [rsp+AB8h] [rbp+9B8h]
  int v395; // [rsp+AC0h] [rbp+9C0h]
  char v396; // [rsp+AC4h] [rbp+9C4h]
  UFG::qString v397; // [rsp+AD0h] [rbp+9D0h]
  __int64 v398; // [rsp+AF8h] [rbp+9F8h]
  int v399; // [rsp+B00h] [rbp+A00h]
  int v400; // [rsp+B04h] [rbp+A04h]
  int v401; // [rsp+B08h] [rbp+A08h]
  __int64 v402; // [rsp+B0Ch] [rbp+A0Ch]
  int v403; // [rsp+B14h] [rbp+A14h]
  int v404; // [rsp+B18h] [rbp+A18h]
  __int128 v405; // [rsp+B20h] [rbp+A20h]
  __int128 v406; // [rsp+B30h] [rbp+A30h]
  __int64 v407; // [rsp+B40h] [rbp+A40h]
  __int64 v408; // [rsp+B48h] [rbp+A48h]
  __int64 v409; // [rsp+B50h] [rbp+A50h]
  __int64 v410; // [rsp+B58h] [rbp+A58h]
  __int64 v411; // [rsp+B60h] [rbp+A60h]
  __int64 v412; // [rsp+B68h] [rbp+A68h]
  int v413; // [rsp+B70h] [rbp+A70h]
  char v414; // [rsp+B74h] [rbp+A74h]
  UFG::qString v415; // [rsp+B80h] [rbp+A80h]
  __int64 v416; // [rsp+BA8h] [rbp+AA8h]
  int v417; // [rsp+BB0h] [rbp+AB0h]
  int v418; // [rsp+BB4h] [rbp+AB4h]
  int v419; // [rsp+BB8h] [rbp+AB8h]
  __int64 v420; // [rsp+BBCh] [rbp+ABCh]
  int v421; // [rsp+BC4h] [rbp+AC4h]
  int v422; // [rsp+BC8h] [rbp+AC8h]
  __int128 v423; // [rsp+BD0h] [rbp+AD0h]
  __int128 v424; // [rsp+BE0h] [rbp+AE0h]
  __int64 v425; // [rsp+BF0h] [rbp+AF0h]
  __int64 v426; // [rsp+BF8h] [rbp+AF8h]
  __int64 v427; // [rsp+C00h] [rbp+B00h]
  __int64 v428; // [rsp+C08h] [rbp+B08h]
  __int64 v429; // [rsp+C10h] [rbp+B10h]
  __int64 v430; // [rsp+C18h] [rbp+B18h]
  int v431; // [rsp+C20h] [rbp+B20h]
  char v432; // [rsp+C24h] [rbp+B24h]
  UFG::qString v433; // [rsp+C30h] [rbp+B30h]
  unsigned __int64 v434; // [rsp+C58h] [rbp+B58h]
  int v435; // [rsp+C60h] [rbp+B60h]
  int v436; // [rsp+C64h] [rbp+B64h]
  int v437; // [rsp+C68h] [rbp+B68h]
  __int64 v438; // [rsp+C6Ch] [rbp+B6Ch]
  int v439; // [rsp+C74h] [rbp+B74h]
  int v440; // [rsp+C78h] [rbp+B78h]
  __int128 v441; // [rsp+C80h] [rbp+B80h]
  __int128 v442; // [rsp+C90h] [rbp+B90h]
  __int64 v443; // [rsp+CA0h] [rbp+BA0h]
  __int64 v444; // [rsp+CA8h] [rbp+BA8h]
  __int64 v445; // [rsp+CB0h] [rbp+BB0h]
  __int64 v446; // [rsp+CB8h] [rbp+BB8h]
  __int64 v447; // [rsp+CC0h] [rbp+BC0h]
  __int64 v448; // [rsp+CC8h] [rbp+BC8h]
  int v449; // [rsp+CD0h] [rbp+BD0h]
  char v450; // [rsp+CD4h] [rbp+BD4h]
  UFG::qString v451; // [rsp+CE0h] [rbp+BE0h]
  __int64 v452; // [rsp+D08h] [rbp+C08h]
  int v453; // [rsp+D10h] [rbp+C10h]
  int v454; // [rsp+D14h] [rbp+C14h]
  int v455; // [rsp+D18h] [rbp+C18h]
  __int64 v456; // [rsp+D1Ch] [rbp+C1Ch]
  int v457; // [rsp+D24h] [rbp+C24h]
  int v458; // [rsp+D28h] [rbp+C28h]
  __int128 v459; // [rsp+D30h] [rbp+C30h]
  __int128 v460; // [rsp+D40h] [rbp+C40h]
  __int64 v461; // [rsp+D50h] [rbp+C50h]
  __int64 v462; // [rsp+D58h] [rbp+C58h]
  __int64 v463; // [rsp+D60h] [rbp+C60h]
  __int64 v464; // [rsp+D68h] [rbp+C68h]
  __int64 v465; // [rsp+D70h] [rbp+C70h]
  __int64 v466; // [rsp+D78h] [rbp+C78h]
  int v467; // [rsp+D80h] [rbp+C80h]
  char v468; // [rsp+D84h] [rbp+C84h]
  UFG::qString v469; // [rsp+D90h] [rbp+C90h]
  __int64 v470; // [rsp+DB8h] [rbp+CB8h]
  int v471; // [rsp+DC0h] [rbp+CC0h]
  int v472; // [rsp+DC4h] [rbp+CC4h]
  int v473; // [rsp+DC8h] [rbp+CC8h]
  __int64 v474; // [rsp+DCCh] [rbp+CCCh]
  int v475; // [rsp+DD4h] [rbp+CD4h]
  int v476; // [rsp+DD8h] [rbp+CD8h]
  __int128 v477; // [rsp+DE0h] [rbp+CE0h]
  __int128 v478; // [rsp+DF0h] [rbp+CF0h]
  __int64 v479; // [rsp+E00h] [rbp+D00h]
  __int64 v480; // [rsp+E08h] [rbp+D08h]
  __int64 v481; // [rsp+E10h] [rbp+D10h]
  __int64 v482; // [rsp+E18h] [rbp+D18h]
  __int64 v483; // [rsp+E20h] [rbp+D20h]
  __int64 v484; // [rsp+E28h] [rbp+D28h]
  int v485; // [rsp+E30h] [rbp+D30h]
  char v486; // [rsp+E34h] [rbp+D34h]
  UFG::qString v487; // [rsp+E40h] [rbp+D40h]
  __int64 v488; // [rsp+E68h] [rbp+D68h]
  int v489; // [rsp+E70h] [rbp+D70h]
  int v490; // [rsp+E74h] [rbp+D74h]
  int v491; // [rsp+E78h] [rbp+D78h]
  __int64 v492; // [rsp+E7Ch] [rbp+D7Ch]
  int v493; // [rsp+E84h] [rbp+D84h]
  int v494; // [rsp+E88h] [rbp+D88h]
  __int128 v495; // [rsp+E90h] [rbp+D90h]
  __int128 v496; // [rsp+EA0h] [rbp+DA0h]
  __int64 v497; // [rsp+EB0h] [rbp+DB0h]
  __int64 v498; // [rsp+EB8h] [rbp+DB8h]
  __int64 v499; // [rsp+EC0h] [rbp+DC0h]
  __int64 v500; // [rsp+EC8h] [rbp+DC8h]
  __int64 v501; // [rsp+ED0h] [rbp+DD0h]
  __int64 v502; // [rsp+ED8h] [rbp+DD8h]
  int v503; // [rsp+EE0h] [rbp+DE0h]
  char v504; // [rsp+EE4h] [rbp+DE4h]
  UFG::qString v505; // [rsp+EF0h] [rbp+DF0h]
  __int64 v506; // [rsp+F18h] [rbp+E18h]
  int v507; // [rsp+F20h] [rbp+E20h]
  int v508; // [rsp+F24h] [rbp+E24h]
  int v509; // [rsp+F28h] [rbp+E28h]
  __int64 v510; // [rsp+F2Ch] [rbp+E2Ch]
  int v511; // [rsp+F34h] [rbp+E34h]
  int v512; // [rsp+F38h] [rbp+E38h]
  __int128 v513; // [rsp+F40h] [rbp+E40h]
  __int128 v514; // [rsp+F50h] [rbp+E50h]
  __int64 v515; // [rsp+F60h] [rbp+E60h]
  __int64 v516; // [rsp+F68h] [rbp+E68h]
  __int64 v517; // [rsp+F70h] [rbp+E70h]
  __int64 v518; // [rsp+F78h] [rbp+E78h]
  __int64 v519; // [rsp+F80h] [rbp+E80h]
  __int64 v520; // [rsp+F88h] [rbp+E88h]
  int v521; // [rsp+F90h] [rbp+E90h]
  char v522; // [rsp+F94h] [rbp+E94h]
  UFG::qString v523; // [rsp+FA0h] [rbp+EA0h]
  __int64 v524; // [rsp+FC8h] [rbp+EC8h]
  int v525; // [rsp+FD0h] [rbp+ED0h]
  int v526; // [rsp+FD4h] [rbp+ED4h]
  int v527; // [rsp+FD8h] [rbp+ED8h]
  __int64 v528; // [rsp+FDCh] [rbp+EDCh]
  int v529; // [rsp+FE4h] [rbp+EE4h]
  int v530; // [rsp+FE8h] [rbp+EE8h]
  __int128 v531; // [rsp+FF0h] [rbp+EF0h]
  __int128 v532; // [rsp+1000h] [rbp+F00h]
  __int64 v533; // [rsp+1010h] [rbp+F10h]
  __int64 v534; // [rsp+1018h] [rbp+F18h]
  __int64 v535; // [rsp+1020h] [rbp+F20h]
  __int64 v536; // [rsp+1028h] [rbp+F28h]
  __int64 v537; // [rsp+1030h] [rbp+F30h]
  __int64 v538; // [rsp+1038h] [rbp+F38h]
  int v539; // [rsp+1040h] [rbp+F40h]
  char v540; // [rsp+1044h] [rbp+F44h]
  UFG::qString v541; // [rsp+1050h] [rbp+F50h]
  __int64 v542; // [rsp+1078h] [rbp+F78h]
  int v543; // [rsp+1080h] [rbp+F80h]
  int v544; // [rsp+1084h] [rbp+F84h]
  int v545; // [rsp+1088h] [rbp+F88h]
  __int64 v546; // [rsp+108Ch] [rbp+F8Ch]
  int v547; // [rsp+1094h] [rbp+F94h]
  int v548; // [rsp+1098h] [rbp+F98h]
  __int128 v549; // [rsp+10A0h] [rbp+FA0h]
  __int128 v550; // [rsp+10B0h] [rbp+FB0h]
  Illusion::Texture *v551; // [rsp+10C0h] [rbp+FC0h]
  __int64 v552; // [rsp+10C8h] [rbp+FC8h]
  __int64 v553; // [rsp+10D0h] [rbp+FD0h]
  __int64 v554; // [rsp+10D8h] [rbp+FD8h]
  __int64 v555; // [rsp+10E0h] [rbp+FE0h]
  __int64 v556; // [rsp+10E8h] [rbp+FE8h]
  int v557; // [rsp+10F0h] [rbp+FF0h]
  char v558; // [rsp+10F4h] [rbp+FF4h]
  UFG::qString v559; // [rsp+1100h] [rbp+1000h]
  __int64 v560; // [rsp+1128h] [rbp+1028h]
  int v561; // [rsp+1130h] [rbp+1030h]
  int v562; // [rsp+1134h] [rbp+1034h]
  int v563; // [rsp+1138h] [rbp+1038h]
  __int64 v564; // [rsp+113Ch] [rbp+103Ch]
  int v565; // [rsp+1144h] [rbp+1044h]
  int v566; // [rsp+1148h] [rbp+1048h]
  __int128 v567; // [rsp+1150h] [rbp+1050h]
  __int128 v568; // [rsp+1160h] [rbp+1060h]
  __int64 v569; // [rsp+1170h] [rbp+1070h]
  __int64 v570; // [rsp+1178h] [rbp+1078h]
  __int64 v571; // [rsp+1180h] [rbp+1080h]
  __int64 v572; // [rsp+1188h] [rbp+1088h]
  __int64 v573; // [rsp+1190h] [rbp+1090h]
  __int64 v574; // [rsp+1198h] [rbp+1098h]
  int v575; // [rsp+11A0h] [rbp+10A0h]
  char v576; // [rsp+11A4h] [rbp+10A4h]
  UFG::qString v577; // [rsp+11B0h] [rbp+10B0h]
  __int64 v578; // [rsp+11D8h] [rbp+10D8h]
  int v579; // [rsp+11E0h] [rbp+10E0h]
  int v580; // [rsp+11E4h] [rbp+10E4h]
  int v581; // [rsp+11E8h] [rbp+10E8h]
  __int64 v582; // [rsp+11ECh] [rbp+10ECh]
  int v583; // [rsp+11F4h] [rbp+10F4h]
  int v584; // [rsp+11F8h] [rbp+10F8h]
  __int128 v585; // [rsp+1200h] [rbp+1100h]
  __int128 v586; // [rsp+1210h] [rbp+1110h]
  __int64 v587; // [rsp+1220h] [rbp+1120h]
  __int64 v588; // [rsp+1228h] [rbp+1128h]
  __int64 v589; // [rsp+1230h] [rbp+1130h]
  __int64 v590; // [rsp+1238h] [rbp+1138h]
  __int64 v591; // [rsp+1240h] [rbp+1140h]
  __int64 v592; // [rsp+1248h] [rbp+1148h]
  int v593; // [rsp+1250h] [rbp+1150h]
  char v594; // [rsp+1254h] [rbp+1154h]
  UFG::qString v595; // [rsp+1260h] [rbp+1160h]
  __int64 v596; // [rsp+1288h] [rbp+1188h]
  int v597; // [rsp+1290h] [rbp+1190h]
  int v598; // [rsp+1294h] [rbp+1194h]
  int v599; // [rsp+1298h] [rbp+1198h]
  __int64 v600; // [rsp+129Ch] [rbp+119Ch]
  int v601; // [rsp+12A4h] [rbp+11A4h]
  int v602; // [rsp+12A8h] [rbp+11A8h]
  __int128 v603; // [rsp+12B0h] [rbp+11B0h]
  __int128 v604; // [rsp+12C0h] [rbp+11C0h]
  __int64 v605; // [rsp+12D0h] [rbp+11D0h]
  __int64 v606; // [rsp+12D8h] [rbp+11D8h]
  __int64 v607; // [rsp+12E0h] [rbp+11E0h]
  __int64 v608; // [rsp+12E8h] [rbp+11E8h]
  __int64 v609; // [rsp+12F0h] [rbp+11F0h]
  __int64 v610; // [rsp+12F8h] [rbp+11F8h]
  int v611; // [rsp+1300h] [rbp+1200h]
  char v612; // [rsp+1304h] [rbp+1204h]
  UFG::qString v613; // [rsp+1310h] [rbp+1210h]
  __int64 v614; // [rsp+1338h] [rbp+1238h]
  int v615; // [rsp+1340h] [rbp+1240h]
  int v616; // [rsp+1344h] [rbp+1244h]
  int v617; // [rsp+1348h] [rbp+1248h]
  __int64 v618; // [rsp+134Ch] [rbp+124Ch]
  int v619; // [rsp+1354h] [rbp+1254h]
  int v620; // [rsp+1358h] [rbp+1258h]
  __int128 v621; // [rsp+1360h] [rbp+1260h]
  __int128 v622; // [rsp+1370h] [rbp+1270h]
  Illusion::Texture *v623; // [rsp+1380h] [rbp+1280h]
  __int64 v624; // [rsp+1388h] [rbp+1288h]
  __int64 v625; // [rsp+1390h] [rbp+1290h]
  __int64 v626; // [rsp+1398h] [rbp+1298h]
  __int64 v627; // [rsp+13A0h] [rbp+12A0h]
  __int64 v628; // [rsp+13A8h] [rbp+12A8h]
  int v629; // [rsp+13B0h] [rbp+12B0h]
  char v630; // [rsp+13B4h] [rbp+12B4h]
  UFG::qString v631; // [rsp+13C0h] [rbp+12C0h]
  __int64 v632; // [rsp+13E8h] [rbp+12E8h]
  int v633; // [rsp+13F0h] [rbp+12F0h]
  int v634; // [rsp+13F4h] [rbp+12F4h]
  int v635; // [rsp+13F8h] [rbp+12F8h]
  __int64 v636; // [rsp+13FCh] [rbp+12FCh]
  int v637; // [rsp+1404h] [rbp+1304h]
  int v638; // [rsp+1408h] [rbp+1308h]
  __int128 v639; // [rsp+1410h] [rbp+1310h]
  __int128 v640; // [rsp+1420h] [rbp+1320h]
  __int64 v641; // [rsp+1430h] [rbp+1330h]
  __int64 v642; // [rsp+1438h] [rbp+1338h]
  __int64 v643; // [rsp+1440h] [rbp+1340h]
  __int64 v644; // [rsp+1448h] [rbp+1348h]
  __int64 v645; // [rsp+1450h] [rbp+1350h]
  __int64 v646; // [rsp+1458h] [rbp+1358h]
  int v647; // [rsp+1460h] [rbp+1360h]
  char v648; // [rsp+1464h] [rbp+1364h]
  UFG::qString v649; // [rsp+1470h] [rbp+1370h]
  __int64 v650; // [rsp+1498h] [rbp+1398h]
  int v651; // [rsp+14A0h] [rbp+13A0h]
  int v652; // [rsp+14A4h] [rbp+13A4h]
  int v653; // [rsp+14A8h] [rbp+13A8h]
  __int64 v654; // [rsp+14ACh] [rbp+13ACh]
  int v655; // [rsp+14B4h] [rbp+13B4h]
  int v656; // [rsp+14B8h] [rbp+13B8h]
  __int128 v657; // [rsp+14C0h] [rbp+13C0h]
  __int128 v658; // [rsp+14D0h] [rbp+13D0h]
  __int64 v659; // [rsp+14E0h] [rbp+13E0h]
  __int64 v660; // [rsp+14E8h] [rbp+13E8h]
  __int64 v661; // [rsp+14F0h] [rbp+13F0h]
  __int64 v662; // [rsp+14F8h] [rbp+13F8h]
  __int64 v663; // [rsp+1500h] [rbp+1400h]
  __int64 v664; // [rsp+1508h] [rbp+1408h]
  int v665; // [rsp+1510h] [rbp+1410h]
  char v666; // [rsp+1514h] [rbp+1414h]
  UFG::qString v667; // [rsp+1520h] [rbp+1420h]
  __int64 v668; // [rsp+1548h] [rbp+1448h]
  int v669; // [rsp+1550h] [rbp+1450h]
  int v670; // [rsp+1554h] [rbp+1454h]
  int v671; // [rsp+1558h] [rbp+1458h]
  __int64 v672; // [rsp+155Ch] [rbp+145Ch]
  int v673; // [rsp+1564h] [rbp+1464h]
  int v674; // [rsp+1568h] [rbp+1468h]
  __int128 v675; // [rsp+1570h] [rbp+1470h]
  __int128 v676; // [rsp+1580h] [rbp+1480h]
  __int64 v677; // [rsp+1590h] [rbp+1490h]
  __int64 v678; // [rsp+1598h] [rbp+1498h]
  __int64 v679; // [rsp+15A0h] [rbp+14A0h]
  __int64 v680; // [rsp+15A8h] [rbp+14A8h]
  __int64 v681; // [rsp+15B0h] [rbp+14B0h]
  __int64 v682; // [rsp+15B8h] [rbp+14B8h]
  int v683; // [rsp+15C0h] [rbp+14C0h]
  char v684; // [rsp+15C4h] [rbp+14C4h]
  UFG::qString v685; // [rsp+15D0h] [rbp+14D0h]
  __int64 v686; // [rsp+15F8h] [rbp+14F8h]
  int v687; // [rsp+1600h] [rbp+1500h]
  int v688; // [rsp+1604h] [rbp+1504h]
  int v689; // [rsp+1608h] [rbp+1508h]
  __int64 v690; // [rsp+160Ch] [rbp+150Ch]
  int v691; // [rsp+1614h] [rbp+1514h]
  int v692; // [rsp+1618h] [rbp+1518h]
  __int128 v693; // [rsp+1620h] [rbp+1520h]
  __int128 v694; // [rsp+1630h] [rbp+1530h]
  __int64 v695; // [rsp+1640h] [rbp+1540h]
  __int64 v696; // [rsp+1648h] [rbp+1548h]
  __int64 v697; // [rsp+1650h] [rbp+1550h]
  __int64 v698; // [rsp+1658h] [rbp+1558h]
  __int64 v699; // [rsp+1660h] [rbp+1560h]
  __int64 v700; // [rsp+1668h] [rbp+1568h]
  int v701; // [rsp+1670h] [rbp+1570h]
  char v702; // [rsp+1674h] [rbp+1574h]
  __int64 v703; // [rsp+1680h] [rbp+1580h]
  Illusion::CreateTargetParams params; // [rsp+1690h] [rbp+1590h]
  Render::RenderOutputParams outSettings; // [rsp+1740h] [rbp+1640h]
  char *v706; // [rsp+17F0h] [rbp+16F0h]
  int v707; // [rsp+1800h] [rbp+1700h]
  int v708; // [rsp+1808h] [rbp+1708h]

  v708 = scene_output_height;
  v707 = scene_output_width;
  v703 = -2i64;
  v10 = scene_output_height;
  v11 = scene_output_width;
  v12 = description;
  v13 = this;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  v13->mGBufferTarget = 0i64;
  v13->mCascadeShadowTarget = 0i64;
  v13->mCharacterShadowTarget = 0i64;
  v13->mCubeMapTarget = 0i64;
  if ( outSettings.mShadowRes == 2 )
  {
    v13->mCascadeShadowSize = 2048;
    v13->mSpotShadowSize = 2048;
    v13->mCharacterShadowSize = 1408;
  }
  else
  {
    v13->mCascadeShadowSize = 1024;
    v13->mSpotShadowSize = 1024;
    v13->mCharacterShadowSize = 1024;
  }
  v14 = *(float *)&FLOAT_1_0;
  if ( aaQuality == 1 )
  {
    v14 = FLOAT_1_333333;
LABEL_9:
    v15 = ((signed int)(float)((float)v11 * v14) + 31) & 0xFFFFFFE0;
    goto LABEL_11;
  }
  if ( aaQuality == 2 )
  {
    v14 = FLOAT_2_0;
    goto LABEL_9;
  }
  if ( aaQuality )
    goto LABEL_9;
  v15 = v11;
LABEL_11:
  v13->mGBufferWidth = v15;
  if ( aaQuality )
    v16 = ((signed int)(float)((float)v10 * v14) + 31) & 0xFFFFFFE0;
  else
    v16 = v10;
  v13->mGBufferHeight = v16;
  UFG::RenderContextPlat::CreateTargets(
    v13->mRenderContextPlat,
    v12,
    v11,
    v10,
    reflection_width,
    reflection_height,
    envmap_size,
    bRequireReadAccess,
    bLightMRT,
    aaQuality);
  if ( envmap_size )
  {
    v17 = UFG::qMalloc(0x4B0ui64, "EnvCubeMap", 0i64);
    v18 = v17;
    v706 = v17;
    if ( v17 )
      `eh vector constructor iterator'(v17 + 944, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::qString);
    else
      v18 = 0i64;
    v13->mEnvCubeMap = (Render::EnvCubeMap *)v18;
    if ( !v13->mCubeMapTarget )
    {
      UFG::qString::qString(&v127, "RealtimeCubeMap");
      v128 = 0i64;
      v129 = 1;
      v130 = 1;
      v131 = -1;
      v132 = 8589934593i64;
      v133 = 0;
      v134 = 1;
      _mm_store_si128((__m128i *)&v135, (__m128i)0i64);
      _mm_store_si128((__m128i *)&v136, (__m128i)0i64);
      v137 = 0i64;
      v138 = 0i64;
      v139 = 0i64;
      v140 = 0i64;
      v141 = 0i64;
      v142 = 0i64;
      v143 = 0;
      v144 = 0;
      LODWORD(v128) = envmap_size;
      HIDWORD(v128) = envmap_size;
      LOBYTE(v131) = 0;
      v133 = 1;
      v13->mCubeMapTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
      UFG::qString::~qString(&v127);
    }
    Render::EnvCubeMap::Init(v13->mEnvCubeMap, v13->mCubeMapTarget);
  }
  else
  {
    v13->mEnvCubeMap = 0i64;
  }
  if ( !v13->mGBufferTarget )
  {
    v19 = UFG::qString::FormatEx(&result, "GBuffers%s", v12);
    UFG::qString::qString(&v127, v19->mData);
    v132 = 1i64;
    v128 = 0i64;
    v129 = 1;
    v130 = 1;
    v131 = -1;
    v133 = 0;
    v134 = 1;
    _mm_store_si128((__m128i *)&v135, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v136, (__m128i)0i64);
    v137 = 0i64;
    v138 = 0i64;
    v139 = 0i64;
    v140 = 0i64;
    v141 = 0i64;
    v142 = 0i64;
    v143 = 0;
    v144 = 0;
    UFG::qString::~qString(&result);
    v128 = *(_QWORD *)&v13->mGBufferWidth;
    LOWORD(v131) = 0;
    BYTE2(v131) = 0;
    LODWORD(v132) = 3;
    v133 = (bRequireReadAccess != 0 ? 0x4000 : 0) | 0x210303;
    v13->mGBufferTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
    UFG::qString::~qString(&v127);
  }
  v20 = v13->mGBufferTarget;
  v21 = v20->mTargetTexture[0];
  v22 = v20->mTargetTexture[1];
  v23 = v20->mTargetTexture[2];
  v24 = v20->mDepthTextureCopy;
  Illusion::Texture::SetSamplerFilter(v20->mTargetTexture[0], 2u);
  Illusion::Texture::SetSamplerFilter(v22, 1u);
  Illusion::Texture::SetSamplerFilter(v23, 2u);
  Illusion::Texture::SetSamplerFilter(v24, 2u);
  Illusion::Texture::SetSamplerFilter(v13->mGBufferTarget->mDepthTexture, 2u);
  v25 = UFG::qString::FormatEx(&result, "GBufferDiffuseAlbedoAliasTarget%s", v12);
  UFG::qString::qString(&v685, v25->mData);
  v690 = 1i64;
  v686 = 0i64;
  v687 = 1;
  v688 = 1;
  v689 = -1;
  v691 = 0;
  v692 = 1;
  _mm_store_si128((__m128i *)&v693, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v694, (__m128i)0i64);
  v695 = 0i64;
  v696 = 0i64;
  v697 = 0i64;
  v698 = 0i64;
  v699 = 0i64;
  v700 = 0i64;
  v701 = 0;
  v702 = 0;
  UFG::qString::~qString(&result);
  *(_QWORD *)&v693 = v21;
  v691 = 256;
  v13->mGBufferDiffuseAlbedoAliasTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v685);
  v13->mGBufferDepthTarget = 0i64;
  v26 = UFG::qString::FormatEx(&result, "DynamicRange%s", v12);
  UFG::qString::qString(&v235, v26->mData);
  v240 = 1i64;
  v236 = 0i64;
  v237 = 1;
  v238 = 1;
  v239 = -1;
  v241 = 0;
  v242 = 1;
  _mm_store_si128((__m128i *)&v243, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v244, (__m128i)0i64);
  v245 = 0i64;
  v246 = 0i64;
  v247 = 0i64;
  v248 = 0i64;
  v249 = 0i64;
  v250 = 0i64;
  v251 = 0;
  v252 = 0;
  UFG::qString::~qString(&result);
  v236 = *(_QWORD *)&v13->mGBufferWidth;
  LOBYTE(v239) = 0;
  v241 = 2097923;
  v245 = v13->mGBufferTarget->mDepthTexture;
  v27 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v235);
  v13->mDynamicRangeTarget = v27;
  v28 = v27->mTargetTexture[0];
  v29 = Illusion::Texture::GetSamplerAddressFlags(v27->mTargetTexture[0]);
  Illusion::Texture::SetSamplerState(v28, 1u, v29 | 3);
  v30 = UFG::qString::FormatEx(&result, "LightBuffer%s", v12);
  UFG::qString::qString(&v145, v30->mData);
  v150 = 1i64;
  v146 = 0i64;
  v147 = 1;
  v148 = 1;
  v149 = -1;
  v151 = 0;
  v152 = 1;
  _mm_store_si128((__m128i *)&v153, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v154, (__m128i)0i64);
  v155 = 0i64;
  v156 = 0i64;
  v157 = 0i64;
  v158 = 0i64;
  v159 = 0i64;
  v160 = 0i64;
  v161 = 0;
  v162 = 0;
  UFG::qString::~qString(&result);
  v146 = *(_QWORD *)&v13->mGBufferWidth;
  LOBYTE(v149) = 15;
  BYTE1(v149) = bLightMRT != 0 ? 0xF : 0;
  LODWORD(v150) = (bLightMRT != 0) + 1;
  v151 = 2097921;
  v155 = v13->mGBufferTarget->mDepthTexture;
  v31 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v145);
  v13->mLightBufferTarget = v31;
  v32 = v31->mTargetTexture[0];
  v33 = Illusion::Texture::GetSamplerAddressFlags(v31->mTargetTexture[0]);
  Illusion::Texture::SetSamplerAddressFlags(v32, v33 | 3);
  if ( bLightMRT )
  {
    v34 = v13->mLightBufferTarget->mTargetTexture[1];
    v35 = Illusion::Texture::GetSamplerAddressFlags(v34);
    Illusion::Texture::SetSamplerState(v34, 2u, v35 | 3);
  }
  v36 = UFG::qString::FormatEx(&result, "HDRBloom%s", v12);
  UFG::qString::qString(&v649, v36->mData);
  v654 = 1i64;
  v650 = 0i64;
  v651 = 1;
  v652 = 1;
  v653 = -1;
  v655 = 0;
  v656 = 1;
  _mm_store_si128((__m128i *)&v657, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v658, (__m128i)0i64);
  v659 = 0i64;
  v660 = 0i64;
  v661 = 0i64;
  v662 = 0i64;
  v663 = 0i64;
  v664 = 0i64;
  v665 = 0;
  v666 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v650) = v13->mGBufferWidth >> 2;
  HIDWORD(v650) = v13->mGBufferHeight >> 2;
  LOBYTE(v653) = 0;
  v13->mHDRBloomTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v649);
  v37 = v13->mGBufferWidth >> 1;
  v38 = v13->mGBufferHeight >> 1;
  v39 = UFG::qString::FormatEx(&result, "HalfsizeLinearDepthTarget%s", v12);
  UFG::qString::qString(&v379, v39->mData);
  v384 = 1i64;
  v380 = 0i64;
  v381 = 1;
  v382 = 1;
  v383 = -1;
  v385 = 0;
  v386 = 1;
  _mm_store_si128((__m128i *)&v387, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v388, (__m128i)0i64);
  v389 = 0i64;
  v390 = 0i64;
  v391 = 0i64;
  v392 = 0i64;
  v393 = 0i64;
  v394 = 0i64;
  v395 = 0;
  v396 = 0;
  UFG::qString::~qString(&result);
  v380 = __PAIR__(v38, v37);
  LOBYTE(v383) = 14;
  v385 = 65539;
  v13->mHalfSizeLinearDepthTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v379);
  v40 = UFG::qString::FormatEx(&result, "Halfsize%s", v12);
  UFG::qString::qString(&v325, v40->mData);
  v330 = 1i64;
  v326 = 0i64;
  v327 = 1;
  v328 = 1;
  v329 = -1;
  v331 = 0;
  v332 = 1;
  _mm_store_si128((__m128i *)&v333, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v334, (__m128i)0i64);
  v335 = 0i64;
  v336 = 0i64;
  v337 = 0i64;
  v338 = 0i64;
  v339 = 0i64;
  v340 = 0i64;
  v341 = 0;
  v342 = 0;
  UFG::qString::~qString(&result);
  v326 = __PAIR__(v38, v37);
  LOBYTE(v329) = 0;
  v331 = 3;
  v335 = v13->mHalfSizeLinearDepthTarget->mDepthTexture;
  v13->mHalfSizeTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v325);
  Illusion::Texture::SetSamplerFilter(v13->mHalfSizeLinearDepthTarget->mTargetTexture[0], 2u);
  Illusion::Texture::SetSamplerFilter(v13->mHalfSizeLinearDepthTarget->mDepthTexture, 2u);
  v41 = v13->mGBufferWidth >> 2;
  v42 = v13->mGBufferHeight >> 2;
  v43 = UFG::qString::FormatEx(&result, "QuarterSizeLinearDepthTarget%s", v12);
  UFG::qString::qString(&v433, v43->mData);
  v438 = 1i64;
  v434 = 0i64;
  v435 = 1;
  v436 = 1;
  v437 = -1;
  v439 = 0;
  v440 = 1;
  _mm_store_si128((__m128i *)&v441, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v442, (__m128i)0i64);
  v443 = 0i64;
  v444 = 0i64;
  v445 = 0i64;
  v446 = 0i64;
  v447 = 0i64;
  v448 = 0i64;
  v449 = 0;
  v450 = 0;
  UFG::qString::~qString(&result);
  v434 = __PAIR__(v42, v41);
  LOBYTE(v437) = 14;
  v439 = 65539;
  v44 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v433);
  v13->mQuarterSizeLinearDepthTarget = v44;
  Illusion::Texture::SetSamplerFilter(v44->mTargetTexture[0], 2u);
  Illusion::Texture::SetSamplerFilter(v13->mQuarterSizeLinearDepthTarget->mDepthTexture, 2u);
  if ( reflection_width && reflection_height )
  {
    v45 = UFG::qString::FormatEx(&result, "ReflectionMips%s", v12);
    Illusion::CreateTargetParams::CreateTargetParams((Illusion::CreateTargetParams *)&v127, v45->mData, 0);
    UFG::qString::~qString(&result);
    v128 = __PAIR__(reflection_height, reflection_width);
    LOBYTE(v131) = 0;
    v133 = 0x20000;
    v134 = 6;
    v13->mReflectionMipTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
    v46 = UFG::qString::FormatEx(&result, "Reflection%s", v12);
    Illusion::CreateTargetParams::CreateTargetParams(&params, v46->mData, 0);
    UFG::qString::~qString(&result);
    params.width = reflection_width;
    params.height = reflection_height;
    params.mrt_formats[0] = 0;
    params.target_flags = 1;
    v47 = Illusion::CreateTarget(&params);
    v13->mReflectionTarget = v47;
    Illusion::Texture::SetSamplerAddressFlags(v47->mTargetTexture[0], 0xCu);
    Illusion::Texture::SetSamplerAddressFlags(v13->mReflectionMipTarget->mTargetTexture[0], 0xCu);
    UFG::qString::~qString(&params.name);
    UFG::qString::~qString(&v127);
  }
  else
  {
    v13->mReflectionMipTarget = 0i64;
    v13->mReflectionTarget = 0i64;
  }
  if ( envmap_size )
  {
    v48 = UFG::qString::FormatEx(&result, "SphericalEnvMap%s", v12);
    UFG::qString::qString(&v127, v48->mData);
    v132 = 1i64;
    v128 = 0i64;
    v129 = 1;
    v130 = 1;
    v131 = -1;
    v133 = 0;
    v134 = 1;
    _mm_store_si128((__m128i *)&v135, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v136, (__m128i)0i64);
    v137 = 0i64;
    v138 = 0i64;
    v139 = 0i64;
    v140 = 0i64;
    v141 = 0i64;
    v142 = 0i64;
    v143 = 0;
    v144 = 0;
    UFG::qString::~qString(&result);
    v128 = 2748779070720i64;
    LOBYTE(v131) = 0;
    v133 = 0x20000;
    v134 = 7;
    v49 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
    v13->mSphericalEnvMapTarget = v49;
    v50 = Illusion::Texture::GetSamplerAddressFlags(v49->mTargetTexture[0]);
    Illusion::Texture::SetSamplerAddressFlags(v13->mSphericalEnvMapTarget->mTargetTexture[0], v50 & 0xFFFFFFFE | 2);
    UFG::qString::~qString(&v127);
  }
  else
  {
    v13->mSphericalEnvMapTarget = 0i64;
  }
  v51 = UFG::qString::FormatEx(&result, "FullSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v289, v51->mData);
  v294 = 1i64;
  v290 = 0i64;
  v291 = 1;
  v292 = 1;
  v293 = -1;
  v295 = 0;
  v296 = 1;
  _mm_store_si128((__m128i *)&v297, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v298, (__m128i)0i64);
  v299 = 0i64;
  v300 = 0i64;
  v301 = 0i64;
  v302 = 0i64;
  v303 = 0i64;
  v304 = 0i64;
  v305 = 0;
  v306 = 0;
  UFG::qString::~qString(&result);
  v290 = *(_QWORD *)&v13->mGBufferWidth;
  LOBYTE(v293) = 0;
  v295 = 2097921;
  v299 = v13->mGBufferTarget->mDepthTexture;
  v52 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v289);
  v13->mFullSizeScratchTargetA = v52;
  Illusion::Texture::SetSamplerFilter(v52->mTargetTexture[0], 1u);
  v53 = 0;
  if ( outSettings.mFeatureLevel == 2 )
    v53 = 0x80000;
  v54 = UFG::qString::FormatEx(&result, "HalfSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v667, v54->mData);
  v672 = 1i64;
  v668 = 0i64;
  v669 = 1;
  v670 = 1;
  v671 = -1;
  v673 = 0;
  v674 = 1;
  _mm_store_si128((__m128i *)&v675, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v676, (__m128i)0i64);
  v677 = 0i64;
  v678 = 0i64;
  v679 = 0i64;
  v680 = 0i64;
  v681 = 0i64;
  v682 = 0i64;
  v683 = 0;
  v684 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v668) = v13->mGBufferWidth >> 1;
  HIDWORD(v668) = v13->mGBufferHeight >> 1;
  LOBYTE(v671) = 0;
  v13->mHalfSizeScratchTargetA = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v667);
  v55 = UFG::qString::FormatEx(&result, "HalfSizeScratchTargetB%s", v12);
  UFG::qString::qString(&v397, v55->mData);
  v402 = 1i64;
  v398 = 0i64;
  v399 = 1;
  v400 = 1;
  v401 = -1;
  v403 = 0;
  v404 = 1;
  _mm_store_si128((__m128i *)&v405, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v406, (__m128i)0i64);
  v407 = 0i64;
  v408 = 0i64;
  v409 = 0i64;
  v410 = 0i64;
  v411 = 0i64;
  v412 = 0i64;
  v413 = 0;
  v414 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v398) = v13->mGBufferWidth >> 1;
  HIDWORD(v398) = v13->mGBufferHeight >> 1;
  LOBYTE(v401) = 0;
  v403 = v53;
  v13->mHalfSizeScratchTargetB = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v397);
  v56 = UFG::qString::FormatEx(&result, "HalfSizeScratchTargetC%s", v12);
  UFG::qString::qString(&v343, v56->mData);
  v348 = 1i64;
  v344 = 0i64;
  v345 = 1;
  v346 = 1;
  v347 = -1;
  v349 = 0;
  v350 = 1;
  _mm_store_si128((__m128i *)&v351, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v352, (__m128i)0i64);
  v353 = 0i64;
  v354 = 0i64;
  v355 = 0i64;
  v356 = 0i64;
  v357 = 0i64;
  v358 = 0i64;
  v359 = 0;
  v360 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v344) = v13->mGBufferWidth >> 1;
  HIDWORD(v344) = v13->mGBufferHeight >> 1;
  LOBYTE(v347) = 0;
  v349 = v53;
  v13->mHalfSizeScratchTargetC = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v343);
  v57 = UFG::qString::FormatEx(&result, "QuarterSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v361, v57->mData);
  v366 = 1i64;
  v362 = 0i64;
  v363 = 1;
  v364 = 1;
  v365 = -1;
  v367 = 0;
  v368 = 1;
  _mm_store_si128((__m128i *)&v369, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v370, (__m128i)0i64);
  v371 = 0i64;
  v372 = 0i64;
  v373 = 0i64;
  v374 = 0i64;
  v375 = 0i64;
  v376 = 0i64;
  v377 = 0;
  v378 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v362) = v13->mGBufferWidth >> 2;
  HIDWORD(v362) = v13->mGBufferHeight >> 2;
  LOBYTE(v365) = 0;
  v367 = v53;
  v13->mQuarterSizeScratchTargetA = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v361);
  v58 = UFG::qString::FormatEx(&result, "QuarterSizeScratchTargetB%s", v12);
  UFG::qString::qString(&v415, v58->mData);
  v420 = 1i64;
  v416 = 0i64;
  v417 = 1;
  v418 = 1;
  v419 = -1;
  v421 = 0;
  v422 = 1;
  _mm_store_si128((__m128i *)&v423, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v424, (__m128i)0i64);
  v425 = 0i64;
  v426 = 0i64;
  v427 = 0i64;
  v428 = 0i64;
  v429 = 0i64;
  v430 = 0i64;
  v431 = 0;
  v432 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v416) = v13->mGBufferWidth >> 2;
  HIDWORD(v416) = v13->mGBufferHeight >> 2;
  LOBYTE(v419) = 0;
  v421 = v53;
  v13->mQuarterSizeScratchTargetB = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v415);
  v59 = UFG::qString::FormatEx(&result, "EighthSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v595, v59->mData);
  v600 = 1i64;
  v596 = 0i64;
  v597 = 1;
  v598 = 1;
  v599 = -1;
  v601 = 0;
  v602 = 1;
  _mm_store_si128((__m128i *)&v603, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v604, (__m128i)0i64);
  v605 = 0i64;
  v606 = 0i64;
  v607 = 0i64;
  v608 = 0i64;
  v609 = 0i64;
  v610 = 0i64;
  v611 = 0;
  v612 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v596) = v13->mGBufferWidth >> 3;
  HIDWORD(v596) = v13->mGBufferHeight >> 3;
  LOBYTE(v599) = 0;
  v13->mEighthSizeScratchTargetA = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v595);
  v60 = UFG::qString::FormatEx(&result, "EighthSizeScratchTargetB%s", v12);
  UFG::qString::qString(&v559, v60->mData);
  v564 = 1i64;
  v560 = 0i64;
  v561 = 1;
  v562 = 1;
  v563 = -1;
  v565 = 0;
  v566 = 1;
  _mm_store_si128((__m128i *)&v567, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v568, (__m128i)0i64);
  v569 = 0i64;
  v570 = 0i64;
  v571 = 0i64;
  v572 = 0i64;
  v573 = 0i64;
  v574 = 0i64;
  v575 = 0;
  v576 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v560) = v13->mGBufferWidth >> 3;
  HIDWORD(v560) = v13->mGBufferHeight >> 3;
  LOBYTE(v563) = 0;
  v13->mEighthSizeScratchTargetB = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v559);
  v61 = UFG::qString::FormatEx(&result, "mSixteenthSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v523, v61->mData);
  v528 = 1i64;
  v524 = 0i64;
  v525 = 1;
  v526 = 1;
  v527 = -1;
  v529 = 0;
  v530 = 1;
  _mm_store_si128((__m128i *)&v531, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v532, (__m128i)0i64);
  v533 = 0i64;
  v534 = 0i64;
  v535 = 0i64;
  v536 = 0i64;
  v537 = 0i64;
  v538 = 0i64;
  v539 = 0;
  v540 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v524) = v13->mGBufferWidth >> 4;
  HIDWORD(v524) = v13->mGBufferHeight >> 4;
  LOBYTE(v527) = 0;
  v13->mSixteenthSizeScratchTargetA = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v523);
  v62 = UFG::qString::FormatEx(&result, "mSixteenthSizeScratchTargetB%s", v12);
  UFG::qString::qString(&v487, v62->mData);
  v492 = 1i64;
  v488 = 0i64;
  v489 = 1;
  v490 = 1;
  v491 = -1;
  v493 = 0;
  v494 = 1;
  _mm_store_si128((__m128i *)&v495, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v496, (__m128i)0i64);
  v497 = 0i64;
  v498 = 0i64;
  v499 = 0i64;
  v500 = 0i64;
  v501 = 0i64;
  v502 = 0i64;
  v503 = 0;
  v504 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v488) = v13->mGBufferWidth >> 4;
  HIDWORD(v488) = v13->mGBufferHeight >> 4;
  LOBYTE(v491) = 0;
  v13->mSixteenthSizeScratchTargetB = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v487);
  v63 = UFG::qString::FormatEx(&result, "mThrityTwoSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v469, v63->mData);
  v474 = 1i64;
  v470 = 0i64;
  v471 = 1;
  v472 = 1;
  v473 = -1;
  v475 = 0;
  v476 = 1;
  _mm_store_si128((__m128i *)&v477, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v478, (__m128i)0i64);
  v479 = 0i64;
  v480 = 0i64;
  v481 = 0i64;
  v482 = 0i64;
  v483 = 0i64;
  v484 = 0i64;
  v485 = 0;
  v486 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v470) = v13->mGBufferWidth >> 5;
  HIDWORD(v470) = v13->mGBufferHeight >> 5;
  LOBYTE(v473) = 0;
  v13->mThrityTwoSizeScratchTargetA = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v469);
  v64 = UFG::qString::FormatEx(&result, "mThrityTwoSizeScratchTargetB%s", v12);
  UFG::qString::qString(&v631, v64->mData);
  v636 = 1i64;
  v632 = 0i64;
  v633 = 1;
  v634 = 1;
  v635 = -1;
  v637 = 0;
  v638 = 1;
  _mm_store_si128((__m128i *)&v639, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v640, (__m128i)0i64);
  v641 = 0i64;
  v642 = 0i64;
  v643 = 0i64;
  v644 = 0i64;
  v645 = 0i64;
  v646 = 0i64;
  v647 = 0;
  v648 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v632) = v13->mGBufferWidth >> 5;
  HIDWORD(v632) = v13->mGBufferHeight >> 5;
  LOBYTE(v635) = 0;
  v13->mThrityTwoSizeScratchTargetB = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v631);
  v65 = UFG::qString::FormatEx(&result, "mSixtyFourSizeScratchTargetA%s", v12);
  UFG::qString::qString(&v577, v65->mData);
  v582 = 1i64;
  v578 = 0i64;
  v579 = 1;
  v580 = 1;
  v581 = -1;
  v583 = 0;
  v584 = 1;
  _mm_store_si128((__m128i *)&v585, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v586, (__m128i)0i64);
  v587 = 0i64;
  v588 = 0i64;
  v589 = 0i64;
  v590 = 0i64;
  v591 = 0i64;
  v592 = 0i64;
  v593 = 0;
  v594 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v578) = v13->mGBufferWidth >> 6;
  HIDWORD(v578) = v13->mGBufferHeight >> 6;
  LOBYTE(v581) = 0;
  v13->mSixtyFourSizeScratchTargetA = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v577);
  v66 = UFG::qString::FormatEx(&result, "mSixtyFourSizeScratchTargetB%s", v12);
  UFG::qString::qString(&v451, v66->mData);
  v456 = 1i64;
  v452 = 0i64;
  v453 = 1;
  v454 = 1;
  v455 = -1;
  v457 = 0;
  v458 = 1;
  _mm_store_si128((__m128i *)&v459, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v460, (__m128i)0i64);
  v461 = 0i64;
  v462 = 0i64;
  v463 = 0i64;
  v464 = 0i64;
  v465 = 0i64;
  v466 = 0i64;
  v467 = 0;
  v468 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v452) = v13->mGBufferWidth >> 6;
  HIDWORD(v452) = v13->mGBufferHeight >> 6;
  LOBYTE(v455) = 0;
  v13->mSixtyFourSizeScratchTargetB = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v451);
  v67 = v13->mHalfSizeScratchTargetC->mTargetTexture[0];
  v68 = UFG::qString::FormatEx(&result, "AmbientOcclusionTarget%s", v12);
  UFG::qString::qString(&v541, v68->mData);
  v546 = 1i64;
  v542 = 0i64;
  v543 = 1;
  v544 = 1;
  v545 = -1;
  v547 = 0;
  v548 = 1;
  _mm_store_si128((__m128i *)&v549, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v550, (__m128i)0i64);
  v551 = 0i64;
  v552 = 0i64;
  v553 = 0i64;
  v554 = 0i64;
  v555 = 0i64;
  v556 = 0i64;
  v557 = 0;
  v558 = 0;
  UFG::qString::~qString(&result);
  *(_QWORD *)&v549 = v67;
  v551 = v13->mHalfSizeLinearDepthTarget->mDepthTexture;
  v547 = 771;
  v13->mAmbientOcclusionAliasTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v541);
  v69 = v13->mHalfSizeScratchTargetB->mTargetTexture[0];
  v70 = UFG::qString::FormatEx(&result, "SkyOcclusionTarget%s", v12);
  UFG::qString::qString(&v613, v70->mData);
  v618 = 1i64;
  v614 = 0i64;
  v615 = 1;
  v616 = 1;
  v617 = -1;
  v619 = 0;
  v620 = 1;
  _mm_store_si128((__m128i *)&v621, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v622, (__m128i)0i64);
  v623 = 0i64;
  v624 = 0i64;
  v625 = 0i64;
  v626 = 0i64;
  v627 = 0i64;
  v628 = 0i64;
  v629 = 0;
  v630 = 0;
  UFG::qString::~qString(&result);
  *(_QWORD *)&v621 = v69;
  v623 = v13->mHalfSizeLinearDepthTarget->mDepthTexture;
  v619 = 771;
  v13->mSkyOcclusionAliasTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v613);
  v71 = UFG::qString::FormatEx(&result, "QuarterSizeVolumetricTargetA%s", v12);
  UFG::qString::qString(&v253, v71->mData);
  v258 = 1i64;
  v254 = 0i64;
  v255 = 1;
  v256 = 1;
  v257 = -1;
  v259 = 0;
  v260 = 1;
  _mm_store_si128((__m128i *)&v261, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v262, (__m128i)0i64);
  v263 = 0i64;
  v264 = 0i64;
  v265 = 0i64;
  v266 = 0i64;
  v267 = 0i64;
  v268 = 0i64;
  v269 = 0;
  v270 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v254) = v13->mGBufferWidth >> 2;
  HIDWORD(v254) = v13->mGBufferHeight >> 2;
  LOBYTE(v257) = 0;
  v259 = 1;
  v263 = v13->mQuarterSizeLinearDepthTarget->mDepthTexture;
  v13->mQuarterSizeVolumetricTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v253);
  v72 = UFG::qString::FormatEx(&result, "HalfSizeVolumetricTargetA%s", v12);
  UFG::qString::qString(&v217, v72->mData);
  v222 = 1i64;
  v218 = 0i64;
  v219 = 1;
  v220 = 1;
  v221 = -1;
  v223 = 0;
  v224 = 1;
  _mm_store_si128((__m128i *)&v225, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v226, (__m128i)0i64);
  v227 = 0i64;
  v228 = 0i64;
  v229 = 0i64;
  v230 = 0i64;
  v231 = 0i64;
  v232 = 0i64;
  v233 = 0;
  v234 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v218) = v13->mGBufferWidth >> 1;
  HIDWORD(v218) = v13->mGBufferHeight >> 1;
  LOBYTE(v221) = 0;
  v223 = 1;
  v227 = v13->mHalfSizeLinearDepthTarget->mDepthTexture;
  v13->mHalfSizeVolumetricTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v217);
  v73 = Render::GetBackBufferTarget();
  LODWORD(v69) = v73->mWidth;
  v74 = v73->mHeight;
  v75 = UFG::qString::FormatEx(&result, "DepthOfField_NearBlur%s", v12);
  UFG::qString::qString(&v505, v75->mData);
  v510 = 1i64;
  v506 = 0i64;
  v507 = 1;
  v508 = 1;
  v509 = -1;
  v511 = 0;
  v512 = 1;
  _mm_store_si128((__m128i *)&v513, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v514, (__m128i)0i64);
  v515 = 0i64;
  v516 = 0i64;
  v517 = 0i64;
  v518 = 0i64;
  v519 = 0i64;
  v520 = 0i64;
  v521 = 0;
  v522 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v506) = (unsigned int)v69 >> 2;
  HIDWORD(v506) = v74 >> 2;
  LOBYTE(v509) = 0;
  v13->mNearBlur = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v505);
  if ( !v13->mCascadeShadowTarget )
  {
    v76 = UFG::qString::FormatEx(&result, "CascadeTarget%s", v12);
    UFG::qString::qString(&v127, v76->mData);
    v132 = 1i64;
    v128 = 0i64;
    v129 = 1;
    v130 = 1;
    v131 = -1;
    v133 = 0;
    v134 = 1;
    _mm_store_si128((__m128i *)&v135, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v136, (__m128i)0i64);
    v137 = 0i64;
    v138 = 0i64;
    v139 = 0i64;
    v140 = 0i64;
    v141 = 0i64;
    v142 = 0i64;
    v143 = 0;
    v144 = 0;
    UFG::qString::~qString(&result);
    LODWORD(v128) = v13->mCascadeShadowSize;
    HIDWORD(v128) = v128;
    LOBYTE(v131) = 0;
    LODWORD(v132) = 0;
    v133 = 2097795;
    v13->mCascadeShadowTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
    UFG::qString::~qString(&v127);
  }
  v13->mCascadeShadowTexture = v13->mCascadeShadowTarget->mDepthTexture;
  v77 = UFG::qString::FormatEx(&result, "HalfSizeShadowTarget%s", v12);
  UFG::qString::qString(&v181, v77->mData);
  v186 = 1i64;
  v182 = 0i64;
  v183 = 1;
  v184 = 1;
  v185 = -1;
  v187 = 0;
  v188 = 1;
  _mm_store_si128((__m128i *)&v189, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v190, (__m128i)0i64);
  v191 = 0i64;
  v192 = 0i64;
  v193 = 0i64;
  v194 = 0i64;
  v195 = 0i64;
  v196 = 0i64;
  v197 = 0;
  v198 = 0;
  UFG::qString::~qString(&result);
  v78 = v13->mCascadeShadowSize >> 1;
  LODWORD(v182) = v78;
  HIDWORD(v182) = v78;
  LOBYTE(v185) = 0;
  LODWORD(v186) = 0;
  v187 = 3;
  v79 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v181);
  v13->mHalfSizeShadowTarget = v79;
  if ( v79 )
  {
    v80 = v79->mDepthTexture;
    v81 = Illusion::Texture::GetSamplerAddressFlags(v79->mDepthTexture);
    Illusion::Texture::SetSamplerState(v80, 2u, v81 | 3);
  }
  v82 = UFG::qString::FormatEx(&result, "QuarterSizeShadowTarget%s", v12);
  UFG::qString::qString(&v307, v82->mData);
  v312 = 1i64;
  v308 = 0i64;
  v309 = 1;
  v310 = 1;
  v311 = -1;
  v313 = 0;
  v314 = 1;
  _mm_store_si128((__m128i *)&v315, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v316, (__m128i)0i64);
  v317 = 0i64;
  v318 = 0i64;
  v319 = 0i64;
  v320 = 0i64;
  v321 = 0i64;
  v322 = 0i64;
  v323 = 0;
  v324 = 0;
  UFG::qString::~qString(&result);
  v83 = v13->mCascadeShadowSize >> 2;
  LODWORD(v308) = v83;
  HIDWORD(v308) = v83;
  LOBYTE(v311) = 0;
  LODWORD(v312) = 0;
  v313 = 3;
  v84 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v307);
  v13->mQuarterSizeShadowTarget = v84;
  if ( v84 )
  {
    v85 = v84->mDepthTexture;
    v86 = Illusion::Texture::GetSamplerAddressFlags(v84->mDepthTexture);
    Illusion::Texture::SetSamplerState(v85, 2u, v86 | 3);
  }
  v87 = UFG::qString::FormatEx(&result, "SingleShadowTarget%s", v12);
  UFG::qString::qString(&v163, v87->mData);
  v168 = 1i64;
  v164 = 0i64;
  v165 = 1;
  v166 = 1;
  v167 = -1;
  v169 = 0;
  v170 = 1;
  _mm_store_si128((__m128i *)&v171, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v172, (__m128i)0i64);
  v173 = 0i64;
  v174 = 0i64;
  v175 = 0i64;
  v176 = 0i64;
  v177 = 0i64;
  v178 = 0i64;
  v179 = 0;
  v180 = 0;
  UFG::qString::~qString(&result);
  v88 = v13->mSpotShadowSize;
  LODWORD(v164) = v88;
  HIDWORD(v164) = v88;
  LOBYTE(v167) = 0;
  LODWORD(v168) = 0;
  v169 = 707;
  v89 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v163);
  v13->mSingleShadowTarget = v89;
  v90 = v89->mTargetTexture[0];
  if ( v90 )
  {
    v91 = Illusion::Texture::GetSamplerAddressFlags(v89->mTargetTexture[0]);
    Illusion::Texture::SetSamplerState(v90, 2u, v91 | 3);
  }
  v13->mSingleShadowTarget->mDepthTexture->mFilter = 1;
  v13->mSingleShadowSubtexture = v13->mSingleShadowTarget->mDepthTexture;
  v92 = UFG::qString::FormatEx(&result, "HalfSizeSingleShadowTarget%s", v12);
  UFG::qString::qString(&v271, v92->mData);
  v276 = 1i64;
  v272 = 0i64;
  v273 = 1;
  v274 = 1;
  v275 = -1;
  v277 = 0;
  v278 = 1;
  _mm_store_si128((__m128i *)&v279, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v280, (__m128i)0i64);
  v281 = 0i64;
  v282 = 0i64;
  v283 = 0i64;
  v284 = 0i64;
  v285 = 0i64;
  v286 = 0i64;
  v287 = 0;
  v288 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v272) = v13->mSpotShadowSize >> 1;
  HIDWORD(v272) = v272;
  LOBYTE(v275) = 0;
  LODWORD(v276) = 0;
  v277 = 1049091;
  v93 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v271);
  v13->mHalfSizeSingleShadowTarget = v93;
  v94 = v93->mDepthTexture;
  v95 = Illusion::Texture::GetSamplerAddressFlags(v93->mDepthTexture);
  Illusion::Texture::SetSamplerState(v94, 2u, v95 | 3);
  if ( !v13->mCharacterShadowTarget )
  {
    v96 = UFG::qString::FormatEx(&result, "CharacterShadowTarget%s", v12);
    UFG::qString::qString(&v127, v96->mData);
    v132 = 1i64;
    v128 = 0i64;
    v129 = 1;
    v130 = 1;
    v131 = -1;
    v133 = 0;
    v134 = 1;
    _mm_store_si128((__m128i *)&v135, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v136, (__m128i)0i64);
    v137 = 0i64;
    v138 = 0i64;
    v139 = 0i64;
    v140 = 0i64;
    v141 = 0i64;
    v142 = 0i64;
    v143 = 0;
    v144 = 0;
    UFG::qString::~qString(&result);
    LODWORD(v128) = v13->mCharacterShadowSize;
    HIDWORD(v128) = v128;
    LOBYTE(v131) = 0;
    LODWORD(v132) = 0;
    v133 = 131;
    v13->mCharacterShadowTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
    UFG::qString::~qString(&v127);
  }
  v13->mCharacterShadowTexture = v13->mCharacterShadowTarget->mDepthTexture;
  v97 = UFG::qString::FormatEx(&result, "HeightmapTarget%s", v12);
  UFG::qString::qString(&v199, v97->mData);
  v204 = 1i64;
  v200 = 0i64;
  v201 = 1;
  v202 = 1;
  v203 = -1;
  v205 = 0;
  v206 = 1;
  _mm_store_si128((__m128i *)&v207, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v208, (__m128i)0i64);
  v209 = 0i64;
  v210 = 0i64;
  v211 = 0i64;
  v212 = 0i64;
  v213 = 0i64;
  v214 = 0i64;
  v215 = 0;
  v216 = 0;
  UFG::qString::~qString(&result);
  LODWORD(v200) = v13->mCascadeShadowSize >> 2;
  HIDWORD(v200) = v200;
  LOBYTE(v203) = 0;
  LODWORD(v204) = 0;
  v205 = 3;
  v98 = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v199);
  v13->mHeightmapTarget = v98;
  v99 = v98->mDepthTexture;
  v100 = Illusion::Texture::GetSamplerAddressFlags(v98->mDepthTexture);
  Illusion::Texture::SetSamplerState(v99, 2u, v100 | 3);
  v101 = UFG::qString::FormatEx(&result, "HeightmapShadowAlias%s", v12);
  v13->mHeightmapShadowTextureAlias = Illusion::CreateTextureAlias(
                                        v101->mData,
                                        v13->mHeightmapTarget->mDepthTexture,
                                        FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v102 = Illusion::Texture::GetSamplerAddressFlags(v13->mHeightmapShadowTextureAlias);
  Illusion::Texture::SetSamplerState(v13->mHeightmapShadowTextureAlias, 1u, v102 | 3);
  v103 = UFG::qString::FormatEx(&result, "CascadeTargetAlias%s", v12);
  v13->mCascadeShadowTextureAliasDepth = Illusion::CreateTextureAlias(
                                           v103->mData,
                                           v13->mCascadeShadowTexture,
                                           FORMAT_D24S8);
  UFG::qString::~qString(&result);
  v104 = Illusion::Texture::GetSamplerAddressFlags(v13->mCascadeShadowTextureAliasDepth);
  Illusion::Texture::SetSamplerState(v13->mCascadeShadowTextureAliasDepth, 2u, v104 | 3);
  v105 = UFG::qString::FormatEx(&result, "HalfSizeShadowAlias%s", v12);
  v13->mHalfSizeShadowAliasTexture = Illusion::CreateTextureAlias(
                                       v105->mData,
                                       v13->mHalfSizeShadowTarget->mDepthTexture,
                                       FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v106 = Illusion::Texture::GetSamplerAddressFlags(v13->mHalfSizeShadowAliasTexture);
  Illusion::Texture::SetSamplerState(v13->mHalfSizeShadowAliasTexture, 1u, v106 | 3);
  v107 = UFG::qString::FormatEx(&result, "QuarterSizeShadowAlias%s", v12);
  v13->mQuarterSizeShadowAliasTexture = Illusion::CreateTextureAlias(
                                          v107->mData,
                                          v13->mQuarterSizeShadowTarget->mDepthTexture,
                                          FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v108 = Illusion::Texture::GetSamplerAddressFlags(v13->mQuarterSizeShadowAliasTexture);
  Illusion::Texture::SetSamplerState(v13->mQuarterSizeShadowAliasTexture, 1u, v108 | 3);
  v109 = UFG::qString::FormatEx(&result, "CharacterShadowTargetAlias%s", v12);
  v13->mCharacterShadowTextureAliasDepth = Illusion::CreateTextureAlias(
                                             v109->mData,
                                             v13->mCharacterShadowTexture,
                                             FORMAT_D24S8);
  UFG::qString::~qString(&result);
  v110 = Illusion::Texture::GetSamplerAddressFlags(v13->mCharacterShadowTextureAliasDepth);
  Illusion::Texture::SetSamplerState(v13->mCharacterShadowTextureAliasDepth, 2u, v110 | 3);
  v111 = UFG::qString::FormatEx(&result, "SingleShadowTargetAlias%s", v12);
  v13->mSingleShadowTextureAliasDepth = Illusion::CreateTextureAlias(
                                          v111->mData,
                                          v13->mSingleShadowSubtexture,
                                          FORMAT_D24S8);
  UFG::qString::~qString(&result);
  v112 = Illusion::Texture::GetSamplerAddressFlags(v13->mSingleShadowTextureAliasDepth);
  Illusion::Texture::SetSamplerState(v13->mSingleShadowTextureAliasDepth, 2u, v112 | 3);
  v113 = UFG::qString::FormatEx(&result, "HalfSizeSingleShadowAliasTexture%s", v12);
  v13->mHalfSizeSingleShadowAliasTexture = Illusion::CreateTextureAlias(
                                             v113->mData,
                                             v13->mHalfSizeSingleShadowTarget->mDepthTexture,
                                             FORMAT_SHADOW);
  UFG::qString::~qString(&result);
  v114 = Illusion::Texture::GetSamplerAddressFlags(v13->mHalfSizeSingleShadowAliasTexture);
  Illusion::Texture::SetSamplerState(v13->mHalfSizeSingleShadowAliasTexture, 1u, v114 | 3);
  if ( aaQuality == AA_QUALITY_NORMAL || v13->mAAResultTarget )
  {
    v13->mAAResultTarget = 0i64;
  }
  else
  {
    v115 = UFG::qString::FormatEx(&result, "AAResult%s", v12);
    Illusion::CreateTargetParams::CreateTargetParams(&params, v115->mData, 0);
    UFG::qString::~qString(&result);
    params.width = v707;
    params.height = v708;
    params.mrt_formats[0] = v13->mGBufferTarget->mTargetTexture[0]->mFormat;
    params.target_flags = 1;
    v13->mAAResultTarget = Illusion::CreateTarget(&params);
    UFG::qString::~qString(&params.name);
  }
  if ( bLightMRT )
  {
    v116 = UFG::qString::FormatEx(&result, "DirectionalOcclusion%s", v12);
    UFG::qString::qString(&v127, v116->mData);
    v132 = 1i64;
    v128 = 0i64;
    v129 = 1;
    v130 = 1;
    v131 = -1;
    v133 = 0;
    v134 = 1;
    _mm_store_si128((__m128i *)&v135, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v136, (__m128i)0i64);
    v137 = 0i64;
    v138 = 0i64;
    v139 = 0i64;
    v140 = 0i64;
    v141 = 0i64;
    v142 = 0i64;
    v143 = 0;
    v144 = 0;
    UFG::qString::~qString(&result);
    v128 = *(_QWORD *)&v13->mGBufferWidth;
    LOBYTE(v131) = v13->mLightBufferTarget->mTargetTexture[0]->mFormat;
    v13->mDirectionalOcclusionTarget = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v127);
    v117 = UFG::qString::FormatEx(&result, "LightBuffer%s", v12);
    v13->mLightBufferMain = Illusion::CreateTextureAlias(
                              v117->mData,
                              v13->mLightBufferTarget->mTargetTexture[0],
                              FORMAT_X16FY16FZ16FW16F);
    UFG::qString::~qString(&result);
    UFG::qString::~qString(&v127);
  }
  else
  {
    v13->mLightBufferMain = 0i64;
    v13->mDirectionalOcclusionTarget = 0i64;
  }
  v118 = outSettings.mFeatureLevel;
  if ( outSettings.mFeatureLevel != 2 || outSettings.mSSAO < 1 )
  {
    v13->mQuarterSizeScratchAPointSampleTexture = 0i64;
    v13->mQuarterSizeScratchBPointSampleTexture = 0i64;
    v13->mQuarterSizeAmbientOcclusionTarget = 0i64;
    v13->mQuarterSizeAmbientOcclusionAliasUAV = 0i64;
    v13->mQuarterSizeAmbientOcclusionScratchUAV = 0i64;
  }
  else
  {
    v119 = UFG::qString::FormatEx(&result, "QuarterSizeScratchAPointSample%s", v12);
    v13->mQuarterSizeScratchAPointSampleTexture = Illusion::CreateTextureAlias(
                                                    v119->mData,
                                                    v13->mQuarterSizeScratchTargetA->mTargetTexture[0],
                                                    0);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(v13->mQuarterSizeScratchAPointSampleTexture, 2u);
    v120 = UFG::qString::FormatEx(&result, "QuarterSizeScratchBPointSample%s", v12);
    v13->mQuarterSizeScratchBPointSampleTexture = Illusion::CreateTextureAlias(
                                                    v120->mData,
                                                    v13->mQuarterSizeScratchTargetB->mTargetTexture[0],
                                                    0);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(v13->mQuarterSizeScratchBPointSampleTexture, 2u);
    v121 = v13->mQuarterSizeScratchTargetA->mTargetTexture[0];
    v122 = UFG::qString::FormatEx(&result, "QuarterAmbientOcclusionTarget%s", v12);
    Illusion::CreateTargetParams::CreateTargetParams(&params, v122->mData, 0);
    UFG::qString::~qString(&result);
    params.textures[0] = v121;
    params.depth_texture = v13->mQuarterSizeLinearDepthTarget->mDepthTexture;
    params.target_flags = 771;
    v123 = Illusion::CreateTarget(&params);
    v13->mQuarterSizeAmbientOcclusionTarget = v123;
    v13->mQuarterSizeAmbientOcclusionAliasUAV = Illusion::UnorderedAccessView::Create(v123->mTargetTexture[0]);
    v13->mQuarterSizeAmbientOcclusionScratchUAV = Illusion::UnorderedAccessView::Create(v13->mQuarterSizeScratchTargetB->mTargetTexture[0]);
    UFG::qString::~qString(&params.name);
    v118 = outSettings.mFeatureLevel;
  }
  if ( v118 == 2 )
  {
    v124 = UFG::qString::FormatEx(&result, "HalfSizeScratchCPointSample%s", v12);
    v13->mHalfSizeScratchCPointSampleTexture = Illusion::CreateTextureAlias(
                                                 v124->mData,
                                                 v13->mHalfSizeScratchTargetC->mTargetTexture[0],
                                                 0);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(v13->mHalfSizeScratchCPointSampleTexture, 2u);
    v125 = UFG::qString::FormatEx(&result, "HalfSizeScratchBPointSample%s", v12);
    v13->mHalfSizeScratchBPointSampleTexture = Illusion::CreateTextureAlias(
                                                 v125->mData,
                                                 v13->mHalfSizeScratchTargetB->mTargetTexture[0],
                                                 0);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(v13->mHalfSizeScratchBPointSampleTexture, 2u);
    v13->mAmbientOcclusionAliasUAV = Illusion::UnorderedAccessView::Create(v13->mAmbientOcclusionAliasTarget->mTargetTexture[0]);
    v13->mAmbientOcclusionScratchUAV = Illusion::UnorderedAccessView::Create(v13->mHalfSizeScratchTargetB->mTargetTexture[0]);
  }
  else
  {
    v13->mHalfSizeScratchCPointSampleTexture = 0i64;
    v13->mHalfSizeScratchBPointSampleTexture = 0i64;
    v13->mAmbientOcclusionAliasUAV = 0i64;
    v13->mAmbientOcclusionScratchUAV = 0i64;
  }
  _((AMD_HD3D *)v13->mRenderContextPlat);
  v13->mTargetsCreated = 1;
  UFG::qString::~qString(&v199);
  UFG::qString::~qString(&v271);
  UFG::qString::~qString(&v163);
  UFG::qString::~qString(&v307);
  UFG::qString::~qString(&v181);
  UFG::qString::~qString(&v505);
  UFG::qString::~qString(&v217);
  UFG::qString::~qString(&v253);
  UFG::qString::~qString(&v613);
  UFG::qString::~qString(&v541);
  UFG::qString::~qString(&v451);
  UFG::qString::~qString(&v577);
  UFG::qString::~qString(&v631);
  UFG::qString::~qString(&v469);
  UFG::qString::~qString(&v487);
  UFG::qString::~qString(&v523);
  UFG::qString::~qString(&v559);
  UFG::qString::~qString(&v595);
  UFG::qString::~qString(&v415);
  UFG::qString::~qString(&v361);
  UFG::qString::~qString(&v343);
  UFG::qString::~qString(&v397);
  UFG::qString::~qString(&v667);
  UFG::qString::~qString(&v289);
  UFG::qString::~qString(&v433);
  UFG::qString::~qString(&v325);
  UFG::qString::~qString(&v379);
  UFG::qString::~qString(&v649);
  UFG::qString::~qString(&v145);
  UFG::qString::~qString(&v235);
  UFG::qString::~qString(&v685);
}fSizeScratchBPointSampleTexture = Illusion::CreateTextureAlias(
                                                 v125->mData,
                                                 v13->mHalfSizeScratchTargetB->mTargetTexture[0],
                                                 0);
    UFG::qString::~qString(&result);
    Illusion::Texture::SetSamplerFilter(v13->mHalfSizeScratchBPointSampleTexture, 2u);
    v13->mAmbientOcclusionAliasUAV = Illusion::UnorderedAccessView::Create(v13->mAmbientOcclusionAliasTarget->mTargetTex

// File Line: 797
// RVA: 0x3FC60
void __fastcall UFG::RenderContext::CreateMaterials(UFG::RenderContext *this)
{
  Illusion::Target *v1; // rax
  UFG::RenderContext *v2; // rbp
  Illusion::Texture *v3; // r12
  Illusion::Texture *v4; // r13
  Illusion::Texture *v5; // r15
  Illusion::Texture *v6; // r14
  unsigned int v7; // eax
  Illusion::Material *v8; // rdi
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  unsigned int v12; // ebx
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  unsigned int v16; // ebx
  int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ebx
  int v20; // eax
  unsigned int v21; // ebx
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  unsigned int v29; // eax
  int v30; // ebx
  int v31; // eax
  UFG::qResourceWarehouse *v32; // rax
  __int64 v33; // rax
  _WORD *v34; // rax
  __int64 v35; // rax
  _WORD *v36; // rax
  unsigned int v37; // eax
  Illusion::Material *v38; // rdi
  int v39; // ebx
  int v40; // eax
  unsigned int v41; // ebx
  int v42; // eax
  unsigned int v43; // ebx
  unsigned int v44; // eax
  unsigned int v45; // ebx
  int v46; // eax
  int v47; // eax
  unsigned int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  UFG::qResourceWarehouse *v52; // rax
  unsigned int v53; // eax
  Illusion::Material *v54; // rdi
  int v55; // ebx
  int v56; // eax
  unsigned int v57; // ebx
  int v58; // eax
  unsigned int v59; // ebx
  unsigned int v60; // eax
  unsigned int v61; // ebx
  int v62; // eax
  int v63; // eax
  unsigned int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  UFG::qResourceWarehouse *v68; // rax
  unsigned int v69; // eax
  Illusion::Material *v70; // rdi
  int v71; // ebx
  int v72; // eax
  unsigned int v73; // ebx
  int v74; // eax
  unsigned int v75; // ebx
  unsigned int v76; // eax
  unsigned int v77; // ebx
  int v78; // eax
  int v79; // eax
  unsigned int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  UFG::qResourceWarehouse *v84; // rax
  unsigned int v85; // eax
  Illusion::Material *v86; // rdi
  int v87; // ebx
  int v88; // eax
  unsigned int v89; // ebx
  int v90; // eax
  unsigned int v91; // ebx
  unsigned int v92; // eax
  unsigned int v93; // ebx
  int v94; // eax
  int v95; // eax
  unsigned int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // eax
  UFG::qResourceWarehouse *v100; // rax
  unsigned int v101; // eax
  Illusion::Material *v102; // rdi
  int v103; // ebx
  int v104; // eax
  unsigned int v105; // ebx
  int v106; // eax
  unsigned int v107; // eax
  int v108; // eax
  unsigned int v109; // ebx
  unsigned int v110; // ebx
  unsigned int v111; // eax
  int v112; // ebx
  int v113; // eax
  unsigned int v114; // ebx
  int v115; // eax
  unsigned int v116; // ebx
  int v117; // eax
  UFG::qResourceWarehouse *v118; // rax
  unsigned int v119; // esi
  UFG::qResourceData *v120; // rbx
  UFG::qResourceWarehouse *v121; // rax
  unsigned int v122; // eax
  Illusion::Material *v123; // rdi
  int v124; // eax
  int v125; // eax
  unsigned int v126; // eax
  UFG::qResourceWarehouse *v127; // rax
  UFG::qResourceData *v128; // rbx
  UFG::qResourceWarehouse *v129; // rax
  unsigned int v130; // eax
  UFG::qResourceData *v131; // rax
  UFG::qResourceData *v132; // rbx
  UFG::qResourceWarehouse *v133; // rax
  unsigned int v134; // eax
  Illusion::Material *v135; // rdi
  int v136; // eax
  int v137; // eax
  unsigned int v138; // eax
  int v139; // eax
  unsigned int v140; // eax
  int v141; // eax
  UFG::qResourceWarehouse *v142; // rax
  unsigned int v143; // eax
  Illusion::Material *v144; // rax
  Illusion::Material *v145; // rdi
  int v146; // eax
  int v147; // eax
  unsigned int v148; // eax
  int v149; // eax
  int v150; // eax
  unsigned int v151; // eax
  int v152; // eax
  UFG::qResourceWarehouse *v153; // rax
  unsigned int v154; // eax
  Illusion::Material *v155; // rdi
  int v156; // eax
  int v157; // eax
  unsigned int v158; // eax
  int v159; // eax
  int v160; // eax
  unsigned int v161; // eax
  UFG::qResourceWarehouse *v162; // rax
  __int64 v163; // rax
  _WORD *v164; // rax
  __int64 v165; // rax
  _WORD *v166; // rax
  unsigned int v167; // eax
  Illusion::Material *v168; // rax
  Illusion::Material *v169; // rdi
  int v170; // eax
  unsigned int v171; // ebx
  int v172; // eax
  unsigned int v173; // ebx
  unsigned int v174; // eax
  unsigned int v175; // ebx
  int v176; // eax
  int v177; // eax
  unsigned int v178; // eax
  unsigned int v179; // ebx
  int v180; // eax
  unsigned int v181; // ebx
  int v182; // eax
  unsigned int v183; // ebx
  int v184; // eax
  unsigned int v185; // ebx
  int v186; // eax
  int v187; // eax
  int v188; // ebx
  unsigned int v189; // eax
  UFG::qResourceWarehouse *v190; // rax
  unsigned int v191; // eax
  Illusion::Material *v192; // rax
  Illusion::Material *v193; // rdi
  int v194; // eax
  int v195; // eax
  unsigned int v196; // ebx
  unsigned int v197; // eax
  int v198; // eax
  int v199; // eax
  unsigned int v200; // eax
  UFG::qResourceWarehouse *v201; // rax
  unsigned int v202; // eax
  Illusion::Material *v203; // rdi
  int v204; // eax
  int v205; // ebx
  int v206; // eax
  int v207; // eax
  unsigned int v208; // ebx
  unsigned int v209; // eax
  unsigned int v210; // ebx
  int v211; // eax
  int v212; // eax
  unsigned int v213; // eax
  UFG::qResourceWarehouse *v214; // rax
  unsigned int v215; // eax
  Illusion::Material *v216; // rdi
  int v217; // ebx
  int v218; // eax
  unsigned int v219; // ebx
  int v220; // eax
  unsigned int v221; // eax
  int v222; // eax
  UFG::qResourceWarehouse *v223; // rax
  __int64 v224; // rax
  _WORD *v225; // rax
  __int64 v226; // rax
  _WORD *v227; // rax
  unsigned int v228; // eax
  Illusion::Material *v229; // rdi
  int v230; // ebx
  int v231; // eax
  int v232; // eax
  unsigned int v233; // eax
  int v234; // ebx
  int v235; // eax
  unsigned int v236; // ebx
  int v237; // eax
  UFG::qResourceWarehouse *v238; // rax
  unsigned int v239; // eax
  Illusion::Material *v240; // rdi
  int v241; // ebx
  int v242; // eax
  int v243; // eax
  unsigned int v244; // eax
  int v245; // ebx
  int v246; // eax
  unsigned int v247; // ebx
  int v248; // eax
  UFG::qResourceWarehouse *v249; // rax
  unsigned int v250; // eax
  Illusion::Material *v251; // rdi
  int v252; // ebx
  int v253; // eax
  int v254; // eax
  unsigned int v255; // eax
  int v256; // ebx
  int v257; // eax
  unsigned int v258; // ebx
  int v259; // eax
  UFG::qResourceWarehouse *v260; // rax
  unsigned int v261; // eax
  Illusion::Material *v262; // rdi
  int v263; // ebx
  int v264; // eax
  int v265; // eax
  unsigned int v266; // eax
  unsigned int v267; // ebx
  int v268; // eax
  int v269; // eax
  int v270; // ebx
  int v271; // eax
  unsigned int v272; // ebx
  unsigned int v273; // eax
  int v274; // eax
  unsigned int v275; // ebx
  int v276; // eax
  UFG::qResourceWarehouse *v277; // rax
  unsigned int v278; // eax
  Illusion::Material *v279; // rdi
  int v280; // ebx
  int v281; // eax
  unsigned int v282; // ebx
  unsigned int v283; // eax
  int v284; // eax
  int v285; // eax
  int v286; // ebx
  int v287; // eax
  int v288; // eax
  int v289; // ebx
  unsigned int v290; // eax
  int v291; // eax
  int v292; // ebx
  int v293; // eax
  unsigned int v294; // eax
  unsigned int v295; // ebx
  int v296; // eax
  UFG::qResourceWarehouse *v297; // rax
  unsigned int v298; // eax
  Illusion::Material *v299; // rdi
  int v300; // ebx
  int v301; // eax
  unsigned int v302; // ebx
  int v303; // eax
  unsigned int v304; // eax
  int v305; // eax
  unsigned int v306; // ebx
  int v307; // eax
  UFG::qResourceWarehouse *v308; // rax
  unsigned int v309; // eax
  Illusion::Material *v310; // rdi
  int v311; // ebx
  int v312; // eax
  unsigned int v313; // ebx
  int v314; // eax
  unsigned int v315; // eax
  int v316; // eax
  unsigned int v317; // ebx
  UFG::qResourceWarehouse *v318; // rax
  unsigned int v319; // eax
  Illusion::Material *v320; // rdi
  int v321; // ebx
  int v322; // eax
  int v323; // eax
  unsigned int v324; // eax
  int v325; // eax
  unsigned int v326; // ebx
  int v327; // eax
  unsigned int v328; // ebx
  unsigned int v329; // eax
  unsigned int v330; // ebx
  int v331; // eax
  UFG::qResourceWarehouse *v332; // rax
  unsigned int v333; // eax
  Illusion::Material *v334; // rax
  Illusion::Material *v335; // rdi
  int v336; // eax
  int v337; // eax
  unsigned int v338; // eax
  int v339; // eax
  unsigned int v340; // ebx
  int v341; // eax
  unsigned int v342; // eax
  UFG::qResourceWarehouse *v343; // rax
  unsigned int v344; // eax
  Illusion::Material *v345; // rax
  Illusion::Material *v346; // rbx
  int v347; // eax
  int v348; // eax
  unsigned int v349; // eax
  int v350; // eax
  int v351; // eax
  unsigned int v352; // eax
  UFG::qResourceWarehouse *v353; // rax
  Illusion::Texture *v354; // [rsp+60h] [rbp+8h]

  v1 = this->mGBufferTarget;
  v2 = this;
  v3 = v1->mTargetTexture[0];
  v4 = v1->mTargetTexture[1];
  v5 = v1->mTargetTexture[2];
  v6 = v1->mDepthTextureCopy;
  v354 = this->mLightBufferTarget->mTargetTexture[0];
  v7 = UFG::qStringHashUpper32("DeferredLight", 0xFFFFFFFF);
  v8 = Illusion::Factory::NewMaterial("DeferredLight", v7, 0xCu, 0i64, 0i64, 0i64);
  v9 = UFG::qStringHash32("DRSPOTLIGHTSHADOWS", 0xFFFFFFFF);
  LOWORD(v8[1].mNode.mChild[0]) = 0;
  v10 = v9;
  HIDWORD(v8[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v8[1].mTypeUID = -1957338719;
  LODWORD(v8[1].mResourceHandles.mNode.mNext) = v10;
  LODWORD(v8[1].mNode.mParent) = v11;
  v12 = v3->mNode.mUID;
  *(_WORD *)&v8[1].mDebugName[12] = 0;
  *(_DWORD *)&v8[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v13 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v8[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v8[1].mStateBlockMask.mFlags[0]) = v12;
  *(_DWORD *)&v8[1].mDebugName[4] = v13;
  v14 = v4->mNode.mUID;
  LOWORD(v8[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v8[2].mNode.mUID = v14;
  v8[1].mNumParams = v15;
  v16 = v6->mNode.mUID;
  LOWORD(v8[2].mTypeUID) = 0;
  HIDWORD(v8[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v17 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v8[2].0 + 22) = -1958479169;
  *(_DWORD *)&v8[2].mDebugName[28] = v16;
  LODWORD(v8[2].mResourceHandles.mNode.mNext) = v17;
  LOWORD(v8[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[3].mNode.mChild[1]) = 315097330;
  LODWORD(v8[3].mNode.mChild[0]) = -1032465351;
  LOWORD(v8[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v8[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v8[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v8[3].mDebugName[12] = -929296280;
  v8[3].mNode.mUID = v18;
  v19 = v2->mSingleShadowTarget->mDepthTexture->mNode.mUID;
  *((_WORD *)&v8[3].0 + 44) = 0;
  *(_DWORD *)&v8[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("texShadow", 0xFFFFFFFF);
  LODWORD(v8[4].mNode.mParent) = -1958479169;
  LODWORD(v8[3].mMaterialUser.mOffset) = v19;
  *(_DWORD *)&v8[3].mDebugName[28] = v20;
  v21 = v5->mNode.mUID;
  LOWORD(v8[4].mNode.mChild[1]) = 0;
  HIDWORD(v8[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v22 = UFG::qStringHash32("texAmbient", 0xFFFFFFFF);
  *(_DWORD *)&v8[4].mDebugName[4] = -1958479169;
  v8[4].mTypeUID = v21;
  LODWORD(v8[4].mNode.mChild[0]) = v22;
  v23 = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  *(_WORD *)&v8[4].mDebugName[20] = 0;
  v24 = v23;
  *(_DWORD *)&v8[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v25 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  v8[4].mNumParams = -1958479169;
  LODWORD(v8[4].mStateBlockMask.mFlags[1]) = v24;
  *(_DWORD *)&v8[4].mDebugName[12] = v25;
  v26 = UFG::qStringHashUpper32("FX_NOISESINCOS", 0xFFFFFFFF);
  LOWORD(v8[5].mNode.mParent) = 0;
  v27 = v26;
  HIDWORD(v8[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v28 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v8[5].mResourceHandles.mNode.mNext) = -1958479169;
  LODWORD(v8[5].mResourceHandles.mNode.mPrev) = v27;
  LODWORD(v8[4].mMaterialUser.mOffset) = v28;
  *(_WORD *)&v8[5].mDebugName[4] = 0;
  *(_DWORD *)v8[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v29 = UFG::qStringHash32("texDistAtten", 0xFFFFFFFF);
  LODWORD(v8[5].mStateBlockMask.mFlags[0]) = -1958479169;
  *((_DWORD *)&v8[5].0 + 22) = 0;
  v8[5].mTypeUID = v29;
  v30 = UFG::qStringHashUpper32("25c7d589-9646-416c-985c-57db93552ed3", 0xFFFFFFFF);
  LOWORD(v8[5].mNumParams) = 0;
  HIDWORD(v8[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v31 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v8[6].mNode.mUID = 1292158962;
  LODWORD(v8[6].mNode.mChild[1]) = v30;
  LODWORD(v8[5].mStateBlockMask.mFlags[1]) = v31;
  v32 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v32, (UFG::qResourceData *)&v8->mNode);
  if ( LODWORD(v8[3].mNode.mChild[0]) != -1032465351 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v8[2].mNumParams,
      (unsigned int)v8[3].mNode.mChild[1],
      0xC275D439);
    v33 = v8->mMaterialUser.mOffset;
    if ( v33 )
      v34 = (_WORD *)((char *)&v8->mMaterialUser + v33);
    else
      v34 = 0i64;
    *v34 |= 0x20u;
  }
  if ( *(_DWORD *)&v8[3].mDebugName[12] != -929296280 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v8[3].mResourceHandles.mNode.mNext,
      *(_DWORD *)&v8[3].mDebugName[20],
      0xC89C1068);
    v35 = v8->mMaterialUser.mOffset;
    if ( v35 )
      v36 = (_WORD *)((char *)&v8->mMaterialUser + v35);
    else
      v36 = 0i64;
    *v36 |= 0x20u;
  }
  v2->mLightMaterial = v8;
  v37 = UFG::qStringHashUpper32("IrradianceVolume", 0xFFFFFFFF);
  v38 = Illusion::Factory::NewMaterial("IrradianceVolume", v37, 9u, 0i64, 0i64, 0i64);
  v39 = UFG::qStringHash32("DRIRRADIANCEVOLUME", 0xFFFFFFFF);
  LOWORD(v38[1].mNode.mChild[0]) = 0;
  HIDWORD(v38[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v40 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v38[1].mTypeUID = -1957338719;
  LODWORD(v38[1].mResourceHandles.mNode.mNext) = v39;
  LODWORD(v38[1].mNode.mParent) = v40;
  v41 = v3->mNode.mUID;
  *(_WORD *)&v38[1].mDebugName[12] = 0;
  *(_DWORD *)&v38[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v42 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v38[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v38[1].mStateBlockMask.mFlags[0]) = v41;
  *(_DWORD *)&v38[1].mDebugName[4] = v42;
  v43 = v4->mNode.mUID;
  LOWORD(v38[1].mMaterialUser.mOffset) = 0;
  *(&v38[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v44 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v38[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v38[2].mNode.mUID = v43;
  v38[1].mNumParams = v44;
  v45 = v6->mNode.mUID;
  LOWORD(v38[2].mTypeUID) = 0;
  HIDWORD(v38[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v46 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v38[2].0 + 22) = -1958479169;
  *(_DWORD *)&v38[2].mDebugName[28] = v45;
  LODWORD(v38[2].mResourceHandles.mNode.mNext) = v46;
  LOWORD(v38[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v38[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v47 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v38[3].mNode.mChild[1]) = 315097330;
  LODWORD(v38[3].mNode.mChild[0]) = 662883558;
  LODWORD(v38[2].mStateBlockMask.mFlags[0]) = v47;
  LOWORD(v38[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v38[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v48 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v38[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v38[3].mDebugName[12] = -262489691;
  v38[3].mNode.mUID = v48;
  *((_WORD *)&v38[3].0 + 44) = 0;
  *(_DWORD *)&v38[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v49 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v38[4].mNode.mParent) = -1958479169;
  LODWORD(v38[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v38[3].mDebugName[28] = v49;
  LOWORD(v38[4].mNode.mChild[1]) = 0;
  HIDWORD(v38[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v50 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v38[4].mDebugName[4] = -1958479169;
  v38[4].mTypeUID = 0;
  LODWORD(v38[4].mNode.mChild[0]) = v50;
  *(_WORD *)&v38[4].mDebugName[20] = 0;
  *(_DWORD *)&v38[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v51 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v38[4].mNumParams = -1958479169;
  LODWORD(v38[4].mStateBlockMask.mFlags[1]) = 0;
  *(_DWORD *)&v38[4].mDebugName[12] = v51;
  v52 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v52, (UFG::qResourceData *)&v38->mNode);
  v2->mIrradianceVolumeMaterial = v38;
  v53 = UFG::qStringHashUpper32("IrradianceSkyVolume", 0xFFFFFFFF);
  v54 = Illusion::Factory::NewMaterial("IrradianceSkyVolume", v53, 9u, 0i64, 0i64, 0i64);
  v55 = UFG::qStringHash32("DRIRRADIANCESKYVOLUME", 0xFFFFFFFF);
  LOWORD(v54[1].mNode.mChild[0]) = 0;
  HIDWORD(v54[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v56 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v54[1].mTypeUID = -1957338719;
  LODWORD(v54[1].mResourceHandles.mNode.mNext) = v55;
  LODWORD(v54[1].mNode.mParent) = v56;
  v57 = v3->mNode.mUID;
  *(_WORD *)&v54[1].mDebugName[12] = 0;
  *(_DWORD *)&v54[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v58 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v54[1].mStateBlockMask.mFlags[1]) = -1958479169;
  *(_DWORD *)&v54[1].mDebugName[4] = v58;
  LODWORD(v54[1].mStateBlockMask.mFlags[0]) = v57;
  v59 = v4->mNode.mUID;
  LOWORD(v54[1].mMaterialUser.mOffset) = 0;
  *(&v54[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v60 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v54[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v54[2].mNode.mUID = v59;
  v54[1].mNumParams = v60;
  v61 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v54[2].mTypeUID) = 0;
  HIDWORD(v54[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v62 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v54[2].0 + 22) = -1958479169;
  *(_DWORD *)&v54[2].mDebugName[28] = v61;
  LODWORD(v54[2].mResourceHandles.mNode.mNext) = v62;
  LOWORD(v54[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v54[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v63 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v54[3].mNode.mChild[1]) = 315097330;
  LODWORD(v54[3].mNode.mChild[0]) = 1478433551;
  LODWORD(v54[2].mStateBlockMask.mFlags[0]) = v63;
  LOWORD(v54[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v54[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v64 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v54[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v54[3].mDebugName[12] = -262489691;
  v54[3].mNode.mUID = v64;
  *((_WORD *)&v54[3].0 + 44) = 0;
  *(_DWORD *)&v54[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v65 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v54[4].mNode.mParent) = -1958479169;
  LODWORD(v54[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v54[3].mDebugName[28] = v65;
  LOWORD(v54[4].mNode.mChild[1]) = 0;
  HIDWORD(v54[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v66 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v54[4].mDebugName[4] = -1958479169;
  v54[4].mTypeUID = 0;
  LODWORD(v54[4].mNode.mChild[0]) = v66;
  *(_WORD *)&v54[4].mDebugName[20] = 0;
  *(_DWORD *)&v54[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v67 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v54[4].mNumParams = -1958479169;
  *(_DWORD *)&v54[4].mDebugName[12] = v67;
  LODWORD(v54[4].mStateBlockMask.mFlags[1]) = 0;
  v68 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v68, (UFG::qResourceData *)&v54->mNode);
  v2->mIrradianceVolumeSkyMaterial = v54;
  v69 = UFG::qStringHashUpper32("IrradianceSkyVolume", 0xFFFFFFFF);
  v70 = Illusion::Factory::NewMaterial("IrradianceSkyVolume", v69, 9u, 0i64, 0i64, 0i64);
  v71 = UFG::qStringHash32("DRIRRADIANCESKYVOLUME", 0xFFFFFFFF);
  LOWORD(v70[1].mNode.mChild[0]) = 0;
  HIDWORD(v70[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v72 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v70[1].mTypeUID = -1957338719;
  LODWORD(v70[1].mResourceHandles.mNode.mNext) = v71;
  LODWORD(v70[1].mNode.mParent) = v72;
  v73 = v3->mNode.mUID;
  *(_WORD *)&v70[1].mDebugName[12] = 0;
  *(_DWORD *)&v70[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v74 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v70[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v70[1].mStateBlockMask.mFlags[0]) = v73;
  *(_DWORD *)&v70[1].mDebugName[4] = v74;
  v75 = v4->mNode.mUID;
  LOWORD(v70[1].mMaterialUser.mOffset) = 0;
  *(&v70[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v76 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v70[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v70[2].mNode.mUID = v75;
  v70[1].mNumParams = v76;
  v77 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v70[2].mTypeUID) = 0;
  HIDWORD(v70[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v78 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v70[2].0 + 22) = -1958479169;
  *(_DWORD *)&v70[2].mDebugName[28] = v77;
  LODWORD(v70[2].mResourceHandles.mNode.mNext) = v78;
  LOWORD(v70[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v70[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v79 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v70[3].mNode.mChild[1]) = 315097330;
  LODWORD(v70[3].mNode.mChild[0]) = 662883558;
  LODWORD(v70[2].mStateBlockMask.mFlags[0]) = v79;
  LOWORD(v70[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v70[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v80 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v70[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v70[3].mDebugName[12] = -262489691;
  v70[3].mNode.mUID = v80;
  *((_WORD *)&v70[3].0 + 44) = 0;
  *(_DWORD *)&v70[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v81 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v70[4].mNode.mParent) = -1958479169;
  LODWORD(v70[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v70[3].mDebugName[28] = v81;
  LOWORD(v70[4].mNode.mChild[1]) = 0;
  HIDWORD(v70[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v82 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v70[4].mDebugName[4] = -1958479169;
  v70[4].mTypeUID = 0;
  LODWORD(v70[4].mNode.mChild[0]) = v82;
  *(_WORD *)&v70[4].mDebugName[20] = 0;
  *(_DWORD *)&v70[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v83 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v70[4].mNumParams = -1958479169;
  *(_DWORD *)&v70[4].mDebugName[12] = v83;
  LODWORD(v70[4].mStateBlockMask.mFlags[1]) = 0;
  v84 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v84, (UFG::qResourceData *)&v70->mNode);
  v2->mIrradianceVolumeSkyMaterial2 = v70;
  v85 = UFG::qStringHashUpper32("IrradianceSkyBlackVolume", 0xFFFFFFFF);
  v86 = Illusion::Factory::NewMaterial("IrradianceSkyBlackVolume", v85, 9u, 0i64, 0i64, 0i64);
  v87 = UFG::qStringHash32("DRIRRADIANCESKYBLACKVOLUME", 0xFFFFFFFF);
  LOWORD(v86[1].mNode.mChild[0]) = 0;
  HIDWORD(v86[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v88 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v86[1].mTypeUID = -1957338719;
  LODWORD(v86[1].mResourceHandles.mNode.mNext) = v87;
  LODWORD(v86[1].mNode.mParent) = v88;
  v89 = v3->mNode.mUID;
  *(_WORD *)&v86[1].mDebugName[12] = 0;
  *(_DWORD *)&v86[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v90 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v86[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v86[1].mStateBlockMask.mFlags[0]) = v89;
  *(_DWORD *)&v86[1].mDebugName[4] = v90;
  v91 = v4->mNode.mUID;
  LOWORD(v86[1].mMaterialUser.mOffset) = 0;
  *(&v86[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v92 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v86[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v86[2].mNode.mUID = v91;
  v86[1].mNumParams = v92;
  v93 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v86[2].mTypeUID) = 0;
  HIDWORD(v86[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v94 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v86[2].0 + 22) = -1958479169;
  *(_DWORD *)&v86[2].mDebugName[28] = v93;
  LODWORD(v86[2].mResourceHandles.mNode.mNext) = v94;
  LOWORD(v86[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v86[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v95 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v86[3].mNode.mChild[1]) = 315097330;
  LODWORD(v86[3].mNode.mChild[0]) = 1478433551;
  LODWORD(v86[2].mStateBlockMask.mFlags[0]) = v95;
  LOWORD(v86[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v86[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v96 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v86[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v86[3].mDebugName[12] = -262489691;
  v86[3].mNode.mUID = v96;
  *((_WORD *)&v86[3].0 + 44) = 0;
  *(_DWORD *)&v86[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v97 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  LODWORD(v86[4].mNode.mParent) = -1958479169;
  LODWORD(v86[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v86[3].mDebugName[28] = v97;
  LOWORD(v86[4].mNode.mChild[1]) = 0;
  HIDWORD(v86[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v98 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  *(_DWORD *)&v86[4].mDebugName[4] = -1958479169;
  v86[4].mTypeUID = 0;
  LODWORD(v86[4].mNode.mChild[0]) = v98;
  *(_WORD *)&v86[4].mDebugName[20] = 0;
  *(_DWORD *)&v86[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v99 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  v86[4].mNumParams = -1958479169;
  LODWORD(v86[4].mStateBlockMask.mFlags[1]) = 0;
  *(_DWORD *)&v86[4].mDebugName[12] = v99;
  v100 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v100, (UFG::qResourceData *)&v86->mNode);
  v2->mIrradianceVolumeSkyBlackMaterial = v86;
  v101 = UFG::qStringHashUpper32("ShadowCollector", 0xFFFFFFFF);
  v102 = Illusion::Factory::NewMaterial("ShadowCollector", v101, 9u, 0i64, 0i64, 0i64);
  v103 = UFG::qStringHash32("DRSHADOWCOLLECTOR", 0xFFFFFFFF);
  LOWORD(v102[1].mNode.mChild[0]) = 0;
  HIDWORD(v102[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v104 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v102[1].mTypeUID = -1957338719;
  LODWORD(v102[1].mResourceHandles.mNode.mNext) = v103;
  LODWORD(v102[1].mNode.mParent) = v104;
  v105 = v6->mNode.mUID;
  *(_WORD *)&v102[1].mDebugName[12] = 0;
  *(_DWORD *)&v102[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v106 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v102[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v102[1].mStateBlockMask.mFlags[0]) = v105;
  *(_DWORD *)&v102[1].mDebugName[4] = v106;
  LOWORD(v102[1].mMaterialUser.mOffset) = 0;
  *(&v102[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v107 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v102[2].mResourceHandles.mNode.mPrev) = 315097330;
  v102[2].mNode.mUID = 662883558;
  v102[1].mNumParams = v107;
  LOWORD(v102[2].mTypeUID) = 0;
  HIDWORD(v102[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v108 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v102[2].0 + 22) = 1002903008;
  *(_DWORD *)&v102[2].mDebugName[28] = 1660426324;
  LODWORD(v102[2].mResourceHandles.mNode.mNext) = v108;
  v109 = v2->mHalfSizeScratchTargetC->mTargetTexture[0]->mNode.mUID;
  LOWORD(v102[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v102[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v102[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v102[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v102[3].mNode.mChild[0]) = v109;
  v110 = v2->mCascadeShadowTexture->mNode.mUID;
  LOWORD(v102[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v102[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v111 = UFG::qStringHash32("texShadowAtlas", 0xFFFFFFFF);
  *(_DWORD *)&v102[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v102[3].mDebugName[12] = v110;
  v102[3].mNode.mUID = v111;
  v112 = UFG::qStringHashUpper32("FX_NOISESINCOS", 0xFFFFFFFF);
  *((_WORD *)&v102[3].0 + 44) = 0;
  *(_DWORD *)&v102[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v113 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v102[4].mNode.mParent) = -1958479169;
  LODWORD(v102[3].mMaterialUser.mOffset) = v112;
  *(_DWORD *)&v102[3].mDebugName[28] = v113;
  v114 = v2->mCascadeShadowTextureAliasDepth->mNode.mUID;
  LOWORD(v102[4].mNode.mChild[1]) = 0;
  HIDWORD(v102[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v115 = UFG::qStringHash32("texShadowRaw", 0xFFFFFFFF);
  *(_DWORD *)&v102[4].mDebugName[4] = -1958479169;
  v102[4].mTypeUID = v114;
  LODWORD(v102[4].mNode.mChild[0]) = v115;
  v116 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v102[4].mDebugName[20] = 0;
  *(_DWORD *)&v102[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v117 = UFG::qStringHash32("texDepth2", 0xFFFFFFFF);
  v102[4].mNumParams = -1958479169;
  *(_DWORD *)&v102[4].mDebugName[12] = v117;
  LODWORD(v102[4].mStateBlockMask.mFlags[1]) = v116;
  v118 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v118, (UFG::qResourceData *)&v102->mNode);
  v2->mShadowCollectorMaterial = v102;
  v119 = UFG::qStringHashUpper32("RasterState.SunMark", 0xFFFFFFFF);
  v120 = Illusion::Factory::NewRasterState("RasterState.SunMark", v119, 0i64, 0i64, 0i64);
  LODWORD(v120[1].mNode.mParent) = 33619969;
  *(_DWORD *)((char *)&v120[1].mNode.mParent + 6) = -16711423;
  *(_DWORD *)((char *)v120[1].mNode.mChild + 5) = 133119;
  BYTE4(v120[1].mNode.mChild[0]) = -1;
  BYTE1(v120[1].mNode.mChild[1]) = 0;
  v121 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v121, v120);
  v122 = UFG::qStringHashUpper32("StencilMaterialSunMark", 0xFFFFFFFF);
  v123 = Illusion::Factory::NewMaterial("StencilMaterialSunMark", v122, 3u, 0i64, 0i64, 0i64);
  LODWORD(v120) = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v123[1].mNode.mChild[0]) = 0;
  HIDWORD(v123[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v124 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v123[1].mResourceHandles.mNode.mNext) = (_DWORD)v120;
  v123[1].mTypeUID = -1957338719;
  LODWORD(v123[1].mNode.mParent) = v124;
  *(_WORD *)&v123[1].mDebugName[12] = 0;
  *(_DWORD *)&v123[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v125 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v123[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v123[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v123[1].mDebugName[4] = v125;
  LOWORD(v123[1].mMaterialUser.mOffset) = 0;
  *(&v123[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v126 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v123[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v123[1].mNumParams = v126;
  v123[2].mNode.mUID = v119;
  v127 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v127, (UFG::qResourceData *)&v123->mNode);
  v2->mSunAfterAmbientSpecMarkMaterial = v123;
  LODWORD(v123) = UFG::qStringHashUpper32("RasterState.SunTest", 0xFFFFFFFF);
  v128 = Illusion::Factory::NewRasterState("RasterState.SunTest", (unsigned int)v123, 0i64, 0i64, 0i64);
  LODWORD(v128[1].mNode.mParent) = 17235968;
  BYTE6(v128[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v128[1].mNode.mChild + 5) = 767;
  BYTE4(v128[1].mNode.mChild[0]) = -1;
  BYTE1(v128[1].mNode.mChild[1]) = 0;
  v129 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v129, v128);
  v2->mSunAfterAmbientSpecTestRasterStateUID = (unsigned int)v123;
  v130 = UFG::qStringHashUpper32("RasterState.SunTest.NoClear", 0xFFFFFFFF);
  LODWORD(v123) = v130;
  v131 = Illusion::Factory::NewRasterState("RasterState.SunTest.NoClear", v130, 0i64, 0i64, 0i64);
  LODWORD(v131[1].mNode.mParent) = 17235968;
  HIWORD(v131[1].mNode.mParent) = 257;
  *(_DWORD *)((char *)v131[1].mNode.mChild + 5) = 66303;
  BYTE4(v131[1].mNode.mChild[0]) = -1;
  *(_WORD *)((char *)v131[1].mNode.mChild + 1) = 511;
  LOBYTE(v131[1].mNode.mChild[0]) = 1;
  BYTE1(v131[1].mNode.mChild[1]) = 0;
  v132 = v131;
  v133 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v133, v132);
  v2->mSunAfterAmbientSpecTestNoClearRasterStateUID = (unsigned int)v123;
  v134 = UFG::qStringHashUpper32("SunUsingCollectorMat", 0xFFFFFFFF);
  v135 = Illusion::Factory::NewMaterial("SunUsingCollectorMat", v134, 7u, 0i64, 0i64, 0i64);
  LODWORD(v132) = UFG::qStringHash32("DRSUNLIGHTUSINGCOLLECTOR", 0xFFFFFFFF);
  LOWORD(v135[1].mNode.mChild[0]) = 0;
  HIDWORD(v135[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v136 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v135[1].mTypeUID = -1957338719;
  LODWORD(v135[1].mResourceHandles.mNode.mNext) = (_DWORD)v132;
  LODWORD(v135[1].mNode.mParent) = v136;
  LODWORD(v132) = v3->mNode.mUID;
  *(_WORD *)&v135[1].mDebugName[12] = 0;
  *(_DWORD *)&v135[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v137 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v135[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v135[1].mStateBlockMask.mFlags[0]) = (_DWORD)v132;
  *(_DWORD *)&v135[1].mDebugName[4] = v137;
  LODWORD(v132) = v4->mNode.mUID;
  LOWORD(v135[1].mMaterialUser.mOffset) = 0;
  *(&v135[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v138 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v135[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v135[2].mNode.mUID = (unsigned int)v132;
  v135[1].mNumParams = v138;
  LODWORD(v132) = v6->mNode.mUID;
  LOWORD(v135[2].mTypeUID) = 0;
  HIDWORD(v135[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v135[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v135[2].0 + 22) = -1958479169;
  *(_DWORD *)&v135[2].mDebugName[28] = (_DWORD)v132;
  LOWORD(v135[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v135[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v139 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v135[3].mNode.mChild[1]) = 315097330;
  LODWORD(v135[3].mNode.mChild[0]) = -1032465351;
  LODWORD(v135[2].mStateBlockMask.mFlags[0]) = v139;
  LOWORD(v135[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v135[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v140 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v135[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v135[3].mDebugName[12] = 1660426324;
  v135[3].mNode.mUID = v140;
  LODWORD(v132) = v2->mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  *((_WORD *)&v135[3].0 + 44) = 0;
  *(_DWORD *)&v135[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v141 = UFG::qStringHash32("texCollector", 0xFFFFFFFF);
  LODWORD(v135[4].mNode.mParent) = -1958479169;
  *(_DWORD *)&v135[3].mDebugName[28] = v141;
  LODWORD(v135[3].mMaterialUser.mOffset) = (_DWORD)v132;
  v142 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v142, (UFG::qResourceData *)&v135->mNode);
  v2->mSunUsingCollectorMaterial = v135;
  v2->mAmbientSpecShaderUID = UFG::qStringHash32("DRSKYAMBIENTSPEC", 0xFFFFFFFF);
  v2->mAmbientSpecWithSunShaderUID = UFG::qStringHash32("DRSKYAMBIENTSPECWITHSUN", 0xFFFFFFFF);
  v2->mAmbientSpecWithSunShader_DOUID = UFG::qStringHash32("DRSKYAMBIENTSPECWITHSUN_DO", 0xFFFFFFFF);
  v143 = UFG::qStringHashUpper32("SkyLightAmbientMaterial", 0xFFFFFFFF);
  v144 = Illusion::Factory::NewMaterial("SkyLightAmbientMaterial", v143, 8u, 0i64, 0i64, 0i64);
  LODWORD(v132) = v2->mAmbientSpecShaderUID;
  v145 = v144;
  LOWORD(v144[1].mNode.mChild[0]) = 0;
  HIDWORD(v144[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v146 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v145[1].mTypeUID = -1957338719;
  LODWORD(v145[1].mResourceHandles.mNode.mNext) = (_DWORD)v132;
  LODWORD(v145[1].mNode.mParent) = v146;
  LODWORD(v132) = v3->mNode.mUID;
  *(_WORD *)&v145[1].mDebugName[12] = 0;
  *(_DWORD *)&v145[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v147 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v145[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v145[1].mStateBlockMask.mFlags[0]) = (_DWORD)v132;
  *(_DWORD *)&v145[1].mDebugName[4] = v147;
  LODWORD(v132) = v4->mNode.mUID;
  LOWORD(v145[1].mMaterialUser.mOffset) = 0;
  *(&v145[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v148 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v145[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v145[2].mNode.mUID = (unsigned int)v132;
  v145[1].mNumParams = v148;
  LODWORD(v132) = v6->mNode.mUID;
  LOWORD(v145[2].mTypeUID) = 0;
  HIDWORD(v145[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v149 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v145[2].0 + 22) = -1958479169;
  *(_DWORD *)&v145[2].mDebugName[28] = (_DWORD)v132;
  LODWORD(v145[2].mResourceHandles.mNode.mNext) = v149;
  LOWORD(v145[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v145[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v150 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v145[3].mNode.mChild[1]) = 315097330;
  LODWORD(v145[3].mNode.mChild[0]) = -1032465351;
  LODWORD(v145[2].mStateBlockMask.mFlags[0]) = v150;
  LOWORD(v145[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v145[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v151 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v145[3].mDebugName[20] = 1002903008;
  *(_DWORD *)&v145[3].mDebugName[12] = -1835606658;
  v145[3].mNode.mUID = v151;
  LODWORD(v132) = v2->mSkyOcclusionAliasTarget->mTargetTexture[0]->mNode.mUID;
  *((_WORD *)&v145[3].0 + 44) = 0;
  *(_DWORD *)&v145[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v152 = UFG::qStringHash32("texAmbient2", 0xFFFFFFFF);
  LODWORD(v145[4].mNode.mParent) = -1958479169;
  LODWORD(v145[3].mMaterialUser.mOffset) = (_DWORD)v132;
  *(_DWORD *)&v145[3].mDebugName[28] = v152;
  LODWORD(v132) = v2->mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  LOWORD(v145[4].mNode.mChild[1]) = 0;
  HIDWORD(v145[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v145[4].mNode.mChild[0]) = UFG::qStringHash32("texCollector", 0xFFFFFFFF);
  *(_DWORD *)&v145[4].mDebugName[4] = -1958479169;
  v145[4].mTypeUID = (unsigned int)v132;
  v153 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v153, (UFG::qResourceData *)&v145->mNode);
  v2->mSkyAmbientMaterial = v145;
  v154 = UFG::qStringHashUpper32("BlobMat", 0xFFFFFFFF);
  v155 = Illusion::Factory::NewMaterial("BlobMat", v154, 6u, 0i64, 0i64, 0i64);
  LODWORD(v132) = UFG::qStringHash32("DRBLOBSHADOW", 0xFFFFFFFF);
  LOWORD(v155[1].mNode.mChild[0]) = 0;
  HIDWORD(v155[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v156 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v155[1].mTypeUID = -1957338719;
  LODWORD(v155[1].mResourceHandles.mNode.mNext) = (_DWORD)v132;
  LODWORD(v155[1].mNode.mParent) = v156;
  LODWORD(v132) = v4->mNode.mUID;
  *(_WORD *)&v155[1].mDebugName[12] = 0;
  *(_DWORD *)&v155[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v157 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v155[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v155[1].mStateBlockMask.mFlags[0]) = (_DWORD)v132;
  *(_DWORD *)&v155[1].mDebugName[4] = v157;
  LODWORD(v132) = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v155[1].mMaterialUser.mOffset) = 0;
  *(&v155[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v158 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v155[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v155[2].mNode.mUID = (unsigned int)v132;
  v155[1].mNumParams = v158;
  LOWORD(v155[2].mTypeUID) = 0;
  HIDWORD(v155[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v159 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *((_DWORD *)&v155[2].0 + 22) = 315097330;
  *(_DWORD *)&v155[2].mDebugName[28] = 1478433551;
  LODWORD(v155[2].mResourceHandles.mNode.mNext) = v159;
  LOWORD(v155[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v155[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v160 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v155[3].mNode.mChild[1]) = 1002903008;
  LODWORD(v155[2].mStateBlockMask.mFlags[0]) = v160;
  LODWORD(v155[3].mNode.mChild[0]) = 1660426324;
  LOWORD(v155[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v155[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v161 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *(_DWORD *)&v155[3].mDebugName[20] = -1958479169;
  v155[3].mNode.mUID = v161;
  *(_DWORD *)&v155[3].mDebugName[12] = 0;
  v162 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v162, (UFG::qResourceData *)&v155->mNode);
  if ( *(_DWORD *)&v155[2].mDebugName[28] != 1478433551 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v155[2].mDebugName[4],
      *((_DWORD *)&v155[2].0 + 22),
      0x581F1B0Fu);
    v163 = v155->mMaterialUser.mOffset;
    if ( v163 )
      v164 = (_WORD *)((char *)&v155->mMaterialUser + v163);
    else
      v164 = 0i64;
    *v164 |= 0x20u;
  }
  if ( LODWORD(v155[3].mNode.mChild[0]) != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v155[2].mNumParams,
      (unsigned int)v155[3].mNode.mChild[1],
      0x62F81854u);
    v165 = v155->mMaterialUser.mOffset;
    if ( v165 )
      v166 = (_WORD *)((char *)&v155->mMaterialUser + v165);
    else
      v166 = 0i64;
    *v166 |= 0x20u;
  }
  v2->mBlobMaterial = v155;
  v167 = UFG::qStringHashUpper32("CompositeLightsAndEffects", 0xFFFFFFFF);
  v168 = Illusion::Factory::NewMaterial("CompositeLightsAndEffects", v167, 0xBu, 0i64, 0i64, 0i64);
  LOWORD(v168[1].mNode.mChild[0]) = 0;
  v169 = v168;
  HIDWORD(v168[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v170 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v169[1].mTypeUID = -1957338719;
  LODWORD(v169[1].mResourceHandles.mNode.mNext) = 443851384;
  LODWORD(v169[1].mNode.mParent) = v170;
  v171 = v3->mNode.mUID;
  *(_WORD *)&v169[1].mDebugName[12] = 0;
  *(_DWORD *)&v169[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v172 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v169[1].mStateBlockMask.mFlags[1]) = -1958479169;
  *(_DWORD *)&v169[1].mDebugName[4] = v172;
  LODWORD(v169[1].mStateBlockMask.mFlags[0]) = v171;
  v173 = v354->mNode.mUID;
  LOWORD(v169[1].mMaterialUser.mOffset) = 0;
  *(&v169[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v174 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v169[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v169[2].mNode.mUID = v173;
  v169[1].mNumParams = v174;
  v175 = v5->mNode.mUID;
  LOWORD(v169[2].mTypeUID) = 0;
  HIDWORD(v169[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v176 = UFG::qStringHash32("texAmbient", 0xFFFFFFFF);
  *((_DWORD *)&v169[2].0 + 22) = -1958479169;
  *(_DWORD *)&v169[2].mDebugName[28] = v175;
  LODWORD(v169[2].mResourceHandles.mNode.mNext) = v176;
  LOWORD(v169[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v169[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v177 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v169[3].mNode.mChild[1]) = 315097330;
  LODWORD(v169[3].mNode.mChild[0]) = 662883558;
  LODWORD(v169[2].mStateBlockMask.mFlags[0]) = v177;
  LOWORD(v169[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v169[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v178 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v169[3].mDebugName[20] = 1002903008;
  v169[3].mNode.mUID = v178;
  *(_DWORD *)&v169[3].mDebugName[12] = 785612091;
  v179 = v4->mNode.mUID;
  *((_WORD *)&v169[3].0 + 44) = 0;
  *(_DWORD *)&v169[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v180 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v169[4].mNode.mParent) = -1958479169;
  LODWORD(v169[3].mMaterialUser.mOffset) = v179;
  *(_DWORD *)&v169[3].mDebugName[28] = v180;
  v181 = v6->mNode.mUID;
  LOWORD(v169[4].mNode.mChild[1]) = 0;
  HIDWORD(v169[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v182 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *(_DWORD *)&v169[4].mDebugName[4] = -1958479169;
  v169[4].mTypeUID = v181;
  LODWORD(v169[4].mNode.mChild[0]) = v182;
  v183 = v2->mSkyOcclusionAliasTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v169[4].mDebugName[20] = 0;
  *(_DWORD *)&v169[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v184 = UFG::qStringHash32("texAmbient2", 0xFFFFFFFF);
  v169[4].mNumParams = -1958479169;
  LODWORD(v169[4].mStateBlockMask.mFlags[1]) = v183;
  *(_DWORD *)&v169[4].mDebugName[12] = v184;
  v185 = v2->mFullSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
  LOWORD(v169[5].mNode.mParent) = 0;
  HIDWORD(v169[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v186 = UFG::qStringHash32("texCollector", 0xFFFFFFFF);
  LODWORD(v169[5].mResourceHandles.mNode.mNext) = -1958479169;
  LODWORD(v169[5].mResourceHandles.mNode.mPrev) = v185;
  LODWORD(v169[4].mMaterialUser.mOffset) = v186;
  v187 = UFG::qStringHash32("ATAN2", 0xFFFFFFFF);
  *(_WORD *)&v169[5].mDebugName[4] = 0;
  v188 = v187;
  *(_DWORD *)v169[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v189 = UFG::qStringHash32("texArcTan", 0xFFFFFFFF);
  LODWORD(v169[5].mStateBlockMask.mFlags[0]) = -1958479169;
  v169[5].mTypeUID = v189;
  *((_DWORD *)&v169[5].0 + 22) = v188;
  v190 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v190, (UFG::qResourceData *)&v169->mNode);
  v2->mCompositeLightingMaterial = v169;
  v191 = UFG::qStringHashUpper32("CompositeFinalMaterial", 0xFFFFFFFF);
  v192 = Illusion::Factory::NewMaterial("CompositeFinalMaterial", v191, 6u, 0i64, 0i64, 0i64);
  LOWORD(v192[1].mNode.mChild[0]) = 0;
  v193 = v192;
  HIDWORD(v192[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v194 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v193[1].mTypeUID = -1957338719;
  LODWORD(v193[1].mResourceHandles.mNode.mNext) = -1067196633;
  LODWORD(v193[1].mNode.mParent) = v194;
  *(_WORD *)&v193[1].mDebugName[12] = 0;
  *(_DWORD *)&v193[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v195 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v193[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v193[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v193[1].mDebugName[4] = v195;
  v196 = v2->mHDRBloomTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v193[1].mMaterialUser.mOffset) = 0;
  *(&v193[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v197 = UFG::qStringHash32("texHDRBloom", 0xFFFFFFFF);
  LODWORD(v193[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v193[2].mNode.mUID = v196;
  v193[1].mNumParams = v197;
  LOWORD(v193[2].mTypeUID) = 0;
  HIDWORD(v193[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v198 = UFG::qStringHash32("texColourCube", 0xFFFFFFFF);
  *((_DWORD *)&v193[2].0 + 22) = -1958479169;
  *(_DWORD *)&v193[2].mDebugName[28] = 0;
  LODWORD(v193[2].mResourceHandles.mNode.mNext) = v198;
  LOWORD(v193[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v193[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v199 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v193[3].mNode.mChild[1]) = 315097330;
  LODWORD(v193[3].mNode.mChild[0]) = 662883558;
  LODWORD(v193[2].mStateBlockMask.mFlags[0]) = v199;
  LOWORD(v193[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v193[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v200 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v193[3].mDebugName[20] = 1002903008;
  v193[3].mNode.mUID = v200;
  *(_DWORD *)&v193[3].mDebugName[12] = 1660426324;
  v201 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v201, (UFG::qResourceData *)&v193->mNode);
  v2->mCompositeFinalMaterial = v193;
  v202 = UFG::qStringHashUpper32("CameraBlur", 0xFFFFFFFF);
  v203 = Illusion::Factory::NewMaterial("CameraBlur", v202, 6u, 0i64, 0i64, 0i64);
  v204 = UFG::qStringHashUpper32("HK_CAMERABLUR", 0xFFFFFFFF);
  LOWORD(v203[1].mNode.mChild[0]) = 0;
  v205 = v204;
  HIDWORD(v203[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v206 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v203[1].mTypeUID = -1957338719;
  LODWORD(v203[1].mResourceHandles.mNode.mNext) = v205;
  LODWORD(v203[1].mNode.mParent) = v206;
  *(_WORD *)&v203[1].mDebugName[12] = 0;
  *(_DWORD *)&v203[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v207 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v203[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v203[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v203[1].mDebugName[4] = v207;
  v208 = v5->mNode.mUID;
  LOWORD(v203[1].mMaterialUser.mOffset) = 0;
  *(&v203[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v209 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v203[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v203[2].mNode.mUID = v208;
  v203[1].mNumParams = v209;
  v210 = v6->mNode.mUID;
  LOWORD(v203[2].mTypeUID) = 0;
  HIDWORD(v203[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v211 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *((_DWORD *)&v203[2].0 + 22) = -1958479169;
  *(_DWORD *)&v203[2].mDebugName[28] = v210;
  LODWORD(v203[2].mResourceHandles.mNode.mNext) = v211;
  LOWORD(v203[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v203[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v212 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v203[3].mNode.mChild[1]) = 315097330;
  LODWORD(v203[3].mNode.mChild[0]) = 662883558;
  LODWORD(v203[2].mStateBlockMask.mFlags[0]) = v212;
  LOWORD(v203[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v203[3].mNode.mUID + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v213 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *(_DWORD *)&v203[3].mDebugName[20] = 1002903008;
  v203[3].mNode.mUID = v213;
  *(_DWORD *)&v203[3].mDebugName[12] = 1660426324;
  v214 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v214, (UFG::qResourceData *)&v203->mNode);
  v2->mCameraBlurMaterial = v203;
  v215 = UFG::qStringHashUpper32("DownsampleDepth", 0xFFFFFFFF);
  v216 = Illusion::Factory::NewMaterial("DownsampleDepth", v215, 4u, 0i64, 0i64, 0i64);
  v217 = UFG::qStringHash32("DR_BLITDEPTHDOWNSAMPLE", 0xFFFFFFFF);
  LOWORD(v216[1].mNode.mChild[0]) = 0;
  HIDWORD(v216[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v218 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v216[1].mTypeUID = -1957338719;
  LODWORD(v216[1].mResourceHandles.mNode.mNext) = v217;
  LODWORD(v216[1].mNode.mParent) = v218;
  v219 = v6->mNode.mUID;
  *(_WORD *)&v216[1].mDebugName[12] = 0;
  *(_DWORD *)&v216[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v220 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v216[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v216[1].mStateBlockMask.mFlags[0]) = v219;
  *(_DWORD *)&v216[1].mDebugName[4] = v220;
  LOWORD(v216[1].mMaterialUser.mOffset) = 0;
  *(&v216[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v221 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v216[2].mResourceHandles.mNode.mPrev) = 315097330;
  v216[2].mNode.mUID = 662883558;
  v216[1].mNumParams = v221;
  LOWORD(v216[2].mTypeUID) = 0;
  HIDWORD(v216[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v222 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v216[2].0 + 22) = 1002903008;
  LODWORD(v216[2].mResourceHandles.mNode.mNext) = v222;
  *(_DWORD *)&v216[2].mDebugName[28] = 304454940;
  v223 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v223, (UFG::qResourceData *)&v216->mNode);
  if ( v216[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v216[2],
      (unsigned int)v216[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v224 = v216->mMaterialUser.mOffset;
    if ( v224 )
      v225 = (_WORD *)((char *)&v216->mMaterialUser + v224);
    else
      v225 = 0i64;
    *v225 |= 0x20u;
  }
  if ( *(_DWORD *)&v216[2].mDebugName[28] != 304454940 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v216[2].mDebugName[4],
      *((_DWORD *)&v216[2].0 + 22),
      0x12259D1Cu);
    v226 = v216->mMaterialUser.mOffset;
    if ( v226 )
      v227 = (_WORD *)((char *)&v216->mMaterialUser + v226);
    else
      v227 = 0i64;
    *v227 |= 0x20u;
  }
  v2->mDownsampleDepthMaterial = v216;
  v228 = UFG::qStringHashUpper32("DR_SSAO", 0xFFFFFFFF);
  v229 = Illusion::Factory::NewMaterial("DR_SSAO", v228, 5u, 0i64, 0i64, 0i64);
  v230 = UFG::qStringHashUpper32("HK_AO", 0xFFFFFFFF);
  LOWORD(v229[1].mNode.mChild[0]) = 0;
  HIDWORD(v229[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v231 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v229[1].mTypeUID = -1957338719;
  LODWORD(v229[1].mResourceHandles.mNode.mNext) = v230;
  LODWORD(v229[1].mNode.mParent) = v231;
  *(_WORD *)&v229[1].mDebugName[12] = 0;
  *(_DWORD *)&v229[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v232 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v229[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v229[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v229[1].mDebugName[4] = v232;
  LOWORD(v229[1].mMaterialUser.mOffset) = 0;
  *(&v229[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v233 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v229[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v229[2].mNode.mUID = 1660426324;
  v229[1].mNumParams = v233;
  v234 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v229[2].mTypeUID) = 0;
  HIDWORD(v229[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v235 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  *((_DWORD *)&v229[2].0 + 22) = -1958479169;
  *(_DWORD *)&v229[2].mDebugName[28] = v234;
  LODWORD(v229[2].mResourceHandles.mNode.mNext) = v235;
  v236 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v229[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v229[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v237 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v229[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v229[2].mStateBlockMask.mFlags[0]) = v237;
  LODWORD(v229[3].mNode.mChild[0]) = v236;
  v238 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v238, (UFG::qResourceData *)&v229->mNode);
  v2->mSSAOMaterial = v229;
  v239 = UFG::qStringHashUpper32("DR_SSAONIS", 0xFFFFFFFF);
  v240 = Illusion::Factory::NewMaterial("DR_SSAONIS", v239, 5u, 0i64, 0i64, 0i64);
  v241 = UFG::qStringHashUpper32("HK_AO_NIS", 0xFFFFFFFF);
  LOWORD(v240[1].mNode.mChild[0]) = 0;
  HIDWORD(v240[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v242 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v240[1].mTypeUID = -1957338719;
  LODWORD(v240[1].mResourceHandles.mNode.mNext) = v241;
  LODWORD(v240[1].mNode.mParent) = v242;
  *(_WORD *)&v240[1].mDebugName[12] = 0;
  *(_DWORD *)&v240[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v243 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v240[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v240[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v240[1].mDebugName[4] = v243;
  LOWORD(v240[1].mMaterialUser.mOffset) = 0;
  *(&v240[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v244 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v240[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v240[2].mNode.mUID = 1660426324;
  v240[1].mNumParams = v244;
  v245 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v240[2].mTypeUID) = 0;
  HIDWORD(v240[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v246 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  *((_DWORD *)&v240[2].0 + 22) = -1958479169;
  *(_DWORD *)&v240[2].mDebugName[28] = v245;
  LODWORD(v240[2].mResourceHandles.mNode.mNext) = v246;
  v247 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v240[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v240[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v248 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v240[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v240[2].mStateBlockMask.mFlags[0]) = v248;
  LODWORD(v240[3].mNode.mChild[0]) = v247;
  v249 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v249, (UFG::qResourceData *)&v240->mNode);
  v2->mSSAONISMaterial = v240;
  v250 = UFG::qStringHashUpper32("DR_SSAOHIGH", 0xFFFFFFFF);
  v251 = Illusion::Factory::NewMaterial("DR_SSAOHIGH", v250, 5u, 0i64, 0i64, 0i64);
  v252 = UFG::qStringHashUpper32("HK_AO_HIGH", 0xFFFFFFFF);
  LOWORD(v251[1].mNode.mChild[0]) = 0;
  HIDWORD(v251[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v253 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v251[1].mTypeUID = -1957338719;
  LODWORD(v251[1].mResourceHandles.mNode.mNext) = v252;
  LODWORD(v251[1].mNode.mParent) = v253;
  *(_WORD *)&v251[1].mDebugName[12] = 0;
  *(_DWORD *)&v251[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v254 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v251[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v251[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v251[1].mDebugName[4] = v254;
  LOWORD(v251[1].mMaterialUser.mOffset) = 0;
  *(&v251[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v255 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v251[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v251[2].mNode.mUID = 1660426324;
  v251[1].mNumParams = v255;
  v256 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v251[2].mTypeUID) = 0;
  HIDWORD(v251[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v257 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  *((_DWORD *)&v251[2].0 + 22) = -1958479169;
  *(_DWORD *)&v251[2].mDebugName[28] = v256;
  LODWORD(v251[2].mResourceHandles.mNode.mNext) = v257;
  v258 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v251[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v251[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v259 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v251[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v251[2].mStateBlockMask.mFlags[0]) = v259;
  LODWORD(v251[3].mNode.mChild[0]) = v258;
  v260 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v260, (UFG::qResourceData *)&v251->mNode);
  v2->mSSAOHighMaterial = v251;
  v261 = UFG::qStringHashUpper32("DR_SSDO", 0xFFFFFFFF);
  v262 = Illusion::Factory::NewMaterial("DR_SSDO", v261, 8u, 0i64, 0i64, 0i64);
  v263 = UFG::qStringHashUpper32("HK_DO", 0xFFFFFFFF);
  LOWORD(v262[1].mNode.mChild[0]) = 0;
  HIDWORD(v262[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v264 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v262[1].mTypeUID = -1957338719;
  LODWORD(v262[1].mResourceHandles.mNode.mNext) = v263;
  LODWORD(v262[1].mNode.mParent) = v264;
  *(_WORD *)&v262[1].mDebugName[12] = 0;
  *(_DWORD *)&v262[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v265 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v262[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v262[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v262[1].mDebugName[4] = v265;
  LOWORD(v262[1].mMaterialUser.mOffset) = 0;
  *(&v262[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v266 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v262[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v262[2].mNode.mUID = 1660426324;
  v262[1].mNumParams = v266;
  v267 = v2->mLightBufferTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v262[2].mTypeUID) = 0;
  HIDWORD(v262[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v268 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v262[2].0 + 22) = -1958479169;
  *(_DWORD *)&v262[2].mDebugName[28] = v267;
  LODWORD(v262[2].mResourceHandles.mNode.mNext) = v268;
  v269 = UFG::qStringHashUpper32("FX_NOISE4x4", 0xFFFFFFFF);
  LOWORD(v262[2].mStateBlockMask.mFlags[1]) = 0;
  v270 = v269;
  HIDWORD(v262[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v271 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v262[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v262[2].mStateBlockMask.mFlags[0]) = v271;
  LODWORD(v262[3].mNode.mChild[0]) = v270;
  v272 = v2->mGBufferTarget->mDepthTextureCopy->mNode.mUID;
  LOWORD(v262[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v262[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v273 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  *(_DWORD *)&v262[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v262[3].mDebugName[12] = v272;
  v262[3].mNode.mUID = v273;
  *((_WORD *)&v262[3].0 + 44) = 0;
  *(_DWORD *)&v262[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v274 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  LODWORD(v262[4].mNode.mParent) = -1958479169;
  LODWORD(v262[3].mMaterialUser.mOffset) = 0;
  *(_DWORD *)&v262[3].mDebugName[28] = v274;
  v275 = v2->mGBufferTarget->mTargetTexture[1]->mNode.mUID;
  LOWORD(v262[4].mNode.mChild[1]) = 0;
  HIDWORD(v262[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v276 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  *(_DWORD *)&v262[4].mDebugName[4] = -1958479169;
  LODWORD(v262[4].mNode.mChild[0]) = v276;
  v262[4].mTypeUID = v275;
  v277 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v277, (UFG::qResourceData *)&v262->mNode);
  v2->mSSDOMaterial = v262;
  v278 = UFG::qStringHashUpper32("SpotlightLightShaftMat", 0xFFFFFFFF);
  v279 = Illusion::Factory::NewMaterial("SpotlightLightShaftMat", v278, 8u, 0i64, 0i64, 0i64);
  v280 = UFG::qStringHash32("HK_LIGHTSHAFT_SPOTLIGHT", 0xFFFFFFFF);
  LOWORD(v279[1].mNode.mChild[0]) = 0;
  HIDWORD(v279[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v281 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v279[1].mTypeUID = -1957338719;
  LODWORD(v279[1].mResourceHandles.mNode.mNext) = v280;
  LODWORD(v279[1].mNode.mParent) = v281;
  v282 = v2->mQuarterSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v279[1].mDebugName[12] = 0;
  *(_DWORD *)&v279[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v279[1].mDebugName[4] = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v279[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v279[1].mStateBlockMask.mFlags[0]) = v282;
  LOWORD(v279[1].mMaterialUser.mOffset) = 0;
  *(&v279[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v283 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v279[2].mResourceHandles.mNode.mPrev) = 315097330;
  v279[2].mNode.mUID = -89056095;
  v279[1].mNumParams = v283;
  LOWORD(v279[2].mTypeUID) = 0;
  HIDWORD(v279[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v284 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v279[2].0 + 22) = 1002903008;
  *(_DWORD *)&v279[2].mDebugName[28] = -652645828;
  LODWORD(v279[2].mResourceHandles.mNode.mNext) = v284;
  v285 = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v279[2].mStateBlockMask.mFlags[1]) = 0;
  v286 = v285;
  HIDWORD(v279[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v287 = UFG::qStringHash32("texShadow", 0xFFFFFFFF);
  LODWORD(v279[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v279[3].mNode.mChild[0]) = v286;
  LODWORD(v279[2].mStateBlockMask.mFlags[0]) = v287;
  v288 = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v279[3].mResourceHandles.mNode.mPrev) = 0;
  v289 = v288;
  *(&v279[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v290 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *(_DWORD *)&v279[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v279[3].mDebugName[12] = v289;
  v279[3].mNode.mUID = v290;
  v291 = UFG::qStringHashUpper32("FX_NOISESINCOS", 0xFFFFFFFF);
  *((_WORD *)&v279[3].0 + 44) = 0;
  v292 = v291;
  *(_DWORD *)&v279[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v293 = UFG::qStringHash32("texNoise", 0xFFFFFFFF);
  LODWORD(v279[4].mNode.mParent) = -1958479169;
  LODWORD(v279[3].mMaterialUser.mOffset) = v292;
  *(_DWORD *)&v279[3].mDebugName[28] = v293;
  v294 = UFG::qStringHashUpper32("SKY_Noise_001", 0xFFFFFFFF);
  LOWORD(v279[4].mNode.mChild[1]) = 0;
  v295 = v294;
  HIDWORD(v279[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v296 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v279[4].mDebugName[4] = -1958479169;
  v279[4].mTypeUID = v295;
  LODWORD(v279[4].mNode.mChild[0]) = v296;
  v297 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v297, (UFG::qResourceData *)&v279->mNode);
  v2->mLightShaftSpotLightMaterial = v279;
  v298 = UFG::qStringHashUpper32("BlendVolumesIntoHalfSizeTarget", 0xFFFFFFFF);
  v299 = Illusion::Factory::NewMaterial("BlendVolumesIntoHalfSizeTarget", v298, 5u, 0i64, 0i64, 0i64);
  v300 = UFG::qStringHash32("BLENDVOLUMETRICEFFECTS", 0xFFFFFFFF);
  LOWORD(v299[1].mNode.mChild[0]) = 0;
  HIDWORD(v299[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v301 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v299[1].mTypeUID = -1957338719;
  LODWORD(v299[1].mResourceHandles.mNode.mNext) = v300;
  LODWORD(v299[1].mNode.mParent) = v301;
  v302 = v2->mQuarterSizeVolumetricTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v299[1].mDebugName[12] = 0;
  *(_DWORD *)&v299[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v303 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v299[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v299[1].mStateBlockMask.mFlags[0]) = v302;
  *(_DWORD *)&v299[1].mDebugName[4] = v303;
  LOWORD(v299[1].mMaterialUser.mOffset) = 0;
  *(&v299[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v304 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v299[2].mResourceHandles.mNode.mPrev) = 315097330;
  v299[2].mNode.mUID = -89056095;
  v299[1].mNumParams = v304;
  LOWORD(v299[2].mTypeUID) = 0;
  HIDWORD(v299[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v305 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v299[2].0 + 22) = 1002903008;
  *(_DWORD *)&v299[2].mDebugName[28] = 1660426324;
  LODWORD(v299[2].mResourceHandles.mNode.mNext) = v305;
  v306 = v2->mHalfSizeLinearDepthTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v299[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v299[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v307 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v299[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v299[3].mNode.mChild[0]) = v306;
  LODWORD(v299[2].mStateBlockMask.mFlags[0]) = v307;
  v308 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v308, (UFG::qResourceData *)&v299->mNode);
  v2->mMatBlendVolumesIntoHalfSize = v299;
  v309 = UFG::qStringHashUpper32("PostCompLightshaft", 0xFFFFFFFF);
  v310 = Illusion::Factory::NewMaterial("PostCompLightshaft", v309, 5u, 0i64, 0i64, 0i64);
  v311 = UFG::qStringHash32("HK_POSTCOMPBLIT_LIGHTSHAFT", 0xFFFFFFFF);
  LOWORD(v310[1].mNode.mChild[0]) = 0;
  HIDWORD(v310[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v312 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v310[1].mTypeUID = -1957338719;
  LODWORD(v310[1].mResourceHandles.mNode.mNext) = v311;
  LODWORD(v310[1].mNode.mParent) = v312;
  v313 = v2->mHalfSizeVolumetricTarget->mTargetTexture[0]->mNode.mUID;
  *(_WORD *)&v310[1].mDebugName[12] = 0;
  *(_DWORD *)&v310[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v314 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v310[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v310[1].mStateBlockMask.mFlags[0]) = v313;
  *(_DWORD *)&v310[1].mDebugName[4] = v314;
  LOWORD(v310[1].mMaterialUser.mOffset) = 0;
  *(&v310[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v315 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v310[2].mResourceHandles.mNode.mPrev) = 315097330;
  v310[2].mNode.mUID = -89056095;
  v310[1].mNumParams = v315;
  LOWORD(v310[2].mTypeUID) = 0;
  HIDWORD(v310[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v316 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v310[2].0 + 22) = 1002903008;
  *(_DWORD *)&v310[2].mDebugName[28] = 1660426324;
  LODWORD(v310[2].mResourceHandles.mNode.mNext) = v316;
  v317 = v6->mNode.mUID;
  LOWORD(v310[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v310[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v310[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v310[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v310[3].mNode.mChild[0]) = v317;
  v318 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v318, (UFG::qResourceData *)&v310->mNode);
  v2->mPostCompLightshaftMaterial = v310;
  v319 = UFG::qStringHashUpper32("BloomThresholdMaterial", 0xFFFFFFFF);
  v320 = Illusion::Factory::NewMaterial("BloomThresholdMaterial", v319, 7u, 0i64, 0i64, 0i64);
  v321 = UFG::qStringHash32("BLOOMTHRESHOLD", 0xFFFFFFFF);
  LOWORD(v320[1].mNode.mChild[0]) = 0;
  HIDWORD(v320[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v322 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v320[1].mTypeUID = -1957338719;
  LODWORD(v320[1].mResourceHandles.mNode.mNext) = v321;
  LODWORD(v320[1].mNode.mParent) = v322;
  *(_WORD *)&v320[1].mDebugName[12] = 0;
  *(_DWORD *)&v320[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v323 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v320[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v320[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v320[1].mDebugName[4] = v323;
  LOWORD(v320[1].mMaterialUser.mOffset) = 0;
  *(&v320[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v324 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v320[2].mResourceHandles.mNode.mPrev) = 315097330;
  v320[2].mNode.mUID = -89056095;
  v320[1].mNumParams = v324;
  LOWORD(v320[2].mTypeUID) = 0;
  HIDWORD(v320[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v325 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v320[2].0 + 22) = 1002903008;
  *(_DWORD *)&v320[2].mDebugName[28] = 1660426324;
  LODWORD(v320[2].mResourceHandles.mNode.mNext) = v325;
  v326 = v2->mHalfSizeLinearDepthTarget->mDepthTextureCopy->mNode.mUID;
  LOWORD(v320[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v320[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v327 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v320[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v320[2].mStateBlockMask.mFlags[0]) = v327;
  LODWORD(v320[3].mNode.mChild[0]) = v326;
  v328 = v2->mHalfSizeVolumetricTarget->mTargetTexture[0]->mNode.mUID;
  LOWORD(v320[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v320[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v329 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v320[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v320[3].mDebugName[12] = v328;
  v320[3].mNode.mUID = v329;
  v330 = v5->mNode.mUID;
  *((_WORD *)&v320[3].0 + 44) = 0;
  *(_DWORD *)&v320[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v331 = UFG::qStringHash32("texEmission", 0xFFFFFFFF);
  LODWORD(v320[4].mNode.mParent) = -1958479169;
  *(_DWORD *)&v320[3].mDebugName[28] = v331;
  LODWORD(v320[3].mMaterialUser.mOffset) = v330;
  v332 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v332, (UFG::qResourceData *)&v320->mNode);
  v2->mBloomThresholdMaterial = v320;
  v333 = UFG::qStringHashUpper32("AntiAliasMaterial", 0xFFFFFFFF);
  v334 = Illusion::Factory::NewMaterial("AntiAliasMaterial", v333, 6u, 0i64, 0i64, 0i64);
  LOWORD(v334[1].mNode.mChild[0]) = 0;
  v335 = v334;
  HIDWORD(v334[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v336 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v335[1].mTypeUID = -1957338719;
  LODWORD(v335[1].mResourceHandles.mNode.mNext) = 0;
  LODWORD(v335[1].mNode.mParent) = v336;
  *(_WORD *)&v335[1].mDebugName[12] = 0;
  *(_DWORD *)&v335[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v337 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v335[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v335[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v335[1].mDebugName[4] = v337;
  LOWORD(v335[1].mMaterialUser.mOffset) = 0;
  *(&v335[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v338 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v335[2].mResourceHandles.mNode.mPrev) = 315097330;
  v335[2].mNode.mUID = 662883558;
  v335[1].mNumParams = v338;
  LOWORD(v335[2].mTypeUID) = 0;
  HIDWORD(v335[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v339 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v335[2].0 + 22) = 1002903008;
  *(_DWORD *)&v335[2].mDebugName[28] = 1660426324;
  LODWORD(v335[2].mResourceHandles.mNode.mNext) = v339;
  v340 = v6->mNode.mUID;
  LOWORD(v335[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v335[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v341 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v335[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v335[3].mNode.mChild[0]) = v340;
  LODWORD(v335[2].mStateBlockMask.mFlags[0]) = v341;
  LOWORD(v335[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v335[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v342 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v335[3].mDebugName[20] = -1958479169;
  v335[3].mNode.mUID = v342;
  *(_DWORD *)&v335[3].mDebugName[12] = 0;
  v343 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v343, (UFG::qResourceData *)&v335->mNode);
  v2->mAntiAliasMaterial = v335;
  v344 = UFG::qStringHashUpper32("DistortionMaterial", 0xFFFFFFFF);
  v345 = Illusion::Factory::NewMaterial("DistortionMaterial", v344, 6u, 0i64, 0i64, 0i64);
  LOWORD(v345[1].mNode.mChild[0]) = 0;
  v346 = v345;
  HIDWORD(v345[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v347 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v346[1].mTypeUID = -1957338719;
  LODWORD(v346[1].mResourceHandles.mNode.mNext) = 0;
  LODWORD(v346[1].mNode.mParent) = v347;
  *(_WORD *)&v346[1].mDebugName[12] = 0;
  *(_DWORD *)&v346[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v348 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v346[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v346[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v346[1].mDebugName[4] = v348;
  LOWORD(v346[1].mMaterialUser.mOffset) = 0;
  *(&v346[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v349 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v346[2].mResourceHandles.mNode.mPrev) = 315097330;
  v346[2].mNode.mUID = 662883558;
  v346[1].mNumParams = v349;
  LOWORD(v346[2].mTypeUID) = 0;
  HIDWORD(v346[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v350 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v346[2].0 + 22) = 1002903008;
  *(_DWORD *)&v346[2].mDebugName[28] = 1660426324;
  LODWORD(v346[2].mResourceHandles.mNode.mNext) = v350;
  LOWORD(v346[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v346[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v351 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v346[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v346[3].mNode.mChild[0]) = 0;
  LODWORD(v346[2].mStateBlockMask.mFlags[0]) = v351;
  LOWORD(v346[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v346[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v352 = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v346[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v346[3].mDebugName[12] = 0;
  v346[3].mNode.mUID = v352;
  v353 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v353, (UFG::qResourceData *)&v346->mNode);
  v2->mDistortionMaterial = v346;
}a *)&v346->mNode);
  v2->mDistortionMaterial = v346;
}

// File Line: 1495
// RVA: 0x46890
void __fastcall UFG::RenderContext::DeleteTargets(UFG::RenderContext *this)
{
  UFG::RenderContext *v1; // rbx
  Illusion::Target *v2; // rcx
  Illusion::Target *v3; // rcx
  Illusion::Target *v4; // rcx
  Illusion::Target *v5; // rcx
  Illusion::Target *v6; // rcx
  Illusion::Target *v7; // rcx
  Illusion::Target *v8; // rcx
  Illusion::Target *v9; // rcx
  Illusion::Target *v10; // rcx
  Illusion::Target *v11; // rcx
  Illusion::Target *v12; // rcx
  Illusion::Target *v13; // rcx
  Illusion::Target *v14; // rcx
  Illusion::Target *v15; // rcx
  Illusion::Target *v16; // rcx
  Illusion::Target *v17; // rcx
  Illusion::Target *v18; // rcx
  Illusion::Target *v19; // rcx
  Illusion::Target *v20; // rcx
  Illusion::Target *v21; // rcx
  Illusion::Target *v22; // rcx
  Illusion::Target *v23; // rcx
  Illusion::Target *v24; // rcx
  Illusion::Target *v25; // rcx
  Illusion::Target *v26; // rcx
  Illusion::Texture *v27; // rcx
  Illusion::Target *v28; // rcx
  Illusion::Target *v29; // rcx
  Illusion::Target *v30; // rcx
  Illusion::Target *v31; // rcx
  Illusion::Target *v32; // rcx
  Illusion::Target *v33; // rcx
  Illusion::Target *v34; // rcx
  Illusion::Target *v35; // rcx
  Illusion::Texture *v36; // rcx
  Illusion::Target *v37; // rcx
  Illusion::UnorderedAccessView *v38; // rcx
  Illusion::UnorderedAccessView *v39; // rcx
  Illusion::UnorderedAccessView *v40; // rcx
  Illusion::UnorderedAccessView *v41; // rcx
  Illusion::Texture *v42; // rcx
  Illusion::Texture *v43; // rcx
  Illusion::Texture *v44; // rcx
  Illusion::Texture *v45; // rcx
  Illusion::Target *v46; // rcx
  Illusion::Target *v47; // rcx

  v1 = this;
  if ( this->mTargetsCreated )
  {
    Illusion::DeleteTarget(this->mGBufferTarget, 1);
    v2 = v1->mDynamicRangeTarget;
    v1->mGBufferTarget = 0i64;
    Illusion::DeleteTarget(v2, 1);
    v3 = v1->mLightBufferTarget;
    v1->mDynamicRangeTarget = 0i64;
    Illusion::DeleteTarget(v3, 1);
    v4 = v1->mHDRBloomTarget;
    v1->mLightBufferTarget = 0i64;
    Illusion::DeleteTarget(v4, 1);
    v5 = v1->mHalfSizeLinearDepthTarget;
    v1->mHDRBloomTarget = 0i64;
    Illusion::DeleteTarget(v5, 1);
    v6 = v1->mHalfSizeTarget;
    v1->mHalfSizeLinearDepthTarget = 0i64;
    Illusion::DeleteTarget(v6, 1);
    v7 = v1->mReflectionMipTarget;
    v1->mHalfSizeTarget = 0i64;
    if ( v7 )
    {
      Illusion::DeleteTarget(v7, 1);
      v1->mReflectionMipTarget = 0i64;
    }
    v8 = v1->mReflectionTarget;
    if ( v8 )
    {
      Illusion::DeleteTarget(v8, 1);
      v1->mReflectionTarget = 0i64;
    }
    v9 = v1->mSphericalEnvMapTarget;
    if ( v9 )
    {
      Illusion::DeleteTarget(v9, 1);
      v1->mSphericalEnvMapTarget = 0i64;
    }
    v10 = v1->mCubeMapTarget;
    if ( v10 )
    {
      Illusion::DeleteTarget(v10, 1);
      v1->mCubeMapTarget = 0i64;
    }
    Illusion::DeleteTarget(v1->mFullSizeScratchTargetA, 1);
    v11 = v1->mHalfSizeScratchTargetA;
    v1->mFullSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v11, 1);
    v12 = v1->mHalfSizeScratchTargetB;
    v1->mHalfSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v12, 1);
    v13 = v1->mHalfSizeScratchTargetC;
    v1->mHalfSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(v13, 1);
    v14 = v1->mQuarterSizeScratchTargetA;
    v1->mHalfSizeScratchTargetC = 0i64;
    Illusion::DeleteTarget(v14, 1);
    v15 = v1->mQuarterSizeScratchTargetB;
    v1->mQuarterSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v15, 1);
    v16 = v1->mEighthSizeScratchTargetA;
    v1->mQuarterSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(v16, 1);
    v17 = v1->mEighthSizeScratchTargetB;
    v1->mEighthSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v17, 1);
    v18 = v1->mSixteenthSizeScratchTargetA;
    v1->mEighthSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(v18, 1);
    v19 = v1->mSixteenthSizeScratchTargetB;
    v1->mSixteenthSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v19, 1);
    v20 = v1->mThrityTwoSizeScratchTargetA;
    v1->mSixteenthSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(v20, 1);
    v21 = v1->mThrityTwoSizeScratchTargetB;
    v1->mThrityTwoSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v21, 1);
    v22 = v1->mSixtyFourSizeScratchTargetA;
    v1->mThrityTwoSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(v22, 1);
    v23 = v1->mSixtyFourSizeScratchTargetB;
    v1->mSixtyFourSizeScratchTargetA = 0i64;
    Illusion::DeleteTarget(v23, 1);
    v24 = v1->mAmbientOcclusionAliasTarget;
    v1->mSixtyFourSizeScratchTargetB = 0i64;
    Illusion::DeleteTarget(v24, 1);
    v25 = v1->mSkyOcclusionAliasTarget;
    v1->mAmbientOcclusionAliasTarget = 0i64;
    Illusion::DeleteTarget(v25, 1);
    v26 = v1->mNearBlur;
    v1->mSkyOcclusionAliasTarget = 0i64;
    Illusion::DeleteTarget(v26, 1);
    v27 = v1->mHeightmapShadowTextureAlias;
    v1->mNearBlur = 0i64;
    Illusion::DeleteTexture(v27, 1);
    v28 = v1->mCascadeShadowTarget;
    v1->mHeightmapShadowTextureAlias = 0i64;
    Illusion::DeleteTarget(v28, 1);
    v29 = v1->mHalfSizeShadowTarget;
    v1->mCascadeShadowTarget = 0i64;
    v1->mCascadeShadowTexture = 0i64;
    Illusion::DeleteTarget(v29, 1);
    v1->mHalfSizeShadowTarget = 0i64;
    Illusion::DeleteTarget(v1->mQuarterSizeShadowTarget, 1);
    v30 = v1->mSingleShadowTarget;
    v1->mQuarterSizeShadowTarget = 0i64;
    Illusion::DeleteTarget(v30, 1);
    v31 = v1->mHalfSizeSingleShadowTarget;
    v1->mSingleShadowTarget = 0i64;
    Illusion::DeleteTarget(v31, 1);
    v32 = v1->mHeightmapTarget;
    v1->mHalfSizeSingleShadowTarget = 0i64;
    Illusion::DeleteTarget(v32, 1);
    v33 = v1->mCharacterShadowTarget;
    v1->mHeightmapTarget = 0i64;
    Illusion::DeleteTarget(v33, 1);
    Illusion::DeleteTexture(v1->mCascadeShadowTextureAliasDepth, 1);
    Illusion::DeleteTexture(v1->mHalfSizeShadowAliasTexture, 1);
    Illusion::DeleteTexture(v1->mQuarterSizeShadowAliasTexture, 1);
    Illusion::DeleteTexture(v1->mCharacterShadowTextureAliasDepth, 1);
    Illusion::DeleteTexture(v1->mSingleShadowTextureAliasDepth, 1);
    Illusion::DeleteTexture(v1->mHalfSizeSingleShadowAliasTexture, 1);
    v34 = v1->mAAResultTarget;
    v1->mCharacterShadowTarget = 0i64;
    v1->mCharacterShadowTexture = 0i64;
    v1->mCascadeShadowTextureAliasDepth = 0i64;
    v1->mHalfSizeShadowAliasTexture = 0i64;
    v1->mQuarterSizeShadowAliasTexture = 0i64;
    v1->mCharacterShadowTextureAliasDepth = 0i64;
    v1->mSingleShadowTextureAliasDepth = 0i64;
    v1->mHalfSizeSingleShadowAliasTexture = 0i64;
    if ( v34 )
    {
      Illusion::DeleteTarget(v34, 1);
      v1->mAAResultTarget = 0i64;
    }
    v35 = v1->mDirectionalOcclusionTarget;
    if ( v35 )
    {
      Illusion::DeleteTarget(v35, 1);
      v1->mDirectionalOcclusionTarget = 0i64;
    }
    v36 = v1->mLightBufferMain;
    if ( v36 )
    {
      Illusion::DeleteTexture(v36, 1);
      v1->mLightBufferMain = 0i64;
    }
    v37 = v1->mQuarterSizeAmbientOcclusionTarget;
    if ( v37 )
    {
      Illusion::DeleteTarget(v37, 1);
      v1->mQuarterSizeAmbientOcclusionTarget = 0i64;
    }
    v38 = v1->mQuarterSizeAmbientOcclusionAliasUAV;
    if ( v38 )
    {
      Illusion::UnorderedAccessView::Delete(v38);
      v1->mQuarterSizeAmbientOcclusionAliasUAV = 0i64;
    }
    v39 = v1->mQuarterSizeAmbientOcclusionScratchUAV;
    if ( v39 )
    {
      Illusion::UnorderedAccessView::Delete(v39);
      v1->mQuarterSizeAmbientOcclusionScratchUAV = 0i64;
    }
    v40 = v1->mAmbientOcclusionAliasUAV;
    if ( v40 )
    {
      Illusion::UnorderedAccessView::Delete(v40);
      v1->mAmbientOcclusionAliasUAV = 0i64;
    }
    v41 = v1->mAmbientOcclusionScratchUAV;
    if ( v41 )
    {
      Illusion::UnorderedAccessView::Delete(v41);
      v1->mAmbientOcclusionScratchUAV = 0i64;
    }
    v42 = v1->mQuarterSizeScratchAPointSampleTexture;
    if ( v42 )
    {
      Illusion::DeleteTexture(v42, 1);
      v1->mQuarterSizeScratchAPointSampleTexture = 0i64;
    }
    v43 = v1->mQuarterSizeScratchBPointSampleTexture;
    if ( v43 )
    {
      Illusion::DeleteTexture(v43, 1);
      v1->mQuarterSizeScratchBPointSampleTexture = 0i64;
    }
    v44 = v1->mHalfSizeScratchCPointSampleTexture;
    if ( v44 )
    {
      Illusion::DeleteTexture(v44, 1);
      v1->mHalfSizeScratchCPointSampleTexture = 0i64;
    }
    v45 = v1->mHalfSizeScratchBPointSampleTexture;
    if ( v45 )
    {
      Illusion::DeleteTexture(v45, 1);
      v1->mHalfSizeScratchBPointSampleTexture = 0i64;
    }
    v46 = v1->mQuarterSizeVolumetricTarget;
    if ( v46 )
    {
      Illusion::DeleteTarget(v46, 1);
      v1->mQuarterSizeVolumetricTarget = 0i64;
    }
    v47 = v1->mHalfSizeVolumetricTarget;
    if ( v47 )
    {
      Illusion::DeleteTarget(v47, 1);
      v1->mHalfSizeVolumetricTarget = 0i64;
    }
    _((AMD_HD3D *)v1->mRenderContextPlat);
    v1->mTargetsCreated = 0;
  }
}

