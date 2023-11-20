// File Line: 10
// RVA: 0x48D660
void __fastcall UFG::SSGameSlice::SSGameSlice(UFG::SSGameSlice *this, UFG::GameSlice *pGameSlice, ASymbol *name, SSActorClass *pClass, bool addToInstanceList)
{
  SSActorClass *v5; // rdi
  ASymbol *v6; // rsi
  UFG::GameSlice *v7; // rbp
  UFG::SSGameSlice *v8; // r14

  v5 = pClass;
  v6 = name;
  v7 = pGameSlice;
  v8 = this;
  UFG::qSafePointerNode<UFG::SSGameSlice>::qSafePointerNode<UFG::SSGameSlice>((UFG::qSafePointerNode<UFG::SSGameSlice> *)&this->vfptr);
  SSActor::SSActor((SSActor *)&v8->vfptr, v6, v5, addToInstanceList);
  v8->vfptr = (UFG::qSafePointerNode<UFG::SSGameSlice>Vtbl *)&UFG::SSGameSlice::`vftable'{for `UFG::qSafePointerNode<UFG::SSGameSlice>'};
  v8->vfptr = (SSObjectBaseVtbl *)&UFG::SSGameSlice::`vftable'{for `SSActor'};
  v8->mpGameSlice = v7;
}

// File Line: 15
// RVA: 0x491100
void __fastcall UFG::SSGameSlice::~SSGameSlice(UFG::SSGameSlice *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v1; // rbx
  SSActor *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v5; // [rsp+40h] [rbp+8h]

  v1 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SSGameSlice>Vtbl *)&UFG::SSGameSlice::`vftable'{for `UFG::qSafePointerNode<UFG::SSGameSlice>'};
  v2 = (SSActor *)&this->vfptr;
  v2->vfptr = (SSObjectBaseVtbl *)&UFG::SSGameSlice::`vftable'{for `SSActor'};
  LODWORD(v1[6].m_SafePointerList.mNode.mPrev[22].mNext) = 2;
  SSActor::~SSActor(v2);
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::SSGameSlice>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v1);
  v5 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v3 = v1->m_SafePointerList.mNode.mPrev;
  v4 = v1->m_SafePointerList.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

