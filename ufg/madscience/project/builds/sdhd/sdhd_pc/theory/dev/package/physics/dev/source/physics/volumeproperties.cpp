// File Line: 26
// RVA: 0x14588B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::PhysicsVolumeProperties_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::PhysicsVolumeProperties,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 33
// RVA: 0x14584A0
__int64 dynamic_initializer_for__UFG::PhysicsVolumePropertyManager::mGuidTranslation__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsVolumePropertyManager::mGuidTranslation__);
}

// File Line: 37
// RVA: 0xACA00
void UFG::PhysicsVolumePropertyManager::Initialize(void)
{
  DNA::Database *v0; // rax
  unsigned __int64 v1; // rdi
  char *v2; // rax
  UFG::qBaseNodeRB *v3; // rbx

  v0 = DNA::Database::Instance();
  v1 = DNA::Database::GenUID(v0);
  v2 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x80ui64, "PhysicsVolumeProperties", 0i64, 1u);
  if ( v2 )
    UFG::PhysicsVolumeProperties::PhysicsVolumeProperties((UFG::PhysicsVolumeProperties *)v2, "default", v1);
  v3 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v3 )
  {
    v3->mParent = 0i64;
    v3->mChild[0] = 0i64;
    v3->mChild[1] = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  v3[1].mParent = (UFG::qBaseNodeRB *)v1;
  v3->mUID = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
  UFG::qBaseTreeRB::Add(&UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree, v3);
}

// File Line: 59
// RVA: 0xAD060
void UFG::PhysicsVolumePropertyManager::LoadDefinitionsFromInventory(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qReflectInventoryBase *v2; // rax
  UFG::qTree64Base *v3; // rsi
  UFG::qTree64Base *v4; // rax
  UFG::qReflectObject *v5; // rdi
  SimpleXML::XMLDocument *v6; // rax
  UFG::qBaseNodeRB *v7; // rbx
  const char *v8; // rax
  UFG::qTree64Base *v9; // rax
  SimpleXML::XMLDocument *xmlFile; // [rsp+40h] [rbp+8h]

  v0 = UFG::qStringHash64("UFG::PhysicsVolumeProperties", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  v2 = UFG::qReflectWarehouse::GetInventory(v1, v0);
  v3 = &v2->mItems.mTree;
  v4 = UFG::qTree64Base::GetHead(&v2->mItems.mTree);
  if ( v4 )
  {
    v5 = (UFG::qReflectObject *)&v4[-1].mCount;
    if ( v4 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v6 = (SimpleXML::XMLDocument *)UFG::qMalloc(0x28ui64, "PhysicsVolumeProperties::LookupNode", 0i64);
        v7 = (UFG::qBaseNodeRB *)v6;
        xmlFile = v6;
        if ( v6 )
        {
          v6->mData = 0i64;
          v6->mPool = 0i64;
          v6[1].mData = 0i64;
        }
        else
        {
          v7 = 0i64;
        }
        v8 = UFG::qReflectObject::GetName(v5);
        v7->mUID = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
        v7[1].mParent = (UFG::qBaseNodeRB *)v5->mBaseNode.mUID;
        UFG::qBaseTreeRB::Add(&UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree, v7);
        v9 = UFG::qTree64Base::GetNext(v3, &v5->mBaseNode);
        if ( !v9 )
          break;
        v5 = (UFG::qReflectObject *)&v9[-1].mCount;
      }
      while ( v9 != (UFG::qTree64Base *)8 );
    }
  }
  xmlFile = 0i64;
  UFG::PhysicsVolumePropertyManager::FireHitRecordType = UFG::PhysicsVolumePropertyManager::GetEnumIndex(
                                                           &xmlFile,
                                                           "FireDamage");
}

// File Line: 210
// RVA: 0xA9EB0
signed __int64 __fastcall UFG::PhysicsVolumePropertyManager::GetEnumIndex(SimpleXML::XMLDocument **xmlFile, const char *enumEntryName)
{
  const char *v2; // rbp
  SimpleXML::XMLDocument **v3; // rdi
  SimpleXML::XMLNode *v4; // rax
  SimpleXML::XMLNode *v5; // rbx
  char *v6; // rax
  int v7; // eax
  SimpleXML::XMLDocument *v8; // rcx
  unsigned int v9; // esi
  SimpleXML::XMLNode *v10; // rbx
  char *v11; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h]

  v2 = enumEntryName;
  v3 = xmlFile;
  if ( !*xmlFile )
  {
    UFG::qString::qString(&v13, "Data\\Global\\Act\\AttackCollisionTypes.xml");
    *v3 = SimpleXML::XMLDocument::Open(v13.mData, 1ui64, 0i64);
    UFG::qString::~qString(&v13);
  }
  if ( !*v3 )
    return 0xFFFFFFFFi64;
  v4 = SimpleXML::XMLDocument::GetChildNode(*v3, 0i64, 0i64);
  if ( !v4 )
    return 0xFFFFFFFFi64;
  v5 = SimpleXML::XMLDocument::GetChildNode(*v3, 0i64, v4);
  if ( !v5 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v6 = SimpleXML::XMLNode::GetName(v5);
    v7 = UFG::qStringCompare(v6, "AttackType", -1);
    v8 = *v3;
    if ( !v7 )
      break;
    v5 = SimpleXML::XMLDocument::GetNode(v8, 0i64, v5);
    if ( !v5 )
      return 0xFFFFFFFFi64;
  }
  v9 = 0;
  v10 = SimpleXML::XMLDocument::GetChildNode(v8, 0i64, v5);
  if ( !v10 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v11 = SimpleXML::XMLNode::GetAttribute(v10, "name");
    if ( !(unsigned int)UFG::qStringCompare(v11, v2, -1) )
      break;
    ++v9;
    v10 = SimpleXML::XMLDocument::GetNode(*v3, 0i64, v10);
    if ( !v10 )
      return 0xFFFFFFFFi64;
  }
  return v9;
}

// File Line: 262
// RVA: 0xA8380
UFG::qReflectObject *__fastcall UFG::PhysicsVolumePropertyManager::Find(unsigned int uid, bool allowDefault)
{
  UFG::qBaseTreeRB *v2; // rax
  unsigned __int64 v3; // rbx
  UFG::qReflectObject *v4; // rbx
  UFG::qReflectHandleBase v6; // [rsp+28h] [rbp-30h]

  if ( uid )
  {
    v2 = UFG::qBaseTreeRB::Get(&UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree, uid);
    if ( v2 )
    {
      v3 = (unsigned __int64)v2->mNULL.mParent;
      UFG::qReflectHandleBase::qReflectHandleBase(&v6);
      v6.mTypeUID = UFG::qStringHash64("UFG::PhysicsVolumeProperties", 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v6, v6.mTypeUID, v3);
      v4 = v6.mData;
      if ( v6.mData )
      {
        UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
        return v4;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
    }
  }
  return 0i64;
}

