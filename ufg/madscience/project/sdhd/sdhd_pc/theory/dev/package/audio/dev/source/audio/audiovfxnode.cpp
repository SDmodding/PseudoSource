// File Line: 25
// RVA: 0x141310
void __fastcall UFG::AudioVFXNode::~AudioVFXNode(UFG::AudioVFXNode *this)
{
  UFG::AudioVFXNode *v1; // rbx
  UFG::OneShot *v2; // rcx
  UFG::OneShot *v3; // rax
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v4; // rdx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v5; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::AudioVFXNodeVtbl *)&UFG::AudioVFXNode::`vftable;
  this->m_eventId = 0;
  this->m_fxInstance = 0i64;
  v2 = this->m_oneShot.m_pOneShot;
  if ( v2 )
    UFG::OneShotPool::Free(v2);
  v3 = v1->m_oneShot.m_pOneShot;
  if ( v3 && v3->m_pOwnerHandle )
    v3->m_pOwnerHandle = 0i64;
  v1->m_oneShot.m_pOneShot = 0i64;
  v4 = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 32
// RVA: 0x14A0B0
void __fastcall UFG::AudioVFXNode::Play(UFG::AudioVFXNode *this, Render::FXInstance *instance, unsigned int eventId)
{
  unsigned int v3; // edi
  Render::FXInstance *v4; // rsi
  UFG::AudioVFXNode *v5; // rbx
  UFG::qBaseTreeRB *v6; // rax
  float v7; // xmm0_4
  UFG::qMatrix44 *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::OneShot *v11; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-18h]

  v3 = eventId;
  v4 = instance;
  v5 = this;
  if ( eventId
    && (v6 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, eventId)) != 0i64
    && (v7 = *(float *)&v6->mNULL.mChild[0][3].mParent, v7 > 0.1) )
  {
    v5->m_maxDist2 = v7 * v7;
  }
  else
  {
    v5->m_maxDist2 = 10000.0;
  }
  v5->m_fxInstance = v4;
  v5->m_eventId = v3;
  v8 = Render::FXInstance::GetBasis(v4);
  v9 = v8->v3.y;
  position.x = v8->v3.x;
  v10 = v8->v3.z;
  position.y = v9;
  position.z = v10;
  UFG::OneShotPool::GetOneShotHandle(&v5->m_oneShot, &position);
  v11 = v5->m_oneShot.m_pOneShot;
  if ( v11 )
    UFG::OneShot::Play(v11, v3);
}

// File Line: 80
// RVA: 0x14DBE0
void __fastcall UFG::AudioVFXNode::Update(UFG::AudioVFXNode *this, float delta_sec)
{
  UFG::AudioVFXNode *v2; // rbx
  UFG::qMatrix44 *v3; // rax
  float v4; // xmm6_4
  UFG::qMatrix44 *v5; // rax
  UFG::OneShot *v6; // rcx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::OneShot *v10; // rax
  UFG::AudioEvent *v11; // rcx
  UFG::OneShot *v12; // rax
  UFG::qMatrix44 *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::OneShot *v16; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = Render::FXInstance::GetBasis(this->m_fxInstance);
  v4 = (float)((float)((float)(v3->v3.y - UFG::AudioListener::sm_pInstance->m_position.y)
                     * (float)(v3->v3.y - UFG::AudioListener::sm_pInstance->m_position.y))
             + (float)((float)(v3->v3.x - UFG::AudioListener::sm_pInstance->m_position.x)
                     * (float)(v3->v3.x - UFG::AudioListener::sm_pInstance->m_position.x)))
     + (float)((float)(v3->v3.z - UFG::AudioListener::sm_pInstance->m_position.z)
             * (float)(v3->v3.z - UFG::AudioListener::sm_pInstance->m_position.z));
  if ( v2->m_oneShot.m_pOneShot && v4 <= v2->m_maxDist2 )
  {
    v5 = Render::FXInstance::GetBasis(v2->m_fxInstance);
    v6 = v2->m_oneShot.m_pOneShot;
    v7 = v5->v3.x;
    v8 = v5->v3.y;
    v9 = v5->v3.z;
    v6->m_WorldMatrix.v3.w = 1.0;
    v6->m_WorldMatrix.v3.x = v7;
    v6->m_WorldMatrix.v3.y = v8;
    v6->m_WorldMatrix.v3.z = v9;
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v6->vfptr);
  }
  v10 = v2->m_oneShot.m_pOneShot;
  if ( v10 )
  {
    if ( v4 > v2->m_maxDist2 )
    {
      if ( v10->m_bIsInitialized && v10->m_controller.m_pEvent )
      {
        v11 = v10->m_controller.m_pEvent;
        if ( v11 )
          UFG::AudioEvent::StopAndForget(v11, 0x9C4u);
        v12 = v2->m_oneShot.m_pOneShot;
        if ( v12 )
        {
          if ( v12->m_pOwnerHandle )
            v12->m_pOwnerHandle = 0i64;
        }
        v2->m_oneShot.m_pOneShot = 0i64;
      }
      v2->m_stoppedFromDistCutoff = 1;
      return;
    }
    if ( v10 )
      return;
  }
  if ( v4 < v2->m_maxDist2 )
  {
    if ( v2->m_stoppedFromDistCutoff )
    {
      v13 = Render::FXInstance::GetBasis(v2->m_fxInstance);
      v14 = v13->v3.y;
      position.x = v13->v3.x;
      v15 = v13->v3.z;
      position.y = v14;
      position.z = v15;
      UFG::OneShotPool::GetOneShotHandle(&v2->m_oneShot, &position);
      v16 = v2->m_oneShot.m_pOneShot;
      if ( v16 )
      {
        UFG::OneShot::Play(v16, v2->m_eventId);
        v2->m_stoppedFromDistCutoff = 0;
      }
    }
  }
}

// File Line: 106
// RVA: 0x1465220
__int64 dynamic_initializer_for__UFG::AudioVFXManager::sm_list__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AudioVFXManager::sm_list__);
}

// File Line: 124
// RVA: 0x1427C0
void __fastcall UFG::AudioVFXManager::Add(Render::FXInstance *fxInstance, unsigned int eventId)
{
  unsigned int v2; // ebx
  Render::FXInstance *v3; // rdi
  char *v4; // rax
  char *v5; // rcx
  _QWORD *v6; // rax
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **v7; // rdx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v8; // rax

  v2 = eventId;
  v3 = fxInstance;
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
  v7 = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **)(v5 + 8);
  v8 = UFG::AudioVFXManager::sm_list.mNode.mPrev;
  UFG::AudioVFXManager::sm_list.mNode.mPrev->mNext = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)(v5 + 8);
  *v7 = v8;
  v7[1] = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)&UFG::AudioVFXManager::sm_list;
  UFG::AudioVFXManager::sm_list.mNode.mPrev = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)(v5 + 8);
  UFG::AudioVFXNode::Play((UFG::AudioVFXNode *)v5, v3, v2);
}

// File Line: 132
// RVA: 0x14B400
void __fastcall UFG::AudioVFXManager::Remove(Render::FXInstance *fxInstance)
{
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **v1; // rbx
  UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *v2; // rax
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v3; // rdi
  UFG::AudioEvent *v4; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v5; // rdx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v6; // rax
  _QWORD *v7; // r8

  v1 = &UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext;
  if ( &UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext != (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **)((char *)&UFG::AudioVFXManager::sm_list - 8) )
  {
    while ( 1 )
    {
      v2 = (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)&v1[2][-1].mNext;
      if ( v1[3] == (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)fxInstance )
        break;
      v1 = &v1[2][-1].mNext;
      if ( v2 == (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)((char *)&UFG::AudioVFXManager::sm_list - 8) )
        return;
    }
    v3 = v1[4];
    if ( v3 && LOBYTE(v3[18].mNext) && v3[21].mPrev )
    {
      v4 = (UFG::AudioEvent *)v3[21].mPrev;
      if ( v4 )
        UFG::AudioEvent::StopAndForget(v4, 0x9C4u);
      if ( v3[21].mNext )
        v3[21].mNext = 0i64;
      v1[4] = 0i64;
    }
    v5 = v1[1];
    v6 = v1[2];
    v7 = v1 + 1;
    v5->mNext = v6;
    v6->mPrev = v5;
    *v7 = v7;
    v7[1] = v7;
    ((void (__fastcall *)(UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **, signed __int64))(*v1)->mPrev)(v1, 1i64);
  }
}

// File Line: 158
// RVA: 0x14DB80
void __fastcall UFG::AudioVFXManager::Update(float delta_sec)
{
  UFG::AudioVFXNode *v1; // rcx
  UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *v2; // rbx

  v1 = (UFG::AudioVFXNode *)&UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext;
  if ( &UFG::AudioVFXManager::sm_list.mNode.mNext[-1].mNext != (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> **)((char *)&UFG::AudioVFXManager::sm_list - 8) )
  {
    do
    {
      v2 = (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)&v1->mNext[-1].mNext;
      UFG::AudioVFXNode::Update(v1, delta_sec);
      v1 = (UFG::AudioVFXNode *)v2;
    }
    while ( v2 != (UFG::qList<UFG::AudioVFXNode,UFG::AudioVFXNode,1,0> *)((char *)&UFG::AudioVFXManager::sm_list - 8) );
  }
}

