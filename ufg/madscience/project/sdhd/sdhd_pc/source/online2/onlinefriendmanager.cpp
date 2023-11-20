// File Line: 14
// RVA: 0x150CDE0
__int64 UFG::OnlineFriendManager::_dynamic_initializer_for__nFriends__()
{
  return atexit(UFG::OnlineFriendManager::_dynamic_atexit_destructor_for__nFriends__);
}

// File Line: 15
// RVA: 0x150CE00
__int64 UFG::OnlineFriendManager::_dynamic_initializer_for__nFriendsMutex__()
{
  UFG::qMutex::qMutex(&UFG::OnlineFriendManager::nFriendsMutex, "Online friends list");
  return atexit(UFG::OnlineFriendManager::_dynamic_atexit_destructor_for__nFriendsMutex__);
}

// File Line: 26
// RVA: 0x42ADE0
void __fastcall UFG::OnlineFriendManager::Clear(UFG::OnlineFriendManager *this)
{
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *i; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v2; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v3; // rdx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
  for ( i = UFG::OnlineFriendManager::nFriends.mNode.mNext;
        &UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext != (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)((char *)&UFG::OnlineFriendManager::nFriends - 8);
        i = UFG::OnlineFriendManager::nFriends.mNode.mNext )
  {
    v2 = i->mNext;
    v3 = i->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **, signed __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
  UFG::OnlineFriendManager::nState = 0;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
}

// File Line: 37
// RVA: 0x42C450
char __fastcall UFG::OnlineFriendManager::FindFriend(UFG::OnlineFriend *frnd, UFG::OnlineId *id)
{
  UFG::OnlineId *v2; // rdi
  UFG::OnlineFriend *v3; // rbx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **v4; // rdx
  char result; // al

  v2 = id;
  v3 = frnd;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
  v4 = &UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext;
  if ( &UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext == (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)((char *)&UFG::OnlineFriendManager::nFriends - 8) )
  {
LABEL_4:
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
    result = 0;
  }
  else
  {
    while ( v4[5] != (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)v2->m_SteamId.m_steamid.m_unAll64Bits )
    {
      v4 = &v4[2][-1].mNext;
      if ( v4 == (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)((char *)&UFG::OnlineFriendManager::nFriends - 8) )
        goto LABEL_4;
    }
    if ( v3 != (UFG::OnlineFriend *)v4 )
    {
      v3->m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = (unsigned __int64)v4[5];
      UFG::qString::Set(&v3->m_sOnlineName, (const char *)v4[9], *((_DWORD *)v4 + 17), 0i64, 0);
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
    result = 1;
  }
  return result;
}

