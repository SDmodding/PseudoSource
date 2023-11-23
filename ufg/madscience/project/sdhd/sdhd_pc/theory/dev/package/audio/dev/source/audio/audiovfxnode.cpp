// File Line: 25
// RVA: 0x141310
void __fastcall UFG::AudioVFXNode::~AudioVFXNode(UFG::AudioVFXNode *this)
{
  UFG::OneShot *m_pOneShot; // rcx
  UFG::OneShot *v3; // rax
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mPrev; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mNext; // rax

  this->vfptr = (UFG::AudioVFXNodeVtbl *)&UFG::AudioVFXNode::`vftable;
  this->m_eventId = 0;
  this->m_fxInstance = 0i64;
  m_pOneShot = this->m_oneShot.m_pOneShot;
  if ( m_pOneShot )
    UFG::OneShotPool::Free(m_pOneShot);
  v3 = this->m_oneShot.m_pOneShot;
  if ( v3 && v3->m_pOwnerHandle )
    v3->m_pOwnerHandle = 0i64;
  this->m_oneShot.m_pOneShot = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode>;
  this->mNext = &this->UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode>;
}

// File Line: 32
// RVA: 0x14A0B0
void __fastcall UFG::AudioVFXNode::Play(UFG::AudioVFXNode *this, Render::FXInstance *instance, unsigned int eventId)
{
  UFG::qBaseTreeRB *v6; // rax
  float v7; // xmm0_4
  UFG::qMatrix44 *Basis; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::OneShot *m_pOneShot; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-18h] BYREF

  if ( eventId
    && (v6 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, eventId)) != 0i64
    && (v7 = *(float *)&v6->mNULL.mChild[0][3].mParent, v7 > 0.1) )
  {
    this->m_maxDist2 = v7 * v7;
  }
  else
  {
    this->m_maxDist2 = 10000.0;
  }
  this->m_fxInstance = instance;
  this->m_eventId = eventId;
  Basis = Render::FXInstance::GetBasis(instance);
  y = Basis->v3.y;
  position.x = Basis->v3.x;
  z = Basis->v3.z;
  position.y = y;
  position.z = z;
  UFG::OneShotPool::GetOneShotHandle(&this->m_oneShot, &position);
  m_pOneShot = this->m_oneShot.m_pOneShot;
  if ( m_pOneShot )
    UFG::OneShot::Play(m_pOneShot, eventId);
}

// File Line: 80
// RVA: 0x14DBE0
void __fastcall UFG::AudioVFXNode::Update(UFG::AudioVFXNode *this, float delta_sec)
{
  UFG::qMatrix44 *Basis; // rax
  float v4; // xmm6_4
  UFG::qMatrix44 *v5; // rax
  UFG::OneShot *m_pOneShot; // rcx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::OneShot *v10; // rax
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::OneShot *v12; // rax
  UFG::qMatrix44 *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::OneShot *v16; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-28h] BYREF

  Basis = Render::FXInstance::GetBasis(this->m_fxInstance);
  v4 = (float)((float)((float)(Basis->v3.y - UFG::AudioListener::sm_pInstance->m_position.y)
                     * (float)(Basis->v3.y - UFG::AudioListener::sm_pInstance->m_position.y))
             + (float)((float)(Basis->v3.x - UFG::AudioListener::sm_pInstance->m_position.x)
                     * (float)(Basis->v3.x - UFG::AudioListener::sm_pInstance->m_position.x)))
     + (float)((float)(Basis->v3.z - UFG::AudioListener::sm_pInstance->m_position.z)
             * (float)(Basis->v3.z - UFG::AudioListener::sm_pInstance->m_position.z));
  if ( this->m_oneShot.m_pOneShot && v4 <= this->m_maxDist2 )
  {
    v5 = Render::FXInstance::GetBasis(this->m_fxInstance);
    m_pOneShot = this->m_oneShot.m_pOneShot;
    x = v5->v3.x;
    y = v5->v3.y;
    z = v5->v3.z;
    m_pOneShot->m_WorldMatrix.v3.w = 1.0;
    m_pOneShot->m_WorldMatrix.v3.x = x;
    m_pOneShot->m_WorldMatrix.v3.y = y;
    m_pOneShot->m_WorldMatrix.v3.z = z;
    UFG::AudioEntity::ForcePositionUpdate(m_pOneShot);
  }
  v10 = this->m_oneShot.m_pOneShot;
  if ( v10 )
  {
    if ( v4 > this->m_maxDist2 )
    {
      if ( v10->m_bIsInitialized && v10->m_controller.m_pEvent )
      {
        m_pEvent = v10->m_controller.m_pEvent;
        if ( m_pEvent )
          UFG::AudioEvent::StopAndForget(m_pEvent, 2500);
        v12 = this->m_oneShot.m_pOneShot;
        if ( v12 )
        {
          if ( v12->m_pOwnerHandle )
            v12->m_pOwnerHandle = 0i64;
        }
        this->m_oneShot.m_pOneShot = 0i64;
      }
      this->m_stoppedFromDistCutoff = 1;
    }
  }
  else if ( v4 < this->m_maxDist2 && this->m_stoppedFromDistCutoff )
  {
    v13 = Render::FXInstance::GetBasis(this->m_fxInstance);
    v14 = v13->v3.y;
    position.x = v13->v3.x;
    v15 = v13->v3.z;
    position.y = v14;
    position.z = v15;
    UFG::OneShotPool::GetOneShotHandle(&this->m_oneShot, &position);
    v16 = this->m_oneShot.m_pOneShot;
    if ( v16 )
    {
      UFG::OneShot::Play(v16, this->m_eventId);
      this->m_stoppedFromDistCutoff = 0;
    }
  }
}

// File Line: 106
// RVA: 0x1465220
__int64 dynamic_initializer_for__UFG::AudioVFXManager::sm_list__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioVFXManager::sm_list__);
}

// File Line: 124
// RVA: 0x1427C0
void __fastcall UFG::AudioVFXManager::Add(Render::FXInstance *fxInstance, unsigned int eventId)
{
  char *v4; // rax
  char *v5; // rcx
  _QWORD *v6; // rax
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mPrev; // rax

  v4 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x38ui64, "AudioVFXNode", 0i64, 1u);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4 + 8;
    *v6 = v6;
    v6[1] = v6;
    *(_QWORD *)v5 = &UFG::AudioVFXNode::`vftable;
    *((_QWORD *)v5 + 3) = 0i64;
    *((_QWORD *)v5 + 4) = 0i64;
    *((_QWORD *)v5 + 5) = 0i64;
    v5[48] = 0;
  }
  else
  {
    v5 = 0i64;
  }
  mPrev = UFG::AudioVFXManager::sm_list.mNode.mPrev;
  UFG::AudioVFXManager::sm_list.mNode.mPrev->mNext = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)(v5 + 8);
  *((_QWORD *)v5 + 1) = mPrev;
  *((_QWORD *)v5 + 2) = &UFG::AudioVFXManager::sm_list;
  UFG::AudioVFXManager::sm_list.mNode.mPrev = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)(v5 + 8);
  UFG::AudioVFXNode::Play((UFG::AudioVFXNode *)v5, fxInstance, eventId);
}

// File Line: 132
// RVA: 0x14B400
void __fastcall UFG::AudioVFXManager::Remove(UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *fxInstance)
{
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **p_mNext; // rbx
  UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *v2; // rax
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v3; // rdi
  UFG::AudioEvent *mPrev; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v5; // rdx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v6; // rax

  p_mNext = &UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext;
  if ( &UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext != (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **)((char *)&UFG::AudioVFXManager::sm_list - 8) )
  {
    while ( 1 )
    {
      v2 = (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)&p_mNext[2][-1].mNext;
      if ( p_mNext[3] == fxInstance )
        break;
      p_mNext = &p_mNext[2][-1].mNext;
      if ( v2 == (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)((char *)&UFG::AudioVFXManager::sm_list - 8) )
        return;
    }
    v3 = p_mNext[4];
    if ( v3 && LOBYTE(v3[18].mNext) && v3[21].mPrev )
    {
      mPrev = (UFG::AudioEvent *)v3[21].mPrev;
      if ( mPrev )
        UFG::AudioEvent::StopAndForget(mPrev, 0x9C4u);
      if ( v3[21].mNext )
        v3[21].mNext = 0i64;
      p_mNext[4] = 0i64;
    }
    v5 = p_mNext[1];
    v6 = p_mNext[2];
    v5->mNext = v6;
    v6->mPrev = v5;
    p_mNext[1] = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)(p_mNext + 1);
    p_mNext[2] = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)(p_mNext + 1);
    ((void (__fastcall *)(UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **, __int64))(*p_mNext)->mPrev)(p_mNext, 1i64);
  }
}

// File Line: 158
// RVA: 0x14DB80
void __fastcall UFG::AudioVFXManager::Update(float delta_sec)
{
  UFG::AudioVFXNode *p_mNext; // rcx
  UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *v2; // rbx

  p_mNext = (UFG::AudioVFXNode *)&UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext;
  if ( &UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext != (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **)((char *)&UFG::AudioVFXManager::sm_list - 8) )
  {
    do
    {
      v2 = (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)&p_mNext->mNext[-1].mNext;
      UFG::AudioVFXNode::Update(p_mNext, delta_sec);
      p_mNext = (UFG::AudioVFXNode *)v2;
    }
    while ( v2 != (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)((char *)&UFG::AudioVFXManager::sm_list - 8) );
  }
}

