// File Line: 121
// RVA: 0x12E9740
void __fastcall hkaiFaceCutResults::writeFlags(hkaiFaceCutResults *this, unsigned int **dataPtr, hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *f, int numFlags)
{
  int v4; // eax
  int v5; // er9
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v6; // rbx
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v7; // r11
  int v8; // eax
  __int64 v9; // r8
  unsigned int v10; // ecx
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v11; // rbx
  char v12; // al
  char v13; // al
  char v14; // al
  unsigned int v15; // [rsp+20h] [rbp+20h]

  v4 = numFlags;
  v5 = numFlags & 3;
  v6 = f;
  v7 = f;
  v8 = v4 / 4;
  if ( v8 > 0 )
  {
    v9 = (unsigned int)v8;
    do
    {
      v10 = *(_DWORD *)&v7->m_storage;
      v7 += 4;
      **dataPtr = v10;
      ++*dataPtr;
      --v9;
    }
    while ( v9 );
  }
  v11 = &v6[4 * v8];
  if ( v5 > 0 )
  {
    if ( v5 <= 1 )
      v12 = -1;
    else
      v12 = v11[1].m_storage;
    BYTE1(v15) = v12;
    if ( v5 <= 2 )
      v13 = -1;
    else
      v13 = v11[2].m_storage;
    BYTE2(v15) = v13;
    if ( v5 <= 3 )
      v14 = -1;
    else
      v14 = v11[3].m_storage;
    HIBYTE(v15) = v14;
    LOBYTE(v15) = (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char>)v11->m_storage;
    **dataPtr = v15;
    ++*dataPtr;
  }
}

// File Line: 160
// RVA: 0x12E96B0
char *__fastcall hkaiFaceCutResults::init(hkaiFaceCutResults *this, int numPolys, int numEdges)
{
  hkaiFaceCutResults *v3; // rdi
  signed int v4; // ebx
  char *result; // rax
  _QWORD **v6; // rax

  this->m_numPolys = numPolys;
  this->m_numVertices = 0;
  v3 = this;
  this->m_numEdges = numEdges;
  v4 = 16 * ((numEdges + 3) & 0xFFFFFFFC) + ((11 * numPolys + numEdges + 8 * numEdges + 15) & 0xFFFFFFF0);
  if ( v4 > 0x7FFFFFFF )
    return 0i64;
  if ( v4 > 0 )
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3->m_data = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v6[11] + 8i64))(v6[11], (unsigned int)v4);
  }
  result = v3->m_data;
  v3->m_allocatedSize = v4;
  return result;
}

