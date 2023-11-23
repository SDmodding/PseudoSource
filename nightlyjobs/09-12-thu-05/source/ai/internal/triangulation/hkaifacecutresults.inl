// File Line: 121
// RVA: 0x12E9740
void __fastcall hkaiFaceCutResults::writeFlags(
        hkaiFaceCutResults *this,
        unsigned int **dataPtr,
        hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *f,
        int numFlags)
{
  int v5; // r9d
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v7; // r11
  int v8; // eax
  __int64 v9; // r8
  unsigned int v10; // ecx
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v11; // rbx
  char m_storage; // al
  char v13; // al
  unsigned int v14; // [rsp+20h] [rbp+20h]

  v5 = numFlags & 3;
  v7 = f;
  v8 = numFlags / 4;
  if ( v8 > 0 )
  {
    v9 = (unsigned int)v8;
    do
    {
      v10 = *(_DWORD *)&v7->m_storage;
      v7 += 4;
      *(*dataPtr)++ = v10;
      --v9;
    }
    while ( v9 );
  }
  v11 = &f[4 * v8];
  if ( v5 > 0 )
  {
    if ( v5 <= 1 )
      m_storage = -1;
    else
      m_storage = v11[1].m_storage;
    BYTE1(v14) = m_storage;
    if ( v5 <= 2 )
      v13 = -1;
    else
      v13 = v11[2].m_storage;
    BYTE2(v14) = v13;
    HIBYTE(v14) = -1;
    LOBYTE(v14) = (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char>)v11->m_storage;
    *(*dataPtr)++ = v14;
  }
}

// File Line: 160
// RVA: 0x12E96B0
char *__fastcall hkaiFaceCutResults::init(hkaiFaceCutResults *this, int numPolys, int numEdges)
{
  int v4; // ebx
  _QWORD **Value; // rax
  char *result; // rax

  this->m_numPolys = numPolys;
  this->m_numVertices = 0;
  this->m_numEdges = numEdges;
  v4 = 16 * ((numEdges + 3) & 0xFFFFFFFC) + ((11 * numPolys + numEdges + 8 * numEdges + 15) & 0xFFFFFFF0);
  if ( v4 > 0 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    this->m_data = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                             Value[11],
                             (unsigned int)v4);
  }
  result = this->m_data;
  this->m_allocatedSize = v4;
  return result;
}

