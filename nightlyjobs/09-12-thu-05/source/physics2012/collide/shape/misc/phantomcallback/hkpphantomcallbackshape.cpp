// File Line: 16
// RVA: 0xCF34E0
void __fastcall hkpPhantomCallbackShape::hkpPhantomCallbackShape(
        hkpPhantomCallbackShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhantomCallbackShape::`vftable;
  this->m_type.m_storage = 32;
}

// File Line: 23
// RVA: 0xCF3510
void __fastcall hkpPhantomCallbackShape::getAabb(
        hkpPhantomCallbackShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  out->m_min = 0i64;
  out->m_max = 0i64;
}

// File Line: 30
// RVA: 0xCF3530
hkBool *__fastcall hkpPhantomCallbackShape::castRay(
        hkpPhantomCallbackShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  result->m_bool = 0;
  return result;
}

// File Line: 36
// RVA: 0xCF3540
void __fastcall hkpPhantomCallbackShape::castRayWithCollector(
        hkpPhantomCallbackShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  ;
}

