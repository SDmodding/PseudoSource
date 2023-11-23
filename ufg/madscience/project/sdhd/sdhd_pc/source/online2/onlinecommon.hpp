// File Line: 36
// RVA: 0x149B580
__int64 UFG::_dynamic_initializer_for__UI_HASH_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT", -1);
  UI_HASH_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT = result;
  return result;
}

// File Line: 147
// RVA: 0x428780
void __fastcall UFG::OnlineId::OnlineId(UFG::OnlineId *this, const char *id)
{
  this->mPrev = this;
  this->mNext = this;
  *(_DWORD *)&this->m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  this->m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(id, 0i64);
}

// File Line: 166
// RVA: 0x431260
UFG::qString *__fastcall UFG::OnlineId::ToString(UFG::OnlineId *this, UFG::qString *result)
{
  UFG::qString text; // [rsp+30h] [rbp-78h] BYREF
  char dest[72]; // [rsp+60h] [rbp-48h] BYREF

  UFG::qMemSet(dest, 0, 0x40u);
  UFG::qSPrintf(dest, 64, "%u64", this->m_SteamId.m_steamid.m_unAll64Bits);
  UFG::qString::qString(&text);
  UFG::qString::Set(&text, dest);
  UFG::qString::qString(result, &text);
  UFG::qString::~qString(&text);
  return result;
}

