// File Line: 129
// RVA: 0x48DF70
void __usercall UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(UFG::XMLWrapperGameSlice *this@<rcx>, SimpleXML::XMLDocument *pDocument@<rdx>, SimpleXML::XMLNode *pXMLNode@<r8>, const char *pAuthor@<r9>, float a5@<xmm0>)
{
  SimpleXML::XMLNode *v5; // r12
  SimpleXML::XMLDocument *v6; // r15
  UFG::XMLWrapperGameSlice *v7; // r14
  char *v8; // rbx
  char v9; // r13
  char v10; // si
  char v11; // di
  UFG::qBaseTreeRB *v12; // rax
  char *v13; // rax
  UFG::qBaseNodeRB *v14; // rax
  UFG::qBaseNodeRB *v15; // rbx
  SimpleXML::XMLNode *v16; // rax
  char *v17; // rbx
  unsigned int v18; // eax
  SimpleXML::XMLNode *v19; // rax
  SimpleXML::XMLNode *v20; // rax
  const char *v21; // rax
  const char *v22; // rbx
  UFG::qSymbol *v23; // rax
  SimpleXML::XMLNode *v24; // rax
  const char *v25; // rbx
  SimpleXML::XMLNode *v26; // rax
  const char *v27; // rax
  const char *v28; // rdx
  SimpleXML::XMLNode *v29; // rax
  const char *v30; // rax
  SimpleXML::XMLNode *v31; // rax
  const char *v32; // rax
  SimpleXML::XMLNode *v33; // rax
  const char *v34; // rax
  SimpleXML::XMLNode *v35; // rax
  SimpleXML::XMLNode *v36; // rax
  SimpleXML::XMLNode *v37; // rax
  const char *v38; // rax
  SimpleXML::XMLNode *v39; // rbx
  SimpleXML::XMLNode *v40; // rsi
  SimpleXML::XMLNode *v41; // r13
  const char *v42; // rax
  char v43; // al
  char *v44; // rcx
  char *v45; // rax
  char *v46; // rdi
  const char *v47; // rbx
  char *v48; // rax
  char *v49; // rax
  char *v50; // rdi
  char *v51; // rbx
  char *v52; // rax
  char *v53; // rax
  SimpleXML::XMLNode *v54; // rax
  const char *v55; // rax
  UFG::SceneSettings *v56; // rax
  SimpleXML::XMLNode *v57; // rax
  SimpleXML::XMLNode *v58; // rbx
  const char *v59; // rax
  UFG::qSymbol *v60; // rax
  SimpleXML::XMLNode *v61; // rax
  const char *v62; // rax
  SimpleXML::XMLNode *v63; // rdi
  UFG::SceneSettings *v64; // rbx
  SimpleXML::XMLNode *v65; // rdi
  UFG::SceneSettings *v66; // rbx
  SimpleXML::XMLNode *v67; // rdi
  UFG::SceneSettings *v68; // rbx
  SimpleXML::XMLNode *v69; // rdi
  UFG::SceneSettings *v70; // rbx
  SimpleXML::XMLNode *v71; // rdi
  UFG::SceneSettings *v72; // rbx
  SimpleXML::XMLNode *v73; // rdi
  UFG::SceneSettings *v74; // rbx
  SimpleXML::XMLNode *v75; // rdi
  UFG::SceneSettings *v76; // rbx
  SimpleXML::XMLNode *v77; // rdi
  UFG::SceneSettings *v78; // rbx
  SimpleXML::XMLNode *v79; // rax
  const char *v80; // rax
  SimpleXML::XMLNode *v81; // rax
  const char *v82; // rax
  SimpleXML::XMLNode *v83; // rax
  const char *v84; // rax
  SimpleXML::XMLNode *v85; // rax
  SimpleXML::XMLNode *v86; // rax
  SimpleXML::XMLNode *v87; // rax
  SimpleXML::XMLNode *v88; // rax
  SimpleXML::XMLNode *v89; // rax
  signed __int64 v90; // rcx
  SimpleXML::XMLNode *v91; // rax
  SimpleXML::XMLNode *v92; // rbx
  char v93; // di
  char v94; // si
  bool v95; // bl
  __m128i v96; // xmm0
  float v97; // xmm1_4
  UFG::GameSlice *v98; // rax
  SimpleXML::XMLNode *v99; // rax
  SimpleXML::XMLNode *v100; // rbx
  char *v101; // rdi
  float v102; // xmm7_4
  char v103; // bl
  UFG::SceneSettings *v104; // rax
  SimpleXML::XMLNode *v105; // rax
  SimpleXML::XMLNode *v106; // rbx
  char v107; // bl
  UFG::SceneSettings *v108; // rax
  SimpleXML::XMLNode *v109; // rax
  SimpleXML::XMLNode *v110; // rbx
  const char *v111; // rdi
  UFG::GameSlice *v112; // rcx
  SimpleXML::XMLNode *v113; // rax
  const char *v114; // rax
  SimpleXML::XMLNode *i; // rbx
  const char *v116; // rax
  SimpleXML::XMLNode *v117; // rax
  SimpleXML::XMLNode *v118; // rbx
  char *v119; // r13
  char *v120; // rsi
  UFG::qBaseTreeRB *v121; // rdi
  char v122; // si
  UFG::allocator::free_link *v123; // rax
  UFG::qBaseTreeRB *v124; // rax
  UFG::GameSlice *v125; // rbx
  SimpleXML::XMLNode *v126; // rdi
  char v127; // r12
  const char *v128; // rax
  UFG::SceneSettings *v129; // rax
  UFG::qArray<UFG::SceneSettings::LayerSetup,0> *v130; // rsi
  __int64 v131; // r13
  unsigned int v132; // ebx
  unsigned int v133; // edx
  unsigned int v134; // edx
  UFG::SceneSettings::LayerSetup *v135; // rax
  SimpleXML::XMLNode *v136; // rdi
  char v137; // r12
  const char *v138; // rax
  UFG::SceneSettings *v139; // rax
  UFG::qArray<UFG::SceneSettings::LayerSetup,0> *v140; // rsi
  __int64 v141; // r13
  unsigned int v142; // ebx
  unsigned int v143; // edx
  unsigned int v144; // edx
  UFG::SceneSettings::LayerSetup *v145; // rax
  SimpleXML::XMLNode *j; // r13
  const char *v147; // rsi
  char v148; // di
  char v149; // bl
  UFG::SceneSettings *v150; // rax
  SimpleXML::XMLNode *k; // r13
  const char *v152; // rsi
  char v153; // di
  char v154; // bl
  UFG::SceneSettings *v155; // rax
  SimpleXML::XMLNode *v156; // rsi
  const char *v157; // rax
  UFG::SceneSettings *v158; // rax
  UFG::qArray<UFG::SceneSettings::VendorSetup,0> *v159; // rdi
  __int64 v160; // r13
  unsigned int v161; // ebx
  unsigned int v162; // edx
  unsigned int v163; // edx
  UFG::SceneSettings::VendorSetup *v164; // rax
  SimpleXML::XMLNode *v165; // rsi
  const char *v166; // rax
  UFG::SceneSettings *v167; // rax
  UFG::qArray<UFG::SceneSettings::VendorSetup,0> *v168; // rdi
  __int64 v169; // r13
  unsigned int v170; // ebx
  unsigned int v171; // edx
  unsigned int v172; // edx
  UFG::SceneSettings::VendorSetup *v173; // rax
  SimpleXML::XMLNode *v174; // rdi
  const char *v175; // rax
  UFG::SceneSettings *v176; // rax
  UFG::qArray<UFG::SceneSettings::DisguiseSetup,0> *v177; // rsi
  __int64 v178; // r13
  unsigned int v179; // ebx
  unsigned int v180; // edx
  unsigned int v181; // edx
  UFG::SceneSettings::DisguiseSetup *v182; // rax
  SimpleXML::XMLNode *l; // rsi
  char v184; // di
  char v185; // bl
  UFG::SceneSettings *v186; // rax
  SimpleXML::XMLNode *m; // rsi
  const char *v188; // rdi
  unsigned int v189; // ebx
  UFG::SceneSettings *v190; // rax
  SimpleXML::XMLNode *n; // rsi
  const char *v192; // rdi
  unsigned int v193; // ebx
  UFG::SceneSettings *v194; // rax
  SimpleXML::XMLNode *ii; // rsi
  const char *v196; // rdi
  unsigned int v197; // ebx
  UFG::SceneSettings *v198; // rax
  SimpleXML::XMLNode *jj; // rsi
  const char *v200; // rdi
  unsigned int v201; // ebx
  UFG::SceneSettings *v202; // rax
  SimpleXML::XMLNode *kk; // rdi
  const char *v204; // rbx
  UFG::GameSlice *v205; // rbx
  char v206; // al
  SimpleXML::XMLNode *ll; // rdi
  const char *v208; // rbx
  SimpleXML::XMLNode *v209; // rax
  int v210; // ecx
  SimpleXML::XMLNode *v211; // rax
  SimpleXML::XMLNode *v212; // rax
  const char *v213; // rbx
  UFG::qSymbol v214; // [rsp+8h] [rbp-79h]
  int timeInSeconds[2]; // [rsp+10h] [rbp-71h]
  UFG::qSymbol result; // [rsp+18h] [rbp-69h]
  UFG::qString weather; // [rsp+20h] [rbp-61h]
  char *v218; // [rsp+48h] [rbp-39h]
  __int64 v219; // [rsp+50h] [rbp-31h]
  char v220; // [rsp+EDh] [rbp+6Ch]
  SimpleXML::XMLNode *v221; // [rsp+F8h] [rbp+77h]

  v219 = -2i64;
  v5 = pXMLNode;
  v6 = pDocument;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&this->mPrev;
  this->mpGameSlice = 0i64;
  v8 = SimpleXML::XMLNode::GetAttribute(pXMLNode, "name");
  v218 = v8;
  UFG::qSymbol::create_from_string(&result, v8);
  v9 = SimpleXML::XMLNode::GetAttribute(v5, "checkpoint", 0);
  v10 = SimpleXML::XMLNode::GetAttribute(v5, "internal", 0);
  v11 = SimpleXML::XMLNode::GetAttribute(v5, "statsid", 0);
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( !result.mUID )
    goto LABEL_307;
  v12 = UFG::qBaseTreeRB::Get(&stru_14240A190, result.mUID);
  if ( v12 )
    goto LABEL_10;
  if ( !result.mUID )
    goto LABEL_307;
  v12 = UFG::qBaseTreeRB::Get(&stru_14240A100, result.mUID);
  if ( v12 )
    goto LABEL_10;
  if ( result.mUID )
    v12 = UFG::qBaseTreeRB::Get(&stru_14240A148, result.mUID);
  else
LABEL_307:
    v12 = 0i64;
LABEL_10:
  v7->mpGameSlice = (UFG::GameSlice *)v12;
  if ( v12 )
  {
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Binding to an existing slice: %s\n");
  }
  else
  {
    UFG::qString::qString(&weather, v8);
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v13 = (char *)UFG::qMalloc(0x240ui64, "GameSlice", 0i64);
    weather.mData = v13;
    if ( v13 )
    {
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v13, weather.mData);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, v15);
    unk_14240B986 = 1;
    v7->mpGameSlice = (UFG::GameSlice *)v15;
    UFG::qString::~qString(&weather);
  }
  v7->mpGameSlice->mStatsId = v11;
  v16 = SimpleXML::XMLDocument::GetChildNode(v6, "title", v5);
  if ( v16 )
  {
    v17 = (char *)SimpleXML::XMLNode::GetValue(v16);
    UFG::qString::qString(&weather, v17);
    UFG::qSharedString::operator=(&v7->mpGameSlice->mTitle, weather.mData);
    UFG::qString::~qString(&weather);
    weather.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v17;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Slice: %s, Title: %s\n");
  }
  else
  {
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Slice: %s\n");
  }
  UFG::XMLWrapperGameSlice::CollectWorkStatus(v7, v6, v5);
  if ( v9 )
    v7->mpGameSlice->mCheckpointSlice = 1;
  if ( v10 )
    v7->mpGameSlice->mInternalSlice = 1;
  v18 = SimpleXML::XMLNode::GetAttribute(v5, "repeatableinterval", 0);
  if ( v18 )
    v7->mpGameSlice->mRepeatableInterval = 1000 * v18;
  if ( SimpleXML::XMLNode::GetAttribute(v5, "holdcurtain", 0) )
    v7->mpGameSlice->mHoldCurtain = 1;
  v19 = SimpleXML::XMLDocument::GetChildNode(v6, "minpiplevel", v5);
  if ( v19 )
    v7->mpGameSlice->mMinPipLevel = SimpleXML::XMLNode::GetValue(v19, 0);
  v20 = SimpleXML::XMLDocument::GetChildNode(v6, "faceactiontype", v5);
  if ( v20 )
  {
    v21 = SimpleXML::XMLNode::GetValue(v20);
    v22 = v21;
    if ( v21 )
    {
      UFG::qPrintf(" Face Action Type: %s\n", v21);
      v23 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v22);
      v7->mpGameSlice->mFaceActionType = UFG::FaceActionComponent::LookupFaceAction(v23);
    }
  }
  v24 = SimpleXML::XMLDocument::GetChildNode(v6, "scriptclass", v5);
  if ( v24 )
  {
    v25 = SimpleXML::XMLNode::GetValue(v24);
    UFG::qString::qString(&weather, v25);
    UFG::qSharedString::operator=(&v7->mpGameSlice->mScriptClassName, weather.mData);
    UFG::qString::~qString(&weather);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    ScriptClass: %s\n");
  }
  v26 = SimpleXML::XMLDocument::GetChildNode(v6, "layeroverride", v5);
  if ( v26 && (v27 = SimpleXML::XMLNode::GetValue(v26)) != 0i64 && *v27 )
    v28 = v27;
  else
    v28 = v7->mpGameSlice->mScriptClassName.mText;
  v7->mpGameSlice->mLayerName = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v28)->mUID;
  v29 = SimpleXML::XMLDocument::GetChildNode(v6, "audiooverride", v5);
  if ( v29 )
  {
    v30 = SimpleXML::XMLNode::GetValue(v29);
    if ( v30 )
    {
      if ( *v30 )
      {
        UFG::qString::qString(&weather, v30);
        UFG::qSharedString::operator=(&v7->mpGameSlice->mAudioOverride, weather.mData);
        UFG::qString::~qString(&weather);
      }
    }
  }
  v31 = SimpleXML::XMLDocument::GetChildNode(v6, "saveoverride", v5);
  if ( v31 )
  {
    v32 = SimpleXML::XMLNode::GetValue(v31);
    if ( v32 )
    {
      if ( *v32 )
        v7->mpGameSlice->mSaveGamesliceOverrideName = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                                      (UFG::qSymbol *)&weather.mData,
                                                                      v32)->mUID;
    }
  }
  v33 = SimpleXML::XMLDocument::GetChildNode(v6, "savegamenameoverride", v5);
  if ( v33 )
  {
    v34 = SimpleXML::XMLNode::GetValue(v33);
    if ( v34 )
    {
      if ( *v34 )
        UFG::qSharedString::operator=(&v7->mpGameSlice->mSaveGameNameOverride, v34);
    }
  }
  v35 = SimpleXML::XMLDocument::GetChildNode(v6, "autosave", v5);
  if ( v35 )
    v7->mpGameSlice->mAutosave = SimpleXML::XMLNode::GetBool(v35, 1);
  v36 = SimpleXML::XMLDocument::GetChildNode(v6, "allowuicancellation", v5);
  if ( v36 )
    v7->mpGameSlice->mAllowUICancellation = SimpleXML::XMLNode::GetBool(v36, 1);
  v37 = SimpleXML::XMLDocument::GetChildNode(v6, "dlcproductid", v5);
  if ( v37 )
  {
    v38 = SimpleXML::XMLNode::GetValue(v37);
    if ( v38 )
    {
      if ( *v38 )
        v7->mpGameSlice->mDLCProductId = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                         (UFG::qSymbol *)&weather.mData,
                                                         v38)->mUID;
    }
  }
  v39 = SimpleXML::XMLDocument::GetChildNode(v6, "triggerobject", v5);
  v40 = SimpleXML::XMLDocument::GetChildNode(v6, "pdatrigger", v5);
  v41 = SimpleXML::XMLDocument::GetChildNode(v6, "incomingpdatrigger", v5);
  if ( v39 )
  {
    v42 = SimpleXML::XMLNode::GetValue(v39);
    v7->mpGameSlice->mTriggerObjectName = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                          (UFG::qSymbol *)&weather.mData,
                                                          v42)->mUID;
    v43 = SimpleXML::XMLNode::GetAttribute(v39, "keepobjectiveenabled", 0);
    if ( v43 )
      v7->mpGameSlice->mKeepTriggerObjectiveEnabled = v43;
    v44 = &customWorldMapCaption;
    if ( v43 )
      v44 = "[KeepObjective]";
    weather.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v44;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    TriggerObject: %s%s\n");
  }
  if ( v40 )
  {
    v45 = (char *)UFG::qMalloc(0x60ui64, "PDATriggerParameters", 0i64);
    v46 = v45;
    weather.mData = v45;
    if ( v45 )
    {
      UFG::qString::qString((UFG::qString *)v45);
      *((_QWORD *)v46 + 5) = -1i64;
      UFG::qString::qString((UFG::qString *)(v46 + 48));
      v46[88] = 0;
    }
    else
    {
      v46 = 0i64;
    }
    v47 = SimpleXML::XMLNode::GetValue(v40);
    *((UFG::qSymbol *)v46 + 10) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v47)->mUID;
    UFG::qString::Set((UFG::qString *)v46, v47);
    v48 = SimpleXML::XMLNode::GetAttribute(v40, "objective", &customWorldMapCaption);
    if ( *v48 )
      UFG::qString::Set((UFG::qString *)(v46 + 48), v48);
    v7->mpGameSlice->mPDATriggerParameters = (UFG::PDATriggerParameters *)v46;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v46 + 10);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    PDATrigger: %s\n");
  }
  if ( v41 )
  {
    v49 = (char *)UFG::qMalloc(0x60ui64, "PDATriggerParameters", 0i64);
    v50 = v49;
    weather.mData = v49;
    if ( v49 )
    {
      UFG::qString::qString((UFG::qString *)v49);
      *((_QWORD *)v50 + 5) = -1i64;
      UFG::qString::qString((UFG::qString *)(v50 + 48));
      v50[88] = 0;
    }
    else
    {
      v50 = 0i64;
    }
    v50[88] = 1;
    v51 = SimpleXML::XMLNode::GetAttribute(v41, "contactname", &customWorldMapCaption);
    *((UFG::qSymbol *)v50 + 10) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v51)->mUID;
    UFG::qString::Set((UFG::qString *)v50, v51);
    v52 = SimpleXML::XMLNode::GetAttribute(v41, "vehiclefilter", &customWorldMapCaption);
    if ( v52 && *v52 )
      *((UFG::qSymbol *)v50 + 11) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v52)->mUID;
    v53 = SimpleXML::XMLNode::GetAttribute(v41, "triggerobject", &customWorldMapCaption);
    v7->mpGameSlice->mTriggerObjectName = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                          (UFG::qSymbol *)&weather.mData,
                                                          v53)->mUID;
    v7->mpGameSlice->mPDATriggerParameters = (UFG::PDATriggerParameters *)v50;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v50 + 10);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    IncomingPDATrigger: %s\n");
  }
  v54 = SimpleXML::XMLDocument::GetChildNode(v6, "teleportlocationmarker", v5);
  if ( v54 )
  {
    v55 = SimpleXML::XMLNode::GetValue(v54);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v55);
    v56 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v56->mTeleportMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Teleport location marker: %s\n");
  }
  v57 = SimpleXML::XMLDocument::GetChildNode(v6, "vehicleteleportlocationmarker", v5);
  v58 = v57;
  if ( v57 )
  {
    v59 = SimpleXML::XMLNode::GetValue(v57);
    if ( v59 )
    {
      UFG::qSymbol::create_from_string(&v214, v59);
      SimpleXML::XMLNode::GetAttribute(v58, "range", -1.0);
      v60 = (UFG::qSymbol *)UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      if ( a5 < 0.0 )
      {
        v60[29].mUID = v214.mUID;
        v60[16].mUID = 1106247680;
      }
      else
      {
        v60[29].mUID = v214.mUID;
        *(float *)&v60[16].mUID = a5;
      }
    }
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Vehicle Teleport location marker: %s\n");
  }
  v61 = SimpleXML::XMLDocument::GetChildNode(v6, "restorelocationmarker", v5);
  if ( v61 )
  {
    v62 = SimpleXML::XMLNode::GetValue(v61);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v62);
    v7->mpGameSlice->mRestoreLocationMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Restore location marker: %s\n");
  }
  if ( SimpleXML::XMLDocument::GetChildNode(v6, "disablecopscoring", v5) )
    v7->mpGameSlice->mDisableCopScoring = 1;
  if ( SimpleXML::XMLDocument::GetChildNode(v6, "disabletriadscoring", v5) )
    v7->mpGameSlice->mDisableTriadScoring = 1;
  v63 = SimpleXML::XMLDocument::GetChildNode(v6, "lockambientpedsonstart", v5);
  if ( v63 )
  {
    v64 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v64->mLockPedsOnStart = SimpleXML::XMLNode::GetBool(v63, 0);
  }
  v65 = SimpleXML::XMLDocument::GetChildNode(v6, "unlockambientpedsonend", v5);
  if ( v65 )
  {
    v66 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v66->mUnLockPedsOnEnd = SimpleXML::XMLNode::GetBool(v65, 0);
  }
  v67 = SimpleXML::XMLDocument::GetChildNode(v6, "enableambientpedsonstart", v5);
  if ( v67 )
  {
    v68 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v68->mEnableAmbientPedsOnStart = SimpleXML::XMLNode::GetBool(v67, 1);
  }
  v69 = SimpleXML::XMLDocument::GetChildNode(v6, "enableambientpedsonend", v5);
  if ( v69 )
  {
    v70 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v70->mEnableAmbientPedsOnEnd = SimpleXML::XMLNode::GetBool(v69, 1);
  }
  v71 = SimpleXML::XMLDocument::GetChildNode(v6, "locktrafficonstart", v5);
  if ( v71 )
  {
    v72 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v72->mLockTrafficOnStart = SimpleXML::XMLNode::GetBool(v71, 0);
  }
  v73 = SimpleXML::XMLDocument::GetChildNode(v6, "unlocktrafficonend", v5);
  if ( v73 )
  {
    v74 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v74->mUnLockTrafficOnEnd = SimpleXML::XMLNode::GetBool(v73, 0);
  }
  v75 = SimpleXML::XMLDocument::GetChildNode(v6, "enabletrafficonstart", v5);
  if ( v75 )
  {
    v76 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v76->mEnableTrafficOnStart = SimpleXML::XMLNode::GetBool(v75, 1);
  }
  v77 = SimpleXML::XMLDocument::GetChildNode(v6, "enabletrafficonend", v5);
  if ( v77 )
  {
    v78 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    v78->mEnableTrafficOnEnd = SimpleXML::XMLNode::GetBool(v77, 1);
  }
  v79 = SimpleXML::XMLDocument::GetChildNode(v6, "cancellocationmarker", v5);
  if ( v79 )
  {
    v80 = SimpleXML::XMLNode::GetValue(v79);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v80);
    v7->mpGameSlice->mCancelLocationMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Cancel location marker: %s\n");
  }
  v81 = SimpleXML::XMLDocument::GetChildNode(v6, "completelocationmarker", v5);
  if ( v81 )
  {
    v82 = SimpleXML::XMLNode::GetValue(v81);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v82);
    v7->mpGameSlice->mCompleteLocationMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Complete location marker: %s\n");
  }
  v83 = SimpleXML::XMLDocument::GetChildNode(v6, "subsetmode", v5);
  if ( v83 )
  {
    v84 = SimpleXML::XMLNode::GetValue(v83);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v84);
    v7->mpGameSlice->mSubsetModeType.mUID = (unsigned int)weather.mData;
  }
  v85 = SimpleXML::XMLDocument::GetChildNode(v6, "vehiclesuperstop", v5);
  if ( v85 )
    v7->mpGameSlice->mVehicleSuperStop = SimpleXML::XMLNode::GetBool(v85, 0);
  v86 = SimpleXML::XMLDocument::GetChildNode(v6, "ignoresafehouserestore", v5);
  if ( v86 )
    v7->mpGameSlice->mIgnoreSafehouseRestore = SimpleXML::XMLNode::GetBool(v86, 1);
  v87 = SimpleXML::XMLDocument::GetChildNode(v6, "deferredregionstart", v5);
  if ( v87 )
    v7->mpGameSlice->mDeferStartIfInsideRegion = SimpleXML::XMLNode::GetBool(v87, 0);
  v88 = SimpleXML::XMLDocument::GetChildNode(v6, "deferredregionrestart", v5);
  if ( v88 )
    v7->mpGameSlice->mDeferRestartIfInsideRegion = SimpleXML::XMLNode::GetBool(v88, 1);
  v89 = SimpleXML::XMLDocument::GetChildNode(v6, "failtimeout", v5);
  if ( v89 )
  {
    SimpleXML::XMLNode::GetValue(v89, -1.0);
    if ( a5 >= 0.0 )
    {
      a5 = a5 * 1000.0;
      v90 = 0i64;
      if ( a5 >= 9.223372e18 )
      {
        a5 = a5 - 9.223372e18;
        if ( a5 < 9.223372e18 )
          v90 = 0x8000000000000000i64;
      }
      v7->mpGameSlice->mFailTimeout = v90 + (unsigned int)(signed int)a5;
    }
  }
  v91 = SimpleXML::XMLDocument::GetChildNode(v6, "timeofday", v5);
  v92 = v91;
  if ( v91 )
  {
    SimpleXML::XMLNode::GetAttribute(v91, "restore", -1.0);
    SimpleXML::XMLNode::GetAttribute(v92, "active", -1.0);
    SimpleXML::XMLNode::GetAttribute(v92, "inactive", -1.0);
    v93 = SimpleXML::XMLNode::GetAttribute(v92, "bypassprompt", 0);
    v94 = SimpleXML::XMLNode::GetAttribute(v92, "performtimeshift", 1);
    LODWORD(weather.mData) = 0;
    v95 = UFG::TimeOfDayManager::GetTimeInSeconds(a5, (int *)&v214) == 0 && a5 <= 0.0;
    if ( UFG::TimeOfDayManager::GetTimeInSeconds(a5, (int *)&weather.mData) != 0 || !v95 )
    {
      if ( UFG::TimeOfDayManager::GetTimeInSeconds(a5, timeInSeconds) )
        v96 = _mm_cvtsi32_si128(timeInSeconds[0]);
      else
        v96 = _mm_cvtsi32_si128(v214.mUID);
      LODWORD(v7->mpGameSlice->mTODRestore) = (unsigned __int128)_mm_cvtepi32_ps(v96);
      v97 = (float)SLODWORD(weather.mData);
      a5 = (float)(signed int)v214.mUID;
      v98 = v7->mpGameSlice;
      v98->mIsTODRestricted = 1;
      v98->mTODActive = a5;
      v98->mTODInactive = v97;
      v98->mTODBypassPrompt = v93;
      v98->mPerformTimeShift = v94;
    }
  }
  v99 = SimpleXML::XMLDocument::GetChildNode(v6, "forceweather", v5);
  v100 = v99;
  if ( v99 )
  {
    v101 = SimpleXML::XMLNode::GetAttribute(v99, "type", "notset");
    SimpleXML::XMLNode::GetAttribute(v100, "wetness", -1.0);
    v102 = a5;
    v103 = SimpleXML::XMLNode::GetAttribute(v100, "locked", 0);
    UFG::qString::qString(&weather, v101);
    a5 = UFG::TimeOfDayManager::GetWeatherIntensityFromString(&weather);
    if ( a5 >= 0.0 )
    {
      v104 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      v104->mWeatherOverrideIntensity = a5;
      v104->mWeatherOverrideWetness = v102;
      v104->mWeatherOverrideLock = v103;
      v104->mWeatherOverrideLockSet = 1;
    }
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Weather: %s\n");
    UFG::qString::~qString(&weather);
  }
  v105 = SimpleXML::XMLDocument::GetChildNode(v6, "forcetime", v5);
  v106 = v105;
  if ( v105 )
  {
    SimpleXML::XMLNode::GetAttribute(v105, "time", -1.0);
    v107 = SimpleXML::XMLNode::GetAttribute(v106, "locked", 0);
    if ( a5 >= 0.0 )
    {
      LODWORD(weather.mData) = 0;
      if ( UFG::TimeOfDayManager::GetTimeInSeconds(a5, (int *)&weather.mData) )
      {
        v108 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
        a5 = (float)SLODWORD(weather.mData);
        v108->mTimeOverrideInSeconds = (float)SLODWORD(weather.mData);
        v108->mTimeOverrideLock = v107;
        v108->mTimeOverrideLockSet = 1;
      }
    }
  }
  v109 = SimpleXML::XMLDocument::GetChildNode(v6, "vehiclerestore", v5);
  v110 = v109;
  if ( v109 )
  {
    v111 = SimpleXML::XMLNode::GetValue(v109);
    SimpleXML::XMLNode::GetAttribute(v110, "range", -1.0);
    if ( v111 )
    {
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v111);
      v112 = v7->mpGameSlice;
      v112->mVehicleMarker.mUID = (unsigned int)weather.mData;
      if ( a5 <= 0.0 )
        v112->mVehicleMarkerRange = 30.0;
      else
        v112->mVehicleMarkerRange = a5;
    }
  }
  v113 = SimpleXML::XMLDocument::GetChildNode(v6, "weaponrestore", v5);
  if ( v113 )
  {
    v114 = SimpleXML::XMLNode::GetValue(v113);
    if ( v114 )
    {
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v114);
      v7->mpGameSlice->mRestoreWeapon.mUID = (unsigned int)weather.mData;
    }
  }
  for ( i = SimpleXML::XMLDocument::GetChildNode(v6, "restartcompletedslice", v5);
        i;
        i = SimpleXML::XMLDocument::GetNode(v6, "restartcompletedslice", i) )
  {
    v116 = SimpleXML::XMLNode::GetValue(i);
    UFG::qString::qString(&weather, v116);
    UFG::GameSlice::AddReEnableSlice(v7->mpGameSlice, &weather);
    UFG::qString::~qString(&weather);
  }
  v117 = SimpleXML::XMLDocument::GetChildNode(v6, "nis", v5);
  v118 = v117;
  if ( v117 )
  {
    v119 = SimpleXML::XMLNode::GetAttribute(v117, "path");
    v120 = SimpleXML::XMLNode::GetAttribute(v118, "scenesettings", &customWorldMapCaption);
    LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v118, "autofadein", 1);
    BYTE2(weather.mMagic) = 0;
    v121 = 0i64;
    if ( !strcmp(v120, "Settings_Intermediate_Nis") )
    {
      BYTE2(weather.mMagic) = 1;
      v122 = 0;
    }
    else
    {
      if ( *v120 )
      {
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v120);
        if ( !(_S19_1 & 1) )
        {
          _S19_1 |= 1u;
          UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
          atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
        }
        UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
        if ( LODWORD(weather.mData) )
          v121 = UFG::qBaseTreeRB::Get(&stru_14240A220, (unsigned int)weather.mData);
        else
          v121 = 0i64;
        if ( !v121 )
        {
          UFG::qString::qString(&weather, v120);
          if ( !(_S19_1 & 1) )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          v123 = UFG::qMalloc(0x148ui64, "SceneSettings", 0i64);
          *(_QWORD *)timeInSeconds = v123;
          if ( v123 )
          {
            UFG::SceneSettings::SceneSettings((UFG::SceneSettings *)v123, weather.mData);
            v121 = v124;
          }
          else
          {
            v121 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&stru_14240A220, &v121->mRoot);
          UFG::qString::~qString(&weather);
        }
      }
      v122 = weather.mMagic;
    }
    if ( v119 )
    {
      v125 = v7->mpGameSlice;
      UFG::qSharedString::operator=(&v125->mNisPath, v119);
      v125->mNisSceneSettings = (UFG::SceneSettings *)v121;
      v125->mNisIntermediate = BYTE2(weather.mMagic);
      v125->mNisPostFadeIn = v122;
      if ( v121 )
      {
        if ( v7->mpGameSlice->mSceneSettings )
          UFG::qPrintf(
            "WARNING: Settings such as weather, time and teleport location will conflict with the nis settings and cause "
            "longer loading times for %s!\n",
            v218);
      }
    }
  }
  v126 = SimpleXML::XMLDocument::GetChildNode(v6, "scenelayeronstart", v5);
  if ( v126 )
  {
    v127 = v220;
    do
    {
      v128 = SimpleXML::XMLNode::GetValue(v126);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v128);
      BYTE2(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v126, "geoautoactivate") != 0i64;
      LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v126, "geoautoactivate", 0);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v126, "activate", 0);
      v129 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      timeInSeconds[0] = (int)weather.mData;
      v130 = &v129->mLayerSetupOnStart;
      v131 = v129->mLayerSetupOnStart.size;
      v132 = v131 + 1;
      v133 = v129->mLayerSetupOnStart.capacity;
      if ( (signed int)v131 + 1 > v133 )
      {
        if ( v133 )
          v134 = 2 * v133;
        else
          v134 = 1;
        for ( ; v134 < v132; v134 *= 2 )
          ;
        if ( v134 <= 2 )
          v134 = 2;
        if ( v134 - v132 > 0x10000 )
          v134 = v131 + 65537;
        UFG::qArray<UFG::SceneSettings::LayerSetup,0>::Reallocate(v130, v134, "SceneSettings::AddLayerSetupOnStart");
      }
      v130->size = v132;
      v135 = v130->p;
      v135[v131].mLayerName.mUID = timeInSeconds[0];
      v135[v131].mGeoSettingsPresent = BYTE2(weather.mMagic);
      v135[v131].mEnable = v127;
      *(_WORD *)&v135[v131].mGeoAutoActivate = weather.mMagic;
      v126 = SimpleXML::XMLDocument::GetNode(v6, "scenelayeronstart", v126);
    }
    while ( v126 );
    v5 = v221;
  }
  v136 = SimpleXML::XMLDocument::GetChildNode(v6, "scenelayeronend", v5);
  if ( v136 )
  {
    v137 = v220;
    do
    {
      v138 = SimpleXML::XMLNode::GetValue(v136);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v138);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v136, "geoautoactivate") != 0i64;
      BYTE2(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v136, "geoautoactivate", 0);
      LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v136, "activate", 0);
      v139 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      timeInSeconds[0] = (int)weather.mData;
      v140 = &v139->mLayerSetupOnEnd;
      v141 = v139->mLayerSetupOnEnd.size;
      v142 = v141 + 1;
      v143 = v139->mLayerSetupOnEnd.capacity;
      if ( (signed int)v141 + 1 > v143 )
      {
        if ( v143 )
          v144 = 2 * v143;
        else
          v144 = 1;
        for ( ; v144 < v142; v144 *= 2 )
          ;
        if ( v144 <= 2 )
          v144 = 2;
        if ( v144 - v142 > 0x10000 )
          v144 = v141 + 65537;
        UFG::qArray<UFG::SceneSettings::LayerSetup,0>::Reallocate(v140, v144, "SceneSettings::AddLayerSetupOnEnd");
      }
      v140->size = v142;
      v145 = v140->p;
      v145[v141].mLayerName.mUID = timeInSeconds[0];
      v145[v141].mGeoSettingsPresent = BYTE1(weather.mMagic);
      v145[v141].mEnable = v137;
      v145[v141].mGeoAutoActivate = BYTE2(weather.mMagic);
      v145[v141].mActivate = weather.mMagic;
      v136 = SimpleXML::XMLDocument::GetNode(v6, "scenelayeronend", v136);
    }
    while ( v136 );
    v5 = v221;
  }
  for ( j = SimpleXML::XMLDocument::GetChildNode(v6, "altlayeronstart", v5);
        j;
        j = SimpleXML::XMLDocument::GetNode(v6, "altlayeronstart", j) )
  {
    v147 = SimpleXML::XMLNode::GetValue(j);
    v148 = SimpleXML::XMLNode::GetAttribute(j, "flush", 0);
    v149 = SimpleXML::XMLNode::GetAttribute(j, "activate", 0);
    v150 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddAltLayerSetupOnStart(v150, v147, v149, v148);
  }
  for ( k = SimpleXML::XMLDocument::GetChildNode(v6, "altlayeronend", v5);
        k;
        k = SimpleXML::XMLDocument::GetNode(v6, "altlayeronend", k) )
  {
    v152 = SimpleXML::XMLNode::GetValue(k);
    v153 = SimpleXML::XMLNode::GetAttribute(k, "flush", 0);
    v154 = SimpleXML::XMLNode::GetAttribute(k, "activate", 0);
    v155 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddAltLayerSetupOnEnd(v155, v152, v154, v153);
  }
  v156 = SimpleXML::XMLDocument::GetChildNode(v6, "vendorenableonstart", v5);
  if ( v156 )
  {
    do
    {
      v157 = SimpleXML::XMLNode::GetValue(v156);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v157);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v156, "enable", 0);
      v158 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      timeInSeconds[0] = (int)weather.mData;
      v159 = &v158->mVendorSetupOnStart;
      v160 = v158->mVendorSetupOnStart.size;
      v161 = v160 + 1;
      v162 = v158->mVendorSetupOnStart.capacity;
      if ( (signed int)v160 + 1 > v162 )
      {
        if ( v162 )
          v163 = 2 * v162;
        else
          v163 = 1;
        for ( ; v163 < v161; v163 *= 2 )
          ;
        if ( v163 <= 2 )
          v163 = 2;
        if ( v163 - v161 > 0x10000 )
          v163 = v160 + 65537;
        UFG::qArray<UFG::SceneSettings::VendorSetup,0>::Reallocate(v159, v163, "SceneSettings::AddVendorSetupOnStart");
      }
      v159->size = v161;
      v164 = v159->p;
      v164[v160].mVendorType.mUID = timeInSeconds[0];
      v164[v160].mEnable = BYTE1(weather.mMagic);
      v156 = SimpleXML::XMLDocument::GetNode(v6, "vendorenableonstart", v156);
    }
    while ( v156 );
    v5 = v221;
  }
  v165 = SimpleXML::XMLDocument::GetChildNode(v6, "vendorenableonend", v5);
  if ( v165 )
  {
    do
    {
      v166 = SimpleXML::XMLNode::GetValue(v165);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v166);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v165, "enable", 1);
      v167 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      timeInSeconds[0] = (int)weather.mData;
      v168 = &v167->mVendorSetupOnEnd;
      v169 = v167->mVendorSetupOnEnd.size;
      v170 = v169 + 1;
      v171 = v167->mVendorSetupOnEnd.capacity;
      if ( (signed int)v169 + 1 > v171 )
      {
        if ( v171 )
          v172 = 2 * v171;
        else
          v172 = 1;
        for ( ; v172 < v170; v172 *= 2 )
          ;
        if ( v172 <= 2 )
          v172 = 2;
        if ( v172 - v170 > 0x10000 )
          v172 = v169 + 65537;
        UFG::qArray<UFG::SceneSettings::VendorSetup,0>::Reallocate(v168, v172, "SceneSettings::AddVendorSetupOnEnd");
      }
      v168->size = v170;
      v173 = v168->p;
      v173[v169].mVendorType.mUID = timeInSeconds[0];
      v173[v169].mEnable = BYTE1(weather.mMagic);
      v165 = SimpleXML::XMLDocument::GetNode(v6, "vendorenableonend", v165);
    }
    while ( v165 );
    v5 = v221;
  }
  v174 = SimpleXML::XMLDocument::GetChildNode(v6, "setdisguiseonstart", v5);
  if ( v174 )
  {
    do
    {
      v175 = SimpleXML::XMLNode::GetValue(v174);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v175);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v174, "enablewardrobe", 0);
      BYTE2(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v174, "enablestores", 0);
      LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v174, "keepoutfit", 0);
      v176 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
      timeInSeconds[0] = (int)weather.mData;
      v177 = &v176->mDisguiseSetupOnStart;
      v178 = v176->mDisguiseSetupOnStart.size;
      v179 = v178 + 1;
      v180 = v176->mDisguiseSetupOnStart.capacity;
      if ( (signed int)v178 + 1 > v180 )
      {
        if ( v180 )
          v181 = 2 * v180;
        else
          v181 = 1;
        for ( ; v181 < v179; v181 *= 2 )
          ;
        if ( v181 <= 2 )
          v181 = 2;
        if ( v181 - v179 > 0x10000 )
          v181 = v178 + 65537;
        UFG::qArray<UFG::SceneSettings::DisguiseSetup,0>::Reallocate(
          v177,
          v181,
          "SceneSettings::AddDisguiseSetupOnStart");
      }
      v177->size = v179;
      v182 = v177->p;
      v182[v178].mDisguise.mUID = timeInSeconds[0];
      *(_WORD *)&v182[v178].mEnableWardrobe = *(_WORD *)((char *)&weather.mMagic + 1);
      v182[v178].mKeepOutfit = weather.mMagic;
      v174 = SimpleXML::XMLDocument::GetNode(v6, "setdisguiseonstart", v174);
    }
    while ( v174 );
    v5 = v221;
  }
  for ( l = SimpleXML::XMLDocument::GetChildNode(v6, "removedisguiseonend", v5);
        l;
        l = SimpleXML::XMLDocument::GetNode(v6, "removedisguiseonend", l) )
  {
    v184 = SimpleXML::XMLNode::GetAttribute(l, "enablewardrobe", 0);
    v185 = SimpleXML::XMLNode::GetAttribute(l, "enablestores", 0);
    v186 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddDisguiseSetupOnEnd(v186, v184, v185);
  }
  for ( m = SimpleXML::XMLDocument::GetChildNode(v6, "loadhintonstart", v5);
        m;
        m = SimpleXML::XMLDocument::GetNode(v6, "loadhintonstart", m) )
  {
    v188 = SimpleXML::XMLNode::GetValue(m);
    v189 = SimpleXML::XMLNode::GetAttribute(m, "priority", 0);
    v190 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddLoadingHintSetupOnStart(v190, v188, v189);
  }
  for ( n = SimpleXML::XMLDocument::GetChildNode(v6, "loadhintonend", v5);
        n;
        n = SimpleXML::XMLDocument::GetNode(v6, "loadhintonend", n) )
  {
    v192 = SimpleXML::XMLNode::GetValue(n);
    v193 = SimpleXML::XMLNode::GetAttribute(n, "priority", 0);
    v194 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddLoadingHintSetupOnEnd(v194, v192, v193);
  }
  for ( ii = SimpleXML::XMLDocument::GetChildNode(v6, "loadscreenonstart", v5);
        ii;
        ii = SimpleXML::XMLDocument::GetNode(v6, "loadscreenonstart", ii) )
  {
    v196 = SimpleXML::XMLNode::GetValue(ii);
    v197 = SimpleXML::XMLNode::GetAttribute(ii, "priority", 0);
    v198 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddLoadingScreenSetupOnStart(v198, v196, v197);
  }
  for ( jj = SimpleXML::XMLDocument::GetChildNode(v6, "loadscreenonend", v5);
        jj;
        jj = SimpleXML::XMLDocument::GetNode(v6, "loadscreenonend", jj) )
  {
    v200 = SimpleXML::XMLNode::GetValue(jj);
    v201 = SimpleXML::XMLNode::GetAttribute(jj, "priority", 0);
    v202 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(v7);
    UFG::SceneSettings::AddLoadingScreenSetupOnEnd(v202, v200, v201);
  }
  for ( kk = SimpleXML::XMLDocument::GetChildNode(v6, "child", v5);
        kk;
        kk = SimpleXML::XMLDocument::GetNode(v6, "child", kk) )
  {
    v204 = SimpleXML::XMLNode::GetValue(kk);
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Child: %s\n");
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v204);
    UFG::qString::qString(&weather, v204);
    v205 = UFG::GameSlice::AddChild(v7->mpGameSlice, &weather);
    UFG::qString::~qString(&weather);
    if ( SimpleXML::XMLNode::GetAttribute(kk, "checkpoint", 0) )
      v205->mCheckpointSlice = 1;
    if ( SimpleXML::XMLNode::GetAttribute(kk, "optional", 0) )
      v205->mOptional = 1;
    if ( SimpleXML::XMLNode::GetAttribute(kk, "exclusive", 0) )
    {
      v206 = SimpleXML::XMLNode::GetAttribute(kk, "persistent", 0);
      v205->mExclusive = 1;
      v205->mPersistent = v206;
    }
    if ( SimpleXML::XMLNode::GetAttribute(kk, "holdcurtain", 0) )
      v205->mHoldCurtain = 1;
    if ( SimpleXML::XMLNode::GetAttribute(kk, "randomexclusive", 0) )
      v205->mRandomExclusive = 1;
  }
  for ( ll = SimpleXML::XMLDocument::GetChildNode(v6, "dependent", v5);
        ll;
        ll = SimpleXML::XMLDocument::GetNode(v6, "dependent", ll) )
  {
    v208 = SimpleXML::XMLNode::GetValue(ll);
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Dependent: %s\n");
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v208);
    UFG::GameSlice::AddDependency(v7->mpGameSlice, v208);
  }
  v209 = SimpleXML::XMLDocument::GetChildNode(v6, "minimumdependents", v5);
  if ( v209 )
    v210 = SimpleXML::XMLNode::GetValue(v209, 0);
  else
    v210 = v7->mpGameSlice->mDependents.mCount;
  v7->mpGameSlice->mMinimumDependentsRequired = v210;
  v211 = SimpleXML::XMLDocument::GetChildNode(v6, "maxheatlevel", v5);
  if ( v211 )
    v7->mpGameSlice->mMaxHeatLevel = SimpleXML::XMLNode::GetValue(v211, -1);
  v212 = SimpleXML::XMLDocument::GetChildNode(v6, "trackgamesliceas", v5);
  if ( v212 )
  {
    v213 = SimpleXML::XMLNode::GetValue(v212);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  TrackType[MISSION,CASE,EVENT,FAVOUR,JOB,DATE,RACE,DLC] : %s\n");
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v213);
    if ( LODWORD(weather.mData) > 0x8C436ED8 )
    {
      switch ( LODWORD(weather.mData) )
      {
        case 0x9713299A:
          v7->mpGameSlice->mTrackType = 1;
          break;
        case 0xD3FAB807:
          v7->mpGameSlice->mTrackType = 4;
          break;
        case 0xF78BD9D7:
          v7->mpGameSlice->mTrackType = 9;
          break;
        case 0xFB11F7DE:
          v7->mpGameSlice->mTrackType = 3;
          break;
      }
    }
    else
    {
      switch ( LODWORD(weather.mData) )
      {
        case 0x8C436ED8:
          v7->mpGameSlice->mTrackType = 10;
          break;
        case 0x12CC197:
          v7->mpGameSlice->mTrackType = 2;
          break;
        case 0xDFE7B8B:
          v7->mpGameSlice->mTrackType = 5;
          break;
        case 0x2A614186:
          v7->mpGameSlice->mTrackType = 6;
          break;
        case 0x3A04ED90:
          v7->mpGameSlice->mTrackType = 7;
          break;
        case 0x71C2B6C5:
          v7->mpGameSlice->mTrackType = 8;
          break;
      }
    }
  }
  UFG::GameSlice::CreateRuntimeRewardsPropertySets(v7->mpGameSlice);
}break;
      }
    }
  }
  UFG::GameSlice::CreateRuntimeRewardsPropertySets(v7->mpGameSlice);
}

// File Line: 1029
// RVA: 0x491730
void __fastcall UFG::XMLWrapperGameSlice::~XMLWrapperGameSlice(UFG::XMLWrapperGameSlice *this)
{
  UFG::XMLWrapperGameSlice *v1; // rbx
  char *v2; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v3; // rdx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v4; // rax

  v1 = this;
  v2 = this->mpGameSlice->mName.mText;
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Progression,
    OUTPUT_LEVEL_DEBUG,
    "[GameSlice]:    Cleaned Game Slice (%s)\n");
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&v1->mPrev;
}

// File Line: 1035
// RVA: 0x4988F0
void __fastcall UFG::XMLWrapperGameSlice::CollectWorkStatus(UFG::XMLWrapperGameSlice *this, SimpleXML::XMLDocument *pDocument, SimpleXML::XMLNode *pXMLNode)
{
  SimpleXML::XMLDocument *v3; // r13
  UFG::XMLWrapperGameSlice *v4; // rbx
  int v5; // edi
  SimpleXML::XMLNode *v6; // rax
  SimpleXML::XMLNode *i; // r15
  const char *v8; // r14
  char *v9; // r12
  UFG::GameSlice *v10; // rcx
  char v11; // bp
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *v12; // rbx
  UFG::allocator::free_link *v13; // rsi
  UFG::allocator::free_link *v14; // rbx
  UFG::allocator::free_link *v15; // rax
  UFG::qString text; // [rsp+30h] [rbp-88h]
  UFG::qString v17; // [rsp+58h] [rbp-60h]
  UFG::XMLWrapperGameSlice *v18; // [rsp+C0h] [rbp+8h]

  v18 = this;
  v3 = pDocument;
  v4 = this;
  v5 = 0;
  v6 = SimpleXML::XMLDocument::GetChildNode(pDocument, "workstatus", pXMLNode);
  if ( v6 )
  {
    for ( i = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, v6); i; v4 = v18 )
    {
      v8 = SimpleXML::XMLNode::GetValue(i);
      v9 = SimpleXML::XMLNode::GetName(i);
      v10 = v4->mpGameSlice;
      v11 = 0;
      v12 = v10->mMissionStates.mNode.mNext;
      v13 = (UFG::allocator::free_link *)&v10->mMissionStates;
      if ( v12 == (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)&v10->mMissionStates )
        goto LABEL_18;
      do
      {
        if ( !(unsigned int)UFG::qStringCompareInsensitive(v9, (const char *)v12[2].mNext, -1) )
        {
          v11 = 1;
          UFG::qString::Set((UFG::qString *)&v12[3].mNext, v8);
        }
        v12 = v12->mNext;
      }
      while ( v12 != (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)v13 );
      if ( !v11 )
      {
LABEL_18:
        v14 = UFG::qMalloc(0x60ui64, UFG::gGlobalNewName, 0i64);
        if ( v14 )
        {
          UFG::qString::qString(&v17, v8);
          UFG::qString::qString(&text, v9);
          v5 |= 3u;
          v14->mNext = v14;
          v14[1].mNext = v14;
          UFG::qString::qString((UFG::qString *)&v14[2], &text);
          UFG::qString::qString((UFG::qString *)&v14[7], &v17);
        }
        else
        {
          v14 = 0i64;
        }
        v15 = v13->mNext;
        v15[1].mNext = v14;
        v14->mNext = v15;
        v14[1].mNext = v13;
        v13->mNext = v14;
        if ( v5 & 2 )
        {
          v5 &= 0xFFFFFFFD;
          UFG::qString::~qString(&text);
        }
        if ( v5 & 1 )
        {
          v5 &= 0xFFFFFFFE;
          UFG::qString::~qString(&v17);
        }
      }
      i = SimpleXML::XMLDocument::GetNode(v3, 0i64, i);
    }
  }
}

// File Line: 1088
// RVA: 0x4A5A90
UFG::qBaseTreeRB *__fastcall UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(UFG::XMLWrapperGameSlice *this)
{
  UFG::XMLWrapperGameSlice *v1; // rdi
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h]
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v9; // [rsp+68h] [rbp+10h]

  v1 = this;
  UFG::qString::qString(&v7, "SliceSettings_");
  UFG::qString::operator+=(&v7, v1->mpGameSlice->mName.mText);
  UFG::qSymbol::create_from_string(&result, v7.mData);
  v2 = _S19_1;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v2 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( result.mUID )
  {
    v3 = UFG::qBaseTreeRB::Get(&stru_14240A220, result.mUID);
    v2 = _S19_1;
  }
  else
  {
    v3 = 0i64;
  }
  if ( !v3 )
  {
    if ( !(v2 & 1) )
    {
      _S19_1 = v2 | 1;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v4 = UFG::qMalloc(0x148ui64, "SceneSettings", 0i64);
    v9 = v4;
    if ( v4 )
    {
      UFG::SceneSettings::SceneSettings((UFG::SceneSettings *)v4, v7.mData);
      v3 = v5;
    }
    else
    {
      v3 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A220, &v3->mRoot);
    v1->mpGameSlice->mSceneSettings = (UFG::SceneSettings *)v3;
  }
  UFG::qString::~qString(&v7);
  return v3;
}

