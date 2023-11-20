// File Line: 19
// RVA: 0x154D9A0
__int64 dynamic_initializer_for__UFG::AudioEmitterComponent::s_AudioEmitterComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEmitterComponent::s_AudioEmitterComponentList__);
}

// File Line: 20
// RVA: 0x5825B0
UFG::ComponentIDDesc *__fastcall UFG::AudioEmitterComponent::GetDesc(UFG::AudioEmitterComponent *this)
{
  return &UFG::AudioEmitterComponent::_TypeIDesc;
}

// File Line: 26
// RVA: 0x57C330
void __fastcall UFG::AudioEmitterComponent::AudioEmitterComponent(UFG::AudioEmitterComponent *this, unsigned __int64 emitter_definition_uid, unsigned int name_uid)
{
  unsigned __int64 v3; // rsi
  UFG::AudioEmitterComponent *v4; // r14
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v5; // rbx
  UFG::qReflectObjectType<UFG::AudioEmitterDefinition,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  unsigned int v8; // ebp
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v9; // rax
  UFG::qReflectObject *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm6_4
  signed __int64 v13; // rdx
  UFG::qBaseTreeRB *v14; // rax
  UFG::qBaseNodeRB *v15; // rax

  v3 = emitter_definition_uid;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterComponent::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v4->m_audioEmitterDefinition.mPrev);
  v7 = UFG::qReflectObjectType<UFG::AudioEmitterDefinition,UFG::qReflectObject>::GetTypeName(v6);
  v4->m_audioEmitterDefinition.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  v8 = 0;
  v4->m_oneShotHandle.m_pOneShot = 0i64;
  *(_WORD *)&v4->m_bankLoadsRequested = 0;
  v9 = UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mPrev;
  UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)&v4->mPrev;
  v5->mPrev = v9;
  v4->mNext = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)&UFG::AudioEmitterComponent::s_AudioEmitterComponentList;
  UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mPrev = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AudioEmitterComponent::_AudioEmitterComponentTypeUID,
    "AudioEmitterComponent");
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&v4->m_audioEmitterDefinition.mPrev,
    v4->m_audioEmitterDefinition.mTypeUID,
    v3);
  v10 = v4->m_audioEmitterDefinition.mData;
  v11 = *(float *)&v10[1].mBaseNode.mParent;
  v4->m_activationRadius = v11;
  v12 = 0.0;
  if ( v11 <= 0.0 )
  {
    if ( LODWORD(v10[1].mBaseNode.mUID) > 0 )
    {
      do
      {
        v13 = (signed __int64)&v4->m_audioEmitterDefinition.mData[1].vfptr[6 * v8];
        if ( *(_DWORD *)(v13 + 80) == 1 )
        {
          v14 = UFG::AudioEventPropertyManager::Find(*(_DWORD *)(v13 + 84));
          if ( v14 )
          {
            v15 = v14->mNULL.mChild[0];
            if ( *((float *)v15[3].mChild + 1) > v12 )
              v12 = *((float *)v15[3].mChild + 1);
          }
        }
        ++v8;
      }
      while ( v8 < LODWORD(v4->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) );
    }
    v4->m_activationRadius = v12;
  }
}

// File Line: 41
// RVA: 0x57D550
void __fastcall UFG::AudioEmitterComponent::~AudioEmitterComponent(UFG::AudioEmitterComponent *this)
{
  UFG::AudioEmitterComponent *v1; // rdi
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v2; // rbx
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v3; // rcx
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v4; // rax
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v5; // rcx
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterComponent::`vftable;
  if ( this == UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator )
    UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator = (UFG::AudioEmitterComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::OneShotHandle::Release(&v1->m_oneShotHandle);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->m_audioEmitterDefinition.mPrev);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 50
// RVA: 0x5869F0
void __fastcall UFG::AudioEmitterComponent::OnDetach(UFG::AudioEmitterComponent *this)
{
  UFG::AudioEmitterComponent *v1; // rbx

  v1 = this;
  if ( UFG::OneShotHandle::IsValid(&this->m_oneShotHandle) )
    ((void (*)(void))v1->m_oneShotHandle.m_pOneShot->vfptr->StopAndForgetAllEvents)();
  v1->m_eventsPlaying = 0;
  UFG::AudioEmitterComponent::UnloadBanks(v1);
}

// File Line: 56
// RVA: 0x58D3F0
void __fastcall UFG::AudioEmitterComponent::Update(UFG::AudioEmitterComponent *this, float delta_sec)
{
  UFG::SimObject *v2; // rdi
  UFG::AudioEmitterComponent *v3; // rbx
  UFG::OneShot *v4; // rcx
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1

  v2 = this->m_pSimObject;
  v3 = this;
  if ( v2 )
    v2 = (UFG::SimObject *)v2->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2);
  if ( UFG::AudioListener::GetDistance2From(UFG::AudioListener::sm_pInstance, (UFG::qVector3 *)v2[1].mNode.mChild) <= (float)(v3->m_activationRadius * v3->m_activationRadius) )
  {
    if ( !v3->m_bankLoadsRequested )
      UFG::AudioEmitterComponent::LoadBanks(v3);
    if ( UFG::AudioEmitterComponent::AreBanksLoaded(v3) )
      UFG::AudioEmitterComponent::PlayEvents(v3);
  }
  else
  {
    if ( UFG::OneShotHandle::IsValid(&v3->m_oneShotHandle) )
      ((void (*)(void))v3->m_oneShotHandle.m_pOneShot->vfptr->StopAndForgetAllEvents)();
    v3->m_eventsPlaying = 0;
    UFG::AudioEmitterComponent::UnloadBanks(v3);
  }
  if ( UFG::OneShotHandle::IsValid(&v3->m_oneShotHandle) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2);
    v4 = v3->m_oneShotHandle.m_pOneShot;
    v5 = *(UFG::qVector4 *)&v2[1].m_SafePointerList.mNode.mNext;
    v6 = *(UFG::qVector4 *)&v2[1].m_SafePointerWithCallbackList.mNode.mNext;
    v7 = *(UFG::qVector4 *)v2[1].mNode.mChild;
    v4->m_WorldMatrix.v0 = *(UFG::qVector4 *)&v2[1].vfptr;
    v4->m_WorldMatrix.v1 = v5;
    v4->m_WorldMatrix.v2 = v6;
    v4->m_WorldMatrix.v3 = v7;
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v4->vfptr);
  }
}

// File Line: 91
// RVA: 0x585840
void __fastcall UFG::AudioEmitterComponent::LoadBanks(UFG::AudioEmitterComponent *this)
{
  UFG::AudioEmitterComponent *v1; // rdi
  __int64 v2; // rbx
  UFG::qWiseSymbol *v3; // rcx

  v1 = this;
  if ( !this->m_bankLoadsRequested )
  {
    v2 = 0i64;
    if ( LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) )
    {
      do
      {
        v3 = (UFG::qWiseSymbol *)&v1->m_audioEmitterDefinition.mData[1].vfptr[6 * v2];
        if ( v3[20].mUID == 5 )
          UFG::SoundBankManager::QueueBankForLoad(v3 + 21);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < LODWORD(v1->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) );
    }
    v1->m_bankLoadsRequested = 1;
  }
}

// File Line: 109
// RVA: 0x58D380
void __fastcall UFG::AudioEmitterComponent::UnloadBanks(UFG::AudioEmitterComponent *this)
{
  UFG::AudioEmitterComponent *v1; // rdi
  __int64 v2; // rbx
  UFG::qWiseSymbol *v3; // rcx

  v1 = this;
  if ( this->m_bankLoadsRequested )
  {
    v2 = 0i64;
    if ( LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) )
    {
      do
      {
        v3 = (UFG::qWiseSymbol *)&v1->m_audioEmitterDefinition.mData[1].vfptr[6 * v2];
        if ( v3[20].mUID == 5 )
          UFG::SoundBankManager::QueueBankForUnload(v3 + 21);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < LODWORD(v1->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) );
    }
    v1->m_bankLoadsRequested = 0;
  }
}

// File Line: 127
// RVA: 0x57F290
char __fastcall UFG::AudioEmitterComponent::AreBanksLoaded(UFG::AudioEmitterComponent *this)
{
  UFG::AudioEmitterComponent *v1; // rsi
  UFG::qReflectObject *v3; // rdx
  __int64 v4; // rbx
  char v5; // di
  UFG::qWiseSymbol *v6; // rcx

  v1 = this;
  if ( !this->m_bankLoadsRequested )
    return 0;
  v3 = this->m_audioEmitterDefinition.mData;
  v4 = 0i64;
  v5 = 1;
  if ( LODWORD(v3[1].mBaseNode.mUID) )
  {
    do
    {
      v6 = (UFG::qWiseSymbol *)&v3[1].vfptr[6 * v4];
      if ( v6[20].mUID == 5 )
        v5 &= UFG::SoundBankManager::BankLoadRequestFinished(v6 + 21);
      v3 = v1->m_audioEmitterDefinition.mData;
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < LODWORD(v3[1].mBaseNode.mUID) );
  }
  return v5;
}

// File Line: 147
// RVA: 0x588690
void __fastcall UFG::AudioEmitterComponent::PlayEvents(UFG::AudioEmitterComponent *this)
{
  UFG::AudioEmitterComponent *v1; // rdi
  __int64 v2; // rsi
  signed __int64 v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::TransformNodeComponent *v5; // rbp

  v1 = this;
  if ( !this->m_eventsPlaying )
  {
    v2 = 0i64;
    if ( LODWORD(this->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) )
    {
      do
      {
        v3 = (signed __int64)&v1->m_audioEmitterDefinition.mData[1].vfptr[6 * v2];
        if ( *(_DWORD *)(v3 + 80) == 1 )
        {
          v4 = v1->m_pSimObject;
          if ( v4 )
            v5 = v4->m_pTransformNodeComponent;
          else
            v5 = 0i64;
          if ( !UFG::OneShotHandle::IsValid(&v1->m_oneShotHandle) )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v5);
            UFG::OneShotPool::GetOneShotHandle(&v1->m_oneShotHandle, &v5->mWorldTransform);
          }
          if ( UFG::OneShotHandle::IsValid(&v1->m_oneShotHandle) )
            UFG::OneShot::Play(v1->m_oneShotHandle.m_pOneShot, *(_DWORD *)(v3 + 84));
        }
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < LODWORD(v1->m_audioEmitterDefinition.mData[1].mBaseNode.mUID) );
    }
    v1->m_eventsPlaying = 1;
  }
}

