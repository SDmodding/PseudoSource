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
void __fastcall hkStructureLayout::hkStructureLayout(hkStructureLayout *this, hkStructureLayout *rules)
{
  *this = *rules;
}

// File Line: 127
// RVA: 0xE395B0
int __fastcall computeMemberSize(
        hkClassMember *member,
        hkStructureLayout::LayoutRules *rules,
        hkClassMember::Type type)
{
  int v3; // ebx
  int result; // eax
  int m_bytesInPointer; // ebx
  hkClass *StructClass; // rax
  hkErrStream v8; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  v3 = 0;
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
      m_bytesInPointer = (unsigned __int8)rules->m_bytesInPointer;
      goto LABEL_4;
    case 22:
      v3 = 4;
      goto $LN9_166;
    case 23:
      goto $LN3_202;
    case 25:
      StructClass = hkClassMember::getStructClass(member);
      m_bytesInPointer = hkClass::getObjectSize(StructClass);
LABEL_4:
      if ( (unsigned int)hkClassMember::getCstyleArraySize(member) )
        return hkClassMember::getCstyleArraySize(member) * m_bytesInPointer;
      else
        return m_bytesInPointer;
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
      hkErrStream::hkErrStream(&v8, buf, 512);
      hkOstream::operator<<(&v8, "Unknown class member type in structureLayout::getMemberSize().");
      if ( (unsigned int)hkError::messageError(0x50A18B58u, buf, "Util\\hkStructureLayout.cpp", 211) )
        __debugbreak();
      hkOstream::~hkOstream(&v8);
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
  int Alignment; // ebx
  hkClassMember *v4; // rdi
  int v6; // esi
  hkClassMember *v7; // rax
  int LayoutAlignment; // eax
  int v9; // ecx
  int v11; // eax
  hkClass *StructClass; // [rsp+58h] [rbp+20h]

  Alignment = -1;
  v4 = member;
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
      Alignment = hkClassMember::getAlignment(member);
      break;
    case 19:
      Alignment = getLayoutAlignment(
                    member,
                    (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage,
                    bytesInPointer);
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
      Alignment = bytesInPointer;
      break;
    case 25:
      Alignment = 1;
      v6 = 0;
      StructClass = hkClassMember::getStructClass(member);
      if ( (int)hkClass::getNumMembers(StructClass) > 0 )
      {
        do
        {
          v7 = hkClass::getMember(StructClass, v6);
          LayoutAlignment = getLayoutAlignment(
                              v7,
                              (hkClassMember::Type)(unsigned __int8)v7->m_type.m_storage,
                              bytesInPointer);
          if ( LayoutAlignment > Alignment )
            Alignment = LayoutAlignment;
          ++v6;
        }
        while ( v6 < (int)hkClass::getNumMembers(StructClass) );
        v4 = member;
      }
      break;
    default:
      break;
  }
  v9 = v4->m_flags.m_storage & 0x980;
  if ( (v4->m_flags.m_storage & 0x980) == 0 )
    return (unsigned int)Alignment;
  if ( v9 != 2048 )
  {
    v11 = 8;
    if ( v9 == 256 )
      v11 = 16;
    if ( v11 > Alignment )
      return (unsigned int)v11;
    return (unsigned int)Alignment;
  }
  if ( Alignment < 32 )
    return 32;
  return (unsigned int)Alignment;
}

// File Line: 305
// RVA: 0xE39920
void __fastcall s_setOffset(hkClassMember *member, unsigned __int16 currentOffset)
{
  member->m_offset = currentOffset;
}

// File Line: 314
// RVA: 0xE39930
void __fastcall retargetClassInplace(
        hkClass *topLevelClass,
        hkStructureLayout::LayoutRules *rules,
        hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *classesDone,
        unsigned int recurse)
{
  hkClass *Parent; // rbx
  int v7; // edi
  hkClassMember *Member; // rax
  hkClassMember *v9; // rsi
  hkClass *StructClass; // rax
  int Key; // eax
  hkClass *v12; // rax
  int m_bytesInPointer; // ebp
  int v14; // ebx
  __int64 v15; // rcx
  int v16; // edi
  int v17; // esi
  hkClass *v18; // rsi
  int v19; // esi
  hkClassMember *DeclaredMember; // rsi
  int LayoutAlignment; // eax
  unsigned int v22; // ecx
  int v23; // eax
  int v24; // eax
  hkClass *v25; // [rsp+30h] [rbp-48h]
  int v26; // [rsp+30h] [rbp-48h]
  __int64 v27; // [rsp+38h] [rbp-40h]
  hkArrayBase<hkClass *> array; // [rsp+40h] [rbp-38h] BYREF
  int NumMembers; // [rsp+80h] [rbp+8h]
  int v30; // [rsp+80h] [rbp+8h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *p_m_map; // [rsp+90h] [rbp+18h] BYREF
  unsigned int recursea; // [rsp+98h] [rbp+20h] BYREF

  recursea = recurse;
  p_m_map = &classesDone->m_map;
  Parent = topLevelClass;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &classesDone->m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)topLevelClass,
    0i64);
  if ( recurse )
  {
    v7 = 0;
    NumMembers = hkClass::getNumMembers(Parent);
    if ( NumMembers > 0 )
    {
      do
      {
        Member = hkClass::getMember(Parent, v7);
        v9 = Member;
        if ( Member->m_class )
        {
          StructClass = hkClassMember::getStructClass(Member);
          Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                p_m_map,
                                (unsigned __int64)StructClass);
          if ( Key > p_m_map->m_hashMod )
          {
            v12 = hkClassMember::getStructClass(v9);
            retargetClassInplace(
              v12,
              rules,
              (hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *)p_m_map,
              recursea);
          }
        }
        ++v7;
      }
      while ( v7 < NumMembers );
    }
  }
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve((hkResult *)&recursea, &hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, 16, 8);
  for ( ; Parent; Parent = hkClass::getParent(Parent) )
  {
    p_m_map = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)Parent;
    hkArrayBase<hkClass *>::_insertAt(&array, &hkContainerTempAllocator::s_alloc, 0, (hkProcess *const *)&p_m_map);
  }
  m_bytesInPointer = (unsigned __int8)rules->m_bytesInPointer;
  v14 = 0;
  v15 = 0i64;
  v30 = m_bytesInPointer;
  v16 = 1;
  LODWORD(p_m_map) = 0;
  v27 = 0i64;
  if ( array.m_size > 0 )
  {
    do
    {
      v17 = 0;
      v25 = array.m_data[v15];
      if ( (int)hkClass::getNumDeclaredInterfaces(v25) > 0 )
      {
        do
        {
          if ( v14 % m_bytesInPointer )
            v14 += m_bytesInPointer - v14 % m_bytesInPointer;
          v14 += m_bytesInPointer;
          if ( m_bytesInPointer > v16 )
            v16 = m_bytesInPointer;
          ++v17;
        }
        while ( v17 < (int)hkClass::getNumDeclaredInterfaces(v25) );
      }
      v18 = v25;
      recursea = 0;
      if ( (int)hkClass::getNumDeclaredMembers(v25) > 0 )
      {
        v19 = recursea;
        do
        {
          DeclaredMember = hkClass::getDeclaredMember(v25, v19);
          if ( !v14 && v27 && !rules->m_emptyBaseClassOptimization )
            v14 = 1;
          LayoutAlignment = getLayoutAlignment(
                              DeclaredMember,
                              (hkClassMember::Type)(unsigned __int8)DeclaredMember->m_type.m_storage,
                              (unsigned __int8)rules->m_bytesInPointer);
          if ( LayoutAlignment > v16 )
            v16 = LayoutAlignment;
          if ( v14 % LayoutAlignment )
            v14 += LayoutAlignment - v14 % LayoutAlignment;
          if ( DeclaredMember->m_offset != v14 )
            s_setOffset(DeclaredMember, v14);
          v14 += computeMemberSize(
                   DeclaredMember,
                   rules,
                   (hkClassMember::Type)(unsigned __int8)DeclaredMember->m_type.m_storage);
          v19 = ++recursea;
        }
        while ( v19 < (int)hkClass::getNumDeclaredMembers(v25) );
        m_bytesInPointer = v30;
        v18 = v25;
      }
      v22 = v14;
      recursea = v14;
      if ( v14 % v16 )
      {
        v22 = v14 + v16 - v14 % v16;
        recursea = v22;
      }
      v23 = 1;
      if ( v22 )
        v23 = v22;
      v26 = v23;
      if ( (unsigned int)hkClass::getObjectSize(v18) != v23 )
        hkClass::setObjectSize(v18, v26);
      v24 = (int)p_m_map;
      if ( !rules->m_reusePaddingOptimization )
        v14 = recursea;
      v15 = v27 + 1;
      LODWORD(p_m_map) = (_DWORD)p_m_map + 1;
      ++v27;
    }
    while ( v24 + 1 < array.m_size );
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
}

// File Line: 436
// RVA: 0xE39550
void __fastcall hkStructureLayout::computeMemberOffsetsInplace(
        hkStructureLayout *this,
        hkClass *klass,
        hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *classesDone,
        unsigned int recurse)
{
  if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
              &classesDone->m_map,
              (unsigned __int64)klass) > classesDone->m_map.m_hashMod )
    retargetClassInplace(klass, &this->m_rules, classesDone, recurse);
}

