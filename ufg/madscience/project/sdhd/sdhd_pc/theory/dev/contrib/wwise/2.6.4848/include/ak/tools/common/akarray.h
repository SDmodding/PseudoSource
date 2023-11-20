// File Line: 285
// RVA: 0x1428A0
hkQueue<hkpRigidBody *> *__fastcall AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *this)
{
  AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v1; // rbx
  unsigned __int64 v2; // rdi
  __int64 v3; // rdx
  hkQueue<hkpRigidBody *> *v4; // rdi
  char v6; // [rsp+50h] [rbp+8h]
  hkQueue<hkpRigidBody *> *v7; // [rsp+58h] [rbp+10h]
  char *v8; // [rsp+60h] [rbp+18h]
  hkQueue<hkpRigidBody *> *v9; // [rsp+68h] [rbp+20h]

  v1 = this;
  v2 = this->m_uLength;
  if ( v2 >= this->m_ulReserved
    && !AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::GrowArray(
          this,
          4u)
    || v2 >= v1->m_ulReserved )
  {
    return 0i64;
  }
  v3 = v1->m_uLength;
  v7 = (hkQueue<hkpRigidBody *> *)&v1->m_pItems[v3];
  v4 = v7;
  v1->m_uLength = v3 + 1;
  v8 = &v6;
  v9 = v4;
  if ( v4 )
    hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v4);
  return v4;
}

// File Line: 425
// RVA: 0x1468D0
bool __fastcall AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::GrowArray(AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *this, unsigned int in_uGrowBy)
{
  AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v2; // rsi
  __int64 v3; // r12
  AK::SoundEngine::DynamicSequence::PlaylistItem *v4; // rax
  AK::SoundEngine::DynamicSequence::PlaylistItem *v5; // rbp
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rbx
  signed __int64 v8; // r14
  char v10; // [rsp+78h] [rbp+10h]
  AK::SoundEngine::DynamicSequence::PlaylistItem *v11; // [rsp+80h] [rbp+18h]
  char *v12; // [rsp+88h] [rbp+20h]

  v2 = this;
  v3 = in_uGrowBy + this->m_ulReserved;
  v4 = (AK::SoundEngine::DynamicSequence::PlaylistItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v3);
  v5 = v4;
  v11 = v4;
  if ( v4 )
  {
    v6 = v2->m_uLength;
    if ( v2->m_pItems )
    {
      v7 = 0i64;
      if ( v2->m_uLength )
      {
        v12 = &v10;
        do
        {
          v8 = v7;
          if ( &v5[v7] )
            hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>((hkQueue<hkpRigidBody *> *)&v5[v7]);
          AK::SoundEngine::DynamicSequence::PlaylistItem::operator=(&v5[v7], &v2->m_pItems[v8]);
          AK::SoundEngine::DynamicSequence::PlaylistItem::~PlaylistItem(&v2->m_pItems[v8]);
          ++v7;
        }
        while ( v7 < v6 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_pItems);
    }
    v2->m_pItems = v5;
    v2->m_ulReserved = v3;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

