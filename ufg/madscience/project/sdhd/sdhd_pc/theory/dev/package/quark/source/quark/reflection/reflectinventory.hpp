// File Line: 115
// RVA: 0x54B0
void __fastcall UFG::qReflectInventoryBase::AddDerivedInventory(UFG::qReflectInventoryBase *this, UFG::qReflectInventoryBase *derived)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // rdi
  UFG::qReflectInventoryBase *v3; // rbp
  __int64 v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  v2 = &this->mDerivedInventories;
  v3 = derived;
  v4 = this->mDerivedInventories.size;
  v5 = this->mDerivedInventories.capacity;
  v6 = v4 + 1;
  if ( (signed int)v4 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v7, "qArray.Add");
  }
  v8 = v2->p;
  v2->size = v6;
  v8[v4] = v3;
}

// File Line: 164
// RVA: 0x40BFA0
signed __int64 __fastcall UFG::qReflectInventory<UITest::ArrayTest>::GetClassSize(UFG::qReflectInventory<UFG::ConstraintDefStiffSpring> *this)
{
  return 144i64;
}

// File Line: 169
// RVA: 0x69D7D0
bool __fastcall UFG::qReflectInventory<UFG::Editor::PrefabWindow>::IsBaseClassOfThis(UFG::qReflectInventory<UFG::PartCustomizer> *this, unsigned __int64 type_uid)
{
  unsigned __int64 v2; // rbx
  const char *v3; // rax

  v2 = type_uid;
  v3 = UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::GetStaticTypeName();
  return v2 == UFG::qStringHash64(v3, 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 174
// RVA: 0x20EFE0
void __fastcall UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow>::OnAddToWarehouse(UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *this)
{
  UFG::qReflectInventory<UFG::Editor::SceneLayerListWindow> *v1; // rdi
  UFG::qReflectWarehouse *v2; // rax
  UFG::qTree64Base *v3; // rax
  signed __int64 v4; // rbx
  UFG::qReflectInventoryBase *v5; // rdx
  UFG::qReflectInventoryBase *v6; // rcx
  unsigned __int64 v7; // rax
  UFG::qReflectWarehouse *v8; // rax
  UFG::qTree64Base *v9; // rax

  v1 = this;
  v2 = UFG::qReflectWarehouse::Instance();
  v3 = UFG::qTree64Base::GetHead(&v2->mInventoryTree.mTree);
  if ( v3 )
    v4 = (signed __int64)&v3[-1].mCount;
  else
    v4 = 0i64;
  UFG::qReflectWarehouse::Instance();
  if ( v4 )
  {
    while ( !v1->vfptr->IsBaseClassOfThis((UFG::qReflectInventoryBase *)&v1->vfptr, *(_QWORD *)(v4 + 8)) )
    {
      v7 = UFG::qStringHash64("UFG::Editor::SceneLayerListWindow", 0xFFFFFFFFFFFFFFFFui64);
      if ( (*(unsigned __int8 (__fastcall **)(signed __int64, unsigned __int64))(*(_QWORD *)v4 + 8i64))(v4, v7) )
      {
        *(_QWORD *)(v4 + 360) = v1;
        v5 = (UFG::qReflectInventoryBase *)v4;
        v6 = (UFG::qReflectInventoryBase *)&v1->vfptr;
        goto LABEL_9;
      }
LABEL_10:
      v8 = UFG::qReflectWarehouse::Instance();
      v9 = UFG::qTree64Base::GetNext(&v8->mInventoryTree.mTree, (UFG::qTree64Base::BaseNode *)(v4 + 8));
      if ( v9 )
        v4 = (signed __int64)&v9[-1].mCount;
      else
        v4 = 0i64;
      UFG::qReflectWarehouse::Instance();
      if ( !v4 )
        return;
    }
    v1->mBaseClassInventory = (UFG::qReflectInventoryBase *)v4;
    v5 = (UFG::qReflectInventoryBase *)&v1->vfptr;
    v6 = (UFG::qReflectInventoryBase *)v4;
LABEL_9:
    UFG::qReflectInventoryBase::AddDerivedInventory(v6, v5);
    goto LABEL_10;
  }
}

