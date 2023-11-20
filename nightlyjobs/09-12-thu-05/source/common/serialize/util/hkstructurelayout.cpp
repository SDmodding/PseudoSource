// File Line: 70
// RVA: 0x15D89D0
void dynamic_initializer_for__hkStructureLayout::HostLayoutRules__()
{
  hkStructureLayout::HostLayoutRules.m_littleEndian = endianChecker.i == 1;
}

// File Line: 77
// RVA: 0xE39520
void __fastcall hkStructureLayout::hkStructureLayout(hkStructureLayout *this)
{
  this->m_rules = hkStructureLayout::HostLayoutRules;
}

// File Line: 120
// RVA: 0xE39540
void __fastcall hkStructureLayout::hkStructureLayout(hkStructureLayout *this, hkStructureLayout::LayoutRules *rules)
{
  *this = (hkStructureLayout)*rules;
}

// File Line: 127
// RVA: 0xE395B0
int __fastcall computeMemberSize(hkClassMember *member, hkStructureLayout::LayoutRules *rules, hkClassMember::Type type)
{
  signed int v3; // ebx
  hkClassMember *v4; // rdi
  int result; // eax
  int v6; // ebx
  hkClass *v7; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v3 = 0;
  v4 = member;
  switch ( type )
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
      return hkClassMember::getSizeInBytes(member);
    case 19:
      return computeMemberSize(member, rules, (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage);
    case 20:
    case 21:
    case 29:
    case 30:
    case 33:
      v6 = (unsigned __int8)rules->m_bytesInPointer;
      goto LABEL_4;
    case 22:
      v3 = 4;
      goto $LN9_166;
    case 23:
      goto $LN3_202;
    case 25:
      v7 = hkClassMember::getStructClass(member);
      v6 = hkClass::getObjectSize(v7);
LABEL_4:
      if ( (unsigned int)hkClassMember::getCstyleArraySize(v4) )
        result = (unsigned __int64)hkClassMember::getCstyleArraySize(v4) * v6;
      else
        result = v6;
      break;
    case 26:
$LN9_166:
      result = (unsigned __int8)rules->m_bytesInPointer + 4 + v3;
      break;
    case 27:
      result = 2 * (unsigned __int8)rules->m_bytesInPointer + 4;
      break;
    case 28:
      result = 2 * (unsigned __int8)rules->m_bytesInPointer;
      break;
    case 34:
      result = 4;
      break;
    default:
      hkErrStream::hkErrStream(&v8, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v8.vfptr, "Unknown class member type in structureLayout::getMemberSize().");
      if ( (unsigned int)hkError::messageError(1352764248, &buf, "Util\\hkStructureLayout.cpp", 211) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v8.vfptr);
$LN3_202:
      result = 0;
      break;
  }
  return result;
}

// File Line: 219
// RVA: 0xE397B0
__int64 __fastcall getLayoutAlignment(hkClassMember *member, hkClassMember::Type memType, int bytesInPointer)
{
  int v3; // ebx
  hkClassMember *v4; // rdi
  int v5; // ebp
  int v6; // esi
  hkClassMember *v7; // rax
  int v8; // eax
  int v9; // ecx
  signed int v11; // eax
  hkClassMember *v12; // [rsp+40h] [rbp+8h]
  hkClass *v13; // [rsp+58h] [rbp+20h]

  v12 = member;
  v3 = -1;
  v4 = member;
  v5 = bytesInPointer;
  switch ( memType )
  {
    case 0:
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
    case 34:
      v3 = hkClassMember::getAlignment(member);
      break;
    case 19:
      v3 = getLayoutAlignment(member, (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage, bytesInPointer);
      break;
    case 20:
    case 21:
    case 22:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 33:
      v3 = bytesInPointer;
      break;
    case 25:
      v3 = 1;
      v6 = 0;
      v13 = hkClassMember::getStructClass(member);
      if ( (signed int)hkClass::getNumMembers(v13) > 0 )
      {
        do
        {
          v7 = hkClass::getMember(v13, v6);
          v8 = getLayoutAlignment(v7, (hkClassMember::Type)(unsigned __int8)v7->m_type.m_storage, v5);
          if ( v8 > v3 )
            v3 = v8;
          ++v6;
        }
        while ( v6 < (signed int)hkClass::getNumMembers(v13) );
        v4 = v12;
      }
      break;
    default:
      break;
  }
  v9 = v4->m_flags.m_storage & 0x980;
  if ( !(v4->m_flags.m_storage & 0x980) )
    return (unsigned int)v3;
  if ( v9 != 2048 )
  {
    v11 = 8;
    if ( v9 == 256 )
      v11 = 16;
    if ( v11 > v3 )
      v3 = v11;
    return (unsigned int)v3;
  }
  if ( v3 < 32 )
    v3 = 32;
  return (unsigned int)v3;
}

// File Line: 305
// RVA: 0xE39920
void __fastcall s_setOffset(hkClassMember *member, int currentOffset)
{
  member->m_offset = currentOffset;
}

// File Line: 314
// RVA: 0xE39930
void __fastcall retargetClassInplace(hkClass *topLevelClass, hkStructureLayout::LayoutRules *rules, hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *classesDone, unsigned int recurse)
{
  hkStructureLayout::LayoutRules *v4; // rbp
  unsigned int v5; // edi
  hkClass *v6; // rbx
  int v7; // edi
  hkClassMember *v8; // rax
  hkClassMember *v9; // rsi
  hkClass *v10; // rax
  int v11; // eax
  hkClass *v12; // rax
  signed int v13; // ebp
  signed int v14; // ebx
  signed __int64 v15; // rcx
  signed int v16; // edi
  signed int v17; // esi
  hkClass *v18; // rsi
  int v19; // esi
  hkClassMember *v20; // rsi
  signed int v21; // eax
  int v22; // ecx
  int v23; // edx
  signed int v24; // eax
  int v25; // eax
  hkClass *v26; // [rsp+30h] [rbp-48h]
  int v27; // [rsp+30h] [rbp-48h]
  __int64 v28; // [rsp+38h] [rbp-40h]
  _QWORD *array; // [rsp+40h] [rbp-38h]
  int v30; // [rsp+48h] [rbp-30h]
  int v31; // [rsp+4Ch] [rbp-2Ch]
  int v32; // [rsp+80h] [rbp+8h]
  signed int v33; // [rsp+80h] [rbp+8h]
  hkStructureLayout::LayoutRules *rulesa; // [rsp+88h] [rbp+10h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v35; // [rsp+90h] [rbp+18h]
  unsigned int recursea; // [rsp+98h] [rbp+20h]

  recursea = recurse;
  v35 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&classesDone->m_map.m_elem;
  rulesa = rules;
  v4 = rules;
  v5 = recurse;
  v6 = topLevelClass;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&classesDone->m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)topLevelClass,
    0i64);
  if ( v5 )
  {
    v7 = 0;
    v32 = hkClass::getNumMembers(v6);
    if ( v32 > 0 )
    {
      do
      {
        v8 = hkClass::getMember(v6, v7);
        v9 = v8;
        if ( v8->m_class )
        {
          v10 = hkClassMember::getStructClass(v8);
          v11 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                    v35,
                                    (unsigned __int64)v10);
          if ( v11 > v35->m_hashMod )
          {
            v12 = hkClassMember::getStructClass(v9);
            retargetClassInplace(v12, v4, (hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *)v35, recursea);
          }
        }
        ++v7;
      }
      while ( v7 < v32 );
    }
  }
  array = 0i64;
  v30 = 0;
  v31 = 2147483648;
  hkArrayUtil::_reserve(
    (hkResult *)&recursea,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    &array,
    16,
    8);
  for ( ; v6; v6 = hkClass::getParent(v6) )
  {
    v35 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v6;
    hkArrayBase<hkClass *>::_insertAt(
      (hkArrayBase<hkClass *> *)&array,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      0,
      (hkClass *const *)&v35);
  }
  v13 = (unsigned __int8)v4->m_bytesInPointer;
  v14 = 0;
  v15 = 0i64;
  v33 = v13;
  v16 = 1;
  LODWORD(v35) = 0;
  v28 = 0i64;
  if ( v30 > 0 )
  {
    do
    {
      v17 = 0;
      v26 = (hkClass *)array[v15];
      if ( (signed int)hkClass::getNumDeclaredInterfaces(v26) > 0 )
      {
        do
        {
          if ( v14 % v13 )
            v14 += v13 - v14 % v13;
          v14 += v13;
          if ( v13 > v16 )
            v16 = v13;
          ++v17;
        }
        while ( v17 < (signed int)hkClass::getNumDeclaredInterfaces(v26) );
      }
      v18 = v26;
      recursea = 0;
      if ( (signed int)hkClass::getNumDeclaredMembers(v26) > 0 )
      {
        v19 = recursea;
        do
        {
          v20 = hkClass::getDeclaredMember(v26, v19);
          if ( !v14 && v28 && !rulesa->m_emptyBaseClassOptimization )
            v14 = 1;
          v21 = getLayoutAlignment(
                  v20,
                  (hkClassMember::Type)(unsigned __int8)v20->m_type.m_storage,
                  (unsigned __int8)rulesa->m_bytesInPointer);
          if ( v21 > v16 )
            v16 = v21;
          if ( v14 % v21 )
            v14 += v21 - v14 % v21;
          if ( v20->m_offset != v14 )
            s_setOffset(v20, v14);
          v14 += computeMemberSize(v20, rulesa, (hkClassMember::Type)(unsigned __int8)v20->m_type.m_storage);
          v19 = ++recursea;
        }
        while ( v19 < (signed int)hkClass::getNumDeclaredMembers(v26) );
        v13 = v33;
        v18 = v26;
      }
      v22 = v14;
      recursea = v14;
      v23 = v14 % v16;
      if ( v14 % v16 )
      {
        v22 = v14 + v16 - v23;
        recursea = v14 + v16 - v23;
      }
      v24 = 1;
      if ( v22 )
        v24 = v22;
      v27 = v24;
      if ( (unsigned int)hkClass::getObjectSize(v18) != v24 )
        hkClass::setObjectSize(v18, v27);
      v25 = (signed int)v35;
      if ( !rulesa->m_reusePaddingOptimization )
        v14 = recursea;
      v15 = v28 + 1;
      LODWORD(v35) = (_DWORD)v35 + 1;
      ++v28;
    }
    while ( v25 + 1 < v30 );
  }
  v30 = 0;
  if ( v31 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v31);
}

// File Line: 436
// RVA: 0xE39550
void __fastcall hkStructureLayout::computeMemberOffsetsInplace(hkStructureLayout *this, hkClass *klass, hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *classesDone, unsigned int recurse)
{
  hkStructureLayout *v4; // rbp
  unsigned int v5; // esi
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v6; // rbx
  hkClass *v7; // rdi

  v4 = this;
  v5 = recurse;
  v6 = classesDone;
  v7 = klass;
  if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&classesDone->m_map.m_elem,
                     (unsigned __int64)klass) > classesDone->m_map.m_hashMod )
    retargetClassInplace(v7, &v4->m_rules, v6, v5);
}

