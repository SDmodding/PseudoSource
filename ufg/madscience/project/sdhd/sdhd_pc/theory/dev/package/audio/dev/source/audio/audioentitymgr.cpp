// File Line: 23
// RVA: 0x1464FA0
__int64 dynamic_initializer_for__UFG::AudioEntityManager::sm_EntityList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEntityManager::sm_EntityList__);
}

// File Line: 78
// RVA: 0x14D300
void __fastcall UFG::AudioEntityManager::Update(float delta_sec)
{
  UFG::AudioEntity *v1; // rcx
  UFG::AudioEntity *v2; // rcx
  UFG::EventInfo **v3; // rdi
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v4; // rbx
  char v5; // al
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v6; // rcx

  v1 = (UFG::AudioEntity *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
  for ( UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate = (UFG::AudioEntity *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
        v1 != (UFG::AudioEntity *)((char *)&UFG::AudioEntityManager::sm_EntityList - 8);
        UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate = v1 )
  {
    ((void (*)(void))v1->vfptr->AudioEntityUpdate)();
    v2 = UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate;
    v3 = &UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate->m_eventInfos.p;
    v4 = &UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate->m_events.mNode.mNext[-1].mNext;
    if ( v4 != (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)&UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate->m_eventInfos.p )
    {
      do
      {
        if ( v4[13] )
          UFG::AudioEvent::PoolUpdate((UFG::AudioEvent *)v4);
        v5 = *((_BYTE *)v4 + 144);
        if ( v5 & 4 || v5 & 1 && *((float *)v4 + 34) <= 0.0 )
        {
          v6 = v4;
          v4 = &v4[2][-1].mNext;
          if ( v6 )
            ((void (__fastcall *)(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **, signed __int64))(*v6)->mPrev)(
              v6,
              1i64);
        }
        else
        {
          v4 = &v4[2][-1].mNext;
        }
      }
      while ( v4 != (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)v3 );
      v2 = UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate;
    }
    v1 = (UFG::AudioEntity *)&v2->mNext[-1].mNext;
  }
  UFG::AudioEntityManager::sm_pCurrentEntityInListUpdate = 0i64;
}

// File Line: 146
// RVA: 0x145770
UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *__fastcall UFG::AudioEntityManager::FindNamed(UFG::qSymbol *name)
{
  UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *v1; // rbx
  unsigned int v2; // esi
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v1 = (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)&UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext;
  if ( &UFG::AudioEntityManager::sm_EntityList.mNode.mNext[-1].mNext == (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> **)((char *)&UFG::AudioEntityManager::sm_EntityList - 8) )
    return 0i64;
  v2 = name->mUID;
  while ( v2 != UFG::AudioEntity::GetName((UFG::AudioEntity *)v1, &result)->mUID )
  {
    v1 = (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)&v1[1].mNode.mPrev[-1].mNext;
    if ( v1 == (UFG::qList<UFG::AudioEntity,UFG::AudioEntity,0,1> *)((char *)&UFG::AudioEntityManager::sm_EntityList - 8) )
      return 0i64;
  }
  return v1;
}

