// File Line: 24
// RVA: 0x1544140
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList__);
}

// File Line: 25
// RVA: 0x15436D0
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::TargetingSystemPedNPCBaseComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 38
// RVA: 0x519C60
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::TargetingSystemPedNPCBaseComponent(UFG::TargetingSystemPedNPCBaseComponent *this, UFG::TargetingMap *pTargetingMap, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::TargetingSystemPedNPCBaseComponent *v4; // rdi
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v5; // rbx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v6; // rax

  v4 = this;
  UFG::TargetingSystemPedBaseComponent::TargetingSystemPedBaseComponent(
    (UFG::TargetingSystemPedBaseComponent *)&this->vfptr,
    pTargetingMap,
    name_uid,
    properties);
  v5 = (UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::RebindingComponentHandle<UFG::AIActionTreeComponent,0>(&v4->m_pAIActionTreeComponent);
  v6 = UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList.mNode.mPrev;
  UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *)&UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList;
  UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TargetingSystemPedNPCBaseComponent::_TargetingSystemPedNPCBaseComponentTypeUID,
    "TargetingSystemPedNPCBaseComponent");
  UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate((UFG::TargetingSystemPedBaseComponent *)&v4->vfptr);
}

// File Line: 48
// RVA: 0x51D0E0
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::~TargetingSystemPedNPCBaseComponent(UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::TargetingSystemPedNPCBaseComponent *v1; // rdi
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v2; // rbx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v3; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v4; // rax
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentpCurrentIterator )
    UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentpCurrentIterator = (UFG::TargetingSystemPedNPCBaseComponent *)&this->mPrev[-174].mNext;
  v2 = (UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIActionTreeComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemPedBaseComponent::~TargetingSystemPedBaseComponent((UFG::TargetingSystemPedBaseComponent *)&v1->vfptr);
}

// File Line: 57
// RVA: 0x53EED0
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::OnAttach(UFG::TargetingSystemPedNPCBaseComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v2; // rdi
  UFG::TargetingSystemPedNPCBaseComponent *v3; // rbx
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = pSimObject;
  v3 = this;
  UFG::TargetingSystemPedBaseComponent::OnAttach((UFG::TargetingSystemPedBaseComponent *)&this->vfptr, pSimObject);
  v4 = &v3->m_pAIActionTreeComponent;
  if ( v4->m_pSimComponent )
  {
    v5 = v4->mNext;
    v6 = v4->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v4->m_pSimComponent = 0i64;
LABEL_7:
    v4->m_pSimObject = 0i64;
    v4->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v4->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v4->mNext != v4) )
  {
    v7 = v4->mNext;
    v8 = v4->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v4->m_Changed = 1;
  v4->m_pSimObject = v2;
  v4->m_TypeUID = UFG::AIActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::BindInternal<UFG::SimObject>(v4, v2);
}

// File Line: 87
// RVA: 0x576BB0
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::updatePropTarget(UFG::TargetingSystemPedNPCBaseComponent *this, UFG::qFixedArray<UFG::CloseTarget *,5> *closePropsList)
{
  UFG::qFixedArray<UFG::CloseTarget *,5> *v2; // rsi
  UFG::TargetingSystemPedNPCBaseComponent *v3; // rdi
  UFG::TargetingSimObject *v4; // r8
  UFG::SimComponent *v5; // rbx
  UFG::SimObject *v6; // rbx
  unsigned __int16 v7; // cx
  unsigned int v8; // er8
  unsigned int v9; // er9
  signed __int64 v10; // rdx
  UFG::PropInteractComponent *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // er9
  unsigned __int8 v14; // cl
  unsigned __int8 v15; // cl

  v2 = closePropsList;
  v3 = this;
  v4 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[40]];
  if ( v4->m_pTarget.m_pPointer && v4->m_bLock )
    return;
  v5 = this->m_pActiveAIEntityComponent.m_pSimComponent;
  if ( v5 )
  {
    v6 = v5[45].m_pSimObject;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (unsigned int)v6[1].vfptr;
        v9 = v6->m_Components.size;
        if ( v8 < v9 )
        {
          v10 = (signed __int64)&v6->m_Components.p[v8];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
               || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
          {
            ++v8;
            v10 += 16i64;
            if ( v8 >= v9 )
              goto LABEL_11;
          }
LABEL_12:
          v11 = *(UFG::PropInteractComponent **)v10;
          goto LABEL_25;
        }
      }
      else
      {
        if ( (v7 & 0x8000u) != 0 )
        {
          v11 = (UFG::PropInteractComponent *)v6->m_Components.p[33].m_pComponent;
          goto LABEL_25;
        }
        if ( (v7 >> 13) & 1 )
        {
          v11 = (UFG::PropInteractComponent *)v6->m_Components.p[13].m_pComponent;
          goto LABEL_25;
        }
        if ( !((v7 >> 12) & 1) )
        {
          v11 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                v6,
                                                UFG::PropInteractComponent::_TypeUID);
          goto LABEL_25;
        }
        v12 = (unsigned int)v6[1].vfptr;
        v13 = v6->m_Components.size;
        if ( v12 < v13 )
        {
          v10 = (signed __int64)&v6->m_Components.p[v12];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
               || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
          {
            ++v12;
            v10 += 16i64;
            if ( v12 >= v13 )
            {
              v11 = 0i64;
              goto LABEL_25;
            }
          }
          goto LABEL_12;
        }
      }
LABEL_11:
      v11 = 0i64;
LABEL_25:
      if ( v11 && !v11->mInteractingSimObject.m_pPointer && !UFG::PropInteractComponent::NotInteractable(v11) )
      {
        v14 = v3->m_pTargetingMap->m_Map.p[40];
        if ( v14 )
          UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v14], v6);
        return;
      }
      goto LABEL_30;
    }
  }
LABEL_30:
  if ( v2->size )
  {
    v15 = v3->m_pTargetingMap->m_Map.p[40];
    if ( v15 )
      UFG::TargetingSimObject::SetTarget(&v3->m_pTargets[v15], v2->p[0]->m_pSimObjectPropertiesComponent->m_pSimObject);
  }
  else
  {
    UFG::TargetingSystemBaseComponent::ClearTarget(
      (UFG::TargetingSystemBaseComponent *)&v3->vfptr,
      eTARGET_TYPE_INTERACTIVE_PROP);
  }
}

// File Line: 141
// RVA: 0x579530
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::updateTargetingIntentions(UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::SimComponent *v1; // rax
  float v2; // xmm2_4
  float v3; // xmm0_4
  __m128 v4; // xmm4
  float v5; // xmm6_4
  __m128 v6; // xmm3

  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v1 = this->m_pAICharacterControllerBaseComponent.m_pSimComponent;
    v2 = 0.0;
    v3 = *(float *)&v1[2].m_TypeUID;
    LODWORD(v1) = HIDWORD(v1[2].m_SafePointerList.mNode.mNext);
    this->m_vTargetingIntention.y = v3;
    LODWORD(this->m_vTargetingIntention.x) = (_DWORD)v1;
    this->m_vTargetingIntention.z = 0.0;
    v4 = (__m128)LODWORD(this->m_vTargetingIntention.x);
    v5 = this->m_vTargetingIntention.z;
    v6 = v4;
    v6.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3)) + (float)(v5 * v5);
    if ( v6.m128_f32[0] != 0.0 )
      v2 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
    this->m_vTargetingIntention.x = v4.m128_f32[0] * v2;
    this->m_vTargetingIntention.z = v5 * v2;
    this->m_vTargetingIntention.y = v3 * v2;
  }
}

// File Line: 160
// RVA: 0x56AF10
bool __fastcall UFG::TargetingSystemPedNPCBaseComponent::isScriptControlled(UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::TargetingSystemPedNPCBaseComponent *v1; // rbx
  UFG::SimComponent *v2; // rcx

  v1 = this;
  if ( !(_S32 & 1) )
  {
    _S32 |= 1u;
    UIDScriptControlled.mUID = UFG::qStringHashUpper32("Perform script commands", 0xFFFFFFFF);
  }
  v2 = v1->m_pAIActionTreeComponent.m_pSimComponent;
  return v2 && ActionController::IsPlaying((ActionController *)&v2[3].m_TypeUID, &UIDScriptControlled, 0xFFFFFFFF, 0);
}

// File Line: 168
// RVA: 0x56D600
bool __fastcall UFG::TargetingSystemPedNPCBaseComponent::shouldUpdateThisFrame(UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::TargetingSystemPedNPCBaseComponent *v1; // r8
  unsigned int v3; // ecx

  v1 = this;
  if ( this->m_bForceUpdate )
    return 1;
  if ( !(~LOBYTE(UFG::Metrics::msInstance.mSimFrameCount) & 1) )
    return 0;
  v3 = 60;
  if ( v1->m_pBucketList == UFG::TargetingSystemPedBaseComponent::ms_HighFrequencyUpdateBuckets )
    v3 = 10;
  return (UFG::Metrics::msInstance.mSimFrameCount >> 1) % v3 == v1->m_uUpdateBucket;
}

