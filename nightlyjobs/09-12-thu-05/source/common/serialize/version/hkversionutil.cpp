// File Line: 19
// RVA: 0xE39300
const char *__fastcall hkVersionUtil::getCurrentVersion()
{
  return "hk_2013.2.0-r1";
}

// File Line: 24
// RVA: 0xE39310
void __fastcall hkVersionUtil::renameMember(
        hkVariant *oldObj,
        const char *oldName,
        hkVariant *newObj,
        const char *newName)
{
  hkClassMember *ClassMember; // rax
  unsigned int SizeInBytes; // edi
  const void *v8; // rbx
  void *v9; // rax
  hkBool result; // [rsp+20h] [rbp-38h] BYREF
  hkClassMemberAccessor v11; // [rsp+28h] [rbp-30h] BYREF
  hkClassMemberAccessor v12; // [rsp+38h] [rbp-20h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v12, oldObj, oldName);
  hkClassMemberAccessor::hkClassMemberAccessor(&v11, newObj, newName);
  if ( hkClassMemberAccessor::isOk(&v12, &result)->m_bool )
  {
    if ( hkClassMemberAccessor::isOk(&v11, &result)->m_bool )
    {
      ClassMember = hkClassMemberAccessor::getClassMember(&v11);
      SizeInBytes = hkClassMember::getSizeInBytes(ClassMember);
      v8 = hkClassMemberAccessor::asRaw(&v12);
      v9 = hkClassMemberAccessor::asRaw(&v11);
      hkString::memCpy(v9, v8, SizeInBytes);
    }
  }
}

// File Line: 35
// RVA: 0xE393C0
void __fastcall hkVersionUtil::copyDefaults(char *obj, hkClass *oldClass, hkClass *newClass)
{
  unsigned int ObjectSize; // eax
  int i; // ebx
  hkClassMember *Member; // rsi
  hkResult v9; // [rsp+20h] [rbp-48h] BYREF
  hkBufferedStreamWriter v10; // [rsp+28h] [rbp-40h] BYREF
  hkResult result; // [rsp+88h] [rbp+20h] BYREF

  ObjectSize = hkClass::getObjectSize(newClass);
  hkBufferedStreamWriter::hkBufferedStreamWriter(&v10, obj, ObjectSize, 0);
  for ( i = 0; i < (int)hkClass::getNumMembers(newClass); ++i )
  {
    Member = hkClass::getMember(newClass, i);
    if ( !hkClass::getMemberByName(oldClass, Member->m_name) )
    {
      hkBufferedStreamWriter::seek(&v10, &result, Member->m_offset, 0);
      hkClass::getDefault(newClass, &v9, i, &v10);
    }
  }
  hkBufferedStreamWriter::~hkBufferedStreamWriter(&v10);
}

// File Line: 49
// RVA: 0xE39490
void __fastcall hkVersionUtil::recomputeClassMemberOffsets(hkClass **classes, int classVersion)
{
  hkClass *v3; // rax
  __int64 v4; // rbx
  _BYTE classesDone[24]; // [rsp+20h] [rbp-18h] BYREF
  hkStructureLayout v6; // [rsp+40h] [rbp+8h] BYREF

  hkClass::updateMetadataInplace(classes, classVersion);
  hkStructureLayout::hkStructureLayout(&v6);
  v3 = *classes;
  v4 = 0i64;
  *(_QWORD *)classesDone = 0i64;
  *(_DWORD *)&classesDone[8] = 0;
  for ( *(_DWORD *)&classesDone[12] = -1; v3; ++v4 )
  {
    hkStructureLayout::computeMemberOffsetsInplace(
      &v6,
      v3,
      (hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *)classesDone,
      1u);
    v3 = classes[v4 + 1];
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)classesDone,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)classesDone);
}

