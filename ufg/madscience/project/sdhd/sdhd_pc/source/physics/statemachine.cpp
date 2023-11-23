// File Line: 22
// RVA: 0x1514170
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::StateMachineDefinition_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory,
    "UFG::StateMachineDefinition",
    v0);
  UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::StateMachineDefinition>::`vftable;
  UFG::qReflectInventory<UFG::StateMachineDefinition>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::StateMachineDefinition_UFG::qReflectObject_::sInventory__);
}

// File Line: 27
// RVA: 0x1513CE0
__int64 dynamic_initializer_for__UFG::StateMachineDefinition::mGuidTranslation__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::StateMachineDefinition::mGuidTranslation.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StateMachineDefinition::mGuidTranslation__);
}

// File Line: 32
// RVA: 0x46B5D0
void UFG::StateMachineDefinition::LoadDefinitionsFromInventory(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rdi
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rbx
  UFG::qBaseNodeRB *v5; // rax
  UFG::qTree64Base *Next; // rax

  v0 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v1, v0)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = &Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        v5 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "StateMachineDefinition::LookupNode", 0i64);
        if ( v5 )
        {
          v5->mParent = 0i64;
          v5->mChild[0] = 0i64;
          v5->mChild[1] = 0i64;
        }
        else
        {
          v5 = 0i64;
        }
        v5->mUID = *((_DWORD *)p_mCount + 24);
        v5[1].mParent = (UFG::qBaseNodeRB *)p_mCount[1];
        UFG::qBaseTreeRB::Add(&UFG::StateMachineDefinition::mGuidTranslation.mTree, v5);
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(p_mCount + 1));
        if ( !Next )
          break;
        p_mCount = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 74
// RVA: 0x1519E20
__int64 UFG::_dynamic_initializer_for__gStateMachineDefinitionNotifier__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &UFG::gStateMachineDefinitionNotifier,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))_,
    (void (__fastcall *)(char *, void *))_,
    0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gStateMachineDefinitionNotifier__);
}

// File Line: 120
// RVA: 0x4664A0
UFG::qBaseNodeRB *__fastcall UFG::StateMachineDefinition::GetDnaUid(unsigned int nameGuid)
{
  UFG::qBaseTreeRB *v1; // rax

  if ( nameGuid && (v1 = UFG::qBaseTreeRB::Get(&UFG::StateMachineDefinition::mGuidTranslation.mTree, nameGuid)) != 0i64 )
    return v1->mNULL.mParent;
  else
    return 0i64;
}

// File Line: 133
// RVA: 0x4647B0
__int64 __fastcall UFG::StateMachineDefinition::FindNamedNode(UFG::StateMachineDefinition *this, UFG::qSymbol *name)
{
  unsigned int v2; // ebx
  UFG::StateMachineNode *v5; // rax
  const char *v6; // rdx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0;
  if ( !this->mStateNodes.mData.mNumItems )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = &this->mStateNodes.mData.mItems[v2];
    v6 = v5->mName.mText.mData.mNumItems ? v5->mName.mText.mData.mItems : &customCaption;
    UFG::qSymbol::create_from_string(&result, v6);
    if ( result.mUID == name->mUID )
      break;
    if ( ++v2 >= this->mStateNodes.mData.mNumItems )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

