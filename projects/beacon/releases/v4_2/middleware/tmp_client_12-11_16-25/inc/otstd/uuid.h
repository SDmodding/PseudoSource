// File Line: 178
// RVA: 0xEC140C
OSuite::ZString *__fastcall OSuite::ZUuid::ToString(OSuite::ZUuid *this, OSuite::ZString *result)
{
  OSuite::ZUuid *v2; // rbx
  OSuite::ZString *v3; // rdi
  __int64 v5; // [rsp+20h] [rbp-78h]
  __int64 v6; // [rsp+28h] [rbp-70h]
  __int64 v7; // [rsp+30h] [rbp-68h]
  __int64 v8; // [rsp+38h] [rbp-60h]
  OSuite::ZString resulta; // [rsp+40h] [rbp-58h]
  OSuite::ZStringBuilder v10; // [rsp+58h] [rbp-40h]

  v10.m_Chars.m_pList = 0i64;
  v2 = this;
  v3 = result;
  OSuite::ZStringBuilder::ZStringBuilder(&v10, 0x24ui64);
  LODWORD(v8) = (unsigned __int8)v2->m_anUuid[15] | (((unsigned __int8)v2->m_anUuid[14] | (((unsigned __int8)v2->m_anUuid[13] | ((unsigned __int8)v2->m_anUuid[12] << 8)) << 8)) << 8);
  LODWORD(v7) = (unsigned __int8)v2->m_anUuid[11] | ((unsigned __int8)v2->m_anUuid[10] << 8);
  LODWORD(v6) = (unsigned __int8)v2->m_anUuid[9] | ((unsigned __int8)v2->m_anUuid[8] << 8);
  LODWORD(v5) = (unsigned __int8)v2->m_anUuid[7] | ((unsigned __int8)v2->m_anUuid[6] << 8);
  OSuite::ZStringBuilder::AppendFormat(
    &v10,
    "%08x-%04x-%04x-%04x-%04x%08x",
    (unsigned __int8)v2->m_anUuid[3] | (((unsigned __int8)v2->m_anUuid[2] | (((unsigned __int8)v2->m_anUuid[1] | ((unsigned int)(unsigned __int8)v2->m_anUuid[0] << 8)) << 8)) << 8),
    (unsigned __int8)v2->m_anUuid[5] | ((unsigned int)(unsigned __int8)v2->m_anUuid[4] << 8),
    v5,
    v6,
    v7,
    v8);
  OSuite::ZStringBuilder::ToString(&v10, &resulta);
  OSuite::ZString::ZString(v3, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v10);
  return v3;
}

// File Line: 201
// RVA: 0xEC0D48
unsigned int __fastcall OSuite::ZUuid::ComputeHash(OSuite::ZUuid *this)
{
  OSuite::ZUuid *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax

  v1 = this;
  v2 = OSuite::FComputeHashBegin((_exception *)this);
  v3 = OSuite::FComputeHashAdd(v2, &v1->vfptr, 0x10ui64);
  return OSuite::FComputeHashEnd(v3);
}

