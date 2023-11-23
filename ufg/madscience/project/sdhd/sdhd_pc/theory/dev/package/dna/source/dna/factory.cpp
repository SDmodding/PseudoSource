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

  v1 = UFG::qTree64Base::Get(&DNA::DNAFactory::sInstance->mLoadedContent.mTree, object->mBaseNode.mUID);
  return !v1 || v1 == (UFG::qTree64Base *)136;
}

// File Line: 68
// RVA: 0x1AF290
UFG::qReflectObject *__fastcall DNA::DNAFactory::CreateObject(
        DNA::DNAFactory *this,
        unsigned __int64 type_uid,
        const char *name)
{
  UFG::allocator::free_link *v6; // rax
  DNA::DNAFactory::CreatedContent *v7; // rbx
  UFG::allocator::free_link *v8; // rax
  DNA::Database *v9; // rax
  unsigned __int64 v10; // rax

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
    v7->mObjectLookup.mBaseNode.mUID = 0i64;
    v7->mObjectLookup.mBaseNode.mParent = &v7->mObjectLookup.mBaseNode;
    v7->mObjectLookup.mBaseNode.mChildren[0] = &v7->mObjectLookup.mBaseNode;
    v7->mObjectLookup.mBaseNode.mChildren[1] = &v7->mObjectLookup.mBaseNode;
    v7->mObjectLookup.mBaseNode.mNeighbours[0] = &v7->mObjectLookup.mBaseNode;
    v7->mObjectLookup.mBaseNode.mNeighbours[1] = &v7->mObjectLookup.mBaseNode;
  }
  else
  {
    v7 = 0i64;
  }
  DNA::Database::Instance();
  v10 = DNA::Database::GenUID(v9);
  v7->mBaseNode.mUID = v10;
  DNA::DNAFactory::CreatedContent::CreateObject(v7, type_uid, v10, name);
  UFG::qTree64Base::Add(&this->mCreatedContent.mTree, &v7->mBaseNode);
  return v7->mObject;
}

// File Line: 80
// RVA: 0x1AF250
UFG::qReflectObject *__fastcall DNA::DNAFactory::CreateObject(
        DNA::DNAFactory *this,
        const char *type_name,
        const char *name)
{
  unsigned __int64 v5; // rax

  v5 = UFG::qStringHash64(type_name, 0xFFFFFFFFFFFFFFFFui64);
  return DNA::DNAFactory::CreateObject(this, v5, name);
}

// File Line: 209
// RVA: 0x1AF1A0
void __fastcall DNA::DNAFactory::CreatedContent::CreateObject(
        DNA::DNAFactory::CreatedContent *this,
        unsigned __int64 type_uid,
        unsigned __int64 name_uid,
        const char *name)
{
  UFG::qTree64Base *v7; // rax
  UFG::qReflectObject *v8; // rax
  UFG::qReflectWarehouse *v9; // rax
  UFG::qReflectInventoryBase *Inventory; // rbx

  this->mTypeUID = type_uid;
  v7 = UFG::qTree64Base::Get(&UFG::FactoryOperation::sOperations->mTree, type_uid);
  if ( v7 )
  {
    v8 = (UFG::qReflectObject *)((__int64 (__fastcall *)(unsigned __int64))v7->mCount)(name_uid);
    this->mNameLookup.mName = name;
    this->mNameLookup.mBaseNode.mUID = name_uid;
    this->mObjectLookup.mNameUID = name_uid;
    this->mObject = v8;
    this->mObjectLookup.mBaseNode.mUID = UFG::qStringHash64(name, 0xFFFFFFFFFFFFFFFFui64);
    v9 = UFG::qReflectWarehouse::Instance();
    Inventory = UFG::qReflectWarehouse::GetInventory(v9, this->mTypeUID);
    UFG::qReflectInventoryBase::AddLookup(Inventory, &this->mNameLookup, &this->mObjectLookup);
    UFG::qReflectInventoryBase::Add(Inventory, this->mObject);
  }
}

