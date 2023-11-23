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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsVolumePropertyManager::mGuidTranslation__);
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
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rsi
  UFG::qTree64Base *Head; // rax
  UFG::qReflectObject *p_mCount; // rdi
  SimpleXML::XMLDocument *v5; // rax
  UFG::qBaseNodeRB *v6; // rbx
  const char *Name; // rax
  UFG::qTree64Base *Next; // rax
  SimpleXML::XMLDocument *xmlFile; // [rsp+40h] [rbp+8h] BYREF

  v0 = UFG::qStringHash64("UFG::PhysicsVolumeProperties", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v1, v0)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = (UFG::qReflectObject *)&Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        v5 = (SimpleXML::XMLDocument *)UFG::qMalloc(0x28ui64, "PhysicsVolumeProperties::LookupNode", 0i64);
        v6 = (UFG::qBaseNodeRB *)v5;
        xmlFile = v5;
        if ( v5 )
        {
          v5->mData = 0i64;
          v5->mPool = 0i64;
          v5[1].mData = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        Name = UFG::qReflectObject::GetName(p_mCount);
        v6->mUID = UFG::qStringHashUpper32(Name, 0xFFFFFFFF);
        v6[1].mParent = (UFG::qBaseNodeRB *)p_mCount->mBaseNode.mUID;
        UFG::qBaseTreeRB::Add(&UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree, v6);
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, &p_mCount->mBaseNode);
        if ( !Next )
          break;
        p_mCount = (UFG::qReflectObject *)&Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
  xmlFile = 0i64;
  UFG::PhysicsVolumePropertyManager::FireHitRecordType = UFG::PhysicsVolumePropertyManager::GetEnumIndex(
                                                           &xmlFile,
                                                           "FireDamage");
}

// File Line: 210
// RVA: 0xA9EB0
__int64 __fastcall UFG::PhysicsVolumePropertyManager::GetEnumIndex(
        SimpleXML::XMLDocument **xmlFile,
        const char *enumEntryName)
{
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *Node; // rbx
  char *Name; // rax
  int v7; // eax
  SimpleXML::XMLDocument *v8; // rcx
  unsigned int v9; // esi
  SimpleXML::XMLNode *v10; // rbx
  char *Attribute; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h] BYREF

  if ( !*xmlFile )
  {
    UFG::qString::qString(&v13, "Data\\Global\\Act\\AttackCollisionTypes.xml");
    *xmlFile = SimpleXML::XMLDocument::Open(v13.mData, 1ui64, 0i64);
    UFG::qString::~qString(&v13);
  }
  if ( !*xmlFile )
    return 0xFFFFFFFFi64;
  ChildNode = SimpleXML::XMLDocument::GetChildNode(*xmlFile, 0i64, 0i64);
  if ( !ChildNode )
    return 0xFFFFFFFFi64;
  Node = SimpleXML::XMLDocument::GetChildNode(*xmlFile, 0i64, ChildNode);
  if ( !Node )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    Name = SimpleXML::XMLNode::GetName(Node);
    v7 = UFG::qStringCompare(Name, "AttackType", -1);
    v8 = *xmlFile;
    if ( !v7 )
      break;
    Node = SimpleXML::XMLDocument::GetNode(v8, 0i64, Node);
    if ( !Node )
      return 0xFFFFFFFFi64;
  }
  v9 = 0;
  v10 = SimpleXML::XMLDocument::GetChildNode(v8, 0i64, Node);
  if ( !v10 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    Attribute = SimpleXML::XMLNode::GetAttribute(v10, "name");
    if ( !(unsigned int)UFG::qStringCompare(Attribute, enumEntryName, -1) )
      break;
    ++v9;
    v10 = SimpleXML::XMLDocument::GetNode(*xmlFile, 0i64, v10);
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
  unsigned __int64 mParent; // rbx
  UFG::qReflectObject *mData; // rbx
  UFG::qReflectHandleBase v6; // [rsp+28h] [rbp-30h] BYREF

  if ( uid )
  {
    v2 = UFG::qBaseTreeRB::Get(&UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree, uid);
    if ( v2 )
    {
      mParent = (unsigned __int64)v2->mNULL.mParent;
      UFG::qReflectHandleBase::qReflectHandleBase(&v6);
      v6.mTypeUID = UFG::qStringHash64("UFG::PhysicsVolumeProperties", 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v6, v6.mTypeUID, mParent);
      mData = v6.mData;
      if ( v6.mData )
      {
        UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
        return mData;
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
    }
  }
  return 0i64;
}

