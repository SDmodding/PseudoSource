// File Line: 17
// RVA: 0xC2F740
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::hkaiPhysics2012BodySilhouetteGenerator(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkpRigidBody *rb,
        hkaiPhysics2012WorldListener *listener)
{
  __m128 m_quad; // xmm1
  hkVector4f translationInOut; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f linearVel; // [rsp+30h] [rbp-28h] BYREF
  hkQuaternionf rbRotation; // [rsp+40h] [rbp-18h] BYREF

  hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(this);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodySilhouetteGenerator::`vftable;
  this->m_rigidBody.m_pntr = 0i64;
  this->m_physicsWorldListener = listener;
  m_quad = rb->m_motion.m_motionState.m_transform.m_translation.m_quad;
  rbRotation.m_vec.m_quad = (__m128)rb->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  translationInOut.m_quad = m_quad;
  hkaiPhysics2012BodySilhouetteGenerator::addWorldShift(this, &translationInOut);
  linearVel.m_quad = (__m128)rb->m_motion.m_linearVelocity;
  hkaiPhysics2012BodySilhouetteGenerator::setRigidBody(this, rb);
  hkaiPhysicsBodySilhouetteGeneratorBase::updateFromBodyInfo(this, &rbRotation, &translationInOut, &linearVel);
  this->m_weldTolerance = 0.000001;
}

// File Line: 35
// RVA: 0xC2F800
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::hkaiPhysics2012BodySilhouetteGenerator(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodySilhouetteGenerator::`vftable;
}

// File Line: 39
// RVA: 0xC2F970
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::~hkaiPhysics2012BodySilhouetteGenerator(
        hkaiPhysics2012BodySilhouetteGenerator *this)
{
  hkpRigidBody *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodySilhouetteGenerator::`vftable;
  m_pntr = this->m_rigidBody.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_rigidBody.m_pntr = 0i64;
  hkaiPhysicsBodySilhouetteGeneratorBase::~hkaiPhysicsBodySilhouetteGeneratorBase(this);
}

// File Line: 43
// RVA: 0xC2F830
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::setRigidBody(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkpRigidBody *rb)
{
  hkpRigidBody *m_pntr; // rcx

  if ( rb )
    hkReferencedObject::addReference(rb);
  m_pntr = this->m_rigidBody.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_rigidBody.m_pntr = rb;
  hkaiPhysics2012BodySilhouetteGenerator::setPointCloudFromShape(this, rb->m_collidable.m_shape);
}

// File Line: 49
// RVA: 0xC2F890
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::setPointCloudFromShape(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkpShape *shape)
{
  hkArray<int,hkContainerHeapAllocator> sizesOut; // [rsp+20h] [rbp-28h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> verticesOut; // [rsp+30h] [rbp-18h] BYREF

  verticesOut.m_data = 0i64;
  verticesOut.m_size = 0;
  verticesOut.m_capacityAndFlags = 0x80000000;
  sizesOut.m_data = 0i64;
  sizesOut.m_size = 0;
  sizesOut.m_capacityAndFlags = 0x80000000;
  hkaiPhysics2012SilhouetteBuilder::createPointCloudFromShapeRecursive(
    shape,
    &hkQsTransformf_identityStorage,
    &verticesOut,
    &sizesOut);
  hkaiPointCloudSilhouetteGenerator::setLocalPoints(this, &verticesOut, &sizesOut);
  sizesOut.m_size = 0;
  if ( sizesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sizesOut.m_data,
      4 * sizesOut.m_capacityAndFlags);
  sizesOut.m_data = 0i64;
  sizesOut.m_capacityAndFlags = 0x80000000;
  verticesOut.m_size = 0;
  if ( verticesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      verticesOut.m_data,
      16 * verticesOut.m_capacityAndFlags);
}

// File Line: 59
// RVA: 0xC2F9C0
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::getBodyRotationAndTranslation(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkQuaternionf *rotationOut,
        hkVector4f *translationOut)
{
  hkVector4f translationInOut; // [rsp+20h] [rbp-18h] BYREF

  *rotationOut = this->m_rigidBody.m_pntr->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  translationInOut.m_quad = (__m128)this->m_rigidBody.m_pntr->m_motion.m_motionState.m_transform.m_translation;
  hkaiPhysics2012BodySilhouetteGenerator::addWorldShift(this, &translationInOut);
  *translationOut = (hkVector4f)translationInOut.m_quad;
}

// File Line: 67
// RVA: 0xC2FA10
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::getBodyLinearVelocity(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkVector4f *velocityOut)
{
  *velocityOut = this->m_rigidBody.m_pntr->m_motion.m_linearVelocity;
}

// File Line: 72
// RVA: 0xC2FA50
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::addWorldShift(
        hkaiPhysics2012BodySilhouetteGenerator *this,
        hkVector4f *translationInOut)
{
  hkaiPhysics2012WorldListener *m_physicsWorldListener; // rax

  m_physicsWorldListener = this->m_physicsWorldListener;
  if ( m_physicsWorldListener )
    translationInOut->m_quad = _mm_add_ps(m_physicsWorldListener->m_worldShift.m_quad, translationInOut->m_quad);
}

// File Line: 80
// RVA: 0xC2FA30
_BOOL8 __fastcall hkaiPhysics2012BodySilhouetteGenerator::isInWorld(hkaiPhysics2012BodySilhouetteGenerator *this)
{
  return this->m_rigidBody.m_pntr->m_world != 0i64;
}

