// File Line: 36
// RVA: 0x149B580
__int64 UFG::_dynamic_initializer_for__UI_HASH_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT", 0xFFFFFFFF);
  UI_HASH_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT = result;
  return result;
}

// File Line: 147
// RVA: 0x428780
void __fastcall UFG::OnlineId::OnlineId(UFG::OnlineId *this, const char *id)
{
  this->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&this->mPrev;
  this->m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  this->m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(id, 0i64);
}

// File Line: 166
// RVA: 0x431260
UFG::qString *__fastcall UFG::OnlineId::ToString(UFG::OnlineId *this, UFG::qString *result)
{
  UFG::qString *v2; // rdi
  UFG::OnlineId *v3; // rbx
  _QWORD v5[2]; // [rsp+20h] [rbp-88h]
  UFG::qString text; // [rsp+30h] [rbp-78h]
  char dest; // [rsp+60h] [rbp-48h]

  v2 = result;
  v3 = this;
  LODWORD(v5[0]) = 0;
  UFG::qMemSet(&dest, 0, 0x40u);
  UFG::qSPrintf(&dest, 64, "%u64", v3->m_SteamId.m_steamid.m_unAll64Bits, v5[0], -2i64);
  UFG::qString::qString(&text);
  UFG::qString::Set(&text, &dest);
  UFG::qString::qString(v2, &text);
  UFG::qString::~qString(&text);
  return v2;
}

