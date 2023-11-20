// File Line: 35
// RVA: 0x1A2E80
void DNA::Database::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  DNA::Database *v1; // rax

  v0 = UFG::qMalloc(0x1E0ui64, "DNA::Database", 0i64);
  if ( v0 )
  {
    DNA::Database::Database((DNA::Database *)v0);
    DNA::Database::sInstance = v1;
  }
  else
  {
    DNA::Database::sInstance = 0i64;
  }
}

// File Line: 48
// RVA: 0x1A2ED0
void __fastcall DNA::Database::Instance()
{
  UFG::allocator::free_link *v0; // rax

  if ( !DNA::Database::sInstance )
  {
    v0 = UFG::qMalloc(0x1E0ui64, "DNA::Database", 0i64);
    if ( v0 )
      DNA::Database::Database((DNA::Database *)v0);
    DNA::Database::sInstance = (DNA::Database *)v0;
  }
}

// File Line: 54
// RVA: 0x1A3130
_BOOL8 __fastcall DNA::Database::IsInitialized()
{
  return DNA::Database::sInstance != 0i64;
}

// File Line: 63
// RVA: 0x1A2400
void __fastcall DNA::Database::Database(DNA::Database *this)
{
  DNA::Database *v1; // rbx
  UFG::qTree64<DNA::PropertyBag,DNA::PropertyBag,0> *v2; // rax
  UFG::qTree64<DNA::PropertyBag,DNA::PropertyBag,0> *v3; // rax
  UFG::qTree64<DNA::SchemaType,DNA::SchemaType,0> *v4; // rax
  UFG::qTree64<DNA::SchemaEnum,DNA::SchemaEnum,0> *v5; // rax
  DNA::Event<void __cdecl(DNA::PropertyBag *)> *v6; // [rsp+48h] [rbp+10h]
  DNA::Event<void __cdecl(DNA::PropertyBag *)> *v7; // [rsp+48h] [rbp+10h]
  UFG::qList<DNA::PropertyChangedEvent,DNA::PropertyChangedEvent,1,0> *v8; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->PropertyBagCreated.mDelegates.p = 0i64;
  *(_QWORD *)&this->PropertyBagCreated.mDelegates.size = 0i64;
  v6 = &this->PropertyBagDeleted;
  v6->mDelegates.p = 0i64;
  *(_QWORD *)&v6->mDelegates.size = 0i64;
  v7 = &this->PropertyBagMarkedDirty;
  v7->mDelegates.p = 0i64;
  *(_QWORD *)&v7->mDelegates.size = 0i64;
  this->mBroadcastChangeNotifications = 0;
  v2 = &this->mPropertyBags;
  v2->mTree.mHead.mUID = 0i64;
  v2->mTree.mHead.mParent = &v2->mTree.mHead;
  v2->mTree.mHead.mChildren[0] = &v2->mTree.mHead;
  v2->mTree.mHead.mChildren[1] = &v2->mTree.mHead;
  v2->mTree.mHead.mNeighbours[0] = &v2->mTree.mHead;
  v2->mTree.mHead.mNeighbours[1] = &v2->mTree.mHead;
  v2->mTree.mCount = 0i64;
  v3 = &this->mPropertyBagsInternal;
  v3->mTree.mHead.mUID = 0i64;
  v3->mTree.mHead.mParent = &v3->mTree.mHead;
  v3->mTree.mHead.mChildren[0] = &v3->mTree.mHead;
  v3->mTree.mHead.mChildren[1] = &v3->mTree.mHead;
  v3->mTree.mHead.mNeighbours[0] = &v3->mTree.mHead;
  v3->mTree.mHead.mNeighbours[1] = &v3->mTree.mHead;
  v3->mTree.mCount = 0i64;
  v4 = &this->mSchemaTypes;
  v4->mTree.mHead.mUID = 0i64;
  v4->mTree.mHead.mParent = &v4->mTree.mHead;
  v4->mTree.mHead.mChildren[0] = &v4->mTree.mHead;
  v4->mTree.mHead.mChildren[1] = &v4->mTree.mHead;
  v4->mTree.mHead.mNeighbours[0] = &v4->mTree.mHead;
  v4->mTree.mHead.mNeighbours[1] = &v4->mTree.mHead;
  v4->mTree.mCount = 0i64;
  v5 = &this->mSchemaEnums;
  v5->mTree.mHead.mUID = 0i64;
  v5->mTree.mHead.mParent = &v5->mTree.mHead;
  v5->mTree.mHead.mChildren[0] = &v5->mTree.mHead;
  v5->mTree.mHead.mChildren[1] = &v5->mTree.mHead;
  v5->mTree.mHead.mNeighbours[0] = &v5->mTree.mHead;
  v5->mTree.mHead.mNeighbours[1] = &v5->mTree.mHead;
  v5->mTree.mCount = 0i64;
  v8 = &this->mQueuedChangeEvents;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  this->mQueuedReloadEvents.p = 0i64;
  *(_QWORD *)&this->mQueuedReloadEvents.size = 0i64;
  DNA::ActionManager::ActionManager(&this->mActionManager);
  UFG::qMutex::qMutex(&v1->mMutex, &customWorldMapCaption);
}

// File Line: 219
// RVA: 0x1A3AC0
void __fastcall DNA::Database::Unload(DNA::Database *this, const char *filePath)
{
  DNA::Database *v2; // r14
  DNA::IQueryNode *v3; // rsi
  DNA::PropertyBag *i; // rdi
  UFG::allocator::free_link *v5; // rax
  __int64 *v6; // rax
  __int64 *v7; // rcx
  __int64 *v8; // rax
  DNA::PropertyBagHandle *j; // rbx
  DNA::PropertyBag *v10; // rax
  DNA::PropertyBagHandle *k; // rbx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v12; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v13; // rax
  __int64 *v14; // rcx
  DNA::PropertyBagHandle *v15; // rax
  __int64 *v16; // [rsp+28h] [rbp-38h]
  DNA::PropertyBagHandle *v17; // [rsp+30h] [rbp-30h]
  UFG::qString result; // [rsp+38h] [rbp-28h]

  v2 = this;
  UFG::qCleanupFilepath(&result, filePath, 92);
  v3 = DNA::Query::FilePath(result.mData);
  v16 = (__int64 *)&v16;
  v17 = (DNA::PropertyBagHandle *)&v16;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mMutex);
  for ( i = (DNA::PropertyBag *)UFG::qTree64Base::GetHead(&v2->mPropertyBags.mTree);
        i;
        i = (DNA::PropertyBag *)UFG::qTree64Base::GetNext(&v2->mPropertyBags.mTree, &i->mBaseNode) )
  {
    if ( v3 && v3->vfptr->Match(v3, i) )
    {
      v5 = UFG::qMalloc(0x20ui64, "DNA::PropertyBagHandle", 0i64);
      if ( v5 )
      {
        DNA::PropertyBagHandle::PropertyBagHandle((DNA::PropertyBagHandle *)v5, i);
        v7 = v6;
      }
      else
      {
        v7 = 0i64;
      }
      v8 = v16;
      v16[1] = (__int64)v7;
      *v7 = (__int64)v8;
      v7[1] = (__int64)&v16;
      v16 = v7;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mMutex);
  for ( j = v17; j != (DNA::PropertyBagHandle *)&v16; j = (DNA::PropertyBagHandle *)j->mNext )
  {
    v10 = DNA::PropertyBagHandle::Get(j);
    DNA::Database::DeleteBag(v2, v10);
  }
  for ( k = v17; v17 != (DNA::PropertyBagHandle *)&v16; k = v17 )
  {
    v12 = k->mPrev;
    v13 = k->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    k->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&k->mPrev;
    k->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&k->mPrev;
    DNA::PropertyBagHandle::~PropertyBagHandle(k);
    operator delete[](k);
  }
  v14 = v16;
  v15 = v17;
  v16[1] = (__int64)v17;
  v15->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)v14;
  v16 = (__int64 *)&v16;
  v17 = (DNA::PropertyBagHandle *)&v16;
  if ( v3 )
    ((void (__fastcall *)(DNA::IQueryNode *, signed __int64))v3->vfptr->~IQueryNode)(v3, 1i64);
  UFG::qString::~qString(&result);
}

// File Line: 398
// RVA: 0x1A2F70
char __fastcall DNA::IsDefaultPropertyBagWrapper(DNA::PropertyBagWrapper *wrapper)
{
  UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *v1; // rsi
  unsigned int v2; // ebx
  DNA::SchemaField *v3; // rdi
  signed int v4; // eax
  DNA::PropertyData *v5; // rdi
  const char *v6; // rax
  DNA::PropertyInfo result; // [rsp+28h] [rbp-50h]
  UFG::qString v9; // [rsp+40h] [rbp-38h]
  DNA::PropertyBagWrapper *v; // [rsp+A0h] [rbp+28h]
  DNA::PropertyBag *v11; // [rsp+A8h] [rbp+30h]
  DNA::SchemaField *v12; // [rsp+B0h] [rbp+38h]
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *v13; // [rsp+B8h] [rbp+40h]

  v11 = *wrapper->mPropertyBags.p;
  v1 = wrapper->mProperties.mNode.mNext;
  v13 = &wrapper->mProperties;
  if ( v1 == (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)&wrapper->mProperties )
    return 1;
  v2 = 0;
  while ( 1 )
  {
    v3 = (DNA::SchemaField *)v1[1].mNext;
    v12 = (DNA::SchemaField *)v1[1].mNext;
    DNA::PropertyWrapper::GetPropertyInfo((DNA::PropertyWrapper *)v1, &result);
    if ( result.Size )
    {
      if ( (result.Type != -915936389
         || (unsigned int)UFG::qStringCompare(v3->mTypeName.mData, "UFG::qReflectObject", -1))
        && !DNA::SchemaField::GetAnnotation(v3, "AutoBindHandleType") )
      {
        break;
      }
    }
    if ( result.States.p )
      operator delete[](result.States.p);
    *(_QWORD *)&result.States.size = 0i64;
LABEL_23:
    result.States.p = 0i64;
    v1 = v1->mNext;
    if ( v1 == (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)v13 )
      return 1;
  }
  v4 = v3->mArrayLength;
  if ( v4 < 2 && v4 != -1 || v4 != -1 )
  {
    if ( result.Size )
    {
      do
      {
        if ( result.Type == -915936389 )
        {
          DNA::PropertyWrapper::Get((DNA::PropertyWrapper *)v1, v2, &v, 0);
          if ( !DNA::IsDefaultPropertyBagWrapper(v) )
            goto LABEL_26;
        }
        else
        {
          v5 = DNA::PropertyBag::GetProperty(v11, v3->mName.mData);
          UFG::qString::qString(&v9);
          DNA::PropertyData::GetRaw(v5, v2, &v9);
          v3 = v12;
          v6 = DNA::SchemaField::GetDefaultValue(v12);
          if ( !DNA::DataConverter::Equals(v3->mType, v6, v9.mData) )
          {
            UFG::qString::~qString(&v9);
            goto LABEL_26;
          }
          UFG::qString::~qString(&v9);
        }
        ++v2;
      }
      while ( v2 < result.Size );
    }
    if ( result.States.p )
      operator delete[](result.States.p);
    v2 = 0;
    *(_QWORD *)&result.States.size = 0i64;
    goto LABEL_23;
  }
LABEL_26:
  if ( result.States.p )
    operator delete[](result.States.p);
  result.States.p = 0i64;
  *(_QWORD *)&result.States.size = 0i64;
  return 0;
}

// File Line: 478
// RVA: 0x1A3610
void __fastcall DNA::SaveWrapper(SimpleXML::XMLWriter *writer, DNA::PropertyBagWrapper *wrapper)
{
  DNA::PropertyBagWrapper *v2; // rbx
  SimpleXML::XMLWriter *v3; // rdi
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  __int64 v6; // rsi
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  DNA::PropertyBagWrapper **v9; // rdi
  DNA::PropertyWrapper *v10; // rax
  DNA::PropertyWrapper *v11; // r10
  signed int v12; // ecx
  unsigned int v13; // ebx
  UFG::qString *v14; // rax
  unsigned int v15; // ebx
  UFG::qString *v16; // rax
  __int64 v17; // rcx
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rdx
  __int64 v23; // r8
  DNA::PropertyBagWrapper **v24; // rbx
  UFG::allocator::free_link *mem; // [rsp+28h] [rbp-D8h]
  DNA::PropertyInfo v26; // [rsp+30h] [rbp-D0h]
  UFG::allocator::free_link *v27; // [rsp+48h] [rbp-B8h]
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *v28; // [rsp+50h] [rbp-B0h]
  DNA::PropertyBag *v29; // [rsp+58h] [rbp-A8h]
  DNA::PropertyData *v30; // [rsp+60h] [rbp-A0h]
  DNA::PropertyBagWrapper *v; // [rsp+68h] [rbp-98h]
  DNA::PropertyBagWrapper *v32; // [rsp+70h] [rbp-90h]
  UFG::qString result; // [rsp+78h] [rbp-88h]
  __int64 v34; // [rsp+A0h] [rbp-60h]
  UFG::qString v35; // [rsp+A8h] [rbp-58h]
  UFG::qString v36; // [rsp+D0h] [rbp-30h]
  SimpleXML::XMLWriter *writera; // [rsp+130h] [rbp+30h]
  DNA::SchemaField *v38; // [rsp+138h] [rbp+38h]
  unsigned int v39; // [rsp+138h] [rbp+38h]
  DNA::PropertyWrapper *v40; // [rsp+148h] [rbp+48h]

  writera = writer;
  v34 = -2i64;
  v2 = wrapper;
  v3 = writer;
  v29 = *wrapper->mPropertyBags.p;
  SimpleXML::XMLWriter::BeginNode(writer, "PropertyBag");
  SimpleXML::XMLWriter::AddAttribute(v3, "ID", v29->mBaseNode.mUID);
  v4 = DNA::PropertyBag::GetName(v29, &result);
  SimpleXML::XMLWriter::AddAttribute(v3, "Name", v4->mData, 1);
  UFG::qString::~qString(&result);
  v5 = DNA::PropertyBag::GetSchemaName(v29, &result);
  SimpleXML::XMLWriter::AddAttribute(v3, "SchemaName", v5->mData, 1);
  UFG::qString::~qString(&result);
  SimpleXML::XMLWriter::AddAttribute(v3, "Checksum", v2->mSchema->mReflectionType->mChecksum);
  v6 = 0i64;
  v27 = (UFG::allocator::free_link *)16;
  v7 = 128i64;
  if ( !is_mul_ok(0x10ui64, 8ui64) )
    v7 = -1i64;
  v8 = UFG::qMalloc(v7, "qArray.Reallocate(Constructor)", 0i64);
  v9 = (DNA::PropertyBagWrapper **)v8;
  mem = v8;
  v10 = (DNA::PropertyWrapper *)v2->mProperties.mNode.mNext;
  v40 = v10;
  v28 = &v2->mProperties;
  if ( v10 != (DNA::PropertyWrapper *)&v2->mProperties )
  {
    while ( 1 )
    {
      v38 = v10->mSchemaField;
      DNA::PropertyWrapper::GetPropertyInfo(v10, &v26);
      if ( v26.Size )
      {
        if ( v26.Type != -915936389 )
          goto LABEL_16;
        v11 = v40;
        v12 = v40->mSchemaField->mArrayLength;
        if ( (v12 >= 2 || v12 == -1) && v12 == -1 )
          goto LABEL_16;
        v13 = 0;
        if ( v26.Size )
          break;
      }
LABEL_5:
      if ( v26.States.p )
        operator delete[](v26.States.p);
      v26.States.p = 0i64;
      *(_QWORD *)&v26.States.size = 0i64;
LABEL_44:
      v10 = (DNA::PropertyWrapper *)v40->mNext;
      v40 = v10;
      if ( v10 == (DNA::PropertyWrapper *)v28 )
        goto LABEL_45;
    }
    while ( 1 )
    {
      DNA::PropertyWrapper::Get(v11, v13, &v, 0);
      if ( !DNA::IsDefaultPropertyBagWrapper(v) )
        break;
      ++v13;
      v11 = v40;
      if ( v13 >= v26.Size )
        goto LABEL_5;
    }
LABEL_16:
    SimpleXML::XMLWriter::BeginNode(writera, "Property");
    SimpleXML::XMLWriter::AddAttribute(writera, "Name", v38->mName.mData, 1);
    v14 = UFG::qToHex(&v35, v26.Type);
    SimpleXML::XMLWriter::AddAttribute(writera, "Type", v14->mData, 1);
    UFG::qString::~qString(&v35);
    if ( v26.Size != 1 )
      SimpleXML::XMLWriter::AddAttribute(writera, "Count", v26.Size);
    v30 = DNA::PropertyBag::GetProperty(v29, v38->mName.mData);
    v15 = 0;
    v39 = 0;
    if ( v26.Size )
    {
      do
      {
        UFG::qString::qString(&result);
        DNA::PropertyData::GetRaw(v30, v15, &result);
        SimpleXML::XMLWriter::BeginNode(writera, "Value");
        v16 = UFG::qToHex(&v36, v15);
        SimpleXML::XMLWriter::AddAttribute(writera, "ID", v16->mData, 1);
        UFG::qString::~qString(&v36);
        SimpleXML::XMLWriter::AddValue(writera, result.mData, 1);
        SimpleXML::XMLWriter::EndNode(writera, "Value");
        if ( v26.Type == -915936389 )
        {
          DNA::PropertyWrapper::Get(v40, v15, &v32, 0);
          v17 = (unsigned int)v6;
          v18 = v6 + 1;
          if ( (signed int)v6 + 1 > (unsigned int)v27 )
          {
            v19 = 1;
            if ( (_DWORD)v27 )
              v19 = 2 * (_DWORD)v27;
            for ( ; v19 < v18; v19 *= 2 )
              ;
            if ( v19 <= 2 )
              v19 = 2;
            if ( v19 - v18 > 0x10000 )
              v19 = v6 + 65537;
            if ( v19 != (_DWORD)v6 )
            {
              v20 = 8i64 * v19;
              if ( !is_mul_ok(v19, 8ui64) )
                v20 = -1i64;
              v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
              v27 = v21;
              if ( mem )
              {
                if ( (_DWORD)v6 )
                {
                  v22 = v21;
                  v23 = (unsigned int)v6;
                  do
                  {
                    v22->mNext = *(UFG::allocator::free_link **)((char *)v22 + (char *)mem - (char *)v21);
                    ++v22;
                    --v23;
                  }
                  while ( v23 );
                }
                operator delete[](mem);
                v21 = v27;
              }
              mem = v21;
              v27 = (UFG::allocator::free_link *)v19;
              v17 = (unsigned int)v6;
            }
            v15 = v39;
          }
          v6 = v18;
          v9 = (DNA::PropertyBagWrapper **)mem;
          mem[v17].mNext = (UFG::allocator::free_link *)v32;
        }
        UFG::qString::~qString(&result);
        v39 = ++v15;
      }
      while ( v15 < v26.Size );
    }
    SimpleXML::XMLWriter::EndNode(writera, "Property");
    if ( v26.States.p )
      operator delete[](v26.States.p);
    v26.States.p = 0i64;
    *(_QWORD *)&v26.States.size = 0i64;
    goto LABEL_44;
  }
LABEL_45:
  if ( (_DWORD)v6 )
  {
    v24 = v9;
    do
    {
      DNA::SaveWrapper(writera, *v24);
      ++v24;
      --v6;
    }
    while ( v6 );
    v9 = (DNA::PropertyBagWrapper **)mem;
  }
  SimpleXML::XMLWriter::EndNode(writera, "PropertyBag");
  if ( v9 )
    operator delete[](v9);
}

// File Line: 581
// RVA: 0x1A3560
bool __fastcall DNA::Database::SaveToBuffer(DNA::Database *this, const char **buffer, unsigned int *buffer_size, DNA::PropertyBag *propertyBag)
{
  DNA::PropertyBag *v4; // rbx
  unsigned int *v5; // rdi
  const char **v6; // rsi
  SimpleXML::XMLWriter *v7; // rax
  SimpleXML::XMLWriter *writer; // [rsp+20h] [rbp-48h]
  __int64 v10; // [rsp+28h] [rbp-40h]
  DNA::PropertyBagWrapper wrapper; // [rsp+30h] [rbp-38h]

  v10 = -2i64;
  v4 = propertyBag;
  v5 = buffer_size;
  v6 = buffer;
  v7 = (SimpleXML::XMLWriter *)SimpleXML::XMLWriter::CreateBuffer(0x400u, 1);
  writer = v7;
  if ( v7 )
  {
    SimpleXML::XMLWriter::BeginNode(v7, "DNAFile");
    DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, v4);
    DNA::SaveWrapper(writer, &wrapper);
    SimpleXML::XMLWriter::EndNode(writer, "DNAFile");
    *v6 = SimpleXML::XMLWriter::CloseBuffer(&writer, v5);
    writer = 0i64;
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 603
// RVA: 0x1A2BF0
unsigned __int64 __fastcall DNA::Database::GenUID(DNA::Database *this)
{
  DNA::Database *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  char *v3; // rdi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  UFG::qString result; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  do
  {
    do
    {
      v3 = UFG::qGetUserName(&result)->mData;
      v4 = UFG::qGetTicks();
      v5 = UFG::qStringHash64(v3, v4) ^ 0x7FFFFFFFFFFFFFE7i64;
      UFG::qString::~qString(&result);
    }
    while ( UFG::qTree64Base::Get(&v1->mPropertyBags.mTree, v5) );
  }
  while ( UFG::qTree64Base::Get(&v1->mPropertyBagsInternal.mTree, v5) );
  UFG::qMutex::Unlock(v2);
  return v5;
}

// File Line: 625
// RVA: 0x1A26F0
DNA::PropertyBag *__fastcall DNA::Database::CreateBag(DNA::Database *this, const char *name, const char *schemaName, const char *filePath, unsigned __int64 id)
{
  const char *v5; // rdi
  const char *v6; // r14
  const char *v7; // r15
  DNA::Database *v8; // rbp
  _RTL_CRITICAL_SECTION *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  unsigned int v11; // edi
  DNA::PropertyBag *v12; // rax
  DNA::PropertyBag *v13; // rsi
  signed __int64 v14; // rcx
  UFG::qString result; // [rsp+30h] [rbp-48h]

  v5 = filePath;
  v6 = schemaName;
  v7 = name;
  v8 = this;
  v9 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  UFG::qCleanupFilepath(&result, v5, 92);
  v10 = UFG::qMalloc(0x80ui64, "DNA::PropertyBag", 0i64);
  v11 = 0;
  if ( v10 )
  {
    DNA::PropertyBag::PropertyBag((DNA::PropertyBag *)v10, id);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  DNA::PropertyBag::SetName(v13, v7);
  DNA::PropertyBag::SetSchemaName(v13, v6);
  DNA::PropertyBag::SetFilePath(v13, result.mData);
  UFG::qTree64Base::Add(&v8->mPropertyBags.mTree, &v13->mBaseNode);
  if ( v8->PropertyBagCreated.mDelegates.size )
  {
    do
    {
      v14 = (signed __int64)&v8->PropertyBagCreated.mDelegates.p[v11];
      (*(void (__fastcall **)(_QWORD, DNA::PropertyBag *))(v14 + 8))(*(_QWORD *)v14, v13);
      ++v11;
    }
    while ( v11 < v8->PropertyBagCreated.mDelegates.size );
  }
  UFG::qString::~qString(&result);
  UFG::qMutex::Unlock(v9);
  return v13;
}

// File Line: 643
// RVA: 0x1A2810
DNA::PropertyBag *__fastcall DNA::Database::CreateBag(DNA::Database *this, const char *name, const char *schemaName, DNA::PropertyBag *owner)
{
  DNA::PropertyBag *v4; // r14
  const char *v5; // r15
  const char *v6; // r12
  DNA::Database *v7; // rbp
  _RTL_CRITICAL_SECTION *v8; // rbx
  UFG::allocator::free_link *v9; // rsi
  unsigned int v10; // edi
  unsigned __int64 v11; // rax
  DNA::PropertyBag *v12; // rax
  DNA::PropertyBag *v13; // rsi
  signed __int64 v14; // rcx

  v4 = owner;
  v5 = schemaName;
  v6 = name;
  v7 = this;
  v8 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v9 = UFG::qMalloc(0x80ui64, "DNA::PropertyBag", 0i64);
  v10 = 0;
  if ( v9 )
  {
    v11 = DNA::Database::GenUID(v7);
    DNA::PropertyBag::PropertyBag((DNA::PropertyBag *)v9, v11);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  DNA::PropertyBag::SetName(v13, v6);
  DNA::PropertyBag::SetSchemaName(v13, v5);
  DNA::PropertyBag::SetOwner(v13, v4);
  UFG::qTree64Base::Add(&v7->mPropertyBagsInternal.mTree, &v13->mBaseNode);
  if ( v7->PropertyBagCreated.mDelegates.size )
  {
    do
    {
      v14 = (signed __int64)&v7->PropertyBagCreated.mDelegates.p[v10];
      (*(void (__fastcall **)(_QWORD, DNA::PropertyBag *))(v14 + 8))(*(_QWORD *)v14, v13);
      ++v10;
    }
    while ( v10 < v7->PropertyBagCreated.mDelegates.size );
  }
  UFG::qMutex::Unlock(v8);
  return v13;
}

// File Line: 660
// RVA: 0x1A2A00
void __fastcall DNA::Database::DeleteBag(DNA::Database *this, DNA::PropertyBag *bag)
{
  DNA::PropertyBag *v2; // rdi
  DNA::Database *v3; // rbp
  _RTL_CRITICAL_SECTION *v4; // rbx
  unsigned int v5; // esi
  signed __int64 v6; // rcx

  v2 = bag;
  v3 = this;
  v4 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v5 = 0;
  if ( v3->PropertyBagDeleted.mDelegates.size )
  {
    do
    {
      v6 = (signed __int64)&v3->PropertyBagDeleted.mDelegates.p[v5];
      (*(void (__fastcall **)(_QWORD, DNA::PropertyBag *))(v6 + 8))(*(_QWORD *)v6, v2);
      ++v5;
    }
    while ( v5 < v3->PropertyBagDeleted.mDelegates.size );
  }
  if ( UFG::qTree64Base::Contains(&v3->mPropertyBags.mTree, v2->mBaseNode.mUID) )
    UFG::qTree64Base::Remove(&v3->mPropertyBags.mTree, &v2->mBaseNode);
  if ( UFG::qTree64Base::Contains(&v3->mPropertyBagsInternal.mTree, v2->mBaseNode.mUID) )
    UFG::qTree64Base::Remove(&v3->mPropertyBagsInternal.mTree, &v2->mBaseNode);
  DNA::PropertyBag::~PropertyBag(v2);
  operator delete[](v2);
  UFG::qMutex::Unlock(v4);
}

// File Line: 769
// RVA: 0x1A3370
void __fastcall DNA::Database::OnOwnerChanged(DNA::Database *this, DNA::PropertyBag *bag, DNA::PropertyBag *owner)
{
  DNA::PropertyBag *v3; // rdi
  DNA::PropertyBag *v4; // rsi
  DNA::Database *v5; // rbp
  _RTL_CRITICAL_SECTION *v6; // rbx
  unsigned __int64 v7; // rdx
  UFG::qTree64Base *v8; // rcx

  v3 = owner;
  v4 = bag;
  v5 = this;
  v6 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v7 = v4->mBaseNode.mUID;
  if ( v3 )
  {
    if ( UFG::qTree64Base::Contains(&v5->mPropertyBags.mTree, v7) )
    {
      UFG::qTree64Base::Remove(&v5->mPropertyBags.mTree, &v4->mBaseNode);
      v8 = &v5->mPropertyBagsInternal.mTree;
LABEL_6:
      UFG::qTree64Base::Add(v8, &v4->mBaseNode);
      goto LABEL_7;
    }
  }
  else if ( UFG::qTree64Base::Contains(&v5->mPropertyBagsInternal.mTree, v7) )
  {
    UFG::qTree64Base::Remove(&v5->mPropertyBagsInternal.mTree, &v4->mBaseNode);
    v8 = &v5->mPropertyBags.mTree;
    goto LABEL_6;
  }
LABEL_7:
  UFG::qMutex::Unlock(v6);
}

// File Line: 794
// RVA: 0x1A2CE0
UFG::qTree64Base *__fastcall DNA::Database::GetPropertyBag(DNA::Database *this, unsigned __int64 uid)
{
  unsigned __int64 v2; // rbp
  DNA::Database *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  UFG::qTree64Base *v5; // rdi

  v2 = uid;
  v3 = this;
  v4 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v5 = UFG::qTree64Base::Get(&v3->mPropertyBags.mTree, v2);
  if ( !v5 )
    v5 = UFG::qTree64Base::Get(&v3->mPropertyBagsInternal.mTree, v2);
  UFG::qMutex::Unlock(v4);
  return v5;
}

// File Line: 806
// RVA: 0x1A2D70
void __fastcall DNA::Database::GetPropertyBags(DNA::Database *this, DNA::Query *query, UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *propertyBags)
{
  UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *v3; // rsi
  DNA::Query *v4; // r14
  DNA::Database *v5; // rbp
  _RTL_CRITICAL_SECTION *v6; // rbx
  DNA::PropertyBag *i; // rdi
  DNA::PropertyBagHandle *v8; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v9; // rcx

  v3 = propertyBags;
  v4 = query;
  v5 = this;
  v6 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  for ( i = (DNA::PropertyBag *)UFG::qTree64Base::GetHead(&v5->mPropertyBags.mTree);
        i;
        i = (DNA::PropertyBag *)UFG::qTree64Base::GetNext(&v5->mPropertyBags.mTree, &i->mBaseNode) )
  {
    if ( v4->mRoot && v4->mRoot->vfptr->Match(v4->mRoot, i) )
    {
      v8 = (DNA::PropertyBagHandle *)UFG::qMalloc(0x20ui64, "DNA::PropertyBagHandle", 0i64);
      if ( v8 )
        DNA::PropertyBagHandle::PropertyBagHandle(v8, i);
      v9 = v3->mNode.mPrev;
      v9->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&v8->mPrev;
      v8->mPrev = v9;
      v8->mNext = &v3->mNode;
      v3->mNode.mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&v8->mPrev;
    }
  }
  UFG::qMutex::Unlock(v6);
}

// File Line: 819
// RVA: 0x1A3140
__int64 __fastcall DNA::Database::LoadReflectionDatabase(DNA::Database *this, const char *filePath, bool validate_type_sizes)
{
  bool v3; // r13
  const char *v4; // rdi
  DNA::Database *v5; // r15
  _RTL_CRITICAL_SECTION *v6; // rbx
  UFG::ReflectionDB *v7; // rax
  unsigned __int8 v8; // r12
  UFG::ReflectionDB *v9; // rax
  UFG::qReflectType *v10; // rsi
  unsigned __int64 v11; // rdi
  UFG::ReflectionDB *v12; // rax
  UFG::qTree64Base *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::ReflectionDB *v15; // rax
  UFG::ReflectionDB *v16; // rax
  UFG::qReflectEnum *v17; // r14
  UFG::allocator::free_link *v18; // rax
  UFG::qTree64Base::BaseNode *v19; // rax
  UFG::qTree64Base::BaseNode *v20; // rsi
  UFG::allocator::free_link *v21; // rdi
  UFG::allocator::free_link *v22; // rsi
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rcx
  UFG::allocator::free_link *v25; // rcx
  UFG::ReflectionDB *v26; // rax
  UFG::ReflectionDB *v27; // rax

  v3 = validate_type_sizes;
  v4 = filePath;
  v5 = this;
  v6 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v7 = UFG::ReflectionDB::Instance();
  v8 = UFG::ReflectionDB::Load(v7, v4);
  if ( v8 )
  {
    v9 = UFG::ReflectionDB::Instance();
    v10 = (UFG::qReflectType *)UFG::qTree64Base::GetHead(&v9->mTypes.mTree);
    UFG::ReflectionDB::Instance();
    while ( v10 )
    {
      v11 = v10->mBaseNode.mUID;
      v12 = UFG::ReflectionDB::Instance();
      v13 = UFG::qTree64Base::Get(&v12->mSchemas.mTree, v11);
      v14 = UFG::qMalloc(0xE8ui64, "Database::SchemaType", 0i64);
      if ( v14 )
        DNA::SchemaType::SchemaType((DNA::SchemaType *)v14, v10, (UFG::qReflectSchema *)v13);
      UFG::qTree64Base::Add(&v5->mSchemaTypes.mTree, (UFG::qTree64Base::BaseNode *)v14);
      v15 = UFG::ReflectionDB::Instance();
      v10 = (UFG::qReflectType *)UFG::qTree64Base::GetNext(&v15->mTypes.mTree, &v10->mBaseNode);
      UFG::ReflectionDB::Instance();
    }
    v16 = UFG::ReflectionDB::Instance();
    v17 = (UFG::qReflectEnum *)UFG::qTree64Base::GetHead(&v16->mEnums.mTree);
    UFG::ReflectionDB::Instance();
    while ( v17 )
    {
      v18 = UFG::qMalloc(0x48ui64, "Database::SchemaEnum", 0i64);
      if ( v18 )
      {
        DNA::SchemaEnum::SchemaEnum((DNA::SchemaEnum *)v18, v17);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      UFG::qTree64Base::Add(&v5->mSchemaEnums.mTree, v20);
      v21 = (UFG::allocator::free_link *)v17->mValues.mNode.mNext;
      if ( v21 != (UFG::allocator::free_link *)&v17->mValues )
      {
        v22 = (UFG::allocator::free_link *)&v20[1].mParent;
        do
        {
          v23 = UFG::qMalloc(0x50ui64, "Database::SchemaEnumValue", 0i64);
          if ( v23 )
          {
            v23->mNext = v23;
            v23[1].mNext = v23;
            v23[2].mNext = v21;
            v24 = v23 + 3;
            v24->mNext = 0i64;
            v24[1].mNext = v24;
            v24[2].mNext = v24;
            v24[3].mNext = v24;
            v24[4].mNext = v24;
            v24[5].mNext = v24;
            v24[6].mNext = 0i64;
          }
          v25 = v22->mNext;
          v25[1].mNext = v23;
          v23->mNext = v25;
          v23[1].mNext = v22;
          v22->mNext = v23;
          v21 = v21[1].mNext;
        }
        while ( v21 != (UFG::allocator::free_link *)&v17->mValues );
      }
      v26 = UFG::ReflectionDB::Instance();
      v17 = (UFG::qReflectEnum *)UFG::qTree64Base::GetNext(&v26->mEnums.mTree, &v17->mBaseNode);
      UFG::ReflectionDB::Instance();
    }
    if ( v3 )
    {
      v27 = UFG::ReflectionDB::Instance();
      UFG::ReflectionDB::ValidateClassSizes(v27);
    }
  }
  UFG::qMutex::Unlock(v6);
  return v8;
}

// File Line: 855
// RVA: 0x1A2CB0
UFG::qTree64Base *__fastcall DNA::Database::GetEnum(DNA::Database *this, const char *enumName)
{
  DNA::Database *v2; // rbx
  unsigned __int64 v3; // rax

  v2 = this;
  v3 = UFG::qStringHash64(enumName, 0xFFFFFFFFFFFFFFFFui64);
  return UFG::qTree64Base::Get(&v2->mSchemaEnums.mTree, v3);
}

// File Line: 865
// RVA: 0x1A2E50
UFG::qTree64Base *__fastcall DNA::Database::GetSchema(DNA::Database *this, const char *schemaName)
{
  DNA::Database *v2; // rbx
  unsigned __int64 v3; // rax

  v2 = this;
  v3 = UFG::qStringHash64(schemaName, 0xFFFFFFFFFFFFFFFFui64);
  return UFG::qTree64Base::Get(&v2->mSchemaTypes.mTree, v3);
}

// File Line: 995
// RVA: 0x1A3420
void __fastcall DNA::Database::OnStructureChanged(DNA::Database *this, DNA::PropertyData *data)
{
  _RTL_CRITICAL_SECTION *v2; // rbx

  v2 = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  UFG::qMutex::Unlock(v2);
}

