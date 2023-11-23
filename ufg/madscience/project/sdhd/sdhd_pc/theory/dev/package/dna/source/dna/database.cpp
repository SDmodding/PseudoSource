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
  this->PropertyBagCreated.mDelegates.p = 0i64;
  *(_QWORD *)&this->PropertyBagCreated.mDelegates.size = 0i64;
  this->PropertyBagDeleted.mDelegates.p = 0i64;
  *(_QWORD *)&this->PropertyBagDeleted.mDelegates.size = 0i64;
  this->PropertyBagMarkedDirty.mDelegates.p = 0i64;
  *(_QWORD *)&this->PropertyBagMarkedDirty.mDelegates.size = 0i64;
  this->mBroadcastChangeNotifications = 0;
  this->mPropertyBags.mTree.mHead.mUID = 0i64;
  this->mPropertyBags.mTree.mHead.mParent = &this->mPropertyBags.mTree.mHead;
  this->mPropertyBags.mTree.mHead.mChildren[0] = &this->mPropertyBags.mTree.mHead;
  this->mPropertyBags.mTree.mHead.mChildren[1] = &this->mPropertyBags.mTree.mHead;
  this->mPropertyBags.mTree.mHead.mNeighbours[0] = &this->mPropertyBags.mTree.mHead;
  this->mPropertyBags.mTree.mHead.mNeighbours[1] = &this->mPropertyBags.mTree.mHead;
  this->mPropertyBags.mTree.mCount = 0i64;
  this->mPropertyBagsInternal.mTree.mHead.mUID = 0i64;
  this->mPropertyBagsInternal.mTree.mHead.mParent = &this->mPropertyBagsInternal.mTree.mHead;
  this->mPropertyBagsInternal.mTree.mHead.mChildren[0] = &this->mPropertyBagsInternal.mTree.mHead;
  this->mPropertyBagsInternal.mTree.mHead.mChildren[1] = &this->mPropertyBagsInternal.mTree.mHead;
  this->mPropertyBagsInternal.mTree.mHead.mNeighbours[0] = &this->mPropertyBagsInternal.mTree.mHead;
  this->mPropertyBagsInternal.mTree.mHead.mNeighbours[1] = &this->mPropertyBagsInternal.mTree.mHead;
  this->mPropertyBagsInternal.mTree.mCount = 0i64;
  this->mSchemaTypes.mTree.mHead.mUID = 0i64;
  this->mSchemaTypes.mTree.mHead.mParent = &this->mSchemaTypes.mTree.mHead;
  this->mSchemaTypes.mTree.mHead.mChildren[0] = &this->mSchemaTypes.mTree.mHead;
  this->mSchemaTypes.mTree.mHead.mChildren[1] = &this->mSchemaTypes.mTree.mHead;
  this->mSchemaTypes.mTree.mHead.mNeighbours[0] = &this->mSchemaTypes.mTree.mHead;
  this->mSchemaTypes.mTree.mHead.mNeighbours[1] = &this->mSchemaTypes.mTree.mHead;
  this->mSchemaTypes.mTree.mCount = 0i64;
  this->mSchemaEnums.mTree.mHead.mUID = 0i64;
  this->mSchemaEnums.mTree.mHead.mParent = &this->mSchemaEnums.mTree.mHead;
  this->mSchemaEnums.mTree.mHead.mChildren[0] = &this->mSchemaEnums.mTree.mHead;
  this->mSchemaEnums.mTree.mHead.mChildren[1] = &this->mSchemaEnums.mTree.mHead;
  this->mSchemaEnums.mTree.mHead.mNeighbours[0] = &this->mSchemaEnums.mTree.mHead;
  this->mSchemaEnums.mTree.mHead.mNeighbours[1] = &this->mSchemaEnums.mTree.mHead;
  this->mSchemaEnums.mTree.mCount = 0i64;
  this->mQueuedChangeEvents.mNode.mPrev = &this->mQueuedChangeEvents.mNode;
  this->mQueuedChangeEvents.mNode.mNext = &this->mQueuedChangeEvents.mNode;
  this->mQueuedReloadEvents.p = 0i64;
  *(_QWORD *)&this->mQueuedReloadEvents.size = 0i64;
  DNA::ActionManager::ActionManager(&this->mActionManager);
  UFG::qMutex::qMutex(&this->mMutex, &customCaption);
}

// File Line: 219
// RVA: 0x1A3AC0
void __fastcall DNA::Database::Unload(DNA::Database *this, char *filePath)
{
  DNA::IQueryNode *v3; // rsi
  DNA::PropertyBag *i; // rdi
  UFG::allocator::free_link *v5; // rax
  __int64 *v6; // rax
  __int64 *v7; // rcx
  __int64 *v8; // rax
  DNA::PropertyBagHandle *j; // rbx
  UFG::qTree64Base *v10; // rax
  DNA::PropertyBagHandle *k; // rbx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mPrev; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mNext; // rax
  __int64 *v14; // rcx
  DNA::PropertyBagHandle *v15; // rax
  __int64 *v16; // [rsp+28h] [rbp-38h] BYREF
  DNA::PropertyBagHandle *v17; // [rsp+30h] [rbp-30h]
  UFG::qString result; // [rsp+38h] [rbp-28h] BYREF

  UFG::qCleanupFilepath(&result, filePath, 92);
  v3 = DNA::Query::FilePath(result.mData);
  v16 = (__int64 *)&v16;
  v17 = (DNA::PropertyBagHandle *)&v16;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  for ( i = (DNA::PropertyBag *)UFG::qTree64Base::GetHead(&this->mPropertyBags.mTree);
        i;
        i = (DNA::PropertyBag *)UFG::qTree64Base::GetNext(&this->mPropertyBags.mTree, &i->mBaseNode) )
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
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mMutex);
  for ( j = v17; j != (DNA::PropertyBagHandle *)&v16; j = (DNA::PropertyBagHandle *)j->mNext )
  {
    v10 = (UFG::qTree64Base *)DNA::PropertyBagHandle::Get(j);
    DNA::Database::DeleteBag(this, v10);
  }
  for ( k = v17; v17 != (DNA::PropertyBagHandle *)&v16; k = v17 )
  {
    mPrev = k->mPrev;
    mNext = k->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    k->mPrev = k;
    k->mNext = k;
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
    ((void (__fastcall *)(DNA::IQueryNode *, __int64))v3->vfptr->~IQueryNode)(v3, 1i64);
  UFG::qString::~qString(&result);
}

// File Line: 398
// RVA: 0x1A2F70
char __fastcall DNA::IsDefaultPropertyBagWrapper(DNA::PropertyBagWrapper *wrapper)
{
  UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *mNext; // rsi
  unsigned int v2; // ebx
  DNA::SchemaField *v3; // rdi
  int mArrayLength; // eax
  DNA::PropertyData *Property; // rdi
  const char *DefaultValue; // rax
  DNA::PropertyInfo result; // [rsp+28h] [rbp-50h] BYREF
  UFG::qString v9; // [rsp+40h] [rbp-38h] BYREF
  DNA::PropertyBagWrapper *v; // [rsp+A0h] [rbp+28h] BYREF
  DNA::PropertyBag *v11; // [rsp+A8h] [rbp+30h]
  DNA::SchemaField *v12; // [rsp+B0h] [rbp+38h]
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *p_mProperties; // [rsp+B8h] [rbp+40h]

  v11 = *wrapper->mPropertyBags.p;
  mNext = wrapper->mProperties.mNode.mNext;
  p_mProperties = &wrapper->mProperties;
  if ( mNext == (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)&wrapper->mProperties )
    return 1;
  v2 = 0;
  while ( 1 )
  {
    v3 = (DNA::SchemaField *)mNext[1].mNext;
    v12 = v3;
    DNA::PropertyWrapper::GetPropertyInfo((DNA::PropertyWrapper *)mNext, &result);
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
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<DNA::PropertyWrapper,DNA::PropertyWrapper> *)p_mProperties )
      return 1;
  }
  mArrayLength = v3->mArrayLength;
  if ( mArrayLength < 2 && mArrayLength != -1 || mArrayLength != -1 )
  {
    if ( result.Size )
    {
      do
      {
        if ( result.Type == -915936389 )
        {
          DNA::PropertyWrapper::Get((DNA::PropertyWrapper *)mNext, v2, &v, 0);
          if ( !DNA::IsDefaultPropertyBagWrapper(v) )
            goto LABEL_26;
        }
        else
        {
          Property = DNA::PropertyBag::GetProperty(v11, v3->mName.mData);
          UFG::qString::qString(&v9);
          DNA::PropertyData::GetRaw(Property, v2, &v9);
          v3 = v12;
          DefaultValue = DNA::SchemaField::GetDefaultValue(v12);
          if ( !DNA::DataConverter::Equals(v3->mType, DefaultValue, v9.mData) )
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
  UFG::qString *Name; // rax
  UFG::qString *SchemaName; // rax
  __int64 v6; // rsi
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rdi
  DNA::PropertyWrapper *mNext; // rax
  DNA::PropertyWrapper *v10; // r10
  int mArrayLength; // ecx
  unsigned int v12; // ebx
  UFG::qString *v13; // rax
  unsigned int v14; // ebx
  UFG::qString *v15; // rax
  __int64 v16; // rcx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned __int64 v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rdx
  __int64 v22; // r8
  DNA::PropertyBagWrapper **v23; // rbx
  UFG::allocator::free_link *mem; // [rsp+28h] [rbp-D8h]
  DNA::PropertyInfo v25; // [rsp+30h] [rbp-D0h] BYREF
  unsigned __int64 v26; // [rsp+48h] [rbp-B8h]
  UFG::qList<DNA::PropertyWrapper,DNA::PropertyWrapper,1,0> *i; // [rsp+50h] [rbp-B0h]
  DNA::PropertyBag *v28; // [rsp+58h] [rbp-A8h]
  DNA::PropertyData *Property; // [rsp+60h] [rbp-A0h]
  DNA::PropertyBagWrapper *v; // [rsp+68h] [rbp-98h] BYREF
  DNA::PropertyBagWrapper *v31; // [rsp+70h] [rbp-90h] BYREF
  UFG::qString result; // [rsp+78h] [rbp-88h] BYREF
  __int64 v33; // [rsp+A0h] [rbp-60h]
  UFG::qString v34; // [rsp+A8h] [rbp-58h] BYREF
  UFG::qString v35; // [rsp+D0h] [rbp-30h] BYREF
  DNA::SchemaField *mSchemaField; // [rsp+138h] [rbp+38h]
  unsigned int j; // [rsp+138h] [rbp+38h]
  DNA::PropertyWrapper *v39; // [rsp+148h] [rbp+48h]

  v33 = -2i64;
  v28 = *wrapper->mPropertyBags.p;
  SimpleXML::XMLWriter::BeginNode(writer, "PropertyBag");
  SimpleXML::XMLWriter::AddAttribute(writer, "ID", v28->mBaseNode.mUID);
  Name = DNA::PropertyBag::GetName(v28, &result);
  SimpleXML::XMLWriter::AddAttribute(writer, "Name", Name->mData, 1);
  UFG::qString::~qString(&result);
  SchemaName = DNA::PropertyBag::GetSchemaName(v28, &result);
  SimpleXML::XMLWriter::AddAttribute(writer, "SchemaName", SchemaName->mData, 1);
  UFG::qString::~qString(&result);
  SimpleXML::XMLWriter::AddAttribute(writer, "Checksum", wrapper->mSchema->mReflectionType->mChecksum);
  v6 = 0i64;
  v26 = 16i64;
  v7 = 128i64;
  if ( !is_mul_ok(0x10ui64, 8ui64) )
    v7 = -1i64;
  v8 = UFG::qMalloc(v7, "qArray.Reallocate(Constructor)", 0i64);
  mem = v8;
  mNext = (DNA::PropertyWrapper *)wrapper->mProperties.mNode.mNext;
  v39 = mNext;
  for ( i = &wrapper->mProperties; mNext != (DNA::PropertyWrapper *)i; v39 = mNext )
  {
    mSchemaField = mNext->mSchemaField;
    DNA::PropertyWrapper::GetPropertyInfo(mNext, &v25);
    if ( v25.Size )
    {
      if ( v25.Type == -915936389 )
      {
        if ( (v10 = v39, mArrayLength = v39->mSchemaField->mArrayLength, mArrayLength < 2) && mArrayLength != -1
          || mArrayLength != -1 )
        {
          v12 = 0;
          while ( 1 )
          {
            DNA::PropertyWrapper::Get(v10, v12, &v, 0);
            if ( !DNA::IsDefaultPropertyBagWrapper(v) )
              break;
            ++v12;
            v10 = v39;
            if ( v12 >= v25.Size )
              goto LABEL_5;
          }
        }
      }
      SimpleXML::XMLWriter::BeginNode(writer, "Property");
      SimpleXML::XMLWriter::AddAttribute(writer, "Name", mSchemaField->mName.mData, 1);
      v13 = UFG::qToHex(&v34, v25.Type);
      SimpleXML::XMLWriter::AddAttribute(writer, "Type", v13->mData, 1);
      UFG::qString::~qString(&v34);
      if ( v25.Size != 1 )
        SimpleXML::XMLWriter::AddAttribute(writer, "Count", v25.Size);
      Property = DNA::PropertyBag::GetProperty(v28, mSchemaField->mName.mData);
      v14 = 0;
      for ( j = 0; v14 < v25.Size; j = v14 )
      {
        UFG::qString::qString(&result);
        DNA::PropertyData::GetRaw(Property, v14, &result);
        SimpleXML::XMLWriter::BeginNode(writer, "Value");
        v15 = UFG::qToHex(&v35, v14);
        SimpleXML::XMLWriter::AddAttribute(writer, "ID", v15->mData, 1);
        UFG::qString::~qString(&v35);
        SimpleXML::XMLWriter::AddValue(writer, result.mData, 1);
        SimpleXML::XMLWriter::EndNode(writer, "Value");
        if ( v25.Type == -915936389 )
        {
          DNA::PropertyWrapper::Get(v39, v14, &v31, 0);
          v16 = (unsigned int)v6;
          v17 = v6 + 1;
          if ( (int)v6 + 1 > (unsigned int)v26 )
          {
            v18 = 1;
            if ( (_DWORD)v26 )
              v18 = 2 * v26;
            for ( ; v18 < v17; v18 *= 2 )
              ;
            if ( v18 <= 2 )
              v18 = 2;
            if ( v18 - v17 > 0x10000 )
              v18 = v6 + 65537;
            if ( v18 != (_DWORD)v6 )
            {
              v19 = 8i64 * v18;
              if ( !is_mul_ok(v18, 8ui64) )
                v19 = -1i64;
              v20 = UFG::qMalloc(v19, "qArray.Add", 0i64);
              v26 = (unsigned __int64)v20;
              if ( mem )
              {
                if ( (_DWORD)v6 )
                {
                  v21 = v20;
                  v22 = (unsigned int)v6;
                  do
                  {
                    v21->mNext = *(UFG::allocator::free_link **)((char *)v21 + (char *)mem - (char *)v20);
                    ++v21;
                    --v22;
                  }
                  while ( v22 );
                }
                operator delete[](mem);
                v20 = (UFG::allocator::free_link *)v26;
              }
              mem = v20;
              v26 = v18;
              v16 = (unsigned int)v6;
            }
            v14 = j;
          }
          v6 = v17;
          v8 = mem;
          mem[v16].mNext = (UFG::allocator::free_link *)v31;
        }
        UFG::qString::~qString(&result);
        ++v14;
      }
      SimpleXML::XMLWriter::EndNode(writer, "Property");
      if ( v25.States.p )
        operator delete[](v25.States.p);
      v25.States.p = 0i64;
      *(_QWORD *)&v25.States.size = 0i64;
    }
    else
    {
LABEL_5:
      if ( v25.States.p )
        operator delete[](v25.States.p);
      v25.States.p = 0i64;
      *(_QWORD *)&v25.States.size = 0i64;
    }
    mNext = (DNA::PropertyWrapper *)v39->mNext;
  }
  if ( (_DWORD)v6 )
  {
    v23 = (DNA::PropertyBagWrapper **)v8;
    do
    {
      DNA::SaveWrapper(writer, *v23++);
      --v6;
    }
    while ( v6 );
    v8 = mem;
  }
  SimpleXML::XMLWriter::EndNode(writer, "PropertyBag");
  if ( v8 )
    operator delete[](v8);
}

// File Line: 581
// RVA: 0x1A3560
bool __fastcall DNA::Database::SaveToBuffer(
        DNA::Database *this,
        const char **buffer,
        unsigned int *buffer_size,
        DNA::PropertyBag *propertyBag)
{
  SimpleXML::XMLWriter *v7; // rax
  SimpleXML::XMLWriter *writer[2]; // [rsp+20h] [rbp-48h] BYREF
  DNA::PropertyBagWrapper wrapper; // [rsp+30h] [rbp-38h] BYREF

  writer[1] = (SimpleXML::XMLWriter *)-2i64;
  v7 = SimpleXML::XMLWriter::CreateBuffer(0x400u, 1);
  writer[0] = v7;
  if ( v7 )
  {
    SimpleXML::XMLWriter::BeginNode(v7, "DNAFile");
    DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, propertyBag);
    DNA::SaveWrapper(writer[0], &wrapper);
    SimpleXML::XMLWriter::EndNode(writer[0], "DNAFile");
    *buffer = SimpleXML::XMLWriter::CloseBuffer((SimpleXML::XMLWriterData ***)writer, buffer_size);
    writer[0] = 0i64;
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 603
// RVA: 0x1A2BF0
unsigned __int64 __fastcall DNA::Database::GenUID(DNA::Database *this)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  char *mData; // rdi
  unsigned __int64 Ticks; // rax
  unsigned __int64 v5; // rdi
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  do
  {
    do
    {
      mData = UFG::qGetUserName(&result)->mData;
      Ticks = UFG::qGetTicks();
      v5 = UFG::qStringHash64(mData, Ticks) ^ 0x7FFFFFFFFFFFFFE7i64;
      UFG::qString::~qString(&result);
    }
    while ( UFG::qTree64Base::Get(&this->mPropertyBags.mTree, v5) );
  }
  while ( UFG::qTree64Base::Get(&this->mPropertyBagsInternal.mTree, v5) );
  UFG::qMutex::Unlock(p_mMutex);
  return v5;
}

// File Line: 625
// RVA: 0x1A26F0
DNA::PropertyBag *__fastcall DNA::Database::CreateBag(
        DNA::Database *this,
        const char *name,
        const char *schemaName,
        char *filePath,
        unsigned __int64 id)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  UFG::allocator::free_link *v10; // rax
  unsigned int v11; // edi
  DNA::PropertyBag *v12; // rax
  DNA::PropertyBag *v13; // rsi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *v14; // rcx
  UFG::qString result; // [rsp+30h] [rbp-48h] BYREF

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  UFG::qCleanupFilepath(&result, filePath, 92);
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
  DNA::PropertyBag::SetName(v13, name);
  DNA::PropertyBag::SetSchemaName(v13, schemaName);
  DNA::PropertyBag::SetFilePath(v13, result.mData);
  UFG::qTree64Base::Add(&this->mPropertyBags.mTree, &v13->mBaseNode);
  if ( this->PropertyBagCreated.mDelegates.size )
  {
    do
    {
      v14 = &this->PropertyBagCreated.mDelegates.p[v11];
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, DNA::PropertyBag *))v14->m_Closure.m_pFunction)(
        v14->m_Closure.m_pthis,
        v13);
      ++v11;
    }
    while ( v11 < this->PropertyBagCreated.mDelegates.size );
  }
  UFG::qString::~qString(&result);
  UFG::qMutex::Unlock(p_mMutex);
  return v13;
}

// File Line: 643
// RVA: 0x1A2810
DNA::PropertyBag *__fastcall DNA::Database::CreateBag(
        DNA::Database *this,
        const char *name,
        const char *schemaName,
        DNA::PropertyBag *owner)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  UFG::allocator::free_link *v9; // rsi
  unsigned int v10; // edi
  unsigned __int64 v11; // rax
  DNA::PropertyBag *v12; // rax
  DNA::PropertyBag *v13; // rsi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *v14; // rcx

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v9 = UFG::qMalloc(0x80ui64, "DNA::PropertyBag", 0i64);
  v10 = 0;
  if ( v9 )
  {
    v11 = DNA::Database::GenUID(this);
    DNA::PropertyBag::PropertyBag((DNA::PropertyBag *)v9, v11);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  DNA::PropertyBag::SetName(v13, name);
  DNA::PropertyBag::SetSchemaName(v13, schemaName);
  DNA::PropertyBag::SetOwner(v13, owner);
  UFG::qTree64Base::Add(&this->mPropertyBagsInternal.mTree, &v13->mBaseNode);
  if ( this->PropertyBagCreated.mDelegates.size )
  {
    do
    {
      v14 = &this->PropertyBagCreated.mDelegates.p[v10];
      ((void (__fastcall *)(fastdelegate::detail::GenericClass *, DNA::PropertyBag *))v14->m_Closure.m_pFunction)(
        v14->m_Closure.m_pthis,
        v13);
      ++v10;
    }
    while ( v10 < this->PropertyBagCreated.mDelegates.size );
  }
  UFG::qMutex::Unlock(p_mMutex);
  return v13;
}

// File Line: 660
// RVA: 0x1A2A00
void __fastcall DNA::Database::DeleteBag(DNA::Database *this, UFG::qTree64Base *bag)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  unsigned int i; // esi
  fastdelegate::FastDelegate1<DNA::PropertyBag *,void> *v6; // rcx

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  for ( i = 0; i < this->PropertyBagDeleted.mDelegates.size; ++i )
  {
    v6 = &this->PropertyBagDeleted.mDelegates.p[i];
    ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::qTree64Base *))v6->m_Closure.m_pFunction)(
      v6->m_Closure.m_pthis,
      bag);
  }
  if ( UFG::qTree64Base::Contains(&this->mPropertyBags.mTree, bag->mHead.mUID) )
    UFG::qTree64Base::Remove(&this->mPropertyBags.mTree, bag);
  if ( UFG::qTree64Base::Contains(&this->mPropertyBagsInternal.mTree, bag->mHead.mUID) )
    UFG::qTree64Base::Remove(&this->mPropertyBagsInternal.mTree, bag);
  DNA::PropertyBag::~PropertyBag((DNA::PropertyBag *)bag);
  operator delete[](bag);
  UFG::qMutex::Unlock(p_mMutex);
}

// File Line: 769
// RVA: 0x1A3370
void __fastcall DNA::Database::OnOwnerChanged(DNA::Database *this, UFG::qTree64Base *bag, DNA::PropertyBag *owner)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  unsigned __int64 mUID; // rdx
  UFG::qTree64<DNA::PropertyBag,DNA::PropertyBag,0> *p_mPropertyBagsInternal; // rcx

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  mUID = bag->mHead.mUID;
  if ( owner )
  {
    if ( UFG::qTree64Base::Contains(&this->mPropertyBags.mTree, mUID) )
    {
      UFG::qTree64Base::Remove(&this->mPropertyBags.mTree, bag);
      p_mPropertyBagsInternal = &this->mPropertyBagsInternal;
LABEL_6:
      UFG::qTree64Base::Add(&p_mPropertyBagsInternal->mTree, &bag->mHead);
    }
  }
  else if ( UFG::qTree64Base::Contains(&this->mPropertyBagsInternal.mTree, mUID) )
  {
    UFG::qTree64Base::Remove(&this->mPropertyBagsInternal.mTree, bag);
    p_mPropertyBagsInternal = &this->mPropertyBags;
    goto LABEL_6;
  }
  UFG::qMutex::Unlock(p_mMutex);
}

// File Line: 794
// RVA: 0x1A2CE0
UFG::qTree64Base *__fastcall DNA::Database::GetPropertyBag(DNA::Database *this, unsigned __int64 uid)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  UFG::qTree64Base *v5; // rdi

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v5 = UFG::qTree64Base::Get(&this->mPropertyBags.mTree, uid);
  if ( !v5 )
    v5 = UFG::qTree64Base::Get(&this->mPropertyBagsInternal.mTree, uid);
  UFG::qMutex::Unlock(p_mMutex);
  return v5;
}

// File Line: 806
// RVA: 0x1A2D70
void __fastcall DNA::Database::GetPropertyBags(
        DNA::Database *this,
        DNA::Query *query,
        UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *propertyBags)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  DNA::PropertyBag *i; // rdi
  DNA::PropertyBagHandle *v8; // rax
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mPrev; // rcx

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  for ( i = (DNA::PropertyBag *)UFG::qTree64Base::GetHead(&this->mPropertyBags.mTree);
        i;
        i = (DNA::PropertyBag *)UFG::qTree64Base::GetNext(&this->mPropertyBags.mTree, &i->mBaseNode) )
  {
    if ( query->mRoot
      && ((__int64 (__fastcall *)(DNA::IQueryNode *, DNA::PropertyBag *))query->mRoot->vfptr->Match)(query->mRoot, i) )
    {
      v8 = (DNA::PropertyBagHandle *)UFG::qMalloc(0x20ui64, "DNA::PropertyBagHandle", 0i64);
      if ( v8 )
        DNA::PropertyBagHandle::PropertyBagHandle(v8, i);
      mPrev = propertyBags->mNode.mPrev;
      mPrev->mNext = v8;
      v8->mPrev = mPrev;
      v8->mNext = &propertyBags->mNode;
      propertyBags->mNode.mPrev = v8;
    }
  }
  UFG::qMutex::Unlock(p_mMutex);
}

// File Line: 819
// RVA: 0x1A3140
__int64 __fastcall DNA::Database::LoadReflectionDatabase(
        DNA::Database *this,
        const char *filePath,
        bool validate_type_sizes)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx
  UFG::ReflectionDB *v7; // rax
  unsigned __int8 v8; // r12
  UFG::ReflectionDB *v9; // rax
  UFG::qReflectType *Head; // rsi
  unsigned __int64 mUID; // rdi
  UFG::ReflectionDB *v12; // rax
  UFG::qTree64Base *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::ReflectionDB *v15; // rax
  UFG::ReflectionDB *v16; // rax
  UFG::qReflectEnum *Next; // r14
  UFG::allocator::free_link *v18; // rax
  UFG::qTree64Base::BaseNode *v19; // rax
  UFG::qTree64Base::BaseNode *v20; // rsi
  UFG::allocator::free_link *mNext; // rdi
  UFG::allocator::free_link *p_mParent; // rsi
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rcx
  UFG::ReflectionDB *v25; // rax
  UFG::ReflectionDB *v26; // rax

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  v7 = UFG::ReflectionDB::Instance();
  v8 = UFG::ReflectionDB::Load(v7, filePath);
  if ( v8 )
  {
    v9 = UFG::ReflectionDB::Instance();
    Head = (UFG::qReflectType *)UFG::qTree64Base::GetHead(&v9->mTypes.mTree);
    UFG::ReflectionDB::Instance();
    while ( Head )
    {
      mUID = Head->mBaseNode.mUID;
      v12 = UFG::ReflectionDB::Instance();
      v13 = UFG::qTree64Base::Get(&v12->mSchemas.mTree, mUID);
      v14 = UFG::qMalloc(0xE8ui64, "Database::SchemaType", 0i64);
      if ( v14 )
        DNA::SchemaType::SchemaType((DNA::SchemaType *)v14, Head, (UFG::qReflectSchema *)v13);
      UFG::qTree64Base::Add(&this->mSchemaTypes.mTree, (UFG::qTree64Base::BaseNode *)v14);
      v15 = UFG::ReflectionDB::Instance();
      Head = (UFG::qReflectType *)UFG::qTree64Base::GetNext(&v15->mTypes.mTree, &Head->mBaseNode);
      UFG::ReflectionDB::Instance();
    }
    v16 = UFG::ReflectionDB::Instance();
    Next = (UFG::qReflectEnum *)UFG::qTree64Base::GetHead(&v16->mEnums.mTree);
    UFG::ReflectionDB::Instance();
    while ( Next )
    {
      v18 = UFG::qMalloc(0x48ui64, "Database::SchemaEnum", 0i64);
      if ( v18 )
      {
        DNA::SchemaEnum::SchemaEnum((DNA::SchemaEnum *)v18, Next);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      UFG::qTree64Base::Add(&this->mSchemaEnums.mTree, v20);
      mNext = (UFG::allocator::free_link *)Next->mValues.mNode.mNext;
      if ( mNext != (UFG::allocator::free_link *)&Next->mValues )
      {
        p_mParent = (UFG::allocator::free_link *)&v20[1].mParent;
        do
        {
          v23 = UFG::qMalloc(0x50ui64, "Database::SchemaEnumValue", 0i64);
          if ( v23 )
          {
            v23->mNext = v23;
            v23[1].mNext = v23;
            v23[2].mNext = mNext;
            v23[3].mNext = 0i64;
            v23[4].mNext = v23 + 3;
            v23[5].mNext = v23 + 3;
            v23[6].mNext = v23 + 3;
            v23[7].mNext = v23 + 3;
            v23[8].mNext = v23 + 3;
            v23[9].mNext = 0i64;
          }
          v24 = p_mParent->mNext;
          v24[1].mNext = v23;
          v23->mNext = v24;
          v23[1].mNext = p_mParent;
          p_mParent->mNext = v23;
          mNext = mNext[1].mNext;
        }
        while ( mNext != (UFG::allocator::free_link *)&Next->mValues );
      }
      v25 = UFG::ReflectionDB::Instance();
      Next = (UFG::qReflectEnum *)UFG::qTree64Base::GetNext(&v25->mEnums.mTree, &Next->mBaseNode);
      UFG::ReflectionDB::Instance();
    }
    if ( validate_type_sizes )
    {
      v26 = UFG::ReflectionDB::Instance();
      UFG::ReflectionDB::ValidateClassSizes(v26);
    }
  }
  UFG::qMutex::Unlock(p_mMutex);
  return v8;
}

// File Line: 855
// RVA: 0x1A2CB0
UFG::qTree64Base *__fastcall DNA::Database::GetEnum(DNA::Database *this, const char *enumName)
{
  unsigned __int64 v3; // rax

  v3 = UFG::qStringHash64(enumName, 0xFFFFFFFFFFFFFFFFui64);
  return UFG::qTree64Base::Get(&this->mSchemaEnums.mTree, v3);
}

// File Line: 865
// RVA: 0x1A2E50
UFG::qTree64Base *__fastcall DNA::Database::GetSchema(DNA::Database *this, const char *schemaName)
{
  unsigned __int64 v3; // rax

  v3 = UFG::qStringHash64(schemaName, 0xFFFFFFFFFFFFFFFFui64);
  return UFG::qTree64Base::Get(&this->mSchemaTypes.mTree, v3);
}

// File Line: 995
// RVA: 0x1A3420
void __fastcall DNA::Database::OnStructureChanged(DNA::Database *this, DNA::PropertyData *data)
{
  _RTL_CRITICAL_SECTION *p_mMutex; // rbx

  p_mMutex = (_RTL_CRITICAL_SECTION *)&this->mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mMutex);
  UFG::qMutex::Unlock(p_mMutex);
}

