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
  int v14; // r15d
  __int64 v15; // rdx
  __int64 v16; // rcx
  int v17; // r14d
  __int64 v18; // rax
  __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // rax
  const char *v22; // rax
  UFG::allocator::free_link *v23; // rdi
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *mPrev; // rax
  __int64 *v25; // rcx
  __int64 **v26; // rax
  UFG::OnlineFriend *i; // rbx
  UFG::allocator::free_link *v28; // rax
  __int64 v29; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v30; // rdx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v31; // rax
  int v32; // [rsp+20h] [rbp-58h]
  __int64 v33; // [rsp+28h] [rbp-50h]
  __int64 *v34; // [rsp+30h] [rbp-48h] BYREF
  __int64 **v35; // [rsp+38h] [rbp-40h]
  UFG::allocator::free_link *v36; // [rsp+40h] [rbp-38h]
  UFG::qString text; // [rsp+48h] [rbp-30h] BYREF
  UFG::allocator::free_link *v39; // [rsp+C8h] [rbp+50h] BYREF
  UFG::allocator::free_link *v40; // [rsp+D0h] [rbp+58h]
  UFG::allocator::free_link *v41; // [rsp+D8h] [rbp+60h]

  v33 = -2i64;
  v1 = friends;
  v2 = 0;
  v32 = 0;
  result = (unsigned int)UFG::OnlineFriendManager::nState;
  if ( UFG::OnlineFriendManager::nState != State_Retrieving )
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
            v14 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v13 + 24i64))(v13, 4i64);
            UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
            v17 = 0;
            if ( v14 > 0 )
            {
              do
              {
                v18 = SteamFriends(v16, v15);
                (*(void (__fastcall **)(__int64, UFG::allocator::free_link **, _QWORD, __int64, int, __int64))(*(_QWORD *)v18 + 32i64))(
                  v18,
                  &v39,
                  (unsigned int)v17,
                  4i64,
                  v32,
                  v33);
                v21 = SteamFriends(v20, v19);
                v22 = (const char *)(*(__int64 (__fastcall **)(__int64, UFG::allocator::free_link *))(*(_QWORD *)v21 + 56i64))(
                                      v21,
                                      v39);
                UFG::qString::qString(&text, v22);
                v23 = UFG::qMalloc(0x58ui64, "OnlineFriendManager", 0i64);
                v40 = v23;
                if ( v23 )
                {
                  v34 = (__int64 *)&v34;
                  v35 = &v34;
                  v36 = v39;
                  v2 |= 1u;
                  v32 = v2;
                  v23[1].mNext = v23 + 1;
                  v23[2].mNext = v23 + 1;
                  v23->mNext = (UFG::allocator::free_link *)&UFG::OnlineFriend::`vftable;
                  v41 = v23 + 3;
                  v23[3].mNext = v23 + 3;
                  v23[4].mNext = v23 + 3;
                  LODWORD(v23[5].mNext) = 0;
                  HIDWORD(v23[5].mNext) &= 0xFF0FFFFF;
                  HIBYTE(v23[5].mNext) = 0;
                  HIDWORD(v23[5].mNext) &= 0xFFF00000;
                  v23[5].mNext = v36;
                  UFG::qString::qString((UFG::qString *)&v23[6], &text);
                }
                else
                {
                  v23 = 0i64;
                }
                mPrev = UFG::OnlineFriendManager::nFriends.mNode.mPrev;
                UFG::OnlineFriendManager::nFriends.mNode.mPrev->mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v23[1];
                v23[1].mNext = (UFG::allocator::free_link *)mPrev;
                v23[2].mNext = (UFG::allocator::free_link *)&UFG::OnlineFriendManager::nFriends;
                UFG::OnlineFriendManager::nFriends.mNode.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v23[1];
                if ( (v2 & 1) != 0 )
                {
                  v2 &= ~1u;
                  v32 = v2;
                  v25 = v34;
                  v26 = v35;
                  v34[1] = (__int64)v35;
                  *v26 = v25;
                  v34 = (__int64 *)&v34;
                  v35 = &v34;
                }
                UFG::qString::~qString(&text);
                ++v17;
              }
              while ( v17 < v14 );
              v1 = friends;
            }
            UFG::OnlineFriendManager::nState = State_Retrieved;
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
        v28 = UFG::qMalloc(0x58ui64, "OnlineFriendManager", 0i64);
        v39 = v28;
        if ( v28 )
          UFG::OnlineFriend::OnlineFriend((UFG::OnlineFriend *)v28, i);
        else
          v29 = 0i64;
        v30 = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)(v29 + 8);
        v31 = v1->mNode.mPrev;
        v31->mNext = v30;
        v30->mPrev = v31;
        v30->mNext = &v1->mNode;
        v1->mNode.mPrev = v30;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::OnlineFriendManager::nFriendsMutex);
      return (unsigned int)UFG::OnlineFriendManager::nState;
    }
  }
  return result;
}

