// File Line: 10
// RVA: 0x48D660
void __fastcall UFG::SSGameSlice::SSGameSlice(
        UFG::SSGameSlice *this,
        UFG::GameSlice *pGameSlice,
        ASymbol *name,
        SSActorClass *pClass,
        bool addToInstanceList)
{
  UFG::qSafePointerNode<UFG::SSGameSlice>::qSafePointerNode<UFG::SSGameSlice>(this);
  SSActor::SSActor(&this->SSActor, name, pClass, addToInstanceList);
  this->UFG::qSafePointerNode<UFG::SSGameSlice>::vfptr = (UFG::qSafePointerNode<UFG::SSGameSlice>Vtbl *)&UFG::SSGameSlice::`vftable{for `UFG::qSafePointerNode<UFG::SSGameSlice>};
  this->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr = (SSObjectBaseVtbl *)&UFG::SSGameSlice::`vftable{for `SSActor};
  this->mpGameSlice = pGameSlice;
}

// File Line: 15
// RVA: 0x491100
void __fastcall UFG::SSGameSlice::~SSGameSlice(UFG::SSGameSlice *this)
{
  SSActor *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SSGameSlice>,UFG::qSafePointerNodeList> *mNext; // rax

  this->UFG::qSafePointerNode<UFG::SSGameSlice>::vfptr = (UFG::qSafePointerNode<UFG::SSGameSlice>Vtbl *)&UFG::SSGameSlice::`vftable{for `UFG::qSafePointerNode<UFG::SSGameSlice>};
  v2 = &this->SSActor;
  v2->vfptr = (SSObjectBaseVtbl *)&UFG::SSGameSlice::`vftable{for `SSActor};
  this->mpGameSlice->mCleanupPending = CLEANUP_SCRIPT_CLEANUP;
  SSActor::~SSActor(v2);
  this->UFG::qSafePointerNode<UFG::SSGameSlice>::vfptr = (UFG::qSafePointerNode<UFG::SSGameSlice>Vtbl *)&UFG::qSafePointerNode<UFG::SSGameSlice>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  mPrev = this->m_SafePointerList.mNode.mPrev;
  mNext = this->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

