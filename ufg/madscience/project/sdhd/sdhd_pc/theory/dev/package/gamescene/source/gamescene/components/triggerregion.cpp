// File Line: 60
// RVA: 0x14754B0
__int64 dynamic_initializer_for__gTriggerRegionCullLayer__()
{
  CullLayer::CullLayer(&gTriggerRegionCullLayer, TYPE_CULL, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTriggerRegionCullLayer__);
}

// File Line: 107
// RVA: 0x23E080
UFG::SimObject *__fastcall UFG::TriggerTarget::GetSimObject(UFG::TriggerTarget *this)
{
  UFG::SimObject *m_pPointer; // r9
  UFG::SimObject *SimObject; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpSimObject; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  m_pPointer = this->mpSimObject.m_pPointer;
  if ( m_pPointer )
    return m_pPointer;
  SimObject = (UFG::SimObject *)UFG::Simulation::GetSimObject(&UFG::gSim, &this->mName);
  m_pPointer = SimObject;
  if ( SimObject )
  {
    p_mpSimObject = &this->mpSimObject;
    if ( this->mpSimObject.m_pPointer )
    {
      mPrev = p_mpSimObject->mPrev;
      mNext = this->mpSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpSimObject->mPrev = p_mpSimObject;
      this->mpSimObject.mNext = &this->mpSimObject;
    }
    this->mpSimObject.m_pPointer = SimObject;
    p_mNode = &SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v8 = SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v8->mNext = p_mpSimObject;
    p_mpSimObject->mPrev = v8;
    this->mpSimObject.mNext = p_mNode;
    p_mNode->mPrev = p_mpSimObject;
    return m_pPointer;
  }
  this->mFlags |= 1u;
  return 0i64;
}

// File Line: 137
// RVA: 0x23D9C0
UFG::qVector4 *__fastcall UFG::TriggerTarget::GetPos(UFG::TriggerTarget *this)
{
  UFG::TransformNodeComponent *m_pPointer; // rbx
  UFG::SimObject *SimObject; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpXform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  m_pPointer = (UFG::TransformNodeComponent *)this->mpXform.m_pPointer;
  if ( m_pPointer )
  {
LABEL_7:
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
    return &m_pPointer->mWorldTransform.v3;
  }
  SimObject = UFG::TriggerTarget::GetSimObject(this);
  if ( SimObject )
  {
    m_pPointer = SimObject->m_pTransformNodeComponent;
    if ( m_pPointer )
    {
      p_mpXform = &this->mpXform;
      if ( this->mpXform.m_pPointer )
      {
        mPrev = p_mpXform->mPrev;
        mNext = this->mpXform.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpXform->mPrev = p_mpXform;
        this->mpXform.mNext = &this->mpXform;
      }
      this->mpXform.m_pPointer = m_pPointer;
      v7 = m_pPointer->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v7->mNext = p_mpXform;
      p_mpXform->mPrev = v7;
      this->mpXform.mNext = &m_pPointer->m_SafePointerList.mNode;
      m_pPointer->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpXform;
      goto LABEL_7;
    }
  }
  this->mFlags |= 1u;
  return 0i64;
}

// File Line: 172
// RVA: 0x23E290
const char *__fastcall UFG::TriggerRegion::GetTypeName(UFG::TriggerRegion *this)
{
  return "TriggerRegion";
}

// File Line: 174
// RVA: 0x1470BA0
__int64 dynamic_initializer_for__UFG::TriggerRegion::msTriggerRegions__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::TriggerRegion::msTriggerRegions.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TriggerRegion::msTriggerRegions__);
}

// File Line: 175
// RVA: 0x1470B40
__int64 dynamic_initializer_for__UFG::TriggerRegion::msHotTriggerRegions__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TriggerRegion::msHotTriggerRegions__);
}

// File Line: 176
// RVA: 0x1470AB0
__int64 dynamic_initializer_for__UFG::TriggerRegion::msCullCheckingTriggerRegions__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TriggerRegion::msCullCheckingTriggerRegions__);
}

// File Line: 177
// RVA: 0x1470A90
__int64 dynamic_initializer_for__UFG::TriggerRegion::msChangedTriggers__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TriggerRegion::msChangedTriggers__);
}

// File Line: 178
// RVA: 0x1470B90
__int64 dynamic_initializer_for__UFG::TriggerRegion::msReuseableTargets__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TriggerRegion::msReuseableTargets__);
}

// File Line: 224
// RVA: 0x237DC0
void __fastcall UFG::TriggerRegion::TriggerRegion(
        UFG::TriggerRegion *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj,
        bool init)
{
  unsigned int mUID; // eax

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  mUID = name->mUID;
  this->UFG::qNodeRB<UFG::TriggerRegion>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::TriggerRegion>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::TriggerRegion>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::TriggerRegion>::mNode.mUID = mUID;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
  this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
  this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TriggerRegion::`vftable;
  this->mModeFlags = 0;
  this->mpRegion.mPrev = &this->mpRegion;
  this->mpRegion.mNext = &this->mpRegion;
  this->mpRegion.m_pPointer = 0i64;
  this->mTrackList.mNode.mPrev = &this->mTrackList.mNode;
  this->mTrackList.mNode.mNext = &this->mTrackList.mNode;
  this->mOnEnteredDelegate.m_Closure.m_pthis = 0i64;
  this->mOnEnteredDelegate.m_Closure.m_pFunction = 0i64;
  this->mOnExitedDelegate.m_Closure.m_pthis = 0i64;
  this->mOnExitedDelegate.m_Closure.m_pFunction = 0i64;
  this->mCullInfo = 0i64;
  this->mCullResults = 0i64;
  UFG::SimComponent::AddType(this, UFG::TriggerRegion::_TriggerRegionTypeUID, "TriggerRegion");
  if ( init )
    UFG::TriggerRegion::InitTrigger(this, pSimObj);
}

// File Line: 237
// RVA: 0x23E590
void __fastcall UFG::TriggerRegion::InitTrigger(UFG::TriggerRegion *this, UFG::SimObject *pSimObj)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mpRegion; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v13; // rax
  bool v14; // bp
  UFG::SimObject *v15; // rax
  UFG::SceneObjectProperties *v16; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  bool *v18; // rax
  bool v19; // si
  UFG::SimObject *v20; // rax
  UFG::qPropertySet *v21; // rcx
  bool *v22; // rax

  v2 = 0i64;
  if ( pSimObj )
    ComponentOfType = UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  p_mpRegion = &this->mpRegion;
  if ( this->mpRegion.m_pPointer )
  {
    mPrev = p_mpRegion->mPrev;
    mNext = this->mpRegion.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpRegion->mPrev = p_mpRegion;
    this->mpRegion.mNext = &this->mpRegion;
  }
  this->mpRegion.m_pPointer = ComponentOfType;
  if ( ComponentOfType )
  {
    p_mNode = &ComponentOfType->m_SafePointerList.mNode;
    v9 = ComponentOfType->m_SafePointerList.mNode.mPrev;
    v9->mNext = p_mpRegion;
    p_mpRegion->mPrev = v9;
    this->mpRegion.mNext = p_mNode;
    p_mNode->mPrev = p_mpRegion;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v13 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_TriggerOnFoot,
          DEPTH_RECURSE);
  if ( v13 )
    v14 = *v13;
  else
    v14 = 0;
  v15 = this->m_pSimObject;
  if ( v15 )
    v16 = v15->m_pSceneObj;
  else
    v16 = 0i64;
  mpConstProperties = v16->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = v16->mpConstProperties;
  v18 = UFG::qPropertySet::Get<bool>(
          mpConstProperties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_TriggerInVehicle,
          DEPTH_RECURSE);
  if ( v18 )
    v19 = *v18;
  else
    v19 = 0;
  v20 = this->m_pSimObject;
  if ( v20 )
    v2 = v20->m_pSceneObj;
  v21 = v2->mpWritableProperties;
  if ( !v21 )
    v21 = v2->mpConstProperties;
  v22 = UFG::qPropertySet::Get<bool>(v21, (UFG::qArray<unsigned long,0> *)&qSymbol_TriggerOnBike, DEPTH_RECURSE);
  if ( v22 )
    LOBYTE(v22) = *v22;
  if ( v14 )
    this->mModeFlags |= 0x100u;
  else
    this->mModeFlags &= ~0x100u;
  if ( v19 )
    this->mModeFlags |= 0x200u;
  else
    this->mModeFlags &= ~0x200u;
  if ( (_BYTE)v22 )
    this->mModeFlags |= 0x400u;
  else
    this->mModeFlags &= ~0x400u;
  UFG::qBaseTreeRB::Add(&UFG::TriggerRegion::msTriggerRegions.mTree, &this->UFG::qNodeRB<UFG::TriggerRegion>::mNode);
}

// File Line: 256
// RVA: 0x2388E0
void __fastcall UFG::TriggerRegion::~TriggerRegion(UFG::TriggerRegion *this)
{
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *p_mTrackList; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mPrev; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mpRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v12; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v13; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v14; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v15; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TriggerRegion::`vftable;
  p_mTrackList = &this->mTrackList;
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0>::DeleteNodes(&this->mTrackList);
  mPrev = p_mTrackList->mNode.mPrev;
  mNext = p_mTrackList->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mTrackList->mNode.mPrev = &p_mTrackList->mNode;
  p_mTrackList->mNode.mNext = &p_mTrackList->mNode;
  p_mpRegion = &this->mpRegion;
  if ( this->mpRegion.m_pPointer )
  {
    v6 = p_mpRegion->mPrev;
    v7 = this->mpRegion.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mpRegion->mPrev = p_mpRegion;
    this->mpRegion.mNext = &this->mpRegion;
  }
  this->mpRegion.m_pPointer = 0i64;
  v8 = p_mpRegion->mPrev;
  v9 = this->mpRegion.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mpRegion->mPrev = p_mpRegion;
  this->mpRegion.mNext = &this->mpRegion;
  v10 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev;
  v11 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
  v12 = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev;
  v13 = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
  this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
  v14 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mPrev;
  v15 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
  this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable;
  if ( (this->mFlags & 0x10000) != 0 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::MarkerBase::msMarkers,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::MarkerBase>);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 301
// RVA: 0x2431C0
void __fastcall UFG::TriggerRegion::OnDetach(UFG::TriggerRegion *this)
{
  CullInfo *mCullInfo; // rbx
  CullManager *v3; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *mPrev; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *mNext; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v6; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v7; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v8; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v9; // rax
  UFG::TriggerTarget *i; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v11; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v12; // rax

  mCullInfo = this->mCullInfo;
  if ( mCullInfo )
  {
    v3 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v3, 0i64, mCullInfo);
    this->mModeFlags &= ~0x800u;
    this->mCullInfo = 0i64;
    mPrev = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev;
    mNext = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
    this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
  }
  if ( (this->mModeFlags & 2) != 0 )
  {
    v6 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mPrev;
    v7 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
    this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
    v8 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev;
    v9 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
    this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
    this->mModeFlags &= ~2u;
  }
  for ( i = (UFG::TriggerTarget *)this->mTrackList.mNode.mNext;
        i != (UFG::TriggerTarget *)&this->mTrackList;
        i = (UFG::TriggerTarget *)this->mTrackList.mNode.mNext )
  {
    v11 = i->mPrev;
    v12 = i->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    i->mPrev = i;
    i->mNext = i;
    UFG::TriggerTarget::~TriggerTarget(i);
    operator delete[](i);
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::TriggerRegion::msTriggerRegions,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::TriggerRegion>);
}

// File Line: 342
// RVA: 0x23B8F0
void __fastcall UFG::TriggerRegion::EnableHot(UFG::TriggerRegion *this, bool makeHot)
{
  bool v3; // zf
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v4; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v5; // rax
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *p_mTrackList; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v7; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *mPrev; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *mNext; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rax

  if ( ((this->mModeFlags & 2) != 0) != makeHot )
  {
    v3 = !makeHot;
    v4 = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget>;
    if ( v3 )
    {
      mPrev = v4->mPrev;
      mNext = v4->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v4->mPrev = v4;
      v4->mNext = v4;
      v10 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev;
      v11 = this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
      this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
      this->mModeFlags &= ~2u;
    }
    else
    {
      v5 = UFG::TriggerRegion::msHotTriggerRegions.mNode.mPrev;
      p_mTrackList = &this->mTrackList;
      UFG::TriggerRegion::msHotTriggerRegions.mNode.mPrev->mNext = v4;
      v4->mPrev = v5;
      v4->mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *)&UFG::TriggerRegion::msHotTriggerRegions;
      UFG::TriggerRegion::msHotTriggerRegions.mNode.mPrev = v4;
      v7 = p_mTrackList->mNode.mNext;
      for ( LODWORD(p_mTrackList[-2].mNode.mPrev) |= 2u;
            v7 != (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)p_mTrackList;
            v7 = v7->mNext )
      {
        HIDWORD(v7[1].mPrev) = 1;
      }
      this->mModeFlags &= ~0x10000u;
    }
  }
}

// File Line: 367
// RVA: 0x23B650
void __fastcall UFG::TriggerRegion::EnableCullChecking(UFG::TriggerRegion *this, bool checkCulling)
{
  UFG::SimComponent *m_pPointer; // rdi
  CullManager *v4; // rax
  CullInfo *mCullInfo; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::TransformNodeComponent *m_pSimObject; // rbx
  CullInfo *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::qNode<UFG::TriggerRegion,CullInfo> *mNext; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *mPrev; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v14; // rax
  CullInfo *v15; // rbx
  CullManager *v16; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v17; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v18; // rax
  __int64 v19; // [rsp+30h] [rbp-28h] BYREF
  __int64 v20; // [rsp+38h] [rbp-20h]
  __int64 v21; // [rsp+40h] [rbp-18h]

  if ( checkCulling )
  {
    if ( !this->mCullInfo )
    {
      m_pPointer = this->mpRegion.m_pPointer;
      ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))m_pPointer[1].m_SafePointerList.mNode.mNext->mPrev[3].mNext)(m_pPointer[1].m_SafePointerList.mNode.mNext);
      v4 = CullManager::Instance();
      CullManager::AllocPersistentCullInfo(
        v4,
        &this->mCullResults,
        &this->mCullInfo,
        &gTriggerRegionCullLayer,
        this,
        this);
      v19 = 0i64;
      v20 = 0i64;
      v21 = 0i64;
      ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, __int64 *))m_pPointer[1].m_SafePointerList.mNode.mNext->mPrev[2].mNext)(
        m_pPointer[1].m_SafePointerList.mNode.mNext,
        &v19);
      mCullInfo = this->mCullInfo;
      v6 = *((float *)&v19 + 1);
      v7 = *(float *)&v20;
      m_pSimObject = (UFG::TransformNodeComponent *)m_pPointer->m_pSimObject;
      LODWORD(mCullInfo->mAABBMin[0]) = v19;
      mCullInfo->mAABBMin[1] = v6;
      mCullInfo->mAABBMin[2] = v7;
      v9 = this->mCullInfo;
      v10 = *(float *)&v21;
      v11 = *((float *)&v21 + 1);
      v9->mAABBMax[0] = *((float *)&v20 + 1);
      v9->mAABBMax[1] = v10;
      v9->mAABBMax[2] = v11;
      if ( m_pSimObject )
        m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
      this->mCullInfo->mpLocalWorld = &m_pSimObject->mWorldTransform.v0.x;
      mNext = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext;
      mPrev = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
      this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
      v14 = UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mPrev;
      UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
      this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev = v14;
      this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&UFG::TriggerRegion::msCullCheckingTriggerRegions;
      UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mPrev = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
    }
  }
  else
  {
    v15 = this->mCullInfo;
    if ( v15 )
    {
      v16 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v16, 0i64, v15);
      this->mModeFlags &= ~0x800u;
      this->mCullInfo = 0i64;
      v17 = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev;
      v18 = this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
      this->UFG::qNode<UFG::TriggerRegion,CullInfo>::mNext = &this->UFG::qNode<UFG::TriggerRegion,CullInfo>;
    }
  }
}

// File Line: 446
// RVA: 0x245D90
void __fastcall UFG::TriggerRegion::TrackTarget(UFG::TriggerRegion *this, UFG::SimObject *targetObj, bool *isInside)
{
  UFG::TriggerRegion::TrackTarget(this, &targetObj->m_Name, isInside);
}

// File Line: 454
// RVA: 0x245DA0
void __fastcall UFG::TriggerRegion::TrackTarget(UFG::TriggerRegion *this, UFG::qSymbol *targetName, bool *isInside)
{
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mNext; // rax
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *p_mTrackList; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::TriggerTarget *v9; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *mPrev; // rax
  UFG::qVector4 *Pos; // rax

  mNext = this->mTrackList.mNode.mNext;
  p_mTrackList = &this->mTrackList;
  if ( mNext == (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&this->mTrackList )
  {
LABEL_4:
    v8 = UFG::qMalloc(0x48ui64, "TriggerTarget", 0i64);
    v9 = (UFG::TriggerTarget *)v8;
    if ( v8 )
    {
      v8->mNext = v8;
      v8[1].mNext = v8;
      LODWORD(v8[2].mNext) = (UFG::qSymbol)targetName->mUID;
      HIDWORD(v8[2].mNext) = 1;
      v8[3].mNext = v8 + 3;
      v8[4].mNext = v8 + 3;
      v8[5].mNext = 0i64;
      v8[6].mNext = v8 + 6;
      v8[7].mNext = v8 + 6;
      v8[8].mNext = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    mPrev = p_mTrackList->mNode.mPrev;
    mPrev->mNext = v9;
    v9->mPrev = mPrev;
    v9->mNext = &p_mTrackList->mNode;
    p_mTrackList->mNode.mPrev = v9;
    this->mModeFlags |= 0x10u;
    if ( LocalPlayer && v9->mName.mUID == LocalPlayer->m_Name.mUID )
      this->mModeFlags |= 4u;
    if ( isInside )
    {
      Pos = UFG::TriggerTarget::GetPos(v9);
      if ( Pos )
        LOBYTE(Pos) = UFG::RegionComponent::IsHitPoint(
                        (UFG::RegionComponent *)this->mpRegion.m_pPointer,
                        (UFG::qVector3 *)Pos);
      *isInside = (char)Pos;
    }
  }
  else
  {
    while ( LODWORD(mNext[1].mPrev) != targetName->mUID )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)p_mTrackList )
        goto LABEL_4;
    }
  }
}

// File Line: 543
// RVA: 0x245270
void __fastcall UFG::TriggerRegion::ResetEvents(UFG::TriggerRegion *this)
{
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *i; // rax

  for ( i = this->mTrackList.mNode.mNext;
        i != (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&this->mTrackList;
        i = i->mNext )
  {
    HIDWORD(i[1].mPrev) = 1;
  }
  this->mModeFlags &= ~0x10000u;
}

// File Line: 558
// RVA: 0x243820
void __fastcall UFG::TriggerRegion::OnUpdate(UFG::TriggerRegion *this, UFG::TriggerUpdateContext *context)
{
  UFG::TriggerTarget *mNext; // rsi
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *p_mTrackList; // rbp
  char v4; // di
  bool updated; // al
  unsigned int mModeFlags; // ecx
  unsigned int v9; // ecx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *mPrev; // rax

  mNext = (UFG::TriggerTarget *)this->mTrackList.mNode.mNext;
  p_mTrackList = &this->mTrackList;
  v4 = 0;
  while ( mNext != (UFG::TriggerTarget *)p_mTrackList )
  {
    updated = UFG::TriggerRegion::UpdateTarget(this, mNext, context);
    mNext = (UFG::TriggerTarget *)mNext->mNext;
    if ( updated )
      v4 = 1;
  }
  mModeFlags = this->mModeFlags;
  if ( ((mModeFlags & 0x10012) == 65554) != v4 )
  {
    if ( v4 )
      v9 = mModeFlags | 0x10000;
    else
      v9 = mModeFlags & 0xFFFEFFFF;
    this->mModeFlags = v9;
    mPrev = UFG::TriggerRegion::msChangedTriggers.mNode.mPrev;
    UFG::TriggerRegion::msChangedTriggers.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
    this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mPrev = mPrev;
    this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>::mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&UFG::TriggerRegion::msChangedTriggers;
    UFG::TriggerRegion::msChangedTriggers.mNode.mPrev = &this->UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion>;
  }
}

// File Line: 594
// RVA: 0x2468E0
char __fastcall UFG::TriggerRegion::UpdateTarget(
        UFG::TriggerRegion *this,
        UFG::TriggerTarget *pTarget,
        UFG::TriggerUpdateContext *context)
{
  UFG::qVector3 *p_mPlayerPos; // rbp
  UFG::SimObject *SimObject; // rsi
  bool v8; // cl
  unsigned int mModeFlags; // edx
  bool v10; // zf
  bool v11; // di

  p_mPlayerPos = 0i64;
  SimObject = UFG::TriggerTarget::GetSimObject(pTarget);
  if ( SimObject == context->mpPlayer )
    p_mPlayerPos = &context->mPlayerPos;
  else
    UFG::TriggerTarget::GetPos(pTarget);
  v8 = p_mPlayerPos != 0i64;
  if ( p_mPlayerPos )
  {
    mModeFlags = this->mModeFlags;
    if ( (mModeFlags & 0x700) != 0 )
    {
      if ( SimObject )
      {
        if ( SimObject == context->mpPlayer )
        {
          if ( ((mModeFlags & 0x100) == 0 || !context->mIsPlayerOnFoot)
            && ((mModeFlags & 0x400) == 0 || !context->mIsPlayerOnBike) )
          {
            v10 = (this->mModeFlags & 0x200) == 0;
LABEL_17:
            if ( v10 || !context->mIsPlayerInVehicle )
            {
              v8 = 0;
              goto LABEL_21;
            }
            goto LABEL_19;
          }
          goto LABEL_19;
        }
        if ( (mModeFlags & 0x400) != 0 )
        {
          if ( (mModeFlags & 0x100) == 0 || !context->mIsPlayerOnFoot )
          {
            v10 = (this->mModeFlags & 0x200) == 0;
            goto LABEL_17;
          }
LABEL_19:
          v8 = 1;
        }
      }
    }
  }
LABEL_21:
  v11 = (pTarget->mFlags & 2) != 0;
  if ( v8 && UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)this->mpRegion.m_pPointer, p_mPlayerPos) )
  {
    if ( v11 )
      pTarget->mFlags &= ~4u;
    else
      pTarget->mFlags |= 6u;
    return 1;
  }
  else
  {
    if ( v11 )
    {
      pTarget->mFlags &= ~2u;
      pTarget->mFlags |= 4u;
    }
    else
    {
      pTarget->mFlags &= ~4u;
    }
    return 0;
  }
}

// File Line: 711
// RVA: 0x246620
void __fastcall UFG::TriggerRegion::UpdateAll(UFG::TriggerUpdateContext *context)
{
  UFG::qNode<UFG::TriggerRegion,CullInfo> *p_mNode; // rdx
  UFG::qList<UFG::TriggerRegion,CullInfo,1,0> *v3; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v4; // rcx
  UFG::qList<UFG::TriggerRegion,UFG::TriggerTarget,1,0> *v5; // rbx
  UFG::qList<UFG::TriggerRegion,UFG::TriggerRegion,1,0> *v6; // rbx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *i; // rcx
  _QWORD *p_mPrev; // r8
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *mPrev; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *mNext; // rax
  __int64 *v11; // rax
  __int64 **v12; // rbx
  __int64 **j; // rcx
  __int64 *v14; // rdx
  __int64 *v15; // rax
  __int64 **k; // rax
  _QWORD *v17; // rdx
  __int64 *v18; // rcx
  __int64 *v19; // rax
  __int64 *v20; // rcx
  __int64 **v21; // rax
  UFG::qSNode<CullResultBucket,CullResultBucket> *mHead; // rax
  UFG::qSNode<CullResultBucket,CullResultBucket> *v23; // rdx
  unsigned int v24; // r8d
  UFG::qSNode<CullResultBucket,CullResultBucket> *v25; // rcx
  _QWORD v26[5]; // [rsp+0h] [rbp-48h] BYREF
  __int64 *v27; // [rsp+28h] [rbp-20h] BYREF
  __int64 **v28; // [rsp+30h] [rbp-18h]

  v26[4] = -2i64;
  p_mNode = UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mNext - 10;
  if ( (UFG::qList<UFG::TriggerRegion,CullInfo,1,0> *)&UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mNext[-10] != &UFG::TriggerRegion::msCullCheckingTriggerRegions - 10 )
  {
    do
    {
      v3 = (UFG::qList<UFG::TriggerRegion,CullInfo,1,0> *)&p_mNode[10].mNext[-10];
      if ( p_mNode[17].mPrev )
        LODWORD(p_mNode[12].mPrev) = (__int64)p_mNode[12].mPrev & 0xFFFFE7FF | 0x800;
      else
        LODWORD(p_mNode[12].mPrev) &= ~0x800u;
      p_mNode = &v3->mNode;
    }
    while ( v3 != &UFG::TriggerRegion::msCullCheckingTriggerRegions - 10 );
  }
  v4 = UFG::TriggerRegion::msHotTriggerRegions.mNode.mNext - 9;
  if ( (UFG::qList<UFG::TriggerRegion,UFG::TriggerTarget,1,0> *)&UFG::TriggerRegion::msHotTriggerRegions.mNode.mNext[-9] != &UFG::TriggerRegion::msHotTriggerRegions - 9 )
  {
    do
    {
      v5 = (UFG::qList<UFG::TriggerRegion,UFG::TriggerTarget,1,0> *)&v4[9].mNext[-9];
      ((void (__fastcall *)(UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *, UFG::TriggerUpdateContext *))v4->mPrev[8].mNext)(
        v4,
        context);
      v4 = &v5->mNode;
    }
    while ( v5 != &UFG::TriggerRegion::msHotTriggerRegions - 9 );
  }
  v6 = &UFG::TriggerRegion::msChangedTriggers - 11;
  if ( (UFG::qList<UFG::TriggerRegion,UFG::TriggerRegion,1,0> *)&UFG::TriggerRegion::msChangedTriggers.mNode.mNext[-11] != &UFG::TriggerRegion::msChangedTriggers - 11 )
  {
    v27 = (__int64 *)&v27;
    v28 = &v27;
    for ( i = UFG::TriggerRegion::msChangedTriggers.mNode.mNext - 11;
          (UFG::qList<UFG::TriggerRegion,UFG::TriggerRegion,1,0> *)&UFG::TriggerRegion::msChangedTriggers.mNode.mNext[-11] != v6;
          i = UFG::TriggerRegion::msChangedTriggers.mNode.mNext - 11 )
    {
      p_mPrev = &i[11].mPrev;
      mPrev = i[11].mPrev;
      mNext = i[11].mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      i[11].mPrev = i + 11;
      i[11].mNext = i + 11;
      if ( ((__int64)i[12].mPrev & 0x10012) == 65554 )
      {
        v11 = v27;
        v27[1] = (__int64)p_mPrev;
        *p_mPrev = v11;
        i[11].mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v27;
        v27 = (__int64 *)&i[11];
      }
      else
      {
        ((void (__fastcall *)(UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *))i->mPrev[9].mNext)(i);
      }
    }
    v12 = (__int64 **)&v26[-17];
    for ( j = v28 - 22; v28 - 22 != v12; j = v28 - 22 )
    {
      v14 = j[22];
      v15 = j[23];
      v14[1] = (__int64)v15;
      *v15 = (__int64)v14;
      j[22] = (__int64 *)(j + 22);
      j[23] = (__int64 *)(j + 22);
      ((void (__fastcall *)(__int64 **))(*j)[18])(j);
    }
    for ( k = v28 - 22; v28 - 22 != v12; k = v28 - 22 )
    {
      v17 = k + 22;
      v18 = k[22];
      v19 = k[23];
      v18[1] = (__int64)v19;
      *v19 = (__int64)v18;
      *v17 = v17;
      v17[1] = v17;
      if ( v17 != (_QWORD *)176 )
        (*(void (__fastcall **)(_QWORD *, __int64))*(v17 - 22))(v17 - 22, 1i64);
    }
    v20 = v27;
    v21 = v28;
    v27[1] = (__int64)v28;
    *v21 = v20;
    v27 = (__int64 *)&v27;
    v28 = &v27;
  }
  mHead = 0i64;
  if ( gTriggerRegionCullLayer.mDrawEnabled )
    mHead = gTriggerRegionCullLayer.mCullResultBuckets[0].mHead;
  v23 = mHead;
  v24 = 0;
  while ( v23 )
  {
    v25 = v23[v24 + 3].mNext;
    LODWORD(v25[24].mNext) |= 0x1000u;
    if ( ++v24 == LODWORD(v23[1].mNext) )
    {
      v23 = v23->mNext;
      v24 = 0;
    }
  }
}

// File Line: 876
// RVA: 0x240660
bool __fastcall UFG::TriggerRegion::IsHitPoint(UFG::TriggerRegion *this, UFG::qVector3 *pos)
{
  return UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)this->mpRegion.m_pPointer, pos);
}

// File Line: 885
// RVA: 0x242F30
bool __fastcall UFG::TriggerRegion::IsVisibleOnScreen(UFG::TriggerRegion *this)
{
  if ( this->mCullInfo )
    return (this->mModeFlags & 0x1000) != 0;
  UFG::TriggerRegion::EnableCullChecking(this, 1);
  return 0;
}

// File Line: 931
// RVA: 0x2432D0
void __fastcall UFG::TriggerRegion::OnEntered(UFG::TriggerRegion *this)
{
  fastdelegate::detail::GenericClass *m_pthis; // rcx

  m_pthis = this->mOnEnteredDelegate.m_Closure.m_pthis;
  if ( m_pthis || this->mOnEnteredDelegate.m_Closure.m_pFunction )
    ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::TriggerRegion *))this->mOnEnteredDelegate.m_Closure.m_pFunction)(
      m_pthis,
      this);
}

// File Line: 946
// RVA: 0x243300
void __fastcall UFG::TriggerRegion::OnExited(UFG::TriggerRegion *this)
{
  fastdelegate::detail::GenericClass *m_pthis; // rcx

  m_pthis = this->mOnExitedDelegate.m_Closure.m_pthis;
  if ( m_pthis || this->mOnExitedDelegate.m_Closure.m_pFunction )
    ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::TriggerRegion *))this->mOnExitedDelegate.m_Closure.m_pFunction)(
      m_pthis,
      this);
}

// File Line: 957
// RVA: 0x23E440
bool __fastcall UFG::TriggerRegion::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::SchemaDef *Schema; // rax

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  Schema = UFG::PropertySetManager::GetSchema((UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTriggerRegion);
  if ( Schema )
    return UFG::qPropertySet::PropertyExists(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&Schema->mPropertyName,
             DEPTH_RECURSE) != 0i64;
  else
    return UFG::qPropertySet::GetParentFromName(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentTriggerRegion,
             DEPTH_RECURSE) != 0i64;
}

// File Line: 967
// RVA: 0x244210
void __fastcall UFG::TriggerRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x120ui64, "TriggerRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, pSceneObj->m_NameUID);
    UFG::TriggerRegion::TriggerRegion((UFG::TriggerRegion *)v3, v5, m_pSimObject, 1);
  }
}

