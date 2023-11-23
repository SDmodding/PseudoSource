// File Line: 25
// RVA: 0xCECE80
void __fastcall hkpShapeBase::hkpShapeBase(hkpShapeBase *this, hkFinishLoadedObjectFlag flag)
{
  hkcdShape::hkcdShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeBase::`vftable;
  if ( flag.m_finishing )
    this->m_type.m_storage = 34;
}

// File Line: 35
// RVA: 0xCECEC0
void __fastcall hkpShapeBase::getAabb(hkpShapeBase *this, hkTransformf *localToWorld, float tolerance, hkAabb *aabbOut)
{
  ;
}

// File Line: 40
// RVA: 0xCECED0
hkBool *__fastcall hkpShapeBase::castRay(
        hkpShapeBase *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *output)
{
  result->m_bool = 0;
  return result;
}

// File Line: 46
// RVA: 0xCECEE0
void __fastcall hkpShapeBase::castRayWithCollector(
        hkpShapeBase *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  ;
}

// File Line: 51
// RVA: 0xCECEF0
hkVector4fComparison *__fastcall hkpShapeBase::castRayBundle(
        hkpShapeBase *this,
        hkVector4fComparison *result,
        hkpShapeRayBundleCastInput *input,
        hkpShapeRayBundleCastOutput *output)
{
  hkVector4fComparison *v4; // rax

  v4 = result;
  *result = 0i64;
  return v4;
}

// File Line: 59
// RVA: 0xCECF00
void __fastcall hkpShapeBase::getSupportingVertex(
        hkpShapeBase *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  ;
}

// File Line: 64
// RVA: 0xCECF10
void __fastcall hkpShapeBase::convertVertexIdsToVertices(
        hkpShapeBase *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *vertexArrayOut)
{
  ;
}

// File Line: 69
// RVA: 0xCECF20
void __fastcall hkpShapeBase::getCentre(hkpShapeBase *this, hkVector4f *centreOut)
{
  ;
}

// File Line: 74
// RVA: 0xCECF30
__int64 __fastcall hkpShapeBase::getNumCollisionSpheres(hkpShapeBase *this)
{
  return 0i64;
}

// File Line: 80
// RVA: 0xCECF40
hkSphere *__fastcall hkpShapeBase::getCollisionSpheres(hkpShapeBase *this, hkSphere *sphereBuffer)
{
  return 0i64;
}

// File Line: 102
// RVA: 0xCECF50
__int64 __fastcall hkpShapeBase::weldContactPoint(
        hkpShapeBase *this,
        unsigned __int16 *featurePoints,
        char *numFeaturePoints,
        hkVector4f *contactPointWs)
{
  return 0i64;
}

