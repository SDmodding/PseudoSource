// File Line: 154
// RVA: 0x52D8F0
UFG::qSymbol *__fastcall UFG::VehicleSubjectComponent::GetFollowOverrideContext(
        UFG::VehicleSubjectComponent *this,
        UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mFollowOverrideContext;
  return result;
}

