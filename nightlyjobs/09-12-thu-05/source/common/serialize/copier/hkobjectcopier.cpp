// File Line: 30
// RVA: 0xE6AC70
bool __fastcall `anonymous namespace'::inRange(int num, int lo, int hi)
{
  return num >= lo && num < hi;
}

// File Line: 35
// RVA: 0xE6B2F0
__int64 __fastcall `anonymous namespace'::min2<int>(int a, int b)
{
  if ( a < b )
    b = a;
  return (unsigned int)b;
}

// File Line: 43
// RVA: 0xE68B60
void __fastcall hkObjectCopier::hkObjectCopier(hkObjectCopier *this, hkStructureLayout *layoutIn, hkStructureLayout *layoutOut, hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  hkStructureLayout v4; // eax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkObjectCopier::`vftable';
  this->m_layoutIn = *layoutIn;
  v4 = *layoutOut;
  this->m_flags = flags;
  this->m_layoutOut = v4;
  this->m_byteSwap.m_bool = this->m_layoutIn.m_rules.m_littleEndian != this->m_layoutOut.m_rules.m_littleEndian;
}

// File Line: 49
// RVA: 0xE68BA0
void __fastcall hkObjectCopier::~hkObjectCopier(hkObjectCopier *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 74
// RVA: 0xE6AC90
void __fastcall objectCopierPadUp(hkStreamWriter *w, int pad)
{
  int v2; // ebx
  hkStreamWriter *v3; // rsi
  int v4; // eax
  int v5; // edx
  int v6; // ebp
  hkLifoAllocator *v7; // rax
  char *v8; // rcx
  int v9; // edx
  char *v10; // rdi
  char *v11; // rax
  signed int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // eax
  char *v16; // rdi
  unsigned __int64 v17; // rdx
  char *v18; // rsi
  signed int v19; // edi
  hkLifoAllocator *v20; // rax
  int v21; // er8
  char *array; // [rsp+30h] [rbp-38h]
  int v23; // [rsp+38h] [rbp-30h]
  int v24; // [rsp+3Ch] [rbp-2Ch]
  void *p; // [rsp+40h] [rbp-28h]
  int v26; // [rsp+48h] [rbp-20h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v2 = pad;
  v3 = w;
  v4 = ((__int64 (*)(void))w->vfptr[4].__vecDelDtor)();
  v24 = 2147483648;
  v5 = 0;
  array = 0i64;
  v26 = v2;
  v6 = v4;
  v23 = 0;
  if ( v2 )
  {
    v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (char *)v7->m_cur;
    v9 = (v2 + 127) & 0xFFFFFF80;
    v10 = &v8[v9];
    if ( v9 > v7->m_slabSize || v10 > v7->m_end )
    {
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
      v5 = v23;
      v8 = v11;
    }
    else
    {
      v7->m_cur = v10;
      v5 = v23;
    }
  }
  else
  {
    v8 = 0i64;
  }
  array = v8;
  p = v8;
  v24 = v2 | 0x80000000;
  v12 = (v2 | 0x80000000) & 0x3FFFFFFF;
  if ( v12 < v2 )
  {
    v13 = 2 * v12;
    v14 = v2;
    if ( v2 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v14, 1);
    v5 = v23;
    v8 = array;
  }
  v15 = v2 - v5;
  v16 = &v8[v5];
  v17 = v2 - v5;
  if ( v15 > 0 )
  {
    memset(v16, 0, v17);
    v8 = array;
  }
  v23 = v2;
  if ( v6 & (v2 - 1) )
  {
    ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v3->vfptr[2].__vecDelDtor)(
      v3,
      v8,
      v2 - (v6 & (unsigned int)(v2 - 1)));
    v2 = v23;
    v8 = array;
  }
  v18 = (char *)p;
  if ( p == v8 )
    v2 = 0;
  v19 = (v26 + 127) & 0xFFFFFF80;
  v23 = v2;
  v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (v19 + 15) & 0xFFFFFFF0;
  if ( v19 > v20->m_slabSize || &v18[v21] != v20->m_cur || v20->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v20, v18, v21);
  else
    v20->m_cur = v18;
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v24 & 0x3FFFFFFF);
}

// File Line: 86
// RVA: 0xE6AE50
__int64 __fastcall objectCopier_calcCArraySize(hkClassMember *member)
{
  hkClassMember *v1; // rbx
  __int64 result; // rax

  v1 = member;
  if ( (unsigned int)hkClassMember::getCstyleArraySize(member) )
    result = hkClassMember::getCstyleArraySize(v1);
  else
    result = 1i64;
  return result;
}

// File Line: 91
// RVA: 0xE6AE80
__int64 __fastcall writeZeros(hkOArchive *oa, int numZeros, hkLocalArray<char> *zeroArray)
{
  hkLocalArray<char> *v3; // rbx
  unsigned int v4; // esi
  int v5; // eax
  hkOArchive *v6; // rbp
  int v7; // eax
  int v8; // er9
  signed __int64 v9; // rcx
  char *v10; // rdx
  hkResult result; // [rsp+48h] [rbp+10h]

  v3 = zeroArray;
  v4 = numZeros;
  v5 = zeroArray->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = oa;
  if ( v5 < numZeros )
  {
    v7 = 2 * v5;
    v8 = numZeros;
    if ( numZeros < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, zeroArray, v8, 1);
  }
  v9 = (signed int)(v4 - v3->m_size);
  if ( v9 > 0 )
    memset(&v3->m_data[v3->m_size], 0, v9);
  v10 = v3->m_data;
  v3->m_size = v4;
  return hkOArchive::writeRaw(v6, v10, v4);
}

// File Line: 100
// RVA: 0xE68FC0
void __fastcall hkObjectCopier::writeZero(hkObjectCopier *this, hkOArchive *oa, hkClassMember *memberOut, hkLocalArray<char> *zeroArray)
{
  hkObjectCopier *v4; // rsi
  int v5; // ecx
  unsigned int v6; // ebx
  hkLocalArray<char> *v7; // r14
  hkClassMember *v8; // rdi
  hkOArchive *v9; // rbp
  hkClass *v10; // rax
  int v11; // ebx
  char buf; // [rsp+20h] [rbp-228h]
  __int64 v13; // [rsp+21h] [rbp-227h]
  __int16 v14; // [rsp+29h] [rbp-21Fh]
  char v15; // [rsp+2Bh] [rbp-21Dh]
  char description; // [rsp+40h] [rbp-208h]

  v4 = this;
  v5 = (unsigned __int8)memberOut->m_type.m_storage;
  v6 = 0;
  v7 = zeroArray;
  v8 = memberOut;
  v9 = oa;
  switch ( v5 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 24:
    case 31:
    case 32:
      v6 = hkClassMember::getSizeInBytes(memberOut);
      break;
    case 20:
    case 21:
    case 30:
    case 33:
      v6 = (unsigned __int8)v4->m_layoutOut.m_rules.m_bytesInPointer * objectCopier_calcCArraySize(memberOut);
      break;
    case 22:
    case 23:
    case 26:
    case 27:
      if ( (_BYTE)v5 == 27 )
        v6 = (unsigned __int8)v4->m_layoutOut.m_rules.m_bytesInPointer;
      v6 += (unsigned __int8)v4->m_layoutOut.m_rules.m_bytesInPointer + 4;
      if ( (_BYTE)v5 != 22 )
        break;
      buf = 0;
      v13 = 0i64;
      v14 = 0;
      v15 = 0;
      hkOArchive::writeRaw(oa, &buf, v6);
      hkOArchive::write32u(v9, 0x80000000);
      return;
    case 25:
      v10 = hkClassMember::getStructClass(memberOut);
      v11 = hkClass::getObjectSize(v10);
      v6 = objectCopier_calcCArraySize(v8) * v11;
      break;
    case 28:
      v6 = 2 * (unsigned __int8)v4->m_layoutOut.m_rules.m_bytesInPointer * objectCopier_calcCArraySize(memberOut);
      break;
    default:
      hkErrStream::hkErrStream((hkErrStream *)&buf, &description, 512);
      hkOstream::operator<<((hkOstream *)&buf, "Unknown class member type found!");
      if ( (unsigned int)hkError::messageError(1593107876, &description, "Copier\\hkObjectCopier.cpp", 178) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&buf);
      break;
  }
  writeZeros(v9, v6, v7);
}

// File Line: 188
// RVA: 0xE6AF20
void __fastcall writeUlongArray(hkOArchive *oa, int elemsize, int nelem, const void *startAddress)
{
  _DWORD *v4; // rdi
  __int64 v5; // rsi
  int v6; // er15
  hkOArchive *v7; // r14
  hkLifoAllocator *v8; // rax
  _DWORD *v9; // rbx
  int v10; // ebp
  char *v11; // rcx
  __int64 v12; // rdx
  int v13; // ecx
  hkLifoAllocator *v14; // rax
  int v15; // er8

  v4 = startAddress;
  v5 = nelem;
  v6 = elemsize;
  v7 = oa;
  if ( elemsize == 8 )
  {
    hkOArchive::writeArrayGeneric(oa, startAddress, 8, v5);
  }
  else
  {
    v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = v8->m_cur;
    v10 = (4 * v5 + 127) & 0xFFFFFF80;
    v11 = (char *)v9 + v10;
    if ( v10 > v8->m_slabSize || v11 > v8->m_end )
      v9 = hkLifoAllocator::allocateFromNewSlab(v8, v10);
    else
      v8->m_cur = v11;
    v12 = 0i64;
    if ( (signed int)v5 > 0 )
    {
      do
      {
        v13 = v4[2 * v12++];
        v9[v12 - 1] = v13;
      }
      while ( v12 < v5 );
    }
    hkOArchive::writeArrayGeneric(v7, v9, v6, v5);
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (v10 + 15) & 0xFFFFFFF0;
    if ( v10 > v14->m_slabSize || (char *)v9 + v15 != v14->m_cur || v14->m_firstNonLifoEnd == v9 )
      hkLifoAllocator::slowBlockFree(v14, v9, v15);
    else
      v14->m_cur = v9;
  }
}

// File Line: 214
// RVA: 0xE6B030
void __fastcall writePodArray(hkOArchive *oa, hkClassMember::Type mtype, int elemsize, int nelem, const void *startAddress)
{
  unsigned __int64 v5; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  switch ( mtype )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 32:
      goto $LN6_229;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
      v5 = elemsize;
      elemsize = 4;
      nelem *= (unsigned int)(v5 >> 2);
$LN6_229:
      hkOArchive::writeArrayGeneric(oa, startAddress, elemsize, nelem);
      break;
    default:
      hkErrStream::hkErrStream(&v6, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v6.vfptr, "Unknown class member found during write of plain data array.");
      if ( (unsigned int)hkError::messageError(1954422275, &buf, "Copier\\hkObjectCopier.cpp", 259) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v6.vfptr);
      break;
  }
}

// File Line: 265
// RVA: 0xE6B120
hkResult *__fastcall applyDefaultsFor(hkResult *result, hkClass *klass, hkClassMember *mem, int memberIndex, hkStreamWriter *writer)
{
  hkClassMember *v5; // rbx
  hkResult *v6; // rsi
  hkClass *v7; // rdi
  unsigned int v8; // eax
  __int64 v9; // rbp
  int v10; // ebx
  hkStreamWriter *v11; // rbp
  hkClassMember *v12; // rax
  hkResult resulta; // [rsp+50h] [rbp+8h]
  __int64 v15; // [rsp+60h] [rbp+18h]

  v5 = mem;
  v6 = result;
  hkClass::getDefault(klass, result, memberIndex, writer);
  if ( v5->m_type.m_storage != 25 )
    return v6;
  v7 = hkClassMember::getClass(v5);
  if ( !v7 )
    return v6;
  v8 = objectCopier_calcCArraySize(v5);
  if ( (signed int)v8 <= 0 )
    return v6;
  v9 = v8;
  v15 = v8;
  do
  {
    v10 = 0;
    if ( (signed int)hkClass::getNumMembers(v7) > 0 )
    {
      v11 = writer;
      do
      {
        v12 = hkClass::getMember(v7, v10);
        if ( applyDefaultsFor(&resulta, v7, v12, v10, v11)->m_enum == HK_SUCCESS )
          v6->m_enum = 0;
        ++v10;
      }
      while ( v10 < (signed int)hkClass::getNumMembers(v7) );
      v9 = v15;
    }
    v15 = --v9;
  }
  while ( v9 );
  return v6;
}

// File Line: 290
// RVA: 0xE68F90
_BOOL8 __fastcall hkObjectCopier::areMembersCompatible(hkObjectCopier *this, hkClassMember *src, hkClassMember *dst)
{
  char v3; // cl

  v3 = src->m_type.m_storage;
  return v3 == dst->m_type.m_storage && (src->m_subtype.m_storage == dst->m_subtype.m_storage || v3 == 24);
}

// File Line: 313
// RVA: 0xE69190
void __fastcall hkObjectCopier::saveBody(hkObjectCopier *this, const void *dataIn, hkClass *klassIn, hkOArchive *dataOut, hkClass *klassOut, hkLocalArray<char> *zeroArray)
{
  hkOArchive *v6; // rsi
  hkStreamWriter *v7; // rax
  int v8; // eax
  hkClass *v9; // rbx
  int v10; // edi
  hkClassMember *v11; // rdi
  hkStreamWriter *v12; // rax
  int v13; // ebx
  int v14; // eax
  unsigned int v15; // eax
  hkStreamWriter *v16; // rax
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  hkClassEnum *v20; // rbx
  __int16 v21; // ax
  hkStreamWriter *v22; // rax
  unsigned int v23; // edi
  hkStreamWriter *v24; // rax
  __int16 v25; // ax
  __int16 v26; // bx
  hkStreamWriter *v27; // rax
  hkStreamWriter *v28; // rax
  unsigned __int16 v29; // ax
  unsigned __int8 v30; // dl
  signed __int64 v31; // r8
  hkClass *v32; // rdi
  hkClassMember *v33; // rax
  signed int i; // ebx
  int v35; // eax
  hkStreamWriter *v36; // rax
  hkClassMember *v37; // rax
  int v38; // edx
  char *v39; // rbx
  int v40; // edi
  int v41; // esi
  int v42; // ebx
  int v43; // er9
  int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // eax
  int v48; // ebx
  int v49; // eax
  __int64 v50; // rdi
  __int64 v51; // rbx
  char *v52; // rax
  int v53; // eax
  int v54; // eax
  __int64 v55; // rbx
  int v56; // er8
  int v57; // ebx
  const char *v58; // rdi
  const char *v59; // rbx
  hkOstream *v60; // rax
  hkOstream *v61; // rax
  hkOstream *v62; // rax
  hkOstream *v63; // rax
  int v64; // er8
  hkStreamWriter *v65; // rax
  int v66; // eax
  __int64 v67; // rbx
  hkClassMember *v68; // rbx
  int v69; // edx
  hkClassMember **v70; // r8
  hkStreamWriter *v71; // rax
  __int64 v72; // rax
  hkClassMember *v73; // rax
  hkClassMember *v74; // rbx
  hkClassEnum *v75; // rax
  int v76; // ebx
  int v77; // eax
  int v78; // eax
  int v79; // ebx
  hkClass *v80; // rdi
  int v81; // eax
  int v82; // ebx
  int v83; // eax
  int v84; // eax
  __int64 v85; // rbx
  int v86; // ebx
  int v87; // eax
  hkClassEnum *v88; // rax
  hkClassMember *v89; // rdi
  int v90; // eax
  hkClassMember *v91; // rcx
  char *v92; // rbx
  int v93; // eax
  int v94; // edi
  int v95; // esi
  __int64 v96; // rbx
  int v97; // edx
  __int16 v98; // dx
  char v99; // dl
  bool v100; // zf
  hkStreamWriter *v101; // rax
  hkClassMember::Type v102; // edi
  int v103; // ebx
  int v104; // eax
  int v105; // [rsp+30h] [rbp-D0h]
  int val; // [rsp+34h] [rbp-CCh]
  void *startAddress; // [rsp+38h] [rbp-C8h]
  hkClassMember *member; // [rsp+40h] [rbp-C0h]
  hkClassMember *ptr; // [rsp+48h] [rbp-B8h]
  int memberIndex; // [rsp+50h] [rbp-B0h]
  int v111; // [rsp+54h] [rbp-ACh]
  int bitsOver; // [rsp+58h] [rbp-A8h]
  hkClassEnum *v113; // [rsp+60h] [rbp-A0h]
  char *array; // [rsp+68h] [rbp-98h]
  int v115; // [rsp+70h] [rbp-90h]
  int v116; // [rsp+74h] [rbp-8Ch]
  hkArray<char const *,hkContainerHeapAllocator> bitsOut; // [rsp+78h] [rbp-88h]
  hkClassMember *v118; // [rsp+88h] [rbp-78h]
  hkClassMember *v119; // [rsp+90h] [rbp-70h]
  int v120; // [rsp+98h] [rbp-68h]
  hkResult v121; // [rsp+9Ch] [rbp-64h]
  int v122; // [rsp+A0h] [rbp-60h]
  hkResult v123; // [rsp+A4h] [rbp-5Ch]
  __int64 v124; // [rsp+A8h] [rbp-58h]
  hkResult v125; // [rsp+B0h] [rbp-50h]
  hkResult v126; // [rsp+B4h] [rbp-4Ch]
  hkResult v127; // [rsp+B8h] [rbp-48h]
  __int64 buf; // [rsp+C0h] [rbp-40h]
  hkResult v129; // [rsp+C8h] [rbp-38h]
  hkClassEnum *v130; // [rsp+D0h] [rbp-30h]
  char *name; // [rsp+D8h] [rbp-28h]
  hkErrStream v132; // [rsp+E0h] [rbp-20h]
  __int64 v133; // [rsp+100h] [rbp+0h]
  hkResult result; // [rsp+108h] [rbp+8h]
  __int64 v135; // [rsp+110h] [rbp+10h]
  __int64 v136; // [rsp+118h] [rbp+18h]
  char description; // [rsp+120h] [rbp+20h]
  hkObjectCopier *v138; // [rsp+350h] [rbp+250h]
  char *v139; // [rsp+358h] [rbp+258h]
  hkClass *v140; // [rsp+360h] [rbp+260h]
  hkOArchive *oa; // [rsp+368h] [rbp+268h]

  oa = dataOut;
  v140 = klassIn;
  v139 = (char *)dataIn;
  v138 = this;
  v6 = dataOut;
  v7 = hkOArchive::getStreamWriter(dataOut);
  v8 = ((__int64 (__fastcall *)(hkStreamWriter *))v7->vfptr[4].__vecDelDtor)(v7);
  v9 = klassOut;
  v116 = 2147483648;
  v111 = v8;
  array = 0i64;
  v115 = 0;
  v10 = 0;
  memberIndex = 0;
  v122 = hkClass::getNumMembers(klassOut);
  if ( v122 > 0 )
  {
    while ( 1 )
    {
      v11 = hkClass::getMember(v9, v10);
      v118 = v11;
      v12 = hkOArchive::getStreamWriter(v6);
      v13 = v11->m_offset;
      v14 = ((__int64 (__fastcall *)(hkStreamWriter *))v12->vfptr[4].__vecDelDtor)(v12);
      writeZeros(v6, v13 + v111 - v14, zeroArray);
      if ( !(v11->m_flags.m_storage & 0x400) )
        goto LABEL_21;
      v15 = v138->m_flags.m_storage;
      if ( !(v15 & 2) )
        break;
      hkObjectCopier::writeZero(v138, v6, v11, zeroArray);
$LN357_0:
      v9 = klassOut;
LABEL_6:
      v10 = memberIndex + 1;
      memberIndex = v10;
      if ( v10 >= v122 )
        goto LABEL_7;
    }
    if ( v15 & 1 )
    {
      v36 = hkOArchive::getStreamWriter(v6);
      v9 = klassOut;
      applyDefaultsFor(&result, klassOut, v11, memberIndex, v36);
      goto LABEL_6;
    }
LABEL_21:
    if ( v140 == klassOut )
      v37 = v11;
    else
      v37 = hkClass::getMemberByName(v140, v11->m_name);
    member = v37;
    if ( !v37
      || !((unsigned int (__fastcall *)(hkObjectCopier *, hkClassMember *, hkClassMember *))v138->vfptr[2].__vecDelDtor)(
            v138,
            v37,
            v11) )
    {
      v101 = hkOArchive::getStreamWriter(v6);
      v9 = klassOut;
      applyDefaultsFor(&v121, klassOut, v11, memberIndex, v101);
      goto LABEL_6;
    }
    v38 = (unsigned __int8)v11->m_type.m_storage;
    v39 = &v139[member->m_offset];
    startAddress = &v139[member->m_offset];
    switch ( v38 )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 32:
        v40 = objectCopier_calcCArraySize(member);
        v41 = objectCopier_calcCArraySize(v118);
        v42 = hkClassMember::getSizeInBytes(v118);
        v43 = `anonymous namespace'::min2<int>(v40, v41);
        v44 = v42 / v41;
        v6 = oa;
        writePodArray(oa, (hkClassMember::Type)(unsigned __int8)v118->m_type.m_storage, v44, v43, startAddress);
        break;
      case 19:
        goto $LN357_0;
      case 20:
      case 21:
      case 29:
      case 33:
        v54 = objectCopier_calcCArraySize(v11);
        buf = 0i64;
        if ( v54 > 0 )
        {
          v55 = (unsigned int)v54;
          do
          {
            hkOArchive::writeRaw(v6, &buf, (unsigned __int8)v138->m_layoutOut.m_rules.m_bytesInPointer);
            --v55;
          }
          while ( v55 );
        }
        break;
      case 22:
      case 26:
      case 27:
        if ( (_BYTE)v38 == 27 )
        {
          v56 = (unsigned __int8)v138->m_layoutOut.m_rules.m_bytesInPointer;
          ptr = 0i64;
          hkOArchive::writeArrayGeneric(v6, &ptr, v56, 1);
          if ( *(_QWORD *)v39 )
          {
            v57 = *((_DWORD *)v39 + 4);
          }
          else
          {
            hkErrStream::hkErrStream(&v132, &description, 512);
            v58 = member->m_name;
            v59 = hkClass::getName(v140);
            v60 = hkOstream::operator<<((hkOstream *)&v132.vfptr, "Can't copy homogeneous array. No hkClass for ");
            v61 = hkOstream::operator<<(v60, v59);
            v62 = hkOstream::operator<<(v61, "::");
            v63 = hkOstream::operator<<(v62, v58);
            hkOstream::operator<<(v63, ".");
            hkError::messageWarning(-1413850539, &description, "Copier\\hkObjectCopier.cpp", 462);
            hkOstream::~hkOstream((hkOstream *)&v132.vfptr);
            v11 = v118;
            v57 = 0;
          }
        }
        else if ( v11->m_subtype.m_storage )
        {
          v57 = *((_DWORD *)v39 + 2);
        }
        else
        {
          v57 = 0;
        }
        v64 = (unsigned __int8)v138->m_layoutOut.m_rules.m_bytesInPointer;
        v124 = 0i64;
        hkOArchive::writeArrayGeneric(v6, &v124, v64, 1);
        hkOArchive::write32(v6, v57);
        if ( v11->m_type.m_storage == 22 )
          hkOArchive::write32(v6, v57 | 0x80000000);
        break;
      case 24:
        if ( member->m_enum )
        {
          if ( v11->m_enum )
          {
            v48 = objectCopier_calcCArraySize(member);
            v49 = objectCopier_calcCArraySize(v11);
            v105 = `anonymous namespace'::min2<int>(v48, v49);
            ptr = (hkClassMember *)hkClassMember::getEnumClass(member);
            v113 = hkClassMember::getEnumClass(v11);
            v50 = (signed int)hkClassMember::getSizeInBytes(member) / v48;
            if ( v105 > 0 )
            {
              v51 = (unsigned int)v105;
              v52 = (char *)startAddress;
              do
              {
                v53 = hkClassMember::getEnumValue(member, v52);
                val = 0;
                if ( hkClassEnum::getNameOfValue((hkClassEnum *)ptr, &v127, v53, (const char **)&name)->m_enum == HK_SUCCESS )
                  hkClassEnum::getValueOfName(v113, &v129, name, &val);
                switch ( (_DWORD)v50 )
                {
                  case 1:
                    hkOArchive::write8(v6, val);
                    break;
                  case 2:
                    hkOArchive::write16(v6, val);
                    break;
                  case 4:
                    hkOArchive::write32(v6, val);
                    break;
                }
                v52 = (char *)startAddress + v50;
                startAddress = (char *)startAddress + v50;
                --v51;
              }
              while ( v51 );
            }
          }
        }
        break;
      case 25:
        v73 = (hkClassMember *)hkClassMember::getClass(member);
        v74 = v73;
        ptr = v73;
        v75 = (hkClassEnum *)hkClassMember::getClass(v11);
        v113 = v75;
        if ( v74 )
        {
          if ( v75 )
          {
            v76 = objectCopier_calcCArraySize(v11);
            v77 = objectCopier_calcCArraySize(member);
            v78 = `anonymous namespace'::min2<int>(v77, v76);
            v79 = 0;
            v105 = v78;
            if ( v78 > 0 )
            {
              v80 = (hkClass *)ptr;
              do
              {
                v81 = hkClass::getObjectSize(v80);
                hkObjectCopier::saveBody(v138, (char *)startAddress + v79++ * v81, v80, v6, (hkClass *)v113, zeroArray);
              }
              while ( v79 < v105 );
            }
          }
        }
        break;
      case 28:
        v135 = 0i64;
        v136 = 0i64;
        v82 = objectCopier_calcCArraySize(v11);
        v83 = objectCopier_calcCArraySize(member);
        v84 = `anonymous namespace'::min2<int>(v83, v82);
        if ( v84 > 0 )
        {
          v85 = (unsigned int)v84;
          do
          {
            hkOArchive::writeArrayGeneric(v6, &v135, (unsigned __int8)v138->m_layoutOut.m_rules.m_bytesInPointer, 2);
            --v85;
          }
          while ( v85 );
        }
        break;
      case 30:
        v45 = objectCopier_calcCArraySize(member);
        v46 = objectCopier_calcCArraySize(v11);
        v47 = `anonymous namespace'::min2<int>(v45, v46);
        writeUlongArray(v6, (unsigned __int8)v138->m_layoutOut.m_rules.m_bytesInPointer, v47, startAddress);
        break;
      case 31:
        if ( member->m_enum )
        {
          if ( v11->m_enum )
          {
            v86 = objectCopier_calcCArraySize(member);
            v87 = objectCopier_calcCArraySize(v11);
            v105 = `anonymous namespace'::min2<int>(v86, v87);
            v130 = hkClassMember::getEnumClass(member);
            v88 = hkClassMember::getEnumClass(v11);
            v89 = member;
            v113 = v88;
            v90 = hkClassMember::getSizeInBytes(member);
            v91 = (hkClassMember *)(v90 / v86);
            LODWORD(v118) = v90 / v86;
            if ( v105 > 0 )
            {
              v92 = (char *)startAddress;
              v119 = v91;
              ptr = (hkClassMember *)(unsigned int)v105;
              do
              {
                v93 = hkClassMember::getEnumValue(v89, v92);
                v94 = 0;
                bitsOut.m_data = 0i64;
                bitsOut.m_size = 0;
                bitsOut.m_capacityAndFlags = 2147483648;
                bitsOver = 0;
                hkClassEnum::decomposeFlags(v130, &v126, v93, &bitsOut, &bitsOver);
                v95 = 0;
                if ( bitsOut.m_size > 0 )
                {
                  v96 = 0i64;
                  do
                  {
                    if ( hkClassEnum::getValueOfName(v113, &v125, bitsOut.m_data[v96], &v120)->m_enum )
                      bitsOver |= v120;
                    else
                      v95 |= v120;
                    ++v94;
                    ++v96;
                  }
                  while ( v94 < bitsOut.m_size );
                  v92 = (char *)startAddress;
                }
                if ( bitsOver )
                {
                  v105 = 0;
                  hkClassEnum::decomposeFlags(v113, &v123, bitsOver, &bitsOut, &v105);
                  v95 |= v105;
                }
                switch ( (_DWORD)v118 )
                {
                  case 1:
                    v99 = v95;
                    v6 = oa;
                    hkOArchive::write8(oa, v99);
                    break;
                  case 2:
                    v98 = v95;
                    v6 = oa;
                    hkOArchive::write16(oa, v98);
                    break;
                  case 4:
                    v97 = v95;
                    v6 = oa;
                    hkOArchive::write32(oa, v97);
                    break;
                  default:
                    v6 = oa;
                    break;
                }
                v92 = &v92[(_QWORD)v119];
                bitsOut.m_size = 0;
                startAddress = v92;
                if ( bitsOut.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    bitsOut.m_data,
                    8 * bitsOut.m_capacityAndFlags);
                v100 = ptr == (hkClassMember *)1;
                ptr = (hkClassMember *)((char *)ptr - 1);
                bitsOut.m_data = 0i64;
                v89 = member;
                bitsOut.m_capacityAndFlags = 2147483648;
              }
              while ( !v100 );
            }
          }
        }
        break;
      case 34:
        v65 = hkOArchive::getStreamWriter(v6);
        v66 = ((__int64 (__fastcall *)(hkStreamWriter *))v65->vfptr[4].__vecDelDtor)(v65);
        v67 = *((unsigned __int16 *)v39 + 1);
        LODWORD(v132.m_writer.m_pntr) = v66 - v111;
        v68 = (hkClassMember *)((char *)startAddress + v67);
        LOWORD(v133) = *(_WORD *)startAddress;
        hkOArchive::write16u(v6, 0);
        hkOArchive::write16u(v6, 0);
        v69 = v115;
        if ( v115 == (v116 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 40);
          v69 = v115;
        }
        v70 = (hkClassMember **)&array[40 * v69];
        if ( v70 )
        {
          *v70 = member;
          v71 = v132.m_writer.m_pntr;
          v70[1] = v11;
          v70[2] = (hkClassMember *)v71;
          v72 = v133;
          v70[3] = v68;
          v70[4] = (hkClassMember *)v72;
          v69 = v115;
        }
        v115 = v69 + 1;
        break;
      default:
        hkErrStream::hkErrStream(&v132, &description, 512);
        hkOstream::operator<<((hkOstream *)&v132.vfptr, "Unknown class member found during write of data.");
        if ( (unsigned int)hkError::messageError(1679703555, &description, "Copier\\hkObjectCopier.cpp", 585) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&v132.vfptr);
        break;
    }
    goto $LN357_0;
  }
LABEL_7:
  v16 = hkOArchive::getStreamWriter(v6);
  v17 = ((__int64 (__fastcall *)(hkStreamWriter *))v16->vfptr[4].__vecDelDtor)(v16);
  v18 = v111 - v17;
  v19 = hkClass::getObjectSize(klassOut);
  writeZeros(v6, v18 + v19, zeroArray);
  v105 = 0;
  if ( v115 > 0 )
  {
    v20 = 0i64;
    v113 = 0i64;
    while ( 1 )
    {
      v119 = *(hkClassMember **)&array[(_QWORD)v20];
      ptr = *(hkClassMember **)&array[(_QWORD)v20 + 8];
      v21 = *(_WORD *)&array[(_QWORD)v20 + 32];
      startAddress = *(void **)&array[(_QWORD)v20 + 24];
      LOWORD(val) = v21;
      v22 = hkOArchive::getStreamWriter(v6);
      objectCopierPadUp(v22, 16);
      v23 = *(_DWORD *)&array[(_QWORD)v20 + 16];
      v24 = hkOArchive::getStreamWriter(v6);
      v25 = ((__int64 (__fastcall *)(hkStreamWriter *))v24->vfptr[4].__vecDelDtor)(v24);
      v26 = v25 - v111;
      v27 = hkOArchive::getStreamWriter(v6);
      ((void (__fastcall *)(hkStreamWriter *, hkResult *, _QWORD, _QWORD))v27->vfptr[3].__first_virtual_table_function__)(
        v27,
        &v121,
        v23,
        0i64);
      hkOArchive::write16u(v6, val);
      hkOArchive::write16u(v6, v26 - v23);
      v28 = hkOArchive::getStreamWriter(v6);
      ((void (__fastcall *)(hkStreamWriter *, hkResult *, _QWORD, signed __int64))v28->vfptr[3].__first_virtual_table_function__)(
        v28,
        &v123,
        0i64,
        2i64);
      v29 = val;
      if ( (_WORD)val )
      {
        v30 = ptr->m_subtype.m_storage;
        if ( v30 > 0x21u )
          goto LABEL_13;
        v31 = 9127854081i64;
        if ( !_bittest64(&v31, v30) )
          break;
      }
LABEL_103:
      v20 = v113 + 1;
      ++v105;
      ++v113;
      if ( v105 >= v115 )
        goto LABEL_104;
    }
    v29 = val;
LABEL_13:
    if ( v30 == 25 )
    {
      v32 = hkClassMember::getClass(v119);
      v33 = (hkClassMember *)hkClassMember::getClass(ptr);
      v119 = v33;
      if ( v32 )
      {
        if ( v33 )
        {
          for ( i = 0; i < (unsigned __int16)val; ++i )
          {
            v35 = hkClass::getObjectSize(v32);
            hkObjectCopier::saveBody(v138, (char *)startAddress + i * v35, v32, v6, (hkClass *)v119, zeroArray);
          }
        }
      }
    }
    else if ( v30 != 28 )
    {
      if ( v30 == 30 )
      {
        writeUlongArray(v6, (unsigned __int8)v138->m_layoutOut.m_rules.m_bytesInPointer, v29, startAddress);
      }
      else
      {
        v102 = v30;
        v103 = v29;
        v104 = hkClassMember::getArrayMemberSize(ptr);
        writePodArray(v6, v102, v104, v103, startAddress);
      }
    }
    goto LABEL_103;
  }
LABEL_104:
  v115 = 0;
  if ( v116 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      40 * (v116 & 0x3FFFFFFF));
}

// File Line: 674
// RVA: 0xE6B220
hkResult *__fastcall saveCstring(hkResult *result, const char *dataIn, int klassMemOffset, int extrasStart, hkOArchive *dataOut, hkRelocationInfo *fixups)
{
  hkResult *v6; // r14
  int v7; // edi
  int v8; // ebx
  const char *v9; // rsi
  hkStreamWriter *v10; // rax
  hkStreamWriter *v11; // rax
  int v12; // eax
  hkRelocationInfo::Local v14; // [rsp+30h] [rbp+8h]

  v6 = result;
  v7 = extrasStart;
  v8 = klassMemOffset;
  v9 = dataIn;
  v10 = hkOArchive::getStreamWriter(dataOut);
  objectCopierPadUp(v10, 2);
  v11 = hkOArchive::getStreamWriter(dataOut);
  v14.m_fromOffset = v8;
  v14.m_toOffset = v7 + (unsigned __int64)((__int64 (__fastcall *)(hkStreamWriter *))v11->vfptr[4].__vecDelDtor)(v11);
  if ( fixups->m_local.m_size == (fixups->m_local.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, fixups, 8);
  fixups->m_local.m_data[fixups->m_local.m_size++] = v14;
  v12 = hkString::strLen(v9);
  hkOArchive::writeRaw(dataOut, v9, (unsigned int)(v12 + 1));
  v6->m_enum = 0;
  return v6;
}

// File Line: 692
// RVA: 0xE69D60
void __fastcall hkObjectCopier::saveExtras(hkObjectCopier *this, const void *dataIn, hkClass *klassIn, hkOArchive *dataOut, hkClass *klassOut, int classStart, int extrasStart, hkRelocationInfo *fixups, hkLocalArray<char> *zeroArray, int level)
{
  int v10; // eax
  hkClass *v11; // rbx
  hkOArchive *v12; // rdi
  hkObjectCopier *v13; // rsi
  hkRelocationInfo::Finish *v14; // rcx
  int v15; // eax
  hkClassMember *v16; // rax
  hkClassMember *v17; // rcx
  hkClassMember *v18; // rax
  char *v19; // rbx
  int v20; // edi
  int v21; // eax
  hkClass *v22; // rsi
  int v23; // edi
  int v24; // eax
  int v25; // er8
  __int64 v26; // rax
  int v27; // edi
  char v28; // al
  int v29; // er8
  hkClass *v30; // rax
  bool v31; // zf
  char v32; // al
  hkStreamWriter *v33; // rax
  int v34; // edi
  int v35; // eax
  char *v36; // rcx
  hkStreamWriter *v37; // rdi
  hkClass *v38; // rsi
  int v39; // eax
  hkStreamWriter *v40; // rax
  int v41; // edi
  int v42; // eax
  hkStreamWriter *v43; // rax
  int v44; // eax
  int v45; // er11
  int v46; // er9
  int v47; // ecx
  hkClass *v48; // rdx
  hkStreamWriter *v49; // rax
  int v50; // edi
  int v51; // eax
  hkStreamWriter *v52; // rax
  int v53; // eax
  int v54; // er10
  int v55; // er9
  int v56; // ecx
  signed __int64 v57; // rdx
  const char *v58; // rdx
  hkStreamWriter *v59; // rax
  hkClass *v60; // rax
  hkClass *v61; // rcx
  hkClass *v62; // rax
  int v63; // eax
  int v64; // edi
  int v65; // eax
  int v66; // ST28_4
  hkStreamWriter *v67; // rax
  int v68; // er8
  int v69; // eax
  hkClassMember *v70; // rcx
  void *v71; // r8
  int v72; // edi
  void *v73; // r8
  hkStreamWriter *v74; // rax
  int v75; // edi
  int v76; // eax
  unsigned __int8 v77; // cl
  hkClassMember::Type v78; // edi
  int v79; // eax
  hkClassMember::Type v80; // edx
  hkStreamWriter *v81; // rax
  int v82; // eax
  int v83; // edi
  int v84; // eax
  int v85; // ST28_4
  hkClass *v86; // rax
  int v87; // edi
  int v88; // eax
  int v89; // eax
  int v90; // edi
  char *v91; // rdi
  int v92; // eax
  int v93; // edi
  int v94; // eax
  int v95; // eax
  int v96; // er11
  __int64 v97; // rdx
  signed int v98; // er9
  signed __int64 v99; // r8
  __int64 v100; // rcx
  void *v101; // r10
  signed __int64 v102; // rcx
  hkClass *v103; // r8
  hkStreamWriter *v104; // rax
  int v105; // [rsp+50h] [rbp-B0h]
  __int64 v106; // [rsp+50h] [rbp-B0h]
  int v107; // [rsp+50h] [rbp-B0h]
  int v108; // [rsp+50h] [rbp-B0h]
  int v109; // [rsp+50h] [rbp-B0h]
  int i; // [rsp+50h] [rbp-B0h]
  int v111; // [rsp+50h] [rbp-B0h]
  int l; // [rsp+50h] [rbp-B0h]
  int m; // [rsp+50h] [rbp-B0h]
  int k; // [rsp+50h] [rbp-B0h]
  int v115; // [rsp+50h] [rbp-B0h]
  __int64 v116; // [rsp+58h] [rbp-A8h]
  int v117; // [rsp+58h] [rbp-A8h]
  int v118; // [rsp+58h] [rbp-A8h]
  int v119; // [rsp+58h] [rbp-A8h]
  int v120; // [rsp+58h] [rbp-A8h]
  int v121; // [rsp+58h] [rbp-A8h]
  int v122; // [rsp+58h] [rbp-A8h]
  int j; // [rsp+58h] [rbp-A8h]
  int v124; // [rsp+58h] [rbp-A8h]
  int v125; // [rsp+58h] [rbp-A8h]
  int v126; // [rsp+58h] [rbp-A8h]
  signed int v127; // [rsp+58h] [rbp-A8h]
  hkClassMember *v128; // [rsp+60h] [rbp-A0h]
  hkClass *v129; // [rsp+60h] [rbp-A0h]
  hkClassMember *v130; // [rsp+60h] [rbp-A0h]
  char *v131; // [rsp+60h] [rbp-A0h]
  hkClassMember *v132; // [rsp+60h] [rbp-A0h]
  hkClassMember *member; // [rsp+68h] [rbp-98h]
  hkClass *membera; // [rsp+68h] [rbp-98h]
  int memberb; // [rsp+68h] [rbp-98h]
  hkClass *klassIna; // [rsp+70h] [rbp-90h]
  hkClass *klassInb; // [rsp+70h] [rbp-90h]
  hkClass *klassInc; // [rsp+70h] [rbp-90h]
  hkClass *klassInd; // [rsp+70h] [rbp-90h]
  const char *klassIne; // [rsp+70h] [rbp-90h]
  hkClass *klassInf; // [rsp+70h] [rbp-90h]
  hkClass *klassIng; // [rsp+70h] [rbp-90h]
  hkClass *klassInh; // [rsp+70h] [rbp-90h]
  const char *toAddr; // [rsp+78h] [rbp-88h]
  char *toAddra; // [rsp+78h] [rbp-88h]
  void *toAddrb; // [rsp+78h] [rbp-88h]
  hkClass *toAddrc; // [rsp+78h] [rbp-88h]
  char *toAddrd; // [rsp+78h] [rbp-88h]
  int memberIndex; // [rsp+80h] [rbp-80h]
  int v150; // [rsp+84h] [rbp-7Ch]
  __int64 ptr; // [rsp+88h] [rbp-78h]
  __int64 v152; // [rsp+90h] [rbp-70h]
  hkResult v153; // [rsp+98h] [rbp-68h]
  __int64 v154; // [rsp+A0h] [rbp-60h]
  __int64 v155; // [rsp+A8h] [rbp-58h]
  hkResult v156; // [rsp+B0h] [rbp-50h]
  __int64 v157; // [rsp+B8h] [rbp-48h]
  __int64 buf; // [rsp+C0h] [rbp-40h]
  hkResult result; // [rsp+C8h] [rbp-38h]
  hkResult v160; // [rsp+CCh] [rbp-34h]
  hkErrStream v161; // [rsp+D0h] [rbp-30h]
  hkResult v162; // [rsp+E8h] [rbp-18h]
  char description; // [rsp+F0h] [rbp-10h]
  hkObjectCopier *v164; // [rsp+320h] [rbp+220h]
  char *v165; // [rsp+328h] [rbp+228h]
  hkClass *v166; // [rsp+330h] [rbp+230h]
  hkOArchive *oa; // [rsp+338h] [rbp+238h]
  int levela; // [rsp+368h] [rbp+268h]

  oa = dataOut;
  v166 = klassIn;
  v165 = (char *)dataIn;
  v164 = this;
  v10 = level;
  v11 = klassOut;
  v12 = dataOut;
  v13 = this;
  if ( !level )
  {
    LODWORD(ptr) = classStart;
    toAddr = hkClass::getName(klassOut);
    if ( fixups->m_finish.m_size == (fixups->m_finish.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &fixups->m_finish, 16);
    v14 = &fixups->m_finish.m_data[fixups->m_finish.m_size];
    *(_QWORD *)&v14->m_fromOffset = ptr;
    v14->m_className = toAddr;
    ++fixups->m_finish.m_size;
    v11 = klassOut;
    v10 = 0;
  }
  memberIndex = 0;
  levela = v10 + 1;
  v150 = hkClass::getNumMembers(v11);
  if ( v150 > 0 )
  {
    v15 = 0;
    do
    {
      v16 = hkClass::getMember(v11, v15);
      member = v16;
      if ( v166 == v11 )
      {
        v17 = v16;
        v128 = v16;
      }
      else
      {
        v18 = hkClass::getMemberByName(v166, v16->m_name);
        v17 = v18;
        v128 = v18;
        v16 = member;
      }
      if ( v17 )
      {
        v19 = &v165[v17->m_offset];
        if ( ((unsigned int (__fastcall *)(hkObjectCopier *, hkClassMember *, hkClassMember *))v13->vfptr[2].__vecDelDtor)(
               v13,
               v17,
               v16)
          && (!(v13->m_flags.m_storage & 2) || !(member->m_flags.m_storage & 0x400)) )
        {
          switch ( member->m_type.m_storage )
          {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 0xA:
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x15:
            case 0x18:
            case 0x1E:
            case 0x1F:
            case 0x20:
            case 0x22:
              break;
            case 0x13:
              hkErrStream::hkErrStream(&v161, &description, 512);
              hkOstream::operator<<((hkOstream *)&v161.vfptr, "TYPE_ZERO should not occur.");
              if ( (unsigned int)hkError::messageError(1679703557, &description, "Copier\\hkObjectCopier.cpp", 1047) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&v161.vfptr);
              break;
            case 0x14:
              v20 = objectCopier_calcCArraySize(member);
              v21 = objectCopier_calcCArraySize(v128);
              v22 = (hkClass *)`anonymous namespace'::min2<int>(v21, v20);
              v23 = objectCopier_calcCArraySize(v128);
              v24 = hkClassMember::getSizeInBytes(v128);
              v25 = 0;
              v105 = 0;
              klassIna = v22;
              v26 = v24 / v23;
              v116 = v26;
              if ( (signed int)v22 <= 0 )
              {
                v13 = v164;
                goto LABEL_111;
              }
              do
              {
                v13 = v164;
                toAddra = *(char **)v19;
                if ( *(_QWORD *)v19 )
                {
                  v27 = member->m_offset + v25 * (unsigned __int8)v164->m_layoutOut.m_rules.m_bytesInPointer;
                  v28 = member->m_subtype.m_storage;
                  if ( v28 == 2 )
                  {
                    v29 = v27 + classStart;
                    v12 = oa;
                    saveCstring(&v156, *(const char **)v19, v29, extrasStart, oa, fixups);
                    v25 = v105;
                  }
                  else
                  {
                    if ( v28 )
                    {
                      v30 = hkClassMember::getClass(v128);
                      hkRelocationInfo::addGlobal(fixups, v27 + classStart, toAddra, v30, 0);
                      v25 = v105;
                    }
                    v12 = oa;
                  }
                  v26 = v116;
                }
                else
                {
                  v12 = oa;
                }
                ++v25;
                v19 += v26;
                v31 = klassIna == (hkClass *)1;
                klassIna = (hkClass *)((char *)klassIna - 1);
                v105 = v25;
              }
              while ( !v31 );
              break;
            case 0x16:
            case 0x17:
            case 0x1A:
              if ( *((_DWORD *)v19 + 2) )
              {
                v32 = member->m_subtype.m_storage;
                if ( v32 )
                {
                  switch ( v32 )
                  {
                    case 20:
                      v33 = hkOArchive::getStreamWriter(v12);
                      v34 = member->m_offset;
                      v35 = ((__int64 (__fastcall *)(hkStreamWriter *))v33->vfptr[4].__vecDelDtor)(v33);
                      hkRelocationInfo::addLocal(fixups, v34 + classStart, extrasStart + v35);
                      buf = 0i64;
                      v117 = 0;
                      v106 = (signed int)hkClassMember::getArrayMemberSize(v128);
                      if ( *((_DWORD *)v19 + 2) <= 0 )
                        goto LABEL_111;
                      v36 = 0i64;
                      v12 = oa;
                      klassInb = 0i64;
                      do
                      {
                        toAddrb = *(void **)&v36[*(_QWORD *)v19];
                        if ( toAddrb && member->m_subtype.m_storage )
                        {
                          v37 = hkOArchive::getStreamWriter(v12);
                          v38 = hkClassMember::getClass(v128);
                          v39 = ((__int64 (__fastcall *)(hkStreamWriter *))v37->vfptr[4].__vecDelDtor)(v37);
                          hkRelocationInfo::addGlobal(fixups, extrasStart + v39, toAddrb, v38, 0);
                          v13 = v164;
                          v12 = oa;
                        }
                        hkOArchive::writeRaw(v12, &buf, (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer);
                        v36 = (char *)klassInb + v106;
                        klassInb = (hkClass *)((char *)klassInb + v106);
                        ++v117;
                      }
                      while ( v117 < *((_DWORD *)v19 + 2) );
                      break;
                    case 29:
                      v40 = hkOArchive::getStreamWriter(v12);
                      v41 = member->m_offset;
                      v42 = ((__int64 (__fastcall *)(hkStreamWriter *))v40->vfptr[4].__vecDelDtor)(v40);
                      hkRelocationInfo::addLocal(fixups, v41 + classStart, extrasStart + v42);
                      v12 = oa;
                      v154 = 0i64;
                      v43 = hkOArchive::getStreamWriter(oa);
                      v44 = ((__int64 (__fastcall *)(hkStreamWriter *))v43->vfptr[4].__vecDelDtor)(v43);
                      v45 = extrasStart;
                      v46 = extrasStart + v44;
                      v118 = 0;
                      v107 = extrasStart + v44;
                      if ( *((_DWORD *)v19 + 2) > 0 )
                      {
                        do
                        {
                          hkOArchive::writeRaw(oa, &v154, (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer);
                          ++v118;
                        }
                        while ( v118 < *((_DWORD *)v19 + 2) );
                        v46 = v107;
                        v45 = extrasStart;
                      }
                      v47 = 0;
                      v119 = 0;
                      if ( *((_DWORD *)v19 + 2) > 0 )
                      {
                        v48 = 0i64;
                        klassInc = 0i64;
                        do
                        {
                          if ( *(const char **)((char *)&v48->m_name + *(_QWORD *)v19) )
                          {
                            saveCstring(
                              &v160,
                              *(const char **)((char *)&v48->m_name + *(_QWORD *)v19),
                              v46 + v47 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                              v45,
                              oa,
                              fixups);
                            v47 = v119;
                            v48 = klassInc;
                          }
                          v46 = v107;
                          v45 = extrasStart;
                          ++v47;
                          v48 = (hkClass *)((char *)v48 + 8);
                          v119 = v47;
                          klassInc = v48;
                        }
                        while ( v47 < *((_DWORD *)v19 + 2) );
                      }
                      break;
                    case 33:
                      v49 = hkOArchive::getStreamWriter(v12);
                      v50 = member->m_offset;
                      v51 = ((__int64 (__fastcall *)(hkStreamWriter *))v49->vfptr[4].__vecDelDtor)(v49);
                      hkRelocationInfo::addLocal(fixups, v50 + classStart, extrasStart + v51);
                      v12 = oa;
                      v155 = 0i64;
                      v52 = hkOArchive::getStreamWriter(oa);
                      v53 = ((__int64 (__fastcall *)(hkStreamWriter *))v52->vfptr[4].__vecDelDtor)(v52);
                      v54 = extrasStart;
                      v55 = extrasStart + v53;
                      v120 = 0;
                      v108 = extrasStart + v53;
                      if ( *((_DWORD *)v19 + 2) > 0 )
                      {
                        do
                        {
                          hkOArchive::writeRaw(oa, &v155, (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer);
                          ++v120;
                        }
                        while ( v120 < *((_DWORD *)v19 + 2) );
                        v55 = v108;
                        v54 = extrasStart;
                      }
                      v56 = 0;
                      v121 = 0;
                      if ( *((_DWORD *)v19 + 2) > 0 )
                      {
                        v57 = 0i64;
                        klassInd = 0i64;
                        do
                        {
                          v58 = (const char *)(*(_QWORD *)(v57 + *(_QWORD *)v19) & 0xFFFFFFFFFFFFFFFEui64);
                          if ( v58 )
                          {
                            saveCstring(
                              &v153,
                              v58,
                              v55 + v56 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                              v54,
                              oa,
                              fixups);
                            v56 = v121;
                          }
                          v55 = v108;
                          v54 = extrasStart;
                          ++v56;
                          v57 = (signed __int64)&klassInd->m_parent;
                          klassInd = (hkClass *)((char *)klassInd + 8);
                          v121 = v56;
                        }
                        while ( v56 < *((_DWORD *)v19 + 2) );
                      }
                      break;
                    case 25:
                      v59 = hkOArchive::getStreamWriter(v12);
                      v122 = extrasStart
                           + (unsigned __int64)((__int64 (__fastcall *)(hkStreamWriter *))v59->vfptr[4].__vecDelDtor)(v59);
                      hkRelocationInfo::addLocal(fixups, classStart + member->m_offset, v122);
                      v129 = hkClassMember::getClass(v128);
                      v60 = hkClassMember::getClass(member);
                      v61 = v60;
                      membera = v60;
                      v62 = v129;
                      if ( v129 && v61 )
                      {
                        v109 = 0;
                        klassIne = *(const char **)v19;
                        if ( *((_DWORD *)v19 + 2) > 0 )
                        {
                          while ( 1 )
                          {
                            v63 = hkClass::getObjectSize(v62);
                            hkObjectCopier::saveBody(v13, &klassIne[v109++ * v63], v129, v12, membera, zeroArray);
                            if ( v109 >= *((_DWORD *)v19 + 2) )
                              break;
                            v62 = v129;
                          }
                          v61 = membera;
                        }
                        for ( i = 0; i < *((_DWORD *)v19 + 2); ++i )
                        {
                          v64 = v122 + i * (unsigned __int64)hkClass::getObjectSize(v61);
                          v65 = hkClass::getObjectSize(v129);
                          v66 = v64;
                          v12 = oa;
                          hkObjectCopier::saveExtras(
                            v13,
                            &klassIne[i * v65],
                            v129,
                            oa,
                            membera,
                            v66,
                            extrasStart,
                            fixups,
                            zeroArray,
                            levela);
                          v61 = membera;
                        }
                      }
                      break;
                    case 28:
                      v67 = hkOArchive::getStreamWriter(v12);
                      v111 = extrasStart
                           + (unsigned __int64)((__int64 (__fastcall *)(hkStreamWriter *))v67->vfptr[4].__vecDelDtor)(v67);
                      hkRelocationInfo::addLocal(fixups, classStart + member->m_offset, v111);
                      for ( j = 0; j < *((_DWORD *)v19 + 2); ++j )
                      {
                        v68 = (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer;
                        ptr = 0i64;
                        v152 = 0i64;
                        hkOArchive::writeArrayGeneric(v12, &ptr, v68, 2);
                      }
                      v69 = 0;
                      v124 = 0;
                      if ( *((_DWORD *)v19 + 2) > 0 )
                      {
                        v70 = 0i64;
                        v130 = 0i64;
                        do
                        {
                          v71 = *(void **)((char *)&v70->m_name + *(_QWORD *)v19);
                          v72 = 2 * v69 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer;
                          if ( v71 )
                          {
                            hkRelocationInfo::addGlobal(
                              fixups,
                              v72 + v111,
                              v71,
                              *(hkClass **)((char *)&v70->m_class + *(_QWORD *)v19),
                              0);
                            v70 = v130;
                          }
                          v73 = *(hkClass **)((char *)&v70->m_class + *(_QWORD *)v19);
                          if ( v73 )
                          {
                            hkRelocationInfo::addGlobal(
                              fixups,
                              v111 + v72 + (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                              v73,
                              &hkClassClass,
                              0);
                            v70 = v130;
                          }
                          v70 = (hkClassMember *)((char *)v70 + 16);
                          v69 = v124 + 1;
                          v130 = v70;
                          v124 = v69;
                        }
                        while ( v69 < *((_DWORD *)v19 + 2) );
                        goto LABEL_111;
                      }
                      break;
                    default:
                      v74 = hkOArchive::getStreamWriter(v12);
                      v75 = member->m_offset;
                      v76 = ((__int64 (__fastcall *)(hkStreamWriter *))v74->vfptr[4].__vecDelDtor)(v74);
                      hkRelocationInfo::addLocal(fixups, v75 + classStart, extrasStart + v76);
                      v77 = member->m_subtype.m_storage;
                      if ( v77 == 30 )
                      {
                        v12 = oa;
                        writeUlongArray(
                          oa,
                          (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                          *((_DWORD *)v19 + 2),
                          *(const void **)v19);
                      }
                      else
                      {
                        v78 = v77;
                        v79 = hkClassMember::getArrayMemberSize(member);
                        v80 = v78;
                        v12 = oa;
                        writePodArray(oa, v80, v79, *((_DWORD *)v19 + 2), *(const void **)v19);
                      }
                      break;
                  }
                }
              }
              break;
            case 0x19:
              klassIng = hkClassMember::getClass(v128);
              v86 = hkClassMember::getClass(member);
              toAddrc = v86;
              if ( klassIng && v86 )
              {
                v126 = classStart + member->m_offset;
                v87 = objectCopier_calcCArraySize(v128);
                v88 = objectCopier_calcCArraySize(member);
                v89 = `anonymous namespace'::min2<int>(v87, v88);
                v90 = 0;
                memberb = v89;
                for ( k = 0; v90 < memberb; k = v90 )
                {
                  v91 = &v19[(signed int)(v90 * (unsigned __int64)hkClass::getObjectSize(klassIng))];
                  v92 = hkClass::getObjectSize(toAddrc);
                  hkObjectCopier::saveExtras(
                    v13,
                    v91,
                    klassIng,
                    oa,
                    toAddrc,
                    v126 + k * v92,
                    extrasStart,
                    fixups,
                    zeroArray,
                    levela);
                  v90 = k + 1;
                }
                goto LABEL_111;
              }
              break;
            case 0x1B:
              v131 = *(char **)v19;
              if ( *(_QWORD *)v19 )
              {
                hkRelocationInfo::addGlobal(fixups, classStart + member->m_offset, *(void **)v19, &hkClassClass, 1u);
                v81 = hkOArchive::getStreamWriter(v12);
                v125 = extrasStart
                     + (unsigned __int64)((__int64 (__fastcall *)(hkStreamWriter *))v81->vfptr[4].__vecDelDtor)(v81);
                hkRelocationInfo::addLocal(
                  fixups,
                  classStart + (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer + member->m_offset,
                  v125);
                klassInf = (hkClass *)*((_QWORD *)v19 + 1);
                for ( l = 0; l < *((_DWORD *)v19 + 4); ++l )
                {
                  v82 = hkClass::getObjectSize((hkClass *)v131);
                  hkObjectCopier::saveBody(
                    v13,
                    (char *)klassInf + l * v82,
                    (hkClass *)v131,
                    v12,
                    (hkClass *)v131,
                    zeroArray);
                }
                for ( m = 0; m < *((_DWORD *)v19 + 4); ++m )
                {
                  v83 = v125 + m * (unsigned __int64)hkClass::getObjectSize((hkClass *)v131);
                  v84 = hkClass::getObjectSize((hkClass *)v131);
                  v85 = v83;
                  v12 = oa;
                  hkObjectCopier::saveExtras(
                    v13,
                    (char *)klassInf + m * v84,
                    (hkClass *)v131,
                    oa,
                    (hkClass *)v131,
                    v85,
                    extrasStart,
                    fixups,
                    zeroArray,
                    levela);
                }
              }
              break;
            case 0x1C:
              v93 = objectCopier_calcCArraySize(v128);
              v94 = objectCopier_calcCArraySize(member);
              v95 = `anonymous namespace'::min2<int>(v93, v94);
              v96 = 0;
              v97 = 0i64;
              v115 = 0;
              klassInh = 0i64;
              v157 = v95;
              if ( v95 > 0i64 )
              {
                v98 = 1;
                v127 = 1;
                v99 = 1i64;
                toAddrd = (char *)1;
                do
                {
                  v100 = (unsigned __int8)v13->m_layoutIn.m_rules.m_bytesInPointer;
                  v101 = *(void **)&v19[2 * v100 * v97];
                  v102 = v99 * v100;
                  v103 = *(hkClass **)&v19[v102];
                  v132 = *(hkClassMember **)&v19[v102];
                  if ( v101 )
                  {
                    hkRelocationInfo::addGlobal(
                      fixups,
                      member->m_offset
                    + classStart
                    + 2 * v96 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                      v101,
                      v103,
                      0);
                    v97 = (__int64)klassInh;
                    v103 = (hkClass *)v132;
                    v98 = v127;
                    v96 = v115;
                  }
                  if ( v103 )
                  {
                    hkRelocationInfo::addGlobal(
                      fixups,
                      classStart + v98 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer + member->m_offset,
                      v103,
                      &hkClassClass,
                      0);
                    v97 = (__int64)klassInh;
                    v98 = v127;
                    v96 = v115;
                  }
                  ++v97;
                  ++v96;
                  v99 = (signed __int64)(toAddrd + 2);
                  v98 += 2;
                  v115 = v96;
                  toAddrd += 2;
                  v127 = v98;
                  klassInh = (hkClass *)v97;
                }
                while ( v97 < v157 );
              }
LABEL_111:
              v12 = oa;
              break;
            case 0x1D:
              if ( *(_QWORD *)v19 )
                saveCstring(&result, *(const char **)v19, classStart + member->m_offset, extrasStart, v12, fixups);
              break;
            case 0x21:
              if ( *(_QWORD *)v19 & 0xFFFFFFFFFFFFFFFEui64 )
                saveCstring(
                  &v162,
                  (const char *)(*(_QWORD *)v19 & 0xFFFFFFFFFFFFFFFEui64),
                  classStart + member->m_offset,
                  extrasStart,
                  v12,
                  fixups);
              break;
            default:
              hkErrStream::hkErrStream(&v161, &description, 512);
              hkOstream::operator<<((hkOstream *)&v161.vfptr, "Unknown class member found during write of data.");
              if ( (unsigned int)hkError::messageError(1679703557, &description, "Copier\\hkObjectCopier.cpp", 1052) )
                __debugbreak();
              hkOstream::~hkOstream((hkOstream *)&v161.vfptr);
              break;
          }
          v104 = hkOArchive::getStreamWriter(v12);
          objectCopierPadUp(v104, 16);
        }
        v11 = klassOut;
      }
      v15 = memberIndex + 1;
      memberIndex = v15;
    }
    while ( v15 < v150 );
  }
}     v12,
                  fixups);
              break;
            default:
              hkErrStream::hkErrStream(&v161, &description, 512);
       

// File Line: 1062
// RVA: 0xE68BC0
hkResult *__fastcall hkObjectCopier::copyObject(hkObjectCopier *this, hkResult *result, const void *dataIn, hkClass *klassIn, hkStreamWriter *dataOut, hkClass *klassOut, hkRelocationInfo *reloc)
{
  hkObjectCopier *v7; // r15
  hkClass *v8; // r12
  const void *v9; // r13
  hkResult *v10; // r14
  hkLifoAllocator *v11; // rax
  char *v12; // rdx
  unsigned __int64 v13; // rcx
  hkLifoAllocator *v14; // rax
  char *v15; // rcx
  unsigned __int64 v16; // rdx
  void **v17; // rdx
  int v18; // er9
  hkStreamWriter *v19; // rsi
  int v20; // eax
  hkClass *v21; // rbx
  int v22; // edi
  int extrasStart; // eax
  __int64 v24; // rbx
  _QWORD **v25; // rax
  char *v26; // rdi
  int v27; // eax
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // er8
  unsigned int v31; // eax
  char *v32; // rdi
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // er8
  void *array; // [rsp+50h] [rbp-71h]
  unsigned int v38; // [rsp+58h] [rbp-69h]
  int v39; // [rsp+5Ch] [rbp-65h]
  void *p; // [rsp+60h] [rbp-61h]
  int v41; // [rsp+68h] [rbp-59h]
  hkLocalArray<char> zeroArray; // [rsp+70h] [rbp-51h]
  hkStreamWriter sw; // [rsp+90h] [rbp-31h]
  void **v44; // [rsp+A0h] [rbp-21h]
  hkContainerHeapAllocator::Allocator *v45; // [rsp+A8h] [rbp-19h]
  unsigned int v46; // [rsp+B0h] [rbp-11h]
  int v47; // [rsp+B4h] [rbp-Dh]
  hkOArchive v48; // [rsp+B8h] [rbp-9h]
  hkResult resulta; // [rsp+110h] [rbp+4Fh]

  v7 = this;
  v8 = klassIn;
  v9 = dataIn;
  v10 = result;
  array = 0i64;
  v38 = 0;
  v39 = 2147483648;
  v41 = 1024;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (char *)v11->m_cur;
  v13 = (unsigned __int64)(v12 + 1024);
  if ( v11->m_slabSize < 1024 || (void *)v13 > v11->m_end )
    v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v11, 1024);
  else
    v11->m_cur = (void *)v13;
  array = v12;
  v39 = -2147482624;
  p = v12;
  zeroArray.m_data = 0i64;
  zeroArray.m_size = 0;
  zeroArray.m_capacityAndFlags = 2147483648;
  zeroArray.m_initialCapacity = 16;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (char *)v14->m_cur;
  v16 = (unsigned __int64)(v15 + 128);
  if ( v14->m_slabSize < 128 || (void *)v16 > v14->m_end )
    v15 = (char *)hkLifoAllocator::allocateFromNewSlab(v14, 128);
  else
    v14->m_cur = (void *)v16;
  zeroArray.m_data = v15;
  zeroArray.m_localMemory = v15;
  sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
  v17 = &array;
  v18 = v38 + 1;
  v46 = v38;
  zeroArray.m_capacityAndFlags = -2147483632;
  *(_DWORD *)&sw.m_memSizeAndFlags = 0x1FFFF;
  v44 = &array;
  v45 = &hkContainerHeapAllocator::s_alloc;
  v47 = 1;
  if ( (v39 & 0x3FFFFFFF) < (signed int)(v38 + 1) )
  {
    if ( v18 < 2 * (v39 & 0x3FFFFFFF) )
      v18 = 2 * (v39 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 1);
    v17 = v44;
  }
  *((_BYTE *)*v17 + *((signed int *)v17 + 2)) = 0;
  hkOArchive::hkOArchive(&v48, &sw, v7->m_byteSwap);
  v19 = dataOut;
  v20 = ((__int64 (__fastcall *)(hkStreamWriter *))dataOut->vfptr[4].__vecDelDtor)(dataOut);
  v21 = klassOut;
  v22 = v20;
  hkObjectCopier::saveBody(v7, v9, v8, &v48, klassOut, &zeroArray);
  ((void (__fastcall *)(hkStreamWriter *, void *, _QWORD))v19->vfptr[2].__vecDelDtor)(v19, array, v38);
  objectCopierPadUp(v19, 16);
  hkArrayStreamWriter::clear((hkArrayStreamWriter *)&sw);
  extrasStart = ((__int64 (__fastcall *)(hkStreamWriter *))v19->vfptr[4].__vecDelDtor)(v19);
  hkObjectCopier::saveExtras(v7, v9, v8, &v48, v21, v22, extrasStart, reloc, &zeroArray, 0);
  ((void (__fastcall *)(hkStreamWriter *, void *, _QWORD))v19->vfptr[2].__vecDelDtor)(v19, array, v38);
  objectCopierPadUp(v19, 16);
  hkArrayStreamWriter::clear((hkArrayStreamWriter *)&sw);
  v10->m_enum = hkOArchive::isOk(&v48, (hkBool *)&dataOut)->m_bool == 0;
  hkOArchive::~hkOArchive(&v48);
  sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable';
  if ( !v47 )
  {
    v24 = (__int64)v44;
    if ( v44 )
    {
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v25[11] + 16i64))(v25[11], v24, 16i64);
    }
  }
  v26 = zeroArray.m_localMemory;
  sw.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v27 = zeroArray.m_size;
  if ( zeroArray.m_localMemory == zeroArray.m_data )
    v27 = 0;
  v28 = (zeroArray.m_initialCapacity + 127) & 0xFFFFFF80;
  zeroArray.m_size = v27;
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v28 + 15) & 0xFFFFFFF0;
  if ( v28 > v29->m_slabSize || &v26[v30] != v29->m_cur || v29->m_firstNonLifoEnd == v26 )
    hkLifoAllocator::slowBlockFree(v29, v26, v30);
  else
    v29->m_cur = v26;
  zeroArray.m_size = 0;
  if ( zeroArray.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      zeroArray.m_data,
      zeroArray.m_capacityAndFlags & 0x3FFFFFFF);
  v31 = v38;
  v32 = (char *)p;
  zeroArray.m_data = 0i64;
  if ( p == array )
    v31 = 0;
  zeroArray.m_capacityAndFlags = 2147483648;
  v33 = (v41 + 127) & 0xFFFFFF80;
  v38 = v31;
  v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (v33 + 15) & 0xFFFFFFF0;
  if ( v33 > v34->m_slabSize || &v32[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v32 )
    hkLifoAllocator::slowBlockFree(v34, v32, v35);
  else
    v34->m_cur = v32;
  v38 = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v39 & 0x3FFFFFFF);
  return v10;
}

