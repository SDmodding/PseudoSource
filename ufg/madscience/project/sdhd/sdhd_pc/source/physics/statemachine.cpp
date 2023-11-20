// File Line: 22
// RVA: 0x1514170
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::StateMachineDefinition_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::StateMachineDefinition",
    v0);
  UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::StateMachineDefinition>::`vftable;
  UFG::qReflectInventory<UFG::StateMachineDefinition>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::StateMachineDefinition_UFG::qReflectObject_::sInventory__);
}

// File Line: 27
// RVA: 0x1513CE0
__int64 dynamic_initializer_for__UFG::StateMachineDefinition::mGuidTranslation__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::StateMachineDefinition::mGuidTranslation.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::StateMachineDefinition::mGuidTranslation__);
}

// File Line: 32
// RVA: 0x46B5D0
void UFG::StateMachineDefinition::LoadDefinitionsFromInventory(void)
{
  unsigned __int64 v0; // rbx
  UFG::qReflectWarehouse *v1; // rax
  UFG::qReflectInventoryBase *v2; // rax
  UFG::qTree64Base *v3; // rdi
  UFG::qTree64Base *v4; // rax
  signed __int64 v5; // rbx
  UFG::qBaseNodeRB *v6; // rax
  UFG::qTree64Base *v7; // rax

  v0 = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v1 = UFG::qReflectWarehouse::Instance();
  v2 = UFG::qReflectWarehouse::GetInventory(v1, v0);
  v3 = &v2->mItems.mTree;
  v4 = UFG::qTree64Base::GetHead(&v2->mItems.mTree);
  if ( v4 )
  {
    v5 = (signed __int64)&v4[-1].mCount;
    if ( v4 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v6 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "StateMachineDefinition::LookupNode", 0i64);
        if ( v6 )
        {
          v6->mParent = 0i64;
          v6->mChild[0] = 0i64;
          v6->mChild[1] = 0i64;
        }
        else
        {
          v6 = 0i64;
        }
        v6->mUID = *(_DWORD *)(v5 + 96);
        v6[1].mParent = *(UFG::qBaseNodeRB **)(v5 + 8);
        UFG::qBaseTreeRB::Add(&UFG::StateMachineDefinition::mGuidTranslation.mTree, v6);
        v7 = UFG::qTree64Base::GetNext(v3, (UFG::qTree64Base::BaseNode *)(v5 + 8));
        if ( !v7 )
          break;
        v5 = (signed __int64)&v7[-1].mCount;
      }
      while ( v7 != (UFG::qTree64Base *)8 );
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gStateMachineDefinitionNotifier__);
}

// File Line: 120
// RVA: 0x4664A0
UFG::qBaseNodeRB *__fastcall UFG::StateMachineDefinition::GetDnaUid(unsigned int nameGuid)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::qBaseNodeRB *result; // rax

  if ( nameGuid && (v1 = UFG::qBaseTreeRB::Get(&UFG::StateMachineDefinition::mGuidTranslation.mTree, nameGuid)) != 0i64 )
    result = v1->mNULL.mParent;
  else
    result = 0i64;
  return result;
}

// File Line: 133
// RVA: 0x4647B0
signed __int64 __fastcall UFG::StateMachineDefinition::FindNamedNode(UFG::StateMachineDefinition *this, UFG::qSymbol *name)
{
  unsigned int v2; // ebx
  UFG::qSymbol *v3; // rsi
  UFG::StateMachineDefinition *v4; // rdi
  signed __int64 v5; // rax
  const char *v6; // rdx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = 0;
  v3 = name;
  v4 = this;
  if ( !this->mStateNodes.mData.mNumItems )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = (signed __int64)&v4->mStateNodes.mData.mItems[v2];
    v6 = (const char *)(*(_DWORD *)(v5 + 8) ? *(_QWORD *)v5 : &customWorldMapCaption);
    UFG::qSymbol::create_from_string(&result, v6);
    if ( result.mUID == v3->mUID )
      break;
    if ( ++v2 >= v4->mStateNodes.mData.mNumItems )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

