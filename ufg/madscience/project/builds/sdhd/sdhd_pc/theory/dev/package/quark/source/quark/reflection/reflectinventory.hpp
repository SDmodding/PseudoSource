// File Line: 164
// RVA: 0xAB760
signed __int64 __fastcall UFG::TerrainCollisionComponent::GetTypeSize(UFG::TerrainCollisionComponent *this)
{
  return 184i64;
}

// File Line: 169
// RVA: 0xACC50
bool __fastcall UFG::qReflectInventory<UFG::ConstraintDefRagdoll>::IsBaseClassOfThis(UFG::qReflectInventory<UFG::ConstraintDefStiffSpring> *this, unsigned __int64 type_uid)
{
  return type_uid == UFG::qStringHash64("UFG::ConstraintDef", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 174
// RVA: 0xAD3C0
void __fastcall UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket>::OnAddToWarehouse(UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *this)
{
  UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *v1; // rdi
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
      v7 = UFG::qStringHash64("UFG::ConstraintDefBallAndSocket", 0xFFFFFFFFFFFFFFFFui64);
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

