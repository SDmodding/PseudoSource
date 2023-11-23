// File Line: 14
// RVA: 0x150CDE0
__int64 UFG::OnlineFriendManager::_dynamic_initializer_for__nFriends__()
{
  return atexit((int (__fastcall *)())UFG::OnlineFriendManager::_dynamic_atexit_destructor_for__nFriends__);
}

// File Line: 15
// RVA: 0x150CE00
__int64 UFG::OnlineFriendManager::_dynamic_initializer_for__nFriendsMutex__()
{
  UFG::qMutex::qMutex(&UFG::OnlineFriendManager::nFriendsMutex, "Online friends list");
  return atexit((int (__fastcall *)())UFG::OnlineFriendManager::_dynamic_atexit_destructor_for__nFriendsMutex__);
}

// File Line: 26
// RVA: 0x42ADE0
void __fastcall UFG::OnlineFriendManager::Clear(UFG::OnlineFriendManager *this)
{
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *i; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *mNext; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *mPrev; // rdx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
  for ( i = UFG::OnlineFriendManager::nFriends.mNode.mNext;
        &UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext != (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)((char *)&UFG::OnlineFriendManager::nFriends - 8);
        i = UFG::OnlineFriendManager::nFriends.mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **, __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
  UFG::OnlineFriendManager::nState = State_Idle;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
}

// File Line: 37
// RVA: 0x42C450
char __fastcall UFG::OnlineFriendManager::FindFriend(
        UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **frnd,
        UFG::OnlineId *id)
{
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **p_mNext; // rdx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
  p_mNext = &UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext;
  if ( &UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext == (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)((char *)&UFG::OnlineFriendManager::nFriends - 8) )
  {
LABEL_4:
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
    return 0;
  }
  else
  {
    while ( p_mNext[5] != (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)id->m_SteamId.m_steamid.m_unAll64Bits )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)((char *)&UFG::OnlineFriendManager::nFriends
                                                                         - 8) )
        goto LABEL_4;
    }
    if ( frnd != p_mNext )
    {
      frnd[5] = p_mNext[5];
      UFG::qString::Set((UFG::qString *)(frnd + 6), (const char *)p_mNext[9], *((_DWORD *)p_mNext + 17), 0i64, 0);
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
    return 1;
  }
}

