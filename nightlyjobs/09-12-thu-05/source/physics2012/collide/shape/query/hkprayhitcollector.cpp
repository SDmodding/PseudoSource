// File Line: 13
// RVA: 0xD318B0
__int64 __fastcall hkpRayHitCollector::shapeKeysFromCdBody(unsigned int *buf, int maxKeys, hkpCdBody *body)
{
  hkpCdBody *m_parent; // r10
  int v4; // r9d
  int v6; // r11d
  char *v7; // rax
  __int64 v8; // rdx
  unsigned int *v9; // r8
  __int64 v10; // rax
  __int64 v12; // [rsp+0h] [rbp-50h]
  char v13; // [rsp+8h] [rbp-48h] BYREF

  m_parent = body->m_parent;
  v4 = 0;
  v6 = 0;
  if ( m_parent )
  {
    v7 = &v13;
    do
    {
      *(_QWORD *)v7 = body;
      body = m_parent;
      m_parent = m_parent->m_parent;
      ++v6;
      v7 += 8;
    }
    while ( m_parent );
  }
  v8 = v6;
  if ( v6 > 0 )
  {
    v9 = buf;
    do
    {
      if ( v4 >= maxKeys - 1 )
        break;
      v10 = *(&v12 + v8--);
      ++v9;
      ++v4;
      *(v9 - 1) = *(_DWORD *)(v10 + 8);
    }
    while ( v8 > 0 );
  }
  buf[v4] = -1;
  return (unsigned int)(v4 + 1);
}

