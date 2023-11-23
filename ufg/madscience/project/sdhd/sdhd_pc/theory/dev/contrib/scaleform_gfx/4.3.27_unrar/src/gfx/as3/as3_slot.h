// File Line: 281
// RVA: 0x8DCE60
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::SlotInfo::GetQualifiedName(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pObject; // rax

  pObject = this->Name.pObject;
  result->pNode = pObject;
  ++pObject->RefCount;
  return result;
}

