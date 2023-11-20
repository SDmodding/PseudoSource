// File Line: 37
// RVA: 0x1567600
__int64 UFG::_dynamic_initializer_for__HASH_HUD_COMPONENT__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("hud_component", 0xFFFFFFFF);
  HASH_HUD_COMPONENT = result;
  return result;
}

// File Line: 38
// RVA: 0x1572460
__int64 UFG::_dynamic_initializer_for__symbol_List__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("List", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symbol_List, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symbol_List__);
}

// File Line: 39
// RVA: 0x1572420
__int64 UFG::_dynamic_initializer_for__symbol_CaseName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CaseName", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symbol_CaseName, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symbol_CaseName__);
}

// File Line: 47
// RVA: 0x5C4670
void __fastcall UFG::UIHKPlayerObjective::UIHKPlayerObjective(UFG::UIHKPlayerObjective *this)
{
  UFG::UIHKPlayerObjective *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qString::qString(&this->titleCaption);
  v1->minimapBlips.p = 0i64;
  *(_QWORD *)&v1->minimapBlips.size = 0i64;
  UFG::qString::qString(&v1->gameSliceName);
  v2 = &v1->gpsTarget;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->gpsTarget.m_pPointer = 0i64;
  v1->useFixedPos = 0;
  UFG::qString::qString(&v1->alternateCaption);
  v1->mObjective = 0i64;
}

// File Line: 79
// RVA: 0x5E8490
UFG::qReflectObject *__fastcall UFG::UIHKPlayerObjective::GetObjective(Render::SimpleDrawableComponent *this)
{
  return this->mModelDataHandle.mData;
}

// File Line: 103
// RVA: 0x5E9440
UFG::SimObject *__fastcall UFG::UIHKPlayerObjective::GetSimObject(UFG::UIHKPlayerObjective *this)
{
  UFG::Objective *v1; // rcx
  UFG::qSymbol *v2; // rcx
  Render::SkinningCacheNode *v3; // rax
  char v4; // al
  UFG::SimObject *v5; // rcx
  UFG::SimObject *simObj; // [rsp+30h] [rbp+8h]

  v1 = this->mObjective;
  if ( v1 )
  {
    v3 = UFG::Objective::GetFirstIndicator(v1);
    v2 = &UFG::gNullQSymbol;
    if ( v3 )
      v2 = (UFG::qSymbol *)&v3[1];
  }
  else
  {
    v2 = &UFG::gNullQSymbol;
  }
  v4 = UFG::FindTargetBySymbol(v2, &simObj);
  v5 = 0i64;
  if ( v4 )
    v5 = simObj;
  return v5;
}

// File Line: 138
// RVA: 0x5E7930
UFG::Objective *__fastcall UFG::UIHKPlayerObjective::GetDisplayPriority(UFG::UIHKPlayerObjective *this)
{
  UFG::Objective *result; // rax

  result = this->mObjective;
  if ( result )
    result = (UFG::Objective *)result->mDisplayPriority;
  return result;
}

// File Line: 157
// RVA: 0x5C46F0
void __fastcall UFG::UIHKPlayerObjectiveManager::UIHKPlayerObjectiveManager(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjectiveManager *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIHKPlayerObjectiveManagerVtbl *)&UFG::UIHKPlayerObjectiveManager::`vftable';
  this->m_objectives.p = 0i64;
  *(_QWORD *)&this->m_objectives.size = 0i64;
  this->m_currentObjective = -1;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_knownBlips.mTree.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->m_pendingBlips.mTree.mTree);
  v1->mFlashObjectiveFlag = 0;
  UFG::UIHKPlayerObjective::UIHKPlayerObjective(&v1->mTempObjective);
  *(_WORD *)&v1->mTempObjectiveSelected = 0;
  v1->mWorldMapObjective_IsSelected = 0;
  UFG::UIHKPlayerObjective::UIHKPlayerObjective(&v1->mWorldMapObjective);
  UFG::UIHKPlayerObjectiveManager::mInstance = v1;
}

// File Line: 164
// RVA: 0x5C9C40
void __fastcall UFG::UIHKPlayerObjectiveManager::~UIHKPlayerObjectiveManager(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjectiveManager *v1; // rdi
  UFG::UIHKPlayerObjective **v2; // rcx

  v1 = this;
  this->vfptr = (UFG::UIHKPlayerObjectiveManagerVtbl *)&UFG::UIHKPlayerObjectiveManager::`vftable';
  UFG::UIHKPlayerObjectiveManager::mInstance = 0i64;
  UFG::UIHKPlayerObjective::~UIHKPlayerObjective(&this->mWorldMapObjective);
  UFG::UIHKPlayerObjective::~UIHKPlayerObjective(&v1->mTempObjective);
  UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll(&v1->m_pendingBlips.mTree);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->m_pendingBlips);
  UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll(&v1->m_knownBlips.mTree);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->m_knownBlips);
  v2 = v1->m_objectives.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_objectives.p = 0i64;
  *(_QWORD *)&v1->m_objectives.size = 0i64;
}

// File Line: 199
// RVA: 0x5D5290
void __fastcall UFG::UIHKPlayerObjectiveManager::Clear(UFG::UIHKPlayerObjectiveManager *this)
{
  __int64 v1; // rbx
  UFG::UIHKPlayerObjectiveManager *v2; // rdi
  UFG::UIHKPlayerObjective **v3; // rax
  UFG::UIHKPlayerObjective *v4; // rsi
  UFG::UIHKPlayerObjective **v5; // rcx

  v1 = 0i64;
  v2 = this;
  if ( this->m_objectives.size )
  {
    do
    {
      v3 = v2->m_objectives.p;
      v4 = v3[v1];
      if ( v4 )
      {
        UFG::UIHKPlayerObjective::~UIHKPlayerObjective(v3[v1]);
        operator delete[](v4);
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_objectives.size );
  }
  v5 = v2->m_objectives.p;
  if ( v5 )
    operator delete[](v5);
  v2->m_objectives.p = 0i64;
  *(_QWORD *)&v2->m_objectives.size = 0i64;
  v2->m_currentObjective = 0;
  v2->mTempObjectiveSelected = 0;
}

// File Line: 297
// RVA: 0x5D5B10
void __fastcall UFG::UIHKPlayerObjectiveManager::ClearWorldMapDest(UFG::UIHKPlayerObjectiveManager *this)
{
  *(_WORD *)&this->mWorldMapObjective_IsSet = 0;
}

// File Line: 304
// RVA: 0x61B910
void __fastcall UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjectiveManager *v1; // r13
  signed __int64 v2; // rax
  unsigned int v3; // ecx
  __int64 v4; // rcx
  const char *v5; // rdx
  UFG::UIHKPlayerObjective *v6; // r15
  unsigned int v7; // ebx
  UFG::UIHKPlayerObjective **v8; // rax
  UFG::UIHKPlayerObjective *v9; // rdi
  UFG::UIHKPlayerObjective **v10; // rcx
  UFG::ProgressionTracker *v11; // rax
  UFG::ObjectiveTracker *v12; // r14
  UFG::qSymbol *v13; // rax
  UFG::qPropertySet *v14; // r12
  UFG::Objective *v15; // r14
  UFG::Objective::Status v16; // eax
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rdi
  UFG::GameSlice *v20; // rsi
  UFG::qString *v21; // rax
  UFG::qPropertyList *v22; // rbx
  UFG::qSymbol *v23; // rax
  unsigned int v24; // eax
  char *v25; // rax
  UFG::qPropertySet *v26; // rcx
  char *v27; // rdx
  UFG::GameSlice *v28; // rbx
  UFG::qString *v29; // rax
  UFG::qString *v30; // rax
  UFG::qPropertyList *v31; // rbx
  UFG::qSymbol *v32; // rax
  unsigned int v33; // eax
  char *v34; // rax
  UFG::qSharedStringData *v35; // rbx
  UFG::qSymbol *v36; // rax
  UFG::qSymbol *v37; // rbx
  UFG::TSActor *v38; // rax
  UFG::SimObject *v39; // rsi
  UFG::qBaseTreeRB *v40; // rax
  UFG::qMemoryPool *v41; // rax
  UFG::allocator::free_link *v42; // rax
  UFG::SimComponent *v43; // rax
  UFG::SimComponent *v44; // rbx
  unsigned __int16 v45; // cx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v48; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v49; // rax
  void *v50; // rcx
  UFG::ObjectiveIndicator *v51; // r14
  UFG::qBaseTreeRB *v52; // rsi
  UFG::allocator::free_link *v53; // rax
  signed __int64 v54; // rbx
  _QWORD *v55; // rax
  __int64 *v56; // rbx
  __int64 v57; // rdx
  __int64 v58; // rcx
  _QWORD *v59; // rax
  __int64 v60; // rax
  UFG::qBaseNodeRB **v61; // rdx
  __int64 v62; // r8
  UFG::qBaseNodeRB *v63; // rcx
  UFG::qBaseNodeRB *v64; // rax
  UFG::qBaseNodeRB *v65; // rax
  __int64 v66; // r12
  unsigned int v67; // esi
  unsigned int v68; // ebx
  unsigned int v69; // ebx
  unsigned __int64 v70; // rax
  UFG::allocator::free_link *v71; // rax
  UFG::allocator::free_link *v72; // r14
  unsigned int i; // er9
  __int64 *v74; // rcx
  __int64 **v75; // rax
  __int64 *v76; // rcx
  __int64 **v77; // rax
  __int64 v78; // r12
  unsigned int v79; // esi
  unsigned int v80; // ebx
  unsigned int v81; // ebx
  unsigned __int64 v82; // rax
  UFG::allocator::free_link *v83; // rax
  UFG::UIHKPlayerObjective **v84; // r14
  unsigned int j; // er9
  unsigned int v86; // esi
  __int64 v87; // rsi
  __int64 v88; // rbx
  UFG::UIHKPlayerObjective **v89; // r12
  UFG::UIHKPlayerObjective *v90; // r13
  UFG::Objective *v91; // rax
  unsigned int v92; // er14
  char *v93; // rdi
  int v94; // ebx
  UFG::UIHKPlayerObjective *v95; // rax
  UFG::Objective *v96; // rax
  const char *v97; // rcx
  UFG::UIHKObjectiveFlasherWidget::eState v98; // eax
  UFG::qBaseTreeRB *v99; // r14
  Render::SkinningCacheNode *v100; // rdi
  unsigned int v101; // edx
  UFG::qBaseTreeRB *v102; // rax
  UFG::SimComponent *v103; // rdx
  Render::SkinningCacheNode *v104; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v105; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v106; // rax
  UFG::ProgressionTracker *v107; // rax
  unsigned int v108; // edx
  UFG::qBaseTreeRB *v109; // rax
  UFG::qBaseTreeRB *v110; // rbx
  UFG::qBaseNodeRB **v111; // rdx
  UFG::qBaseNodeRB *v112; // rcx
  UFG::qBaseNodeRB *v113; // rax
  UFG::qBaseNodeRB *v114; // rcx
  UFG::qBaseNodeRB *v115; // rax
  UFG::qBaseTreeRB *v116; // r12
  UFG::qBaseTreeRB *v117; // r13
  unsigned int v118; // edx
  UFG::TSActor *v119; // rax
  UFG::SimObject *v120; // rdi
  UFG::qBaseTreeRB *v121; // rax
  UFG::qMemoryPool *v122; // rax
  UFG::allocator::free_link *v123; // rax
  UFG::SimComponent *v124; // rax
  UFG::SimComponent *v125; // rsi
  unsigned __int16 v126; // cx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v127; // rdx
  UFG::qBaseNodeRB *v128; // rcx
  UFG::qBaseNodeRB *v129; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v130; // rax
  UFG::ProgressionTracker *v131; // rax
  UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *v132; // rcx
  unsigned int v133; // edx
  unsigned int v134; // ecx
  UFG::Objective *v135; // [rsp+30h] [rbp-D0h]
  unsigned int uid; // [rsp+40h] [rbp-C0h]
  UFG::qString v137; // [rsp+48h] [rbp-B8h]
  __int64 *v138; // [rsp+70h] [rbp-90h]
  __int64 **v139; // [rsp+78h] [rbp-88h]
  __int64 v140; // [rsp+80h] [rbp-80h]
  UFG::ObjectiveIndicator *v141; // [rsp+90h] [rbp-70h]
  UFG::qPropertySet *v142; // [rsp+98h] [rbp-68h]
  UFG::ObjectiveTracker *v143; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol v144; // [rsp+A8h] [rbp-58h]
  UFG::qBaseTreeRB *v145; // [rsp+B0h] [rbp-50h]
  UFG::qSymbol v146; // [rsp+B8h] [rbp-48h]
  UFG::SimObjectModifier v147; // [rsp+C0h] [rbp-40h]
  UFG::UIHKScreenHud *v148; // [rsp+E0h] [rbp-20h]
  UFG::qString v149; // [rsp+E8h] [rbp-18h]
  UFG::qBaseTreeRB v150; // [rsp+110h] [rbp+10h]
  __int64 **v151; // [rsp+160h] [rbp+60h]
  UFG::qString v152; // [rsp+168h] [rbp+68h]
  _QWORD *v153; // [rsp+190h] [rbp+90h]
  __int64 v154; // [rsp+198h] [rbp+98h]
  __int64 v155; // [rsp+1A0h] [rbp+A0h]
  __int64 **v156; // [rsp+1A8h] [rbp+A8h]
  UFG::qString v157; // [rsp+1B0h] [rbp+B0h]
  UFG::qString v158; // [rsp+1D8h] [rbp+D8h]
  UFG::qString v159; // [rsp+200h] [rbp+100h]
  UFG::qString v160; // [rsp+228h] [rbp+128h]
  UFG::UIHKPlayerObjectiveManager *v161; // [rsp+2B0h] [rbp+1B0h]
  UFG::qSymbol result; // [rsp+2C0h] [rbp+1C0h]
  UFG::qSymbol v163; // [rsp+2C8h] [rbp+1C8h]

  v161 = this;
  v154 = -2i64;
  v1 = this;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    UFG::qString::qString(&v152);
    if ( v1->mTempObjectiveSelected )
    {
      v2 = (signed __int64)&v1->mTempObjective;
      goto LABEL_12;
    }
    if ( v1->mWorldMapObjective_IsSelected )
    {
      if ( v1->mWorldMapObjective_IsSet )
      {
        v2 = (signed __int64)&v1->mWorldMapObjective;
        goto LABEL_12;
      }
      v1->mWorldMapObjective_IsSelected = 0;
    }
    v3 = v1->m_objectives.size;
    if ( !v3 )
      goto LABEL_17;
    if ( (unsigned __int8)v1->m_currentObjective >= v3 )
      v1->m_currentObjective = 0;
    v2 = (signed __int64)v1->m_objectives.p[(unsigned __int8)v1->m_currentObjective];
LABEL_12:
    if ( v2 )
    {
      v4 = *(_QWORD *)(v2 + 184);
      if ( v4 )
        v5 = *(const char **)(v4 + 72);
      else
        v5 = &customWorldMapCaption;
      UFG::qString::Set(&v152, v5);
    }
LABEL_17:
    v6 = 0i64;
    v7 = 0;
    if ( v1->m_objectives.size )
    {
      do
      {
        v8 = v1->m_objectives.p;
        v9 = v8[v7];
        if ( v9 )
        {
          UFG::UIHKPlayerObjective::~UIHKPlayerObjective(v8[v7]);
          operator delete[](v9);
        }
        ++v7;
      }
      while ( v7 < v1->m_objectives.size );
    }
    v10 = v1->m_objectives.p;
    if ( v10 )
      operator delete[](v10);
    v1->m_objectives.p = 0i64;
    *(_QWORD *)&v1->m_objectives.size = 0i64;
    v145 = &v1->m_pendingBlips.mTree.mTree;
    UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll(&v1->m_pendingBlips.mTree);
    v148 = UFG::UIHKScreenHud::mInstance;
    if ( UFG::UIHKScreenHud::mInstance )
      UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKScreenHud::ObjectiveDistance);
    v11 = UFG::ProgressionTracker::Instance();
    v12 = &v11->mObjectiveTracker;
    v143 = &v11->mObjectiveTracker;
    if ( v11 == (UFG::ProgressionTracker *)-408i64 )
      goto LABEL_199;
    UFG::qBaseTreeRB::qBaseTreeRB(&v150);
    v13 = UFG::qSymbol::create_from_string(&result, "default-unlockables-casedocs-list");
    v14 = UFG::PropertySetManager::GetPropertySet(v13);
    v142 = v14;
    v15 = UFG::ObjectiveTracker::GetFirstObjective(v12);
    v135 = v15;
    if ( v15 )
    {
      while ( 1 )
      {
        v16 = v15->mStatus;
        if ( v16 && (unsigned int)(v16 - 3) > 1 )
        {
          v17 = UFG::qMalloc(0xC0ui64, "UIHKPlayerObjectiveManager::UpdateObjectives UIHKPlayerObjective", 0i64);
          if ( v17 )
          {
            UFG::UIHKPlayerObjective::UIHKPlayerObjective((UFG::UIHKPlayerObjective *)v17);
            v19 = v18;
          }
          else
          {
            v19 = 0i64;
          }
          if ( v19 )
            break;
        }
LABEL_127:
        v15 = UFG::ObjectiveTracker::GetNextObjective(v143, v15);
        v135 = v15;
        if ( !v15 )
          goto LABEL_128;
      }
      *(_QWORD *)(v19 + 184) = v15;
      v20 = v15->mpGameSlice;
      if ( v20 && v20->mType == 10 && v14 )
      {
        UFG::qString::qString(&v157, v20->mName.mText);
        UFG::qString::qString(&v149, "CaseDoc_");
        v21 = UFG::qString::Substring(&v157, &v158, 0, v157.mLength - 1);
        UFG::qString::operator+=(&v149, v21);
        UFG::qString::~qString(&v158);
        v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(v14, (UFG::qSymbol *)&symbol_List.mUID, DEPTH_RECURSE);
        v23 = UFG::qSymbol::create_from_string(&v163, v149.mData);
        v24 = UFG::PSWrapper::FindElementPropertySet(v22, v23);
        v25 = UFG::qPropertyList::GetValuePtr(v22, 0x1Au, v24);
        if ( v25 )
        {
          if ( *(_QWORD *)v25 )
          {
            v26 = (UFG::qPropertySet *)&v25[*(_QWORD *)v25];
            if ( v26 )
              goto LABEL_202;
          }
        }
        v28 = UFG::GameSlice::GetParent(v20);
        if ( !v28 )
          goto LABEL_203;
        UFG::qString::Set(&v149, "CaseDoc_");
        UFG::qString::qString(&v160, v28->mName.mText);
        v30 = UFG::qString::Substring(v29, &v159, 0, *((signed __int16 *)v28->mName.mText - 4) - 1);
        UFG::qString::operator+=(&v149, v30);
        UFG::qString::~qString(&v159);
        UFG::qString::~qString(&v160);
        v31 = UFG::qPropertySet::Get<UFG::qPropertyList>(v14, (UFG::qSymbol *)&symbol_List.mUID, DEPTH_RECURSE);
        v32 = UFG::qSymbol::create_from_string(&v144, v149.mData);
        v33 = UFG::PSWrapper::FindElementPropertySet(v31, v32);
        v34 = UFG::qPropertyList::GetValuePtr(v31, 0x1Au, v33);
        if ( !v34 )
          goto LABEL_203;
        if ( *(_QWORD *)v34 && (v26 = (UFG::qPropertySet *)&v34[*(_QWORD *)v34]) != 0i64 )
LABEL_202:
          v27 = UFG::qPropertySet::Get<char const *>(v26, (UFG::qSymbol *)&symbol_CaseName.mUID, DEPTH_RECURSE);
        else
LABEL_203:
          v27 = &customWorldMapCaption;
        UFG::qString::Set((UFG::qString *)v19, v27);
        UFG::qString::~qString(&v149);
        UFG::qString::~qString(&v157);
      }
      UFG::qString::Set((UFG::qString *)(v19 + 56), v20->mName.mText);
      *(_DWORD *)(v19 + 96) = v20->mType;
      v35 = (UFG::qSharedStringData *)(v15->mGPSMarker.mText - 48);
      if ( v35 != UFG::qSharedStringData::GetEmptyString() )
      {
        v36 = UFG::qSymbol::create_from_string(&v146, v15->mGPSMarker.mText);
        v37 = v36;
        v38 = UFG::TSActor::find_instance(v36);
        if ( v38 )
        {
          v39 = v38->mpSimObj.m_pPointer;
          goto LABEL_51;
        }
        v40 = UFG::MarkerBase::GetNamed(v37);
        if ( v40 )
        {
          v39 = (UFG::SimObject *)v40->mNULL.mChild[0];
LABEL_51:
          if ( v39 )
          {
            v41 = UFG::GetSimulationMemoryPool();
            v42 = UFG::qMemoryPool::Allocate(v41, 0x118ui64, "HudComponent", 0i64, 1u);
            if ( v42 )
            {
              UFG::HudComponent::HudComponent(
                (UFG::HudComponent *)v42,
                HASH_HUD_COMPONENT,
                "invisible_icon",
                0,
                0.0,
                &customWorldMapCaption);
              v44 = v43;
            }
            else
            {
              v44 = 0i64;
            }
            v45 = v39->m_Flags;
            UFG::SimObjectModifier::SimObjectModifier(&v147, v39, 1);
            UFG::SimObjectModifier::AttachComponent(&v147, v44, 0xFFFFFFFFi64);
            UFG::SimObjectModifier::Close(&v147);
            UFG::SimObjectModifier::~SimObjectModifier(&v147);
            v46 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v19 + 104);
            if ( *(_QWORD *)(v19 + 120) )
            {
              v47 = v46->mPrev;
              v48 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v19 + 112);
              v47->mNext = v48;
              v48->mPrev = v47;
              v46->mPrev = v46;
              *(_QWORD *)(v19 + 112) = v19 + 104;
            }
            *(_QWORD *)(v19 + 120) = v44;
            if ( v44 )
            {
              v49 = v44->m_SafePointerList.mNode.mPrev;
              v49->mNext = v46;
              v46->mPrev = v49;
              *(_QWORD *)(v19 + 112) = (char *)v44 + 8;
              v44->m_SafePointerList.mNode.mPrev = v46;
            }
          }
          goto LABEL_59;
        }
      }
LABEL_59:
      v50 = *(void **)(v19 + 48);
      if ( v50 )
        operator delete[](v50);
      *(_QWORD *)(v19 + 48) = 0i64;
      *(_QWORD *)(v19 + 40) = 0i64;
      v51 = (UFG::ObjectiveIndicator *)UFG::Objective::GetFirstIndicator(v15);
      v141 = v51;
      if ( v51 )
      {
        v156 = &v138;
        v151 = &v138;
        do
        {
          UFG::qString::qString(&v137);
          v138 = (__int64 *)&v138;
          v139 = &v138;
          v140 = 0i64;
          uid = v51->mIdentifier.mUID;
          UFG::qString::Set(&v137, v51->mBlipType.mText);
          if ( !uid || (v52 = UFG::qBaseTreeRB::Get(&v150, uid)) == 0i64 )
          {
            v53 = UFG::qMalloc(0x68ui64, "qMap::qMapNode32", 0i64);
            v52 = (UFG::qBaseTreeRB *)v53;
            if ( v53 )
            {
              v53->mNext = 0i64;
              v53[1].mNext = 0i64;
              v53[2].mNext = 0i64;
              LODWORD(v53[3].mNext) = uid;
              v54 = (signed __int64)&v53[4];
              v155 = v54;
              *(_DWORD *)v54 = -1;
              UFG::qString::qString((UFG::qString *)&v53[5]);
              v55 = (_QWORD *)(v54 + 48);
              v153 = v55;
              *v55 = v55;
              v55[1] = v55;
              *(_QWORD *)(v54 + 64) = 0i64;
              *(_DWORD *)v54 = uid;
              UFG::qString::Set((UFG::qString *)(v54 + 8), v137.mData, v137.mLength, 0i64, 0);
              v56 = (__int64 *)(v54 + 48);
              v57 = v140;
              if ( v56[2] )
              {
                v58 = *v56;
                v59 = (_QWORD *)v56[1];
                *(_QWORD *)(v58 + 8) = v59;
                *v59 = v58;
                *v56 = (__int64)v56;
                v56[1] = (__int64)v56;
              }
              v56[2] = v57;
              if ( v57 )
              {
                v60 = *(_QWORD *)(v57 + 8);
                *(_QWORD *)(v60 + 8) = v56;
                *v56 = v60;
                v56[1] = v57 + 8;
                *(_QWORD *)(v57 + 8) = v56;
              }
            }
            else
            {
              v52 = 0i64;
            }
            UFG::qBaseTreeRB::Add(&v150, &v52->mRoot);
          }
          LODWORD(v52->mNULL.mParent) = uid;
          UFG::qString::Set((UFG::qString *)v52->mNULL.mChild, v137.mData, v137.mLength, 0i64, 0);
          v61 = v52[1].mRoot.mChild;
          v62 = v140;
          if ( *(_QWORD *)&v52[1].mRoot.mUID )
          {
            v63 = *v61;
            v64 = v52[1].mRoot.mChild[1];
            v63->mChild[0] = v64;
            v64->mParent = v63;
            *v61 = (UFG::qBaseNodeRB *)v61;
            v52[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v52[1].mRoot + 8);
          }
          *(_QWORD *)&v52[1].mRoot.mUID = v62;
          if ( v62 )
          {
            v65 = *(UFG::qBaseNodeRB **)(v62 + 8);
            v65->mChild[0] = (UFG::qBaseNodeRB *)v61;
            *v61 = v65;
            v52[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)(v62 + 8);
            *(_QWORD *)(v62 + 8) = v61;
          }
          v66 = *(unsigned int *)(v19 + 40);
          v67 = v66 + 1;
          v68 = *(_DWORD *)(v19 + 44);
          if ( (signed int)v66 + 1 > v68 )
          {
            if ( v68 )
              v69 = 2 * v68;
            else
              v69 = 1;
            for ( ; v69 < v67; v69 *= 2 )
              ;
            if ( v69 <= 4 )
              v69 = 4;
            if ( v69 - v67 > 0x10000 )
              v69 = v66 + 65537;
            if ( v69 != (_DWORD)v66 )
            {
              v70 = 4i64 * v69;
              if ( !is_mul_ok(v69, 4ui64) )
                v70 = -1i64;
              v71 = UFG::qMalloc(v70, "qArray.Add", 0i64);
              v72 = v71;
              if ( *(_QWORD *)(v19 + 48) )
              {
                for ( i = 0; i < *(_DWORD *)(v19 + 40); ++i )
                  *((_DWORD *)&v71->mNext + i) = *(_DWORD *)(*(_QWORD *)(v19 + 48) + 4i64 * i);
                operator delete[](*(void **)(v19 + 48));
              }
              *(_QWORD *)(v19 + 48) = v72;
              *(_DWORD *)(v19 + 44) = v69;
              v51 = v141;
            }
          }
          *(_DWORD *)(v19 + 40) = v67;
          *(_DWORD *)(*(_QWORD *)(v19 + 48) + 4 * v66) = uid;
          if ( v140 )
          {
            v74 = v138;
            v75 = v139;
            v138[1] = (__int64)v139;
            *v75 = v74;
            v138 = (__int64 *)&v138;
            v139 = &v138;
          }
          v140 = 0i64;
          v76 = v138;
          v77 = v139;
          v138[1] = (__int64)v139;
          *v77 = v76;
          v138 = (__int64 *)&v138;
          v139 = &v138;
          UFG::qString::~qString(&v137);
          v51 = (UFG::ObjectiveIndicator *)UFG::Objective::GetNextIndicator(v135, v51);
          v141 = v51;
        }
        while ( v51 );
        v1 = v161;
      }
      v78 = v1->m_objectives.size;
      v79 = v78 + 1;
      v80 = v1->m_objectives.capacity;
      if ( (signed int)v78 + 1 > v80 )
      {
        if ( v80 )
          v81 = 2 * v80;
        else
          v81 = 1;
        for ( ; v81 < v79; v81 *= 2 )
          ;
        if ( v81 <= 2 )
          v81 = 2;
        if ( v81 - v79 > 0x10000 )
          v81 = v78 + 65537;
        if ( v81 != (_DWORD)v78 )
        {
          v82 = 8i64 * v81;
          if ( !is_mul_ok(v81, 8ui64) )
            v82 = -1i64;
          v83 = UFG::qMalloc(v82, "qArray.Add", 0i64);
          v84 = (UFG::UIHKPlayerObjective **)v83;
          if ( v1->m_objectives.p )
          {
            for ( j = 0; j < v1->m_objectives.size; ++j )
              v83[j] = (UFG::allocator::free_link)v1->m_objectives.p[j];
            operator delete[](v1->m_objectives.p);
          }
          v1->m_objectives.p = v84;
          v1->m_objectives.capacity = v81;
        }
      }
      v1->m_objectives.size = v79;
      v1->m_objectives.p[v78] = (UFG::UIHKPlayerObjective *)v19;
      v86 = v1->m_objectives.size;
      if ( v86 > 1 )
      {
        v87 = v86 - 1;
        v88 = (signed int)v87;
        if ( (signed int)v87 > 0 )
        {
          do
          {
            v89 = v1->m_objectives.p;
            v90 = v89[(unsigned int)(v87 - 1)];
            v91 = v90->mObjective;
            if ( v91 )
              v92 = v91->mDisplayPriority;
            else
              v92 = 0;
            if ( (unsigned int)UFG::UIHKPlayerObjective::GetDisplayPriority((UFG::UIHKPlayerObjective *)v19) <= v92 )
              break;
            v89[v88] = v90;
            v87 = (unsigned int)(v87 - 1);
            --v88;
            v1 = v161;
          }
          while ( v88 > 0 );
          v1 = v161;
        }
        v1->m_objectives.p[v87] = (UFG::UIHKPlayerObjective *)v19;
      }
      v14 = v142;
      v15 = v135;
      goto LABEL_127;
    }
LABEL_128:
    v1->m_currentObjective = 0;
    if ( !v1->mTempObjectiveSelected && v152.mLength > 0 )
    {
      v93 = v152.mData;
      v94 = 0;
      if ( v1->m_objectives.size <= 0 )
      {
LABEL_139:
        v98 = UFG::UIHKObjectiveFlasherWidget::mState;
        if ( UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB )
          v98 = 3;
        UFG::UIHKObjectiveFlasherWidget::mState = v98;
      }
      else
      {
        while ( 1 )
        {
          v95 = v1->m_objectives.p[v94];
          if ( v95 )
          {
            v96 = v95->mObjective;
            v97 = v96 ? v96->mIdentifier.mData : &customWorldMapCaption;
            if ( !(unsigned int)UFG::qStringCompare(v97, v93, -1) )
              break;
          }
          if ( ++v94 >= v1->m_objectives.size )
            goto LABEL_139;
        }
        v1->m_currentObjective = v94;
      }
    }
    v99 = &v1->m_knownBlips.mTree.mTree;
    v100 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->m_knownBlips);
    if ( v100 )
    {
      do
      {
        v101 = (unsigned int)v100->mCachedBufferPtr;
        if ( v101 && UFG::qBaseTreeRB::Get(&v150, v101) )
        {
          v102 = UFG::qBaseTreeRB::GetNext(&v1->m_knownBlips.mTree.mTree, (UFG::qBaseNodeRB *)v100);
        }
        else
        {
          v103 = (UFG::SimComponent *)v100[2].mNode.mChild[1];
          if ( v103 )
          {
            if ( v103->m_pSimObject )
              UFG::Simulation::DestroySimComponent(&UFG::gSim, v103);
            v104 = v100 + 2;
            if ( v100[2].mNode.mChild[1] )
            {
              v105 = v104->mNode.mParent;
              v106 = v100[2].mNode.mChild[0];
              v105->mChild[0] = v106;
              v106->mParent = v105;
              v104->mNode.mParent = &v104->mNode;
              v100[2].mNode.mChild[0] = &v100[2].mNode;
            }
            v100[2].mNode.mChild[1] = 0i64;
          }
          v107 = UFG::ProgressionTracker::Instance();
          if ( v107 != (UFG::ProgressionTracker *)-408i64 )
            UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
              &v107->mObjectiveTracker,
              (UFG::qSymbol *)&v100->mCachedBufferPtr,
              0);
          v108 = (unsigned int)v100->mCachedBufferPtr;
          if ( v108 )
          {
            v109 = UFG::qBaseTreeRB::Get(&v1->m_knownBlips.mTree.mTree, v108);
            v110 = v109;
            if ( v109 )
            {
              UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->m_knownBlips,
                (UFG::qBaseNodeVariableRB<unsigned __int64> *)v109);
              v111 = v110[1].mRoot.mChild;
              *(_QWORD *)&result.mUID = (char *)v110 + 80;
              if ( *(_QWORD *)&v110[1].mRoot.mUID )
              {
                v112 = *v111;
                v113 = v110[1].mRoot.mChild[1];
                v112->mChild[0] = v113;
                v113->mParent = v112;
                *v111 = (UFG::qBaseNodeRB *)v111;
                v110[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v110[1].mRoot + 8);
              }
              *(_QWORD *)&v110[1].mRoot.mUID = 0i64;
              v114 = *v111;
              v115 = v110[1].mRoot.mChild[1];
              v114->mChild[0] = v115;
              v115->mParent = v114;
              *v111 = (UFG::qBaseNodeRB *)v111;
              v110[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v110[1].mRoot + 8);
              UFG::qString::~qString((UFG::qString *)v110->mNULL.mChild);
              operator delete[](v110);
            }
          }
          v102 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->m_knownBlips);
        }
        v100 = (Render::SkinningCacheNode *)v102;
      }
      while ( v102 );
    }
    v116 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v150);
    if ( v116 )
    {
      v117 = v145;
      while ( 1 )
      {
        v118 = (unsigned int)v116->mNULL.mParent;
        if ( v118 && UFG::qBaseTreeRB::Get(v99, v118) )
          goto LABEL_184;
        v119 = UFG::TSActor::find_instance((UFG::qSymbol *)&v116->mNULL);
        if ( v119 )
        {
          v120 = v119->mpSimObj.m_pPointer;
        }
        else
        {
          v121 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&v116->mNULL);
          if ( !v121 )
            goto LABEL_180;
          v120 = (UFG::SimObject *)v121->mNULL.mChild[0];
        }
        if ( v120 )
        {
          v122 = UFG::GetSimulationMemoryPool();
          v123 = UFG::qMemoryPool::Allocate(v122, 0x118ui64, "HudComponent", 0i64, 1u);
          if ( v123 )
          {
            UFG::HudComponent::HudComponent(
              (UFG::HudComponent *)v123,
              HASH_HUD_COMPONENT,
              *(const char **)&v116->mCount,
              0,
              0.0,
              &customWorldMapCaption);
            v125 = v124;
          }
          else
          {
            v125 = 0i64;
          }
          v126 = v120->m_Flags;
          UFG::SimObjectModifier::SimObjectModifier(&v147, v120, 1);
          UFG::SimObjectModifier::AttachComponent(&v147, v125, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v147);
          UFG::SimObjectModifier::~SimObjectModifier(&v147);
          v127 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v116[1].mRoot.mChild;
          if ( *(_QWORD *)&v116[1].mRoot.mUID )
          {
            v128 = (UFG::qBaseNodeRB *)v127->mPrev;
            v129 = v116[1].mRoot.mChild[1];
            v128->mChild[0] = v129;
            v129->mParent = v128;
            v127->mPrev = v127;
            v116[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v116[1].mRoot + 8);
          }
          *(_QWORD *)&v116[1].mRoot.mUID = v125;
          if ( v125 )
          {
            v130 = v125->m_SafePointerList.mNode.mPrev;
            v130->mNext = v127;
            v127->mPrev = v130;
            v116[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)&v125->m_SafePointerList;
            v125->m_SafePointerList.mNode.mPrev = v127;
          }
          v131 = UFG::ProgressionTracker::Instance();
          if ( v131 != (UFG::ProgressionTracker *)-408i64 )
            UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
              &v131->mObjectiveTracker,
              (UFG::qSymbol *)&v116->mNULL,
              1);
          v132 = (UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *)v99;
          goto LABEL_183;
        }
LABEL_180:
        v133 = (unsigned int)v116->mNULL.mParent;
        if ( v133 && UFG::qBaseTreeRB::Get(v117, v133) )
          goto LABEL_184;
        v132 = (UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *)v117;
LABEL_183:
        UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip>::Set(
          v132,
          (unsigned int)v116->mNULL.mParent,
          (UFG::UIHKPlayerObjectiveMinimapBlip *)&v116->mNULL);
LABEL_184:
        v116 = UFG::qBaseTreeRB::GetNext(&v150, &v116->mRoot);
        if ( !v116 )
        {
          v1 = v161;
          break;
        }
      }
    }
    if ( !v148 )
    {
LABEL_198:
      UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll((UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1> *)&v150);
      UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v150);
LABEL_199:
      UFG::qString::~qString(&v152);
      return;
    }
    if ( v1->mTempObjectiveSelected )
    {
      v6 = &v1->mTempObjective;
LABEL_197:
      UFG::UIHKObjectiveDistanceWidget::SetObjective(UFG::UIHKScreenHud::ObjectiveDistance, v6);
      goto LABEL_198;
    }
    if ( v1->mWorldMapObjective_IsSelected )
    {
      if ( v1->mWorldMapObjective_IsSet )
      {
        v6 = &v1->mWorldMapObjective;
        goto LABEL_197;
      }
      v1->mWorldMapObjective_IsSelected = 0;
    }
    v134 = v1->m_objectives.size;
    if ( v134 )
    {
      if ( (unsigned __int8)v1->m_currentObjective >= v134 )
        v1->m_currentObjective = 0;
      v6 = v1->m_objectives.p[(unsigned __int8)v1->m_currentObjective];
    }
    goto LABEL_197;
  }
}

// File Line: 569
// RVA: 0x61CA60
void __fastcall UFG::UIHKPlayerObjectiveManager::UpdatePendingBlips(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjectiveMinimapBlip *v1; // r15
  __int64 v2; // rdi
  unsigned int v3; // er14
  UFG::qBaseTreeRB *v4; // r12
  UFG::qBaseTreeRB *v5; // r13
  UFG::TSActor *v6; // rax
  UFG::SimObject *v7; // rbp
  UFG::qBaseTreeRB *v8; // rax
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rdx
  UFG::qBaseNodeRB *v14; // rcx
  UFG::qBaseNodeRB *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::ProgressionTracker *v17; // rax
  __int64 v18; // rbx
  unsigned int v19; // edx
  signed __int64 v20; // rbx
  unsigned int *v21; // rdx
  __int64 v22; // r8
  __int64 v23; // rcx
  _QWORD *v24; // rax
  __int64 v25; // rax
  unsigned int *v26; // rsi
  UFG::qBaseTreeRB *v27; // rax
  UFG::qBaseTreeRB *v28; // rbx
  UFG::qBaseNodeRB **v29; // rdx
  UFG::qBaseNodeRB *v30; // rcx
  UFG::qBaseNodeRB *v31; // rax
  UFG::qBaseNodeRB *v32; // rcx
  UFG::qBaseNodeRB *v33; // rax
  UFG::qArray<UFG::UIHKPlayerObjectiveMinimapBlip,0> v34; // [rsp+38h] [rbp-80h]
  UFG::SimObjectModifier v35; // [rsp+48h] [rbp-70h]
  UFG::UIHKPlayerObjectiveManager *v36; // [rsp+C0h] [rbp+8h]

  v36 = this;
  v1 = 0i64;
  v34.p = 0i64;
  v2 = 0i64;
  *(_QWORD *)&v34.size = 0i64;
  v3 = 0;
  v4 = &this->m_pendingBlips.mTree.mTree;
  v5 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->m_pendingBlips);
  if ( v5 )
  {
    while ( 1 )
    {
      v6 = UFG::TSActor::find_instance((UFG::qSymbol *)&v5->mNULL);
      if ( v6 )
        break;
      v8 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&v5->mNULL);
      if ( v8 )
      {
        v7 = (UFG::SimObject *)v8->mNULL.mChild[0];
LABEL_6:
        if ( v7 )
        {
          v9 = UFG::GetSimulationMemoryPool();
          v10 = UFG::qMemoryPool::Allocate(v9, 0x118ui64, "HudComponent", 0i64, 1u);
          if ( v10 )
          {
            UFG::HudComponent::HudComponent(
              (UFG::HudComponent *)v10,
              HASH_HUD_COMPONENT,
              *(const char **)&v5->mCount,
              0,
              0.0,
              &customWorldMapCaption);
            v12 = v11;
          }
          else
          {
            v12 = 0i64;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v35, v7, 1);
          UFG::SimObjectModifier::AttachComponent(&v35, v12, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v35);
          UFG::SimObjectModifier::~SimObjectModifier(&v35);
          v13 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v5[1].mRoot.mChild;
          if ( *(_QWORD *)&v5[1].mRoot.mUID )
          {
            v14 = (UFG::qBaseNodeRB *)v13->mPrev;
            v15 = v5[1].mRoot.mChild[1];
            v14->mChild[0] = v15;
            v15->mParent = v14;
            v13->mPrev = v13;
            v5[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v5[1].mRoot + 8);
          }
          *(_QWORD *)&v5[1].mRoot.mUID = v12;
          if ( v12 )
          {
            v16 = v12->m_SafePointerList.mNode.mPrev;
            v16->mNext = v13;
            v13->mPrev = v16;
            v5[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)&v12->m_SafePointerList;
            v12->m_SafePointerList.mNode.mPrev = v13;
          }
          v17 = UFG::ProgressionTracker::Instance();
          if ( v17 != (UFG::ProgressionTracker *)-408i64 )
            UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
              &v17->mObjectiveTracker,
              (UFG::qSymbol *)&v5->mNULL,
              1);
          UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip>::Set(
            &v36->m_knownBlips,
            (unsigned int)v5->mNULL.mParent,
            (UFG::UIHKPlayerObjectiveMinimapBlip *)&v5->mNULL);
          v18 = (unsigned int)v2;
          v2 = (unsigned int)(v2 + 1);
          if ( (unsigned int)v2 > v3 )
          {
            v19 = 1;
            if ( v3 )
              v19 = 2 * v3;
            for ( ; v19 < (unsigned int)v2; v19 *= 2 )
              ;
            if ( v19 - (unsigned int)v2 > 0x10000 )
              v19 = v2 + 0x10000;
            UFG::qArray<UFG::UIHKPlayerObjectiveMinimapBlip,0>::Reallocate(&v34, v19, "qArray.Add");
            v1 = v34.p;
            v3 = v34.capacity;
          }
          v34.size = v2;
          v20 = 9 * v18;
          v1[(unsigned __int64)v20 / 9].name.mUID = (unsigned int)v5->mNULL.mParent;
          UFG::qString::Set(
            (UFG::qString *)((char *)v1 + 8 * (v20 + 1)),
            *(const char **)&v5->mCount,
            *(&v5->mNULL.mUID + 1),
            0i64,
            0);
          v21 = &v1->name.mUID + 2 * (v20 + 6);
          v22 = *(_QWORD *)&v5[1].mRoot.mUID;
          if ( *((_QWORD *)v21 + 2) )
          {
            v23 = *(_QWORD *)v21;
            v24 = (_QWORD *)*((_QWORD *)v21 + 1);
            *(_QWORD *)(v23 + 8) = v24;
            *v24 = v23;
            *(_QWORD *)v21 = v21;
            *((_QWORD *)v21 + 1) = v21;
          }
          *((_QWORD *)v21 + 2) = v22;
          if ( v22 )
          {
            v25 = *(_QWORD *)(v22 + 8);
            *(_QWORD *)(v25 + 8) = v21;
            *(_QWORD *)v21 = v25;
            *((_QWORD *)v21 + 1) = v22 + 8;
            *(_QWORD *)(v22 + 8) = v21;
          }
        }
      }
      v5 = UFG::qBaseTreeRB::GetNext(v4, &v5->mRoot);
      if ( !v5 )
        goto LABEL_29;
    }
    v7 = v6->mpSimObj.m_pPointer;
    goto LABEL_6;
  }
LABEL_29:
  if ( (_DWORD)v2 )
  {
    v26 = &v1->name.mUID;
    do
    {
      if ( *v26 )
      {
        v27 = UFG::qBaseTreeRB::Get(v4, *v26);
        v28 = v27;
        if ( v27 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)v4,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v27);
          v29 = v28[1].mRoot.mChild;
          if ( *(_QWORD *)&v28[1].mRoot.mUID )
          {
            v30 = *v29;
            v31 = v28[1].mRoot.mChild[1];
            v30->mChild[0] = v31;
            v31->mParent = v30;
            *v29 = (UFG::qBaseNodeRB *)v29;
            v28[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v28[1].mRoot + 8);
          }
          *(_QWORD *)&v28[1].mRoot.mUID = 0i64;
          v32 = *v29;
          v33 = v28[1].mRoot.mChild[1];
          v32->mChild[0] = v33;
          v33->mParent = v32;
          *v29 = (UFG::qBaseNodeRB *)v29;
          v28[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v28[1].mRoot + 8);
          UFG::qString::~qString((UFG::qString *)v28->mNULL.mChild);
          operator delete[](v28);
        }
      }
      v26 += 18;
      --v2;
    }
    while ( v2 );
  }
  if ( v1 )
  {
    `eh vector destructor iterator'(
      v1,
      0x48ui64,
      (int)v1[-1].target.m_pPointer,
      (void (__fastcall *)(void *))UFG::UIHKPlayerObjectiveMinimapBlip::~UIHKPlayerObjectiveMinimapBlip);
    operator delete[](&v1[-1].target.m_pPointer);
  }
}

// File Line: 615
// RVA: 0x5E7260
UFG::UIHKPlayerObjective *__fastcall UFG::UIHKPlayerObjectiveManager::GetCurrentObjective(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjectiveManager *v1; // rdx
  unsigned int v3; // ecx

  v1 = this;
  if ( this->mTempObjectiveSelected )
    return &this->mTempObjective;
  if ( this->mWorldMapObjective_IsSelected )
  {
    if ( this->mWorldMapObjective_IsSet )
      return &this->mWorldMapObjective;
    this->mWorldMapObjective_IsSelected = 0;
  }
  v3 = this->m_objectives.size;
  if ( !v3 )
    return 0i64;
  if ( (unsigned __int8)v1->m_currentObjective >= v3 )
    v1->m_currentObjective = 0;
  return v1->m_objectives.p[(unsigned __int8)v1->m_currentObjective];
}

// File Line: 663
// RVA: 0x604030
void __fastcall UFG::UIHKPlayerObjectiveManager::ScrollNextObjective(UFG::UIHKPlayerObjectiveManager *this)
{
  unsigned int v1; // eax
  UFG::UIHKPlayerObjectiveManager *v2; // rbx
  UFG::Objective *v3; // rcx
  const char *v4; // rsi
  __int64 v5; // rdi
  UFG::UIHKPlayerObjective *v6; // rax
  UFG::Objective *v7; // rax
  const char *v8; // rcx
  char v9; // di
  UFG::UIHKPlayerObjective *v10; // rdx
  signed __int64 v11; // rax
  unsigned int v12; // ecx

  v1 = this->m_objectives.size;
  v2 = this;
  if ( v1 )
  {
    if ( this->mTempObjectiveSelected )
    {
      this->mTempObjectiveSelected = 0;
      v3 = this->mTempObjective.mObjective;
      v4 = v3 ? v3->mIdentifier.mData : &customWorldMapCaption;
      v5 = 0i64;
      if ( v1 )
      {
        while ( 1 )
        {
          v6 = v2->m_objectives.p[v5];
          if ( v6 )
          {
            v7 = v6->mObjective;
            v8 = v7 ? v7->mIdentifier.mData : &customWorldMapCaption;
            if ( !(unsigned int)UFG::qStringCompare(v8, v4, -1) )
              break;
          }
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= v2->m_objectives.size )
            goto LABEL_17;
        }
        v2->m_currentObjective = v5;
      }
    }
LABEL_17:
    v9 = 0;
    while ( 1 )
    {
      if ( v2->mWorldMapObjective_IsSelected )
      {
        v2->mWorldMapObjective_IsSelected = 0;
        v2->m_currentObjective = 0;
      }
      else
      {
        ++v2->m_currentObjective;
      }
      if ( (unsigned __int8)v2->m_currentObjective >= v2->m_objectives.size )
      {
        v2->m_currentObjective = 0;
        if ( v9 )
          goto LABEL_28;
        v9 = 1;
        if ( v2->mWorldMapObjective_IsSet )
          break;
      }
      v10 = v2->m_objectives.p[(unsigned __int8)v2->m_currentObjective];
      if ( v10 && UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(v2, v10) )
        goto LABEL_28;
    }
    v2->mWorldMapObjective_IsSelected = 1;
  }
  else
  {
    if ( !this->mWorldMapObjective_IsSet )
      return;
    this->mWorldMapObjective_IsSelected = 1;
  }
LABEL_28:
  if ( v2->mTempObjectiveSelected )
  {
    v11 = (signed __int64)&v2->mTempObjective;
    goto LABEL_38;
  }
  if ( v2->mWorldMapObjective_IsSelected )
  {
    if ( v2->mWorldMapObjective_IsSet )
    {
      v11 = (signed __int64)&v2->mWorldMapObjective;
      goto LABEL_38;
    }
    v2->mWorldMapObjective_IsSelected = 0;
  }
  v12 = v2->m_objectives.size;
  if ( !v12 )
    return;
  if ( (unsigned __int8)v2->m_currentObjective >= v12 )
    v2->m_currentObjective = 0;
  v11 = (signed __int64)v2->m_objectives.p[(unsigned __int8)v2->m_currentObjective];
LABEL_38:
  if ( v11 )
    v2->mFlashObjectiveFlag = 1;
}

// File Line: 778
// RVA: 0x5D8E50
void __fastcall UFG::UIHKPlayerObjectiveManager::FlashObjective(UFG::UIHKPlayerObjectiveManager *this, UFG::Objective *obj, bool forceFlash)
{
  bool v3; // r12
  UFG::Objective *v4; // r13
  UFG::UIHKPlayerObjectiveManager *v5; // rdi
  char *v6; // rsi
  int v7; // ebx
  UFG::UIHKPlayerObjective *v8; // rax
  UFG::Objective *v9; // rax
  const char *v10; // rcx
  UFG::qArray<unsigned long,0> *v11; // rsi
  unsigned int *v12; // rcx
  UFG::ObjectiveIndicator *v13; // rbp
  __int64 v14; // r14
  unsigned int v15; // edx
  unsigned int v16; // er15
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int *v19; // rax
  bool v20; // [rsp+60h] [rbp+18h]

  if ( obj )
  {
    v20 = forceFlash;
    v3 = forceFlash;
    v4 = obj;
    v5 = this;
    if ( forceFlash || (v6 = obj->mIdentifier.mData, v7 = 0, this->m_objectives.size <= 0) )
    {
LABEL_10:
      v11 = &v5->mTempObjective.minimapBlips;
      v5->mTempObjective.mObjective = v4;
      v12 = v5->mTempObjective.minimapBlips.p;
      if ( v12 )
        operator delete[](v12);
      v5->mTempObjective.minimapBlips.p = 0i64;
      *(_QWORD *)&v11->size = 0i64;
      v13 = (UFG::ObjectiveIndicator *)UFG::Objective::GetFirstIndicator(v4);
      if ( v13 )
      {
        do
        {
          if ( *((_WORD *)v13->mBlipType.mText - 4) > 0 )
          {
            v14 = v11->size;
            v15 = v5->mTempObjective.minimapBlips.capacity;
            v16 = v13->mIdentifier.mUID;
            v17 = v14 + 1;
            if ( (signed int)v14 + 1 > v15 )
            {
              if ( v15 )
                v18 = 2 * v15;
              else
                v18 = 1;
              for ( ; v18 < v17; v18 *= 2 )
                ;
              if ( v18 <= 4 )
                v18 = 4;
              if ( v18 - v17 > 0x10000 )
                v18 = v14 + 65537;
              UFG::qArray<long,0>::Reallocate(&v5->mTempObjective.minimapBlips, v18, "qArray.Add");
            }
            v19 = v5->mTempObjective.minimapBlips.p;
            v11->size = v17;
            v19[v14] = v16;
          }
          v13 = (UFG::ObjectiveIndicator *)UFG::Objective::GetNextIndicator(v4, v13);
        }
        while ( v13 );
        v3 = v20;
      }
      if ( v3 || UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(v5, &v5->mTempObjective) )
      {
        v5->mTempObjectiveSelected = 1;
        goto LABEL_33;
      }
    }
    else
    {
      while ( 1 )
      {
        v8 = v5->m_objectives.p[v7];
        if ( v8 )
        {
          v9 = v8->mObjective;
          v10 = v9 ? v9->mIdentifier.mData : &customWorldMapCaption;
          if ( !(unsigned int)UFG::qStringCompare(v10, v6, -1) )
            break;
        }
        if ( ++v7 >= v5->m_objectives.size )
          goto LABEL_10;
      }
      if ( UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(v5, v5->m_objectives.p[v7]) )
      {
        v5->m_currentObjective = v7;
        v5->mTempObjectiveSelected = 0;
        v5->mWorldMapObjective_IsSelected = 0;
LABEL_33:
        v5->mFlashObjectiveFlag = 1;
        return;
      }
    }
  }
}

// File Line: 818
// RVA: 0x1570BE0
__int64 UFG::_dynamic_initializer_for__symMissionStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMissionStart, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symMissionStart__);
}

// File Line: 819
// RVA: 0x1570BA0
__int64 UFG::_dynamic_initializer_for__symMissionObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMissionObjective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symMissionObjective__);
}

// File Line: 820
// RVA: 0x1570AA0
__int64 UFG::_dynamic_initializer_for__symCopEventStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_event_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCopEventStart, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCopEventStart__);
}

// File Line: 821
// RVA: 0x1570B20
__int64 UFG::_dynamic_initializer_for__symEventStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symEventStart, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symEventStart__);
}

// File Line: 822
// RVA: 0x1570AE0
__int64 UFG::_dynamic_initializer_for__symEventObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symEventObjective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symEventObjective__);
}

// File Line: 823
// RVA: 0x1570A60
__int64 UFG::_dynamic_initializer_for__symCaseStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCaseStart, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCaseStart__);
}

// File Line: 824
// RVA: 0x1570A20
__int64 UFG::_dynamic_initializer_for__symCaseObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCaseObjective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCaseObjective__);
}

// File Line: 828
// RVA: 0x5D8B20
void __fastcall UFG::UIHKPlayerObjectiveManager::FlashObjective(UFG::UIHKPlayerObjectiveManager *this, UFG::UIHKPlayerObjective *obj)
{
  UFG::UIMapBlipManager *v2; // r14
  UFG::UIHKPlayerObjective *v3; // rdi
  UFG::UIHKPlayerObjectiveManager *v4; // r15
  const char *v5; // rbx
  UFG::qBaseTreeRB *v6; // rax
  AK::IAkPluginParam *v7; // rax
  int v8; // eax
  UFG::Objective *v9; // rax
  const char *v10; // rcx
  UFG::Objective *v11; // rax
  const char *v12; // rsi
  char v13; // al
  UFG::UIHKObjectiveFlasherWidget::eState v14; // eax
  UFG::HudComponent *v15; // rbp
  unsigned int v16; // ebx
  UFG::qBaseTreeRB *v17; // rax
  UFG::UIMapBlip *v18; // rsi
  UFG::qBaseTreeRB *v19; // rax
  UFG::UIMapBlip *v20; // rbx
  UFG::qColour *v21; // rax
  UFG::qColour *v22; // rax
  float v23; // eax
  float v24; // xmm1_4
  float v25; // xmm0_4
  char v26; // al
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h]
  UFG::HudComponent *target; // [rsp+58h] [rbp+10h]

  if ( obj )
  {
    v2 = UFG::UIHKScreenHud::mIconManager;
    v3 = obj;
    v4 = this;
    if ( UFG::UIHKScreenHud::mIconManager )
    {
      v5 = "$COMMON_OBJECTIVE";
      if ( obj->minimapBlips.size )
      {
        v6 = UFG::BasePhysicsSystem::GetCollisionModel(
               (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager,
               *obj->minimapBlips.p);
        if ( v6 )
        {
          v7 = UFG::UIMapBlip::GetType((CAkSrcPhysModel *)v6);
          if ( v7 )
          {
            v8 = (int)v7->vfptr;
            if ( v8 == UFG::symMissionStart.mUID || v8 == UFG::symMissionObjective.mUID )
            {
              v5 = "$COMMON_MISSION";
            }
            else if ( v8 == UFG::symEventStart.mUID || v8 == UFG::symEventObjective.mUID )
            {
              v5 = "$COMMON_EVENT";
            }
            else if ( v8 == UFG::symCaseStart.mUID || v8 == UFG::symCaseObjective.mUID )
            {
              v5 = "$COMMON_CASE_LEAD";
            }
          }
        }
      }
      v9 = v3->mObjective;
      if ( v9 )
        v10 = v9->mCaption.mData;
      else
        v10 = v3->alternateCaption.mData;
      if ( (signed int)UFG::qStringLength(v10) <= 0 )
      {
        v14 = UFG::UIHKObjectiveFlasherWidget::mState;
        if ( UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB )
          v14 = 3;
        UFG::UIHKObjectiveFlasherWidget::mState = v14;
      }
      else
      {
        v11 = v3->mObjective;
        if ( v11 )
          v12 = v11->mCaption.mData;
        else
          v12 = v3->alternateCaption.mData;
        v13 = UFG::UIHKPlayerObjectiveManager::AnyObjectiveUsesPDA(v4);
        UFG::UIHKObjectiveFlasherWidget::Show(v12, v5, v13);
      }
      UFG::UIMapBlipManager::UnselectAllObjectiveBlips(v2);
      v15 = 0i64;
      v16 = 0;
      if ( v3->minimapBlips.size )
      {
        do
        {
          v17 = UFG::BasePhysicsSystem::GetCollisionModel((UFG::BasePhysicsSystem *)v2, v3->minimapBlips.p[v16]);
          v18 = (UFG::UIMapBlip *)v17;
          if ( v17 )
          {
            UFG::UIMapBlip::Blink((UFG::UIMapBlip *)v17);
            UFG::UIMapBlip::SetIsSelectedObjective(v18, 1);
          }
          ++v16;
        }
        while ( v16 < v3->minimapBlips.size );
      }
      if ( v3->minimapBlips.size > 0
        && (v19 = UFG::BasePhysicsSystem::GetCollisionModel((UFG::BasePhysicsSystem *)v2, *v3->minimapBlips.p),
            (v20 = (UFG::UIMapBlip *)v19) != 0i64) )
      {
        v21 = UFG::UIMapBlip::GetColor((UFG::UIMapBlip *)v19);
        UFG::UITiledMapWidget::SetGPSLineColor(v21);
        v22 = UFG::UIMapBlip::GetColor(v20);
        UFG::UIHKObjectiveFlasherWidget::mColor.r = v22->r;
        UFG::UIHKObjectiveFlasherWidget::mColor.g = v22->g;
        UFG::UIHKObjectiveFlasherWidget::mColor.b = v22->b;
        v23 = v22->a;
      }
      else if ( v4->mWorldMapObjective_IsSelected )
      {
        UFG::UITiledMapWidget::SetGPSLineColor(&v4->mWorldMapObjectiveColor);
        UFG::UIHKObjectiveFlasherWidget::mColor.r = v4->mWorldMapObjectiveColor.r;
        UFG::UIHKObjectiveFlasherWidget::mColor.g = v4->mWorldMapObjectiveColor.g;
        UFG::UIHKObjectiveFlasherWidget::mColor.b = v4->mWorldMapObjectiveColor.b;
        v23 = v4->mWorldMapObjectiveColor.a;
      }
      else
      {
        UFG::UITiledMapWidget::SetGPSLineColor(&UFG::UITiledMapWidget::DefaultGPSLineColor);
        UFG::UIHKObjectiveFlasherWidget::mColor.r = UFG::qColour::White.r;
        UFG::UIHKObjectiveFlasherWidget::mColor.g = UFG::qColour::White.g;
        UFG::UIHKObjectiveFlasherWidget::mColor.b = UFG::qColour::White.b;
        v23 = UFG::qColour::White.a;
      }
      UFG::UIHKObjectiveFlasherWidget::mColor.a = v23;
      target = 0i64;
      if ( v3->useFixedPos )
      {
        v24 = v3->fixedPos.y;
        pos.x = v3->fixedPos.x;
        v25 = v3->fixedPos.z;
        pos.y = v24;
        pos.z = v25;
      }
      else
      {
        v15 = (UFG::HudComponent *)v3->gpsTarget.m_pPointer;
        if ( v15 )
        {
          v26 = UFG::HudComponent::GetWorldPosition((UFG::HudComponent *)v3->gpsTarget.m_pPointer, &pos);
        }
        else
        {
          v26 = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(v4, v3, &pos, &target);
          v15 = target;
        }
        if ( !v26 )
        {
          UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 0);
LABEL_44:
          if ( UFG::UIHKScreenHud::ObjectiveDistance )
            UFG::UIHKObjectiveDistanceWidget::SetObjective(UFG::UIHKScreenHud::ObjectiveDistance, v3);
          return;
        }
      }
      UFG::UITiledMapGPS::UsePlayerSourcePosition(UFG::UIHKScreenHud::GPS);
      UFG::UITiledMapGPS::SetDestination(UFG::UIHKScreenHud::GPS, &pos, v4->mWorldMapObjective_IsSelected);
      UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 1);
      UFG::UITiledMapGPS::SetTrackingTarget(UFG::UIHKScreenHud::GPS, v15);
      goto LABEL_44;
    }
  }
}

// File Line: 934
// RVA: 0x60C8B0
char __fastcall UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(UFG::UIHKPlayerObjectiveManager *this, UFG::UIHKPlayerObjective *obj)
{
  UFG::UIHKPlayerObjective *v2; // rbp
  unsigned int v4; // er12
  char v5; // r15
  unsigned int v6; // ebx
  __int64 v7; // r14
  UFG::qBaseTreeRB *v8; // rax
  UFG::UIMapBlip *v9; // rdi
  UFG::UIHKScreenHud *v10; // rsi
  float v11; // xmm0_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-48h]
  UFG::qVector3 dir; // [rsp+30h] [rbp-38h]

  v2 = obj;
  if ( !obj )
    return 0;
  v4 = obj->minimapBlips.size;
  if ( v4 < 1 )
    return 1;
  v5 = 0;
  v6 = 0;
  if ( v4 )
  {
    v7 = 0i64;
    do
    {
      if ( UFG::UIHKScreenHud::mIconManager )
      {
        if ( v2->minimapBlips.size > v6 )
        {
          v8 = UFG::BasePhysicsSystem::GetCollisionModel(
                 (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager,
                 v2->minimapBlips.p[v7]);
          v9 = (UFG::UIMapBlip *)v8;
          if ( v8 )
          {
            if ( UFG::UIMapBlip::IsVisible((UFG::UIMapBlip *)v8) )
            {
              v10 = UFG::UIHKScreenHud::mInstance;
              if ( UFG::UIHKScreenHud::mInstance && UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
                v11 = UFG::UIMapBlip::GetAlpha(v9, &pos, &v10->Minimap.m_mapGeo);
              else
                v11 = UFG::UIMapBlip::GetAlpha(v9);
              if ( v11 >= 0.1 )
                v5 |= BYTE1(UFG::UIMapBlip::GetType((CAkSrcPhysModel *)v9)[6].vfptr);
            }
          }
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v4 );
  }
  return v5;
}

// File Line: 1005
// RVA: 0x5D3B80
char __fastcall UFG::UIHKPlayerObjectiveManager::AnyObjectiveUsesPDA(UFG::UIHKPlayerObjectiveManager *this)
{
  unsigned int v1; // er9
  unsigned int v2; // eax
  UFG::UIHKPlayerObjective **v3; // rcx
  UFG::Objective *v4; // r8

  v1 = this->m_objectives.size;
  v2 = 0;
  if ( !v1 )
    return 0;
  v3 = this->m_objectives.p;
  while ( 1 )
  {
    if ( *v3 )
    {
      v4 = (*v3)->mObjective;
      if ( v4 )
      {
        if ( v4->mUsesPDA )
          break;
      }
    }
    ++v2;
    ++v3;
    if ( v2 >= v1 )
      return 0;
  }
  return 1;
}

// File Line: 1071
// RVA: 0x5E84A0
char __fastcall UFG::UIHKPlayerObjectiveManager::GetObjectivePos(UFG::UIHKPlayerObjectiveManager *this, UFG::UIHKPlayerObjective *obj, UFG::qVector3 *pos, UFG::HudComponent **target)
{
  UFG::HudComponent **v4; // r15
  UFG::qVector3 *v5; // r14
  UFG::UIHKPlayerObjective *v6; // rsi
  UFG::UIHKPlayerObjectiveManager *v7; // r13
  char v8; // r12
  float v10; // xmm0_4
  float v11; // xmm1_4
  __int64 v12; // rdi
  unsigned int v13; // ebx
  UFG::qBaseTreeRB *v14; // rax
  int *v15; // rbx
  UFG::HudComponent *v16; // r8
  __int64 *v17; // rcx
  __int64 **v18; // rax
  __int64 *v19; // rax
  __int64 *v20; // rcx
  __int64 **v21; // rax
  __int64 *v22; // rcx
  __int64 **v23; // rax
  __int64 *v24; // rcx
  __int64 **v25; // rax
  __int64 *v26; // rcx
  __int64 **v27; // rax
  __int64 *v28; // rcx
  __int64 **v29; // rax
  __int64 *v30; // rcx
  __int64 **v31; // rax
  __int64 *v32; // rcx
  __int64 **v33; // rax
  __int64 *v34; // rcx
  __int64 **v35; // rax
  __int64 *v36; // rcx
  __int64 **v37; // rax
  __int64 *v38; // rcx
  __int64 **v39; // rax
  __int64 *v40; // rcx
  __int64 **v41; // rax
  __int64 *v42; // rcx
  __int64 **v43; // rax
  __int64 *v44; // rcx
  __int64 **v45; // rax
  __int64 *v46; // rcx
  __int64 **v47; // rax
  __int64 *v48; // rcx
  __int64 **v49; // rax
  __int64 *v50; // rdx
  __int64 **v51; // rcx
  int v52; // [rsp+30h] [rbp-99h]
  UFG::qString v53; // [rsp+38h] [rbp-91h]
  __int64 *v54; // [rsp+60h] [rbp-69h]
  __int64 **v55; // [rsp+68h] [rbp-61h]
  UFG::HudComponent *v56; // [rsp+70h] [rbp-59h]
  int v57; // [rsp+80h] [rbp-49h]
  UFG::qString v58; // [rsp+88h] [rbp-41h]
  __int64 *v59; // [rsp+B0h] [rbp-19h]
  __int64 **v60; // [rsp+B8h] [rbp-11h]
  __int64 v61; // [rsp+C0h] [rbp-9h]
  __int64 **v62; // [rsp+D0h] [rbp+7h]
  UFG::qVector3 posa; // [rsp+D8h] [rbp+Fh]
  __int64 v64; // [rsp+E8h] [rbp+1Fh]

  v64 = -2i64;
  v4 = target;
  v5 = pos;
  v6 = obj;
  v7 = this;
  v8 = 0;
  *target = 0i64;
  if ( !obj )
    return 0;
  if ( obj->useFixedPos )
  {
    v10 = obj->fixedPos.y;
    v11 = obj->fixedPos.z;
    pos->x = obj->fixedPos.x;
    pos->y = v10;
    pos->z = v11;
    return 1;
  }
  v12 = 0i64;
  if ( !obj->minimapBlips.size )
    return v8;
  while ( 1 )
  {
    v13 = v6->minimapBlips.p[v12];
    v57 = -1;
    UFG::qString::qString(&v58);
    v59 = (__int64 *)&v59;
    v60 = &v59;
    v61 = 0i64;
    UFG::qString::qString(&v53);
    v54 = (__int64 *)&v54;
    v55 = &v54;
    v56 = 0i64;
    if ( !v13 || (v14 = UFG::qBaseTreeRB::Get(&v7->m_knownBlips.mTree.mTree, v13), v15 = (int *)&v14->mNULL, !v14) )
      v15 = &v57;
    v52 = *v15;
    UFG::qString::Set(&v53, *((const char **)v15 + 4), v15[7], 0i64, 0);
    v16 = (UFG::HudComponent *)*((_QWORD *)v15 + 8);
    if ( v56 )
    {
      v17 = v54;
      v18 = v55;
      v54[1] = (__int64)v55;
      *v18 = v17;
      v54 = (__int64 *)&v54;
      v55 = &v54;
    }
    v56 = v16;
    if ( v16 )
    {
      v19 = (__int64 *)v16->m_SafePointerList.mNode.mPrev;
      v19[1] = (__int64)&v54;
      v54 = v19;
      v55 = (__int64 **)&v16->m_SafePointerList;
      v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v54;
      v16 = v56;
    }
    if ( v52 != -1 )
      break;
    v62 = &v54;
    if ( v56 )
    {
      v20 = v54;
      v21 = v55;
      v54[1] = (__int64)v55;
      *v21 = v20;
      v54 = (__int64 *)&v54;
      v55 = &v54;
    }
    v56 = 0i64;
    v22 = v54;
    v23 = v55;
    v54[1] = (__int64)v55;
    *v23 = v22;
    v54 = (__int64 *)&v54;
    v55 = &v54;
    UFG::qString::~qString(&v53);
    v62 = &v59;
    if ( v61 )
    {
      v24 = v59;
      v25 = v60;
      v59[1] = (__int64)v60;
      *v25 = v24;
      v59 = (__int64 *)&v59;
      v60 = &v59;
    }
    v61 = 0i64;
    v26 = v59;
    v27 = v60;
    v59[1] = (__int64)v60;
    *v27 = v26;
    v59 = (__int64 *)&v59;
    v60 = &v59;
LABEL_31:
    UFG::qString::~qString(&v58);
    v12 = (unsigned int)(v12 + 1);
    if ( (unsigned int)v12 >= v6->minimapBlips.size )
      return v8;
  }
  *v4 = v16;
  if ( !v16 )
  {
    v62 = &v54;
    if ( v56 )
    {
      v28 = v54;
      v29 = v55;
      v54[1] = (__int64)v55;
      *v29 = v28;
      v54 = (__int64 *)&v54;
      v55 = &v54;
    }
    v56 = 0i64;
    v30 = v54;
    v31 = v55;
    v54[1] = (__int64)v55;
    *v31 = v30;
    v54 = (__int64 *)&v54;
    v55 = &v54;
    UFG::qString::~qString(&v53);
    v62 = &v59;
    if ( v61 )
    {
      v32 = v59;
      v33 = v60;
      v59[1] = (__int64)v60;
      *v33 = v32;
      v59 = (__int64 *)&v59;
      v60 = &v59;
    }
    v61 = 0i64;
    v34 = v59;
    v35 = v60;
    v59[1] = (__int64)v60;
    *v35 = v34;
    v59 = (__int64 *)&v59;
    v60 = &v59;
    goto LABEL_31;
  }
  if ( !UFG::HudComponent::GetWorldPosition(v16, &posa) )
  {
    v62 = &v54;
    if ( v56 )
    {
      v36 = v54;
      v37 = v55;
      v54[1] = (__int64)v55;
      *v37 = v36;
      v54 = (__int64 *)&v54;
      v55 = &v54;
    }
    v56 = 0i64;
    v38 = v54;
    v39 = v55;
    v54[1] = (__int64)v55;
    *v39 = v38;
    v54 = (__int64 *)&v54;
    v55 = &v54;
    UFG::qString::~qString(&v53);
    v62 = &v59;
    if ( v61 )
    {
      v40 = v59;
      v41 = v60;
      v59[1] = (__int64)v60;
      *v41 = v40;
      v59 = (__int64 *)&v59;
      v60 = &v59;
    }
    v61 = 0i64;
    v42 = v59;
    v43 = v60;
    v59[1] = (__int64)v60;
    *v43 = v42;
    v59 = (__int64 *)&v59;
    v60 = &v59;
    goto LABEL_31;
  }
  v5->x = posa.x;
  v5->y = posa.y;
  v5->z = posa.z;
  v8 = 1;
  if ( v56 )
  {
    v44 = v54;
    v45 = v55;
    v54[1] = (__int64)v55;
    *v45 = v44;
    v54 = (__int64 *)&v54;
    v55 = &v54;
  }
  v56 = 0i64;
  v46 = v54;
  v47 = v55;
  v54[1] = (__int64)v55;
  *v47 = v46;
  v54 = (__int64 *)&v54;
  v55 = &v54;
  UFG::qString::~qString(&v53);
  if ( v61 )
  {
    v48 = v59;
    v49 = v60;
    v59[1] = (__int64)v60;
    *v49 = v48;
    v59 = (__int64 *)&v59;
    v60 = &v59;
  }
  v61 = 0i64;
  v50 = v59;
  v51 = v60;
  v59[1] = (__int64)v60;
  *v51 = v50;
  v59 = (__int64 *)&v59;
  v60 = &v59;
  UFG::qString::~qString(&v58);
  return v8;
}

// File Line: 1157
// RVA: 0x5D86C0
UFG::UIHKPlayerObjective *__fastcall UFG::UIHKPlayerObjectiveManager::FindNearestObjective(UFG::UIHKPlayerObjectiveManager *this, UFG::qVector3 *pos)
{
  float v2; // xmm6_4
  UFG::qVector3 *v3; // r14
  UFG::UIHKPlayerObjectiveManager *v4; // rsi
  UFG::UIHKPlayerObjective *v5; // rbp
  unsigned int v6; // edi
  UFG::UIHKPlayerObjective *v7; // rbx
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  UFG::HudComponent *v11; // rcx
  char v12; // al
  UFG::qVector3 posa; // [rsp+20h] [rbp-38h]
  UFG::HudComponent *target; // [rsp+60h] [rbp+8h]

  v2 = FLOAT_1_0e8;
  v3 = pos;
  v4 = this;
  v5 = 0i64;
  v6 = 0;
  if ( this->m_objectives.size )
  {
    do
    {
      v7 = v4->m_objectives.p[v6];
      if ( v7 )
      {
        target = 0i64;
        if ( v7->useFixedPos )
        {
          v8 = v7->fixedPos.y;
          v9 = v7->fixedPos.z;
          v10 = v7->fixedPos.x;
          posa.x = v7->fixedPos.x;
          posa.y = v8;
          posa.z = v9;
        }
        else
        {
          v11 = (UFG::HudComponent *)v7->gpsTarget.m_pPointer;
          if ( v11 )
            v12 = UFG::HudComponent::GetWorldPosition(v11, &posa);
          else
            v12 = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(v4, v7, &posa, &target);
          if ( !v12 )
            goto LABEL_12;
          v9 = posa.z;
          v8 = posa.y;
          v10 = posa.x;
        }
        if ( (float)((float)((float)((float)(v3->y - v8) * (float)(v3->y - v8))
                           + (float)((float)(v3->x - v10) * (float)(v3->x - v10)))
                   + (float)((float)(v3->z - v9) * (float)(v3->z - v9))) < v2 )
        {
          v2 = (float)((float)((float)(v3->y - v8) * (float)(v3->y - v8))
                     + (float)((float)(v3->x - v10) * (float)(v3->x - v10)))
             + (float)((float)(v3->z - v9) * (float)(v3->z - v9));
          v5 = v7;
        }
      }
LABEL_12:
      ++v6;
    }
    while ( v6 < v4->m_objectives.size );
  }
  return v5;
}

// File Line: 1187
// RVA: 0x5D8800
UFG::UIHKPlayerObjective *__fastcall UFG::UIHKPlayerObjectiveManager::FindObjectiveFromBlip(UFG::UIHKPlayerObjectiveManager *this, UFG::UIMapBlip *blip)
{
  UFG::UIMapBlip *v2; // rbp
  UFG::UIHKPlayerObjectiveManager *v3; // r14
  UFG::BasePhysicsSystem *v5; // r15
  __int64 v6; // rsi
  UFG::UIHKPlayerObjective *v7; // rdi
  unsigned int v8; // eax
  __int64 v9; // rbx
  UFG::qBaseTreeRB *v10; // rax

  v2 = blip;
  v3 = this;
  if ( !blip )
    return 0i64;
  v5 = (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager;
  if ( !UFG::UIHKScreenHud::mIconManager )
    return 0i64;
  v6 = 0i64;
  if ( !this->m_objectives.size )
    return 0i64;
  while ( 1 )
  {
    v7 = v3->m_objectives.p[v6];
    if ( !v7 )
      goto LABEL_12;
    v8 = v7->minimapBlips.size;
    v9 = 0i64;
    if ( !v8 )
      goto LABEL_12;
    if ( v8 > 0 )
      break;
LABEL_11:
    v9 = (unsigned int)(v9 + 1);
    if ( v7->minimapBlips.size > (unsigned int)v9 )
      break;
LABEL_12:
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= v3->m_objectives.size )
      return 0i64;
  }
  v10 = UFG::BasePhysicsSystem::GetCollisionModel(v5, v7->minimapBlips.p[v9]);
  if ( !v10 || v2->mNode.mUID != v10->mRoot.mUID )
    goto LABEL_11;
  return v7;
}

