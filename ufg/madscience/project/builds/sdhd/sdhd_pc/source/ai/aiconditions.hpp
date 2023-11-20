// File Line: 1087
// RVA: 0x32CF60
void __fastcall CanAttackConditionGroup::CanAttackConditionGroup(CanAttackConditionGroup *this)
{
  CanAttackConditionGroup *v1; // rdi

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&ConditionGroup::`vftable;
  v1->mSignalMask = -1i64;
  v1->mConditions.mCount = 0;
  v1->mConditions.mData.mOffset = 0i64;
  UFG::qSafePointerNode<CanAttackConditionGroup>::qSafePointerNode<CanAttackConditionGroup>((UFG::qSafePointerNode<CanAttackConditionGroup> *)&v1->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CanAttackConditionGroup::`vftable{for `ConditionGroup};
  v1->vfptr = (UFG::qSafePointerNode<CanAttackConditionGroup>Vtbl *)&CanAttackConditionGroup::`vftable{for `UFG::qSafePointerNode<CanAttackConditionGroup>};
}

