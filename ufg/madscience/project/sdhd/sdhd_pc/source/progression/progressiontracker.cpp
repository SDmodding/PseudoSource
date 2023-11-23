// File Line: 161
// RVA: 0x152C070
__int64 dynamic_initializer_for__gDirectGameSliceId__()
{
  UFG::qString::qString(&gDirectGameSliceId);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDirectGameSliceId__);
}

// File Line: 173
// RVA: 0x152C030
__int64 UFG::_dynamic_initializer_for__gDefaultFlowId__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Main", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gDefaultFlowId, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gDefaultFlowId__);
}

// File Line: 181
// RVA: 0x4AB740
UFG::ProgressionTracker *__fastcall UFG::ProgressionTracker::Instance()
{
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  return &sProgressionTracker;
}

// File Line: 190
// RVA: 0x4A33B0
UFG::GameSetup *__fastcall UFG::ProgressionTracker::GetGameSetup(UFG::ProgressionTracker *this)
{
  return &this->mGameSetup;
}

// File Line: 195
// RVA: 0x4BB850
void __fastcall UFG::ProgressionTracker::SetActiveFlow(
        UFG::ProgressionTracker *this,
        UFG::qArray<unsigned long,0> *flowId)
{
  this->mActiveFlowId.mUID = flowId->size;
  if ( (_S13_4 & 1) == 0 )
  {
    _S13_4 |= 1u;
    UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
    atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
  }
  UFG::GameSaveLoad::SetActiveFlow(&sGameSaveLoad, flowId);
}

// File Line: 202
// RVA: 0x4A1920
UFG::qSymbol *__fastcall UFG::ProgressionTracker::GetActiveFlow(UFG::ProgressionTracker *this)
{
  return &this->mActiveFlowId;
}

// File Line: 207
// RVA: 0x4A22A0
UFG::qStaticSymbol *__fastcall UFG::ProgressionTracker::GetDefaultFlow()
{
  return &gDefaultFlowId;
}

// File Line: 212
// RVA: 0x4A3310
UFG::qPropertySet *__fastcall UFG::ProgressionTracker::GetGameFlowProperties(
        UFG::ProgressionTracker *this,
        UFG::qArray<unsigned long,0> *flowId)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+18h] BYREF

  v3 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0x3971E8ABu);
  PropertySet = UFG::PropertySetManager::FindPropertySet(v3);
  if ( PropertySet )
    return UFG::qPropertySet::Get<UFG::qPropertySet>(PropertySet, flowId, DEPTH_RECURSE);
  return PropertySet;
}

// File Line: 235
// RVA: 0x4A07F0
UFG::qBaseTreeRB *__fastcall UFG::ProgressionTracker::FindSceneSettings(
        UFG::ProgressionTracker *this,
        UFG::qSymbol *name)
{
  unsigned int mUID; // edx

  mUID = name->mUID;
  if ( mUID )
    return UFG::qBaseTreeRB::Get(&this->mSceneSettings.mTree, mUID);
  else
    return 0i64;
}

// File Line: 241
// RVA: 0x4B3D30
void __fastcall UFG::ReadMasks(
        SimpleXML::XMLDocument *pDocument,
        SimpleXML::XMLNode *pGameSliceXMLNode,
        UFG::XMLWrapperGameSlice *xmlSlice)
{
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *i; // rbp
  char *Attribute; // rdi
  char *v9; // rsi
  UFG::GameSlice *mpGameSlice; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::GameSliceMasks *v12; // rbx
  int TypeFromCategoryName; // eax
  UFG::GameSlice *v14; // rbx
  UFG::allocator::free_link *v15; // rax
  SimpleXML::XMLNode *v16; // rax
  SimpleXML::XMLNode *j; // rsi
  char *v18; // rdi
  char *v19; // rbp
  UFG::GameSlice *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::GameSliceMasks *v22; // rbx
  int v23; // eax
  UFG::GameSlice *v24; // rbx
  UFG::allocator::free_link *v25; // rax
  UFG::qString name; // [rsp+28h] [rbp-80h] BYREF
  UFG::qString sliceName; // [rsp+50h] [rbp-58h] BYREF

  ChildNode = SimpleXML::XMLDocument::GetChildNode(pDocument, "enablemasks", pGameSliceXMLNode);
  if ( ChildNode )
  {
    for ( i = SimpleXML::XMLDocument::GetChildNode(pDocument, "enable", ChildNode);
          i;
          i = SimpleXML::XMLDocument::GetNode(pDocument, "enable", i) )
    {
      Attribute = SimpleXML::XMLNode::GetAttribute(i, "forcategory");
      v9 = SimpleXML::XMLNode::GetAttribute(i, "for");
      if ( Attribute )
      {
        UFG::qString::qString(&name, Attribute);
        mpGameSlice = xmlSlice->mpGameSlice;
        if ( !mpGameSlice->maMasks[0] )
        {
          v11 = UFG::qMalloc(0x20ui64, "GameSliceMasks", 0i64);
          if ( v11 )
          {
            v11[2].mNext = 0i64;
            v11[3].mNext = 0i64;
            v11->mNext = 0i64;
            LODWORD(v11[1].mNext) = 0;
          }
          else
          {
            v11 = 0i64;
          }
          mpGameSlice->maMasks[0] = (UFG::GameSliceMasks *)v11;
        }
        v12 = mpGameSlice->maMasks[0];
        TypeFromCategoryName = UFG::GameSlice::GetTypeFromCategoryName(&name);
        if ( TypeFromCategoryName != 12 )
          v12->mEnabledCategory[TypeFromCategoryName] = 1;
        UFG::qString::~qString(&name);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  Scenario: Adding EnableCategoryMask: %s\n");
      }
      if ( v9 )
      {
        UFG::qString::qString(&sliceName, v9);
        v14 = xmlSlice->mpGameSlice;
        if ( !v14->maMasks[0] )
        {
          v15 = UFG::qMalloc(0x20ui64, "GameSliceMasks", 0i64);
          if ( v15 )
          {
            v15[2].mNext = 0i64;
            v15[3].mNext = 0i64;
            v15->mNext = 0i64;
            LODWORD(v15[1].mNext) = 0;
          }
          else
          {
            v15 = 0i64;
          }
          v14->maMasks[0] = (UFG::GameSliceMasks *)v15;
        }
        UFG::GameSliceMasks::AddMask(v14->maMasks[0], &sliceName);
        UFG::qString::~qString(&sliceName);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  Scenario: Adding EnableMask: %s\n");
      }
    }
  }
  v16 = SimpleXML::XMLDocument::GetChildNode(pDocument, "disablemasks", pGameSliceXMLNode);
  if ( v16 )
  {
    for ( j = SimpleXML::XMLDocument::GetChildNode(pDocument, "disable", v16);
          j;
          j = SimpleXML::XMLDocument::GetNode(pDocument, "disable", j) )
    {
      v18 = SimpleXML::XMLNode::GetAttribute(j, "forcategory");
      v19 = SimpleXML::XMLNode::GetAttribute(j, "for");
      if ( v18 )
      {
        UFG::qString::qString(&sliceName, v18);
        v20 = xmlSlice->mpGameSlice;
        if ( !v20->maMasks[1] )
        {
          v21 = UFG::qMalloc(0x20ui64, "GameSliceMasks", 0i64);
          if ( v21 )
          {
            v21[2].mNext = 0i64;
            v21[3].mNext = 0i64;
            v21->mNext = 0i64;
            LODWORD(v21[1].mNext) = 0;
          }
          else
          {
            v21 = 0i64;
          }
          v20->maMasks[1] = (UFG::GameSliceMasks *)v21;
        }
        v22 = v20->maMasks[1];
        v23 = UFG::GameSlice::GetTypeFromCategoryName(&sliceName);
        if ( v23 != 12 )
          v22->mEnabledCategory[v23] = 1;
        UFG::qString::~qString(&sliceName);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  Adding DisableCategoryMask: %s\n");
      }
      if ( v19 )
      {
        UFG::qString::qString(&name, v19);
        v24 = xmlSlice->mpGameSlice;
        if ( !v24->maMasks[1] )
        {
          v25 = UFG::qMalloc(0x20ui64, "GameSliceMasks", 0i64);
          if ( v25 )
          {
            v25[2].mNext = 0i64;
            v25[3].mNext = 0i64;
            v25->mNext = 0i64;
            LODWORD(v25[1].mNext) = 0;
          }
          else
          {
            v25 = 0i64;
          }
          v24->maMasks[1] = (UFG::GameSliceMasks *)v25;
        }
        UFG::GameSliceMasks::AddMask(v24->maMasks[1], &name);
        UFG::qString::~qString(&name);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  Adding DisableMask: %s\n");
      }
    }
  }
}

// File Line: 291
// RVA: 0x4C7C30
void __fastcall UFG::UpdatePlayerDismountLocation(UFG *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCharacter *v2; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax

  LocalPlayer = UFG::GetLocalPlayer();
  v2 = LocalPlayer;
  if ( LocalPlayer )
  {
    if ( UFG::SimObjectUtility::IsCharacterInVehicle(LocalPlayer) )
    {
      m_pTransformNodeComponent = v2->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        y = m_pTransformNodeComponent->mWorldTransform.v3.y;
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
        v7 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
          v7->mpSnapshots[0]->mFloats[99].mValue = x;
        v8 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
          v8->mpSnapshots[0]->mFloats[100].mValue = y;
        v9 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v9 + 6216) & 1) == 0 )
          v9->mpSnapshots[0]->mFloats[101].mValue = z;
      }
    }
  }
}

// File Line: 310
// RVA: 0x4AF1A0
__int64 __fastcall UFG::ProgressionTracker::LoadSupportFile(
        UFG::ProgressionTracker *this,
        const char *pLocationPath,
        const char *pFilename,
        UFG::ProgressionTracker *pAuthor)
{
  float v4; // xmm0_4
  SimpleXML::XMLNode *v6; // rax
  SimpleXML::XMLDocument *v7; // rbx
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *i; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  SimpleXML::XMLNode *v12; // rax
  SimpleXML::XMLNode *ChildNode; // rax
  char *v14; // rcx
  __int64 v15; // rdi
  __int64 v16; // rsi
  __int64 v17; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  SimpleXML::XMLNode *v20; // rax
  char *v21; // rax
  __int64 v22; // rdi
  __int64 v23; // rsi
  __int64 v24; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  SimpleXML::XMLNode *v27; // rax
  char *v28; // rax
  __int64 v29; // rdi
  __int64 v30; // rsi
  __int64 v31; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rax
  SimpleXML::XMLNode *v34; // rax
  char *v35; // rax
  __int64 v36; // rdi
  __int64 v37; // rsi
  __int64 v38; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v39; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v40; // rax
  SimpleXML::XMLNode *v41; // rax
  char *v42; // rax
  __int64 v43; // rdi
  __int64 v44; // rsi
  __int64 v45; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v46; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v47; // rax
  SimpleXML::XMLNode *v48; // rax
  char *v49; // rax
  __int64 v50; // rdi
  __int64 v51; // rsi
  __int64 v52; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v53; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v54; // rax
  SimpleXML::XMLNode *v55; // rax
  char *v56; // rax
  __int64 v57; // rdi
  __int64 v58; // rsi
  __int64 v59; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v60; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v61; // rax
  SimpleXML::XMLNode *v62; // rax
  char *v63; // rax
  __int64 v64; // rdi
  __int64 v65; // rsi
  __int64 v66; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v67; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v68; // rax
  SimpleXML::XMLNode *v69; // rax
  char *v70; // rax
  __int64 v71; // rdi
  __int64 v72; // rsi
  __int64 v73; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v74; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v75; // rax
  SimpleXML::XMLNode *v76; // rax
  char *v77; // rax
  __int64 v78; // rdi
  __int64 v79; // rsi
  __int64 v80; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v81; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v82; // rax
  SimpleXML::XMLNode *v83; // rax
  char *v84; // rcx
  __int64 v85; // rdi
  __int64 v86; // rsi
  __int64 v87; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v88; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v89; // rax
  SimpleXML::XMLNode *v90; // rsi
  char *v91; // rax
  __int64 v92; // rdi
  __int64 v93; // rbx
  __int64 v94; // rsi
  SimpleXML::XMLNode *v95; // rax
  SimpleXML::XMLNode *v96; // rdi
  char Attribute; // di
  SimpleXML::XMLNode *v98; // rax
  SimpleXML::XMLNode *v99; // rax
  char *Value; // rax
  UFG::qSymbol *v101; // rax
  SimpleXML::XMLNode *v102; // rax
  char *v103; // rax
  UFG::qSymbol *v104; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v105; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v106; // rax
  SimpleXML::XMLNode *v107; // rax
  SimpleXML::XMLNode *v108; // rdi
  char *v109; // rax
  char *v110; // rdi
  SimpleXML::XMLNode *v111; // rdi
  char *v112; // rax
  UFG::qBaseTreeRB *v113; // rdx
  __int64 v114; // rax
  char *v115; // rcx
  SimpleXML::XMLNode *v116; // rax
  SimpleXML::XMLNode *v117; // rdi
  char *v118; // rsi
  char *v119; // rdi
  const char *v120; // r9
  char *v121; // rsi
  SimpleXML::XMLNode *k; // rdi
  char *v123; // rsi
  char *v124; // rax
  UFG::qSymbolUC *v125; // rax
  SimpleXML::XMLNode *m; // rsi
  char *v127; // rdi
  UFG::allocator::free_link *v128; // rdi
  unsigned int mStringHash32; // eax
  UFG::qBaseNodeRB *v130; // rdx
  SimpleXML::XMLNode *v131; // rax
  SimpleXML::XMLNode *n; // rdi
  SimpleXML::XMLNode *v133; // rax
  SimpleXML::XMLNode *v134; // rsi
  SimpleXML::XMLNode *v135; // rdi
  UFG::ProgressionTracker *v136; // rsi
  char *v137; // rax
  SimpleXML::XMLNode *v138; // rax
  char *v139; // rax
  UFG::ProgressionTracker *v140; // rdi
  char *caption; // [rsp+28h] [rbp-79h]
  char *captiona; // [rsp+28h] [rbp-79h]
  char *captionb; // [rsp+28h] [rbp-79h]
  char *captionc; // [rsp+28h] [rbp-79h]
  char *captiond; // [rsp+28h] [rbp-79h]
  char *captione; // [rsp+28h] [rbp-79h]
  char *captionf; // [rsp+28h] [rbp-79h]
  char *captiong; // [rsp+28h] [rbp-79h]
  char *captionh; // [rsp+28h] [rbp-79h]
  char *captioni; // [rsp+28h] [rbp-79h]
  char *captionj; // [rsp+28h] [rbp-79h]
  char *captionk; // [rsp+28h] [rbp-79h]
  char *captionl; // [rsp+28h] [rbp-79h]
  SimpleXML::XMLNode *prev_node; // [rsp+30h] [rbp-71h] BYREF
  char *format; // [rsp+38h] [rbp-69h]
  UFG::qString xmlSlice; // [rsp+40h] [rbp-61h] BYREF
  SimpleXML::XMLNode *j; // [rsp+68h] [rbp-39h]
  UFG::qSymbol v159[2]; // [rsp+70h] [rbp-31h] BYREF
  char v160; // [rsp+78h] [rbp-29h]
  char v161; // [rsp+79h] [rbp-28h]
  char v162; // [rsp+7Ah] [rbp-27h]
  char v163; // [rsp+7Bh] [rbp-26h]
  char *log; // [rsp+80h] [rbp-21h]
  SimpleXML::XMLNode *v165; // [rsp+88h] [rbp-19h]
  UFG::qString collectionName; // [rsp+90h] [rbp-11h] BYREF
  __int64 v167; // [rsp+B8h] [rbp+17h]
  UFG::qString result; // [rsp+C0h] [rbp+1Fh] BYREF
  UFG::ProgressionTracker *v169; // [rsp+108h] [rbp+67h]
  char *pLocationPatha; // [rsp+110h] [rbp+6Fh]

  v167 = -2i64;
  UFG::qString::FormatEx((UFG::qString *)&result.mData, "%s\\%s", pLocationPath, pFilename);
  v6 = (SimpleXML::XMLNode *)SimpleXML::XMLDocument::Open(result.mData, 1ui64, 0i64);
  v7 = (SimpleXML::XMLDocument *)v6;
  j = v6;
  if ( v6 )
  {
    Node = SimpleXML::XMLDocument::GetNode((SimpleXML::XMLDocument *)v6, "gameslices", 0i64);
    if ( Node )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v7, "gameslice", Node);
            i;
            i = SimpleXML::XMLDocument::GetNode(v7, "gameslice", i) )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          i,
          pAuthor->gActiveGameSlices);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        mPrev = xmlSlice.mPrev;
        mNext = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        mNext->mPrev = mPrev;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
      }
    }
    v12 = SimpleXML::XMLDocument::GetNode(v7, "groups", 0i64);
    *(_QWORD *)&v159[0].mUID = v12;
    if ( v12 )
    {
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v7, "disabled", v12);
      for ( prev_node = ChildNode; ChildNode; prev_node = ChildNode )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          ChildNode,
          pAuthor->gActiveGameSlices);
        v14 = *(char **)&xmlSlice.mMagic;
        caption = *(char **)&xmlSlice.mMagic;
        v15 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v16 = *(_QWORD *)&xmlSlice.mMagic;
          v17 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v16 + 400) + 8 * v15++), TYPE_CULL);
          while ( v15 < v17 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v14 = caption;
        }
        *((_DWORD *)v14 + 67) = 0;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v18 = xmlSlice.mPrev;
        v19 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v19->mPrev = v18;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        ChildNode = SimpleXML::XMLDocument::GetNode(v7, "disabled", prev_node);
      }
      v20 = SimpleXML::XMLDocument::GetChildNode(v7, "fail", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v20; v20; prev_node = v20 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v20,
          pAuthor->gActiveGameSlices);
        v21 = *(char **)&xmlSlice.mMagic;
        captiona = *(char **)&xmlSlice.mMagic;
        v22 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v23 = *(_QWORD *)&xmlSlice.mMagic;
          v24 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v23 + 400) + 8 * v22++), NUM_TYPES);
          while ( v22 < v24 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v21 = captiona;
        }
        *((_DWORD *)v21 + 67) = 2;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v25 = xmlSlice.mPrev;
        v26 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v26->mPrev = v25;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v20 = SimpleXML::XMLDocument::GetNode(v7, "fail", prev_node);
      }
      v27 = SimpleXML::XMLDocument::GetChildNode(v7, "scenario", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v27; v27; prev_node = v27 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v27,
          pAuthor->gActiveGameSlices);
        v28 = *(char **)&xmlSlice.mMagic;
        captionb = *(char **)&xmlSlice.mMagic;
        v29 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v30 = *(_QWORD *)&xmlSlice.mMagic;
          v31 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v30 + 400) + 8 * v29++), NUM_TYPES|TYPE_OCCLUSION);
          while ( v29 < v31 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v28 = captionb;
        }
        *((_DWORD *)v28 + 67) = 3;
        UFG::ReadMasks(v7, prev_node, (UFG::XMLWrapperGameSlice *)&xmlSlice);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v32 = xmlSlice.mPrev;
        v33 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v33->mPrev = v32;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v27 = SimpleXML::XMLDocument::GetNode(v7, "scenario", prev_node);
      }
      v34 = SimpleXML::XMLDocument::GetChildNode(v7, "mission", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v34; v34; prev_node = v34 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v34,
          pAuthor->gActiveGameSlices);
        v35 = *(char **)&xmlSlice.mMagic;
        captionc = *(char **)&xmlSlice.mMagic;
        v36 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v37 = *(_QWORD *)&xmlSlice.mMagic;
          v38 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(
              *(UFG::GameSlice **)(*(_QWORD *)(v37 + 400) + 8 * v36++),
              NUM_TYPES|TYPE_OCCLUSION|0x8);
          while ( v36 < v38 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v35 = captionc;
        }
        *((_DWORD *)v35 + 67) = 11;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v39 = xmlSlice.mPrev;
        v40 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v40->mPrev = v39;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v34 = SimpleXML::XMLDocument::GetNode(v7, "mission", prev_node);
      }
      v41 = SimpleXML::XMLDocument::GetChildNode(v7, "case", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v41; v41; prev_node = v41 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v41,
          pAuthor->gActiveGameSlices);
        v42 = *(char **)&xmlSlice.mMagic;
        captiond = *(char **)&xmlSlice.mMagic;
        v43 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v44 = *(_QWORD *)&xmlSlice.mMagic;
          v45 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v44 + 400) + 8 * v43++), (UFG::GameSlice::Type)10);
          while ( v43 < v45 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v42 = captiond;
        }
        *((_DWORD *)v42 + 67) = 10;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v46 = xmlSlice.mPrev;
        v47 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v47->mPrev = v46;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v41 = SimpleXML::XMLDocument::GetNode(v7, "case", prev_node);
      }
      v48 = SimpleXML::XMLDocument::GetChildNode(v7, "date", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v48; v48; prev_node = v48 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v48,
          pAuthor->gActiveGameSlices);
        v49 = *(char **)&xmlSlice.mMagic;
        captione = *(char **)&xmlSlice.mMagic;
        v50 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v51 = *(_QWORD *)&xmlSlice.mMagic;
          v52 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v51 + 400) + 8 * v50++), (UFG::GameSlice::Type)9);
          while ( v50 < v52 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v49 = captione;
        }
        *((_DWORD *)v49 + 67) = 9;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v53 = xmlSlice.mPrev;
        v54 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v54->mPrev = v53;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v48 = SimpleXML::XMLDocument::GetNode(v7, "date", prev_node);
      }
      v55 = SimpleXML::XMLDocument::GetChildNode(v7, "event", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v55; v55; prev_node = v55 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v55,
          pAuthor->gActiveGameSlices);
        v56 = *(char **)&xmlSlice.mMagic;
        captionf = *(char **)&xmlSlice.mMagic;
        v57 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v58 = *(_QWORD *)&xmlSlice.mMagic;
          v59 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v58 + 400) + 8 * v57++), (UFG::GameSlice::Type)5);
          while ( v57 < v59 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v56 = captionf;
        }
        *((_DWORD *)v56 + 67) = 5;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v60 = xmlSlice.mPrev;
        v61 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v61->mPrev = v60;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v55 = SimpleXML::XMLDocument::GetNode(v7, "event", prev_node);
      }
      v62 = SimpleXML::XMLDocument::GetChildNode(v7, "favour", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v62; v62; prev_node = v62 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v62,
          pAuthor->gActiveGameSlices);
        v63 = *(char **)&xmlSlice.mMagic;
        captiong = *(char **)&xmlSlice.mMagic;
        v64 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v65 = *(_QWORD *)&xmlSlice.mMagic;
          v66 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v65 + 400) + 8 * v64++), (UFG::GameSlice::Type)6);
          while ( v64 < v66 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v63 = captiong;
        }
        *((_DWORD *)v63 + 67) = 6;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v67 = xmlSlice.mPrev;
        v68 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v68->mPrev = v67;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v62 = SimpleXML::XMLDocument::GetNode(v7, "favour", prev_node);
      }
      v69 = SimpleXML::XMLDocument::GetChildNode(v7, "job", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v69; v69; prev_node = v69 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v69,
          pAuthor->gActiveGameSlices);
        v70 = *(char **)&xmlSlice.mMagic;
        captionh = *(char **)&xmlSlice.mMagic;
        v71 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v72 = *(_QWORD *)&xmlSlice.mMagic;
          v73 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(
              *(UFG::GameSlice **)(*(_QWORD *)(v72 + 400) + 8 * v71++),
              NUM_TYPES|TYPE_OCCLUSION|0x4);
          while ( v71 < v73 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v70 = captionh;
        }
        *((_DWORD *)v70 + 67) = 7;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v74 = xmlSlice.mPrev;
        v75 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v75->mPrev = v74;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v69 = SimpleXML::XMLDocument::GetNode(v7, "job", prev_node);
      }
      v76 = SimpleXML::XMLDocument::GetChildNode(v7, "race", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v76; v76; prev_node = v76 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v76,
          pAuthor->gActiveGameSlices);
        v77 = *(char **)&xmlSlice.mMagic;
        captioni = *(char **)&xmlSlice.mMagic;
        v78 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v79 = *(_QWORD *)&xmlSlice.mMagic;
          v80 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v79 + 400) + 8 * v78++), (UFG::GameSlice::Type)8);
          while ( v78 < v80 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v77 = captioni;
        }
        *((_DWORD *)v77 + 67) = 8;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v81 = xmlSlice.mPrev;
        v82 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v82->mPrev = v81;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v76 = SimpleXML::XMLDocument::GetNode(v7, "race", prev_node);
      }
      v83 = SimpleXML::XMLDocument::GetChildNode(v7, "ambient", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( prev_node = v83; v83; prev_node = v83 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v83,
          pAuthor->gActiveGameSlices);
        v84 = *(char **)&xmlSlice.mMagic;
        captionj = *(char **)&xmlSlice.mMagic;
        v85 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v86 = *(_QWORD *)&xmlSlice.mMagic;
          v87 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v86 + 400) + 8 * v85++), TYPE_OCCLUSION);
          while ( v85 < v87 );
          v7 = (SimpleXML::XMLDocument *)j;
          pAuthor = this;
          v84 = captionj;
        }
        *((_DWORD *)v84 + 67) = 1;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v88 = xmlSlice.mPrev;
        v89 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v89->mPrev = v88;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v83 = SimpleXML::XMLDocument::GetNode(v7, "ambient", prev_node);
      }
      v90 = SimpleXML::XMLDocument::GetChildNode(v7, "sprinkle", *(SimpleXML::XMLNode **)&v159[0].mUID);
      for ( log = (char *)v90; v90; log = (char *)v90 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(
          (UFG::XMLWrapperGameSlice *)&xmlSlice,
          v7,
          v90,
          this->gActiveGameSlices);
        v91 = *(char **)&xmlSlice.mMagic;
        captionk = *(char **)&xmlSlice.mMagic;
        v92 = 0i64;
        if ( *(_DWORD *)(*(_QWORD *)&xmlSlice.mMagic + 392i64) )
        {
          v93 = *(_QWORD *)&xmlSlice.mMagic;
          v94 = *(unsigned int *)(*(_QWORD *)&xmlSlice.mMagic + 392i64);
          do
            UFG::GameSlice::SetType(*(UFG::GameSlice **)(*(_QWORD *)(v93 + 400) + 8 * v92++), (UFG::GameSlice::Type)4);
          while ( v92 < v94 );
          v7 = (SimpleXML::XMLDocument *)j;
          v90 = (SimpleXML::XMLNode *)log;
          v91 = captionk;
        }
        *((_DWORD *)v91 + 67) = 4;
        v95 = SimpleXML::XMLDocument::GetChildNode(v7, "collection", v90);
        v96 = v95;
        if ( v95 )
        {
          format = SimpleXML::XMLNode::GetAttribute(v95, "name");
          Attribute = SimpleXML::XMLNode::GetAttribute(v96, "highpriority", 0);
          if ( format )
          {
            UFG::qString::qString(&collectionName, format);
            UFG::GameSlice::SetCollection(*(UFG::GameSlice **)&xmlSlice.mMagic, &collectionName, Attribute);
            UFG::qString::~qString(&collectionName);
          }
        }
        UFG::ReadMasks(v7, v90, (UFG::XMLWrapperGameSlice *)&xmlSlice);
        v98 = SimpleXML::XMLDocument::GetChildNode(v7, "singlecharacter", v90);
        if ( v98 && SimpleXML::XMLNode::GetBool(v98, 0) )
          *(_BYTE *)(*(_QWORD *)&xmlSlice.mMagic + 481i64) = 1;
        v99 = SimpleXML::XMLDocument::GetChildNode(v7, "character1override", v90);
        if ( v99 )
        {
          Value = SimpleXML::XMLNode::GetValue(v99);
          if ( Value )
          {
            v101 = UFG::qSymbol::create_from_string(v159, Value);
            *(UFG::qSymbol *)(*(_QWORD *)&xmlSlice.mMagic + 484i64) = (UFG::qSymbol)v101->mUID;
          }
        }
        v102 = SimpleXML::XMLDocument::GetChildNode(v7, "character2override", v90);
        if ( v102 )
        {
          v103 = SimpleXML::XMLNode::GetValue(v102);
          if ( v103 )
          {
            v104 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&prev_node, v103);
            *(UFG::qSymbol *)(*(_QWORD *)&xmlSlice.mMagic + 488i64) = (UFG::qSymbol)v104->mUID;
          }
        }
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v105 = xmlSlice.mPrev;
        v106 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v106->mPrev = v105;
        xmlSlice.mPrev = &xmlSlice;
        xmlSlice.mNext = &xmlSlice;
        v90 = SimpleXML::XMLDocument::GetNode(v7, "sprinkle", v90);
      }
    }
    v107 = SimpleXML::XMLDocument::GetNode(v7, "casegroups", 0i64);
    if ( v107 )
    {
      v108 = SimpleXML::XMLDocument::GetChildNode(v7, "casegroup", v107);
      j = v108;
      if ( v108 )
      {
        while ( 1 )
        {
          if ( (_S19_1 & 1) == 0 )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          v109 = SimpleXML::XMLNode::GetAttribute(v108, "properties");
          UFG::qSymbol::create_from_string(v159, v109);
          v110 = (char *)&unk_14240A3F0 + 80 * dword_14240A3E8[0]++;
          UFG::qSymbol::set_null((UFG::qSymbol *)v110);
          *((_DWORD *)v110 + 18) = 0;
          format = v110 + 8;
          *((_DWORD *)v110 + 2) = 0;
          *(UFG::qSymbol *)v110 = v159[0];
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Progression,
            OUTPUT_LEVEL_DEBUG,
            "[Progression]:  CaseGroup: %s\n");
          v111 = SimpleXML::XMLDocument::GetChildNode(v7, "case", j);
          if ( v111 )
            break;
LABEL_103:
          v108 = SimpleXML::XMLDocument::GetNode(v7, "casegroup", j);
          j = v108;
          if ( !v108 )
            goto LABEL_104;
        }
        while ( 1 )
        {
          v112 = SimpleXML::XMLNode::GetAttribute(v111, "name");
          UFG::qSymbol::create_from_string((UFG::qSymbol *)&prev_node, v112);
          if ( !(_DWORD)prev_node )
            break;
          v113 = UFG::qBaseTreeRB::Get(&stru_14240A190, (unsigned int)prev_node);
          if ( !v113 )
          {
            if ( !(_DWORD)prev_node )
              break;
            v113 = UFG::qBaseTreeRB::Get(&stru_14240A100, (unsigned int)prev_node);
            if ( !v113 )
            {
              if ( !(_DWORD)prev_node )
                break;
              v113 = UFG::qBaseTreeRB::Get(&stru_14240A148, (unsigned int)prev_node);
            }
          }
LABEL_102:
          v114 = *(unsigned int *)format;
          v115 = &format[8 * v114];
          *(_DWORD *)format = v114 + 1;
          *((_QWORD *)v115 + 1) = v113;
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Progression,
            OUTPUT_LEVEL_DEBUG,
            "[Progression]:    Case: %s\n");
          v111 = SimpleXML::XMLDocument::GetNode(v7, "case", v111);
          if ( !v111 )
            goto LABEL_103;
        }
        v113 = 0i64;
        goto LABEL_102;
      }
    }
LABEL_104:
    v116 = SimpleXML::XMLDocument::GetNode(v7, "objectives", 0i64);
    v165 = v116;
    if ( v116 )
    {
      v117 = SimpleXML::XMLDocument::GetChildNode(v7, "objective", v116);
      for ( j = v117; v117; j = v117 )
      {
        format = SimpleXML::XMLNode::GetAttribute(v117, "name");
        SimpleXML::XMLNode::GetAttribute(v117, "caption");
        v118 = SimpleXML::XMLNode::GetAttribute(v117, "location_caption");
        log = SimpleXML::XMLNode::GetAttribute(v117, "log");
        v119 = SimpleXML::XMLNode::GetAttribute(v117, "gps_marker");
        v160 = SimpleXML::XMLNode::GetAttribute(j, "secondary", 0);
        v162 = SimpleXML::XMLNode::GetAttribute(j, "uses_pda", 0);
        v161 = SimpleXML::XMLNode::GetAttribute(j, "autoflash", 1);
        v163 = SimpleXML::XMLNode::GetAttribute(j, "text_unlockable", 0);
        v159[0].mUID = SimpleXML::XMLNode::GetAttribute(j, "display_priority", 0);
        v120 = v118;
        v121 = v119;
        UFG::ObjectiveTracker::AddObjective(&v169->mObjectiveTracker, format, v119, v120, log, v119, 0i64);
        LOBYTE(v119) = v160;
        prev_node = (SimpleXML::XMLNode *)log;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  %s: %s - %s - %s\n");
        if ( (_BYTE)v119 )
          v121[154] = 1;
        if ( v162 )
          v121[155] = 1;
        if ( v161 )
          v121[152] = 1;
        if ( v163 )
          v121[153] = 1;
        *((UFG::qSymbol *)v121 + 58) = v159[0];
        for ( k = SimpleXML::XMLDocument::GetChildNode(v7, "indicator", j);
              k;
              k = SimpleXML::XMLDocument::GetNode(v7, "indicator", k) )
        {
          format = SimpleXML::XMLNode::GetAttribute(k, "name");
          v123 = SimpleXML::XMLNode::GetAttribute(k, "blip");
          v124 = SimpleXML::XMLNode::GetAttribute(k, "corona");
          log = v124;
          if ( format && (v123 || v124) )
          {
            captionl = v124;
            UFG::qPrintChannel::Print(
              &UFG::gPrintChannel_HK_Progression,
              OUTPUT_LEVEL_DEBUG,
              "[Progression]:    Indicator: (%s)[%s]\n");
            UFG::qString::qString(&xmlSlice, log);
            UFG::qString::qString(&collectionName, v123);
            v125 = (UFG::qSymbolUC *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&prev_node, format);
            UFG::Objective::AddIndicator((UFG::Objective *)captionl, v125, &collectionName, &xmlSlice, 0);
            UFG::qString::~qString(&collectionName);
            UFG::qString::~qString(&xmlSlice);
          }
        }
        v117 = SimpleXML::XMLDocument::GetNode(v7, "objective", j);
      }
      for ( m = SimpleXML::XMLDocument::GetChildNode(v7, "objectivehint", v165);
            m;
            m = SimpleXML::XMLDocument::GetNode(v7, "objectivehint", m) )
      {
        v127 = SimpleXML::XMLNode::GetAttribute(m, "name");
        format = v127;
        v165 = (SimpleXML::XMLNode *)SimpleXML::XMLNode::GetAttribute(m, "caption");
        UFG::qString::qString(&collectionName, (const char *)v165);
        UFG::qString::qString(&xmlSlice, v127);
        v128 = UFG::qMalloc(0x50ui64, "ObjectiveTrackerHint", 0i64);
        log = (char *)v128;
        if ( v128 )
        {
          mStringHash32 = xmlSlice.mStringHash32;
          if ( xmlSlice.mStringHash32 == -1 )
          {
            mStringHash32 = UFG::qStringHash32(xmlSlice.mData, 0xFFFFFFFF);
            xmlSlice.mStringHash32 = mStringHash32;
          }
          v128[1].mNext = 0i64;
          v128[2].mNext = 0i64;
          v128[3].mNext = 0i64;
          LODWORD(v128[4].mNext) = mStringHash32;
          v128->mNext = (UFG::allocator::free_link *)&UFG::ObjectiveHint::`vftable;
          UFG::qString::qString((UFG::qString *)&v128[5], &collectionName);
        }
        else
        {
          v128 = 0i64;
        }
        if ( v128 )
          v130 = (UFG::qBaseNodeRB *)&v128[1];
        else
          v130 = 0i64;
        UFG::qBaseTreeRB::Add(&v169->mObjectiveTracker.mObjectiveHints.mTree, v130);
        UFG::qString::~qString(&xmlSlice);
        UFG::qString::~qString(&collectionName);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  ObjectiveHint: %s - %s\n");
      }
    }
    v131 = SimpleXML::XMLDocument::GetNode(v7, "scenesettingsgroup", 0i64);
    if ( v131 )
    {
      for ( n = SimpleXML::XMLDocument::GetChildNode(v7, "scenesettings", v131);
            n;
            n = SimpleXML::XMLDocument::GetNode(v7, "scenesettings", n) )
      {
        UFG::ProgressionTracker::ParseSceneSettings(v169, v7, n);
      }
    }
    v133 = SimpleXML::XMLDocument::GetNode(v7, "supportfiles", 0i64);
    v134 = v133;
    v165 = v133;
    if ( v133 )
    {
      v135 = SimpleXML::XMLDocument::GetChildNode(v7, "supportfile", v133);
      if ( v135 )
      {
        v136 = v169;
        do
        {
          v137 = SimpleXML::XMLNode::GetAttribute(v135, "name");
          UFG::ProgressionTracker::LoadSupportFile(v136, pLocationPatha, v137, 0i64, v4);
          v135 = SimpleXML::XMLDocument::GetNode(v7, "supportfile", v135);
        }
        while ( v135 );
        v134 = v165;
      }
      v138 = SimpleXML::XMLDocument::GetChildNode(v7, "dependencygraph", v134);
      if ( v138 )
      {
        v139 = SimpleXML::XMLNode::GetAttribute(v138, "name");
        if ( v139 )
        {
          UFG::qString::FormatEx(&xmlSlice, "%s\\%s", pLocationPatha, v139);
          v140 = v169;
          UFG::qString::Set(&v169->mDependencyGraphName, xmlSlice.mData, xmlSlice.mLength, 0i64, 0);
          UFG::ProgressionTracker::LoadDependencyGraph(v140);
          UFG::qString::~qString(&xmlSlice);
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v7);
    operator delete[](v7);
    LOBYTE(v7) = 1;
  }
  UFG::qString::~qString(&result);
  return (unsigned __int8)v7;
}

// File Line: 649
// RVA: 0x4B1FA0
void __fastcall UFG::ProgressionTracker::ParseSceneSettings(
        UFG::ProgressionTracker *this,
        SimpleXML::XMLDocument *pDocument,
        SimpleXML::XMLNode *pSceneSettingsXMLNode)
{
  char *Attribute; // r15
  UFG::qBaseTreeRB *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  SimpleXML::XMLNode *ChildNode; // rax
  char *v10; // rax
  SimpleXML::XMLNode *v11; // rax
  SimpleXML::XMLNode *v12; // rbx
  char *Value; // rax
  double v14; // xmm0_8
  SimpleXML::XMLNode *v15; // rax
  SimpleXML::XMLNode *v16; // rax
  SimpleXML::XMLNode *v17; // r14
  char *v18; // rbx
  double v19; // xmm0_8
  float v20; // xmm8_4
  char v21; // r14
  float WeatherIntensityFromString; // xmm0_4
  SimpleXML::XMLNode *v23; // rax
  SimpleXML::XMLNode *v24; // rbx
  double v25; // xmm0_8
  char v26; // bl
  SimpleXML::XMLNode *v27; // rax
  SimpleXML::XMLNode *v28; // rax
  SimpleXML::XMLNode *v29; // rax
  SimpleXML::XMLNode *v30; // rax
  SimpleXML::XMLNode *v31; // rax
  SimpleXML::XMLNode *v32; // rax
  UFG::qSymbol result; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v34; // [rsp+28h] [rbp-B0h]
  UFG::qString v35; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qString weather; // [rsp+58h] [rbp-80h] BYREF
  UFG::allocator::free_link *v37; // [rsp+F8h] [rbp+20h] BYREF

  v34 = -2i64;
  Attribute = SimpleXML::XMLNode::GetAttribute(pSceneSettingsXMLNode, "name");
  UFG::qSymbol::create_from_string(&result, Attribute);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( result.mUID )
    v6 = UFG::qBaseTreeRB::Get(&stru_14240A220, result.mUID);
  else
    v6 = 0i64;
  if ( !v6 )
  {
    UFG::qString::qString(&v35, Attribute);
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v7 = UFG::qMalloc(0x148ui64, "SceneSettings", 0i64);
    v37 = v7;
    if ( v7 )
    {
      UFG::SceneSettings::SceneSettings((UFG::SceneSettings *)v7, v35.mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A220, &v6->mRoot);
    UFG::qString::~qString(&v35);
  }
  ChildNode = SimpleXML::XMLDocument::GetChildNode(pDocument, "teleportlocationmarker", pSceneSettingsXMLNode);
  if ( ChildNode )
  {
    v10 = SimpleXML::XMLNode::GetAttribute(ChildNode, "name", &customCaption);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v37, v10);
    LODWORD(v6[1].mNULL.mChild[0]) = (_DWORD)v37;
  }
  v11 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vehicleteleportlocationmarker", pSceneSettingsXMLNode);
  v12 = v11;
  if ( v11 )
  {
    Value = SimpleXML::XMLNode::GetValue(v11);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v37, Value);
    v14 = SimpleXML::XMLNode::GetAttribute(v12, "range", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    HIDWORD(v6[1].mNULL.mChild[0]) = (_DWORD)v37;
    if ( *(float *)&v14 < 0.0 )
      v6->mCount = 1106247680;
    else
      v6->mCount = LODWORD(v14);
  }
  v15 = SimpleXML::XMLDocument::GetChildNode(pDocument, "vehicledestroy", pSceneSettingsXMLNode);
  if ( v15 )
    LOBYTE(v6[1].mNULL.mChild[1]) = SimpleXML::XMLNode::GetValue(v15) != 0i64;
  v16 = SimpleXML::XMLDocument::GetChildNode(pDocument, "forceweather", pSceneSettingsXMLNode);
  v17 = v16;
  if ( v16 )
  {
    v18 = SimpleXML::XMLNode::GetAttribute(v16, "type", "notset");
    v19 = SimpleXML::XMLNode::GetAttribute(v17, "wetness", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v20 = *(float *)&v19;
    v21 = SimpleXML::XMLNode::GetAttribute(v17, "locked", 0);
    UFG::qString::qString(&weather, v18);
    WeatherIntensityFromString = UFG::TimeOfDayManager::GetWeatherIntensityFromString(&weather);
    if ( WeatherIntensityFromString >= 0.0 )
    {
      UFG::qPrintf("ProgressionTracker::ParseSceneSettings:%s=%f\n", Attribute, v20);
      *(float *)&v6->mNULL.mParent = WeatherIntensityFromString;
      *((float *)&v6->mNULL.mParent + 1) = v20;
      LOBYTE(v6->mNULL.mChild[0]) = v21;
      BYTE1(v6->mNULL.mChild[1]) = 1;
    }
    UFG::qString::~qString(&weather);
  }
  v23 = SimpleXML::XMLDocument::GetChildNode(pDocument, "forcetime", pSceneSettingsXMLNode);
  v24 = v23;
  if ( v23 )
  {
    v25 = SimpleXML::XMLNode::GetAttribute(v23, "time", COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_N1_0)));
    v26 = SimpleXML::XMLNode::GetAttribute(v24, "locked", 0);
    if ( *(float *)&v25 >= 0.0 )
    {
      LODWORD(v37) = 0;
      if ( UFG::TimeOfDayManager::GetTimeInSeconds(*(float *)&v25, (int *)&v37) )
      {
        *((float *)v6->mNULL.mChild + 1) = (float)(int)v37;
        BYTE2(v6->mNULL.mChild[1]) = v26;
        LOBYTE(v6->mNULL.mChild[1]) = 1;
      }
    }
  }
  v27 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enableambientpedsonstart", pSceneSettingsXMLNode);
  if ( v27 )
    BYTE1(v6->mNULL.mUID) = SimpleXML::XMLNode::GetBool(v27, 1);
  v28 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enableambientpedsonend", pSceneSettingsXMLNode);
  if ( v28 )
    BYTE2(v6->mNULL.mUID) = SimpleXML::XMLNode::GetBool(v28, 1);
  v29 = SimpleXML::XMLDocument::GetChildNode(pDocument, "locktrafficonstart", pSceneSettingsXMLNode);
  if ( v29 )
    HIBYTE(v6->mNULL.mUID) = SimpleXML::XMLNode::GetBool(v29, 0);
  v30 = SimpleXML::XMLDocument::GetChildNode(pDocument, "unlocktrafficonend", pSceneSettingsXMLNode);
  if ( v30 )
    *((_BYTE *)&v6->mNULL.mUID + 4) = SimpleXML::XMLNode::GetBool(v30, 0);
  v31 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enabletrafficonstart", pSceneSettingsXMLNode);
  if ( v31 )
    *((_BYTE *)&v6->mNULL.mUID + 5) = SimpleXML::XMLNode::GetBool(v31, 1);
  v32 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enabletrafficonend", pSceneSettingsXMLNode);
  if ( v32 )
    *((_BYTE *)&v6->mNULL.mUID + 6) = SimpleXML::XMLNode::GetBool(v32, 1);
}

// File Line: 786
// RVA: 0x4C2400
void __fastcall UFG::ProgressionTracker::SyncCompleted(UFG::ProgressionTracker *this, bool simulateRewards)
{
  UFG::GameStatTracker *v4; // rbp
  UFG::GameStatTracker *v5; // rcx
  UFG::PersistentData::MapBool *v6; // r12
  UFG::PersistentData::MapFloat *mList; // rdi
  unsigned int i; // esi
  unsigned int size; // ecx
  bool v10; // cf
  UFG::qSymbol *v11; // rbx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qSymbolUC *v13; // rcx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int mIndex; // ebp
  UFG::PersistentData::MapFloat *j; // r15
  __int64 v18; // r14
  UFG::PersistentData::KeyValue *p; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v21; // rdx
  unsigned int v22; // edx
  UFG::qSymbolUC *v23; // rcx
  UFG::PersistentData::MapFloat::Iterator *Iterator; // rax
  UFG::PersistentData::MapFloat *v25; // rsi
  unsigned int k; // ebx
  unsigned int v27; // ecx
  bool v28; // cf
  UFG::qSymbol *v29; // rdi
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-50h] BYREF
  UFG::PersistentData::MapFloat::Iterator v31; // [rsp+38h] [rbp-40h] BYREF

  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v5 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = v5->mpSnapshots[0]->mpMapBools[75];
  UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v6, &result);
  mList = result.mList;
  for ( i = result.mIndex; ; ++i )
  {
    size = mList->mValues.size;
    if ( mList->mValues.size )
    {
      if ( size - 1 > 1 )
        break;
      v10 = i < mList[1].mValues.size;
    }
    else
    {
      v10 = i < LODWORD(mList->mValues.p);
    }
    if ( !v10 )
      break;
    if ( size )
    {
      if ( size - 1 > 1 )
        v11 = &UFG::gNullQSymbol;
      else
        v11 = (UFG::qSymbol *)mList[1].mValues.p + i;
    }
    else
    {
      v11 = (UFG::qSymbol *)(*(_QWORD *)&mList->mPersistentDataType + 8i64 * i);
    }
    if ( v11->mUID && (v12 = UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, v11->mUID)) != 0i64
      || (v11->mUID ? (v12 = UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, v11->mUID)) : (v12 = 0i64), v12) )
    {
      UFG::GameSlice::_SimulateComplete((UFG::GameSlice *)v12, simulateRewards);
    }
    else
    {
      if ( mList->mValues.size )
      {
        if ( mList->mValues.size - 1 > 1 )
          v13 = (UFG::qSymbolUC *)&UFG::gNullQSymbol;
        else
          v13 = (UFG::qSymbolUC *)mList[1].mValues.p + i;
      }
      else
      {
        v13 = (UFG::qSymbolUC *)(*(_QWORD *)&mList->mPersistentDataType + 8i64 * i);
      }
      UFG::qSymbol::as_cstr_dbg(v13);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_ERROR,
        "[Progression]: Unable to find gameslice to auto-complete (%s)\n");
    }
  }
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v14 = v4->mpSnapshots[0]->mpMapInts[23]->mValues.size;
  if ( v6->mKeepType )
  {
    if ( (unsigned int)(v6->mKeepType - 1) > 1 )
      v15 = 0;
    else
      v15 = v6->mNames.size;
  }
  else
  {
    v15 = v6->mValues.size;
  }
  if ( v15 == v14 || !v14 )
  {
    UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v4->mpSnapshots[0]->mpMapInts[23], &v31);
    mIndex = v31.mIndex;
    for ( j = v31.mList; mIndex < j->mValues.size; ++mIndex )
    {
      v18 = mIndex;
      p = j->mValues.p;
      mUID = p[v18].mKey.mUID;
      if ( !mUID || (v21 = UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, mUID)) == 0i64 )
      {
        v22 = p[mIndex].mKey.mUID;
        if ( v22 )
          v21 = UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, v22);
        else
          v21 = 0i64;
      }
      if ( v21 )
      {
        WORD2(v21[5].mRoot.mParent) = LOWORD(j->mValues.p[v18].mFloatValue);
      }
      else
      {
        if ( mList->mValues.size )
        {
          if ( mList->mValues.size - 1 > 1 )
            v23 = (UFG::qSymbolUC *)&UFG::gNullQSymbol;
          else
            v23 = (UFG::qSymbolUC *)mList[1].mValues.p + i;
        }
        else
        {
          v23 = (UFG::qSymbolUC *)(*(_QWORD *)&mList->mPersistentDataType + 8i64 * i);
        }
        UFG::qSymbol::as_cstr_dbg(v23);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_ERROR,
          "[Progression]: Unable to find gameslice to auto-complete (%s)\n");
      }
    }
  }
  Iterator = UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v6, &v31);
  *(_QWORD *)&result.mIndex = *(_QWORD *)&Iterator->mIndex;
  v25 = Iterator->mList;
  for ( k = result.mIndex; ; ++k )
  {
    v27 = v25->mValues.size;
    if ( v25->mValues.size )
    {
      if ( v27 - 1 > 1 )
        return;
      v28 = k < v25[1].mValues.size;
    }
    else
    {
      v28 = k < LODWORD(v25->mValues.p);
    }
    if ( !v28 )
      break;
    if ( v27 )
    {
      if ( v27 - 1 > 1 )
        v29 = &UFG::gNullQSymbol;
      else
        v29 = (UFG::qSymbol *)v25[1].mValues.p + k;
    }
    else
    {
      v29 = (UFG::qSymbol *)(*(_QWORD *)&v25->mPersistentDataType + 8i64 * k);
    }
    if ( (!v29->mUID || !UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, v29->mUID)) && v29->mUID )
      UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, v29->mUID);
  }
}

// File Line: 849
// RVA: 0x495450
void __fastcall UFG::ProgressionTracker::BindProgressionStage(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v2; // rcx
  UFG::qBaseTreeRB *StartupSlice; // rsi
  bool v4; // bl
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol *v7; // rbx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-90h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-68h] BYREF
  UFG::qString v11; // [rsp+78h] [rbp-40h] BYREF
  UFG::qSymbol weaponOverride; // [rsp+C0h] [rbp+8h] BYREF
  UFG::qSymbol *p_weaponOverride; // [rsp+C8h] [rbp+10h]

  if ( this->mIsLoaded || this->mIsLoadedSimple )
  {
    StartupSlice = 0i64;
    v4 = 0;
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( !byte_14240BA99[0] )
      goto LABEL_18;
    if ( !(unsigned int)UFG::qStringCompareInsensitive(byte_14240BA99, "USER_SAVE", -1) )
    {
      v4 = 0;
      StartupSlice = UFG::ProgressionTracker::GetStartupSlice(this);
LABEL_17:
      UFG::ProgressionTracker::SyncCompleted(this, v4);
LABEL_18:
      UFG::ProgressionTracker::ForceProgress(this, (UFG::GameSlice *)StartupSlice, v4);
      goto LABEL_19;
    }
    UFG::qString::qString(&v11, &byte_14240BAB9);
    UFG::qString::qString(&v9, byte_14240BA99);
    UFG::qString::MakeLower(&v9);
    UFG::qString::FormatEx(&result, "default-savegames-debugmenu-%s-%s", v11.mData, v9.mData);
    v5 = UFG::qSymbol::create_from_string(&weaponOverride, result.mData);
    v6 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::LoadPresetGame(v6, v5);
    v7 = UFG::qSymbol::create_from_string(&weaponOverride, byte_14240BA99);
    if ( !v7->mUID || (v8 = UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, v7->mUID)) == 0i64 )
    {
      if ( !v7->mUID )
      {
LABEL_14:
        v4 = 1;
        if ( StartupSlice )
          UFG::GameSlice::_SimulateUnlock((UFG::GameSlice *)StartupSlice, 1);
        UFG::qString::~qString(&result);
        UFG::qString::~qString(&v9);
        UFG::qString::~qString(&v11);
        goto LABEL_17;
      }
      v8 = UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, v7->mUID);
    }
    StartupSlice = v8;
    goto LABEL_14;
  }
  p_weaponOverride = &weaponOverride;
  weaponOverride.mUID = UFG::gNullQSymbol.mUID;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplySnapshotEffects(v2, &weaponOverride.mUID);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_9);
LABEL_19:
  UFG::ProgressionTracker::UpdatePermanentDLC(this);
}

// File Line: 924
// RVA: 0x495180
void __fastcall UFG::ProgressionTracker::BindChallengeGameSlice(
        UFG::ProgressionTracker *this,
        const char *gameslicename)
{
  UFG::GameSlice *mpActiveMaster; // rdx
  UFG::GameStatTracker *v5; // rdi
  UFG::GameStatTracker *v6; // rbx
  UFG::qSymbol *v7; // r14
  UFG::qBaseTreeRB *mParent; // rbx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameStatTracker *v10; // rcx
  unsigned int v11; // ecx
  UFG::GameStatTracker *v12; // rdx
  UFG::PersistentData::MapBool *v13; // rdx
  UFG::PersistentData::MapInt *v14; // rdi
  UFG::PersistentData::KeyValue *p; // rcx
  char *v16; // rbx
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  mpActiveMaster = this->mpActiveMaster;
  if ( mpActiveMaster && mpActiveMaster->mType != NUM_TYPES )
    UFG::ProgressionTracker::CancelMission(this, mpActiveMaster, 0, RestoreType_SafehouseFailure);
  this->mModeType = ModeType_Challenge;
  UFG::ProgressionTracker::UpdateGameSlicesSnapshot(this);
  v5 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v6 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v6 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v6;
  UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v6);
  UFG::GameSnapshot::Clone(v6->mpSnapshots[1], v6->mpSnapshots[0]);
  v7 = UFG::qSymbol::create_from_string(&result, gameslicename);
  if ( !v7->mUID || (mParent = UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, v7->mUID)) == 0i64 )
  {
    if ( v7->mUID )
      mParent = UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, v7->mUID);
    else
      mParent = 0i64;
  }
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v9 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v9 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v9;
  if ( (*((_BYTE *)v9 + 6216) & 1) == 0 )
  {
    UFG::PersistentData::MapInt::ApplyDelta(v9->mpSnapshots[0]->mpMapInts[35], (UFG::qSymbol *)&mParent->mRoot.mUID, 1);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( (_S12_6 & 1) == 0 )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      v10 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v10 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v10;
    }
  }
  if ( !mParent[5].mRoot.mChild[0] && SHIDWORD(mParent[3].mNULL.mChild[1]) > 0 && SLODWORD(mParent[5].mNULL.mParent) > 0 )
    mParent = (UFG::qBaseTreeRB *)mParent[5].mNULL.mChild[0]->mParent;
  UFG::GameStatAction::Inventory::UnEquip(1);
  UFG::GameStatAction::Inventory::UnequipAllWeapons(1);
  UFG::ProgressionTracker::ForceProgress(this, (UFG::GameSlice *)mParent, 0);
  v11 = _S12_6;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v11 = _S12_6;
  }
  v12 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v12 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v12;
  v13 = v12->mpSnapshots[0]->mpMapBools[75];
  v13->mValues.size = 0;
  v13->mNames.size = 0;
  if ( (v11 & 1) == 0 )
  {
    _S12_6 = v11 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v14 = v5->mpSnapshots[0]->mpMapInts[23];
  p = v14->mValues.p;
  if ( p )
  {
    v16 = (char *)&p[-1].4;
    `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v16);
  }
  v14->mValues.p = 0i64;
  *(_QWORD *)&v14->mValues.size = 0i64;
}

// File Line: 975
// RVA: 0x4BCED0
void __fastcall UFG::ProgressionTracker::SetMode(UFG::ProgressionTracker *this, UFG::ProgressionTracker::ModeType mode)
{
  this->mModeType = mode;
}

// File Line: 982
// RVA: 0x4A6340
bool __fastcall UFG::ProgressionTracker::GetStartupLocation(
        UFG::ProgressionTracker *this,
        UFG::qMatrix44 *transRotation)
{
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qMatrix44 *v4; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol name; // [rsp+58h] [rbp+20h] BYREF

  UFG::qSymbol::create_from_string(&result, "config-StartupLocations");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&result);
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  UFG::qSymbol::create_from_string(&name, byte_14240BA58);
  v4 = UFG::qPropertySet::Get<UFG::qMatrix44>(PropertySet, (UFG::qArray<unsigned long,0> *)&name, DEPTH_RECURSE);
  if ( v4 )
  {
    v5 = v4->v1;
    v6 = v4->v2;
    v7 = v4->v3;
    transRotation->v0 = v4->v0;
    transRotation->v1 = v5;
    transRotation->v2 = v6;
    transRotation->v3 = v7;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 999
// RVA: 0x495650
void __fastcall UFG::ProgressionTracker::BindStartupLocation(UFG::ProgressionTracker *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::qMatrix44 transRotation; // [rsp+40h] [rbp-48h] BYREF

  if ( UFG::ProgressionTracker::GetStartupLocation(this, &transRotation) )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      v2 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      if ( v2 )
        UFG::TeleportEvent::TeleportEvent(
          (UFG::TeleportEvent *)v2,
          &transRotation,
          LocalPlayer->mNode.mUID,
          0,
          UFG::TeleportEvent::m_Name,
          0);
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v2);
    }
  }
}

// File Line: 1013
// RVA: 0x4B9480
__int64 **UFG::SendNewGameSessionTelemetry()
{
  char v0; // di
  UFG::allocator::free_link *v1; // rbx
  unsigned __int64 SystemTimeUTC; // rax
  __int64 *v3; // rax
  UFG::allocator::free_link *v4; // rbx
  UFG::OnlineManager *v5; // rax
  int OnlineIdStringHash32; // eax
  __int64 *v7; // rax
  UFG::allocator::free_link *v8; // rax
  __int64 *v9; // rdx
  int v10; // ecx
  __int64 *v11; // rax
  UFG::allocator::free_link *v12; // rax
  __int64 *v13; // rbx
  int v14; // eax
  char *v15; // rax
  __int64 *v16; // rax
  UFG::allocator::free_link *v17; // rsi
  char *mData; // rbx
  int v19; // eax
  char *v20; // rax
  __int64 *v21; // rax
  UFG::NameValueColumnType *i; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mNext; // rax
  __int64 *v25; // rcx
  UFG::NameValueColumnType *v26; // rax
  __int64 **v27; // rax
  __int64 *v28; // [rsp+30h] [rbp-40h] BYREF
  UFG::NameValueColumnType *v29; // [rsp+38h] [rbp-38h]
  UFG::qString result; // [rsp+40h] [rbp-30h] BYREF

  v0 = 0;
  v28 = (__int64 *)&v28;
  v29 = (UFG::NameValueColumnType *)&v28;
  v1 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  if ( v1 )
  {
    SystemTimeUTC = UFG::qGetSystemTimeUTC();
    v1->mNext = v1;
    v1[1].mNext = v1;
    LODWORD(v1[2].mNext) = 1;
    v1[4].mNext = (UFG::allocator::free_link *)"SessionId";
    LOBYTE(v1[5].mNext) = 0;
    v1[3].mNext = (UFG::allocator::free_link *)SystemTimeUTC;
  }
  else
  {
    v1 = 0i64;
  }
  v3 = v28;
  v28[1] = (__int64)v1;
  v1->mNext = (UFG::allocator::free_link *)v3;
  v1[1].mNext = (UFG::allocator::free_link *)&v28;
  v28 = (__int64 *)v1;
  v4 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  if ( v4 )
  {
    v5 = UFG::OnlineManager::Instance();
    OnlineIdStringHash32 = UFG::OnlineManager::GetOnlineIdStringHash32(v5);
    v4->mNext = v4;
    v4[1].mNext = v4;
    LODWORD(v4[2].mNext) = 6;
    v4[4].mNext = (UFG::allocator::free_link *)"PlayerId";
    LOBYTE(v4[5].mNext) = 0;
    LODWORD(v4[3].mNext) = OnlineIdStringHash32;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = v28;
  v28[1] = (__int64)v4;
  v4->mNext = (UFG::allocator::free_link *)v7;
  v4[1].mNext = (UFG::allocator::free_link *)&v28;
  v28 = (__int64 *)v4;
  v8 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  v9 = (__int64 *)v8;
  if ( v8 )
  {
    v10 = UFG::gCL_number;
    v8->mNext = v8;
    v8[1].mNext = v8;
    LODWORD(v8[2].mNext) = 5;
    v8[4].mNext = (UFG::allocator::free_link *)"Changelist";
    LOBYTE(v8[5].mNext) = 0;
    LODWORD(v8[3].mNext) = v10;
  }
  else
  {
    v9 = 0i64;
  }
  v11 = v28;
  v28[1] = (__int64)v9;
  *v9 = (__int64)v11;
  v9[1] = (__int64)&v28;
  v28 = v9;
  v12 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  v13 = (__int64 *)v12;
  if ( v12 )
  {
    v12->mNext = v12;
    v12[1].mNext = v12;
    LODWORD(v12[2].mNext) = 9;
    v12[4].mNext = (UFG::allocator::free_link *)"Platform";
    LOBYTE(v12[5].mNext) = 0;
    v14 = UFG::qStringLength("PC");
    v15 = (char *)UFG::qMalloc(v14 + 1, "StringColumn", 0i64);
    v13[3] = (__int64)v15;
    UFG::qStringCopy(v15, 0x7FFFFFFF, "PC", -1);
  }
  else
  {
    v13 = 0i64;
  }
  v16 = v28;
  v28[1] = (__int64)v13;
  *v13 = (__int64)v16;
  v13[1] = (__int64)&v28;
  v28 = v13;
  v17 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  if ( v17 )
  {
    v0 = 1;
    mData = UFG::qString::FormatEx(&result, "%s%s", "PC", &customCaption)->mData;
    v17->mNext = v17;
    v17[1].mNext = v17;
    LODWORD(v17[2].mNext) = 9;
    v17[4].mNext = (UFG::allocator::free_link *)"BuildType";
    LOBYTE(v17[5].mNext) = 0;
    v19 = UFG::qStringLength(mData);
    v20 = (char *)UFG::qMalloc(v19 + 1, "StringColumn", 0i64);
    v17[3].mNext = (UFG::allocator::free_link *)v20;
    UFG::qStringCopy(v20, 0x7FFFFFFF, mData, -1);
  }
  else
  {
    v17 = 0i64;
  }
  v21 = v28;
  v28[1] = (__int64)v17;
  v17->mNext = (UFG::allocator::free_link *)v21;
  v17[1].mNext = (UFG::allocator::free_link *)&v28;
  v28 = (__int64 *)v17;
  if ( (v0 & 1) != 0 )
    UFG::qString::~qString(&result);
  for ( i = v29; v29 != (UFG::NameValueColumnType *)&v28; i = v29 )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::NameValueColumnType::~NameValueColumnType(i);
    operator delete[](i);
  }
  v25 = v28;
  v26 = v29;
  v28[1] = (__int64)v29;
  v26->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v25;
  v28 = (__int64 *)&v28;
  v27 = &v28;
  v29 = (UFG::NameValueColumnType *)&v28;
  return v27;
}

// File Line: 1051
// RVA: 0x4AE620
void __fastcall UFG::ProgressionTracker::LoadGraph(UFG::ProgressionTracker *this)
{
  float v1; // xmm0_4
  UFG::GUIProgressionEditor *v3; // rdi
  char *gActiveContainers; // rax
  __int64 v5; // rcx
  UFG::qString *v6; // rax
  UFG::qString result; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qString v8; // [rsp+58h] [rbp-90h] BYREF
  __int64 v9; // [rsp+80h] [rbp-68h]
  UFG::qString v10; // [rsp+88h] [rbp-60h] BYREF
  UFG::qString v11; // [rsp+B0h] [rbp-38h] BYREF

  v9 = -2i64;
  if ( !this->mDisableProgression && !this->mIsLoaded && !this->mIsLoadedSimple )
  {
    v3 = UFG::GUIProgressionEditor::mpInstance;
    if ( UFG::GUIProgressionEditor::mpInstance
      && UFG::GUIProgressionEditor::mpInstance->vfptr->IsVisible(UFG::GUIProgressionEditor::mpInstance) )
    {
      v3->vfptr->Hide(v3);
    }
    this->mState = STATE_NORMAL;
    this->mpActiveMaster = 0i64;
    this->mpLastCheckpoint = 0i64;
    this->mpLastFailed = 0i64;
    *(_WORD *)&this->mDirty = 0;
    this->mActiveMasterMode = ActiveMasterMode_OpenWorld;
    gActiveContainers = this->gActiveContainers;
    v5 = 12i64;
    do
    {
      *(gActiveContainers - 12) = 0;
      *gActiveContainers++ = 0;
      --v5;
    }
    while ( v5 );
    this->mRestoreType = RestoreType_GameLoad;
    UFG::SendNewGameSessionTelemetry();
    this->mLastUpdateTimestamp = 0i64;
    this->mContainerCompletedTimestamp = 0i64;
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( byte_14240BA58[0] )
    {
      UFG::qString::FormatEx(&result, "Data\\World\\%s\\MetaGame", byte_14240BA58);
      UFG::qString::qString(&v10, "ProgressionDependencyGraph_Main.xml");
      if ( byte_14240BAB9 )
      {
        v6 = UFG::qString::FormatEx(&v8, "ProgressionDependencyGraph_%s.xml", &byte_14240BAB9);
        UFG::qString::Set(&v10, v6->mData, v6->mLength, 0i64, 0);
        UFG::qString::~qString(&v8);
      }
      UFG::qString::Set(&this->mLocationPath, result.mData, result.mLength, 0i64, 0);
      if ( byte_14240BAB9 == 82 && unk_14240BABA == 80 )
      {
        UFG::qString::FormatEx(&v8, "%s\\Replayable", result.mData);
        if ( byte_14240BA99[0] )
        {
          UFG::qString::FormatEx(&v11, "%s.xml", byte_14240BA99);
          UFG::ProgressionTracker::LoadSupportFile(this, v8.mData, v11.mData, 0i64, v1);
          UFG::qString::~qString(&v11);
        }
        UFG::qString::~qString(&v8);
      }
      if ( (unsigned __int8)UFG::ProgressionTracker::LoadSupportFile(this, result.mData, v10.mData, 0i64, v1) )
      {
        UFG::ProgressionTracker::FixupMasterLists(this, 0);
        this->mIsLoaded = 1;
      }
      else
      {
        this->mIsLoadedSimple = 1;
        UFG::ProgressionTracker::BindStartupLocation(this);
      }
      this->mState = STATE_DANGER;
      UFG::qString::~qString(&v10);
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 1178
// RVA: 0x4C3A10
void __fastcall UFG::ProgressionTracker::UnloadGraph(UFG::ProgressionTracker *this)
{
  UFG::GUIProgressionEditor *v2; // rdi
  UFG::GameSlice *i; // rdi
  UFG::GameSlice *j; // rdi
  Render::SkinningCacheNode *Head; // rdi
  Render::SkinningCacheNode *v6; // rdi
  Render::SkinningCacheNode *v7; // rdi
  Render::SkinningCacheNode *v8; // rdi
  void **mppArray; // rdi
  void **k; // rsi
  UFG::SecondaryObjectiveTracker *p_mSecondaryObjectiveTracker; // rdi
  __int64 v12; // rsi
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKScreenWorldMap *v14; // rax
  Render::SkinningCacheNode *v15; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  char *gActiveContainers; // rax
  __int64 v19; // rcx

  if ( this->mIsLoaded )
  {
    v2 = UFG::GUIProgressionEditor::mpInstance;
    if ( UFG::GUIProgressionEditor::mpInstance
      && UFG::GUIProgressionEditor::mpInstance->vfptr->IsVisible(UFG::GUIProgressionEditor::mpInstance) )
    {
      v2->vfptr->Hide(v2);
    }
    this->mpActiveMaster = 0i64;
    this->mpLastCheckpoint = 0i64;
    this->mpLastFailed = 0i64;
    for ( i = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
          i;
          i = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mNode) )
    {
      UFG::GameSlice::ForceLock(i, 1);
    }
    for ( j = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
          j;
          j = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mNode) )
    {
      UFG::GameSlice::ForceLock(j, 1);
    }
    UFG::GameSliceStreamer::Clear(&this->mGameSliceStreamer);
    while ( this->mGameSlices.mTree.mCount )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mGameSlices,
        &Head->mNode);
      if ( Head )
      {
        UFG::GameSlice::~GameSlice((UFG::GameSlice *)Head);
        operator delete[](Head);
      }
    }
    while ( this->mContainerGameSlices.mTree.mCount )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mContainerGameSlices,
        &v6->mNode);
      if ( v6 )
      {
        UFG::GameSlice::~GameSlice((UFG::GameSlice *)v6);
        operator delete[](v6);
      }
    }
    UFG::ProgressionTracker::DeleteDisabledGameSlices(this);
    while ( this->mCollections.mTree.mCount )
    {
      v7 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mCollections);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mCollections,
        &v7->mNode);
      if ( v7 )
      {
        operator delete[](v7[1].mNode.mChild[0]);
        operator delete[](v7);
      }
    }
    while ( this->mSceneSettings.mTree.mCount )
    {
      v8 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mSceneSettings);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mSceneSettings,
        &v8->mNode);
      if ( v8 )
      {
        UFG::SceneSettings::~SceneSettings((UFG::SceneSettings *)v8);
        operator delete[](v8);
      }
    }
    mppArray = (void **)this->mLayerOwnership.mppArray;
    for ( k = &mppArray[this->mLayerOwnership.mCount]; mppArray < k; ++mppArray )
    {
      if ( *mppArray )
        operator delete[](*mppArray);
    }
    this->mLayerOwnership.mCount = 0;
    UFG::qString::Set(&this->mGlobalAlternateLayer, &customCaption);
    UFG::ObjectiveTracker::Clear(&this->mObjectiveTracker);
    p_mSecondaryObjectiveTracker = &this->mSecondaryObjectiveTracker;
    v12 = 2i64;
    do
    {
      p_mSecondaryObjectiveTracker->mObjectives[0].mStatus = STATUS_INACTIVE;
      UFG::qString::Set(&p_mSecondaryObjectiveTracker->mObjectives[0].mCaption, &customCaption);
      p_mSecondaryObjectiveTracker = (UFG::SecondaryObjectiveTracker *)((char *)p_mSecondaryObjectiveTracker + 56);
      --v12;
    }
    while ( v12 );
    Instance = UFG::UIHKScreenHud::getInstance();
    if ( Instance )
      UFG::UIHKSecondaryObjectivesWidget::Refresh(&Instance->SecondaryObjectives);
    v14 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
    if ( v14 )
      UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v14);
    if ( this->mPDATriggerTracker.mPDATriggers.mTree.mCount )
    {
      while ( 1 )
      {
        v15 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mPDATriggerTracker);
        if ( !v15 )
          break;
        p_mCachedBufferPtr = &v15[-1].mCachedBufferPtr;
        if ( v15 == (Render::SkinningCacheNode *)8 )
          goto LABEL_40;
        p_mNode = &v15->mNode;
LABEL_41:
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mPDATriggerTracker,
          p_mNode);
        if ( p_mCachedBufferPtr )
          ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
            p_mCachedBufferPtr,
            1i64);
        if ( !this->mPDATriggerTracker.mPDATriggers.mTree.mCount )
          goto LABEL_44;
      }
      p_mCachedBufferPtr = 0i64;
LABEL_40:
      p_mNode = 0i64;
      goto LABEL_41;
    }
LABEL_44:
    this->mCaseTracker.mCases.size = 0;
    this->mIsLoaded = 0;
    this->mState = STATE_NORMAL;
    this->mbOpenWorldSnapshotState = Update_Completed;
    this->mbPendingSceneSettingsValid = 0;
    this->mPendingSceneSettingsLocal.mWeatherOverrideIntensity = -1.0;
    this->mPendingSceneSettingsLocal.mWeatherOverrideWetness = -1.0;
    this->mPendingSceneSettingsLocal.mWeatherOverrideLock = 0;
    this->mPendingSceneSettingsLocal.mTimeOverrideInSeconds = -1.0;
    *(_DWORD *)&this->mPendingSceneSettingsLocal.mTimeOverrideLockSet = 0;
    *(_DWORD *)&this->mPendingSceneSettingsLocal.mShowCurtains = 257;
    *(_DWORD *)&this->mPendingSceneSettingsLocal.mEnableAmbientPedsOnStart = 257;
    *(_WORD *)&this->mPendingSceneSettingsLocal.mEnableTrafficOnStart = 257;
    this->mPendingSceneSettingsLocal.mResetEnvironmentOverride = 0;
    UFG::qSymbol::set_null(&this->mPendingSceneSettingsLocal.mTeleportMarker);
    *(_WORD *)&this->mPendingSceneSettingsLocal.mVehicleDestroy = 0;
    this->mPendingSceneSettingsLocal.mTeleportPositionInternal.x = -1.0;
    this->mPendingSceneSettingsLocal.mTeleportPositionInternal.y = -1.0;
    this->mPendingSceneSettingsLocal.mTeleportPositionInternal.z = -1.0;
    this->mPendingSceneSettingsCache.mWeatherOverrideIntensity = -1.0;
    this->mPendingSceneSettingsCache.mWeatherOverrideWetness = -1.0;
    this->mPendingSceneSettingsCache.mWeatherOverrideLock = 0;
    this->mPendingSceneSettingsCache.mTimeOverrideInSeconds = -1.0;
    *(_DWORD *)&this->mPendingSceneSettingsCache.mTimeOverrideLockSet = 0;
    *(_DWORD *)&this->mPendingSceneSettingsCache.mShowCurtains = 257;
    *(_DWORD *)&this->mPendingSceneSettingsCache.mEnableAmbientPedsOnStart = 257;
    *(_WORD *)&this->mPendingSceneSettingsCache.mEnableTrafficOnStart = 257;
    this->mPendingSceneSettingsCache.mResetEnvironmentOverride = 0;
    UFG::qSymbol::set_null(&this->mPendingSceneSettingsCache.mTeleportMarker);
    *(_WORD *)&this->mPendingSceneSettingsCache.mVehicleDestroy = 0;
    this->mPendingSceneSettingsCache.mTeleportPositionInternal.x = -1.0;
    this->mPendingSceneSettingsCache.mTeleportPositionInternal.y = -1.0;
    this->mPendingSceneSettingsCache.mTeleportPositionInternal.z = -1.0;
    *(_WORD *)&this->mDirty = 0;
    *(_QWORD *)&this->mRestoreType = 1i64;
    this->mModeType = ModeType_Normal;
    this->mActiveMasterMode = ActiveMasterMode_OpenWorld;
    *(_QWORD *)&this->mTimeShiftState = 0i64;
    this->mTimeShiftSlice = 0i64;
    this->mTimeShiftTrigger = 0i64;
    UFG::qSymbol::set_null(&this->mSubSetModeType);
    this->mResourceFreezeMode = 0;
    UFG::SectionChooser::EnableStreamsUpdate(1);
    gActiveContainers = this->gActiveContainers;
    v19 = 12i64;
    do
    {
      *(gActiveContainers - 12) = 0;
      *gActiveContainers++ = 0;
      --v19;
    }
    while ( v19 );
    this->mIsLoadedSimple = 0;
  }
  else
  {
    this->mIsLoadedSimple = 0;
  }
}

// File Line: 1305
// RVA: 0x4B1070
void __fastcall UFG::ProgressionTracker::MoveAllSlicesInDisabledList(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rbx
  UFG::allocator::free_link *v2; // r15
  __int64 v3; // rsi
  unsigned int v4; // r14d
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1> *p_mGameSlices; // r13
  UFG::qBaseTreeRB *Head; // r12
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbp
  UFG::allocator::free_link *v13; // rdx
  __int64 v14; // r8
  UFG::qBaseTreeRB *p_mTree; // rbp
  UFG::qBaseNodeVariableRB<unsigned __int64> **v16; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v17; // rbx
  UFG::allocator::free_link *v18; // r15
  __int64 v19; // rsi
  unsigned int v20; // r14d
  UFG::ProgressionTracker *v21; // rbx
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1> *p_mContainerGameSlices; // r13
  UFG::qBaseTreeRB *Next; // r12
  int v24; // ecx
  unsigned int v25; // edi
  unsigned int v26; // ebx
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::allocator::free_link *v29; // rbp
  UFG::allocator::free_link *v30; // rdx
  __int64 v31; // r8
  UFG::qBaseTreeRB *v32; // rbp
  UFG::qBaseNodeVariableRB<unsigned __int64> **v33; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v34; // rbx

  v1 = this;
  v2 = 0i64;
  v3 = 0i64;
  v4 = 0;
  p_mGameSlices = &this->mGameSlices;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
  if ( Head )
  {
    do
    {
      v7 = v3;
      v8 = v3 + 1;
      if ( (int)v3 + 1 > v4 )
      {
        v9 = 1;
        if ( v4 )
          v9 = 2 * v4;
        for ( ; v9 < v8; v9 *= 2 )
          ;
        if ( v9 <= 2 )
          v9 = 2;
        if ( v9 - v8 > 0x10000 )
          v9 = v3 + 65537;
        if ( v9 != (_DWORD)v3 )
        {
          v10 = 8i64 * v9;
          if ( !is_mul_ok(v9, 8ui64) )
            v10 = -1i64;
          v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
          v12 = v11;
          if ( v2 )
          {
            if ( (_DWORD)v3 )
            {
              v13 = v11;
              v14 = (unsigned int)v3;
              do
              {
                v13->mNext = *(UFG::allocator::free_link **)((char *)v13 + (char *)v2 - (char *)v11);
                ++v13;
                --v14;
              }
              while ( v14 );
            }
            operator delete[](v2);
          }
          v2 = v12;
          v4 = v9;
          v7 = v3;
        }
      }
      v3 = v8;
      v2[v7].mNext = (UFG::allocator::free_link *)Head;
      Head = UFG::qBaseTreeRB::GetNext(&p_mGameSlices->mTree, &Head->mRoot);
    }
    while ( Head );
    v1 = this;
  }
  if ( (_DWORD)v3 )
  {
    p_mTree = &v1->mDisabledGameSlices.mTree;
    v16 = (UFG::qBaseNodeVariableRB<unsigned __int64> **)v2;
    do
    {
      v17 = *v16;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mGameSlices,
        *v16);
      UFG::qBaseTreeRB::Add(p_mTree, (UFG::qBaseNodeRB *)v17);
      ++v16;
      --v3;
    }
    while ( v3 );
  }
  if ( v2 )
    operator delete[](v2);
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0;
  v21 = this;
  p_mContainerGameSlices = &this->mContainerGameSlices;
  Next = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
  if ( Next )
  {
    do
    {
      v24 = v19;
      v25 = v19 + 1;
      if ( (int)v19 + 1 > v20 )
      {
        v26 = 1;
        if ( v20 )
          v26 = 2 * v20;
        for ( ; v26 < v25; v26 *= 2 )
          ;
        if ( v26 <= 2 )
          v26 = 2;
        if ( v26 - v25 > 0x10000 )
          v26 = v19 + 65537;
        if ( v26 != (_DWORD)v19 )
        {
          v27 = 8i64 * v26;
          if ( !is_mul_ok(v26, 8ui64) )
            v27 = -1i64;
          v28 = UFG::qMalloc(v27, "qArray.Add", 0i64);
          v29 = v28;
          if ( v18 )
          {
            if ( (_DWORD)v19 )
            {
              v30 = v28;
              v31 = (unsigned int)v19;
              do
              {
                v30->mNext = *(UFG::allocator::free_link **)((char *)v30 + (char *)v18 - (char *)v28);
                ++v30;
                --v31;
              }
              while ( v31 );
            }
            operator delete[](v18);
          }
          v18 = v29;
          v20 = v26;
          v24 = v19;
        }
      }
      v19 = v25;
      v18[v24].mNext = (UFG::allocator::free_link *)Next;
      Next = UFG::qBaseTreeRB::GetNext(&p_mContainerGameSlices->mTree, &Next->mRoot);
    }
    while ( Next );
    v21 = this;
  }
  if ( (_DWORD)v19 )
  {
    v32 = &v21->mDisabledGameSlices.mTree;
    v33 = (UFG::qBaseNodeVariableRB<unsigned __int64> **)v18;
    do
    {
      v34 = *v33;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mContainerGameSlices,
        *v33);
      UFG::qBaseTreeRB::Add(v32, (UFG::qBaseNodeRB *)v34);
      ++v33;
      --v19;
    }
    while ( v19 );
  }
  if ( v18 )
    operator delete[](v18);
}

// File Line: 1333
// RVA: 0x49A980
void __fastcall UFG::ProgressionTracker::DeleteDisabledGameSlices(UFG::ProgressionTracker *this)
{
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1> *p_mDisabledGameSlices; // rdi
  UFG::qBaseTreeRB *Head; // rbx
  UFG::GameSlice *v3; // rsi
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx
  Render::SkinningCacheNode *v6; // rbx

  p_mDisabledGameSlices = &this->mDisabledGameSlices;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mDisabledGameSlices);
  while ( Head )
  {
    if ( Head[5].mRoot.mChild[0] || SHIDWORD(Head[3].mNULL.mChild[1]) <= 0 )
    {
      v3 = (UFG::GameSlice *)Head;
      Next = UFG::qBaseTreeRB::GetNext(&p_mDisabledGameSlices->mTree, &Head->mRoot);
      v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head;
      Head = Next;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mDisabledGameSlices,
        v5);
      if ( v3 )
      {
        UFG::GameSlice::~GameSlice(v3);
        operator delete[](v3);
      }
    }
    else
    {
      Head = UFG::qBaseTreeRB::GetNext(&p_mDisabledGameSlices->mTree, &Head->mRoot);
    }
  }
  while ( p_mDisabledGameSlices->mTree.mCount )
  {
    v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)p_mDisabledGameSlices);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mDisabledGameSlices,
      &v6->mNode);
    if ( v6 )
    {
      UFG::GameSlice::~GameSlice((UFG::GameSlice *)v6);
      operator delete[](v6);
    }
  }
}

// File Line: 1356
// RVA: 0x4A0CF0
void __fastcall UFG::ProgressionTracker::FixupMasterLists(UFG::ProgressionTracker *this, bool allowDisabledSlices)
{
  char v2; // di
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *p_mDisabledGameSlices; // r13
  UFG::qBaseTreeRB *Head; // rbx
  bool v6; // si
  UFG::GameSlice *v7; // rcx
  __int64 v8; // rdi
  __int64 mParent_low; // rbp
  UFG::allocator::free_link *v10; // r12
  __int64 v11; // rsi
  unsigned int v12; // r14d
  UFG::qBaseTreeRB *i; // r15
  int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rbp
  UFG::allocator::free_link *v20; // rdx
  __int64 v21; // r8
  __int64 v22; // r15
  UFG::qBaseNodeVariableRB<unsigned __int64> **v23; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v24; // rbx
  UFG::qBaseTreeRB *v25; // rcx
  UFG::qBaseTreeRB *j; // rbp
  __int64 v27; // rcx
  __int64 v28; // rbx
  UFG::GameSlice **v29; // rax
  UFG::GameSlice *v30; // rdi
  int v31; // r14d
  UFG::GameSlice **v32; // rsi
  UFG::GameSlice *DependentRecursive; // rax
  UFG::ProgressionTracker *depth; // [rsp+80h] [rbp+8h] BYREF
  bool v35; // [rsp+88h] [rbp+10h]

  v35 = allowDisabledSlices;
  depth = this;
  v2 = allowDisabledSlices;
  UFG::ProgressionTracker::MoveAllSlicesInDisabledList(this);
  p_mDisabledGameSlices = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mDisabledGameSlices;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_mDisabledGameSlices);
  if ( Head )
  {
    do
    {
      if ( !Head[5].mRoot.mChild[0] && SHIDWORD(Head[3].mNULL.mChild[1]) > 0 )
      {
        if ( BYTE1(Head[4].mNULL.mParent) )
        {
          v6 = 1;
        }
        else
        {
          v7 = SLODWORD(Head[5].mNULL.mParent) <= 0
             ? (UFG::GameSlice *)Head
             : (UFG::GameSlice *)Head[5].mNULL.mChild[0]->mParent;
          v6 = (unsigned __int8)UFG::GameSlice::CanDependantsBeEnabled(v7) != 0;
        }
        LOBYTE(Head[4].mNULL.mParent) = v6;
        v8 = 0i64;
        mParent_low = LODWORD(Head[5].mNULL.mParent);
        if ( LODWORD(Head[5].mNULL.mParent) )
        {
          do
            UFG::GameSlice::SetEnabled(*((UFG::GameSlice **)&Head[5].mNULL.mChild[0]->mParent + v8++), v6);
          while ( v8 < mParent_low );
        }
      }
      Head = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)p_mDisabledGameSlices, &Head->mRoot);
    }
    while ( Head );
    v2 = v35;
  }
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_mDisabledGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)p_mDisabledGameSlices, &i->mRoot) )
  {
    if ( LOBYTE(i[4].mNULL.mParent) || v2 )
    {
      v14 = v11;
      v15 = v11 + 1;
      if ( (int)v11 + 1 > v12 )
      {
        v16 = 1;
        if ( v12 )
          v16 = 2 * v12;
        for ( ; v16 < v15; v16 *= 2 )
          ;
        if ( v16 <= 2 )
          v16 = 2;
        if ( v16 - v15 > 0x10000 )
          v16 = v11 + 65537;
        if ( v16 != (_DWORD)v11 )
        {
          v17 = 8i64 * v16;
          if ( !is_mul_ok(v16, 8ui64) )
            v17 = -1i64;
          v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
          v19 = v18;
          if ( v10 )
          {
            if ( (_DWORD)v11 )
            {
              v20 = v18;
              v21 = (unsigned int)v11;
              do
              {
                v20->mNext = *(UFG::allocator::free_link **)((char *)v20 + (char *)v10 - (char *)v18);
                ++v20;
                --v21;
              }
              while ( v21 );
            }
            operator delete[](v10);
          }
          v10 = v19;
          v12 = v16;
          v14 = v11;
        }
      }
      v11 = v15;
      v10[v14].mNext = (UFG::allocator::free_link *)i;
      v2 = v35;
    }
  }
  v22 = (__int64)depth;
  if ( (_DWORD)v11 )
  {
    v23 = (UFG::qBaseNodeVariableRB<unsigned __int64> **)v10;
    do
    {
      v24 = *v23;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mDisabledGameSlices->mTree, *v23);
      if ( v24[11].mChild[1] || (v25 = (UFG::qBaseTreeRB *)(v22 + 104), SHIDWORD(v24[8].mChild0) <= 0) )
        v25 = (UFG::qBaseTreeRB *)(v22 + 32);
      UFG::qBaseTreeRB::Add(v25, (UFG::qBaseNodeRB *)v24);
      ++v23;
      --v11;
    }
    while ( v11 );
  }
  for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(v22 + 104));
        j;
        j = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(v22 + 104), &j->mRoot) )
  {
    if ( HIDWORD(j[3].mNULL.mChild[1]) == 4 )
    {
      v27 = 0i64;
      v28 = LODWORD(j[5].mRoot.mChild[1]);
      if ( LODWORD(j[5].mRoot.mChild[1]) )
      {
        v29 = *(UFG::GameSlice ***)&j[5].mRoot.mUID;
        while ( 1 )
        {
          v30 = *v29;
          if ( (*v29)->mType == (NUM_TYPES|TYPE_OCCLUSION|0x8) )
            break;
          ++v27;
          ++v29;
          if ( v27 >= v28 )
            goto LABEL_49;
        }
      }
      else
      {
LABEL_49:
        v31 = 0x7FFFFFFF;
        v30 = 0i64;
        if ( LODWORD(j[5].mRoot.mChild[1]) )
        {
          v32 = *(UFG::GameSlice ***)&j[5].mRoot.mUID;
          do
          {
            LODWORD(depth) = 0x7FFFFFFF;
            DependentRecursive = UFG::GameSlice::GetDependentRecursive(
                                   *v32,
                                   NUM_TYPES|TYPE_OCCLUSION|0x8,
                                   (int *)&depth);
            if ( (int)depth < v31 )
            {
              v31 = (int)depth;
              v30 = DependentRecursive;
            }
            ++v32;
            --v28;
          }
          while ( v28 );
        }
      }
      if ( v30 )
        j[6].mRoot.mChild[0] = &v30->mNode;
    }
  }
  if ( v10 )
    operator delete[](v10);
}

// File Line: 1435
// RVA: 0x4ABA50
bool __fastcall UFG::ProgressionTracker::IsCleanupCompleted(UFG::ProgressionTracker *this)
{
  char v2; // di
  UFG::qBaseTreeRB *i; // rbx
  int mParent; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  UFG::qBaseTreeRB *Layer; // rax
  UFG::qBaseTreeRB *j; // rbx
  UFG::qSymbol name; // [rsp+60h] [rbp+8h] BYREF

  v2 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mRoot) )
  {
    mParent = (int)i[5].mRoot.mParent;
    if ( mParent )
    {
      v5 = mParent - 1;
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( v6 )
        {
          v7 = v6 - 1;
          if ( v7 )
          {
            if ( v7 == 1 )
              LODWORD(i[5].mRoot.mParent) = 0;
            else
              HIWORD(i[5].mRoot.mParent) = 0;
          }
          else
          {
            if ( BYTE5(i[4].mNULL.mChild[0]) )
            {
              name.mUID = i[2].mRoot.mUID;
              BYTE5(i[4].mNULL.mChild[0]) = 0;
              Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
              if ( Layer )
                UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)Layer, 0, PERSISTENT, 0);
            }
            LODWORD(i[5].mRoot.mParent) = 4;
          }
        }
        else
        {
          LODWORD(i[5].mRoot.mParent) = 3;
        }
      }
      else
      {
        if ( UFG::Metrics::msInstance.mSimTimeDelta > 0.0 )
          ++HIWORD(i[5].mRoot.mParent);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]: (%s) Cleanup count is (%d)\n");
      }
      v2 = 1;
    }
  }
  for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
        j;
        j = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mRoot) )
  {
    if ( LODWORD(j[5].mRoot.mParent) )
    {
      UFG::GameSlice::UpdateCleanupPending((UFG::GameSlice *)j);
      v2 = 1;
    }
  }
  return v2 == 0;
}

// File Line: 1460
// RVA: 0x4B7E70
void __fastcall UFG::ProgressionTracker::RestoreVehicle(UFG::ProgressionTracker *this, UFG::GameSlice *slice)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpRestoredVehicle; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::GameSnapshot *v6; // rdi
  UFG::qPropertySet *PropertySet; // rax
  UFG::qBaseTreeRB *Named; // rbp
  float mValue; // xmm8_4
  float v10; // xmm6_4
  UFG::GameStatTracker *v11; // rax
  UFG::TransformNodeComponent *mParent; // rbx
  float v13; // xmm7_4
  UFG::SimObject *v14; // rax
  UFG::TransformNodeComponent *v15; // rbx
  UFG::SimObject *v16; // rdi
  __int16 m_Flags; // dx
  UFG::TSActorComponent *m_pComponent; // rbx
  SSActorClass *v19; // rdi
  SSClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  UFG::TSVehicle *Actor; // rax
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF

  if ( slice )
  {
    p_mpRestoredVehicle = &slice->mpRestoredVehicle;
    if ( slice->mpRestoredVehicle.m_pPointer )
    {
      mPrev = p_mpRestoredVehicle->mPrev;
      mNext = slice->mpRestoredVehicle.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpRestoredVehicle->mPrev = p_mpRestoredVehicle;
      slice->mpRestoredVehicle.mNext = &slice->mpRestoredVehicle;
    }
    slice->mpRestoredVehicle.m_pPointer = 0i64;
    if ( slice->mVehicleMarker.mUID != -1 )
    {
      v6 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
      if ( v6->mIDs[30].mValue.mUID != -1 )
      {
        PropertySet = UFG::PropertySetManager::GetPropertySet(&v6->mIDs[30].mValue);
        if ( !UFG::SimObjectUtility::IsClassType(PropertySet, &qSymbol_Boat_14) )
        {
          Named = UFG::MarkerBase::GetNamed(&slice->mVehicleMarker);
          if ( Named )
          {
            mValue = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[99].mValue;
            v10 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[100].mValue;
            v11 = UFG::GameStatTracker::Instance();
            mParent = (UFG::TransformNodeComponent *)Named[1].mNULL.mParent;
            v13 = v11->mpSnapshots[0]->mFloats[101].mValue;
            UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
            if ( (float)((float)((float)((float)(mValue - mParent->mWorldTransform.v3.x)
                                       * (float)(mValue - mParent->mWorldTransform.v3.x))
                               + (float)((float)(v10 - mParent->mWorldTransform.v3.y)
                                       * (float)(v10 - mParent->mWorldTransform.v3.y)))
                       + (float)((float)(v13 - mParent->mWorldTransform.v3.z)
                               * (float)(v13 - mParent->mWorldTransform.v3.z))) <= (float)(slice->mVehicleMarkerRange
                                                                                         * slice->mVehicleMarkerRange) )
            {
              UFG::qSymbol::create_from_string(&result, "Checkpoint Restore Car");
              v14 = UFG::SpawnInfoInterface::SpawnObject(&result, &v6->mIDs[30].mValue, UnReferenced, 0i64, 0i64, 0i64);
              v15 = (UFG::TransformNodeComponent *)Named[1].mNULL.mParent;
              v16 = v14;
              UFG::TransformNodeComponent::UpdateWorldTransform(v15);
              UFG::SimObjectUtility::Teleport(v16, &v15->mWorldTransform);
              UFG::GameSlice::SetRestoreVehicle(slice, v16);
              if ( v16 )
              {
                m_Flags = v16->m_Flags;
                if ( (m_Flags & 0x4000) != 0 )
                {
                  m_pComponent = (UFG::TSActorComponent *)v16->m_Components.p[4].m_pComponent;
                }
                else if ( m_Flags >= 0 )
                {
                  if ( (m_Flags & 0x2000) != 0 )
                  {
                    m_pComponent = (UFG::TSActorComponent *)v16->m_Components.p[3].m_pComponent;
                  }
                  else if ( (m_Flags & 0x1000) != 0 )
                  {
                    m_pComponent = (UFG::TSActorComponent *)v16->m_Components.p[2].m_pComponent;
                  }
                  else
                  {
                    m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                              v16,
                                                              UFG::TSActorComponent::_TypeUID);
                  }
                }
                else
                {
                  m_pComponent = (UFG::TSActorComponent *)v16->m_Components.p[4].m_pComponent;
                }
                if ( m_pComponent )
                {
                  v19 = UFG::TSVehicle::mClass;
                  i_class_p = UFG::TSActorComponent::GetActor(m_pComponent)->i_class_p;
                  if ( v19 == i_class_p
                    || (i_superclass_p = i_class_p->i_superclass_p) != 0i64 && SSClass::is_class(i_superclass_p, v19) )
                  {
                    Actor = (UFG::TSVehicle *)UFG::TSActorComponent::GetActor(m_pComponent);
                    UFG::TSVehicle::UnlockDoors(Actor, 1);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1517
// RVA: 0x4C2A80
void __fastcall UFG::ProgressionTracker::TeleportVehicle(UFG::ProgressionTracker *this, UFG::SceneSettings *settings)
{
  UFG::qBaseTreeRB *Named; // rax
  UFG::SimObject *m_pPointer; // rdi
  UFG::qBaseTreeRB *v6; // rbp
  float mValue; // xmm7_4
  float v8; // xmm8_4
  UFG::GameStatTracker *v9; // rax
  UFG::TransformNodeComponent *mParent; // rbx
  float v11; // xmm6_4
  UFG::TransformNodeComponent *v12; // rbx

  if ( settings )
  {
    if ( settings->mVehicleTeleportMarker.mUID != -1 )
    {
      if ( this->mLastUsedVehicle.m_pPointer )
      {
        Named = UFG::MarkerBase::GetNamed(&settings->mVehicleTeleportMarker);
        m_pPointer = this->mLastUsedVehicle.m_pPointer;
        v6 = Named;
        if ( m_pPointer )
        {
          if ( Named && !UFG::SimObjectUtility::IsClassType(m_pPointer, &qSymbol_Boat_14) )
          {
            mValue = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[99].mValue;
            v8 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[100].mValue;
            v9 = UFG::GameStatTracker::Instance();
            mParent = (UFG::TransformNodeComponent *)v6[1].mNULL.mParent;
            v11 = v9->mpSnapshots[0]->mFloats[101].mValue;
            UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
            if ( (float)((float)((float)((float)(v8 - mParent->mWorldTransform.v3.y)
                                       * (float)(v8 - mParent->mWorldTransform.v3.y))
                               + (float)((float)(mValue - mParent->mWorldTransform.v3.x)
                                       * (float)(mValue - mParent->mWorldTransform.v3.x)))
                       + (float)((float)(v11 - mParent->mWorldTransform.v3.z)
                               * (float)(v11 - mParent->mWorldTransform.v3.z))) <= (float)(settings->mVehicleTeleportRange
                                                                                         * settings->mVehicleTeleportRange) )
            {
              v12 = (UFG::TransformNodeComponent *)v6[1].mNULL.mParent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v12);
              UFG::SimObjectUtility::Teleport(m_pPointer, &v12->mWorldTransform);
            }
          }
        }
      }
    }
  }
}

// File Line: 1552
// RVA: 0x49D0B0
void __fastcall UFG::ProgressionTracker::DestroyVehicle(UFG::ProgressionTracker *this)
{
  UFG::SimObject *m_pPointer; // rdx

  m_pPointer = this->mLastUsedVehicle.m_pPointer;
  if ( m_pPointer )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
}

// File Line: 1565
// RVA: 0x4B7AE0
void __fastcall UFG::ProgressionTracker::RestorePlayerLocation(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker::RestoreType mRestoreType; // edx
  UFG::GameSlice *mpLastCheckpoint; // rax
  bool v4; // cl
  UFG::GameSlice *v5; // rbx
  UFG::SceneSettings *mSceneSettings; // rsi
  UFG::qSymbol *p_mTeleportMarker; // rsi
  UFG::qBaseTreeRB *Named; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rsi
  UFG::TransformNodeComponent *mParent; // rbx
  UFG::SimObjectCharacter *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  bool v13; // zf
  UFG::GameSnapshot *v14; // rcx
  float mValue; // xmm2_4
  float v16; // xmm1_4
  UFG::ProgressionTracker *v17; // rax
  UFG::ProgressionTracker::RestoreType v18; // ecx
  SSActor *v19; // rsi
  __int32 v20; // ecx
  __int32 v21; // ecx
  __int32 v22; // ecx
  ASymbol *v23; // rax
  SSInstance *v24; // rax
  const char *v25; // rdx
  char *v26; // rcx
  ASymbol *v27; // rax
  SSInstance *v28; // rax
  UFG::qMatrix44 *v29; // rsi
  __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *Actor; // rax
  UFG::qSymbol v33; // [rsp+30h] [rbp-39h] BYREF
  __int64 v34; // [rsp+38h] [rbp-31h] BYREF
  UFG::qVector3 vec; // [rsp+40h] [rbp-29h] BYREF
  __int64 v36[2]; // [rsp+50h] [rbp-19h] BYREF
  UFG::qMatrix44 transRotation; // [rsp+60h] [rbp-9h] BYREF
  UFG::qSymbol result; // [rsp+D0h] [rbp+67h] BYREF
  char v39; // [rsp+D8h] [rbp+6Fh] BYREF
  char v40; // [rsp+E0h] [rbp+77h] BYREF
  char v41; // [rsp+E8h] [rbp+7Fh] BYREF

  this->mRestoringType = RestoreType_Unknown;
  this->mMonetaryPenalty = MonetaryPenalty_None;
  if ( !this->mIsLoadedSimple && !this->mResourceFreezeMode )
  {
    mRestoreType = this->mRestoreType;
    v4 = 0;
    if ( mRestoreType == RestoreType_GameLoad )
    {
      mpLastCheckpoint = this->mpLastCheckpoint;
      if ( mpLastCheckpoint )
      {
        if ( !mpLastCheckpoint->mpParent
          && mpLastCheckpoint->mType > TYPE_CULL
          && !mpLastCheckpoint->mIgnoreSafehouseRestore )
        {
          v4 = 1;
        }
      }
    }
    v5 = this->mpLastCheckpoint;
    if ( v5 && v5->mType != NUM_TYPES && ((mRestoreType - 3) & 0xFFFFFFFB) != 0 && !v4 )
    {
      mSceneSettings = v5->mSceneSettings;
      if ( mSceneSettings && (p_mTeleportMarker = &mSceneSettings->mTeleportMarker, p_mTeleportMarker->mUID != -1)
        || (p_mTeleportMarker = &v5->mRestoreLocationMarker, v5->mRestoreLocationMarker.mUID != -1) )
      {
        do
        {
          UFG::GameSlice::_EnableLayer(v5);
          v5 = v5->mpParent;
        }
        while ( v5 );
        Named = UFG::MarkerBase::GetNamed(p_mTeleportMarker);
        LocalPlayer = UFG::GetLocalPlayer();
        if ( LocalPlayer )
        {
          if ( Named )
          {
            mParent = (UFG::TransformNodeComponent *)Named[1].mNULL.mParent;
            UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
            UFG::SimObjectUtility::Teleport(LocalPlayer, &mParent->mWorldTransform);
          }
        }
      }
LABEL_48:
      this->mRestoreType = RestoreType_Safehouse;
      return;
    }
    v11 = UFG::GetLocalPlayer();
    v12 = UFG::GameStatTracker::Instance();
    v13 = this->mRestoreType == RestoreType_GameLoad;
    v14 = v12->mpSnapshots[0];
    mValue = v14->mFloats[81].mValue;
    v16 = v14->mFloats[80].mValue;
    vec.x = v14->mFloats[79].mValue;
    vec.y = v16;
    vec.z = mValue;
    if ( v13 )
    {
      v17 = UFG::ProgressionTracker::Instance();
      if ( (unsigned int)UFG::qStringCompare(v17->mGameSetup.mLocationDir, "Game", -1) )
      {
        if ( UFG::ProgressionTracker::GetStartupLocation(this, &transRotation) )
        {
          vec.x = transRotation.v3.x;
          vec.y = transRotation.v3.y;
          vec.z = transRotation.v3.z;
        }
      }
    }
    v18 = this->mRestoreType;
    v19 = SkookumScript::c_world_p;
    this->mRestoringType = v18;
    v20 = v18 - 2;
    if ( v20 )
    {
      v21 = v20 - 3;
      if ( v21 )
      {
        v22 = v21 - 1;
        if ( v22 )
        {
          if ( v22 != 1 )
          {
            v23 = (ASymbol *)UFG::qSymbol::create_from_string(&result, "Safehouse");
            v24 = SSSymbol::as_instance(v23);
            this->mRestoringType = RestoreType_Safehouse;
            goto LABEL_35;
          }
          v25 = "ScriptLocation";
          v26 = &v39;
        }
        else
        {
          this->mMonetaryPenalty = MonetaryPenalty_Arrest;
          v25 = "PoliceStation";
          v26 = &v40;
        }
      }
      else
      {
        this->mMonetaryPenalty = MonetaryPenalty_Hospitalization;
        v25 = "Clinic";
        v26 = &v41;
      }
    }
    else
    {
      v25 = "SafehouseComputer";
      v26 = (char *)&v33;
    }
    v27 = (ASymbol *)UFG::qSymbol::create_from_string((UFG::qSymbol *)v26, v25);
    v24 = SSSymbol::as_instance(v27);
LABEL_35:
    v36[0] = (__int64)v24;
    v28 = UFG::TSVector3::AsInstance(&vec);
    v34 = 0i64;
    v36[1] = (__int64)v28;
    ((void (__fastcall *)(SSActor *, UFG::qStaticSymbol *, __int64 *, __int64, __int64 *, _QWORD))v19->vfptr[1].set_data_by_name)(
      v19,
      &qSymbol_get_closest_restore_location,
      v36,
      2i64,
      &v34,
      0i64);
    v29 = *(UFG::qMatrix44 **)(v34 + 32);
    if ( v29 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v34 + 32));
      UFG::SimObjectUtility::Teleport(v11, v29 + 2);
      if ( v11 )
      {
        m_Flags = v11->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::TSActorComponent *)v11->m_Components.p[4].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            m_pComponent = (UFG::TSActorComponent *)v11->m_Components.p[3].m_pComponent;
          else
            m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                                   ? v11->m_Components.p[2].m_pComponent
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v11,
                                                       UFG::TSActorComponent::_TypeUID));
        }
        else
        {
          m_pComponent = (UFG::TSActorComponent *)v11->m_Components.p[4].m_pComponent;
        }
        if ( m_pComponent )
        {
          Actor = UFG::TSActorComponent::GetActor(m_pComponent);
          ((void (__fastcall *)(UFG::TSActor *))Actor->vfptr[2].get_data_by_name)(Actor);
        }
      }
    }
    goto LABEL_48;
  }
  this->mRestoreType = RestoreType_Safehouse;
}

// File Line: 1711
// RVA: 0x493D10
void __fastcall UFG::ProgressionTracker::AdjustPlayerLocationToGround(UFG::ProgressionTracker *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObject *v2; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float x; // xmm0_4
  float z; // xmm2_4
  float y; // xmm1_4
  float v7; // xmm4_4
  __m128 x_low; // xmm3
  float v9; // xmm5_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  __m128 v15; // xmm2
  float v16; // xmm0_4
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  float v19; // xmm10_4
  float v20; // xmm10_4
  __m128 v21; // xmm11
  float v22; // xmm10_4
  __m128 v23; // xmm8
  float v24; // xmm1_4
  __m128 v25; // xmm9
  float v26; // xmm2_4
  float v27; // xmm8_4
  __m128 v28; // xmm3
  float v29; // xmm6_4
  UFG::qVector3 out; // [rsp+30h] [rbp-69h] BYREF
  UFG::qVector3 position; // [rsp+40h] [rbp-59h] BYREF
  UFG::qMatrix44 xform; // [rsp+50h] [rbp-49h] BYREF

  LocalPlayer = UFG::GetLocalPlayer();
  v2 = LocalPlayer;
  if ( LocalPlayer )
  {
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      *(_QWORD *)&out.x = 0i64;
      out.z = 0.0;
      position.x = x;
      position.z = z;
      position.y = y;
      if ( UFG::PlaceOnGround(&out, &position, 0.0, 1.0, 0.5) )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v7 = m_pTransformNodeComponent->mWorldTransform.v0.y;
        x_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.x);
        v9 = m_pTransformNodeComponent->mWorldTransform.v0.z;
        v10 = x_low;
        v10.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
        if ( v10.m128_f32[0] == 0.0 )
          v11 = 0.0;
        else
          v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
        v12 = x_low.m128_f32[0] * v11;
        v13 = v7 * v11;
        v14 = v9 * v11;
        xform.v0.w = 0.0;
        v15 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        xform.v0.x = v12;
        xform.v0.y = v13;
        xform.v0.z = v14;
        v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v15.m128_f32[0] == 0.0 )
        {
          v17 = 0i64;
        }
        else
        {
          v16 = _mm_sqrt_ps(v15).m128_f32[0];
          v17 = (__m128)(unsigned int)FLOAT_1_0;
          v17.m128_f32[0] = 1.0 / v16;
        }
        v18 = v17;
        v19 = v17.m128_f32[0];
        v17.m128_f32[0] = v17.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v20 = v19 * UFG::qVector3::msDirUp.x;
        v18.m128_f32[0] = v18.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v21 = v18;
        v21.m128_f32[0] = (float)(v18.m128_f32[0] * v14) - (float)(v17.m128_f32[0] * v13);
        v17.m128_f32[0] = (float)(v17.m128_f32[0] * v12) - (float)(v20 * v14);
        v22 = (float)(v20 * v13) - (float)(v18.m128_f32[0] * v12);
        v23 = v17;
        v23.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v21.m128_f32[0] * v21.m128_f32[0]))
                        + (float)(v22 * v22);
        if ( v23.m128_f32[0] == 0.0 )
          v24 = 0.0;
        else
          v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
        v21.m128_f32[0] = v21.m128_f32[0] * v24;
        xform.v1.w = 0.0;
        v25 = v21;
        xform.v1.z = v22 * v24;
        LODWORD(xform.v1.x) = v21.m128_i32[0];
        xform.v1.y = v17.m128_f32[0] * v24;
        v25.m128_f32[0] = (float)(v21.m128_f32[0] * v14) - (float)((float)(v22 * v24) * v12);
        v26 = (float)((float)(v17.m128_f32[0] * v24) * v12) - (float)(v21.m128_f32[0] * v13);
        v28 = v25;
        v27 = (float)((float)(v22 * v24) * v13) - (float)(xform.v1.y * v14);
        v28.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v27 * v27)) + (float)(v26 * v26);
        if ( v28.m128_f32[0] == 0.0 )
          v29 = 0.0;
        else
          v29 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
        xform.v2.w = 0.0;
        xform.v3.w = 1.0;
        xform.v3.x = out.x;
        xform.v3.y = out.y;
        xform.v3.z = out.z;
        xform.v2.x = v27 * v29;
        xform.v2.y = v25.m128_f32[0] * v29;
        xform.v2.z = v26 * v29;
        UFG::SimObjectUtility::Teleport(v2, &xform);
      }
    }
  }
}

// File Line: 1741
// RVA: 0x4ACFF0
__int64 __fastcall UFG::ProgressionTracker::IsUICancellationAllowed(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpActiveMaster; // rax

  mpActiveMaster = this->mpActiveMaster;
  return !mpActiveMaster || mpActiveMaster->mAllowUICancellation;
}

// File Line: 1749
// RVA: 0x4944D0
void __fastcall UFG::ProgressionTracker::ApplyGameplayEffects(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpLastCheckpoint; // rax
  UFG::qSymbol *p_mRestoreWeapon; // rax
  unsigned int mUID; // eax
  UFG::GameStatTracker *v5; // rbx
  UFG::qSymbol weaponOverride; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_weaponOverride; // [rsp+48h] [rbp+10h]

  if ( (unsigned int)(this->mRestoringType - 5) <= 1 )
  {
    UFG::GameStatAction::Inventory::UnEquip(1);
    UFG::GameStatAction::Inventory::UnequipAllWeapons(1);
  }
  mpLastCheckpoint = this->mpLastCheckpoint;
  if ( mpLastCheckpoint )
    p_mRestoreWeapon = &mpLastCheckpoint->mRestoreWeapon;
  else
    p_mRestoreWeapon = &UFG::gNullQSymbol;
  mUID = p_mRestoreWeapon->mUID;
  p_weaponOverride = &weaponOverride;
  weaponOverride.mUID = mUID;
  v5 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  UFG::GameStatTracker::ApplySnapshotEffects(v5, (UFG::qSymbol)&weaponOverride);
}

// File Line: 1778
// RVA: 0x4C4360
void __fastcall UFG::ProgressionTracker::Update(UFG::ProgressionTracker *this, float realTimeDelta)
{
  UFG::InputActionData *v3; // rcx
  UFG::GameSaveLoad *v4; // rax
  UFG::GameSlice *mpLastCheckpoint; // rbx
  bool v6; // si
  bool v7; // al
  UFG::GameSlice *mpParent; // rbx
  UFG::GameSlice *v9; // rcx
  UFG::TimeOfDayManager *Instance; // rbx
  UFG::GameSlice *v11; // rcx
  UFG::StoreFrontTracker *v12; // rax
  bool v13; // al
  UFG::GameSlice *v14; // rcx
  UFG::GameSlice *v15; // rcx
  float mTODRestore; // xmm6_4
  UFG::TimeOfDayManager *v17; // rax
  UFG::GameSlice *v18; // rbx
  UFG::GameSlice::State mState; // esi
  UFG::GameSlice *v20; // rcx
  UFG::GameSlice *v21; // rcx
  bool v22; // al

  switch ( this->mState )
  {
    case 3:
      if ( this->mTimeShiftSlice
        && (v3 = UFG::ActionDef_Action.mDataPerController[UFG::gActiveControllerNum]) != 0i64
        && v3->mActionTrue )
      {
        this->mState = STATE_INCOMPLETE;
        *(_QWORD *)&this->mTimeShiftState = 5i64;
      }
      else
      {
        UFG::ProgressionTracker::UpdateDependency(this);
        UFG::ProgressionTracker::UpdateSnapshot(this);
        if ( this->mpAutoSaveQueuedSlice )
        {
          this->mpAutoSaveQueuedSlice = 0i64;
          v4 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SaveAutoGameSlot(v4);
        }
        UFG::ProgressionTracker::ApplyMonetaryPenalty(this);
      }
      goto LABEL_89;
    case 4:
      if ( !UFG::ProgressionTracker::UpdateTimeShift(this, realTimeDelta) )
        goto LABEL_88;
      goto LABEL_89;
    case 5:
      if ( UFG::ProgressionTracker::IsCleanupCompleted(this) )
        this->mState = STATE_ANIMATE_COMPLETE|0x8;
      goto LABEL_89;
    case 6:
      this->mIsWorldDataRestored = 0;
      if ( UFG::ProgressionTracker::IsCleanupCompleted(this) )
        this->mState = NUM_STATES|STATE_NORMAL;
      goto LABEL_89;
    case 7:
      UFG::ProgressionTracker::LoadSnapshotWeather(this);
      mpLastCheckpoint = this->mpLastCheckpoint;
      if ( !mpLastCheckpoint || mpLastCheckpoint->mType == NUM_TYPES )
      {
        if ( (unsigned int)(this->mRestoreType - 5) <= 1 )
        {
          Instance = UFG::TimeOfDayManager::GetInstance();
          UFG::TimeOfDayManager::SetTime(Instance, Instance->m_SecondsSinceMidnight + 21600.0, 0);
          TimePlotPoint::SetTimeValue(Instance, 40.0);
        }
      }
      else
      {
        v6 = !mpLastCheckpoint->mpParent && mpLastCheckpoint->mType > TYPE_CULL && !mpLastCheckpoint->mChildren.mCount;
        v7 = !mpLastCheckpoint->mpParent
          && mpLastCheckpoint->mType > TYPE_CULL
          && !UFG::GameSlice::HasProgressionTrigger(this->mpLastCheckpoint);
        if ( mpLastCheckpoint->mpParent || mpLastCheckpoint->mType <= TYPE_CULL || v6 || v7 )
        {
          mpParent = mpLastCheckpoint->mpParent;
          if ( mpParent )
          {
            UFG::GameSlice::SetupTimeAndWeather(mpParent, 1);
            UFG::GameSlice::SetupPedsAndVehicles(mpParent);
            UFG::GameSlice::SetupSceneLayers(mpParent);
          }
          v9 = this->mpLastCheckpoint;
          if ( v9->mSceneSettings )
          {
            UFG::GameSlice::SetupTimeAndWeather(v9, 1);
            UFG::GameSlice::SetupPedsAndVehicles(this->mpLastCheckpoint);
            UFG::GameSlice::SetupSceneLayers(this->mpLastCheckpoint);
            goto LABEL_38;
          }
        }
      }
      UFG::PedSpawning_AmbientPedEnableHelper(1);
      UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 1);
LABEL_38:
      UFG::ProgressionTracker::RestorePlayerLocation(this);
      UFG::ProgressionTracker::RestoreVehicle(this, this->mpLastCheckpoint);
      UFG::qSymbol::set_null(&this->mSubSetModeType);
      v11 = this->mpLastCheckpoint;
      if ( v11 )
      {
        if ( v11->mpParent )
          v11 = v11->mpParent;
        this->mpActiveMaster = v11;
        UFG::ProgressionTracker::HandleActiveMasterChanged(this);
      }
      if ( this->mbOpenWorldSnapshotState == Update_Requested )
        this->mbOpenWorldSnapshotState = Update_Pending;
      this->mState = 8;
      goto LABEL_89;
    case 8:
      if ( this->mIsWorldDataRestored )
        this->mState = 9;
      goto LABEL_89;
    case 9:
      UFG::ProgressionTracker::AdjustPlayerLocationToGround(this);
      v12 = UFG::StoreFrontTracker::Instance();
      UFG::StoreFrontTracker::ResetEquipment(v12);
      UFG::GameStatAction::Player::SetHeat(0.0);
      UFG::ProgressionTracker::SyncCompleted(this, 0);
      UFG::ProgressionTracker::ApplyGameplayEffects(this);
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
        if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
        {
          v13 = 1;
          goto LABEL_52;
        }
      }
      else
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
      }
      v13 = 0;
LABEL_52:
      UFG::Metrics::msInstance.mSimPausedInGame = v13;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      v14 = this->mpLastCheckpoint;
      if ( v14 )
      {
        this->mHoldCurtainPostRestore = v14->mHoldCurtain != 0;
        UFG::GameSlice::_SimulateUnlock(v14, 0);
        UFG::ProgressionTracker::StartTrackingMissionScoring(this, this->mpActiveMaster, 0);
        v15 = this->mpLastCheckpoint;
        if ( v15->mpParent )
          v15 = v15->mpParent;
        if ( v15->mIsTODRestricted )
        {
          mTODRestore = v15->mTODRestore;
          v17 = UFG::TimeOfDayManager::GetInstance();
          UFG::TimeOfDayManager::SetTime(v17, mTODRestore, 0);
        }
        v18 = this->mpLastCheckpoint;
        mState = v18->mState;
        if ( mState != STATE_RESTORING )
        {
          if ( (_S19_1 & 1) == 0 )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          byte_14240B986 = 1;
          UFG::GameSlice::Unlock(v18, STATE_RESTORING);
          if ( v18->mExclusive || v18->mRandomExclusive )
          {
            if ( mState == STATE_STARTED && v18->mExclusiveChild == v18 )
            {
              v18->mExclusiveChild = 0i64;
              v20 = v18->mpParent;
              if ( v20 )
                UFG::GameSlice::_MarkExclusiveChild(v20, 0i64);
            }
            if ( v18->mState == STATE_STARTED )
            {
              v18->mExclusiveChild = v18;
              v21 = v18->mpParent;
              if ( v21 )
                UFG::GameSlice::_MarkExclusiveChild(v21, v18);
              v18->mRequiresSave = 0;
            }
            if ( v18->mState == STATE_COMPLETED && v18->mExclusive && v18->mPersistent )
              v18->mRequiresSave = 1;
          }
        }
        if ( this->mRestoringType == RestoreType_Safehouse )
          UFG::GameSlice::OnSafehouseRestore(this->mpLastCheckpoint);
      }
      else
      {
        this->mHoldCurtainPostRestore = 0;
      }
      goto LABEL_88;
    case 0xB:
      if ( UFG::ProgressionTracker::IsCleanupCompleted(this) )
        this->mState = 12;
      goto LABEL_89;
    case 0xC:
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
        if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
        {
          v22 = 1;
          goto LABEL_84;
        }
      }
      else
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
      }
      v22 = 0;
LABEL_84:
      UFG::Metrics::msInstance.mSimPausedInGame = v22;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      UFG::PedSpawnManager::SetAmbientSpawningEnable(1);
      UFG::TSGameSlice::FromCPP_setup_interior_triggers();
LABEL_88:
      this->mState = STATE_COMPLETE;
LABEL_89:
      UFG::GameSliceStreamer::Update(&this->mGameSliceStreamer);
      if ( gShowMissionWorkState )
        UFG::ProgressionTracker::DrawMissionWorkStates(this, realTimeDelta);
      return;
    case 0xD:
      if ( !this->mContainerCompleted )
        goto LABEL_88;
      if ( UFG::Metrics::msInstance.mSimTimeMSec <= this->mContainerCompletedTimestamp )
        goto LABEL_89;
      this->mLastUpdateTimestamp = 0i64;
      this->mContainerCompleted = 0;
      goto LABEL_88;
    default:
      goto LABEL_89;
  }
}

// File Line: 2094
// RVA: 0x4C6630
void __fastcall UFG::ProgressionTracker::UpdateDependency(UFG::ProgressionTracker *this)
{
  unsigned __int64 v2; // rax
  UFG::qBaseTreeRB *i; // rdi
  UFG::qBaseTreeRB *j; // rdi
  UFG::GameSlice *k; // rdi
  UFG::GameSlice *m; // rdi
  UFG::qBaseTreeRB *n; // rdi
  UFG::GameSlice *ii; // rdi
  UFG::CaseTracker *p_mCaseTracker; // rsi
  __int64 v10; // rbx
  int jj; // edi

  if ( UFG::Metrics::msInstance.mSimTimeMSec > this->mLastUpdateTimestamp )
  {
    v2 = UFG::Metrics::msInstance.mSimTimeMSec + 3000;
    this->mDirty = 1;
    this->mLastUpdateTimestamp = v2;
  }
  if ( this->mDirty )
  {
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
          i;
          i = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mRoot) )
    {
      BYTE2(i[4].mNULL.mParent) = 1;
      UFG::ProgressionTracker::Instance()->mDirty = 1;
    }
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
          j;
          j = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mRoot) )
    {
      BYTE2(j[4].mNULL.mParent) = 1;
      UFG::ProgressionTracker::Instance()->mDirty = 1;
    }
    for ( k = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
          k;
          k = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &k->mNode) )
    {
      UFG::GameSlice::UpdateDependency(k);
    }
    for ( m = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
          m;
          m = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &m->mNode) )
    {
      UFG::GameSlice::UpdateDependency(m);
    }
    if ( this->mContainerCompleted )
    {
      for ( n = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
            n;
            n = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &n->mRoot) )
      {
        BYTE2(n[4].mNULL.mParent) = 1;
        UFG::ProgressionTracker::Instance()->mDirty = 1;
      }
      for ( ii = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
            ii;
            ii = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &ii->mNode) )
      {
        UFG::GameSlice::UpdateDependency(ii);
      }
    }
    this->mDirty = 0;
    UFG::ProgressionTracker::ActiveMasterCheck(this);
    p_mCaseTracker = &this->mCaseTracker;
    v10 = 0i64;
    for ( jj = p_mCaseTracker->mCases.size; (int)v10 < jj; v10 = (unsigned int)(v10 + 1) )
      UFG::CaseInfo::UpdateStatus(&p_mCaseTracker->mCases.p[v10]);
  }
}

// File Line: 2190
// RVA: 0x4BCCE0
void __fastcall UFG::ProgressionTracker::SetLastCompleted(UFG::ProgressionTracker *this, UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *mpAutoSaveQueuedSlice; // rax
  __int64 mType; // rcx
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax

  mpAutoSaveQueuedSlice = this->mpAutoSaveQueuedSlice;
  if ( (!mpAutoSaveQueuedSlice || mpAutoSaveQueuedSlice == pGameSlice) && !pGameSlice->mpParent )
  {
    mType = pGameSlice->mType;
    if ( (int)mType > 0 && gGameSliceTypePriority[mType] >= CONTENTPRIORITY_EVENT && !pGameSlice->mInternalSlice )
    {
      if ( (_DWORD)mType == 11 )
      {
        v5 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v5 + 6216) & 1) == 0 )
          v5->mpSnapshots[0]->mIDs[29].mValue.mUID = pGameSlice->mNode.mUID;
      }
      v6 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
        v6->mpSnapshots[0]->mIDs[28].mValue.mUID = pGameSlice->mNode.mUID;
    }
  }
}

// File Line: 2224
// RVA: 0x4C8470
void __fastcall UFG::ProgressionTracker::UpdateSnapshot(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v2; // rbx
  int v3; // esi
  UFG::ProgressionTracker::ActiveMasterMode mActiveMasterMode; // eax
  UFG::GameSnapshot *v5; // rcx
  UFG::ProgressionTracker::ActiveMasterMode v6; // ecx
  __int32 v7; // ecx

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = 2;
  if ( this->mbOpenWorldSnapshotState == Update_Pending )
  {
    UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
    UFG::GameSnapshot::Clone(v2->mpSnapshots[1], v2->mpSnapshots[0]);
    this->mbOpenWorldSnapshotState = Update_Completed;
  }
  if ( this->mMasterModeChanged )
  {
    UFG::ProgressionTracker::UpdateGameSlicesSnapshot(this);
    mActiveMasterMode = this->mActiveMasterMode;
    if ( mActiveMasterMode == ActiveMasterMode_Container )
    {
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      UFG::GameSnapshot::Clone(v2->mpSnapshots[1], v2->mpSnapshots[0]);
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      v5 = v2->mpSnapshots[2];
    }
    else if ( mActiveMasterMode == ActiveMasterMode_Challenge_Container )
    {
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      v5 = v2->mpSnapshots[3];
    }
    else
    {
      if ( !this->mCommitOnMasterModeChanged )
        goto LABEL_15;
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      v5 = v2->mpSnapshots[1];
    }
    UFG::GameSnapshot::Clone(v5, v2->mpSnapshots[0]);
  }
LABEL_15:
  if ( this->mCheckpointChanged )
  {
    UFG::ProgressionTracker::UpdateGameSlicesSnapshot(this);
    v6 = this->mActiveMasterMode;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 1 )
          v3 = 3;
        else
          v3 = 6;
      }
    }
    else
    {
      v3 = 1;
    }
    UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
    UFG::GameSnapshot::Clone(v2->mpSnapshots[v3], v2->mpSnapshots[0]);
  }
  *(_WORD *)&this->mCheckpointChanged = 0;
  this->mCommitOnMasterModeChanged = 0;
}

// File Line: 2308
// RVA: 0x495D20
void __fastcall UFG::ProgressionTracker::BuildSavegameSnapshot(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v2; // rbx
  UFG::GameSnapshot *v3; // rdx

  UFG::ProgressionTracker::SaveSnapshotWeather(this);
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  if ( this->mActiveMasterMode )
  {
    v3 = v2->mpSnapshots[1];
  }
  else
  {
    UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
    v3 = v2->mpSnapshots[0];
  }
  UFG::GameSnapshot::Clone(v2->mpSnapshots[4], v3);
  UFG::GameSnapshot::CommitByFilter(v2->mpSnapshots[4], v2->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
  UFG::GameSnapshot::CommitByFilter(v2->mpSnapshots[4], v2->mpSnapshots[0], 4u, 2u, 0);
}

// File Line: 2329
// RVA: 0x49D0D0
void __fastcall UFG::ProgressionTracker::DiscardSnapshot(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v2; // rdi
  UFG::ProgressionTracker::ActiveMasterMode mActiveMasterMode; // ecx
  __int32 v4; // ecx
  int v5; // eax
  UFG::GameSnapshot **v6; // rbx

  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  mActiveMasterMode = this->mActiveMasterMode;
  if ( mActiveMasterMode )
  {
    v4 = mActiveMasterMode - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
        v5 = 3;
      else
        v5 = 6;
    }
    else
    {
      v5 = 2;
    }
  }
  else
  {
    v5 = 1;
  }
  v6 = (UFG::GameSnapshot **)((char *)v2 + 8 * v5);
  UFG::GameSnapshot::CommitByFilter(v6[770], v2->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
  UFG::GameSnapshot::CommitByFilter(v6[770], v2->mpSnapshots[0], 4u, 2u, 0);
  UFG::GameSnapshot::Clone(v2->mpSnapshots[0], v6[770]);
}

// File Line: 2355
// RVA: 0x4B2D10
void __fastcall UFG::ProgressionTracker::PublishProgressionStatistics(UFG::ProgressionTracker *this)
{
  UFG::qBaseTreeRB *i; // rdi
  bool v3; // si
  UFG::GameStatTracker *v4; // rax
  UFG::GameStat::MapBoolStat v5; // edx
  UFG::GameSlice *j; // rbx

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &i->mRoot) )
  {
    v3 = LODWORD(i[3].mNULL.mChild[1]) == 8 || SWORD2(i[5].mRoot.mParent) > 0;
    switch ( BYTE3(i[4].mNULL.mChild[1]) )
    {
      case 1:
        v4 = UFG::GameStatTracker::Instance();
        v5 = MissionsCompleted;
        goto LABEL_15;
      case 2:
        v4 = UFG::GameStatTracker::Instance();
        v5 = CasesCompleted;
        goto LABEL_15;
      case 3:
        v4 = UFG::GameStatTracker::Instance();
        v5 = EventsCompleted;
        goto LABEL_15;
      case 4:
        v4 = UFG::GameStatTracker::Instance();
        v5 = FavoursCompleted;
        goto LABEL_15;
      case 5:
        v4 = UFG::GameStatTracker::Instance();
        v5 = JobsCompleted;
        goto LABEL_15;
      case 6:
        v4 = UFG::GameStatTracker::Instance();
        v5 = DatesCompleted;
        goto LABEL_15;
      case 7:
        v4 = UFG::GameStatTracker::Instance();
        v5 = StreetRacesCompletedWon;
        goto LABEL_15;
      case 8:
        v4 = UFG::GameStatTracker::Instance();
        v5 = DLCCompleted;
LABEL_15:
        UFG::GameStatTracker::SetStat(v4, v5, (UFG::qSymbol *)&i->mRoot.mUID, v3);
        break;
      default:
        continue;
    }
  }
  for ( j = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
        j;
        j = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &j->mNode) )
  {
    UFG::GameStatAction::GameSliceAction::PublishProgression(j);
  }
}

// File Line: 2369
// RVA: 0x4C8F60
void __fastcall UFG::ProgressionTracker::VendorExtortionHack(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v1; // rbx

  UFG::ProgressionTracker::UpdateGameSlicesSnapshot(this);
  v1 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v1);
  UFG::GameSnapshot::Clone(v1->mpSnapshots[1], v1->mpSnapshots[0]);
}

// File Line: 2379
// RVA: 0x4BDDF0
void __fastcall UFG::ProgressionTracker::SetupGlobalAlternateLayer(UFG::ProgressionTracker *this)
{
  if ( UFG::qString::operator!=(&this->mGlobalAlternateLayer, &customCaption) )
  {
    UFG::SectionLayout::SetLayerActive(this->mGlobalAlternateLayer.mData, 1);
    UFG::SectionChooser::FlushAltLayer(this->mGlobalAlternateLayer.mData, 1);
  }
}

// File Line: 2389
// RVA: 0x4B75A0
void __fastcall UFG::ProgressionTracker::Restart(UFG::ProgressionTracker *this, UFG::GameSlice *pData)
{
  UFG::GameStatTracker *v4; // rbx

  if ( this->mActiveMasterMode != ActiveMasterMode_Challenge_Container )
  {
    v4 = UFG::GameStatTracker::Instance();
    UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
    UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 4u, 2u, 0);
    UFG::GameSnapshot::Clone(v4->mpSnapshots[0], v4->mpSnapshots[1]);
    this->mActiveMasterMode = ActiveMasterMode_OpenWorld;
    this->mbOpenWorldSnapshotState = Update_Completed;
    UFG::ProgressionTracker::ForceProgress(this, pData, 0);
  }
}

// File Line: 2405
// RVA: 0x49FC20
void __fastcall UFG::ProgressionTracker::ExitChallenge(UFG::ProgressionTracker *this, bool success)
{
  UFG::GameStatTracker *v4; // rdi
  UFG::qPropertySet *RewardsProperties; // rbp
  UFG::GameSlice *mpActiveMaster; // rbx
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF

  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  RewardsProperties = UFG::GameSlice::GetRewardsProperties(this->mpActiveMaster);
  if ( success )
  {
    mpActiveMaster = this->mpActiveMaster;
    if ( mpActiveMaster->mNode.mUID == UFG::qSymbol::create_from_string(&result, "M_VE")->mUID )
    {
      UFG::qSymbol::create_from_string(&result, "default-rewards-progression-M_VEM_repeat");
      RewardsProperties = UFG::PropertySetManager::FindPropertySet(&result);
    }
    UFG::RewardsHandler::HandleRewards(ShowReward, RewardsProperties, 0i64);
  }
  UFG::ProgressionTracker::ResetProgression(this, RestoreType_SafehouseComputer, uidGameStateUnloadChallenge_9, 1);
  UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
  UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 4u, 2u, 0);
  UFG::GameSnapshot::Clone(v4->mpSnapshots[0], v4->mpSnapshots[1]);
  this->mActiveMasterMode = ActiveMasterMode_OpenWorld;
  this->mbOpenWorldSnapshotState = Update_Completed;
  this->mModeType = ModeType_Normal;
}

// File Line: 2445
// RVA: 0x4A0380
UFG::qBaseTreeRB *__fastcall UFG::ProgressionTracker::Find(
        UFG::ProgressionTracker *this,
        UFG::qSymbol *name,
        bool searchDisabledSlices)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *result; // rax

  if ( (!searchDisabledSlices
     || (mUID = name->mUID) == 0
     || (result = UFG::qBaseTreeRB::Get(&this->mDisabledGameSlices.mTree, mUID)) == 0i64)
    && (!name->mUID || (result = UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, name->mUID)) == 0i64) )
  {
    if ( name->mUID )
      return UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, name->mUID);
    else
      return 0i64;
  }
  return result;
}

// File Line: 2463
// RVA: 0x4A03F0
Render::SkinningCacheNode *__fastcall UFG::ProgressionTracker::FindByLayer(
        UFG::ProgressionTracker *this,
        UFG::qSymbol *name)
{
  Render::SkinningCacheNode *Head; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
  if ( Head )
  {
    while ( UFG::qSymbol::create_from_string(&result, (const char *)Head[1].mNode.mChild[0])->mUID != name->mUID )
    {
      Head = (Render::SkinningCacheNode *)UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, (UFG::qBaseNodeRB *)Head);
      if ( !Head )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
    if ( !Head )
      return 0i64;
    while ( UFG::qSymbol::create_from_string(&result, (const char *)Head[1].mNode.mChild[0])->mUID != name->mUID )
    {
      Head = (Render::SkinningCacheNode *)UFG::qBaseTreeRB::GetNext(
                                            &this->mContainerGameSlices.mTree,
                                            (UFG::qBaseNodeRB *)Head);
      if ( !Head )
        return 0i64;
    }
  }
  return Head;
}

// File Line: 2502
// RVA: 0x494670
void __fastcall UFG::ProgressionTracker::ApplyMonetaryReward(UFG::ProgressionTracker *this, int moneyCount)
{
  UFG::GameStatTracker *v3; // rbx

  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  UFG::GameStatTracker::MoneyHackSoWeCanShipThisGame(v3, moneyCount);
}

// File Line: 2508
// RVA: 0x494590
void __fastcall UFG::ProgressionTracker::ApplyMonetaryPenalty(UFG::ProgressionTracker *this)
{
  UFG::UIHKScreenHud *Instance; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameSnapshot *v4; // rcx
  int mValue; // edx
  float v6; // xmm1_4
  int v7; // ebx
  UFG::OSuiteLeaderboardManager *v8; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax

  if ( this->mMonetaryPenalty )
  {
    if ( UFG::UIHK_NISOverlay::IsCurtainHidden() )
    {
      Instance = UFG::UIHKScreenHud::getInstance();
      if ( Instance )
      {
        if ( Instance->mState >= STATE_EXECUTING )
        {
          v3 = UFG::GameStatTracker::Instance();
          v4 = v3->mpSnapshots[0];
          mValue = v4->mInts[44].mValue;
          v6 = v4->mFloats[77].mValue;
          if ( this->mMonetaryPenalty == MonetaryPenalty_Hospitalization )
          {
            mValue = v4->mInts[45].mValue;
            v6 = v4->mFloats[78].mValue;
          }
          v7 = (int)(float)((float)((float)v4->mInts[62].mValue * v6) * 0.0099999998);
          if ( mValue < v7 )
            v7 = mValue;
          UFG::GameStatTracker::ApplyDelta(v3, Money, -v7);
          v8 = UFG::OSuiteLeaderboardManager::Instance();
          LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                  v8,
                                                  "StatAwardsBigSpender");
          UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, v7);
          this->mMonetaryPenalty = MonetaryPenalty_None;
        }
      }
    }
  }
}

// File Line: 2620
// RVA: 0x4A1390
void __fastcall UFG::ProgressionTracker::ForceSliceChange(
        UFG::ProgressionTracker *this,
        UFG::GameSlice *pData,
        bool simulateRewards)
{
  unsigned int v6; // r9d
  UFG::GameStatTracker *v7; // rbx
  UFG::GameStatTracker *v8; // rcx
  UFG::PersistentData::MapBool *v9; // rdx
  UFG::PersistentData::MapInt *v10; // rdi
  UFG::PersistentData::KeyValue *p; // rcx
  char *v12; // rbx

  v6 = _S12_6;
  v7 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v6 = _S12_6;
  }
  v8 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v8 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v8;
  v9 = v8->mpSnapshots[0]->mpMapBools[75];
  v9->mValues.size = 0;
  v9->mNames.size = 0;
  if ( (v6 & 1) == 0 )
  {
    _S12_6 = v6 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v10 = v7->mpSnapshots[0]->mpMapInts[23];
  p = v10->mValues.p;
  if ( p )
  {
    v12 = (char *)&p[-1].4;
    `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v12);
  }
  v10->mValues.p = 0i64;
  *(_QWORD *)&v10->mValues.size = 0i64;
  UFG::ProgressionTracker::ForceProgress(this, pData, simulateRewards);
}

// File Line: 2633
// RVA: 0x4A11F0
UFG::ProgressionTracker::ForceProgress

// File Line: 2684
// RVA: 0x4B0D20
void __fastcall UFG::ProgressionTracker::MarkCleanup(UFG::ProgressionTracker *this)
{
  switch ( this->mState )
  {
    case 1:
      this->mState = STATE_COMPLETE;
      break;
    case 3:
    case 9:
    case 0xA:
    case 0xC:
    case 0xD:
      this->mState = STATE_ANIMATE_COMPLETE;
      break;
    default:
      return;
  }
}

// File Line: 2804
// RVA: 0x48D3C0
void __fastcall UFG::ProgressionTracker::ProgressionTracker(UFG::ProgressionTracker *this)
{
  this->mState = STATE_NORMAL;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mGameSlices.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mContainerGameSlices.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDisabledGameSlices.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mCollections.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mSceneSettings.mTree);
  *(_QWORD *)&this->mLayerOwnership.mCount = 0i64;
  this->mLayerOwnership.mppArray = 0i64;
  this->mObjectiveTracker.mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&this->mObjectiveTracker.mLoadedOrderObjectives.size = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mObjectiveTracker.mObjectives.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mObjectiveTracker.mObjectiveHints.mTree);
  this->mObjectiveTracker.mDirty = 0;
  this->mObjectiveTracker.mpFlashObjective = 0i64;
  this->mObjectiveTracker.mLastLoadId = 0;
  `eh vector constructor iterator(
    &this->mSecondaryObjectiveTracker,
    0x38ui64,
    2,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::SecondaryObjective);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mPDATriggerTracker.mPDATriggers.mTree);
  `eh vector constructor iterator(
    this->mCaseTracker.mCases.p,
    0x50ui64,
    20,
    (void (__fastcall *)(void *))UFG::CaseInfo::CaseInfo);
  this->mCaseTracker.mCases.size = 0;
  this->mCaseTracker.mCases.size = 0;
  UFG::GameSliceStreamer::GameSliceStreamer(&this->mGameSliceStreamer);
  UFG::qString::qString(&this->mLocationPath);
  UFG::qString::qString(&this->mDependencyGraphName);
  *(_QWORD *)&this->mDEBUGTestScenarioScriptName.mUID = -1i64;
  this->mpActiveMaster = 0i64;
  this->mpLastCheckpoint = 0i64;
  this->mpLastFailed = 0i64;
  this->mbOpenWorldSnapshotState = Update_Completed;
  this->mbPendingSceneSettingsValid = 0;
  UFG::SceneSettings::SceneSettings(&this->mPendingSceneSettingsLocal, "ProgressionTrackerSettingsLocal");
  UFG::SceneSettings::SceneSettings(&this->mPendingSceneSettingsCache, "ProgressionTrackerSettingsCache");
  *(_QWORD *)&this->mMonetaryPenalty = 0i64;
  *(_WORD *)&this->mDisableProgression = 0;
  this->mIsWorldDataRestored = 0;
  *(_QWORD *)&this->mRestoreType = 1i64;
  this->mModeType = ModeType_Normal;
  this->mSubSetModeType.mUID = -1;
  *(_DWORD *)&this->mResourceFreezeMode = 0;
  this->mpAutoSaveQueuedSlice = 0i64;
  this->mActiveMasterMode = ActiveMasterMode_OpenWorld;
  this->mLastUpdateTimestamp = 0i64;
  this->mContainerCompletedTimestamp = 0i64;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_bHasBeenBound = 0;
  UFG::qString::qString(&this->mGlobalAlternateLayer);
  *(_QWORD *)&this->mTimeShiftState = 0i64;
  this->mTimeShiftSlice = 0i64;
  this->mTimeShiftTrigger = 0i64;
  this->mLastUsedVehicle.mPrev = &this->mLastUsedVehicle;
  this->mLastUsedVehicle.mNext = &this->mLastUsedVehicle;
  this->mLastUsedVehicle.m_pPointer = 0i64;
  UFG::GameSetup::GameSetup(&this->mGameSetup);
  this->mActiveFlowId.mUID = gDefaultFlowId.mUID;
  this->mIsPossessedPedsEnabled = 0;
}

// File Line: 2808
// RVA: 0x490F20
void __fastcall UFG::ProgressionTracker::~ProgressionTracker(UFG::ProgressionTracker *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mLastUsedVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rax

  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll(&this->mLayerOwnership);
  this->mGameSetup.vfptr = (UFG::GameSetupVtbl *)&UFG::GameSetup::`vftable;
  p_mLastUsedVehicle = &this->mLastUsedVehicle;
  if ( this->mLastUsedVehicle.m_pPointer )
  {
    mPrev = p_mLastUsedVehicle->mPrev;
    mNext = this->mLastUsedVehicle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLastUsedVehicle->mPrev = p_mLastUsedVehicle;
    this->mLastUsedVehicle.mNext = &this->mLastUsedVehicle;
  }
  this->mLastUsedVehicle.m_pPointer = 0i64;
  v5 = p_mLastUsedVehicle->mPrev;
  v6 = this->mLastUsedVehicle.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mLastUsedVehicle->mPrev = p_mLastUsedVehicle;
  this->mLastUsedVehicle.mNext = &this->mLastUsedVehicle;
  UFG::qString::~qString(&this->mGlobalAlternateLayer);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  v7 = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev;
  v8 = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  UFG::SceneSettings::~SceneSettings(&this->mPendingSceneSettingsCache);
  UFG::SceneSettings::~SceneSettings(&this->mPendingSceneSettingsLocal);
  UFG::qString::~qString(&this->mDependencyGraphName);
  UFG::qString::~qString(&this->mLocationPath);
  UFG::GameSliceStreamer::~GameSliceStreamer(&this->mGameSliceStreamer);
  this->mCaseTracker.mCases.size = 0;
  this->mCaseTracker.mCases.size = 0;
  `eh vector destructor iterator(
    this->mCaseTracker.mCases.p,
    0x50ui64,
    20,
    (void (__fastcall *)(void *))UFG::CaseInfo::~CaseInfo);
  UFG::PDATriggerTracker::~PDATriggerTracker(&this->mPDATriggerTracker);
  `eh vector destructor iterator(
    &this->mSecondaryObjectiveTracker,
    0x38ui64,
    2,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
  UFG::ObjectiveTracker::~ObjectiveTracker(&this->mObjectiveTracker);
  operator delete[](this->mLayerOwnership.mppArray);
  UFG::qTreeRB<UFG::SceneSettings,UFG::SceneSettings,1>::~qTreeRB<UFG::SceneSettings,UFG::SceneSettings,1>(&this->mSceneSettings);
  UFG::qTreeRB<UFG::GameSliceCollection,UFG::GameSliceCollection,1>::DeleteAll(&this->mCollections);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mCollections);
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1>::~qTreeRB<UFG::GameSlice,UFG::GameSlice,1>(&this->mDisabledGameSlices);
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1>::~qTreeRB<UFG::GameSlice,UFG::GameSlice,1>(&this->mContainerGameSlices);
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1>::~qTreeRB<UFG::GameSlice,UFG::GameSlice,1>(&this->mGameSlices);
}

// File Line: 2831
// RVA: 0x4A5610
__int64 __fastcall UFG::ProgressionTracker::GetNumContainerSlices(UFG::ProgressionTracker *this)
{
  return (unsigned int)this->mContainerGameSlices.mTree.mCount;
}

// File Line: 2836
// RVA: 0x4A2000
UFG::qBaseTreeRB *__fastcall UFG::ProgressionTracker::GetContainerSlice(UFG::ProgressionTracker *this, int index)
{
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1> *p_mContainerGameSlices; // rdi
  UFG::qBaseTreeRB *result; // rax

  p_mContainerGameSlices = &this->mContainerGameSlices;
  result = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
  if ( !result )
    return 0i64;
  while ( index )
  {
    --index;
    result = UFG::qBaseTreeRB::GetNext(&p_mContainerGameSlices->mTree, &result->mRoot);
    if ( !result )
      return 0i64;
  }
  return result;
}

// File Line: 2898
// RVA: 0x4BFC40
void __fastcall UFG::ProgressionTracker::StartTrackingMissionScoring(
        UFG::ProgressionTracker *this,
        UFG::GameSlice *pGameSlice,
        bool resetScore)
{
  UFG::GameSlice::Type mType; // eax
  UFG::qPropertySet *PropertySet; // rdi
  UFG::qPropertySet *RewardsProperties; // rcx
  UFG::qSymbol result; // [rsp+20h] [rbp-18h] BYREF
  __int64 v9; // [rsp+28h] [rbp-10h]
  UFG::qSymbol symGameSliceName; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol *propSetName; // [rsp+58h] [rbp+20h] BYREF

  v9 = -2i64;
  if ( !pGameSlice->mInternalSlice )
  {
    mType = pGameSlice->mType;
    if ( mType >= 5 )
    {
      if ( mType <= 10 )
      {
        RewardsProperties = UFG::GameSlice::GetRewardsProperties(pGameSlice);
      }
      else
      {
        if ( mType != (NUM_TYPES|TYPE_OCCLUSION|0x8) )
          return;
        UFG::qSymbol::create_from_string(&result, "M_VE");
        PropertySet = UFG::GameSlice::GetRewardsProperties(pGameSlice);
        if ( pGameSlice->mNode.mUID == result.mUID )
        {
          propSetName = &symGameSliceName;
          symGameSliceName.mUID = result.mUID;
          if ( UFG::GameStatAction::GameSliceAction::IsCompleted(&symGameSliceName.mUID) )
          {
            UFG::qSymbol::create_from_string((UFG::qSymbol *)&propSetName, "default-rewards-progression-M_VEF");
            if ( UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&propSetName) )
              PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&propSetName);
            else
              PropertySet = 0i64;
          }
        }
        RewardsProperties = PropertySet;
      }
      UFG::GameStatAction::MissionScoring::StartTracking(RewardsProperties);
      if ( resetScore )
        UFG::GameStatAction::MissionScoring::ResetScore();
    }
  }
}

// File Line: 2950
// RVA: 0x4BB8B0
void __fastcall UFG::ProgressionTracker::SetActiveMaster(
        UFG::ProgressionTracker *this,
        UFG::GameSlice *pActiveMaster,
        UFG::GameSlice *pCheckpoint,
        bool forceSave)
{
  char v8; // r14
  bool v9; // di
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::SimObjectCharacter *LocalPlayer; // rax
  float *m_pTransformNodeComponent; // rbx
  UFG::qBaseTreeRB *Named; // rax
  float *mParent; // rbx
  UFG::GameStatTracker *v17; // rax
  UFG::GameStatTracker *v18; // rbx
  UFG::PersistentData::MapBool *v19; // r15
  UFG::PersistentData::MapInt *v20; // r12
  UFG::qBaseTreeRB *i; // rdi

  v8 = 0;
  v9 = 0;
  if ( this->mpActiveMaster != pActiveMaster )
  {
    if ( !pActiveMaster || pActiveMaster->mType == NUM_TYPES )
    {
      v8 = 0;
    }
    else
    {
      v8 = 1;
      pActiveMaster->mSecondsLeftToDisplayFor = pActiveMaster->mStateDisplaySeconds;
      UFG::ProgressionTracker::StartTrackingMissionScoring(this, pActiveMaster, 1);
    }
    this->mpActiveMaster = pActiveMaster;
    this->mDirty = 1;
    UFG::ProgressionTracker::HandleActiveMasterChanged(this);
  }
  if ( this->mpLastCheckpoint != pCheckpoint )
  {
    v9 = pCheckpoint && pCheckpoint->mType != NUM_TYPES;
    x = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_pTransformNodeComponent = (float *)LocalPlayer->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
        x = m_pTransformNodeComponent[44];
        y = m_pTransformNodeComponent[45];
        z = m_pTransformNodeComponent[46];
      }
    }
    if ( pCheckpoint )
    {
      if ( pCheckpoint->mRestoreLocationMarker.mUID != -1 )
      {
        Named = UFG::MarkerBase::GetNamed(&pCheckpoint->mRestoreLocationMarker);
        if ( Named )
        {
          mParent = (float *)Named[1].mNULL.mParent;
          if ( mParent )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)Named[1].mNULL.mParent);
            x = mParent[44];
            y = mParent[45];
            z = mParent[46];
          }
        }
      }
    }
    v17 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v17 + 6216) & 1) == 0 )
    {
      v17->mpSnapshots[0]->mFloats[79].mValue = x;
      if ( (*((_BYTE *)v17 + 6216) & 1) == 0 )
        v17->mpSnapshots[0]->mFloats[80].mValue = y;
    }
    if ( (*((_BYTE *)v17 + 6216) & 1) == 0 )
      v17->mpSnapshots[0]->mFloats[81].mValue = z;
    this->mpLastCheckpoint = pCheckpoint;
    if ( this->mState == STATE_COMPLETE && pCheckpoint && pCheckpoint->mType != NUM_TYPES )
      this->mCheckpointChanged = 1;
  }
  if ( v8 || v9 || forceSave )
  {
    v18 = &sGameStatTracker;
    if ( (_S12_6 & 1) == 0 )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    }
    if ( UFG::GameStatTracker::mspInstance )
      v18 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v18;
    if ( forceSave )
    {
      v19 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[75];
      v20 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapInts[23];
      for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
            i;
            i = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &i->mRoot) )
      {
        if ( SWORD2(i[5].mRoot.mParent) > 0 && BYTE5(i[4].mNULL.mParent) && BYTE6(i[4].mNULL.mParent) )
        {
          UFG::PersistentData::MapBool::SetStatus(v19, (UFG::qSymbol *)&i->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v20, (UFG::qSymbol *)&i->mRoot.mUID, SWORD2(i[5].mRoot.mParent));
          BYTE6(i[4].mNULL.mParent) = 0;
        }
      }
    }
    if ( pCheckpoint )
    {
      if ( this->mState == STATE_COMPLETE )
        UFG::ProgressionTracker::SaveSnapshotWeather(this);
    }
  }
}

// File Line: 3054
// RVA: 0x4A1930
UFG::GameSlice *__fastcall UFG::ProgressionTracker::GetActiveMaster(UFG::ProgressionTracker *this)
{
  return this->mpActiveMaster;
}

// File Line: 3059
// RVA: 0x492400
void __fastcall UFG::ProgressionTracker::ActiveMasterCheck(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpLastCheckpoint; // rax
  UFG::ProgressionTracker::ActiveMasterMode v3; // ebp
  UFG::qBaseTreeRB *v4; // r15
  UFG::GameSlice *v5; // rsi
  UFG::qBaseTreeRB *v6; // r12
  UFG::qBaseTreeRB *v7; // r14
  UFG::qBaseTreeRB *Head; // rdi
  int v9; // eax
  UFG::GameSlice *v10; // rbx
  int mParent; // r15d
  int v12; // ecx
  int v13; // r14d
  int v14; // esi
  __int64 mParent_low; // r8
  UFG::GameSlice **v16; // rdx
  UFG::GameSlice *v17; // rax
  int mState; // ecx
  UFG::qBaseNodeRB *v19; // rax
  UFG::qBaseNodeRB *v20; // rdx
  UFG::GameSlice *v21; // rcx
  bool v22; // al
  UFG::GameSlice *mpParent; // rcx
  int v24; // eax
  bool v25; // r9
  UFG::GameSlice *v26; // r8
  UFG::GameSlice *v27; // rdx
  UFG::GameSlice *mpActiveMaster; // rax
  char v29; // [rsp+70h] [rbp+8h]
  UFG::GameSlice *v30; // [rsp+78h] [rbp+10h]
  UFG::qBaseTreeRB *v31; // [rsp+80h] [rbp+18h]
  UFG::qBaseTreeRB *v32; // [rsp+88h] [rbp+20h]

  mpLastCheckpoint = this->mpLastCheckpoint;
  if ( mpLastCheckpoint && mpLastCheckpoint->mCheckpointSlice && mpLastCheckpoint->mState == STATE_RESTORING )
    return;
  v3 = ActiveMasterMode_OpenWorld;
  v4 = 0i64;
  v31 = 0i64;
  v5 = 0i64;
  v30 = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v32 = 0i64;
  v29 = 0;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
  if ( !Head )
  {
LABEL_54:
    v25 = 0;
    v26 = v5;
    v27 = (UFG::GameSlice *)v4;
    goto LABEL_55;
  }
  do
  {
    v9 = (int)Head[3].mNULL.mChild[1];
    v10 = this->mpLastCheckpoint;
    if ( v9 == 8 )
      goto LABEL_50;
    mParent = (int)Head[5].mNULL.mParent;
    if ( mParent )
    {
      v13 = 0;
      v14 = 0;
      mParent_low = LODWORD(Head[5].mNULL.mParent);
      if ( LODWORD(Head[5].mNULL.mParent) )
      {
        v16 = (UFG::GameSlice **)Head[5].mNULL.mChild[0];
        do
        {
          v17 = *v16;
          mState = (*v16)->mState;
          if ( mState == 8 )
          {
            ++v13;
            if ( v17->mCheckpointSlice )
              v10 = *v16;
            if ( v17->mRequiresSave )
              v29 = 1;
          }
          else
          {
            if ( v17->mOptional )
              ++v14;
            if ( (mState >= 1 || v17->mCompletionCount > 0) && v17->mCheckpointSlice )
              v10 = *v16;
          }
          ++v16;
          --mParent_low;
        }
        while ( mParent_low );
      }
      v19 = Head[5].mNULL.mChild[0];
      v20 = v19->mParent;
      if ( SLODWORD(v19->mParent[8].mChild[0]) < 4 )
        goto LABEL_49;
      v21 = (UFG::GameSlice *)v20[11].mChild[1];
      v22 = v21 ? UFG::GameSlice::IsWaitingForTrigger(v21) : BYTE4(v20[10].mChild[0]) != 0;
      if ( v22 || v13 >= mParent - v14 )
        goto LABEL_49;
      v5 = 0i64;
      if ( v10 )
      {
        if ( v10 == (UFG::GameSlice *)Head
          || (mpParent = v10->mpParent) != 0i64 && UFG::GameSlice::_IsChildOf(mpParent, (UFG::GameSlice *)Head) )
        {
          v5 = v10;
        }
      }
      v24 = HIDWORD(Head[3].mNULL.mChild[1]);
      if ( v24 == 2 )
      {
        v7 = v32;
        v4 = Head;
        v31 = Head;
        v30 = v5;
        goto LABEL_51;
      }
      if ( v6 && SHIDWORD(v6[3].mNULL.mChild[1]) >= v24 )
      {
LABEL_49:
        v7 = v32;
      }
      else
      {
        v6 = Head;
        v7 = (UFG::qBaseTreeRB *)v5;
        v32 = (UFG::qBaseTreeRB *)v5;
      }
      goto LABEL_50;
    }
    if ( v9 != 4 )
      goto LABEL_50;
    v12 = HIDWORD(Head[3].mNULL.mChild[1]);
    if ( ((v12 - 1) & 0xFFFFFFFC) == 0 && v12 != 2 )
      goto LABEL_50;
    if ( v12 != 2 )
    {
      if ( !v6 || SHIDWORD(v6[3].mNULL.mChild[1]) < v12 )
      {
        v7 = 0i64;
        v6 = Head;
        if ( BYTE2(Head[4].mNULL.mChild[0]) )
          v7 = Head;
        v32 = v7;
      }
LABEL_50:
      v4 = v31;
      v5 = v30;
      goto LABEL_51;
    }
    v5 = 0i64;
    v4 = Head;
    v31 = Head;
    if ( BYTE2(Head[4].mNULL.mChild[0]) )
      v5 = (UFG::GameSlice *)Head;
    v30 = v5;
LABEL_51:
    Head = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &Head->mRoot);
  }
  while ( Head );
  if ( !v6 )
    goto LABEL_54;
  v25 = v29;
  v26 = (UFG::GameSlice *)v7;
  v27 = (UFG::GameSlice *)v6;
LABEL_55:
  UFG::ProgressionTracker::SetActiveMaster(this, v27, v26, v25);
  mpActiveMaster = this->mpActiveMaster;
  if ( mpActiveMaster && mpActiveMaster->mType != NUM_TYPES )
  {
    LOBYTE(v3) = this->mModeType != ModeType_Normal;
    ++v3;
  }
  if ( v3 != this->mActiveMasterMode )
  {
    *(_WORD *)&this->mMasterModeChanged = 1;
    this->mActiveMasterMode = v3;
  }
}

// File Line: 3244
// RVA: 0x4A7390
void __fastcall UFG::ProgressionTracker::HandleActiveMasterChanged(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpActiveMaster; // rcx
  char v3; // bl
  UFG::GameSlice *v4; // rcx
  UFG::GameSlice::Type mType; // eax
  UFG::StatGameManager *v6; // rdi

  mpActiveMaster = this->mpActiveMaster;
  v3 = 1;
  if ( mpActiveMaster )
  {
    if ( UFG::GameSlice::IsRewardPropertyRaceType(mpActiveMaster)
      || (v4 = this->mpActiveMaster, mType = v4->mType, mType == 8)
      || this->mModeType != ModeType_Challenge && !v4->mInternalSlice && mType == (NUM_TYPES|TYPE_OCCLUSION|0x8) )
    {
      v3 = 0;
    }
  }
  v6 = UFG::StatGameManager::sInstance;
  if ( !v3 )
    UFG::StatGameManager::FinishCurrentStats(UFG::StatGameManager::sInstance);
  v6->mDefaultFlowGamesAreEnabled = v3;
}

// File Line: 3275
// RVA: 0x4C7480
void __fastcall UFG::ProgressionTracker::UpdateGameSlicesSnapshot(UFG::ProgressionTracker *this)
{
  unsigned int v2; // edx
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // rcx
  UFG::PersistentData::MapBool *v5; // r15
  UFG::PersistentData::MapInt *v6; // rsi
  UFG::PersistentData::KeyValue *p; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v8; // rbx
  UFG::GameSlice *mpActiveMaster; // rax
  UFG::qBaseTreeRB *i; // rdi
  UFG::qBaseTreeRB *j; // rdi
  UFG::GameSlice *v12; // rdx
  UFG::GameSlice *v13; // rcx
  UFG::qBaseTreeRB *k; // rdi
  UFG::qBaseTreeRB *m; // rdi

  v2 = _S12_6;
  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v2 = _S12_6;
  }
  v4 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v5 = v4->mpSnapshots[0]->mpMapBools[75];
  v5->mValues.size = 0;
  v5->mNames.size = 0;
  if ( (v2 & 1) == 0 )
  {
    _S12_6 = v2 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  v6 = v3->mpSnapshots[0]->mpMapInts[23];
  p = v6->mValues.p;
  if ( p )
  {
    v8 = &p[-1].4;
    `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  v6->mValues.p = 0i64;
  *(_QWORD *)&v6->mValues.size = 0i64;
  if ( this->mGameSlices.mTree.mCount )
  {
    mpActiveMaster = this->mpActiveMaster;
    if ( mpActiveMaster && mpActiveMaster->mCompletionCount <= 0 )
    {
      for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
            i;
            i = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mRoot) )
      {
        if ( SWORD2(i[5].mRoot.mParent) > 0 )
        {
          UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&i->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&i->mRoot.mUID, SWORD2(i[5].mRoot.mParent));
        }
      }
      for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
            j;
            j = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mRoot) )
      {
        if ( SWORD2(j[5].mRoot.mParent) > 0 )
        {
          if ( BYTE5(j[4].mNULL.mParent)
            || (v12 = this->mpActiveMaster, j != (UFG::qBaseTreeRB *)v12)
            && ((v13 = (UFG::GameSlice *)j[5].mRoot.mChild[0]) == 0i64 || !UFG::GameSlice::_IsChildOf(v13, v12)) )
          {
            UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&j->mRoot.mUID, 1);
            UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&j->mRoot.mUID, SWORD2(j[5].mRoot.mParent));
          }
        }
      }
    }
    else
    {
      for ( k = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
            k;
            k = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &k->mRoot) )
      {
        if ( SWORD2(k[5].mRoot.mParent) > 0 )
        {
          UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&k->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&k->mRoot.mUID, SWORD2(k[5].mRoot.mParent));
        }
      }
      for ( m = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
            m;
            m = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &m->mRoot) )
      {
        if ( SWORD2(m[5].mRoot.mParent) > 0 )
        {
          UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&m->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&m->mRoot.mUID, SWORD2(m[5].mRoot.mParent));
        }
      }
    }
  }
}

// File Line: 3332
// RVA: 0x4BCFA0
void __fastcall UFG::ProgressionTracker::SetResourceFreezeMode(UFG::ProgressionTracker *this, bool enable)
{
  this->mResourceFreezeMode = enable;
  UFG::SectionChooser::EnableStreamsUpdate(!enable);
}

// File Line: 3338
// RVA: 0x4A4480
UFG::GameSlice *__fastcall UFG::ProgressionTracker::GetLastCheckpoint(UFG::ProgressionTracker *this)
{
  return this->mpLastCheckpoint;
}

// File Line: 3343
// RVA: 0x4BD0F0
void __fastcall UFG::ProgressionTracker::SetScriptRestoreLocation(
        UFG::ProgressionTracker *this,
        UFG::qVector3 *position)
{
  UFG::GameStatTracker *v3; // rbx

  this->mRestoreType = RestoreType_ScriptLocation;
  v3 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
    v3->mpSnapshots[0]->mFloats[79].mValue = position->x;
  if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
    v3->mpSnapshots[0]->mFloats[80].mValue = position->y;
  if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
    v3->mpSnapshots[0]->mFloats[81].mValue = position->z;
}

// File Line: 3353
// RVA: 0x4ACC30
bool __fastcall UFG::ProgressionTracker::IsRunningCriticalActiveMaster(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpActiveMaster; // rax

  mpActiveMaster = this->mpActiveMaster;
  return mpActiveMaster
      && !mpActiveMaster->mInternalSlice
      && gGameSliceTypePriority[mpActiveMaster->mType] == CONTENTPRIORITY_CRITICAL;
}

// File Line: 3366
// RVA: 0x4BCFB0
void __fastcall UFG::ProgressionTracker::SetRestoreType(
        UFG::ProgressionTracker *this,
        UFG::ProgressionTracker::RestoreType restoreType,
        bool useCurrentLocation)
{
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm6_4
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::GameStatTracker *v8; // rax

  this->mRestoreType = restoreType;
  if ( useCurrentLocation )
  {
    x = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
        x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        y = m_pTransformNodeComponent->mWorldTransform.v3.y;
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      }
    }
    v8 = UFG::GameStatTracker::Instance();
    if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
    {
      v8->mpSnapshots[0]->mFloats[79].mValue = x;
      if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
        v8->mpSnapshots[0]->mFloats[80].mValue = y;
    }
    if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
      v8->mpSnapshots[0]->mFloats[81].mValue = z;
  }
}

// File Line: 3404
// RVA: 0x4B1970
void __fastcall UFG::ProgressionTracker::OnFailObject(
        UFG::ProgressionTracker *this,
        UFG::SimObjectGame *pObject,
        UFG::qString *caption)
{
  UFG::GameSlice *mpCustomGameSlice; // rbx
  signed __int16 m_Flags; // cx
  UFG::MissionFailConditionComponent *ComponentOfTypeHK; // rax
  UFG::qSymbol *OwnerLayer; // rax
  UFG::qSymbolUC *v10; // rdi

  if ( this->mState != 10 )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[Progression]:  This object (%s) caused a mission fail, reason: (%s)\n");
    mpCustomGameSlice = 0i64;
    if ( !pObject
      || ((m_Flags = pObject->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? (ComponentOfTypeHK = (UFG::MissionFailConditionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         pObject,
                                                                         UFG::MissionFailConditionComponent::_TypeUID))
          : (ComponentOfTypeHK = (UFG::MissionFailConditionComponent *)UFG::SimObject::GetComponentOfType(
                                                                         pObject,
                                                                         UFG::MissionFailConditionComponent::_TypeUID)))
         : (ComponentOfTypeHK = (UFG::MissionFailConditionComponent *)pObject->m_Components.p[8].m_pComponent))
        : (ComponentOfTypeHK = (UFG::MissionFailConditionComponent *)pObject->m_Components.p[8].m_pComponent),
          !ComponentOfTypeHK || (mpCustomGameSlice = ComponentOfTypeHK->mpCustomGameSlice) == 0i64) )
    {
      OwnerLayer = (UFG::qSymbol *)UFG::SceneObjectProperties::FindOwnerLayer(pObject->m_pSceneObj);
      if ( !OwnerLayer )
      {
LABEL_16:
        UFG::ProgressionTracker::OnFailGameSlice(this, mpCustomGameSlice, caption);
        return;
      }
      v10 = (UFG::qSymbolUC *)&OwnerLayer[6];
      mpCustomGameSlice = (UFG::GameSlice *)UFG::ProgressionTracker::FindByLayer(this, OwnerLayer + 6);
      if ( !mpCustomGameSlice )
      {
        UFG::qSymbol::as_cstr_dbg(v10);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]: Unable to find the proper game slice that this object is attached to in order to fail it.  The layer is (%s)\n");
        goto LABEL_16;
      }
    }
    while ( mpCustomGameSlice->mpParent )
      mpCustomGameSlice = mpCustomGameSlice->mpParent;
    goto LABEL_16;
  }
}

// File Line: 3451
// RVA: 0x4B1840
void __fastcall UFG::ProgressionTracker::OnFailGameSlice(
        UFG::ProgressionTracker *this,
        UFG::GameSlice *pGameSlice,
        UFG::qString *caption)
{
  UFG::GameSlice *mpActiveMaster; // rbx
  __int64 mCount; // rsi
  __int64 v7; // rdi
  UFG::SSGameSlice *mScript; // rcx
  UFG::SSGameSlice *v9; // rcx

  mpActiveMaster = pGameSlice;
  if ( this->mState != 10 && (!pGameSlice || pGameSlice->mScript) )
  {
    this->mpLastFailed = pGameSlice;
    if ( !pGameSlice )
    {
      mpActiveMaster = this->mpActiveMaster;
      if ( !mpActiveMaster )
        return;
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]:  The passed in GameSlice is NULL, so trying to fail the active mission(%s)[%s]\n");
    }
    if ( mpActiveMaster->mScript )
    {
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]:  Failing Gameslice(%s)[%s]\n");
      mCount = mpActiveMaster->mChildren.mCount;
      v7 = 0i64;
      if ( mpActiveMaster->mChildren.mCount )
      {
        do
        {
          mScript = mpActiveMaster->mChildren.mppArray[v7]->mScript;
          if ( mScript )
            SSActor::suspend_coroutines(&mScript->SSActor);
          ++v7;
        }
        while ( v7 < mCount );
      }
      v9 = mpActiveMaster->mScript;
      if ( v9 )
        SSActor::suspend_coroutines(&v9->SSActor);
      this->mState = 10;
      UFG::GameSlice::FailSlice(mpActiveMaster, caption);
    }
  }
}

// File Line: 3502
// RVA: 0x4B0680
char __fastcall UFG::ProgressionTracker::LoadedProgression(
        UFG::ProgressionTracker *this,
        unsigned int dPoint,
        char *pDeserializeBuffer,
        unsigned int bufferSize,
        bool resetProgression)
{
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseTreeRB *j; // rax
  UFG::GameStatTracker *v11; // rdi
  UFG::GameStatTracker *v12; // rcx
  char v13; // si
  unsigned int mUID; // eax
  char *v15; // rbx
  char *v16; // rax
  UFG::qSymbolUC v18; // [rsp+50h] [rbp+8h] BYREF

  if ( resetProgression )
  {
    UFG::ProgressionTracker::ResetProgression(this, RestoreType_Safehouse, uidGameStateRestoreCheckpoint_9, 1);
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
          i;
          i = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mRoot) )
    {
      *(_QWORD *)&i[3].mCount = 0i64;
    }
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
          j;
          j = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mRoot) )
    {
      *(_QWORD *)&j[3].mCount = 0i64;
    }
  }
  v11 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v12 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v12 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v12;
  v13 = UFG::GameStatTracker::ResetFromLoadedBuffer(v12, dPoint, pDeserializeBuffer, bufferSize);
  if ( resetProgression )
    this->mpLastCheckpoint = (UFG::GameSlice *)UFG::ProgressionTracker::GetStartupSlice(this);
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v11 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v11;
  mUID = v11->mpSnapshots[0]->mIDs[25].mValue.mUID;
  if ( mUID == -1 )
    mUID = gDefaultFlowId.mUID;
  v18.mUID = mUID;
  if ( mUID == this->mActiveFlowId.mUID )
  {
    UFG::ProgressionTracker::UpdatePermanentDLC(this);
    return v13;
  }
  else
  {
    v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mActiveFlowId);
    v16 = UFG::qSymbol::as_cstr_dbg(&v18);
    UFG::qPrintf(
      "[ProgressionTracker::LoadedProgression] - Returning false because the save game is loaded from the wrong flow (%s)"
      " - Active flow (%s)\n",
      v16,
      v15);
    return 0;
  }
}

// File Line: 3557
// RVA: 0x4C7980
void __fastcall UFG::ProgressionTracker::UpdatePermanentDLC(UFG::ProgressionTracker *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rdx
  UFG::GameStatTracker *v3; // rsi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapFloat *mList; // rdi
  unsigned int i; // ebx
  unsigned int size; // ecx
  bool v8; // cf
  UFG::qSymbol *v9; // rdx
  unsigned int mUID; // eax
  UFG::PersistentData::MapBool *v11; // r10
  __int64 v12; // rdx
  unsigned int v13; // r8d
  bool mBoolValue; // al
  __int64 v15; // rdx
  unsigned int v16; // r8d
  unsigned int v17; // r8d
  __int64 v18; // rcx
  UFG::PersistentData::KeyValue *p; // rdx
  unsigned int v20; // edx
  UFG::GameStatTracker *v21; // r8
  UFG::GameStatTracker *v22; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol name; // [rsp+68h] [rbp+10h] BYREF

  v1 = _S12_6;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
  }
  v2 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = v2;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v2 = UFG::GameStatTracker::mspInstance;
  }
  v4 = &sGameStatTracker;
  if ( v2 )
    v4 = v2;
  UFG::GameStatTracker::mspInstance = v4;
  UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v4->mpSnapshots[0]->mpMapBools[83], &result);
  mList = result.mList;
  for ( i = result.mIndex; ; ++i )
  {
    size = mList->mValues.size;
    if ( mList->mValues.size )
    {
      if ( size - 1 > 1 )
        return;
      v8 = i < mList[1].mValues.size;
    }
    else
    {
      v8 = i < LODWORD(mList->mValues.p);
    }
    if ( !v8 )
      break;
    if ( size )
    {
      if ( size - 1 > 1 )
        v9 = &UFG::gNullQSymbol;
      else
        v9 = (UFG::qSymbol *)mList[1].mValues.p + i;
    }
    else
    {
      v9 = (UFG::qSymbol *)(*(_QWORD *)&mList->mPersistentDataType + 8i64 * i);
    }
    mUID = v9->mUID;
    name.mUID = v9->mUID;
    v11 = v3->mpSnapshots[0]->mpMapBools[61];
    if ( v11->mKeepType )
    {
      if ( v11->mKeepType == KEEP_TRUE )
      {
        v15 = 0i64;
        v16 = v11->mNames.size;
        if ( v16 )
        {
          while ( mUID != v11->mNames.p[v15].mUID )
          {
            v15 = (unsigned int)(v15 + 1);
            if ( (unsigned int)v15 >= v16 )
              goto LABEL_31;
          }
        }
        else
        {
LABEL_31:
          LODWORD(v15) = -1;
        }
        mBoolValue = (_DWORD)v15 != -1;
LABEL_40:
        if ( mBoolValue )
          continue;
        goto LABEL_41;
      }
      v12 = (unsigned int)(v11->mKeepType - 2);
      if ( v11->mKeepType == KEEP_FALSE )
      {
        v13 = v11->mNames.size;
        if ( v13 )
        {
          while ( mUID != v11->mNames.p[v12].mUID )
          {
            v12 = (unsigned int)(v12 + 1);
            if ( (unsigned int)v12 >= v13 )
              goto LABEL_26;
          }
        }
        else
        {
LABEL_26:
          LODWORD(v12) = -1;
        }
        mBoolValue = (_DWORD)v12 == -1;
        goto LABEL_40;
      }
    }
    else
    {
      v17 = v11->mValues.size;
      v18 = 0i64;
      if ( v17 )
      {
        p = v11->mValues.p;
        while ( p->mKey.mUID != mUID )
        {
          v18 = (unsigned int)(v18 + 1);
          ++p;
          if ( (unsigned int)v18 >= v17 )
            goto LABEL_41;
        }
        if ( (_DWORD)v18 != -1 )
        {
          mBoolValue = v11->mValues.p[v18].mBoolValue;
          goto LABEL_40;
        }
      }
    }
LABEL_41:
    if ( (*((_BYTE *)v3 + 6216) & 1) == 0 )
    {
      UFG::PersistentData::MapBool::SetStatus(v11, &name, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v20 = _S12_6;
        if ( (_S12_6 & 1) == 0 )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v20 = _S12_6;
        }
        v21 = &sGameStatTracker;
        if ( UFG::GameStatTracker::mspInstance )
          v21 = UFG::GameStatTracker::mspInstance;
        UFG::GameStatTracker::mspInstance = v21;
        if ( (v20 & 1) == 0 )
        {
          _S12_6 = v20 | 1;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          v21 = UFG::GameStatTracker::mspInstance;
        }
        v22 = &sGameStatTracker;
        if ( v21 )
          v22 = v21;
        UFG::GameStatTracker::mspInstance = v22;
        if ( UFG::GameStatAction::Store::AreAllClothesPurchased() )
          UFG::AchievementTrophyManager::UnlockAchievementTrophy(37);
      }
    }
  }
}

// File Line: 3579
// RVA: 0x4A6410
UFG::qBaseTreeRB *__fastcall UFG::ProgressionTracker::GetStartupSlice(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v1; // rbx
  unsigned int mUID; // ebx
  __int64 v3; // rsi
  UFG::qBaseTreeRB *v4; // rdi
  UFG::ProgressionTracker *v5; // rax
  UFG::ProgressionTracker *v6; // rbx
  unsigned int v7; // edx
  UFG::qBaseTreeRB *result; // rax
  unsigned int v9; // edx

  v1 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  mUID = v1->mpSnapshots[0]->mIDs[28].mValue.mUID;
  v3 = 0i64;
  if ( mUID == -1 )
    return (UFG::qBaseTreeRB *)v3;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( mUID )
  {
    v4 = UFG::qBaseTreeRB::Get(&stru_14240A100, mUID);
    if ( !v4 )
      v4 = UFG::qBaseTreeRB::Get(&stru_14240A148, mUID);
  }
  else
  {
    v4 = 0i64;
  }
  if ( !v4 || HIDWORD(v4[2].mNULL.mChild[0]) == -1 )
    return (UFG::qBaseTreeRB *)v3;
  v5 = UFG::ProgressionTracker::Instance();
  v6 = v5;
  v7 = HIDWORD(v4[2].mNULL.mChild[0]);
  if ( !v7 || (result = UFG::qBaseTreeRB::Get(&v5->mGameSlices.mTree, v7)) == 0i64 )
  {
    v9 = HIDWORD(v4[2].mNULL.mChild[0]);
    if ( v9 )
      return UFG::qBaseTreeRB::Get(&v6->mContainerGameSlices.mTree, v9);
    return (UFG::qBaseTreeRB *)v3;
  }
  return result;
}

// File Line: 3596
// RVA: 0x4A60E0
UFG::qBaseNodeRB *__fastcall UFG::ProgressionTracker::GetSaveGameName(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpLastCheckpoint; // rdi
  UFG::qSharedStringData *v2; // rbx
  UFG::GameStatTracker *v4; // rbx
  unsigned int mUID; // ebx
  __int64 v6; // rsi
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qSharedStringData *v8; // rbx

  mpLastCheckpoint = this->mpLastCheckpoint;
  if ( mpLastCheckpoint )
  {
    v2 = (UFG::qSharedStringData *)(mpLastCheckpoint->mSaveGameNameOverride.mText - 48);
    if ( v2 != UFG::qSharedStringData::GetEmptyString() )
      return (UFG::qBaseNodeRB *)mpLastCheckpoint->mSaveGameNameOverride.mText;
  }
  v4 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  mUID = v4->mpSnapshots[0]->mIDs[28].mValue.mUID;
  v6 = 0i64;
  if ( mUID != -1 )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( mUID )
    {
      v7 = UFG::qBaseTreeRB::Get(&stru_14240A100, mUID);
      if ( !v7 )
        v7 = UFG::qBaseTreeRB::Get(&stru_14240A148, mUID);
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
    {
      v8 = (UFG::qSharedStringData *)&v7[2].mRoot.mChild[1][-2].mChild[1];
      if ( v8 == UFG::qSharedStringData::GetEmptyString() )
        return v7->mNULL.mChild[0];
      else
        return v7[2].mRoot.mChild[1];
    }
  }
  return (UFG::qBaseNodeRB *)v6;
}

// File Line: 3630
// RVA: 0x4B7060
void __fastcall UFG::ProgressionTracker::ResetProgression(
        UFG::ProgressionTracker *this,
        UFG::ProgressionTracker::RestoreType restoreType,
        unsigned int newGameState,
        bool useCurrentLocation)
{
  UFG::GameSlice *i; // rbx
  UFG::GameSlice *j; // rbx
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll(&this->mLayerOwnership);
  this->mpLastCheckpoint = 0i64;
  for ( i = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
        i;
        i = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mNode) )
  {
    UFG::GameSlice::ForceLock(i, 1);
  }
  for ( j = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
        j;
        j = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mNode) )
  {
    UFG::GameSlice::ForceLock(j, 1);
  }
  UFG::ObjectiveTracker::OnRestore(&this->mObjectiveTracker);
  if ( this->mPDATriggerTracker.mPDATriggers.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mPDATriggerTracker);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      p_mNode = &Head->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mPDATriggerTracker,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !this->mPDATriggerTracker.mPDATriggers.mTree.mCount )
        goto LABEL_14;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_10:
    p_mNode = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  this->mState = NUM_STATES;
  this->mpActiveMaster = 0i64;
  *(_WORD *)&this->mDirty = 0;
  this->mLastUpdateTimestamp = 0i64;
  this->mContainerCompletedTimestamp = 0i64;
  UFG::ProgressionTracker::SetRestoreType(this, restoreType, useCurrentLocation);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, newGameState);
}

// File Line: 3666
// RVA: 0x4B0850
void __fastcall UFG::ProgressionTracker::LockAllRunningGameSlicesForSoftReset(UFG::ProgressionTracker *this)
{
  UFG::qSymbol *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseTreeRB *j; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v2 = UFG::qSymbol::create_from_string(&result, "LivingWorld");
  if ( v2->mUID && (v3 = UFG::qBaseTreeRB::Get(&this->mGameSlices.mTree, v2->mUID)) != 0i64
    || (v2->mUID ? (v3 = UFG::qBaseTreeRB::Get(&this->mContainerGameSlices.mTree, v2->mUID)) : (v3 = 0i64), v3) )
  {
    UFG::GameSlice::ForceLock((UFG::GameSlice *)v3, 0);
  }
  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll(&this->mLayerOwnership);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mContainerGameSlices.mTree, &i->mRoot) )
  {
    if ( (unsigned int)(LODWORD(i[3].mNULL.mChild[1]) - 1) <= 6 )
      UFG::GameSlice::ForceLock((UFG::GameSlice *)i, 0);
  }
  for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
        j;
        j = UFG::qBaseTreeRB::GetNext(&this->mGameSlices.mTree, &j->mRoot) )
  {
    if ( (unsigned int)(LODWORD(j[3].mNULL.mChild[1]) - 1) <= 6 )
      UFG::GameSlice::ForceLock((UFG::GameSlice *)j, 0);
  }
}

// File Line: 3695
// RVA: 0x4B7660
void __fastcall UFG::ProgressionTracker::RestoreCheckpoint(UFG::ProgressionTracker *this)
{
  UFG::UpdatePlayerDismountLocation((UFG *)this);
  UFG::ProgressionTracker::RestoreCheckpointInternal(this);
  UFG::ProgressionTracker::DiscardSnapshot(this);
}

// File Line: 3708
// RVA: 0x4B7690
void __fastcall UFG::ProgressionTracker::RestoreCheckpointInternal(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *mpActiveMaster; // rcx
  unsigned int v3; // edx

  if ( (unsigned int)(this->mState - 6) > 3 )
  {
    if ( this->mpLastCheckpoint )
    {
      UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
      UFG::GameSlice::ForceLock(this->mpLastCheckpoint, 0);
    }
    mpActiveMaster = this->mpActiveMaster;
    if ( mpActiveMaster )
      UFG::GameSlice::ForceLock(mpActiveMaster, 0);
    UFG::ProgressionTracker::LockAllRunningGameSlicesForSoftReset(this);
    UFG::ObjectiveTracker::OnRestore(&this->mObjectiveTracker);
    UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&this->mPDATriggerTracker);
    v3 = uidGameStateRestoreCheckpoint_9;
    this->mState = NUM_STATES;
    this->mpActiveMaster = 0i64;
    *(_WORD *)&this->mDirty = 0;
    this->mLastUpdateTimestamp = 0i64;
    this->mContainerCompletedTimestamp = 0i64;
    UFG::FlowController::RequestSetNewState(&UFG::gFlowController, v3);
  }
}

// File Line: 3749
// RVA: 0x4968F0
void __fastcall UFG::ProgressionTracker::CancelMission(
        UFG::ProgressionTracker *this,
        UFG::GameSlice *pGameSlice,
        bool resetScene,
        UFG::ProgressionTracker::RestoreType restoreType)
{
  UFG::GameSlice *v5; // rbx
  UFG::GameStatTracker *v7; // rbx
  int v8; // eax
  UFG::GameSlice *mpActiveMaster; // rax
  const char *mText; // r8

  v5 = pGameSlice;
  if ( resetScene )
  {
    if ( this->mActiveMasterMode == ActiveMasterMode_Challenge_Container )
    {
      UFG::ProgressionTracker::ExitChallenge(this, 0);
    }
    else
    {
      v7 = UFG::GameStatTracker::Instance();
      UFG::ProgressionTracker::ResetProgression(
        this,
        restoreType,
        uidGameStateRestoreCheckpoint_9,
        restoreType != RestoreType_ScriptLocation);
      UFG::GameStatTracker::CommitPermanentDataTo(v7, Snapshot_OpenWorld);
      UFG::GameSnapshot::Clone(v7->mpSnapshots[0], v7->mpSnapshots[1]);
    }
  }
  else if ( this->mState != (STATE_COMPLETE|0x8) )
  {
    this->mpLastFailed = pGameSlice;
    if ( pGameSlice )
    {
      while ( v5->mpParent )
        v5 = v5->mpParent;
      UFG::GameSlice::ForceLock(v5, 0);
      v8 = 1;
      if ( v5->mState == STATE_STARTED )
        v8 = 3;
      v5->mCompletionStatus = v8;
      v5->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    }
    mpActiveMaster = this->mpActiveMaster;
    if ( v5 == mpActiveMaster )
    {
      UFG::GameStatAction::MissionScoring::FinishedTracking();
      this->mpActiveMaster = 0i64;
      this->mpLastCheckpoint = 0i64;
      UFG::ObjectiveTracker::OnFail(&this->mObjectiveTracker);
      this->mState = STATE_COMPLETE|0x8;
    }
    else
    {
      if ( mpActiveMaster )
        mText = mpActiveMaster->mName.mText;
      else
        mText = "*NoActiveMaster*";
      UFG::qPrintf("Warning: (%s) called CancelMission when (%s) is running\n", v5->mName.mText, mText);
    }
  }
}

// File Line: 3822
// RVA: 0x49DC00
void __fastcall UFG::ProgressionTracker::EnableGameSliceTODWait(
        UFG::ProgressionTracker *this,
        UFG::GameSlice *slice,
        UFG::ProgressionTriggerComponent *trigger)
{
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *v4; // rax
  unsigned int v5; // ebx
  UFG::UIHKHelpBarWidget *v6; // rax

  this->mTimeShiftSlice = slice;
  this->mTimeShiftTrigger = trigger;
  if ( slice )
  {
    v3 = UFG::qStringHash32("ProgressionTracker", 0xFFFFFFFF);
    v4 = UFG::UIHKHelpBarWidget::Get();
    UFG::UIHKHelpBarWidget::Show(
      v4,
      v3,
      PRIORITY_ONE,
      ALIGN_RIGHT,
      BUTTON2_BUTTON,
      "$ACTIVATE_TIME_RESTRICTED_SLICE",
      INVALID_BUTTON,
      &customCaption,
      INVALID_BUTTON,
      &customCaption,
      INVALID_BUTTON,
      &customCaption,
      INVALID_BUTTON,
      &customCaption,
      INVALID_BUTTON,
      &customCaption);
  }
  else
  {
    v5 = UFG::qStringHash32("ProgressionTracker", 0xFFFFFFFF);
    v6 = UFG::UIHKHelpBarWidget::Get();
    UFG::UIHKHelpBarWidget::Hide(v6, v5);
  }
}

// File Line: 3843
// RVA: 0x4B8DB0
void __fastcall UFG::ProgressionTracker::SaveSnapshotWeather(UFG::ProgressionTracker *this)
{
  UFG::TimeOfDayManager *Instance; // rax
  float m_WeatherState; // xmm6_4
  float m_WeatherSurfaceWetness; // xmm8_4
  float m_SecondsSinceMidnight; // xmm7_4
  unsigned int v5; // ecx
  UFG::GameStatTracker *v6; // rbx
  UFG::GameStatTracker *v7; // rdx
  UFG::GameStatTracker *v8; // rax

  Instance = UFG::TimeOfDayManager::GetInstance();
  m_WeatherState = Instance->m_WeatherState;
  m_WeatherSurfaceWetness = Instance->m_WeatherSurfaceWetness;
  m_SecondsSinceMidnight = Instance->m_SecondsSinceMidnight;
  v5 = _S12_6;
  v6 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = _S12_6;
  }
  v7 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  if ( (*((_BYTE *)v7 + 6216) & 1) == 0 )
  {
    v7->mpSnapshots[0]->mFloats[129].mValue = m_WeatherState;
    v7 = UFG::GameStatTracker::mspInstance;
  }
  if ( (v5 & 1) == 0 )
  {
    _S12_6 = v5 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = _S12_6;
    v7 = UFG::GameStatTracker::mspInstance;
  }
  v8 = &sGameStatTracker;
  if ( v7 )
    v8 = v7;
  UFG::GameStatTracker::mspInstance = v8;
  if ( (*((_BYTE *)v8 + 6216) & 1) == 0 )
  {
    v8->mpSnapshots[0]->mFloats[130].mValue = m_WeatherSurfaceWetness;
    v8 = UFG::GameStatTracker::mspInstance;
  }
  if ( (v5 & 1) == 0 )
  {
    _S12_6 = v5 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v8 = UFG::GameStatTracker::mspInstance;
  }
  if ( v8 )
    v6 = v8;
  UFG::GameStatTracker::mspInstance = v6;
  if ( (*((_BYTE *)v6 + 6216) & 1) == 0 )
    v6->mpSnapshots[0]->mFloats[131].mValue = m_SecondsSinceMidnight;
}

// File Line: 3856
// RVA: 0x4AEE80
void __fastcall UFG::ProgressionTracker::LoadSnapshotWeather(UFG::ProgressionTracker *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rdx
  float mValue; // xmm6_4
  UFG::GameStatTracker *v5; // r8
  float v6; // xmm8_4
  float v7; // xmm7_4
  UFG::TimeOfDayManager *Instance; // rax
  float v9; // xmm0_4

  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
  }
  v3 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  mValue = v3->mpSnapshots[0]->mFloats[129].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v1 = _S12_6;
    v3 = UFG::GameStatTracker::mspInstance;
  }
  v5 = &sGameStatTracker;
  if ( v3 )
    v5 = v3;
  UFG::GameStatTracker::mspInstance = v5;
  v6 = v5->mpSnapshots[0]->mFloats[130].mValue;
  if ( (v1 & 1) == 0 )
  {
    _S12_6 = v1 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v5 = UFG::GameStatTracker::mspInstance;
  }
  if ( v5 )
    v2 = v5;
  UFG::GameStatTracker::mspInstance = v2;
  v7 = v2->mpSnapshots[0]->mFloats[131].mValue;
  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( mValue <= 0.0 )
  {
    mValue = 0.0;
  }
  else
  {
    v9 = FLOAT_2_0;
    if ( mValue >= 2.0 )
      goto LABEL_18;
  }
  v9 = mValue;
LABEL_18:
  Instance->m_WeatherState = v9;
  Instance->m_WeatherTarget = v9;
  Instance->m_NextWeatherTarget = v9;
  Instance->m_WeatherSurfaceWetness = v6;
  UFG::TimeOfDayManager::SetTime(Instance, v7, 0);
}

// File Line: 3878
// RVA: 0x4C8A60
bool __fastcall UFG::ProgressionTracker::UpdateTimeShift(UFG::ProgressionTracker *this, float realTimeDelta)
{
  UFG::GameSlice *mTimeShiftSlice; // rcx
  float v4; // xmm1_4
  UFG::ProgressionTracker::TimeShiftState mTimeShiftState; // eax
  bool result; // al
  float mTODActive; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax
  UFG::ProgressionTriggerComponent *mTimeShiftTrigger; // rcx
  unsigned int v10; // ebx
  UFG::UIHKHelpBarWidget *v11; // rax

  mTimeShiftSlice = this->mTimeShiftSlice;
  if ( !mTimeShiftSlice || !mTimeShiftSlice->mIsTODRestricted )
    return 0;
  v4 = realTimeDelta + this->mTimeShiftTimer;
  mTimeShiftState = this->mTimeShiftState;
  this->mTimeShiftTimer = v4;
  if ( mTimeShiftState == TS_FADE_OUT )
  {
    UFG::UIHK_NISOverlay::ShowCurtains(1.0, 1);
    result = 1;
    *(_QWORD *)&this->mTimeShiftState = 6i64;
    return result;
  }
  if ( mTimeShiftState == TS_FADE_OUT2 )
  {
    if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
      this->mTimeShiftState = TS_SHIFT;
    return 1;
  }
  if ( mTimeShiftState != TS_SHIFT )
  {
    if ( mTimeShiftState == TS_SHIFT2 )
    {
      if ( v4 < 2.0 )
        UFG::SyncLoadCurrentLocation((UFG *)mTimeShiftSlice);
      else
        this->mTimeShiftState = TS_FADE_IN;
      return 1;
    }
    if ( mTimeShiftState == TS_FADE_IN )
    {
      UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
      result = 0;
      this->mTimeShiftState = TS_STATE_NONE;
      this->mTimeShiftSlice = 0i64;
      this->mTimeShiftTrigger = 0i64;
      return result;
    }
    return 0;
  }
  if ( !UFG::GameSlice::IsAllowedAtThisTimeOfDay(mTimeShiftSlice) )
  {
    mTODActive = this->mTimeShiftSlice->mTODActive;
    Instance = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::SetTime(Instance, mTODActive, 0);
  }
  mTimeShiftTrigger = this->mTimeShiftTrigger;
  *(_QWORD *)&this->mTimeShiftState = 4i64;
  UFG::ProgressionTriggerComponent::ForceOnEnter(mTimeShiftTrigger);
  v10 = UFG::qStringHash32("ProgressionTracker", 0xFFFFFFFF);
  v11 = UFG::UIHKHelpBarWidget::Get();
  UFG::UIHKHelpBarWidget::Hide(v11, v10);
  return 1;
}

// File Line: 3947
// RVA: 0x4C8FE0
void __fastcall UFG::ProgressionTracker::WaitForStreamer(UFG::ProgressionTracker *this)
{
  char IsComplete; // bp
  char v3; // si
  UFG::PartDatabase *v4; // rax
  UFG::PartDatabase *v5; // rax
  bool v6; // bl
  bool v7; // al

  IsComplete = UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3);
  v3 = UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 7);
  v4 = (UFG::PartDatabase *)UFG::ObjectResourceManager::Instance();
  v6 = 0;
  if ( !UFG::ObjectResourceManager::HasQueue(v4) )
  {
    v5 = UFG::PartDatabase::Instance();
    if ( !UFG::ObjectResourceManager::HasQueue(v5) )
      v6 = 1;
  }
  v7 = UFG::PedSpawnManager::SpawnsQueued();
  if ( !IsComplete || !v3 || v6 || v7 || UFG::StoreMeshHelper::sSwapQueued )
  {
    this->mbPendingSceneSettingsValid = 0;
    UFG::SceneSettings::Reset(&this->mPendingSceneSettingsLocal);
    UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
  }
}

// File Line: 3963
// RVA: 0x494C90
void __fastcall UFG::ProgressionTracker::ApplySceneSettings(
        UFG::ProgressionTracker *this,
        UFG::SceneSettings *settings)
{
  this->mbPendingSceneSettingsValid = 1;
  UFG::SceneSettings::operator=(&this->mPendingSceneSettingsLocal, settings);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
}

// File Line: 3972
// RVA: 0x494CC0
void __fastcall UFG::ProgressionTracker::ApplySceneSettingsCached(
        UFG::ProgressionTracker *this,
        UFG::SceneSettings *settings)
{
  UFG::SceneSettings::operator=(&this->mPendingSceneSettingsCache, settings);
  this->mbPendingSceneSettingsValid = 1;
  UFG::SceneSettings::operator=(&this->mPendingSceneSettingsLocal, &this->mPendingSceneSettingsCache);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
}

// File Line: 3979
// RVA: 0x494C10
void __fastcall UFG::ProgressionTracker::ApplySceneSettings(UFG::ProgressionTracker *this, UFG::qVector3 *position)
{
  UFG::SceneSettings *p_mPendingSceneSettingsCache; // rdi
  float x; // eax
  float z; // xmm1_4

  p_mPendingSceneSettingsCache = &this->mPendingSceneSettingsCache;
  UFG::SceneSettings::Reset(&this->mPendingSceneSettingsCache);
  p_mPendingSceneSettingsCache->mHasTeleportPositionInternal = 1;
  x = position->x;
  z = position->z;
  p_mPendingSceneSettingsCache->mTeleportPositionInternal.y = position->y;
  p_mPendingSceneSettingsCache->mTeleportPositionInternal.z = z;
  p_mPendingSceneSettingsCache->mTeleportPositionInternal.x = x;
  this->mbPendingSceneSettingsValid = 1;
  UFG::SceneSettings::operator=(&this->mPendingSceneSettingsLocal, p_mPendingSceneSettingsCache);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
}

// File Line: 3986
// RVA: 0x4C5D00
float __fastcall UFG::ProgressionTracker::UpdateCompletionPercentage(UFG::ProgressionTracker *this)
{
  UFG::GameStatTracker *v1; // rbx
  UFG::GameSnapshot *v2; // r13
  UFG::PersistentData::MapBool *v3; // rdx
  unsigned int v4; // ecx
  unsigned int size; // edi
  UFG::PersistentData::MapBool *v6; // r8
  unsigned int v7; // ebp
  UFG::PersistentData::MapBool *v8; // rbx
  unsigned int v9; // esi
  UFG::PersistentData::MapBool *v10; // r14
  unsigned int v11; // r11d
  UFG::PersistentData::MapBool *v12; // r15
  unsigned int v13; // r10d
  UFG::PersistentData::MapBool *v14; // r12
  unsigned int v15; // r9d
  UFG::PersistentData::MapBool *v16; // r13
  unsigned int v17; // eax
  unsigned int v18; // esi
  unsigned int v19; // r9d
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v20; // rax
  __int64 v21; // rdx
  unsigned int v22; // edi
  __int64 v23; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v24; // rax
  unsigned int v25; // r11d
  __int64 v26; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v27; // rax
  unsigned int v28; // r10d
  __int64 v29; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v30; // rax
  unsigned int v31; // r9d
  __int64 v32; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v33; // rax
  unsigned int v34; // r8d
  __int64 v35; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v36; // rax
  __int64 v37; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v38; // rax
  float result; // xmm0_4
  int v40; // [rsp+78h] [rbp+10h]
  UFG::GameStatTracker *v41; // [rsp+80h] [rbp+18h]
  float *v42; // [rsp+88h] [rbp+20h]

  v1 = &sGameStatTracker;
  if ( (_S12_6 & 1) == 0 )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  v41 = v1;
  UFG::GameStatTracker::mspInstance = v1;
  v2 = v1->mpSnapshots[0];
  v42 = (float *)v2;
  v3 = v2->mpMapBools[66];
  v4 = 0;
  if ( v3->mKeepType )
  {
    if ( (unsigned int)(v3->mKeepType - 1) > 1 )
      size = 0;
    else
      size = v3->mNames.size;
  }
  else
  {
    size = v3->mValues.size;
  }
  v6 = v2->mpMapBools[67];
  if ( v6->mKeepType )
  {
    if ( (unsigned int)(v6->mKeepType - 1) > 1 )
      v7 = 0;
    else
      v7 = v6->mNames.size;
  }
  else
  {
    v7 = v6->mValues.size;
  }
  v8 = v2->mpMapBools[68];
  if ( v8->mKeepType )
  {
    if ( (unsigned int)(v8->mKeepType - 1) > 1 )
      v9 = 0;
    else
      v9 = v8->mNames.size;
  }
  else
  {
    v9 = v8->mValues.size;
  }
  v10 = v2->mpMapBools[69];
  if ( v10->mKeepType )
  {
    if ( (unsigned int)(v10->mKeepType - 1) > 1 )
      v11 = 0;
    else
      v11 = v10->mNames.size;
  }
  else
  {
    v11 = v10->mValues.size;
  }
  v12 = v2->mpMapBools[71];
  if ( v12->mKeepType )
  {
    if ( (unsigned int)(v12->mKeepType - 1) > 1 )
      v13 = 0;
    else
      v13 = v12->mNames.size;
  }
  else
  {
    v13 = v12->mValues.size;
  }
  v14 = v2->mpMapBools[72];
  if ( v14->mKeepType )
  {
    if ( (unsigned int)(v14->mKeepType - 1) > 1 )
      v15 = 0;
    else
      v15 = v14->mNames.size;
  }
  else
  {
    v15 = v14->mValues.size;
  }
  v16 = v2->mpMapBools[73];
  if ( v16->mKeepType )
  {
    if ( (unsigned int)(v16->mKeepType - 1) > 1 )
      v17 = 0;
    else
      v17 = v16->mNames.size;
  }
  else
  {
    v17 = v16->mValues.size;
  }
  v40 = size + v7 + v9 + v11 + v13 + v15 + v17;
  if ( v3->mKeepType == KEEP_FALSE )
  {
    v18 = 0;
  }
  else if ( v3->mKeepType == KEEP_TRUE )
  {
    v18 = v3->mNames.size;
  }
  else
  {
    v18 = 0;
    v19 = v3->mValues.size;
    if ( v19 )
    {
      v20 = &v3->mValues.p->4;
      v21 = v19;
      do
      {
        if ( v20->mBoolValue )
          ++v18;
        v20 += 2;
        --v21;
      }
      while ( v21 );
    }
  }
  if ( v6->mKeepType == KEEP_FALSE )
  {
    v22 = 0;
  }
  else if ( v6->mKeepType == KEEP_TRUE )
  {
    v22 = v6->mNames.size;
  }
  else
  {
    v22 = 0;
    v23 = v6->mValues.size;
    if ( (_DWORD)v23 )
    {
      v24 = &v6->mValues.p->4;
      do
      {
        if ( v24->mBoolValue )
          ++v22;
        v24 += 2;
        --v23;
      }
      while ( v23 );
    }
  }
  if ( v8->mKeepType == KEEP_FALSE )
  {
    v25 = 0;
  }
  else if ( v8->mKeepType == KEEP_TRUE )
  {
    v25 = v8->mNames.size;
  }
  else
  {
    v25 = 0;
    v26 = v8->mValues.size;
    if ( (_DWORD)v26 )
    {
      v27 = &v8->mValues.p->4;
      do
      {
        if ( v27->mBoolValue )
          ++v25;
        v27 += 2;
        --v26;
      }
      while ( v26 );
    }
  }
  if ( v10->mKeepType == KEEP_FALSE )
  {
    v28 = 0;
  }
  else if ( v10->mKeepType == KEEP_TRUE )
  {
    v28 = v10->mNames.size;
  }
  else
  {
    v28 = 0;
    v29 = v10->mValues.size;
    if ( (_DWORD)v29 )
    {
      v30 = &v10->mValues.p->4;
      do
      {
        if ( v30->mBoolValue )
          ++v28;
        v30 += 2;
        --v29;
      }
      while ( v29 );
    }
  }
  if ( v12->mKeepType == KEEP_FALSE )
  {
    v31 = 0;
  }
  else if ( v12->mKeepType == KEEP_TRUE )
  {
    v31 = v12->mNames.size;
  }
  else
  {
    v31 = 0;
    v32 = v12->mValues.size;
    if ( (_DWORD)v32 )
    {
      v33 = &v12->mValues.p->4;
      do
      {
        if ( v33->mBoolValue )
          ++v31;
        v33 += 2;
        --v32;
      }
      while ( v32 );
    }
  }
  if ( v14->mKeepType == KEEP_FALSE )
  {
    v34 = 0;
  }
  else if ( v14->mKeepType == KEEP_TRUE )
  {
    v34 = v14->mNames.size;
  }
  else
  {
    v34 = 0;
    v35 = v14->mValues.size;
    if ( (_DWORD)v35 )
    {
      v36 = &v14->mValues.p->4;
      do
      {
        if ( v36->mBoolValue )
          ++v34;
        v36 += 2;
        --v35;
      }
      while ( v35 );
    }
  }
  if ( v16->mKeepType != KEEP_FALSE )
  {
    if ( v16->mKeepType == KEEP_TRUE )
    {
      v4 = v16->mNames.size;
    }
    else
    {
      v37 = v16->mValues.size;
      if ( (_DWORD)v37 )
      {
        v38 = &v16->mValues.p->4;
        do
        {
          if ( v38->mBoolValue )
            ++v4;
          v38 += 2;
          --v37;
        }
        while ( v37 );
      }
    }
  }
  result = (float)((float)(int)(v18 + v22 + v25 + v28 + v31 + v4 + v34) * 100.0) / (float)v40;
  if ( (*((_BYTE *)v41 + 6216) & 1) == 0 )
    v42[464] = result;
  return result;
}

// File Line: 4016
// RVA: 0x152C130
__int64 UFG::_dynamic_initializer_for__gSymbolRunTest__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("_run_test", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymbolRunTest, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymbolRunTest__);
}

// File Line: 4018
// RVA: 0x49A0B0
void __fastcall UFG::ProgressionTracker::DEBUG_LaunchTestScenarioIfAvailable(UFG::ProgressionTracker *this)
{
  SSClass *v2; // rax
  SSInstance *v3; // rsi
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( this->mDEBUGTestScenarioScriptName.mUID != -1 )
  {
    v2 = SSBrain::get_class("ScriptTests");
    if ( LODWORD(v2[1].vfptr) )
    {
      v3 = **(SSInstance ***)&v2[1].i_name.i_uid;
      if ( v3 )
      {
        args_pp = 0i64;
        SSInstance::coroutine_call(v3, (ASymbol *)&UFG::gSymbolRunTest, &args_pp, 0, 1, 0.0, 0i64, 0i64);
        args_pp = SSSymbol::as_instance((ASymbol *)&this->mDEBUGTestScenarioParameter);
        SSInstance::coroutine_call(
          v3,
          (ASymbol *)&this->mDEBUGTestScenarioScriptName,
          &args_pp,
          args_pp != 0i64,
          1,
          0.0,
          0i64,
          0i64);
      }
    }
    this->mDEBUGTestScenarioScriptName = UFG::gNullQSymbol;
    this->mDEBUGTestScenarioParameter = UFG::gNullQSymbol;
  }
}

