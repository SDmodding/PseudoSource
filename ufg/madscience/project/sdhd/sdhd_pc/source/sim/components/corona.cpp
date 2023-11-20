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
  UFG::Corona *v3; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // [rsp+58h] [rbp+20h]

  v3 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x10000u);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Corona::`vftable';
  v3->mEffectId = -1;
  v4 = &v3->mpEffectTransform;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v3->mpEffectTransform.m_pPointer = 0i64;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v3->vfptr, UFG::Corona::_CoronaTypeUID, "Corona");
}

// File Line: 84
// RVA: 0x57D8B0
void __fastcall UFG::Corona::~Corona(UFG::Corona *this)
{
  UFG::Corona *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::Corona::`vftable';
  v2 = &this->mpEffectTransform;
  if ( this->mpEffectTransform.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x586BD0
void __fastcall UFG::Corona::OnDetach(UFG::Corona *this)
{
  unsigned int v1; // edx
  UFG::Corona *v2; // rbx
  UFG::SimComponent *v3; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this->mEffectId;
  v2 = this;
  if ( v1 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v1, 0);
    v2->mEffectId = -1;
  }
  v3 = v2->mpEffectTransform.m_pPointer;
  if ( v3 )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v3);
    v4 = &v2->mpEffectTransform;
    if ( v2->mpEffectTransform.m_pPointer )
    {
      v5 = v4->mPrev;
      v6 = v2->mpEffectTransform.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      v2->mpEffectTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpEffectTransform.mPrev;
    }
    v2->mpEffectTransform.m_pPointer = 0i64;
  }
}

// File Line: 140
// RVA: 0x58A2B0
UFG::Corona *__fastcall UFG::Corona::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v10; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xA0ui64, "Corona", 0i64, 1u);
  v10 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::Corona::Corona((UFG::Corona *)v3, v5, v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  (*(void (__fastcall **)(__int64, UFG::SceneObjectProperties *))(*(_QWORD *)v7 + 96i64))(v7, v1);
  return (UFG::Corona *)v7;
}

// File Line: 151
// RVA: 0x5889E0
void __fastcall UFG::Corona::PropertiesLoad(UFG::Corona *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::Corona *v3; // rdi
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  unsigned int v6; // esi
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qPropertySet *v13; // rcx
  unsigned int *v14; // rax
  UFG::qPropertySet *v15; // rcx
  bool *v16; // rax
  UFG::qPropertySet *v17; // rcx
  unsigned int *v18; // rax
  signed int v19; // eax

  v2 = pSceneObj;
  v3 = this;
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0x110ui64, "ObjectiveIndicator.Indicator", 0i64, 1u);
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
  v9 = &v3->mpEffectTransform;
  if ( v3->mpEffectTransform.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v3->mpEffectTransform.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v3->mpEffectTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mpEffectTransform.mPrev;
  }
  v3->mpEffectTransform.m_pPointer = v8;
  if ( v8 )
  {
    v12 = v8->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v3->mpEffectTransform.mNext = &v8->m_SafePointerList.mNode;
    v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = v2->mpWritableProperties;
  if ( !v13 )
    v13 = v2->mpConstProperties;
  v14 = PropertyUtils::Get<unsigned long>(v13, (UFG::qSymbol *)&qSymbol_CoronaIndex.mUID, DEPTH_RECURSE);
  if ( v14 )
    v6 = *v14;
  v3->mCurrentCoronaIdx = v6;
  v15 = v2->mpWritableProperties;
  if ( !v15 )
    v15 = v2->mpConstProperties;
  v16 = PropertyUtils::Get<bool>(v15, (UFG::qSymbol *)&qSymbol_ShowBlip.mUID, DEPTH_RECURSE);
  if ( v16 )
    LOBYTE(v16) = *v16;
  v3->mShowBlip = (char)v16;
  v17 = v2->mpWritableProperties;
  if ( !v17 )
    v17 = v2->mpConstProperties;
  v18 = PropertyUtils::Get<unsigned long>(v17, (UFG::qSymbol *)&qSymbol_CoronaIndex.mUID, DEPTH_RECURSE);
  if ( v18 )
    v19 = *v18;
  else
    v19 = -1;
  v3->mCurrentBlipIdx = v19;
  UFG::Corona::OnSelectCoronaType(v3, v3->mCurrentCoronaIdx, 0i64);
  v3->mShowBlip = v3->mCurrentBlipIdx != -1;
}

// File Line: 216
// RVA: 0x587660
void __fastcall UFG::Corona::OnSelectCoronaType(UFG::Corona *this, unsigned int popId, void *pvData)
{
  __int64 v3; // rsi
  unsigned int v4; // edx
  UFG::Corona *v5; // rdi
  UFG::TransformNodeComponent *v6; // rcx
  UFG::TransformNodeComponent *v7; // rdx
  UFG::TransformNodeComponent *v8; // rcx
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h]

  v3 = popId;
  v4 = this->mEffectId;
  v5 = this;
  if ( v4 != -1 )
  {
    Render::FXManager::KillEffect(&Render::gFXManager, v4, 0);
    v5->mEffectId = -1;
  }
  v6 = (UFG::TransformNodeComponent *)v5->mpEffectTransform.m_pPointer;
  if ( v6 )
  {
    v7 = (UFG::TransformNodeComponent *)v5->m_pSimObject;
    if ( v7 )
      v7 = (UFG::TransformNodeComponent *)v7->mChildren.mNode.mNext;
    if ( v7 )
      UFG::TransformNodeComponent::SetParentKeepWorld(v6, v7, 0);
    v8 = (UFG::TransformNodeComponent *)v5->mpEffectTransform.m_pPointer;
    *(_QWORD *)&pos.x = 0i64;
    pos.z = UFG::CoronaInfos[v3].coronaHeight;
    UFG::TransformNodeComponent::SetLocalTranslation(v8, &pos);
    v5->mEffectId = Render::FXManager::CreateEffect(
                      &Render::gFXManager,
                      UFG::CoronaInfos[v3].coronaName,
                      (UFG::TransformNodeComponent *)v5->mpEffectTransform.m_pPointer,
                      0xFFFFFFFF,
                      0i64);
    v5->mCurrentCoronaIdx = v3;
  }
}

