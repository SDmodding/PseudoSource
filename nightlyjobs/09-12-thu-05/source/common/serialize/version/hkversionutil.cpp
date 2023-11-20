// File Line: 19
// RVA: 0xE39300
const char *__fastcall hkVersionUtil::getCurrentVersion()
{
  return "hk_2013.2.0-r1";
}

// File Line: 24
// RVA: 0xE39310
void __fastcall hkVersionUtil::renameMember(hkVariant *oldObj, const char *oldName, hkVariant *newObj, const char *newName)
{
  hkVariant *v4; // rdi
  const char *v5; // rbx
  hkClassMember *v6; // rax
  int v7; // edi
  const void *v8; // rbx
  void *v9; // rax
  hkBool result; // [rsp+20h] [rbp-38h]
  hkClassMemberAccessor v11; // [rsp+28h] [rbp-30h]
  hkClassMemberAccessor v12; // [rsp+38h] [rbp-20h]

  v4 = newObj;
  v5 = newName;
  hkClassMemberAccessor::hkClassMemberAccessor(&v12, oldObj, oldName);
  hkClassMemberAccessor::hkClassMemberAccessor(&v11, v4, v5);
  if ( hkClassMemberAccessor::isOk(&v12, &result)->m_bool )
  {
    if ( hkClassMemberAccessor::isOk(&v11, &result)->m_bool )
    {
      v6 = hkClassMemberAccessor::getClassMember(&v11);
      v7 = hkClassMember::getSizeInBytes(v6);
      v8 = hkClassMemberAccessor::asRaw(&v12);
      v9 = hkClassMemberAccessor::asRaw(&v11);
      hkString::memCpy(v9, v8, v7);
    }
  }
}

// File Line: 35
// RVA: 0xE393C0
void __fastcall hkVersionUtil::copyDefaults(void *obj, hkClass *oldClass, hkClass *newClass)
{
  void *v3; // rbx
  hkClass *v4; // rdi
  hkClass *v5; // rbp
  int v6; // eax
  int i; // ebx
  hkClassMember *v8; // rsi
  hkResult v9; // [rsp+20h] [rbp-48h]
  hkBufferedStreamWriter v10; // [rsp+28h] [rbp-40h]
  hkResult result; // [rsp+88h] [rbp+20h]

  v3 = obj;
  v4 = newClass;
  v5 = oldClass;
  v6 = hkClass::getObjectSize(newClass);
  hkBufferedStreamWriter::hkBufferedStreamWriter(&v10, v3, v6, 0);
  for ( i = 0; i < (signed int)hkClass::getNumMembers(v4); ++i )
  {
    v8 = hkClass::getMember(v4, i);
    if ( !hkClass::getMemberByName(v5, v8->m_name) )
    {
      hkBufferedStreamWriter::seek(&v10, &result, v8->m_offset, 0);
      hkClass::getDefault(v4, &v9, i, (hkStreamWriter *)&v10.vfptr);
    }
  }
  hkBufferedStreamWriter::~hkBufferedStreamWriter(&v10);
}

// File Line: 49
// RVA: 0xE39490
void __fastcall hkVersionUtil::recomputeClassMemberOffsets(hkClass *const *classes, int classVersion)
{
  hkClass *const *v2; // rdi
  hkClass *v3; // rax
  __int64 v4; // rbx
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> classesDone; // [rsp+20h] [rbp-18h]
  hkStructureLayout v6; // [rsp+40h] [rbp+8h]

  v2 = classes;
  hkClass::updateMetadataInplace((hkClass **)classes, classVersion);
  hkStructureLayout::hkStructureLayout(&v6);
  v3 = *v2;
  v4 = 0i64;
  classesDone.m_map.m_elem = 0i64;
  classesDone.m_map.m_numElems = 0;
  for ( classesDone.m_map.m_hashMod = -1; v3; ++v4 )
  {
    hkStructureLayout::computeMemberOffsetsInplace(&v6, v3, &classesDone, 1u);
    v3 = v2[v4 + 1];
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&classesDone.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&classesDone);
}

