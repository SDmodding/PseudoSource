// File Line: 29
// RVA: 0x146200
UFG::OneShot *__fastcall UFG::OneShotPool::GetOneShot(UFG::qMatrix44 *transform)
{
  UFG::qMatrix44 *v1; // rdi
  char *v2; // rax
  UFG::OneShot *v3; // rax
  UFG::OneShot *v4; // rbx

  v1 = transform;
  if ( UFG::OneShot::sm_disableOneShots || !UFG::gOneShotPool.mFreeListHead )
    return 0i64;
  v2 = UFG::OneShot::operator new(0x170ui64);
  if ( v2 )
  {
    UFG::OneShot::OneShot((UFG::OneShot *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  if ( !v4 )
    return 0i64;
  UFG::OneShot::Init(v4, ((char *)v4 - UFG::gOneShotPool.mBuffer) / UFG::gOneShotPool.mSlotSize, v1);
  return v4;
}

// File Line: 56
// RVA: 0x146290
void __fastcall UFG::OneShotPool::GetOneShotHandle(UFG::OneShotHandle *pHandle, UFG::qMatrix44 *transform)
{
  UFG::OneShotHandle *v2; // rbx
  UFG::OneShot *v3; // rax

  v2 = pHandle;
  v3 = UFG::OneShotPool::GetOneShot(transform);
  v2->m_pOneShot = v3;
  if ( v3 )
    v3->m_pOwnerHandle = v2;
}

// File Line: 71
// RVA: 0x1462C0
void __fastcall UFG::OneShotPool::GetOneShotHandle(UFG::OneShotHandle *pHandle, UFG::qVector3 *position)
{
  UFG::OneShotHandle *v2; // rsi
  float v3; // xmm1_4
  float v4; // xmm2_4
  char *v5; // rax
  UFG::OneShot *v6; // rbx
  UFG::OneShot *v7; // rax
  UFG::OneShot *v8; // rdi
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-48h]

  v2 = pHandle;
  transform.v0 = UFG::qMatrix44::msIdentity.v0;
  transform.v1 = UFG::qMatrix44::msIdentity.v1;
  transform.v2 = UFG::qMatrix44::msIdentity.v2;
  v3 = position->y;
  v4 = position->z;
  transform.v3.x = position->x;
  transform.v3.y = v3;
  transform.v3.z = v4;
  LODWORD(transform.v3.w) = (_DWORD)FLOAT_1_0;
  if ( UFG::OneShot::sm_disableOneShots || !UFG::gOneShotPool.mFreeListHead )
  {
    v6 = 0i64;
  }
  else
  {
    v5 = UFG::OneShot::operator new(0x170ui64);
    v6 = 0i64;
    if ( v5 )
    {
      UFG::OneShot::OneShot((UFG::OneShot *)v5);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    if ( v8 )
    {
      UFG::OneShot::Init(v8, ((char *)v8 - UFG::gOneShotPool.mBuffer) / UFG::gOneShotPool.mSlotSize, &transform);
      v6 = v8;
    }
  }
  v2->m_pOneShot = v6;
  if ( v6 )
    v6->m_pOwnerHandle = v2;
}

// File Line: 81
// RVA: 0x145BB0
void __fastcall UFG::OneShotPool::Free(UFG::OneShot *oneShot)
{
  UFG::OneShotHandle *v1; // rax
  UFG::OneShot *v2; // rbx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v3; // rdx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v4; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v5; // rax

  v1 = oneShot->m_pOwnerHandle;
  v2 = oneShot;
  if ( v1 )
  {
    v1->m_pOneShot = 0i64;
    oneShot->m_pOwnerHandle = 0i64;
  }
  UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&oneShot->vfptr);
  v3 = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&v2->mPrev;
  v4 = v2->mPrev;
  v5 = v2->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->m_eventCount = 0;
  v2->vfptr->__vecDelDtor((UFG::AudioEntity *)&v2->vfptr, 1u);
}

// File Line: 100
// RVA: 0x14DD60
void UFG::OneShotPool::Update(void)
{
  UFG::OneShot *i; // rbx
  UFG::OneShotHandle *v1; // rax
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v2; // rdx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v3; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v4; // rax

  for ( i = (UFG::OneShot *)&UFG::OneShot::smMarkedForClearList.mNode.mNext[-20];
        (UFG::qList<UFG::OneShot,UFG::OneShot,1,0> *)&UFG::OneShot::smMarkedForClearList.mNode.mNext[-20] != &UFG::OneShot::smMarkedForClearList - 20;
        i = (UFG::OneShot *)&UFG::OneShot::smMarkedForClearList.mNode.mNext[-20] )
  {
    UFG::TiDo::m_pInstance->vfptr->OnOneShotFree(UFG::TiDo::m_pInstance, i);
    v1 = i->m_pOwnerHandle;
    if ( v1 )
    {
      v1->m_pOneShot = 0i64;
      i->m_pOwnerHandle = 0i64;
    }
    UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&i->vfptr);
    v2 = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&i->mPrev;
    v3 = i->mPrev;
    v4 = i->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
    i->m_eventCount = 0;
    i->vfptr->__vecDelDtor((UFG::AudioEntity *)&i->vfptr, 1u);
  }
}

