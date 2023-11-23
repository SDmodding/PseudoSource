// File Line: 30
// RVA: 0xE6AC70
bool __fastcall `anonymous namespace::inRange(int num, int lo, int hi)
{
  return num >= lo && num < hi;
}

// File Line: 35
// RVA: 0xE6B2F0
__int64 __fastcall `anonymous namespace::min2<int>(unsigned int a, unsigned int b)
{
  if ( (int)a < (int)b )
    return a;
  return b;
}

// File Line: 43
// RVA: 0xE68B60
void __fastcall hkObjectCopier::hkObjectCopier(
        hkObjectCopier *this,
        hkStructureLayout *layoutIn,
        hkStructureLayout *layoutOut,
        hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  hkStructureLayout v4; // eax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkObjectCopier::`vftable;
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
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 74
// RVA: 0xE6AC90
void __fastcall objectCopierPadUp(hkStreamWriter *w, int pad)
{
  int v4; // eax
  int v5; // edx
  int v6; // ebp
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  int v9; // edx
  char *v10; // rdi
  __int64 v11; // rax
  int v12; // r9d
  int v13; // eax
  char *v14; // rdi
  unsigned __int64 v15; // rdx
  char *v16; // rsi
  signed int v17; // edi
  hkLifoAllocator *v18; // rax
  int v19; // r8d
  char *array; // [rsp+30h] [rbp-38h] BYREF
  int v21; // [rsp+38h] [rbp-30h]
  int v22; // [rsp+3Ch] [rbp-2Ch]
  void *p; // [rsp+40h] [rbp-28h]
  int v24; // [rsp+48h] [rbp-20h]
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  v4 = ((__int64 (__fastcall *)(hkStreamWriter *))w->vfptr[4].__vecDelDtor)(w);
  v22 = 0x80000000;
  v5 = 0;
  array = 0i64;
  v24 = pad;
  v6 = v4;
  v21 = 0;
  if ( pad )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v9 = (pad + 127) & 0xFFFFFF80;
    v10 = &m_cur[v9];
    if ( v9 > Value->m_slabSize || v10 > Value->m_end )
    {
      v11 = hkLifoAllocator::allocateFromNewSlab(Value, v9);
      v5 = v21;
      m_cur = (char *)v11;
    }
    else
    {
      Value->m_cur = v10;
      v5 = v21;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  array = m_cur;
  p = m_cur;
  v22 = pad | 0x80000000;
  if ( (pad & 0x3FFFFFFF) < pad )
  {
    v12 = pad;
    if ( pad < 2 * (pad & 0x3FFFFFFF) )
      v12 = 2 * (pad & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v12, 1);
    v5 = v21;
    m_cur = array;
  }
  v13 = pad - v5;
  v14 = &m_cur[v5];
  v15 = pad - v5;
  if ( v13 > 0 )
  {
    memset(v14, 0, v15);
    m_cur = array;
  }
  v21 = pad;
  if ( (v6 & (pad - 1)) != 0 )
  {
    ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))w->vfptr[2].__vecDelDtor)(
      w,
      m_cur,
      pad - (v6 & (unsigned int)(pad - 1)));
    pad = v21;
    m_cur = array;
  }
  v16 = (char *)p;
  if ( p == m_cur )
    pad = 0;
  v17 = (v24 + 127) & 0xFFFFFF80;
  v21 = pad;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (v17 + 15) & 0xFFFFFFF0;
  if ( v17 > v18->m_slabSize || &v16[v19] != v18->m_cur || v18->m_firstNonLifoEnd == v16 )
    hkLifoAllocator::slowBlockFree(v18, v16, v19);
  else
    v18->m_cur = v16;
  v21 = 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v22 & 0x3FFFFFFF);
}

// File Line: 86
// RVA: 0xE6AE50
__int64 __fastcall objectCopier_calcCArraySize(hkClassMember *member)
{
  if ( (unsigned int)hkClassMember::getCstyleArraySize(member) )
    return hkClassMember::getCstyleArraySize(member);
  else
    return 1i64;
}

// File Line: 91
// RVA: 0xE6AE80
__int64 __fastcall writeZeros(hkOArchive *oa, int numZeros, hkLocalArray<char> *zeroArray)
{
  int v5; // eax
  int v7; // eax
  int v8; // r9d
  signed __int64 v9; // rcx
  char *m_data; // rdx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v5 = zeroArray->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < numZeros )
  {
    v7 = 2 * v5;
    v8 = numZeros;
    if ( numZeros < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&zeroArray->m_data, v8, 1);
  }
  v9 = numZeros - zeroArray->m_size;
  if ( v9 > 0 )
    memset(&zeroArray->m_data[zeroArray->m_size], 0, v9);
  m_data = zeroArray->m_data;
  zeroArray->m_size = numZeros;
  return hkOArchive::writeRaw(oa, m_data, (unsigned int)numZeros);
}

// File Line: 100
// RVA: 0xE68FC0
void __fastcall hkObjectCopier::writeZero(
        hkObjectCopier *this,
        hkOArchive *oa,
        hkClassMember *memberOut,
        hkLocalArray<char> *zeroArray)
{
  char m_storage; // cl
  unsigned int SizeInBytes; // ebx
  hkClass *StructClass; // rax
  int ObjectSize; // ebx
  hkOstream buf; // [rsp+20h] [rbp-228h] BYREF
  char description[512]; // [rsp+40h] [rbp-208h] BYREF

  m_storage = memberOut->m_type.m_storage;
  SizeInBytes = 0;
  switch ( m_storage )
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
      SizeInBytes = hkClassMember::getSizeInBytes(memberOut);
      goto LABEL_13;
    case 20:
    case 21:
    case 30:
    case 33:
      SizeInBytes = (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer * objectCopier_calcCArraySize(memberOut);
      goto LABEL_13;
    case 22:
    case 23:
    case 26:
    case 27:
      if ( m_storage == 27 )
        SizeInBytes = (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer;
      SizeInBytes += (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer + 4;
      if ( m_storage != 22 )
        goto LABEL_13;
      LOBYTE(buf.vfptr) = 0;
      *(hkBaseObjectVtbl **)((char *)&buf.vfptr + 1) = 0i64;
      *(unsigned __int16 *)((char *)&buf.m_memSizeAndFlags + 1) = 0;
      HIBYTE(buf.m_referenceCount) = 0;
      hkOArchive::writeRaw(oa, &buf, SizeInBytes);
      hkOArchive::write32u(oa, 0x80000000);
      break;
    case 25:
      StructClass = hkClassMember::getStructClass(memberOut);
      ObjectSize = hkClass::getObjectSize(StructClass);
      SizeInBytes = objectCopier_calcCArraySize(memberOut) * ObjectSize;
      goto LABEL_13;
    case 28:
      SizeInBytes = 2
                  * (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer
                  * objectCopier_calcCArraySize(memberOut);
      goto LABEL_13;
    default:
      hkErrStream::hkErrStream((hkErrStream *)&buf, description, 512);
      hkOstream::operator<<(&buf, "Unknown class member type found!");
      if ( (unsigned int)hkError::messageError(0x5EF4E5A4u, description, "Copier\\hkObjectCopier.cpp", 178) )
        __debugbreak();
      hkOstream::~hkOstream(&buf);
LABEL_13:
      writeZeros(oa, SizeInBytes, zeroArray);
      break;
  }
}

// File Line: 188
// RVA: 0xE6AF20
void __fastcall writeUlongArray(hkOArchive *oa, int elemsize, int nelem, char *startAddress)
{
  __int64 v5; // rsi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rbx
  int v10; // ebp
  char *v11; // rcx
  __int64 v12; // rdx
  int v13; // ecx
  hkLifoAllocator *v14; // rax
  int v15; // r8d

  v5 = nelem;
  if ( elemsize == 8 )
  {
    hkOArchive::writeArrayGeneric(oa, startAddress, 8, nelem);
  }
  else
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v10 = (4 * v5 + 127) & 0xFFFFFF80;
    v11 = &m_cur[v10];
    if ( v10 > Value->m_slabSize || v11 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
    else
      Value->m_cur = v11;
    v12 = 0i64;
    if ( (int)v5 > 0 )
    {
      do
      {
        v13 = *(_DWORD *)&startAddress[8 * v12++];
        *(_DWORD *)&m_cur[4 * v12 - 4] = v13;
      }
      while ( v12 < v5 );
    }
    hkOArchive::writeArrayGeneric(oa, m_cur, elemsize, v5);
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (v10 + 15) & 0xFFFFFFF0;
    if ( v10 > v14->m_slabSize || &m_cur[v15] != v14->m_cur || v14->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v14, m_cur, v15);
    else
      v14->m_cur = m_cur;
  }
}

// File Line: 214
// RVA: 0xE6B030
void __fastcall writePodArray(hkOArchive *oa, hkClassMember::Type mtype, int elemsize, int nelem, char *startAddress)
{
  unsigned __int64 v5; // rax
  hkErrStream v6; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

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
      hkErrStream::hkErrStream(&v6, buf, 512);
      hkOstream::operator<<(&v6, "Unknown class member found during write of plain data array.");
      if ( (unsigned int)hkError::messageError(0x747E1E03u, buf, "Copier\\hkObjectCopier.cpp", 259) )
        __debugbreak();
      hkOstream::~hkOstream(&v6);
      break;
  }
}

// File Line: 265
// RVA: 0xE6B120
hkResult *__fastcall applyDefaultsFor(
        hkResult *result,
        hkClass *klass,
        hkClassMember *mem,
        int memberIndex,
        hkStreamWriter *writer)
{
  hkClass *Class; // rdi
  int v8; // eax
  __int64 v9; // rbp
  int v10; // ebx
  hkStreamWriter *v11; // rbp
  hkClassMember *Member; // rax
  hkResult resulta; // [rsp+50h] [rbp+8h] BYREF
  __int64 v15; // [rsp+60h] [rbp+18h]

  hkClass::getDefault(klass, result, memberIndex, writer);
  if ( mem->m_type.m_storage != 25 )
    return result;
  Class = hkClassMember::getClass(mem);
  if ( !Class )
    return result;
  v8 = objectCopier_calcCArraySize(mem);
  if ( v8 <= 0 )
    return result;
  v9 = (unsigned int)v8;
  v15 = (unsigned int)v8;
  do
  {
    v10 = 0;
    if ( (int)hkClass::getNumMembers(Class) > 0 )
    {
      v11 = writer;
      do
      {
        Member = hkClass::getMember(Class, v10);
        if ( applyDefaultsFor(&resulta, Class, Member, v10, v11)->m_enum == HK_SUCCESS )
          result->m_enum = HK_SUCCESS;
        ++v10;
      }
      while ( v10 < (int)hkClass::getNumMembers(Class) );
      v9 = v15;
    }
    v15 = --v9;
  }
  while ( v9 );
  return result;
}

// File Line: 290
// RVA: 0xE68F90
_BOOL8 __fastcall hkObjectCopier::areMembersCompatible(hkObjectCopier *this, hkClassMember *src, hkClassMember *dst)
{
  char m_storage; // cl

  m_storage = src->m_type.m_storage;
  return m_storage == dst->m_type.m_storage && (src->m_subtype.m_storage == dst->m_subtype.m_storage || m_storage == 24);
}

// File Line: 313
// RVA: 0xE69190
void __fastcall hkObjectCopier::saveBody(
        hkObjectCopier *this,
        char *dataIn,
        hkClass *klassIn,
        hkOArchive *dataOut,
        hkClass *klassOut,
        hkLocalArray<char> *zeroArray)
{
  hkOArchive *v6; // rsi
  hkStreamWriter *StreamWriter; // rax
  int v8; // eax
  hkClass *v9; // rbx
  int v10; // edi
  hkClassMember *v11; // rdi
  hkStreamWriter *v12; // rax
  int m_offset; // ebx
  int v14; // eax
  unsigned int m_storage; // eax
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
  __int64 v31; // r8
  hkClass *v32; // rdi
  hkClassMember *v33; // rax
  int v34; // ebx
  int v35; // eax
  hkStreamWriter *v36; // rax
  hkClassMember *MemberByName; // rax
  int v38; // edx
  int *v39; // rbx
  int v40; // edi
  int v41; // esi
  int SizeInBytes; // ebx
  int v43; // r9d
  int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // eax
  int v48; // ebx
  int v49; // eax
  __int64 v50; // rdi
  __int64 v51; // rbx
  char *v52; // rax
  int EnumValue; // eax
  int v54; // eax
  __int64 v55; // rbx
  int m_bytesInPointer; // r8d
  int v57; // ebx
  const char *m_name; // rdi
  const char *v59; // rbx
  hkOstream *v60; // rax
  hkOstream *v61; // rax
  hkOstream *v62; // rax
  hkOstream *v63; // rax
  int v64; // r8d
  hkStreamWriter *v65; // rax
  int v66; // eax
  __int64 v67; // rbx
  hkClassMember *v68; // rbx
  int v69; // edx
  hkClassMember **v70; // r8
  hkStreamWriter *m_pntr; // rax
  __int64 v72; // rax
  hkClassMember *Class; // rbx
  hkClassEnum *v74; // rax
  int v75; // ebx
  int v76; // eax
  int v77; // eax
  int v78; // ebx
  hkClass *v79; // rdi
  int ObjectSize; // eax
  int v81; // ebx
  int v82; // eax
  int v83; // eax
  __int64 v84; // rbx
  int v85; // ebx
  int v86; // eax
  hkClassEnum *v87; // rax
  hkClassMember *v88; // rdi
  int v89; // eax
  hkClassMember *v90; // rcx
  char *v91; // rbx
  int v92; // eax
  int v93; // edi
  int v94; // esi
  __int64 v95; // rbx
  int v96; // edx
  __int16 v97; // dx
  char v98; // dl
  bool v99; // zf
  hkStreamWriter *v100; // rax
  hkClassMember::Type v101; // edi
  int v102; // ebx
  int ArrayMemberSize; // eax
  int v104; // [rsp+30h] [rbp-D0h] BYREF
  int val; // [rsp+34h] [rbp-CCh] BYREF
  void *startAddress; // [rsp+38h] [rbp-C8h]
  hkClassMember *member; // [rsp+40h] [rbp-C0h]
  hkClassMember *ptr; // [rsp+48h] [rbp-B8h] BYREF
  int memberIndex; // [rsp+50h] [rbp-B0h]
  int v110; // [rsp+54h] [rbp-ACh]
  int bitsOver; // [rsp+58h] [rbp-A8h] BYREF
  hkClassEnum *EnumClass; // [rsp+60h] [rbp-A0h]
  char *array; // [rsp+68h] [rbp-98h] BYREF
  int v114; // [rsp+70h] [rbp-90h]
  int v115; // [rsp+74h] [rbp-8Ch]
  hkArray<char const *,hkContainerHeapAllocator> bitsOut; // [rsp+78h] [rbp-88h] BYREF
  hkClassMember *v117; // [rsp+88h] [rbp-78h]
  hkClassMember *v118; // [rsp+90h] [rbp-70h]
  int v119; // [rsp+98h] [rbp-68h] BYREF
  hkResult v120; // [rsp+9Ch] [rbp-64h] BYREF
  int NumMembers; // [rsp+A0h] [rbp-60h]
  hkResult v122; // [rsp+A4h] [rbp-5Ch] BYREF
  __int64 v123; // [rsp+A8h] [rbp-58h] BYREF
  hkResult v124; // [rsp+B0h] [rbp-50h] BYREF
  hkResult v125; // [rsp+B4h] [rbp-4Ch] BYREF
  hkResult v126; // [rsp+B8h] [rbp-48h] BYREF
  __int64 buf; // [rsp+C0h] [rbp-40h] BYREF
  hkResult v128; // [rsp+C8h] [rbp-38h] BYREF
  hkClassEnum *v129; // [rsp+D0h] [rbp-30h]
  char *name; // [rsp+D8h] [rbp-28h] BYREF
  hkErrStream v131; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v132; // [rsp+100h] [rbp+0h]
  hkResult result; // [rsp+108h] [rbp+8h] BYREF
  __int64 v134[2]; // [rsp+110h] [rbp+10h] BYREF
  char description[544]; // [rsp+120h] [rbp+20h] BYREF

  v6 = dataOut;
  StreamWriter = hkOArchive::getStreamWriter(dataOut);
  v8 = ((__int64 (__fastcall *)(hkStreamWriter *))StreamWriter->vfptr[4].__vecDelDtor)(StreamWriter);
  v9 = klassOut;
  v115 = 0x80000000;
  v110 = v8;
  array = 0i64;
  v114 = 0;
  v10 = 0;
  memberIndex = 0;
  NumMembers = hkClass::getNumMembers(klassOut);
  if ( NumMembers > 0 )
  {
    while ( 1 )
    {
      v11 = hkClass::getMember(v9, v10);
      v117 = v11;
      v12 = hkOArchive::getStreamWriter(v6);
      m_offset = v11->m_offset;
      v14 = ((__int64 (__fastcall *)(hkStreamWriter *))v12->vfptr[4].__vecDelDtor)(v12);
      writeZeros(v6, m_offset + v110 - v14, zeroArray);
      if ( (v11->m_flags.m_storage & 0x400) == 0 )
        goto LABEL_21;
      m_storage = this->m_flags.m_storage;
      if ( (m_storage & 2) == 0 )
        break;
      hkObjectCopier::writeZero(this, v6, v11, zeroArray);
$LN357_0:
      v9 = klassOut;
LABEL_6:
      v10 = memberIndex + 1;
      memberIndex = v10;
      if ( v10 >= NumMembers )
        goto LABEL_7;
    }
    if ( (m_storage & 1) != 0 )
    {
      v36 = hkOArchive::getStreamWriter(v6);
      v9 = klassOut;
      applyDefaultsFor(&result, klassOut, v11, memberIndex, v36);
      goto LABEL_6;
    }
LABEL_21:
    if ( klassIn == klassOut )
      MemberByName = v11;
    else
      MemberByName = hkClass::getMemberByName(klassIn, v11->m_name);
    member = MemberByName;
    if ( !MemberByName
      || !((unsigned int (__fastcall *)(hkObjectCopier *, hkClassMember *, hkClassMember *))this->vfptr[2].__vecDelDtor)(
            this,
            MemberByName,
            v11) )
    {
      v100 = hkOArchive::getStreamWriter(v6);
      v9 = klassOut;
      applyDefaultsFor(&v120, klassOut, v11, memberIndex, v100);
      goto LABEL_6;
    }
    v38 = (unsigned __int8)v11->m_type.m_storage;
    v39 = (int *)&dataIn[member->m_offset];
    startAddress = v39;
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
        v41 = objectCopier_calcCArraySize(v117);
        SizeInBytes = hkClassMember::getSizeInBytes(v117);
        v43 = `anonymous namespace::min2<int>(v40, v41);
        v44 = SizeInBytes / v41;
        v6 = dataOut;
        writePodArray(dataOut, (hkClassMember::Type)(unsigned __int8)v117->m_type.m_storage, v44, v43, startAddress);
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
            hkOArchive::writeRaw(v6, &buf, (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer);
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
          m_bytesInPointer = (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer;
          ptr = 0i64;
          hkOArchive::writeArrayGeneric(v6, (char *)&ptr, m_bytesInPointer, 1);
          if ( *(_QWORD *)v39 )
          {
            v57 = v39[4];
          }
          else
          {
            hkErrStream::hkErrStream(&v131, description, 512);
            m_name = member->m_name;
            v59 = hkClass::getName(klassIn);
            v60 = hkOstream::operator<<(&v131, "Cant copy homogeneous array. No hkClass for ");
            v61 = hkOstream::operator<<(v60, v59);
            v62 = hkOstream::operator<<(v61, "::");
            v63 = hkOstream::operator<<(v62, m_name);
            hkOstream::operator<<(v63, ".");
            hkError::messageWarning(0xABBA5A55, description, "Copier\\hkObjectCopier.cpp", 462);
            hkOstream::~hkOstream(&v131);
            v11 = v117;
            v57 = 0;
          }
        }
        else if ( v11->m_subtype.m_storage )
        {
          v57 = v39[2];
        }
        else
        {
          v57 = 0;
        }
        v64 = (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer;
        v123 = 0i64;
        hkOArchive::writeArrayGeneric(v6, (char *)&v123, v64, 1);
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
            v104 = `anonymous namespace::min2<int>(v48, v49);
            ptr = (hkClassMember *)hkClassMember::getEnumClass(member);
            EnumClass = hkClassMember::getEnumClass(v11);
            v50 = (int)hkClassMember::getSizeInBytes(member) / v48;
            if ( v104 > 0 )
            {
              v51 = (unsigned int)v104;
              v52 = (char *)startAddress;
              do
              {
                EnumValue = hkClassMember::getEnumValue(member, v52);
                val = 0;
                if ( hkClassEnum::getNameOfValue((hkClassEnum *)ptr, &v126, EnumValue, (const char **)&name)->m_enum == HK_SUCCESS )
                  hkClassEnum::getValueOfName(EnumClass, &v128, name, &val);
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
        Class = (hkClassMember *)hkClassMember::getClass(member);
        ptr = Class;
        v74 = (hkClassEnum *)hkClassMember::getClass(v11);
        EnumClass = v74;
        if ( Class )
        {
          if ( v74 )
          {
            v75 = objectCopier_calcCArraySize(v11);
            v76 = objectCopier_calcCArraySize(member);
            v77 = `anonymous namespace::min2<int>(v76, v75);
            v78 = 0;
            v104 = v77;
            if ( v77 > 0 )
            {
              v79 = (hkClass *)ptr;
              do
              {
                ObjectSize = hkClass::getObjectSize(v79);
                hkObjectCopier::saveBody(
                  this,
                  (char *)startAddress + v78 * ObjectSize,
                  v79,
                  v6,
                  (hkClass *)EnumClass,
                  zeroArray);
                ++v78;
              }
              while ( v78 < v104 );
            }
          }
        }
        break;
      case 28:
        v134[0] = 0i64;
        v134[1] = 0i64;
        v81 = objectCopier_calcCArraySize(v11);
        v82 = objectCopier_calcCArraySize(member);
        v83 = `anonymous namespace::min2<int>(v82, v81);
        if ( v83 > 0 )
        {
          v84 = (unsigned int)v83;
          do
          {
            hkOArchive::writeArrayGeneric(
              v6,
              (char *)v134,
              (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer,
              2);
            --v84;
          }
          while ( v84 );
        }
        break;
      case 30:
        v45 = objectCopier_calcCArraySize(member);
        v46 = objectCopier_calcCArraySize(v11);
        v47 = `anonymous namespace::min2<int>(v45, v46);
        writeUlongArray(v6, (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer, v47, startAddress);
        break;
      case 31:
        if ( member->m_enum )
        {
          if ( v11->m_enum )
          {
            v85 = objectCopier_calcCArraySize(member);
            v86 = objectCopier_calcCArraySize(v11);
            v104 = `anonymous namespace::min2<int>(v85, v86);
            v129 = hkClassMember::getEnumClass(member);
            v87 = hkClassMember::getEnumClass(v11);
            v88 = member;
            EnumClass = v87;
            v89 = hkClassMember::getSizeInBytes(member);
            v90 = (hkClassMember *)(v89 / v85);
            LODWORD(v117) = v89 / v85;
            if ( v104 > 0 )
            {
              v91 = (char *)startAddress;
              v118 = v90;
              ptr = (hkClassMember *)(unsigned int)v104;
              do
              {
                v92 = hkClassMember::getEnumValue(v88, v91);
                v93 = 0;
                bitsOut.m_data = 0i64;
                bitsOut.m_size = 0;
                bitsOut.m_capacityAndFlags = 0x80000000;
                bitsOver = 0;
                hkClassEnum::decomposeFlags(v129, &v125, v92, &bitsOut, &bitsOver);
                v94 = 0;
                if ( bitsOut.m_size > 0 )
                {
                  v95 = 0i64;
                  do
                  {
                    if ( hkClassEnum::getValueOfName(EnumClass, &v124, bitsOut.m_data[v95], &v119)->m_enum )
                      bitsOver |= v119;
                    else
                      v94 |= v119;
                    ++v93;
                    ++v95;
                  }
                  while ( v93 < bitsOut.m_size );
                  v91 = (char *)startAddress;
                }
                if ( bitsOver )
                {
                  v104 = 0;
                  hkClassEnum::decomposeFlags(EnumClass, &v122, bitsOver, &bitsOut, &v104);
                  v94 |= v104;
                }
                switch ( (_DWORD)v117 )
                {
                  case 1:
                    v98 = v94;
                    v6 = dataOut;
                    hkOArchive::write8(dataOut, v98);
                    break;
                  case 2:
                    v97 = v94;
                    v6 = dataOut;
                    hkOArchive::write16(dataOut, v97);
                    break;
                  case 4:
                    v96 = v94;
                    v6 = dataOut;
                    hkOArchive::write32(dataOut, v96);
                    break;
                  default:
                    v6 = dataOut;
                    break;
                }
                v91 = &v91[(_QWORD)v118];
                bitsOut.m_size = 0;
                startAddress = v91;
                if ( bitsOut.m_capacityAndFlags >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    bitsOut.m_data,
                    8 * bitsOut.m_capacityAndFlags);
                v99 = ptr == (hkClassMember *)1;
                ptr = (hkClassMember *)((char *)ptr - 1);
                bitsOut.m_data = 0i64;
                v88 = member;
                bitsOut.m_capacityAndFlags = 0x80000000;
              }
              while ( !v99 );
            }
          }
        }
        break;
      case 34:
        v65 = hkOArchive::getStreamWriter(v6);
        v66 = ((__int64 (__fastcall *)(hkStreamWriter *))v65->vfptr[4].__vecDelDtor)(v65);
        v67 = *((unsigned __int16 *)v39 + 1);
        LODWORD(v131.m_writer.m_pntr) = v66 - v110;
        v68 = (hkClassMember *)((char *)startAddress + v67);
        LOWORD(v132) = *(_WORD *)startAddress;
        hkOArchive::write16u(v6, 0);
        hkOArchive::write16u(v6, 0);
        v69 = v114;
        if ( v114 == (v115 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array, 40);
          v69 = v114;
        }
        v70 = (hkClassMember **)&array[40 * v69];
        if ( v70 )
        {
          *v70 = member;
          m_pntr = v131.m_writer.m_pntr;
          v70[1] = v11;
          v70[2] = (hkClassMember *)m_pntr;
          v72 = v132;
          v70[3] = v68;
          v70[4] = (hkClassMember *)v72;
          v69 = v114;
        }
        v114 = v69 + 1;
        break;
      default:
        hkErrStream::hkErrStream(&v131, description, 512);
        hkOstream::operator<<(&v131, "Unknown class member found during write of data.");
        if ( (unsigned int)hkError::messageError(0x641E3E03u, description, "Copier\\hkObjectCopier.cpp", 585) )
          __debugbreak();
        hkOstream::~hkOstream(&v131);
        break;
    }
    goto $LN357_0;
  }
LABEL_7:
  v16 = hkOArchive::getStreamWriter(v6);
  v17 = ((__int64 (__fastcall *)(hkStreamWriter *))v16->vfptr[4].__vecDelDtor)(v16);
  v18 = v110 - v17;
  v19 = hkClass::getObjectSize(klassOut);
  writeZeros(v6, v18 + v19, zeroArray);
  v104 = 0;
  if ( v114 > 0 )
  {
    v20 = 0i64;
    EnumClass = 0i64;
    while ( 1 )
    {
      v118 = *(hkClassMember **)&array[(_QWORD)v20];
      ptr = *(hkClassMember **)&array[(_QWORD)v20 + 8];
      v21 = *(_WORD *)&array[(_QWORD)v20 + 32];
      startAddress = *(void **)&array[(_QWORD)v20 + 24];
      LOWORD(val) = v21;
      v22 = hkOArchive::getStreamWriter(v6);
      objectCopierPadUp(v22, 16);
      v23 = *(_DWORD *)&array[(_QWORD)v20 + 16];
      v24 = hkOArchive::getStreamWriter(v6);
      v25 = ((__int64 (__fastcall *)(hkStreamWriter *))v24->vfptr[4].__vecDelDtor)(v24);
      v26 = v25 - v110;
      v27 = hkOArchive::getStreamWriter(v6);
      ((void (__fastcall *)(hkStreamWriter *, hkResult *, _QWORD, _QWORD))v27->vfptr[3].__first_virtual_table_function__)(
        v27,
        &v120,
        v23,
        0i64);
      hkOArchive::write16u(v6, val);
      hkOArchive::write16u(v6, v26 - v23);
      v28 = hkOArchive::getStreamWriter(v6);
      ((void (__fastcall *)(hkStreamWriter *, hkResult *, _QWORD, __int64))v28->vfptr[3].__first_virtual_table_function__)(
        v28,
        &v122,
        0i64,
        2i64);
      v29 = val;
      if ( (_WORD)val )
      {
        v30 = ptr->m_subtype.m_storage;
        if ( v30 > 0x21u )
          goto LABEL_13;
        v31 = 0x220100001i64;
        if ( !_bittest64(&v31, v30) )
          break;
      }
LABEL_103:
      v20 = EnumClass + 1;
      ++v104;
      ++EnumClass;
      if ( v104 >= v114 )
        goto LABEL_104;
    }
    v29 = val;
LABEL_13:
    if ( v30 == 25 )
    {
      v32 = hkClassMember::getClass(v118);
      v33 = (hkClassMember *)hkClassMember::getClass(ptr);
      v118 = v33;
      if ( v32 )
      {
        if ( v33 )
        {
          v34 = 0;
          if ( (_WORD)val )
          {
            do
            {
              v35 = hkClass::getObjectSize(v32);
              hkObjectCopier::saveBody(this, (char *)startAddress + v34 * v35, v32, v6, (hkClass *)v118, zeroArray);
              ++v34;
            }
            while ( v34 < (unsigned __int16)val );
          }
        }
      }
    }
    else if ( v30 != 28 )
    {
      if ( v30 == 30 )
      {
        writeUlongArray(v6, (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer, v29, startAddress);
      }
      else
      {
        v101 = v30;
        v102 = v29;
        ArrayMemberSize = hkClassMember::getArrayMemberSize(ptr);
        writePodArray(v6, v101, ArrayMemberSize, v102, startAddress);
      }
    }
    goto LABEL_103;
  }
LABEL_104:
  v114 = 0;
  if ( v115 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array,
      40 * (v115 & 0x3FFFFFFF));
}cator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array,
      40 * (v115 & 0x3FFFFFFF));
}

// File Line: 674
// RVA: 0xE6B220
hkResult *__fastcall saveCstring(
        hkResult *result,
        const char *dataIn,
        int klassMemOffset,
        int extrasStart,
        hkOArchive *dataOut,
        hkRelocationInfo *fixups)
{
  hkStreamWriter *StreamWriter; // rax
  hkStreamWriter *v11; // rax
  int v12; // eax
  hkRelocationInfo::Local v14; // [rsp+30h] [rbp+8h]

  StreamWriter = hkOArchive::getStreamWriter(dataOut);
  objectCopierPadUp(StreamWriter, 2);
  v11 = hkOArchive::getStreamWriter(dataOut);
  v14.m_fromOffset = klassMemOffset;
  v14.m_toOffset = extrasStart + ((__int64 (__fastcall *)(hkStreamWriter *))v11->vfptr[4].__vecDelDtor)(v11);
  if ( fixups->m_local.m_size == (fixups->m_local.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&fixups->m_local.m_data, 8);
  fixups->m_local.m_data[fixups->m_local.m_size++] = v14;
  v12 = hkString::strLen(dataIn);
  hkOArchive::writeRaw(dataOut, dataIn, (unsigned int)(v12 + 1));
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 692
// RVA: 0xE69D60
void __fastcall hkObjectCopier::saveExtras(
        hkObjectCopier *this,
        char *dataIn,
        hkClass *klassIn,
        hkOArchive *dataOut,
        hkClass *klassOut,
        int classStart,
        int extrasStart,
        hkRelocationInfo *fixups,
        hkLocalArray<char> *zeroArray,
        int level)
{
  int v10; // eax
  hkClass *v11; // rbx
  hkOArchive *v12; // rdi
  hkObjectCopier *v13; // rsi
  hkRelocationInfo::Finish *v14; // rcx
  int i; // eax
  hkClassMember *v16; // rax
  hkClassMember *MemberByName; // rcx
  char *v18; // rbx
  int v19; // edi
  int v20; // eax
  hkClass *v21; // rsi
  int v22; // edi
  int SizeInBytes; // eax
  int v24; // r8d
  __int64 v25; // rax
  int v26; // edi
  char m_storage; // al
  int v28; // r8d
  hkClass *Class; // rax
  bool v30; // zf
  char v31; // al
  hkStreamWriter *StreamWriter; // rax
  int m_offset; // edi
  int v34; // eax
  char *v35; // rcx
  hkStreamWriter *v36; // rdi
  hkClass *v37; // rsi
  int v38; // eax
  hkStreamWriter *v39; // rax
  int v40; // edi
  int v41; // eax
  hkStreamWriter *v42; // rax
  int v43; // eax
  int v44; // r11d
  int v45; // r9d
  int v46; // ecx
  hkClass *v47; // rdx
  hkStreamWriter *v48; // rax
  int v49; // edi
  int v50; // eax
  hkStreamWriter *v51; // rax
  int v52; // eax
  int v53; // r10d
  int v54; // r9d
  int v55; // ecx
  hkClass **p_m_parent; // rdx
  const char *v57; // rdx
  hkStreamWriter *v58; // rax
  hkClass *v59; // rcx
  hkClass *v60; // rax
  int ObjectSize; // eax
  int v62; // edi
  int v63; // eax
  hkStreamWriter *v64; // rax
  int m_bytesInPointer; // r8d
  int v66; // eax
  hkClassMember *v67; // rcx
  void *v68; // r8
  int v69; // edi
  void *v70; // r8
  hkStreamWriter *v71; // rax
  int v72; // edi
  int v73; // eax
  unsigned __int8 v74; // cl
  hkClassMember::Type v75; // edi
  int v76; // eax
  hkClassMember::Type v77; // edx
  hkStreamWriter *v78; // rax
  int v79; // eax
  int v80; // edi
  int v81; // eax
  hkClass *v82; // rax
  int v83; // edi
  int v84; // eax
  int v85; // eax
  int v86; // edi
  char *v87; // rdi
  int v88; // eax
  int v89; // edi
  int v90; // eax
  int v91; // eax
  int v92; // r11d
  __int64 v93; // rdx
  int v94; // r9d
  __int64 v95; // r8
  __int64 v96; // rcx
  void *v97; // r10
  hkClass *v98; // r8
  hkStreamWriter *v99; // rax
  int v100; // [rsp+28h] [rbp-D8h]
  int v101; // [rsp+28h] [rbp-D8h]
  int v102; // [rsp+50h] [rbp-B0h]
  __int64 ArrayMemberSize; // [rsp+50h] [rbp-B0h]
  int v104; // [rsp+50h] [rbp-B0h]
  int v105; // [rsp+50h] [rbp-B0h]
  int v106; // [rsp+50h] [rbp-B0h]
  int j; // [rsp+50h] [rbp-B0h]
  unsigned int v108; // [rsp+50h] [rbp-B0h]
  int n; // [rsp+50h] [rbp-B0h]
  int ii; // [rsp+50h] [rbp-B0h]
  int m; // [rsp+50h] [rbp-B0h]
  int v112; // [rsp+50h] [rbp-B0h]
  __int64 v113; // [rsp+58h] [rbp-A8h]
  int v114; // [rsp+58h] [rbp-A8h]
  int v115; // [rsp+58h] [rbp-A8h]
  int v116; // [rsp+58h] [rbp-A8h]
  int v117; // [rsp+58h] [rbp-A8h]
  int v118; // [rsp+58h] [rbp-A8h]
  unsigned int v119; // [rsp+58h] [rbp-A8h]
  int k; // [rsp+58h] [rbp-A8h]
  int v121; // [rsp+58h] [rbp-A8h]
  unsigned int v122; // [rsp+58h] [rbp-A8h]
  int v123; // [rsp+58h] [rbp-A8h]
  int v124; // [rsp+58h] [rbp-A8h]
  hkClassMember *v125; // [rsp+60h] [rbp-A0h]
  hkClass *v126; // [rsp+60h] [rbp-A0h]
  hkClassMember *v127; // [rsp+60h] [rbp-A0h]
  char *v128; // [rsp+60h] [rbp-A0h]
  hkClassMember *v129; // [rsp+60h] [rbp-A0h]
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
  __int64 toAddrd; // [rsp+78h] [rbp-88h]
  int memberIndex; // [rsp+80h] [rbp-80h]
  int NumMembers; // [rsp+84h] [rbp-7Ch]
  __int64 ptr[2]; // [rsp+88h] [rbp-78h] BYREF
  hkResult v149; // [rsp+98h] [rbp-68h] BYREF
  __int64 v150; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v151; // [rsp+A8h] [rbp-58h] BYREF
  hkResult v152; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v153; // [rsp+B8h] [rbp-48h]
  __int64 buf; // [rsp+C0h] [rbp-40h] BYREF
  hkResult result; // [rsp+C8h] [rbp-38h] BYREF
  hkResult v156; // [rsp+CCh] [rbp-34h] BYREF
  hkErrStream v157; // [rsp+D0h] [rbp-30h] BYREF
  hkResult v158; // [rsp+E8h] [rbp-18h] BYREF
  char description[544]; // [rsp+F0h] [rbp-10h] BYREF
  int levela; // [rsp+368h] [rbp+268h]

  v10 = level;
  v11 = klassOut;
  v12 = dataOut;
  v13 = this;
  if ( !level )
  {
    LODWORD(ptr[0]) = classStart;
    toAddr = hkClass::getName(klassOut);
    if ( fixups->m_finish.m_size == (fixups->m_finish.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&fixups->m_finish.m_data, 16);
    v14 = &fixups->m_finish.m_data[fixups->m_finish.m_size];
    *(_QWORD *)&v14->m_fromOffset = ptr[0];
    v14->m_className = toAddr;
    ++fixups->m_finish.m_size;
    v11 = klassOut;
    v10 = 0;
  }
  memberIndex = 0;
  levela = v10 + 1;
  NumMembers = hkClass::getNumMembers(v11);
  if ( NumMembers > 0 )
  {
    for ( i = 0; i < NumMembers; memberIndex = i )
    {
      v16 = hkClass::getMember(v11, i);
      member = v16;
      if ( klassIn == v11 )
      {
        MemberByName = v16;
        v125 = v16;
      }
      else
      {
        MemberByName = hkClass::getMemberByName(klassIn, v16->m_name);
        v125 = MemberByName;
        v16 = member;
      }
      if ( MemberByName )
      {
        v18 = &dataIn[MemberByName->m_offset];
        if ( ((unsigned int (__fastcall *)(hkObjectCopier *, hkClassMember *, hkClassMember *))v13->vfptr[2].__vecDelDtor)(
               v13,
               MemberByName,
               v16)
          && ((v13->m_flags.m_storage & 2) == 0 || (member->m_flags.m_storage & 0x400) == 0) )
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
              goto $LN3_221;
            case 0x13:
              hkErrStream::hkErrStream(&v157, description, 512);
              hkOstream::operator<<(&v157, "TYPE_ZERO should not occur.");
              if ( (unsigned int)hkError::messageError(0x641E3E05u, description, "Copier\\hkObjectCopier.cpp", 1047) )
                __debugbreak();
              goto LABEL_106;
            case 0x14:
              v19 = objectCopier_calcCArraySize(member);
              v20 = objectCopier_calcCArraySize(v125);
              v21 = (hkClass *)`anonymous namespace::min2<int>(v20, v19);
              v22 = objectCopier_calcCArraySize(v125);
              SizeInBytes = hkClassMember::getSizeInBytes(v125);
              v24 = 0;
              v102 = 0;
              klassIna = v21;
              v25 = SizeInBytes / v22;
              v113 = v25;
              if ( (int)v21 <= 0 )
              {
                v13 = this;
                goto LABEL_111;
              }
              do
              {
                v13 = this;
                toAddra = *(char **)v18;
                if ( *(_QWORD *)v18 )
                {
                  v26 = member->m_offset + v24 * (unsigned __int8)this->m_layoutOut.m_rules.m_bytesInPointer;
                  m_storage = member->m_subtype.m_storage;
                  if ( m_storage == 2 )
                  {
                    v28 = v26 + classStart;
                    v12 = dataOut;
                    saveCstring(&v152, *(const char **)v18, v28, extrasStart, dataOut, fixups);
                    v24 = v102;
                  }
                  else
                  {
                    if ( m_storage )
                    {
                      Class = hkClassMember::getClass(v125);
                      hkRelocationInfo::addGlobal(fixups, v26 + classStart, toAddra, Class, 0);
                      v24 = v102;
                    }
                    v12 = dataOut;
                  }
                  v25 = v113;
                }
                else
                {
                  v12 = dataOut;
                }
                ++v24;
                v18 += v25;
                v30 = klassIna == (hkClass *)1;
                klassIna = (hkClass *)((char *)klassIna - 1);
                v102 = v24;
              }
              while ( !v30 );
              goto $LN3_221;
            case 0x16:
            case 0x17:
            case 0x1A:
              if ( !*((_DWORD *)v18 + 2) )
                goto $LN3_221;
              v31 = member->m_subtype.m_storage;
              switch ( v31 )
              {
                case 0:
                  break;
                case 20:
                  StreamWriter = hkOArchive::getStreamWriter(v12);
                  m_offset = member->m_offset;
                  v34 = ((__int64 (__fastcall *)(hkStreamWriter *))StreamWriter->vfptr[4].__vecDelDtor)(StreamWriter);
                  hkRelocationInfo::addLocal(fixups, m_offset + classStart, extrasStart + v34);
                  buf = 0i64;
                  v114 = 0;
                  ArrayMemberSize = (int)hkClassMember::getArrayMemberSize(v125);
                  if ( *((int *)v18 + 2) <= 0 )
                    goto LABEL_111;
                  v35 = 0i64;
                  v12 = dataOut;
                  klassInb = 0i64;
                  do
                  {
                    toAddrb = *(void **)&v35[*(_QWORD *)v18];
                    if ( toAddrb && member->m_subtype.m_storage )
                    {
                      v36 = hkOArchive::getStreamWriter(v12);
                      v37 = hkClassMember::getClass(v125);
                      v38 = ((__int64 (__fastcall *)(hkStreamWriter *))v36->vfptr[4].__vecDelDtor)(v36);
                      hkRelocationInfo::addGlobal(fixups, extrasStart + v38, toAddrb, v37, 0);
                      v13 = this;
                      v12 = dataOut;
                    }
                    hkOArchive::writeRaw(v12, &buf, (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer);
                    v35 = (char *)klassInb + ArrayMemberSize;
                    klassInb = (hkClass *)((char *)klassInb + ArrayMemberSize);
                    ++v114;
                  }
                  while ( v114 < *((_DWORD *)v18 + 2) );
                  break;
                case 29:
                  v39 = hkOArchive::getStreamWriter(v12);
                  v40 = member->m_offset;
                  v41 = ((__int64 (__fastcall *)(hkStreamWriter *))v39->vfptr[4].__vecDelDtor)(v39);
                  hkRelocationInfo::addLocal(fixups, v40 + classStart, extrasStart + v41);
                  v12 = dataOut;
                  v150 = 0i64;
                  v42 = hkOArchive::getStreamWriter(dataOut);
                  v43 = ((__int64 (__fastcall *)(hkStreamWriter *))v42->vfptr[4].__vecDelDtor)(v42);
                  v44 = extrasStart;
                  v45 = extrasStart + v43;
                  v115 = 0;
                  v104 = extrasStart + v43;
                  if ( *((int *)v18 + 2) > 0 )
                  {
                    do
                    {
                      hkOArchive::writeRaw(dataOut, &v150, (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer);
                      ++v115;
                    }
                    while ( v115 < *((_DWORD *)v18 + 2) );
                    v45 = v104;
                    v44 = extrasStart;
                  }
                  v46 = 0;
                  v116 = 0;
                  if ( *((int *)v18 + 2) > 0 )
                  {
                    v47 = 0i64;
                    klassInc = 0i64;
                    do
                    {
                      if ( *(const char **)((char *)&v47->m_name + *(_QWORD *)v18) )
                      {
                        saveCstring(
                          &v156,
                          *(const char **)((char *)&v47->m_name + *(_QWORD *)v18),
                          v45 + v46 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                          v44,
                          dataOut,
                          fixups);
                        v46 = v116;
                        v47 = klassInc;
                      }
                      v45 = v104;
                      v44 = extrasStart;
                      ++v46;
                      v47 = (hkClass *)((char *)v47 + 8);
                      v116 = v46;
                      klassInc = v47;
                    }
                    while ( v46 < *((_DWORD *)v18 + 2) );
                  }
                  break;
                case 33:
                  v48 = hkOArchive::getStreamWriter(v12);
                  v49 = member->m_offset;
                  v50 = ((__int64 (__fastcall *)(hkStreamWriter *))v48->vfptr[4].__vecDelDtor)(v48);
                  hkRelocationInfo::addLocal(fixups, v49 + classStart, extrasStart + v50);
                  v12 = dataOut;
                  v151 = 0i64;
                  v51 = hkOArchive::getStreamWriter(dataOut);
                  v52 = ((__int64 (__fastcall *)(hkStreamWriter *))v51->vfptr[4].__vecDelDtor)(v51);
                  v53 = extrasStart;
                  v54 = extrasStart + v52;
                  v117 = 0;
                  v105 = extrasStart + v52;
                  if ( *((int *)v18 + 2) > 0 )
                  {
                    do
                    {
                      hkOArchive::writeRaw(dataOut, &v151, (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer);
                      ++v117;
                    }
                    while ( v117 < *((_DWORD *)v18 + 2) );
                    v54 = v105;
                    v53 = extrasStart;
                  }
                  v55 = 0;
                  v118 = 0;
                  if ( *((int *)v18 + 2) > 0 )
                  {
                    p_m_parent = 0i64;
                    klassInd = 0i64;
                    do
                    {
                      v57 = (const char *)(*(unsigned __int64 *)((char *)p_m_parent + *(_QWORD *)v18) & 0xFFFFFFFFFFFFFFFEui64);
                      if ( v57 )
                      {
                        saveCstring(
                          &v149,
                          v57,
                          v54 + v55 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                          v53,
                          dataOut,
                          fixups);
                        v55 = v118;
                      }
                      v54 = v105;
                      v53 = extrasStart;
                      ++v55;
                      p_m_parent = &klassInd->m_parent;
                      klassInd = (hkClass *)((char *)klassInd + 8);
                      v118 = v55;
                    }
                    while ( v55 < *((_DWORD *)v18 + 2) );
                  }
                  break;
                case 25:
                  v58 = hkOArchive::getStreamWriter(v12);
                  v119 = extrasStart + ((__int64 (__fastcall *)(hkStreamWriter *))v58->vfptr[4].__vecDelDtor)(v58);
                  hkRelocationInfo::addLocal(fixups, classStart + member->m_offset, v119);
                  v126 = hkClassMember::getClass(v125);
                  v59 = hkClassMember::getClass(member);
                  membera = v59;
                  v60 = v126;
                  if ( v126 && v59 )
                  {
                    v106 = 0;
                    klassIne = *(const char **)v18;
                    if ( *((int *)v18 + 2) > 0 )
                    {
                      while ( 1 )
                      {
                        ObjectSize = hkClass::getObjectSize(v60);
                        hkObjectCopier::saveBody(
                          v13,
                          (char *)&klassIne[v106 * ObjectSize],
                          v126,
                          v12,
                          membera,
                          zeroArray);
                        if ( ++v106 >= *((_DWORD *)v18 + 2) )
                          break;
                        v60 = v126;
                      }
                      v59 = membera;
                    }
                    for ( j = 0; j < *((_DWORD *)v18 + 2); ++j )
                    {
                      v62 = v119 + j * hkClass::getObjectSize(v59);
                      v63 = hkClass::getObjectSize(v126);
                      v100 = v62;
                      v12 = dataOut;
                      hkObjectCopier::saveExtras(
                        v13,
                        &klassIne[j * v63],
                        v126,
                        dataOut,
                        membera,
                        v100,
                        extrasStart,
                        fixups,
                        zeroArray,
                        levela);
                      v59 = membera;
                    }
                  }
                  break;
                case 28:
                  v64 = hkOArchive::getStreamWriter(v12);
                  v108 = extrasStart + ((__int64 (__fastcall *)(hkStreamWriter *))v64->vfptr[4].__vecDelDtor)(v64);
                  hkRelocationInfo::addLocal(fixups, classStart + member->m_offset, v108);
                  for ( k = 0; k < *((_DWORD *)v18 + 2); ++k )
                  {
                    m_bytesInPointer = (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer;
                    ptr[0] = 0i64;
                    ptr[1] = 0i64;
                    hkOArchive::writeArrayGeneric(v12, (char *)ptr, m_bytesInPointer, 2);
                  }
                  v66 = 0;
                  v121 = 0;
                  if ( *((int *)v18 + 2) > 0 )
                  {
                    v67 = 0i64;
                    v127 = 0i64;
                    do
                    {
                      v68 = *(void **)((char *)&v67->m_name + *(_QWORD *)v18);
                      v69 = 2 * v66 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer;
                      if ( v68 )
                      {
                        hkRelocationInfo::addGlobal(
                          fixups,
                          v69 + v108,
                          v68,
                          *(hkClass **)((char *)&v67->m_class + *(_QWORD *)v18),
                          0);
                        v67 = v127;
                      }
                      v70 = *(hkClass **)((char *)&v67->m_class + *(_QWORD *)v18);
                      if ( v70 )
                      {
                        hkRelocationInfo::addGlobal(
                          fixups,
                          v108 + v69 + (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                          v70,
                          &hkClassClass,
                          0);
                        v67 = v127;
                      }
                      v67 = (hkClassMember *)((char *)v67 + 16);
                      v66 = v121 + 1;
                      v127 = v67;
                      v121 = v66;
                    }
                    while ( v66 < *((_DWORD *)v18 + 2) );
LABEL_111:
                    v12 = dataOut;
                  }
                  break;
                default:
                  v71 = hkOArchive::getStreamWriter(v12);
                  v72 = member->m_offset;
                  v73 = ((__int64 (__fastcall *)(hkStreamWriter *))v71->vfptr[4].__vecDelDtor)(v71);
                  hkRelocationInfo::addLocal(fixups, v72 + classStart, extrasStart + v73);
                  v74 = member->m_subtype.m_storage;
                  if ( v74 == 30 )
                  {
                    v12 = dataOut;
                    writeUlongArray(
                      dataOut,
                      (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                      *((_DWORD *)v18 + 2),
                      *(const void **)v18);
                  }
                  else
                  {
                    v75 = v74;
                    v76 = hkClassMember::getArrayMemberSize(member);
                    v77 = v75;
                    v12 = dataOut;
                    writePodArray(dataOut, v77, v76, *((_DWORD *)v18 + 2), *(const void **)v18);
                  }
                  break;
              }
$LN3_221:
              v99 = hkOArchive::getStreamWriter(v12);
              objectCopierPadUp(v99, 16);
              break;
            case 0x19:
              klassIng = hkClassMember::getClass(v125);
              v82 = hkClassMember::getClass(member);
              toAddrc = v82;
              if ( !klassIng || !v82 )
                goto $LN3_221;
              v123 = classStart + member->m_offset;
              v83 = objectCopier_calcCArraySize(v125);
              v84 = objectCopier_calcCArraySize(member);
              v85 = `anonymous namespace::min2<int>(v83, v84);
              v86 = 0;
              memberb = v85;
              for ( m = 0; v86 < memberb; m = v86 )
              {
                v87 = &v18[(int)(v86 * hkClass::getObjectSize(klassIng))];
                v88 = hkClass::getObjectSize(toAddrc);
                hkObjectCopier::saveExtras(
                  v13,
                  v87,
                  klassIng,
                  dataOut,
                  toAddrc,
                  v123 + m * v88,
                  extrasStart,
                  fixups,
                  zeroArray,
                  levela);
                v86 = m + 1;
              }
              goto LABEL_111;
            case 0x1B:
              v128 = *(char **)v18;
              if ( *(_QWORD *)v18 )
              {
                hkRelocationInfo::addGlobal(fixups, classStart + member->m_offset, *(void **)v18, &hkClassClass, 1u);
                v78 = hkOArchive::getStreamWriter(v12);
                v122 = extrasStart + ((__int64 (__fastcall *)(hkStreamWriter *))v78->vfptr[4].__vecDelDtor)(v78);
                hkRelocationInfo::addLocal(
                  fixups,
                  classStart + (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer + member->m_offset,
                  v122);
                klassInf = (hkClass *)*((_QWORD *)v18 + 1);
                for ( n = 0; n < *((_DWORD *)v18 + 4); ++n )
                {
                  v79 = hkClass::getObjectSize((hkClass *)v128);
                  hkObjectCopier::saveBody(
                    v13,
                    (char *)klassInf + n * v79,
                    (hkClass *)v128,
                    v12,
                    (hkClass *)v128,
                    zeroArray);
                }
                for ( ii = 0; ii < *((_DWORD *)v18 + 4); ++ii )
                {
                  v80 = v122 + ii * hkClass::getObjectSize((hkClass *)v128);
                  v81 = hkClass::getObjectSize((hkClass *)v128);
                  v101 = v80;
                  v12 = dataOut;
                  hkObjectCopier::saveExtras(
                    v13,
                    (char *)klassInf + ii * v81,
                    (hkClass *)v128,
                    dataOut,
                    (hkClass *)v128,
                    v101,
                    extrasStart,
                    fixups,
                    zeroArray,
                    levela);
                }
              }
              goto $LN3_221;
            case 0x1C:
              v89 = objectCopier_calcCArraySize(v125);
              v90 = objectCopier_calcCArraySize(member);
              v91 = `anonymous namespace::min2<int>(v89, v90);
              v92 = 0;
              v93 = 0i64;
              v112 = 0;
              klassInh = 0i64;
              v153 = v91;
              if ( v91 > 0 )
              {
                v94 = 1;
                v124 = 1;
                v95 = 1i64;
                toAddrd = 1i64;
                do
                {
                  v96 = (unsigned __int8)v13->m_layoutIn.m_rules.m_bytesInPointer;
                  v97 = *(void **)&v18[2 * v96 * v93];
                  v98 = *(hkClass **)&v18[v95 * v96];
                  v129 = (hkClassMember *)v98;
                  if ( v97 )
                  {
                    hkRelocationInfo::addGlobal(
                      fixups,
                      member->m_offset
                    + classStart
                    + 2 * v92 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer,
                      v97,
                      v98,
                      0);
                    v93 = (__int64)klassInh;
                    v98 = (hkClass *)v129;
                    v94 = v124;
                    v92 = v112;
                  }
                  if ( v98 )
                  {
                    hkRelocationInfo::addGlobal(
                      fixups,
                      classStart + v94 * (unsigned __int8)v13->m_layoutOut.m_rules.m_bytesInPointer + member->m_offset,
                      v98,
                      &hkClassClass,
                      0);
                    v93 = (__int64)klassInh;
                    v94 = v124;
                    v92 = v112;
                  }
                  ++v93;
                  ++v92;
                  v95 = toAddrd + 2;
                  v94 += 2;
                  v112 = v92;
                  toAddrd += 2i64;
                  v124 = v94;
                  klassInh = (hkClass *)v93;
                }
                while ( v93 < v153 );
              }
              goto LABEL_111;
            case 0x1D:
              if ( *(_QWORD *)v18 )
                saveCstring(&result, *(const char **)v18, classStart + member->m_offset, extrasStart, v12, fixups);
              goto $LN3_221;
            case 0x21:
              if ( (*(_QWORD *)v18 & 0xFFFFFFFFFFFFFFFEui64) != 0 )
                saveCstring(
                  &v158,
                  (const char *)(*(_QWORD *)v18 & 0xFFFFFFFFFFFFFFFEui64),
                  classStart + member->m_offset,
                  extrasStart,
                  v12,
                  fixups);
              goto $LN3_221;
            default:
              hkErrStream::hkErrStream(&v157, description, 512);
              hkOstream::operator<<(&v157, "Unknown class member found during write of data.");
              if ( (unsigned int)hkError::messageError(0x641E3E05u, description, "Copier\\hkObjectCopier.cpp", 1052) )
                __debugbreak();
LABEL_106:
              hkOstream::~hkOstream(&v157);
              goto $LN3_221;
          }
        }
        v11 = klassOut;
      }
      i = memberIndex + 1;
    }
  }
}          }
        }
        v11 = klassOut;
      }
      i = memberIndex + 1;
    }
  }
}

// File Line: 1062
// RVA: 0xE68BC0
hkResult *__fastcall hkObjectCopier::copyObject(
        hkObjectCopier *this,
        hkResult *result,
        const void *dataIn,
        hkClass *klassIn,
        hkStreamWriter *dataOut,
        hkClass *klassOut,
        hkRelocationInfo *reloc)
{
  hkLifoAllocator *Value; // rax
  char *m_cur; // rdx
  char *v13; // rcx
  hkLifoAllocator *v14; // rax
  char *v15; // rcx
  char *v16; // rdx
  hkArrayBase<char> *p_array; // rdx
  int v18; // r9d
  hkStreamWriter *v19; // rsi
  int v20; // eax
  hkClass *v21; // rbx
  int v22; // edi
  int extrasStart; // eax
  hkArrayBase<char> *m_arr; // rbx
  _QWORD **v25; // rax
  char *m_localMemory; // rdi
  int m_size; // eax
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // r8d
  unsigned int v31; // eax
  char *v32; // rdi
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // r8d
  char *array; // [rsp+50h] [rbp-71h] BYREF
  unsigned int v38; // [rsp+58h] [rbp-69h]
  int v39; // [rsp+5Ch] [rbp-65h]
  void *p; // [rsp+60h] [rbp-61h]
  int v41; // [rsp+68h] [rbp-59h]
  hkLocalArray<char> zeroArray; // [rsp+70h] [rbp-51h] BYREF
  hkArrayStreamWriter sw; // [rsp+90h] [rbp-31h] BYREF
  hkOArchive v44; // [rsp+B8h] [rbp-9h] BYREF
  hkResult resulta; // [rsp+110h] [rbp+4Fh] BYREF

  array = 0i64;
  v38 = 0;
  v39 = 0x80000000;
  v41 = 1024;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v13 = m_cur + 1024;
  if ( Value->m_slabSize < 1024 || v13 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 1024);
  else
    Value->m_cur = v13;
  array = m_cur;
  v39 = -2147482624;
  p = m_cur;
  zeroArray.m_data = 0i64;
  zeroArray.m_size = 0;
  zeroArray.m_capacityAndFlags = 0x80000000;
  zeroArray.m_initialCapacity = 16;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (char *)v14->m_cur;
  v16 = v15 + 128;
  if ( v14->m_slabSize < 128 || v16 > v14->m_end )
    v15 = (char *)hkLifoAllocator::allocateFromNewSlab(v14, 128);
  else
    v14->m_cur = v16;
  zeroArray.m_data = v15;
  zeroArray.m_localMemory = v15;
  sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  p_array = (hkArrayBase<char> *)&array;
  v18 = v38 + 1;
  sw.m_offset = v38;
  zeroArray.m_capacityAndFlags = -2147483632;
  *(_DWORD *)&sw.m_memSizeAndFlags = 0x1FFFF;
  sw.m_arr = (hkArrayBase<char> *)&array;
  sw.m_allocator = &hkContainerHeapAllocator::s_alloc;
  sw.m_ownerShip = ARRAY_BORROW;
  if ( (v39 & 0x3FFFFFFF) < (int)(v38 + 1) )
  {
    if ( v18 < 2 * (v39 & 0x3FFFFFFF) )
      v18 = 2 * (v39 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v18, 1);
    p_array = sw.m_arr;
  }
  p_array->m_data[p_array->m_size] = 0;
  hkOArchive::hkOArchive(&v44, &sw, this->m_byteSwap);
  v19 = dataOut;
  v20 = ((__int64 (__fastcall *)(hkStreamWriter *))dataOut->vfptr[4].__vecDelDtor)(dataOut);
  v21 = klassOut;
  v22 = v20;
  hkObjectCopier::saveBody(this, dataIn, klassIn, &v44, klassOut, &zeroArray);
  ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v19->vfptr[2].__vecDelDtor)(v19, array, v38);
  objectCopierPadUp(v19, 16);
  hkArrayStreamWriter::clear(&sw);
  extrasStart = ((__int64 (__fastcall *)(hkStreamWriter *))v19->vfptr[4].__vecDelDtor)(v19);
  hkObjectCopier::saveExtras(this, dataIn, klassIn, &v44, v21, v22, extrasStart, reloc, &zeroArray, 0);
  ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v19->vfptr[2].__vecDelDtor)(v19, array, v38);
  objectCopierPadUp(v19, 16);
  hkArrayStreamWriter::clear(&sw);
  result->m_enum = hkOArchive::isOk(&v44, (hkBool *)&dataOut)->m_bool == 0;
  hkOArchive::~hkOArchive(&v44);
  sw.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  if ( sw.m_ownerShip == ARRAY_TAKE )
  {
    m_arr = sw.m_arr;
    if ( sw.m_arr )
    {
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkArrayBase<char> *, __int64))(*v25[11] + 16i64))(v25[11], m_arr, 16i64);
    }
  }
  m_localMemory = zeroArray.m_localMemory;
  sw.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  m_size = zeroArray.m_size;
  if ( zeroArray.m_localMemory == zeroArray.m_data )
    m_size = 0;
  v28 = (zeroArray.m_initialCapacity + 127) & 0xFFFFFF80;
  zeroArray.m_size = m_size;
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v28 + 15) & 0xFFFFFFF0;
  if ( v28 > v29->m_slabSize || &m_localMemory[v30] != v29->m_cur || v29->m_firstNonLifoEnd == m_localMemory )
    hkLifoAllocator::slowBlockFree(v29, m_localMemory, v30);
  else
    v29->m_cur = m_localMemory;
  zeroArray.m_size = 0;
  if ( zeroArray.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      zeroArray.m_data,
      zeroArray.m_capacityAndFlags & 0x3FFFFFFF);
  v31 = v38;
  v32 = (char *)p;
  zeroArray.m_data = 0i64;
  if ( p == array )
    v31 = 0;
  zeroArray.m_capacityAndFlags = 0x80000000;
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v39 & 0x3FFFFFFF);
  return result;
}

