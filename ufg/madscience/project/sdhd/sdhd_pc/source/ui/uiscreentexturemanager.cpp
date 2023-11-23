// File Line: 94
// RVA: 0x1566890
__int64 UFG::_dynamic_initializer_for__symGhostFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_Ghost", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symGhostFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symGhostFlow__);
}

// File Line: 126
// RVA: 0x5BD7C0
void __fastcall UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
        UFG::UIScreenTextureManager::ScreenInfo *this,
        const char *screenName,
        const char *texturePackName)
{
  unsigned int v6; // eax

  v6 = UFG::qStringHashUpper32(screenName, -1);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v6;
  this->mPrev = &this->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
  this->mNext = &this->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
  UFG::qString::qString(&this->mScreenName, screenName);
  UFG::qString::qString(&this->mTexturePackName, texturePackName);
  *(_QWORD *)&this->mValidStates = 0i64;
  this->mTexturePackSize = 0;
  this->mLoadCb = 0i64;
  this->mIsLoadedCb = 0i64;
  this->mReleaseCb = 0i64;
  UFG::UIScreenTextureManager::ScreenInfo::SetTexturePack(this, texturePackName);
}

// File Line: 131
// RVA: 0x5C2040
void __fastcall UFG::UIScreenTextureManager::ScreenInfo::SetTexturePack(
        UFG::UIScreenTextureManager::ScreenInfo *this,
        const char *texturePackName)
{
  UFG::qString v3; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::Set(&this->mTexturePackName, texturePackName);
  if ( UFG::qString::operator!=(&this->mTexturePackName, 0i64) )
  {
    UFG::qString::qString(&v3, &this->mTexturePackName);
    UFG::qString::ReplaceString(&v3, ".perm.bin", ".temp.bin", 1);
    this->mTexturePackSize = (UFG::StreamFileWrapper::GetAllocationSize(v3.mData) + 4095) & 0xFFFFF000;
    UFG::qString::~qString(&v3);
  }
  else
  {
    this->mTexturePackSize = 0;
  }
}

// File Line: 151
// RVA: 0x5BD880
void __fastcall UFG::UIScreenTextureManager::TexturePackReference::TexturePackReference(
        UFG::UIScreenTextureManager::TexturePackReference *this,
        const char *fileName)
{
  unsigned int v4; // eax

  v4 = UFG::qStringHashUpper32(fileName, -1);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v4;
  UFG::qString::qString(&this->mFileName, fileName);
  *(_QWORD *)&this->mReferenceCount = 0i64;
  this->mTextures.mPrev = &this->mTextures;
  this->mTextures.mNext = &this->mTextures;
  this->mTextures.mCallback = 0i64;
  this->mTextures.mCallbackParam = 0i64;
  this->mTextures.mImpl = 0i64;
  *(_DWORD *)&this->mTextures.mFlags = 536870915;
  this->mTextures._mTargetState.mValue = 1;
  this->mDeferredCallbacks.p = 0i64;
  *(_QWORD *)&this->mDeferredCallbacks.size = 0i64;
  this->mDeferredCallbackParams.p = 0i64;
  *(_QWORD *)&this->mDeferredCallbackParams.size = 0i64;
  UFG::UIScreenTextureManager::TexturePackReference::SetTexturePack(this, fileName);
}

// File Line: 156
// RVA: 0x5C20E0
void __fastcall UFG::UIScreenTextureManager::TexturePackReference::SetTexturePack(
        UFG::UIScreenTextureManager::TexturePackReference *this,
        const char *texturePackName)
{
  UFG::qString v3; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::Set(&this->mFileName, texturePackName);
  if ( UFG::qString::operator!=(&this->mFileName, 0i64) )
  {
    UFG::qString::qString(&v3, &this->mFileName);
    UFG::qString::ReplaceString(&v3, ".perm.bin", ".temp.bin", 1);
    this->mTextureSize = (UFG::StreamFileWrapper::GetAllocationSize(v3.mData) + 4095) & 0xFFFFF000;
    UFG::qString::~qString(&v3);
  }
  else
  {
    this->mTextureSize = 0;
  }
}

// File Line: 171
// RVA: 0x5BE120
void __fastcall UFG::UIScreenTextureManager::Init(unsigned int texturePoolSize)
{
  UFG::allocator::free_link *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenFactoryBase *v4; // rax
  char *mData; // rdi
  UFG::UIScreenTextureManager *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbx
  UFG::UIScreenFactoryBase *v10; // rax
  UFG::UIScreenTextureManager *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  UFG::UIScreenFactoryBase *v14; // rax
  UFG::UIScreenTextureManager *v15; // rbx
  UFG::allocator::free_link *v16; // rax
  __int64 v17; // rax
  UFG::UIScreenFactoryBase *v18; // rax
  UFG::UIScreenTextureManager *v19; // rbx
  UFG::allocator::free_link *v20; // rax
  __int64 v21; // rax
  UFG::UIScreenFactoryBase *v22; // rax
  const char *v23; // rdi
  UFG::UIScreenTextureManager *v24; // rsi
  UFG::allocator::free_link *v25; // rax
  __int64 v26; // rax
  __int64 v27; // rbx
  UFG::UIScreenFactoryBase *v28; // rax
  const char *v29; // rdi
  UFG::UIScreenTextureManager *v30; // rsi
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rbx
  UFG::UIScreenFactoryBase *v34; // rax
  const char *v35; // rdi
  UFG::UIScreenTextureManager *v36; // rsi
  UFG::allocator::free_link *v37; // rax
  __int64 v38; // rax
  __int64 v39; // rbx
  UFG::UIScreenFactoryBase *v40; // rax
  UFG::UIScreenTextureManager *v41; // rbx
  UFG::allocator::free_link *v42; // rax
  __int64 v43; // rax
  UFG::UIScreenFactoryBase *v44; // rax
  const char *v45; // rdi
  UFG::UIScreenTextureManager *v46; // rsi
  UFG::allocator::free_link *v47; // rax
  __int64 v48; // rax
  __int64 v49; // rbx
  UFG::UIScreenFactoryBase *v50; // rax
  const char *v51; // rdi
  UFG::UIScreenTextureManager *v52; // rsi
  UFG::allocator::free_link *v53; // rax
  UFG::UIScreenTextureManager::ScreenInfo *v54; // rax
  UFG::UIScreenTextureManager::ScreenInfo *v55; // rbx
  UFG::UIScreenFactoryBase *v56; // rax
  UFG::UIScreenTextureManager *v57; // rbx
  UFG::allocator::free_link *v58; // rax
  __int64 v59; // rax
  UFG::UIScreenFactoryBase *v60; // rax
  const char *v61; // rdi
  UFG::UIScreenTextureManager *v62; // rsi
  UFG::allocator::free_link *v63; // rax
  __int64 v64; // rax
  __int64 v65; // rbx
  UFG::UIScreenFactoryBase *v66; // rax
  UFG::UIScreenTextureManager *v67; // rbx
  UFG::allocator::free_link *v68; // rax
  __int64 v69; // rax
  UFG::UIScreenFactoryBase *v70; // rax
  const char *v71; // rdi
  UFG::UIScreenTextureManager *v72; // rsi
  UFG::allocator::free_link *v73; // rax
  __int64 v74; // rax
  __int64 v75; // rbx
  UFG::UIScreenFactoryBase *v76; // rax
  UFG::UIScreenTextureManager *v77; // rbx
  UFG::allocator::free_link *v78; // rax
  __int64 v79; // rax
  UFG::UIScreenFactoryBase *v80; // rax
  const char *v81; // rdi
  UFG::UIScreenTextureManager *v82; // rsi
  UFG::allocator::free_link *v83; // rax
  __int64 v84; // rax
  __int64 v85; // rbx
  UFG::UIScreenFactoryBase *v86; // rax
  UFG::UIScreenTextureManager *v87; // rbx
  UFG::allocator::free_link *v88; // rax
  __int64 v89; // rax
  UFG::UIScreenFactoryBase *v90; // rax
  const char *v91; // rdi
  UFG::UIScreenTextureManager *v92; // rsi
  UFG::allocator::free_link *v93; // rax
  __int64 v94; // rax
  __int64 v95; // rbx
  UFG::UIScreenFactoryBase *v96; // rax
  const char *v97; // rdi
  UFG::UIScreenTextureManager *v98; // rsi
  UFG::allocator::free_link *v99; // rax
  __int64 v100; // rax
  __int64 v101; // rbx
  UFG::UIScreenFactoryBase *v102; // rax
  UFG::UIScreenTextureManager *v103; // rbx
  UFG::allocator::free_link *v104; // rax
  __int64 v105; // rax
  UFG::UIScreenFactoryBase *v106; // rax
  UFG::UIScreenTextureManager *v107; // rbx
  UFG::allocator::free_link *v108; // rax
  __int64 v109; // rax
  UFG::UIScreenFactoryBase *v110; // rax
  UFG::UIScreenTextureManager *v111; // rbx
  UFG::allocator::free_link *v112; // rax
  __int64 v113; // rax
  UFG::UIScreenFactoryBase *v114; // rax
  UFG::UIScreenTextureManager *v115; // rbx
  UFG::allocator::free_link *v116; // rax
  __int64 v117; // rax
  UFG::UIScreenFactoryBase *v118; // rax
  const char *v119; // rdi
  UFG::UIScreenTextureManager *v120; // rsi
  UFG::allocator::free_link *v121; // rax
  __int64 v122; // rax
  __int64 v123; // rbx
  UFG::UIScreenFactoryBase *v124; // rax
  const char *v125; // rdi
  UFG::UIScreenTextureManager *v126; // rsi
  UFG::allocator::free_link *v127; // rax
  __int64 v128; // rax
  __int64 v129; // rbx
  UFG::UIScreenFactoryBase *v130; // rax
  const char *v131; // rdi
  UFG::UIScreenTextureManager *v132; // rsi
  UFG::allocator::free_link *v133; // rax
  __int64 v134; // rax
  __int64 v135; // rbx
  UFG::UIScreenFactoryBase *v136; // rax
  UFG::UIScreenTextureManager *v137; // rbx
  UFG::allocator::free_link *v138; // rax
  __int64 v139; // rax
  UFG::UIScreenFactoryBase *v140; // rax
  const char *v141; // rdi
  UFG::UIScreenTextureManager *v142; // rsi
  UFG::allocator::free_link *v143; // rax
  __int64 v144; // rax
  __int64 v145; // rbx
  UFG::UIScreenFactoryBase *v146; // rax
  const char *v147; // rdi
  UFG::UIScreenTextureManager *v148; // rsi
  UFG::allocator::free_link *v149; // rax
  __int64 v150; // rax
  __int64 v151; // rbx
  UFG::UIScreenFactoryBase *v152; // rax
  UFG::UIScreenTextureManager *v153; // rbx
  UFG::allocator::free_link *v154; // rax
  __int64 v155; // rax
  UFG::UIScreenFactoryBase *v156; // rax
  UFG::UIScreenTextureManager *v157; // rbx
  UFG::allocator::free_link *v158; // rax
  __int64 v159; // rax
  UFG::UIScreenFactoryBase *v160; // rax
  const char *v161; // rdi
  UFG::UIScreenTextureManager *v162; // rsi
  UFG::allocator::free_link *v163; // rax
  __int64 v164; // rax
  __int64 v165; // rbx
  UFG::UIScreenFactoryBase *v166; // rax
  const char *v167; // rdi
  UFG::UIScreenTextureManager *v168; // rsi
  UFG::allocator::free_link *v169; // rax
  __int64 v170; // rax
  __int64 v171; // rbx
  UFG::UIScreenFactoryBase *v172; // rax
  const char *v173; // rdi
  UFG::UIScreenTextureManager *v174; // rsi
  UFG::allocator::free_link *v175; // rax
  __int64 v176; // rax
  __int64 v177; // rbx
  UFG::UIScreenFactoryBase *v178; // rax
  UFG::UIScreenTextureManager *v179; // rbx
  UFG::allocator::free_link *v180; // rax
  __int64 v181; // rax
  UFG::UIScreenFactoryBase *v182; // rax
  const char *v183; // rdi
  UFG::UIScreenTextureManager *v184; // rsi
  UFG::allocator::free_link *v185; // rax
  __int64 v186; // rax
  __int64 v187; // rbx
  UFG::UIScreenFactoryBase *v188; // rax
  const char *v189; // rdi
  UFG::UIScreenTextureManager *v190; // rsi
  UFG::allocator::free_link *v191; // rax
  __int64 v192; // rax
  __int64 v193; // rbx
  UFG::UIScreenFactoryBase *v194; // rax
  const char *v195; // rdi
  UFG::UIScreenTextureManager *v196; // rsi
  UFG::allocator::free_link *v197; // rax
  __int64 v198; // rax
  __int64 v199; // rbx
  UFG::UIScreenFactoryBase *v200; // rax
  UFG::UIScreenTextureManager *v201; // rbx
  UFG::allocator::free_link *v202; // rax
  __int64 v203; // rax
  UFG::UIScreenFactoryBase *v204; // rax
  const char *v205; // rdi
  UFG::UIScreenTextureManager *v206; // rsi
  UFG::allocator::free_link *v207; // rax
  __int64 v208; // rax
  __int64 v209; // rbx
  UFG::UIScreenFactoryBase *v210; // rax
  const char *v211; // rdi
  UFG::UIScreenTextureManager *v212; // rsi
  UFG::allocator::free_link *v213; // rax
  __int64 v214; // rax
  __int64 v215; // rbx
  UFG::UIScreenFactoryBase *v216; // rax
  UFG::UIScreenTextureManager *v217; // rbx
  UFG::allocator::free_link *v218; // rax
  __int64 v219; // rax
  UFG::UIScreenFactoryBase *v220; // rax
  UFG::UIScreenTextureManager *v221; // rbx
  UFG::allocator::free_link *v222; // rax
  __int64 v223; // rax
  UFG::UIScreenFactoryBase *v224; // rax
  const char *v225; // rdi
  UFG::UIScreenTextureManager *v226; // rsi
  UFG::allocator::free_link *v227; // rax
  __int64 v228; // rax
  __int64 v229; // rbx
  UFG::UIScreenFactoryBase *v230; // rax
  const char *v231; // rdi
  UFG::UIScreenTextureManager *v232; // rsi
  UFG::allocator::free_link *v233; // rax
  __int64 v234; // rax
  __int64 v235; // rbx
  UFG::UIScreenFactoryBase *v236; // rax
  const char *v237; // rdi
  UFG::UIScreenTextureManager *v238; // rsi
  UFG::allocator::free_link *v239; // rax
  __int64 v240; // rax
  __int64 v241; // rbx
  UFG::UIScreenFactoryBase *v242; // rax
  const char *v243; // rdi
  UFG::UIScreenTextureManager *v244; // rsi
  UFG::allocator::free_link *v245; // rax
  __int64 v246; // rax
  __int64 v247; // rbx
  UFG::UIScreenFactoryBase *v248; // rax
  const char *v249; // rdi
  UFG::UIScreenTextureManager *v250; // rsi
  UFG::allocator::free_link *v251; // rax
  __int64 v252; // rax
  __int64 v253; // rbx
  UFG::UIScreenFactoryBase *v254; // rax
  const char *v255; // rdi
  UFG::UIScreenTextureManager *v256; // rsi
  UFG::allocator::free_link *v257; // rax
  __int64 v258; // rax
  __int64 v259; // rbx
  UFG::UIScreenFactoryBase *v260; // rax
  const char *v261; // rdi
  UFG::UIScreenTextureManager *v262; // rsi
  UFG::allocator::free_link *v263; // rax
  __int64 v264; // rax
  __int64 v265; // rbx
  UFG::UIScreenFactoryBase *v266; // rax
  const char *v267; // rdi
  UFG::UIScreenTextureManager *v268; // rsi
  UFG::allocator::free_link *v269; // rax
  __int64 v270; // rax
  __int64 v271; // rbx
  UFG::UIScreenFactoryBase *v272; // rax
  const char *v273; // rdi
  UFG::UIScreenTextureManager *v274; // rsi
  UFG::allocator::free_link *v275; // rax
  __int64 v276; // rax
  __int64 v277; // rbx
  UFG::UIScreenFactoryBase *v278; // rax
  const char *v279; // rdi
  UFG::UIScreenTextureManager *v280; // rsi
  UFG::allocator::free_link *v281; // rax
  __int64 v282; // rax
  __int64 v283; // rbx
  UFG::UIScreenFactoryBase *v284; // rax
  UFG::UIScreenTextureManager *v285; // rbx
  UFG::allocator::free_link *v286; // rax
  __int64 v287; // rax
  UFG::UIScreenFactoryBase *v288; // rax
  UFG::UIScreenTextureManager *v289; // rbx
  UFG::allocator::free_link *v290; // rax
  __int64 v291; // rax
  UFG::UIScreenFactoryBase *v292; // rax
  UFG::UIScreenTextureManager *v293; // rbx
  UFG::allocator::free_link *v294; // rax
  __int64 v295; // rax
  UFG::UIScreenFactoryBase *v296; // rax
  UFG::UIScreenTextureManager *v297; // rbx
  UFG::allocator::free_link *v298; // rax
  __int64 v299; // rax
  UFG::UIScreenFactoryBase *v300; // rax
  UFG::UIScreenTextureManager *v301; // rbx
  UFG::allocator::free_link *v302; // rax
  __int64 v303; // rax
  UFG::UIScreenFactoryBase *v304; // rax
  const char *v305; // rdi
  UFG::UIScreenTextureManager *v306; // rsi
  UFG::allocator::free_link *v307; // rax
  __int64 v308; // rax
  __int64 v309; // rbx
  UFG::UIScreenFactoryBase *v310; // rax
  UFG::UIScreenTextureManager *v311; // rbx
  UFG::allocator::free_link *v312; // rax
  __int64 v313; // rax
  Illusion::Texture *v314; // rdx
  __int64 mOffset; // rax
  Illusion::TextureUser *v316; // rcx
  UFG::qString v317; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v318; // [rsp+58h] [rbp-90h]
  int v319; // [rsp+60h] [rbp-88h]
  int v320; // [rsp+64h] [rbp-84h]
  __int128 v321; // [rsp+68h] [rbp-80h]
  __int128 v322; // [rsp+78h] [rbp-70h]
  __int64 v323; // [rsp+88h] [rbp-60h]
  __int64 v324; // [rsp+90h] [rbp-58h]
  __int64 v325; // [rsp+98h] [rbp-50h]
  __int64 v326; // [rsp+A0h] [rbp-48h]
  __int64 v327; // [rsp+A8h] [rbp-40h]
  __int64 v328; // [rsp+B0h] [rbp-38h]
  int v329; // [rsp+B8h] [rbp-30h]
  char v330; // [rsp+BCh] [rbp-2Ch]
  Illusion::CreateTargetParams v331; // [rsp+C8h] [rbp-20h] BYREF
  __int64 v332; // [rsp+178h] [rbp+90h]
  void *vars0; // [rsp+1B0h] [rbp+C8h]

  v332 = -2i64;
  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x1B0ui64, "UIScreenTextureManager", 0i64, 1u);
  vars0 = v2;
  if ( v2 )
    UFG::UIScreenTextureManager::UIScreenTextureManager((UFG::UIScreenTextureManager *)v2, texturePoolSize);
  else
    v3 = 0i64;
  UFG::UIScreenTextureManager::sInstance = v3;
  UFG::UIScreen::mInitCallback = UFG::UI::ScreenInitCallback;
  v4 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                     &gScaleformMemoryPool,
                                     8ui64,
                                     "UIHKScreenLoading",
                                     0i64,
                                     1u);
  vars0 = v4;
  if ( v4 )
  {
    v4->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v4->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenLoading>::`vftable;
  }
  else
  {
    v4 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Loading", v4);
  mData = UFG::UIHKScreenLoading::gTexturePackFilename.mData;
  v6 = UFG::UIScreenTextureManager::sInstance;
  v7 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v7;
  if ( v7 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v7, "Loading", mData);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *(_DWORD *)(v9 + 128) = 12;
  *(_DWORD *)(v9 + 132) = 76;
  *(_QWORD *)(v9 + 144) = 0i64;
  *(_QWORD *)(v9 + 152) = 0i64;
  *(_QWORD *)(v9 + 160) = 0i64;
  if ( mData )
    *(_DWORD *)(v9 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(mData) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v6->mAllScreens.mTree, (UFG::qBaseNodeRB *)v9);
  v10 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenGlobalOverlay",
                                      0i64,
                                      1u);
  vars0 = v10;
  if ( v10 )
  {
    v10->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v10->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenGlobalOverlay>::`vftable;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "GlobalOverlay", v10);
  v11 = UFG::UIScreenTextureManager::sInstance;
  v12 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v12;
  if ( v12 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v12,
      "GlobalOverlay",
      0i64);
  else
    v13 = 0i64;
  *(_DWORD *)(v13 + 128) = -1;
  *(_DWORD *)(v13 + 132) = 36;
  *(_QWORD *)(v13 + 144) = 0i64;
  *(_QWORD *)(v13 + 152) = 0i64;
  *(_QWORD *)(v13 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v11->mAllScreens.mTree, (UFG::qBaseNodeRB *)v13);
  v14 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenDialogBox",
                                      0i64,
                                      1u);
  vars0 = v14;
  if ( v14 )
  {
    v14->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v14->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDialogBox>::`vftable;
  }
  else
  {
    v14 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DialogBox", v14);
  v15 = UFG::UIScreenTextureManager::sInstance;
  v16 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v16;
  if ( v16 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v16,
      "DialogBox",
      0i64);
  else
    v17 = 0i64;
  *(_DWORD *)(v17 + 128) = -1;
  *(_DWORD *)(v17 + 132) = 0;
  *(_QWORD *)(v17 + 144) = 0i64;
  *(_QWORD *)(v17 + 152) = 0i64;
  *(_QWORD *)(v17 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v15->mAllScreens.mTree, (UFG::qBaseNodeRB *)v17);
  v18 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenDialogPopup",
                                      0i64,
                                      1u);
  vars0 = v18;
  if ( v18 )
  {
    v18->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v18->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDialogPopup>::`vftable;
  }
  else
  {
    v18 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DialogPopup", v18);
  v19 = UFG::UIScreenTextureManager::sInstance;
  v20 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v20;
  if ( v20 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v20,
      "DialogPopup",
      0i64);
  else
    v21 = 0i64;
  *(_DWORD *)(v21 + 128) = -1;
  *(_DWORD *)(v21 + 132) = 0;
  *(_QWORD *)(v21 + 144) = 0i64;
  *(_QWORD *)(v21 + 152) = 0i64;
  *(_QWORD *)(v21 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v19->mAllScreens.mTree, (UFG::qBaseNodeRB *)v21);
  v22 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenSplash",
                                      0i64,
                                      1u);
  vars0 = v22;
  if ( v22 )
  {
    v22->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v22->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSplash>::`vftable;
  }
  else
  {
    v22 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Splash", v22);
  v23 = UFG::UIHKScreenSplash::gTexturePackFilename;
  v24 = UFG::UIScreenTextureManager::sInstance;
  v25 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v25;
  if ( v25 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v25, "Splash", v23);
    v27 = v26;
  }
  else
  {
    v27 = 0i64;
  }
  *(_DWORD *)(v27 + 128) = -1;
  *(_DWORD *)(v27 + 132) = 2;
  *(_QWORD *)(v27 + 144) = 0i64;
  *(_QWORD *)(v27 + 152) = 0i64;
  *(_QWORD *)(v27 + 160) = 0i64;
  if ( v23 )
    *(_DWORD *)(v27 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v23) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v24->mAllScreens.mTree, (UFG::qBaseNodeRB *)v27);
  v28 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenHints",
                                      0i64,
                                      1u);
  vars0 = v28;
  if ( v28 )
  {
    v28->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v28->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenHints>::`vftable;
  }
  else
  {
    v28 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Hints", v28);
  v29 = UFG::UIHKScreenHints::gTexturePackFilename;
  v30 = UFG::UIScreenTextureManager::sInstance;
  v31 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v31;
  if ( v31 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v31, "Hints", v29);
    v33 = v32;
  }
  else
  {
    v33 = 0i64;
  }
  *(_DWORD *)(v33 + 128) = 8;
  *(_DWORD *)(v33 + 132) = 12;
  *(_QWORD *)(v33 + 144) = 0i64;
  *(_QWORD *)(v33 + 152) = 0i64;
  *(_QWORD *)(v33 + 160) = 0i64;
  if ( v29 )
    *(_DWORD *)(v33 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v29) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v30->mAllScreens.mTree, (UFG::qBaseNodeRB *)v33);
  v34 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenMainMenu",
                                      0i64,
                                      1u);
  vars0 = v34;
  if ( v34 )
  {
    v34->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v34->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenMainMenu>::`vftable;
  }
  else
  {
    v34 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "MainMenu", v34);
  v35 = UFG::UIHKScreenMainMenu::gTexturePackFilename;
  v36 = UFG::UIScreenTextureManager::sInstance;
  v37 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v37;
  if ( v37 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v37, "MainMenu", v35);
    v39 = v38;
  }
  else
  {
    v39 = 0i64;
  }
  *(_DWORD *)(v39 + 128) = -1;
  *(_DWORD *)(v39 + 132) = 0;
  *(_QWORD *)(v39 + 144) = 0i64;
  *(_QWORD *)(v39 + 152) = 0i64;
  *(_QWORD *)(v39 + 160) = 0i64;
  if ( v35 )
    *(_DWORD *)(v39 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v35) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v36->mAllScreens.mTree, (UFG::qBaseNodeRB *)v39);
  v40 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenStartFlow",
                                      0i64,
                                      1u);
  vars0 = v40;
  if ( v40 )
  {
    v40->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v40->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenStartFlow>::`vftable;
  }
  else
  {
    v40 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "StartFlowScreen", v40);
  v41 = UFG::UIScreenTextureManager::sInstance;
  v42 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v42;
  if ( v42 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v42,
      "StartFlowScreen",
      0i64);
  else
    v43 = 0i64;
  *(_DWORD *)(v43 + 128) = -1;
  *(_DWORD *)(v43 + 132) = 0;
  *(_QWORD *)(v43 + 144) = 0i64;
  *(_QWORD *)(v43 + 152) = 0i64;
  *(_QWORD *)(v43 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v41->mAllScreens.mTree, (UFG::qBaseNodeRB *)v43);
  v44 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenPauseMenu",
                                      0i64,
                                      1u);
  vars0 = v44;
  if ( v44 )
  {
    v44->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v44->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPauseMenu>::`vftable;
  }
  else
  {
    v44 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PauseMenu", v44);
  v45 = UFG::UIHKScreenPauseMenu::gTexturePackFilename;
  v46 = UFG::UIScreenTextureManager::sInstance;
  v47 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v47;
  if ( v47 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v47,
      "PauseMenu",
      v45);
    v49 = v48;
  }
  else
  {
    v49 = 0i64;
  }
  *(_DWORD *)(v49 + 128) = 16;
  *(_DWORD *)(v49 + 132) = 26;
  *(_QWORD *)(v49 + 144) = 0i64;
  *(_QWORD *)(v49 + 152) = 0i64;
  *(_QWORD *)(v49 + 160) = 0i64;
  if ( v45 )
    *(_DWORD *)(v49 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v45) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v46->mAllScreens.mTree, (UFG::qBaseNodeRB *)v49);
  v50 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 8ui64, "UIHKScreenHud", 0i64, 1u);
  vars0 = v50;
  if ( v50 )
  {
    v50->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v50->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenHud>::`vftable;
  }
  else
  {
    v50 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Hud", v50);
  v51 = UFG::UIHKScreenHud::gTexturePackFilename;
  v52 = UFG::UIScreenTextureManager::sInstance;
  v53 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v53;
  if ( v53 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v53, "Hud", v51);
    v55 = v54;
  }
  else
  {
    v55 = 0i64;
  }
  v55->mValidStates = 2;
  v55->mFlags = 37;
  v55->mLoadCb = 0i64;
  v55->mIsLoadedCb = 0i64;
  v55->mReleaseCb = 0i64;
  if ( v51 )
    v55->mTexturePackSize = (UFG::StreamFileWrapper::GetAllocationSize(v51) + 0xFFF) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v52->mAllScreens.mTree, &v55->mNode);
  v56 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenSaveLoad",
                                      0i64,
                                      1u);
  vars0 = v56;
  if ( v56 )
  {
    v56->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v56->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSaveLoad>::`vftable;
  }
  else
  {
    v56 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "SaveLoad", v56);
  v57 = UFG::UIScreenTextureManager::sInstance;
  v58 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v58;
  if ( v58 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v58,
      "SaveLoad",
      0i64);
  else
    v59 = 0i64;
  *(_DWORD *)(v59 + 128) = -1;
  *(_DWORD *)(v59 + 132) = 18;
  *(_QWORD *)(v59 + 144) = 0i64;
  *(_QWORD *)(v59 + 152) = 0i64;
  *(_QWORD *)(v59 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v57->mAllScreens.mTree, (UFG::qBaseNodeRB *)v59);
  v60 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenWardrobe",
                                      0i64,
                                      1u);
  vars0 = v60;
  if ( v60 )
  {
    v60->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v60->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenWardrobe>::`vftable;
  }
  else
  {
    v60 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Wardrobe", v60);
  v61 = UFG::UIHKScreenWardrobe::gTexturePackFilename;
  v62 = UFG::UIScreenTextureManager::sInstance;
  v63 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v63;
  if ( v63 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v63, "Wardrobe", v61);
    v65 = v64;
  }
  else
  {
    v65 = 0i64;
  }
  *(_DWORD *)(v65 + 128) = 46;
  *(_DWORD *)(v65 + 132) = 2;
  *(_QWORD *)(v65 + 144) = 0i64;
  *(_QWORD *)(v65 + 152) = 0i64;
  *(_QWORD *)(v65 + 160) = 0i64;
  if ( v61 )
    *(_DWORD *)(v65 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v61) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v62->mAllScreens.mTree, (UFG::qBaseNodeRB *)v65);
  v66 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenCaseComplete",
                                      0i64,
                                      1u);
  vars0 = v66;
  if ( v66 )
  {
    v66->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v66->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenCaseComplete>::`vftable;
  }
  else
  {
    v66 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "CaseComplete", v66);
  v67 = UFG::UIScreenTextureManager::sInstance;
  v68 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v68;
  if ( v68 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v68,
      "CaseComplete",
      0i64);
  else
    v69 = 0i64;
  *(_DWORD *)(v69 + 128) = 46;
  *(_DWORD *)(v69 + 132) = 2;
  *(_QWORD *)(v69 + 144) = UFG::UIHKScreenCaseComplete::LoadTextures;
  *(_QWORD *)(v69 + 152) = UFG::UIHKScreenCaseComplete::AreTexturesLoaded;
  *(_QWORD *)(v69 + 160) = UFG::UIHKScreenCaseComplete::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v67->mAllScreens.mTree, (UFG::qBaseNodeRB *)v69);
  v70 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenWorldMap",
                                      0i64,
                                      1u);
  vars0 = v70;
  if ( v70 )
  {
    v70->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v70->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenWorldMap>::`vftable;
  }
  else
  {
    v70 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "WorldMap", v70);
  v71 = UFG::UIHKScreenWorldMap::gTexturePackFilename;
  v72 = UFG::UIScreenTextureManager::sInstance;
  v73 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v73;
  if ( v73 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v73, "WorldMap", v71);
    v75 = v74;
  }
  else
  {
    v75 = 0i64;
  }
  *(_DWORD *)(v75 + 128) = 16;
  *(_DWORD *)(v75 + 132) = 18;
  *(_QWORD *)(v75 + 144) = 0i64;
  *(_QWORD *)(v75 + 152) = 0i64;
  *(_QWORD *)(v75 + 160) = 0i64;
  if ( v71 )
    *(_DWORD *)(v75 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v71) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v72->mAllScreens.mTree, (UFG::qBaseNodeRB *)v75);
  v76 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenScriptableList",
                                      0i64,
                                      1u);
  vars0 = v76;
  if ( v76 )
  {
    v76->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v76->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenScriptableList>::`vftable;
  }
  else
  {
    v76 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "ScriptableList", v76);
  v77 = UFG::UIScreenTextureManager::sInstance;
  v78 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v78;
  if ( v78 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v78,
      "ScriptableList",
      0i64);
  else
    v79 = 0i64;
  *(_DWORD *)(v79 + 128) = -1;
  *(_DWORD *)(v79 + 132) = 0;
  *(_QWORD *)(v79 + 144) = 0i64;
  *(_QWORD *)(v79 + 152) = 0i64;
  *(_QWORD *)(v79 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v77->mAllScreens.mTree, (UFG::qBaseNodeRB *)v79);
  v80 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenGarageBrowser",
                                      0i64,
                                      1u);
  vars0 = v80;
  if ( v80 )
  {
    v80->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v80->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenGarageBrowser>::`vftable;
  }
  else
  {
    v80 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "GarageBrowser", v80);
  v81 = UFG::UIHKScreenGarageBrowser::gTexturePackFilename;
  v82 = UFG::UIScreenTextureManager::sInstance;
  v83 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v83;
  if ( v83 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v83,
      "GarageBrowser",
      v81);
    v85 = v84;
  }
  else
  {
    v85 = 0i64;
  }
  *(_DWORD *)(v85 + 128) = 46;
  *(_DWORD *)(v85 + 132) = 2;
  *(_QWORD *)(v85 + 144) = 0i64;
  *(_QWORD *)(v85 + 152) = 0i64;
  *(_QWORD *)(v85 + 160) = 0i64;
  if ( v81 )
    *(_DWORD *)(v85 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v81) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v82->mAllScreens.mTree, (UFG::qBaseNodeRB *)v85);
  v86 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenGameTracker",
                                      0i64,
                                      1u);
  vars0 = v86;
  if ( v86 )
  {
    v86->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v86->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenGameTracker>::`vftable;
  }
  else
  {
    v86 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "GameTracker", v86);
  v87 = UFG::UIScreenTextureManager::sInstance;
  v88 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v88;
  if ( v88 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v88,
      "GameTracker",
      0i64);
  else
    v89 = 0i64;
  *(_DWORD *)(v89 + 128) = -1;
  *(_DWORD *)(v89 + 132) = 0;
  *(_QWORD *)(v89 + 144) = UFG::UIHKScreenGameTracker::LoadTextures;
  *(_QWORD *)(v89 + 152) = UFG::UIHKScreenGameTracker::AreTexturesLoaded;
  *(_QWORD *)(v89 + 160) = UFG::UIHKScreenGameTracker::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v87->mAllScreens.mTree, (UFG::qBaseNodeRB *)v89);
  v90 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenCamera",
                                      0i64,
                                      1u);
  vars0 = v90;
  if ( v90 )
  {
    v90->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v90->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenCamera>::`vftable;
  }
  else
  {
    v90 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Camera", v90);
  v91 = UFG::UIHKScreenCamera::gTexturePackFilename;
  v92 = UFG::UIScreenTextureManager::sInstance;
  v93 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v93;
  if ( v93 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v93, "Camera", v91);
    v95 = v94;
  }
  else
  {
    v95 = 0i64;
  }
  *(_DWORD *)(v95 + 128) = -1;
  *(_DWORD *)(v95 + 132) = 6;
  *(_QWORD *)(v95 + 144) = 0i64;
  *(_QWORD *)(v95 + 152) = 0i64;
  *(_QWORD *)(v95 + 160) = 0i64;
  if ( v91 )
    *(_DWORD *)(v95 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v91) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v92->mAllScreens.mTree, (UFG::qBaseNodeRB *)v95);
  v96 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                      &gScaleformMemoryPool,
                                      8ui64,
                                      "UIHKScreenCameraCCTV",
                                      0i64,
                                      1u);
  vars0 = v96;
  if ( v96 )
  {
    v96->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v96->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenCameraCCTV>::`vftable;
  }
  else
  {
    v96 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Camera_CCTV", v96);
  v97 = UFG::UIHKScreenCameraCCTV::gTexturePackFilename;
  v98 = UFG::UIScreenTextureManager::sInstance;
  v99 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v99;
  if ( v99 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v99,
      "Camera_CCTV",
      v97);
    v101 = v100;
  }
  else
  {
    v101 = 0i64;
  }
  *(_DWORD *)(v101 + 128) = -1;
  *(_DWORD *)(v101 + 132) = 2;
  *(_QWORD *)(v101 + 144) = 0i64;
  *(_QWORD *)(v101 + 152) = 0i64;
  *(_QWORD *)(v101 + 160) = 0i64;
  if ( v97 )
    *(_DWORD *)(v101 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v97) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v98->mAllScreens.mTree, (UFG::qBaseNodeRB *)v101);
  v102 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsAudio",
                                       0i64,
                                       1u);
  vars0 = v102;
  if ( v102 )
  {
    v102->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v102->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsAudio>::`vftable;
  }
  else
  {
    v102 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_Audio", v102);
  v103 = UFG::UIScreenTextureManager::sInstance;
  v104 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v104;
  if ( v104 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v104,
      "Options_Audio",
      0i64);
  else
    v105 = 0i64;
  *(_DWORD *)(v105 + 128) = -1;
  *(_DWORD *)(v105 + 132) = 0;
  *(_QWORD *)(v105 + 144) = UFG::UIHKScreenOptionsDisplay::LoadTextures;
  *(_QWORD *)(v105 + 152) = UFG::UIHKScreenOptionsDisplayAdvanced::AreTexturesLoaded;
  *(_QWORD *)(v105 + 160) = UFG::UIHKScreenOptionsGame::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v103->mAllScreens.mTree, (UFG::qBaseNodeRB *)v105);
  v106 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsDisplay",
                                       0i64,
                                       1u);
  vars0 = v106;
  if ( v106 )
  {
    v106->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v106->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsDisplay>::`vftable;
  }
  else
  {
    v106 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_Display", v106);
  v107 = UFG::UIScreenTextureManager::sInstance;
  v108 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v108;
  if ( v108 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v108,
      "Options_Display",
      0i64);
  else
    v109 = 0i64;
  *(_DWORD *)(v109 + 128) = -1;
  *(_DWORD *)(v109 + 132) = 0;
  *(_QWORD *)(v109 + 144) = UFG::UIHKScreenOptionsDisplay::LoadTextures;
  *(_QWORD *)(v109 + 152) = UFG::UIHKScreenOptionsDisplayAdvanced::AreTexturesLoaded;
  *(_QWORD *)(v109 + 160) = UFG::UIHKScreenOptionsGame::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v107->mAllScreens.mTree, (UFG::qBaseNodeRB *)v109);
  v110 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsDisplayAdvanced",
                                       0i64,
                                       1u);
  vars0 = v110;
  if ( v110 )
  {
    v110->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v110->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsDisplayAdvanced>::`vftable;
  }
  else
  {
    v110 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_DisplayAdvanced", v110);
  v111 = UFG::UIScreenTextureManager::sInstance;
  v112 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v112;
  if ( v112 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v112,
      "Options_DisplayAdvanced",
      0i64);
  else
    v113 = 0i64;
  *(_DWORD *)(v113 + 128) = -1;
  *(_DWORD *)(v113 + 132) = 0;
  *(_QWORD *)(v113 + 144) = UFG::UIHKScreenOptionsDisplay::LoadTextures;
  *(_QWORD *)(v113 + 152) = UFG::UIHKScreenOptionsDisplayAdvanced::AreTexturesLoaded;
  *(_QWORD *)(v113 + 160) = UFG::UIHKScreenOptionsGame::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v111->mAllScreens.mTree, (UFG::qBaseNodeRB *)v113);
  v114 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsGame",
                                       0i64,
                                       1u);
  vars0 = v114;
  if ( v114 )
  {
    v114->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v114->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsGame>::`vftable;
  }
  else
  {
    v114 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_Game", v114);
  v115 = UFG::UIScreenTextureManager::sInstance;
  v116 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v116;
  if ( v116 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v116,
      "Options_Game",
      0i64);
  else
    v117 = 0i64;
  *(_DWORD *)(v117 + 128) = -1;
  *(_DWORD *)(v117 + 132) = 0;
  *(_QWORD *)(v117 + 144) = UFG::UIHKScreenOptionsDisplay::LoadTextures;
  *(_QWORD *)(v117 + 152) = UFG::UIHKScreenOptionsDisplayAdvanced::AreTexturesLoaded;
  *(_QWORD *)(v117 + 160) = UFG::UIHKScreenOptionsGame::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v115->mAllScreens.mTree, (UFG::qBaseNodeRB *)v117);
  v118 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsController",
                                       0i64,
                                       1u);
  vars0 = v118;
  if ( v118 )
  {
    v118->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v118->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsController>::`vftable;
  }
  else
  {
    v118 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_Controllers", v118);
  v119 = UFG::UIHKScreenOptionsController::gTexturePackFilename;
  v120 = UFG::UIScreenTextureManager::sInstance;
  v121 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v121;
  if ( v121 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v121,
      "Options_Controllers",
      v119);
    v123 = v122;
  }
  else
  {
    v123 = 0i64;
  }
  *(_DWORD *)(v123 + 128) = -1;
  *(_DWORD *)(v123 + 132) = 0;
  *(_QWORD *)(v123 + 144) = 0i64;
  *(_QWORD *)(v123 + 152) = 0i64;
  *(_QWORD *)(v123 + 160) = 0i64;
  if ( v119 )
    *(_DWORD *)(v123 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v119) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v120->mAllScreens.mTree, (UFG::qBaseNodeRB *)v123);
  v124 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsButtonMapping",
                                       0i64,
                                       1u);
  vars0 = v124;
  if ( v124 )
  {
    v124->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v124->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsButtonMapping>::`vftable;
  }
  else
  {
    v124 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_ButtonMapping", v124);
  v125 = UFG::UIHKScreenOptionsButtonMapping::gTexturePackFilename;
  v126 = UFG::UIScreenTextureManager::sInstance;
  v127 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v127;
  if ( v127 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v127,
      "Options_ButtonMapping",
      v125);
    v129 = v128;
  }
  else
  {
    v129 = 0i64;
  }
  *(_DWORD *)(v129 + 128) = -1;
  *(_DWORD *)(v129 + 132) = 0;
  *(_QWORD *)(v129 + 144) = 0i64;
  *(_QWORD *)(v129 + 152) = 0i64;
  *(_QWORD *)(v129 + 160) = 0i64;
  if ( v125 )
    *(_DWORD *)(v129 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v125) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v126->mAllScreens.mTree, (UFG::qBaseNodeRB *)v129);
  v130 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOptionsCalibration",
                                       0i64,
                                       1u);
  vars0 = v130;
  if ( v130 )
  {
    v130->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v130->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOptionsCalibration>::`vftable;
  }
  else
  {
    v130 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Options_Calibration", v130);
  v131 = UFG::UIHKScreenOptionsCalibration::gTexturePackFilename;
  v132 = UFG::UIScreenTextureManager::sInstance;
  v133 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v133;
  if ( v133 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v133,
      "Options_Calibration",
      v131);
    v135 = v134;
  }
  else
  {
    v135 = 0i64;
  }
  *(_DWORD *)(v135 + 128) = -1;
  *(_DWORD *)(v135 + 132) = 0;
  *(_QWORD *)(v135 + 144) = 0i64;
  *(_QWORD *)(v135 + 152) = 0i64;
  *(_QWORD *)(v135 + 160) = 0i64;
  if ( v131 )
    *(_DWORD *)(v135 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v131) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v132->mAllScreens.mTree, (UFG::qBaseNodeRB *)v135);
  v136 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenSocialHub",
                                       0i64,
                                       1u);
  vars0 = v136;
  if ( v136 )
  {
    v136->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v136->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSocialHub>::`vftable;
  }
  else
  {
    v136 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "SocialHub", v136);
  v137 = UFG::UIScreenTextureManager::sInstance;
  v138 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v138;
  if ( v138 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v138,
      "SocialHub",
      0i64);
  else
    v139 = 0i64;
  *(_DWORD *)(v139 + 128) = 16;
  *(_DWORD *)(v139 + 132) = 16;
  *(_QWORD *)(v139 + 144) = UFG::UIHKScreenSocialHub::LoadTextures;
  *(_QWORD *)(v139 + 152) = UFG::UIHKScreenSocialHub::AreTexturesLoaded;
  *(_QWORD *)(v139 + 160) = UFG::UIHKScreenSocialHub::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v137->mAllScreens.mTree, (UFG::qBaseNodeRB *)v139);
  v140 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenStats",
                                       0i64,
                                       1u);
  vars0 = v140;
  if ( v140 )
  {
    v140->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v140->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenStats>::`vftable;
  }
  else
  {
    v140 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Stats", v140);
  v141 = UFG::UIHKScreenStats::gTexturePackFilename;
  v142 = UFG::UIScreenTextureManager::sInstance;
  v143 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v143;
  if ( v143 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v143, "Stats", v141);
    v145 = v144;
  }
  else
  {
    v145 = 0i64;
  }
  *(_DWORD *)(v145 + 128) = -1;
  *(_DWORD *)(v145 + 132) = 0;
  *(_QWORD *)(v145 + 144) = 0i64;
  *(_QWORD *)(v145 + 152) = 0i64;
  *(_QWORD *)(v145 + 160) = 0i64;
  if ( v141 )
    *(_DWORD *)(v145 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v141) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v142->mAllScreens.mTree, (UFG::qBaseNodeRB *)v145);
  v146 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenPhotoBrowser",
                                       0i64,
                                       1u);
  vars0 = v146;
  if ( v146 )
  {
    v146->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v146->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPhotoBrowser>::`vftable;
  }
  else
  {
    v146 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PhotoBrowser", v146);
  v147 = UFG::UIHKScreenPhotoBrowser::gTexturePackFilename;
  v148 = UFG::UIScreenTextureManager::sInstance;
  v149 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v149;
  if ( v149 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v149,
      "PhotoBrowser",
      v147);
    v151 = v150;
  }
  else
  {
    v151 = 0i64;
  }
  *(_DWORD *)(v151 + 128) = -1;
  *(_DWORD *)(v151 + 132) = 0;
  *(_QWORD *)(v151 + 144) = 0i64;
  *(_QWORD *)(v151 + 152) = 0i64;
  *(_QWORD *)(v151 + 160) = 0i64;
  if ( v147 )
    *(_DWORD *)(v151 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v147) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v148->mAllScreens.mTree, (UFG::qBaseNodeRB *)v151);
  v152 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIScreenCredits",
                                       0i64,
                                       1u);
  vars0 = v152;
  if ( v152 )
  {
    v152->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v152->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIScreenCredits>::`vftable;
  }
  else
  {
    v152 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Credits", v152);
  v153 = UFG::UIScreenTextureManager::sInstance;
  v154 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v154;
  if ( v154 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v154,
      "Credits",
      0i64);
  else
    v155 = 0i64;
  *(_DWORD *)(v155 + 128) = -1;
  *(_DWORD *)(v155 + 132) = 2;
  *(_QWORD *)(v155 + 144) = 0i64;
  *(_QWORD *)(v155 + 152) = 0i64;
  *(_QWORD *)(v155 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v153->mAllScreens.mTree, (UFG::qBaseNodeRB *)v155);
  v156 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenNISPause",
                                       0i64,
                                       1u);
  vars0 = v156;
  if ( v156 )
  {
    v156->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v156->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenNISPause>::`vftable;
  }
  else
  {
    v156 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "NISPause", v156);
  v157 = UFG::UIScreenTextureManager::sInstance;
  v158 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v158;
  if ( v158 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v158,
      "NISPause",
      0i64);
  else
    v159 = 0i64;
  *(_DWORD *)(v159 + 128) = -1;
  *(_DWORD *)(v159 + 132) = 0;
  *(_QWORD *)(v159 + 144) = 0i64;
  *(_QWORD *)(v159 + 152) = 0i64;
  *(_QWORD *)(v159 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v157->mAllScreens.mTree, (UFG::qBaseNodeRB *)v159);
  v160 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenMissionFailed",
                                       0i64,
                                       1u);
  vars0 = v160;
  if ( v160 )
  {
    v160->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v160->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenMissionFailed>::`vftable;
  }
  else
  {
    v160 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Dialog_MissionFailed", v160);
  v161 = UFG::UIHKScreenMissionFailed::gTexturePackFilename;
  v162 = UFG::UIScreenTextureManager::sInstance;
  v163 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v163;
  if ( v163 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v163,
      "Dialog_MissionFailed",
      v161);
    v165 = v164;
  }
  else
  {
    v165 = 0i64;
  }
  *(_DWORD *)(v165 + 128) = -1;
  *(_DWORD *)(v165 + 132) = 18;
  *(_QWORD *)(v165 + 144) = 0i64;
  *(_QWORD *)(v165 + 152) = 0i64;
  *(_QWORD *)(v165 + 160) = 0i64;
  if ( v161 )
    *(_DWORD *)(v165 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v161) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v162->mAllScreens.mTree, (UFG::qBaseNodeRB *)v165);
  v166 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenFightClub",
                                       0i64,
                                       1u);
  vars0 = v166;
  if ( v166 )
  {
    v166->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v166->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenFightClub>::`vftable;
  }
  else
  {
    v166 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "FightClub", v166);
  v167 = UFG::UIHKScreenFightClub::gTexturePackFilename;
  v168 = UFG::UIScreenTextureManager::sInstance;
  v169 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v169;
  if ( v169 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v169,
      "FightClub",
      v167);
    v171 = v170;
  }
  else
  {
    v171 = 0i64;
  }
  *(_DWORD *)(v171 + 128) = -1;
  *(_DWORD *)(v171 + 132) = 2;
  *(_QWORD *)(v171 + 144) = 0i64;
  *(_QWORD *)(v171 + 152) = 0i64;
  *(_QWORD *)(v171 + 160) = 0i64;
  if ( v167 )
    *(_DWORD *)(v171 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v167) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v168->mAllScreens.mTree, (UFG::qBaseNodeRB *)v171);
  v172 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenMartialArts",
                                       0i64,
                                       1u);
  vars0 = v172;
  if ( v172 )
  {
    v172->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v172->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenMartialArts>::`vftable;
  }
  else
  {
    v172 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "MartialArts", v172);
  v173 = UFG::UIHKScreenMartialArts::gTexturePackFilename;
  v174 = UFG::UIScreenTextureManager::sInstance;
  v175 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v175;
  if ( v175 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v175,
      "MartialArts",
      v173);
    v177 = v176;
  }
  else
  {
    v177 = 0i64;
  }
  *(_DWORD *)(v177 + 128) = -1;
  *(_DWORD *)(v177 + 132) = 0;
  *(_QWORD *)(v177 + 144) = 0i64;
  *(_QWORD *)(v177 + 152) = 0i64;
  *(_QWORD *)(v177 + 160) = 0i64;
  if ( v173 )
    *(_DWORD *)(v177 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v173) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v174->mAllScreens.mTree, (UFG::qBaseNodeRB *)v177);
  v178 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenFightTutorial",
                                       0i64,
                                       1u);
  vars0 = v178;
  if ( v178 )
  {
    v178->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v178->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenFightTutorial>::`vftable;
  }
  else
  {
    v178 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "FightingTutorial", v178);
  v179 = UFG::UIScreenTextureManager::sInstance;
  v180 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v180;
  if ( v180 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v180,
      "FightingTutorial",
      0i64);
  else
    v181 = 0i64;
  *(_DWORD *)(v181 + 128) = -1;
  *(_DWORD *)(v181 + 132) = 4;
  *(_QWORD *)(v181 + 144) = 0i64;
  *(_QWORD *)(v181 + 152) = 0i64;
  *(_QWORD *)(v181 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v179->mAllScreens.mTree, (UFG::qBaseNodeRB *)v181);
  v182 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenCockFight",
                                       0i64,
                                       1u);
  vars0 = v182;
  if ( v182 )
  {
    v182->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v182->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenCockFight>::`vftable;
  }
  else
  {
    v182 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "CockFight", v182);
  v183 = UFG::UIHKScreenCockFight::gTexturePackFilename;
  v184 = UFG::UIScreenTextureManager::sInstance;
  v185 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v185;
  if ( v185 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v185,
      "CockFight",
      v183);
    v187 = v186;
  }
  else
  {
    v187 = 0i64;
  }
  *(_DWORD *)(v187 + 128) = -1;
  *(_DWORD *)(v187 + 132) = 2;
  *(_QWORD *)(v187 + 144) = 0i64;
  *(_QWORD *)(v187 + 152) = 0i64;
  *(_QWORD *)(v187 + 160) = 0i64;
  if ( v183 )
    *(_DWORD *)(v187 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v183) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v184->mAllScreens.mTree, (UFG::qBaseNodeRB *)v187);
  v188 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenGameLog",
                                       0i64,
                                       1u);
  vars0 = v188;
  if ( v188 )
  {
    v188->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v188->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenGameLog>::`vftable;
  }
  else
  {
    v188 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "GameLog", v188);
  v189 = UFG::UIHKScreenGameLog::gTexturePackFilename;
  v190 = UFG::UIScreenTextureManager::sInstance;
  v191 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v191;
  if ( v191 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v191,
      "GameLog",
      v189);
    v193 = v192;
  }
  else
  {
    v193 = 0i64;
  }
  *(_DWORD *)(v193 + 128) = -1;
  *(_DWORD *)(v193 + 132) = 0;
  *(_QWORD *)(v193 + 144) = 0i64;
  *(_QWORD *)(v193 + 152) = 0i64;
  *(_QWORD *)(v193 + 160) = 0i64;
  if ( v189 )
    *(_DWORD *)(v193 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v189) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v190->mAllScreens.mTree, (UFG::qBaseNodeRB *)v193);
  v194 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenFaceTracker",
                                       0i64,
                                       1u);
  vars0 = v194;
  if ( v194 )
  {
    v194->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v194->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenFaceTracker>::`vftable;
  }
  else
  {
    v194 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "FaceTracker", v194);
  v195 = UFG::UIHKScreenFaceTracker::gTexturePackFilename;
  v196 = UFG::UIScreenTextureManager::sInstance;
  v197 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v197;
  if ( v197 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v197,
      "FaceTracker",
      v195);
    v199 = v198;
  }
  else
  {
    v199 = 0i64;
  }
  *(_DWORD *)(v199 + 128) = -1;
  *(_DWORD *)(v199 + 132) = 0;
  *(_QWORD *)(v199 + 144) = 0i64;
  *(_QWORD *)(v199 + 152) = 0i64;
  *(_QWORD *)(v199 + 160) = 0i64;
  if ( v195 )
    *(_DWORD *)(v199 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v195) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v196->mAllScreens.mTree, (UFG::qBaseNodeRB *)v199);
  v200 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenMissionComplete",
                                       0i64,
                                       1u);
  vars0 = v200;
  if ( v200 )
  {
    v200->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v200->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenMissionComplete>::`vftable;
  }
  else
  {
    v200 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "MissionComplete", v200);
  v201 = UFG::UIScreenTextureManager::sInstance;
  v202 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v202;
  if ( v202 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v202,
      "MissionComplete",
      0i64);
  else
    v203 = 0i64;
  *(_DWORD *)(v203 + 128) = 46;
  *(_DWORD *)(v203 + 132) = 6;
  *(_QWORD *)(v203 + 144) = UFG::UIHKScreenMissionComplete::LoadTextures;
  *(_QWORD *)(v203 + 152) = UFG::UIHKScreenMissionComplete::AreTexturesLoaded;
  *(_QWORD *)(v203 + 160) = UFG::UIHKScreenMissionComplete::ReleaseTextures;
  UFG::qBaseTreeRB::Add(&v201->mAllScreens.mTree, (UFG::qBaseNodeRB *)v203);
  v204 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenUpgrades",
                                       0i64,
                                       1u);
  vars0 = v204;
  if ( v204 )
  {
    v204->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v204->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenUpgrades>::`vftable;
  }
  else
  {
    v204 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Upgrades", v204);
  v205 = UFG::UIHKScreenUpgrades::gTexturePackFilename;
  v206 = UFG::UIScreenTextureManager::sInstance;
  v207 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v207;
  if ( v207 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v207,
      "Upgrades",
      v205);
    v209 = v208;
  }
  else
  {
    v209 = 0i64;
  }
  *(_DWORD *)(v209 + 128) = 16;
  *(_DWORD *)(v209 + 132) = 18;
  *(_QWORD *)(v209 + 144) = 0i64;
  *(_QWORD *)(v209 + 152) = 0i64;
  *(_QWORD *)(v209 + 160) = 0i64;
  if ( v205 )
    *(_DWORD *)(v209 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v205) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v206->mAllScreens.mTree, (UFG::qBaseNodeRB *)v209);
  v210 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenUnlockables",
                                       0i64,
                                       1u);
  vars0 = v210;
  if ( v210 )
  {
    v210->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v210->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenUnlockables>::`vftable;
  }
  else
  {
    v210 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Unlockables", v210);
  v211 = UFG::UIHKScreenUnlockables::gTexturePackFilename;
  v212 = UFG::UIScreenTextureManager::sInstance;
  v213 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v213;
  if ( v213 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v213,
      "Unlockables",
      v211);
    v215 = v214;
  }
  else
  {
    v215 = 0i64;
  }
  *(_DWORD *)(v215 + 128) = -1;
  *(_DWORD *)(v215 + 132) = 2;
  *(_QWORD *)(v215 + 144) = 0i64;
  *(_QWORD *)(v215 + 152) = 0i64;
  *(_QWORD *)(v215 + 160) = 0i64;
  if ( v211 )
    *(_DWORD *)(v215 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v211) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v212->mAllScreens.mTree, (UFG::qBaseNodeRB *)v215);
  v216 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenOpeningCredits",
                                       0i64,
                                       1u);
  vars0 = v216;
  if ( v216 )
  {
    v216->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v216->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenOpeningCredits>::`vftable;
  }
  else
  {
    v216 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "OpeningCredits", v216);
  v217 = UFG::UIScreenTextureManager::sInstance;
  v218 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v218;
  if ( v218 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v218,
      "OpeningCredits",
      0i64);
  else
    v219 = 0i64;
  *(_DWORD *)(v219 + 128) = -1;
  *(_DWORD *)(v219 + 132) = 4;
  *(_QWORD *)(v219 + 144) = 0i64;
  *(_QWORD *)(v219 + 152) = 0i64;
  *(_QWORD *)(v219 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v217->mAllScreens.mTree, (UFG::qBaseNodeRB *)v219);
  v220 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenPCBenchmark",
                                       0i64,
                                       1u);
  vars0 = v220;
  if ( v220 )
  {
    v220->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v220->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPCBenchmark>::`vftable;
  }
  else
  {
    v220 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PCBenchmark", v220);
  v221 = UFG::UIScreenTextureManager::sInstance;
  v222 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v222;
  if ( v222 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v222,
      "PCBenchmark",
      0i64);
  else
    v223 = 0i64;
  *(_DWORD *)(v223 + 128) = -1;
  *(_DWORD *)(v223 + 132) = 2;
  *(_QWORD *)(v223 + 144) = 0i64;
  *(_QWORD *)(v223 + 152) = 0i64;
  *(_QWORD *)(v223 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v221->mAllScreens.mTree, (UFG::qBaseNodeRB *)v223);
  v224 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenPickLockMinigame",
                                       0i64,
                                       1u);
  vars0 = v224;
  if ( v224 )
  {
    v224->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v224->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPickLockMinigame>::`vftable;
  }
  else
  {
    v224 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PickLockMinigame", v224);
  v225 = UFG::UIHKScreenPickLockMinigame::gTexturePackFilename;
  v226 = UFG::UIScreenTextureManager::sInstance;
  v227 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v227;
  if ( v227 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v227,
      "PickLockMinigame",
      v225);
    v229 = v228;
  }
  else
  {
    v229 = 0i64;
  }
  *(_DWORD *)(v229 + 128) = 46;
  *(_DWORD *)(v229 + 132) = 2;
  *(_QWORD *)(v229 + 144) = 0i64;
  *(_QWORD *)(v229 + 152) = 0i64;
  *(_QWORD *)(v229 + 160) = 0i64;
  if ( v225 )
    *(_DWORD *)(v229 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v225) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v226->mAllScreens.mTree, (UFG::qBaseNodeRB *)v229);
  v230 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenBugPlantingMinigame",
                                       0i64,
                                       1u);
  vars0 = v230;
  if ( v230 )
  {
    v230->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v230->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenBugPlantingMinigame>::`vftable;
  }
  else
  {
    v230 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "BugPlantingMinigame", v230);
  v231 = UFG::UIHKScreenBugPlantingMinigame::gTexturePackFilename;
  v232 = UFG::UIScreenTextureManager::sInstance;
  v233 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v233;
  if ( v233 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v233,
      "BugPlantingMinigame",
      v231);
    v235 = v234;
  }
  else
  {
    v235 = 0i64;
  }
  *(_DWORD *)(v235 + 128) = 46;
  *(_DWORD *)(v235 + 132) = 2;
  *(_QWORD *)(v235 + 144) = 0i64;
  *(_QWORD *)(v235 + 152) = 0i64;
  *(_QWORD *)(v235 + 160) = 0i64;
  if ( v231 )
    *(_DWORD *)(v235 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v231) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v232->mAllScreens.mTree, (UFG::qBaseNodeRB *)v235);
  v236 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenPhoneTraceMinigame",
                                       0i64,
                                       1u);
  vars0 = v236;
  if ( v236 )
  {
    v236->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v236->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPhoneTraceMinigame>::`vftable;
  }
  else
  {
    v236 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PhoneTraceMinigame", v236);
  v237 = UFG::UIHKScreenPhoneTraceMinigame::gTexturePackFilename;
  v238 = UFG::UIScreenTextureManager::sInstance;
  v239 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v239;
  if ( v239 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v239,
      "PhoneTraceMinigame",
      v237);
    v241 = v240;
  }
  else
  {
    v241 = 0i64;
  }
  *(_DWORD *)(v241 + 128) = 46;
  *(_DWORD *)(v241 + 132) = 2;
  *(_QWORD *)(v241 + 144) = 0i64;
  *(_QWORD *)(v241 + 152) = 0i64;
  *(_QWORD *)(v241 + 160) = 0i64;
  if ( v237 )
    *(_DWORD *)(v241 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v237) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v238->mAllScreens.mTree, (UFG::qBaseNodeRB *)v241);
  v242 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenPhoneSignalMinigame",
                                       0i64,
                                       1u);
  vars0 = v242;
  if ( v242 )
  {
    v242->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v242->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPhoneSignalMinigame>::`vftable;
  }
  else
  {
    v242 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PhoneSignalMinigame", v242);
  v243 = UFG::UIHKScreenPhoneSignalMinigame::gTexturePackFilename;
  v244 = UFG::UIScreenTextureManager::sInstance;
  v245 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v245;
  if ( v245 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v245,
      "PhoneSignalMinigame",
      v243);
    v247 = v246;
  }
  else
  {
    v247 = 0i64;
  }
  *(_DWORD *)(v247 + 128) = -1;
  *(_DWORD *)(v247 + 132) = 4;
  *(_QWORD *)(v247 + 144) = 0i64;
  *(_QWORD *)(v247 + 152) = 0i64;
  *(_QWORD *)(v247 + 160) = 0i64;
  if ( v243 )
    *(_DWORD *)(v247 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v243) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v244->mAllScreens.mTree, (UFG::qBaseNodeRB *)v247);
  v248 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenSpyPC",
                                       0i64,
                                       1u);
  vars0 = v248;
  if ( v248 )
  {
    v248->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v248->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSpyPC>::`vftable;
  }
  else
  {
    v248 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "SpyPC", v248);
  v249 = UFG::UIHKScreenSpyPC::gTexturePackFilename;
  v250 = UFG::UIScreenTextureManager::sInstance;
  v251 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v251;
  if ( v251 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v251, "SpyPC", v249);
    v253 = v252;
  }
  else
  {
    v253 = 0i64;
  }
  *(_DWORD *)(v253 + 128) = -1;
  *(_DWORD *)(v253 + 132) = 2;
  *(_QWORD *)(v253 + 144) = 0i64;
  *(_QWORD *)(v253 + 152) = 0i64;
  *(_QWORD *)(v253 + 160) = 0i64;
  if ( v249 )
    *(_DWORD *)(v253 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v249) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v250->mAllScreens.mTree, (UFG::qBaseNodeRB *)v253);
  v254 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenSpyCam",
                                       0i64,
                                       1u);
  vars0 = v254;
  if ( v254 )
  {
    v254->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v254->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSpyCam>::`vftable;
  }
  else
  {
    v254 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "SpyCam", v254);
  v255 = UFG::UIHKScreenSpyCam::gTexturePackFilename;
  v256 = UFG::UIScreenTextureManager::sInstance;
  v257 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v257;
  if ( v257 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo((UFG::UIScreenTextureManager::ScreenInfo *)v257, "SpyCam", v255);
    v259 = v258;
  }
  else
  {
    v259 = 0i64;
  }
  *(_DWORD *)(v259 + 128) = -1;
  *(_DWORD *)(v259 + 132) = 0;
  *(_QWORD *)(v259 + 144) = 0i64;
  *(_QWORD *)(v259 + 152) = 0i64;
  *(_QWORD *)(v259 + 160) = 0i64;
  if ( v255 )
    *(_DWORD *)(v259 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v255) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v256->mAllScreens.mTree, (UFG::qBaseNodeRB *)v259);
  v260 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenKaraokeMinigame",
                                       0i64,
                                       1u);
  vars0 = v260;
  if ( v260 )
  {
    v260->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v260->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenKaraokeMinigame>::`vftable;
  }
  else
  {
    v260 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "KaraokeMinigame", v260);
  v261 = UFG::UIHKScreenKaraokeMinigame::gTexturePackFilename;
  v262 = UFG::UIScreenTextureManager::sInstance;
  v263 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v263;
  if ( v263 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v263,
      "KaraokeMinigame",
      v261);
    v265 = v264;
  }
  else
  {
    v265 = 0i64;
  }
  *(_DWORD *)(v265 + 128) = 46;
  *(_DWORD *)(v265 + 132) = 2;
  *(_QWORD *)(v265 + 144) = 0i64;
  *(_QWORD *)(v265 + 152) = 0i64;
  *(_QWORD *)(v265 + 160) = 0i64;
  if ( v261 )
    *(_DWORD *)(v265 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v261) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v262->mAllScreens.mTree, (UFG::qBaseNodeRB *)v265);
  v266 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenHackingMinigame",
                                       0i64,
                                       1u);
  vars0 = v266;
  if ( v266 )
  {
    v266->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v266->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenHackingMinigame>::`vftable;
  }
  else
  {
    v266 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "HackingMinigame", v266);
  v267 = UFG::UIHKScreenHackingMinigame::gTexturePackFilename;
  v268 = UFG::UIScreenTextureManager::sInstance;
  v269 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v269;
  if ( v269 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v269,
      "HackingMinigame",
      v267);
    v271 = v270;
  }
  else
  {
    v271 = 0i64;
  }
  *(_DWORD *)(v271 + 128) = 46;
  *(_DWORD *)(v271 + 132) = 2;
  *(_QWORD *)(v271 + 144) = 0i64;
  *(_QWORD *)(v271 + 152) = 0i64;
  *(_QWORD *)(v271 + 160) = 0i64;
  if ( v267 )
    *(_DWORD *)(v271 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v267) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v268->mAllScreens.mTree, (UFG::qBaseNodeRB *)v271);
  v272 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenPokerDiceMinigame",
                                       0i64,
                                       1u);
  vars0 = v272;
  if ( v272 )
  {
    v272->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v272->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenPokerDiceMinigame>::`vftable;
  }
  else
  {
    v272 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "PokerDiceMinigame", v272);
  v273 = UFG::UIHKScreenPokerDiceMinigame::gTexturePackFilename;
  v274 = UFG::UIScreenTextureManager::sInstance;
  v275 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v275;
  if ( v275 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v275,
      "PokerDiceMinigame",
      v273);
    v277 = v276;
  }
  else
  {
    v277 = 0i64;
  }
  *(_DWORD *)(v277 + 128) = -1;
  *(_DWORD *)(v277 + 132) = 2;
  *(_QWORD *)(v277 + 144) = 0i64;
  *(_QWORD *)(v277 + 152) = 0i64;
  *(_QWORD *)(v277 + 160) = 0i64;
  if ( v273 )
    *(_DWORD *)(v277 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v273) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v274->mAllScreens.mTree, (UFG::qBaseNodeRB *)v277);
  v278 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenSafeCrackingMinigame",
                                       0i64,
                                       1u);
  vars0 = v278;
  if ( v278 )
  {
    v278->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v278->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSafeCrackingMinigame>::`vftable;
  }
  else
  {
    v278 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "SafeCrackingMinigame", v278);
  v279 = UFG::UIHKScreenSafeCrackingMinigame::gTexturePackFilename;
  v280 = UFG::UIScreenTextureManager::sInstance;
  v281 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v281;
  if ( v281 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v281,
      "SafeCrackingMinigame",
      v279);
    v283 = v282;
  }
  else
  {
    v283 = 0i64;
  }
  *(_DWORD *)(v283 + 128) = 46;
  *(_DWORD *)(v283 + 132) = 2;
  *(_QWORD *)(v283 + 144) = 0i64;
  *(_QWORD *)(v283 + 152) = 0i64;
  *(_QWORD *)(v283 + 160) = 0i64;
  if ( v279 )
    *(_DWORD *)(v283 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v279) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v280->mAllScreens.mTree, (UFG::qBaseNodeRB *)v283);
  v284 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenDebugScreenList",
                                       0i64,
                                       1u);
  vars0 = v284;
  if ( v284 )
  {
    v284->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v284->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDebugScreenList>::`vftable;
  }
  else
  {
    v284 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DebugScreenList", v284);
  v285 = UFG::UIScreenTextureManager::sInstance;
  v286 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v286;
  if ( v286 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v286,
      "DebugScreenList",
      0i64);
  else
    v287 = 0i64;
  *(_DWORD *)(v287 + 128) = -1;
  *(_DWORD *)(v287 + 132) = 0;
  *(_QWORD *)(v287 + 144) = 0i64;
  *(_QWORD *)(v287 + 152) = 0i64;
  *(_QWORD *)(v287 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v285->mAllScreens.mTree, (UFG::qBaseNodeRB *)v287);
  v288 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenDebugNISList",
                                       0i64,
                                       1u);
  vars0 = v288;
  if ( v288 )
  {
    v288->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v288->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDebugNISList>::`vftable;
  }
  else
  {
    v288 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DebugNISList", v288);
  v289 = UFG::UIScreenTextureManager::sInstance;
  v290 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v290;
  if ( v290 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v290,
      "DebugNISList",
      0i64);
  else
    v291 = 0i64;
  *(_DWORD *)(v291 + 128) = -1;
  *(_DWORD *)(v291 + 132) = 0;
  *(_QWORD *)(v291 + 144) = 0i64;
  *(_QWORD *)(v291 + 152) = 0i64;
  *(_QWORD *)(v291 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v289->mAllScreens.mTree, (UFG::qBaseNodeRB *)v291);
  v292 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenDebugLanguageList",
                                       0i64,
                                       1u);
  vars0 = v292;
  if ( v292 )
  {
    v292->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v292->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDebugLanguageList>::`vftable;
  }
  else
  {
    v292 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DebugLanguageList", v292);
  v293 = UFG::UIScreenTextureManager::sInstance;
  v294 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v294;
  if ( v294 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v294,
      "DebugLanguageList",
      0i64);
  else
    v295 = 0i64;
  *(_DWORD *)(v295 + 128) = -1;
  *(_DWORD *)(v295 + 132) = 0;
  *(_QWORD *)(v295 + 144) = 0i64;
  *(_QWORD *)(v295 + 152) = 0i64;
  *(_QWORD *)(v295 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v293->mAllScreens.mTree, (UFG::qBaseNodeRB *)v295);
  v296 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenSandbox",
                                       0i64,
                                       1u);
  vars0 = v296;
  if ( v296 )
  {
    v296->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v296->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSandbox>::`vftable;
  }
  else
  {
    v296 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Sandbox", v296);
  v297 = UFG::UIScreenTextureManager::sInstance;
  v298 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v298;
  if ( v298 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v298,
      "Sandbox",
      0i64);
  else
    v299 = 0i64;
  *(_DWORD *)(v299 + 128) = -1;
  *(_DWORD *)(v299 + 132) = 0;
  *(_QWORD *)(v299 + 144) = 0i64;
  *(_QWORD *)(v299 + 152) = 0i64;
  *(_QWORD *)(v299 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v297->mAllScreens.mTree, (UFG::qBaseNodeRB *)v299);
  v300 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenSandbox",
                                       0i64,
                                       1u);
  vars0 = v300;
  if ( v300 )
  {
    v300->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v300->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenSandbox>::`vftable;
  }
  else
  {
    v300 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "Sandbox2", v300);
  v301 = UFG::UIScreenTextureManager::sInstance;
  v302 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v302;
  if ( v302 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v302,
      "Sandbox2",
      0i64);
  else
    v303 = 0i64;
  *(_DWORD *)(v303 + 128) = -1;
  *(_DWORD *)(v303 + 132) = 0;
  *(_QWORD *)(v303 + 144) = 0i64;
  *(_QWORD *)(v303 + 152) = 0i64;
  *(_QWORD *)(v303 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v301->mAllScreens.mTree, (UFG::qBaseNodeRB *)v303);
  v304 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenDemoClosing",
                                       0i64,
                                       1u);
  vars0 = v304;
  if ( v304 )
  {
    v304->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v304->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDemoClosing>::`vftable;
  }
  else
  {
    v304 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DemoClosing", v304);
  v305 = UFG::UIHKScreenDemoClosing::gTexturePackFilename;
  v306 = UFG::UIScreenTextureManager::sInstance;
  v307 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v307;
  if ( v307 )
  {
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v307,
      "DemoClosing",
      v305);
    v309 = v308;
  }
  else
  {
    v309 = 0i64;
  }
  *(_DWORD *)(v309 + 128) = -1;
  *(_DWORD *)(v309 + 132) = 2;
  *(_QWORD *)(v309 + 144) = 0i64;
  *(_QWORD *)(v309 + 152) = 0i64;
  *(_QWORD *)(v309 + 160) = 0i64;
  if ( v305 )
    *(_DWORD *)(v309 + 136) = (UFG::StreamFileWrapper::GetAllocationSize(v305) + 4095) & 0xFFFFF000;
  UFG::qBaseTreeRB::Add(&v306->mAllScreens.mTree, (UFG::qBaseNodeRB *)v309);
  v310 = (UFG::UIScreenFactoryBase *)UFG::qMemoryPool::Allocate(
                                       &gScaleformMemoryPool,
                                       8ui64,
                                       "UIHKScreenDemoHack_SkipGameslice",
                                       0i64,
                                       1u);
  vars0 = v310;
  if ( v310 )
  {
    v310->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
    v310->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryWrapper<UFG::UIHKScreenDemoHack_SkipGameslice>::`vftable;
  }
  else
  {
    v310 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DemoHack_SkipGameslice", v310);
  v311 = UFG::UIScreenTextureManager::sInstance;
  v312 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v312;
  if ( v312 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v312,
      "DemoHack_SkipGameslice",
      0i64);
  else
    v313 = 0i64;
  *(_DWORD *)(v313 + 128) = -1;
  *(_DWORD *)(v313 + 132) = 0;
  *(_QWORD *)(v313 + 144) = 0i64;
  *(_QWORD *)(v313 + 152) = 0i64;
  *(_QWORD *)(v313 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v311->mAllScreens.mTree, (UFG::qBaseNodeRB *)v313);
  UFG::qString::qString(&v331.name, "UI_Shared_512_256");
  *(_QWORD *)&v331.num_mrt = 1i64;
  v331.depth = 1;
  v331.array_size = 1;
  *(_DWORD *)v331.mrt_formats = -256;
  v331.target_flags = 0;
  v331.num_mips = 1;
  memset(v331.textures, 0, 85);
  *(_QWORD *)&v331.width = 0x10000000200i64;
  UFG::UIScreenTextureManager::sInstance->mSharedTargets[0] = Illusion::CreateTarget(&v331);
  UFG::qString::qString(&v317, "UI_Shared_128_128");
  v319 = 1;
  v320 = 1;
  v321 = 0i64;
  v322 = 0i64;
  v323 = 0i64;
  v324 = 0i64;
  v325 = 0i64;
  v326 = 0i64;
  v327 = 0i64;
  v328 = 0i64;
  v329 = 0;
  v330 = 0;
  v318 = 0x8000000080i64;
  LOBYTE(v321) = 0;
  UFG::UIScreenTextureManager::sInstance->mSharedTargets[1] = Illusion::CreateTarget((Illusion::CreateTargetParams *)&v317);
  v314 = UFG::UIScreenTextureManager::sInstance->mSharedTargets[0]->mTargetTexture[0];
  v314->mAlphaStateUID = -89056095;
  mOffset = v314->mTextureUser.mOffset;
  if ( mOffset )
    v316 = (Illusion::TextureUser *)((char *)&v314->mTextureUser + mOffset);
  else
    v316 = 0i64;
  Illusion::TextureUser::OnLoad(v316, v314);
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[0] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[1] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[2] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[3] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[4] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[5] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[6] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[7] = 0i64;
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[8] = 0i64;
  UFG::qString::~qString(&v317);
  UFG::qString::~qString(&v331.name);
}toryWrapper<UFG::UIHKScreenDemoHack_SkipGameslice>::`vftable;
  }
  else
  {
    v310 = 0i64;
  }
  UFG::UIScreenFactory::addScreenMapping(UFG::UIScreenTextureManager::sInstance, "DemoHack_SkipGameslice", v310);
  v311 = UFG::UIScreenTextureManager::sInstance;
  v312 = UFG::qMalloc(0xA8ui64, "UIScreenTextureManager", 0i64);
  vars0 = v312;
  if ( v312 )
    UFG::UIScreenTextureManager::ScreenInfo::ScreenInfo(
      (UFG::UIScreenTextureManager::ScreenInfo *)v312,
      "DemoHack_SkipGameslice",
      0i64);
  else
    v313 = 0i64;
  *(_DWORD *)(v313 + 128) = -1;
  *(_DWORD *)(v313 + 132) = 0;
  *(_QWORD *)(v313 + 144) = 0i64;
  *(_QWORD *)(v313 + 152) = 0i64;
  *(_QWORD *)(v313 + 160) = 0i64;
  UFG::qBaseTreeRB::Add(&v311->mAllScreens.mTree, (UFG::qBaseNodeRB *)v313);
  UFG::qString::qString(&v331.name, "UI_Shared_512_256");
  *(_QWORD *)&v331.num_mrt = 1i64;
  v331.depth = 1;
  v331.array_size = 1;
  *(_DWORD *)v331.mrt_formats = -256;
  v331.target_flags = 0;
  v331.num_mips = 1;
  memset(v331.textures, 0, 85);
  *(_QWORD *)&v331.width = 0x10000000200i64;
  UFG::UIScreenTextureManager::sInstance->mSharedTargets[0] = Illusion::CreateTarget(&v331);
  UFG::qString::qString(&v317, "UI_Shared_128_128");
  v319 = 1;
  v320 = 1;
  v321 = 0i64;
  v322 = 0i64;
  v323 = 

// File Line: 272
// RVA: 0x5C1E80
void UFG::UIScreenTextureManager::Quit(void)
{
  __int64 v0; // rbx
  __int64 v1; // rdi

  v0 = 52i64;
  v1 = 2i64;
  UFG::UIScreen::mInitCallback = 0i64;
  do
  {
    Illusion::DeleteTarget((AMD_HD3D *)(&UFG::UIScreenTextureManager::sInstance->vfptr)[v0++], 1);
    *(_QWORD *)((char *)UFG::UIScreenTextureManager::sInstance + v0 * 8 - 8) = 0i64;
    --v1;
  }
  while ( v1 );
  if ( UFG::UIScreenTextureManager::sInstance )
    UFG::UIScreenTextureManager::sInstance->vfptr->__vecDelDtor(UFG::UIScreenTextureManager::sInstance, 1i64);
  UFG::UIScreenTextureManager::sInstance = 0i64;
}

// File Line: 290
// RVA: 0x5C1910
UFG::UIScreenTextureManager *__fastcall UFG::UIScreenTextureManager::Instance()
{
  return UFG::UIScreenTextureManager::sInstance;
}

// File Line: 304
// RVA: 0x5BD940
void __fastcall UFG::UIScreenTextureManager::UIScreenTextureManager(
        UFG::UIScreenTextureManager *this,
        unsigned int texturePoolSize)
{
  UFG::UIScreenFactory::UIScreenFactory(this);
  this->vfptr = (UFG::UIScreenFactoryVtbl *)&UFG::UIScreenTextureManager::`vftable;
  this->mGameState = GameState_FE;
  this->mTexturePoolSize = texturePoolSize;
  this->mCurrentTexturePoolUsage = 0;
  this->mForceFlush = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mAllScreens.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mTextures.mTree);
  this->mQueued.mNode.mPrev = &this->mQueued.mNode;
  this->mQueued.mNode.mNext = &this->mQueued.mNode;
  this->mLoading.mNode.mPrev = &this->mLoading.mNode;
  this->mLoading.mNode.mNext = &this->mLoading.mNode;
  this->mActive.mNode.mPrev = &this->mActive.mNode;
  this->mActive.mNode.mNext = &this->mActive.mNode;
  UFG::qStringCopy(this->m_rootDir, 128, "Data/UI/Screens/", -1);
}

// File Line: 313
// RVA: 0x5BDB10
void __fastcall UFG::UIScreenTextureManager::~UIScreenTextureManager(UFG::UIScreenTextureManager *this)
{
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v2; // rax
  UFG::qBaseNodeRB **i; // r8
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v4; // rdx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mPrev; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mNext; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *j; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v8; // rdx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v9; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v10; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *k; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v12; // rdx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v13; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v14; // rax

  this->vfptr = (UFG::UIScreenFactoryVtbl *)&UFG::UIScreenTextureManager::`vftable;
  v2 = this->mQueued.mNode.mNext - 2;
  for ( i = this->mTextures.mTree.mNULL.mChild;
        v2 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)i;
        v2 = this->mQueued.mNode.mNext - 2 )
  {
    v4 = v2 + 2;
    mPrev = v2[2].mPrev;
    mNext = v2[2].mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  for ( j = this->mActive.mNode.mNext - 2;
        j != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)&this->mQueued;
        j = this->mActive.mNode.mNext - 2 )
  {
    v8 = j + 2;
    v9 = j[2].mPrev;
    v10 = j[2].mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = v8;
    v8->mNext = v8;
  }
  for ( k = this->mLoading.mNode.mNext - 2;
        k != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)&this->mTextures.mTree.mNULL.mUID;
        k = this->mLoading.mNode.mNext - 2 )
  {
    v12 = k + 2;
    v13 = k[2].mPrev;
    v14 = k[2].mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = v12;
    v12->mNext = v12;
  }
  UFG::qTreeRB<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,1>::DeleteAll(&this->mAllScreens);
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0>::~qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0>((UFG::qList<MemberMapMemberVariable,MemberMapMemberVariable,0,0> *)&this->mActive);
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0>::~qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0>((UFG::qList<MemberMapMemberVariable,MemberMapMemberVariable,0,0> *)&this->mLoading);
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0>::~qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0>((UFG::qList<MemberMapMemberVariable,MemberMapMemberVariable,0,0> *)&this->mQueued);
  UFG::qTreeRB<UFG::UIScreenTextureManager::TexturePackReference,UFG::UIScreenTextureManager::TexturePackReference,1>::DeleteAll(&this->mTextures);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mTextures);
  UFG::qTreeRB<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,1>::DeleteAll(&this->mAllScreens);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mAllScreens);
  UFG::UIScreenFactory::~UIScreenFactory(this);
}llScre

// File Line: 321
// RVA: 0x5C2030
void __fastcall UFG::UIScreenTextureManager::SetGameState(ANTLR3_INPUT_STREAM_struct *input, unsigned int newlineChar)
{
  input->newlineChar = newlineChar;
}

// File Line: 326
// RVA: 0x5BDFA0
__int64 __fastcall UFG::UIScreenTextureManager::GetGameState(UFG::UIScreenTextureManager *this)
{
  return (unsigned int)this->mGameState;
}

// File Line: 331
// RVA: 0x5C1A70
void __fastcall UFG::UIScreenTextureManager::QueueLoadAndPush(
        UFG::UIScreenTextureManager *this,
        const char *screenName,
        const char *texturePack)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *callbackParam; // rbx
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mQueued; // rsi
  int v9; // eax
  UFG::UIScreenTextureManager *v10; // rcx
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mLoading; // r14
  int v12; // ecx
  UFG::UIScreenTextureManager *v13; // rax
  UFG::qBaseNodeRB *mPrev; // rax
  unsigned int v15; // ecx
  UFG::ProgressionTracker *v16; // rax
  UFG::qSymbol *ActiveFlow; // rax
  UFG::DataStreamer::PRIORITY v18; // r8d
  UFG::qBaseNodeRB *mParent; // rax
  UFG::qBaseNodeRB *v20; // rax
  UFG::qBaseNodeRB *v21; // rcx
  UFG::qBaseNodeRB *v22; // rax

  UFG::qPrintf("QueueLoadAndPush:%s\n", screenName);
  v6 = UFG::qStringHashUpper32(screenName, -1);
  if ( v6 )
    callbackParam = UFG::qBaseTreeRB::Get(&this->mAllScreens.mTree, v6);
  else
    callbackParam = 0i64;
  p_mQueued = &this->mQueued;
  v9 = -1;
  v10 = (UFG::UIScreenTextureManager *)&this->mQueued.mNode.mNext[-2];
  if ( v10 == (UFG::UIScreenTextureManager *)this->mTextures.mTree.mNULL.mChild )
    goto LABEL_9;
  while ( 1 )
  {
    ++v9;
    if ( v10 == (UFG::UIScreenTextureManager *)callbackParam )
      break;
    v10 = (UFG::UIScreenTextureManager *)&v10->m_factoryList.mTree.mNULL.mParent[-1];
    if ( v10 == (UFG::UIScreenTextureManager *)this->mTextures.mTree.mNULL.mChild )
      goto LABEL_9;
  }
  if ( v9 == -1 )
  {
LABEL_9:
    p_mLoading = &this->mLoading;
    v12 = -1;
    v13 = (UFG::UIScreenTextureManager *)&this->mLoading.mNode.mNext[-2];
    if ( v13 == (UFG::UIScreenTextureManager *)&this->mTextures.mTree.mNULL.mUID )
      goto LABEL_14;
    while ( 1 )
    {
      ++v12;
      if ( v13 == (UFG::UIScreenTextureManager *)callbackParam )
        break;
      v13 = (UFG::UIScreenTextureManager *)&v13->m_factoryList.mTree.mNULL.mParent[-1];
      if ( v13 == (UFG::UIScreenTextureManager *)&this->mTextures.mTree.mNULL.mUID )
        goto LABEL_14;
    }
    if ( v12 == -1 )
    {
LABEL_14:
      if ( callbackParam )
      {
        if ( (this->mGameState & callbackParam[1].mNULL.mUID) != 0 )
        {
          if ( (*(_BYTE *)(&callbackParam[1].mNULL.mUID + 1) & 2) != 0
            && UFG::UIScreenTextureManager::ModalScreenInQueue(this) )
          {
            mPrev = (UFG::qBaseNodeRB *)p_mQueued->mNode.mPrev;
            mPrev->mChild[0] = &callbackParam->mNULL;
            callbackParam->mNULL.mParent = mPrev;
            callbackParam->mNULL.mChild[0] = (UFG::qBaseNodeRB *)p_mQueued;
            p_mQueued->mNode.mPrev = (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)&callbackParam->mNULL;
            return;
          }
          if ( (*(_BYTE *)(&callbackParam[1].mNULL.mUID + 1) & 0x10) != 0 )
          {
            if ( (unsigned int)UFG::qStringCompare(screenName, "Dialog_MissionFailed", -1) )
            {
              v16 = UFG::ProgressionTracker::Instance();
              ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v16);
              v15 = -1497411807;
              if ( ActiveFlow->mUID == UFG::symGhostFlow.mUID )
                v15 = 0x4AA0BCE2;
            }
            else
            {
              v15 = 1753162818;
            }
            UFG::UI::StartPauseVFX(v15);
          }
          if ( texturePack )
            UFG::UIScreenTextureManager::ScreenInfo::SetTexturePack(
              (UFG::UIScreenTextureManager::ScreenInfo *)callbackParam,
              texturePack);
          if ( HIDWORD(callbackParam[1].mNULL.mParent) )
          {
            v18 = HIGH_PRIORITY;
            if ( (*(_BYTE *)(&callbackParam[1].mNULL.mUID + 1) & 8) != 0 )
              v18 = 16385;
            UFG::UIScreenTextureManager::QueueTexturePackLoad(
              this,
              (const char *)callbackParam[1].mNULL.mChild[0],
              v18,
              (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))UFG::UIScreenTextureManager::HandleScreenTextureLoaded,
              callbackParam);
            goto LABEL_33;
          }
          mParent = callbackParam[2].mRoot.mParent;
          if ( mParent )
          {
            ((void (__fastcall *)(_QWORD, UFG::qBaseTreeRB *))mParent)(
              UFG::UIScreenTextureManager::HandleScreenTextureLoaded,
              callbackParam);
LABEL_33:
            v20 = callbackParam->mNULL.mChild[0];
            v21 = callbackParam->mNULL.mParent;
            v21->mChild[0] = v20;
            v20->mParent = v21;
            callbackParam->mNULL.mParent = &callbackParam->mNULL;
            callbackParam->mNULL.mChild[0] = &callbackParam->mNULL;
            v22 = (UFG::qBaseNodeRB *)p_mLoading->mNode.mPrev;
            v22->mChild[0] = &callbackParam->mNULL;
            callbackParam->mNULL.mParent = v22;
            callbackParam->mNULL.mChild[0] = (UFG::qBaseNodeRB *)p_mLoading;
            p_mLoading->mNode.mPrev = (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)&callbackParam->mNULL;
            return;
          }
          UFG::UIScreenTextureManager::PushScreen(this, (UFG::UIScreenTextureManager::ScreenInfo *)callbackParam);
        }
        else
        {
          UFG::qPrintf(
            "Error: UIScreenTextureManager::QueueLoadAndPush could screen %s is not valid for current game state\n",
            screenName);
        }
      }
      else
      {
        UFG::qPrintf("Error: UIScreenTextureManager::QueueLoadAndPush could not find screen %s\n", screenName);
      }
    }
  }
}

// File Line: 404
// RVA: 0x5C1920
bool __fastcall UFG::UIScreenTextureManager::IsTexturePackLoaded(
        UFG::UIScreenTextureManager *this,
        const char *textureName)
{
  unsigned int v3; // eax
  UFG::qBaseTreeRB *v4; // rax

  v3 = UFG::qStringHashUpper32(textureName, -1);
  return v3
      && (v4 = UFG::qBaseTreeRB::Get(&this->mTextures.mTree, v3)) != 0i64
      && (unsigned int)UFG::DataStreamer::GetStreamState((UFG::DataStreamer::Handle *)v4[1].mRoot.mChild) == 6;
}

// File Line: 415
// RVA: 0x5C1CA0
void __fastcall UFG::UIScreenTextureManager::QueueTexturePackLoad(
        UFG::UIScreenTextureManager *this,
        const char *textureName,
        UFG::DataStreamer::PRIORITY priority,
        UFG::qReflectInventoryBase *callback,
        UFG::qReflectInventoryBase *callbackParam)
{
  unsigned int v9; // eax
  UFG::qBaseTreeRB *v10; // rax
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v11; // rsi
  __int64 mUID; // rbp
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // ebx
  unsigned int v16; // edx
  __int64 size; // rbp
  unsigned int v18; // edi
  unsigned int capacity; // eax
  UFG::allocator::free_link *v20; // rax
  __int64 v21; // rax
  __int64 v22; // rdi

  v9 = UFG::qStringHashUpper32(textureName, -1);
  if ( v9
    && (v10 = UFG::qBaseTreeRB::Get(&this->mTextures.mTree, v9),
        (v11 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v10) != 0i64) )
  {
    ++LODWORD(v10[1].mRoot.mParent);
    mUID = v10[1].mNULL.mUID;
    v13 = mUID + 1;
    v14 = *(&v10[1].mNULL.mUID + 1);
    v15 = 1;
    if ( (int)mUID + 1 > v14 )
    {
      if ( v14 )
        v16 = 2 * v14;
      else
        v16 = 1;
      for ( ; v16 < v13; v16 *= 2 )
        ;
      if ( v16 <= 2 )
        v16 = 2;
      if ( v16 - v13 > 0x10000 )
        v16 = mUID + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v10[1].mNULL.mUID,
        v16,
        "qArray.Add");
    }
    v11[8].size = v13;
    v11[8].p[mUID] = callback;
    size = v11[9].size;
    v18 = size + 1;
    capacity = v11[9].capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v15 = 2 * capacity;
      for ( ; v15 < v18; v15 *= 2 )
        ;
      if ( v15 <= 2 )
        v15 = 2;
      if ( v15 - v18 > 0x10000 )
        v15 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v11 + 9, v15, "qArray.Add");
    }
    v11[9].size = v18;
    v11[9].p[size] = callbackParam;
  }
  else
  {
    v20 = UFG::qMalloc(0xA0ui64, "TexturePackReference", 0i64);
    if ( v20 )
    {
      UFG::UIScreenTextureManager::TexturePackReference::TexturePackReference(
        (UFG::UIScreenTextureManager::TexturePackReference *)v20,
        textureName);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    *(_DWORD *)(v22 + 72) = 1;
    UFG::DataStreamer::QueueStream(
      (UFG::DataStreamer::Handle *)(v22 + 80),
      textureName,
      DATA_UI,
      priority,
      2u,
      (void (__fastcall *)(UFG::DataStreamer::Handle *, void *))callback,
      callbackParam);
    UFG::qBaseTreeRB::Add(&this->mTextures.mTree, (UFG::qBaseNodeRB *)v22);
  }
}

// File Line: 461
// RVA: 0x5C1FF0
void __fastcall UFG::UIScreenTextureManager::ReleaseTexturePack(
        UFG::UIScreenTextureManager *this,
        const char *textureName)
{
  unsigned int v3; // eax
  UFG::qBaseTreeRB *v4; // rax
  int mParent; // ecx

  v3 = UFG::qStringHashUpper32(textureName, -1);
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->mTextures.mTree, v3);
    if ( v4 )
    {
      mParent = (int)v4[1].mRoot.mParent;
      if ( mParent )
        LODWORD(v4[1].mRoot.mParent) = mParent - 1;
    }
  }
}

// File Line: 470
// RVA: 0x5C1F00
void __fastcall UFG::UIScreenTextureManager::ReleaseScreen(UFG::UIScreenTextureManager *this, const char *screenName)
{
  unsigned int v4; // eax
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  UFG::qBaseNodeRB *mParent; // rcx
  UFG::qBaseNodeRB *v8; // rax
  unsigned int v9; // eax
  UFG::qBaseTreeRB *v10; // rax
  int v11; // ecx
  void (*v12)(void); // rax

  v4 = UFG::qStringHashUpper32(screenName, -1);
  if ( v4 && (v5 = UFG::qBaseTreeRB::Get(&this->mAllScreens.mTree, v4), (v6 = v5) != 0i64) )
  {
    if ( (*(_BYTE *)(&v5[1].mNULL.mUID + 1) & 0x10) != 0 )
      UFG::UI::StopPauseVFX(1);
    mParent = v6->mNULL.mParent;
    v8 = v6->mNULL.mChild[0];
    mParent->mChild[0] = v8;
    v8->mParent = mParent;
    v6->mNULL.mParent = &v6->mNULL;
    v6->mNULL.mChild[0] = &v6->mNULL;
    if ( HIDWORD(v6[1].mNULL.mParent) )
    {
      v9 = UFG::qStringHashUpper32((const char *)v6[1].mNULL.mChild[0], -1);
      if ( v9 )
      {
        v10 = UFG::qBaseTreeRB::Get(&this->mTextures.mTree, v9);
        if ( v10 )
        {
          v11 = (int)v10[1].mRoot.mParent;
          if ( v11 )
            LODWORD(v10[1].mRoot.mParent) = v11 - 1;
        }
      }
    }
    else
    {
      v12 = (void (*)(void))v6[2].mRoot.mChild[1];
      if ( v12 )
        v12();
    }
  }
  else
  {
    UFG::qPrintf("Error: UIScreenTextureManager::ReleaseScreen() could not find screen %s\n", screenName);
  }
}

// File Line: 497
// RVA: 0x5BDF90
void __fastcall UFG::UIScreenTextureManager::ForceFlush(UFG::UIScreenTextureManager *this)
{
  this->mForceFlush = 1;
}

// File Line: 502
// RVA: 0x5C2170
void __fastcall UFG::UIScreenTextureManager::Update(UFG::UIScreenTextureManager *this, float deltaTime)
{
  UFG::qBaseNodeRB **mChild; // r14
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v3; // rdx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mPrev; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mNext; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v7; // rdx
  unsigned int *p_mUID; // rbp
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v9; // rbx
  unsigned __int8 (*v10)(void); // rax
  int mPrev_high; // eax
  const char *v12; // rdx
  int v13; // r8d
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v14; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v15; // rax
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mActive; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v17; // rax
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mQueued; // rdi
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v19; // rbx
  char v20; // cl
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v21; // rdx
  __int64 v22; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v23; // rax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *j; // rbx
  int v25; // eax
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v26; // rdx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v27; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v28; // rax
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseTreeRB *k; // rbx
  __int64 m; // rdi
  signed int mCurrentTexturePoolUsage; // eax
  float v33; // xmm1_4
  UFG::UIScreenTextureManager::TexturePackReference *Head; // rbx
  UFG::qTreeRB<UFG::UIScreenTextureManager::TexturePackReference,UFG::UIScreenTextureManager::TexturePackReference,1> *p_mTextures; // rcx
  UFG::StreamingMemory::DATA_TYPE dataTypes; // [rsp+40h] [rbp+8h] BYREF

  mChild = this->mTextures.mTree.mNULL.mChild;
  v3 = this->mQueued.mNode.mNext - 2;
  if ( v3 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)this->mTextures.mTree.mNULL.mChild )
  {
    while ( (this->mGameState & (__int64)v3[8].mPrev) != 0 )
    {
      v3 = v3[2].mNext - 2;
      if ( v3 == (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)mChild )
        goto LABEL_6;
    }
    mPrev = v3[2].mPrev;
    mNext = v3[2].mNext;
    v7 = v3 + 2;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v7->mPrev = v7;
    v7->mNext = v7;
  }
LABEL_6:
  p_mUID = &this->mTextures.mTree.mNULL.mUID;
  v9 = this->mLoading.mNode.mNext - 2;
  if ( v9 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)&this->mTextures.mTree.mNULL.mUID )
  {
    while ( 1 )
    {
      if ( ((__int64)v9[8].mPrev & this->mGameState) == 0 )
      {
        UFG::UIScreenTextureManager::ReleaseScreen(this, (const char *)v9[4].mNext);
        goto LABEL_21;
      }
      v10 = (unsigned __int8 (*)(void))v9[9].mNext;
      if ( v10 )
      {
        if ( v10() )
          break;
      }
      v9 = v9[2].mNext - 2;
      if ( v9 == (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mUID )
        goto LABEL_21;
    }
    mPrev_high = HIDWORD(v9[8].mPrev);
    v12 = (const char *)v9[4].mNext;
    if ( (mPrev_high & 4) != 0 )
    {
      v13 = 0;
      if ( (mPrev_high & 0x20) != 0 )
        v13 = -2;
      if ( (mPrev_high & 0x40) != 0 )
        v13 = -1;
      UFG::UIScreenManagerBase::queuePushOverlay(UFG::UIScreenManager::s_instance, v12, v13, -1);
    }
    else
    {
      UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, v12, -1);
    }
    v14 = v9[2].mPrev;
    v15 = v9[2].mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v9[2].mPrev = v9 + 2;
    v9[2].mNext = v9 + 2;
    p_mActive = &UFG::UIScreenTextureManager::sInstance->mActive;
    v17 = UFG::UIScreenTextureManager::sInstance->mActive.mNode.mPrev;
    v17->mNext = v9 + 2;
    v9[2].mPrev = v17;
    v9[2].mNext = &p_mActive->mNode;
    p_mActive->mNode.mPrev = v9 + 2;
  }
LABEL_21:
  p_mQueued = &this->mQueued;
  v19 = this->mActive.mNode.mNext - 2;
  if ( v19 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)&this->mQueued )
  {
    do
    {
      if ( ((__int64)v19[8].mPrev & this->mGameState) == 0 )
      {
        if ( (BYTE4(v19[8].mPrev) & 4) != 0 )
          UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, (const char *)v19[4].mNext);
        else
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, (unsigned int)v19[1].mNext);
      }
      v19 = v19[2].mNext - 2;
    }
    while ( v19 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mQueued );
  }
  v20 = 0;
  v21 = this->mLoading.mNode.mNext - 2;
  v22 = (__int64)v21;
  if ( v21 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mUID )
  {
    while ( (*(_BYTE *)(v22 + 132) & 2) == 0 )
    {
      v22 = *(_QWORD *)(v22 + 40) - 32i64;
      if ( (unsigned int *)v22 == p_mUID )
        goto LABEL_32;
    }
    v20 = 1;
  }
LABEL_32:
  v23 = this->mActive.mNode.mNext - 2;
  if ( v23 == (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mQueued )
  {
LABEL_35:
    if ( !v20 )
    {
      v26 = this->mQueued.mNode.mNext - 2;
      if ( v26 == (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)mChild )
      {
        for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mAllScreens);
              i;
              i = UFG::qBaseTreeRB::GetNext(&this->mAllScreens.mTree, &i->mRoot) )
        {
          if ( (i[1].mNULL.mUID & this->mGameState) != 0
            && (*(_BYTE *)(&i[1].mNULL.mUID + 1) & 1) != 0
            && i->mNULL.mParent == &i->mNULL
            && i->mNULL.mChild[0] == &i->mNULL )
          {
            UFG::UIScreenTextureManager::QueueLoadAndPush(this, (const char *)i[1].mRoot.mParent, 0i64);
          }
        }
      }
      else
      {
        v27 = this->mQueued.mNode.mNext->mPrev;
        v28 = v26[2].mNext;
        v27->mNext = v28;
        v28->mPrev = v27;
        v26[2].mPrev = v26 + 2;
        v26[2].mNext = v26 + 2;
        UFG::UIScreenTextureManager::QueueLoadAndPush(this, (const char *)v26[4].mNext, 0i64);
      }
      goto LABEL_57;
    }
  }
  else
  {
    while ( (BYTE4(v23[8].mPrev) & 2) == 0 )
    {
      v23 = v23[2].mNext - 2;
      if ( v23 == (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mQueued )
        goto LABEL_35;
    }
  }
  if ( v21 != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mUID )
  {
    while ( (BYTE4(v21[8].mPrev) & 1) == 0 )
    {
      v21 = v21[2].mNext - 2;
      if ( v21 == (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mUID )
        goto LABEL_41;
    }
    UFG::UIScreenTextureManager::ReleaseScreen(this, (const char *)v21[4].mNext);
  }
LABEL_41:
  for ( j = this->mActive.mNode.mNext - 2;
        j != (UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *)p_mQueued;
        j = j[2].mNext - 2 )
  {
    v25 = HIDWORD(j[8].mPrev);
    if ( (v25 & 1) != 0 )
    {
      if ( (v25 & 4) != 0 )
        UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, (const char *)j[4].mNext);
      else
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, (unsigned int)j[1].mNext);
    }
  }
LABEL_57:
  this->mCurrentTexturePoolUsage = 0;
  for ( k = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mTextures);
        k;
        k = UFG::qBaseTreeRB::GetNext(&this->mTextures.mTree, &k->mRoot) )
  {
    this->mCurrentTexturePoolUsage += HIDWORD(k[1].mRoot.mParent);
    if ( k[1].mNULL.mUID
      && (unsigned int)UFG::DataStreamer::GetStreamState((UFG::DataStreamer::Handle *)k[1].mRoot.mChild) == 6 )
    {
      for ( m = 0i64; (unsigned int)m < k[1].mNULL.mUID; m = (unsigned int)(m + 1) )
        (*(void (__fastcall **)(UFG::qBaseNodeRB **, _QWORD))(*(_QWORD *)&k[1].mCount + 8 * m))(
          k[1].mRoot.mChild,
          *((_QWORD *)&k[2].mRoot.mChild[0]->mParent + m));
      UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>((UFG::qArray<ActiveMultiMorphTarget,0> *)&k[1].mNULL.mUID);
      UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>((UFG::qArray<ActiveMultiMorphTarget,0> *)&k[2]);
    }
  }
  mCurrentTexturePoolUsage = this->mCurrentTexturePoolUsage;
  dataTypes = DATA_UI;
  v33 = (float)mCurrentTexturePoolUsage / (float)(int)this->mTexturePoolSize;
  if ( UFG::DataStreamer::IsStalled(&dataTypes, 1u) )
    this->mForceFlush = 1;
  if ( v33 > 0.80000001 || this->mForceFlush )
  {
    while ( 1 )
    {
      Head = (UFG::UIScreenTextureManager::TexturePackReference *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mTextures);
      if ( !Head )
        break;
      while ( 1 )
      {
        p_mTextures = &this->mTextures;
        if ( !Head->mReferenceCount )
          break;
        Head = (UFG::UIScreenTextureManager::TexturePackReference *)UFG::qBaseTreeRB::GetNext(
                                                                      &p_mTextures->mTree,
                                                                      &Head->mNode);
        if ( !Head )
          goto LABEL_71;
      }
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mTextures,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head);
      UFG::UIScreenTextureManager::TexturePackReference::~TexturePackReference(Head);
      operator delete[](Head);
    }
LABEL_71:
    this->mForceFlush = 0;
  }
}

// File Line: 650
// RVA: 0x5C19E0
void __fastcall UFG::UIScreenTextureManager::PushScreen(
        UFG::UIScreenTextureManager *this,
        UFG::UIScreenTextureManager::ScreenInfo *screenInfo)
{
  unsigned int mFlags; // eax
  char *mData; // rdx
  int v5; // r8d
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mPrev; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mNext; // rax
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mActive; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v9; // rax

  mFlags = screenInfo->mFlags;
  mData = screenInfo->mScreenName.mData;
  if ( (mFlags & 4) != 0 )
  {
    v5 = 0;
    if ( (mFlags & 0x20) != 0 )
      v5 = -2;
    if ( (mFlags & 0x40) != 0 )
      v5 = -1;
    UFG::UIScreenManagerBase::queuePushOverlay(UFG::UIScreenManager::s_instance, mData, v5, -1);
  }
  else
  {
    UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, mData, -1);
  }
  mPrev = screenInfo->mPrev;
  mNext = screenInfo->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  screenInfo->mPrev = &screenInfo->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
  screenInfo->mNext = &screenInfo->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
  p_mActive = &UFG::UIScreenTextureManager::sInstance->mActive;
  v9 = UFG::UIScreenTextureManager::sInstance->mActive.mNode.mPrev;
  v9->mNext = &screenInfo->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
  screenInfo->mPrev = v9;
  screenInfo->mNext = &p_mActive->mNode;
  p_mActive->mNode.mPrev = &screenInfo->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
}

// File Line: 690
// RVA: 0x5C1970
char __fastcall UFG::UIScreenTextureManager::ModalScreenInQueue(UFG::UIScreenTextureManager *this)
{
  char v1; // r8
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mQueued; // rdx
  UFG::UIScreenTextureManager *v5; // rcx

  v1 = 0;
  v2 = (UFG::UIScreenTextureManager *)&this->mLoading.mNode.mNext[-2];
  if ( v2 != (UFG::UIScreenTextureManager *)&this->mTextures.mTree.mNULL.mUID )
  {
    while ( (v2->m_rootDir[52] & 2) == 0 )
    {
      v2 = (UFG::UIScreenTextureManager *)&v2->m_factoryList.mTree.mNULL.mParent[-1];
      if ( v2 == (UFG::UIScreenTextureManager *)&this->mTextures.mTree.mNULL.mUID )
        goto LABEL_6;
    }
    v1 = 1;
  }
LABEL_6:
  p_mQueued = &this->mQueued;
  v5 = (UFG::UIScreenTextureManager *)&this->mActive.mNode.mNext[-2];
  if ( v5 == (UFG::UIScreenTextureManager *)&this->mQueued )
    return v1;
  while ( (v5->m_rootDir[52] & 2) == 0 )
  {
    v5 = (UFG::UIScreenTextureManager *)&v5->m_factoryList.mTree.mNULL.mParent[-1];
    if ( v5 == (UFG::UIScreenTextureManager *)p_mQueued )
      return v1;
  }
  return 1;
}

// File Line: 823
// RVA: 0x5BE000
void __fastcall UFG::UIScreenTextureManager::HandleScreenTextureLoaded(
        UFG::DataStreamer::Handle *handle,
        UFG::UIScreenTextureManager::ScreenInfo *param)
{
  void (*mIsLoadedCb)(void); // rax
  unsigned int mFlags; // eax
  char *mData; // rdx
  int v6; // r8d
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mPrev; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *mNext; // rax
  UFG::qList<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo,0,0> *p_mActive; // rcx
  UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo> *v10; // rax
  UFG::UIScreenTextureManager *v11; // rdi
  unsigned int v12; // eax
  UFG::qBaseTreeRB *v13; // rax
  int mParent; // ecx

  if ( (UFG::UIScreenTextureManager::sInstance->mGameState & param->mValidStates) != 0 )
  {
    mIsLoadedCb = (void (*)(void))param->mIsLoadedCb;
    if ( mIsLoadedCb )
      mIsLoadedCb();
    if ( !param->mIsLoadedCb )
    {
      mFlags = param->mFlags;
      mData = param->mScreenName.mData;
      if ( (mFlags & 4) != 0 )
      {
        v6 = 0;
        if ( (mFlags & 0x20) != 0 )
          v6 = -2;
        if ( (mFlags & 0x40) != 0 )
          v6 = -1;
        UFG::UIScreenManagerBase::queuePushOverlay(UFG::UIScreenManager::s_instance, mData, v6, -1);
      }
      else
      {
        UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, mData, -1);
      }
      mPrev = param->mPrev;
      mNext = param->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      param->mPrev = &param->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
      param->mNext = &param->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
      p_mActive = &UFG::UIScreenTextureManager::sInstance->mActive;
      v10 = UFG::UIScreenTextureManager::sInstance->mActive.mNode.mPrev;
      v10->mNext = &param->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
      param->mPrev = v10;
      param->mNext = &p_mActive->mNode;
      p_mActive->mNode.mPrev = &param->UFG::qNode<UFG::UIScreenTextureManager::ScreenInfo,UFG::UIScreenTextureManager::ScreenInfo>;
    }
  }
  else if ( UFG::qString::operator!=(&param->mTexturePackName, 0i64) )
  {
    v11 = UFG::UIScreenTextureManager::sInstance;
    v12 = UFG::qStringHashUpper32(param->mTexturePackName.mData, -1);
    if ( v12 )
    {
      v13 = UFG::qBaseTreeRB::Get(&v11->mTextures.mTree, v12);
      if ( v13 )
      {
        mParent = (int)v13[1].mRoot.mParent;
        if ( mParent )
          LODWORD(v13[1].mRoot.mParent) = mParent - 1;
      }
    }
  }
}

// File Line: 847
// RVA: 0x5BDFF0
Illusion::Target *__fastcall UFG::UIScreenTextureManager::GetSharedTarget(
        UFG::UIScreenTextureManager *this,
        UFG::UIScreenTextureManager::SharedTargetType type)
{
  return this->mSharedTargets[type];
}

// File Line: 853
// RVA: 0x5BDFB0
UFG::qBaseTreeRB *__fastcall UFG::UIScreenTextureManager::GetScreenInfo(
        UFG::UIScreenTextureManager *this,
        const char *screenName)
{
  unsigned int v3; // eax

  v3 = UFG::qStringHashUpper32(screenName, -1);
  if ( v3 )
    return UFG::qBaseTreeRB::Get(&this->mAllScreens.mTree, v3);
  else
    return 0i64;
}

