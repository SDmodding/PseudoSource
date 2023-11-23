// File Line: 63
// RVA: 0x154D5B0
__int64 dynamic_initializer_for__UFG::Corona::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::Corona::AccessComponentDesc();
  *(_DWORD *)&UFG::Corona::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::Corona::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::Corona::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 65
// RVA: 0x154D940
__int64 dynamic_initializer_for__UFG::Corona::sCoronaColour__()
{
  UFG::Corona::sCoronaColour = UFG::qColour::Gold;
  return LODWORD(UFG::qColour::Gold.a);
}

// File Line: 75
// RVA: 0x57C9C0
void __fastcall UFG::Corona::Corona(UFG::Corona *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x10000u);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Corona::`vftable;
  this->mEffectId = -1;
  this->mpEffectTransform.mPrev = &this->mpEffectTransform;
  this->mpEffectTransform.mNext = &this->mpEffectTransform;
  this->mpEffectTransform.m_pPointer = 0i64;
  UFG::SimComponent::AddType(this, UFG::Corona::_CoronaTypeUID, "Corona");
}

// File Line: 84
// RVA: 0x57D8B0
void __fastcall UFG::Corona::~Corona(UFG::Corona *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpEffectTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Corona::`vftable;
  p_mpEffectTransform = &this->mpEffectTransform;
  if ( this->mpEffectTransform.m_pPointer )
  {
    mPrev = p_mpEffectTransform->mPrev;
    mNext = p_mpEffectTransform->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpEffectTransform->mPrev = p_mpEffectTransform;
    p_mpEffectTransform->mNext = p_mpEffectTransform;
  }
  p_mpEffectTransform->m_pPointer = 0i64;
  v5 = p_mpEffectTransform->mPrev;
  v6 = p_mpEffectTransform->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpEffectTransform->mPrev = p_mpEffectTransform;
  p_mpEffectTransform->mNext = p_mpEffectTransform;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 101
// RVA: 0x586BD0
void __fastcall UFG::Corona::OnDetach(UFG::Corona *this)
{
  unsigned int mEffectId; // edx
  UFG::SimComponent *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpEffectTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  mEffectId = this->mEffectId;
  if ( mEffectId != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mEffectId, FXKILLOPTION_DEFAULT);
    this->mEffectId = -1;
  }
  m_pPointer = this->mpEffectTransform.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pPointer);
    p_mpEffectTransform = &this->mpEffectTransform;
    if ( this->mpEffectTransform.m_pPointer )
    {
      mPrev = p_mpEffectTransform->mPrev;
      mNext = this->mpEffectTransform.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpEffectTransform->mPrev = p_mpEffectTransform;
      this->mpEffectTransform.mNext = &this->mpEffectTransform;
    }
    this->mpEffectTransform.m_pPointer = 0i64;
  }
}

// File Line: 140
// RVA: 0x58A2B0
UFG::Corona *__fastcall UFG::Corona::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v10; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA0ui64, "Corona", 0i64, 1u);
  v10 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::Corona::Corona((UFG::Corona *)v3, v5, m_pSimObject);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  (*(void (__fastcall **)(__int64, UFG::SceneObjectProperties *))(*(_QWORD *)v7 + 96i64))(v7, pSceneObj);
  return (UFG::Corona *)v7;
}

// File Line: 151
// RVA: 0x5889E0
void __fastcall UFG::Corona::PropertiesLoad(UFG::Corona *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  unsigned int v6; // esi
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpEffectTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  unsigned int *v14; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  bool *v16; // rax
  UFG::qPropertySet *v17; // rcx
  unsigned int *v18; // rax
  unsigned int v19; // eax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "ObjectiveIndicator.Indicator", 0i64, 1u);
  v6 = 0;
  if ( v5 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v5, 1u, 0i64, 0);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  p_mpEffectTransform = &this->mpEffectTransform;
  if ( this->mpEffectTransform.m_pPointer )
  {
    mPrev = p_mpEffectTransform->mPrev;
    mNext = this->mpEffectTransform.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpEffectTransform->mPrev = p_mpEffectTransform;
    this->mpEffectTransform.mNext = &this->mpEffectTransform;
  }
  this->mpEffectTransform.m_pPointer = v8;
  if ( v8 )
  {
    v12 = v8->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_mpEffectTransform;
    p_mpEffectTransform->mPrev = v12;
    this->mpEffectTransform.mNext = &v8->m_SafePointerList.mNode;
    v8->m_SafePointerList.mNode.mPrev = p_mpEffectTransform;
  }
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v14 = PropertyUtils::Get<unsigned long>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_CoronaIndex,
          DEPTH_RECURSE);
  if ( v14 )
    v6 = *v14;
  this->mCurrentCoronaIdx = v6;
  mpConstProperties = pSceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = pSceneObj->mpConstProperties;
  v16 = PropertyUtils::Get<bool>(mpConstProperties, (UFG::qArray<unsigned long,0> *)&qSymbol_ShowBlip, DEPTH_RECURSE);
  if ( v16 )
    LOBYTE(v16) = *v16;
  this->mShowBlip = (char)v16;
  v17 = pSceneObj->mpWritableProperties;
  if ( !v17 )
    v17 = pSceneObj->mpConstProperties;
  v18 = PropertyUtils::Get<unsigned long>(v17, (UFG::qArray<unsigned long,0> *)&qSymbol_CoronaIndex, DEPTH_RECURSE);
  if ( v18 )
    v19 = *v18;
  else
    v19 = -1;
  this->mCurrentBlipIdx = v19;
  UFG::Corona::OnSelectCoronaType(this, this->mCurrentCoronaIdx, 0i64);
  this->mShowBlip = this->mCurrentBlipIdx != -1;
}

// File Line: 216
// RVA: 0x587660
void __fastcall UFG::Corona::OnSelectCoronaType(UFG::Corona *this, unsigned int popId, void *pvData)
{
  __int64 v3; // rsi
  unsigned int mEffectId; // edx
  UFG::TransformNodeComponent *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pSimObject; // rdx
  UFG::TransformNodeComponent *v8; // rcx
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h] BYREF

  v3 = popId;
  mEffectId = this->mEffectId;
  if ( mEffectId != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, mEffectId, FXKILLOPTION_DEFAULT);
    this->mEffectId = -1;
  }
  m_pPointer = (UFG::TransformNodeComponent *)this->mpEffectTransform.m_pPointer;
  if ( m_pPointer )
  {
    m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
    if ( m_pSimObject )
      m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
    if ( m_pSimObject )
      UFG::TransformNodeComponent::SetParentKeepWorld(m_pPointer, m_pSimObject, eInheritXform_Full);
    v8 = (UFG::TransformNodeComponent *)this->mpEffectTransform.m_pPointer;
    *(_QWORD *)&pos.x = 0i64;
    pos.z = UFG::CoronaInfos[v3].coronaHeight;
    UFG::TransformNodeComponent::SetLocalTranslation(v8, &pos);
    this->mEffectId = Render::FXManager::CreateEffect(
                        &Render::gFXManager,
                        UFG::CoronaInfos[v3].coronaName,
                        (UFG::TransformNodeComponent *)this->mpEffectTransform.m_pPointer,
                        0xFFFFFFFF,
                        0i64);
    this->mCurrentCoronaIdx = v3;
  }
}

