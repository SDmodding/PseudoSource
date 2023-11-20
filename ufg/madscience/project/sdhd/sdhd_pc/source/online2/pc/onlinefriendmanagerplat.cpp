// File Line: 21
// RVA: 0xA406E0
__int64 __fastcall UFG::OnlineFriendManager::GetFriends(UFG::qList<UFG::OnlineFriend,UFG::OnlineFriend,1,0> *friends)
{
  UFG::qList<UFG::OnlineFriend,UFG::OnlineFriend,1,0> *v1; // rsi
  int v2; // ebx
  __int64 result; // rax
  __int64 v4; // rdx
  __int64 v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rax
  int v14; // er15
  __int64 v15; // rdx
  __int64 v16; // rcx
  unsigned int v17; // er14
  __int64 v18; // rax
  __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // rax
  const char *v22; // rax
  UFG::allocator::free_link *v23; // rdi
  UFG::allocator::free_link *v24; // rax
  UFG::allocator::free_link *v25; // rcx
  _QWORD *v26; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v27; // rax
  __int64 *v28; // rcx
  __int64 **v29; // rax
  UFG::OnlineFriend *i; // rbx
  UFG::allocator::free_link *v31; // rax
  __int64 v32; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v33; // rdx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v34; // rax
  __int64 v35; // [rsp+20h] [rbp-58h]
  signed __int64 v36; // [rsp+28h] [rbp-50h]
  __int64 *v37; // [rsp+30h] [rbp-48h]
  __int64 **v38; // [rsp+38h] [rbp-40h]
  UFG::allocator::free_link *v39; // [rsp+40h] [rbp-38h]
  UFG::qString text; // [rsp+48h] [rbp-30h]
  UFG::qList<UFG::OnlineFriend,UFG::OnlineFriend,1,0> *v41; // [rsp+C0h] [rbp+48h]
  UFG::allocator::free_link *v42; // [rsp+C8h] [rbp+50h]
  UFG::allocator::free_link *v43; // [rsp+D0h] [rbp+58h]
  UFG::allocator::free_link *v44; // [rsp+D8h] [rbp+60h]

  v41 = friends;
  v36 = -2i64;
  v1 = friends;
  v2 = 0;
  LODWORD(v35) = 0;
  result = (unsigned int)UFG::OnlineFriendManager::nState;
  if ( UFG::OnlineFriendManager::nState != 2 )
  {
    if ( UFG::OnlineFriendManager::nState == State_Idle )
    {
      UFG::OnlineFriendManager::Clear((UFG::OnlineFriendManager *)friends);
      if ( SteamUserStats(v5, v4) )
      {
        if ( SteamUser(v7, v6) )
        {
          v10 = SteamUser(v9, v8);
          if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v10 + 8i64))(v10) )
          {
            v13 = SteamFriends(v12, v11);
            v14 = (*(__int64 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v13 + 24i64))(v13, 4i64);
            UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
            v17 = 0;
            if ( v14 > 0 )
            {
              do
              {
                v18 = SteamFriends(v16, v15);
                (*(void (__fastcall **)(__int64, UFG::allocator::free_link **, _QWORD, signed __int64, __int64, signed __int64))(*(_QWORD *)v18 + 32i64))(
                  v18,
                  &v42,
                  v17,
                  4i64,
                  v35,
                  v36);
                v21 = SteamFriends(v20, v19);
                v22 = (const char *)(*(__int64 (__fastcall **)(__int64, UFG::allocator::free_link *))(*(_QWORD *)v21 + 56i64))(
                                      v21,
                                      v42);
                UFG::qString::qString(&text, v22);
                v23 = UFG::qMalloc(0x58ui64, "OnlineFriendManager", 0i64);
                v43 = v23;
                if ( v23 )
                {
                  v37 = (__int64 *)&v37;
                  v38 = &v37;
                  v39 = v42;
                  v2 |= 1u;
                  LODWORD(v35) = v2;
                  v24 = v23 + 1;
                  v24->mNext = v24;
                  v24[1].mNext = v24;
                  v23->mNext = (UFG::allocator::free_link *)&UFG::OnlineFriend::`vftable';
                  v25 = v23 + 3;
                  v44 = v25;
                  v25->mNext = v25;
                  v25[1].mNext = v25;
                  LODWORD(v23[5].mNext) = 0;
                  HIDWORD(v23[5].mNext) &= 0xFF0FFFFF;
                  HIBYTE(v23[5].mNext) = 0;
                  HIDWORD(v23[5].mNext) &= 0xFFF00000;
                  v23[5].mNext = v39;
                  UFG::qString::qString((UFG::qString *)&v23[6], &text);
                }
                else
                {
                  v23 = 0i64;
                }
                v26 = &v23[1].mNext;
                v27 = UFG::OnlineFriendManager::nFriends.mNode.mPrev;
                UFG::OnlineFriendManager::nFriends.mNode.mPrev->mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v23[1];
                *v26 = v27;
                v26[1] = &UFG::OnlineFriendManager::nFriends;
                UFG::OnlineFriendManager::nFriends.mNode.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v23[1];
                if ( v2 & 1 )
                {
                  v2 &= 0xFFFFFFFE;
                  LODWORD(v35) = v2;
                  v28 = v37;
                  v29 = v38;
                  v37[1] = (__int64)v38;
                  *v29 = v28;
                  v37 = (__int64 *)&v37;
                  v38 = &v37;
                }
                UFG::qString::~qString(&text);
                ++v17;
              }
              while ( (signed int)v17 < v14 );
              v1 = v41;
            }
            UFG::OnlineFriendManager::nState = 1;
            UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
          }
        }
      }
      result = (unsigned int)UFG::OnlineFriendManager::nState;
    }
    if ( (_DWORD)result == 1 && v1 )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
      for ( i = (UFG::OnlineFriend *)&UFG::OnlineFriendManager::nFriends.mNode.mNext[-1].mNext;
            i != (UFG::OnlineFriend *)((char *)&UFG::OnlineFriendManager::nFriends - 8);
            i = (UFG::OnlineFriend *)&i->mNext[-1].mNext )
      {
        v31 = UFG::qMalloc(0x58ui64, "OnlineFriendManager", 0i64);
        v42 = v31;
        if ( v31 )
          UFG::OnlineFriend::OnlineFriend((UFG::OnlineFriend *)v31, i);
        else
          v32 = 0i64;
        v33 = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)(v32 + 8);
        v34 = v1->mNode.mPrev;
        v34->mNext = v33;
        v33->mPrev = v34;
        v33->mNext = &v1->mNode;
        v1->mNode.mPrev = v33;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
      result = (unsigned int)UFG::OnlineFriendManager::nState;
    }
  }
  return result;
}

