// File Line: 115
// RVA: 0x54B0
void __fastcall UFG::qReflectInventoryBase::AddDerivedInventory(
        UFG::qReflectInventoryBase *this,
        UFG::qReflectInventoryBase *derived)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mDerivedInventories; // rdi
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  p_mDerivedInventories = &this->mDerivedInventories;
  size = this->mDerivedInventories.size;
  capacity = this->mDerivedInventories.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mDerivedInventories, v7, "qArray.Add");
  }
  p = p_mDerivedInventories->p;
  p_mDerivedInventories->size = v6;
  p[size] = derived;
}

// File Line: 164
// RVA: 0x40BFA0
__int64 __fastcall UFG::qReflectInventory<UITest::ArrayTest>::GetClassSize(
        UFG::qReflectInventory<UFG::ConstraintDefStiffSpring> *this)
{
  return 144i64;
}

// File Line: 169
// RVA: 0x69D7D0
bool __fastcall UFG::qReflectInventory<UFG::Editor::PrefabWindow>::IsBaseClassOfThis(
        UFG::qReflectInventory<UFG::PartCustomizer> *this,
        unsigned __int64 type_uid)
{
  const char *StaticTypeName; // rax

  StaticTypeName = UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::GetStaticTypeName();
  return type_uid == UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 174
// RVA: 0x20EFE0
void __fastcall UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow>::OnAddToWarehouse(
        UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *this)
{
  UFG::qReflectWarehouse *v2; // rax
  UFG::qTree64Base *Head; // rax
  UFG::qReflectInventoryBase *p_mCount; // rbx
  UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *v5; // rdx
  UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *v6; // rcx
  unsigned __int64 v7; // rax
  UFG::qReflectWarehouse *v8; // rax
  UFG::qTree64Base *Next; // rax

  v2 = UFG::qReflectWarehouse::Instance();
  Head = UFG::qTree64Base::GetHead(&v2->mInventoryTree.mTree);
  if ( Head )
    p_mCount = (UFG::qReflectInventoryBase *)&Head[-1].mCount;
  else
    p_mCount = 0i64;
  UFG::qReflectWarehouse::Instance();
  if ( p_mCount )
  {
    while ( !this->vfptr->IsBaseClassOfThis(this, p_mCount->mBaseNode.mUID) )
    {
      v7 = UFG::qStringHash64("UFG::Editor::SceneLayerListWindow", 0xFFFFFFFFFFFFFFFFui64);
      if ( p_mCount->vfptr->IsBaseClassOfThis(p_mCount, v7) )
      {
        p_mCount->mBaseClassInventory = this;
        v5 = (UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *)p_mCount;
        v6 = this;
        goto LABEL_9;
      }
LABEL_10:
      v8 = UFG::qReflectWarehouse::Instance();
      Next = UFG::qTree64Base::GetNext(&v8->mInventoryTree.mTree, &p_mCount->mBaseNode);
      if ( Next )
        p_mCount = (UFG::qReflectInventoryBase *)&Next[-1].mCount;
      else
        p_mCount = 0i64;
      UFG::qReflectWarehouse::Instance();
      if ( !p_mCount )
        return;
    }
    this->mBaseClassInventory = p_mCount;
    v5 = this;
    v6 = (UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *)p_mCount;
LABEL_9:
    UFG::qReflectInventoryBase::AddDerivedInventory(v6, v5);
    goto LABEL_10;
  }
}

