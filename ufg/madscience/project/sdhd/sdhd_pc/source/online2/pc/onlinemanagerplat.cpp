// File Line: 13
// RVA: 0x15B5720
__int64 UFG::OnlineManagerPlat::_dynamic_initializer_for__nOnlineId__()
{
  UFG::OnlineManagerPlat::nOnlineId.m_SteamId.m_steamid.m_unAll64Bits &= 0xFF0FFFFF00000000ui64;
  HIBYTE(UFG::OnlineManagerPlat::nOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&UFG::OnlineManagerPlat::nOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  return atexit(UFG::OnlineManagerPlat::_dynamic_atexit_destructor_for__nOnlineId__);
}

// File Line: 14
// RVA: 0x15B5710
__int64 UFG::OnlineManagerPlat::_dynamic_initializer_for__nOnlineHash__()
{
  return atexit(UFG::OnlineManagerPlat::_dynamic_atexit_destructor_for__nOnlineHash__);
}

// File Line: 15
// RVA: 0x15B5770
__int64 UFG::OnlineManagerPlat::_dynamic_initializer_for__nOnlineName__()
{
  UFG::qString::qString(&UFG::OnlineManagerPlat::nOnlineName);
  return atexit(UFG::OnlineManagerPlat::_dynamic_atexit_destructor_for__nOnlineName__);
}

// File Line: 23
// RVA: 0xA40A50
void __fastcall UFG::OnlineManager::Init(UFG::OnlineManager *this)
{
  if ( !this->m_bInitialized )
    this->m_bInitialized = 1;
}

// File Line: 32
// RVA: 0xA40C30
void __fastcall UFG::OnlineManager::Shutdown(UFG::OnlineManager *this)
{
  if ( this->m_bInitialized )
    this->m_bInitialized = 0;
}

// File Line: 41
// RVA: 0xA40DB0
void __fastcall UFG::OnlineManager::Update(UFG::OnlineManager *this, float realTimeDelta)
{
  JUMPOUT(this->m_bInitialized, 0, UFG::OnlineManager::UpdateObservers);
}

// File Line: 56
// RVA: 0xA40A60
_BOOL8 __fastcall UFG::OnlineManager::IsNetworkAvailable(UFG::OnlineManager *this)
{
  return UFG::OnlineManagerPlat::nSignedIn;
}

// File Line: 62
// RVA: 0xA40C40
void __fastcall UFG::OnlineManager::SignInNetwork(UFG::OnlineManager *this)
{
  UFG::OnlineManager *v1; // rsi
  __int64 v2; // rdx
  __int64 v3; // rcx
  __int64 v4; // rdi
  __int64 v5; // rdx
  __int64 v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rbx
  __int64 v11; // rax
  _QWORD *v12; // rax
  UFG::qString *v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // rax
  const char *v17; // rax
  bool *i; // rbx
  UFG::qString result; // [rsp+28h] [rbp-30h]
  UFG::qSymbol v20; // [rsp+68h] [rbp+10h]

  v1 = this;
  if ( !UFG::OnlineManagerPlat::nSignedIn && (unsigned __int8)SteamAPI_IsSteamRunning(this) )
  {
    v4 = SteamUserStats(v3, v2);
    v7 = SteamUser(v6, v5);
    v10 = v7;
    if ( v7 )
      LOBYTE(v7) = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 8i64))(v7);
    if ( v4 )
    {
      if ( v10 )
      {
        if ( (_BYTE)v7 )
        {
          UFG::OnlineManagerPlat::nSignedIn = 1;
          v11 = SteamUser(v9, v8);
          v12 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, UFG::qSymbol *))(*(_QWORD *)v11 + 16i64))(v11, &v20);
          result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
          result.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
          *(_QWORD *)&result.mMagic = *v12;
          UFG::OnlineManagerPlat::nOnlineId.m_SteamId.m_steamid.m_unAll64Bits = *(_QWORD *)&result.mMagic;
          result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
          result.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&result;
          v13 = UFG::OnlineId::ToString(&UFG::OnlineManagerPlat::nOnlineId, &result);
          UFG::OnlineManagerPlat::nOnlineHash.mUID = UFG::qSymbol::create_from_string(&v20, v13->mData)->mUID;
          UFG::qString::~qString(&result);
          v16 = SteamFriends(v15, v14);
          v17 = (const char *)(*(__int64 (__fastcall **)(__int64, CSteamID::SteamID_t))(*(_QWORD *)v16 + 56i64))(
                                v16,
                                UFG::OnlineManagerPlat::nOnlineId.m_SteamId.m_steamid);
          UFG::qString::Set(&UFG::OnlineManagerPlat::nOnlineName, v17);
          for ( i = (bool *)&v1->m_lObservers.mNode.mNext[-1].mNext;
                i != &v1->m_bInitialized;
                i = (bool *)(*((_QWORD *)i + 2) - 8i64) )
          {
            (*(void (__fastcall **)(bool *))(*(_QWORD *)i + 8i64))(i);
          }
        }
      }
    }
  }
}

// File Line: 85
// RVA: 0xA40A70
void __fastcall UFG::OnlineManager::RetreivePlayerDisplayImage(UFG::OnlineManager *this, UFG::OnlineId *onlineId)
{
  UFG::OnlineId *v2; // rsi
  UFG::OnlineManager *v3; // r14
  __int64 v4; // rdx
  __int64 v5; // rcx
  __int64 v6; // rax
  __int64 v7; // rcx
  unsigned int v8; // ebx
  __int64 v9; // rax
  signed int v10; // ebp
  UFG::allocator::free_link *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // rax
  UFG::qResourceData *v14; // rbx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v15; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v16; // rax
  Illusion::TextureLockInfo info; // [rsp+48h] [rbp-80h]
  char dest; // [rsp+60h] [rbp-68h]
  int height; // [rsp+E0h] [rbp+18h]
  int width; // [rsp+E8h] [rbp+20h]

  v2 = onlineId;
  v3 = this;
  if ( (unsigned __int8)SteamAPI_IsSteamRunning(this) )
  {
    v6 = SteamFriends(v5, v4);
    v8 = (*(__int64 (__fastcall **)(__int64, CSteamID::SteamID_t))(*(_QWORD *)v6 + 224i64))(v6, v2->m_SteamId.m_steamid);
    if ( v8 )
    {
      v9 = SteamUtils(v7);
      (*(void (__fastcall **)(__int64, _QWORD, int *, int *))(*(_QWORD *)v9 + 40i64))(v9, v8, &width, &height);
      if ( height )
      {
        if ( width )
        {
          v10 = 4 * width * width;
          v11 = UFG::qMalloc(v10, UFG::gGlobalNewName, 0i64);
          v13 = SteamUtils(v12);
          (*(void (__fastcall **)(__int64, _QWORD, UFG::allocator::free_link *, _QWORD))(*(_QWORD *)v13 + 48i64))(
            v13,
            v8,
            v11,
            (unsigned int)(4 * height * width));
          v14 = Illusion::CreateTexture("userIcon", width, height, 0, 0x440500u, 1, 0, 0);
          Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)v14, LOCK_MODIFY, &info, 0, 0);
          UFG::qMemCopy(info.mData, v11, v10);
          Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)v14);
          UFG::qSPrintf(&dest, 64, "img://%u", v14->mNode.mUID);
          UFG::qString::Set(&v3->mRetreivedDisplayImage, &dest);
          operator delete[](v11);
        }
      }
    }
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UI_HASH_DISPLAY_IMAGE_LOADED_23,
      0xFFFFFFFF);
  }
  v15 = v2->mPrev;
  v16 = v2->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v2->mPrev;
  v2->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v2->mPrev;
}

// File Line: 123
// RVA: 0xA409B0
UFG::OnlineId *__fastcall UFG::OnlineManager::GetOnlineId(UFG::OnlineManager *this, UFG::OnlineId *result)
{
  result->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result->mPrev;
  result->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result->mPrev;
  result->m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&result->m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(result->m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&result->m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  result->m_SteamId.m_steamid.m_unAll64Bits = UFG::OnlineManagerPlat::nOnlineId.m_SteamId.m_steamid.m_unAll64Bits;
  return result;
}

// File Line: 129
// RVA: 0xA40A00
__int64 __fastcall UFG::OnlineManager::GetOnlineIdStringHash32(UFG::OnlineManager *this)
{
  return UFG::OnlineManagerPlat::nOnlineHash.mUID;
}

// File Line: 135
// RVA: 0xA40A10
UFG::qString *__fastcall UFG::OnlineManager::GetOnlineName(UFG::OnlineManager *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qString::qString(result, &UFG::OnlineManagerPlat::nOnlineName);
  return v2;
}

