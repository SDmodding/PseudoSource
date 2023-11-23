// File Line: 164
// RVA: 0xAB760
__int64 __fastcall UFG::TerrainCollisionComponent::GetTypeSize(UFG::TerrainCollisionComponent *this)
{
  return 184i64;
}

// File Line: 169
// RVA: 0xACC50
bool __fastcall UFG::qReflectInventory<UFG::ConstraintDefRagdoll>::IsBaseClassOfThis(
        UFG::qReflectInventory<UFG::ConstraintDefStiffSpring> *this,
        unsigned __int64 type_uid)
{
  return type_uid == UFG::qStringHash64("UFG::ConstraintDef", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 174
// RVA: 0xAD3C0
void __fastcall UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket>::OnAddToWarehouse(
        UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *this)
{
  UFG::qReflectWarehouse *v2; // rax
  UFG::qTree64Base *Head; // rax
  UFG::qReflectInventoryBase *p_mCount; // rbx
  UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *v5; // rdx
  UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *v6; // rcx
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
      v7 = UFG::qStringHash64("UFG::ConstraintDefBallAndSocket", 0xFFFFFFFFFFFFFFFFui64);
      if ( p_mCount->vfptr->IsBaseClassOfThis(p_mCount, v7) )
      {
        p_mCount->mBaseClassInventory = this;
        v5 = (UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *)p_mCount;
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
    v6 = (UFG::qReflectInventory<UFG::ConstraintDefBallAndSocket> *)p_mCount;
LABEL_9:
    UFG::qReflectInventoryBase::AddDerivedInventory(v6, v5);
    goto LABEL_10;
  }
}

