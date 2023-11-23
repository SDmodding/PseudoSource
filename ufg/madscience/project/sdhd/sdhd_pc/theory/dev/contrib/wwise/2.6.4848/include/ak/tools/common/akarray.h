// File Line: 285
// RVA: 0x1428A0
hkQueue<hkpRigidBody *> *__fastcall AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(
        AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *this)
{
  unsigned __int64 m_uLength; // rdi
  __int64 v3; // rdx
  hkQueue<hkpRigidBody *> *v4; // rdi
  char v6; // [rsp+50h] [rbp+8h] BYREF
  AK::SoundEngine::DynamicSequence::PlaylistItem *v7; // [rsp+58h] [rbp+10h]
  char *v8; // [rsp+60h] [rbp+18h]
  hkQueue<hkpRigidBody *> *v9; // [rsp+68h] [rbp+20h]

  m_uLength = this->m_uLength;
  if ( m_uLength >= this->m_ulReserved
    && !AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::GrowArray(
          this,
          4u)
    || m_uLength >= this->m_ulReserved )
  {
    return 0i64;
  }
  v3 = this->m_uLength;
  v7 = &this->m_pItems[v3];
  v4 = (hkQueue<hkpRigidBody *> *)v7;
  this->m_uLength = v3 + 1;
  v8 = &v6;
  v9 = v4;
  if ( v4 )
    hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v4);
  return v4;
}

// File Line: 425
// RVA: 0x1468D0
bool __fastcall AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::GrowArray(
        AkArray<AK::SoundEngine::DynamicSequence::PlaylistItem,AK::SoundEngine::DynamicSequence::PlaylistItem const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *this,
        unsigned int in_uGrowBy)
{
  __int64 v3; // r12
  AK::SoundEngine::DynamicSequence::PlaylistItem *v4; // rax
  AK::SoundEngine::DynamicSequence::PlaylistItem *v5; // rbp
  unsigned __int64 m_uLength; // r15
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r14
  char v10; // [rsp+78h] [rbp+10h] BYREF
  AK::SoundEngine::DynamicSequence::PlaylistItem *v11; // [rsp+80h] [rbp+18h]
  char *v12; // [rsp+88h] [rbp+20h]

  v3 = in_uGrowBy + this->m_ulReserved;
  v4 = (AK::SoundEngine::DynamicSequence::PlaylistItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v3);
  v5 = v4;
  v11 = v4;
  if ( v4 )
  {
    m_uLength = this->m_uLength;
    if ( this->m_pItems )
    {
      v7 = 0i64;
      if ( this->m_uLength )
      {
        v12 = &v10;
        do
        {
          v8 = v7;
          if ( &v5[v7] )
            hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>((hkQueue<hkpRigidBody *> *)&v5[v7]);
          AK::SoundEngine::DynamicSequence::PlaylistItem::operator=(&v5[v7], &this->m_pItems[v8]);
          AK::SoundEngine::DynamicSequence::PlaylistItem::~PlaylistItem(&this->m_pItems[v8]);
          ++v7;
        }
        while ( v7 < m_uLength );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pItems);
    }
    this->m_pItems = v5;
    this->m_ulReserved = v3;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

