// File Line: 26
// RVA: 0x160A70
void __fastcall UFG::SerializeOperation::SerializeOperation(UFG::SerializeOperation *this, unsigned __int64 type_uid, void (__fastcall *load)(char *), void (__fastcall *unload)(char *))
{
  UFG::SerializeOperation *v4; // rbx
  UFG::qOpRegistry *v5; // rax

  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mOnLoadFunc = load;
  this->mOnUnloadFunc = unload;
  this->mBaseNode.mUID = type_uid;
  v4 = this;
  v5 = UFG::qOpRegistry::Instance();
  UFG::qTree64Base::Add(&v5->mOpTree.mTree, &v4->mBaseNode);
}

// File Line: 37
// RVA: 0x15FF50
void __fastcall UFG::EditNotification::EditNotification(UFG::EditNotification *this, unsigned __int64 type_uid, void (__fastcall *changed)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *), void (__fastcall *reload)(char *, void *), void *user_data)
{
  UFG::EditNotification *v5; // rbx
  UFG::qOpRegistry *v6; // rax
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v7; // rcx
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v8; // rax

  v5 = this;
  this->mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&this->mPrev;
  this->mTypeUID = type_uid;
  this->mUserData = user_data;
  this->mOnPropertyChangedFunc = changed;
  this->mOnObjectReloadedFunc = reload;
  v6 = UFG::qOpRegistry::Instance();
  v7 = &v6->mNotificationList.mNode;
  v8 = v6->mNotificationList.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&v5->mPrev;
  v5->mPrev = v8;
  v5->mNext = v7;
  v7->mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&v5->mPrev;
}

// File Line: 42
// RVA: 0x162DD0
void __fastcall UFG::EditNotification::~EditNotification(UFG::EditNotification *this)
{
  UFG::EditNotification *v1; // rbx
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v2; // rdx
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v3; // rax
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v4; // rdx
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v5; // rax

  v1 = this;
  UFG::qOpRegistry::Instance();
  v2 = v1->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&v1->mPrev;
}

// File Line: 57
// RVA: 0x173F20
UFG::qOpRegistry *__fastcall UFG::qOpRegistry::Instance()
{
  if ( !(_S10_0 & 1) )
  {
    _S10_0 |= 1u;
    sOpsInstance.mOpTree.mTree.mHead.mUID = 0i64;
    unk_14235BC68 = &sOpsInstance;
    unk_14235BC70 = &sOpsInstance;
    unk_14235BC78 = &sOpsInstance;
    unk_14235BC80 = &sOpsInstance;
    unk_14235BC88 = &sOpsInstance;
    unk_14235BC90 = 0i64;
    stru_14235BC98.mNode.mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&stru_14235BC98;
    stru_14235BC98.mNode.mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&stru_14235BC98;
    atexit(UFG::qOpRegistry::Instance_::_2_::_dynamic_atexit_destructor_for__sOpsInstance__);
  }
  return &sOpsInstance;
}

// File Line: 89
// RVA: 0x178750
void __fastcall UFG::OnLoadHandle(char *object_data)
{
  if ( object_data )
  {
    *(_QWORD *)object_data = object_data;
    *((_QWORD *)object_data + 1) = object_data;
  }
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)object_data,
    *((_QWORD *)object_data + 2),
    *((_QWORD *)object_data + 3));
}

// File Line: 99
// RVA: 0x1467DD0
void UFG::_dynamic_initializer_for__gHandleSerialize__()
{
  const char *v0; // r8
  unsigned __int64 v1; // rax
  char v2; // cl
  UFG::qOpRegistry *v3; // rax

  v0 = "UFG::qReflectHandleBase";
  v1 = -1i64;
  v2 = 85;
  do
  {
    ++v0;
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *v0;
  }
  while ( *v0 );
  UFG::gHandleSerialize.mBaseNode.mUID = v1;
  v3 = UFG::qOpRegistry::Instance();
  UFG::qTree64Base::Add(&v3->mOpTree.mTree, &UFG::gHandleSerialize.mBaseNode);
}

// File Line: 102
// RVA: 0x178790
void __fastcall UFG::OnLoadqWiseSymbol(char *object_data)
{
  ;
}

// File Line: 104
// RVA: 0x1468240
void UFG::_dynamic_initializer_for__gqSymbolSerialize__()
{
  const char *v0; // r8
  unsigned __int64 v1; // rax
  char v2; // cl
  UFG::qOpRegistry *v3; // rax

  v0 = "UFG::qSymbol";
  v1 = -1i64;
  v2 = 85;
  do
  {
    ++v0;
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *v0;
  }
  while ( *v0 );
  UFG::gqSymbolSerialize.mBaseNode.mUID = v1;
  v3 = UFG::qOpRegistry::Instance();
  UFG::qTree64Base::Add(&v3->mOpTree.mTree, &UFG::gqSymbolSerialize.mBaseNode);
}

// File Line: 108
// RVA: 0x14682A0
void UFG::_dynamic_initializer_for__gqSymbolUCSerialize__()
{
  const char *v0; // r8
  unsigned __int64 v1; // rax
  char v2; // cl
  UFG::qOpRegistry *v3; // rax

  v0 = "UFG::qSymbolUC";
  v1 = -1i64;
  v2 = 85;
  do
  {
    ++v0;
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *v0;
  }
  while ( *v0 );
  UFG::gqSymbolUCSerialize.mBaseNode.mUID = v1;
  v3 = UFG::qOpRegistry::Instance();
  UFG::qTree64Base::Add(&v3->mOpTree.mTree, &UFG::gqSymbolUCSerialize.mBaseNode);
}

// File Line: 112
// RVA: 0x1468300
void UFG::_dynamic_initializer_for__gqWiseSymbolSerialize__()
{
  const char *v0; // r8
  unsigned __int64 v1; // rax
  char v2; // cl
  UFG::qOpRegistry *v3; // rax

  v0 = "UFG::qWiseSymbol";
  v1 = -1i64;
  v2 = 85;
  do
  {
    ++v0;
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *v0;
  }
  while ( *v0 );
  UFG::gqWiseSymbolSerialize.mBaseNode.mUID = v1;
  v3 = UFG::qOpRegistry::Instance();
  UFG::qTree64Base::Add(&v3->mOpTree.mTree, &UFG::gqWiseSymbolSerialize.mBaseNode);
}

// File Line: 121
// RVA: 0x178740
void __fastcall UFG::OnHandlePropertyChanged(char *object, UFG::qReflectField *field, UFG::qReflectType *field_type, char *field_data)
{
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)object, *((_QWORD *)object + 2), *((_QWORD *)object + 3));
}

// File Line: 127
// RVA: 0x1467D20
__int64 UFG::_dynamic_initializer_for__gHandleChangedNotifier__()
{
  const char *v0; // r8
  unsigned __int64 v1; // rdx
  char v2; // al
  UFG::qOpRegistry *v3; // rax
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v4; // rcx
  UFG::qNode<UFG::EditNotification,UFG::EditNotification> *v5; // rax

  v0 = "UFG::qReflectHandleBase";
  v1 = -1i64;
  v2 = 85;
  do
  {
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *++v0;
  }
  while ( *v0 );
  UFG::gHandleChangedNotifier.mTypeUID = v1;
  UFG::gHandleChangedNotifier.mUserData = 0i64;
  UFG::gHandleChangedNotifier.mOnPropertyChangedFunc = (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))UFG::OnHandlePropertyChanged;
  UFG::gHandleChangedNotifier.mOnObjectReloadedFunc = (void (__fastcall *)(char *, void *))_;
  v3 = UFG::qOpRegistry::Instance();
  v4 = &v3->mNotificationList.mNode;
  v5 = v3->mNotificationList.mNode.mPrev;
  v5->mNext = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&UFG::gHandleChangedNotifier;
  UFG::gHandleChangedNotifier.mPrev = v5;
  UFG::gHandleChangedNotifier.mNext = v4;
  v4->mPrev = (UFG::qNode<UFG::EditNotification,UFG::EditNotification> *)&UFG::gHandleChangedNotifier;
  return atexit(UFG::_dynamic_atexit_destructor_for__gHandleChangedNotifier__);
}

// File Line: 142
// RVA: 0x160100
void __fastcall UFG::FactoryOperation::FactoryOperation(UFG::FactoryOperation *this)
{
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mOnCreateFunc = 0i64;
  this->mOnDeleteFunc = 0i64;
}

// File Line: 149
// RVA: 0x160130
void __fastcall UFG::FactoryOperation::FactoryOperation(UFG::FactoryOperation *this, unsigned __int64 type_uid, UFG::qReflectObject *(__fastcall *createFn)(unsigned __int64), void (__fastcall *deleteFn)(char *))
{
  UFG::FactoryOperation *v4; // rbx
  UFG::qTree64<UFG::FactoryOperation,UFG::FactoryOperation,0> *v5; // rax
  const char *v6; // rdi
  UFG::qMemoryPool *v7; // rcx

  v4 = this;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = type_uid;
  this->mOnCreateFunc = createFn;
  this->mOnDeleteFunc = deleteFn;
  v5 = UFG::FactoryOperation::sOperations;
  if ( !UFG::FactoryOperation::sOperations )
  {
    v6 = UFG::gGlobalNewName;
    v7 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v7 = UFG::gMainMemoryPool;
    }
    v5 = (UFG::qTree64<UFG::FactoryOperation,UFG::FactoryOperation,0> *)UFG::qMemoryPool::Allocate(
                                                                          v7,
                                                                          0x38ui64,
                                                                          v6,
                                                                          0i64,
                                                                          1u);
    if ( v5 )
    {
      v5->mTree.mHead.mUID = 0i64;
      v5->mTree.mHead.mParent = &v5->mTree.mHead;
      v5->mTree.mHead.mChildren[0] = &v5->mTree.mHead;
      v5->mTree.mHead.mChildren[1] = &v5->mTree.mHead;
      v5->mTree.mHead.mNeighbours[0] = &v5->mTree.mHead;
      v5->mTree.mHead.mNeighbours[1] = &v5->mTree.mHead;
      v5->mTree.mCount = 0i64;
    }
    UFG::FactoryOperation::sOperations = v5;
  }
  UFG::qTree64Base::Add(&v5->mTree, &v4->mBaseNode);
}

// File Line: 164
// RVA: 0x1713D0
char *__fastcall UFG::qReflectObject::GetName(UFG::qReflectObject *this)
{
  unsigned __int64 v1; // rbx
  UFG::qReflectObject *v2; // rdi
  UFG::qReflectWarehouse *v3; // rax
  UFG::qReflectWarehouse *v4; // rdx

  v1 = this->mTypeUID;
  v2 = this;
  v3 = UFG::qReflectWarehouse::Instance();
  v4 = (UFG::qReflectWarehouse *)v3->mInventoryTree.mTree.mHead.mChildren[0];
  if ( v4 == v3 )
    return &customWorldMapCaption;
  while ( v4->mInventoryTree.mTree.mHead.mUID < v1 )
  {
    v4 = (UFG::qReflectWarehouse *)v4->mInventoryTree.mTree.mHead.mChildren[1];
LABEL_6:
    if ( v4 == v3 )
      return &customWorldMapCaption;
  }
  if ( v4->mInventoryTree.mTree.mHead.mUID > v1 )
  {
    v4 = (UFG::qReflectWarehouse *)v4->mInventoryTree.mTree.mHead.mChildren[0];
    goto LABEL_6;
  }
  if ( v4 == (UFG::qReflectWarehouse *)8 )
    return &customWorldMapCaption;
  return UFG::qReflectInventoryBase::FindObjectName(
           (UFG::qReflectInventoryBase *)&v4[-1].mInventoryTree.mTree.mCount,
           v2->mBaseNode.mUID);
}

// File Line: 183
// RVA: 0x161910
void __fastcall UFG::qReflectHandleBase::qReflectHandleBase(UFG::qReflectHandleBase *this)
{
  this->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mTypeUID = 0i64;
  this->mNameUID = 0i64;
  this->mData = 0i64;
}

// File Line: 195
// RVA: 0x1618B0
void __fastcall UFG::qReflectHandleBase::qReflectHandleBase(UFG::qReflectHandleBase *this, UFG::qReflectHandleBase *other)
{
  this->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  UFG::qReflectHandleBase::Init(this, other->mTypeUID, other->mNameUID);
}

// File Line: 200
// RVA: 0x163F80
void __fastcall UFG::qReflectHandleBase::~qReflectHandleBase(UFG::qReflectHandleBase *this)
{
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v1; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v2; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v3; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v4; // rax

  v1 = this->mPrev;
  v2 = this->mNext;
  v1->mNext = v2;
  v2->mPrev = v1;
  this->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mData = 0i64;
  v3 = this->mPrev;
  v4 = this->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  this->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
}

// File Line: 205
// RVA: 0x164790
UFG::qReflectHandleBase *__fastcall UFG::qReflectHandleBase::operator=(UFG::qReflectHandleBase *this, UFG::qReflectHandleBase *other)
{
  UFG::qReflectHandleBase *v2; // rbx

  v2 = this;
  UFG::qReflectHandleBase::Init(this, other->mTypeUID, other->mNameUID);
  return v2;
}

// File Line: 212
// RVA: 0x173420
void __fastcall UFG::qReflectHandleBase::Init(UFG::qReflectHandleBase *this, unsigned __int64 type_uid, unsigned __int64 name_uid)
{
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v3; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v4; // r9
  UFG::qReflectInventoryBase *v5; // rsi
  unsigned __int64 v6; // rbx
  UFG::qReflectHandleBase *v7; // rdi
  UFG::qReflectWarehouse *v8; // rax
  UFG::qReflectWarehouse *v9; // rcx

  v3 = this->mNext;
  v4 = this->mPrev;
  v5 = 0i64;
  v4->mNext = v3;
  v3->mPrev = v4;
  v6 = type_uid;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&this->mPrev;
  this->mData = 0i64;
  this->mTypeUID = type_uid;
  this->mNameUID = name_uid;
  if ( type_uid - 1 > 0xFFFFFFFFFFFFFFFDui64 )
    return;
  v8 = UFG::qReflectWarehouse::Instance();
  v9 = (UFG::qReflectWarehouse *)v8->mInventoryTree.mTree.mHead.mChildren[0];
  if ( v9 == v8 )
    goto LABEL_10;
  while ( v9->mInventoryTree.mTree.mHead.mUID < v6 )
  {
    v9 = (UFG::qReflectWarehouse *)v9->mInventoryTree.mTree.mHead.mChildren[1];
LABEL_7:
    if ( v9 == v8 )
      goto LABEL_10;
  }
  if ( v9->mInventoryTree.mTree.mHead.mUID > v6 )
  {
    v9 = (UFG::qReflectWarehouse *)v9->mInventoryTree.mTree.mHead.mChildren[0];
    goto LABEL_7;
  }
  v5 = (UFG::qReflectInventoryBase *)&v9[-1].mInventoryTree.mTree.mCount;
LABEL_10:
  UFG::qReflectInventoryBase::AttachHandle(v5, v7);
}

// File Line: 227
// RVA: 0x178880
void __fastcall UFG::OnUnloadHandle(char *object_data)
{
  __int64 v1; // rdx
  _QWORD *v2; // rax

  v1 = *(_QWORD *)object_data;
  v2 = (_QWORD *)*((_QWORD *)object_data + 1);
  *(_QWORD *)(v1 + 8) = v2;
  *v2 = v1;
  *(_QWORD *)object_data = object_data;
  *((_QWORD *)object_data + 1) = object_data;
  *((_QWORD *)object_data + 4) = 0i64;
}

