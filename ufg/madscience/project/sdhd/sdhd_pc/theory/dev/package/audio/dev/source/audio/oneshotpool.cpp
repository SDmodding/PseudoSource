// File Line: 29
// RVA: 0x146200
UFG::OneShot *__fastcall UFG::OneShotPool::GetOneShot(UFG::qMatrix44 *transform)
{
  char *v2; // rax
  UFG::OneShot *v3; // rax
  UFG::OneShot *v4; // rbx

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
  UFG::OneShot::Init(v4, ((char *)v4 - UFG::gOneShotPool.mBuffer) / UFG::gOneShotPool.mSlotSize, transform);
  return v4;
}

// File Line: 56
// RVA: 0x146290
void __fastcall UFG::OneShotPool::GetOneShotHandle(UFG::OneShotHandle *pHandle, UFG::qMatrix44 *transform)
{
  UFG::OneShot *OneShot; // rax

  OneShot = UFG::OneShotPool::GetOneShot(transform);
  pHandle->m_pOneShot = OneShot;
  if ( OneShot )
    OneShot->m_pOwnerHandle = pHandle;
}

// File Line: 71
// RVA: 0x1462C0
void __fastcall UFG::OneShotPool::GetOneShotHandle(UFG::OneShotHandle *pHandle, UFG::qVector3 *position)
{
  float y; // xmm1_4
  float z; // xmm2_4
  char *v5; // rax
  UFG::OneShot *v6; // rbx
  UFG::OneShot *v7; // rax
  UFG::OneShot *v8; // rdi
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-48h] BYREF

  transform.v0 = UFG::qMatrix44::msIdentity.v0;
  transform.v1 = UFG::qMatrix44::msIdentity.v1;
  transform.v2 = UFG::qMatrix44::msIdentity.v2;
  y = position->y;
  z = position->z;
  transform.v3.x = position->x;
  transform.v3.y = y;
  transform.v3.z = z;
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
  pHandle->m_pOneShot = v6;
  if ( v6 )
    v6->m_pOwnerHandle = pHandle;
}

// File Line: 81
// RVA: 0x145BB0
void __fastcall UFG::OneShotPool::Free(UFG::OneShot *oneShot)
{
  UFG::OneShotHandle *m_pOwnerHandle; // rax
  UFG::qNode<UFG::OneShot,UFG::OneShot> *mPrev; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *mNext; // rax

  m_pOwnerHandle = oneShot->m_pOwnerHandle;
  if ( m_pOwnerHandle )
  {
    m_pOwnerHandle->m_pOneShot = 0i64;
    oneShot->m_pOwnerHandle = 0i64;
  }
  UFG::AudioEntity::Shutdown(oneShot);
  mPrev = oneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>::mPrev;
  mNext = oneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  oneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>::mPrev = &oneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>;
  oneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>::mNext = &oneShot->UFG::qNode<UFG::OneShot,UFG::OneShot>;
  oneShot->m_eventCount = 0;
  oneShot->vfptr->__vecDelDtor(oneShot, 1i64);
}

// File Line: 100
// RVA: 0x14DD60
void UFG::OneShotPool::Update(void)
{
  UFG::OneShot *i; // rbx
  UFG::OneShotHandle *m_pOwnerHandle; // rax
  UFG::qNode<UFG::OneShot,UFG::OneShot> *mPrev; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *mNext; // rax

  for ( i = (UFG::OneShot *)&UFG::OneShot::smMarkedForClearList.mNode.mNext[-20];
        (UFG::qList<UFG::OneShot,UFG::OneShot,1,0> *)&UFG::OneShot::smMarkedForClearList.mNode.mNext[-20] != &UFG::OneShot::smMarkedForClearList - 20;
        i = (UFG::OneShot *)&UFG::OneShot::smMarkedForClearList.mNode.mNext[-20] )
  {
    UFG::TiDo::m_pInstance->vfptr->OnOneShotFree(UFG::TiDo::m_pInstance, i);
    m_pOwnerHandle = i->m_pOwnerHandle;
    if ( m_pOwnerHandle )
    {
      m_pOwnerHandle->m_pOneShot = 0i64;
      i->m_pOwnerHandle = 0i64;
    }
    UFG::AudioEntity::Shutdown(i);
    mPrev = i->UFG::qNode<UFG::OneShot,UFG::OneShot>::mPrev;
    mNext = i->UFG::qNode<UFG::OneShot,UFG::OneShot>::mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->UFG::qNode<UFG::OneShot,UFG::OneShot>::mPrev = &i->UFG::qNode<UFG::OneShot,UFG::OneShot>;
    i->UFG::qNode<UFG::OneShot,UFG::OneShot>::mNext = &i->UFG::qNode<UFG::OneShot,UFG::OneShot>;
    i->m_eventCount = 0;
    i->vfptr->__vecDelDtor(i, 1u);
  }
}

