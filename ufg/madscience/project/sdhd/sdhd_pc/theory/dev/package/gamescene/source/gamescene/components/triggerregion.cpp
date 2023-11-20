// File Line: 60
// RVA: 0x14754B0
__int64 dynamic_initializer_for__gTriggerRegionCullLayer__()
{
  CullLayer::CullLayer(&gTriggerRegionCullLayer, 0, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__gTriggerRegionCullLayer__);
}

// File Line: 107
// RVA: 0x23E080
UFG::SimObject *__fastcall UFG::TriggerTarget::GetSimObject(UFG::TriggerTarget *this)
{
  UFG::SimObject *v1; // r9
  UFG::TriggerTarget *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qBaseNodeRB **v7; // rcx
  UFG::qBaseNodeRB *v8; // rax

  v1 = this->mpSimObject.m_pPointer;
  v2 = this;
  if ( v1 )
    return v1;
  v3 = UFG::Simulation::GetSimObject(&UFG::gSim, &this->mName);
  v1 = (UFG::SimObject *)v3;
  if ( v3 )
  {
    v4 = &v2->mpSimObject;
    if ( v2->mpSimObject.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v2->mpSimObject.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v2->mpSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpSimObject.mPrev;
    }
    v2->mpSimObject.m_pPointer = (UFG::SimObject *)v3;
    v7 = v3->mChild;
    v8 = v3->mChild[0];
    v8->mChild[0] = (UFG::qBaseNodeRB *)v4;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v8;
    v2->mpSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v7;
    *v7 = (UFG::qBaseNodeRB *)v4;
    return v1;
  }
  v2->mFlags |= 1u;
  return 0i64;
}

// File Line: 137
// RVA: 0x23D9C0
UFG::qVector4 *__fastcall UFG::TriggerTarget::GetPos(UFG::TriggerTarget *this)
{
  UFG::TransformNodeComponent *v1; // rbx
  UFG::TriggerTarget *v2; // rdi
  UFG::SimObject *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = (UFG::TransformNodeComponent *)this->mpXform.m_pPointer;
  v2 = this;
  if ( v1 )
  {
LABEL_7:
    UFG::TransformNodeComponent::UpdateWorldTransform(v1);
    return &v1->mWorldTransform.v3;
  }
  v3 = UFG::TriggerTarget::GetSimObject(this);
  if ( v3 )
  {
    v1 = v3->m_pTransformNodeComponent;
    if ( v1 )
    {
      v4 = &v2->mpXform;
      if ( v2->mpXform.m_pPointer )
      {
        v5 = v4->mPrev;
        v6 = v2->mpXform.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v2->mpXform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpXform.mPrev;
      }
      v2->mpXform.m_pPointer = (UFG::SimComponent *)&v1->vfptr;
      v7 = v1->m_SafePointerList.mNode.mPrev;
      v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v4->mPrev = v7;
      v2->mpXform.mNext = &v1->m_SafePointerList.mNode;
      v1->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      goto LABEL_7;
    }
  }
  v2->mFlags |= 1u;
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
  return atexit(dynamic_atexit_destructor_for__UFG::TriggerRegion::msTriggerRegions__);
}

// File Line: 175
// RVA: 0x1470B40
__int64 dynamic_initializer_for__UFG::TriggerRegion::msHotTriggerRegions__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TriggerRegion::msHotTriggerRegions__);
}

// File Line: 176
// RVA: 0x1470AB0
__int64 dynamic_initializer_for__UFG::TriggerRegion::msCullCheckingTriggerRegions__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TriggerRegion::msCullCheckingTriggerRegions__);
}

// File Line: 177
// RVA: 0x1470A90
__int64 dynamic_initializer_for__UFG::TriggerRegion::msChangedTriggers__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TriggerRegion::msChangedTriggers__);
}

// File Line: 178
// RVA: 0x1470B90
__int64 dynamic_initializer_for__UFG::TriggerRegion::msReuseableTargets__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TriggerRegion::msReuseableTargets__);
}

// File Line: 224
// RVA: 0x237DC0
void __fastcall UFG::TriggerRegion::TriggerRegion(UFG::TriggerRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj, bool init)
{
  bool v4; // di
  UFG::SimObject *v5; // rbp
  UFG::qSymbol *v6; // rbx
  UFG::TriggerRegion *v7; // rsi
  unsigned int v8; // eax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v9; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v10; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v12; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *v13; // [rsp+58h] [rbp+10h]

  v4 = init;
  v5 = pSimObj;
  v6 = name;
  v7 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v8 = v6->mUID;
  v7->mNode.mParent = 0i64;
  v7->mNode.mChild[0] = 0i64;
  v7->mNode.mChild[1] = 0i64;
  v7->mNode.mUID = v8;
  v9 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *)&v7->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v10 = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&v7->mPrev;
  v10->mPrev = v10;
  v10->mNext = v10;
  v11 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v7->mPrev;
  v11->mPrev = v11;
  v11->mNext = v11;
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TriggerRegion::`vftable';
  v7->mModeFlags = 0;
  v12 = &v7->mpRegion;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v7->mpRegion.m_pPointer = 0i64;
  v13 = &v7->mTrackList;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v7->mOnEnteredDelegate.m_Closure.m_pthis = 0i64;
  v7->mOnEnteredDelegate.m_Closure.m_pFunction = 0i64;
  v7->mOnExitedDelegate.m_Closure.m_pthis = 0i64;
  v7->mOnExitedDelegate.m_Closure.m_pFunction = 0i64;
  v7->mCullInfo = 0i64;
  v7->mCullResults = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v7->vfptr,
    UFG::TriggerRegion::_TriggerRegionTypeUID,
    "TriggerRegion");
  if ( v4 )
    UFG::TriggerRegion::InitTrigger(v7, v5);
}

// File Line: 237
// RVA: 0x23E590
void __fastcall UFG::TriggerRegion::InitTrigger(UFG::TriggerRegion *this, UFG::SimObject *pSimObj)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::TriggerRegion *v3; // rbx
  UFG::SimComponent *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SceneObjectProperties *v11; // rax
  UFG::qPropertySet *v12; // rcx
  bool *v13; // rax
  bool v14; // bp
  UFG::SimObject *v15; // rax
  UFG::SceneObjectProperties *v16; // rax
  UFG::qPropertySet *v17; // rcx
  bool *v18; // rax
  bool v19; // si
  UFG::SimObject *v20; // rax
  UFG::qPropertySet *v21; // rcx
  bool *v22; // rax

  v2 = 0i64;
  v3 = this;
  if ( pSimObj )
    v4 = UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
  else
    v4 = 0i64;
  v5 = &v3->mpRegion;
  if ( v3->mpRegion.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v3->mpRegion.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->mpRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mpRegion.mPrev;
  }
  v3->mpRegion.m_pPointer = v4;
  if ( v4 )
  {
    v8 = &v4->m_SafePointerList;
    v9 = v4->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v9;
    v3->mpRegion.mNext = &v8->mNode;
    v8->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v10 = v3->m_pSimObject;
  if ( v10 )
    v11 = v10->m_pSceneObj;
  else
    v11 = 0i64;
  v12 = v11->mpWritableProperties;
  if ( !v12 )
    v12 = v11->mpConstProperties;
  v13 = UFG::qPropertySet::Get<bool>(v12, (UFG::qSymbol *)&qSymbol_TriggerOnFoot.mUID, DEPTH_RECURSE);
  if ( v13 )
    v14 = *v13;
  else
    v14 = 0;
  v15 = v3->m_pSimObject;
  if ( v15 )
    v16 = v15->m_pSceneObj;
  else
    v16 = 0i64;
  v17 = v16->mpWritableProperties;
  if ( !v17 )
    v17 = v16->mpConstProperties;
  v18 = UFG::qPropertySet::Get<bool>(v17, (UFG::qSymbol *)&qSymbol_TriggerInVehicle.mUID, DEPTH_RECURSE);
  if ( v18 )
    v19 = *v18;
  else
    v19 = 0;
  v20 = v3->m_pSimObject;
  if ( v20 )
    v2 = v20->m_pSceneObj;
  v21 = v2->mpWritableProperties;
  if ( !v21 )
    v21 = v2->mpConstProperties;
  v22 = UFG::qPropertySet::Get<bool>(v21, (UFG::qSymbol *)&qSymbol_TriggerOnBike.mUID, DEPTH_RECURSE);
  if ( v22 )
    LOBYTE(v22) = *v22;
  if ( v14 )
    v3->mModeFlags |= 0x100u;
  else
    v3->mModeFlags &= 0xFFFFFEFF;
  if ( v19 )
    v3->mModeFlags |= 0x200u;
  else
    v3->mModeFlags &= 0xFFFFFDFF;
  if ( (_BYTE)v22 )
    v3->mModeFlags |= 0x400u;
  else
    v3->mModeFlags &= 0xFFFFFBFF;
  UFG::qBaseTreeRB::Add(&UFG::TriggerRegion::msTriggerRegions.mTree, &v3->mNode);
}

// File Line: 256
// RVA: 0x2388E0
void __fastcall UFG::TriggerRegion::~TriggerRegion(UFG::TriggerRegion *this)
{
  UFG::TriggerRegion *v1; // rdi
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *v2; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v3; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v12; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v13; // rdx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v14; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v15; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v16; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v17; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TriggerRegion::`vftable';
  v2 = &this->mTrackList;
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0>::DeleteNodes(&this->mTrackList);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v5 = &v1->mpRegion;
  if ( v1->mpRegion.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mpRegion.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mpRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpRegion.mPrev;
  }
  v1->mpRegion.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mpRegion.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mpRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpRegion.mPrev;
  v10 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  v13 = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&v1->mPrev;
  v14 = v1->mPrev;
  v15 = v1->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v13->mPrev = v13;
  v13->mNext = v13;
  v16 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *)&v1->mPrev;
  v17 = v1->mPrev;
  v18 = v1->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v16->mPrev = v16;
  v16->mNext = v16;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable';
  if ( v1->mFlags & 0x10000 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::MarkerBase::msMarkers,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 301
// RVA: 0x2431C0
void __fastcall UFG::TriggerRegion::OnDetach(UFG::TriggerRegion *this)
{
  CullInfo *v1; // rbx
  UFG::TriggerRegion *v2; // rdi
  CullManager *v3; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v4; // rdx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v5; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v6; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v7; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v8; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v9; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v12; // rax
  UFG::TriggerTarget *i; // rbx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v14; // rdx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v15; // rax

  v1 = this->mCullInfo;
  v2 = this;
  if ( v1 )
  {
    v3 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v3, 0i64, v1);
    v2->mModeFlags &= 0xFFFFF7FF;
    v2->mCullInfo = 0i64;
    v4 = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&v2->mPrev;
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    v4->mNext = v4;
  }
  if ( (v2->mModeFlags >> 1) & 1 )
  {
    v7 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *)&v2->mPrev;
    v8 = v2->mPrev;
    v9 = v2->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = v7;
    v7->mNext = v7;
    v10 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v2->mPrev;
    v11 = v2->mPrev;
    v12 = v2->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = v10;
    v10->mNext = v10;
    v2->mModeFlags &= 0xFFFFFFFD;
  }
  for ( i = (UFG::TriggerTarget *)v2->mTrackList.mNode.mNext;
        i != (UFG::TriggerTarget *)&v2->mTrackList;
        i = (UFG::TriggerTarget *)v2->mTrackList.mNode.mNext )
  {
    v14 = i->mPrev;
    v15 = i->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    i->mPrev = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&i->mPrev;
    UFG::TriggerTarget::~TriggerTarget(i);
    operator delete[](i);
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::TriggerRegion::msTriggerRegions,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v2->mNode);
}

// File Line: 342
// RVA: 0x23B8F0
void __fastcall UFG::TriggerRegion::EnableHot(UFG::TriggerRegion *this, bool makeHot)
{
  UFG::TriggerRegion *v2; // r8
  bool v3; // zf
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v4; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v5; // rax
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *v6; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v7; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v8; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v9; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v12; // rax

  v2 = this;
  if ( ((this->mModeFlags >> 1) & 1) != makeHot )
  {
    v3 = makeHot == 0;
    v4 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *)&this->mPrev;
    if ( v3 )
    {
      v8 = v4->mPrev;
      v9 = v4->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v4->mPrev = v4;
      v4->mNext = v4;
      v10 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v2->mPrev;
      v11 = v2->mPrev;
      v12 = v2->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v10->mPrev = v10;
      v10->mNext = v10;
      v2->mModeFlags &= 0xFFFFFFFD;
    }
    else
    {
      v5 = UFG::TriggerRegion::msHotTriggerRegions.mNode.mPrev;
      v6 = &this->mTrackList;
      UFG::TriggerRegion::msHotTriggerRegions.mNode.mPrev->mNext = v4;
      v4->mPrev = v5;
      v4->mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *)&UFG::TriggerRegion::msHotTriggerRegions;
      UFG::TriggerRegion::msHotTriggerRegions.mNode.mPrev = v4;
      v7 = v6->mNode.mNext;
      for ( LODWORD(v6[-2].mNode.mPrev) |= 2u; v7 != (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)v6; v7 = v7->mNext )
        HIDWORD(v7[1].mPrev) = 1;
      v2->mModeFlags &= 0xFFFEFFFF;
    }
  }
}

// File Line: 367
// RVA: 0x23B650
void __fastcall UFG::TriggerRegion::EnableCullChecking(UFG::TriggerRegion *this, bool checkCulling)
{
  UFG::TriggerRegion *cull_info_param0; // rsi
  UFG::SimComponent *v3; // rdi
  CullManager *v4; // rax
  _DWORD *v5; // rax
  int v6; // xmm1_4
  int v7; // xmm2_4
  UFG::TransformNodeComponent *v8; // rbx
  CullInfo *v9; // rax
  __int64 v10; // kr00_8
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v11; // rdx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v12; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v13; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v14; // rax
  CullInfo *v15; // rbx
  CullManager *v16; // rax
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v17; // rdx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v18; // rcx
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v19; // rax
  __int64 v20; // [rsp+30h] [rbp-28h]
  __int64 v21; // [rsp+38h] [rbp-20h]
  __int64 v22; // [rsp+40h] [rbp-18h]

  cull_info_param0 = this;
  if ( checkCulling )
  {
    if ( !this->mCullInfo )
    {
      v3 = this->mpRegion.m_pPointer;
      ((void (*)(void))v3[1].m_SafePointerList.mNode.mNext->mPrev[3].mNext)();
      v4 = CullManager::Instance();
      CullManager::AllocPersistentCullInfo(
        v4,
        &cull_info_param0->mCullResults,
        &cull_info_param0->mCullInfo,
        &gTriggerRegionCullLayer,
        cull_info_param0,
        cull_info_param0);
      v20 = 0i64;
      v21 = 0i64;
      v22 = 0i64;
      ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, __int64 *))v3[1].m_SafePointerList.mNode.mNext->mPrev[2].mNext)(
        v3[1].m_SafePointerList.mNode.mNext,
        &v20);
      v5 = (_DWORD *)cull_info_param0->mCullInfo->mAABBMin;
      v6 = HIDWORD(v20);
      v7 = v21;
      v8 = (UFG::TransformNodeComponent *)v3->m_pSimObject;
      *v5 = v20;
      v5[1] = v6;
      v5[2] = v7;
      v9 = cull_info_param0->mCullInfo;
      v10 = v22;
      v9->mAABBMax[0] = *((float *)&v21 + 1);
      *(_QWORD *)&v9->mAABBMax[1] = v10;
      if ( v8 )
        v8 = (UFG::TransformNodeComponent *)v8->mChildren.mNode.mNext;
      UFG::TransformNodeComponent::UpdateWorldTransform(v8);
      v11 = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&cull_info_param0->mPrev;
      cull_info_param0->mCullInfo->mpLocalWorld = &v8->mWorldTransform.v0.x;
      v12 = cull_info_param0->mNext;
      v13 = cull_info_param0->mPrev;
      v13->mNext = v12;
      v12->mPrev = v13;
      v11->mPrev = v11;
      v11->mNext = v11;
      v14 = UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mPrev;
      UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mPrev->mNext = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&cull_info_param0->mPrev;
      v11->mPrev = v14;
      v11->mNext = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&UFG::TriggerRegion::msCullCheckingTriggerRegions;
      UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mPrev = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&cull_info_param0->mPrev;
    }
  }
  else
  {
    v15 = this->mCullInfo;
    if ( v15 )
    {
      v16 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v16, 0i64, v15);
      v17 = (UFG::qNode<UFG::TriggerRegion,CullInfo> *)&cull_info_param0->mPrev;
      cull_info_param0->mModeFlags &= 0xFFFFF7FF;
      cull_info_param0->mCullInfo = 0i64;
      v18 = cull_info_param0->mPrev;
      v19 = cull_info_param0->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = v17;
      v17->mNext = v17;
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
  bool *v3; // rsi
  UFG::qSymbol *v4; // r14
  UFG::TriggerRegion *v5; // rdi
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v6; // rax
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::TriggerTarget *v9; // rcx
  UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *v10; // rax
  UFG::qVector4 *v11; // rax
  UFG::allocator::free_link *v12; // [rsp+68h] [rbp+20h]
  UFG::allocator::free_link *v13; // [rsp+68h] [rbp+20h]

  v3 = isInside;
  v4 = targetName;
  v5 = this;
  v6 = this->mTrackList.mNode.mNext;
  v7 = &this->mTrackList.mNode;
  if ( v6 == (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&this->mTrackList )
  {
LABEL_4:
    v8 = UFG::qMalloc(0x48ui64, "TriggerTarget", 0i64);
    v9 = (UFG::TriggerTarget *)v8;
    if ( v8 )
    {
      v8->mNext = v8;
      v8[1].mNext = v8;
      LODWORD(v8[2].mNext) = (UFG::qSymbol)v4->mUID;
      HIDWORD(v8[2].mNext) = 1;
      v12 = v8 + 3;
      v12->mNext = v12;
      v12[1].mNext = v12;
      v8[5].mNext = 0i64;
      v13 = v8 + 6;
      v13->mNext = v13;
      v13[1].mNext = v13;
      v8[8].mNext = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = v7->mPrev;
    v10->mNext = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&v9->mPrev;
    v9->mPrev = v10;
    v9->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::TriggerTarget,UFG::TriggerTarget> *)&v9->mPrev;
    v5->mModeFlags |= 0x10u;
    if ( LocalPlayer && v9->mName.mUID == LocalPlayer->m_Name.mUID )
      v5->mModeFlags |= 4u;
    if ( v3 )
    {
      v11 = UFG::TriggerTarget::GetPos(v9);
      if ( v11 )
        LOBYTE(v11) = UFG::RegionComponent::IsHitPoint(
                        (UFG::RegionComponent *)v5->mpRegion.m_pPointer,
                        (UFG::qVector3 *)v11);
      *v3 = (char)v11;
    }
  }
  else
  {
    while ( LODWORD(v6[1].mPrev) != targetName->mUID )
    {
      v6 = v6->mNext;
      if ( v6 == v7 )
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
  this->mModeFlags &= 0xFFFEFFFF;
}

// File Line: 558
// RVA: 0x243820
void __fastcall UFG::TriggerRegion::OnUpdate(UFG::TriggerRegion *this, UFG::TriggerUpdateContext *context)
{
  UFG::TriggerTarget *v2; // rsi
  UFG::qList<UFG::TriggerTarget,UFG::TriggerTarget,1,0> *v3; // rbp
  char v4; // di
  UFG::TriggerUpdateContext *v5; // r14
  UFG::TriggerRegion *v6; // rbx
  bool v7; // al
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rax
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v11; // rcx

  v2 = (UFG::TriggerTarget *)this->mTrackList.mNode.mNext;
  v3 = &this->mTrackList;
  v4 = 0;
  v5 = context;
  v6 = this;
  if ( v2 != (UFG::TriggerTarget *)&this->mTrackList )
  {
    do
    {
      v7 = UFG::TriggerRegion::UpdateTarget(v6, v2, v5);
      v2 = (UFG::TriggerTarget *)v2->mNext;
      if ( v7 )
        v4 = 1;
    }
    while ( v2 != (UFG::TriggerTarget *)v3 );
  }
  v8 = v6->mModeFlags;
  if ( ((v6->mModeFlags & 0x10012) == 65554) != v4 )
  {
    if ( v4 )
      v9 = v8 | 0x10000;
    else
      v9 = v8 & 0xFFFEFFFF;
    v6->mModeFlags = v9;
    v10 = UFG::TriggerRegion::msChangedTriggers.mNode.mPrev;
    v11 = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v6->mPrev;
    UFG::TriggerRegion::msChangedTriggers.mNode.mPrev->mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v6->mPrev;
    v11->mPrev = v10;
    v11->mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&UFG::TriggerRegion::msChangedTriggers;
    UFG::TriggerRegion::msChangedTriggers.mNode.mPrev = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v6->mPrev;
  }
}

// File Line: 594
// RVA: 0x2468E0
char __fastcall UFG::TriggerRegion::UpdateTarget(UFG::TriggerRegion *this, UFG::TriggerTarget *pTarget, UFG::TriggerUpdateContext *context)
{
  UFG::TriggerRegion *v3; // r14
  UFG::TriggerUpdateContext *v4; // rdi
  UFG::TriggerTarget *v5; // rbx
  UFG::qVector3 *v6; // rbp
  UFG::SimObject *v7; // rsi
  bool v8; // cl
  unsigned int v9; // edx
  unsigned int v10; // eax
  char v11; // al
  bool v12; // zf
  char v13; // di
  char result; // al

  v3 = this;
  v4 = context;
  v5 = pTarget;
  v6 = 0i64;
  v7 = UFG::TriggerTarget::GetSimObject(pTarget);
  if ( v7 == v4->mpPlayer )
    v6 = &v4->mPlayerPos;
  else
    UFG::TriggerTarget::GetPos(v5);
  v8 = v6 != 0i64;
  if ( v6 )
  {
    v9 = v3->mModeFlags;
    if ( v9 & 0x700 )
    {
      if ( v7 )
      {
        v10 = v9 >> 10;
        if ( v7 == v4->mpPlayer )
        {
          v11 = v10 & 1;
          if ( (!(v9 & 0x100) || !v4->mIsPlayerOnFoot) && (!v11 || !v4->mIsPlayerOnBike) )
          {
            v12 = ((v9 >> 9) & 1) == 0;
LABEL_17:
            if ( v12 || !v4->mIsPlayerInVehicle )
            {
              v8 = 0;
              goto LABEL_21;
            }
            goto LABEL_19;
          }
          goto LABEL_19;
        }
        if ( v10 & 1 )
        {
          if ( !(v9 & 0x100) || !v4->mIsPlayerOnFoot )
          {
            v12 = ((v9 >> 9) & 1) == 0;
            goto LABEL_17;
          }
LABEL_19:
          v8 = 1;
          goto LABEL_21;
        }
      }
    }
  }
LABEL_21:
  v13 = (v5->mFlags >> 1) & 1;
  if ( v8 && UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)v3->mpRegion.m_pPointer, v6) )
  {
    if ( v13 )
      v5->mFlags &= 0xFFFFFFFB;
    else
      v5->mFlags |= 6u;
    result = 1;
  }
  else
  {
    if ( v13 )
    {
      v5->mFlags &= 0xFFFFFFFD;
      v5->mFlags |= 4u;
    }
    else
    {
      v5->mFlags &= 0xFFFFFFFB;
    }
    result = 0;
  }
  return result;
}

// File Line: 711
// RVA: 0x246620
void __fastcall UFG::TriggerRegion::UpdateAll(UFG::TriggerUpdateContext *context)
{
  UFG::TriggerUpdateContext *v1; // rsi
  UFG::qNode<UFG::TriggerRegion,CullInfo> *v2; // rdx
  UFG::qList<UFG::TriggerRegion,CullInfo,1,0> *v3; // rcx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerTarget> *v4; // rcx
  UFG::qList<UFG::TriggerRegion,UFG::TriggerTarget,1,0> *v5; // rbx
  UFG::qList<UFG::TriggerRegion,UFG::TriggerRegion,1,0> *v6; // rbx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *i; // rcx
  _QWORD *v8; // r8
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v9; // rdx
  UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *v10; // rax
  __int64 *v11; // rax
  __int64 **v12; // rbx
  __int64 **j; // rcx
  _QWORD *v14; // r8
  __int64 *v15; // rdx
  __int64 *v16; // rax
  __int64 k; // rax
  _QWORD *v18; // rdx
  __int64 v19; // rcx
  _QWORD *v20; // rax
  __int64 *v21; // rcx
  __int64 **v22; // rax
  UFG::qSNode<CullResultBucket,CullResultBucket> *v23; // rax
  UFG::qSNode<CullResultBucket,CullResultBucket> *v24; // rdx
  unsigned int v25; // er8
  UFG::qSNode<CullResultBucket,CullResultBucket> *v26; // rcx
  __int64 v27; // [rsp+0h] [rbp-48h]
  __int64 v28; // [rsp+20h] [rbp-28h]
  __int64 *v29; // [rsp+28h] [rbp-20h]
  __int64 **v30; // [rsp+30h] [rbp-18h]

  v28 = -2i64;
  v1 = context;
  v2 = UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mNext - 10;
  if ( (UFG::qList<UFG::TriggerRegion,CullInfo,1,0> *)&UFG::TriggerRegion::msCullCheckingTriggerRegions.mNode.mNext[-10] != &UFG::TriggerRegion::msCullCheckingTriggerRegions - 10 )
  {
    do
    {
      v3 = (UFG::qList<UFG::TriggerRegion,CullInfo,1,0> *)&v2[10].mNext[-10];
      if ( v2[17].mPrev )
        LODWORD(v2[12].mPrev) = (_QWORD)v2[12].mPrev & 0xFFFFEFFF | 0x800;
      else
        LODWORD(v2[12].mPrev) &= 0xFFFFF7FF;
      v2 = &v3->mNode;
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
        v1);
      v4 = &v5->mNode;
    }
    while ( v5 != &UFG::TriggerRegion::msHotTriggerRegions - 9 );
  }
  v6 = &UFG::TriggerRegion::msChangedTriggers - 11;
  if ( (UFG::qList<UFG::TriggerRegion,UFG::TriggerRegion,1,0> *)&UFG::TriggerRegion::msChangedTriggers.mNode.mNext[-11] != &UFG::TriggerRegion::msChangedTriggers - 11 )
  {
    v29 = (__int64 *)&v29;
    v30 = &v29;
    for ( i = UFG::TriggerRegion::msChangedTriggers.mNode.mNext - 11;
          (UFG::qList<UFG::TriggerRegion,UFG::TriggerRegion,1,0> *)&UFG::TriggerRegion::msChangedTriggers.mNode.mNext[-11] != v6;
          i = UFG::TriggerRegion::msChangedTriggers.mNode.mNext - 11 )
    {
      v8 = &i[11].mPrev;
      v9 = i[11].mPrev;
      v10 = i[11].mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      *v8 = v8;
      v8[1] = v8;
      if ( ((_QWORD)i[12].mPrev & 0x10012) == 65554 )
      {
        v11 = v29;
        v29[1] = (__int64)v8;
        *v8 = v11;
        i[11].mNext = (UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *)&v29;
        v29 = (__int64 *)&i[11];
      }
      else
      {
        ((void (__cdecl *)(UFG::qNode<UFG::TriggerRegion,UFG::TriggerRegion> *))i->mPrev[9].mNext)(i);
      }
    }
    v12 = (__int64 **)(&v27 - 17);
    for ( j = v30 - 22; v30 - 22 != v12; j = v30 - 22 )
    {
      v14 = j + 22;
      v15 = j[22];
      v16 = j[23];
      v15[1] = (__int64)v16;
      *v16 = (__int64)v15;
      *v14 = v14;
      v14[1] = v14;
      ((void (__cdecl *)(__int64 **))(*j)[18])(j);
    }
    for ( k = (__int64)(v30 - 22); v30 - 22 != v12; k = (__int64)(v30 - 22) )
    {
      v18 = (_QWORD *)(k + 176);
      v19 = *(_QWORD *)(k + 176);
      v20 = *(_QWORD **)(k + 184);
      *(_QWORD *)(v19 + 8) = v20;
      *v20 = v19;
      *v18 = v18;
      v18[1] = v18;
      if ( v18 != (_QWORD *)176 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v18 - 22))(v18 - 22, 1i64);
    }
    v21 = v29;
    v22 = v30;
    v29[1] = (__int64)v30;
    *v22 = v21;
    v29 = (__int64 *)&v29;
    v30 = &v29;
  }
  v23 = 0i64;
  if ( gTriggerRegionCullLayer.mDrawEnabled )
    v23 = gTriggerRegionCullLayer.mCullResultBuckets[0].mHead;
  v24 = v23;
  v25 = 0;
  while ( v24 )
  {
    v26 = v24[v25 + 3].mNext;
    LODWORD(v26[24].mNext) |= 0x1000u;
    if ( ++v25 == LODWORD(v24[1].mNext) )
    {
      v24 = v24->mNext;
      v25 = 0;
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
    return (this->mModeFlags >> 12) & 1;
  UFG::TriggerRegion::EnableCullChecking(this, 1);
  return 0;
}

// File Line: 931
// RVA: 0x2432D0
void __fastcall UFG::TriggerRegion::OnEntered(UFG::TriggerRegion *this)
{
  UFG::TriggerRegion *v1; // rax
  fastdelegate::detail::GenericClass *v2; // rcx

  v1 = this;
  v2 = this->mOnEnteredDelegate.m_Closure.m_pthis;
  if ( v2 || v1->mOnEnteredDelegate.m_Closure.m_pFunction )
    ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::TriggerRegion *))v1->mOnEnteredDelegate.m_Closure.m_pFunction)(
      v2,
      v1);
}

// File Line: 946
// RVA: 0x243300
void __fastcall UFG::TriggerRegion::OnExited(UFG::TriggerRegion *this)
{
  UFG::TriggerRegion *v1; // rax
  fastdelegate::detail::GenericClass *v2; // rcx

  v1 = this;
  v2 = this->mOnExitedDelegate.m_Closure.m_pthis;
  if ( v2 || v1->mOnExitedDelegate.m_Closure.m_pFunction )
    ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::TriggerRegion *))v1->mOnExitedDelegate.m_Closure.m_pFunction)(
      v2,
      v1);
}

// File Line: 957
// RVA: 0x23E440
bool __fastcall UFG::TriggerRegion::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *v1; // rbx
  UFG::SchemaDef *v2; // rax
  bool result; // al

  v1 = pSceneObj->mpWritableProperties;
  if ( !v1 )
    v1 = pSceneObj->mpConstProperties;
  v2 = UFG::PropertySetManager::GetSchema((UFG::qSymbol *)&SimSymX_propset_componentTriggerRegion.mUID);
  if ( v2 )
    result = UFG::qPropertySet::PropertyExists(v1, &v2->mPropertyName, DEPTH_RECURSE) != 0i64;
  else
    result = UFG::qPropertySet::GetParentFromName(
               v1,
               (UFG::qSymbol *)&SimSymX_propset_componentTriggerRegion.mUID,
               DEPTH_RECURSE) != 0i64;
  return result;
}

// File Line: 967
// RVA: 0x244210
void __fastcall UFG::TriggerRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v7; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x120ui64, "TriggerRegion", 0i64, 1u);
  v7 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v1->m_NameUID);
    UFG::TriggerRegion::TriggerRegion((UFG::TriggerRegion *)v3, v5, v4, 1);
  }
}

