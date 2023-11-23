// File Line: 129
// RVA: 0x48DF70
void __fastcall UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
        UFG::XMLWrapperGameSlice *this,
        SimpleXML::XMLDocument *pDocument,
        SimpleXML::XMLNode *pXMLNode,
        const char *pAuthor)
{
  SimpleXML::XMLNode *v4; // r12
  char *Attribute; // rbx
  char v8; // r13
  char v9; // si
  char v10; // di
  UFG::qBaseTreeRB *v11; // rax
  char *v12; // rax
  UFG::GameSlice *v13; // rax
  UFG::GameSlice *v14; // rbx
  SimpleXML::XMLNode *ChildNode; // rax
  char *Value; // rbx
  unsigned int v17; // eax
  SimpleXML::XMLNode *v18; // rax
  SimpleXML::XMLNode *v19; // rax
  char *v20; // rax
  const char *v21; // rbx
  UFG::qSymbol *v22; // rax
  SimpleXML::XMLNode *v23; // rax
  char *v24; // rbx
  SimpleXML::XMLNode *v25; // rax
  char *v26; // rax
  char *mText; // rdx
  SimpleXML::XMLNode *v28; // rax
  char *v29; // rax
  SimpleXML::XMLNode *v30; // rax
  char *v31; // rax
  SimpleXML::XMLNode *v32; // rax
  char *v33; // rax
  SimpleXML::XMLNode *v34; // rax
  SimpleXML::XMLNode *v35; // rax
  SimpleXML::XMLNode *v36; // rax
  char *v37; // rax
  SimpleXML::XMLNode *v38; // rbx
  SimpleXML::XMLNode *v39; // rsi
  SimpleXML::XMLNode *v40; // r13
  char *v41; // rax
  char v42; // al
  char *v43; // rcx
  char *v44; // rax
  char *v45; // rdi
  char *v46; // rbx
  char *v47; // rax
  char *v48; // rax
  char *v49; // rdi
  char *v50; // rbx
  char *v51; // rax
  char *v52; // rax
  SimpleXML::XMLNode *v53; // rax
  char *v54; // rax
  UFG::SceneSettings *SceneSettings; // rax
  SimpleXML::XMLNode *v56; // rax
  SimpleXML::XMLNode *v57; // rbx
  char *v58; // rax
  double v59; // xmm0_8
  UFG::qSymbol *v60; // rax
  SimpleXML::XMLNode *v61; // rax
  char *v62; // rax
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
  char *v80; // rax
  SimpleXML::XMLNode *v81; // rax
  char *v82; // rax
  SimpleXML::XMLNode *v83; // rax
  char *v84; // rax
  SimpleXML::XMLNode *v85; // rax
  SimpleXML::XMLNode *v86; // rax
  SimpleXML::XMLNode *v87; // rax
  SimpleXML::XMLNode *v88; // rax
  SimpleXML::XMLNode *v89; // rax
  double v90; // xmm0_8
  float v91; // xmm0_4
  unsigned __int64 v92; // rcx
  SimpleXML::XMLNode *v93; // rax
  SimpleXML::XMLNode *v94; // rbx
  double v95; // xmm0_8
  float v96; // xmm8_4
  double v97; // xmm0_8
  float v98; // xmm7_4
  double v99; // xmm0_8
  char v100; // di
  char v101; // si
  bool v102; // bl
  bool v103; // bl
  __m128i v104; // xmm0
  float mData_low; // xmm1_4
  float mUID; // xmm0_4
  UFG::GameSlice *mpGameSlice; // rax
  SimpleXML::XMLNode *v108; // rax
  SimpleXML::XMLNode *v109; // rbx
  char *v110; // rdi
  double v111; // xmm0_8
  float v112; // xmm7_4
  char v113; // bl
  float WeatherIntensityFromString; // xmm0_4
  UFG::SceneSettings *v115; // rax
  SimpleXML::XMLNode *v116; // rax
  SimpleXML::XMLNode *v117; // rbx
  double v118; // xmm0_8
  char v119; // bl
  UFG::SceneSettings *v120; // rax
  SimpleXML::XMLNode *v121; // rax
  SimpleXML::XMLNode *v122; // rbx
  char *v123; // rdi
  double v124; // xmm0_8
  UFG::GameSlice *v125; // rcx
  SimpleXML::XMLNode *v126; // rax
  char *v127; // rax
  SimpleXML::XMLNode *i; // rbx
  char *v129; // rax
  SimpleXML::XMLNode *v130; // rax
  SimpleXML::XMLNode *v131; // rbx
  char *v132; // r13
  char *v133; // rsi
  UFG::qBaseTreeRB *v134; // rdi
  char mMagic; // si
  UFG::allocator::free_link *v136; // rax
  UFG::qBaseTreeRB *v137; // rax
  UFG::GameSlice *v138; // rbx
  SimpleXML::XMLNode *Node; // rdi
  char v140; // r12
  char *v141; // rax
  UFG::SceneSettings *v142; // rax
  UFG::qArray<UFG::SceneSettings::LayerSetup,0> *p_mLayerSetupOnStart; // rsi
  __int64 size; // r13
  unsigned int v145; // ebx
  unsigned int capacity; // edx
  unsigned int v147; // edx
  UFG::SceneSettings::LayerSetup *p; // rax
  SimpleXML::XMLNode *v149; // rdi
  char v150; // r12
  char *v151; // rax
  UFG::SceneSettings *v152; // rax
  UFG::qArray<UFG::SceneSettings::LayerSetup,0> *p_mLayerSetupOnEnd; // rsi
  __int64 v154; // r13
  unsigned int v155; // ebx
  unsigned int v156; // edx
  unsigned int v157; // edx
  UFG::SceneSettings::LayerSetup *v158; // rax
  SimpleXML::XMLNode *j; // r13
  char *v160; // rsi
  char v161; // di
  char v162; // bl
  UFG::SceneSettings *v163; // rax
  SimpleXML::XMLNode *k; // r13
  char *v165; // rsi
  char v166; // di
  char v167; // bl
  UFG::SceneSettings *v168; // rax
  SimpleXML::XMLNode *v169; // rsi
  char *v170; // rax
  UFG::SceneSettings *v171; // rax
  UFG::qArray<UFG::SceneSettings::VendorSetup,0> *p_mVendorSetupOnStart; // rdi
  __int64 v173; // r13
  unsigned int v174; // ebx
  unsigned int v175; // edx
  unsigned int v176; // edx
  UFG::SceneSettings::VendorSetup *v177; // rax
  SimpleXML::XMLNode *v178; // rsi
  char *v179; // rax
  UFG::SceneSettings *v180; // rax
  UFG::qArray<UFG::SceneSettings::VendorSetup,0> *p_mVendorSetupOnEnd; // rdi
  __int64 v182; // r13
  unsigned int v183; // ebx
  unsigned int v184; // edx
  unsigned int v185; // edx
  UFG::SceneSettings::VendorSetup *v186; // rax
  SimpleXML::XMLNode *v187; // rdi
  char *v188; // rax
  UFG::SceneSettings *v189; // rax
  UFG::qArray<UFG::SceneSettings::DisguiseSetup,0> *p_mDisguiseSetupOnStart; // rsi
  __int64 v191; // r13
  unsigned int v192; // ebx
  unsigned int v193; // edx
  unsigned int v194; // edx
  UFG::SceneSettings::DisguiseSetup *v195; // rax
  SimpleXML::XMLNode *m; // rsi
  char v197; // di
  char v198; // bl
  UFG::SceneSettings *v199; // rax
  SimpleXML::XMLNode *n; // rsi
  char *v201; // rdi
  unsigned int v202; // ebx
  UFG::SceneSettings *v203; // rax
  SimpleXML::XMLNode *ii; // rsi
  char *v205; // rdi
  unsigned int v206; // ebx
  UFG::SceneSettings *v207; // rax
  SimpleXML::XMLNode *jj; // rsi
  char *v209; // rdi
  unsigned int v210; // ebx
  UFG::SceneSettings *v211; // rax
  SimpleXML::XMLNode *kk; // rsi
  char *v213; // rdi
  unsigned int v214; // ebx
  UFG::SceneSettings *v215; // rax
  SimpleXML::XMLNode *mm; // rdi
  char *v217; // rbx
  UFG::GameSlice *v218; // rbx
  char v219; // al
  SimpleXML::XMLNode *nn; // rdi
  char *v221; // rbx
  SimpleXML::XMLNode *v222; // rax
  int mCount; // ecx
  SimpleXML::XMLNode *v224; // rax
  SimpleXML::XMLNode *v225; // rax
  char *v226; // rbx
  UFG::qSymbol v227; // [rsp+8h] [rbp-79h] BYREF
  int timeInSeconds[2]; // [rsp+10h] [rbp-71h] BYREF
  UFG::qSymbol result; // [rsp+18h] [rbp-69h] BYREF
  UFG::qString weather; // [rsp+20h] [rbp-61h] BYREF
  char *v231; // [rsp+48h] [rbp-39h]
  __int64 v232; // [rsp+50h] [rbp-31h]
  char v233; // [rsp+EDh] [rbp+6Ch]
  SimpleXML::XMLNode *v234; // [rsp+F8h] [rbp+77h]

  v232 = -2i64;
  v4 = pXMLNode;
  this->mPrev = this;
  this->mNext = this;
  this->mpGameSlice = 0i64;
  Attribute = SimpleXML::XMLNode::GetAttribute(pXMLNode, "name");
  v231 = Attribute;
  UFG::qSymbol::create_from_string(&result, Attribute);
  v8 = SimpleXML::XMLNode::GetAttribute(v4, "checkpoint", 0);
  v9 = SimpleXML::XMLNode::GetAttribute(v4, "internal", 0);
  v10 = SimpleXML::XMLNode::GetAttribute(v4, "statsid", 0);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( !result.mUID )
    goto LABEL_9;
  v11 = UFG::qBaseTreeRB::Get(&stru_14240A190, result.mUID);
  if ( v11 )
    goto LABEL_10;
  if ( !result.mUID )
    goto LABEL_9;
  v11 = UFG::qBaseTreeRB::Get(&stru_14240A100, result.mUID);
  if ( v11 )
    goto LABEL_10;
  if ( result.mUID )
    v11 = UFG::qBaseTreeRB::Get(&stru_14240A148, result.mUID);
  else
LABEL_9:
    v11 = 0i64;
LABEL_10:
  this->mpGameSlice = (UFG::GameSlice *)v11;
  if ( v11 )
  {
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Binding to an existing slice: %s\n");
  }
  else
  {
    UFG::qString::qString(&weather, Attribute);
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v12 = (char *)UFG::qMalloc(0x240ui64, "GameSlice", 0i64);
    weather.mData = v12;
    if ( v12 )
    {
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v12, weather.mData);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v14->mNode);
    byte_14240B986 = 1;
    this->mpGameSlice = v14;
    UFG::qString::~qString(&weather);
  }
  this->mpGameSlice->mStatsId = v10;
  ChildNode = SimpleXML::XMLDocument::GetChildNode(pDocument, "title", v4);
  if ( ChildNode )
  {
    Value = SimpleXML::XMLNode::GetValue(ChildNode);
    UFG::qString::qString(&weather, Value);
    UFG::qSharedString::operator=(&this->mpGameSlice->mTitle, weather.mData);
    UFG::qString::~qString(&weather);
    weather.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)Value;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Slice: %s, Title: %s\n");
  }
  else
  {
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Slice: %s\n");
  }
  UFG::XMLWrapperGameSlice::CollectWorkStatus(this, pDocument, v4);
  if ( v8 )
    this->mpGameSlice->mCheckpointSlice = 1;
  if ( v9 )
    this->mpGameSlice->mInternalSlice = 1;
  v17 = SimpleXML::XMLNode::GetAttribute(v4, "repeatableinterval", 0);
  if ( v17 )
    this->mpGameSlice->mRepeatableInterval = 1000 * v17;
  if ( SimpleXML::XMLNode::GetAttribute(v4, "holdcurtain", 0) )
    this->mpGameSlice->mHoldCurtain = 1;
  v18 = SimpleXML::XMLDocument::GetChildNode(pDocument, "minpiplevel", v4);
  if ( v18 )
    this->mpGameSlice->mMinPipLevel = SimpleXML::XMLNode::GetValue(v18, 0);
  v19 = SimpleXML::XMLDocument::GetChildNode(pDocument, "faceactiontype", v4);
  if ( v19 )
  {
    v20 = SimpleXML::XMLNode::GetValue(v19);
    v21 = v20;
    if ( v20 )
    {
      UFG::qPrintf(" Face Action Type: %s\n", v20);
      v22 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v21);
      this->mpGameSlice->mFaceActionType = UFG::FaceActionComponent::LookupFaceAction(v22);
    }
  }
  v23 = SimpleXML::XMLDocument::GetChildNode(pDocument, "scriptclass", v4);
  if ( v23 )
  {
    v24 = SimpleXML::XMLNode::GetValue(v23);
    UFG::qString::qString(&weather, v24);
    UFG::qSharedString::operator=(&this->mpGameSlice->mScriptClassName, weather.mData);
    UFG::qString::~qString(&weather);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    ScriptClass: %s\n");
  }
  v25 = SimpleXML::XMLDocument::GetChildNode(pDocument, "layeroverride", v4);
  if ( v25 && (v26 = SimpleXML::XMLNode::GetValue(v25)) != 0i64 && *v26 )
    mText = v26;
  else
    mText = this->mpGameSlice->mScriptClassName.mText;
  this->mpGameSlice->mLayerName = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, mText)->mUID;
  v28 = SimpleXML::XMLDocument::GetChildNode(pDocument, "audiooverride", v4);
  if ( v28 )
  {
    v29 = SimpleXML::XMLNode::GetValue(v28);
    if ( v29 )
    {
      if ( *v29 )
      {
        UFG::qString::qString(&weather, v29);
        UFG::qSharedString::operator=(&this->mpGameSlice->mAudioOverride, weather.mData);
        UFG::qString::~qString(&weather);
      }
    }
  }
  v30 = SimpleXML::XMLDocument::GetChildNode(pDocument, "saveoverride", v4);
  if ( v30 )
  {
    v31 = SimpleXML::XMLNode::GetValue(v30);
    if ( v31 )
    {
      if ( *v31 )
        this->mpGameSlice->mSaveGamesliceOverrideName = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                                        (UFG::qSymbol *)&weather.mData,
                                                                        v31)->mUID;
    }
  }
  v32 = SimpleXML::XMLDocument::GetChildNode(pDocument, "savegamenameoverride", v4);
  if ( v32 )
  {
    v33 = SimpleXML::XMLNode::GetValue(v32);
    if ( v33 )
    {
      if ( *v33 )
        UFG::qSharedString::operator=(&this->mpGameSlice->mSaveGameNameOverride, v33);
    }
  }
  v34 = SimpleXML::XMLDocument::GetChildNode(pDocument, "autosave", v4);
  if ( v34 )
    this->mpGameSlice->mAutosave = SimpleXML::XMLNode::GetBool(v34, 1);
  v35 = SimpleXML::XMLDocument::GetChildNode(pDocument, "allowuicancellation", v4);
  if ( v35 )
    this->mpGameSlice->mAllowUICancellation = SimpleXML::XMLNode::GetBool(v35, 1);
  v36 = SimpleXML::XMLDocument::GetChildNode(pDocument, "dlcproductid", v4);
  if ( v36 )
  {
    v37 = SimpleXML::XMLNode::GetValue(v36);
    if ( v37 )
    {
      if ( *v37 )
        this->mpGameSlice->mDLCProductId = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                           (UFG::qSymbol *)&weather.mData,
                                                           v37)->mUID;
    }
  }
  v38 = SimpleXML::XMLDocument::GetChildNode(pDocument, "triggerobject", v4);
  v39 = SimpleXML::XMLDocument::GetChildNode(pDocument, "pdatrigger", v4);
  v40 = SimpleXML::XMLDocument::GetChildNode(pDocument, "incomingpdatrigger", v4);
  if ( v38 )
  {
    v41 = SimpleXML::XMLNode::GetValue(v38);
    this->mpGameSlice->mTriggerObjectName = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                            (UFG::qSymbol *)&weather.mData,
                                                            v41)->mUID;
    v42 = SimpleXML::XMLNode::GetAttribute(v38, "keepobjectiveenabled", 0);
    if ( v42 )
      this->mpGameSlice->mKeepTriggerObjectiveEnabled = v42;
    v43 = &customCaption;
    if ( v42 )
      v43 = "[KeepObjective]";
    weather.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v43;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    TriggerObject: %s%s\n");
  }
  if ( v39 )
  {
    v44 = (char *)UFG::qMalloc(0x60ui64, "PDATriggerParameters", 0i64);
    v45 = v44;
    weather.mData = v44;
    if ( v44 )
    {
      UFG::qString::qString((UFG::qString *)v44);
      *((_QWORD *)v45 + 5) = -1i64;
      UFG::qString::qString((UFG::qString *)(v45 + 48));
      v45[88] = 0;
    }
    else
    {
      v45 = 0i64;
    }
    v46 = SimpleXML::XMLNode::GetValue(v39);
    *((UFG::qSymbol *)v45 + 10) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v46)->mUID;
    UFG::qString::Set((UFG::qString *)v45, v46);
    v47 = SimpleXML::XMLNode::GetAttribute(v39, "objective", &customCaption);
    if ( *v47 )
      UFG::qString::Set((UFG::qString *)(v45 + 48), v47);
    this->mpGameSlice->mPDATriggerParameters = (UFG::PDATriggerParameters *)v45;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v45 + 10);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    PDATrigger: %s\n");
  }
  if ( v40 )
  {
    v48 = (char *)UFG::qMalloc(0x60ui64, "PDATriggerParameters", 0i64);
    v49 = v48;
    weather.mData = v48;
    if ( v48 )
    {
      UFG::qString::qString((UFG::qString *)v48);
      *((_QWORD *)v49 + 5) = -1i64;
      UFG::qString::qString((UFG::qString *)(v49 + 48));
      v49[88] = 0;
    }
    else
    {
      v49 = 0i64;
    }
    v49[88] = 1;
    v50 = SimpleXML::XMLNode::GetAttribute(v40, "contactname", &customCaption);
    *((UFG::qSymbol *)v49 + 10) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v50)->mUID;
    UFG::qString::Set((UFG::qString *)v49, v50);
    v51 = SimpleXML::XMLNode::GetAttribute(v40, "vehiclefilter", &customCaption);
    if ( v51 && *v51 )
      *((UFG::qSymbol *)v49 + 11) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v51)->mUID;
    v52 = SimpleXML::XMLNode::GetAttribute(v40, "triggerobject", &customCaption);
    this->mpGameSlice->mTriggerObjectName = (UFG::qSymbol)UFG::qSymbol::create_from_string(
                                                            (UFG::qSymbol *)&weather.mData,
                                                            v52)->mUID;
    this->mpGameSlice->mPDATriggerParameters = (UFG::PDATriggerParameters *)v49;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v49 + 10);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:    IncomingPDATrigger: %s\n");
  }
  v53 = SimpleXML::XMLDocument::GetChildNode(pDocument, "teleportlocationmarker", v4);
  if ( v53 )
  {
    v54 = SimpleXML::XMLNode::GetValue(v53);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v54);
    SceneSettings = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    SceneSettings->mTeleportMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Teleport location marker: %s\n");
  }
  v56 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vehicleteleportlocationmarker", v4);
  v57 = v56;
  if ( v56 )
  {
    v58 = SimpleXML::XMLNode::GetValue(v56);
    if ( v58 )
    {
      UFG::qSymbol::create_from_string(&v227, v58);
      v59 = SimpleXML::XMLNode::GetAttribute(v57, "range", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
      v60 = (UFG::qSymbol *)UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      v60[29].mUID = v227.mUID;
      if ( *(float *)&v59 < 0.0 )
        v60[16].mUID = 1106247680;
      else
        v60[16].mUID = (unsigned int)LODWORD(v59);
    }
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Vehicle Teleport location marker: %s\n");
  }
  v61 = SimpleXML::XMLDocument::GetChildNode(pDocument, "restorelocationmarker", v4);
  if ( v61 )
  {
    v62 = SimpleXML::XMLNode::GetValue(v61);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v62);
    this->mpGameSlice->mRestoreLocationMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Restore location marker: %s\n");
  }
  if ( SimpleXML::XMLDocument::GetChildNode(pDocument, "disablecopscoring", v4) )
    this->mpGameSlice->mDisableCopScoring = 1;
  if ( SimpleXML::XMLDocument::GetChildNode(pDocument, "disabletriadscoring", v4) )
    this->mpGameSlice->mDisableTriadScoring = 1;
  v63 = SimpleXML::XMLDocument::GetChildNode(pDocument, "lockambientpedsonstart", v4);
  if ( v63 )
  {
    v64 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v64->mLockPedsOnStart = SimpleXML::XMLNode::GetBool(v63, 0);
  }
  v65 = SimpleXML::XMLDocument::GetChildNode(pDocument, "unlockambientpedsonend", v4);
  if ( v65 )
  {
    v66 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v66->mUnLockPedsOnEnd = SimpleXML::XMLNode::GetBool(v65, 0);
  }
  v67 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enableambientpedsonstart", v4);
  if ( v67 )
  {
    v68 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v68->mEnableAmbientPedsOnStart = SimpleXML::XMLNode::GetBool(v67, 1);
  }
  v69 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enableambientpedsonend", v4);
  if ( v69 )
  {
    v70 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v70->mEnableAmbientPedsOnEnd = SimpleXML::XMLNode::GetBool(v69, 1);
  }
  v71 = SimpleXML::XMLDocument::GetChildNode(pDocument, "locktrafficonstart", v4);
  if ( v71 )
  {
    v72 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v72->mLockTrafficOnStart = SimpleXML::XMLNode::GetBool(v71, 0);
  }
  v73 = SimpleXML::XMLDocument::GetChildNode(pDocument, "unlocktrafficonend", v4);
  if ( v73 )
  {
    v74 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v74->mUnLockTrafficOnEnd = SimpleXML::XMLNode::GetBool(v73, 0);
  }
  v75 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enabletrafficonstart", v4);
  if ( v75 )
  {
    v76 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v76->mEnableTrafficOnStart = SimpleXML::XMLNode::GetBool(v75, 1);
  }
  v77 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enabletrafficonend", v4);
  if ( v77 )
  {
    v78 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    v78->mEnableTrafficOnEnd = SimpleXML::XMLNode::GetBool(v77, 1);
  }
  v79 = SimpleXML::XMLDocument::GetChildNode(pDocument, "cancellocationmarker", v4);
  if ( v79 )
  {
    v80 = SimpleXML::XMLNode::GetValue(v79);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v80);
    this->mpGameSlice->mCancelLocationMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Cancel location marker: %s\n");
  }
  v81 = SimpleXML::XMLDocument::GetChildNode(pDocument, "completelocationmarker", v4);
  if ( v81 )
  {
    v82 = SimpleXML::XMLNode::GetValue(v81);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v82);
    this->mpGameSlice->mCompleteLocationMarker.mUID = (unsigned int)weather.mData;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  Complete location marker: %s\n");
  }
  v83 = SimpleXML::XMLDocument::GetChildNode(pDocument, "subsetmode", v4);
  if ( v83 )
  {
    v84 = SimpleXML::XMLNode::GetValue(v83);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v84);
    this->mpGameSlice->mSubsetModeType.mUID = (unsigned int)weather.mData;
  }
  v85 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vehiclesuperstop", v4);
  if ( v85 )
    this->mpGameSlice->mVehicleSuperStop = SimpleXML::XMLNode::GetBool(v85, 0);
  v86 = SimpleXML::XMLDocument::GetChildNode(pDocument, "ignoresafehouserestore", v4);
  if ( v86 )
    this->mpGameSlice->mIgnoreSafehouseRestore = SimpleXML::XMLNode::GetBool(v86, 1);
  v87 = SimpleXML::XMLDocument::GetChildNode(pDocument, "deferredregionstart", v4);
  if ( v87 )
    this->mpGameSlice->mDeferStartIfInsideRegion = SimpleXML::XMLNode::GetBool(v87, 0);
  v88 = SimpleXML::XMLDocument::GetChildNode(pDocument, "deferredregionrestart", v4);
  if ( v88 )
    this->mpGameSlice->mDeferRestartIfInsideRegion = SimpleXML::XMLNode::GetBool(v88, 1);
  v89 = SimpleXML::XMLDocument::GetChildNode(pDocument, "failtimeout", v4);
  if ( v89 )
  {
    v90 = SimpleXML::XMLNode::GetValue(v89, COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    if ( *(float *)&v90 >= 0.0 )
    {
      v91 = *(float *)&v90 * 1000.0;
      v92 = 0i64;
      if ( v91 >= 9.223372e18 )
      {
        v91 = v91 - 9.223372e18;
        if ( v91 < 9.223372e18 )
          v92 = 0x8000000000000000ui64;
      }
      this->mpGameSlice->mFailTimeout = v92 + (unsigned int)(int)v91;
    }
  }
  v93 = SimpleXML::XMLDocument::GetChildNode(pDocument, "timeofday", v4);
  v94 = v93;
  if ( v93 )
  {
    v95 = SimpleXML::XMLNode::GetAttribute(v93, "restore", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v96 = *(float *)&v95;
    v97 = SimpleXML::XMLNode::GetAttribute(v94, "active", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v98 = *(float *)&v97;
    v99 = SimpleXML::XMLNode::GetAttribute(v94, "inactive", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v100 = SimpleXML::XMLNode::GetAttribute(v94, "bypassprompt", 0);
    v101 = SimpleXML::XMLNode::GetAttribute(v94, "performtimeshift", 1);
    timeInSeconds[0] = 0;
    v227.mUID = 0;
    LODWORD(weather.mData) = 0;
    v102 = v98 < 0.0 || *(float *)&v99 < 0.0;
    v103 = !UFG::TimeOfDayManager::GetTimeInSeconds(v98, (int *)&v227) && v102;
    if ( UFG::TimeOfDayManager::GetTimeInSeconds(*(float *)&v99, (int *)&weather.mData) || !v103 )
    {
      if ( UFG::TimeOfDayManager::GetTimeInSeconds(v96, timeInSeconds) )
        v104 = _mm_cvtsi32_si128(timeInSeconds[0]);
      else
        v104 = _mm_cvtsi32_si128(v227.mUID);
      LODWORD(this->mpGameSlice->mTODRestore) = _mm_cvtepi32_ps(v104).m128_u32[0];
      mData_low = (float)SLODWORD(weather.mData);
      mUID = (float)(int)v227.mUID;
      mpGameSlice = this->mpGameSlice;
      mpGameSlice->mIsTODRestricted = 1;
      mpGameSlice->mTODActive = mUID;
      mpGameSlice->mTODInactive = mData_low;
      mpGameSlice->mTODBypassPrompt = v100;
      mpGameSlice->mPerformTimeShift = v101;
    }
  }
  v108 = SimpleXML::XMLDocument::GetChildNode(pDocument, "forceweather", v4);
  v109 = v108;
  if ( v108 )
  {
    v110 = SimpleXML::XMLNode::GetAttribute(v108, "type", "notset");
    v111 = SimpleXML::XMLNode::GetAttribute(v109, "wetness", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v112 = *(float *)&v111;
    v113 = SimpleXML::XMLNode::GetAttribute(v109, "locked", 0);
    UFG::qString::qString(&weather, v110);
    WeatherIntensityFromString = UFG::TimeOfDayManager::GetWeatherIntensityFromString(&weather);
    if ( WeatherIntensityFromString >= 0.0 )
    {
      v115 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      v115->mWeatherOverrideIntensity = WeatherIntensityFromString;
      v115->mWeatherOverrideWetness = v112;
      v115->mWeatherOverrideLock = v113;
      v115->mWeatherOverrideLockSet = 1;
    }
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Weather: %s\n");
    UFG::qString::~qString(&weather);
  }
  v116 = SimpleXML::XMLDocument::GetChildNode(pDocument, "forcetime", v4);
  v117 = v116;
  if ( v116 )
  {
    v118 = SimpleXML::XMLNode::GetAttribute(v116, "time", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v119 = SimpleXML::XMLNode::GetAttribute(v117, "locked", 0);
    if ( *(float *)&v118 >= 0.0 )
    {
      LODWORD(weather.mData) = 0;
      if ( UFG::TimeOfDayManager::GetTimeInSeconds(*(float *)&v118, (int *)&weather.mData) )
      {
        v120 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
        v120->mTimeOverrideInSeconds = (float)SLODWORD(weather.mData);
        v120->mTimeOverrideLock = v119;
        v120->mTimeOverrideLockSet = 1;
      }
    }
  }
  v121 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vehiclerestore", v4);
  v122 = v121;
  if ( v121 )
  {
    v123 = SimpleXML::XMLNode::GetValue(v121);
    v124 = SimpleXML::XMLNode::GetAttribute(v122, "range", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    if ( v123 )
    {
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v123);
      v125 = this->mpGameSlice;
      v125->mVehicleMarker.mUID = (unsigned int)weather.mData;
      if ( *(float *)&v124 <= 0.0 )
        v125->mVehicleMarkerRange = 30.0;
      else
        v125->mVehicleMarkerRange = *(float *)&v124;
    }
  }
  v126 = SimpleXML::XMLDocument::GetChildNode(pDocument, "weaponrestore", v4);
  if ( v126 )
  {
    v127 = SimpleXML::XMLNode::GetValue(v126);
    if ( v127 )
    {
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v127);
      this->mpGameSlice->mRestoreWeapon.mUID = (unsigned int)weather.mData;
    }
  }
  for ( i = SimpleXML::XMLDocument::GetChildNode(pDocument, "restartcompletedslice", v4);
        i;
        i = SimpleXML::XMLDocument::GetNode(pDocument, "restartcompletedslice", i) )
  {
    v129 = SimpleXML::XMLNode::GetValue(i);
    UFG::qString::qString(&weather, v129);
    UFG::GameSlice::AddReEnableSlice(this->mpGameSlice, &weather);
    UFG::qString::~qString(&weather);
  }
  v130 = SimpleXML::XMLDocument::GetChildNode(pDocument, "nis", v4);
  v131 = v130;
  if ( v130 )
  {
    v132 = SimpleXML::XMLNode::GetAttribute(v130, "path");
    v133 = SimpleXML::XMLNode::GetAttribute(v131, "scenesettings", &customCaption);
    LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v131, "autofadein", 1);
    BYTE2(weather.mMagic) = 0;
    v134 = 0i64;
    if ( !strcmp(v133, "Settings_Intermediate_Nis") )
    {
      BYTE2(weather.mMagic) = 1;
      mMagic = 0;
    }
    else
    {
      if ( *v133 )
      {
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v133);
        if ( (_S19_1 & 1) == 0 )
        {
          _S19_1 |= 1u;
          UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
          atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
        }
        UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
        if ( LODWORD(weather.mData) )
          v134 = UFG::qBaseTreeRB::Get(&stru_14240A220, (unsigned int)weather.mData);
        else
          v134 = 0i64;
        if ( !v134 )
        {
          UFG::qString::qString(&weather, v133);
          if ( (_S19_1 & 1) == 0 )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          v136 = UFG::qMalloc(0x148ui64, "SceneSettings", 0i64);
          *(_QWORD *)timeInSeconds = v136;
          if ( v136 )
          {
            UFG::SceneSettings::SceneSettings((UFG::SceneSettings *)v136, weather.mData);
            v134 = v137;
          }
          else
          {
            v134 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&stru_14240A220, &v134->mRoot);
          UFG::qString::~qString(&weather);
        }
      }
      mMagic = weather.mMagic;
    }
    if ( v132 )
    {
      v138 = this->mpGameSlice;
      UFG::qSharedString::operator=(&v138->mNisPath, v132);
      v138->mNisSceneSettings = (UFG::SceneSettings *)v134;
      v138->mNisIntermediate = BYTE2(weather.mMagic);
      v138->mNisPostFadeIn = mMagic;
      if ( v134 )
      {
        if ( this->mpGameSlice->mSceneSettings )
          UFG::qPrintf(
            "WARNING: Settings such as weather, time and teleport location will conflict with the nis settings and cause "
            "longer loading times for %s!\n",
            v231);
      }
    }
  }
  Node = SimpleXML::XMLDocument::GetChildNode(pDocument, "scenelayeronstart", v4);
  if ( Node )
  {
    v140 = v233;
    do
    {
      v141 = SimpleXML::XMLNode::GetValue(Node);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v141);
      BYTE2(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(Node, "geoautoactivate") != 0i64;
      LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(Node, "geoautoactivate", 0);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(Node, "activate", 0);
      v142 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      timeInSeconds[0] = (int)weather.mData;
      p_mLayerSetupOnStart = &v142->mLayerSetupOnStart;
      size = v142->mLayerSetupOnStart.size;
      v145 = size + 1;
      capacity = v142->mLayerSetupOnStart.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v147 = 2 * capacity;
        else
          v147 = 1;
        for ( ; v147 < v145; v147 *= 2 )
          ;
        if ( v147 <= 2 )
          v147 = 2;
        if ( v147 - v145 > 0x10000 )
          v147 = size + 65537;
        UFG::qArray<UFG::SceneSettings::LayerSetup,0>::Reallocate(
          p_mLayerSetupOnStart,
          v147,
          "SceneSettings::AddLayerSetupOnStart");
      }
      p_mLayerSetupOnStart->size = v145;
      p = p_mLayerSetupOnStart->p;
      p[size].mLayerName.mUID = timeInSeconds[0];
      p[size].mGeoSettingsPresent = BYTE2(weather.mMagic);
      p[size].mEnable = v140;
      *(_WORD *)&p[size].mGeoAutoActivate = weather.mMagic;
      Node = SimpleXML::XMLDocument::GetNode(pDocument, "scenelayeronstart", Node);
    }
    while ( Node );
    v4 = v234;
  }
  v149 = SimpleXML::XMLDocument::GetChildNode(pDocument, "scenelayeronend", v4);
  if ( v149 )
  {
    v150 = v233;
    do
    {
      v151 = SimpleXML::XMLNode::GetValue(v149);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v151);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v149, "geoautoactivate") != 0i64;
      BYTE2(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v149, "geoautoactivate", 0);
      LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v149, "activate", 0);
      v152 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      timeInSeconds[0] = (int)weather.mData;
      p_mLayerSetupOnEnd = &v152->mLayerSetupOnEnd;
      v154 = v152->mLayerSetupOnEnd.size;
      v155 = v154 + 1;
      v156 = v152->mLayerSetupOnEnd.capacity;
      if ( (int)v154 + 1 > v156 )
      {
        if ( v156 )
          v157 = 2 * v156;
        else
          v157 = 1;
        for ( ; v157 < v155; v157 *= 2 )
          ;
        if ( v157 <= 2 )
          v157 = 2;
        if ( v157 - v155 > 0x10000 )
          v157 = v154 + 65537;
        UFG::qArray<UFG::SceneSettings::LayerSetup,0>::Reallocate(
          p_mLayerSetupOnEnd,
          v157,
          "SceneSettings::AddLayerSetupOnEnd");
      }
      p_mLayerSetupOnEnd->size = v155;
      v158 = p_mLayerSetupOnEnd->p;
      v158[v154].mLayerName.mUID = timeInSeconds[0];
      v158[v154].mGeoSettingsPresent = BYTE1(weather.mMagic);
      v158[v154].mEnable = v150;
      v158[v154].mGeoAutoActivate = BYTE2(weather.mMagic);
      v158[v154].mActivate = weather.mMagic;
      v149 = SimpleXML::XMLDocument::GetNode(pDocument, "scenelayeronend", v149);
    }
    while ( v149 );
    v4 = v234;
  }
  for ( j = SimpleXML::XMLDocument::GetChildNode(pDocument, "altlayeronstart", v4);
        j;
        j = SimpleXML::XMLDocument::GetNode(pDocument, "altlayeronstart", j) )
  {
    v160 = SimpleXML::XMLNode::GetValue(j);
    v161 = SimpleXML::XMLNode::GetAttribute(j, "flush", 0);
    v162 = SimpleXML::XMLNode::GetAttribute(j, "activate", 0);
    v163 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddAltLayerSetupOnStart(v163, v160, v162, v161);
  }
  for ( k = SimpleXML::XMLDocument::GetChildNode(pDocument, "altlayeronend", v4);
        k;
        k = SimpleXML::XMLDocument::GetNode(pDocument, "altlayeronend", k) )
  {
    v165 = SimpleXML::XMLNode::GetValue(k);
    v166 = SimpleXML::XMLNode::GetAttribute(k, "flush", 0);
    v167 = SimpleXML::XMLNode::GetAttribute(k, "activate", 0);
    v168 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddAltLayerSetupOnEnd(v168, v165, v167, v166);
  }
  v169 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vendorenableonstart", v4);
  if ( v169 )
  {
    do
    {
      v170 = SimpleXML::XMLNode::GetValue(v169);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v170);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v169, "enable", 0);
      v171 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      timeInSeconds[0] = (int)weather.mData;
      p_mVendorSetupOnStart = &v171->mVendorSetupOnStart;
      v173 = v171->mVendorSetupOnStart.size;
      v174 = v173 + 1;
      v175 = v171->mVendorSetupOnStart.capacity;
      if ( (int)v173 + 1 > v175 )
      {
        if ( v175 )
          v176 = 2 * v175;
        else
          v176 = 1;
        for ( ; v176 < v174; v176 *= 2 )
          ;
        if ( v176 <= 2 )
          v176 = 2;
        if ( v176 - v174 > 0x10000 )
          v176 = v173 + 65537;
        UFG::qArray<UFG::SceneSettings::VendorSetup,0>::Reallocate(
          p_mVendorSetupOnStart,
          v176,
          "SceneSettings::AddVendorSetupOnStart");
      }
      p_mVendorSetupOnStart->size = v174;
      v177 = p_mVendorSetupOnStart->p;
      v177[v173].mVendorType.mUID = timeInSeconds[0];
      v177[v173].mEnable = BYTE1(weather.mMagic);
      v169 = SimpleXML::XMLDocument::GetNode(pDocument, "vendorenableonstart", v169);
    }
    while ( v169 );
    v4 = v234;
  }
  v178 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vendorenableonend", v4);
  if ( v178 )
  {
    do
    {
      v179 = SimpleXML::XMLNode::GetValue(v178);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v179);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v178, "enable", 1);
      v180 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      timeInSeconds[0] = (int)weather.mData;
      p_mVendorSetupOnEnd = &v180->mVendorSetupOnEnd;
      v182 = v180->mVendorSetupOnEnd.size;
      v183 = v182 + 1;
      v184 = v180->mVendorSetupOnEnd.capacity;
      if ( (int)v182 + 1 > v184 )
      {
        if ( v184 )
          v185 = 2 * v184;
        else
          v185 = 1;
        for ( ; v185 < v183; v185 *= 2 )
          ;
        if ( v185 <= 2 )
          v185 = 2;
        if ( v185 - v183 > 0x10000 )
          v185 = v182 + 65537;
        UFG::qArray<UFG::SceneSettings::VendorSetup,0>::Reallocate(
          p_mVendorSetupOnEnd,
          v185,
          "SceneSettings::AddVendorSetupOnEnd");
      }
      p_mVendorSetupOnEnd->size = v183;
      v186 = p_mVendorSetupOnEnd->p;
      v186[v182].mVendorType.mUID = timeInSeconds[0];
      v186[v182].mEnable = BYTE1(weather.mMagic);
      v178 = SimpleXML::XMLDocument::GetNode(pDocument, "vendorenableonend", v178);
    }
    while ( v178 );
    v4 = v234;
  }
  v187 = SimpleXML::XMLDocument::GetChildNode(pDocument, "setdisguiseonstart", v4);
  if ( v187 )
  {
    do
    {
      v188 = SimpleXML::XMLNode::GetValue(v187);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v188);
      BYTE1(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v187, "enablewardrobe", 0);
      BYTE2(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v187, "enablestores", 0);
      LOBYTE(weather.mMagic) = SimpleXML::XMLNode::GetAttribute(v187, "keepoutfit", 0);
      v189 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
      timeInSeconds[0] = (int)weather.mData;
      p_mDisguiseSetupOnStart = &v189->mDisguiseSetupOnStart;
      v191 = v189->mDisguiseSetupOnStart.size;
      v192 = v191 + 1;
      v193 = v189->mDisguiseSetupOnStart.capacity;
      if ( (int)v191 + 1 > v193 )
      {
        if ( v193 )
          v194 = 2 * v193;
        else
          v194 = 1;
        for ( ; v194 < v192; v194 *= 2 )
          ;
        if ( v194 <= 2 )
          v194 = 2;
        if ( v194 - v192 > 0x10000 )
          v194 = v191 + 65537;
        UFG::qArray<UFG::SceneSettings::DisguiseSetup,0>::Reallocate(
          p_mDisguiseSetupOnStart,
          v194,
          "SceneSettings::AddDisguiseSetupOnStart");
      }
      p_mDisguiseSetupOnStart->size = v192;
      v195 = p_mDisguiseSetupOnStart->p;
      v195[v191].mDisguise.mUID = timeInSeconds[0];
      *(_WORD *)&v195[v191].mEnableWardrobe = *(_WORD *)((char *)&weather.mMagic + 1);
      v195[v191].mKeepOutfit = weather.mMagic;
      v187 = SimpleXML::XMLDocument::GetNode(pDocument, "setdisguiseonstart", v187);
    }
    while ( v187 );
    v4 = v234;
  }
  for ( m = SimpleXML::XMLDocument::GetChildNode(pDocument, "removedisguiseonend", v4);
        m;
        m = SimpleXML::XMLDocument::GetNode(pDocument, "removedisguiseonend", m) )
  {
    v197 = SimpleXML::XMLNode::GetAttribute(m, "enablewardrobe", 0);
    v198 = SimpleXML::XMLNode::GetAttribute(m, "enablestores", 0);
    v199 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddDisguiseSetupOnEnd(v199, v197, v198);
  }
  for ( n = SimpleXML::XMLDocument::GetChildNode(pDocument, "loadhintonstart", v4);
        n;
        n = SimpleXML::XMLDocument::GetNode(pDocument, "loadhintonstart", n) )
  {
    v201 = SimpleXML::XMLNode::GetValue(n);
    v202 = SimpleXML::XMLNode::GetAttribute(n, "priority", 0);
    v203 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddLoadingHintSetupOnStart(v203, v201, v202);
  }
  for ( ii = SimpleXML::XMLDocument::GetChildNode(pDocument, "loadhintonend", v4);
        ii;
        ii = SimpleXML::XMLDocument::GetNode(pDocument, "loadhintonend", ii) )
  {
    v205 = SimpleXML::XMLNode::GetValue(ii);
    v206 = SimpleXML::XMLNode::GetAttribute(ii, "priority", 0);
    v207 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddLoadingHintSetupOnEnd(v207, v205, v206);
  }
  for ( jj = SimpleXML::XMLDocument::GetChildNode(pDocument, "loadscreenonstart", v4);
        jj;
        jj = SimpleXML::XMLDocument::GetNode(pDocument, "loadscreenonstart", jj) )
  {
    v209 = SimpleXML::XMLNode::GetValue(jj);
    v210 = SimpleXML::XMLNode::GetAttribute(jj, "priority", 0);
    v211 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddLoadingScreenSetupOnStart(v211, v209, v210);
  }
  for ( kk = SimpleXML::XMLDocument::GetChildNode(pDocument, "loadscreenonend", v4);
        kk;
        kk = SimpleXML::XMLDocument::GetNode(pDocument, "loadscreenonend", kk) )
  {
    v213 = SimpleXML::XMLNode::GetValue(kk);
    v214 = SimpleXML::XMLNode::GetAttribute(kk, "priority", 0);
    v215 = UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(this);
    UFG::SceneSettings::AddLoadingScreenSetupOnEnd(v215, v213, v214);
  }
  for ( mm = SimpleXML::XMLDocument::GetChildNode(pDocument, "child", v4);
        mm;
        mm = SimpleXML::XMLDocument::GetNode(pDocument, "child", mm) )
  {
    v217 = SimpleXML::XMLNode::GetValue(mm);
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Child: %s\n");
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v217);
    UFG::qString::qString(&weather, v217);
    v218 = UFG::GameSlice::AddChild(this->mpGameSlice, &weather);
    UFG::qString::~qString(&weather);
    if ( SimpleXML::XMLNode::GetAttribute(mm, "checkpoint", 0) )
      v218->mCheckpointSlice = 1;
    if ( SimpleXML::XMLNode::GetAttribute(mm, "optional", 0) )
      v218->mOptional = 1;
    if ( SimpleXML::XMLNode::GetAttribute(mm, "exclusive", 0) )
    {
      v219 = SimpleXML::XMLNode::GetAttribute(mm, "persistent", 0);
      v218->mExclusive = 1;
      v218->mPersistent = v219;
    }
    if ( SimpleXML::XMLNode::GetAttribute(mm, "holdcurtain", 0) )
      v218->mHoldCurtain = 1;
    if ( SimpleXML::XMLNode::GetAttribute(mm, "randomexclusive", 0) )
      v218->mRandomExclusive = 1;
  }
  for ( nn = SimpleXML::XMLDocument::GetChildNode(pDocument, "dependent", v4);
        nn;
        nn = SimpleXML::XMLDocument::GetNode(pDocument, "dependent", nn) )
  {
    v221 = SimpleXML::XMLNode::GetValue(nn);
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Progression, OUTPUT_LEVEL_DEBUG, "[GameSlice]:  Dependent: %s\n");
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v221);
    UFG::GameSlice::AddDependency(this->mpGameSlice, v221);
  }
  v222 = SimpleXML::XMLDocument::GetChildNode(pDocument, "minimumdependents", v4);
  if ( v222 )
    mCount = SimpleXML::XMLNode::GetValue(v222, 0);
  else
    mCount = this->mpGameSlice->mDependents.mCount;
  this->mpGameSlice->mMinimumDependentsRequired = mCount;
  v224 = SimpleXML::XMLDocument::GetChildNode(pDocument, "maxheatlevel", v4);
  if ( v224 )
    this->mpGameSlice->mMaxHeatLevel = SimpleXML::XMLNode::GetValue(v224, -1);
  v225 = SimpleXML::XMLDocument::GetChildNode(pDocument, "trackgamesliceas", v4);
  if ( v225 )
  {
    v226 = SimpleXML::XMLNode::GetValue(v225);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]:  TrackType[MISSION,CASE,EVENT,FAVOUR,JOB,DATE,RACE,DLC] : %s\n");
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&weather.mData, v226);
    if ( LODWORD(weather.mData) > 0x8C436ED8 )
    {
      switch ( LODWORD(weather.mData) )
      {
        case 0x9713299A:
          this->mpGameSlice->mTrackType = 1;
          break;
        case 0xD3FAB807:
          this->mpGameSlice->mTrackType = 4;
          break;
        case 0xF78BD9D7:
          this->mpGameSlice->mTrackType = 9;
          break;
        case 0xFB11F7DE:
          this->mpGameSlice->mTrackType = 3;
          break;
      }
    }
    else
    {
      switch ( LODWORD(weather.mData) )
      {
        case 0x8C436ED8:
          this->mpGameSlice->mTrackType = 10;
          break;
        case 0x12CC197:
          this->mpGameSlice->mTrackType = 2;
          break;
        case 0xDFE7B8B:
          this->mpGameSlice->mTrackType = 5;
          break;
        case 0x2A614186:
          this->mpGameSlice->mTrackType = 6;
          break;
        case 0x3A04ED90:
          this->mpGameSlice->mTrackType = 7;
          break;
        case 0x71C2B6C5:
          this->mpGameSlice->mTrackType = 8;
          break;
      }
    }
  }
  UFG::GameSlice::CreateRuntimeRewardsPropertySets(this->mpGameSlice);
}

// File Line: 1029
// RVA: 0x491730
void __fastcall UFG::XMLWrapperGameSlice::~XMLWrapperGameSlice(UFG::XMLWrapperGameSlice *this)
{
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *mPrev; // rdx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *mNext; // rax

  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Progression,
    OUTPUT_LEVEL_DEBUG,
    "[GameSlice]:    Cleaned Game Slice (%s)\n");
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 1035
// RVA: 0x4988F0
void __fastcall UFG::XMLWrapperGameSlice::CollectWorkStatus(
        UFG::XMLWrapperGameSlice *this,
        SimpleXML::XMLDocument *pDocument,
        SimpleXML::XMLNode *pXMLNode)
{
  UFG::XMLWrapperGameSlice *v4; // rbx
  int v5; // edi
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *i; // r15
  char *Value; // r14
  char *Name; // r12
  UFG::GameSlice *mpGameSlice; // rcx
  char v11; // bp
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *mNext; // rbx
  UFG::allocator::free_link *p_mMissionStates; // rsi
  UFG::allocator::free_link *v14; // rbx
  UFG::allocator::free_link *v15; // rax
  UFG::qString text; // [rsp+30h] [rbp-88h] BYREF
  UFG::qString v17; // [rsp+58h] [rbp-60h] BYREF

  v4 = this;
  v5 = 0;
  ChildNode = SimpleXML::XMLDocument::GetChildNode(pDocument, "workstatus", pXMLNode);
  if ( ChildNode )
  {
    for ( i = SimpleXML::XMLDocument::GetChildNode(pDocument, 0i64, ChildNode); i; v4 = this )
    {
      Value = SimpleXML::XMLNode::GetValue(i);
      Name = SimpleXML::XMLNode::GetName(i);
      mpGameSlice = v4->mpGameSlice;
      v11 = 0;
      mNext = mpGameSlice->mMissionStates.mNode.mNext;
      p_mMissionStates = (UFG::allocator::free_link *)&mpGameSlice->mMissionStates;
      if ( mNext == (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)&mpGameSlice->mMissionStates )
        goto LABEL_8;
      do
      {
        if ( !(unsigned int)UFG::qStringCompareInsensitive(Name, (const char *)mNext[2].mNext, -1) )
        {
          v11 = 1;
          UFG::qString::Set((UFG::qString *)&mNext[3].mNext, Value);
        }
        mNext = mNext->mNext;
      }
      while ( mNext != (UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *)p_mMissionStates );
      if ( !v11 )
      {
LABEL_8:
        v14 = UFG::qMalloc(0x60ui64, UFG::gGlobalNewName, 0i64);
        if ( v14 )
        {
          UFG::qString::qString(&v17, Value);
          UFG::qString::qString(&text, Name);
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
        v15 = p_mMissionStates->mNext;
        v15[1].mNext = v14;
        v14->mNext = v15;
        v14[1].mNext = p_mMissionStates;
        p_mMissionStates->mNext = v14;
        if ( (v5 & 2) != 0 )
        {
          v5 &= ~2u;
          UFG::qString::~qString(&text);
        }
        if ( (v5 & 1) != 0 )
        {
          v5 &= ~1u;
          UFG::qString::~qString(&v17);
        }
      }
      i = SimpleXML::XMLDocument::GetNode(pDocument, 0i64, i);
    }
  }
}

// File Line: 1088
// RVA: 0x4A5A90
UFG::SceneSettings *__fastcall UFG::XMLWrapperGameSlice::GetOrCreateSceneSettings(UFG::XMLWrapperGameSlice *this)
{
  unsigned int v2; // eax
  UFG::SceneSettings *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::SceneSettings *v5; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v9; // [rsp+68h] [rbp+10h]

  UFG::qString::qString(&v7, "SliceSettings_");
  UFG::qString::operator+=(&v7, this->mpGameSlice->mName.mText);
  UFG::qSymbol::create_from_string(&result, v7.mData);
  v2 = _S19_1;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v2 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( result.mUID )
  {
    v3 = (UFG::SceneSettings *)UFG::qBaseTreeRB::Get(&stru_14240A220, result.mUID);
    v2 = _S19_1;
  }
  else
  {
    v3 = 0i64;
  }
  if ( !v3 )
  {
    if ( (v2 & 1) == 0 )
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
    UFG::qBaseTreeRB::Add(&stru_14240A220, &v3->mNode);
    this->mpGameSlice->mSceneSettings = v3;
  }
  UFG::qString::~qString(&v7);
  return v3;
}

