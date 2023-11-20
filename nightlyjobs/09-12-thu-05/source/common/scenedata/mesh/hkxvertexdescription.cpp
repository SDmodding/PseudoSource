// File Line: 12
// RVA: 0xE370A0
void __fastcall hkxVertexDescription::hkxVertexDescription(hkxVertexDescription *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 17
// RVA: 0xE370B0
char __fastcall hkxVertexDescription::operator==(hkxVertexDescription *this, hkxVertexDescription *other)
{
  int v2; // eax
  signed __int64 v3; // r8
  hkxVertexDescription::ElementDecl *v4; // r10
  hkxVertexDescription::ElementDecl *v5; // rax
  hkEnum<enum hkxVertexDescription::DataUsage,unsigned short> *v6; // rdx
  unsigned __int64 v7; // r10

  v2 = this->m_decls.m_size;
  if ( v2 == other->m_decls.m_size )
  {
    v3 = 0i64;
    if ( v2 <= 0 )
      return 1;
    v4 = other->m_decls.m_data;
    v5 = this->m_decls.m_data;
    v6 = &other->m_decls.m_data->m_usage;
    v7 = (char *)v4 - (char *)this->m_decls.m_data;
    while ( v5->m_type.m_storage == v6[-1].m_storage
         && v5->m_usage.m_storage == v6->m_storage
         && v5->m_byteOffset == *(unsigned int *)((char *)&v5->m_byteOffset + v7)
         && v5->m_byteStride == *(_DWORD *)&v6[1].m_storage
         && v5->m_numElements == LOBYTE(v6[3].m_storage) )
    {
      ++v3;
      v6 += 8;
      ++v5;
      if ( v3 >= this->m_decls.m_size )
        return 1;
    }
  }
  return 0;
}

