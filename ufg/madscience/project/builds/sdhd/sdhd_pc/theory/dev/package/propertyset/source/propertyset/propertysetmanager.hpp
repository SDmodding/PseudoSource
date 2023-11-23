// File Line: 269
// RVA: 0x328CF0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::GetComponentDataPtr<component_CharacterProperties>(
        UFG::PropertySetManager *this,
        UFG::qPropertySet *propSet)
{
  UFG::qPropertySet *result; // rax

  result = UFG::qPropertySet::Get<UFG::qPropertySet>(
             (UFG::qPropertySet *)this,
             (UFG::qArray<unsigned long,0> *)&component_CharacterProperties::sPropertyName,
             DEPTH_RECURSE);
  if ( result )
    return (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(result);
  return result;
}

