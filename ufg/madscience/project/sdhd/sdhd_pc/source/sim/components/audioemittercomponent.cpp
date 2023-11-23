// File Line: 19
// RVA: 0x154D9A0
__int64 dynamic_initializer_for__UFG::AudioEmitterComponent::s_AudioEmitterComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEmitterComponent::s_AudioEmitterComponentList__);
}

// File Line: 20
// RVA: 0x5825B0
UFG::ComponentIDDesc *__fastcall UFG::AudioEmitterComponent::GetDesc(UFG::AudioEmitterComponent *this)
{
  return &UFG::AudioEmitterComponent::_TypeIDesc;
}

// File Line: 26
// RVA: 0x57C330
void __fastcall UFG::AudioEmitterComponent::AudioEmitterComponent(
        UFG::AudioEmitterComponent *this,
        unsigned __int64 emitter_definition_uid,
        unsigned int name_uid)
{
  UFG::qReflectObjectType<UFG::AudioEmitterDefinition,UFG::qReflectObject> *v5; // rcx
  const char *TypeName; // rax
  unsigned int v7; // ebp
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *mPrev; // rax
  UFG::qReflectObject *mData; // rax
  float v10; // xmm0_4
  float v11; // xmm6_4
  UFG::qReflectObjectVtbl *v12; // rdx
  UFG::qBaseTreeRB *v13; // rax
  UFG::qBaseNodeRB *v14; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent>;
  this->mNext = &this->UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterComponent::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->m_audioEmitterDefinition);
  TypeName = UFG::qReflectObjectType<UFG::AudioEmitterDefinition,UFG::qReflectObject>::GetTypeName(v5);
  this->m_audioEmitterDefinition.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  v7 = 0;
  this->m_oneShotHandle.m_pOneShot = 0i64;
  *(_WORD *)&this->m_bankLoadsRequested = 0;
  mPrev = UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mPrev;
  UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)&UFG::AudioEmitterComponent::s_AudioEmitterComponentList;
  UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent>;
  UFG::SimComponent::AddType(this, UFG::AudioEmitterComponent::_AudioEmitterComponentTypeUID, "AudioEmitterComponent");
  UFG::qReflectHandleBase::Init(
    &this->m_audioEmitterDefinition,
    this->m_audioEmitterDefinition.mTypeUID,
    emitter_definition_uid);
  mData = this->m_audioEmitterDefinition.mData;
  v10 = *(float *)&mData[1].mBaseNode.mParent;
  this->m_activationRadius = v10;
  v11 = 0.0;
  if ( v10 <= 0.0 )
  {
    if ( LODWORD(mData[1].mBaseNode.mUID) )
    {
      do
      {
        v12 = &this->m_audioEmitterDefinition.mData[1].vfptr[6 * v7];
        if ( LODWORD(v12[5].__vecDelDtor) == 1 )
        {
          v13 = UFG::AudioEventPropertyManager::Find(HIDWORD(v12[5].__vecDelDtor));
          if ( v13 )
          {
            v14 = v13->mNULL.mChild[0];
            if ( *((float *)v14[3].mChild + 1) > v11 )
              v11 = *((float *)v14[3].mChild + 1);
          }
        }
        ++v7;
      }
      while ( v7 < LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) );
    }
    this->m_activationRadius = v11;
  }
}

// File Line: 41
// RVA: 0x57D550
void __fastcall UFG::AudioEmitterComponent::~AudioEmitterComponent(UFG::AudioEmitterComponent *this)
{
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v2; // rbx
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *mPrev; // rcx
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *mNext; // rax
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v5; // rcx
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterComponent::`vftable;
  if ( this == UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator )
    UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator = (UFG::AudioEmitterComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::OneShotHandle::Release(&this->m_oneShotHandle);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->m_audioEmitterDefinition);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 50
// RVA: 0x5869F0
void __fastcall UFG::AudioEmitterComponent::OnDetach(UFG::AudioEmitterComponent *this)
{
  if ( UFG::OneShotHandle::IsValid(&this->m_oneShotHandle) )
    ((void (__fastcall *)(UFG::OneShot *))this->m_oneShotHandle.m_pOneShot->vfptr->StopAndForgetAllEvents)(this->m_oneShotHandle.m_pOneShot);
  this->m_eventsPlaying = 0;
  UFG::AudioEmitterComponent::UnloadBanks(this);
}

// File Line: 56
// RVA: 0x58D3F0
void __fastcall UFG::AudioEmitterComponent::Update(UFG::AudioEmitterComponent *this, float delta_sec)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::OneShot *m_pOneShot; // rcx
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  if ( UFG::AudioListener::GetDistance2From(
         UFG::AudioListener::sm_pInstance,
         (UFG::qVector3 *)m_pSimObject[1].mNode.mChild) <= (float)(this->m_activationRadius * this->m_activationRadius) )
  {
    if ( !this->m_bankLoadsRequested )
      UFG::AudioEmitterComponent::LoadBanks(this);
    if ( UFG::AudioEmitterComponent::AreBanksLoaded(this) )
      UFG::AudioEmitterComponent::PlayEvents(this);
  }
  else
  {
    if ( UFG::OneShotHandle::IsValid(&this->m_oneShotHandle) )
      ((void (__fastcall *)(UFG::OneShot *))this->m_oneShotHandle.m_pOneShot->vfptr->StopAndForgetAllEvents)(this->m_oneShotHandle.m_pOneShot);
    this->m_eventsPlaying = 0;
    UFG::AudioEmitterComponent::UnloadBanks(this);
  }
  if ( UFG::OneShotHandle::IsValid(&this->m_oneShotHandle) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
    m_pOneShot = this->m_oneShotHandle.m_pOneShot;
    v5 = *(UFG::qVector4 *)&m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
    v6 = *(UFG::qVector4 *)&m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
    v7 = *(UFG::qVector4 *)m_pSimObject[1].mNode.mChild;
    m_pOneShot->m_WorldMatrix.v0 = *(UFG::qVector4 *)&m_pSimObject[1].vfptr;
    m_pOneShot->m_WorldMatrix.v1 = v5;
    m_pOneShot->m_WorldMatrix.v2 = v6;
    m_pOneShot->m_WorldMatrix.v3 = v7;
    UFG::AudioEntity::ForcePositionUpdate(m_pOneShot);
  }
}

// File Line: 91
// RVA: 0x585840
void __fastcall UFG::AudioEmitterComponent::LoadBanks(UFG::AudioEmitterComponent *this)
{
  __int64 i; // rbx
  UFG::qWiseSymbol *v3; // rcx

  if ( !this->m_bankLoadsRequested )
  {
    for ( i = 0i64;
          (unsigned int)i < LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID);
          i = (unsigned int)(i + 1) )
    {
      v3 = (UFG::qWiseSymbol *)&this->m_audioEmitterDefinition.mData[1].vfptr[6 * i];
      if ( v3[20].mUID == 5 )
        UFG::SoundBankManager::QueueBankForLoad(v3 + 21);
    }
    this->m_bankLoadsRequested = 1;
  }
}

// File Line: 109
// RVA: 0x58D380
void __fastcall UFG::AudioEmitterComponent::UnloadBanks(UFG::AudioEmitterComponent *this)
{
  __int64 i; // rbx
  UFG::qWiseSymbol *v3; // rcx

  if ( this->m_bankLoadsRequested )
  {
    for ( i = 0i64;
          (unsigned int)i < LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID);
          i = (unsigned int)(i + 1) )
    {
      v3 = (UFG::qWiseSymbol *)&this->m_audioEmitterDefinition.mData[1].vfptr[6 * i];
      if ( v3[20].mUID == 5 )
        UFG::SoundBankManager::QueueBankForUnload(v3 + 21);
    }
    this->m_bankLoadsRequested = 0;
  }
}

// File Line: 127
// RVA: 0x57F290
char __fastcall UFG::AudioEmitterComponent::AreBanksLoaded(UFG::AudioEmitterComponent *this)
{
  UFG::qReflectObject *mData; // rdx
  __int64 v4; // rbx
  char i; // di
  UFG::qWiseSymbol *v6; // rcx

  if ( !this->m_bankLoadsRequested )
    return 0;
  mData = this->m_audioEmitterDefinition.mData;
  v4 = 0i64;
  for ( i = 1; (unsigned int)v4 < LODWORD(mData[1].mBaseNode.mUID); v4 = (unsigned int)(v4 + 1) )
  {
    v6 = (UFG::qWiseSymbol *)&mData[1].vfptr[6 * v4];
    if ( v6[20].mUID == 5 )
      i &= UFG::SoundBankManager::BankLoadRequestFinished(v6 + 21);
    mData = this->m_audioEmitterDefinition.mData;
  }
  return i;
}

// File Line: 147
// RVA: 0x588690
void __fastcall UFG::AudioEmitterComponent::PlayEvents(UFG::AudioEmitterComponent *this)
{
  __int64 i; // rsi
  UFG::qReflectObjectVtbl *v3; // rbx
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp

  if ( !this->m_eventsPlaying )
  {
    for ( i = 0i64;
          (unsigned int)i < LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID);
          i = (unsigned int)(i + 1) )
    {
      v3 = &this->m_audioEmitterDefinition.mData[1].vfptr[6 * i];
      if ( LODWORD(v3[5].__vecDelDtor) == 1 )
      {
        m_pSimObject = this->m_pSimObject;
        if ( m_pSimObject )
          m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
        else
          m_pTransformNodeComponent = 0i64;
        if ( !UFG::OneShotHandle::IsValid(&this->m_oneShotHandle) )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          UFG::OneShotPool::GetOneShotHandle(&this->m_oneShotHandle, &m_pTransformNodeComponent->mWorldTransform);
        }
        if ( UFG::OneShotHandle::IsValid(&this->m_oneShotHandle) )
          UFG::OneShot::Play(this->m_oneShotHandle.m_pOneShot, HIDWORD(v3[5].__vecDelDtor));
      }
    }
    this->m_eventsPlaying = 1;
  }
}

