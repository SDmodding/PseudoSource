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
  int m_size; // eax
  __int64 v3; // r8
  hkxVertexDescription::ElementDecl *m_data; // r10
  hkxVertexDescription::ElementDecl *v5; // rax
  hkEnum<enum hkxVertexDescription::DataUsage,unsigned short> *p_m_usage; // rdx
  signed __int64 v7; // r10

  m_size = this->m_decls.m_size;
  if ( m_size == other->m_decls.m_size )
  {
    v3 = 0i64;
    if ( m_size <= 0 )
      return 1;
    m_data = other->m_decls.m_data;
    v5 = this->m_decls.m_data;
    p_m_usage = &other->m_decls.m_data->m_usage;
    v7 = (char *)m_data - (char *)this->m_decls.m_data;
    while ( v5->m_type.m_storage == p_m_usage[-1].m_storage
         && v5->m_usage.m_storage == p_m_usage->m_storage
         && v5->m_byteOffset == *(unsigned int *)((char *)&v5->m_byteOffset + v7)
         && v5->m_byteStride == *(_DWORD *)&p_m_usage[1].m_storage
         && v5->m_numElements == LOBYTE(p_m_usage[3].m_storage) )
    {
      ++v3;
      p_m_usage += 8;
      ++v5;
      if ( v3 >= this->m_decls.m_size )
        return 1;
    }
  }
  return 0;
}

