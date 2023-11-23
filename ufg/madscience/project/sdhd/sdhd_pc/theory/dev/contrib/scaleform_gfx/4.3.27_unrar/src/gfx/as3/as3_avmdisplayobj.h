// File Line: 75
// RVA: 0x7B2230
void __fastcall NodeRequestCondition::ResolveReferences(NodeRequestCondition *this, ActionNode *action_node)
{
  this->m_pActionNode = action_node;
}

// File Line: 138
// RVA: 0x7EC620
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetName(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::DisplayObject::GetName(this->pDispObj, result);
  return result;
}

// File Line: 145
// RVA: 0x7E7780
const char *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetDefaultASClassName(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  return "flash.display.DisplayObject";
}

// File Line: 229
// RVA: 0x7E69C0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetResourceMovieDef(
        Scaleform::GFx::AS3::AvmBitmap *this)
{
  return this->pDefImpl.pObject;
}

// File Line: 236
// RVA: 0x7EEBE0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS3::ShapeObject::GetRectBounds(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v5; // rax
  char v7[24]; // [rsp+20h] [rbp-18h] BYREF

  v5 = (Scaleform::Render::Rect<float> *)this->pDef.pObject->vfptr[2].__vecDelDtor(this->pDef.pObject, v7);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v5);
  return result;
}

// File Line: 250
// RVA: 0x7E7810
const char *__fastcall Scaleform::GFx::AS3::ShapeObject::GetDefaultASClassName(Scaleform::GFx::AS3::ShapeObject *this)
{
  return "flash.display.Shape";
}

