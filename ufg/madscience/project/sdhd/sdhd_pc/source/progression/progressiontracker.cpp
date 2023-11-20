// File Line: 161
// RVA: 0x152C070
__int64 dynamic_initializer_for__gDirectGameSliceId__()
{
  UFG::qString::qString(&gDirectGameSliceId);
  return atexit(dynamic_atexit_destructor_for__gDirectGameSliceId__);
}

// File Line: 173
// RVA: 0x152C030
__int64 UFG::_dynamic_initializer_for__gDefaultFlowId__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Main", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gDefaultFlowId, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gDefaultFlowId__);
}

// File Line: 181
// RVA: 0x4AB740
UFG::ProgressionTracker *__fastcall UFG::ProgressionTracker::Instance()
{
  if ( !(_S19_1 & 1) )
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
void __fastcall UFG::ProgressionTracker::SetActiveFlow(UFG::ProgressionTracker *this, UFG::qSymbol *flowId)
{
  UFG::qSymbol *v2; // rbx

  v2 = flowId;
  this->mActiveFlowId = (UFG::qSymbol)flowId->mUID;
  if ( !(_S13_4 & 1) )
  {
    _S13_4 |= 1u;
    UFG::GameSaveLoad::GameSaveLoad(&sGameSaveLoad);
    atexit(UFG::GameSaveLoad::Instance_::_2_::_dynamic_atexit_destructor_for__sGameSaveLoad__);
  }
  UFG::GameSaveLoad::SetActiveFlow(&sGameSaveLoad, v2);
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
UFG::qPropertySet *__fastcall UFG::ProgressionTracker::GetGameFlowProperties(UFG::ProgressionTracker *this, UFG::qSymbol *flowId)
{
  UFG::qSymbol *v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+18h]

  v2 = flowId;
  v3 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0x3971E8ABu);
  v4 = UFG::PropertySetManager::FindPropertySet(v3);
  if ( v4 )
    v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(v4, v2, DEPTH_RECURSE);
  return v4;
}

// File Line: 235
// RVA: 0x4A07F0
UFG::qBaseTreeRB *__fastcall UFG::ProgressionTracker::FindSceneSettings(UFG::ProgressionTracker *this, UFG::qSymbol *name)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *result; // rax

  v2 = name->mUID;
  if ( v2 )
    result = UFG::qBaseTreeRB::Get(&this->mSceneSettings.mTree, v2);
  else
    result = 0i64;
  return result;
}

// File Line: 241
// RVA: 0x4B3D30
void __fastcall UFG::ReadMasks(SimpleXML::XMLDocument *pDocument, SimpleXML::XMLNode *pGameSliceXMLNode, UFG::XMLWrapperGameSlice *xmlSlice)
{
  UFG::XMLWrapperGameSlice *v3; // r15
  SimpleXML::XMLNode *v4; // r14
  SimpleXML::XMLDocument *v5; // r12
  SimpleXML::XMLNode *v6; // rax
  SimpleXML::XMLNode *i; // rbp
  char *v8; // rdi
  char *v9; // rsi
  UFG::GameSlice *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::GameSliceMasks *v12; // rbx
  int v13; // eax
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
  UFG::qString name; // [rsp+28h] [rbp-80h]
  UFG::qString sliceName; // [rsp+50h] [rbp-58h]

  v3 = xmlSlice;
  v4 = pGameSliceXMLNode;
  v5 = pDocument;
  v6 = SimpleXML::XMLDocument::GetChildNode(pDocument, "enablemasks", pGameSliceXMLNode);
  if ( v6 )
  {
    for ( i = SimpleXML::XMLDocument::GetChildNode(v5, "enable", v6);
          i;
          i = SimpleXML::XMLDocument::GetNode(v5, "enable", i) )
    {
      v8 = SimpleXML::XMLNode::GetAttribute(i, "forcategory");
      v9 = SimpleXML::XMLNode::GetAttribute(i, "for");
      if ( v8 )
      {
        UFG::qString::qString(&name, v8);
        v10 = v3->mpGameSlice;
        if ( !v10->maMasks[0] )
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
          v10->maMasks[0] = (UFG::GameSliceMasks *)v11;
        }
        v12 = v10->maMasks[0];
        v13 = UFG::GameSlice::GetTypeFromCategoryName(&name);
        if ( v13 != 12 )
          v12->mEnabledCategory[v13] = 1;
        UFG::qString::~qString(&name);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  Scenario: Adding EnableCategoryMask: %s\n");
      }
      if ( v9 )
      {
        UFG::qString::qString(&sliceName, v9);
        v14 = v3->mpGameSlice;
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
  v16 = SimpleXML::XMLDocument::GetChildNode(v5, "disablemasks", v4);
  if ( v16 )
  {
    for ( j = SimpleXML::XMLDocument::GetChildNode(v5, "disable", v16);
          j;
          j = SimpleXML::XMLDocument::GetNode(v5, "disable", j) )
    {
      v18 = SimpleXML::XMLNode::GetAttribute(j, "forcategory");
      v19 = SimpleXML::XMLNode::GetAttribute(j, "for");
      if ( v18 )
      {
        UFG::qString::qString(&sliceName, v18);
        v20 = v3->mpGameSlice;
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
        v24 = v3->mpGameSlice;
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
  UFG::SimObjectCharacter *v1; // rax
  UFG::SimObjectCharacter *v2; // rbx
  UFG::TransformNodeComponent *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm7_4
  float v6; // xmm8_4
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax

  v1 = UFG::GetLocalPlayer();
  v2 = v1;
  if ( v1 )
  {
    if ( UFG::SimObjectUtility::IsCharacterInVehicle((UFG::SimObject *)&v1->vfptr) )
    {
      v3 = v2->m_pTransformNodeComponent;
      if ( v3 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v3);
        v4 = v3->mWorldTransform.v3.x;
        v5 = v3->mWorldTransform.v3.y;
        v6 = v3->mWorldTransform.v3.z;
        v7 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v7 + 6216) & 1) )
          v7->mpSnapshots[0]->mFloats[99].mValue = v4;
        v8 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v8 + 6216) & 1) )
          v8->mpSnapshots[0]->mFloats[100].mValue = v5;
        v9 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v9 + 6216) & 1) )
          v9->mpSnapshots[0]->mFloats[101].mValue = v6;
      }
    }
  }
}

// File Line: 310
// RVA: 0x4AF1A0
__int64 __usercall UFG::ProgressionTracker::LoadSupportFile@<rax>(UFG::ProgressionTracker *this@<rcx>, const char *pLocationPath@<rdx>, const char *pFilename@<r8>, const char *pAuthor@<r9>, float a5@<xmm0>)
{
  const char *v5; // rsi
  SimpleXML::XMLNode *v6; // rax
  SimpleXML::XMLDocument *v7; // rbx
  SimpleXML::XMLNode *v8; // rax
  SimpleXML::XMLNode *i; // rdi
  char *v10; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v11; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v12; // rax
  SimpleXML::XMLNode *v13; // rax
  SimpleXML::XMLNode *v14; // rax
  UFG::GameSlice *v15; // rcx
  __int64 v16; // rdi
  __int64 v17; // rax
  UFG::GameSlice *v18; // rsi
  __int64 v19; // rbx
  char *v20; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v21; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v22; // rax
  SimpleXML::XMLNode *v23; // rax
  UFG::GameSlice *v24; // rax
  __int64 v25; // rdi
  __int64 v26; // rcx
  UFG::GameSlice *v27; // rsi
  __int64 v28; // rbx
  char *v29; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v30; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v31; // rax
  SimpleXML::XMLNode *v32; // rax
  UFG::GameSlice *v33; // rax
  __int64 v34; // rdi
  __int64 v35; // rcx
  UFG::GameSlice *v36; // rsi
  __int64 v37; // rbx
  char *v38; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v39; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v40; // rax
  SimpleXML::XMLNode *v41; // rax
  UFG::GameSlice *v42; // rax
  __int64 v43; // rdi
  __int64 v44; // rcx
  UFG::GameSlice *v45; // rsi
  __int64 v46; // rbx
  char *v47; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v48; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v49; // rax
  SimpleXML::XMLNode *v50; // rax
  UFG::GameSlice *v51; // rax
  __int64 v52; // rdi
  __int64 v53; // rcx
  UFG::GameSlice *v54; // rsi
  __int64 v55; // rbx
  char *v56; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v57; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v58; // rax
  SimpleXML::XMLNode *v59; // rax
  UFG::GameSlice *v60; // rax
  __int64 v61; // rdi
  __int64 v62; // rcx
  UFG::GameSlice *v63; // rsi
  __int64 v64; // rbx
  char *v65; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v66; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v67; // rax
  SimpleXML::XMLNode *v68; // rax
  UFG::GameSlice *v69; // rax
  __int64 v70; // rdi
  __int64 v71; // rcx
  UFG::GameSlice *v72; // rsi
  __int64 v73; // rbx
  char *v74; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v75; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v76; // rax
  SimpleXML::XMLNode *v77; // rax
  UFG::GameSlice *v78; // rax
  __int64 v79; // rdi
  __int64 v80; // rcx
  UFG::GameSlice *v81; // rsi
  __int64 v82; // rbx
  char *v83; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v84; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v85; // rax
  SimpleXML::XMLNode *v86; // rax
  UFG::GameSlice *v87; // rax
  __int64 v88; // rdi
  __int64 v89; // rcx
  UFG::GameSlice *v90; // rsi
  __int64 v91; // rbx
  char *v92; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v93; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v94; // rax
  SimpleXML::XMLNode *v95; // rax
  UFG::GameSlice *v96; // rax
  __int64 v97; // rdi
  __int64 v98; // rcx
  UFG::GameSlice *v99; // rsi
  __int64 v100; // rbx
  char *v101; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v102; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v103; // rax
  SimpleXML::XMLNode *v104; // rax
  UFG::GameSlice *v105; // rcx
  __int64 v106; // rdi
  __int64 v107; // rax
  UFG::GameSlice *v108; // rsi
  __int64 v109; // rbx
  char *v110; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v111; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v112; // rax
  SimpleXML::XMLNode *v113; // rsi
  UFG::GameSlice *v114; // rax
  __int64 v115; // rdi
  __int64 v116; // rcx
  UFG::GameSlice *v117; // rbx
  __int64 v118; // rsi
  SimpleXML::XMLNode *v119; // rax
  SimpleXML::XMLNode *v120; // rdi
  char v121; // di
  SimpleXML::XMLNode *v122; // rax
  SimpleXML::XMLNode *v123; // rax
  const char *v124; // rax
  UFG::qSymbol *v125; // rax
  SimpleXML::XMLNode *v126; // rax
  const char *v127; // rax
  UFG::qSymbol *v128; // rax
  char *v129; // r9
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v130; // rcx
  UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *v131; // rax
  SimpleXML::XMLNode *v132; // rax
  SimpleXML::XMLNode *v133; // rdi
  char *v134; // rax
  char *v135; // rdi
  SimpleXML::XMLNode *v136; // rdi
  char *v137; // rax
  UFG::qBaseTreeRB *v138; // rdx
  __int64 v139; // rax
  char *v140; // rcx
  SimpleXML::XMLNode *v141; // rax
  SimpleXML::XMLNode *v142; // rdi
  char *v143; // rsi
  char *v144; // rdi
  const char *v145; // r9
  char *v146; // rsi
  SimpleXML::XMLNode *l; // rdi
  char *v148; // rsi
  char *v149; // rax
  char *v150; // ST28_8
  UFG::qSymbol *v151; // rax
  SimpleXML::XMLNode *m; // rsi
  char *v153; // rdi
  int v154; // edx
  UFG::allocator::free_link *v155; // rdi
  unsigned int v156; // eax
  UFG::qBaseNodeRB *v157; // rdx
  SimpleXML::XMLNode *v158; // rax
  SimpleXML::XMLNode *n; // rdi
  SimpleXML::XMLNode *v160; // rax
  SimpleXML::XMLNode *v161; // rsi
  SimpleXML::XMLNode *v162; // rdi
  UFG::ProgressionTracker *v163; // rsi
  char *v164; // rax
  SimpleXML::XMLNode *v165; // rax
  char *v166; // rax
  UFG::ProgressionTracker *v167; // rdi
  char *log; // [rsp+20h] [rbp-81h]
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
  SimpleXML::XMLNode *prev_node; // [rsp+30h] [rbp-71h]
  char *format; // [rsp+38h] [rbp-69h]
  UFG::XMLWrapperGameSlice xmlSlice; // [rsp+40h] [rbp-61h]
  char *str; // [rsp+58h] [rbp-49h]
  unsigned int v186; // [rsp+60h] [rbp-41h]
  SimpleXML::XMLNode *k; // [rsp+68h] [rbp-39h]
  UFG::qSymbol v188[2]; // [rsp+70h] [rbp-31h]
  char v189; // [rsp+78h] [rbp-29h]
  char v190; // [rsp+79h] [rbp-28h]
  char v191; // [rsp+7Ah] [rbp-27h]
  char v192; // [rsp+7Bh] [rbp-26h]
  char *j; // [rsp+80h] [rbp-21h]
  SimpleXML::XMLNode *v194; // [rsp+88h] [rbp-19h]
  UFG::qString collectionName; // [rsp+90h] [rbp-11h]
  __int64 v196; // [rsp+B8h] [rbp+17h]
  UFG::qString result; // [rsp+C0h] [rbp+1Fh]
  UFG::ProgressionTracker *v198; // [rsp+108h] [rbp+67h]
  char *pLocationPatha; // [rsp+110h] [rbp+6Fh]
  UFG::ProgressionTracker *pAuthora; // [rsp+120h] [rbp+7Fh]

  pAuthora = this;
  v196 = -2i64;
  v5 = pAuthor;
  UFG::qString::FormatEx((UFG::qString *)((char *)&result + 24), "%s\\%s", pLocationPath, pFilename);
  v6 = (SimpleXML::XMLNode *)SimpleXML::XMLDocument::Open(result.mData, 1ui64, 0i64);
  v7 = (SimpleXML::XMLDocument *)v6;
  k = v6;
  if ( v6 )
  {
    v8 = SimpleXML::XMLDocument::GetNode((SimpleXML::XMLDocument *)v6, "gameslices", 0i64);
    if ( v8 )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v7, "gameslice", v8);
            i;
            i = SimpleXML::XMLDocument::GetNode(v7, "gameslice", i) )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, i, v5, a5);
        v10 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v11 = xmlSlice.mPrev;
        v12 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v12->mPrev = v11;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
      }
    }
    v13 = SimpleXML::XMLDocument::GetNode(v7, "groups", 0i64);
    *(_QWORD *)&v188[0].mUID = v13;
    if ( v13 )
    {
      v14 = SimpleXML::XMLDocument::GetChildNode(v7, "disabled", v13);
      for ( prev_node = v14; v14; prev_node = v14 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v14, v5, a5);
        v15 = xmlSlice.mpGameSlice;
        caption = (char *)xmlSlice.mpGameSlice;
        v16 = 0i64;
        v17 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v17 > 0 )
        {
          v18 = xmlSlice.mpGameSlice;
          v19 = (unsigned int)v17;
          do
            UFG::GameSlice::SetType(v18->mChildren.mppArray[v16++], 0);
          while ( v16 < v19 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v15 = (UFG::GameSlice *)caption;
        }
        v15->mType = 0;
        v20 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v21 = xmlSlice.mPrev;
        v22 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v22->mPrev = v21;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v14 = SimpleXML::XMLDocument::GetNode(v7, "disabled", prev_node);
      }
      v23 = SimpleXML::XMLDocument::GetChildNode(v7, "fail", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v23; v23; prev_node = v23 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v23, v5, a5);
        v24 = xmlSlice.mpGameSlice;
        captiona = (char *)xmlSlice.mpGameSlice;
        v25 = 0i64;
        v26 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v26 > 0 )
        {
          v27 = xmlSlice.mpGameSlice;
          v28 = (unsigned int)v26;
          do
            UFG::GameSlice::SetType(v27->mChildren.mppArray[v25++], NUM_TYPES);
          while ( v25 < v28 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v24 = (UFG::GameSlice *)captiona;
        }
        v24->mType = 2;
        v29 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v30 = xmlSlice.mPrev;
        v31 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v31->mPrev = v30;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v23 = SimpleXML::XMLDocument::GetNode(v7, "fail", prev_node);
      }
      v32 = SimpleXML::XMLDocument::GetChildNode(v7, "scenario", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v32; v32; prev_node = v32 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v32, v5, a5);
        v33 = xmlSlice.mpGameSlice;
        captionb = (char *)xmlSlice.mpGameSlice;
        v34 = 0i64;
        v35 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v35 > 0 )
        {
          v36 = xmlSlice.mpGameSlice;
          v37 = (unsigned int)v35;
          do
            UFG::GameSlice::SetType(v36->mChildren.mppArray[v34++], NUM_TYPES|TYPE_OCCLUSION);
          while ( v34 < v37 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v33 = (UFG::GameSlice *)captionb;
        }
        v33->mType = 3;
        UFG::ReadMasks(v7, prev_node, &xmlSlice);
        v38 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v39 = xmlSlice.mPrev;
        v40 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v40->mPrev = v39;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v32 = SimpleXML::XMLDocument::GetNode(v7, "scenario", prev_node);
      }
      v41 = SimpleXML::XMLDocument::GetChildNode(v7, "mission", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v41; v41; prev_node = v41 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v41, v5, a5);
        v42 = xmlSlice.mpGameSlice;
        captionc = (char *)xmlSlice.mpGameSlice;
        v43 = 0i64;
        v44 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v44 > 0 )
        {
          v45 = xmlSlice.mpGameSlice;
          v46 = (unsigned int)v44;
          do
            UFG::GameSlice::SetType(v45->mChildren.mppArray[v43++], NUM_TYPES|TYPE_OCCLUSION|0x8);
          while ( v43 < v46 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v42 = (UFG::GameSlice *)captionc;
        }
        v42->mType = 11;
        v47 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v48 = xmlSlice.mPrev;
        v49 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v49->mPrev = v48;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v41 = SimpleXML::XMLDocument::GetNode(v7, "mission", prev_node);
      }
      v50 = SimpleXML::XMLDocument::GetChildNode(v7, "case", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v50; v50; prev_node = v50 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v50, v5, a5);
        v51 = xmlSlice.mpGameSlice;
        captiond = (char *)xmlSlice.mpGameSlice;
        v52 = 0i64;
        v53 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v53 > 0 )
        {
          v54 = xmlSlice.mpGameSlice;
          v55 = (unsigned int)v53;
          do
            UFG::GameSlice::SetType(v54->mChildren.mppArray[v52++], (UFG::GameSlice::Type)10);
          while ( v52 < v55 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v51 = (UFG::GameSlice *)captiond;
        }
        v51->mType = 10;
        v56 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v57 = xmlSlice.mPrev;
        v58 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v58->mPrev = v57;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v50 = SimpleXML::XMLDocument::GetNode(v7, "case", prev_node);
      }
      v59 = SimpleXML::XMLDocument::GetChildNode(v7, "date", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v59; v59; prev_node = v59 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v59, v5, a5);
        v60 = xmlSlice.mpGameSlice;
        captione = (char *)xmlSlice.mpGameSlice;
        v61 = 0i64;
        v62 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v62 > 0 )
        {
          v63 = xmlSlice.mpGameSlice;
          v64 = (unsigned int)v62;
          do
            UFG::GameSlice::SetType(v63->mChildren.mppArray[v61++], (UFG::GameSlice::Type)9);
          while ( v61 < v64 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v60 = (UFG::GameSlice *)captione;
        }
        v60->mType = 9;
        v65 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v66 = xmlSlice.mPrev;
        v67 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v67->mPrev = v66;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v59 = SimpleXML::XMLDocument::GetNode(v7, "date", prev_node);
      }
      v68 = SimpleXML::XMLDocument::GetChildNode(v7, "event", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v68; v68; prev_node = v68 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v68, v5, a5);
        v69 = xmlSlice.mpGameSlice;
        captionf = (char *)xmlSlice.mpGameSlice;
        v70 = 0i64;
        v71 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v71 > 0 )
        {
          v72 = xmlSlice.mpGameSlice;
          v73 = (unsigned int)v71;
          do
            UFG::GameSlice::SetType(v72->mChildren.mppArray[v70++], (UFG::GameSlice::Type)5);
          while ( v70 < v73 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v69 = (UFG::GameSlice *)captionf;
        }
        v69->mType = 5;
        v74 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v75 = xmlSlice.mPrev;
        v76 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v76->mPrev = v75;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v68 = SimpleXML::XMLDocument::GetNode(v7, "event", prev_node);
      }
      v77 = SimpleXML::XMLDocument::GetChildNode(v7, "favour", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v77; v77; prev_node = v77 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v77, v5, a5);
        v78 = xmlSlice.mpGameSlice;
        captiong = (char *)xmlSlice.mpGameSlice;
        v79 = 0i64;
        v80 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v80 > 0 )
        {
          v81 = xmlSlice.mpGameSlice;
          v82 = (unsigned int)v80;
          do
            UFG::GameSlice::SetType(v81->mChildren.mppArray[v79++], (UFG::GameSlice::Type)6);
          while ( v79 < v82 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v78 = (UFG::GameSlice *)captiong;
        }
        v78->mType = 6;
        v83 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v84 = xmlSlice.mPrev;
        v85 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v85->mPrev = v84;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v77 = SimpleXML::XMLDocument::GetNode(v7, "favour", prev_node);
      }
      v86 = SimpleXML::XMLDocument::GetChildNode(v7, "job", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v86; v86; prev_node = v86 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v86, v5, a5);
        v87 = xmlSlice.mpGameSlice;
        captionh = (char *)xmlSlice.mpGameSlice;
        v88 = 0i64;
        v89 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v89 > 0 )
        {
          v90 = xmlSlice.mpGameSlice;
          v91 = (unsigned int)v89;
          do
            UFG::GameSlice::SetType(v90->mChildren.mppArray[v88++], NUM_TYPES|TYPE_OCCLUSION|0x4);
          while ( v88 < v91 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v87 = (UFG::GameSlice *)captionh;
        }
        v87->mType = 7;
        v92 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v93 = xmlSlice.mPrev;
        v94 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v94->mPrev = v93;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v86 = SimpleXML::XMLDocument::GetNode(v7, "job", prev_node);
      }
      v95 = SimpleXML::XMLDocument::GetChildNode(v7, "race", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v95; v95; prev_node = v95 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v95, v5, a5);
        v96 = xmlSlice.mpGameSlice;
        captioni = (char *)xmlSlice.mpGameSlice;
        v97 = 0i64;
        v98 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v98 > 0 )
        {
          v99 = xmlSlice.mpGameSlice;
          v100 = (unsigned int)v98;
          do
            UFG::GameSlice::SetType(v99->mChildren.mppArray[v97++], (UFG::GameSlice::Type)8);
          while ( v97 < v100 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v96 = (UFG::GameSlice *)captioni;
        }
        v96->mType = 8;
        v101 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v102 = xmlSlice.mPrev;
        v103 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v103->mPrev = v102;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v95 = SimpleXML::XMLDocument::GetNode(v7, "race", prev_node);
      }
      v104 = SimpleXML::XMLDocument::GetChildNode(v7, "ambient", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( prev_node = v104; v104; prev_node = v104 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v104, v5, a5);
        v105 = xmlSlice.mpGameSlice;
        captionj = (char *)xmlSlice.mpGameSlice;
        v106 = 0i64;
        v107 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v107 > 0 )
        {
          v108 = xmlSlice.mpGameSlice;
          v109 = (unsigned int)v107;
          do
            UFG::GameSlice::SetType(v108->mChildren.mppArray[v106++], TYPE_OCCLUSION);
          while ( v106 < v109 );
          v7 = (SimpleXML::XMLDocument *)k;
          v5 = (const char *)pAuthora;
          v105 = (UFG::GameSlice *)captionj;
        }
        v105->mType = 1;
        v110 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v111 = xmlSlice.mPrev;
        v112 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v112->mPrev = v111;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v104 = SimpleXML::XMLDocument::GetNode(v7, "ambient", prev_node);
      }
      v113 = SimpleXML::XMLDocument::GetChildNode(v7, "sprinkle", *(SimpleXML::XMLNode **)&v188[0].mUID);
      for ( j = (char *)v113; v113; j = (char *)v113 )
      {
        UFG::XMLWrapperGameSlice::XMLWrapperGameSlice(&xmlSlice, v7, v113, pAuthora->gActiveGameSlices, a5);
        v114 = xmlSlice.mpGameSlice;
        captionk = (char *)xmlSlice.mpGameSlice;
        v115 = 0i64;
        v116 = xmlSlice.mpGameSlice->mChildren.mCount;
        if ( v116 > 0 )
        {
          v117 = xmlSlice.mpGameSlice;
          v118 = (unsigned int)v116;
          do
            UFG::GameSlice::SetType(v117->mChildren.mppArray[v115++], (UFG::GameSlice::Type)4);
          while ( v115 < v118 );
          v7 = (SimpleXML::XMLDocument *)k;
          v113 = (SimpleXML::XMLNode *)j;
          v114 = (UFG::GameSlice *)captionk;
        }
        v114->mType = 4;
        v119 = SimpleXML::XMLDocument::GetChildNode(v7, "collection", v113);
        v120 = v119;
        if ( v119 )
        {
          format = SimpleXML::XMLNode::GetAttribute(v119, "name");
          v121 = SimpleXML::XMLNode::GetAttribute(v120, "highpriority", 0);
          if ( format )
          {
            UFG::qString::qString(&collectionName, format);
            UFG::GameSlice::SetCollection(xmlSlice.mpGameSlice, &collectionName, v121);
            UFG::qString::~qString(&collectionName);
          }
        }
        UFG::ReadMasks(v7, v113, &xmlSlice);
        v122 = SimpleXML::XMLDocument::GetChildNode(v7, "singlecharacter", v113);
        if ( v122 && SimpleXML::XMLNode::GetBool(v122, 0) )
          xmlSlice.mpGameSlice->mIsSingleCharacterSprinkle = 1;
        v123 = SimpleXML::XMLDocument::GetChildNode(v7, "character1override", v113);
        if ( v123 )
        {
          v124 = SimpleXML::XMLNode::GetValue(v123);
          if ( v124 )
          {
            v125 = UFG::qSymbol::create_from_string(v188, v124);
            xmlSlice.mpGameSlice->mSprinkleCharacter1Override = (UFG::qSymbol)v125->mUID;
          }
        }
        v126 = SimpleXML::XMLDocument::GetChildNode(v7, "character2override", v113);
        if ( v126 )
        {
          v127 = SimpleXML::XMLNode::GetValue(v126);
          if ( v127 )
          {
            v128 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&prev_node, v127);
            xmlSlice.mpGameSlice->mSprinkleCharacter2Override = (UFG::qSymbol)v128->mUID;
          }
        }
        v129 = xmlSlice.mpGameSlice->mName.mText;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]:    Cleaned Game Slice (%s)\n");
        v130 = xmlSlice.mPrev;
        v131 = xmlSlice.mNext;
        xmlSlice.mPrev->mNext = xmlSlice.mNext;
        v131->mPrev = v130;
        xmlSlice.mPrev = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        xmlSlice.mNext = (UFG::qNode<UFG::XMLWrapperGameSlice,UFG::XMLWrapperGameSlice> *)&xmlSlice;
        v113 = SimpleXML::XMLDocument::GetNode(v7, "sprinkle", v113);
      }
    }
    v132 = SimpleXML::XMLDocument::GetNode(v7, "casegroups", 0i64);
    if ( v132 )
    {
      v133 = SimpleXML::XMLDocument::GetChildNode(v7, "casegroup", v132);
      k = v133;
      if ( v133 )
      {
        while ( 1 )
        {
          if ( !(_S19_1 & 1) )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          v134 = SimpleXML::XMLNode::GetAttribute(v133, "properties");
          UFG::qSymbol::create_from_string(v188, v134);
          v135 = (char *)&unk_14240A3F0 + 80 * dword_14240A3E8[0];
          ++dword_14240A3E8[0];
          UFG::qSymbol::set_null((UFG::qSymbol *)v135);
          *((_DWORD *)v135 + 18) = 0;
          format = v135 + 8;
          *((_DWORD *)v135 + 2) = 0;
          *(UFG::qSymbol *)v135 = v188[0];
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Progression,
            OUTPUT_LEVEL_DEBUG,
            "[Progression]:  CaseGroup: %s\n");
          v136 = SimpleXML::XMLDocument::GetChildNode(v7, "case", k);
          if ( v136 )
            break;
LABEL_103:
          v133 = SimpleXML::XMLDocument::GetNode(v7, "casegroup", k);
          k = v133;
          if ( !v133 )
            goto LABEL_104;
        }
        while ( 1 )
        {
          v137 = SimpleXML::XMLNode::GetAttribute(v136, "name");
          UFG::qSymbol::create_from_string((UFG::qSymbol *)&prev_node, v137);
          if ( !(_DWORD)prev_node )
            break;
          v138 = UFG::qBaseTreeRB::Get(&stru_14240A190, (unsigned int)prev_node);
          if ( !v138 )
          {
            if ( !(_DWORD)prev_node )
              break;
            v138 = UFG::qBaseTreeRB::Get(&stru_14240A100, (unsigned int)prev_node);
            if ( !v138 )
            {
              if ( !(_DWORD)prev_node )
                break;
              v138 = UFG::qBaseTreeRB::Get(&stru_14240A148, (unsigned int)prev_node);
            }
          }
LABEL_102:
          v139 = *(unsigned int *)format;
          v140 = &format[8 * v139];
          *(_DWORD *)format = v139 + 1;
          *((_QWORD *)v140 + 1) = v138;
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Progression,
            OUTPUT_LEVEL_DEBUG,
            "[Progression]:    Case: %s\n");
          v136 = SimpleXML::XMLDocument::GetNode(v7, "case", v136);
          if ( !v136 )
            goto LABEL_103;
        }
        v138 = 0i64;
        goto LABEL_102;
      }
    }
LABEL_104:
    v141 = SimpleXML::XMLDocument::GetNode(v7, "objectives", 0i64);
    v194 = v141;
    if ( v141 )
    {
      v142 = SimpleXML::XMLDocument::GetChildNode(v7, "objective", v141);
      for ( k = v142; v142; k = v142 )
      {
        format = SimpleXML::XMLNode::GetAttribute(v142, "name");
        SimpleXML::XMLNode::GetAttribute(v142, "caption");
        v143 = SimpleXML::XMLNode::GetAttribute(v142, "location_caption");
        j = SimpleXML::XMLNode::GetAttribute(v142, "log");
        v144 = SimpleXML::XMLNode::GetAttribute(v142, "gps_marker");
        v189 = SimpleXML::XMLNode::GetAttribute(k, "secondary", 0);
        v191 = SimpleXML::XMLNode::GetAttribute(k, "uses_pda", 0);
        v190 = SimpleXML::XMLNode::GetAttribute(k, "autoflash", 1);
        v192 = SimpleXML::XMLNode::GetAttribute(k, "text_unlockable", 0);
        v188[0].mUID = SimpleXML::XMLNode::GetAttribute(k, "display_priority", 0);
        v145 = v143;
        v146 = v144;
        UFG::ObjectiveTracker::AddObjective(&v198->mObjectiveTracker, format, v144, v145, j, v144, 0i64);
        LOBYTE(v144) = v189;
        prev_node = (SimpleXML::XMLNode *)j;
        log = format;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  %s: %s - %s - %s\n");
        if ( (_BYTE)v144 )
          v146[154] = 1;
        if ( v191 )
          v146[155] = 1;
        if ( v190 )
          v146[152] = 1;
        if ( v192 )
          v146[153] = 1;
        *((UFG::qSymbol *)v146 + 58) = v188[0];
        for ( l = SimpleXML::XMLDocument::GetChildNode(v7, "indicator", k);
              l;
              l = SimpleXML::XMLDocument::GetNode(v7, "indicator", l) )
        {
          format = SimpleXML::XMLNode::GetAttribute(l, "name");
          v148 = SimpleXML::XMLNode::GetAttribute(l, "blip");
          v149 = SimpleXML::XMLNode::GetAttribute(l, "corona");
          j = v149;
          if ( format && (v148 || v149) )
          {
            v150 = v149;
            UFG::qPrintChannel::Print(
              &UFG::gPrintChannel_HK_Progression,
              OUTPUT_LEVEL_DEBUG,
              "[Progression]:    Indicator: (%s)[%s]\n");
            UFG::qString::qString((UFG::qString *)&xmlSlice, j);
            UFG::qString::qString(&collectionName, v148);
            v151 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&prev_node, format);
            UFG::Objective::AddIndicator((UFG::Objective *)v150, v151, &collectionName, (UFG::qString *)&xmlSlice, 0);
            UFG::qString::~qString(&collectionName);
            UFG::qString::~qString((UFG::qString *)&xmlSlice);
          }
        }
        v142 = SimpleXML::XMLDocument::GetNode(v7, "objective", k);
      }
      for ( m = SimpleXML::XMLDocument::GetChildNode(v7, "objectivehint", v194);
            m;
            m = SimpleXML::XMLDocument::GetNode(v7, "objectivehint", m) )
      {
        v153 = SimpleXML::XMLNode::GetAttribute(m, "name");
        format = v153;
        v194 = (SimpleXML::XMLNode *)SimpleXML::XMLNode::GetAttribute(m, "caption");
        UFG::qString::qString(&collectionName, (const char *)v194);
        UFG::qString::qString((UFG::qString *)&xmlSlice, v153);
        v155 = UFG::qMalloc(0x50ui64, "ObjectiveTrackerHint", 0i64);
        j = (char *)v155;
        if ( v155 )
        {
          v156 = v186;
          if ( v186 == -1 )
          {
            v156 = UFG::qStringHash32(str, v186 | v154);
            v186 = v156;
          }
          v155[1].mNext = 0i64;
          v155[2].mNext = 0i64;
          v155[3].mNext = 0i64;
          LODWORD(v155[4].mNext) = v156;
          v155->mNext = (UFG::allocator::free_link *)&UFG::ObjectiveHint::`vftable';
          UFG::qString::qString((UFG::qString *)&v155[5], &collectionName);
        }
        else
        {
          v155 = 0i64;
        }
        if ( v155 )
          v157 = (UFG::qBaseNodeRB *)&v155[1];
        else
          v157 = 0i64;
        UFG::qBaseTreeRB::Add(&v198->mObjectiveTracker.mObjectiveHints.mTree, v157);
        UFG::qString::~qString((UFG::qString *)&xmlSlice);
        UFG::qString::~qString(&collectionName);
        log = (char *)v194;
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]:  ObjectiveHint: %s - %s\n");
      }
    }
    v158 = SimpleXML::XMLDocument::GetNode(v7, "scenesettingsgroup", 0i64);
    if ( v158 )
    {
      for ( n = SimpleXML::XMLDocument::GetChildNode(v7, "scenesettings", v158);
            n;
            n = SimpleXML::XMLDocument::GetNode(v7, "scenesettings", n) )
      {
        UFG::ProgressionTracker::ParseSceneSettings(v198, v7, n);
      }
    }
    v160 = SimpleXML::XMLDocument::GetNode(v7, "supportfiles", 0i64);
    v161 = v160;
    v194 = v160;
    if ( v160 )
    {
      v162 = SimpleXML::XMLDocument::GetChildNode(v7, "supportfile", v160);
      if ( v162 )
      {
        v163 = v198;
        do
        {
          v164 = SimpleXML::XMLNode::GetAttribute(v162, "name");
          UFG::ProgressionTracker::LoadSupportFile(v163, pLocationPatha, v164, 0i64, a5);
          v162 = SimpleXML::XMLDocument::GetNode(v7, "supportfile", v162);
        }
        while ( v162 );
        v161 = v194;
      }
      v165 = SimpleXML::XMLDocument::GetChildNode(v7, "dependencygraph", v161);
      if ( v165 )
      {
        v166 = SimpleXML::XMLNode::GetAttribute(v165, "name");
        if ( v166 )
        {
          UFG::qString::FormatEx((UFG::qString *)&xmlSlice, "%s\\%s", pLocationPatha, v166, log);
          v167 = v198;
          UFG::qString::Set(&v198->mDependencyGraphName, str, SHIDWORD(xmlSlice.mpGameSlice), 0i64, 0);
          UFG::ProgressionTracker::LoadDependencyGraph(v167);
          UFG::qString::~qString((UFG::qString *)&xmlSlice);
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v7);
    operator delete[](v7);
    LOBYTE(v7) = 1;
  }
  UFG::qString::~qString(&result);
  return (unsigned __int8)v7;
}        v162 = SimpleXML::XMLDocument::GetNode(v7, "supportfile", v162);
        }
        while ( v162 );
        v161 = v194;
      }
      v165 = SimpleXML::XMLDocument::GetChildNode(v7, "dependencygraph", v161);
      if ( v165 )
      {
        v166 = SimpleXML::XMLNode::GetAttribute(v165, "name");
        if ( v166 )
        {
          UFG::qString::FormatEx((UFG::qString *)&xmlSlice, "%s\\%s", pLocationPatha, v166, log);
          v167 = v198;
          UFG::qString::Set(&v198->mDependencyGraphName, str, SHIDWORD(xmlSlice.mpGameSl

// File Line: 649
// RVA: 0x4B1FA0
void __usercall UFG::ProgressionTracker::ParseSceneSettings(UFG::ProgressionTracker *this@<rcx>, SimpleXML::XMLDocument *pDocument@<rdx>, SimpleXML::XMLNode *pSceneSettingsXMLNode@<r8>, float a4@<xmm0>)
{
  SimpleXML::XMLNode *v4; // rsi
  SimpleXML::XMLDocument *v5; // rbp
  char *v6; // r15
  UFG::qBaseTreeRB *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::qBaseTreeRB *v9; // rax
  SimpleXML::XMLNode *v10; // rax
  char *v11; // rax
  SimpleXML::XMLNode *v12; // rax
  SimpleXML::XMLNode *v13; // rbx
  const char *v14; // rax
  SimpleXML::XMLNode *v15; // rax
  SimpleXML::XMLNode *v16; // rax
  SimpleXML::XMLNode *v17; // r14
  char *v18; // rbx
  float v19; // xmm8_4
  char v20; // r14
  SimpleXML::XMLNode *v21; // rax
  SimpleXML::XMLNode *v22; // rbx
  char v23; // bl
  SimpleXML::XMLNode *v24; // rax
  SimpleXML::XMLNode *v25; // rax
  SimpleXML::XMLNode *v26; // rax
  SimpleXML::XMLNode *v27; // rax
  SimpleXML::XMLNode *v28; // rax
  SimpleXML::XMLNode *v29; // rax
  UFG::qSymbol result; // [rsp+20h] [rbp-B8h]
  __int64 v31; // [rsp+28h] [rbp-B0h]
  UFG::qString v32; // [rsp+30h] [rbp-A8h]
  UFG::qString weather; // [rsp+58h] [rbp-80h]
  UFG::allocator::free_link *v34; // [rsp+F8h] [rbp+20h]

  v31 = -2i64;
  v4 = pSceneSettingsXMLNode;
  v5 = pDocument;
  v6 = SimpleXML::XMLNode::GetAttribute(pSceneSettingsXMLNode, "name");
  UFG::qSymbol::create_from_string(&result, v6);
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( result.mUID )
    v7 = UFG::qBaseTreeRB::Get(&stru_14240A220, result.mUID);
  else
    v7 = 0i64;
  if ( !v7 )
  {
    UFG::qString::qString(&v32, v6);
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v8 = UFG::qMalloc(0x148ui64, "SceneSettings", 0i64);
    v34 = v8;
    if ( v8 )
    {
      UFG::SceneSettings::SceneSettings((UFG::SceneSettings *)v8, v32.mData);
      v7 = v9;
    }
    else
    {
      v7 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A220, &v7->mRoot);
    UFG::qString::~qString(&v32);
  }
  v10 = SimpleXML::XMLDocument::GetChildNode(v5, "teleportlocationmarker", v4);
  if ( v10 )
  {
    v11 = SimpleXML::XMLNode::GetAttribute(v10, "name", &customWorldMapCaption);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v34, v11);
    LODWORD(v7[1].mNULL.mChild[0]) = (_DWORD)v34;
  }
  v12 = SimpleXML::XMLDocument::GetChildNode(v5, "vehicleteleportlocationmarker", v4);
  v13 = v12;
  if ( v12 )
  {
    v14 = SimpleXML::XMLNode::GetValue(v12);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v34, v14);
    SimpleXML::XMLNode::GetAttribute(v13, "range", -1.0);
    HIDWORD(v7[1].mNULL.mChild[0]) = (_DWORD)v34;
    if ( a4 < 0.0 )
      v7->mCount = 1106247680;
    else
      *(float *)&v7->mCount = a4;
  }
  v15 = SimpleXML::XMLDocument::GetChildNode(v5, "vehicledestroy", v4);
  if ( v15 )
    LOBYTE(v7[1].mNULL.mChild[1]) = SimpleXML::XMLNode::GetValue(v15) != 0i64;
  v16 = SimpleXML::XMLDocument::GetChildNode(v5, "forceweather", v4);
  v17 = v16;
  if ( v16 )
  {
    v18 = SimpleXML::XMLNode::GetAttribute(v16, "type", "notset");
    SimpleXML::XMLNode::GetAttribute(v17, "wetness", -1.0);
    v19 = a4;
    v20 = SimpleXML::XMLNode::GetAttribute(v17, "locked", 0);
    UFG::qString::qString(&weather, v18);
    a4 = UFG::TimeOfDayManager::GetWeatherIntensityFromString(&weather);
    if ( a4 >= 0.0 )
    {
      UFG::qPrintf("ProgressionTracker::ParseSceneSettings:%s=%f\n", v6, v19);
      *(float *)&v7->mNULL.mParent = a4;
      *((float *)&v7->mNULL.mParent + 1) = v19;
      LOBYTE(v7->mNULL.mChild[0]) = v20;
      BYTE1(v7->mNULL.mChild[1]) = 1;
    }
    UFG::qString::~qString(&weather);
  }
  v21 = SimpleXML::XMLDocument::GetChildNode(v5, "forcetime", v4);
  v22 = v21;
  if ( v21 )
  {
    SimpleXML::XMLNode::GetAttribute(v21, "time", -1.0);
    v23 = SimpleXML::XMLNode::GetAttribute(v22, "locked", 0);
    if ( a4 >= 0.0 )
    {
      LODWORD(v34) = 0;
      if ( UFG::TimeOfDayManager::GetTimeInSeconds(a4, (int *)&v34) )
      {
        *((float *)v7->mNULL.mChild + 1) = (float)(signed int)v34;
        BYTE2(v7->mNULL.mChild[1]) = v23;
        LOBYTE(v7->mNULL.mChild[1]) = 1;
      }
    }
  }
  v24 = SimpleXML::XMLDocument::GetChildNode(v5, "enableambientpedsonstart", v4);
  if ( v24 )
    BYTE1(v7->mNULL.mUID) = SimpleXML::XMLNode::GetBool(v24, 1);
  v25 = SimpleXML::XMLDocument::GetChildNode(v5, "enableambientpedsonend", v4);
  if ( v25 )
    BYTE2(v7->mNULL.mUID) = SimpleXML::XMLNode::GetBool(v25, 1);
  v26 = SimpleXML::XMLDocument::GetChildNode(v5, "locktrafficonstart", v4);
  if ( v26 )
    HIBYTE(v7->mNULL.mUID) = SimpleXML::XMLNode::GetBool(v26, 0);
  v27 = SimpleXML::XMLDocument::GetChildNode(v5, "unlocktrafficonend", v4);
  if ( v27 )
    *((_BYTE *)&v7->mNULL.mUID + 4) = SimpleXML::XMLNode::GetBool(v27, 0);
  v28 = SimpleXML::XMLDocument::GetChildNode(v5, "enabletrafficonstart", v4);
  if ( v28 )
    *((_BYTE *)&v7->mNULL.mUID + 5) = SimpleXML::XMLNode::GetBool(v28, 1);
  v29 = SimpleXML::XMLDocument::GetChildNode(v5, "enabletrafficonend", v4);
  if ( v29 )
    *((_BYTE *)&v7->mNULL.mUID + 6) = SimpleXML::XMLNode::GetBool(v29, 1);
}

// File Line: 786
// RVA: 0x4C2400
void __fastcall UFG::ProgressionTracker::SyncCompleted(UFG::ProgressionTracker *this, bool simulateRewards)
{
  bool v2; // r14
  UFG::ProgressionTracker *v3; // r13
  UFG::GameStatTracker *v4; // rbp
  UFG::GameStatTracker *v5; // rcx
  UFG::PersistentData::MapBool *v6; // r12
  UFG::PersistentData::MapFloat *v7; // rdi
  unsigned int i; // esi
  unsigned int v9; // ecx
  bool v10; // cf
  UFG::qSymbol *v11; // rbx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qSymbolUC *v13; // rcx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ebp
  UFG::PersistentData::MapFloat *v17; // r15
  signed __int64 v18; // r14
  UFG::PersistentData::KeyValue *v19; // rbx
  unsigned int v20; // edx
  UFG::qBaseTreeRB *v21; // rdx
  unsigned int v22; // edx
  UFG::qSymbolUC *v23; // rcx
  UFG::PersistentData::MapFloat::Iterator *v24; // rax
  UFG::PersistentData::MapFloat *v25; // rsi
  unsigned int j; // ebx
  unsigned int v27; // ecx
  bool v28; // cf
  UFG::qSymbol *v29; // rdi
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-50h]
  UFG::PersistentData::MapFloat::Iterator v31; // [rsp+38h] [rbp-40h]

  v2 = simulateRewards;
  v3 = this;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  v7 = result.mList;
  for ( i = result.mIndex; ; ++i )
  {
    v9 = v7->mValues.size;
    if ( v7->mValues.size )
    {
      if ( v9 - 1 > 1 )
        break;
      v10 = i < v7[1].mValues.size;
    }
    else
    {
      v10 = i < LODWORD(v7->mValues.p);
    }
    if ( !v10 )
      break;
    if ( v9 )
    {
      if ( v9 - 1 > 1 )
        v11 = &UFG::gNullQSymbol;
      else
        v11 = (UFG::qSymbol *)((char *)v7[1].mValues.p + 4 * i);
    }
    else
    {
      v11 = (UFG::qSymbol *)(*(_QWORD *)&v7->mPersistentDataType + 8i64 * i);
    }
    if ( v11->mUID && (v12 = UFG::qBaseTreeRB::Get(&v3->mGameSlices.mTree, v11->mUID)) != 0i64
      || (v11->mUID ? (v12 = UFG::qBaseTreeRB::Get(&v3->mContainerGameSlices.mTree, v11->mUID)) : (v12 = 0i64), v12) )
    {
      UFG::GameSlice::_SimulateComplete((UFG::GameSlice *)v12, v2);
    }
    else
    {
      if ( v7->mValues.size )
      {
        if ( v7->mValues.size - 1 > 1 )
          v13 = (UFG::qSymbolUC *)&UFG::gNullQSymbol;
        else
          v13 = (UFG::qSymbolUC *)((char *)v7[1].mValues.p + 4 * i);
      }
      else
      {
        v13 = (UFG::qSymbolUC *)(*(_QWORD *)&v7->mPersistentDataType + 8i64 * i);
      }
      UFG::qSymbol::as_cstr_dbg(v13);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_ERROR,
        "[Progression]: Unable to find gameslice to auto-complete (%s)\n");
    }
  }
  if ( !(_S12_6 & 1) )
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
    v16 = v31.mIndex;
    v17 = v31.mList;
    if ( v31.mIndex < v31.mList->mValues.size )
    {
      do
      {
        v18 = v16;
        v19 = v17->mValues.p;
        v20 = v19[v18].mKey.mUID;
        if ( !v20 || (v21 = UFG::qBaseTreeRB::Get(&v3->mGameSlices.mTree, v20)) == 0i64 )
        {
          v22 = v19[v18].mKey.mUID;
          if ( v22 )
            v21 = UFG::qBaseTreeRB::Get(&v3->mContainerGameSlices.mTree, v22);
          else
            v21 = 0i64;
        }
        if ( v21 )
        {
          WORD2(v21[5].mRoot.mParent) = LOWORD(v17->mValues.p[v18].mFloatValue);
        }
        else
        {
          if ( v7->mValues.size )
          {
            if ( v7->mValues.size - 1 > 1 )
              v23 = (UFG::qSymbolUC *)&UFG::gNullQSymbol;
            else
              v23 = (UFG::qSymbolUC *)((char *)v7[1].mValues.p + 4 * i);
          }
          else
          {
            v23 = (UFG::qSymbolUC *)(*(_QWORD *)&v7->mPersistentDataType + 8i64 * i);
          }
          UFG::qSymbol::as_cstr_dbg(v23);
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Progression,
            OUTPUT_LEVEL_ERROR,
            "[Progression]: Unable to find gameslice to auto-complete (%s)\n");
        }
        ++v16;
      }
      while ( v16 < v17->mValues.size );
    }
  }
  v24 = UFG::PersistentData::MapInt::GetIterator((UFG::PersistentData::MapFloat *)v6, &v31);
  *(_QWORD *)&result.mIndex = *(_QWORD *)&v24->mIndex;
  v25 = v24->mList;
  for ( j = result.mIndex; ; ++j )
  {
    v27 = v25->mValues.size;
    if ( v25->mValues.size )
    {
      if ( v27 - 1 > 1 )
        return;
      v28 = j < v25[1].mValues.size;
    }
    else
    {
      v28 = j < LODWORD(v25->mValues.p);
    }
    if ( !v28 )
      break;
    if ( v27 )
    {
      if ( v27 - 1 > 1 )
        v29 = &UFG::gNullQSymbol;
      else
        v29 = (UFG::qSymbol *)((char *)v25[1].mValues.p + 4 * j);
    }
    else
    {
      v29 = (UFG::qSymbol *)(*(_QWORD *)&v25->mPersistentDataType + 8i64 * j);
    }
    if ( (!v29->mUID || !UFG::qBaseTreeRB::Get(&v3->mGameSlices.mTree, v29->mUID)) && v29->mUID )
      UFG::qBaseTreeRB::Get(&v3->mContainerGameSlices.mTree, v29->mUID);
  }
}

// File Line: 849
// RVA: 0x495450
void __fastcall UFG::ProgressionTracker::BindProgressionStage(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::GameStatTracker *v2; // rcx
  UFG::qBaseTreeRB *v3; // rsi
  bool v4; // bl
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rax
  UFG::qSymbol *v7; // rbx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-90h]
  UFG::qString result; // [rsp+50h] [rbp-68h]
  UFG::qString v11; // [rsp+78h] [rbp-40h]
  UFG::qSymbol weaponOverride; // [rsp+C0h] [rbp+8h]
  UFG::qSymbol *v13; // [rsp+C8h] [rbp+10h]

  v1 = this;
  if ( *(_WORD *)&this->mIsLoaded )
  {
    v3 = 0i64;
    v4 = 0;
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( !byte_14240BA99[0] )
      goto LABEL_17;
    if ( !(unsigned int)UFG::qStringCompareInsensitive(byte_14240BA99, "USER_SAVE", -1) )
    {
      v4 = 0;
      v3 = UFG::ProgressionTracker::GetStartupSlice(v1);
LABEL_16:
      UFG::ProgressionTracker::SyncCompleted(v1, v4);
LABEL_17:
      UFG::ProgressionTracker::ForceProgress(v1, (UFG::GameSlice *)v3, v4);
      goto LABEL_18;
    }
    UFG::qString::qString(&v11, &byte_14240BAB9);
    UFG::qString::qString(&v9, byte_14240BA99);
    UFG::qString::MakeLower(&v9);
    UFG::qString::FormatEx(&result, "default-savegames-debugmenu-%s-%s", v11.mData, v9.mData, -2i64);
    v5 = UFG::qSymbol::create_from_string(&weaponOverride, result.mData);
    v6 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::LoadPresetGame(v6, v5);
    v7 = UFG::qSymbol::create_from_string(&weaponOverride, byte_14240BA99);
    if ( !v7->mUID || (v8 = UFG::qBaseTreeRB::Get(&v1->mGameSlices.mTree, v7->mUID)) == 0i64 )
    {
      if ( !v7->mUID )
      {
LABEL_13:
        v4 = 1;
        if ( v3 )
          UFG::GameSlice::_SimulateUnlock((UFG::GameSlice *)v3, 1);
        UFG::qString::~qString(&result);
        UFG::qString::~qString(&v9);
        UFG::qString::~qString(&v11);
        goto LABEL_16;
      }
      v8 = UFG::qBaseTreeRB::Get(&v1->mContainerGameSlices.mTree, v7->mUID);
    }
    v3 = v8;
    goto LABEL_13;
  }
  v13 = &weaponOverride;
  weaponOverride.mUID = UFG::gNullQSymbol.mUID;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::ApplySnapshotEffects(v2, (__int64)&weaponOverride);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_9);
LABEL_18:
  UFG::ProgressionTracker::UpdatePermanentDLC(v1);
}

// File Line: 924
// RVA: 0x495180
void __fastcall UFG::ProgressionTracker::BindChallengeGameSlice(UFG::ProgressionTracker *this, const char *gameslicename)
{
  const char *v2; // rbp
  UFG::ProgressionTracker *v3; // rsi
  UFG::GameSlice *v4; // rdx
  UFG::GameStatTracker *v5; // rdi
  UFG::GameStatTracker *v6; // rbx
  UFG::qSymbol *v7; // r14
  UFG::qBaseTreeRB *v8; // rbx
  UFG::GameStatTracker *v9; // rcx
  UFG::GameStatTracker *v10; // rcx
  unsigned int v11; // ecx
  UFG::GameStatTracker *v12; // rdx
  UFG::PersistentData::MapBool *v13; // rdx
  UFG::PersistentData::MapInt *v14; // rdi
  UFG::PersistentData::KeyValue *v15; // rcx
  char *v16; // rbx
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v2 = gameslicename;
  v3 = this;
  v4 = this->mpActiveMaster;
  if ( v4 && v4->mType != 2 )
    UFG::ProgressionTracker::CancelMission(this, v4, 0, RestoreType_SafehouseFailure);
  v3->mModeType = 2;
  UFG::ProgressionTracker::UpdateGameSlicesSnapshot(v3);
  v5 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  v7 = UFG::qSymbol::create_from_string(&result, v2);
  if ( !v7->mUID || (v8 = UFG::qBaseTreeRB::Get(&v3->mGameSlices.mTree, v7->mUID)) == 0i64 )
  {
    if ( v7->mUID )
      v8 = UFG::qBaseTreeRB::Get(&v3->mContainerGameSlices.mTree, v7->mUID);
    else
      v8 = 0i64;
  }
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v9 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v9 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v9;
  if ( !(*((_BYTE *)v9 + 6216) & 1) )
  {
    UFG::PersistentData::MapInt::ApplyDelta(v9->mpSnapshots[0]->mpMapInts[35], (UFG::qSymbol *)&v8->mRoot.mUID, 1);
    if ( UFG::GameStatAction::PostStat::sIsEnabled )
    {
      if ( !(_S12_6 & 1) )
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
  if ( !v8[5].mRoot.mChild[0] && SHIDWORD(v8[3].mNULL.mChild[1]) > 0 && SLODWORD(v8[5].mNULL.mParent) > 0 )
    v8 = (UFG::qBaseTreeRB *)v8[5].mNULL.mChild[0]->mParent;
  UFG::GameStatAction::Inventory::UnEquip(1);
  UFG::GameStatAction::Inventory::UnequipAllWeapons(1);
  UFG::ProgressionTracker::ForceProgress(v3, (UFG::GameSlice *)v8, 0);
  v11 = _S12_6;
  if ( !(_S12_6 & 1) )
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
  if ( !(v11 & 1) )
  {
    _S12_6 = v11 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v5 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v5;
  v14 = v5->mpSnapshots[0]->mpMapInts[23];
  v15 = v14->mValues.p;
  if ( v15 )
  {
    v16 = (char *)&v15[-1].4;
    `eh vector destructor iterator'(v15, 8ui64, v15[-1].mIntValue, (void (__fastcall *)(void *))_);
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
bool __fastcall UFG::ProgressionTracker::GetStartupLocation(UFG::ProgressionTracker *this, UFG::qMatrix44 *transRotation)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::qPropertySet *v3; // rdi
  UFG::qMatrix44 *v4; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]
  UFG::qSymbol name; // [rsp+58h] [rbp+20h]

  v2 = transRotation;
  UFG::qSymbol::create_from_string(&result, "config-StartupLocations");
  v3 = UFG::PropertySetManager::GetPropertySet(&result);
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  UFG::qSymbol::create_from_string(&name, byte_14240BA58);
  v4 = UFG::qPropertySet::Get<UFG::qMatrix44>(v3, &name, DEPTH_RECURSE);
  if ( v4 )
  {
    v5 = v4->v1;
    v6 = v4->v2;
    v7 = v4->v3;
    v2->v0 = v4->v0;
    v2->v1 = v5;
    v2->v2 = v6;
    v2->v3 = v7;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 999
// RVA: 0x495650
void __fastcall UFG::ProgressionTracker::BindStartupLocation(UFG::ProgressionTracker *this)
{
  UFG::SimObjectCharacter *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::qMatrix44 transRotation; // [rsp+40h] [rbp-48h]

  if ( UFG::ProgressionTracker::GetStartupLocation(this, &transRotation) )
  {
    v1 = UFG::GetLocalPlayer();
    if ( v1 )
    {
      v2 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
      if ( v2 )
        UFG::TeleportEvent::TeleportEvent(
          (UFG::TeleportEvent *)v2,
          &transRotation,
          v1->mNode.mUID,
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
  unsigned __int64 v2; // rax
  __int64 *v3; // rax
  UFG::allocator::free_link *v4; // rbx
  UFG::OnlineManager *v5; // rax
  int v6; // eax
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
  char *v18; // rbx
  int v19; // eax
  char *v20; // rax
  __int64 *v21; // rax
  UFG::NameValueColumnType *i; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v23; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v24; // rax
  __int64 *v25; // rcx
  UFG::NameValueColumnType *v26; // rax
  __int64 v28; // [rsp+20h] [rbp-50h]
  __int64 *v29; // [rsp+30h] [rbp-40h]
  UFG::NameValueColumnType *v30; // [rsp+38h] [rbp-38h]
  UFG::qString result; // [rsp+40h] [rbp-30h]

  v0 = 0;
  LODWORD(v28) = 0;
  v29 = (__int64 *)&v29;
  v30 = (UFG::NameValueColumnType *)&v29;
  v1 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  if ( v1 )
  {
    v2 = UFG::qGetSystemTimeUTC();
    v1->mNext = v1;
    v1[1].mNext = v1;
    LODWORD(v1[2].mNext) = 1;
    v1[4].mNext = (UFG::allocator::free_link *)"SessionId";
    LOBYTE(v1[5].mNext) = 0;
    v1[3].mNext = (UFG::allocator::free_link *)v2;
  }
  else
  {
    v1 = 0i64;
  }
  v3 = v29;
  v29[1] = (__int64)v1;
  v1->mNext = (UFG::allocator::free_link *)v3;
  v1[1].mNext = (UFG::allocator::free_link *)&v29;
  v29 = (__int64 *)v1;
  v4 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  if ( v4 )
  {
    v5 = UFG::OnlineManager::Instance();
    v6 = UFG::OnlineManager::GetOnlineIdStringHash32(v5);
    v4->mNext = v4;
    v4[1].mNext = v4;
    LODWORD(v4[2].mNext) = 6;
    v4[4].mNext = (UFG::allocator::free_link *)"PlayerId";
    LOBYTE(v4[5].mNext) = 0;
    LODWORD(v4[3].mNext) = v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = v29;
  v29[1] = (__int64)v4;
  v4->mNext = (UFG::allocator::free_link *)v7;
  v4[1].mNext = (UFG::allocator::free_link *)&v29;
  v29 = (__int64 *)v4;
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
  v11 = v29;
  v29[1] = (__int64)v9;
  *v9 = (__int64)v11;
  v9[1] = (__int64)&v29;
  v29 = v9;
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
  v16 = v29;
  v29[1] = (__int64)v13;
  *v13 = (__int64)v16;
  v13[1] = (__int64)&v29;
  v29 = v13;
  v17 = UFG::qMalloc(0x30ui64, "NameValueColumnType", 0i64);
  if ( v17 )
  {
    v0 = 1;
    v18 = UFG::qString::FormatEx(&result, "%s%s", "PC", &customWorldMapCaption, v28, -2i64)->mData;
    v17->mNext = v17;
    v17[1].mNext = v17;
    LODWORD(v17[2].mNext) = 9;
    v17[4].mNext = (UFG::allocator::free_link *)"BuildType";
    LOBYTE(v17[5].mNext) = 0;
    v19 = UFG::qStringLength(v18);
    v20 = (char *)UFG::qMalloc(v19 + 1, "StringColumn", 0i64);
    v17[3].mNext = (UFG::allocator::free_link *)v20;
    UFG::qStringCopy(v20, 0x7FFFFFFF, v18, -1);
  }
  else
  {
    v17 = 0i64;
  }
  v21 = v29;
  v29[1] = (__int64)v17;
  v17->mNext = (UFG::allocator::free_link *)v21;
  v17[1].mNext = (UFG::allocator::free_link *)&v29;
  v29 = (__int64 *)v17;
  if ( v0 & 1 )
    UFG::qString::~qString(&result);
  for ( i = v30; v30 != (UFG::NameValueColumnType *)&v29; i = v30 )
  {
    v23 = i->mPrev;
    v24 = i->mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    i->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
    UFG::NameValueColumnType::~NameValueColumnType(i);
    operator delete[](i);
  }
  v25 = v29;
  v26 = v30;
  v29[1] = (__int64)v30;
  v26->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v25;
  return &v29;
}

// File Line: 1051
// RVA: 0x4AE620
void __usercall UFG::ProgressionTracker::LoadGraph(UFG::ProgressionTracker *this@<rcx>, float a2@<xmm0>)
{
  UFG::ProgressionTracker *v2; // rbx
  UFG::GUIProgressionEditor *v3; // rdi
  char *v4; // rax
  signed __int64 v5; // rcx
  UFG::qString *v6; // rax
  UFG::qString result; // [rsp+30h] [rbp-B8h]
  UFG::qString v8; // [rsp+58h] [rbp-90h]
  __int64 v9; // [rsp+80h] [rbp-68h]
  UFG::qString v10; // [rsp+88h] [rbp-60h]
  UFG::qString v11; // [rsp+B0h] [rbp-38h]

  v9 = -2i64;
  v2 = this;
  if ( !this->mDisableProgression && !*(_WORD *)&this->mIsLoaded )
  {
    v3 = UFG::GUIProgressionEditor::mpInstance;
    if ( UFG::GUIProgressionEditor::mpInstance
      && UFG::GUIProgressionEditor::mpInstance->vfptr->IsVisible((UFG::GUIObjectBase *)UFG::GUIProgressionEditor::mpInstance) )
    {
      v3->vfptr->Hide((UFG::GUIObjectBase *)&v3->vfptr);
    }
    v2->mState = 1;
    v2->mpActiveMaster = 0i64;
    v2->mpLastCheckpoint = 0i64;
    v2->mpLastFailed = 0i64;
    *(_WORD *)&v2->mDirty = 0;
    v2->mActiveMasterMode = 0;
    v4 = v2->gActiveContainers;
    v5 = 12i64;
    do
    {
      *(v4 - 12) = 0;
      *v4++ = 0;
      --v5;
    }
    while ( v5 );
    v2->mRestoreType = 4;
    UFG::SendNewGameSessionTelemetry();
    v2->mLastUpdateTimestamp = 0i64;
    v2->mContainerCompletedTimestamp = 0i64;
    if ( !(_S19_1 & 1) )
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
      UFG::qString::Set(&v2->mLocationPath, result.mData, result.mLength, 0i64, 0);
      if ( byte_14240BAB9 == 82 && unk_14240BABA == 80 )
      {
        UFG::qString::FormatEx(&v8, "%s\\Replayable", result.mData);
        if ( byte_14240BA99[0] )
        {
          UFG::qString::FormatEx(&v11, "%s.xml", byte_14240BA99);
          UFG::ProgressionTracker::LoadSupportFile(v2, v8.mData, v11.mData, 0i64, a2);
          UFG::qString::~qString(&v11);
        }
        UFG::qString::~qString(&v8);
      }
      if ( (unsigned __int8)UFG::ProgressionTracker::LoadSupportFile(v2, result.mData, v10.mData, 0i64, a2) )
      {
        UFG::ProgressionTracker::FixupMasterLists(v2, 0);
        v2->mIsLoaded = 1;
      }
      else
      {
        v2->mIsLoadedSimple = 1;
        UFG::ProgressionTracker::BindStartupLocation(v2);
      }
      v2->mState = 2;
      UFG::qString::~qString(&v10);
      UFG::qString::~qString(&result);
    }
  }
}

// File Line: 1178
// RVA: 0x4C3A10
void __fastcall UFG::ProgressionTracker::UnloadGraph(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rbx
  UFG::GUIProgressionEditor *v2; // rdi
  UFG::GameSlice *i; // rdi
  __int64 v4; // rdx
  UFG::GameSlice *j; // rdi
  __int64 v6; // r8
  __int64 v7; // r9
  Render::SkinningCacheNode *v8; // rdi
  Render::SkinningCacheNode *v9; // rdi
  Render::SkinningCacheNode *v10; // rdi
  Render::SkinningCacheNode *v11; // rdi
  void **v12; // rdi
  unsigned __int64 k; // rsi
  signed __int64 v14; // rdi
  signed __int64 v15; // rsi
  UFG::UIHKScreenHud *v16; // rax
  UFG::UIHKScreenWorldMap *v17; // rax
  Render::SkinningCacheNode *v18; // rax
  Illusion::Buffer **v19; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v20; // rdx
  char *v21; // rax
  signed __int64 v22; // rcx

  v1 = this;
  if ( this->mIsLoaded )
  {
    v2 = UFG::GUIProgressionEditor::mpInstance;
    if ( UFG::GUIProgressionEditor::mpInstance
      && UFG::GUIProgressionEditor::mpInstance->vfptr->IsVisible((UFG::GUIObjectBase *)UFG::GUIProgressionEditor::mpInstance) )
    {
      v2->vfptr->Hide((UFG::GUIObjectBase *)&v2->vfptr);
    }
    v1->mpActiveMaster = 0i64;
    v1->mpLastCheckpoint = 0i64;
    v1->mpLastFailed = 0i64;
    for ( i = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
          i;
          i = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &i->mNode) )
    {
      UFG::GameSlice::ForceLock(i, 1);
    }
    for ( j = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
          j;
          j = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &j->mNode) )
    {
      UFG::GameSlice::ForceLock(j, 1);
    }
    UFG::GameSliceStreamer::Clear(&v1->mGameSliceStreamer, v4, v6, v7);
    while ( v1->mGameSlices.mTree.mCount )
    {
      v8 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mGameSlices,
        &v8->mNode);
      if ( v8 )
      {
        UFG::GameSlice::~GameSlice((UFG::GameSlice *)v8);
        operator delete[](v8);
      }
    }
    while ( v1->mContainerGameSlices.mTree.mCount )
    {
      v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mContainerGameSlices,
        &v9->mNode);
      if ( v9 )
      {
        UFG::GameSlice::~GameSlice((UFG::GameSlice *)v9);
        operator delete[](v9);
      }
    }
    UFG::ProgressionTracker::DeleteDisabledGameSlices(v1);
    while ( v1->mCollections.mTree.mCount )
    {
      v10 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mCollections);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mCollections,
        &v10->mNode);
      if ( v10 )
      {
        operator delete[](v10[1].mNode.mChild[0]);
        operator delete[](v10);
      }
    }
    while ( v1->mSceneSettings.mTree.mCount )
    {
      v11 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mSceneSettings);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mSceneSettings,
        &v11->mNode);
      if ( v11 )
      {
        UFG::SceneSettings::~SceneSettings((UFG::SceneSettings *)v11);
        operator delete[](v11);
      }
    }
    v12 = (void **)v1->mLayerOwnership.mppArray;
    for ( k = (unsigned __int64)&v12[v1->mLayerOwnership.mCount]; (unsigned __int64)v12 < k; ++v12 )
    {
      if ( *v12 )
        operator delete[](*v12);
    }
    v1->mLayerOwnership.mCount = 0;
    UFG::qString::Set(&v1->mGlobalAlternateLayer, &customWorldMapCaption);
    UFG::ObjectiveTracker::Clear(&v1->mObjectiveTracker);
    v14 = (signed __int64)&v1->mSecondaryObjectiveTracker;
    v15 = 2i64;
    do
    {
      *(_DWORD *)v14 = 0;
      UFG::qString::Set((UFG::qString *)(v14 + 8), &customWorldMapCaption);
      v14 += 56i64;
      --v15;
    }
    while ( v15 );
    v16 = UFG::UIHKScreenHud::getInstance();
    if ( v16 )
      UFG::UIHKSecondaryObjectivesWidget::Refresh(&v16->SecondaryObjectives);
    v17 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
    if ( v17 )
      UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v17);
    if ( v1->mPDATriggerTracker.mPDATriggers.mTree.mCount )
    {
      while ( 1 )
      {
        v18 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mPDATriggerTracker);
        if ( !v18 )
          break;
        v19 = &v18[-1].mCachedBufferPtr;
        if ( v18 == (Render::SkinningCacheNode *)8 )
          goto LABEL_40;
        v20 = &v18->mNode;
LABEL_41:
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mPDATriggerTracker,
          v20);
        if ( v19 )
          ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v19)->mNode.mParent)(v19, 1i64);
        if ( !v1->mPDATriggerTracker.mPDATriggers.mTree.mCount )
          goto LABEL_44;
      }
      v19 = 0i64;
LABEL_40:
      v20 = 0i64;
      goto LABEL_41;
    }
LABEL_44:
    v1->mCaseTracker.mCases.size = 0;
    v1->mIsLoaded = 0;
    v1->mState = 1;
    v1->mbOpenWorldSnapshotState = 2;
    v1->mbPendingSceneSettingsValid = 0;
    v1->mPendingSceneSettingsLocal.mWeatherOverrideIntensity = -1.0;
    v1->mPendingSceneSettingsLocal.mWeatherOverrideWetness = -1.0;
    v1->mPendingSceneSettingsLocal.mWeatherOverrideLock = 0;
    v1->mPendingSceneSettingsLocal.mTimeOverrideInSeconds = -1.0;
    *(_DWORD *)&v1->mPendingSceneSettingsLocal.mTimeOverrideLockSet = 0;
    *(_DWORD *)&v1->mPendingSceneSettingsLocal.mShowCurtains = 257;
    *(_DWORD *)&v1->mPendingSceneSettingsLocal.mEnableAmbientPedsOnStart = 257;
    *(_WORD *)&v1->mPendingSceneSettingsLocal.mEnableTrafficOnStart = 257;
    v1->mPendingSceneSettingsLocal.mResetEnvironmentOverride = 0;
    UFG::qSymbol::set_null(&v1->mPendingSceneSettingsLocal.mTeleportMarker);
    *(_WORD *)&v1->mPendingSceneSettingsLocal.mVehicleDestroy = 0;
    v1->mPendingSceneSettingsLocal.mTeleportPositionInternal.x = -1.0;
    v1->mPendingSceneSettingsLocal.mTeleportPositionInternal.y = -1.0;
    v1->mPendingSceneSettingsLocal.mTeleportPositionInternal.z = -1.0;
    v1->mPendingSceneSettingsCache.mWeatherOverrideIntensity = -1.0;
    v1->mPendingSceneSettingsCache.mWeatherOverrideWetness = -1.0;
    v1->mPendingSceneSettingsCache.mWeatherOverrideLock = 0;
    v1->mPendingSceneSettingsCache.mTimeOverrideInSeconds = -1.0;
    *(_DWORD *)&v1->mPendingSceneSettingsCache.mTimeOverrideLockSet = 0;
    *(_DWORD *)&v1->mPendingSceneSettingsCache.mShowCurtains = 257;
    *(_DWORD *)&v1->mPendingSceneSettingsCache.mEnableAmbientPedsOnStart = 257;
    *(_WORD *)&v1->mPendingSceneSettingsCache.mEnableTrafficOnStart = 257;
    v1->mPendingSceneSettingsCache.mResetEnvironmentOverride = 0;
    UFG::qSymbol::set_null(&v1->mPendingSceneSettingsCache.mTeleportMarker);
    *(_WORD *)&v1->mPendingSceneSettingsCache.mVehicleDestroy = 0;
    v1->mPendingSceneSettingsCache.mTeleportPositionInternal.x = -1.0;
    v1->mPendingSceneSettingsCache.mTeleportPositionInternal.y = -1.0;
    v1->mPendingSceneSettingsCache.mTeleportPositionInternal.z = -1.0;
    *(_WORD *)&v1->mDirty = 0;
    *(_QWORD *)&v1->mRestoreType = 1i64;
    v1->mModeType = 0;
    v1->mActiveMasterMode = 0;
    *(_QWORD *)&v1->mTimeShiftState = 0i64;
    v1->mTimeShiftSlice = 0i64;
    v1->mTimeShiftTrigger = 0i64;
    UFG::qSymbol::set_null(&v1->mSubSetModeType);
    v1->mResourceFreezeMode = 0;
    UFG::SectionChooser::EnableStreamsUpdate(1);
    v21 = v1->gActiveContainers;
    v22 = 12i64;
    do
    {
      *(v21 - 12) = 0;
      *v21++ = 0;
      --v22;
    }
    while ( v22 );
    v1->mIsLoadedSimple = 0;
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
  unsigned int v4; // er14
  UFG::qBaseTreeRB *v5; // r13
  UFG::qBaseTreeRB *v6; // r12
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbp
  UFG::allocator::free_link *v13; // rdx
  __int64 v14; // r8
  UFG::qBaseTreeRB *v15; // rbp
  UFG::qBaseNodeVariableRB<unsigned __int64> **v16; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v17; // rbx
  UFG::allocator::free_link *v18; // r15
  __int64 v19; // rsi
  unsigned int v20; // er14
  UFG::ProgressionTracker *v21; // rbx
  UFG::qBaseTreeRB *v22; // r13
  UFG::qBaseTreeRB *v23; // r12
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
  UFG::ProgressionTracker *v35; // [rsp+80h] [rbp+8h]

  v35 = this;
  v1 = this;
  v2 = 0i64;
  v3 = 0i64;
  v4 = 0;
  v5 = &this->mGameSlices.mTree;
  v6 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
  if ( v6 )
  {
    do
    {
      v7 = v3;
      v8 = v3 + 1;
      if ( (signed int)v3 + 1 > v4 )
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
      v2[v7].mNext = (UFG::allocator::free_link *)v6;
      v6 = UFG::qBaseTreeRB::GetNext(v5, &v6->mRoot);
    }
    while ( v6 );
    v1 = v35;
  }
  if ( (_DWORD)v3 )
  {
    v15 = &v1->mDisabledGameSlices.mTree;
    v16 = (UFG::qBaseNodeVariableRB<unsigned __int64> **)v2;
    do
    {
      v17 = *v16;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v5, *v16);
      UFG::qBaseTreeRB::Add(v15, (UFG::qBaseNodeRB *)v17);
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
  v21 = v35;
  v22 = &v35->mContainerGameSlices.mTree;
  v23 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v35->mContainerGameSlices);
  if ( v23 )
  {
    do
    {
      v24 = v19;
      v25 = v19 + 1;
      if ( (signed int)v19 + 1 > v20 )
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
      v18[v24].mNext = (UFG::allocator::free_link *)v23;
      v23 = UFG::qBaseTreeRB::GetNext(v22, &v23->mRoot);
    }
    while ( v23 );
    v21 = v35;
  }
  if ( (_DWORD)v19 )
  {
    v32 = &v21->mDisabledGameSlices.mTree;
    v33 = (UFG::qBaseNodeVariableRB<unsigned __int64> **)v18;
    do
    {
      v34 = *v33;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v22, *v33);
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
  UFG::qBaseTreeRB *v1; // rdi
  UFG::qBaseTreeRB *v2; // rbx
  UFG::GameSlice *v3; // rsi
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx
  Render::SkinningCacheNode *v6; // rbx

  v1 = &this->mDisabledGameSlices.mTree;
  v2 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mDisabledGameSlices);
  while ( v2 )
  {
    if ( v2[5].mRoot.mChild[0] || SHIDWORD(v2[3].mNULL.mChild[1]) <= 0 )
    {
      v3 = (UFG::GameSlice *)v2;
      v4 = UFG::qBaseTreeRB::GetNext(v1, &v2->mRoot);
      v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2;
      v2 = v4;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v1, v5);
      if ( v3 )
      {
        UFG::GameSlice::~GameSlice(v3);
        operator delete[](v3);
      }
    }
    else
    {
      v2 = UFG::qBaseTreeRB::GetNext(v1, &v2->mRoot);
    }
  }
  while ( v1->mCount )
  {
    v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)v1);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v1, &v6->mNode);
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
  UFG::ProgressionTracker *v3; // r13
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v4; // r13
  UFG::qBaseTreeRB *v5; // rbx
  char v6; // si
  UFG::GameSlice *v7; // rcx
  __int64 v8; // rdi
  __int64 v9; // rbp
  UFG::allocator::free_link *v10; // r12
  __int64 v11; // rsi
  unsigned int v12; // er14
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
  signed int v31; // er14
  UFG::GameSlice **v32; // rsi
  UFG::GameSlice *v33; // rax
  UFG::ProgressionTracker *depth; // [rsp+80h] [rbp+8h]
  bool v35; // [rsp+88h] [rbp+10h]

  v35 = allowDisabledSlices;
  depth = this;
  v2 = allowDisabledSlices;
  v3 = this;
  UFG::ProgressionTracker::MoveAllSlicesInDisabledList(this);
  v4 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mDisabledGameSlices;
  v5 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v4);
  if ( v5 )
  {
    do
    {
      if ( !v5[5].mRoot.mChild[0] && SHIDWORD(v5[3].mNULL.mChild[1]) > 0 )
      {
        if ( BYTE1(v5[4].mNULL.mParent) )
        {
          v6 = 1;
        }
        else
        {
          v7 = (UFG::GameSlice *)(SLODWORD(v5[5].mNULL.mParent) <= 0 ? v5 : v5[5].mNULL.mChild[0]->mParent);
          v6 = (unsigned __int8)UFG::GameSlice::CanDependantsBeEnabled(v7) != 0;
        }
        LOBYTE(v5[4].mNULL.mParent) = v6;
        v8 = 0i64;
        v9 = LODWORD(v5[5].mNULL.mParent);
        if ( v9 > 0 )
        {
          do
            UFG::GameSlice::SetEnabled(*((UFG::GameSlice **)&v5[5].mNULL.mChild[0]->mParent + v8++), v6);
          while ( v8 < v9 );
        }
      }
      v5 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)v4, &v5->mRoot);
    }
    while ( v5 );
    v2 = v35;
  }
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v4);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)v4, &i->mRoot) )
  {
    if ( LOBYTE(i[4].mNULL.mParent) || v2 )
    {
      v14 = v11;
      v15 = v11 + 1;
      if ( (signed int)v11 + 1 > v12 )
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
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v4->mTree, *v23);
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
      if ( v28 <= 0 )
      {
LABEL_49:
        v31 = 0x7FFFFFFF;
        v30 = 0i64;
        if ( v28 > 0 )
        {
          v32 = *(UFG::GameSlice ***)&j[5].mRoot.mUID;
          do
          {
            LODWORD(depth) = 0x7FFFFFFF;
            v33 = UFG::GameSlice::GetDependentRecursive(*v32, NUM_TYPES|TYPE_OCCLUSION|0x8, (int *)&depth);
            if ( (signed int)depth < v31 )
            {
              v31 = (signed int)depth;
              v30 = v33;
            }
            ++v32;
            --v28;
          }
          while ( v28 );
        }
      }
      else
      {
        v29 = *(UFG::GameSlice ***)&j[5].mRoot.mUID;
        while ( 1 )
        {
          v30 = *v29;
          if ( (*v29)->mType == 11 )
            break;
          ++v27;
          ++v29;
          if ( v27 >= v28 )
            goto LABEL_49;
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
  UFG::ProgressionTracker *v1; // r14
  char v2; // di
  UFG::qBaseTreeRB *i; // rbx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qBaseNodeRB *v9; // r9
  int v10; // ST20_4
  UFG::qBaseTreeRB *j; // rbx
  UFG::qSymbol name; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = 0;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &i->mRoot) )
  {
    v4 = (int)i[5].mRoot.mParent;
    if ( v4 )
    {
      v5 = v4 - 1;
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
              v8 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
              if ( v8 )
                UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v8, 0, PERSISTENT, 0);
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
        v9 = i->mNULL.mParent;
        v10 = SHIWORD(i[5].mRoot.mParent);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[GameSlice]: (%s) Cleanup count is (%d)\n");
      }
      v2 = 1;
    }
  }
  for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
        j;
        j = UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &j->mRoot) )
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
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // r8
  UFG::GameSlice *v3; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::GameSnapshot *v6; // rdi
  UFG::qPropertySet *v7; // rax
  UFG::qBaseTreeRB *v8; // rbp
  float v9; // xmm8_4
  float v10; // xmm6_4
  UFG::GameStatTracker *v11; // rax
  float *v12; // rbx
  float v13; // xmm7_4
  UFG::SimObject *v14; // rax
  UFG::qMatrix44 *v15; // rbx
  UFG::SimObject *v16; // rdi
  unsigned __int16 v17; // dx
  UFG::TSActorComponent *v18; // rbx
  SSActorClass *v19; // rdi
  SSClass *v20; // rcx
  SSClass *v21; // rcx
  UFG::TSVehicle *v22; // rax
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]

  if ( slice )
  {
    v2 = &slice->mpRestoredVehicle;
    v3 = slice;
    if ( slice->mpRestoredVehicle.m_pPointer )
    {
      v4 = v2->mPrev;
      v5 = slice->mpRestoredVehicle.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      slice->mpRestoredVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&slice->mpRestoredVehicle.mPrev;
    }
    slice->mpRestoredVehicle.m_pPointer = 0i64;
    if ( slice->mVehicleMarker.mUID != -1 )
    {
      v6 = UFG::GameStatTracker::Instance()->mpSnapshots[0];
      if ( v6->mIDs[30].mValue.mUID != -1 )
      {
        v7 = UFG::PropertySetManager::GetPropertySet(&v6->mIDs[30].mValue);
        if ( !UFG::SimObjectUtility::IsClassType(v7, (UFG::qSymbol *)&qSymbol_Boat_14.mUID) )
        {
          v8 = UFG::MarkerBase::GetNamed(&v3->mVehicleMarker);
          if ( v8 )
          {
            v9 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[99].mValue;
            v10 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[100].mValue;
            v11 = UFG::GameStatTracker::Instance();
            v12 = (float *)v8[1].mNULL.mParent;
            v13 = v11->mpSnapshots[0]->mFloats[101].mValue;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8[1].mNULL.mParent);
            if ( (float)((float)((float)((float)(v9 - v12[44]) * (float)(v9 - v12[44]))
                               + (float)((float)(v10 - v12[45]) * (float)(v10 - v12[45])))
                       + (float)((float)(v13 - v12[46]) * (float)(v13 - v12[46]))) <= (float)(v3->mVehicleMarkerRange
                                                                                            * v3->mVehicleMarkerRange) )
            {
              UFG::qSymbol::create_from_string(&result, "Checkpoint Restore Car");
              v14 = UFG::SpawnInfoInterface::SpawnObject(&result, &v6->mIDs[30].mValue, 0, 0i64, 0i64, 0i64);
              v15 = (UFG::qMatrix44 *)v8[1].mNULL.mParent;
              v16 = v14;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8[1].mNULL.mParent);
              UFG::SimObjectUtility::Teleport(v16, v15 + 2);
              UFG::GameSlice::SetRestoreVehicle(v3, v16);
              if ( v16 )
              {
                v17 = v16->m_Flags;
                if ( (v17 >> 14) & 1 )
                {
                  v18 = (UFG::TSActorComponent *)v16->m_Components.p[4].m_pComponent;
                }
                else if ( (v17 & 0x8000u) == 0 )
                {
                  if ( (v17 >> 13) & 1 )
                  {
                    v18 = (UFG::TSActorComponent *)v16->m_Components.p[3].m_pComponent;
                  }
                  else if ( (v17 >> 12) & 1 )
                  {
                    v18 = (UFG::TSActorComponent *)v16->m_Components.p[2].m_pComponent;
                  }
                  else
                  {
                    v18 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                     v16,
                                                     UFG::TSActorComponent::_TypeUID);
                  }
                }
                else
                {
                  v18 = (UFG::TSActorComponent *)v16->m_Components.p[4].m_pComponent;
                }
                if ( v18 )
                {
                  v19 = UFG::TSVehicle::mClass;
                  v20 = UFG::TSActorComponent::GetActor(v18)->i_class_p;
                  if ( v19 == (SSActorClass *)v20
                    || (v21 = v20->i_superclass_p) != 0i64 && SSClass::is_class(v21, (SSClass *)&v19->vfptr) )
                  {
                    v22 = (UFG::TSVehicle *)UFG::TSActorComponent::GetActor(v18);
                    UFG::TSVehicle::UnlockDoors(v22, 1);
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
  UFG::ProgressionTracker *v2; // rdi
  UFG::SceneSettings *v3; // rsi
  UFG::qBaseTreeRB *v4; // rax
  UFG::SimObject *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbp
  float v7; // xmm7_4
  float v8; // xmm8_4
  UFG::GameStatTracker *v9; // rax
  float *v10; // rbx
  float v11; // xmm6_4
  UFG::qMatrix44 *v12; // rbx

  if ( settings )
  {
    v2 = this;
    v3 = settings;
    if ( settings->mVehicleTeleportMarker.mUID != -1 )
    {
      if ( this->mLastUsedVehicle.m_pPointer )
      {
        v4 = UFG::MarkerBase::GetNamed(&settings->mVehicleTeleportMarker);
        v5 = v2->mLastUsedVehicle.m_pPointer;
        v6 = v4;
        if ( v5 )
        {
          if ( v4 && !UFG::SimObjectUtility::IsClassType(v5, (UFG::qSymbol *)&qSymbol_Boat_14.mUID) )
          {
            v7 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[99].mValue;
            v8 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mFloats[100].mValue;
            v9 = UFG::GameStatTracker::Instance();
            v10 = (float *)v6[1].mNULL.mParent;
            v11 = v9->mpSnapshots[0]->mFloats[101].mValue;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6[1].mNULL.mParent);
            if ( (float)((float)((float)((float)(v8 - v10[45]) * (float)(v8 - v10[45]))
                               + (float)((float)(v7 - v10[44]) * (float)(v7 - v10[44])))
                       + (float)((float)(v11 - v10[46]) * (float)(v11 - v10[46]))) <= (float)(v3->mVehicleTeleportRange
                                                                                            * v3->mVehicleTeleportRange) )
            {
              v12 = (UFG::qMatrix44 *)v6[1].mNULL.mParent;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6[1].mNULL.mParent);
              UFG::SimObjectUtility::Teleport(v5, v12 + 2);
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
  UFG::SimObject *v1; // rdx

  v1 = this->mLastUsedVehicle.m_pPointer;
  if ( v1 )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v1);
}

// File Line: 1565
// RVA: 0x4B7AE0
void __fastcall UFG::ProgressionTracker::RestorePlayerLocation(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::ProgressionTracker::RestoreType v2; // edx
  UFG::GameSlice *v3; // rax
  bool v4; // cl
  UFG::GameSlice *v5; // rbx
  UFG::qSymbol *v6; // rsi
  UFG::qSymbol *v7; // rsi
  UFG::qBaseTreeRB *v8; // rbx
  UFG::SimObjectCharacter *v9; // rsi
  UFG::TransformNodeComponent *v10; // rbx
  UFG::SimObjectCharacter *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  bool v13; // zf
  UFG::GameSnapshot *v14; // rcx
  float v15; // xmm2_4
  float v16; // xmm1_4
  UFG::ProgressionTracker *v17; // rax
  UFG::ProgressionTracker::RestoreType v18; // ecx
  SSActor *v19; // rsi
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  ASymbol *v23; // rax
  SSInstance *v24; // rax
  const char *v25; // rdx
  char *v26; // rcx
  ASymbol *v27; // rax
  SSInstance *v28; // rax
  UFG::qMatrix44 *v29; // rsi
  unsigned __int16 v30; // cx
  UFG::TSActorComponent *v31; // rax
  UFG::TSActor *v32; // rax
  UFG::qSymbol v33; // [rsp+30h] [rbp-39h]
  __int64 v34; // [rsp+38h] [rbp-31h]
  UFG::qVector3 vec; // [rsp+40h] [rbp-29h]
  SSInstance *v36; // [rsp+50h] [rbp-19h]
  SSInstance *v37; // [rsp+58h] [rbp-11h]
  UFG::qMatrix44 transRotation; // [rsp+60h] [rbp-9h]
  UFG::qSymbol result; // [rsp+D0h] [rbp+67h]
  char v40; // [rsp+D8h] [rbp+6Fh]
  char v41; // [rsp+E0h] [rbp+77h]
  char v42; // [rsp+E8h] [rbp+7Fh]

  v1 = this;
  this->mRestoringType = 0;
  this->mMonetaryPenalty = 0;
  if ( !this->mIsLoadedSimple && !this->mResourceFreezeMode )
  {
    v2 = this->mRestoreType;
    v4 = 0;
    if ( v2 == 4 )
    {
      v3 = this->mpLastCheckpoint;
      if ( v3 )
      {
        if ( !v3->mpParent && v3->mType > 0 && !v3->mIgnoreSafehouseRestore )
          v4 = 1;
      }
    }
    v5 = v1->mpLastCheckpoint;
    if ( v5 && v5->mType != 2 && (v2 - 3) & 0xFFFFFFFB && !v4 )
    {
      v6 = (UFG::qSymbol *)v5->mSceneSettings;
      if ( v6 && (v7 = v6 + 28, v7->mUID != -1)
        || (v7 = &v5->mRestoreLocationMarker, v5->mRestoreLocationMarker.mUID != -1) )
      {
        do
        {
          UFG::GameSlice::_EnableLayer(v5);
          v5 = v5->mpParent;
        }
        while ( v5 );
        v8 = UFG::MarkerBase::GetNamed(v7);
        v9 = UFG::GetLocalPlayer();
        if ( v9 )
        {
          if ( v8 )
          {
            v10 = (UFG::TransformNodeComponent *)v8[1].mNULL.mParent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v10);
            UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v9->vfptr, &v10->mWorldTransform);
          }
        }
      }
LABEL_48:
      v1->mRestoreType = 1;
      return;
    }
    v11 = UFG::GetLocalPlayer();
    v12 = UFG::GameStatTracker::Instance();
    v13 = v1->mRestoreType == 4;
    v14 = v12->mpSnapshots[0];
    v15 = v14->mFloats[81].mValue;
    v16 = v14->mFloats[80].mValue;
    vec.x = v14->mFloats[79].mValue;
    vec.y = v16;
    vec.z = v15;
    if ( v13 )
    {
      v17 = UFG::ProgressionTracker::Instance();
      if ( (unsigned int)UFG::qStringCompare(v17->mGameSetup.mLocationDir, "Game", -1) )
      {
        if ( UFG::ProgressionTracker::GetStartupLocation(v1, &transRotation) )
          vec = *(UFG::qVector3 *)&transRotation.v3.x;
      }
    }
    v18 = v1->mRestoreType;
    v19 = SkookumScript::c_world_p;
    v1->mRestoringType = v18;
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
            v1->mRestoringType = 1;
            goto LABEL_35;
          }
          v25 = "ScriptLocation";
          v26 = &v40;
        }
        else
        {
          v1->mMonetaryPenalty = 1;
          v25 = "PoliceStation";
          v26 = &v41;
        }
      }
      else
      {
        v1->mMonetaryPenalty = 2;
        v25 = "Clinic";
        v26 = &v42;
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
    v36 = v24;
    v28 = UFG::TSVector3::AsInstance(&vec);
    v34 = 0i64;
    v37 = v28;
    ((void (__fastcall *)(SSActor *, UFG::qStaticSymbol *, SSInstance **, signed __int64, __int64 *, _QWORD))v19->vfptr[1].set_data_by_name)(
      v19,
      &qSymbol_get_closest_restore_location,
      &v36,
      2i64,
      &v34,
      0i64);
    v29 = *(UFG::qMatrix44 **)(v34 + 32);
    if ( v29 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v34 + 32));
      UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v11->vfptr, v29 + 2);
      if ( v11 )
      {
        v30 = v11->m_Flags;
        if ( (v30 >> 14) & 1 )
        {
          v31 = (UFG::TSActorComponent *)v11->m_Components.p[4].m_pComponent;
        }
        else if ( (v30 & 0x8000u) == 0 )
        {
          if ( (v30 >> 13) & 1 )
            v31 = (UFG::TSActorComponent *)v11->m_Components.p[3].m_pComponent;
          else
            v31 = (UFG::TSActorComponent *)((v30 >> 12) & 1 ? v11->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::TSActorComponent::_TypeUID));
        }
        else
        {
          v31 = (UFG::TSActorComponent *)v11->m_Components.p[4].m_pComponent;
        }
        if ( v31 )
        {
          v32 = UFG::TSActorComponent::GetActor(v31);
          ((void (__fastcall *)(UFG::TSActor *))v32->vfptr[2].get_data_by_name)(v32);
        }
      }
    }
    goto LABEL_48;
  }
  this->mRestoreType = 1;
}

// File Line: 1711
// RVA: 0x493D10
void __fastcall UFG::ProgressionTracker::AdjustPlayerLocationToGround(UFG::ProgressionTracker *this)
{
  UFG::SimObjectCharacter *v1; // rax
  UFG::SimObject *v2; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  __m128 v8; // xmm3
  float v9; // xmm5_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  __m128 v12; // xmm8
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  __m128 v16; // xmm2
  float v17; // xmm0_4
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  float v20; // xmm10_4
  float v21; // xmm10_4
  __m128 v22; // xmm11
  float v23; // xmm10_4
  __m128 v24; // xmm8
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  __m128 v28; // xmm9
  float v29; // xmm2_4
  float v30; // xmm8_4
  __m128 v31; // xmm3
  float v32; // xmm6_4
  UFG::qVector3 out; // [rsp+30h] [rbp-69h]
  UFG::qVector3 position; // [rsp+40h] [rbp-59h]
  UFG::qMatrix44 xform; // [rsp+50h] [rbp-49h]

  v1 = UFG::GetLocalPlayer();
  v2 = (UFG::SimObject *)&v1->vfptr;
  if ( v1 )
  {
    v3 = v1->m_pTransformNodeComponent;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v1->m_pTransformNodeComponent);
      v4 = v3->mWorldTransform.v3.x;
      v5 = v3->mWorldTransform.v3.z;
      v6 = v3->mWorldTransform.v3.y;
      *(_QWORD *)&out.x = 0i64;
      out.z = 0.0;
      position.x = v4;
      position.z = v5;
      position.y = v6;
      if ( UFG::PlaceOnGround(&out, &position, 0.0, 1.0, 0.5) )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v3);
        v7 = v3->mWorldTransform.v0.y;
        v8 = (__m128)LODWORD(v3->mWorldTransform.v0.x);
        v9 = v3->mWorldTransform.v0.z;
        v10 = v8;
        v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
        if ( v10.m128_f32[0] == 0.0 )
          v11 = 0.0;
        else
          v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
        v12 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v13 = v8.m128_f32[0] * v11;
        v14 = v7 * v11;
        v15 = v9 * v11;
        xform.v0.w = 0.0;
        v16 = v12;
        xform.v0.x = v13;
        xform.v0.y = v14;
        xform.v0.z = v15;
        v16.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v16.m128_f32[0] == 0.0 )
        {
          v18 = 0i64;
        }
        else
        {
          LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v16);
          v18 = (__m128)(unsigned int)FLOAT_1_0;
          v18.m128_f32[0] = 1.0 / v17;
        }
        v19 = v18;
        v20 = v18.m128_f32[0];
        v18.m128_f32[0] = v18.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v21 = v20 * UFG::qVector3::msDirUp.x;
        v19.m128_f32[0] = v19.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v22 = v19;
        v22.m128_f32[0] = (float)(v19.m128_f32[0] * v15) - (float)(v18.m128_f32[0] * v14);
        v18.m128_f32[0] = (float)(v18.m128_f32[0] * v13) - (float)(v21 * v15);
        v23 = (float)(v21 * v14) - (float)(v19.m128_f32[0] * v13);
        v24 = v18;
        v24.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v22.m128_f32[0] * v22.m128_f32[0]))
                        + (float)(v23 * v23);
        if ( v24.m128_f32[0] == 0.0 )
          v25 = 0.0;
        else
          v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
        v22.m128_f32[0] = v22.m128_f32[0] * v25;
        v26 = v18.m128_f32[0] * v25;
        xform.v1.w = 0.0;
        v27 = v26;
        v28 = v22;
        xform.v1.z = v23 * v25;
        LODWORD(xform.v1.x) = v22.m128_i32[0];
        xform.v1.y = v26;
        v28.m128_f32[0] = (float)(v22.m128_f32[0] * v15) - (float)((float)(v23 * v25) * v13);
        v29 = (float)(v26 * v13) - (float)(v22.m128_f32[0] * v14);
        v31 = v28;
        v30 = (float)((float)(v23 * v25) * v14) - (float)(v27 * v15);
        v31.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v30 * v30)) + (float)(v29 * v29);
        if ( v31.m128_f32[0] == 0.0 )
          v32 = 0.0;
        else
          v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
        xform.v2.w = 0.0;
        xform.v3.w = 1.0;
        *(UFG::qVector3 *)&xform.v3.x = out;
        xform.v2.x = v30 * v32;
        xform.v2.y = v28.m128_f32[0] * v32;
        xform.v2.z = v29 * v32;
        UFG::SimObjectUtility::Teleport(v2, &xform);
      }
    }
  }
}

// File Line: 1741
// RVA: 0x4ACFF0
signed __int64 __fastcall UFG::ProgressionTracker::IsUICancellationAllowed(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *v1; // rax
  signed __int64 result; // rax

  v1 = this->mpActiveMaster;
  if ( v1 )
    result = v1->mAllowUICancellation;
  else
    result = 1i64;
  return result;
}

// File Line: 1749
// RVA: 0x4944D0
void __fastcall UFG::ProgressionTracker::ApplyGameplayEffects(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rbx
  UFG::GameSlice *v2; // rax
  UFG::qSymbol *v3; // rax
  unsigned int v4; // eax
  UFG::GameStatTracker *v5; // rbx
  UFG::qSymbol weaponOverride; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+48h] [rbp+10h]

  v1 = this;
  if ( (unsigned int)(this->mRestoringType - 5) <= 1 )
  {
    UFG::GameStatAction::Inventory::UnEquip(1);
    UFG::GameStatAction::Inventory::UnequipAllWeapons(1);
  }
  v2 = v1->mpLastCheckpoint;
  if ( v2 )
    v3 = &v2->mRestoreWeapon;
  else
    v3 = &UFG::gNullQSymbol;
  v4 = v3->mUID;
  v7 = &weaponOverride;
  weaponOverride.mUID = v4;
  v5 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  UFG::ProgressionTracker *v2; // rdi
  UFG::InputActionData *v3; // rcx
  UFG::GameSaveLoad *v4; // rax
  UFG::GameSlice *v5; // rbx
  bool v6; // si
  bool v7; // al
  UFG::GameSlice *v8; // rbx
  UFG::GameSlice *v9; // rcx
  UFG::TimeOfDayManager *v10; // rbx
  UFG::GameSlice *v11; // rcx
  UFG::StoreFrontTracker *v12; // rax
  bool v13; // al
  UFG::GameSlice *v14; // rcx
  UFG::GameSlice *v15; // rcx
  float v16; // xmm6_4
  UFG::TimeOfDayManager *v17; // rax
  UFG::GameSlice *v18; // rbx
  UFG::GameSlice::State v19; // esi
  UFG::GameSlice *v20; // rcx
  UFG::GameSlice *v21; // rcx
  bool v22; // al

  v2 = this;
  switch ( this->mState )
  {
    case 3:
      if ( this->mTimeShiftSlice
        && (v3 = UFG::ActionDef_Action.mDataPerController[UFG::gActiveControllerNum]) != 0i64
        && v3->mActionTrue )
      {
        v2->mState = 4;
        *(_QWORD *)&v2->mTimeShiftState = 5i64;
      }
      else
      {
        UFG::ProgressionTracker::UpdateDependency(v2);
        UFG::ProgressionTracker::UpdateSnapshot(v2);
        if ( v2->mpAutoSaveQueuedSlice )
        {
          v2->mpAutoSaveQueuedSlice = 0i64;
          v4 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SaveAutoGameSlot(v4);
        }
        UFG::ProgressionTracker::ApplyMonetaryPenalty(v2);
      }
      goto LABEL_89;
    case 4:
      if ( !UFG::ProgressionTracker::UpdateTimeShift(this, realTimeDelta) )
        goto LABEL_88;
      goto LABEL_89;
    case 5:
      if ( UFG::ProgressionTracker::IsCleanupCompleted(this) )
        v2->mState = 13;
      goto LABEL_89;
    case 6:
      this->mIsWorldDataRestored = 0;
      if ( UFG::ProgressionTracker::IsCleanupCompleted(this) )
        v2->mState = 7;
      goto LABEL_89;
    case 7:
      UFG::ProgressionTracker::LoadSnapshotWeather(this);
      v5 = v2->mpLastCheckpoint;
      if ( v5 && v5->mType != 2 )
      {
        v6 = !v5->mpParent && v5->mType > 0 && !v5->mChildren.mCount;
        v7 = !v5->mpParent
          && v5->mType > 0
          && !(unsigned __int8)UFG::GameSlice::HasProgressionTrigger(v2->mpLastCheckpoint);
        if ( v5->mpParent || v5->mType <= 0 || v6 || v7 )
        {
          v8 = v5->mpParent;
          if ( v8 )
          {
            UFG::GameSlice::SetupTimeAndWeather(v8, 1);
            UFG::GameSlice::SetupPedsAndVehicles(v8);
            UFG::GameSlice::SetupSceneLayers(v8);
          }
          v9 = v2->mpLastCheckpoint;
          if ( v9->mSceneSettings )
          {
            UFG::GameSlice::SetupTimeAndWeather(v9, 1);
            UFG::GameSlice::SetupPedsAndVehicles(v2->mpLastCheckpoint);
            UFG::GameSlice::SetupSceneLayers(v2->mpLastCheckpoint);
            goto LABEL_38;
          }
        }
      }
      else if ( (unsigned int)(v2->mRestoreType - 5) <= 1 )
      {
        v10 = UFG::TimeOfDayManager::GetInstance();
        UFG::TimeOfDayManager::SetTime(v10, v10->m_SecondsSinceMidnight + 21600.0, 0);
        TimePlotPoint::SetTimeValue(v10, 40.0);
      }
      UFG::PedSpawning_AmbientPedEnableHelper(1);
      UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 1);
LABEL_38:
      UFG::ProgressionTracker::RestorePlayerLocation(v2);
      UFG::ProgressionTracker::RestoreVehicle(v2, v2->mpLastCheckpoint);
      UFG::qSymbol::set_null(&v2->mSubSetModeType);
      v11 = v2->mpLastCheckpoint;
      if ( v11 )
      {
        if ( v11->mpParent )
          v11 = v11->mpParent;
        v2->mpActiveMaster = v11;
        UFG::ProgressionTracker::HandleActiveMasterChanged(v2);
      }
      if ( v2->mbOpenWorldSnapshotState == Update_Requested )
        v2->mbOpenWorldSnapshotState = 1;
      v2->mState = 8;
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
      UFG::ProgressionTracker::SyncCompleted(v2, 0);
      UFG::ProgressionTracker::ApplyGameplayEffects(v2);
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
      v14 = v2->mpLastCheckpoint;
      if ( v14 )
      {
        v2->mHoldCurtainPostRestore = v14->mHoldCurtain != 0;
        UFG::GameSlice::_SimulateUnlock(v14, 0);
        UFG::ProgressionTracker::StartTrackingMissionScoring(v2, v2->mpActiveMaster, 0);
        v15 = v2->mpLastCheckpoint;
        if ( v15->mpParent )
          v15 = v15->mpParent;
        if ( v15->mIsTODRestricted )
        {
          v16 = v15->mTODRestore;
          v17 = UFG::TimeOfDayManager::GetInstance();
          UFG::TimeOfDayManager::SetTime(v17, v16, 0);
        }
        v18 = v2->mpLastCheckpoint;
        v19 = v18->mState;
        if ( v19 != 2 )
        {
          if ( !(_S19_1 & 1) )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          unk_14240B986 = 1;
          UFG::GameSlice::Unlock(v18, STATE_RESTORING);
          if ( v18->mExclusive || v18->mRandomExclusive )
          {
            if ( v19 == 4 && v18->mExclusiveChild == v18 )
            {
              v18->mExclusiveChild = 0i64;
              v20 = v18->mpParent;
              if ( v20 )
                UFG::GameSlice::_MarkExclusiveChild(v20, 0i64);
            }
            if ( v18->mState == 4 )
            {
              v18->mExclusiveChild = v18;
              v21 = v18->mpParent;
              if ( v21 )
                UFG::GameSlice::_MarkExclusiveChild(v21, v18);
              v18->mRequiresSave = 0;
            }
            if ( v18->mState == 8 && v18->mExclusive && v18->mPersistent )
              v18->mRequiresSave = 1;
          }
        }
        if ( v2->mRestoringType == 1 )
          UFG::GameSlice::OnSafehouseRestore(v2->mpLastCheckpoint);
      }
      else
      {
        v2->mHoldCurtainPostRestore = 0;
      }
      goto LABEL_88;
    case 0xB:
      if ( UFG::ProgressionTracker::IsCleanupCompleted(this) )
        v2->mState = 12;
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
      v2->mState = 3;
LABEL_89:
      UFG::GameSliceStreamer::Update(&v2->mGameSliceStreamer);
      if ( gShowMissionWorkState == 1 )
        UFG::ProgressionTracker::DrawMissionWorkStates(v2, realTimeDelta);
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
}trics::msInstance.mSimTimeMSec <= this->mContainerCompl

// File Line: 2094
// RVA: 0x4C6630
void __fastcall UFG::ProgressionTracker::UpdateDependency(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rsi
  unsigned __int64 v2; // rax
  UFG::qBaseTreeRB *i; // rdi
  UFG::qBaseTreeRB *j; // rdi
  UFG::GameSlice *k; // rdi
  UFG::GameSlice *l; // rdi
  UFG::qBaseTreeRB *m; // rdi
  UFG::GameSlice *n; // rdi
  UFG::CaseTracker *v9; // rsi
  __int64 v10; // rbx
  signed int v11; // edi

  v1 = this;
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
          i = UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &i->mRoot) )
    {
      BYTE2(i[4].mNULL.mParent) = 1;
      UFG::ProgressionTracker::Instance()->mDirty = 1;
    }
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
          j;
          j = UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &j->mRoot) )
    {
      BYTE2(j[4].mNULL.mParent) = 1;
      UFG::ProgressionTracker::Instance()->mDirty = 1;
    }
    for ( k = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
          k;
          k = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &k->mNode) )
    {
      UFG::GameSlice::UpdateDependency(k);
    }
    for ( l = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
          l;
          l = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &l->mNode) )
    {
      UFG::GameSlice::UpdateDependency(l);
    }
    if ( v1->mContainerCompleted )
    {
      for ( m = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
            m;
            m = UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &m->mRoot) )
      {
        BYTE2(m[4].mNULL.mParent) = 1;
        UFG::ProgressionTracker::Instance()->mDirty = 1;
      }
      for ( n = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
            n;
            n = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &n->mNode) )
      {
        UFG::GameSlice::UpdateDependency(n);
      }
    }
    v1->mDirty = 0;
    UFG::ProgressionTracker::ActiveMasterCheck(v1);
    v9 = &v1->mCaseTracker;
    v10 = 0i64;
    v11 = v9->mCases.size;
    if ( (signed int)v9->mCases.size > 0 )
    {
      do
      {
        UFG::CaseInfo::UpdateStatus(&v9->mCases.p[v10]);
        v10 = (unsigned int)(v10 + 1);
      }
      while ( (signed int)v10 < v11 );
    }
  }
}

// File Line: 2190
// RVA: 0x4BCCE0
void __fastcall UFG::ProgressionTracker::SetLastCompleted(UFG::ProgressionTracker *this, UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v2; // rbx
  UFG::GameSlice *v3; // rax
  __int64 v4; // rcx
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax

  v2 = pGameSlice;
  v3 = this->mpAutoSaveQueuedSlice;
  if ( (!v3 || v3 == pGameSlice) && !pGameSlice->mpParent )
  {
    v4 = pGameSlice->mType;
    if ( (signed int)v4 > 0 && gGameSliceTypePriority[v4] >= 4 && !pGameSlice->mInternalSlice )
    {
      if ( (_DWORD)v4 == 11 )
      {
        v5 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v5 + 6216) & 1) )
          v5->mpSnapshots[0]->mIDs[29].mValue.mUID = v2->mNode.mUID;
      }
      v6 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v6 + 6216) & 1) )
        v6->mpSnapshots[0]->mIDs[28].mValue.mUID = v2->mNode.mUID;
    }
  }
}

// File Line: 2224
// RVA: 0x4C8470
void __fastcall UFG::ProgressionTracker::UpdateSnapshot(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  signed int v3; // esi
  UFG::ProgressionTracker::ActiveMasterMode v4; // eax
  UFG::GameSnapshot *v5; // rcx
  UFG::ProgressionTracker::ActiveMasterMode v6; // ecx
  int v7; // ecx

  v1 = this;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = 2;
  if ( v1->mbOpenWorldSnapshotState == 1 )
  {
    UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
    UFG::GameSnapshot::Clone(v2->mpSnapshots[1], v2->mpSnapshots[0]);
    v1->mbOpenWorldSnapshotState = 2;
  }
  if ( v1->mMasterModeChanged )
  {
    UFG::ProgressionTracker::UpdateGameSlicesSnapshot(v1);
    v4 = v1->mActiveMasterMode;
    if ( v4 == 1 )
    {
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      UFG::GameSnapshot::Clone(v2->mpSnapshots[1], v2->mpSnapshots[0]);
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      v5 = v2->mpSnapshots[2];
    }
    else if ( v4 == 2 )
    {
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      v5 = v2->mpSnapshots[3];
    }
    else
    {
      if ( !v1->mCommitOnMasterModeChanged )
        goto LABEL_15;
      UFG::GameStatTracker::SynchronizeCurrentSnapshotWithCurrentGameState(v2);
      v5 = v2->mpSnapshots[1];
    }
    UFG::GameSnapshot::Clone(v5, v2->mpSnapshots[0]);
  }
LABEL_15:
  if ( v1->mCheckpointChanged )
  {
    UFG::ProgressionTracker::UpdateGameSlicesSnapshot(v1);
    v6 = v1->mActiveMasterMode;
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
  *(_WORD *)&v1->mCheckpointChanged = 0;
  v1->mCommitOnMasterModeChanged = 0;
}

// File Line: 2308
// RVA: 0x495D20
void __fastcall UFG::ProgressionTracker::BuildSavegameSnapshot(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  UFG::GameSnapshot *v3; // rdx

  v1 = this;
  UFG::ProgressionTracker::SaveSnapshotWeather(this);
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  if ( v1->mActiveMasterMode )
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
  UFG::ProgressionTracker *v1; // rbx
  UFG::GameStatTracker *v2; // rdi
  UFG::ProgressionTracker::ActiveMasterMode v3; // ecx
  int v4; // ecx
  signed int v5; // eax
  signed __int64 v6; // rbx

  v1 = this;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v2 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v2;
  v3 = v1->mActiveMasterMode;
  if ( v3 )
  {
    v4 = v3 - 1;
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
  v6 = (signed __int64)v2 + 8 * v5;
  UFG::GameSnapshot::CommitByFilter(*(UFG::GameSnapshot **)(v6 + 6160), v2->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
  UFG::GameSnapshot::CommitByFilter(*(UFG::GameSnapshot **)(v6 + 6160), v2->mpSnapshots[0], 4u, 2u, 0);
  UFG::GameSnapshot::Clone(v2->mpSnapshots[0], *(UFG::GameSnapshot **)(v6 + 6160));
}

// File Line: 2355
// RVA: 0x4B2D10
void __fastcall UFG::ProgressionTracker::PublishProgressionStatistics(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // r14
  UFG::qBaseTreeRB *i; // rdi
  bool v3; // si
  UFG::GameStatTracker *v4; // rax
  UFG::GameStat::MapBoolStat v5; // edx
  UFG::GameSlice *j; // rbx

  v1 = this;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &i->mRoot) )
  {
    v3 = LODWORD(i[3].mNULL.mChild[1]) == 8 || SWORD2(i[5].mRoot.mParent) > 0;
    switch ( BYTE3(i[4].mNULL.mChild[1]) )
    {
      case 1u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 66;
        goto LABEL_15;
      case 2u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 69;
        goto LABEL_15;
      case 3u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 67;
        goto LABEL_15;
      case 4u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 68;
        goto LABEL_15;
      case 5u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 72;
        goto LABEL_15;
      case 6u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 70;
        goto LABEL_15;
      case 7u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 71;
        goto LABEL_15;
      case 8u:
        v4 = UFG::GameStatTracker::Instance();
        v5 = 73;
LABEL_15:
        UFG::GameStatTracker::SetStat(v4, v5, (UFG::qSymbol *)&i->mRoot.mUID, v3);
        break;
      default:
        continue;
    }
  }
  for ( j = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
        j;
        j = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &j->mNode) )
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
  if ( !(_S12_6 & 1) )
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
  UFG::ProgressionTracker *v1; // rbx

  v1 = this;
  if ( UFG::qString::operator!=(&this->mGlobalAlternateLayer, &customWorldMapCaption) )
  {
    UFG::SectionLayout::SetLayerActive(v1->mGlobalAlternateLayer.mData, 1);
    UFG::SectionChooser::FlushAltLayer(v1->mGlobalAlternateLayer.mData, 1);
  }
}

// File Line: 2389
// RVA: 0x4B75A0
void __fastcall UFG::ProgressionTracker::Restart(UFG::ProgressionTracker *this, UFG::GameSlice *pData)
{
  UFG::GameSlice *v2; // rsi
  UFG::ProgressionTracker *v3; // rdi
  UFG::GameStatTracker *v4; // rbx

  v2 = pData;
  v3 = this;
  if ( this->mActiveMasterMode != 2 )
  {
    v4 = UFG::GameStatTracker::Instance();
    UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
    UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 4u, 2u, 0);
    UFG::GameSnapshot::Clone(v4->mpSnapshots[0], v4->mpSnapshots[1]);
    v3->mActiveMasterMode = 0;
    v3->mbOpenWorldSnapshotState = 2;
    UFG::ProgressionTracker::ForceProgress(v3, v2, 0);
  }
}

// File Line: 2405
// RVA: 0x49FC20
void __fastcall UFG::ProgressionTracker::ExitChallenge(UFG::ProgressionTracker *this, bool success)
{
  bool v2; // bl
  UFG::ProgressionTracker *v3; // rsi
  UFG::GameStatTracker *v4; // rdi
  UFG::qPropertySet *v5; // rbp
  UFG::GameSlice *v6; // rbx
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]

  v2 = success;
  v3 = this;
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v5 = UFG::GameSlice::GetRewardsProperties(v3->mpActiveMaster);
  if ( v2 )
  {
    v6 = v3->mpActiveMaster;
    if ( v6->mNode.mUID == UFG::qSymbol::create_from_string(&result, "M_VE")->mUID )
    {
      UFG::qSymbol::create_from_string(&result, "default-rewards-progression-M_VEM_repeat");
      v5 = UFG::PropertySetManager::FindPropertySet(&result);
    }
    UFG::RewardsHandler::HandleRewards(0, v5, 0i64);
  }
  UFG::ProgressionTracker::ResetProgression(v3, RestoreType_SafehouseComputer, uidGameStateUnloadChallenge_9, 1);
  UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 0xFFFFFFF8, 2u, 1u);
  UFG::GameSnapshot::CommitByFilter(v4->mpSnapshots[1], v4->mpSnapshots[0], 4u, 2u, 0);
  UFG::GameSnapshot::Clone(v4->mpSnapshots[0], v4->mpSnapshots[1]);
  v3->mActiveMasterMode = 0;
  v3->mbOpenWorldSnapshotState = 2;
  v3->mModeType = 0;
}

// File Line: 2445
// RVA: 0x4A0380
UFG::qBaseTreeRB *__fastcall UFG::ProgressionTracker::Find(UFG::ProgressionTracker *this, UFG::qSymbol *name, bool searchDisabledSlices)
{
  UFG::qSymbol *v3; // rbx
  UFG::ProgressionTracker *v4; // rdi
  unsigned int v5; // edx
  UFG::qBaseTreeRB *result; // rax

  v3 = name;
  v4 = this;
  if ( !searchDisabledSlices
    || (v5 = name->mUID) == 0
    || (result = UFG::qBaseTreeRB::Get(&this->mDisabledGameSlices.mTree, v5)) == 0i64 )
  {
    if ( !v3->mUID || (result = UFG::qBaseTreeRB::Get(&v4->mGameSlices.mTree, v3->mUID)) == 0i64 )
    {
      if ( v3->mUID )
        result = UFG::qBaseTreeRB::Get(&v4->mContainerGameSlices.mTree, v3->mUID);
      else
        result = 0i64;
    }
  }
  return result;
}

// File Line: 2463
// RVA: 0x4A03F0
Render::SkinningCacheNode *__fastcall UFG::ProgressionTracker::FindByLayer(UFG::ProgressionTracker *this, UFG::qSymbol *name)
{
  UFG::ProgressionTracker *v2; // rbp
  UFG::qSymbol *v3; // rsi
  Render::SkinningCacheNode *v4; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = name;
  v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mGameSlices);
  if ( v4 )
  {
    while ( UFG::qSymbol::create_from_string(&result, (const char *)v4[1].mNode.mChild[0])->mUID != v3->mUID )
    {
      v4 = (Render::SkinningCacheNode *)UFG::qBaseTreeRB::GetNext(&v2->mGameSlices.mTree, (UFG::qBaseNodeRB *)v4);
      if ( !v4 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v2->mContainerGameSlices);
    if ( !v4 )
      return 0i64;
    while ( UFG::qSymbol::create_from_string(&result, (const char *)v4[1].mNode.mChild[0])->mUID != v3->mUID )
    {
      v4 = (Render::SkinningCacheNode *)UFG::qBaseTreeRB::GetNext(
                                          &v2->mContainerGameSlices.mTree,
                                          (UFG::qBaseNodeRB *)v4);
      if ( !v4 )
        return 0i64;
    }
  }
  return v4;
}

// File Line: 2502
// RVA: 0x494670
void __fastcall UFG::ProgressionTracker::ApplyMonetaryReward(UFG::ProgressionTracker *this, int moneyCount)
{
  int v2; // edi
  UFG::GameStatTracker *v3; // rbx

  v2 = moneyCount;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  UFG::GameStatTracker::MoneyHackSoWeCanShipThisGame(v3, v2);
}

// File Line: 2508
// RVA: 0x494590
void __fastcall UFG::ProgressionTracker::ApplyMonetaryPenalty(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::UIHKScreenHud *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameSnapshot *v4; // rcx
  int v5; // edx
  float v6; // xmm1_4
  int v7; // ebx
  UFG::OSuiteLeaderboardManager *v8; // rax
  UFG::OSuiteLeaderboardData *v9; // rax

  v1 = this;
  if ( this->mMonetaryPenalty )
  {
    if ( UFG::UIHK_NISOverlay::IsCurtainHidden() )
    {
      v2 = UFG::UIHKScreenHud::getInstance();
      if ( v2 )
      {
        if ( v2->mState >= 3 )
        {
          v3 = UFG::GameStatTracker::Instance();
          v4 = v3->mpSnapshots[0];
          v5 = v4->mInts[44].mValue;
          v6 = v4->mFloats[77].mValue;
          if ( v1->mMonetaryPenalty == 2 )
          {
            v5 = v4->mInts[45].mValue;
            v6 = v4->mFloats[78].mValue;
          }
          v7 = (signed int)(float)((float)((float)v4->mInts[62].mValue * v6) * 0.0099999998);
          if ( v5 < v7 )
            v7 = v5;
          UFG::GameStatTracker::ApplyDelta(v3, Money, -v7);
          v8 = UFG::OSuiteLeaderboardManager::Instance();
          v9 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v8, "StatAwardsBigSpender");
          UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v9, v7);
          v1->mMonetaryPenalty = 0;
        }
      }
    }
  }
}

// File Line: 2620
// RVA: 0x4A1390
void __fastcall UFG::ProgressionTracker::ForceSliceChange(UFG::ProgressionTracker *this, UFG::GameSlice *pData, bool simulateRewards)
{
  bool v3; // si
  UFG::GameSlice *v4; // rbp
  UFG::ProgressionTracker *v5; // r14
  unsigned int v6; // er9
  UFG::GameStatTracker *v7; // rbx
  UFG::GameStatTracker *v8; // rcx
  UFG::PersistentData::MapBool *v9; // rdx
  UFG::PersistentData::MapInt *v10; // rdi
  UFG::PersistentData::KeyValue *v11; // rcx
  char *v12; // rbx

  v3 = simulateRewards;
  v4 = pData;
  v5 = this;
  v6 = _S12_6;
  v7 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  if ( !(v6 & 1) )
  {
    _S12_6 = v6 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v7 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v7;
  v10 = v7->mpSnapshots[0]->mpMapInts[23];
  v11 = v10->mValues.p;
  if ( v11 )
  {
    v12 = (char *)&v11[-1].4;
    `eh vector destructor iterator'(v11, 8ui64, v11[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v12);
  }
  v10->mValues.p = 0i64;
  *(_QWORD *)&v10->mValues.size = 0i64;
  UFG::ProgressionTracker::ForceProgress(v5, v4, v3);
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
      this->mState = 3;
      break;
    case 3:
    case 9:
    case 0xA:
    case 0xC:
    case 0xD:
      this->mState = 5;
      break;
    default:
      return;
  }
}

// File Line: 2804
// RVA: 0x48D3C0
void __fastcall UFG::ProgressionTracker::ProgressionTracker(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::CaseTracker *v2; // rbx
  UFG::ObjectiveTracker *v3; // [rsp+68h] [rbp+10h]
  AnimationGroupHandleContainer *v4; // [rsp+68h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v5; // [rsp+68h] [rbp+10h]

  v1 = this;
  this->mState = 1;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mGameSlices.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mContainerGameSlices.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mDisabledGameSlices.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mCollections.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mSceneSettings.mTree);
  *(_QWORD *)&v1->mLayerOwnership.mCount = 0i64;
  v1->mLayerOwnership.mppArray = 0i64;
  v3 = &v1->mObjectiveTracker;
  v3->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&v3->mLoadedOrderObjectives.size = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mObjectiveTracker.mObjectives.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mObjectiveTracker.mObjectiveHints.mTree);
  v1->mObjectiveTracker.mDirty = 0;
  v1->mObjectiveTracker.mpFlashObjective = 0i64;
  v1->mObjectiveTracker.mLastLoadId = 0;
  `eh vector constructor iterator'(
    &v1->mSecondaryObjectiveTracker,
    0x38ui64,
    2,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::SecondaryObjective);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mPDATriggerTracker.mPDATriggers.mTree);
  v2 = &v1->mCaseTracker;
  `eh vector constructor iterator'(
    v1->mCaseTracker.mCases.p,
    0x50ui64,
    20,
    (void (__fastcall *)(void *))UFG::CaseInfo::CaseInfo);
  v2->mCases.size = 0;
  v2->mCases.size = 0;
  UFG::GameSliceStreamer::GameSliceStreamer(&v1->mGameSliceStreamer);
  UFG::qString::qString(&v1->mLocationPath);
  UFG::qString::qString(&v1->mDependencyGraphName);
  *(_QWORD *)&v1->mDEBUGTestScenarioScriptName.mUID = -1i64;
  v1->mpActiveMaster = 0i64;
  v1->mpLastCheckpoint = 0i64;
  v1->mpLastFailed = 0i64;
  v1->mbOpenWorldSnapshotState = 2;
  v1->mbPendingSceneSettingsValid = 0;
  UFG::SceneSettings::SceneSettings(&v1->mPendingSceneSettingsLocal, "ProgressionTrackerSettingsLocal");
  UFG::SceneSettings::SceneSettings(&v1->mPendingSceneSettingsCache, "ProgressionTrackerSettingsCache");
  *(_QWORD *)&v1->mMonetaryPenalty = 0i64;
  *(_WORD *)&v1->mDisableProgression = 0;
  v1->mIsWorldDataRestored = 0;
  *(_QWORD *)&v1->mRestoreType = 1i64;
  v1->mModeType = 0;
  v1->mSubSetModeType.mUID = -1;
  *(_DWORD *)&v1->mResourceFreezeMode = 0;
  v1->mpAutoSaveQueuedSlice = 0i64;
  v1->mActiveMasterMode = 0;
  v1->mLastUpdateTimestamp = 0i64;
  v1->mContainerCompletedTimestamp = 0i64;
  v4 = &v1->mAnimationGroupHandleContainer;
  v4->m_AnimationGroupHandleList.mNode.mPrev = &v4->m_AnimationGroupHandleList.mNode;
  v4->m_AnimationGroupHandleList.mNode.mNext = &v4->m_AnimationGroupHandleList.mNode;
  v1->mAnimationGroupHandleContainer.m_bHasBeenBound = 0;
  UFG::qString::qString(&v1->mGlobalAlternateLayer);
  *(_QWORD *)&v1->mTimeShiftState = 0i64;
  v1->mTimeShiftSlice = 0i64;
  v1->mTimeShiftTrigger = 0i64;
  v5 = &v1->mLastUsedVehicle;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mLastUsedVehicle.m_pPointer = 0i64;
  UFG::GameSetup::GameSetup(&v1->mGameSetup);
  v1->mActiveFlowId.mUID = gDefaultFlowId.mUID;
  v1->mIsPossessedPedsEnabled = 0;
}

// File Line: 2808
// RVA: 0x490F20
void __fastcall UFG::ProgressionTracker::~ProgressionTracker(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rax
  UFG::CaseTracker *v9; // rcx

  v1 = this;
  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll((qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo> *)&this->mLayerOwnership.mCount);
  v1->mGameSetup.vfptr = (UFG::GameSetupVtbl *)&UFG::GameSetup::`vftable';
  v2 = &v1->mLastUsedVehicle;
  if ( v1->mLastUsedVehicle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mLastUsedVehicle.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mLastUsedVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mLastUsedVehicle.mPrev;
  }
  v1->mLastUsedVehicle.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mLastUsedVehicle.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mLastUsedVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mLastUsedVehicle.mPrev;
  UFG::qString::~qString(&v1->mGlobalAlternateLayer);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  v7 = v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev;
  v8 = v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  UFG::SceneSettings::~SceneSettings(&v1->mPendingSceneSettingsCache);
  UFG::SceneSettings::~SceneSettings(&v1->mPendingSceneSettingsLocal);
  UFG::qString::~qString(&v1->mDependencyGraphName);
  UFG::qString::~qString(&v1->mLocationPath);
  UFG::GameSliceStreamer::~GameSliceStreamer(&v1->mGameSliceStreamer);
  v9 = &v1->mCaseTracker;
  v9->mCases.size = 0;
  v9->mCases.size = 0;
  `eh vector destructor iterator'(
    v1->mCaseTracker.mCases.p,
    0x50ui64,
    20,
    (void (__fastcall *)(void *))UFG::CaseInfo::~CaseInfo);
  UFG::PDATriggerTracker::~PDATriggerTracker(&v1->mPDATriggerTracker);
  `eh vector destructor iterator'(
    &v1->mSecondaryObjectiveTracker,
    0x38ui64,
    2,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
  UFG::ObjectiveTracker::~ObjectiveTracker(&v1->mObjectiveTracker);
  operator delete[](v1->mLayerOwnership.mppArray);
  UFG::qTreeRB<UFG::SceneSettings,UFG::SceneSettings,1>::~qTreeRB<UFG::SceneSettings,UFG::SceneSettings,1>(&v1->mSceneSettings);
  UFG::qTreeRB<UFG::GameSliceCollection,UFG::GameSliceCollection,1>::DeleteAll(&v1->mCollections);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mCollections);
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1>::~qTreeRB<UFG::GameSlice,UFG::GameSlice,1>(&v1->mDisabledGameSlices);
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1>::~qTreeRB<UFG::GameSlice,UFG::GameSlice,1>(&v1->mContainerGameSlices);
  UFG::qTreeRB<UFG::GameSlice,UFG::GameSlice,1>::~qTreeRB<UFG::GameSlice,UFG::GameSlice,1>(&v1->mGameSlices);
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
  UFG::qBaseTreeRB *v2; // rdi
  int v3; // ebx
  UFG::qBaseTreeRB *result; // rax

  v2 = &this->mContainerGameSlices.mTree;
  v3 = index;
  result = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
  if ( !result )
    return 0i64;
  while ( v3 )
  {
    --v3;
    result = UFG::qBaseTreeRB::GetNext(v2, &result->mRoot);
    if ( !result )
      return 0i64;
  }
  return result;
}

// File Line: 2898
// RVA: 0x4BFC40
void __fastcall UFG::ProgressionTracker::StartTrackingMissionScoring(UFG::ProgressionTracker *this, UFG::GameSlice *pGameSlice, bool resetScore)
{
  bool v3; // si
  UFG::GameSlice *v4; // rbx
  UFG::GameSlice::Type v5; // eax
  UFG::qPropertySet *v6; // rdi
  UFG::qPropertySet *v7; // rcx
  UFG::qSymbol result; // [rsp+20h] [rbp-18h]
  __int64 v9; // [rsp+28h] [rbp-10h]
  UFG::qSymbol symGameSliceName; // [rsp+48h] [rbp+10h]
  UFG::qSymbol *propSetName; // [rsp+58h] [rbp+20h]

  v9 = -2i64;
  v3 = resetScore;
  v4 = pGameSlice;
  if ( !pGameSlice->mInternalSlice )
  {
    v5 = pGameSlice->mType;
    if ( (signed int)v5 >= 5 )
    {
      if ( (signed int)v5 <= 10 )
      {
        v7 = UFG::GameSlice::GetRewardsProperties(pGameSlice);
      }
      else
      {
        if ( v5 != 11 )
          return;
        UFG::qSymbol::create_from_string(&result, "M_VE");
        v6 = UFG::GameSlice::GetRewardsProperties(v4);
        if ( v4->mNode.mUID == result.mUID )
        {
          propSetName = &symGameSliceName;
          symGameSliceName.mUID = result.mUID;
          if ( UFG::GameStatAction::GameSliceAction::IsCompleted((__int64)&symGameSliceName) )
          {
            UFG::qSymbol::create_from_string((UFG::qSymbol *)&propSetName, "default-rewards-progression-M_VEF");
            if ( UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&propSetName) )
              v6 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&propSetName);
            else
              v6 = 0i64;
          }
        }
        v7 = v6;
      }
      UFG::GameStatAction::MissionScoring::StartTracking(v7);
      if ( v3 )
        UFG::GameStatAction::MissionScoring::ResetScore();
    }
  }
}

// File Line: 2950
// RVA: 0x4BB8B0
void __fastcall UFG::ProgressionTracker::SetActiveMaster(UFG::ProgressionTracker *this, UFG::GameSlice *pActiveMaster, UFG::GameSlice *pCheckpoint, bool forceSave)
{
  bool v4; // r15
  UFG::qSymbol *v5; // rbp
  UFG::GameSlice *v6; // rbx
  UFG::ProgressionTracker *v7; // rsi
  char v8; // r14
  bool v9; // di
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  UFG::SimObjectCharacter *v13; // rax
  float *v14; // rbx
  UFG::qBaseTreeRB *v15; // rax
  float *v16; // rbx
  UFG::GameStatTracker *v17; // rax
  UFG::GameStatTracker *v18; // rbx
  UFG::PersistentData::MapBool *v19; // r15
  UFG::PersistentData::MapInt *v20; // r12
  UFG::qBaseTreeRB *i; // rdi

  v4 = forceSave;
  v5 = (UFG::qSymbol *)pCheckpoint;
  v6 = pActiveMaster;
  v7 = this;
  v8 = 0;
  v9 = 0;
  if ( this->mpActiveMaster != pActiveMaster )
  {
    if ( pActiveMaster && pActiveMaster->mType != 2 )
    {
      v8 = 1;
      pActiveMaster->mSecondsLeftToDisplayFor = pActiveMaster->mStateDisplaySeconds;
      UFG::ProgressionTracker::StartTrackingMissionScoring(this, pActiveMaster, 1);
    }
    else
    {
      v8 = 0;
    }
    v7->mpActiveMaster = v6;
    v7->mDirty = 1;
    UFG::ProgressionTracker::HandleActiveMasterChanged(v7);
  }
  if ( (UFG::qSymbol *)v7->mpLastCheckpoint != v5 )
  {
    v9 = v5 && v5[67].mUID != 2;
    v10 = UFG::qVector3::msZero.x;
    v11 = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
    v13 = UFG::GetLocalPlayer();
    if ( v13 )
    {
      v14 = (float *)v13->m_pTransformNodeComponent;
      if ( v14 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v13->m_pTransformNodeComponent);
        v10 = v14[44];
        v11 = v14[45];
        v12 = v14[46];
      }
    }
    if ( v5 )
    {
      if ( v5[44].mUID != -1 )
      {
        v15 = UFG::MarkerBase::GetNamed(v5 + 44);
        if ( v15 )
        {
          v16 = (float *)v15[1].mNULL.mParent;
          if ( v16 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15[1].mNULL.mParent);
            v10 = v16[44];
            v11 = v16[45];
            v12 = v16[46];
          }
        }
      }
    }
    v17 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v17 + 6216) & 1) )
    {
      v17->mpSnapshots[0]->mFloats[79].mValue = v10;
      if ( !(*((_BYTE *)v17 + 6216) & 1) )
        v17->mpSnapshots[0]->mFloats[80].mValue = v11;
    }
    if ( !(*((_BYTE *)v17 + 6216) & 1) )
      v17->mpSnapshots[0]->mFloats[81].mValue = v12;
    v7->mpLastCheckpoint = (UFG::GameSlice *)v5;
    if ( v7->mState == 3 && v5 && v5[67].mUID != 2 )
      v7->mCheckpointChanged = 1;
  }
  if ( v8 || v9 || v4 )
  {
    v18 = &sGameStatTracker;
    if ( !(_S12_6 & 1) )
    {
      _S12_6 |= 1u;
      UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
      atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    }
    if ( UFG::GameStatTracker::mspInstance )
      v18 = UFG::GameStatTracker::mspInstance;
    UFG::GameStatTracker::mspInstance = v18;
    if ( v4 )
    {
      v19 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapBools[75];
      v20 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mpMapInts[23];
      for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v7->mGameSlices);
            i;
            i = UFG::qBaseTreeRB::GetNext(&v7->mGameSlices.mTree, &i->mRoot) )
      {
        if ( SWORD2(i[5].mRoot.mParent) > 0 && BYTE5(i[4].mNULL.mParent) && BYTE6(i[4].mNULL.mParent) )
        {
          UFG::PersistentData::MapBool::SetStatus(v19, (UFG::qSymbol *)&i->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v20, (UFG::qSymbol *)&i->mRoot.mUID, SWORD2(i[5].mRoot.mParent));
          BYTE6(i[4].mNULL.mParent) = 0;
        }
      }
    }
    if ( v5 )
    {
      if ( v7->mState == 3 )
        UFG::ProgressionTracker::SaveSnapshotWeather(v7);
    }
  }
}
    if ( v5 )
    {
      if ( v7->mS

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
  UFG::GameSlice *v1; // rax
  UFG::ProgressionTracker *v2; // r13
  UFG::ProgressionTracker::ActiveMasterMode v3; // ebp
  UFG::qBaseTreeRB *v4; // r15
  UFG::qBaseTreeRB *v5; // rsi
  UFG::qBaseTreeRB *v6; // r12
  UFG::qBaseTreeRB *v7; // r14
  UFG::qBaseTreeRB *v8; // rdi
  int v9; // eax
  UFG::GameSlice *v10; // rbx
  __int64 v11; // r15
  int v12; // ecx
  int v13; // er14
  int v14; // esi
  __int64 v15; // r8
  UFG::qBaseNodeRB *v16; // rdx
  UFG::qBaseNodeRB *v17; // rax
  signed int v18; // ecx
  UFG::qBaseNodeRB *v19; // rax
  UFG::qBaseNodeRB *v20; // rdx
  UFG::GameSlice *v21; // rcx
  unsigned __int8 v22; // al
  UFG::GameSlice *v23; // rcx
  int v24; // eax
  bool v25; // r9
  UFG::GameSlice *v26; // r8
  UFG::GameSlice *v27; // rdx
  UFG::GameSlice *v28; // rax
  char v29; // [rsp+70h] [rbp+8h]
  UFG::qBaseTreeRB *v30; // [rsp+78h] [rbp+10h]
  UFG::qBaseTreeRB *v31; // [rsp+80h] [rbp+18h]
  UFG::qBaseTreeRB *v32; // [rsp+88h] [rbp+20h]

  v1 = this->mpLastCheckpoint;
  v2 = this;
  if ( v1 && v1->mCheckpointSlice && v1->mState == 2 )
    return;
  v3 = 0;
  v4 = 0i64;
  v31 = 0i64;
  v5 = 0i64;
  v30 = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v32 = 0i64;
  v29 = 0;
  v8 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mContainerGameSlices);
  if ( !v8 )
  {
LABEL_54:
    v25 = 0;
    v26 = (UFG::GameSlice *)v5;
    v27 = (UFG::GameSlice *)v4;
    goto LABEL_55;
  }
  do
  {
    v9 = (int)v8[3].mNULL.mChild[1];
    v10 = v2->mpLastCheckpoint;
    if ( v9 == 8 )
      goto LABEL_50;
    v11 = LODWORD(v8[5].mNULL.mParent);
    if ( (_DWORD)v11 )
    {
      v13 = 0;
      v14 = 0;
      v15 = LODWORD(v8[5].mNULL.mParent);
      if ( v11 > 0 )
      {
        v16 = v8[5].mNULL.mChild[0];
        do
        {
          v17 = v16->mParent;
          v18 = (signed int)v16->mParent[8].mChild[0];
          if ( v18 == 8 )
          {
            ++v13;
            if ( BYTE2(v17[10].mChild[0]) )
              v10 = (UFG::GameSlice *)v16->mParent;
            if ( BYTE6(v17[10].mParent) )
              v29 = 1;
          }
          else
          {
            if ( BYTE3(v17[10].mParent) )
              ++v14;
            if ( (v18 >= 1 || SWORD2(v17[11].mChild[0]) > 0) && BYTE2(v17[10].mChild[0]) )
              v10 = (UFG::GameSlice *)v16->mParent;
          }
          v16 = (UFG::qBaseNodeRB *)((char *)v16 + 8);
          --v15;
        }
        while ( v15 );
      }
      v19 = v8[5].mNULL.mChild[0];
      v20 = v19->mParent;
      if ( SLODWORD(v19->mParent[8].mChild[0]) < 4 )
        goto LABEL_62;
      v21 = (UFG::GameSlice *)v20[11].mChild[1];
      v22 = v21 ? (unsigned __int8)UFG::GameSlice::IsWaitingForTrigger(v21) : BYTE4(v20[10].mChild[0]) != 0;
      if ( v22 || v13 >= (signed int)v11 - v14 )
        goto LABEL_62;
      v5 = 0i64;
      if ( v10 )
      {
        if ( v10 == (UFG::GameSlice *)v8
          || (v23 = v10->mpParent) != 0i64 && UFG::GameSlice::_IsChildOf(v23, (UFG::GameSlice *)v8) )
        {
          v5 = (UFG::qBaseTreeRB *)v10;
        }
      }
      v24 = HIDWORD(v8[3].mNULL.mChild[1]);
      if ( v24 == 2 )
      {
        v7 = v32;
        v4 = v8;
        v31 = v8;
        v30 = v5;
        goto LABEL_51;
      }
      if ( v6 && SHIDWORD(v6[3].mNULL.mChild[1]) >= v24 )
      {
LABEL_62:
        v7 = v32;
      }
      else
      {
        v6 = v8;
        v7 = v5;
        v32 = v5;
      }
      goto LABEL_50;
    }
    if ( v9 != 4 )
      goto LABEL_50;
    v12 = HIDWORD(v8[3].mNULL.mChild[1]);
    if ( !((v12 - 1) & 0xFFFFFFFC) && v12 != 2 )
      goto LABEL_50;
    if ( v12 != 2 )
    {
      if ( !v6 || SHIDWORD(v6[3].mNULL.mChild[1]) < v12 )
      {
        v7 = 0i64;
        v6 = v8;
        if ( BYTE2(v8[4].mNULL.mChild[0]) )
          v7 = v8;
        v32 = v7;
      }
LABEL_50:
      v4 = v31;
      v5 = v30;
      goto LABEL_51;
    }
    v5 = 0i64;
    v4 = v8;
    v31 = v8;
    if ( BYTE2(v8[4].mNULL.mChild[0]) )
      v5 = v8;
    v30 = v5;
LABEL_51:
    v8 = UFG::qBaseTreeRB::GetNext(&v2->mContainerGameSlices.mTree, &v8->mRoot);
  }
  while ( v8 );
  if ( !v6 )
    goto LABEL_54;
  v25 = v29;
  v26 = (UFG::GameSlice *)v7;
  v27 = (UFG::GameSlice *)v6;
LABEL_55:
  UFG::ProgressionTracker::SetActiveMaster(v2, v27, v26, v25);
  v28 = v2->mpActiveMaster;
  if ( v28 && v28->mType != 2 )
  {
    LOBYTE(v3) = v2->mModeType != 0;
    ++v3;
  }
  if ( v3 != v2->mActiveMasterMode )
  {
    *(_WORD *)&v2->mMasterModeChanged = 1;
    v2->mActiveMasterMode = v3;
  }
}

// File Line: 3244
// RVA: 0x4A7390
void __fastcall UFG::ProgressionTracker::HandleActiveMasterChanged(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  UFG::GameSlice *v2; // rcx
  char v3; // bl
  UFG::GameSlice *v4; // rcx
  UFG::GameSlice::Type v5; // eax
  UFG::StatGameManager *v6; // rdi

  v1 = this;
  v2 = this->mpActiveMaster;
  v3 = 1;
  if ( v2 )
  {
    if ( UFG::GameSlice::IsRewardPropertyRaceType(v2)
      || (v4 = v1->mpActiveMaster, v5 = v4->mType, v5 == 8)
      || v1->mModeType != 2 && !v4->mInternalSlice && v5 == 11 )
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
  UFG::ProgressionTracker *v1; // rbp
  unsigned int v2; // edx
  UFG::GameStatTracker *v3; // rbx
  UFG::GameStatTracker *v4; // rcx
  UFG::PersistentData::MapBool *v5; // r15
  UFG::PersistentData::MapInt *v6; // rsi
  UFG::PersistentData::KeyValue *v7; // rcx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v8; // rbx
  UFG::GameSlice *v9; // rax
  UFG::qBaseTreeRB *i; // rdi
  UFG::qBaseTreeRB *j; // rdi
  UFG::GameSlice *v12; // rdx
  UFG::GameSlice *v13; // rcx
  UFG::qBaseTreeRB *k; // rdi
  UFG::qBaseTreeRB *l; // rdi

  v1 = this;
  v2 = _S12_6;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  if ( !(v2 & 1) )
  {
    _S12_6 = v2 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  v6 = v3->mpSnapshots[0]->mpMapInts[23];
  v7 = v6->mValues.p;
  if ( v7 )
  {
    v8 = &v7[-1].4;
    `eh vector destructor iterator'(v7, 8ui64, v7[-1].mIntValue, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  v6->mValues.p = 0i64;
  *(_QWORD *)&v6->mValues.size = 0i64;
  if ( v1->mGameSlices.mTree.mCount )
  {
    v9 = v1->mpActiveMaster;
    if ( v9 && v9->mCompletionCount <= 0 )
    {
      for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
            i;
            i = UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &i->mRoot) )
      {
        if ( SWORD2(i[5].mRoot.mParent) > 0 )
        {
          UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&i->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&i->mRoot.mUID, SWORD2(i[5].mRoot.mParent));
        }
      }
      for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
            j;
            j = UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &j->mRoot) )
      {
        if ( SWORD2(j[5].mRoot.mParent) > 0 )
        {
          if ( BYTE5(j[4].mNULL.mParent)
            || (v12 = v1->mpActiveMaster, j != (UFG::qBaseTreeRB *)v12)
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
      for ( k = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
            k;
            k = UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &k->mRoot) )
      {
        if ( SWORD2(k[5].mRoot.mParent) > 0 )
        {
          UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&k->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&k->mRoot.mUID, SWORD2(k[5].mRoot.mParent));
        }
      }
      for ( l = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
            l;
            l = UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &l->mRoot) )
      {
        if ( SWORD2(l[5].mRoot.mParent) > 0 )
        {
          UFG::PersistentData::MapBool::SetStatus(v5, (UFG::qSymbol *)&l->mRoot.mUID, 1);
          UFG::PersistentData::MapInt::SetStatus(v6, (UFG::qSymbol *)&l->mRoot.mUID, SWORD2(l[5].mRoot.mParent));
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
  UFG::SectionChooser::EnableStreamsUpdate(enable == 0);
}

// File Line: 3338
// RVA: 0x4A4480
UFG::GameSlice *__fastcall UFG::ProgressionTracker::GetLastCheckpoint(UFG::ProgressionTracker *this)
{
  return this->mpLastCheckpoint;
}

// File Line: 3343
// RVA: 0x4BD0F0
void __fastcall UFG::ProgressionTracker::SetScriptRestoreLocation(UFG::ProgressionTracker *this, UFG::qVector3 *position)
{
  UFG::qVector3 *v2; // rdi
  UFG::GameStatTracker *v3; // rbx

  v2 = position;
  this->mRestoreType = 7;
  v3 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v3 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v3;
  if ( !(*((_BYTE *)v3 + 6216) & 1) )
    v3->mpSnapshots[0]->mFloats[79].mValue = v2->x;
  if ( !(*((_BYTE *)v3 + 6216) & 1) )
    v3->mpSnapshots[0]->mFloats[80].mValue = v2->y;
  if ( !(*((_BYTE *)v3 + 6216) & 1) )
    v3->mpSnapshots[0]->mFloats[81].mValue = v2->z;
}

// File Line: 3353
// RVA: 0x4ACC30
bool __fastcall UFG::ProgressionTracker::IsRunningCriticalActiveMaster(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *v1; // rax

  v1 = this->mpActiveMaster;
  return v1 && !v1->mInternalSlice && gGameSliceTypePriority[v1->mType] == 5;
}

// File Line: 3366
// RVA: 0x4BCFB0
void __fastcall UFG::ProgressionTracker::SetRestoreType(UFG::ProgressionTracker *this, UFG::ProgressionTracker::RestoreType restoreType, bool useCurrentLocation)
{
  float v3; // xmm7_4
  float v4; // xmm8_4
  float v5; // xmm6_4
  UFG::SimObjectCharacter *v6; // rax
  UFG::TransformNodeComponent *v7; // rbx
  UFG::GameStatTracker *v8; // rax

  this->mRestoreType = restoreType;
  if ( useCurrentLocation )
  {
    v3 = UFG::qVector3::msZero.x;
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    v6 = UFG::GetLocalPlayer();
    if ( v6 )
    {
      v7 = v6->m_pTransformNodeComponent;
      if ( v7 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v6->m_pTransformNodeComponent);
        v3 = v7->mWorldTransform.v3.x;
        v4 = v7->mWorldTransform.v3.y;
        v5 = v7->mWorldTransform.v3.z;
      }
    }
    v8 = UFG::GameStatTracker::Instance();
    if ( !(*((_BYTE *)v8 + 6216) & 1) )
    {
      v8->mpSnapshots[0]->mFloats[79].mValue = v3;
      if ( !(*((_BYTE *)v8 + 6216) & 1) )
        v8->mpSnapshots[0]->mFloats[80].mValue = v4;
    }
    if ( !(*((_BYTE *)v8 + 6216) & 1) )
      v8->mpSnapshots[0]->mFloats[81].mValue = v5;
  }
}

// File Line: 3404
// RVA: 0x4B1970
void __fastcall UFG::ProgressionTracker::OnFailObject(UFG::ProgressionTracker *this, UFG::SimObject *pObject, UFG::qString *caption)
{
  UFG::qString *v3; // rbp
  UFG::SimObjectGame *v4; // rdi
  UFG::ProgressionTracker *v5; // rsi
  char *v6; // rbx
  UFG::GameSlice *v7; // rbx
  unsigned __int16 v8; // cx
  UFG::MissionFailConditionComponent *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbolUC *v11; // rdi

  v3 = caption;
  v4 = (UFG::SimObjectGame *)pObject;
  v5 = this;
  if ( this->mState != 10 )
  {
    v6 = caption->mData;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pObject->m_Name);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[Progression]:  This object (%s) caused a mission fail, reason: (%s)\n");
    v7 = 0i64;
    if ( !v4
      || ((v8 = v4->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = (UFG::MissionFailConditionComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::MissionFailConditionComponent::_TypeUID)) : (v9 = (UFG::MissionFailConditionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::MissionFailConditionComponent::_TypeUID))) : (v9 = (UFG::MissionFailConditionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::MissionFailConditionComponent::_TypeUID))) : (v9 = (UFG::MissionFailConditionComponent *)v4->m_Components.p[8].m_pComponent)) : (v9 = (UFG::MissionFailConditionComponent *)v4->m_Components.p[8].m_pComponent),
          !v9 || (v7 = v9->mpCustomGameSlice) == 0i64) )
    {
      v10 = (UFG::qSymbol *)UFG::SceneObjectProperties::FindOwnerLayer(v4->m_pSceneObj);
      if ( !v10 )
      {
LABEL_17:
        UFG::ProgressionTracker::OnFailGameSlice(v5, v7, v3);
        return;
      }
      v11 = (UFG::qSymbolUC *)&v10[6];
      v7 = (UFG::GameSlice *)UFG::ProgressionTracker::FindByLayer(v5, v10 + 6);
      if ( !v7 )
      {
        UFG::qSymbol::as_cstr_dbg(v11);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_Progression,
          OUTPUT_LEVEL_DEBUG,
          "[Progression]: Unable to find the proper game slice that this object is attached to in order to fail it.  The layer is (%s)\n");
        goto LABEL_17;
      }
    }
    while ( v7->mpParent )
      v7 = v7->mpParent;
    goto LABEL_17;
  }
}

// File Line: 3451
// RVA: 0x4B1840
void __fastcall UFG::ProgressionTracker::OnFailGameSlice(UFG::ProgressionTracker *this, UFG::GameSlice *pGameSlice, UFG::qString *caption)
{
  UFG::qString *v3; // r14
  UFG::GameSlice *v4; // rbx
  UFG::ProgressionTracker *v5; // rbp
  char *v6; // r9
  char *v7; // ST20_8
  char *v8; // r9
  char *v9; // ST20_8
  __int64 v10; // rsi
  __int64 i; // rdi
  UFG::SSGameSlice *v12; // rcx
  UFG::SSGameSlice *v13; // rcx

  v3 = caption;
  v4 = pGameSlice;
  v5 = this;
  if ( this->mState != 10 && (!pGameSlice || pGameSlice->mScript) )
  {
    this->mpLastFailed = pGameSlice;
    if ( !pGameSlice )
    {
      v4 = this->mpActiveMaster;
      if ( !v4 )
        return;
      v6 = v4->mName.mText;
      v7 = v4->mScriptClassName.mText;
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]:  The passed in GameSlice is NULL, so trying to fail the active mission(%s)[%s]\n");
    }
    if ( v4->mScript )
    {
      v8 = v4->mName.mText;
      v9 = v4->mScriptClassName.mText;
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]:  Failing Gameslice(%s)[%s]\n");
      v10 = v4->mChildren.mCount;
      for ( i = 0i64; i < v10; ++i )
      {
        v12 = v4->mChildren.mppArray[i]->mScript;
        if ( v12 )
          SSActor::suspend_coroutines((SSActor *)&v12->vfptr);
      }
      v13 = v4->mScript;
      if ( v13 )
        SSActor::suspend_coroutines((SSActor *)&v13->vfptr);
      v5->mState = 10;
      UFG::GameSlice::FailSlice(v4, v3);
    }
  }
}

// File Line: 3502
// RVA: 0x4B0680
bool __fastcall UFG::ProgressionTracker::LoadedProgression(UFG::ProgressionTracker *this, int dPoint, char *pDeserializeBuffer, unsigned int bufferSize, bool resetProgression)
{
  unsigned int v5; // esi
  char *v6; // r14
  int v7; // er15
  UFG::ProgressionTracker *v8; // rbx
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseTreeRB *j; // rax
  UFG::GameStatTracker *v11; // rdi
  UFG::GameStatTracker *v12; // rcx
  __int64 v13; // rsi
  unsigned int v14; // eax
  char *v15; // rbx
  char *v16; // rax
  bool result; // al
  UFG::qSymbolUC v18; // [rsp+50h] [rbp+8h]

  v5 = bufferSize;
  v6 = pDeserializeBuffer;
  v7 = dPoint;
  v8 = this;
  if ( resetProgression )
  {
    UFG::ProgressionTracker::ResetProgression(this, RestoreType_Safehouse, uidGameStateRestoreCheckpoint_9, 1);
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v8->mContainerGameSlices);
          i;
          i = UFG::qBaseTreeRB::GetNext(&v8->mContainerGameSlices.mTree, &i->mRoot) )
    {
      *(_QWORD *)&i[3].mCount = 0i64;
    }
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v8->mGameSlices);
          j;
          j = UFG::qBaseTreeRB::GetNext(&v8->mGameSlices.mTree, &j->mRoot) )
    {
      *(_QWORD *)&j[3].mCount = 0i64;
    }
  }
  v11 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  v12 = &sGameStatTracker;
  if ( UFG::GameStatTracker::mspInstance )
    v12 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v12;
  v13 = (unsigned __int8)UFG::GameStatTracker::ResetFromLoadedBuffer(v12, v7, v6, v5);
  if ( resetProgression )
    v8->mpLastCheckpoint = (UFG::GameSlice *)UFG::ProgressionTracker::GetStartupSlice(v8);
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v11 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v11;
  v14 = v11->mpSnapshots[0]->mIDs[25].mValue.mUID;
  if ( v14 == -1 )
    v14 = gDefaultFlowId.mUID;
  v18.mUID = v14;
  if ( v14 == v8->mActiveFlowId.mUID )
  {
    UFG::ProgressionTracker::UpdatePermanentDLC(v8);
    result = v13;
  }
  else
  {
    v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v8->mActiveFlowId);
    v16 = UFG::qSymbol::as_cstr_dbg(&v18);
    UFG::qPrintf(
      "[ProgressionTracker::LoadedProgression] - Returning false because the save game is loaded from the wrong flow (%s)"
      " - Active flow (%s)\n",
      v16,
      v15);
    result = 0;
  }
  return result;
}

// File Line: 3557
// RVA: 0x4C7980
void __fastcall UFG::ProgressionTracker::UpdatePermanentDLC(UFG::ProgressionTracker *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rdx
  UFG::GameStatTracker *v3; // rsi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::MapFloat *v5; // rdi
  unsigned int i; // ebx
  unsigned int v7; // ecx
  bool v8; // cf
  UFG::qSymbol *v9; // rdx
  unsigned int v10; // eax
  UFG::PersistentData::MapBool *v11; // r10
  __int64 v12; // rdx
  unsigned int v13; // er8
  bool v14; // al
  __int64 v15; // rdx
  unsigned int v16; // er8
  unsigned int v17; // er8
  __int64 v18; // rcx
  UFG::PersistentData::KeyValue *v19; // rdx
  unsigned int v20; // edx
  UFG::GameStatTracker *v21; // r8
  UFG::GameStatTracker *v22; // rax
  __int64 v23; // rax
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+28h] [rbp-30h]
  UFG::qSymbol name; // [rsp+68h] [rbp+10h]

  v1 = _S12_6;
  if ( !(_S12_6 & 1) )
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
  if ( !(v1 & 1) )
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
  v5 = result.mList;
  for ( i = result.mIndex; ; ++i )
  {
    v7 = v5->mValues.size;
    if ( v5->mValues.size )
    {
      if ( v7 - 1 > 1 )
        return;
      v8 = i < v5[1].mValues.size;
    }
    else
    {
      v8 = i < LODWORD(v5->mValues.p);
    }
    if ( !v8 )
      break;
    if ( v7 )
    {
      if ( v7 - 1 > 1 )
        v9 = &UFG::gNullQSymbol;
      else
        v9 = (UFG::qSymbol *)((char *)v5[1].mValues.p + 4 * i);
    }
    else
    {
      v9 = (UFG::qSymbol *)(*(_QWORD *)&v5->mPersistentDataType + 8i64 * i);
    }
    v10 = v9->mUID;
    name.mUID = v9->mUID;
    v11 = v3->mpSnapshots[0]->mpMapBools[61];
    if ( v11->mKeepType )
    {
      if ( v11->mKeepType == 1 )
      {
        v15 = 0i64;
        v16 = v11->mNames.size;
        if ( v16 )
        {
          while ( v10 != v11->mNames.p[v15].mUID )
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
        v14 = (_DWORD)v15 != -1;
LABEL_40:
        if ( v14 )
          continue;
        goto LABEL_41;
      }
      v12 = (unsigned int)(v11->mKeepType - 2);
      if ( v11->mKeepType == 2 )
      {
        v13 = v11->mNames.size;
        if ( v13 )
        {
          while ( v10 != v11->mNames.p[v12].mUID )
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
        v14 = (_DWORD)v12 == -1;
        goto LABEL_40;
      }
    }
    else
    {
      v17 = v11->mValues.size;
      v18 = 0i64;
      if ( v17 )
      {
        v19 = v11->mValues.p;
        while ( v19->mKey.mUID != v10 )
        {
          v18 = (unsigned int)(v18 + 1);
          ++v19;
          if ( (unsigned int)v18 >= v17 )
            goto LABEL_41;
        }
        if ( (_DWORD)v18 != -1 )
        {
          v14 = v11->mValues.p[v18].mBoolValue;
          goto LABEL_40;
        }
      }
    }
LABEL_41:
    if ( !(*((_BYTE *)v3 + 6216) & 1) )
    {
      UFG::PersistentData::MapBool::SetStatus(v11, &name, 1);
      if ( UFG::GameStatAction::PostStat::sIsEnabled )
      {
        v20 = _S12_6;
        if ( !(_S12_6 & 1) )
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
        if ( !(v20 & 1) )
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
        v23 = v22->mpSnapshots[0]->mpMapBools[61]->mKeepType;
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
  unsigned int v2; // ebx
  UFG::qBaseTreeRB *v3; // rsi
  UFG::qBaseTreeRB *v4; // rdi
  UFG::ProgressionTracker *v5; // rax
  UFG::ProgressionTracker *v6; // rbx
  unsigned int v7; // edx
  UFG::qBaseTreeRB *result; // rax
  unsigned int v9; // edx

  v1 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v1 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v1;
  v2 = v1->mpSnapshots[0]->mIDs[28].mValue.mUID;
  v3 = 0i64;
  if ( v2 == -1 )
    goto LABEL_18;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( v2 )
  {
    v4 = UFG::qBaseTreeRB::Get(&stru_14240A100, v2);
    if ( !v4 )
      v4 = UFG::qBaseTreeRB::Get(&stru_14240A148, v2);
  }
  else
  {
    v4 = 0i64;
  }
  if ( !v4 || HIDWORD(v4[2].mNULL.mChild[0]) == -1 )
    goto LABEL_18;
  v5 = UFG::ProgressionTracker::Instance();
  v6 = v5;
  v7 = HIDWORD(v4[2].mNULL.mChild[0]);
  if ( !v7 || (result = UFG::qBaseTreeRB::Get(&v5->mGameSlices.mTree, v7)) == 0i64 )
  {
    v9 = HIDWORD(v4[2].mNULL.mChild[0]);
    if ( v9 )
      v3 = UFG::qBaseTreeRB::Get(&v6->mContainerGameSlices.mTree, v9);
LABEL_18:
    result = v3;
  }
  return result;
}

// File Line: 3596
// RVA: 0x4A60E0
char *__fastcall UFG::ProgressionTracker::GetSaveGameName(UFG::ProgressionTracker *this)
{
  UFG::GameSlice *v1; // rdi
  UFG::qSharedStringData *v2; // rbx
  UFG::GameStatTracker *v4; // rbx
  unsigned int v5; // ebx
  UFG::qBaseNodeRB *v6; // rsi
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qSharedStringData *v8; // rbx

  v1 = this->mpLastCheckpoint;
  if ( v1 )
  {
    v2 = (UFG::qSharedStringData *)(v1->mSaveGameNameOverride.mText - 48);
    if ( v2 != UFG::qSharedStringData::GetEmptyString() )
      return v1->mSaveGameNameOverride.mText;
  }
  v4 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
  {
    _S12_6 |= 1u;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
  }
  if ( UFG::GameStatTracker::mspInstance )
    v4 = UFG::GameStatTracker::mspInstance;
  UFG::GameStatTracker::mspInstance = v4;
  v5 = v4->mpSnapshots[0]->mIDs[28].mValue.mUID;
  v6 = 0i64;
  if ( v5 != -1 )
  {
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( v5 )
    {
      v7 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5);
      if ( !v7 )
        v7 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5);
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
    {
      v8 = (UFG::qSharedStringData *)&v7[2].mRoot.mChild[1][-2].mChild[1];
      if ( v8 == UFG::qSharedStringData::GetEmptyString() )
        v6 = v7->mNULL.mChild[0];
      else
        v6 = v7[2].mRoot.mChild[1];
    }
  }
  return (char *)v6;
}

// File Line: 3630
// RVA: 0x4B7060
void __fastcall UFG::ProgressionTracker::ResetProgression(UFG::ProgressionTracker *this, UFG::ProgressionTracker::RestoreType restoreType, unsigned int newGameState, bool useCurrentLocation)
{
  UFG::ProgressionTracker *v4; // rsi
  bool v5; // bp
  unsigned int v6; // er14
  UFG::ProgressionTracker::RestoreType v7; // er15
  UFG::GameSlice *i; // rbx
  UFG::GameSlice *j; // rbx
  Render::SkinningCacheNode *v10; // rax
  Illusion::Buffer **v11; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v12; // rdx

  v4 = this;
  v5 = useCurrentLocation;
  v6 = newGameState;
  v7 = restoreType;
  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll((qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo> *)&this->mLayerOwnership.mCount);
  v4->mpLastCheckpoint = 0i64;
  for ( i = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v4->mContainerGameSlices);
        i;
        i = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v4->mContainerGameSlices.mTree, &i->mNode) )
  {
    UFG::GameSlice::ForceLock(i, 1);
  }
  for ( j = (UFG::GameSlice *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v4->mGameSlices);
        j;
        j = (UFG::GameSlice *)UFG::qBaseTreeRB::GetNext(&v4->mGameSlices.mTree, &j->mNode) )
  {
    UFG::GameSlice::ForceLock(j, 1);
  }
  UFG::ObjectiveTracker::OnRestore(&v4->mObjectiveTracker);
  if ( v4->mPDATriggerTracker.mPDATriggers.mTree.mCount )
  {
    while ( 1 )
    {
      v10 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v4->mPDATriggerTracker);
      if ( !v10 )
        break;
      v11 = &v10[-1].mCachedBufferPtr;
      if ( v10 == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      v12 = &v10->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v4->mPDATriggerTracker,
        v12);
      if ( v11 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v11)->mNode.mParent)(v11, 1i64);
      if ( !v4->mPDATriggerTracker.mPDATriggers.mTree.mCount )
        goto LABEL_14;
    }
    v11 = 0i64;
LABEL_10:
    v12 = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  v4->mState = 6;
  v4->mpActiveMaster = 0i64;
  *(_WORD *)&v4->mDirty = 0;
  v4->mLastUpdateTimestamp = 0i64;
  v4->mContainerCompletedTimestamp = 0i64;
  UFG::ProgressionTracker::SetRestoreType(v4, v7, v5);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, v6);
}

// File Line: 3666
// RVA: 0x4B0850
void __fastcall UFG::ProgressionTracker::LockAllRunningGameSlicesForSoftReset(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rsi
  UFG::qSymbol *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseTreeRB *j; // rbx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = UFG::qSymbol::create_from_string(&result, "LivingWorld");
  if ( v2->mUID && (v3 = UFG::qBaseTreeRB::Get(&v1->mGameSlices.mTree, v2->mUID)) != 0i64
    || (v2->mUID ? (v3 = UFG::qBaseTreeRB::Get(&v1->mContainerGameSlices.mTree, v2->mUID)) : (v3 = 0i64), v3) )
  {
    UFG::GameSlice::ForceLock((UFG::GameSlice *)v3, 0);
  }
  qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo>::FreeAll((qSetBase<UFG::ProgressionTracker::LayerOwnershipInfo> *)&v1->mLayerOwnership.mCount);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mContainerGameSlices);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v1->mContainerGameSlices.mTree, &i->mRoot) )
  {
    if ( (unsigned int)(LODWORD(i[3].mNULL.mChild[1]) - 1) <= 6 )
      UFG::GameSlice::ForceLock((UFG::GameSlice *)i, 0);
  }
  for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mGameSlices);
        j;
        j = UFG::qBaseTreeRB::GetNext(&v1->mGameSlices.mTree, &j->mRoot) )
  {
    if ( (unsigned int)(LODWORD(j[3].mNULL.mChild[1]) - 1) <= 6 )
      UFG::GameSlice::ForceLock((UFG::GameSlice *)j, 0);
  }
}

// File Line: 3695
// RVA: 0x4B7660
void __fastcall UFG::ProgressionTracker::RestoreCheckpoint(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rbx

  v1 = this;
  UFG::UpdatePlayerDismountLocation((UFG *)this);
  UFG::ProgressionTracker::RestoreCheckpointInternal(v1);
  UFG::ProgressionTracker::DiscardSnapshot(v1);
}

// File Line: 3708
// RVA: 0x4B7690
void __fastcall UFG::ProgressionTracker::RestoreCheckpointInternal(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rbx
  UFG::GameSlice *v2; // rcx
  unsigned int v3; // edx

  v1 = this;
  if ( (unsigned int)(this->mState - 6) > 3 )
  {
    if ( this->mpLastCheckpoint )
    {
      UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
      UFG::GameSlice::ForceLock(v1->mpLastCheckpoint, 0);
    }
    v2 = v1->mpActiveMaster;
    if ( v2 )
      UFG::GameSlice::ForceLock(v2, 0);
    UFG::ProgressionTracker::LockAllRunningGameSlicesForSoftReset(v1);
    UFG::ObjectiveTracker::OnRestore(&v1->mObjectiveTracker);
    UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&v1->mPDATriggerTracker);
    v3 = uidGameStateRestoreCheckpoint_9;
    v1->mState = 6;
    v1->mpActiveMaster = 0i64;
    *(_WORD *)&v1->mDirty = 0;
    v1->mLastUpdateTimestamp = 0i64;
    v1->mContainerCompletedTimestamp = 0i64;
    UFG::FlowController::RequestSetNewState(&UFG::gFlowController, v3);
  }
}

// File Line: 3749
// RVA: 0x4968F0
void __fastcall UFG::ProgressionTracker::CancelMission(UFG::ProgressionTracker *this, UFG::GameSlice *pGameSlice, bool resetScene, UFG::ProgressionTracker::RestoreType restoreType)
{
  UFG::ProgressionTracker::RestoreType v4; // esi
  UFG::GameSlice *v5; // rbx
  UFG::ProgressionTracker *v6; // rdi
  UFG::GameStatTracker *v7; // rbx
  signed int v8; // eax
  UFG::GameSlice *v9; // rax
  const char *v10; // r8

  v4 = restoreType;
  v5 = pGameSlice;
  v6 = this;
  if ( resetScene )
  {
    if ( this->mActiveMasterMode == 2 )
    {
      UFG::ProgressionTracker::ExitChallenge(this, 0);
    }
    else
    {
      v7 = UFG::GameStatTracker::Instance();
      UFG::ProgressionTracker::ResetProgression(v6, v4, uidGameStateRestoreCheckpoint_9, v4 != 7);
      UFG::GameStatTracker::CommitPermanentDataTo(v7, Snapshot_OpenWorld);
      UFG::GameSnapshot::Clone(v7->mpSnapshots[0], v7->mpSnapshots[1]);
    }
  }
  else if ( this->mState != 11 )
  {
    this->mpLastFailed = pGameSlice;
    if ( pGameSlice )
    {
      while ( v5->mpParent )
        v5 = v5->mpParent;
      UFG::GameSlice::ForceLock(v5, 0);
      v8 = 1;
      if ( v5->mState == 4 )
        v8 = 3;
      v5->mCompletionStatus = v8;
      v5->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    }
    v9 = v6->mpActiveMaster;
    if ( v5 == v9 )
    {
      UFG::GameStatAction::MissionScoring::FinishedTracking();
      v6->mpActiveMaster = 0i64;
      v6->mpLastCheckpoint = 0i64;
      UFG::ObjectiveTracker::OnFail(&v6->mObjectiveTracker);
      v6->mState = 11;
    }
    else
    {
      if ( v9 )
        v10 = v9->mName.mText;
      else
        v10 = "*NoActiveMaster*";
      UFG::qPrintf("Warning: (%s) called CancelMission when (%s) is running\n", v5->mName.mText, v10);
    }
  }
}

// File Line: 3822
// RVA: 0x49DC00
void __fastcall UFG::ProgressionTracker::EnableGameSliceTODWait(UFG::ProgressionTracker *this, UFG::GameSlice *slice, UFG::ProgressionTriggerComponent *trigger)
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
      0,
      ALIGN_RIGHT,
      BUTTON2_BUTTON,
      "$ACTIVATE_TIME_RESTRICTED_SLICE",
      0,
      &customWorldMapCaption,
      0,
      &customWorldMapCaption,
      0,
      &customWorldMapCaption,
      0,
      &customWorldMapCaption,
      0,
      &customWorldMapCaption);
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
  UFG::TimeOfDayManager *v1; // rax
  float v2; // xmm6_4
  float v3; // xmm8_4
  float v4; // xmm7_4
  unsigned int v5; // ecx
  UFG::GameStatTracker *v6; // rbx
  UFG::GameStatTracker *v7; // rdx
  UFG::GameStatTracker *v8; // rax

  v1 = UFG::TimeOfDayManager::GetInstance();
  v2 = v1->m_WeatherState;
  v3 = v1->m_WeatherSurfaceWetness;
  v4 = v1->m_SecondsSinceMidnight;
  v5 = _S12_6;
  v6 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  if ( !(*((_BYTE *)v7 + 6216) & 1) )
  {
    v7->mpSnapshots[0]->mFloats[129].mValue = v2;
    v7 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v5 & 1) )
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
  if ( !(*((_BYTE *)v8 + 6216) & 1) )
  {
    v8->mpSnapshots[0]->mFloats[130].mValue = v3;
    v8 = UFG::GameStatTracker::mspInstance;
  }
  if ( !(v5 & 1) )
  {
    _S12_6 = v5 | 1;
    UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
    atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
    v8 = UFG::GameStatTracker::mspInstance;
  }
  if ( v8 )
    v6 = v8;
  UFG::GameStatTracker::mspInstance = v6;
  if ( !(*((_BYTE *)v6 + 6216) & 1) )
    v6->mpSnapshots[0]->mFloats[131].mValue = v4;
}

// File Line: 3856
// RVA: 0x4AEE80
void __fastcall UFG::ProgressionTracker::LoadSnapshotWeather(UFG::ProgressionTracker *this)
{
  unsigned int v1; // ecx
  UFG::GameStatTracker *v2; // rbx
  UFG::GameStatTracker *v3; // rdx
  float v4; // xmm6_4
  UFG::GameStatTracker *v5; // r8
  float v6; // xmm8_4
  float v7; // xmm7_4
  UFG::TimeOfDayManager *v8; // rax
  float v9; // xmm0_4

  v1 = _S12_6;
  v2 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
  v4 = v3->mpSnapshots[0]->mFloats[129].mValue;
  if ( !(v1 & 1) )
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
  if ( !(v1 & 1) )
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
  v8 = UFG::TimeOfDayManager::GetInstance();
  if ( v4 <= 0.0 )
  {
    v4 = 0.0;
  }
  else
  {
    v9 = FLOAT_2_0;
    if ( v4 >= 2.0 )
      goto LABEL_18;
  }
  v9 = v4;
LABEL_18:
  v8->m_WeatherState = v9;
  v8->m_WeatherTarget = v9;
  v8->m_NextWeatherTarget = v9;
  v8->m_WeatherSurfaceWetness = v6;
  UFG::TimeOfDayManager::SetTime(v8, v7, 0);
}

// File Line: 3878
// RVA: 0x4C8A60
bool __fastcall UFG::ProgressionTracker::UpdateTimeShift(UFG::ProgressionTracker *this, float realTimeDelta)
{
  UFG::ProgressionTracker *v2; // rbx
  UFG::GameSlice *v3; // rcx
  float v4; // xmm1_4
  UFG::ProgressionTracker::TimeShiftState v5; // eax
  bool result; // al
  float v7; // xmm6_4
  UFG::TimeOfDayManager *v8; // rax
  UFG::ProgressionTriggerComponent *v9; // rcx
  unsigned int v10; // ebx
  UFG::UIHKHelpBarWidget *v11; // rax

  v2 = this;
  v3 = this->mTimeShiftSlice;
  if ( !v3 || !v3->mIsTODRestricted )
    return 0;
  v4 = realTimeDelta + v2->mTimeShiftTimer;
  v5 = v2->mTimeShiftState;
  v2->mTimeShiftTimer = v4;
  if ( v5 == 5 )
  {
    UFG::UIHK_NISOverlay::ShowCurtains(1.0, 1);
    result = 1;
    *(_QWORD *)&v2->mTimeShiftState = 6i64;
    return result;
  }
  if ( v5 == 6 )
  {
    if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
      v2->mTimeShiftState = 3;
    return 1;
  }
  if ( v5 != 3 )
  {
    if ( v5 == 4 )
    {
      if ( v4 < 2.0 )
        UFG::SyncLoadCurrentLocation((UFG *)v3);
      else
        v2->mTimeShiftState = 1;
      return 1;
    }
    if ( v5 == 1 )
    {
      UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
      result = 0;
      v2->mTimeShiftState = 0;
      v2->mTimeShiftSlice = 0i64;
      v2->mTimeShiftTrigger = 0i64;
      return result;
    }
    return 0;
  }
  if ( !UFG::GameSlice::IsAllowedAtThisTimeOfDay(v3) )
  {
    v7 = v2->mTimeShiftSlice->mTODActive;
    v8 = UFG::TimeOfDayManager::GetInstance();
    UFG::TimeOfDayManager::SetTime(v8, v7, 0);
  }
  v9 = v2->mTimeShiftTrigger;
  *(_QWORD *)&v2->mTimeShiftState = 4i64;
  UFG::ProgressionTriggerComponent::ForceOnEnter(v9);
  v10 = UFG::qStringHash32("ProgressionTracker", 0xFFFFFFFF);
  v11 = UFG::UIHKHelpBarWidget::Get();
  UFG::UIHKHelpBarWidget::Hide(v11, v10);
  return 1;
}

// File Line: 3947
// RVA: 0x4C8FE0
void __fastcall UFG::ProgressionTracker::WaitForStreamer(UFG::ProgressionTracker *this)
{
  UFG::ProgressionTracker *v1; // rdi
  char v2; // bp
  char v3; // si
  UFG::PartDatabase *v4; // rax
  UFG::PartDatabase *v5; // rax
  bool v6; // bl
  bool v7; // al

  v1 = this;
  v2 = UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3u);
  v3 = UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 7u);
  v4 = (UFG::PartDatabase *)UFG::ObjectResourceManager::Instance();
  v6 = 0;
  if ( !UFG::ObjectResourceManager::HasQueue(v4) )
  {
    v5 = UFG::PartDatabase::Instance();
    if ( !UFG::ObjectResourceManager::HasQueue(v5) )
      v6 = 1;
  }
  v7 = UFG::PedSpawnManager::SpawnsQueued();
  if ( !v2 || !v3 || v6 || v7 || UFG::StoreMeshHelper::sSwapQueued )
  {
    v1->mbPendingSceneSettingsValid = 0;
    UFG::SceneSettings::Reset(&v1->mPendingSceneSettingsLocal);
    UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
  }
}

// File Line: 3963
// RVA: 0x494C90
void __fastcall UFG::ProgressionTracker::ApplySceneSettings(UFG::ProgressionTracker *this, UFG::SceneSettings *settings)
{
  this->mbPendingSceneSettingsValid = 1;
  UFG::SceneSettings::operator=(&this->mPendingSceneSettingsLocal, settings);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
}

// File Line: 3972
// RVA: 0x494CC0
void __fastcall UFG::ProgressionTracker::ApplySceneSettingsCached(UFG::ProgressionTracker *this, UFG::SceneSettings *settings)
{
  UFG::ProgressionTracker *v2; // rdi

  v2 = this;
  UFG::SceneSettings::operator=(&this->mPendingSceneSettingsCache, settings);
  v2->mbPendingSceneSettingsValid = 1;
  UFG::SceneSettings::operator=(&v2->mPendingSceneSettingsLocal, &v2->mPendingSceneSettingsCache);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateChangeLocation_9);
}

// File Line: 3979
// RVA: 0x494C10
void __fastcall UFG::ProgressionTracker::ApplySceneSettings(UFG::ProgressionTracker *this, UFG::qVector3 *position)
{
  UFG::SceneSettings *v2; // rdi
  UFG::ProgressionTracker *v3; // rsi
  UFG::qVector3 *v4; // rbx
  float v5; // eax
  float v6; // xmm1_4

  v2 = &this->mPendingSceneSettingsCache;
  v3 = this;
  v4 = position;
  UFG::SceneSettings::Reset(&this->mPendingSceneSettingsCache);
  v2->mHasTeleportPositionInternal = 1;
  v5 = v4->x;
  v6 = v4->z;
  v2->mTeleportPositionInternal.y = v4->y;
  v2->mTeleportPositionInternal.z = v6;
  v2->mTeleportPositionInternal.x = v5;
  v3->mbPendingSceneSettingsValid = 1;
  UFG::SceneSettings::operator=(&v3->mPendingSceneSettingsLocal, v2);
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
  unsigned int v5; // edi
  UFG::PersistentData::MapBool *v6; // r8
  unsigned int v7; // ebp
  UFG::PersistentData::MapBool *v8; // rbx
  unsigned int v9; // esi
  UFG::PersistentData::MapBool *v10; // r14
  unsigned int v11; // er11
  UFG::PersistentData::MapBool *v12; // r15
  unsigned int v13; // er10
  UFG::PersistentData::MapBool *v14; // r12
  unsigned int v15; // er9
  UFG::PersistentData::MapBool *v16; // r13
  unsigned int v17; // eax
  unsigned int v18; // esi
  unsigned int v19; // er9
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v20; // rax
  __int64 v21; // rdx
  unsigned int v22; // edi
  __int64 v23; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v24; // rax
  unsigned int v25; // er11
  __int64 v26; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v27; // rax
  unsigned int v28; // er10
  __int64 v29; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v30; // rax
  unsigned int v31; // er9
  __int64 v32; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v33; // rax
  unsigned int v34; // er8
  __int64 v35; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v36; // rax
  __int64 v37; // rdx
  $CCFB32CF948EEB04FF452B3FEB4ECF53 *v38; // rax
  float result; // xmm0_4
  int v40; // [rsp+78h] [rbp+10h]
  UFG::GameStatTracker *v41; // [rsp+80h] [rbp+18h]
  float *v42; // [rsp+88h] [rbp+20h]

  v1 = &sGameStatTracker;
  if ( !(_S12_6 & 1) )
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
      v5 = 0;
    else
      v5 = v3->mNames.size;
  }
  else
  {
    v5 = v3->mValues.size;
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
  v40 = v5 + v7 + v9 + v11 + v13 + v15 + v17;
  if ( v3->mKeepType == 2 )
  {
    v18 = 0;
  }
  else if ( v3->mKeepType == 1 )
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
        if ( LOBYTE(v20->mFloatValue) )
          ++v18;
        v20 += 2;
        --v21;
      }
      while ( v21 );
    }
  }
  if ( v6->mKeepType == 2 )
  {
    v22 = 0;
  }
  else if ( v6->mKeepType == 1 )
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
        if ( LOBYTE(v24->mFloatValue) )
          ++v22;
        v24 += 2;
        --v23;
      }
      while ( v23 );
    }
  }
  if ( v8->mKeepType == 2 )
  {
    v25 = 0;
  }
  else if ( v8->mKeepType == 1 )
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
        if ( LOBYTE(v27->mFloatValue) )
          ++v25;
        v27 += 2;
        --v26;
      }
      while ( v26 );
    }
  }
  if ( v10->mKeepType == 2 )
  {
    v28 = 0;
  }
  else if ( v10->mKeepType == 1 )
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
        if ( LOBYTE(v30->mFloatValue) )
          ++v28;
        v30 += 2;
        --v29;
      }
      while ( v29 );
    }
  }
  if ( v12->mKeepType == 2 )
  {
    v31 = 0;
  }
  else if ( v12->mKeepType == 1 )
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
        if ( LOBYTE(v33->mFloatValue) )
          ++v31;
        v33 += 2;
        --v32;
      }
      while ( v32 );
    }
  }
  if ( v14->mKeepType == 2 )
  {
    v34 = 0;
  }
  else if ( v14->mKeepType == 1 )
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
        if ( LOBYTE(v36->mFloatValue) )
          ++v34;
        v36 += 2;
        --v35;
      }
      while ( v35 );
    }
  }
  if ( v16->mKeepType != 2 )
  {
    if ( v16->mKeepType == 1 )
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
          if ( LOBYTE(v38->mFloatValue) )
            ++v4;
          v38 += 2;
          --v37;
        }
        while ( v37 );
      }
    }
  }
  result = (float)((float)(signed int)(v18 + v22 + v25 + v28 + v31 + v4 + v34) * 100.0) / (float)v40;
  if ( !(*((_BYTE *)v41 + 6216) & 1) )
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymbolRunTest__);
}

// File Line: 4018
// RVA: 0x49A0B0
void __fastcall UFG::ProgressionTracker::DEBUG_LaunchTestScenarioIfAvailable(UFG::ProgressionTracker *this)
{
  ASymbol *v1; // rbx
  SSClass *v2; // rax
  SSInstance *v3; // rsi
  SSInstance *args_pp; // [rsp+50h] [rbp+8h]

  v1 = (ASymbol *)this;
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
        args_pp = SSSymbol::as_instance(v1 + 1403);
        SSInstance::coroutine_call(v3, v1 + 1402, &args_pp, args_pp != 0i64, 1, 0.0, 0i64, 0i64);
      }
    }
    v1[1402].i_uid = UFG::gNullQSymbol.mUID;
    v1[1403].i_uid = UFG::gNullQSymbol.mUID;
  }
}

