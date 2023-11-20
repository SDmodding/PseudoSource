// File Line: 13
// RVA: 0xD318B0
__int64 __fastcall hkpRayHitCollector::shapeKeysFromCdBody(unsigned int *buf, int maxKeys, hkpCdBody *body)
{
  hkpCdBody *v3; // r10
  int v4; // er9
  int v5; // edi
  int v6; // er11
  char *v7; // rax
  __int64 v8; // rdx
  unsigned int *v9; // r8
  __int64 v10; // rax
  __int64 v12; // [rsp+0h] [rbp-50h]
  char v13; // [rsp+8h] [rbp-48h]

  v3 = body->m_parent;
  v4 = 0;
  v5 = maxKeys;
  v6 = 0;
  if ( v3 )
  {
    v7 = &v13;
    do
    {
      *(_QWORD *)v7 = body;
      body = v3;
      v3 = v3->m_parent;
      ++v6;
      v7 += 8;
    }
    while ( v3 );
  }
  v8 = v6;
  if ( v6 > 0 )
  {
    v9 = buf;
    do
    {
      if ( v4 >= v5 - 1 )
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

