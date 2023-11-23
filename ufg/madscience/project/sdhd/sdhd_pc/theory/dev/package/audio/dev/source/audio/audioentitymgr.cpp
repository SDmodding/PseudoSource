// File Line: 23
// RVA: 0x1464FA0
__int64 dynamic_initializer_for__UFG::AudioEntityManager::sm_EntityList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEntityManager::sm_EntityList__);
}

// File Line: 78
// RVA: 0x14D300
void __fastcall UFG::AudioEntityManager::Update(float delta_sec)
{
  UFG::AudioEntity *p_mNext; // rcx
  UFG::AudioEntity *v2; // rcx
  UFG::EventInfo **p_p; // rdi
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v4; // rbx
  char v5; // al
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v6; // rcx

  p_mNext = (UFG::AudioEntity *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
  for ( UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate = (UFG::AudioEntity *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
        p_mNext != (UFG::AudioEntity *)((char *)&UFG::AudioEntityManager::sm_EntityList - 8);
        UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate = p_mNext )
  {
    ((void (__fastcall *)(UFG::AudioEntity *))p_mNext->vfptr->AudioEntityUpdate)(p_mNext);
    v2 = UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate;
    p_p = &UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate->m_eventInfos.p;
    v4 = &UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate->m_events.mNode.mNext[-1].mNext;
    if ( v4 != (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)&UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate->m_eventInfos.p )
    {
      do
      {
        if ( v4[13] )
          UFG::AudioEvent::PoolUpdate((UFG::AudioEvent *)v4);
        v5 = *((_BYTE *)v4 + 144);
        if ( (v5 & 4) != 0 || (v5 & 1) != 0 && *((float *)v4 + 34) <= 0.0 )
        {
          v6 = v4;
          v4 = &v4[2][-1].mNext;
          if ( v6 )
            ((void (__fastcall *)(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **, __int64))(*v6)->mPrev)(v6, 1i64);
        }
        else
        {
          v4 = &v4[2][-1].mNext;
        }
      }
      while ( v4 != (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)p_p );
      v2 = UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate;
    }
    p_mNext = (UFG::AudioEntity *)&v2->mNext[-1].mNext;
  }
  UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate = 0i64;
}

// File Line: 146
// RVA: 0x145770
UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *__fastcall UFG::AudioEntityManager::FindNamed(UFG::qSymbol *name)
{
  UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *p_mNext; // rbx
  unsigned int mUID; // esi
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  p_mNext = (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
  if ( &UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext == (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> **)((char *)&UFG::AudioEntityManager::sm_EntityList - 8) )
    return 0i64;
  mUID = name->mUID;
  while ( mUID != UFG::AudioEntity::GetName((UFG::AudioEntity *)p_mNext, &result)->mUID )
  {
    p_mNext = (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)&p_mNext[1].mNode.mPrev[-1].mNext;
    if ( p_mNext == (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)((char *)&UFG::AudioEntityManager::sm_EntityList
                                                                        - 8) )
      return 0i64;
  }
  return p_mNext;
}

