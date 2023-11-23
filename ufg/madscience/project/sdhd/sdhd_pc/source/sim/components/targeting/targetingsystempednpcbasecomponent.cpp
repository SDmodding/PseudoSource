// File Line: 24
// RVA: 0x1544140
__int64 dynamic_initializer_for__UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList__);
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
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::TargetingSystemPedNPCBaseComponent(
        UFG::TargetingSystemPedNPCBaseComponent *this,
        UFG::TargetingMap *pTargetingMap,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *mPrev; // rax

  UFG::TargetingSystemPedBaseComponent::TargetingSystemPedBaseComponent(this, pTargetingMap, name_uid, properties);
  this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mPrev = &this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mNext = &this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>;
  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::RebindingComponentHandle<UFG::AIActionTreeComponent,0>(&this->m_pAIActionTreeComponent);
  mPrev = UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList.mNode.mPrev;
  UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>;
  this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mNext = (UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *)&UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList;
  UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemPedNPCBaseComponent::_TargetingSystemPedNPCBaseComponentTypeUID,
    "TargetingSystemPedNPCBaseComponent");
  UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(this);
}

// File Line: 48
// RVA: 0x51D0E0
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::~TargetingSystemPedNPCBaseComponent(
        UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v2; // rbx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *mNext; // rax
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent> *v6; // rax

  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::TargetingSystemPedBaseComponent::UFG::TargetingSystemBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemPedNPCBaseComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentpCurrentIterator )
    UFG::TargetingSystemPedNPCBaseComponent::s_TargetingSystemPedNPCBaseComponentpCurrentIterator = (UFG::TargetingSystemPedNPCBaseComponent *)&this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mPrev[-174].mNext;
  v2 = &this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>;
  mPrev = this->UFG::qNode<UFG::TargetingSystemPedNPCBaseComponent,UFG::TargetingSystemPedNPCBaseComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIActionTreeComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::TargetingSystemPedBaseComponent::~TargetingSystemPedBaseComponent(this);
}

// File Line: 57
// RVA: 0x53EED0
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::OnAttach(
        UFG::TargetingSystemPedNPCBaseComponent *this,
        UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *p_m_pAIActionTreeComponent; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  UFG::TargetingSystemPedBaseComponent::OnAttach(this, pSimObject);
  p_m_pAIActionTreeComponent = &this->m_pAIActionTreeComponent;
  if ( p_m_pAIActionTreeComponent->m_pSimComponent )
  {
    mNext = p_m_pAIActionTreeComponent->mNext;
    mPrev = p_m_pAIActionTreeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIActionTreeComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAIActionTreeComponent->m_pSimObject = 0i64;
    p_m_pAIActionTreeComponent->mNext = p_m_pAIActionTreeComponent;
    p_m_pAIActionTreeComponent->mPrev = p_m_pAIActionTreeComponent;
    goto LABEL_8;
  }
  if ( p_m_pAIActionTreeComponent->m_pSimObject
    && (p_m_pAIActionTreeComponent->mPrev != p_m_pAIActionTreeComponent
     || p_m_pAIActionTreeComponent->mNext != p_m_pAIActionTreeComponent) )
  {
    v7 = p_m_pAIActionTreeComponent->mNext;
    v8 = p_m_pAIActionTreeComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIActionTreeComponent->m_Changed = 1;
  p_m_pAIActionTreeComponent->m_pSimObject = pSimObject;
  p_m_pAIActionTreeComponent->m_TypeUID = UFG::AIActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    p_m_pAIActionTreeComponent,
    pSimObject);
}

// File Line: 87
// RVA: 0x576BB0
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::updatePropTarget(
        UFG::TargetingSystemPedNPCBaseComponent *this,
        UFG::qFixedArray<UFG::CloseTarget *,5> *closePropsList)
{
  UFG::TargetingSimObject *v4; // r8
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v10; // rdx
  UFG::PropInteractComponent *m_pComponent; // rax
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  unsigned __int8 v14; // cl
  unsigned __int8 v15; // cl

  v4 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[40]];
  if ( v4->m_pTarget.m_pPointer && v4->m_bLock )
    return;
  m_pSimComponent = this->m_pActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    m_pSimObject = m_pSimComponent[45].m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v10 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
               || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v10 += 16i64;
            if ( vfptr >= size )
              goto LABEL_11;
          }
LABEL_12:
          m_pComponent = *(UFG::PropInteractComponent **)v10;
          goto LABEL_25;
        }
      }
      else
      {
        if ( m_Flags < 0 )
        {
          m_pComponent = (UFG::PropInteractComponent *)m_pSimObject->m_Components.p[33].m_pComponent;
          goto LABEL_25;
        }
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::PropInteractComponent *)m_pSimObject->m_Components.p[13].m_pComponent;
          goto LABEL_25;
        }
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pSimObject,
                                                         UFG::PropInteractComponent::_TypeUID);
          goto LABEL_25;
        }
        v12 = (unsigned int)m_pSimObject[1].vfptr;
        v13 = m_pSimObject->m_Components.size;
        if ( v12 < v13 )
        {
          v10 = (__int64)&m_pSimObject->m_Components.p[v12];
          while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
               || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v12;
            v10 += 16i64;
            if ( v12 >= v13 )
            {
              m_pComponent = 0i64;
              goto LABEL_25;
            }
          }
          goto LABEL_12;
        }
      }
LABEL_11:
      m_pComponent = 0i64;
LABEL_25:
      if ( m_pComponent
        && !m_pComponent->mInteractingSimObject.m_pPointer
        && !UFG::PropInteractComponent::NotInteractable(m_pComponent) )
      {
        v14 = this->m_pTargetingMap->m_Map.p[40];
        if ( v14 )
          UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v14], m_pSimObject);
        return;
      }
    }
  }
  if ( closePropsList->size )
  {
    v15 = this->m_pTargetingMap->m_Map.p[40];
    if ( v15 )
      UFG::TargetingSimObject::SetTarget(
        &this->m_pTargets[v15],
        closePropsList->p[0]->m_pSimObjectPropertiesComponent->m_pSimObject);
  }
  else
  {
    UFG::TargetingSystemBaseComponent::ClearTarget(this, eTARGET_TYPE_INTERACTIVE_PROP);
  }
}

// File Line: 141
// RVA: 0x579530
void __fastcall UFG::TargetingSystemPedNPCBaseComponent::updateTargetingIntentions(
        UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  float v2; // xmm2_4
  float v3; // xmm0_4
  __m128 x_low; // xmm4
  float z; // xmm6_4
  __m128 v6; // xmm3

  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    m_pSimComponent = this->m_pAICharacterControllerBaseComponent.m_pSimComponent;
    v2 = 0.0;
    v3 = *(float *)&m_pSimComponent[2].m_TypeUID;
    LODWORD(m_pSimComponent) = HIDWORD(m_pSimComponent[2].m_SafePointerList.mNode.mNext);
    this->m_vTargetingIntention.y = v3;
    LODWORD(this->m_vTargetingIntention.x) = (_DWORD)m_pSimComponent;
    this->m_vTargetingIntention.z = 0.0;
    x_low = (__m128)LODWORD(this->m_vTargetingIntention.x);
    z = this->m_vTargetingIntention.z;
    v6 = x_low;
    v6.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v3 * v3)) + (float)(z * z);
    if ( v6.m128_f32[0] != 0.0 )
      v2 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
    this->m_vTargetingIntention.x = x_low.m128_f32[0] * v2;
    this->m_vTargetingIntention.z = z * v2;
    this->m_vTargetingIntention.y = v3 * v2;
  }
}

// File Line: 160
// RVA: 0x56AF10
bool __fastcall UFG::TargetingSystemPedNPCBaseComponent::isScriptControlled(
        UFG::TargetingSystemPedNPCBaseComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  if ( (_S32 & 1) == 0 )
  {
    _S32 |= 1u;
    UIDScriptControlled.mUID = UFG::qStringHashUpper32("Perform script commands", -1);
  }
  m_pSimComponent = this->m_pAIActionTreeComponent.m_pSimComponent;
  return m_pSimComponent
      && ActionController::IsPlaying(
           (ActionController *)&m_pSimComponent[3].m_TypeUID,
           &UIDScriptControlled,
           0xFFFFFFFF,
           0);
}

// File Line: 168
// RVA: 0x56D600
bool __fastcall UFG::TargetingSystemPedNPCBaseComponent::shouldUpdateThisFrame(
        UFG::TargetingSystemPedNPCBaseComponent *this)
{
  unsigned int v3; // ecx

  if ( this->m_bForceUpdate )
    return 1;
  if ( (UFG::Metrics::msInstance.mSimFrameCount & 1) != 0 )
    return 0;
  v3 = 60;
  if ( this->m_pBucketList == UFG::TargetingSystemPedBaseComponent::ms_HighFrequencyUpdateBuckets )
    v3 = 10;
  return (UFG::Metrics::msInstance.mSimFrameCount >> 1) % v3 == this->m_uUpdateBucket;
}

