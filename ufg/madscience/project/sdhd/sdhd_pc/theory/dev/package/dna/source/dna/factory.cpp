// File Line: 23
// RVA: 0x1AF380
void DNA::DNAFactory::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  DNA::DNAFactory *v1; // rcx
  UFG::allocator::free_link *v2; // rax

  v0 = UFG::qMalloc(0x70ui64, UFG::gGlobalNewName, 0i64);
  v1 = (DNA::DNAFactory *)v0;
  if ( v0 )
  {
    v0->mNext = 0i64;
    v0[1].mNext = v0;
    v0[2].mNext = v0;
    v0[3].mNext = v0;
    v0[4].mNext = v0;
    v0[5].mNext = v0;
    v0[6].mNext = 0i64;
    v2 = v0 + 7;
    v2->mNext = 0i64;
    v2[1].mNext = v2;
    v2[2].mNext = v2;
    v2[3].mNext = v2;
    v2[4].mNext = v2;
    v2[5].mNext = v2;
    v2[6].mNext = 0i64;
    UFG::qReflectInventoryBase::sFilterFunc = DNA::DNAFactory::InventoryFilterFunction;
    DNA::DNAFactory::sInstance = v1;
  }
  else
  {
    DNA::DNAFactory::sInstance = 0i64;
  }
}

// File Line: 41
// RVA: 0x1AF410
DNA::DNAFactory *__fastcall DNA::DNAFactory::Instance()
{
  return DNA::DNAFactory::sInstance;
}

// File Line: 61
// RVA: 0x1AF420
bool __fastcall DNA::DNAFactory::InventoryFilterFunction(UFG::qReflectObject *object)
{
  UFG::qTree64Base *v1; // rcx
  bool result; // al

  v1 = UFG::qTree64Base::Get(&DNA::DNAFactory::sInstance->mLoadedContent.mTree, object->mBaseNode.mUID);
  if ( v1 )
    result = v1 == (UFG::qTree64Base *)136;
  else
    result = 1;
  return result;
}

// File Line: 68
// RVA: 0x1AF290
UFG::qReflectObject *__fastcall DNA::DNAFactory::CreateObject(DNA::DNAFactory *this, unsigned __int64 type_uid, const char *name)
{
  const char *v3; // rdi
  unsigned __int64 v4; // rsi
  DNA::DNAFactory *v5; // rbp
  UFG::allocator::free_link *v6; // rax
  DNA::DNAFactory::CreatedContent *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  UFG::qReflectInventoryBase::ObjectLookup *v9; // rax
  DNA::Database *v10; // rax
  unsigned __int64 v11; // rax

  v3 = name;
  v4 = type_uid;
  v5 = this;
  v6 = UFG::qMalloc(0xB0ui64, UFG::gGlobalNewName, 0i64);
  v7 = (DNA::DNAFactory::CreatedContent *)v6;
  if ( v6 )
  {
    v6->mNext = 0i64;
    v6[1].mNext = v6;
    v6[2].mNext = v6;
    v6[3].mNext = v6;
    v6[4].mNext = v6;
    v6[5].mNext = v6;
    v6[6].mNext = (UFG::allocator::free_link *)-1i64;
    v6[7].mNext = 0i64;
    v8 = v6 + 8;
    v8->mNext = 0i64;
    v8[1].mNext = v8;
    v8[2].mNext = v8;
    v8[3].mNext = v8;
    v8[4].mNext = v8;
    v8[5].mNext = v8;
    v9 = &v7->mObjectLookup;
    v9->mBaseNode.mUID = 0i64;
    v9->mBaseNode.mParent = &v9->mBaseNode;
    v9->mBaseNode.mChildren[0] = &v9->mBaseNode;
    v9->mBaseNode.mChildren[1] = &v9->mBaseNode;
    v9->mBaseNode.mNeighbours[0] = &v9->mBaseNode;
    v9->mBaseNode.mNeighbours[1] = &v9->mBaseNode;
  }
  else
  {
    v7 = 0i64;
  }
  DNA::Database::Instance();
  v11 = DNA::Database::GenUID(v10);
  v7->mBaseNode.mUID = v11;
  DNA::DNAFactory::CreatedContent::CreateObject(v7, v4, v11, v3);
  UFG::qTree64Base::Add(&v5->mCreatedContent.mTree, &v7->mBaseNode);
  return v7->mObject;
}

// File Line: 80
// RVA: 0x1AF250
UFG::qReflectObject *__fastcall DNA::DNAFactory::CreateObject(DNA::DNAFactory *this, const char *type_name, const char *name)
{
  DNA::DNAFactory *v3; // rbx
  const char *v4; // rdi
  unsigned __int64 v5; // rax

  v3 = this;
  v4 = name;
  v5 = UFG::qStringHash64(type_name, 0xFFFFFFFFFFFFFFFFui64);
  return DNA::DNAFactory::CreateObject(v3, v5, v4);
}

// File Line: 209
// RVA: 0x1AF1A0
void __fastcall DNA::DNAFactory::CreatedContent::CreateObject(DNA::DNAFactory::CreatedContent *this, unsigned __int64 type_uid, unsigned __int64 name_uid, const char *name)
{
  DNA::DNAFactory::CreatedContent *v4; // rbp
  const char *v5; // r14
  unsigned __int64 v6; // rbx
  UFG::qTree64Base *v7; // rax
  __int64 v8; // rax
  UFG::qReflectWarehouse *v9; // rax
  UFG::qReflectInventoryBase *v10; // rbx

  v4 = this;
  this->mTypeUID = type_uid;
  v5 = name;
  v6 = name_uid;
  v7 = UFG::qTree64Base::Get(&UFG::FactoryOperation::sOperations->mTree, type_uid);
  if ( v7 )
  {
    v8 = ((__int64 (__fastcall *)(unsigned __int64))v7->mCount)(v6);
    v4->mNameLookup.mName = v5;
    v4->mNameLookup.mBaseNode.mUID = v6;
    v4->mObjectLookup.mNameUID = v6;
    v4->mObject = (UFG::qReflectObject *)v8;
    v4->mObjectLookup.mBaseNode.mUID = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
    v9 = UFG::qReflectWarehouse::Instance();
    v10 = UFG::qReflectWarehouse::GetInventory(v9, v4->mTypeUID);
    UFG::qReflectInventoryBase::AddLookup(v10, &v4->mNameLookup, &v4->mObjectLookup);
    UFG::qReflectInventoryBase::Add(v10, v4->mObject);
  }
}

