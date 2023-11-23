// File Line: 1087
// RVA: 0x32CF60
void __fastcall CanAttackConditionGroup::CanAttackConditionGroup(CanAttackConditionGroup *this)
{
  Condition::Condition(this);
  this->ConditionGroup::Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&ConditionGroup::`vftable;
  this->mSignalMask = -1i64;
  this->mConditions.mCount = 0;
  this->mConditions.mData.mOffset = 0i64;
  UFG::qSafePointerNode<CanAttackConditionGroup>::qSafePointerNode<CanAttackConditionGroup>(&this->UFG::qSafePointerNode<CanAttackConditionGroup>);
  this->ConditionGroup::Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&CanAttackConditionGroup::`vftable{for `ConditionGroup};
  this->UFG::qSafePointerNode<CanAttackConditionGroup>::vfptr = (UFG::qSafePointerNode<CanAttackConditionGroup>Vtbl *)&CanAttackConditionGroup::`vftable{for `UFG::qSafePointerNode<CanAttackConditionGroup>};
}

