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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symbol_List__);
}

// File Line: 39
// RVA: 0x1572420
__int64 UFG::_dynamic_initializer_for__symbol_CaseName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CaseName", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symbol_CaseName, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symbol_CaseName__);
}

// File Line: 47
// RVA: 0x5C4670
void __fastcall UFG::UIHKPlayerObjective::UIHKPlayerObjective(UFG::UIHKPlayerObjective *this)
{
  UFG::qString::qString(&this->titleCaption);
  this->minimapBlips.p = 0i64;
  *(_QWORD *)&this->minimapBlips.size = 0i64;
  UFG::qString::qString(&this->gameSliceName);
  this->gpsTarget.mPrev = &this->gpsTarget;
  this->gpsTarget.mNext = &this->gpsTarget;
  this->gpsTarget.m_pPointer = 0i64;
  this->useFixedPos = 0;
  UFG::qString::qString(&this->alternateCaption);
  this->mObjective = 0i64;
}

// File Line: 79
// RVA: 0x5E8490
UFG::ModelData *__fastcall UFG::UIHKPlayerObjective::GetObjective(Render::SimpleDrawableComponent *this)
{
  return (UFG::ModelData *)this->mModelDataHandle.mData;
}

// File Line: 103
// RVA: 0x5E9440
UFG::SimObject *__fastcall UFG::UIHKPlayerObjective::GetSimObject(UFG::UIHKPlayerObjective *this)
{
  UFG::Objective *mObjective; // rcx
  UFG::qSymbol *v2; // rcx
  Render::SkinningCacheNode *FirstIndicator; // rax
  char TargetBySymbol; // al
  __int64 v5; // rcx
  UFG::SimObject *simObj; // [rsp+30h] [rbp+8h] BYREF

  mObjective = this->mObjective;
  if ( mObjective )
  {
    FirstIndicator = UFG::Objective::GetFirstIndicator(mObjective);
    v2 = &UFG::gNullQSymbol;
    if ( FirstIndicator )
      v2 = (UFG::qSymbol *)&FirstIndicator[1];
  }
  else
  {
    v2 = &UFG::gNullQSymbol;
  }
  TargetBySymbol = UFG::FindTargetBySymbol(v2, &simObj);
  v5 = 0i64;
  if ( TargetBySymbol )
    return simObj;
  return (UFG::SimObject *)v5;
}

// File Line: 138
// RVA: 0x5E7930
UFG::Objective *__fastcall UFG::UIHKPlayerObjective::GetDisplayPriority(UFG::UIHKPlayerObjective *this)
{
  UFG::Objective *result; // rax

  result = this->mObjective;
  if ( result )
    return (UFG::Objective *)result->mDisplayPriority;
  return result;
}

// File Line: 157
// RVA: 0x5C46F0
void __fastcall UFG::UIHKPlayerObjectiveManager::UIHKPlayerObjectiveManager(UFG::UIHKPlayerObjectiveManager *this)
{
  this->vfptr = (UFG::UIHKPlayerObjectiveManagerVtbl *)&UFG::UIHKPlayerObjectiveManager::`vftable;
  this->m_objectives.p = 0i64;
  *(_QWORD *)&this->m_objectives.size = 0i64;
  this->m_currentObjective = -1;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_knownBlips.mTree.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_pendingBlips.mTree.mTree);
  this->mFlashObjectiveFlag = 0;
  UFG::UIHKPlayerObjective::UIHKPlayerObjective(&this->mTempObjective);
  *(_WORD *)&this->mTempObjectiveSelected = 0;
  this->mWorldMapObjective_IsSelected = 0;
  UFG::UIHKPlayerObjective::UIHKPlayerObjective(&this->mWorldMapObjective);
  UFG::UIHKPlayerObjectiveManager::mInstance = this;
}

// File Line: 164
// RVA: 0x5C9C40
void __fastcall UFG::UIHKPlayerObjectiveManager::~UIHKPlayerObjectiveManager(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjective **p; // rcx

  this->vfptr = (UFG::UIHKPlayerObjectiveManagerVtbl *)&UFG::UIHKPlayerObjectiveManager::`vftable;
  UFG::UIHKPlayerObjectiveManager::mInstance = 0i64;
  UFG::UIHKPlayerObjective::~UIHKPlayerObjective(&this->mWorldMapObjective);
  UFG::UIHKPlayerObjective::~UIHKPlayerObjective(&this->mTempObjective);
  UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll(&this->m_pendingBlips.mTree);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->m_pendingBlips);
  UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll(&this->m_knownBlips.mTree);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->m_knownBlips);
  p = this->m_objectives.p;
  if ( p )
    operator delete[](p);
  this->m_objectives.p = 0i64;
  *(_QWORD *)&this->m_objectives.size = 0i64;
}

// File Line: 199
// RVA: 0x5D5290
void __fastcall UFG::UIHKPlayerObjectiveManager::Clear(UFG::UIHKPlayerObjectiveManager *this)
{
  __int64 i; // rbx
  UFG::UIHKPlayerObjective **p; // rax
  UFG::UIHKPlayerObjective *v4; // rsi
  UFG::UIHKPlayerObjective **v5; // rcx

  for ( i = 0i64; (unsigned int)i < this->m_objectives.size; i = (unsigned int)(i + 1) )
  {
    p = this->m_objectives.p;
    v4 = p[i];
    if ( v4 )
    {
      UFG::UIHKPlayerObjective::~UIHKPlayerObjective(p[i]);
      operator delete[](v4);
    }
  }
  v5 = this->m_objectives.p;
  if ( v5 )
    operator delete[](v5);
  this->m_objectives.p = 0i64;
  *(_QWORD *)&this->m_objectives.size = 0i64;
  this->m_currentObjective = 0;
  this->mTempObjectiveSelected = 0;
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
  UFG::UIHKPlayerObjective *p_mTempObjective; // rax
  unsigned int size; // ecx
  UFG::Objective *mObjective; // rcx
  const char *mData; // rdx
  UFG::UIHKPlayerObjective *p_mWorldMapObjective; // r15
  unsigned int i; // ebx
  UFG::UIHKPlayerObjective **p; // rax
  UFG::UIHKPlayerObjective *v9; // rdi
  UFG::UIHKPlayerObjective **v10; // rcx
  UFG::ProgressionTracker *v11; // rax
  UFG::ObjectiveTracker *p_mObjectiveTracker; // r14
  UFG::qSymbol *v13; // rax
  UFG::qPropertySet *PropertySet; // r12
  UFG::Objective *FirstObjective; // r14
  UFG::Objective::Status mStatus; // eax
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rdi
  UFG::GameSlice *mpGameSlice; // rsi
  UFG::qString *v21; // rax
  UFG::qPropertyList *v22; // rbx
  UFG::qSymbol *v23; // rax
  unsigned int ElementPropertySet; // eax
  char *ValuePtr; // rax
  UFG::qPropertySet *v26; // rcx
  char *v27; // rdx
  UFG::GameSlice *Parent; // rbx
  UFG::qString *v29; // rax
  UFG::qString *v30; // rax
  UFG::qPropertyList *v31; // rbx
  UFG::qSymbol *v32; // rax
  unsigned int v33; // eax
  char *v34; // rax
  UFG::qSharedStringData *v35; // rbx
  ASymbol *v36; // rbx
  UFG::TSActor *instance; // rax
  UFG::SimObject *m_pPointer; // rsi
  UFG::qBaseTreeRB *Named; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v41; // rax
  UFG::SimComponent *v42; // rax
  UFG::SimComponent *v43; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v44; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rax
  void *v48; // rcx
  UFG::ObjectiveIndicator *FirstIndicator; // r14
  UFG::qBaseTreeRB *v50; // rsi
  UFG::allocator::free_link *v51; // rax
  UFG::allocator::free_link *v52; // rbx
  UFG::allocator::free_link *v53; // rbx
  __int64 v54; // rdx
  UFG::allocator::free_link *mNext; // rcx
  UFG::allocator::free_link *v56; // rax
  UFG::allocator::free_link *v57; // rax
  UFG::qBaseNodeRB **mChild; // rdx
  __int64 v59; // r8
  UFG::qBaseNodeRB *v60; // rcx
  UFG::qBaseNodeRB *v61; // rax
  UFG::qBaseNodeRB *v62; // rax
  __int64 v63; // r12
  unsigned int v64; // esi
  unsigned int v65; // ebx
  unsigned int v66; // ebx
  unsigned __int64 v67; // rax
  UFG::allocator::free_link *v68; // rax
  UFG::allocator::free_link *v69; // r14
  unsigned int j; // r9d
  __int64 *v71; // rcx
  __int64 **v72; // rax
  __int64 *v73; // rcx
  __int64 **v74; // rax
  __int64 v75; // r12
  unsigned int v76; // esi
  unsigned int capacity; // ebx
  unsigned int v78; // ebx
  unsigned __int64 v79; // rax
  UFG::allocator::free_link *v80; // rax
  UFG::UIHKPlayerObjective **v81; // r14
  unsigned int k; // r9d
  unsigned int v83; // esi
  __int64 v84; // rsi
  __int64 v85; // rbx
  UFG::UIHKPlayerObjective **v86; // r12
  UFG::UIHKPlayerObjective *v87; // r13
  UFG::Objective *v88; // rax
  unsigned int mDisplayPriority; // r14d
  char *v90; // rdi
  int v91; // ebx
  UFG::UIHKPlayerObjective *v92; // rax
  UFG::Objective *v93; // rax
  const char *v94; // rcx
  UFG::UIHKObjectiveFlasherWidget::eState v95; // eax
  UFG::qBaseTreeRB *v96; // r14
  Render::SkinningCacheNode *Head; // rdi
  unsigned int mCachedBufferPtr; // edx
  UFG::qBaseTreeRB *Next; // rax
  UFG::SimComponent *v100; // rdx
  Render::SkinningCacheNode *v101; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v103; // rax
  UFG::ProgressionTracker *v104; // rax
  unsigned int v105; // edx
  UFG::qBaseTreeRB *v106; // rax
  UFG::qBaseTreeRB *v107; // rbx
  UFG::qBaseNodeRB **v108; // rdx
  UFG::qBaseNodeRB *v109; // rcx
  UFG::qBaseNodeRB *v110; // rax
  UFG::qBaseNodeRB *v111; // rcx
  UFG::qBaseNodeRB *v112; // rax
  UFG::qBaseTreeRB *v113; // r12
  UFG::qBaseTreeRB *v114; // r13
  unsigned int v115; // edx
  UFG::TSActor *v116; // rax
  UFG::SimObject *v117; // rdi
  UFG::qBaseTreeRB *v118; // rax
  UFG::qMemoryPool *v119; // rax
  UFG::allocator::free_link *v120; // rax
  UFG::SimComponent *v121; // rax
  UFG::SimComponent *v122; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v123; // rdx
  UFG::qBaseNodeRB *v124; // rcx
  UFG::qBaseNodeRB *v125; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v126; // rax
  UFG::ProgressionTracker *v127; // rax
  UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *v128; // rcx
  unsigned int v129; // edx
  unsigned int v130; // ecx
  UFG::Objective *v131; // [rsp+30h] [rbp-D0h]
  unsigned int uid; // [rsp+40h] [rbp-C0h]
  UFG::qString v133; // [rsp+48h] [rbp-B8h] BYREF
  __int64 *v134; // [rsp+70h] [rbp-90h] BYREF
  __int64 **v135; // [rsp+78h] [rbp-88h]
  __int64 v136; // [rsp+80h] [rbp-80h]
  UFG::ObjectiveIndicator *v137; // [rsp+90h] [rbp-70h]
  UFG::qPropertySet *v138; // [rsp+98h] [rbp-68h]
  UFG::ObjectiveTracker *v139; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol v140; // [rsp+A8h] [rbp-58h] BYREF
  UFG::qBaseTreeRB *p_mTree; // [rsp+B0h] [rbp-50h]
  UFG::qSymbol v142; // [rsp+B8h] [rbp-48h] BYREF
  UFG::SimObjectModifier v143; // [rsp+C0h] [rbp-40h] BYREF
  UFG::UIHKScreenHud *v144; // [rsp+E0h] [rbp-20h]
  UFG::qString v145; // [rsp+E8h] [rbp-18h] BYREF
  UFG::qBaseTreeRB v146; // [rsp+110h] [rbp+10h] BYREF
  __int64 **v147; // [rsp+160h] [rbp+60h]
  UFG::qString v148; // [rsp+168h] [rbp+68h] BYREF
  UFG::allocator::free_link *v149; // [rsp+190h] [rbp+90h]
  __int64 v150; // [rsp+198h] [rbp+98h]
  UFG::allocator::free_link *v151; // [rsp+1A0h] [rbp+A0h]
  __int64 **v152; // [rsp+1A8h] [rbp+A8h]
  UFG::qString v153; // [rsp+1B0h] [rbp+B0h] BYREF
  UFG::qString v154; // [rsp+1D8h] [rbp+D8h] BYREF
  UFG::qString v155; // [rsp+200h] [rbp+100h] BYREF
  UFG::qString v156; // [rsp+228h] [rbp+128h] BYREF
  UFG::qBaseNodeRB **result; // [rsp+2C0h] [rbp+1C0h] BYREF
  UFG::qSymbol v159; // [rsp+2C8h] [rbp+1C8h] BYREF

  v150 = -2i64;
  v1 = this;
  if ( UFG::UIHKScreenHud::mIconManager )
  {
    UFG::qString::qString(&v148);
    if ( v1->mTempObjectiveSelected )
    {
      p_mTempObjective = &v1->mTempObjective;
      goto LABEL_12;
    }
    if ( v1->mWorldMapObjective_IsSelected )
    {
      if ( v1->mWorldMapObjective_IsSet )
      {
        p_mTempObjective = &v1->mWorldMapObjective;
        goto LABEL_12;
      }
      v1->mWorldMapObjective_IsSelected = 0;
    }
    size = v1->m_objectives.size;
    if ( !size )
      goto LABEL_17;
    if ( (unsigned __int8)v1->m_currentObjective >= size )
      v1->m_currentObjective = 0;
    p_mTempObjective = v1->m_objectives.p[(unsigned __int8)v1->m_currentObjective];
LABEL_12:
    if ( p_mTempObjective )
    {
      mObjective = p_mTempObjective->mObjective;
      if ( mObjective )
        mData = mObjective->mIdentifier.mData;
      else
        mData = &customCaption;
      UFG::qString::Set(&v148, mData);
    }
LABEL_17:
    p_mWorldMapObjective = 0i64;
    for ( i = 0; i < v1->m_objectives.size; ++i )
    {
      p = v1->m_objectives.p;
      v9 = p[i];
      if ( v9 )
      {
        UFG::UIHKPlayerObjective::~UIHKPlayerObjective(p[i]);
        operator delete[](v9);
      }
    }
    v10 = v1->m_objectives.p;
    if ( v10 )
      operator delete[](v10);
    v1->m_objectives.p = 0i64;
    *(_QWORD *)&v1->m_objectives.size = 0i64;
    p_mTree = &v1->m_pendingBlips.mTree.mTree;
    UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll(&v1->m_pendingBlips.mTree);
    v144 = UFG::UIHKScreenHud::mInstance;
    if ( UFG::UIHKScreenHud::mInstance )
      UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKScreenHud::ObjectiveDistance);
    v11 = UFG::ProgressionTracker::Instance();
    p_mObjectiveTracker = &v11->mObjectiveTracker;
    v139 = &v11->mObjectiveTracker;
    if ( v11 == (UFG::ProgressionTracker *)-408i64 )
      goto LABEL_199;
    UFG::qBaseTreeRB::qBaseTreeRB(&v146);
    v13 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "default-unlockables-casedocs-list");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v13);
    v138 = PropertySet;
    FirstObjective = UFG::ObjectiveTracker::GetFirstObjective(p_mObjectiveTracker);
    v131 = FirstObjective;
    if ( FirstObjective )
    {
      while ( 1 )
      {
        mStatus = FirstObjective->mStatus;
        if ( mStatus && (unsigned int)(mStatus - 3) > 1 )
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
        FirstObjective = UFG::ObjectiveTracker::GetNextObjective(v139, FirstObjective);
        v131 = FirstObjective;
        if ( !FirstObjective )
          goto LABEL_128;
      }
      *(_QWORD *)(v19 + 184) = FirstObjective;
      mpGameSlice = FirstObjective->mpGameSlice;
      if ( mpGameSlice && mpGameSlice->mType == 10 && PropertySet )
      {
        UFG::qString::qString(&v153, mpGameSlice->mName.mText);
        UFG::qString::qString(&v145, "CaseDoc_");
        v21 = UFG::qString::Substring(&v153, &v154, 0, v153.mLength - 1);
        UFG::qString::operator+=(&v145, v21);
        UFG::qString::~qString(&v154);
        v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                PropertySet,
                (UFG::qArray<unsigned long,0> *)&symbol_List,
                DEPTH_RECURSE);
        v23 = UFG::qSymbol::create_from_string(&v159, v145.mData);
        ElementPropertySet = UFG::PSWrapper::FindElementPropertySet((hkMemoryResourceContainer *)v22, v23);
        ValuePtr = UFG::qPropertyList::GetValuePtr(v22, 0x1Au, ElementPropertySet);
        if ( ValuePtr )
        {
          if ( *(_QWORD *)ValuePtr )
          {
            v26 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            if ( v26 )
              goto LABEL_39;
          }
        }
        Parent = UFG::GameSlice::GetParent(mpGameSlice);
        if ( !Parent )
          goto LABEL_44;
        UFG::qString::Set(&v145, "CaseDoc_");
        UFG::qString::qString(&v156, Parent->mName.mText);
        v30 = UFG::qString::Substring(v29, &v155, 0, *((__int16 *)Parent->mName.mText - 4) - 1);
        UFG::qString::operator+=(&v145, v30);
        UFG::qString::~qString(&v155);
        UFG::qString::~qString(&v156);
        v31 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                PropertySet,
                (UFG::qArray<unsigned long,0> *)&symbol_List,
                DEPTH_RECURSE);
        v32 = UFG::qSymbol::create_from_string(&v140, v145.mData);
        v33 = UFG::PSWrapper::FindElementPropertySet((hkMemoryResourceContainer *)v31, v32);
        v34 = UFG::qPropertyList::GetValuePtr(v31, 0x1Au, v33);
        if ( !v34 )
          goto LABEL_44;
        if ( *(_QWORD *)v34 && (v26 = (UFG::qPropertySet *)&v34[*(_QWORD *)v34]) != 0i64 )
LABEL_39:
          v27 = UFG::qPropertySet::Get<char const *>(
                  v26,
                  (UFG::qArray<unsigned long,0> *)&symbol_CaseName,
                  DEPTH_RECURSE);
        else
LABEL_44:
          v27 = &customCaption;
        UFG::qString::Set((UFG::qString *)v19, v27);
        UFG::qString::~qString(&v145);
        UFG::qString::~qString(&v153);
      }
      UFG::qString::Set((UFG::qString *)(v19 + 56), mpGameSlice->mName.mText);
      *(_DWORD *)(v19 + 96) = mpGameSlice->mType;
      v35 = (UFG::qSharedStringData *)(FirstObjective->mGPSMarker.mText - 48);
      if ( v35 != UFG::qSharedStringData::GetEmptyString() )
      {
        v36 = (ASymbol *)UFG::qSymbol::create_from_string(&v142, FirstObjective->mGPSMarker.mText);
        instance = UFG::TSActor::find_instance(v36);
        if ( instance )
        {
          m_pPointer = instance->mpSimObj.m_pPointer;
          goto LABEL_51;
        }
        Named = UFG::MarkerBase::GetNamed((UFG::qSymbol *)v36);
        if ( Named )
        {
          m_pPointer = (UFG::SimObject *)Named->mNULL.mChild[0];
LABEL_51:
          if ( m_pPointer )
          {
            SimulationMemoryPool = UFG::GetSimulationMemoryPool();
            v41 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x118ui64, "HudComponent", 0i64, 1u);
            if ( v41 )
            {
              UFG::HudComponent::HudComponent(
                (UFG::HudComponent *)v41,
                HASH_HUD_COMPONENT,
                "invisible_icon",
                0,
                0.0,
                &customCaption);
              v43 = v42;
            }
            else
            {
              v43 = 0i64;
            }
            UFG::SimObjectModifier::SimObjectModifier(&v143, m_pPointer, 1);
            UFG::SimObjectModifier::AttachComponent(&v143, v43, 0xFFFFFFFFi64);
            UFG::SimObjectModifier::Close(&v143);
            UFG::SimObjectModifier::~SimObjectModifier(&v143);
            v44 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v19 + 104);
            if ( *(_QWORD *)(v19 + 120) )
            {
              mPrev = v44->mPrev;
              v46 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v19 + 112);
              mPrev->mNext = v46;
              v46->mPrev = mPrev;
              v44->mPrev = v44;
              *(_QWORD *)(v19 + 112) = v19 + 104;
            }
            *(_QWORD *)(v19 + 120) = v43;
            if ( v43 )
            {
              v47 = v43->m_SafePointerList.mNode.mPrev;
              v47->mNext = v44;
              v44->mPrev = v47;
              *(_QWORD *)(v19 + 112) = &v43->m_SafePointerList;
              v43->m_SafePointerList.mNode.mPrev = v44;
            }
          }
        }
      }
      v48 = *(void **)(v19 + 48);
      if ( v48 )
        operator delete[](v48);
      *(_QWORD *)(v19 + 48) = 0i64;
      *(_QWORD *)(v19 + 40) = 0i64;
      FirstIndicator = (UFG::ObjectiveIndicator *)UFG::Objective::GetFirstIndicator(FirstObjective);
      v137 = FirstIndicator;
      if ( FirstIndicator )
      {
        v152 = &v134;
        v147 = &v134;
        do
        {
          UFG::qString::qString(&v133);
          v134 = (__int64 *)&v134;
          v135 = &v134;
          v136 = 0i64;
          uid = FirstIndicator->mIdentifier.mUID;
          UFG::qString::Set(&v133, FirstIndicator->mBlipType.mText);
          if ( !uid || (v50 = UFG::qBaseTreeRB::Get(&v146, uid)) == 0i64 )
          {
            v51 = UFG::qMalloc(0x68ui64, "qMap::qMapNode32", 0i64);
            v50 = (UFG::qBaseTreeRB *)v51;
            if ( v51 )
            {
              v51->mNext = 0i64;
              v51[1].mNext = 0i64;
              v51[2].mNext = 0i64;
              LODWORD(v51[3].mNext) = uid;
              v52 = v51 + 4;
              v151 = v51 + 4;
              LODWORD(v51[4].mNext) = -1;
              UFG::qString::qString((UFG::qString *)&v51[5]);
              v149 = v52 + 6;
              v52[6].mNext = v52 + 6;
              v52[7].mNext = v52 + 6;
              v52[8].mNext = 0i64;
              LODWORD(v52->mNext) = uid;
              UFG::qString::Set((UFG::qString *)&v52[1], v133.mData, v133.mLength, 0i64, 0);
              v53 = v52 + 6;
              v54 = v136;
              if ( v53[2].mNext )
              {
                mNext = v53->mNext;
                v56 = v53[1].mNext;
                mNext[1].mNext = v56;
                v56->mNext = mNext;
                v53->mNext = v53;
                v53[1].mNext = v53;
              }
              v53[2].mNext = (UFG::allocator::free_link *)v54;
              if ( v54 )
              {
                v57 = *(UFG::allocator::free_link **)(v54 + 8);
                v57[1].mNext = v53;
                v53->mNext = v57;
                v53[1].mNext = (UFG::allocator::free_link *)(v54 + 8);
                *(_QWORD *)(v54 + 8) = v53;
              }
            }
            else
            {
              v50 = 0i64;
            }
            UFG::qBaseTreeRB::Add(&v146, &v50->mRoot);
          }
          LODWORD(v50->mNULL.mParent) = uid;
          UFG::qString::Set((UFG::qString *)v50->mNULL.mChild, v133.mData, v133.mLength, 0i64, 0);
          mChild = v50[1].mRoot.mChild;
          v59 = v136;
          if ( *(_QWORD *)&v50[1].mRoot.mUID )
          {
            v60 = *mChild;
            v61 = v50[1].mRoot.mChild[1];
            v60->mChild[0] = v61;
            v61->mParent = v60;
            *mChild = (UFG::qBaseNodeRB *)mChild;
            v50[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)v50[1].mRoot.mChild;
          }
          *(_QWORD *)&v50[1].mRoot.mUID = v59;
          if ( v59 )
          {
            v62 = *(UFG::qBaseNodeRB **)(v59 + 8);
            v62->mChild[0] = (UFG::qBaseNodeRB *)mChild;
            *mChild = v62;
            v50[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)(v59 + 8);
            *(_QWORD *)(v59 + 8) = mChild;
          }
          v63 = *(unsigned int *)(v19 + 40);
          v64 = v63 + 1;
          v65 = *(_DWORD *)(v19 + 44);
          if ( (int)v63 + 1 > v65 )
          {
            if ( v65 )
              v66 = 2 * v65;
            else
              v66 = 1;
            for ( ; v66 < v64; v66 *= 2 )
              ;
            if ( v66 <= 4 )
              v66 = 4;
            if ( v66 - v64 > 0x10000 )
              v66 = v63 + 65537;
            if ( v66 != (_DWORD)v63 )
            {
              v67 = 4i64 * v66;
              if ( !is_mul_ok(v66, 4ui64) )
                v67 = -1i64;
              v68 = UFG::qMalloc(v67, "qArray.Add", 0i64);
              v69 = v68;
              if ( *(_QWORD *)(v19 + 48) )
              {
                for ( j = 0; j < *(_DWORD *)(v19 + 40); ++j )
                  *((_DWORD *)&v68->mNext + j) = *(_DWORD *)(*(_QWORD *)(v19 + 48) + 4i64 * j);
                operator delete[](*(void **)(v19 + 48));
              }
              *(_QWORD *)(v19 + 48) = v69;
              *(_DWORD *)(v19 + 44) = v66;
              FirstIndicator = v137;
            }
          }
          *(_DWORD *)(v19 + 40) = v64;
          *(_DWORD *)(*(_QWORD *)(v19 + 48) + 4 * v63) = uid;
          if ( v136 )
          {
            v71 = v134;
            v72 = v135;
            v134[1] = (__int64)v135;
            *v72 = v71;
            v134 = (__int64 *)&v134;
            v135 = &v134;
          }
          v136 = 0i64;
          v73 = v134;
          v74 = v135;
          v134[1] = (__int64)v135;
          *v74 = v73;
          v134 = (__int64 *)&v134;
          v135 = &v134;
          UFG::qString::~qString(&v133);
          FirstIndicator = (UFG::ObjectiveIndicator *)UFG::Objective::GetNextIndicator(v131, FirstIndicator);
          v137 = FirstIndicator;
        }
        while ( FirstIndicator );
        v1 = this;
      }
      v75 = v1->m_objectives.size;
      v76 = v75 + 1;
      capacity = v1->m_objectives.capacity;
      if ( (int)v75 + 1 > capacity )
      {
        if ( capacity )
          v78 = 2 * capacity;
        else
          v78 = 1;
        for ( ; v78 < v76; v78 *= 2 )
          ;
        if ( v78 <= 2 )
          v78 = 2;
        if ( v78 - v76 > 0x10000 )
          v78 = v75 + 65537;
        if ( v78 != (_DWORD)v75 )
        {
          v79 = 8i64 * v78;
          if ( !is_mul_ok(v78, 8ui64) )
            v79 = -1i64;
          v80 = UFG::qMalloc(v79, "qArray.Add", 0i64);
          v81 = (UFG::UIHKPlayerObjective **)v80;
          if ( v1->m_objectives.p )
          {
            for ( k = 0; k < v1->m_objectives.size; ++k )
              v80[k] = (UFG::allocator::free_link)v1->m_objectives.p[k];
            operator delete[](v1->m_objectives.p);
          }
          v1->m_objectives.p = v81;
          v1->m_objectives.capacity = v78;
        }
      }
      v1->m_objectives.size = v76;
      v1->m_objectives.p[v75] = (UFG::UIHKPlayerObjective *)v19;
      v83 = v1->m_objectives.size;
      if ( v83 > 1 )
      {
        v84 = v83 - 1;
        v85 = (int)v84;
        if ( (int)v84 > 0 )
        {
          do
          {
            v86 = v1->m_objectives.p;
            v87 = v86[(unsigned int)(v84 - 1)];
            v88 = v87->mObjective;
            if ( v88 )
              mDisplayPriority = v88->mDisplayPriority;
            else
              mDisplayPriority = 0;
            if ( (unsigned int)UFG::UIHKPlayerObjective::GetDisplayPriority((UFG::UIHKPlayerObjective *)v19) <= mDisplayPriority )
              break;
            v86[v85] = v87;
            v84 = (unsigned int)(v84 - 1);
            --v85;
            v1 = this;
          }
          while ( v85 > 0 );
          v1 = this;
        }
        v1->m_objectives.p[v84] = (UFG::UIHKPlayerObjective *)v19;
      }
      PropertySet = v138;
      FirstObjective = v131;
      goto LABEL_127;
    }
LABEL_128:
    v1->m_currentObjective = 0;
    if ( !v1->mTempObjectiveSelected && v148.mLength > 0 )
    {
      v90 = v148.mData;
      v91 = 0;
      if ( v1->m_objectives.size )
      {
        while ( 1 )
        {
          v92 = v1->m_objectives.p[v91];
          if ( v92 )
          {
            v93 = v92->mObjective;
            v94 = v93 ? v93->mIdentifier.mData : &customCaption;
            if ( !(unsigned int)UFG::qStringCompare(v94, v90, -1) )
              break;
          }
          if ( ++v91 >= v1->m_objectives.size )
            goto LABEL_139;
        }
        v1->m_currentObjective = v91;
      }
      else
      {
LABEL_139:
        v95 = UFG::UIHKObjectiveFlasherWidget::mState;
        if ( (UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB) != 0 )
          v95 = STATE_TEXT_INBOX;
        UFG::UIHKObjectiveFlasherWidget::mState = v95;
      }
    }
    v96 = &v1->m_knownBlips.mTree.mTree;
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->m_knownBlips);
    if ( Head )
    {
      do
      {
        mCachedBufferPtr = (unsigned int)Head->mCachedBufferPtr;
        if ( mCachedBufferPtr && UFG::qBaseTreeRB::Get(&v146, mCachedBufferPtr) )
        {
          Next = UFG::qBaseTreeRB::GetNext(&v1->m_knownBlips.mTree.mTree, (UFG::qBaseNodeRB *)Head);
        }
        else
        {
          v100 = (UFG::SimComponent *)Head[2].mNode.mChild[1];
          if ( v100 )
          {
            if ( v100->m_pSimObject )
              UFG::Simulation::DestroySimComponent(&UFG::gSim, v100);
            v101 = Head + 2;
            if ( Head[2].mNode.mChild[1] )
            {
              mParent = v101->mNode.mParent;
              v103 = Head[2].mNode.mChild[0];
              mParent->mChild[0] = v103;
              v103->mParent = mParent;
              v101->mNode.mParent = &v101->mNode;
              Head[2].mNode.mChild[0] = &Head[2].mNode;
            }
            Head[2].mNode.mChild[1] = 0i64;
          }
          v104 = UFG::ProgressionTracker::Instance();
          if ( v104 != (UFG::ProgressionTracker *)-408i64 )
            UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
              &v104->mObjectiveTracker,
              (UFG::qSymbol *)&Head->mCachedBufferPtr,
              0);
          v105 = (unsigned int)Head->mCachedBufferPtr;
          if ( v105 )
          {
            v106 = UFG::qBaseTreeRB::Get(&v1->m_knownBlips.mTree.mTree, v105);
            v107 = v106;
            if ( v106 )
            {
              UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->m_knownBlips,
                (UFG::qBaseNodeVariableRB<unsigned __int64> *)v106);
              v108 = v107[1].mRoot.mChild;
              result = v107[1].mRoot.mChild;
              if ( *(_QWORD *)&v107[1].mRoot.mUID )
              {
                v109 = *v108;
                v110 = v107[1].mRoot.mChild[1];
                v109->mChild[0] = v110;
                v110->mParent = v109;
                *v108 = (UFG::qBaseNodeRB *)v108;
                v107[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)v107[1].mRoot.mChild;
              }
              *(_QWORD *)&v107[1].mRoot.mUID = 0i64;
              v111 = *v108;
              v112 = v107[1].mRoot.mChild[1];
              v111->mChild[0] = v112;
              v112->mParent = v111;
              *v108 = (UFG::qBaseNodeRB *)v108;
              v107[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)v107[1].mRoot.mChild;
              UFG::qString::~qString((UFG::qString *)v107->mNULL.mChild);
              operator delete[](v107);
            }
          }
          Next = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->m_knownBlips);
        }
        Head = (Render::SkinningCacheNode *)Next;
      }
      while ( Next );
    }
    v113 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v146);
    if ( v113 )
    {
      v114 = p_mTree;
      while ( 1 )
      {
        v115 = (unsigned int)v113->mNULL.mParent;
        if ( v115 && UFG::qBaseTreeRB::Get(v96, v115) )
          goto LABEL_184;
        v116 = UFG::TSActor::find_instance((ASymbol *)&v113->mNULL);
        if ( v116 )
        {
          v117 = v116->mpSimObj.m_pPointer;
        }
        else
        {
          v118 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&v113->mNULL);
          if ( !v118 )
            goto LABEL_180;
          v117 = (UFG::SimObject *)v118->mNULL.mChild[0];
        }
        if ( v117 )
        {
          v119 = UFG::GetSimulationMemoryPool();
          v120 = UFG::qMemoryPool::Allocate(v119, 0x118ui64, "HudComponent", 0i64, 1u);
          if ( v120 )
          {
            UFG::HudComponent::HudComponent(
              (UFG::HudComponent *)v120,
              HASH_HUD_COMPONENT,
              *(const char **)&v113->mCount,
              0,
              0.0,
              &customCaption);
            v122 = v121;
          }
          else
          {
            v122 = 0i64;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v143, v117, 1);
          UFG::SimObjectModifier::AttachComponent(&v143, v122, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v143);
          UFG::SimObjectModifier::~SimObjectModifier(&v143);
          v123 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v113[1].mRoot.mChild;
          if ( *(_QWORD *)&v113[1].mRoot.mUID )
          {
            v124 = (UFG::qBaseNodeRB *)v123->mPrev;
            v125 = v113[1].mRoot.mChild[1];
            v124->mChild[0] = v125;
            v125->mParent = v124;
            v123->mPrev = v123;
            v113[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)v113[1].mRoot.mChild;
          }
          *(_QWORD *)&v113[1].mRoot.mUID = v122;
          if ( v122 )
          {
            v126 = v122->m_SafePointerList.mNode.mPrev;
            v126->mNext = v123;
            v123->mPrev = v126;
            v113[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)&v122->m_SafePointerList;
            v122->m_SafePointerList.mNode.mPrev = v123;
          }
          v127 = UFG::ProgressionTracker::Instance();
          if ( v127 != (UFG::ProgressionTracker *)-408i64 )
            UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
              &v127->mObjectiveTracker,
              (UFG::qSymbol *)&v113->mNULL,
              1);
          v128 = (UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *)v96;
          goto LABEL_183;
        }
LABEL_180:
        v129 = (unsigned int)v113->mNULL.mParent;
        if ( v129 && UFG::qBaseTreeRB::Get(v114, v129) )
          goto LABEL_184;
        v128 = (UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *)v114;
LABEL_183:
        UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip>::Set(
          v128,
          (unsigned int)v113->mNULL.mParent,
          (UFG::UIHKPlayerObjectiveMinimapBlip *)&v113->mNULL);
LABEL_184:
        v113 = UFG::qBaseTreeRB::GetNext(&v146, &v113->mRoot);
        if ( !v113 )
        {
          v1 = this;
          break;
        }
      }
    }
    if ( !v144 )
    {
LABEL_198:
      UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1>::DeleteAll((UFG::qTreeRB<UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>,1> *)&v146);
      UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v146);
LABEL_199:
      UFG::qString::~qString(&v148);
      return;
    }
    if ( v1->mTempObjectiveSelected )
    {
      p_mWorldMapObjective = &v1->mTempObjective;
LABEL_197:
      UFG::UIHKObjectiveDistanceWidget::SetObjective(UFG::UIHKScreenHud::ObjectiveDistance, p_mWorldMapObjective);
      goto LABEL_198;
    }
    if ( v1->mWorldMapObjective_IsSelected )
    {
      if ( v1->mWorldMapObjective_IsSet )
      {
        p_mWorldMapObjective = &v1->mWorldMapObjective;
        goto LABEL_197;
      }
      v1->mWorldMapObjective_IsSelected = 0;
    }
    v130 = v1->m_objectives.size;
    if ( v130 )
    {
      if ( (unsigned __int8)v1->m_currentObjective >= v130 )
        v1->m_currentObjective = 0;
      p_mWorldMapObjective = v1->m_objectives.p[(unsigned __int8)v1->m_currentObjective];
    }
    goto LABEL_197;
  }
}

// File Line: 569
// RVA: 0x61CA60
void __fastcall UFG::UIHKPlayerObjectiveManager::UpdatePendingBlips(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::UIHKPlayerObjectiveMinimapBlip *p; // r15
  __int64 v2; // rdi
  unsigned int capacity; // r14d
  UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip> *p_m_pendingBlips; // r12
  UFG::qBaseTreeRB *Head; // r13
  UFG::TSActor *instance; // rax
  UFG::SimObject *m_pPointer; // rbp
  UFG::qBaseTreeRB *Named; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mChild; // rdx
  UFG::qBaseNodeRB *mPrev; // rcx
  UFG::qBaseNodeRB *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::ProgressionTracker *v17; // rax
  __int64 v18; // rbx
  unsigned int v19; // edx
  __int64 v20; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *p_target; // rdx
  UFG::SimComponent *v22; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  unsigned int *p_mUID; // rsi
  UFG::qBaseTreeRB *v27; // rax
  UFG::qBaseTreeRB *v28; // rbx
  UFG::qBaseNodeRB **v29; // rdx
  UFG::qBaseNodeRB *v30; // rcx
  UFG::qBaseNodeRB *v31; // rax
  UFG::qBaseNodeRB *v32; // rcx
  UFG::qBaseNodeRB *v33; // rax
  UFG::qArray<UFG::UIHKPlayerObjectiveMinimapBlip,0> v34; // [rsp+38h] [rbp-80h] BYREF
  UFG::SimObjectModifier v35; // [rsp+48h] [rbp-70h] BYREF

  p = 0i64;
  v34.p = 0i64;
  v2 = 0i64;
  *(_QWORD *)&v34.size = 0i64;
  capacity = 0;
  p_m_pendingBlips = &this->m_pendingBlips;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->m_pendingBlips);
  if ( Head )
  {
    while ( 1 )
    {
      instance = UFG::TSActor::find_instance((ASymbol *)&Head->mNULL);
      if ( instance )
        break;
      Named = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&Head->mNULL);
      if ( Named )
      {
        m_pPointer = (UFG::SimObject *)Named->mNULL.mChild[0];
LABEL_6:
        if ( m_pPointer )
        {
          SimulationMemoryPool = UFG::GetSimulationMemoryPool();
          v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x118ui64, "HudComponent", 0i64, 1u);
          if ( v10 )
          {
            UFG::HudComponent::HudComponent(
              (UFG::HudComponent *)v10,
              HASH_HUD_COMPONENT,
              *(const char **)&Head->mCount,
              0,
              0.0,
              &customCaption);
            v12 = v11;
          }
          else
          {
            v12 = 0i64;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v35, m_pPointer, 1);
          UFG::SimObjectModifier::AttachComponent(&v35, v12, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v35);
          UFG::SimObjectModifier::~SimObjectModifier(&v35);
          mChild = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)Head[1].mRoot.mChild;
          if ( *(_QWORD *)&Head[1].mRoot.mUID )
          {
            mPrev = (UFG::qBaseNodeRB *)mChild->mPrev;
            v15 = Head[1].mRoot.mChild[1];
            mPrev->mChild[0] = v15;
            v15->mParent = mPrev;
            mChild->mPrev = mChild;
            Head[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)Head[1].mRoot.mChild;
          }
          *(_QWORD *)&Head[1].mRoot.mUID = v12;
          if ( v12 )
          {
            v16 = v12->m_SafePointerList.mNode.mPrev;
            v16->mNext = mChild;
            mChild->mPrev = v16;
            Head[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)&v12->m_SafePointerList;
            v12->m_SafePointerList.mNode.mPrev = mChild;
          }
          v17 = UFG::ProgressionTracker::Instance();
          if ( v17 != (UFG::ProgressionTracker *)-408i64 )
            UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
              &v17->mObjectiveTracker,
              (UFG::qSymbol *)&Head->mNULL,
              1);
          UFG::qMap<UFG::UIHKPlayerObjectiveMinimapBlip>::Set(
            &this->m_knownBlips,
            (unsigned int)Head->mNULL.mParent,
            (UFG::UIHKPlayerObjectiveMinimapBlip *)&Head->mNULL);
          v18 = (unsigned int)v2;
          v2 = (unsigned int)(v2 + 1);
          if ( (unsigned int)v2 > capacity )
          {
            v19 = 1;
            if ( capacity )
              v19 = 2 * capacity;
            for ( ; v19 < (unsigned int)v2; v19 *= 2 )
              ;
            if ( v19 - (unsigned int)v2 > 0x10000 )
              v19 = v2 + 0x10000;
            UFG::qArray<UFG::UIHKPlayerObjectiveMinimapBlip,0>::Reallocate(&v34, v19, "qArray.Add");
            p = v34.p;
            capacity = v34.capacity;
          }
          v34.size = v2;
          v20 = v18;
          p[v20].name.mUID = (unsigned int)Head->mNULL.mParent;
          UFG::qString::Set(&p[v20].type, *(const char **)&Head->mCount, *(&Head->mNULL.mUID + 1), 0i64, 0);
          p_target = &p[v20].target;
          v22 = *(UFG::SimComponent **)&Head[1].mRoot.mUID;
          if ( p_target->m_pPointer )
          {
            v23 = p_target->mPrev;
            mNext = p_target->mNext;
            v23->mNext = mNext;
            mNext->mPrev = v23;
            p_target->mPrev = p_target;
            p_target->mNext = p_target;
          }
          p_target->m_pPointer = v22;
          if ( v22 )
          {
            v25 = v22->m_SafePointerList.mNode.mPrev;
            v25->mNext = p_target;
            p_target->mPrev = v25;
            p_target->mNext = &v22->m_SafePointerList.mNode;
            v22->m_SafePointerList.mNode.mPrev = p_target;
          }
        }
      }
      Head = UFG::qBaseTreeRB::GetNext(&p_m_pendingBlips->mTree.mTree, &Head->mRoot);
      if ( !Head )
        goto LABEL_29;
    }
    m_pPointer = instance->mpSimObj.m_pPointer;
    goto LABEL_6;
  }
LABEL_29:
  if ( (_DWORD)v2 )
  {
    p_mUID = &p->name.mUID;
    do
    {
      if ( *p_mUID )
      {
        v27 = UFG::qBaseTreeRB::Get(&p_m_pendingBlips->mTree.mTree, *p_mUID);
        v28 = v27;
        if ( v27 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_m_pendingBlips,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v27);
          v29 = v28[1].mRoot.mChild;
          if ( *(_QWORD *)&v28[1].mRoot.mUID )
          {
            v30 = *v29;
            v31 = v28[1].mRoot.mChild[1];
            v30->mChild[0] = v31;
            v31->mParent = v30;
            *v29 = (UFG::qBaseNodeRB *)v29;
            v28[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)v28[1].mRoot.mChild;
          }
          *(_QWORD *)&v28[1].mRoot.mUID = 0i64;
          v32 = *v29;
          v33 = v28[1].mRoot.mChild[1];
          v32->mChild[0] = v33;
          v33->mParent = v32;
          *v29 = (UFG::qBaseNodeRB *)v29;
          v28[1].mRoot.mChild[1] = (UFG::qBaseNodeRB *)v28[1].mRoot.mChild;
          UFG::qString::~qString((UFG::qString *)v28->mNULL.mChild);
          operator delete[](v28);
        }
      }
      p_mUID += 18;
      --v2;
    }
    while ( v2 );
  }
  if ( p )
  {
    `eh vector destructor iterator(
      p,
      0x48ui64,
      (int)p[-1].target.m_pPointer,
      (void (__fastcall *)(void *))UFG::UIHKPlayerObjectiveMinimapBlip::~UIHKPlayerObjectiveMinimapBlip);
    operator delete[](&p[-1].target.m_pPointer);
  }
}

// File Line: 615
// RVA: 0x5E7260
UFG::UIHKPlayerObjective *__fastcall UFG::UIHKPlayerObjectiveManager::GetCurrentObjective(
        UFG::UIHKPlayerObjectiveManager *this)
{
  unsigned int size; // ecx

  if ( this->mTempObjectiveSelected )
    return &this->mTempObjective;
  if ( this->mWorldMapObjective_IsSelected )
  {
    if ( this->mWorldMapObjective_IsSet )
      return &this->mWorldMapObjective;
    this->mWorldMapObjective_IsSelected = 0;
  }
  size = this->m_objectives.size;
  if ( !size )
    return 0i64;
  if ( (unsigned __int8)this->m_currentObjective >= size )
    this->m_currentObjective = 0;
  return this->m_objectives.p[(unsigned __int8)this->m_currentObjective];
}

// File Line: 663
// RVA: 0x604030
void __fastcall UFG::UIHKPlayerObjectiveManager::ScrollNextObjective(UFG::UIHKPlayerObjectiveManager *this)
{
  UFG::Objective *mObjective; // rcx
  const char *mData; // rsi
  __int64 v4; // rdi
  UFG::UIHKPlayerObjective *v5; // rax
  UFG::Objective *v6; // rax
  const char *v7; // rcx
  char v8; // di
  UFG::UIHKPlayerObjective *v9; // rdx
  UFG::UIHKPlayerObjective *p_mTempObjective; // rax
  unsigned int size; // ecx

  if ( this->m_objectives.size )
  {
    if ( this->mTempObjectiveSelected )
    {
      this->mTempObjectiveSelected = 0;
      mObjective = this->mTempObjective.mObjective;
      if ( mObjective )
        mData = mObjective->mIdentifier.mData;
      else
        mData = &customCaption;
      v4 = 0i64;
      while ( 1 )
      {
        v5 = this->m_objectives.p[v4];
        if ( v5 )
        {
          v6 = v5->mObjective;
          v7 = v6 ? v6->mIdentifier.mData : &customCaption;
          if ( !(unsigned int)UFG::qStringCompare(v7, mData, -1) )
            break;
        }
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= this->m_objectives.size )
          goto LABEL_17;
      }
      this->m_currentObjective = v4;
    }
LABEL_17:
    v8 = 0;
    while ( 1 )
    {
      if ( this->mWorldMapObjective_IsSelected )
      {
        this->mWorldMapObjective_IsSelected = 0;
        this->m_currentObjective = 0;
      }
      else
      {
        ++this->m_currentObjective;
      }
      if ( (unsigned __int8)this->m_currentObjective >= this->m_objectives.size )
      {
        this->m_currentObjective = 0;
        if ( v8 )
          goto LABEL_28;
        v8 = 1;
        if ( this->mWorldMapObjective_IsSet )
          break;
      }
      v9 = this->m_objectives.p[(unsigned __int8)this->m_currentObjective];
      if ( v9 && UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(this, v9) )
        goto LABEL_28;
    }
    this->mWorldMapObjective_IsSelected = 1;
  }
  else
  {
    if ( !this->mWorldMapObjective_IsSet )
      return;
    this->mWorldMapObjective_IsSelected = 1;
  }
LABEL_28:
  if ( this->mTempObjectiveSelected )
  {
    p_mTempObjective = &this->mTempObjective;
    goto LABEL_38;
  }
  if ( this->mWorldMapObjective_IsSelected )
  {
    if ( this->mWorldMapObjective_IsSet )
    {
      p_mTempObjective = &this->mWorldMapObjective;
      goto LABEL_38;
    }
    this->mWorldMapObjective_IsSelected = 0;
  }
  size = this->m_objectives.size;
  if ( !size )
    return;
  if ( (unsigned __int8)this->m_currentObjective >= size )
    this->m_currentObjective = 0;
  p_mTempObjective = this->m_objectives.p[(unsigned __int8)this->m_currentObjective];
LABEL_38:
  if ( p_mTempObjective )
    this->mFlashObjectiveFlag = 1;
}

// File Line: 778
// RVA: 0x5D8E50
void __fastcall UFG::UIHKPlayerObjectiveManager::FlashObjective(
        UFG::UIHKPlayerObjectiveManager *this,
        UFG::Objective *obj,
        bool forceFlash)
{
  bool v3; // r12
  char *mData; // rsi
  int v7; // ebx
  UFG::UIHKPlayerObjective *v8; // rax
  UFG::Objective *mObjective; // rax
  const char *v10; // rcx
  UFG::qArray<unsigned long,0> *p_minimapBlips; // rsi
  unsigned int *p; // rcx
  UFG::ObjectiveIndicator *FirstIndicator; // rbp
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int mUID; // r15d
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int *v19; // rax

  if ( obj )
  {
    v3 = forceFlash;
    if ( forceFlash || (mData = obj->mIdentifier.mData, v7 = 0, !this->m_objectives.size) )
    {
LABEL_10:
      p_minimapBlips = &this->mTempObjective.minimapBlips;
      this->mTempObjective.mObjective = obj;
      p = this->mTempObjective.minimapBlips.p;
      if ( p )
        operator delete[](p);
      this->mTempObjective.minimapBlips.p = 0i64;
      *(_QWORD *)&p_minimapBlips->size = 0i64;
      FirstIndicator = (UFG::ObjectiveIndicator *)UFG::Objective::GetFirstIndicator(obj);
      if ( FirstIndicator )
      {
        do
        {
          if ( *((__int16 *)FirstIndicator->mBlipType.mText - 4) > 0 )
          {
            size = p_minimapBlips->size;
            capacity = this->mTempObjective.minimapBlips.capacity;
            mUID = FirstIndicator->mIdentifier.mUID;
            v17 = size + 1;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v18 = 2 * capacity;
              else
                v18 = 1;
              for ( ; v18 < v17; v18 *= 2 )
                ;
              if ( v18 <= 4 )
                v18 = 4;
              if ( v18 - v17 > 0x10000 )
                v18 = size + 65537;
              UFG::qArray<long,0>::Reallocate(&this->mTempObjective.minimapBlips, v18, "qArray.Add");
            }
            v19 = this->mTempObjective.minimapBlips.p;
            p_minimapBlips->size = v17;
            v19[size] = mUID;
          }
          FirstIndicator = (UFG::ObjectiveIndicator *)UFG::Objective::GetNextIndicator(obj, FirstIndicator);
        }
        while ( FirstIndicator );
        v3 = forceFlash;
      }
      if ( v3 || UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(this, &this->mTempObjective) )
      {
        this->mTempObjectiveSelected = 1;
        goto LABEL_33;
      }
    }
    else
    {
      while ( 1 )
      {
        v8 = this->m_objectives.p[v7];
        if ( v8 )
        {
          mObjective = v8->mObjective;
          v10 = mObjective ? mObjective->mIdentifier.mData : &customCaption;
          if ( !(unsigned int)UFG::qStringCompare(v10, mData, -1) )
            break;
        }
        if ( ++v7 >= this->m_objectives.size )
          goto LABEL_10;
      }
      if ( UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(this, this->m_objectives.p[v7]) )
      {
        this->m_currentObjective = v7;
        this->mTempObjectiveSelected = 0;
        this->mWorldMapObjective_IsSelected = 0;
LABEL_33:
        this->mFlashObjectiveFlag = 1;
      }
    }
  }
}

// File Line: 818
// RVA: 0x1570BE0
__int64 UFG::_dynamic_initializer_for__symMissionStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMissionStart, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symMissionStart__);
}

// File Line: 819
// RVA: 0x1570BA0
__int64 UFG::_dynamic_initializer_for__symMissionObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMissionObjective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symMissionObjective__);
}

// File Line: 820
// RVA: 0x1570AA0
__int64 UFG::_dynamic_initializer_for__symCopEventStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_event_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCopEventStart, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCopEventStart__);
}

// File Line: 821
// RVA: 0x1570B20
__int64 UFG::_dynamic_initializer_for__symEventStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symEventStart, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symEventStart__);
}

// File Line: 822
// RVA: 0x1570AE0
__int64 UFG::_dynamic_initializer_for__symEventObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symEventObjective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symEventObjective__);
}

// File Line: 823
// RVA: 0x1570A60
__int64 UFG::_dynamic_initializer_for__symCaseStart__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCaseStart, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCaseStart__);
}

// File Line: 824
// RVA: 0x1570A20
__int64 UFG::_dynamic_initializer_for__symCaseObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symCaseObjective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCaseObjective__);
}

// File Line: 828
// RVA: 0x5D8B20
void __fastcall UFG::UIHKPlayerObjectiveManager::FlashObjective(
        UFG::UIHKPlayerObjectiveManager *this,
        UFG::UIHKPlayerObjective *obj)
{
  UFG::UIMapBlipManager *v2; // r14
  const char *v5; // rbx
  UFG::qBaseTreeRB *CollisionModel; // rax
  AK::IAkPluginParam *Type; // rax
  int vfptr; // eax
  UFG::Objective *mObjective; // rax
  char *mData; // rcx
  UFG::Objective *v11; // rax
  char *v12; // rsi
  char v13; // al
  UFG::UIHKObjectiveFlasherWidget::eState v14; // eax
  UFG::HudComponent *m_pPointer; // rbp
  unsigned int i; // ebx
  UFG::qBaseTreeRB *v17; // rax
  UFG::UIMapBlip *v18; // rsi
  UFG::qBaseTreeRB *v19; // rax
  UFG::UIMapBlip *v20; // rbx
  UFG::qColour *Color; // rax
  UFG::qColour *v22; // rax
  float a; // eax
  float y; // xmm1_4
  float z; // xmm0_4
  bool WorldPosition; // al
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h] BYREF
  UFG::HudComponent *target; // [rsp+58h] [rbp+10h] BYREF

  if ( obj )
  {
    v2 = UFG::UIHKScreenHud::mIconManager;
    if ( UFG::UIHKScreenHud::mIconManager )
    {
      v5 = "$COMMON_OBJECTIVE";
      if ( obj->minimapBlips.size )
      {
        CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                           (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager,
                           *obj->minimapBlips.p);
        if ( CollisionModel )
        {
          Type = UFG::UIMapBlip::GetType((CAkSrcPhysModel *)CollisionModel);
          if ( Type )
          {
            vfptr = (int)Type->vfptr;
            if ( vfptr == UFG::symMissionStart.mUID || vfptr == UFG::symMissionObjective.mUID )
            {
              v5 = "$COMMON_MISSION";
            }
            else if ( vfptr == UFG::symEventStart.mUID || vfptr == UFG::symEventObjective.mUID )
            {
              v5 = "$COMMON_EVENT";
            }
            else if ( vfptr == UFG::symCaseStart.mUID || vfptr == UFG::symCaseObjective.mUID )
            {
              v5 = "$COMMON_CASE_LEAD";
            }
          }
        }
      }
      mObjective = obj->mObjective;
      if ( mObjective )
        mData = mObjective->mCaption.mData;
      else
        mData = obj->alternateCaption.mData;
      if ( (int)UFG::qStringLength(mData) <= 0 )
      {
        v14 = UFG::UIHKObjectiveFlasherWidget::mState;
        if ( (UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB) != 0 )
          v14 = STATE_TEXT_INBOX;
        UFG::UIHKObjectiveFlasherWidget::mState = v14;
      }
      else
      {
        v11 = obj->mObjective;
        if ( v11 )
          v12 = v11->mCaption.mData;
        else
          v12 = obj->alternateCaption.mData;
        v13 = UFG::UIHKPlayerObjectiveManager::AnyObjectiveUsesPDA(this);
        UFG::UIHKObjectiveFlasherWidget::Show(v12, v5, v13);
      }
      UFG::UIMapBlipManager::UnselectAllObjectiveBlips(v2);
      m_pPointer = 0i64;
      for ( i = 0; i < obj->minimapBlips.size; ++i )
      {
        v17 = UFG::BasePhysicsSystem::GetCollisionModel((UFG::BasePhysicsSystem *)v2, obj->minimapBlips.p[i]);
        v18 = (UFG::UIMapBlip *)v17;
        if ( v17 )
        {
          UFG::UIMapBlip::Blink((UFG::UIMapBlip *)v17);
          UFG::UIMapBlip::SetIsSelectedObjective(v18, 1);
        }
      }
      if ( obj->minimapBlips.size
        && (v19 = UFG::BasePhysicsSystem::GetCollisionModel((UFG::BasePhysicsSystem *)v2, *obj->minimapBlips.p),
            (v20 = (UFG::UIMapBlip *)v19) != 0i64) )
      {
        Color = UFG::UIMapBlip::GetColor((UFG::UIMapBlip *)v19);
        UFG::UITiledMapWidget::SetGPSLineColor(Color);
        v22 = UFG::UIMapBlip::GetColor(v20);
        UFG::UIHKObjectiveFlasherWidget::mColor.r = v22->r;
        UFG::UIHKObjectiveFlasherWidget::mColor.g = v22->g;
        UFG::UIHKObjectiveFlasherWidget::mColor.b = v22->b;
        a = v22->a;
      }
      else if ( this->mWorldMapObjective_IsSelected )
      {
        UFG::UITiledMapWidget::SetGPSLineColor(&this->mWorldMapObjectiveColor);
        UFG::UIHKObjectiveFlasherWidget::mColor.r = this->mWorldMapObjectiveColor.r;
        UFG::UIHKObjectiveFlasherWidget::mColor.g = this->mWorldMapObjectiveColor.g;
        UFG::UIHKObjectiveFlasherWidget::mColor.b = this->mWorldMapObjectiveColor.b;
        a = this->mWorldMapObjectiveColor.a;
      }
      else
      {
        UFG::UITiledMapWidget::SetGPSLineColor(&UFG::UITiledMapWidget::DefaultGPSLineColor);
        UFG::UIHKObjectiveFlasherWidget::mColor.r = UFG::qColour::White.r;
        UFG::UIHKObjectiveFlasherWidget::mColor.g = UFG::qColour::White.g;
        UFG::UIHKObjectiveFlasherWidget::mColor.b = UFG::qColour::White.b;
        a = UFG::qColour::White.a;
      }
      UFG::UIHKObjectiveFlasherWidget::mColor.a = a;
      target = 0i64;
      if ( obj->useFixedPos )
      {
        y = obj->fixedPos.y;
        pos.x = obj->fixedPos.x;
        z = obj->fixedPos.z;
        pos.y = y;
        pos.z = z;
      }
      else
      {
        m_pPointer = (UFG::HudComponent *)obj->gpsTarget.m_pPointer;
        if ( m_pPointer )
        {
          WorldPosition = UFG::HudComponent::GetWorldPosition((UFG::HudComponent *)obj->gpsTarget.m_pPointer, &pos);
        }
        else
        {
          WorldPosition = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(this, obj, &pos, &target);
          m_pPointer = target;
        }
        if ( !WorldPosition )
        {
          UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 0);
LABEL_44:
          if ( UFG::UIHKScreenHud::ObjectiveDistance )
            UFG::UIHKObjectiveDistanceWidget::SetObjective(UFG::UIHKScreenHud::ObjectiveDistance, obj);
          return;
        }
      }
      UFG::UITiledMapGPS::UsePlayerSourcePosition(UFG::UIHKScreenHud::GPS);
      UFG::UITiledMapGPS::SetDestination(UFG::UIHKScreenHud::GPS, &pos, this->mWorldMapObjective_IsSelected);
      UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 1);
      UFG::UITiledMapGPS::SetTrackingTarget(UFG::UIHKScreenHud::GPS, m_pPointer);
      goto LABEL_44;
    }
  }
}

// File Line: 934
// RVA: 0x60C8B0
char __fastcall UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(
        UFG::UIHKPlayerObjectiveManager *this,
        UFG::UIHKPlayerObjective *obj)
{
  unsigned int size; // r12d
  char v5; // r15
  unsigned int v6; // ebx
  __int64 v7; // r14
  UFG::qBaseTreeRB *CollisionModel; // rax
  UFG::UIMapBlip *v9; // rdi
  UFG::UIHKScreenHud *v10; // rsi
  float Alpha; // xmm0_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 dir; // [rsp+30h] [rbp-38h] BYREF

  if ( !obj )
    return 0;
  size = obj->minimapBlips.size;
  if ( !size )
    return 1;
  v5 = 0;
  v6 = 0;
  v7 = 0i64;
  do
  {
    if ( UFG::UIHKScreenHud::mIconManager )
    {
      if ( obj->minimapBlips.size > v6 )
      {
        CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                           (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager,
                           obj->minimapBlips.p[v7]);
        v9 = (UFG::UIMapBlip *)CollisionModel;
        if ( CollisionModel )
        {
          if ( UFG::UIMapBlip::IsVisible((UFG::UIMapBlip *)CollisionModel) )
          {
            v10 = UFG::UIHKScreenHud::mInstance;
            if ( UFG::UIHKScreenHud::mInstance && UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
              Alpha = UFG::UIMapBlip::GetAlpha(v9, &pos, &v10->Minimap.m_mapGeo);
            else
              Alpha = UFG::UIMapBlip::GetAlpha(v9);
            if ( Alpha >= 0.1 )
              v5 |= BYTE1(UFG::UIMapBlip::GetType((CAkSrcPhysModel *)v9)[6].vfptr);
          }
        }
      }
    }
    ++v6;
    ++v7;
  }
  while ( v6 < size );
  return v5;
}

// File Line: 1005
// RVA: 0x5D3B80
char __fastcall UFG::UIHKPlayerObjectiveManager::AnyObjectiveUsesPDA(UFG::UIHKPlayerObjectiveManager *this)
{
  unsigned int size; // r9d
  int v2; // eax
  UFG::UIHKPlayerObjective **i; // rcx
  UFG::Objective *mObjective; // r8

  size = this->m_objectives.size;
  v2 = 0;
  if ( !size )
    return 0;
  for ( i = this->m_objectives.p; ; ++i )
  {
    if ( *i )
    {
      mObjective = (*i)->mObjective;
      if ( mObjective )
      {
        if ( mObjective->mUsesPDA )
          break;
      }
    }
    if ( ++v2 >= size )
      return 0;
  }
  return 1;
}

// File Line: 1071
// RVA: 0x5E84A0
char __fastcall UFG::UIHKPlayerObjectiveManager::GetObjectivePos(
        UFG::UIHKPlayerObjectiveManager *this,
        UFG::UIHKPlayerObjective *obj,
        UFG::qVector3 *pos,
        UFG::HudComponent **target)
{
  char v8; // r12
  float y; // xmm0_4
  float z; // xmm1_4
  __int64 v12; // rdi
  unsigned int v13; // ebx
  UFG::qBaseTreeRB *v14; // rax
  int *p_mNULL; // rbx
  UFG::HudComponent *v16; // r8
  __int64 *v17; // rcx
  __int64 **v18; // rax
  __int64 *mPrev; // rax
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
  __int64 *v46; // rdx
  __int64 **v47; // rcx
  int v48; // [rsp+30h] [rbp-99h]
  UFG::qString v49; // [rsp+38h] [rbp-91h] BYREF
  __int64 *v50; // [rsp+60h] [rbp-69h] BYREF
  __int64 **p_m_SafePointerList; // [rsp+68h] [rbp-61h]
  UFG::HudComponent *v52; // [rsp+70h] [rbp-59h]
  int v53; // [rsp+80h] [rbp-49h] BYREF
  UFG::qString v54; // [rsp+88h] [rbp-41h] BYREF
  __int64 *v55; // [rsp+B0h] [rbp-19h] BYREF
  __int64 **v56; // [rsp+B8h] [rbp-11h]
  __int64 v57; // [rsp+C0h] [rbp-9h]
  __int64 **v58; // [rsp+D0h] [rbp+7h]
  UFG::qVector3 posa; // [rsp+D8h] [rbp+Fh] BYREF
  __int64 v60; // [rsp+E8h] [rbp+1Fh]

  v60 = -2i64;
  v8 = 0;
  *target = 0i64;
  if ( !obj )
    return 0;
  if ( obj->useFixedPos )
  {
    y = obj->fixedPos.y;
    z = obj->fixedPos.z;
    pos->x = obj->fixedPos.x;
    pos->y = y;
    pos->z = z;
    return 1;
  }
  v12 = 0i64;
  if ( !obj->minimapBlips.size )
    return v8;
  while ( 1 )
  {
    v13 = obj->minimapBlips.p[v12];
    v53 = -1;
    UFG::qString::qString(&v54);
    v55 = (__int64 *)&v55;
    v56 = &v55;
    v57 = 0i64;
    UFG::qString::qString(&v49);
    v50 = (__int64 *)&v50;
    p_m_SafePointerList = &v50;
    v52 = 0i64;
    if ( !v13 || (v14 = UFG::qBaseTreeRB::Get(&this->m_knownBlips.mTree.mTree, v13), p_mNULL = (int *)&v14->mNULL, !v14) )
      p_mNULL = &v53;
    v48 = *p_mNULL;
    UFG::qString::Set(&v49, *((const char **)p_mNULL + 4), p_mNULL[7], 0i64, 0);
    v16 = (UFG::HudComponent *)*((_QWORD *)p_mNULL + 8);
    if ( v52 )
    {
      v17 = v50;
      v18 = p_m_SafePointerList;
      v50[1] = (__int64)p_m_SafePointerList;
      *v18 = v17;
      v50 = (__int64 *)&v50;
      p_m_SafePointerList = &v50;
    }
    v52 = v16;
    if ( v16 )
    {
      mPrev = (__int64 *)v16->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      mPrev[1] = (__int64)&v50;
      v50 = mPrev;
      p_m_SafePointerList = (__int64 **)&v16->m_SafePointerList;
      v16->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v50;
      v16 = v52;
    }
    if ( v48 != -1 )
      break;
    v58 = &v50;
    if ( v52 )
    {
      v20 = v50;
      v21 = p_m_SafePointerList;
      v50[1] = (__int64)p_m_SafePointerList;
      *v21 = v20;
      v50 = (__int64 *)&v50;
      p_m_SafePointerList = &v50;
    }
    v52 = 0i64;
    v22 = v50;
    v23 = p_m_SafePointerList;
    v50[1] = (__int64)p_m_SafePointerList;
    *v23 = v22;
    v50 = (__int64 *)&v50;
    p_m_SafePointerList = &v50;
    UFG::qString::~qString(&v49);
    v58 = &v55;
    if ( v57 )
    {
      v24 = v55;
      v25 = v56;
      v55[1] = (__int64)v56;
      *v25 = v24;
      v55 = (__int64 *)&v55;
      v56 = &v55;
    }
LABEL_30:
    v57 = 0i64;
    v38 = v55;
    v39 = v56;
    v55[1] = (__int64)v56;
    *v39 = v38;
    v55 = (__int64 *)&v55;
    v56 = &v55;
    UFG::qString::~qString(&v54);
    v12 = (unsigned int)(v12 + 1);
    if ( (unsigned int)v12 >= obj->minimapBlips.size )
      return v8;
  }
  *target = v16;
  if ( !v16 )
  {
    v58 = &v50;
    if ( v52 )
    {
      v26 = v50;
      v27 = p_m_SafePointerList;
      v50[1] = (__int64)p_m_SafePointerList;
      *v27 = v26;
      v50 = (__int64 *)&v50;
      p_m_SafePointerList = &v50;
    }
    v52 = 0i64;
    v28 = v50;
    v29 = p_m_SafePointerList;
    v50[1] = (__int64)p_m_SafePointerList;
    *v29 = v28;
    v50 = (__int64 *)&v50;
    p_m_SafePointerList = &v50;
    UFG::qString::~qString(&v49);
    v58 = &v55;
    if ( v57 )
    {
      v30 = v55;
      v31 = v56;
      v55[1] = (__int64)v56;
      *v31 = v30;
      v55 = (__int64 *)&v55;
      v56 = &v55;
    }
    goto LABEL_30;
  }
  if ( !UFG::HudComponent::GetWorldPosition(v16, &posa) )
  {
    v58 = &v50;
    if ( v52 )
    {
      v32 = v50;
      v33 = p_m_SafePointerList;
      v50[1] = (__int64)p_m_SafePointerList;
      *v33 = v32;
      v50 = (__int64 *)&v50;
      p_m_SafePointerList = &v50;
    }
    v52 = 0i64;
    v34 = v50;
    v35 = p_m_SafePointerList;
    v50[1] = (__int64)p_m_SafePointerList;
    *v35 = v34;
    v50 = (__int64 *)&v50;
    p_m_SafePointerList = &v50;
    UFG::qString::~qString(&v49);
    v58 = &v55;
    if ( v57 )
    {
      v36 = v55;
      v37 = v56;
      v55[1] = (__int64)v56;
      *v37 = v36;
      v55 = (__int64 *)&v55;
      v56 = &v55;
    }
    goto LABEL_30;
  }
  *pos = posa;
  v8 = 1;
  if ( v52 )
  {
    v40 = v50;
    v41 = p_m_SafePointerList;
    v50[1] = (__int64)p_m_SafePointerList;
    *v41 = v40;
    v50 = (__int64 *)&v50;
    p_m_SafePointerList = &v50;
  }
  v52 = 0i64;
  v42 = v50;
  v43 = p_m_SafePointerList;
  v50[1] = (__int64)p_m_SafePointerList;
  *v43 = v42;
  v50 = (__int64 *)&v50;
  p_m_SafePointerList = &v50;
  UFG::qString::~qString(&v49);
  if ( v57 )
  {
    v44 = v55;
    v45 = v56;
    v55[1] = (__int64)v56;
    *v45 = v44;
    v55 = (__int64 *)&v55;
    v56 = &v55;
  }
  v57 = 0i64;
  v46 = v55;
  v47 = v56;
  v55[1] = (__int64)v56;
  *v47 = v46;
  v55 = (__int64 *)&v55;
  v56 = &v55;
  UFG::qString::~qString(&v54);
  return v8;
}

// File Line: 1157
// RVA: 0x5D86C0
UFG::UIHKPlayerObjective *__fastcall UFG::UIHKPlayerObjectiveManager::FindNearestObjective(
        UFG::UIHKPlayerObjectiveManager *this,
        UFG::qVector3 *pos)
{
  float v2; // xmm6_4
  UFG::UIHKPlayerObjective *v5; // rbp
  unsigned int i; // edi
  UFG::UIHKPlayerObjective *v7; // rbx
  float y; // xmm3_4
  float z; // xmm4_4
  float x; // xmm0_4
  UFG::HudComponent *m_pPointer; // rcx
  bool WorldPosition; // al
  UFG::qVector3 posa; // [rsp+20h] [rbp-38h] BYREF
  UFG::HudComponent *target; // [rsp+60h] [rbp+8h] BYREF

  v2 = FLOAT_1_0e8;
  v5 = 0i64;
  for ( i = 0; i < this->m_objectives.size; ++i )
  {
    v7 = this->m_objectives.p[i];
    if ( v7 )
    {
      target = 0i64;
      if ( v7->useFixedPos )
      {
        y = v7->fixedPos.y;
        z = v7->fixedPos.z;
        x = v7->fixedPos.x;
        posa.x = x;
        posa.y = y;
        posa.z = z;
      }
      else
      {
        m_pPointer = (UFG::HudComponent *)v7->gpsTarget.m_pPointer;
        if ( m_pPointer )
          WorldPosition = UFG::HudComponent::GetWorldPosition(m_pPointer, &posa);
        else
          WorldPosition = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(this, v7, &posa, &target);
        if ( !WorldPosition )
          continue;
        z = posa.z;
        y = posa.y;
        x = posa.x;
      }
      if ( (float)((float)((float)((float)(pos->y - y) * (float)(pos->y - y))
                         + (float)((float)(pos->x - x) * (float)(pos->x - x)))
                 + (float)((float)(pos->z - z) * (float)(pos->z - z))) < v2 )
      {
        v2 = (float)((float)((float)(pos->y - y) * (float)(pos->y - y))
                   + (float)((float)(pos->x - x) * (float)(pos->x - x)))
           + (float)((float)(pos->z - z) * (float)(pos->z - z));
        v5 = v7;
      }
    }
  }
  return v5;
}

// File Line: 1187
// RVA: 0x5D8800
UFG::UIHKPlayerObjective *__fastcall UFG::UIHKPlayerObjectiveManager::FindObjectiveFromBlip(
        UFG::UIHKPlayerObjectiveManager *this,
        UFG::UIMapBlip *blip)
{
  UFG::BasePhysicsSystem *v5; // r15
  __int64 v6; // rsi
  UFG::UIHKPlayerObjective *v7; // rdi
  __int64 v8; // rbx
  UFG::qBaseTreeRB *CollisionModel; // rax

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
    v7 = this->m_objectives.p[v6];
    if ( v7 )
    {
      v8 = 0i64;
      if ( v7->minimapBlips.size )
        break;
    }
LABEL_11:
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= this->m_objectives.size )
      return 0i64;
  }
  while ( 1 )
  {
    CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(v5, v7->minimapBlips.p[v8]);
    if ( CollisionModel )
    {
      if ( blip->mNode.mUID == CollisionModel->mRoot.mUID )
        return v7;
    }
    v8 = (unsigned int)(v8 + 1);
    if ( v7->minimapBlips.size <= (unsigned int)v8 )
      goto LABEL_11;
  }
}

